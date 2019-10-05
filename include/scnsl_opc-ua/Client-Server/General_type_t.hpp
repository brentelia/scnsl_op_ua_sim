#ifndef SCNSL_OPC_UA_GENERAL_TYPE_HPP
#define SCNSL_OPC_UA_GENERAL_TYPE_HPP

#include <string>

//general class for adress space types

namespace Scnsl{ namespace Opc_ua{
    
    class General_type_t{
        
        protected:
            General_type_t(std::string & name);
            virtual ~General_type_t();
        private:
            std::string type_name;
    };
}
}

#endif // SCNSL_OPC_UA_GENERAL_TYPE_HPP
