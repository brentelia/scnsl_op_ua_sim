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
    if(payload->command_type == DATA_COMMAND && payload->status==OK_STATUS)
    {
        last_query_status=OK_STATUS;
     //   if(payload->data == nullptr)
     //       std::cout<<"ERROR got nullptr on received data  "<<std::endl;
        //data = payload->data;
        //notify the end of query
    }
    else //btransport called with another command or error occurred
    {
        last_query_status=DATA_NOT_FOUND_ERROR;
        SCNSL_TRACE_ERROR( 1, "Invalid packet from server." );
        //data = null; //return null data, user has to take care of it
    }
    data = payload->data;
    std::cout<<"[CLIENT "<<client_id<<"]:Got response, unlocking"<<std::endl;
    query_completed.notify(); //preghiamo che funzioni

}

// query for the data with specific id in the address space
General_type_t* Client_Task_if::query(std::string & id){
    Opc_ua_payload_t * query_p = static_cast<Opc_ua_payload_t *>(new Opc_ua_payload_t());
    query_p->sender_id = std::to_string(client_id)+"_C"; //id_C same used during binding, must crete a class for automatic binding to server to avoid user to make itself and break program
    query_p->sender_time = sc_core::sc_time_stamp().to_double();
    query_p->data_id = id;
    query_p->command_type=QUERY_COMMAND;
    //useless data in query 
    //query_p->data = null;
    query_p->status=OK_STATUS; //starting the query, no use for the response flag

    //DEBUG PRINT, TO REMOVE IN FUTURE
  //  std::cout<<"[CLIENT "<<client_id<<"]:sender ID: "<<query_p->sender_id<<std::endl;
  //  std::cout<<"[CLIENT "<<client_id<<"]:Sending query to server for id: "<<id<<std::endl;
    //////////////////////////////

    //use send primitive to query, always use first taskproxy since only one is created to the server (client doesn't communicate)
    std::cout<<"[CLIENT "<<client_id<<"]:Waiting for response ..."<<std::endl;
    TlmTask_if_t::send(std::to_string(client_id)+"_C",reinterpret_cast<byte_t *>(query_p),sizeof(Opc_ua_payload_t));
    wait(query_completed); //wait for btransport to be invocated from server
    return data;
}
