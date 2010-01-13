//
// Copyright (c) 2002--2010
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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_LATRD_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_LATRD_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_side.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for latrd is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * float value-type.
//
template< typename UpLo >
inline std::ptrdiff_t latrd( UpLo, const fortran_int_t n,
        const fortran_int_t nb, float* a, const fortran_int_t lda, float* e,
        float* tau, float* w, const fortran_int_t ldw ) {
    fortran_int_t info(0);
    LAPACK_SLATRD( &lapack_option< UpLo >::value, &n, &nb, a, &lda, e, tau, w,
            &ldw );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
template< typename UpLo >
inline std::ptrdiff_t latrd( UpLo, const fortran_int_t n,
        const fortran_int_t nb, double* a, const fortran_int_t lda, double* e,
        double* tau, double* w, const fortran_int_t ldw ) {
    fortran_int_t info(0);
    LAPACK_DLATRD( &lapack_option< UpLo >::value, &n, &nb, a, &lda, e, tau, w,
            &ldw );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t latrd( UpLo, const fortran_int_t n,
        const fortran_int_t nb, std::complex<float>* a,
        const fortran_int_t lda, float* e, std::complex<float>* tau,
        std::complex<float>* w, const fortran_int_t ldw ) {
    fortran_int_t info(0);
    LAPACK_CLATRD( &lapack_option< UpLo >::value, &n, &nb, a, &lda, e, tau, w,
            &ldw );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t latrd( UpLo, const fortran_int_t n,
        const fortran_int_t nb, std::complex<double>* a,
        const fortran_int_t lda, double* e, std::complex<double>* tau,
        std::complex<double>* w, const fortran_int_t ldw ) {
    fortran_int_t info(0);
    LAPACK_ZLATRD( &lapack_option< UpLo >::value, &n, &nb, a, &lda, e, tau, w,
            &ldw );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to latrd.
//
template< typename Value, typename Enable = void >
struct latrd_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct latrd_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename VectorE, typename VectorTAU,
            typename MatrixW >
    static std::ptrdiff_t invoke( const fortran_int_t nb, MatrixA& a,
            VectorE& e, VectorTAU& tau, MatrixW& w ) {
        typedef typename result_of::data_side< MatrixA >::type uplo;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                VectorE >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                VectorTAU >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                MatrixW >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorE >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorTAU >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< MatrixW >::value) );
        BOOST_ASSERT( size_minor(a) == 1 || stride_minor(a) == 1 );
        BOOST_ASSERT( size_minor(w) == 1 || stride_minor(w) == 1 );
        BOOST_ASSERT( stride_major(a) >= (ERROR) );
        BOOST_ASSERT( stride_major(w) >= std::max< std::ptrdiff_t >(1,
                size_column(a)) );
        return detail::latrd( uplo(), size_column(a), nb, begin_value(a),
                stride_major(a), begin_value(e), begin_value(tau),
                begin_value(w), stride_major(w) );
    }

};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct latrd_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename VectorE, typename VectorTAU,
            typename MatrixW >
    static std::ptrdiff_t invoke( const fortran_int_t nb, MatrixA& a,
            VectorE& e, VectorTAU& tau, MatrixW& w ) {
        typedef typename result_of::data_side< MatrixA >::type uplo;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                VectorTAU >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                MatrixW >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorE >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorTAU >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< MatrixW >::value) );
        BOOST_ASSERT( size_minor(a) == 1 || stride_minor(a) == 1 );
        BOOST_ASSERT( size_minor(w) == 1 || stride_minor(w) == 1 );
        BOOST_ASSERT( stride_major(a) >= std::max< std::ptrdiff_t >(1,
                size_column(a)) );
        BOOST_ASSERT( stride_major(w) >= std::max< std::ptrdiff_t >(1,
                size_column(a)) );
        return detail::latrd( uplo(), size_column(a), nb, begin_value(a),
                stride_major(a), begin_value(e), begin_value(tau),
                begin_value(w), stride_major(w) );
    }

};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the latrd_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * VectorE&
// * VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        VectorE& e, VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * VectorE&
// * VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        VectorE& e, VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * const VectorE&
// * VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        const VectorE& e, VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * const VectorE&
// * VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        const VectorE& e, VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * VectorE&
// * const VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        VectorE& e, const VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * VectorE&
// * const VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        VectorE& e, const VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * const VectorE&
// * const VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        const VectorE& e, const VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * const VectorE&
// * const VectorTAU&
// * MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        const VectorE& e, const VectorTAU& tau, MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * VectorE&
// * VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        VectorE& e, VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * VectorE&
// * VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        VectorE& e, VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * const VectorE&
// * VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        const VectorE& e, VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * const VectorE&
// * VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        const VectorE& e, VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * VectorE&
// * const VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        VectorE& e, const VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * VectorE&
// * const VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        VectorE& e, const VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * MatrixA&
// * const VectorE&
// * const VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, MatrixA& a,
        const VectorE& e, const VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

//
// Overloaded function for latrd. Its overload differs for
// * const MatrixA&
// * const VectorE&
// * const VectorTAU&
// * const MatrixW&
//
template< typename MatrixA, typename VectorE, typename VectorTAU,
        typename MatrixW >
inline std::ptrdiff_t latrd( const fortran_int_t nb, const MatrixA& a,
        const VectorE& e, const VectorTAU& tau, const MatrixW& w ) {
    return latrd_impl< typename value< MatrixA >::type >::invoke( nb, a,
            e, tau, w );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
