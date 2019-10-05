#ifndef SCNSL_OPC_UA_NODE_TYPE_T_HPP
#define SCNSL_OPC_UA_NODE_TYPE_T_HPP

#include "General_type_t.hpp"

//class with a real type in the adress space

namespace Scnsl{ namespace Opc_ua{

    template < typename T >
    class Node_type_t: public Scnsl::Opc_ua::General_Type_t
    {
        public:
            Node_type_t(std::string & name, T & data);
            T & get_data();
        private:
            T & data;
    };
}}

#endif // SCNSL_OPC_UA_NODE_TYPE_T_HPP