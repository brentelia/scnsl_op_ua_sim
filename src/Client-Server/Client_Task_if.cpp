#include <sstream>
#include "scnsl_opc-ua.hpp"
#include "scnsl_opc-ua/Client-Server/Client_Task_if.hpp"

using namespace Scnsl::Opc_ua;
using namespace Scnsl::Tlm;
//constructor

Client_Task_if::Client_Task_if(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n)
              throw():
    
    TlmTask_if_t( modulename, id, n, 1 ),
    client_id(id)    
{}

Client_Task_if::~Client_Task_if()
{}

//btransport called from server
void Client_Task_if::b_transport( tlm::tlm_generic_payload & p, sc_core::sc_time & t ){

    //get data pointer
    Opc_ua_payload_t* payload = ((Opc_ua_payload_t*)p.get_data_ptr());
    
    //server sent data to the client and data found
    if(payload->command_type == DATA_COMMAND && ! payload->status==OK_STATUS)
    {
        data = payload->data;

        #if (SCNSL_LOG >= 1)
                std::stringstream ss;
                ss << "Query finished";
                SCNSL_TRACE_LOG( 1, ss.str().c_str() );
        #endif
        //notify the end of query
        query_completed.notify(); //preghiamo che funzioni
    }
    else //btransport called with another command or error occurred
    {
        SCNSL_TRACE_ERROR( 1, "Invalid packet from server." );
        data = nullptr; //return null data, user has to take care of it
    }
}

// query for the data with specific id in the address space
const General_type_t* Client_Task_if::query(std::string & id){

    Opc_ua_payload_t * query_p = static_cast<Opc_ua_payload_t *>(malloc(sizeof(Opc_ua_payload_t)*sizeof(query_p)));

    query_p->sender_id = client_id+"_C"; //id_C same used during binding, must crete a class for automatic binding to server to avoid user to make itself and break program
    query_p->sender_time = sc_core::sc_time_stamp().to_double();
    query_p->data_id = id;
    query_p->command_type=QUERY_COMMAND;
    //useless data in query 
    query_p->data = nullptr;
    query_p->status=OK_STATUS; //starting the query, no use for the response flag

    //DEBUG PRINT, TO REMOVE IN FUTURE
    std::cout<<"[CLIENT "<<client_id<<"]:Sending query to server for id: "<<id<<std::endl;
    //////////////////////////////

    //use send primitive to query, always use first taskproxy since only one is created to the server (client doesn't communicate)
    TlmTask_if_t::send(0,reinterpret_cast<byte_t *>(query_p),sizeof(Opc_ua_payload_t));

    wait(query_completed); //wait for btransport to be invocated from server
    return data;
}
