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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_SYGVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_SYGVX_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void sygvx( integer_t const itype, char const jobz,
            char const range, char const uplo, integer_t const n, float* a,
            integer_t const lda, float* b, integer_t const ldb,
            float const vl, float const vu, integer_t const il,
            integer_t const iu, float const abstol, integer_t& m, float* w,
            float* z, integer_t const ldz, float* work, integer_t const lwork,
            integer_t* iwork, integer_t* ifail, integer_t& info ) {
        LAPACK_SSYGVX( &itype, &jobz, &range, &uplo, &n, a, &lda, b, &ldb,
                &vl, &vu, &il, &iu, &abstol, &m, w, z, &ldz, work, &lwork,
                iwork, ifail, &info );
    }
    inline void sygvx( integer_t const itype, char const jobz,
            char const range, char const uplo, integer_t const n, double* a,
            integer_t const lda, double* b, integer_t const ldb,
            double const vl, double const vu, integer_t const il,
            integer_t const iu, double const abstol, integer_t& m, double* w,
            double* z, integer_t const ldz, double* work,
            integer_t const lwork, integer_t* iwork, integer_t* ifail,
            integer_t& info ) {
        LAPACK_DSYGVX( &itype, &jobz, &range, &uplo, &n, a, &lda, b, &ldb,
                &vl, &vu, &il, &iu, &abstol, &m, w, z, &ldz, work, &lwork,
                iwork, ifail, &info );
    }
}

// value-type based template
template< typename ValueType >
struct sygvx_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename MatrixZ, typename VectorIFAIL, typename WORK,
            typename IWORK >
    static void compute( integer_t const itype, char const jobz,
            char const range, integer_t const n, MatrixA& a, MatrixB& b,
            real_type const vl, real_type const vu, integer_t const il,
            integer_t const iu, real_type const abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorW >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
#ifndef NDEBUG
        assert( jobz == 'N' || jobz == 'V' );
        assert( range == 'A' || range == 'V' || range == 'I' );
        assert( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        assert( n >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,n) );
        assert( traits::leading_dimension(b) >= std::max(1,n) );
        assert( traits::vector_size(w) >= n );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                n )));
        assert( traits::vector_size(work.select(integer_t()) >=
                min_size_iwork( n )));
#endif
        detail::sygvx( itype, jobz, range, traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_storage(ifail), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void compute( integer_t const itype, char const jobz,
            char const range, integer_t const n, MatrixA& a, MatrixB& b,
            real_type const vl, real_type const vu, integer_t const il,
            integer_t const iu, real_type const abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        compute( itype, jobz, range, n, a, b, vl, vu, il, iu, abstol, m, w, z,
                ifail, info, workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void compute( integer_t const itype, char const jobz,
            char const range, integer_t const n, MatrixA& a, MatrixB& b,
            real_type const vl, real_type const vu, integer_t const il,
            integer_t const iu, real_type const abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            optimal_workspace work ) {
        real_type opt_size_work;
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        detail::sygvx( itype, jobz, range, traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                &opt_size_work, -1, traits::vector_storage(tmp_iwork),
                traits::vector_storage(ifail), info );
        traits::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( itype, jobz, range, n, a, b, vl, vu, il, iu, abstol, m, w, z,
                ifail, info, workspace( tmp_work, tmp_iwork ) );
    }

    static integer_t min_size_work( integer_t const n ) {
        return std::max( 1, 8*n );
    }

    static integer_t min_size_iwork( integer_t const n ) {
        return 5*n;
    }
};


// template function to call sygvx
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline integer_t sygvx( integer_t const itype, char const jobz,
        char const range, integer_t const n, MatrixA& a, MatrixB& b,
        typename traits::matrix_traits< MatrixA >::value_type const vl,
        typename traits::matrix_traits< MatrixA >::value_type const vu,
        integer_t const il, integer_t const iu,
        typename traits::matrix_traits< MatrixA >::value_type const abstol,
        integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    sygvx_impl< value_type >::compute( itype, jobz, range, n, a, b, vl,
            vu, il, iu, abstol, m, w, z, ifail, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
