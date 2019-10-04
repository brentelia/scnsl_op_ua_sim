#ifndef SCNSL_OPC_UA_CLIENT_TASK_IF_HPP
#define SCNSL_OPC_UA_CLIENT_TASK_IF_HPP

//Client task for opc ua simulation
#include <systemc>
#include <scnsl.hh>
#include <stdio.h>
namespace Scnsl { namespace Opc_ua{
    class Server_Task_t;
}
    
} // namespace Scnsl 
 

namespace Scnsl{ namespace Opc_ua {

    //client class
    class Client_Task_if:
        public Scnsl::Tlm::TlmTask_if_t
    {
    public:
        
        typedef Scnsl::Opc_ua::Server_Task_t Server_t;
        
        //virtual impure destructor
        virtual ~Client_Task_if() throw();
        
        //pure virtual function to be implemented in the real client task
        virtual void ClientProcess() =0;

        void setServer(Server_t & server); 
   
    protected:
    
        //counstructor
        Client_Task_if(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n,
              const size_t proxies )
        throw();
        
        //query method to specific server
        void* query( Server_t& server, std::string & object);

        //query method to defautl server
        void* query();



    private:
        //default server for this client
        Server_t & def_sever;
        // private function wrapped in query method
        virtual void b_transport( tlm::tlm_generic_payload & p, sc_core::sc_time & t );
        
    };
    
}}

#endif // SCNSL_OPC_UA_CLIENT_TASK_IF_HPP   