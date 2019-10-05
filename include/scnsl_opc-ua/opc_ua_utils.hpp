#ifndef SCNSL_OPC_UA_UTILS_HPP
#define SCNSL_OPC_UA_UTILS_HPP


//utils objects and functions for both client-server and pubsub
namespace Scnsl{ namespace Opc_ua{

    //commad used between opc-ua services
    enum Opc_funct
    {
        QUERY_COMMAND,  //only for c-s architecture
        DATA_COMMAND,
        SUBSCRIBE_COMMAND,
        PUBLISH_COMMAND,
        OTHER_COMMAND
    };
}} 

#endif // SCNSL_OPC_UA_UTILS_HPP