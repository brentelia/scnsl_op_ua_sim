#include "Server_Task_if.hpp"

using namespace Scnsl::Opc_ua;
using namespace Scnsl::Tlm;

//constructor
Server_Task_if::Server_Task_if(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n,
              const size_t proxies):
    TlmTask_if_t( modulename, id, n, proxies ),
    server_id(id),
    _Address_space()
{}

//btransport called by the client, need to know what kind of service must be offered and if we need to responde back 
void Server_Task_if::b_transport( tlm::tlm_generic_payload & p, sc_core::sc_time & t )
{
    //get data pointer
    Opc_ua_payload_t* payload = ((Opc_ua_payload_t*)p.get_data_ptr());
    //different requests
    switch (payload->command_type)
    {
    case QUERY_COMMAND: //query from a client;
        query_solve(payload->sender_id, payload->data_id);
        break;
    case PUBLISH_COMMAND:
        add_variable(payload->data_id, *payload->data);
    //OTHER CASE IN FUTURE
    default:
        SCNSL_TRACE_ERROR( 1, "Invalid command received." );
        break;
    }
}

//check in address space for request id
void Server_Task_if::query_solve(std::string & client_id, std::string & object_id){
 
    Opc_ua_payload_t * query_p = static_cast<Opc_ua_payload_t *>(malloc(sizeof(Opc_ua_payload_t)*sizeof(query_p)));

    query_p->sender_id = server_id+"_S"; //id_C same used during binding, must crete a class for automatic binding to server to avoid user to make itself and break program
    query_p->sender_time = sc_core::sc_time_stamp().to_double();
    query_p->data_id = object_id;
    query_p->command_type=DATA_COMMAND;
    
    if(_Address_space.find(object_id)==_Address_space.end()){ //not found 
        query_p->data=nullptr;
        query_p->status=DATA_NOT_FOUND_ERROR;
    }
    else {
        query_p->data = & _Address_space[object_id];
        query_p->status=OK_STATUS;
    }
        //DEBUG PRINT, TO REMOVE IN FUTURE
    std::cout<<"[SERVER "<<server_id<<"]:Sending response for client: "<<client_id<<std::endl;
    //////////////////////////////
    //use send primitive 
    TlmTask_if_t::send(client_id,reinterpret_cast<byte_t *>(query_p),sizeof(Opc_ua_payload_t));
}

void Server_Task_if::add_variable (std::string & name,Scnsl::Opc_ua::General_type_t  variable)
{
    _Address_space[name]=variable;        
}
