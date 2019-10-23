#include "ClientTaskImpl.hpp"
#include <stdio.h>

ClientTaskImpl::ClientTaskImpl(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n):
    Client_Task_if(modulename,id,n)
{
    SC_THREAD( clientProcess ); //make random  query after some times 
}

ClientTaskImpl::~ClientTaskImpl()
{}

void ClientTaskImpl::clientProcess()
{
    std::string data[] = {"INT", "STRING", "DOUBLE"};
    int size = 3; //array size

    while( 1 ){

        switch (std::rand()%size)
        {
        case 0:
            std::cout<<"[Client "<<client_id<<"]:Sendig query for int (time: "<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
            const Scnsl::Opc_ua::Node_type<int>* val = reinterpret_cast<const Scnsl::Opc_ua::Node_type<int>*> (query(data[0]));
            std::cout<<"Got result: "<<val->get_data()<<std::endl;
            break;
        case 1:
            std::cout<<"[Client "<<client_id<<"]:Sendig query for String"<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
            const Scnsl::Opc_ua::Node_type<std::string>* val = reinterpret_cast<const Scnsl::Opc_ua::Node_type<std::string>*> (query(data[1]));
            std::cout<<"Got result: "<<val->get_data()<<std::endl;
            break;
        case 2:
            std::cout<<"[Client "<<client_id<<"]:Sendig query for Struct"<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
            const Scnsl::Opc_ua::Node_type<double>* val = reinterpret_cast<const Scnsl::Opc_ua::Node_type<double>*> (query(data[2]));
            std::cout<<"Got result: "<<val->get_data()<<std::endl;
            break;
        default:
            std::cout<<"Error"<<endl;
            break;
        }
    }
    wait(std::rand()%500+500,sc_core::SC_MS);


}



