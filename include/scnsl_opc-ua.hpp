#ifndef SCNSL_OPC_UA_HPP
#define SCNSL_OPC_UA_HPP

// namespace generale, contiene 2 namespace, uno per client-server e uno per 
//pubsub

#include "scnsl/core/Task_if_t.hh"
#include "scnsl_opc-ua/Opc-ua_payload.hpp"
#include "scnsl_opc-ua/Client-Server/Client_Sub_Task_t.hpp"
#include "scnsl_opc-ua/Client-Server/Client_Task_if.hpp"
#include "scnsl_opc-ua/General_type_t.hpp"
#include "scnsl_opc-ua/Node_type.hpp"
#include "scnsl_opc-ua/Client-Server/Server_Task_if.hpp"



namespace Scnsl{
    //namespace per applicazioni client_server
    namespace Opc_ua{}
}

#endif //SCNSL_OPC_UA_HPP