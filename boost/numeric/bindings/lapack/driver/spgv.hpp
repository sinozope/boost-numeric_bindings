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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SPGV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SPGV_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void spgv( integer_t const itype, char const jobz, char const uplo,
            integer_t const n, float* ap, float* bp, float* w, float* z,
            integer_t const ldz, float* work, integer_t& info ) {
        LAPACK_SSPGV( &itype, &jobz, &uplo, &n, ap, bp, w, z, &ldz, work,
                &info );
    }
    inline void spgv( integer_t const itype, char const jobz, char const uplo,
            integer_t const n, double* ap, double* bp, double* w, double* z,
            integer_t const ldz, double* work, integer_t& info ) {
        LAPACK_DSPGV( &itype, &jobz, &uplo, &n, ap, bp, w, z, &ldz, work,
                &info );
    }
}

// value-type based template
template< typename ValueType >
struct spgv_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAP, typename MatrixBP, typename VectorW,
            typename MatrixZ, typename WORK >
    static void invoke( integer_t const itype, char const jobz,
            integer_t const n, MatrixAP& ap, MatrixBP& bp, VectorW& w,
            MatrixZ& z, integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixBP >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::vector_traits<
                VectorW >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( traits::matrix_uplo_tag(ap) == 'U' ||
                traits::matrix_uplo_tag(ap) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        detail::spgv( itype, jobz, traits::matrix_uplo_tag(ap), n,
                traits::matrix_storage(ap), traits::matrix_storage(bp),
                traits::vector_storage(w), traits::matrix_storage(z),
                traits::leading_dimension(z),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAP, typename MatrixBP, typename VectorW,
            typename MatrixZ >
    static void invoke( integer_t const itype, char const jobz,
            integer_t const n, MatrixAP& ap, MatrixBP& bp, VectorW& w,
            MatrixZ& z, integer_t& info, minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        invoke( itype, jobz, n, ap, bp, w, z, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixAP, typename MatrixBP, typename VectorW,
            typename MatrixZ >
    static void invoke( integer_t const itype, char const jobz,
            integer_t const n, MatrixAP& ap, MatrixBP& bp, VectorW& w,
            MatrixZ& z, integer_t& info, optimal_workspace work ) {
        invoke( itype, jobz, n, ap, bp, w, z, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 3*n;
    }
};


// template function to call spgv
template< typename MatrixAP, typename MatrixBP, typename VectorW,
        typename MatrixZ, typename Workspace >
inline integer_t spgv( integer_t const itype, char const jobz,
        integer_t const n, MatrixAP& ap, MatrixBP& bp, VectorW& w, MatrixZ& z,
        Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    spgv_impl< value_type >::invoke( itype, jobz, n, ap, bp, w, z, info,
            work );
    return info;
}

// template function to call spgv, default workspace type
template< typename MatrixAP, typename MatrixBP, typename VectorW,
        typename MatrixZ >
inline integer_t spgv( integer_t const itype, char const jobz,
        integer_t const n, MatrixAP& ap, MatrixBP& bp, VectorW& w,
        MatrixZ& z ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    spgv_impl< value_type >::invoke( itype, jobz, n, ap, bp, w, z, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
