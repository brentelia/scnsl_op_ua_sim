#ifndef SCNSL_OPC_UA_CLIENT_TASK_IF_HPP
#define SCNSL_OPC_UA_CLIENT_TASK_IF_HPP

//Client task for opc ua simulation
#include <systemc.h>
#include <scnsl.hh>
#include <stdio.h>
#include <iostream>
#include <tlm>
#include "Opc-ua_payload.hpp"
#include "Server_Task_if.hpp"
    
// namespace Scnsl  

namespace Scnsl{ namespace Opc_ua {

    //client class
    class SCNSL_EXPORT Client_Task_if:
        public Scnsl::Tlm::TlmTask_if_t
    {
    public:        
        //virtual pure destructor
        virtual ~Client_Task_if() = 0;
        
        //pure virtual function to be implemented in the real client task
        virtual void clientProcess() =0;
   
    protected:
    
        //counstructor
        Client_Task_if(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n)
              //const size_t proxies ) not necessary since client are bounded to one server
        throw();
        
        //query method to defautl server
        virtual const General_type_t* query(std::string & object) final;
        unsigned int client_id;

    private:

        sc_event query_completed;   //event to notify the end of the query

        General_type_t* data;

        //disable copy constructor and assignment operator
        Client_Task_if(const Client_Task_if &);

        Client_Task_if & operator = (Client_Task_if &);

        // private function wrapped in query method
        void b_transport( tlm::tlm_generic_payload & p, sc_core::sc_time & t );

        //allow server to call btrasport to respond query and at the same time keep the method private
        //friend class Server_Task_if; //must be forced in the implementation or move the method to public 
        
    };
    
}
}

#endif // SCNSL_OPC_UA_CLIENT_TASK_IF_HPP   