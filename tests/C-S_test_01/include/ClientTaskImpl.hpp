#ifndef CLIENT_TASK_IMPL_HPP
#define CLIENT_TASK_IMPL_HPP


#include <systemc>
#include <scnsl.hh>
#include <scnsl_opc-ua.hpp>
#include <stdio.h>
#include "ServerTaskImpl.hpp"
/////
#include<cassert>
///////


class ClientTaskImpl: public Scnsl::Opc_ua::Client_Task_if
{
    public:
        SC_HAS_PROCESS( ClientTaskImpl );
        ClientTaskImpl(const sc_core::sc_module_name modulename,
                const task_id_t id,
                Scnsl::Core::Node_t * n)
                throw();
        virtual ~ClientTaskImpl() throw();
    private:
//        void makequery();
        virtual void clientProcess();
        ClientTaskImpl( const ClientTaskImpl &);
        ClientTaskImpl & operator = (ClientTaskImpl &);
        friend class ServerTaskImpl;   //needed   
}; 

#endif 