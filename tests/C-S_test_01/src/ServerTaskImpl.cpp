#include "ServerTaskImpl.hpp"

ServerTaskImpl::ServerTaskImpl(const sc_core::sc_module_name modulename,
              const task_id_t id,
              Scnsl::Core::Node_t * n,
              const size_t proxies)
              throw():
    Server_Task_if(modulename,id,n,proxies)
{
    SC_THREAD( serverProcess ); //make random  query after some times
}

ServerTaskImpl::~ServerTaskImpl()
{}

void ServerTaskImpl::serverProcess()
{
    std::array<std::string,3> data_t = {"INT", "STRING", "DOUBLE"};
    std::array<std::string,6> words= {"Armadillo", "Calendario", "Ornitorinco","Monotono","Esplosivo","Villa"};

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(10.0, 30.0);
    int startInt=0;
    std::string startString = "hgfhfu";
    double startD=0.0;
    add_variable(data_t[0], *(new Scnsl::Opc_ua::Node_type<int> (startInt)));
    add_variable(data_t[1], *(new Scnsl::Opc_ua::Node_type<std::string> (startString)));
    add_variable(data_t[2], *(new Scnsl::Opc_ua::Node_type<double> (startD)));
    while( 1 ){
        wait(std::rand()%500+500,sc_core::SC_MS);
        switch (std::rand()% data_t.size())
        {
        case 0:
            {
                int val_int = std::rand() %200;
                
                Scnsl::Opc_ua::General_type_t  val = *(new Scnsl::Opc_ua::Node_type<int> (val_int)); //creating a general type to add
                //a destructor should be called somewhere  
                
                std::cout<<"\t[Server "<<server_id<<"]:Setting data_t for int (time: "<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
                add_variable(data_t[0], val);
            }    
            break;
        case 1:
            {
                int word = std::rand() % words.size();
                
                Scnsl::Opc_ua::General_type_t  val = *(new Scnsl::Opc_ua::Node_type<std::string> (words[word])); //creating a general type to add
                //a destructor should be called somewhere  
                
                std::cout<<"\t[Server "<<server_id<<"]:Setting data_t for String (time: "<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
                add_variable(data_t[1], val);
            }
            break;
        case 2:
            {
                double value= dis(gen);
                
                Scnsl::Opc_ua::General_type_t  val = *(new Scnsl::Opc_ua::Node_type<double> (value)); //creating a general type to add
                //a destructor should be called somewhere  
                
                std::cout<<"\t[Server "<<server_id<<"]:Setting data_t for Double (time: "<<sc_core::sc_time_stamp().to_double()*1e-9<<")"<<std::endl;
                add_variable(data_t[2], val);
            }
            break;
        default:
            std::cout<<"Error"<<std::endl;
            break;
        }
    }
}



