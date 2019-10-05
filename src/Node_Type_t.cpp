#include "Node_type_t.hpp"

using namespace Scnsl::Opc_ua;

//constructor
template < typename T >
Node_type_t<T>::Node_type_t(std::string & name, T & data):
    General_type_t(name),
    data(data)
{}
//destructor
template <typename T>
Node_type_t<T>::~Node_type_t(){}
