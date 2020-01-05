#ifndef SCNSL_OPC_UA_UTILS_HPP
#define SCNSL_OPC_UA_UTILS_HPP

#include <cstdint>
#include <string>
#include <sstream>
#include <cstring>

//utils objects and functions for both client-server and pubsub
namespace Scnsl
{
namespace Opc_ua
{

//commad used between opc-ua services
enum Opc_funct
{
    QUERY_COMMAND,     //only for c-s architecture
    DATA_COMMAND,      //data from server/publisher
    SUBSCRIBE_COMMAND, //add subscription
    PUBLISH_COMMAND,   //publish a data or add/update a variable in the address space
    OTHER_COMMAND      //...
};

//status of the message
enum Opc_message_status
{
    OK_STATUS,
    GENERIC_ERROR,
    DATA_NOT_FOUND_ERROR
};

enum Opc_Id_Type
{
    NUMERIC_0, //int
    STRING_1,  //string
    GUID_2,    //specific format string
    OPAQUE_3   //bytestring
};

//DataTypes that can be insert into address space nodes. Each one requiere a sepcific parsing function
enum Opc_data_types
{
    BOOLEAN,
    SBYTE, //int8
    BYTE,  //uint8
    INT16,
    UINT16,
    INT32,
    UINT32,
    INT64,
    UINT64,
    FLOAT,
    DOUBLE,
    STRING,
    DATETIME,
    GUID,
    BYTESTRING,
    XML_ELEMENT,
    NODEID,
    //...
};

//OPC UA type definitions

typedef int8_t sbyte;
typedef uint8_t byte;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
typedef int64 datetime;
typedef std::string guid;
typedef std::string xml_element;

typedef unsigned char byteVector;

/**
 * Encoding function. The function create a byte array using the standard's rules 
 * to encode data. 
 * The encde is done using the type variable inside the node. 
*/
byteVector *encode(bool data);
byteVector *encode(sbyte data);
byteVector *encode(byte data);
byteVector *encode(int16 data);
byteVector *encode(uint16 data);
byteVector *encode(int32 data);
byteVector *encode(uint32 data);
byteVector *encode(int64 data);
byteVector *encode(uint64 data);
byteVector *encode(float data);
byteVector *encode(double data);
byteVector *encode(std::string data);
byteVector *encode(datetime data);
byteVector *encode(guid data);
byteVector *encode(xml_element data);

/**
 * DECODE FUNCTIONS
 * A function to decode each type is needed since different types have differents encoding
 * To reduce the number, types which are similar are decoded the same way.
*/

bool decode_Bool(byteVector *data);
sbyte decode_Sbyte(byteVector *data);
byte decode_Byte(byteVector *data);
int16 decode_Int16(byteVector *data);
uint16 decode_UInt16(byteVector *data);
int32 decode_Int32(byteVector *data);
uint32 decode_UInt32(byteVector *data);
int64 decode_Int64(byteVector *data);
uint64 decode_UInt64(byteVector *data);
float decode_Float(byteVector *data);
double decode_Double(byteVector *data);
std::string decode_String(byteVector *data);
datetime decode_DateTime(byteVector *data);
guid decode_Guid(byteVector *data);
xml_element decode_XML(byteVector *data);

} // namespace Opc_ua
} // namespace Scnsl

#endif // SCNSL_OPC_UA_UTILS_HPP