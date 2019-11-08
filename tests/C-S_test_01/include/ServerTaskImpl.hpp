#ifndef SERVER_TASK_IMPL_HPP
#define SERVER_TASK_IMPL_HPP

#include <systemc>
#include <scnsl.hh>
#include <scnsl_opc-ua.hpp>
#include <stdio.h>
#include <array>
#include <random>
#include "ClientTaskImpl.hpp"

class ServerTaskImpl: public Scnsl::Opc_ua::Server_Task_if
{
    public:
        SC_HAS_PROCESS( ServerTaskImpl );
        ServerTaskImpl(const sc_core::sc_module_name modulename,
                const task_id_t id,
                Scnsl::Core::Node_t * n,
                const size_t proxies)    //need number of client conneted
                throw();
        virtual ~ServerTaskImpl() throw();
    private:
//        void makequery();
        virtual void serverProcess();
        ServerTaskImpl( const ServerTaskImpl &);
        ServerTaskImpl & operator = (ServerTaskImpl &);
        friend class ClientTaskImpl;   //needed   
}; 

#endif 