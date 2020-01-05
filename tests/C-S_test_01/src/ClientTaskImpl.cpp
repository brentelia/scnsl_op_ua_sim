#include "ClientTaskImpl.hpp"

ClientTaskImpl::ClientTaskImpl(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n)
              throw():
    Client_Task_if(modulename,id,n)
{
    SC_THREAD( clientProcess ); //make random  query after some times 
}

ClientTaskImpl::~ClientTaskImpl()
{}

void ClientTaskImpl::clientProcess()
{
    std::string data_t[] = {"INT", "STRING", "DOUBLE"};
    int size = 3; //array size
    Scnsl::Opc_ua::General_type_t* response;
    while( 1 ){
        wait(std::rand()%500+1000,sc_core::SC_MS);  
        //switch (std::rand()%2/*size*/)
        //{
        //case 0:
        //    {
                std::cout<<"[Client "<<client_id<<"]:Sendig query for int (time: "<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
                response = query(data_t[0]);
                if(last_query_status == Scnsl::Opc_ua::DATA_NOT_FOUND_ERROR)
                    std::cout<<"Got no result, maybe response was not initialized yet: "<<std::endl;

                else{
                    //const Scnsl::Opc_ua::Node_type<int>* val = dynamic_cast<Scnsl::Opc_ua::Node_type<int>*>(response);
                    
                  //  assert((reinterpret_cast<Scnsl::Opc_ua::Node_type<int>*>(response))->get_data()<200 && (reinterpret_cast<Scnsl::Opc_ua::Node_type<int>*>(response))->get_data()>0);
                    std::cout<<"[Client "<<client_id<<"]Got result "<<
                    (reinterpret_cast<Scnsl::Opc_ua::Node_type<int>*>(response))->get_data()<<std::endl;
                }
      //      }
      //      break;
      /*  case 1:
            {
                std::cout<<"[Client "<<client_id<<"]:Sendig query for String (time:"<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
                response = query(data_t[1]);
                if(last_query_status == Scnsl::Opc_ua::DATA_NOT_FOUND_ERROR)
                    std::cout<<"Got no result, maybe response was not initialized yet "<<std::endl;
                else{
                //    const Scnsl::Opc_ua::Node_type<std::string>* val = dynamic_cast< Scnsl::Opc_ua::Node_type<std::string>*>(response);
                    std::cout<<"[Client "<<client_id<<"]Got result: "<<
                    (reinterpret_cast<Scnsl::Opc_ua::Node_type<std::string>*>(response))->get_data()<<std::endl;

                }
            }
            break;*/
        // case 1/*2*/:
            // {
                // std::cout<<"[Client "<<client_id<<"]:Sendig query for Struct (time:"<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
                // response = query(data_t[2]);
                // if(last_query_status == Scnsl::Opc_ua::DATA_NOT_FOUND_ERROR)
                    // std::cout<<"Got no result, maybe response was not initialized yet "<<std::endl;
                // else{
                   const Scnsl::Opc_ua::Node_type<double> *val = dynamic_cast<Scnsl::Opc_ua::Node_type<double>*>(response);
                    // std::cout<<"[Client "<<client_id<<"]Got result: "<<
                    // (reinterpret_cast<Scnsl::Opc_ua::Node_type<double>*>(response))->get_data()<<std::endl;
                // }
            // }
            // break;
        // default:
            // std::cout<<"Error"<<std::endl;
        // }
    }


}



