#ifndef SCNSL_OPC_UA_NODE_TYPE_HPP
#define SCNSL_OPC_UA_NODE_TYPE_HPP

#include "General_type_t.hpp"

//class with a real type in the adress space

namespace Scnsl{ namespace Opc_ua{

    template < typename T >
    class Node_type: public Scnsl::Opc_ua::General_type_t
    {
        public:
            Node_type( T & data);
            T & get_data() const;
        private:
            T & data;
    };
}}

#endif // SCNSL_OPC_UA_NODE_TYPE_HPP