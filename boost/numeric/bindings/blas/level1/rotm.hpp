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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL1_ROTM_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL1_ROTM_HPP

#include <boost/numeric/bindings/blas/detail/blas.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {
namespace level1 {

// overloaded functions to call blas
namespace detail {
    inline void rotm( integer_t const n, float* x, integer_t const incx,
            float* y, integer_t const incy, float* param ) {
        BLAS_SROTM( &n, x, &incx, y, &incy, param );
    }
    inline void rotm( integer_t const n, double* x, integer_t const incx,
            double* y, integer_t const incy, double* param ) {
        BLAS_DROTM( &n, x, &incx, y, &incy, param );
    }
}

// value-type based template
template< typename ValueType >
struct rotm_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // templated specialization
    template< typename VectorX, typename VectorY, typename VectorPARAM >
    static return_type invoke( integer_t const n, VectorX& x,
            integer_t const incx, VectorY& y, integer_t const incy,
            VectorPARAM& param ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorX >::value_type, typename traits::vector_traits<
                VectorY >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorX >::value_type, typename traits::vector_traits<
                VectorPARAM >::value_type >::value) );
        detail::rotm( n, traits::vector_storage(x), incx,
                traits::vector_storage(y), incy,
                traits::vector_storage(param) );
    }
};

// low-level template function for direct calls to level1::rotm
template< typename VectorX, typename VectorY, typename VectorPARAM >
inline typename rotm_impl< typename traits::vector_traits<
        VectorX >::value_type >::return_type
rotm( integer_t const n, VectorX& x, integer_t const incx, VectorY& y,
        integer_t const incy, VectorPARAM& param ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    rotm_impl< value_type >::invoke( n, x, incx, y, incy, param );
}

}}}}} // namespace boost::numeric::bindings::blas::level1

#endif
