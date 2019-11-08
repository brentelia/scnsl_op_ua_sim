#ifndef SCNSL_OPC_UA_SERVER_TASK_IF_HPP
#define SCNSL_OPC_UA_SERVER_TASK_IF_HPP

//Client task for opc ua simulation
#include <systemc>
#include <scnsl.hh>
#include <stdio.h>
#include <iostream>
#include <tlm.h>
#include <map>
#include "../Opc_ua_payload.hpp"
#include "../General_type_t.hpp"
#include "Client_Task_if.hpp"

    
// namespace Scnsl  

namespace Scnsl{ namespace Opc_ua {

    //Server class
    class SCNSL_EXPORT Server_Task_if:
        public Scnsl::Tlm::TlmTask_if_t
    {
    public:        
        //virtual pure destructor
        virtual ~Server_Task_if() = 0;
        
        //pure virtual function to be implemented in the real client task
        virtual void serverProcess() =0;

   
    protected:
    
        //counstructor
        Server_Task_if(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n,
              const size_t proxies)    //need number of client conneted
        throw();
        
        //meyhod to resolve the query
        virtual void query_solve(std::string & client_id,std::string & object) final;
        unsigned int server_id;
        void add_variable (std::string & name,Scnsl::Opc_ua::General_type_t & variable);

    private:

        //sc_event query_completed;   //event to notify the end of the query

        //The server adress space
        std::map<std::string, Scnsl::Opc_ua::General_type_t  > _Address_space;
        //<
        void* data;

        //disable copy constructor and assignment operator
        Server_Task_if(const Server_Task_if &);
        Server_Task_if & operator = (Server_Task_if &);

        // private function, called from the client thanks to friend keyword
        void b_transport( tlm::tlm_generic_payload & p, sc_core::sc_time & t );

        
        //friend class Scnsl::Opc_ua::Client_Task_if; //must be forced in the implementation or move the method to public 
        //MACRO maybe?
    };
    
}
}

#endif // SCNSL_OPC_UA_SERVER_TASK_IF_HPP   