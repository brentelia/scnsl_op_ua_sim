#include "scnsl_opc-ua/Opc_ua_utils.hpp"

using namespace Scnsl::Opc_ua;

/**
 * ENCODE USING STANDARD RULES 
 * 
 * 
*/
byteVector *encode(bool data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte));
    enc[0] = data;
    return enc;
}

byteVector *encode(sbyte data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte));
    enc[0] = data;
    return enc;
}

byteVector *encode(byte data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte));
    enc[0] = data;
    return enc;
}

byteVector *encode(int16 data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte) * 2);
    //conversion
    memcpy(enc, &data, sizeof(int16));
    return enc;
}

byteVector *encode(uint16 data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte) * 2);
    //conversion
    memcpy(enc, &data, sizeof(uint16));

    return enc;
}

byteVector *encode(int32 data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte) * 4);
    memcpy(enc, &data, sizeof(int32));
    return enc;
}

byteVector *encode(uint32 data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte) * 4);
    memcpy(enc, &data, sizeof(uint32));
    return enc;
}

byteVector *encode(int64 data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte) * 8);
    memcpy(enc, &data, sizeof(int64));
    return enc;
}

byteVector *encode(uint64 data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(byte) * 8);
    memcpy(enc, &data, sizeof(uint64));
    return enc;
}

byteVector *encode(float data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(float));
    memcpy(enc, &data, sizeof(float));
    return enc;
}
byteVector *encode(double data)
{
    byteVector *enc = (byteVector *)calloc(1, sizeof(double));
    memcpy(enc, &data, sizeof(double));
    return enc;
}

/**
 *Encoding rule for string state that first byte are used to store a int32 with string lenght
 other byes are used to store the string 
*/

byteVector *encode(std::string data)
{
    byteVector *enc = (byteVector *)calloc(data.length() + 4, sizeof(byte)); //+4 byte for lenght
    int len = data.length();
    if (len != 0)
    {
        memcpy(enc, &len, sizeof(int));
        for (int i = 0; i < len; i++)
            enc[i + 4] = data[i];
    }
    else
    {
        len = -1; //null string has lenght -1 and no other data
        memcpy(enc, &len, sizeof(int));
    }
    return enc;
}

byteVector *encode(datetime data)
{
    int64 timevalue = data;
    byteVector *enc = Scnsl::Opc_ua::encode(timevalue);
}

byteVector *encode(guid data)
{
    int enc_pos = 0;
    std::string sub;
    byteVector *enc = (byteVector *)calloc(16, sizeof(byte));
    char c;
    int v;
    for (int i = 7; i > 0; i -= 2)
    {
        sub = data.substr(i - 1, 2);
        v = std::stoi(sub, nullptr, 16);
        enc[enc_pos++] = v;
    }
    for (int i = 12; i > 9; i -= 2)
    {
        sub = data.substr(i - 1, 2);
        v = std::stoi(sub, nullptr, 16);
        enc[enc_pos++] = v;
    }
    for (int i = 17; i > 14; i -= 2)
    {
        sub = data.substr(i - 1, 2);
        v = std::stoi(sub, nullptr, 16);
        enc[enc_pos++] = v;
    }
    for (int i = 19; i < 22; i += 2)
    {
        sub = data.substr(i, 2);
        v = std::stoi(sub, nullptr, 16);
        enc[enc_pos++] = v;
    }
    for (int i = 24; i < 35; i += 2)
    {
        sub = data.substr(i, 2);
        v = std::stoi(sub, nullptr, 16);
        enc[enc_pos++] = v;
    }
    return enc;
}

byteVector *encode(xml_element data)
{
    std::string xml_string = data;
    byteVector *enc = Scnsl::Opc_ua::encode(xml_string);
    return enc;
}

/**
 * 
 * DECODE USING STANDARD RULES IN REVERSE WAY 
 * 
*/
bool decode_Bool(byteVector *data)
{
    bool value = data[0];
    return value;
}

sbyte decode_Sbyte(byteVector *data)
{
    sbyte value = data[0];
    return value;
}

byte decode_Byte(byteVector *data)
{
    byte value = data[0];
    return value;
}

int16 decode_Int16(byteVector *data)
{
    int16 value;
    memcpy(&value, data, sizeof(int16));
    return value;
}

uint16 decode_UInt16(byteVector *data)
{
    uint16 value;
    memcpy(&value, data, sizeof(uint16));
    return value;
}

int32 decode_Int32(byteVector *data)
{
    int32 value;
    memcpy(&value, data, sizeof(int32));
    return value;
}

uint32 decode_UInt32(byteVector *data)
{
    uint32 value;
    memcpy(&value, data, sizeof(uint32));
    return value;
}

int64 decode_Int64(byteVector *data)
{
    int64 value;
    memcpy(&value, data, sizeof(int64));
    return value;
}

uint64 decode_UInt64(byteVector *data)
{
    uint64 value;
    memcpy(&value, data, sizeof(uint64));
    return value;
}

float decode_Float(byteVector *data)
{
    float value;
    memcpy(&value, data, sizeof(float));
    return value;
}

double decode_Double(byteVector *data)
{
    double value;
    memcpy(&value, data, sizeof(double));
    return value;
}

std::string decode_String(byteVector *data)
{
    int len2;
    memcpy(&len2, data, sizeof(int)); //get string length from fist 4 byte of message
    std::string value(reinterpret_cast<char *>(data + 4), len2);
    return value;
}

datetime decode_DateTime(byteVector *data)
{
    datetime value = Scnsl::Opc_ua::decode_Int64(data);
    return value;
}

guid decode_Guid(byteVector *data)
{

    std::stringstream stream;
    for (int i = 3; i >= 0; i--)
        stream << std::hex << static_cast<int>(data[i]);
    stream << '-';
    for (int i = 5; i >= 4; i--)
        stream << std::hex << static_cast<int>(data[i]);
    stream << '-';
    for (int i = 7; i >= 6; i--)
        stream << std::hex << static_cast<int>(data[i]);
    stream << '-';
    for (int i = 8; i <= 9; i++)
        stream << std::hex << static_cast<int>(data[i]);
    stream << '-';
    for (int i = 10; i < 16; i++)
        stream << std::hex << static_cast<int>(data[i]);
    std::string value(stream.str());
    return value;
}

xml_element decode_XML(byteVector *data)
{
    xml_element value = Scnsl::Opc_ua::decode_String(data);
    return value;
}

/**
 * #include <map>
#include <string>
#include <iostream>
#include<stdio.h>
#include <cstdint>
#include <bitset>

typedef int8_t sbyte;
typedef uint8_t byte;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int int32;
typedef byteVector int uint32;
typedef long long int int64;
typedef byteVector long long int uint64;


int main() {
    int64 val = -9223372036854775808;
   // std::cout<<std::hex<<val<<std::endl;
    byteVector arr[8];
    //conversion
    for(int i=0; i<8; i++)
        arr[i]= val>>(8*i) & 0xFF;
    
    for(int i=0;i<8;i++)
        std::cout<<static_cast<int64>(arr[i])<<std::endl;
    
    byteVector* vect= arr;

    int64 val2=0;
    int64 app;
    for(int i=0;i<8;i++){
        app=vect[i];
        val2+= (app<<(i*8));
        std::cout<<static_cast<int64>(app<<(i*8))<<std::endl;
    }

    std::cout<<val2;

}
*/