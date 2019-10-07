#ifndef OPC_UA_PAYLOAD_HPP
#define OPC_UA_PAYLOAD_HPP
//payload struct for OPC_UA services data exchange
#include <string>
#include"opc_ua_utils.hpp"

struct Opc_ua_payload_t
{
	std::string sender_id;		//id used to send message back	
	double sender_time;
	Scnsl::Opc_ua::Opc_funct command_type; //which function the payload represent
   
   	std::string data_id; //id in server address space for query
	
	General_type_t* data; //data sent

	//****other fields for pubsub*****	
	bool not_found_flag; // server cannot find the id requested; 	 
};

#endif // OPC_UA_PAYLOAD_HPP
