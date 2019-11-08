#include "scnsl_opc-ua.hpp"
#include "scnsl_opc-ua/Node_type.hpp"
using namespace Scnsl::Opc_ua;

//constructor
template < typename T >
Node_type<T>::Node_type(T & data):
    General_type_t(),
    data(data)
{}

template <typename T>
T& Node_type<T>::get_data() const
{
    return data;
}