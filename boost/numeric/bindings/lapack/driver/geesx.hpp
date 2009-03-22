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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GEESX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GEESX_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
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
    inline void geesx( char const jobvs, char const sort, logical_t* select,
            char const sense, integer_t const n, float* a,
            integer_t const lda, integer_t& sdim, float* wr, float* wi,
            float* vs, integer_t const ldvs, float& rconde, float& rcondv,
            float* work, integer_t const lwork, integer_t* iwork,
            integer_t const liwork, logical_t* bwork, integer_t& info ) {
        LAPACK_SGEESX( &jobvs, &sort, &select, &sense, &n, a, &lda, &sdim, wr,
                wi, vs, &ldvs, &rconde, &rcondv, work, &lwork, iwork, &liwork,
                bwork, &info );
    }
    inline void geesx( char const jobvs, char const sort, logical_t* select,
            char const sense, integer_t const n, double* a,
            integer_t const lda, integer_t& sdim, double* wr, double* wi,
            double* vs, integer_t const ldvs, double& rconde, double& rcondv,
            double* work, integer_t const lwork, integer_t* iwork,
            integer_t const liwork, logical_t* bwork, integer_t& info ) {
        LAPACK_DGEESX( &jobvs, &sort, &select, &sense, &n, a, &lda, &sdim, wr,
                wi, vs, &ldvs, &rconde, &rcondv, work, &lwork, iwork, &liwork,
                bwork, &info );
    }
    inline void geesx( char const jobvs, char const sort, logical_t* select,
            char const sense, integer_t const n, traits::complex_f* a,
            integer_t const lda, integer_t& sdim, traits::complex_f* w,
            traits::complex_f* vs, integer_t const ldvs, float& rconde,
            float& rcondv, traits::complex_f* work, integer_t const lwork,
            float* rwork, logical_t* bwork, integer_t& info ) {
        LAPACK_CGEESX( &jobvs, &sort, &select, &sense, &n,
                traits::complex_ptr(a), &lda, &sdim, traits::complex_ptr(w),
                traits::complex_ptr(vs), &ldvs, &rconde, &rcondv,
                traits::complex_ptr(work), &lwork, rwork, bwork, &info );
    }
    inline void geesx( char const jobvs, char const sort, logical_t* select,
            char const sense, integer_t const n, traits::complex_d* a,
            integer_t const lda, integer_t& sdim, traits::complex_d* w,
            traits::complex_d* vs, integer_t const ldvs, double& rconde,
            double& rcondv, traits::complex_d* work, integer_t const lwork,
            double* rwork, logical_t* bwork, integer_t& info ) {
        LAPACK_ZGEESX( &jobvs, &sort, &select, &sense, &n,
                traits::complex_ptr(a), &lda, &sdim, traits::complex_ptr(w),
                traits::complex_ptr(vs), &ldvs, &rconde, &rcondv,
                traits::complex_ptr(work), &lwork, rwork, bwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct geesx_impl{};

// real specialization
template< typename ValueType >
struct geesx_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorWR, typename VectorWI,
            typename MatrixVS, typename WORK, typename IWORK, typename BWORK >
    static void invoke( char const jobvs, char const sort, logical_t* select,
            char const sense, MatrixA& a, integer_t& sdim, VectorWR& wr,
            VectorWI& wi, MatrixVS& vs, real_type& rconde, real_type& rcondv,
            integer_t& info, detail::workspace3< WORK, IWORK, BWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorWR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorWI >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixVS >::value_type >::value) );
        BOOST_ASSERT( jobvs == 'N' || jobvs == 'V' );
        BOOST_ASSERT( sort == 'N' || sort == 'S' );
        BOOST_ASSERT( sense == 'N' || sense == 'E' || sense == 'V' ||
                sense == 'B' );
        BOOST_ASSERT( traits::matrix_num_columns(a) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_num_columns(a)) );
        BOOST_ASSERT( traits::vector_size(wr) >=
                traits::matrix_num_columns(a) );
        BOOST_ASSERT( traits::vector_size(wi) >=
                traits::matrix_num_columns(a) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( traits::matrix_num_columns(a), sense ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( traits::matrix_num_columns(a), sense ));
        BOOST_ASSERT( traits::vector_size(work.select(bool())) >=
                min_size_bwork( traits::matrix_num_columns(a), sort ));
        detail::geesx( jobvs, sort, select, sense,
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), sdim,
                traits::vector_storage(wr), traits::vector_storage(wi),
                traits::matrix_storage(vs), traits::leading_dimension(vs),
                rconde, rcondv,
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_size(work.select(integer_t())),
                traits::vector_storage(work.select(bool())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorWR, typename VectorWI,
            typename MatrixVS >
    static void invoke( char const jobvs, char const sort, logical_t* select,
            char const sense, MatrixA& a, integer_t& sdim, VectorWR& wr,
            VectorWI& wi, MatrixVS& vs, real_type& rconde, real_type& rcondv,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work(
                traits::matrix_num_columns(a), sense ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork(
                traits::matrix_num_columns(a), sense ) );
        traits::detail::array< bool > tmp_bwork( min_size_bwork(
                traits::matrix_num_columns(a), sort ) );
        invoke( jobvs, sort, select, sense, a, sdim, wr, wi, vs, rconde,
                rcondv, info, workspace( tmp_work, tmp_iwork, tmp_bwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorWR, typename VectorWI,
            typename MatrixVS >
    static void invoke( char const jobvs, char const sort, logical_t* select,
            char const sense, MatrixA& a, integer_t& sdim, VectorWR& wr,
            VectorWI& wi, MatrixVS& vs, real_type& rconde, real_type& rcondv,
            integer_t& info, optimal_workspace work ) {
        real_type opt_size_work;
        integer_t opt_size_iwork;
        traits::detail::array< bool > tmp_bwork( min_size_bwork(
                traits::matrix_num_columns(a), sort ) );
        detail::geesx( jobvs, sort, select, sense,
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), sdim,
                traits::vector_storage(wr), traits::vector_storage(wi),
                traits::matrix_storage(vs), traits::leading_dimension(vs),
                rconde, rcondv, &opt_size_work, -1, &opt_size_iwork, -1,
                traits::vector_storage(tmp_bwork), info );
        traits::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        traits::detail::array< integer_t > tmp_iwork( opt_size_iwork );
        invoke( jobvs, sort, select, sense, a, sdim, wr, wi, vs, rconde,
                rcondv, info, workspace( tmp_work, tmp_iwork, tmp_bwork ) );
    }

    static integer_t min_size_work( integer_t const n, char const sense ) {
        if ( sense == 'N' )
            return std::max( 1, 3*n );
        else
            return std::max( 1, n+n*n/2 );
    }

    static integer_t min_size_iwork( integer_t const n, char const sense ) {
        if ( sense == 'N' || sense == 'E' )
            return 1;
        else
            return std::max( 1, n*n/4 );
    }

    static integer_t min_size_bwork( integer_t const n, char const sort ) {
        if ( sort == 'N' )
            return 0;
        else
            return n;
    }
};

// complex specialization
template< typename ValueType >
struct geesx_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorW, typename MatrixVS,
            typename WORK, typename RWORK, typename BWORK >
    static void invoke( char const jobvs, char const sort, logical_t* select,
            char const sense, MatrixA& a, integer_t& sdim, VectorW& w,
            MatrixVS& vs, real_type& rconde, real_type& rcondv,
            integer_t& info, detail::workspace3< WORK, RWORK, BWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorW >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixVS >::value_type >::value) );
        BOOST_ASSERT( jobvs == 'N' || jobvs == 'V' );
        BOOST_ASSERT( sort == 'N' || sort == 'S' );
        BOOST_ASSERT( sense == 'N' || sense == 'E' || sense == 'V' ||
                sense == 'B' );
        BOOST_ASSERT( traits::matrix_num_columns(a) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_num_columns(a)) );
        BOOST_ASSERT( traits::vector_size(w) >=
                traits::matrix_num_columns(a) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( traits::matrix_num_columns(a), sense ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( traits::matrix_num_columns(a) ));
        BOOST_ASSERT( traits::vector_size(work.select(bool())) >=
                min_size_bwork( traits::matrix_num_columns(a), sort ));
        detail::geesx( jobvs, sort, select, sense,
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), sdim, traits::vector_storage(w),
                traits::matrix_storage(vs), traits::leading_dimension(vs),
                rconde, rcondv,
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(bool())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorW, typename MatrixVS >
    static void invoke( char const jobvs, char const sort, logical_t* select,
            char const sense, MatrixA& a, integer_t& sdim, VectorW& w,
            MatrixVS& vs, real_type& rconde, real_type& rcondv,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_num_columns(a), sense ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(a) ) );
        traits::detail::array< bool > tmp_bwork( min_size_bwork(
                traits::matrix_num_columns(a), sort ) );
        invoke( jobvs, sort, select, sense, a, sdim, w, vs, rconde, rcondv,
                info, workspace( tmp_work, tmp_rwork, tmp_bwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorW, typename MatrixVS >
    static void invoke( char const jobvs, char const sort, logical_t* select,
            char const sense, MatrixA& a, integer_t& sdim, VectorW& w,
            MatrixVS& vs, real_type& rconde, real_type& rcondv,
            integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(a) ) );
        traits::detail::array< bool > tmp_bwork( min_size_bwork(
                traits::matrix_num_columns(a), sort ) );
        detail::geesx( jobvs, sort, select, sense,
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), sdim, traits::vector_storage(w),
                traits::matrix_storage(vs), traits::leading_dimension(vs),
                rconde, rcondv, &opt_size_work, -1,
                traits::vector_storage(tmp_rwork),
                traits::vector_storage(tmp_bwork), info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        invoke( jobvs, sort, select, sense, a, sdim, w, vs, rconde, rcondv,
                info, workspace( tmp_work, tmp_rwork, tmp_bwork ) );
    }

    static integer_t min_size_work( integer_t const n, char const sense ) {
        if ( sense == 'N' )
            return std::max( 1, 2*n );
        else
            return std::max( 1, n*n/2 );
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return n;
    }

    static integer_t min_size_bwork( integer_t const n, char const sort ) {
        if ( sort == 'N' )
            return 0;
        else
            return n;
    }
};


// template function to call geesx
template< typename MatrixA, typename VectorWR, typename VectorWI,
        typename MatrixVS, typename Workspace >
inline integer_t geesx( char const jobvs, char const sort,
        logical_t* select, char const sense, MatrixA& a, integer_t& sdim,
        VectorWR& wr, VectorWI& wi, MatrixVS& vs,
        typename traits::matrix_traits< MatrixA >::value_type& rconde,
        typename traits::matrix_traits< MatrixA >::value_type& rcondv,
        Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    geesx_impl< value_type >::invoke( jobvs, sort, select, sense, a,
            sdim, wr, wi, vs, rconde, rcondv, info, work );
    return info;
}

// template function to call geesx, default workspace type
template< typename MatrixA, typename VectorWR, typename VectorWI,
        typename MatrixVS >
inline integer_t geesx( char const jobvs, char const sort,
        logical_t* select, char const sense, MatrixA& a, integer_t& sdim,
        VectorWR& wr, VectorWI& wi, MatrixVS& vs,
        typename traits::matrix_traits< MatrixA >::value_type& rconde,
        typename traits::matrix_traits< MatrixA >::value_type& rcondv ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    geesx_impl< value_type >::invoke( jobvs, sort, select, sense, a,
            sdim, wr, wi, vs, rconde, rcondv, info, optimal_workspace() );
    return info;
}
// template function to call geesx
template< typename MatrixA, typename VectorW, typename MatrixVS,
        typename Workspace >
inline integer_t geesx( char const jobvs, char const sort,
        logical_t* select, char const sense, MatrixA& a, integer_t& sdim,
        VectorW& w, MatrixVS& vs, typename traits::matrix_traits<
        MatrixA >::value_type& rconde, typename traits::matrix_traits<
        MatrixA >::value_type& rcondv, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    geesx_impl< value_type >::invoke( jobvs, sort, select, sense, a,
            sdim, w, vs, rconde, rcondv, info, work );
    return info;
}

// template function to call geesx, default workspace type
template< typename MatrixA, typename VectorW, typename MatrixVS >
inline integer_t geesx( char const jobvs, char const sort,
        logical_t* select, char const sense, MatrixA& a, integer_t& sdim,
        VectorW& w, MatrixVS& vs, typename traits::matrix_traits<
        MatrixA >::value_type& rconde, typename traits::matrix_traits<
        MatrixA >::value_type& rcondv ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    geesx_impl< value_type >::invoke( jobvs, sort, select, sense, a,
            sdim, w, vs, rconde, rcondv, info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
