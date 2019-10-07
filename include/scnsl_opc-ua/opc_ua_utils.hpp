#ifndef SCNSL_OPC_UA_UTILS_HPP
#define SCNSL_OPC_UA_UTILS_HPP


//utils objects and functions for both client-server and pubsub
namespace Scnsl{ namespace Opc_ua{

    //commad used between opc-ua services
    enum Opc_funct
    {
        QUERY_COMMAND,  //only for c-s architecture
        DATA_COMMAND,   //data from server/publisher
        SUBSCRIBE_COMMAND,  //add subscription
        PUBLISH_COMMAND,    //publish a data or add/update a variable in the address space
        OTHER_COMMAND //...
    };
}} 

#endif // SCNSL_OPC_UA_UTILS_HPP