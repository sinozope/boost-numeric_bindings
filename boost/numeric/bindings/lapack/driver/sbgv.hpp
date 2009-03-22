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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SBGV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SBGV_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
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
    inline void sbgv( char const jobz, char const uplo, integer_t const n,
            integer_t const ka, integer_t const kb, float* ab,
            integer_t const ldab, float* bb, integer_t const ldbb, float* w,
            float* z, integer_t const ldz, float* work, integer_t& info ) {
        LAPACK_SSBGV( &jobz, &uplo, &n, &ka, &kb, ab, &ldab, bb, &ldbb, w, z,
                &ldz, work, &info );
    }
    inline void sbgv( char const jobz, char const uplo, integer_t const n,
            integer_t const ka, integer_t const kb, double* ab,
            integer_t const ldab, double* bb, integer_t const ldbb, double* w,
            double* z, integer_t const ldz, double* work, integer_t& info ) {
        LAPACK_DSBGV( &jobz, &uplo, &n, &ka, &kb, ab, &ldab, bb, &ldbb, w, z,
                &ldz, work, &info );
    }
}

// value-type based template
template< typename ValueType >
struct sbgv_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename VectorW,
            typename MatrixZ, typename WORK >
    static void invoke( char const jobz, integer_t const n,
            integer_t const ka, integer_t const kb, MatrixAB& ab,
            MatrixBB& bb, VectorW& w, MatrixZ& z, integer_t& info,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixBB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::vector_traits<
                VectorW >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( traits::matrix_uplo_tag(ab) == 'U' ||
                traits::matrix_uplo_tag(ab) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( ka >= 0 );
        BOOST_ASSERT( kb >= 0 );
        BOOST_ASSERT( traits::leading_dimension(ab) >= ka+1 );
        BOOST_ASSERT( traits::leading_dimension(bb) >= kb+1 );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        detail::sbgv( jobz, traits::matrix_uplo_tag(ab), n, ka, kb,
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(bb), traits::leading_dimension(bb),
                traits::vector_storage(w), traits::matrix_storage(z),
                traits::leading_dimension(z),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename VectorW,
            typename MatrixZ >
    static void invoke( char const jobz, integer_t const n,
            integer_t const ka, integer_t const kb, MatrixAB& ab,
            MatrixBB& bb, VectorW& w, MatrixZ& z, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        invoke( jobz, n, ka, kb, ab, bb, w, z, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename VectorW,
            typename MatrixZ >
    static void invoke( char const jobz, integer_t const n,
            integer_t const ka, integer_t const kb, MatrixAB& ab,
            MatrixBB& bb, VectorW& w, MatrixZ& z, integer_t& info,
            optimal_workspace work ) {
        invoke( jobz, n, ka, kb, ab, bb, w, z, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 3*n;
    }
};


// template function to call sbgv
template< typename MatrixAB, typename MatrixBB, typename VectorW,
        typename MatrixZ, typename Workspace >
inline integer_t sbgv( char const jobz, integer_t const n,
        integer_t const ka, integer_t const kb, MatrixAB& ab, MatrixBB& bb,
        VectorW& w, MatrixZ& z, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    sbgv_impl< value_type >::invoke( jobz, n, ka, kb, ab, bb, w, z,
            info, work );
    return info;
}

// template function to call sbgv, default workspace type
template< typename MatrixAB, typename MatrixBB, typename VectorW,
        typename MatrixZ >
inline integer_t sbgv( char const jobz, integer_t const n,
        integer_t const ka, integer_t const kb, MatrixAB& ab, MatrixBB& bb,
        VectorW& w, MatrixZ& z ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    sbgv_impl< value_type >::invoke( jobz, n, ka, kb, ab, bb, w, z,
            info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
