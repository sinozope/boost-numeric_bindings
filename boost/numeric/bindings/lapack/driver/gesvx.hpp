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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_GESVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_GESVX_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void gesvx( char const fact, char const trans, integer_t const n,
            integer_t const nrhs, float* a, integer_t const lda, float* af,
            integer_t const ldaf, integer_t* ipiv, char& equed, float* r,
            float* c, float* b, integer_t const ldb, float* x,
            integer_t const ldx, float& rcond, float* ferr, float* berr,
            float* work, integer_t* iwork, integer_t& info ) {
        LAPACK_SGESVX( &fact, &trans, &n, &nrhs, a, &lda, af, &ldaf, ipiv,
                &equed, r, c, b, &ldb, x, &ldx, &rcond, ferr, berr, work,
                iwork, &info );
    }
    inline void gesvx( char const fact, char const trans, integer_t const n,
            integer_t const nrhs, double* a, integer_t const lda, double* af,
            integer_t const ldaf, integer_t* ipiv, char& equed, double* r,
            double* c, double* b, integer_t const ldb, double* x,
            integer_t const ldx, double& rcond, double* ferr, double* berr,
            double* work, integer_t* iwork, integer_t& info ) {
        LAPACK_DGESVX( &fact, &trans, &n, &nrhs, a, &lda, af, &ldaf, ipiv,
                &equed, r, c, b, &ldb, x, &ldx, &rcond, ferr, berr, work,
                iwork, &info );
    }
    inline void gesvx( char const fact, char const trans, integer_t const n,
            integer_t const nrhs, traits::complex_f* a, integer_t const lda,
            traits::complex_f* af, integer_t const ldaf, integer_t* ipiv,
            char& equed, float* r, float* c, traits::complex_f* b,
            integer_t const ldb, traits::complex_f* x, integer_t const ldx,
            float& rcond, float* ferr, float* berr, traits::complex_f* work,
            float* rwork, integer_t& info ) {
        LAPACK_CGESVX( &fact, &trans, &n, &nrhs, traits::complex_ptr(a), &lda,
                traits::complex_ptr(af), &ldaf, ipiv, &equed, r, c,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                &rcond, ferr, berr, traits::complex_ptr(work), rwork, &info );
    }
    inline void gesvx( char const fact, char const trans, integer_t const n,
            integer_t const nrhs, traits::complex_d* a, integer_t const lda,
            traits::complex_d* af, integer_t const ldaf, integer_t* ipiv,
            char& equed, double* r, double* c, traits::complex_d* b,
            integer_t const ldb, traits::complex_d* x, integer_t const ldx,
            double& rcond, double* ferr, double* berr,
            traits::complex_d* work, double* rwork, integer_t& info ) {
        LAPACK_ZGESVX( &fact, &trans, &n, &nrhs, traits::complex_ptr(a), &lda,
                traits::complex_ptr(af), &ldaf, ipiv, &equed, r, c,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                &rcond, ferr, berr, traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct gesvx_impl{};

// real specialization
template< typename ValueType >
struct gesvx_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR,
            typename WORK, typename IWORK >
    static void compute( char const fact, char const trans, MatrixA& a,
            MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixAF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorC >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
#ifndef NDEBUG
        assert( fact == 'F' || fact == 'N' || fact == 'E' );
        assert( trans == 'N' || trans == 'T' || trans == 'C' );
        assert( traits::matrix_size2(a) >= 0 );
        assert( traits::matrix_size2(x) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::leading_dimension(af) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( equed == 'N' || equed == 'R' || equed == 'C' || equed == 'B' );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::leading_dimension(x) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::vector_size(berr) >= traits::matrix_size2(x) );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                traits::matrix_size2(a) )));
        assert( traits::vector_size(work.select(integer_t()) >=
                min_size_iwork( traits::matrix_size2(a) )));
#endif
        detail::gesvx( fact, trans, traits::matrix_size2(a),
                traits::matrix_size2(x), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(af),
                traits::leading_dimension(af), traits::vector_storage(ipiv),
                equed, traits::vector_storage(r), traits::vector_storage(c),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                rcond, traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, MatrixA& a,
            MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work(
                traits::matrix_size2(a) ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork(
                traits::matrix_size2(a) ) );
        compute( fact, trans, a, af, ipiv, equed, r, c, b, x, rcond, ferr,
                berr, info, workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, MatrixA& a,
            MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( fact, trans, a, af, ipiv, equed, r, c, b, x, rcond, ferr,
                berr, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 4*n;
    }

    static integer_t min_size_iwork( integer_t const n ) {
        return n;
    }
};

// complex specialization
template< typename ValueType >
struct gesvx_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR,
            typename WORK, typename RWORK >
    static void compute( char const fact, char const trans, MatrixA& a,
            MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorR >::value_type, typename traits::vector_traits<
                VectorC >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorR >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorR >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixAF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
#ifndef NDEBUG
        assert( fact == 'F' || fact == 'N' || fact == 'E' );
        assert( trans == 'N' || trans == 'T' || trans == 'C' );
        assert( traits::matrix_size2(a) >= 0 );
        assert( traits::matrix_size2(x) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::leading_dimension(af) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( equed == 'N' || equed == 'R' || equed == 'C' || equed == 'B' );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::leading_dimension(x) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::vector_size(berr) >= traits::matrix_size2(x) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( traits::matrix_size2(a) )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( traits::matrix_size2(a) )));
#endif
        detail::gesvx( fact, trans, traits::matrix_size2(a),
                traits::matrix_size2(x), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(af),
                traits::leading_dimension(af), traits::vector_storage(ipiv),
                equed, traits::vector_storage(r), traits::vector_storage(c),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                rcond, traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, MatrixA& a,
            MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_size2(a) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_size2(a) ) );
        compute( fact, trans, a, af, ipiv, equed, r, c, b, x, rcond, ferr,
                berr, info, workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
            typename VectorR, typename VectorC, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void compute( char const fact, char const trans, MatrixA& a,
            MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r,
            VectorC& c, MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        compute( fact, trans, a, af, ipiv, equed, r, c, b, x, rcond, ferr,
                berr, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 2*n;
    }
};


// template function to call gesvx
template< typename MatrixA, typename MatrixAF, typename VectorIPIV,
        typename VectorR, typename VectorC, typename MatrixB,
        typename MatrixX, typename VectorFERR, typename VectorBERR,
        typename Workspace >
inline integer_t gesvx( char const fact, char const trans, MatrixA& a,
        MatrixAF& af, VectorIPIV& ipiv, char& equed, VectorR& r, VectorC& c,
        MatrixB& b, MatrixX& x, typename traits::matrix_traits<
        MatrixA >::value_type& rcond, VectorFERR& ferr, VectorBERR& berr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    gesvx_impl< value_type >::compute( fact, trans, a, af, ipiv, equed,
            r, c, b, x, rcond, ferr, berr, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
