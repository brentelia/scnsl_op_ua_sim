#include <systemc>
#include <tlm.h>
#include <scnsl.hh>
#include <exception>
#include <string>
#include <scnsl_opc-ua.hpp>
#include "ServerTaskImpl.hpp"
#include "ClientTaskImpl.hpp"

using namespace Scnsl::Setup;
using namespace Scnsl::BuiltinPlugin;
//using namespace Scnsl::Opc_ua;

int sc_main(int argc, char* argv[])
{
    try{
        //simaulation creation
        Scnsl::Setup::Scnsl_t *simulation = Scnsl::Setup::Scnsl_t::get_instance();
        //environment
        Scnsl::Utils::DefaultEnvironment_t::createInstance(0.1);

        //node creation, not important since opc-ua is implemented as task
        Scnsl::Core::Node_t *Server_node = simulation->createNode();
        Scnsl::Core::Node_t *Client_node = simulation->createNode();

        /*
            CHANNEL CREATION
        */
        //setup -> should be created automatically given the tasks and node number to avoid problems
        CoreChannelSetup_t channel_setup;
        channel_setup.extensionId = "core";
        //haf duplex channel for allow comunication in both sense
        channel_setup.channel_type = CoreChannelSetup_t::HALF_DUPLEX;
        channel_setup.name = "channel";
        channel_setup.capacity = 10000;
        channel_setup.delay = sc_core::sc_time(1.0,sc_core::SC_US);
        channel_setup.nodes_number = 2;
        Scnsl::Core::Channel_if_t *channel = simulation->createChannel(channel_setup);
        /////////////////////////////////////////////

        /*
            TASK CREATION
        */
        int server_id=0;
        int client_id=1;
        ServerTaskImpl Server ("Server",server_id,Server_node,1); //numero client = 1 
        std::cout<< "Server created"<<std::endl;

        ClientTaskImpl Client ("Client",client_id,Client_node);
        std::cout<<"Client created"<<std::endl;
        /////////////////////////////////////////////////

        /*
            COMMUINCATOR CREATION
        */
        CoreCommunicatorSetup_t comm;
        comm.extensionId ="core";
        comm.ack_required = false;
        comm.short_addresses= true;
        comm.type= CoreCommunicatorSetup_t::MAC_802_15_4;

        Scnsl::Core::Communicator_if_t *mac0;
        comm.name = "Mac0";
        comm.node = Server_node;
        mac0 = simulation->createCommunicator(comm);

        Scnsl::Core::Communicator_if_t *mac1;
        comm.name = "Mac1";
        comm.node = Client_node;
        mac1 = simulation->createCommunicator(comm);
        ///////////////////////////////////
        std::cout<<"Comunicator created"<<std::endl;
        /*
            BINDINGS
        */

        //server to client

        BindSetup_base_t base_bind_0;
        base_bind_0.extensionId = "core";
        base_bind_0.bindIdentifier=std::to_string(server_id)+"_S";
        base_bind_0.destinationNode = Client_node;
        base_bind_0.node_binding.x = 0;
		base_bind_0.node_binding.y = 0;
		base_bind_0.node_binding.z = 0;
        base_bind_0.node_binding.bitrate=Scnsl::Protocols::Mac_802_15_4::BITRATE;
        base_bind_0.node_binding.transmission_power = 12;
        base_bind_0.node_binding.receiving_threshold = 10;
        
        simulation->bind(Server_node,channel,base_bind_0);

        simulation->bind(&Server, &Client, channel,base_bind_0,mac0);
        std::cout<<"Bind server to client"<<std::endl;
      
        //client to server channel
        BindSetup_base_t base_bind_1;
        base_bind_1.extensionId = "core";
        base_bind_1.bindIdentifier=std::to_string(client_id)+"_C";
        base_bind_1.destinationNode = Server_node;
        base_bind_1.node_binding.x = 10;
		base_bind_1.node_binding.y = 5;
		base_bind_1.node_binding.z = 0;
        base_bind_1.node_binding.bitrate=Scnsl::Protocols::Mac_802_15_4::BITRATE;
        base_bind_1.node_binding.transmission_power = 12;
        base_bind_1.node_binding.receiving_threshold = 10;
        
        simulation->bind(Client_node,channel,base_bind_1);
        std::cout<<"Bind client_node to channel"<<std::endl;


        simulation->bind(&Client, &Server, channel,base_bind_1,mac1);
        std::cout<<"Bind client to server"<<std::endl;

        std::cout<<"Starting simulation"<<std::endl;
        sc_core::sc_start(sc_core::sc_time(100,sc_core::SC_SEC));
        //sc_core::sc_stop();
    }
    catch (std::exception &e){
        std::cerr << "Exception in sc_main(): " << e.what() << std::endl;
		return 1;
    }
    return 0;

}