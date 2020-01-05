#ifndef NODE_HPP
#define NODE_HPP

#include <systemc>
#include <scnsl.hh>
#include <cstdint>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include "../scnsl_opc-ua.hpp"

namespace Scnsl
{
namespace Opc_ua
{

struct NodeId
{
    Scnsl::Opc_ua::int16 namespace_index;
    Scnsl::Opc_ua::Opc_Id_Type Id_type; //type of following id (used also for parsing reasons)
    std::string id;
    //overload operator == and < to use in hashmap
    bool operator==(NodeId const &other) const;
    bool operator<(NodeId const &other) const;
};

/***
 * A node in the address space. Each node is identified by his nodeId.
 * A node can store a single data (an attribute node) which is represented as a string of byte.
 * THe data is encoded using the standard rules in section 6.0 Mappings. The node type represent the real type 
 * of the data and the size the number of elements (1= a single data, >1 an array of data).
 * To get the effective value it is necessary to call the right parsing function
*/
class Node
{
private:
    NodeId Id;
    Opc_data_types type;
    unsigned int size;              // the effective number of data stored
    unsigned char *data;            //data encoded into byte vector using standard rules
    std::vector<Node *> references; //node's parent in the tree;

    Node(const Node &);
    Node &operator=(Node &);

public:
    //getters
    NodeId getNodeId();
    Opc_data_types get_data_type();
    unsigned int get_size();
    unsigned char *get_data();
    std::vector<Node *> get_references();

    //setters
    void set_data(unsigned char* new_data);
    void set_size(unsigned int new_size);

    //destructor
    ~Node();
    //constructor
    //TODO implementare verifica Guid / generazione randomica
    Node(NodeId id, Opc_data_types type, unsigned int size, unsigned char *data, std::vector<Node *> references);
}

} // namespace Opc_ua
} // namespace Scnsl
#endif // !NODE_HPP
