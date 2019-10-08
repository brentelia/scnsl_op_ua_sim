#include "Node_type.hpp"

using namespace Scnsl::Opc_ua;

//constructor
template < typename T >
Node_type<T>::Node_type(std::string & name, T & data):
    General_type_t(name),
    data(data)
{}

template <typename T>
T& Node_type<T>::get_data() const
{
    return data;
}