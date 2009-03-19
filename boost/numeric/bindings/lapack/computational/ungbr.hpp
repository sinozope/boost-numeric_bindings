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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNGBR_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNGBR_HPP

#include <boost/assert.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/keywords.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
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
    inline void ungbr( char const vect, integer_t const m, integer_t const n,
            integer_t const k, traits::complex_f* a, integer_t const lda,
            traits::complex_f* tau, traits::complex_f* work,
            integer_t const lwork, integer_t& info ) {
        LAPACK_CUNGBR( &vect, &m, &n, &k, traits::complex_ptr(a), &lda,
                traits::complex_ptr(tau), traits::complex_ptr(work), &lwork,
                &info );
    }
    inline void ungbr( char const vect, integer_t const m, integer_t const n,
            integer_t const k, traits::complex_d* a, integer_t const lda,
            traits::complex_d* tau, traits::complex_d* work,
            integer_t const lwork, integer_t& info ) {
        LAPACK_ZUNGBR( &vect, &m, &n, &k, traits::complex_ptr(a), &lda,
                traits::complex_ptr(tau), traits::complex_ptr(work), &lwork,
                &info );
    }
}

// value-type based template
template< typename ValueType >
struct ungbr_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef typename mpl::vector< keywords::tag::A > valid_keywords;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorTAU, typename WORK >
    static void compute( char const vect, integer_t const m,
            integer_t const n, integer_t const k, MatrixA& a, VectorTAU& tau,
            integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorTAU >::value_type >::value) );
        BOOST_ASSERT( vect == 'Q' || vect == 'P' );
        BOOST_ASSERT( m >= 0 );
        BOOST_ASSERT( k >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= m );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( m, n ));
        detail::ungbr( vect, m, n, k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(tau),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorTAU >
    static void compute( char const vect, integer_t const m,
            integer_t const n, integer_t const k, MatrixA& a, VectorTAU& tau,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( m, n ) );
        compute( vect, m, n, k, a, tau, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorTAU >
    static void compute( char const vect, integer_t const m,
            integer_t const n, integer_t const k, MatrixA& a, VectorTAU& tau,
            integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        detail::ungbr( vect, m, n, k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(tau),
                &opt_size_work, -1, info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( vect, m, n, k, a, tau, info, workspace( tmp_work ) );
    }

    static integer_t min_size_work( integer_t const m, integer_t const n ) {
        return std::max( 1, std::min( m, n ) );
    }
};


// template function to call ungbr
template< typename MatrixA, typename VectorTAU, typename Workspace >
inline integer_t ungbr( char const vect, integer_t const m,
        integer_t const n, integer_t const k, MatrixA& a, VectorTAU& tau,
        Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    ungbr_impl< value_type >::compute( vect, m, n, k, a, tau, info,
            work );
    return info;
}

// template function to call ungbr, default workspace type
template< typename MatrixA, typename VectorTAU >
inline integer_t ungbr( char const vect, integer_t const m,
        integer_t const n, integer_t const k, MatrixA& a, VectorTAU& tau ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    ungbr_impl< value_type >::compute( vect, m, n, k, a, tau, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
