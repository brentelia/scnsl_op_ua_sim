#include "scnsl_opc-ua/Node.hpp"

using namespace Scnsl::Opc_ua;
/**
 * 
 * NODE_ID CLASS
 * 
*/
bool NodeId::operator<(NodeId const &other) const
{
    if (namespace_index == other.namespace_index)
    {
        if (Id_type == other.Id_type)
            return id < other.id;
        return Id_type < other.Id_type;
    }
    return namespace_index < other.namespace_index;
}

/**
 * 
 *  NODE CLASS 
 * 
*/
bool NodeId::operator==(NodeId const &other) const
{
    return namespace_index == other.namespace_index &&
           Id_type == other.Id_type && id == other.id;
}

Node::Node(NodeId id, Opc_data_types type, unsigned int size, unsigned char *data, std::vector<Node *> references)
    : Id(id), type(type), size(size), data(data), references(references)
{
}

Node::~Node() {}
/**
 * GETTERS
*/
NodeId Node::getNodeId()
{
    return Id;
}
Opc_data_types Node::get_data_type()
{
    return type;
}
unsigned int Node::get_size()
{
    return size;
}
unsigned char *Node::get_data()
{
    return data;
}
std::vector<Node *> Node::get_references()
{
    return references;
}
/**
 * SETTERS
*/ 

void Node::set_data(unsigned char * new_data){
    data = new_data;
}

void Node::set_size(unsigned int new_size){
    size=new_size;
}