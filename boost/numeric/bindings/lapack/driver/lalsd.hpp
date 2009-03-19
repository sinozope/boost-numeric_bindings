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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_LALSD_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_LALSD_HPP

#include <boost/assert.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/keywords.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void lalsd( char const uplo, integer_t const smlsiz,
            integer_t const n, integer_t const nrhs, float* d, float* e,
            float* b, integer_t const ldb, float const rcond, integer_t& rank,
            float* work, integer_t* iwork, integer_t& info ) {
        LAPACK_SLALSD( &uplo, &smlsiz, &n, &nrhs, d, e, b, &ldb, &rcond,
                &rank, work, iwork, &info );
    }
    inline void lalsd( char const uplo, integer_t const smlsiz,
            integer_t const n, integer_t const nrhs, double* d, double* e,
            double* b, integer_t const ldb, double const rcond,
            integer_t& rank, double* work, integer_t* iwork,
            integer_t& info ) {
        LAPACK_DLALSD( &uplo, &smlsiz, &n, &nrhs, d, e, b, &ldb, &rcond,
                &rank, work, iwork, &info );
    }
    inline void lalsd( char const uplo, integer_t const smlsiz,
            integer_t const n, integer_t const nrhs, float* d, float* e,
            traits::complex_f* b, integer_t const ldb, float const rcond,
            integer_t& rank, traits::complex_f* work, float* rwork,
            integer_t* iwork, integer_t& info ) {
        LAPACK_CLALSD( &uplo, &smlsiz, &n, &nrhs, d, e,
                traits::complex_ptr(b), &ldb, &rcond, &rank,
                traits::complex_ptr(work), rwork, iwork, &info );
    }
    inline void lalsd( char const uplo, integer_t const smlsiz,
            integer_t const n, integer_t const nrhs, double* d, double* e,
            traits::complex_d* b, integer_t const ldb, double const rcond,
            integer_t& rank, traits::complex_d* work, double* rwork,
            integer_t* iwork, integer_t& info ) {
        LAPACK_ZLALSD( &uplo, &smlsiz, &n, &nrhs, d, e,
                traits::complex_ptr(b), &ldb, &rcond, &rank,
                traits::complex_ptr(work), rwork, iwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct lalsd_impl{};

// real specialization
template< typename ValueType >
struct lalsd_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef typename mpl::vector< keywords::tag::B > valid_keywords;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixB,
            typename WORK, typename IWORK >
    static void compute( char const uplo, integer_t const smlsiz,
            integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
            real_type const rcond, integer_t& rank, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        integer_t nlvl = std::max( 0, static_cast<integer_t>(
            std::log(static_cast<real_type>(n)/static_cast<real_type>(smlsiz+
                    1)) /
            std::log(static_cast<real_type>(2.)) ) + 1 );
        BOOST_ASSERT( uplo == 'U' || uplo == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 1 );
        BOOST_ASSERT( traits::vector_size(e) >= n-1 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n, smlsiz, nlvl,
                traits::matrix_num_columns(b) ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n, nlvl ));
        detail::lalsd( uplo, smlsiz, n, traits::matrix_num_columns(b),
                traits::vector_storage(d), traits::vector_storage(e),
                traits::matrix_storage(b), traits::leading_dimension(b),
                rcond, rank, traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixB >
    static void compute( char const uplo, integer_t const smlsiz,
            integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
            real_type const rcond, integer_t& rank, integer_t& info,
            minimal_workspace work ) {
        integer_t nlvl = std::max( 0, static_cast<integer_t>(
            std::log(static_cast<real_type>(n)/static_cast<real_type>(smlsiz+
                    1)) /
            std::log(static_cast<real_type>(2.)) ) + 1 );
        traits::detail::array< real_type > tmp_work( min_size_work( n, smlsiz,
                nlvl, traits::matrix_num_columns(b) ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n,
                nlvl ) );
        compute( uplo, smlsiz, n, d, e, b, rcond, rank, info,
                workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixB >
    static void compute( char const uplo, integer_t const smlsiz,
            integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
            real_type const rcond, integer_t& rank, integer_t& info,
            optimal_workspace work ) {
        compute( uplo, smlsiz, n, d, e, b, rcond, rank, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n, integer_t const smlsiz,
            integer_t const nlvl, integer_t const nrhs ) {
        integer_t smlsiz_plus_one = smlsiz + 1;
        return 9*n + 2*n*smlsiz + 8*n*nlvl + n*nrhs +
                smlsiz_plus_one * smlsiz_plus_one;
    }

    static integer_t min_size_iwork( integer_t const n,
            integer_t const nlvl ) {
        return 3*n*nlvl + 11*n;
    }
};

// complex specialization
template< typename ValueType >
struct lalsd_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef typename mpl::vector< keywords::tag::B > valid_keywords;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixB,
            typename WORK, typename RWORK, typename IWORK >
    static void compute( char const uplo, integer_t const smlsiz,
            integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
            real_type const rcond, integer_t& rank, integer_t& info,
            detail::workspace3< WORK, RWORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        integer_t nlvl = std::max( 0, static_cast<integer_t>(
            std::log(static_cast<real_type>(std::min(traits::matrix_size2(b),
                    n))/
            static_cast<real_type>(smlsiz+1)) /
            std::log(static_cast<real_type>(2.))) + 1 );
        BOOST_ASSERT( uplo == 'U' || uplo == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 1 );
        BOOST_ASSERT( traits::vector_size(e) >= n-1 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n, traits::matrix_num_columns(b) ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n, smlsiz, nlvl,
                traits::matrix_num_columns(b) ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n, nlvl ));
        detail::lalsd( uplo, smlsiz, n, traits::matrix_num_columns(b),
                traits::vector_storage(d), traits::vector_storage(e),
                traits::matrix_storage(b), traits::leading_dimension(b),
                rcond, rank,
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixB >
    static void compute( char const uplo, integer_t const smlsiz,
            integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
            real_type const rcond, integer_t& rank, integer_t& info,
            minimal_workspace work ) {
        integer_t nlvl = std::max( 0, static_cast<integer_t>(
            std::log(static_cast<real_type>(std::min(traits::matrix_size2(b),
                    n))/
            static_cast<real_type>(smlsiz+1)) /
            std::log(static_cast<real_type>(2.))) + 1 );
        traits::detail::array< value_type > tmp_work( min_size_work( n,
                traits::matrix_num_columns(b) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n,
                smlsiz, nlvl, traits::matrix_num_columns(b) ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n,
                nlvl ) );
        compute( uplo, smlsiz, n, d, e, b, rcond, rank, info,
                workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixB >
    static void compute( char const uplo, integer_t const smlsiz,
            integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
            real_type const rcond, integer_t& rank, integer_t& info,
            optimal_workspace work ) {
        compute( uplo, smlsiz, n, d, e, b, rcond, rank, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n, integer_t const nrhs ) {
        return n*nrhs;
    }

    static integer_t min_size_rwork( integer_t const n,
            integer_t const smlsiz, integer_t const nlvl,
            integer_t const nrhs ) {
        integer_t smlsiz_plus_one = smlsiz + 1;
        return 9*n + 2*n*smlsiz + 8*n*nlvl + 3*smlsiz*nrhs +
                smlsiz_plus_one * smlsiz_plus_one;
    }

    static integer_t min_size_iwork( integer_t const n,
            integer_t const nlvl ) {
        return 3*n*nlvl+11*n;
    }
};


// template function to call lalsd
template< typename VectorD, typename VectorE, typename MatrixB,
        typename Workspace >
inline integer_t lalsd( char const uplo, integer_t const smlsiz,
        integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
        typename traits::vector_traits< VectorD >::value_type const rcond,
        integer_t& rank, Workspace work ) {
    typedef typename traits::vector_traits< VectorD >::value_type value_type;
    integer_t info(0);
    lalsd_impl< value_type >::compute( uplo, smlsiz, n, d, e, b, rcond,
            rank, info, work );
    return info;
}

// template function to call lalsd, default workspace type
template< typename VectorD, typename VectorE, typename MatrixB >
inline integer_t lalsd( char const uplo, integer_t const smlsiz,
        integer_t const n, VectorD& d, VectorE& e, MatrixB& b,
        typename traits::vector_traits< VectorD >::value_type const rcond,
        integer_t& rank ) {
    typedef typename traits::vector_traits< VectorD >::value_type value_type;
    integer_t info(0);
    lalsd_impl< value_type >::compute( uplo, smlsiz, n, d, e, b, rcond,
            rank, info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
