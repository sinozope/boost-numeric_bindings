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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_DOTU_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_DOTU_HPP

#include <boost/numeric/bindings/blas/blas.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

//$DESCRIPTION

// overloaded functions to call blas
namespace detail {
    inline fcomplex_t dotu( integer_t const n, traits::complex_f* x,
            integer_t const incx, traits::complex_f* y,
            integer_t const incy ) {
        return BLAS_CDOTU( &n, traits::complex_ptr(x), &incx,
                traits::complex_ptr(y), &incy );
    }
    inline dcomplex_t dotu( integer_t const n, traits::complex_d* x,
            integer_t const incx, traits::complex_d* y,
            integer_t const incy ) {
        return BLAS_ZDOTU( &n, traits::complex_ptr(x), &incx,
                traits::complex_ptr(y), &incy );
    }
}

// value-type based template
template< typename ValueType >
struct dotu_impl {

    typedef ValueType value_type;
    typedef value_type return_type;

    // templated specialization
    template< typename VectorX, typename VectorY >
    static return_type compute( VectorX& x, VectorY& y ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorX >::value_type, typename traits::vector_traits<
                VectorY >::value_type >::value) );
        return detail::dotu( traits::vector_size(x),
                traits::vector_storage(x), traits::vector_stride(x),
                traits::vector_storage(y), traits::vector_stride(y) );
    }
};

// template function to call dotu
template< typename VectorX, typename VectorY >
inline typename dotu_impl< typename traits::vector_traits<
        VectorX >::value_type >::return_type
dotu( VectorX& x, VectorY& y ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    return dotu_impl< value_type >::compute( x, y );
}

}}}} // namespace boost::numeric::bindings::blas

#endif
