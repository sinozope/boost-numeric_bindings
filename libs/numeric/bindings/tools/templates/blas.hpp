$TEMPLATE[blas.hpp]
//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_$GROUPNAME_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_$GROUPNAME_HPP

$INCLUDES

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

//$DESCRIPTION

// overloaded functions to call blas
namespace detail {
$OVERLOADS}

$LEVEL1
$LEVEL2
}}}} // namespace boost::numeric::bindings::blas

#endif
$TEMPLATE[blas_overloads]
    inline $RETURN_TYPE $groupname( $LEVEL0 ) {
        $RETURN_STATEMENTBLAS_$SUBROUTINE( $CALL_C_HEADER );
    }
$TEMPLATE[blas_level1]
// value-type based template
template< typename ValueType >
struct $groupname_impl {

    typedef ValueType value_type;
    typedef $RETURN_TYPE return_type;

    // templated specialization
    template< $TYPES >
    static return_type compute( $LEVEL1 ) {
        $RETURN_STATEMENTdetail::$groupname( $CALL_LEVEL0 );
    }
};
$TEMPLATE[blas_level2]
// template function to call $groupname
template< $TYPES >
inline integer_t $groupname( $LEVEL2 ) {
    typedef typename traits::$TYPEOF_FIRST_TYPENAME_traits< $FIRST_TYPENAME >::value_type value_type;
    $RETURN_STATEMENT$groupname_impl< value_type >::compute( $CALL_LEVEL1 );
}

$TEMPLATE[end]
