# 1 "histogram.cpp"

# 149 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h" 3
typedef long ptrdiff_t; 
# 211
typedef unsigned long size_t; 
# 49 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cstddef" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::ptrdiff_t;
using ::size_t;

}
# 39 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/functexcept.h" 3
namespace std __attribute((__visibility__("default" ))) { 



void __throw_bad_exception() __attribute((__noreturn__)); 



void __throw_bad_alloc() __attribute((__noreturn__)); 



void __throw_bad_cast() __attribute((__noreturn__)); 


void __throw_bad_typeid() __attribute((__noreturn__)); 



void __throw_logic_error(const char *) __attribute((__noreturn__)); 


void __throw_domain_error(const char *) __attribute((__noreturn__)); 


void __throw_invalid_argument(const char *) __attribute((__noreturn__)); 


void __throw_length_error(const char *) __attribute((__noreturn__)); 


void __throw_out_of_range(const char *) __attribute((__noreturn__)); 


void __throw_runtime_error(const char *) __attribute((__noreturn__)); 


void __throw_range_error(const char *) __attribute((__noreturn__)); 


void __throw_overflow_error(const char *) __attribute((__noreturn__)); 


void __throw_underflow_error(const char *) __attribute((__noreturn__)); 



void __throw_ios_failure(const char *) __attribute((__noreturn__)); 


void __throw_system_error(int) __attribute((__noreturn__)); 

}
# 69 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 

template < typename _Iterator, typename _Container >
    class __normal_iterator;

}

namespace std __attribute((__visibility__("default" ))) { 

struct __true_type { }; 
struct __false_type { }; 

template < bool >
    struct __truth_type
    { typedef __false_type __type; };


template<> struct __truth_type< true>  { 
typedef __true_type __type; }; 



template < class _Sp, class _Tp >
    struct __traitor
    {
      enum { __value = bool ( _Sp :: __value ) || bool ( _Tp :: __value ) };
      typedef typename __truth_type < __value > :: __type __type;
    };


template < typename, typename >
    struct __are_same
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

template < typename _Tp >
    struct __are_same < _Tp, _Tp >
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };


template < typename _Tp >
    struct __is_void
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };


template<> struct __is_void< void>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 




template < typename _Tp >
    struct __is_integer
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
# 142
template<> struct __is_integer< bool>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< signed char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 



template<> struct __is_integer< wchar_t>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 
# 195
template<> struct __is_integer< short>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned short>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< int>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< long>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned long>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< long long>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned long long>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 




template < typename _Tp >
    struct __is_floating
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };



template<> struct __is_floating< float>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_floating< double>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_floating< long double>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 




template < typename _Tp >
    struct __is_pointer
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

template < typename _Tp >
    struct __is_pointer < _Tp * >
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };




template < typename _Tp >
    struct __is_normal_iterator
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };

template < typename _Iterator, typename _Container >
    struct __is_normal_iterator < __gnu_cxx :: __normal_iterator < _Iterator,
             _Container > >
    {
      enum { __value = 1 };
      typedef __true_type __type;
    };




template < typename _Tp >
    struct __is_arithmetic
    : public __traitor < __is_integer < _Tp >, __is_floating < _Tp > >
    { };




template < typename _Tp >
    struct __is_fundamental
    : public __traitor < __is_void < _Tp >, __is_arithmetic < _Tp > >
    { };




template < typename _Tp >
    struct __is_scalar
    : public __traitor < __is_arithmetic < _Tp >, __is_pointer < _Tp > >
    { };




template < typename _Tp >
    struct __is_char
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };


template<> struct __is_char< char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 



template<> struct __is_char< wchar_t>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template < typename _Tp >
    struct __is_byte
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };


template<> struct __is_byte< char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_byte< signed char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_byte< unsigned char>  { 

enum { __value = 1}; 
typedef __true_type __type; 
}; 




template < typename _Tp >
    struct __is_move_iterator
    {
      enum { __value = 0 };
      typedef __false_type __type;
    };
# 417
}
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/ext/type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 


template < bool, typename >
    struct __enable_if
    { };

template < typename _Tp >
    struct __enable_if < true, _Tp >
    { typedef _Tp __type; };



template < bool _Cond, typename _Iftrue, typename _Iffalse >
    struct __conditional_type
    { typedef _Iftrue __type; };

template < typename _Iftrue, typename _Iffalse >
    struct __conditional_type < false, _Iftrue, _Iffalse >
    { typedef _Iffalse __type; };



template < typename _Tp >
    struct __add_unsigned
    {
    private :
      typedef __enable_if < std :: __is_integer < _Tp > :: __value, _Tp > __if_type;

    public :
      typedef typename __if_type :: __type __type;
    };


template<> struct __add_unsigned< char>  { 
typedef unsigned char __type; }; 


template<> struct __add_unsigned< signed char>  { 
typedef unsigned char __type; }; 


template<> struct __add_unsigned< short>  { 
typedef unsigned short __type; }; 


template<> struct __add_unsigned< int>  { 
typedef unsigned __type; }; 


template<> struct __add_unsigned< long>  { 
typedef unsigned long __type; }; 


template<> struct __add_unsigned< long long>  { 
typedef unsigned long long __type; }; 



template<> struct __add_unsigned< bool> ; 


template<> struct __add_unsigned< wchar_t> ; 



template < typename _Tp >
    struct __remove_unsigned
    {
    private :
      typedef __enable_if < std :: __is_integer < _Tp > :: __value, _Tp > __if_type;

    public :
      typedef typename __if_type :: __type __type;
    };


template<> struct __remove_unsigned< char>  { 
typedef signed char __type; }; 


template<> struct __remove_unsigned< unsigned char>  { 
typedef signed char __type; }; 


template<> struct __remove_unsigned< unsigned short>  { 
typedef short __type; }; 


template<> struct __remove_unsigned< unsigned>  { 
typedef int __type; }; 


template<> struct __remove_unsigned< unsigned long>  { 
typedef long __type; }; 


template<> struct __remove_unsigned< unsigned long long>  { 
typedef long long __type; }; 



template<> struct __remove_unsigned< bool> ; 


template<> struct __remove_unsigned< wchar_t> ; 



template < typename _Type >
    inline bool
    __is_null_pointer ( _Type * __ptr )
    { return __ptr == 0; }

template < typename _Type >
    inline bool
    __is_null_pointer ( _Type )
    { return false; }



template < typename _Tp, bool = std :: __is_integer < _Tp > :: __value >
    struct __promote
    { typedef double __type; };

template < typename _Tp >
    struct __promote < _Tp, false >
    { typedef _Tp __type; };

template < typename _Tp, typename _Up >
    struct __promote_2
    {
    private :
      typedef typename __promote < _Tp > :: __type __type1;
      typedef typename __promote < _Up > :: __type __type2;

    public :
      typedef __typeof__ ( __type1 ( ) + __type2 ( ) ) __type;
    };

template < typename _Tp, typename _Up, typename _Vp >
    struct __promote_3
    {
    private :
      typedef typename __promote < _Tp > :: __type __type1;
      typedef typename __promote < _Up > :: __type __type2;
      typedef typename __promote < _Vp > :: __type __type3;

    public :
      typedef __typeof__ ( __type1 ( ) + __type2 ( ) + __type3 ( ) ) __type;
    };

template < typename _Tp, typename _Up, typename _Vp, typename _Wp >
    struct __promote_4
    {
    private :
      typedef typename __promote < _Tp > :: __type __type1;
      typedef typename __promote < _Up > :: __type __type2;
      typedef typename __promote < _Vp > :: __type __type3;
      typedef typename __promote < _Wp > :: __type __type4;

    public :
      typedef __typeof__ ( __type1 ( ) + __type2 ( ) + __type3 ( ) + __type4 ( ) ) __type;
    };

}
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/ext/numeric_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 52
template < typename _Value >
    struct __numeric_traits_integer
    {

      static const _Value __min = ( ( ( _Value ) ( - 1 ) < 0 ) ? ( _Value ) 1 << ( sizeof ( _Value ) * 8 - ( ( _Value ) ( - 1 ) < 0 ) ) : ( _Value ) 0 );
      static const _Value __max = ( ( ( _Value ) ( - 1 ) < 0 ) ? ( ( ( ( ( _Value ) 1 << ( ( sizeof ( _Value ) * 8 - ( ( _Value ) ( - 1 ) < 0 ) ) - 1 ) ) - 1 ) << 1 ) + 1 ) : ~ ( _Value ) 0 );



      static const bool __is_signed = ( ( _Value ) ( - 1 ) < 0 );
      static const int __digits = ( sizeof ( _Value ) * 8 - ( ( _Value ) ( - 1 ) < 0 ) );
    };

template < typename _Value >
    const _Value __numeric_traits_integer < _Value > :: __min;

template < typename _Value >
    const _Value __numeric_traits_integer < _Value > :: __max;

template < typename _Value >
    const bool __numeric_traits_integer < _Value > :: __is_signed;

template < typename _Value >
    const int __numeric_traits_integer < _Value > :: __digits;
# 97
template < typename _Value >
    struct __numeric_traits_floating
    {

      static const int __max_digits10 = ( 2 + ( std :: __are_same < _Value, float > :: __value ? 24 : std :: __are_same < _Value, double > :: __value ? 53 : 64 ) * 3010 / 10000 );


      static const bool __is_signed = true;
      static const int __digits10 = ( std :: __are_same < _Value, float > :: __value ? 6 : std :: __are_same < _Value, double > :: __value ? 15 : 18 );
      static const int __max_exponent10 = ( std :: __are_same < _Value, float > :: __value ? 38 : std :: __are_same < _Value, double > :: __value ? 308 : 4932 );
    };

template < typename _Value >
    const int __numeric_traits_floating < _Value > :: __max_digits10;

template < typename _Value >
    const bool __numeric_traits_floating < _Value > :: __is_signed;

template < typename _Value >
    const int __numeric_traits_floating < _Value > :: __digits10;

template < typename _Value >
    const int __numeric_traits_floating < _Value > :: __max_exponent10;

template < typename _Value >
    struct __numeric_traits
    : public __conditional_type < std :: __is_integer < _Value > :: __value,
    __numeric_traits_integer < _Value >,
    __numeric_traits_floating < _Value > > :: __type
    { };

}
# 66 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/move.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 74
template < typename _Tp >
    inline void
    swap ( _Tp & __a, _Tp & __b )
    {



      _Tp __tmp = ( __a );
      __a = ( __b );
      __b = ( __tmp );
    }



template < typename _Tp, size_t _Nm >
    inline void
    swap ( _Tp ( & __a ) [ _Nm ], _Tp ( & __b ) [ _Nm ] )
    {
      for ( size_t __n = 0; __n < _Nm; ++ __n )
 swap ( __a [ __n ], __b [ __n ] );
    }

}
# 63 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_pair.h" 3
namespace std __attribute((__visibility__("default" ))) { 


template < class _T1, class _T2 >
    struct pair
    {
      typedef _T1 first_type;
      typedef _T2 second_type;

      _T1 first;
      _T2 second;





      pair ( )
      : first ( ), second ( ) { }


      pair ( const _T1 & __a, const _T2 & __b )
      : first ( __a ), second ( __b ) { }













      template < class _U1, class _U2 >
        pair ( const pair < _U1, _U2 > & __p )
 : first ( __p . first ),
   second ( __p . second ) { }







































    };


template < class _T1, class _T2 >
    inline bool
    operator == ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __x . first == __y . first && __x . second == __y . second; }


template < class _T1, class _T2 >
    inline bool
    operator < ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __x . first < __y . first
      || ( ! ( __y . first < __x . first ) && __x . second < __y . second ); }


template < class _T1, class _T2 >
    inline bool
    operator != ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __x == __y ); }


template < class _T1, class _T2 >
    inline bool
    operator > ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __y < __x; }


template < class _T1, class _T2 >
    inline bool
    operator <= ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __y < __x ); }


template < class _T1, class _T2 >
    inline bool
    operator >= ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __x < __y ); }
# 213
template < class _T1, class _T2 >
    inline pair < _T1, _T2 >
    make_pair ( _T1 __x, _T2 __y )
    { return pair < _T1, _T2 > ( __x, __y ); }
# 259
}
# 68 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_iterator_base_types.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 79
struct input_iterator_tag { }; 

struct output_iterator_tag { }; 

struct forward_iterator_tag : public input_iterator_tag { }; 


struct bidirectional_iterator_tag : public forward_iterator_tag { }; 


struct random_access_iterator_tag : public bidirectional_iterator_tag { }; 
# 102
template < typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp *, typename _Reference = _Tp & >
    struct iterator
    {

      typedef _Category iterator_category;

      typedef _Tp value_type;

      typedef _Distance difference_type;

      typedef _Pointer pointer;

      typedef _Reference reference;
    };
# 124
template < typename _Iterator >
    struct iterator_traits
    {
      typedef typename _Iterator :: iterator_category iterator_category;
      typedef typename _Iterator :: value_type value_type;
      typedef typename _Iterator :: difference_type difference_type;
      typedef typename _Iterator :: pointer pointer;
      typedef typename _Iterator :: reference reference;
    };

template < typename _Tp >
    struct iterator_traits < _Tp * >
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp * pointer;
      typedef _Tp & reference;
    };

template < typename _Tp >
    struct iterator_traits < const _Tp * >
    {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef const _Tp * pointer;
      typedef const _Tp & reference;
    };
# 158
template < typename _Iter >
    inline typename iterator_traits < _Iter > :: iterator_category
    __iterator_category ( const _Iter & )
    { return typename iterator_traits < _Iter > :: iterator_category ( ); }



}
# 66 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_iterator_base_funcs.h" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _InputIterator >
    inline typename iterator_traits < _InputIterator > :: difference_type
    __distance ( _InputIterator __first, _InputIterator __last,
               input_iterator_tag )
    {



      typename iterator_traits < _InputIterator > :: difference_type __n = 0;
      while ( __first != __last )
 {
   ++ __first;
   ++ __n;
 }
      return __n;
    }

template < typename _RandomAccessIterator >
    inline typename iterator_traits < _RandomAccessIterator > :: difference_type
    __distance ( _RandomAccessIterator __first, _RandomAccessIterator __last,
               random_access_iterator_tag )
    {



      return __last - __first;
    }
# 108
template < typename _InputIterator >
    inline typename iterator_traits < _InputIterator > :: difference_type
    distance ( _InputIterator __first, _InputIterator __last )
    {

      return std :: __distance ( __first, __last,
        std :: __iterator_category ( __first ) );
    }

template < typename _InputIterator, typename _Distance >
    inline void
    __advance ( _InputIterator & __i, _Distance __n, input_iterator_tag )
    {


      while ( __n -- )
 ++ __i;
    }

template < typename _BidirectionalIterator, typename _Distance >
    inline void
    __advance ( _BidirectionalIterator & __i, _Distance __n,
       bidirectional_iterator_tag )
    {



      if ( __n > 0 )
        while ( __n -- )
   ++ __i;
      else
        while ( __n ++ )
   -- __i;
    }

template < typename _RandomAccessIterator, typename _Distance >
    inline void
    __advance ( _RandomAccessIterator & __i, _Distance __n,
              random_access_iterator_tag )
    {



      __i += __n;
    }
# 166
template < typename _InputIterator, typename _Distance >
    inline void
    advance ( _InputIterator & __i, _Distance __n )
    {

      typename iterator_traits < _InputIterator > :: difference_type __d = __n;
      std :: __advance ( __i, __d, std :: __iterator_category ( __i ) );
    }
# 195
}
# 68 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_iterator.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 89
template < typename _Iterator >
    class reverse_iterator
    : public iterator < typename iterator_traits < _Iterator > :: iterator_category,
        typename iterator_traits < _Iterator > :: value_type,
        typename iterator_traits < _Iterator > :: difference_type,
        typename iterator_traits < _Iterator > :: pointer,
                      typename iterator_traits < _Iterator > :: reference >
    {
    protected :
      _Iterator current;

    public :
      typedef _Iterator iterator_type;
      typedef typename iterator_traits < _Iterator > :: difference_type
              difference_type;
      typedef typename iterator_traits < _Iterator > :: reference reference;
      typedef typename iterator_traits < _Iterator > :: pointer pointer;

    public :






      reverse_iterator ( ) : current ( ) { }




      explicit
      reverse_iterator ( iterator_type __x ) : current ( __x ) { }




      reverse_iterator ( const reverse_iterator & __x )
      : current ( __x . current ) { }





      template < typename _Iter >
        reverse_iterator ( const reverse_iterator < _Iter > & __x )
 : current ( __x . base ( ) ) { }




      iterator_type
      base ( ) const
      { return current; }






      reference
      operator * ( ) const
      {
 _Iterator __tmp = current;
 return * -- __tmp;
      }






      pointer
      operator -> ( ) const
      { return & ( operator * ( ) ); }






      reverse_iterator &
      operator ++ ( )
      {
 -- current;
 return * this;
      }






      reverse_iterator
      operator ++ ( int )
      {
 reverse_iterator __tmp = * this;
 -- current;
 return __tmp;
      }






      reverse_iterator &
      operator -- ( )
      {
 ++ current;
 return * this;
      }






      reverse_iterator
      operator -- ( int )
      {
 reverse_iterator __tmp = * this;
 ++ current;
 return __tmp;
      }






      reverse_iterator
      operator + ( difference_type __n ) const
      { return reverse_iterator ( current - __n ); }






      reverse_iterator &
      operator += ( difference_type __n )
      {
 current -= __n;
 return * this;
      }






      reverse_iterator
      operator - ( difference_type __n ) const
      { return reverse_iterator ( current + __n ); }






      reverse_iterator &
      operator -= ( difference_type __n )
      {
 current += __n;
 return * this;
      }






      reference
      operator [ ] ( difference_type __n ) const
      { return * ( * this + __n ); }
    };
# 276
template < typename _Iterator >
    inline bool
    operator == ( const reverse_iterator < _Iterator > & __x,
        const reverse_iterator < _Iterator > & __y )
    { return __x . base ( ) == __y . base ( ); }

template < typename _Iterator >
    inline bool
    operator < ( const reverse_iterator < _Iterator > & __x,
       const reverse_iterator < _Iterator > & __y )
    { return __y . base ( ) < __x . base ( ); }

template < typename _Iterator >
    inline bool
    operator != ( const reverse_iterator < _Iterator > & __x,
        const reverse_iterator < _Iterator > & __y )
    { return ! ( __x == __y ); }

template < typename _Iterator >
    inline bool
    operator > ( const reverse_iterator < _Iterator > & __x,
       const reverse_iterator < _Iterator > & __y )
    { return __y < __x; }

template < typename _Iterator >
    inline bool
    operator <= ( const reverse_iterator < _Iterator > & __x,
        const reverse_iterator < _Iterator > & __y )
    { return ! ( __y < __x ); }

template < typename _Iterator >
    inline bool
    operator >= ( const reverse_iterator < _Iterator > & __x,
        const reverse_iterator < _Iterator > & __y )
    { return ! ( __x < __y ); }

template < typename _Iterator >
    inline typename reverse_iterator < _Iterator > :: difference_type
    operator - ( const reverse_iterator < _Iterator > & __x,
       const reverse_iterator < _Iterator > & __y )
    { return __y . base ( ) - __x . base ( ); }

template < typename _Iterator >
    inline reverse_iterator < _Iterator >
    operator + ( typename reverse_iterator < _Iterator > :: difference_type __n,
       const reverse_iterator < _Iterator > & __x )
    { return reverse_iterator < _Iterator > ( __x . base ( ) - __n ); }



template < typename _IteratorL, typename _IteratorR >
    inline bool
    operator == ( const reverse_iterator < _IteratorL > & __x,
        const reverse_iterator < _IteratorR > & __y )
    { return __x . base ( ) == __y . base ( ); }

template < typename _IteratorL, typename _IteratorR >
    inline bool
    operator < ( const reverse_iterator < _IteratorL > & __x,
       const reverse_iterator < _IteratorR > & __y )
    { return __y . base ( ) < __x . base ( ); }

template < typename _IteratorL, typename _IteratorR >
    inline bool
    operator != ( const reverse_iterator < _IteratorL > & __x,
        const reverse_iterator < _IteratorR > & __y )
    { return ! ( __x == __y ); }

template < typename _IteratorL, typename _IteratorR >
    inline bool
    operator > ( const reverse_iterator < _IteratorL > & __x,
       const reverse_iterator < _IteratorR > & __y )
    { return __y < __x; }

template < typename _IteratorL, typename _IteratorR >
    inline bool
    operator <= ( const reverse_iterator < _IteratorL > & __x,
        const reverse_iterator < _IteratorR > & __y )
    { return ! ( __y < __x ); }

template < typename _IteratorL, typename _IteratorR >
    inline bool
    operator >= ( const reverse_iterator < _IteratorL > & __x,
        const reverse_iterator < _IteratorR > & __y )
    { return ! ( __x < __y ); }

template < typename _IteratorL, typename _IteratorR >







    inline typename reverse_iterator < _IteratorL > :: difference_type
    operator - ( const reverse_iterator < _IteratorL > & __x,
       const reverse_iterator < _IteratorR > & __y )

    { return __y . base ( ) - __x . base ( ); }
# 388
template < typename _Container >
    class back_insert_iterator
    : public iterator < output_iterator_tag, void, void, void, void >
    {
    protected :
      _Container * container;

    public :

      typedef _Container container_type;


      explicit
      back_insert_iterator ( _Container & __x ) : container ( & __x ) { }












      back_insert_iterator &
      operator = ( typename _Container :: const_reference __value )
      {
 container -> push_back ( __value );
 return * this;
      }











      back_insert_iterator &
      operator * ( )
      { return * this; }


      back_insert_iterator &
      operator ++ ( )
      { return * this; }


      back_insert_iterator
      operator ++ ( int )
      { return * this; }
    };
# 457
template < typename _Container >
    inline back_insert_iterator < _Container >
    back_inserter ( _Container & __x )
    { return back_insert_iterator < _Container > ( __x ); }
# 472
template < typename _Container >
    class front_insert_iterator
    : public iterator < output_iterator_tag, void, void, void, void >
    {
    protected :
      _Container * container;

    public :

      typedef _Container container_type;


      explicit front_insert_iterator ( _Container & __x ) : container ( & __x ) { }












      front_insert_iterator &
      operator = ( typename _Container :: const_reference __value )
      {
 container -> push_front ( __value );
 return * this;
      }











      front_insert_iterator &
      operator * ( )
      { return * this; }


      front_insert_iterator &
      operator ++ ( )
      { return * this; }


      front_insert_iterator
      operator ++ ( int )
      { return * this; }
    };
# 540
template < typename _Container >
    inline front_insert_iterator < _Container >
    front_inserter ( _Container & __x )
    { return front_insert_iterator < _Container > ( __x ); }
# 559
template < typename _Container >
    class insert_iterator
    : public iterator < output_iterator_tag, void, void, void, void >
    {
    protected :
      _Container * container;
      typename _Container :: iterator iter;

    public :

      typedef _Container container_type;





      insert_iterator ( _Container & __x, typename _Container :: iterator __i )
      : container ( & __x ), iter ( __i ) { }
























      insert_iterator &
      operator = ( typename _Container :: const_reference __value )
      {
 iter = container -> insert ( iter, __value );
 ++ iter;
 return * this;
      }












      insert_iterator &
      operator * ( )
      { return * this; }


      insert_iterator &
      operator ++ ( )
      { return * this; }


      insert_iterator &
      operator ++ ( int )
      { return * this; }
    };
# 646
template < typename _Container, typename _Iterator >
    inline insert_iterator < _Container >
    inserter ( _Container & __x, _Iterator __i )
    {
      return insert_iterator < _Container > ( __x,
      typename _Container :: iterator ( __i ) );
    }

}

namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 665
using std::iterator_traits;
using std::iterator;
template < typename _Iterator, typename _Container >
    class __normal_iterator
    {
    protected :
      _Iterator _M_current;

    public :
      typedef _Iterator iterator_type;
      typedef typename iterator_traits < _Iterator > :: iterator_category
                                                             iterator_category;
      typedef typename iterator_traits < _Iterator > :: value_type value_type;
      typedef typename iterator_traits < _Iterator > :: difference_type
                                                             difference_type;
      typedef typename iterator_traits < _Iterator > :: reference reference;
      typedef typename iterator_traits < _Iterator > :: pointer pointer;

      __normal_iterator ( ) : _M_current ( _Iterator ( ) ) { }

      explicit
      __normal_iterator ( const _Iterator & __i ) : _M_current ( __i ) { }


      template < typename _Iter >
        __normal_iterator ( const __normal_iterator < _Iter,
     typename __enable_if <
              ( std :: __are_same < _Iter, typename _Container :: pointer > :: __value ),
        _Container > :: __type > & __i )
        : _M_current ( __i . base ( ) ) { }


      reference
      operator * ( ) const
      { return * _M_current; }

      pointer
      operator -> ( ) const
      { return _M_current; }

      __normal_iterator &
      operator ++ ( )
      {
 ++ _M_current;
 return * this;
      }

      __normal_iterator
      operator ++ ( int )
      { return __normal_iterator ( _M_current ++ ); }


      __normal_iterator &
      operator -- ( )
      {
 -- _M_current;
 return * this;
      }

      __normal_iterator
      operator -- ( int )
      { return __normal_iterator ( _M_current -- ); }


      reference
      operator [ ] ( const difference_type & __n ) const
      { return _M_current [ __n ]; }

      __normal_iterator &
      operator += ( const difference_type & __n )
      { _M_current += __n; return * this; }

      __normal_iterator
      operator + ( const difference_type & __n ) const
      { return __normal_iterator ( _M_current + __n ); }

      __normal_iterator &
      operator -= ( const difference_type & __n )
      { _M_current -= __n; return * this; }

      __normal_iterator
      operator - ( const difference_type & __n ) const
      { return __normal_iterator ( _M_current - __n ); }

      const _Iterator &
      base ( ) const
      { return _M_current; }
    };
# 763
template < typename _IteratorL, typename _IteratorR, typename _Container >
    inline bool
    operator == ( const __normal_iterator < _IteratorL, _Container > & __lhs,
        const __normal_iterator < _IteratorR, _Container > & __rhs )
    { return __lhs . base ( ) == __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline bool
    operator == ( const __normal_iterator < _Iterator, _Container > & __lhs,
        const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) == __rhs . base ( ); }

template < typename _IteratorL, typename _IteratorR, typename _Container >
    inline bool
    operator != ( const __normal_iterator < _IteratorL, _Container > & __lhs,
        const __normal_iterator < _IteratorR, _Container > & __rhs )
    { return __lhs . base ( ) != __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline bool
    operator != ( const __normal_iterator < _Iterator, _Container > & __lhs,
        const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) != __rhs . base ( ); }


template < typename _IteratorL, typename _IteratorR, typename _Container >
    inline bool
    operator < ( const __normal_iterator < _IteratorL, _Container > & __lhs,
       const __normal_iterator < _IteratorR, _Container > & __rhs )
    { return __lhs . base ( ) < __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline bool
    operator < ( const __normal_iterator < _Iterator, _Container > & __lhs,
       const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) < __rhs . base ( ); }

template < typename _IteratorL, typename _IteratorR, typename _Container >
    inline bool
    operator > ( const __normal_iterator < _IteratorL, _Container > & __lhs,
       const __normal_iterator < _IteratorR, _Container > & __rhs )
    { return __lhs . base ( ) > __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline bool
    operator > ( const __normal_iterator < _Iterator, _Container > & __lhs,
       const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) > __rhs . base ( ); }

template < typename _IteratorL, typename _IteratorR, typename _Container >
    inline bool
    operator <= ( const __normal_iterator < _IteratorL, _Container > & __lhs,
        const __normal_iterator < _IteratorR, _Container > & __rhs )
    { return __lhs . base ( ) <= __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline bool
    operator <= ( const __normal_iterator < _Iterator, _Container > & __lhs,
        const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) <= __rhs . base ( ); }

template < typename _IteratorL, typename _IteratorR, typename _Container >
    inline bool
    operator >= ( const __normal_iterator < _IteratorL, _Container > & __lhs,
        const __normal_iterator < _IteratorR, _Container > & __rhs )
    { return __lhs . base ( ) >= __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline bool
    operator >= ( const __normal_iterator < _Iterator, _Container > & __lhs,
        const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) >= __rhs . base ( ); }
# 840
template < typename _IteratorL, typename _IteratorR, typename _Container >







    inline typename __normal_iterator < _IteratorL, _Container > :: difference_type
    operator - ( const __normal_iterator < _IteratorL, _Container > & __lhs,
       const __normal_iterator < _IteratorR, _Container > & __rhs )

    { return __lhs . base ( ) - __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline typename __normal_iterator < _Iterator, _Container > :: difference_type
    operator - ( const __normal_iterator < _Iterator, _Container > & __lhs,
       const __normal_iterator < _Iterator, _Container > & __rhs )
    { return __lhs . base ( ) - __rhs . base ( ); }

template < typename _Iterator, typename _Container >
    inline __normal_iterator < _Iterator, _Container >
    operator + ( typename __normal_iterator < _Iterator, _Container > :: difference_type
       __n, const __normal_iterator < _Iterator, _Container > & __i )
    { return __normal_iterator < _Iterator, _Container > ( __i . base ( ) + __n ); }

}
# 47 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/debug/debug.h" 3
namespace std { 

namespace __debug { }
}




namespace __gnu_debug { 

using namespace std::__debug;
}
# 74 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_algobase.h" 3
namespace std __attribute((__visibility__("default" ))) { 




template < bool _BoolType >
    struct __iter_swap
    {
      template < typename _ForwardIterator1, typename _ForwardIterator2 >
        static void
        iter_swap ( _ForwardIterator1 __a, _ForwardIterator2 __b )
        {
          typedef typename iterator_traits < _ForwardIterator1 > :: value_type
            _ValueType1;
          _ValueType1 __tmp = ( * __a );
          * __a = ( * __b );
          * __b = ( __tmp );
 }
    };


template<> struct __iter_swap< true>  { 

template < typename _ForwardIterator1, typename _ForwardIterator2 >
        static void
        iter_swap ( _ForwardIterator1 __a, _ForwardIterator2 __b )
        {
          swap ( * __a, * __b );
        }
}; 
# 115
template < typename _ForwardIterator1, typename _ForwardIterator2 >
    inline void
    iter_swap ( _ForwardIterator1 __a, _ForwardIterator2 __b )
    {
      typedef typename iterator_traits < _ForwardIterator1 > :: value_type
 _ValueType1;
      typedef typename iterator_traits < _ForwardIterator2 > :: value_type
 _ValueType2;











      typedef typename iterator_traits < _ForwardIterator1 > :: reference
 _ReferenceType1;
      typedef typename iterator_traits < _ForwardIterator2 > :: reference
 _ReferenceType2;
      std :: __iter_swap < __are_same < _ValueType1, _ValueType2 > :: __value
 && __are_same < _ValueType1 &, _ReferenceType1 > :: __value
 && __are_same < _ValueType2 &, _ReferenceType2 > :: __value > ::
 iter_swap ( __a, __b );
    }
# 156
template < typename _ForwardIterator1, typename _ForwardIterator2 >
    _ForwardIterator2
    swap_ranges ( _ForwardIterator1 __first1, _ForwardIterator1 __last1,
  _ForwardIterator2 __first2 )
    {





                                                       ;

      for (; __first1 != __last1; ++ __first1, ++ __first2 )
 std :: iter_swap ( __first1, __first2 );
      return __first2;
    }
# 184
template < typename _Tp >
    inline const _Tp &
    min ( const _Tp & __a, const _Tp & __b )
    {



      if ( __b < __a )
 return __b;
      return __a;
    }
# 207
template < typename _Tp >
    inline const _Tp &
    max ( const _Tp & __a, const _Tp & __b )
    {



      if ( __a < __b )
 return __b;
      return __a;
    }
# 230
template < typename _Tp, typename _Compare >
    inline const _Tp &
    min ( const _Tp & __a, const _Tp & __b, _Compare __comp )
    {

      if ( __comp ( __b, __a ) )
 return __b;
      return __a;
    }
# 251
template < typename _Tp, typename _Compare >
    inline const _Tp &
    max ( const _Tp & __a, const _Tp & __b, _Compare __comp )
    {

      if ( __comp ( __a, __b ) )
 return __b;
      return __a;
    }




template < typename _Iterator,
    bool _IsNormal = __is_normal_iterator < _Iterator > :: __value >
    struct __niter_base
    {
      static _Iterator
      __b ( _Iterator __it )
      { return __it; }
    };

template < typename _Iterator >
    struct __niter_base < _Iterator, true >
    {
      static typename _Iterator :: iterator_type
      __b ( _Iterator __it )
      { return __it . base ( ); }
    };


template < typename _Iterator,
    bool _IsMove = __is_move_iterator < _Iterator > :: __value >
    struct __miter_base
    {
      static _Iterator
      __b ( _Iterator __it )
      { return __it; }
    };

template < typename _Iterator >
    struct __miter_base < _Iterator, true >
    {
      static typename _Iterator :: iterator_type
      __b ( _Iterator __it )
      { return __it . base ( ); }
    };
# 305
template < bool, bool, typename >
    struct __copy_move
    {
      template < typename _II, typename _OI >
        static _OI
        __copy_m ( _II __first, _II __last, _OI __result )
        {
   for (; __first != __last; ++ __result, ++ __first )
     * __result = * __first;
   return __result;
 }
    };
# 334
template<> struct __copy_move< false, false, random_access_iterator_tag>  { 

template < typename _II, typename _OI >
        static _OI
        __copy_m ( _II __first, _II __last, _OI __result )
        {
   typedef typename iterator_traits < _II > :: difference_type _Distance;
   for ( _Distance __n = __last - __first; __n > 0; -- __n )
     {
       * __result = * __first;
       ++ __first;
       ++ __result;
     }
   return __result;
 }
}; 
# 371
template < bool _IsMove >
    struct __copy_move < _IsMove, true, random_access_iterator_tag >
    {
      template < typename _Tp >
        static _Tp *
        __copy_m ( const _Tp * __first, const _Tp * __last, _Tp * __result )
        {
   __builtin_memmove ( __result, __first,
       sizeof ( _Tp ) * ( __last - __first ) );
   return __result + ( __last - __first );
 }
    };

template < bool _IsMove, typename _II, typename _OI >
    inline _OI
    __copy_move_a ( _II __first, _II __last, _OI __result )
    {
      typedef typename iterator_traits < _II > :: value_type _ValueTypeI;
      typedef typename iterator_traits < _OI > :: value_type _ValueTypeO;
      typedef typename iterator_traits < _II > :: iterator_category _Category;
      const bool __simple = ( __is_pod ( _ValueTypeI )
                      && __is_pointer < _II > :: __value
                      && __is_pointer < _OI > :: __value
        && __are_same < _ValueTypeI, _ValueTypeO > :: __value );

      return std :: __copy_move < _IsMove, __simple,
                       _Category > :: __copy_m ( __first, __last, __result );
    }



template < typename _CharT >
    struct char_traits;

template < typename _CharT, typename _Traits >
    class istreambuf_iterator;

template < typename _CharT, typename _Traits >
    class ostreambuf_iterator;

template < bool _IsMove, typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
      ostreambuf_iterator < _CharT, char_traits < _CharT > > > :: __type
    __copy_move_a2 ( _CharT *, _CharT *,
     ostreambuf_iterator < _CharT, char_traits < _CharT > > );

template < bool _IsMove, typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
      ostreambuf_iterator < _CharT, char_traits < _CharT > > > :: __type
    __copy_move_a2 ( const _CharT *, const _CharT *,
     ostreambuf_iterator < _CharT, char_traits < _CharT > > );

template < bool _IsMove, typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
        _CharT * > :: __type
    __copy_move_a2 ( istreambuf_iterator < _CharT, char_traits < _CharT > >,
     istreambuf_iterator < _CharT, char_traits < _CharT > >, _CharT * );

template < bool _IsMove, typename _II, typename _OI >
    inline _OI
    __copy_move_a2 ( _II __first, _II __last, _OI __result )
    {
      return _OI ( std :: __copy_move_a < _IsMove >
   ( std :: __niter_base < _II > :: __b ( __first ),
    std :: __niter_base < _II > :: __b ( __last ),
    std :: __niter_base < _OI > :: __b ( __result ) ) );
    }
# 456
template < typename _II, typename _OI >
    inline _OI
    copy ( _II __first, _II __last, _OI __result )
    {




                                                     ;

      return ( std :: __copy_move_a2 < __is_move_iterator < _II > :: __value >
       ( std :: __miter_base < _II > :: __b ( __first ),
        std :: __miter_base < _II > :: __b ( __last ), __result ) );
    }
# 509
template < bool, bool, typename >
    struct __copy_move_backward
    {
      template < typename _BI1, typename _BI2 >
        static _BI2
        __copy_move_b ( _BI1 __first, _BI1 __last, _BI2 __result )
        {
   while ( __first != __last )
     * -- __result = * -- __last;
   return __result;
 }
    };
# 538
template<> struct __copy_move_backward< false, false, random_access_iterator_tag>  { 

template < typename _BI1, typename _BI2 >
        static _BI2
        __copy_move_b ( _BI1 __first, _BI1 __last, _BI2 __result )
        {
   typename iterator_traits < _BI1 > :: difference_type __n;
   for ( __n = __last - __first; __n > 0; -- __n )
     * -- __result = * -- __last;
   return __result;
 }
}; 
# 567
template < bool _IsMove >
    struct __copy_move_backward < _IsMove, true, random_access_iterator_tag >
    {
      template < typename _Tp >
        static _Tp *
        __copy_move_b ( const _Tp * __first, const _Tp * __last, _Tp * __result )
        {
   const ptrdiff_t _Num = __last - __first;
   __builtin_memmove ( __result - _Num, __first, sizeof ( _Tp ) * _Num );
   return __result - _Num;
 }
    };

template < bool _IsMove, typename _BI1, typename _BI2 >
    inline _BI2
    __copy_move_backward_a ( _BI1 __first, _BI1 __last, _BI2 __result )
    {
      typedef typename iterator_traits < _BI1 > :: value_type _ValueType1;
      typedef typename iterator_traits < _BI2 > :: value_type _ValueType2;
      typedef typename iterator_traits < _BI1 > :: iterator_category _Category;
      const bool __simple = ( __is_pod ( _ValueType1 )
                      && __is_pointer < _BI1 > :: __value
                      && __is_pointer < _BI2 > :: __value
        && __are_same < _ValueType1, _ValueType2 > :: __value );

      return std :: __copy_move_backward < _IsMove, __simple,
                                _Category > :: __copy_move_b ( __first,
         __last,
         __result );
    }

template < bool _IsMove, typename _BI1, typename _BI2 >
    inline _BI2
    __copy_move_backward_a2 ( _BI1 __first, _BI1 __last, _BI2 __result )
    {
      return _BI2 ( std :: __copy_move_backward_a < _IsMove >
    ( std :: __niter_base < _BI1 > :: __b ( __first ),
     std :: __niter_base < _BI1 > :: __b ( __last ),
     std :: __niter_base < _BI2 > :: __b ( __result ) ) );
    }
# 626
template < typename _BI1, typename _BI2 >
    inline _BI2
    copy_backward ( _BI1 __first, _BI1 __last, _BI2 __result )
    {






                                                     ;

      return ( std :: __copy_move_backward_a2 < __is_move_iterator < _BI1 > :: __value >
       ( std :: __miter_base < _BI1 > :: __b ( __first ),
        std :: __miter_base < _BI1 > :: __b ( __last ), __result ) );
    }
# 684
template < typename _ForwardIterator, typename _Tp >
    inline typename
    __gnu_cxx :: __enable_if < ! __is_scalar < _Tp > :: __value, void > :: __type
    __fill_a ( _ForwardIterator __first, _ForwardIterator __last,
       const _Tp & __value )
    {
      for (; __first != __last; ++ __first )
 * __first = __value;
    }

template < typename _ForwardIterator, typename _Tp >
    inline typename
    __gnu_cxx :: __enable_if < __is_scalar < _Tp > :: __value, void > :: __type
    __fill_a ( _ForwardIterator __first, _ForwardIterator __last,
      const _Tp & __value )
    {
      const _Tp __tmp = __value;
      for (; __first != __last; ++ __first )
 * __first = __tmp;
    }


template < typename _Tp >
    inline typename
    __gnu_cxx :: __enable_if < __is_byte < _Tp > :: __value, void > :: __type
    __fill_a ( _Tp * __first, _Tp * __last, const _Tp & __c )
    {
      const _Tp __tmp = __c;
      __builtin_memset ( __first, static_cast < unsigned char > ( __tmp ),
         __last - __first );
    }
# 728
template < typename _ForwardIterator, typename _Tp >
    inline void
    fill ( _ForwardIterator __first, _ForwardIterator __last, const _Tp & __value )
    {



                                                     ;

      std :: __fill_a ( std :: __niter_base < _ForwardIterator > :: __b ( __first ),
      std :: __niter_base < _ForwardIterator > :: __b ( __last ), __value );
    }

template < typename _OutputIterator, typename _Size, typename _Tp >
    inline typename
    __gnu_cxx :: __enable_if < ! __is_scalar < _Tp > :: __value, _OutputIterator > :: __type
    __fill_n_a ( _OutputIterator __first, _Size __n, const _Tp & __value )
    {
      for (; __n > 0; -- __n, ++ __first )
 * __first = __value;
      return __first;
    }

template < typename _OutputIterator, typename _Size, typename _Tp >
    inline typename
    __gnu_cxx :: __enable_if < __is_scalar < _Tp > :: __value, _OutputIterator > :: __type
    __fill_n_a ( _OutputIterator __first, _Size __n, const _Tp & __value )
    {
      const _Tp __tmp = __value;
      for (; __n > 0; -- __n, ++ __first )
 * __first = __tmp;
      return __first;
    }

template < typename _Size, typename _Tp >
    inline typename
    __gnu_cxx :: __enable_if < __is_byte < _Tp > :: __value, _Tp * > :: __type
    __fill_n_a ( _Tp * __first, _Size __n, const _Tp & __c )
    {
      std :: __fill_a ( __first, __first + __n, __c );
      return __first + __n;
    }
# 783
template < typename _OI, typename _Size, typename _Tp >
    inline _OI
    fill_n ( _OI __first, _Size __n, const _Tp & __value )
    {



      return _OI ( std :: __fill_n_a ( std :: __niter_base < _OI > :: __b ( __first ),
     __n, __value ) );
    }

template < bool _BoolType >
    struct __equal
    {
      template < typename _II1, typename _II2 >
        static bool
        equal ( _II1 __first1, _II1 __last1, _II2 __first2 )
        {
   for (; __first1 != __last1; ++ __first1, ++ __first2 )
     if ( ! ( * __first1 == * __first2 ) )
       return false;
   return true;
 }
    };


template<> struct __equal< true>  { 

template < typename _Tp >
        static bool
        equal ( const _Tp * __first1, const _Tp * __last1, const _Tp * __first2 )
        {
   return ! __builtin_memcmp ( __first1, __first2, sizeof ( _Tp )
       * ( __last1 - __first1 ) );
 }
}; 

template < typename _II1, typename _II2 >
    inline bool
    __equal_aux ( _II1 __first1, _II1 __last1, _II2 __first2 )
    {
      typedef typename iterator_traits < _II1 > :: value_type _ValueType1;
      typedef typename iterator_traits < _II2 > :: value_type _ValueType2;
      const bool __simple = ( __is_integer < _ValueType1 > :: __value
                      && __is_pointer < _II1 > :: __value
                      && __is_pointer < _II2 > :: __value
        && __are_same < _ValueType1, _ValueType2 > :: __value );

      return std :: __equal < __simple > :: equal ( __first1, __last1, __first2 );
    }


template < typename, typename >
    struct __lc_rai
    {
      template < typename _II1, typename _II2 >
        static _II1
        __newlast1 ( _II1, _II1 __last1, _II2, _II2 )
        { return __last1; }

      template < typename _II >
        static bool
        __cnd2 ( _II __first, _II __last )
        { return __first != __last; }
    };


template<> struct __lc_rai< random_access_iterator_tag, random_access_iterator_tag>  { 

template < typename _RAI1, typename _RAI2 >
        static _RAI1
        __newlast1 ( _RAI1 __first1, _RAI1 __last1,
     _RAI2 __first2, _RAI2 __last2 )
        {
   const typename iterator_traits < _RAI1 > :: difference_type
     __diff1 = __last1 - __first1;
   const typename iterator_traits < _RAI2 > :: difference_type
     __diff2 = __last2 - __first2;
   return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
 }

template < typename _RAI >
        static bool
        __cnd2 ( _RAI, _RAI )
        { return true; }
}; 

template < bool _BoolType >
    struct __lexicographical_compare
    {
      template < typename _II1, typename _II2 >
        static bool __lc ( _II1, _II1, _II2, _II2 );
    };

template < bool _BoolType >
    template < typename _II1, typename _II2 >
      bool
      __lexicographical_compare < _BoolType > ::
      __lc ( _II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2 )
      {
 typedef typename iterator_traits < _II1 > :: iterator_category _Category1;
 typedef typename iterator_traits < _II2 > :: iterator_category _Category2;
 typedef std :: __lc_rai < _Category1, _Category2 > __rai_type;

 __last1 = __rai_type :: __newlast1 ( __first1, __last1,
      __first2, __last2 );
 for (; __first1 != __last1 && __rai_type :: __cnd2 ( __first2, __last2 );
      ++ __first1, ++ __first2 )
   {
     if ( * __first1 < * __first2 )
       return true;
     if ( * __first2 < * __first1 )
       return false;
   }
 return __first1 == __last1 && __first2 != __last2;
      }


template<> struct __lexicographical_compare< true>  { 

template < typename _Tp, typename _Up >
        static bool
        __lc ( const _Tp * __first1, const _Tp * __last1,
      const _Up * __first2, const _Up * __last2 )
 {
   const size_t __len1 = __last1 - __first1;
   const size_t __len2 = __last2 - __first2;
   const int __result = __builtin_memcmp ( __first1, __first2,
      std :: min ( __len1, __len2 ) );
   return __result != 0 ? __result < 0 : __len1 < __len2;
 }
}; 

template < typename _II1, typename _II2 >
    inline bool
    __lexicographical_compare_aux ( _II1 __first1, _II1 __last1,
      _II2 __first2, _II2 __last2 )
    {
      typedef typename iterator_traits < _II1 > :: value_type _ValueType1;
      typedef typename iterator_traits < _II2 > :: value_type _ValueType2;
      const bool __simple =
 ( __is_byte < _ValueType1 > :: __value && __is_byte < _ValueType2 > :: __value
  && ! __gnu_cxx :: __numeric_traits < _ValueType1 > :: __is_signed
  && ! __gnu_cxx :: __numeric_traits < _ValueType2 > :: __is_signed
  && __is_pointer < _II1 > :: __value
  && __is_pointer < _II2 > :: __value );

      return std :: __lexicographical_compare < __simple > :: __lc ( __first1, __last1,
           __first2, __last2 );
    }

}

namespace std __attribute((__visibility__("default" ))) { 
# 950
template < typename _II1, typename _II2 >
    inline bool
    equal ( _II1 __first1, _II1 __last1, _II2 __first2 )
    {






                                                       ;

      return std :: __equal_aux ( std :: __niter_base < _II1 > :: __b ( __first1 ),
         std :: __niter_base < _II1 > :: __b ( __last1 ),
         std :: __niter_base < _II2 > :: __b ( __first2 ) );
    }
# 982
template < typename _IIter1, typename _IIter2, typename _BinaryPredicate >
    inline bool
    equal ( _IIter1 __first1, _IIter1 __last1,
   _IIter2 __first2, _BinaryPredicate __binary_pred )
    {



                                                       ;

      for (; __first1 != __last1; ++ __first1, ++ __first2 )
 if ( ! bool ( __binary_pred ( * __first1, * __first2 ) ) )
   return false;
      return true;
    }
# 1013
template < typename _II1, typename _II2 >
    inline bool
    lexicographical_compare ( _II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2 )
    {

      typedef typename iterator_traits < _II1 > :: value_type _ValueType1;
      typedef typename iterator_traits < _II2 > :: value_type _ValueType2;




                                                       ;
                                                       ;

      return std :: __lexicographical_compare_aux
 ( std :: __niter_base < _II1 > :: __b ( __first1 ),
  std :: __niter_base < _II1 > :: __b ( __last1 ),
  std :: __niter_base < _II2 > :: __b ( __first2 ),
  std :: __niter_base < _II2 > :: __b ( __last2 ) );
    }
# 1048
template < typename _II1, typename _II2, typename _Compare >
    bool
    lexicographical_compare ( _II1 __first1, _II1 __last1,
       _II2 __first2, _II2 __last2, _Compare __comp )
    {
      typedef typename iterator_traits < _II1 > :: iterator_category _Category1;
      typedef typename iterator_traits < _II2 > :: iterator_category _Category2;
      typedef std :: __lc_rai < _Category1, _Category2 > __rai_type;




                                                       ;
                                                       ;

      __last1 = __rai_type :: __newlast1 ( __first1, __last1, __first2, __last2 );
      for (; __first1 != __last1 && __rai_type :: __cnd2 ( __first2, __last2 );
    ++ __first1, ++ __first2 )
 {
   if ( __comp ( * __first1, * __first2 ) )
     return true;
   if ( __comp ( * __first2, * __first1 ) )
     return false;
 }
      return __first1 == __last1 && __first2 != __last2;
    }
# 1088
template < typename _InputIterator1, typename _InputIterator2 >
    pair < _InputIterator1, _InputIterator2 >
    mismatch ( _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2 )
    {






                                                       ;

      while ( __first1 != __last1 && * __first1 == * __first2 )
        {
   ++ __first1;
   ++ __first2;
        }
      return pair < _InputIterator1, _InputIterator2 > ( __first1, __first2 );
    }
# 1125
template < typename _InputIterator1, typename _InputIterator2,
    typename _BinaryPredicate >
    pair < _InputIterator1, _InputIterator2 >
    mismatch ( _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _BinaryPredicate __binary_pred )
    {



                                                       ;

      while ( __first1 != __last1 && bool ( __binary_pred ( * __first1, * __first2 ) ) )
        {
   ++ __first1;
   ++ __first2;
        }
      return pair < _InputIterator1, _InputIterator2 > ( __first1, __first2 );
    }

}
# 35 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/exception" 3
#pragma GCC visibility push ( default )





namespace std { 
# 59
class exception { 


public: exception() throw() { } 
virtual ~exception() throw(); 



virtual const char *what() const throw(); 
}; 



class bad_exception : public exception { 


public: bad_exception() throw() { } 



virtual ~bad_exception() throw(); 


virtual const char *what() const throw(); 
}; 


typedef void (*terminate_handler)(void); 


typedef void (*unexpected_handler)(void); 


terminate_handler set_terminate(terminate_handler) throw(); 



void terminate() __attribute((__noreturn__)); 


unexpected_handler set_unexpected(unexpected_handler) throw(); 



void unexpected() __attribute((__noreturn__)); 
# 115
bool uncaught_exception() throw(); 


}

namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 138
void __verbose_terminate_handler(); 

}



#pragma GCC visibility pop
# 42 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/new" 3
#pragma GCC visibility push ( default )



namespace std { 
# 54
class bad_alloc : public exception { 


public: bad_alloc() throw() { } 



virtual ~bad_alloc() throw(); 


virtual const char *what() const throw(); 
}; 

struct nothrow_t { }; 

extern const nothrow_t nothrow; 



typedef void (*new_handler)(void); 



new_handler set_new_handler(new_handler) throw(); 
}
# 91
void *operator new(size_t) throw(std::bad_alloc); 
void *operator new[](size_t) throw(std::bad_alloc); 
void operator delete(void *) throw(); 
void operator delete[](void *) throw(); 
void *operator new(size_t, const std::nothrow_t &) throw(); 
void *operator new[](size_t, const std::nothrow_t &) throw(); 
void operator delete(void *, const std::nothrow_t &) throw(); 
void operator delete[](void *, const std::nothrow_t &) throw(); 


inline void *operator new(size_t, void *__p) throw() { return __p; } 
inline void *operator new[](size_t, void *__p) throw() { return __p; } 


inline void operator delete(void *, void *) throw() { } 
inline void operator delete[](void *, void *) throw() { } 



#pragma GCC visibility pop
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/ext/new_allocator.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 

using std::size_t;
using std::ptrdiff_t;
# 50
template < typename _Tp >
    class new_allocator
    {
    public :
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp * pointer;
      typedef const _Tp * const_pointer;
      typedef _Tp & reference;
      typedef const _Tp & const_reference;
      typedef _Tp value_type;

      template < typename _Tp1 >
        struct rebind
        { typedef new_allocator < _Tp1 > other; };

      new_allocator ( ) throw ( ) { }

      new_allocator ( const new_allocator & ) throw ( ) { }

      template < typename _Tp1 >
        new_allocator ( const new_allocator < _Tp1 > & ) throw ( ) { }

      ~ new_allocator ( ) throw ( ) { }

      pointer
      address ( reference __x ) const { return & __x; }

      const_pointer
      address ( const_reference __x ) const { return & __x; }



      pointer
      allocate ( size_type __n, const void * = 0 )
      {
 if ( __builtin_expect ( __n > this -> max_size ( ), false ) )
   std :: __throw_bad_alloc ( );

 return static_cast < _Tp * > ( :: operator new ( __n * sizeof ( _Tp ) ) );
      }


      void
      deallocate ( pointer __p, size_type )
      { :: operator delete ( __p ); }

      size_type
      max_size ( ) const throw ( )
      { return size_t ( - 1 ) / sizeof ( _Tp ); }



      void
      construct ( pointer __p, const _Tp & __val )
      { :: new ( ( void * ) __p ) _Tp ( __val ); }








      void
      destroy ( pointer __p ) { __p -> ~ _Tp ( ); }
    };

template < typename _Tp >
    inline bool
    operator == ( const new_allocator < _Tp > &, const new_allocator < _Tp > & )
    { return true; }

template < typename _Tp >
    inline bool
    operator != ( const new_allocator < _Tp > &, const new_allocator < _Tp > & )
    { return false; }

}
# 50 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/allocator.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 59
template < typename _Tp >
    class allocator;



template<> class allocator< void>  { 


public: typedef size_t size_type; 
typedef ptrdiff_t difference_type; 
typedef void *pointer; 
typedef const void *const_pointer; 
typedef void value_type; 

template < typename _Tp1 >
        struct rebind
        { typedef allocator < _Tp1 > other; };
}; 
# 85
template < typename _Tp >
    class allocator : public __gnu_cxx :: new_allocator < _Tp >
    {
   public :
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp * pointer;
      typedef const _Tp * const_pointer;
      typedef _Tp & reference;
      typedef const _Tp & const_reference;
      typedef _Tp value_type;

      template < typename _Tp1 >
        struct rebind
        { typedef allocator < _Tp1 > other; };

      allocator ( ) throw ( ) { }

      allocator ( const allocator & __a ) throw ( )
      : __gnu_cxx :: new_allocator < _Tp > ( __a ) { }

      template < typename _Tp1 >
        allocator ( const allocator < _Tp1 > & ) throw ( ) { }

      ~ allocator ( ) throw ( ) { }


    };

template < typename _T1, typename _T2 >
    inline bool
    operator == ( const allocator < _T1 > &, const allocator < _T2 > & )
    { return true; }

template < typename _Tp >
    inline bool
    operator == ( const allocator < _Tp > &, const allocator < _Tp > & )
    { return true; }

template < typename _T1, typename _T2 >
    inline bool
    operator != ( const allocator < _T1 > &, const allocator < _T2 > & )
    { return false; }

template < typename _Tp >
    inline bool
    operator != ( const allocator < _Tp > &, const allocator < _Tp > & )
    { return false; }
# 138
extern template class allocator< char> ;
extern template class allocator< wchar_t> ;
# 146
template < typename _Alloc, bool = __is_empty ( _Alloc ) >
    struct __alloc_swap
    { static void _S_do_it ( _Alloc &, _Alloc & ) { } };

template < typename _Alloc >
    struct __alloc_swap < _Alloc, false >
    {
      static void
      _S_do_it ( _Alloc & __one, _Alloc & __two )
      {

 if ( __one != __two )
   swap ( __one, __two );
      }
    };


template < typename _Alloc, bool = __is_empty ( _Alloc ) >
    struct __alloc_neq
    {
      static bool
      _S_do_it ( const _Alloc &, const _Alloc & )
      { return false; }
    };

template < typename _Alloc >
    struct __alloc_neq < _Alloc, false >
    {
      static bool
      _S_do_it ( const _Alloc & __one, const _Alloc & __two )
      { return __one != __two; }
    };

}
# 62 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_construct.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 68
template < typename _T1, typename _T2 >
    inline void






    _Construct ( _T1 * __p, const _T2 & __value )
    {


      :: new ( static_cast < void * > ( __p ) ) _T1 ( __value );
    }
# 87
template < typename _Tp >
    inline void
    _Destroy ( _Tp * __pointer )
    { __pointer -> ~ _Tp ( ); }

template < bool >
    struct _Destroy_aux
    {
      template < typename _ForwardIterator >
        static void
        __destroy ( _ForwardIterator __first, _ForwardIterator __last )
 {
   for (; __first != __last; ++ __first )
     std :: _Destroy ( & * __first );
 }
    };


template<> struct _Destroy_aux< true>  { 

template < typename _ForwardIterator >
        static void
        __destroy ( _ForwardIterator, _ForwardIterator ) { }
}; 
# 117
template < typename _ForwardIterator >
    inline void
    _Destroy ( _ForwardIterator __first, _ForwardIterator __last )
    {
      typedef typename iterator_traits < _ForwardIterator > :: value_type
                       _Value_type;
      std :: _Destroy_aux < __has_trivial_destructor ( _Value_type ) > ::
 __destroy ( __first, __last );
    }
# 133
template < typename _Tp > class allocator;

template < typename _ForwardIterator, typename _Allocator >
    void
    _Destroy ( _ForwardIterator __first, _ForwardIterator __last,
      _Allocator & __alloc )
    {
      for (; __first != __last; ++ __first )
 __alloc . destroy ( & * __first );
    }

template < typename _ForwardIterator, typename _Tp >
    inline void
    _Destroy ( _ForwardIterator __first, _ForwardIterator __last,
      allocator < _Tp > & )
    {
      _Destroy ( __first, __last );
    }

}
# 60 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_uninitialized.h" 3
namespace std __attribute((__visibility__("default" ))) { 

template < bool >
    struct __uninitialized_copy
    {
      template < typename _InputIterator, typename _ForwardIterator >
        static _ForwardIterator
        uninitialized_copy ( _InputIterator __first, _InputIterator __last,
      _ForwardIterator __result )
        {
   _ForwardIterator __cur = __result;
   try
     {
       for (; __first != __last; ++ __first, ++ __cur )
  std :: _Construct ( & * __cur, * __first );
       return __cur;
     }
   catch ( ... )
     {
       std :: _Destroy ( __result, __cur );
       throw;
     }
 }
    };


template<> struct __uninitialized_copy< true>  { 

template < typename _InputIterator, typename _ForwardIterator >
        static _ForwardIterator
        uninitialized_copy ( _InputIterator __first, _InputIterator __last,
      _ForwardIterator __result )
        { return std :: copy ( __first, __last, __result ); }
}; 
# 104
template < typename _InputIterator, typename _ForwardIterator >
    inline _ForwardIterator
    uninitialized_copy ( _InputIterator __first, _InputIterator __last,
         _ForwardIterator __result )
    {
      typedef typename iterator_traits < _InputIterator > :: value_type
 _ValueType1;
      typedef typename iterator_traits < _ForwardIterator > :: value_type
 _ValueType2;

      return std :: __uninitialized_copy < ( __is_pod ( _ValueType1 )
     && __is_pod ( _ValueType2 ) ) > ::
 uninitialized_copy ( __first, __last, __result );
    }


template < bool >
    struct __uninitialized_fill
    {
      template < typename _ForwardIterator, typename _Tp >
        static void
        uninitialized_fill ( _ForwardIterator __first,
      _ForwardIterator __last, const _Tp & __x )
        {
   _ForwardIterator __cur = __first;
   try
     {
       for (; __cur != __last; ++ __cur )
  std :: _Construct ( & * __cur, __x );
     }
   catch ( ... )
     {
       std :: _Destroy ( __first, __cur );
       throw;
     }
 }
    };


template<> struct __uninitialized_fill< true>  { 

template < typename _ForwardIterator, typename _Tp >
        static void
        uninitialized_fill ( _ForwardIterator __first,
      _ForwardIterator __last, const _Tp & __x )
        { std :: fill ( __first, __last, __x ); }
}; 
# 161
template < typename _ForwardIterator, typename _Tp >
    inline void
    uninitialized_fill ( _ForwardIterator __first, _ForwardIterator __last,
         const _Tp & __x )
    {
      typedef typename iterator_traits < _ForwardIterator > :: value_type
 _ValueType;

      std :: __uninitialized_fill < __is_pod ( _ValueType ) > ::
 uninitialized_fill ( __first, __last, __x );
    }


template < bool >
    struct __uninitialized_fill_n
    {
      template < typename _ForwardIterator, typename _Size, typename _Tp >
        static void
        uninitialized_fill_n ( _ForwardIterator __first, _Size __n,
        const _Tp & __x )
        {
   _ForwardIterator __cur = __first;
   try
     {
       for (; __n > 0; -- __n, ++ __cur )
  std :: _Construct ( & * __cur, __x );
     }
   catch ( ... )
     {
       std :: _Destroy ( __first, __cur );
       throw;
     }
 }
    };


template<> struct __uninitialized_fill_n< true>  { 

template < typename _ForwardIterator, typename _Size, typename _Tp >
        static void
        uninitialized_fill_n ( _ForwardIterator __first, _Size __n,
        const _Tp & __x )
        { std :: fill_n ( __first, __n, __x ); }
}; 
# 215
template < typename _ForwardIterator, typename _Size, typename _Tp >
    inline void
    uninitialized_fill_n ( _ForwardIterator __first, _Size __n, const _Tp & __x )
    {
      typedef typename iterator_traits < _ForwardIterator > :: value_type
 _ValueType;

      std :: __uninitialized_fill_n < __is_pod ( _ValueType ) > ::
 uninitialized_fill_n ( __first, __n, __x );
    }
# 232
template < typename _InputIterator, typename _ForwardIterator,
    typename _Allocator >
    _ForwardIterator
    __uninitialized_copy_a ( _InputIterator __first, _InputIterator __last,
      _ForwardIterator __result, _Allocator & __alloc )
    {
      _ForwardIterator __cur = __result;
      try
 {
   for (; __first != __last; ++ __first, ++ __cur )
     __alloc . construct ( & * __cur, * __first );
   return __cur;
 }
      catch ( ... )
 {
   std :: _Destroy ( __result, __cur, __alloc );
   throw;
 }
    }

template < typename _InputIterator, typename _ForwardIterator, typename _Tp >
    inline _ForwardIterator
    __uninitialized_copy_a ( _InputIterator __first, _InputIterator __last,
      _ForwardIterator __result, allocator < _Tp > & )
    { return std :: uninitialized_copy ( __first, __last, __result ); }

template < typename _InputIterator, typename _ForwardIterator,
    typename _Allocator >
    inline _ForwardIterator
    __uninitialized_move_a ( _InputIterator __first, _InputIterator __last,
      _ForwardIterator __result, _Allocator & __alloc )
    {
      return std :: __uninitialized_copy_a ( ( __first ),
      ( __last ),
      __result, __alloc );
    }

template < typename _ForwardIterator, typename _Tp, typename _Allocator >
    void
    __uninitialized_fill_a ( _ForwardIterator __first, _ForwardIterator __last,
      const _Tp & __x, _Allocator & __alloc )
    {
      _ForwardIterator __cur = __first;
      try
 {
   for (; __cur != __last; ++ __cur )
     __alloc . construct ( & * __cur, __x );
 }
      catch ( ... )
 {
   std :: _Destroy ( __first, __cur, __alloc );
   throw;
 }
    }

template < typename _ForwardIterator, typename _Tp, typename _Tp2 >
    inline void
    __uninitialized_fill_a ( _ForwardIterator __first, _ForwardIterator __last,
      const _Tp & __x, allocator < _Tp2 > & )
    { std :: uninitialized_fill ( __first, __last, __x ); }

template < typename _ForwardIterator, typename _Size, typename _Tp,
    typename _Allocator >
    void
    __uninitialized_fill_n_a ( _ForwardIterator __first, _Size __n,
        const _Tp & __x, _Allocator & __alloc )
    {
      _ForwardIterator __cur = __first;
      try
 {
   for (; __n > 0; -- __n, ++ __cur )
     __alloc . construct ( & * __cur, __x );
 }
      catch ( ... )
 {
   std :: _Destroy ( __first, __cur, __alloc );
   throw;
 }
    }

template < typename _ForwardIterator, typename _Size, typename _Tp,
    typename _Tp2 >
    inline void
    __uninitialized_fill_n_a ( _ForwardIterator __first, _Size __n,
        const _Tp & __x, allocator < _Tp2 > & )
    { std :: uninitialized_fill_n ( __first, __n, __x ); }
# 329
template < typename _InputIterator1, typename _InputIterator2,
    typename _ForwardIterator, typename _Allocator >
    inline _ForwardIterator
    __uninitialized_copy_move ( _InputIterator1 __first1,
         _InputIterator1 __last1,
         _InputIterator2 __first2,
         _InputIterator2 __last2,
         _ForwardIterator __result,
         _Allocator & __alloc )
    {
      _ForwardIterator __mid = std :: __uninitialized_copy_a ( __first1, __last1,
          __result,
          __alloc );
      try
 {
   return std :: __uninitialized_move_a ( __first2, __last2, __mid, __alloc );
 }
      catch ( ... )
 {
   std :: _Destroy ( __result, __mid, __alloc );
   throw;
 }
    }
# 357
template < typename _InputIterator1, typename _InputIterator2,
    typename _ForwardIterator, typename _Allocator >
    inline _ForwardIterator
    __uninitialized_move_copy ( _InputIterator1 __first1,
         _InputIterator1 __last1,
         _InputIterator2 __first2,
         _InputIterator2 __last2,
         _ForwardIterator __result,
         _Allocator & __alloc )
    {
      _ForwardIterator __mid = std :: __uninitialized_move_a ( __first1, __last1,
          __result,
          __alloc );
      try
 {
   return std :: __uninitialized_copy_a ( __first2, __last2, __mid, __alloc );
 }
      catch ( ... )
 {
   std :: _Destroy ( __result, __mid, __alloc );
   throw;
 }
    }




template < typename _ForwardIterator, typename _Tp, typename _InputIterator,
    typename _Allocator >
    inline _ForwardIterator
    __uninitialized_fill_move ( _ForwardIterator __result, _ForwardIterator __mid,
         const _Tp & __x, _InputIterator __first,
         _InputIterator __last, _Allocator & __alloc )
    {
      std :: __uninitialized_fill_a ( __result, __mid, __x, __alloc );
      try
 {
   return std :: __uninitialized_move_a ( __first, __last, __mid, __alloc );
 }
      catch ( ... )
 {
   std :: _Destroy ( __result, __mid, __alloc );
   throw;
 }
    }




template < typename _InputIterator, typename _ForwardIterator, typename _Tp,
    typename _Allocator >
    inline void
    __uninitialized_move_fill ( _InputIterator __first1, _InputIterator __last1,
         _ForwardIterator __first2,
         _ForwardIterator __last2, const _Tp & __x,
         _Allocator & __alloc )
    {
      _ForwardIterator __mid2 = std :: __uninitialized_move_a ( __first1, __last1,
           __first2,
           __alloc );
      try
 {
   std :: __uninitialized_fill_a ( __mid2, __last2, __x, __alloc );
 }
      catch ( ... )
 {
   std :: _Destroy ( __first2, __mid2, __alloc );
   throw;
 }
    }
# 475
}
# 65 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_vector.h" 3
namespace std __attribute((__visibility__("default" ))) { 


template < typename _Tp, typename _Alloc >
    struct _Vector_base
    {
      typedef typename _Alloc :: template rebind < _Tp > :: other _Tp_alloc_type;

      struct _Vector_impl
      : public _Tp_alloc_type
      {
 typename _Tp_alloc_type :: pointer _M_start;
 typename _Tp_alloc_type :: pointer _M_finish;
 typename _Tp_alloc_type :: pointer _M_end_of_storage;

 _Vector_impl ( )
 : _Tp_alloc_type ( ), _M_start ( 0 ), _M_finish ( 0 ), _M_end_of_storage ( 0 )
 { }

 _Vector_impl ( _Tp_alloc_type const & __a )
 : _Tp_alloc_type ( __a ), _M_start ( 0 ), _M_finish ( 0 ), _M_end_of_storage ( 0 )
 { }
      };

    public :
      typedef _Alloc allocator_type;

      _Tp_alloc_type &
      _M_get_Tp_allocator ( )
      { return * static_cast < _Tp_alloc_type * > ( & this -> _M_impl ); }

      const _Tp_alloc_type &
      _M_get_Tp_allocator ( ) const
      { return * static_cast < const _Tp_alloc_type * > ( & this -> _M_impl ); }

      allocator_type
      get_allocator ( ) const
      { return allocator_type ( _M_get_Tp_allocator ( ) ); }

      _Vector_base ( )
      : _M_impl ( ) { }

      _Vector_base ( const allocator_type & __a )
      : _M_impl ( __a ) { }

      _Vector_base ( size_t __n, const allocator_type & __a )
      : _M_impl ( __a )
      {
 this -> _M_impl . _M_start = this -> _M_allocate ( __n );
 this -> _M_impl . _M_finish = this -> _M_impl . _M_start;
 this -> _M_impl . _M_end_of_storage = this -> _M_impl . _M_start + __n;
      }














      ~ _Vector_base ( )
      { _M_deallocate ( this -> _M_impl . _M_start, this -> _M_impl . _M_end_of_storage
        - this -> _M_impl . _M_start ); }

    public :
      _Vector_impl _M_impl;

      typename _Tp_alloc_type :: pointer
      _M_allocate ( size_t __n )
      { return __n != 0 ? _M_impl . allocate ( __n ) : 0; }

      void
      _M_deallocate ( typename _Tp_alloc_type :: pointer __p, size_t __n )
      {
 if ( __p )
   _M_impl . deallocate ( __p, __n );
      }
    };
# 169
template < typename _Tp, typename _Alloc = std :: allocator < _Tp > >
    class vector : protected _Vector_base < _Tp, _Alloc >
    {

      typedef typename _Alloc :: value_type _Alloc_value_type;



      typedef _Vector_base < _Tp, _Alloc > _Base;
      typedef typename _Base :: _Tp_alloc_type _Tp_alloc_type;

    public :
      typedef _Tp value_type;
      typedef typename _Tp_alloc_type :: pointer pointer;
      typedef typename _Tp_alloc_type :: const_pointer const_pointer;
      typedef typename _Tp_alloc_type :: reference reference;
      typedef typename _Tp_alloc_type :: const_reference const_reference;
      typedef __gnu_cxx :: __normal_iterator < pointer, vector > iterator;
      typedef __gnu_cxx :: __normal_iterator < const_pointer, vector >
      const_iterator;
      typedef std :: reverse_iterator < const_iterator > const_reverse_iterator;
      typedef std :: reverse_iterator < iterator > reverse_iterator;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Alloc allocator_type;

    protected :
      using _Base :: _M_allocate;
      using _Base :: _M_deallocate;
      using _Base :: _M_impl;
      using _Base :: _M_get_Tp_allocator;

    public :





      vector ( )
      : _Base ( ) { }





      explicit
      vector ( const allocator_type & __a )
      : _Base ( __a ) { }









      explicit
      vector ( size_type __n, const value_type & __value = value_type ( ),
      const allocator_type & __a = allocator_type ( ) )
      : _Base ( __n, __a )
      { _M_fill_initialize ( __n, __value ); }










      vector ( const vector & __x )
      : _Base ( __x . size ( ), __x . _M_get_Tp_allocator ( ) )
      { this -> _M_impl . _M_finish =
   std :: __uninitialized_copy_a ( __x . begin ( ), __x . end ( ),
          this -> _M_impl . _M_start,
          _M_get_Tp_allocator ( ) );
      }
















































      template < typename _InputIterator >
        vector ( _InputIterator __first, _InputIterator __last,
        const allocator_type & __a = allocator_type ( ) )
 : _Base ( __a )
        {

   typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
   _M_initialize_dispatch ( __first, __last, _Integral ( ) );
 }







      ~ vector ( )
      { std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
        _M_get_Tp_allocator ( ) ); }









      vector &
      operator = ( const vector & __x );















































      void
      assign ( size_type __n, const value_type & __val )
      { _M_fill_assign ( __n, __val ); }













      template < typename _InputIterator >
        void
        assign ( _InputIterator __first, _InputIterator __last )
        {

   typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
   _M_assign_dispatch ( __first, __last, _Integral ( ) );
 }



















      using _Base :: get_allocator;







      iterator
      begin ( )
      { return iterator ( this -> _M_impl . _M_start ); }






      const_iterator
      begin ( ) const
      { return const_iterator ( this -> _M_impl . _M_start ); }






      iterator
      end ( )
      { return iterator ( this -> _M_impl . _M_finish ); }






      const_iterator
      end ( ) const
      { return const_iterator ( this -> _M_impl . _M_finish ); }






      reverse_iterator
      rbegin ( )
      { return reverse_iterator ( end ( ) ); }






      const_reverse_iterator
      rbegin ( ) const
      { return const_reverse_iterator ( end ( ) ); }






      reverse_iterator
      rend ( )
      { return reverse_iterator ( begin ( ) ); }






      const_reverse_iterator
      rend ( ) const
      { return const_reverse_iterator ( begin ( ) ); }









































      size_type
      size ( ) const
      { return size_type ( this -> _M_impl . _M_finish - this -> _M_impl . _M_start ); }


      size_type
      max_size ( ) const
      { return _M_get_Tp_allocator ( ) . max_size ( ); }












      void
      resize ( size_type __new_size, value_type __x = value_type ( ) )
      {
 if ( __new_size < size ( ) )
   _M_erase_at_end ( this -> _M_impl . _M_start + __new_size );
 else
   insert ( end ( ), __new_size - size ( ), __x );
      }





      size_type
      capacity ( ) const
      { return size_type ( this -> _M_impl . _M_end_of_storage
    - this -> _M_impl . _M_start ); }





      bool
      empty ( ) const
      { return begin ( ) == end ( ); }


















      void
      reserve ( size_type __n );













      reference
      operator [ ] ( size_type __n )
      { return * ( this -> _M_impl . _M_start + __n ); }












      const_reference
      operator [ ] ( size_type __n ) const
      { return * ( this -> _M_impl . _M_start + __n ); }

    protected :

      void
      _M_range_check ( size_type __n ) const
      {
 if ( __n >= this -> size ( ) )
   __throw_out_of_range ( ( "vector::_M_range_check" ) );
      }

    public :











      reference
      at ( size_type __n )
      {
 _M_range_check ( __n );
 return ( * this ) [ __n ];
      }












      const_reference
      at ( size_type __n ) const
      {
 _M_range_check ( __n );
 return ( * this ) [ __n ];
      }





      reference
      front ( )
      { return * begin ( ); }





      const_reference
      front ( ) const
      { return * begin ( ); }





      reference
      back ( )
      { return * ( end ( ) - 1 ); }





      const_reference
      back ( ) const
      { return * ( end ( ) - 1 ); }








      pointer
      data ( )
      { return pointer ( this -> _M_impl . _M_start ); }

      const_pointer
      data ( ) const
      { return const_pointer ( this -> _M_impl . _M_start ); }












      void
      push_back ( const value_type & __x )
      {
 if ( this -> _M_impl . _M_finish != this -> _M_impl . _M_end_of_storage )
   {
     this -> _M_impl . construct ( this -> _M_impl . _M_finish, __x );
     ++ this -> _M_impl . _M_finish;
   }
 else
   _M_insert_aux ( end ( ), __x );
      }




















      void
      pop_back ( )
      {
 -- this -> _M_impl . _M_finish;
 this -> _M_impl . destroy ( this -> _M_impl . _M_finish );
      }






























      iterator
      insert ( iterator __position, const value_type & __x );
















































      void
      insert ( iterator __position, size_type __n, const value_type & __x )
      { _M_fill_insert ( __position, __n, __x ); }















      template < typename _InputIterator >
        void
        insert ( iterator __position, _InputIterator __first,
        _InputIterator __last )
        {

   typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
   _M_insert_dispatch ( __position, __first, __last, _Integral ( ) );
 }
















      iterator
      erase ( iterator __position );



















      iterator
      erase ( iterator __first, iterator __last );










      void



      swap ( vector & __x )

      {
 std :: swap ( this -> _M_impl . _M_start, __x . _M_impl . _M_start );
 std :: swap ( this -> _M_impl . _M_finish, __x . _M_impl . _M_finish );
 std :: swap ( this -> _M_impl . _M_end_of_storage,
    __x . _M_impl . _M_end_of_storage );



 std :: __alloc_swap < _Tp_alloc_type > :: _S_do_it ( _M_get_Tp_allocator ( ),
          __x . _M_get_Tp_allocator ( ) );
      }







      void
      clear ( )
      { _M_erase_at_end ( this -> _M_impl . _M_start ); }

    protected :




      template < typename _ForwardIterator >
        pointer
        _M_allocate_and_copy ( size_type __n,
        _ForwardIterator __first, _ForwardIterator __last )
        {
   pointer __result = this -> _M_allocate ( __n );
   try
     {
       std :: __uninitialized_copy_a ( __first, __last, __result,
       _M_get_Tp_allocator ( ) );
       return __result;
     }
   catch ( ... )
     {
       _M_deallocate ( __result, __n );
       throw;
     }
 }








      template < typename _Integer >
        void
        _M_initialize_dispatch ( _Integer __n, _Integer __value, __true_type )
        {
   this -> _M_impl . _M_start = _M_allocate ( static_cast < size_type > ( __n ) );
   this -> _M_impl . _M_end_of_storage =
     this -> _M_impl . _M_start + static_cast < size_type > ( __n );
   _M_fill_initialize ( static_cast < size_type > ( __n ), __value );
 }


      template < typename _InputIterator >
        void
        _M_initialize_dispatch ( _InputIterator __first, _InputIterator __last,
          __false_type )
        {
   typedef typename std :: iterator_traits < _InputIterator > ::
     iterator_category _IterCategory;
   _M_range_initialize ( __first, __last, _IterCategory ( ) );
 }


      template < typename _InputIterator >
        void
        _M_range_initialize ( _InputIterator __first,
       _InputIterator __last, std :: input_iterator_tag )
        {
   for (; __first != __last; ++ __first )
     push_back ( * __first );
 }


      template < typename _ForwardIterator >
        void
        _M_range_initialize ( _ForwardIterator __first,
       _ForwardIterator __last, std :: forward_iterator_tag )
        {
   const size_type __n = std :: distance ( __first, __last );
   this -> _M_impl . _M_start = this -> _M_allocate ( __n );
   this -> _M_impl . _M_end_of_storage = this -> _M_impl . _M_start + __n;
   this -> _M_impl . _M_finish =
     std :: __uninitialized_copy_a ( __first, __last,
     this -> _M_impl . _M_start,
     _M_get_Tp_allocator ( ) );
 }



      void
      _M_fill_initialize ( size_type __n, const value_type & __value )
      {
 std :: __uninitialized_fill_n_a ( this -> _M_impl . _M_start, __n, __value,
          _M_get_Tp_allocator ( ) );
 this -> _M_impl . _M_finish = this -> _M_impl . _M_end_of_storage;
      }









      template < typename _Integer >
        void
        _M_assign_dispatch ( _Integer __n, _Integer __val, __true_type )
        { _M_fill_assign ( __n, __val ); }


      template < typename _InputIterator >
        void
        _M_assign_dispatch ( _InputIterator __first, _InputIterator __last,
      __false_type )
        {
   typedef typename std :: iterator_traits < _InputIterator > ::
     iterator_category _IterCategory;
   _M_assign_aux ( __first, __last, _IterCategory ( ) );
 }


      template < typename _InputIterator >
        void
        _M_assign_aux ( _InputIterator __first, _InputIterator __last,
        std :: input_iterator_tag );


      template < typename _ForwardIterator >
        void
        _M_assign_aux ( _ForwardIterator __first, _ForwardIterator __last,
        std :: forward_iterator_tag );



      void
      _M_fill_assign ( size_type __n, const value_type & __val );








      template < typename _Integer >
        void
        _M_insert_dispatch ( iterator __pos, _Integer __n, _Integer __val,
      __true_type )
        { _M_fill_insert ( __pos, __n, __val ); }


      template < typename _InputIterator >
        void
        _M_insert_dispatch ( iterator __pos, _InputIterator __first,
      _InputIterator __last, __false_type )
        {
   typedef typename std :: iterator_traits < _InputIterator > ::
     iterator_category _IterCategory;
   _M_range_insert ( __pos, __first, __last, _IterCategory ( ) );
 }


      template < typename _InputIterator >
        void
        _M_range_insert ( iterator __pos, _InputIterator __first,
   _InputIterator __last, std :: input_iterator_tag );


      template < typename _ForwardIterator >
        void
        _M_range_insert ( iterator __pos, _ForwardIterator __first,
   _ForwardIterator __last, std :: forward_iterator_tag );



      void
      _M_fill_insert ( iterator __pos, size_type __n, const value_type & __x );



      void
      _M_insert_aux ( iterator __position, const value_type & __x );







      size_type
      _M_check_len ( size_type __n, const char * __s ) const
      {
 if ( max_size ( ) - size ( ) < __n )
   __throw_length_error ( ( __s ) );

 const size_type __len = size ( ) + std :: max ( size ( ), __n );
 return ( __len < size ( ) || __len > max_size ( ) ) ? max_size ( ) : __len;
      }





      void
      _M_erase_at_end ( pointer __pos )
      {
 std :: _Destroy ( __pos, this -> _M_impl . _M_finish, _M_get_Tp_allocator ( ) );
 this -> _M_impl . _M_finish = __pos;
      }
    };
# 1166
template < typename _Tp, typename _Alloc >
    inline bool
    operator == ( const vector < _Tp, _Alloc > & __x, const vector < _Tp, _Alloc > & __y )
    { return ( __x . size ( ) == __y . size ( )
       && std :: equal ( __x . begin ( ), __x . end ( ), __y . begin ( ) ) ); }
# 1183
template < typename _Tp, typename _Alloc >
    inline bool
    operator < ( const vector < _Tp, _Alloc > & __x, const vector < _Tp, _Alloc > & __y )
    { return std :: lexicographical_compare ( __x . begin ( ), __x . end ( ),
       __y . begin ( ), __y . end ( ) ); }


template < typename _Tp, typename _Alloc >
    inline bool
    operator != ( const vector < _Tp, _Alloc > & __x, const vector < _Tp, _Alloc > & __y )
    { return ! ( __x == __y ); }


template < typename _Tp, typename _Alloc >
    inline bool
    operator > ( const vector < _Tp, _Alloc > & __x, const vector < _Tp, _Alloc > & __y )
    { return __y < __x; }


template < typename _Tp, typename _Alloc >
    inline bool
    operator <= ( const vector < _Tp, _Alloc > & __x, const vector < _Tp, _Alloc > & __y )
    { return ! ( __y < __x ); }


template < typename _Tp, typename _Alloc >
    inline bool
    operator >= ( const vector < _Tp, _Alloc > & __x, const vector < _Tp, _Alloc > & __y )
    { return ! ( __x < __y ); }


template < typename _Tp, typename _Alloc >
    inline void
    swap ( vector < _Tp, _Alloc > & __x, vector < _Tp, _Alloc > & __y )
    { __x . swap ( __y ); }
# 1231
}
# 62 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_bvector.h" 3
namespace std __attribute((__visibility__("default" ))) { 

typedef unsigned long _Bit_type; 
enum { _S_word_bit = 64}; 

struct _Bit_reference { 

_Bit_type *_M_p; 
_Bit_type _M_mask; 

_Bit_reference(_Bit_type *__x, _Bit_type __y) : _M_p(__x), _M_mask(__y) 
{ } 

_Bit_reference() : _M_p(0), _M_mask(0) { } 

operator bool() const 
{ return !(!(*(_M_p) & _M_mask)); } 


_Bit_reference &operator=(bool __x) 
{ 
if (__x) { 
*(_M_p) |= _M_mask; } else { 

*(_M_p) &= ~_M_mask; }  
return *this; 
} 


_Bit_reference &operator=(const _Bit_reference &__x) 
{ return (*this = (bool)__x); } 


bool operator==(const _Bit_reference &__x) const 
{ return (bool)(*this) == (bool)__x; } 


bool operator<(const _Bit_reference &__x) const 
{ return !((bool)(*this)) && (bool)__x; } 


void flip() 
{ *(_M_p) ^= _M_mask; } 
}; 

struct _Bit_iterator_base : public iterator< random_access_iterator_tag, bool>  { 


_Bit_type *_M_p; 
unsigned _M_offset; 

_Bit_iterator_base(_Bit_type *__x, unsigned __y) : _M_p(__x), _M_offset(__y) 
{ } 


void _M_bump_up() 
{ 
if ((_M_offset)++ == (int)_S_word_bit - 1) 
{ 
_M_offset = (0); 
++_M_p; 
}  
} 


void _M_bump_down() 
{ 
if ((_M_offset)-- == (0)) 
{ 
_M_offset = (int)_S_word_bit - 1; 
--_M_p; 
}  
} 


void _M_incr(ptrdiff_t __i) 
{ 
difference_type __n = __i + _M_offset; 
_M_p += __n / (int)_S_word_bit; 
__n = __n % (int)_S_word_bit; 
if (__n < (0)) 
{ 
__n += (int)_S_word_bit; 
--_M_p; 
}  
_M_offset = static_cast< unsigned>(__n); 
} 


bool operator==(const _Bit_iterator_base &__i) const 
{ return _M_p == __i._M_p && _M_offset == __i._M_offset; } 


bool operator<(const _Bit_iterator_base &__i) const 
{ 
return _M_p < __i._M_p || _M_p == __i._M_p && _M_offset < __i._M_offset; 

} 


bool operator!=(const _Bit_iterator_base &__i) const 
{ return !(*this == __i); } 


bool operator>(const _Bit_iterator_base &__i) const 
{ return (__i < *this); } 


bool operator<=(const _Bit_iterator_base &__i) const 
{ return !(__i < *this); } 


bool operator>=(const _Bit_iterator_base &__i) const 
{ return !(*this < __i); } 
}; 


inline ptrdiff_t operator-(const _Bit_iterator_base &__x, const _Bit_iterator_base &__y) 
{ 
return ((int)_S_word_bit * (__x._M_p - __y._M_p) + __x._M_offset) - __y._M_offset; 

} 

struct _Bit_iterator : public _Bit_iterator_base { 

typedef _Bit_reference reference; 
typedef _Bit_reference *pointer; 
typedef _Bit_iterator iterator; 

_Bit_iterator() : _Bit_iterator_base(0, 0) { } 

_Bit_iterator(_Bit_type *__x, unsigned __y) : _Bit_iterator_base(__x, __y) 
{ } 


reference operator*() const 
{ return reference(_M_p, 1UL << _M_offset); } 


iterator &operator++() 
{ 
this->_M_bump_up(); 
return *this; 
} 


iterator operator++(int) 
{ 
iterator __tmp = *this; 
this->_M_bump_up(); 
return __tmp; 
} 


iterator &operator--() 
{ 
this->_M_bump_down(); 
return *this; 
} 


iterator operator--(int) 
{ 
iterator __tmp = *this; 
this->_M_bump_down(); 
return __tmp; 
} 


iterator &operator+=(difference_type __i) 
{ 
this->_M_incr(__i); 
return *this; 
} 


iterator &operator-=(difference_type __i) 
{ 
(*this += -__i); 
return *this; 
} 


iterator operator+(difference_type __i) const 
{ 
iterator __tmp = *this; 
return (__tmp += __i); 
} 


iterator operator-(difference_type __i) const 
{ 
iterator __tmp = *this; 
return (__tmp -= __i); 
} 


reference operator[](difference_type __i) const 
{ return (*(*this + __i)); } 
}; 


inline _Bit_iterator operator+(ptrdiff_t __n, const _Bit_iterator &__x) 
{ return (__x + __n); } 

struct _Bit_const_iterator : public _Bit_iterator_base { 

typedef bool reference; 
typedef bool const_reference; 
typedef const bool *pointer; 
typedef _Bit_const_iterator const_iterator; 

_Bit_const_iterator() : _Bit_iterator_base(0, 0) { } 

_Bit_const_iterator(_Bit_type *__x, unsigned __y) : _Bit_iterator_base(__x, __y) 
{ } 

_Bit_const_iterator(const _Bit_iterator &__x) : _Bit_iterator_base(__x._M_p, __x._M_offset) 
{ } 


const_reference operator*() const 
{ return _Bit_reference(_M_p, 1UL << _M_offset); } 


const_iterator &operator++() 
{ 
this->_M_bump_up(); 
return *this; 
} 


const_iterator operator++(int) 
{ 
const_iterator __tmp = *this; 
this->_M_bump_up(); 
return __tmp; 
} 


const_iterator &operator--() 
{ 
this->_M_bump_down(); 
return *this; 
} 


const_iterator operator--(int) 
{ 
const_iterator __tmp = *this; 
this->_M_bump_down(); 
return __tmp; 
} 


const_iterator &operator+=(difference_type __i) 
{ 
this->_M_incr(__i); 
return *this; 
} 


const_iterator &operator-=(difference_type __i) 
{ 
(*this += -__i); 
return *this; 
} 


const_iterator operator+(difference_type __i) const 
{ 
const_iterator __tmp = *this; 
return (__tmp += __i); 
} 


const_iterator operator-(difference_type __i) const 
{ 
const_iterator __tmp = *this; 
return (__tmp -= __i); 
} 


const_reference operator[](difference_type __i) const 
{ return (*(*this + __i)); } 
}; 


inline _Bit_const_iterator operator+(ptrdiff_t __n, const _Bit_const_iterator &__x) 
{ return (__x + __n); } 


inline void __fill_bvector(_Bit_iterator __first, _Bit_iterator __last, bool __x) 
{ 
for (; (__first != __last); (++__first)) { 
((*__first) = __x); }  
} 


inline void fill(_Bit_iterator __first, _Bit_iterator __last, const bool &__x) 
{ 
if (__first._M_p != __last._M_p) 
{ 
std::fill(__first._M_p + 1, __last._M_p, __x ? (~0) : 0); 
__fill_bvector(__first, _Bit_iterator(__first._M_p + 1, 0), __x); 
__fill_bvector(_Bit_iterator(__last._M_p, 0), __last, __x); 
} else { 

__fill_bvector(__first, __last, __x); }  
} 

template < typename _Alloc >
    struct _Bvector_base
    {
      typedef typename _Alloc :: template rebind < _Bit_type > :: other
        _Bit_alloc_type;

      struct _Bvector_impl
      : public _Bit_alloc_type
      {
 _Bit_iterator _M_start;
 _Bit_iterator _M_finish;
 _Bit_type * _M_end_of_storage;

 _Bvector_impl ( )
 : _Bit_alloc_type ( ), _M_start ( ), _M_finish ( ), _M_end_of_storage ( 0 )
 { }

 _Bvector_impl ( const _Bit_alloc_type & __a )
 : _Bit_alloc_type ( __a ), _M_start ( ), _M_finish ( ), _M_end_of_storage ( 0 )
 { }
      };

    public :
      typedef _Alloc allocator_type;

      _Bit_alloc_type &
      _M_get_Bit_allocator ( )
      { return * static_cast < _Bit_alloc_type * > ( & this -> _M_impl ); }

      const _Bit_alloc_type &
      _M_get_Bit_allocator ( ) const
      { return * static_cast < const _Bit_alloc_type * > ( & this -> _M_impl ); }

      allocator_type
      get_allocator ( ) const
      { return allocator_type ( _M_get_Bit_allocator ( ) ); }

      _Bvector_base ( )
      : _M_impl ( ) { }

      _Bvector_base ( const allocator_type & __a )
      : _M_impl ( __a ) { }














      ~ _Bvector_base ( )
      { this -> _M_deallocate ( ); }

    protected :
      _Bvector_impl _M_impl;

      _Bit_type *
      _M_allocate ( size_t __n )
      { return _M_impl . allocate ( ( __n + int ( _S_word_bit ) - 1 )
    / int ( _S_word_bit ) ); }

      void
      _M_deallocate ( )
      {
 if ( _M_impl . _M_start . _M_p )
   _M_impl . deallocate ( _M_impl . _M_start . _M_p,
        _M_impl . _M_end_of_storage - _M_impl . _M_start . _M_p );
      }
    };

}




namespace std __attribute((__visibility__("default" ))) { 
# 473
template < typename _Alloc >
  class vector < bool, _Alloc > : protected _Bvector_base < _Alloc >
  {
    typedef _Bvector_base < _Alloc > _Base;

  public :
    typedef bool value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Bit_reference reference;
    typedef bool const_reference;
    typedef _Bit_reference * pointer;
    typedef const bool * const_pointer;
    typedef _Bit_iterator iterator;
    typedef _Bit_const_iterator const_iterator;
    typedef std :: reverse_iterator < const_iterator > const_reverse_iterator;
    typedef std :: reverse_iterator < iterator > reverse_iterator;
    typedef _Alloc allocator_type;

    allocator_type get_allocator ( ) const
    { return _Base :: get_allocator ( ); }

  protected :
    using _Base :: _M_allocate;
    using _Base :: _M_deallocate;
    using _Base :: _M_get_Bit_allocator;

  public :
    vector ( )
    : _Base ( ) { }

    explicit
    vector ( const allocator_type & __a )
    : _Base ( __a ) { }

    explicit
    vector ( size_type __n, const bool & __value = bool ( ),
    const allocator_type & __a = allocator_type ( ) )
    : _Base ( __a )
    {
      _M_initialize ( __n );
      std :: fill ( this -> _M_impl . _M_start . _M_p, this -> _M_impl . _M_end_of_storage,
  __value ? ~ 0 : 0 );
    }

    vector ( const vector & __x )
    : _Base ( __x . _M_get_Bit_allocator ( ) )
    {
      _M_initialize ( __x . size ( ) );
      _M_copy_aligned ( __x . begin ( ), __x . end ( ), this -> _M_impl . _M_start );
    }














    template < typename _InputIterator >
      vector ( _InputIterator __first, _InputIterator __last,
      const allocator_type & __a = allocator_type ( ) )
      : _Base ( __a )
      {
 typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
 _M_initialize_dispatch ( __first, __last, _Integral ( ) );
      }

    ~ vector ( ) { }

    vector &
    operator = ( const vector & __x )
    {
      if ( & __x == this )
 return * this;
      if ( __x . size ( ) > capacity ( ) )
 {
   this -> _M_deallocate ( );
   _M_initialize ( __x . size ( ) );
 }
      this -> _M_impl . _M_finish = _M_copy_aligned ( __x . begin ( ), __x . end ( ),
      begin ( ) );
      return * this;
    }























    void
    assign ( size_type __n, const bool & __x )
    { _M_fill_assign ( __n, __x ); }

    template < typename _InputIterator >
      void
      assign ( _InputIterator __first, _InputIterator __last )
      {
 typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
 _M_assign_dispatch ( __first, __last, _Integral ( ) );
      }







    iterator
    begin ( )
    { return this -> _M_impl . _M_start; }

    const_iterator
    begin ( ) const
    { return this -> _M_impl . _M_start; }

    iterator
    end ( )
    { return this -> _M_impl . _M_finish; }

    const_iterator
    end ( ) const
    { return this -> _M_impl . _M_finish; }

    reverse_iterator
    rbegin ( )
    { return reverse_iterator ( end ( ) ); }

    const_reverse_iterator
    rbegin ( ) const
    { return const_reverse_iterator ( end ( ) ); }

    reverse_iterator
    rend ( )
    { return reverse_iterator ( begin ( ) ); }

    const_reverse_iterator
    rend ( ) const
    { return const_reverse_iterator ( begin ( ) ); }



















    size_type
    size ( ) const
    { return size_type ( end ( ) - begin ( ) ); }

    size_type
    max_size ( ) const
    {
      const size_type __isize =
 __gnu_cxx :: __numeric_traits < difference_type > :: __max
 - int ( _S_word_bit ) + 1;
      const size_type __asize = _M_get_Bit_allocator ( ) . max_size ( );
      return ( __asize <= __isize / int ( _S_word_bit )
       ? __asize * int ( _S_word_bit ) : __isize );
    }

    size_type
    capacity ( ) const
    { return size_type ( const_iterator ( this -> _M_impl . _M_end_of_storage, 0 )
         - begin ( ) ); }

    bool
    empty ( ) const
    { return begin ( ) == end ( ); }

    reference
    operator [ ] ( size_type __n )
    {
      return * iterator ( this -> _M_impl . _M_start . _M_p
         + __n / int ( _S_word_bit ), __n % int ( _S_word_bit ) );
    }

    const_reference
    operator [ ] ( size_type __n ) const
    {
      return * const_iterator ( this -> _M_impl . _M_start . _M_p
        + __n / int ( _S_word_bit ), __n % int ( _S_word_bit ) );
    }

  protected :
    void
    _M_range_check ( size_type __n ) const
    {
      if ( __n >= this -> size ( ) )
        __throw_out_of_range ( ( "vector<bool>::_M_range_check" ) );
    }

  public :
    reference
    at ( size_type __n )
    { _M_range_check ( __n ); return ( * this ) [ __n ]; }

    const_reference
    at ( size_type __n ) const
    { _M_range_check ( __n ); return ( * this ) [ __n ]; }

    void
    reserve ( size_type __n );

    reference
    front ( )
    { return * begin ( ); }

    const_reference
    front ( ) const
    { return * begin ( ); }

    reference
    back ( )
    { return * ( end ( ) - 1 ); }

    const_reference
    back ( ) const
    { return * ( end ( ) - 1 ); }






    void
    data ( ) { }

    void
    push_back ( bool __x )
    {
      if ( this -> _M_impl . _M_finish . _M_p != this -> _M_impl . _M_end_of_storage )
        * this -> _M_impl . _M_finish ++ = __x;
      else
        _M_insert_aux ( end ( ), __x );
    }

    void



    swap ( vector & __x )

    {
      std :: swap ( this -> _M_impl . _M_start, __x . _M_impl . _M_start );
      std :: swap ( this -> _M_impl . _M_finish, __x . _M_impl . _M_finish );
      std :: swap ( this -> _M_impl . _M_end_of_storage,
  __x . _M_impl . _M_end_of_storage );



      std :: __alloc_swap < typename _Base :: _Bit_alloc_type > ::
 _S_do_it ( _M_get_Bit_allocator ( ), __x . _M_get_Bit_allocator ( ) );
    }


    static void
    swap ( reference __x, reference __y )
    {
      bool __tmp = __x;
      __x = __y;
      __y = __tmp;
    }

    iterator
    insert ( iterator __position, const bool & __x = bool ( ) )
    {
      const difference_type __n = __position - begin ( );
      if ( this -> _M_impl . _M_finish . _M_p != this -> _M_impl . _M_end_of_storage
   && __position == end ( ) )
        * this -> _M_impl . _M_finish ++ = __x;
      else
        _M_insert_aux ( __position, __x );
      return begin ( ) + __n;
    }

    template < typename _InputIterator >
      void
      insert ( iterator __position,
      _InputIterator __first, _InputIterator __last )
      {
 typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
 _M_insert_dispatch ( __position, __first, __last, _Integral ( ) );
      }

    void
    insert ( iterator __position, size_type __n, const bool & __x )
    { _M_fill_insert ( __position, __n, __x ); }






    void
    pop_back ( )
    { -- this -> _M_impl . _M_finish; }

    iterator
    erase ( iterator __position )
    {
      if ( __position + 1 != end ( ) )
        std :: copy ( __position + 1, end ( ), __position );
      -- this -> _M_impl . _M_finish;
      return __position;
    }

    iterator
    erase ( iterator __first, iterator __last )
    {
      _M_erase_at_end ( std :: copy ( __last, end ( ), __first ) );
      return __first;
    }

    void
    resize ( size_type __new_size, bool __x = bool ( ) )
    {
      if ( __new_size < size ( ) )
        _M_erase_at_end ( begin ( ) + difference_type ( __new_size ) );
      else
        insert ( end ( ), __new_size - size ( ), __x );
    }

    void
    flip ( )
    {
      for ( _Bit_type * __p = this -> _M_impl . _M_start . _M_p;
    __p != this -> _M_impl . _M_end_of_storage; ++ __p )
        * __p = ~ * __p;
    }

    void
    clear ( )
    { _M_erase_at_end ( begin ( ) ); }


  protected :

    iterator
    _M_copy_aligned ( const_iterator __first, const_iterator __last,
      iterator __result )
    {
      _Bit_type * __q = std :: copy ( __first . _M_p, __last . _M_p, __result . _M_p );
      return std :: copy ( const_iterator ( __last . _M_p, 0 ), __last,
         iterator ( __q, 0 ) );
    }

    void
    _M_initialize ( size_type __n )
    {
      _Bit_type * __q = this -> _M_allocate ( __n );
      this -> _M_impl . _M_end_of_storage = ( __q
      + ( ( __n + int ( _S_word_bit ) - 1 )
         / int ( _S_word_bit ) ) );
      this -> _M_impl . _M_start = iterator ( __q, 0 );
      this -> _M_impl . _M_finish = this -> _M_impl . _M_start + difference_type ( __n );
    }





    template < typename _Integer >
      void
      _M_initialize_dispatch ( _Integer __n, _Integer __x, __true_type )
      {
 _M_initialize ( static_cast < size_type > ( __n ) );
 std :: fill ( this -> _M_impl . _M_start . _M_p,
    this -> _M_impl . _M_end_of_storage, __x ? ~ 0 : 0 );
      }

    template < typename _InputIterator >
      void
      _M_initialize_dispatch ( _InputIterator __first, _InputIterator __last,
        __false_type )
      { _M_initialize_range ( __first, __last,
       std :: __iterator_category ( __first ) ); }

    template < typename _InputIterator >
      void
      _M_initialize_range ( _InputIterator __first, _InputIterator __last,
     std :: input_iterator_tag )
      {
 for (; __first != __last; ++ __first )
   push_back ( * __first );
      }

    template < typename _ForwardIterator >
      void
      _M_initialize_range ( _ForwardIterator __first, _ForwardIterator __last,
     std :: forward_iterator_tag )
      {
 const size_type __n = std :: distance ( __first, __last );
 _M_initialize ( __n );
 std :: copy ( __first, __last, this -> _M_impl . _M_start );
      }



    template < typename _Integer >
      void
      _M_assign_dispatch ( _Integer __n, _Integer __val, __true_type )
      { _M_fill_assign ( __n, __val ); }

    template < class _InputIterator >
      void
      _M_assign_dispatch ( _InputIterator __first, _InputIterator __last,
    __false_type )
      { _M_assign_aux ( __first, __last, std :: __iterator_category ( __first ) ); }

    void
    _M_fill_assign ( size_t __n, bool __x )
    {
      if ( __n > size ( ) )
 {
   std :: fill ( this -> _M_impl . _M_start . _M_p,
      this -> _M_impl . _M_end_of_storage, __x ? ~ 0 : 0 );
   insert ( end ( ), __n - size ( ), __x );
 }
      else
 {
   _M_erase_at_end ( begin ( ) + __n );
   std :: fill ( this -> _M_impl . _M_start . _M_p,
      this -> _M_impl . _M_end_of_storage, __x ? ~ 0 : 0 );
 }
    }

    template < typename _InputIterator >
      void
      _M_assign_aux ( _InputIterator __first, _InputIterator __last,
      std :: input_iterator_tag )
      {
 iterator __cur = begin ( );
 for (; __first != __last && __cur != end ( ); ++ __cur, ++ __first )
   * __cur = * __first;
 if ( __first == __last )
   _M_erase_at_end ( __cur );
 else
   insert ( end ( ), __first, __last );
      }

    template < typename _ForwardIterator >
      void
      _M_assign_aux ( _ForwardIterator __first, _ForwardIterator __last,
      std :: forward_iterator_tag )
      {
 const size_type __len = std :: distance ( __first, __last );
 if ( __len < size ( ) )
   _M_erase_at_end ( std :: copy ( __first, __last, begin ( ) ) );
 else
   {
     _ForwardIterator __mid = __first;
     std :: advance ( __mid, size ( ) );
     std :: copy ( __first, __mid, begin ( ) );
     insert ( end ( ), __mid, __last );
   }
      }





    template < typename _Integer >
      void
      _M_insert_dispatch ( iterator __pos, _Integer __n, _Integer __x,
    __true_type )
      { _M_fill_insert ( __pos, __n, __x ); }

    template < typename _InputIterator >
      void
      _M_insert_dispatch ( iterator __pos,
    _InputIterator __first, _InputIterator __last,
    __false_type )
      { _M_insert_range ( __pos, __first, __last,
   std :: __iterator_category ( __first ) ); }

    void
    _M_fill_insert ( iterator __position, size_type __n, bool __x );

    template < typename _InputIterator >
      void
      _M_insert_range ( iterator __pos, _InputIterator __first,
        _InputIterator __last, std :: input_iterator_tag )
      {
 for (; __first != __last; ++ __first )
   {
     __pos = insert ( __pos, * __first );
     ++ __pos;
   }
      }

    template < typename _ForwardIterator >
      void
      _M_insert_range ( iterator __position, _ForwardIterator __first,
        _ForwardIterator __last, std :: forward_iterator_tag );

    void
    _M_insert_aux ( iterator __position, bool __x );

    size_type
    _M_check_len ( size_type __n, const char * __s ) const
    {
      if ( max_size ( ) - size ( ) < __n )
 __throw_length_error ( ( __s ) );

      const size_type __len = size ( ) + std :: max ( size ( ), __n );
      return ( __len < size ( ) || __len > max_size ( ) ) ? max_size ( ) : __len;
    }

    void
    _M_erase_at_end ( iterator __pos )
    { this -> _M_impl . _M_finish = __pos; }
  };

}
# 60 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/vector.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _Tp, typename _Alloc >
    void
    vector < _Tp, _Alloc > ::
    reserve ( size_type __n )
    {
      if ( __n > this -> max_size ( ) )
 __throw_length_error ( ( "vector::reserve" ) );
      if ( this -> capacity ( ) < __n )
 {
   const size_type __old_size = size ( );
   pointer __tmp = _M_allocate_and_copy ( __n,
   ( this -> _M_impl . _M_start ),
   ( this -> _M_impl . _M_finish ) );
   std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
   _M_get_Tp_allocator ( ) );
   _M_deallocate ( this -> _M_impl . _M_start,
   this -> _M_impl . _M_end_of_storage
   - this -> _M_impl . _M_start );
   this -> _M_impl . _M_start = __tmp;
   this -> _M_impl . _M_finish = __tmp + __old_size;
   this -> _M_impl . _M_end_of_storage = this -> _M_impl . _M_start + __n;
 }
    }
# 104
template < typename _Tp, typename _Alloc >
    typename vector < _Tp, _Alloc > :: iterator
    vector < _Tp, _Alloc > ::
    insert ( iterator __position, const value_type & __x )
    {
      const size_type __n = __position - begin ( );
      if ( this -> _M_impl . _M_finish != this -> _M_impl . _M_end_of_storage
   && __position == end ( ) )
 {
   this -> _M_impl . construct ( this -> _M_impl . _M_finish, __x );
   ++ this -> _M_impl . _M_finish;
 }
      else
 {








     _M_insert_aux ( __position, __x );
 }
      return iterator ( this -> _M_impl . _M_start + __n );
    }

template < typename _Tp, typename _Alloc >
    typename vector < _Tp, _Alloc > :: iterator
    vector < _Tp, _Alloc > ::
    erase ( iterator __position )
    {
      if ( __position + 1 != end ( ) )
 std :: copy ( __position + 1, end ( ), __position );
      -- this -> _M_impl . _M_finish;
      this -> _M_impl . destroy ( this -> _M_impl . _M_finish );
      return __position;
    }

template < typename _Tp, typename _Alloc >
    typename vector < _Tp, _Alloc > :: iterator
    vector < _Tp, _Alloc > ::
    erase ( iterator __first, iterator __last )
    {
      if ( __last != end ( ) )
 std :: copy ( __last, end ( ), __first );
      _M_erase_at_end ( __first . base ( ) + ( end ( ) - __last ) );
      return __first;
    }

template < typename _Tp, typename _Alloc >
    vector < _Tp, _Alloc > &
    vector < _Tp, _Alloc > ::
    operator = ( const vector < _Tp, _Alloc > & __x )
    {
      if ( & __x != this )
 {
   const size_type __xlen = __x . size ( );
   if ( __xlen > capacity ( ) )
     {
       pointer __tmp = _M_allocate_and_copy ( __xlen, __x . begin ( ),
         __x . end ( ) );
       std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
       _M_get_Tp_allocator ( ) );
       _M_deallocate ( this -> _M_impl . _M_start,
       this -> _M_impl . _M_end_of_storage
       - this -> _M_impl . _M_start );
       this -> _M_impl . _M_start = __tmp;
       this -> _M_impl . _M_end_of_storage = this -> _M_impl . _M_start + __xlen;
     }
   else if ( size ( ) >= __xlen )
     {
       std :: _Destroy ( std :: copy ( __x . begin ( ), __x . end ( ), begin ( ) ),
       end ( ), _M_get_Tp_allocator ( ) );
     }
   else
     {
       std :: copy ( __x . _M_impl . _M_start, __x . _M_impl . _M_start + size ( ),
   this -> _M_impl . _M_start );
       std :: __uninitialized_copy_a ( __x . _M_impl . _M_start + size ( ),
       __x . _M_impl . _M_finish,
       this -> _M_impl . _M_finish,
       _M_get_Tp_allocator ( ) );
     }
   this -> _M_impl . _M_finish = this -> _M_impl . _M_start + __xlen;
 }
      return * this;
    }

template < typename _Tp, typename _Alloc >
    void
    vector < _Tp, _Alloc > ::
    _M_fill_assign ( size_t __n, const value_type & __val )
    {
      if ( __n > capacity ( ) )
 {
   vector __tmp ( __n, __val, _M_get_Tp_allocator ( ) );
   __tmp . swap ( * this );
 }
      else if ( __n > size ( ) )
 {
   std :: fill ( begin ( ), end ( ), __val );
   std :: __uninitialized_fill_n_a ( this -> _M_impl . _M_finish,
     __n - size ( ), __val,
     _M_get_Tp_allocator ( ) );
   this -> _M_impl . _M_finish += __n - size ( );
 }
      else
        _M_erase_at_end ( std :: fill_n ( this -> _M_impl . _M_start, __n, __val ) );
    }

template < typename _Tp, typename _Alloc >
    template < typename _InputIterator >
      void
      vector < _Tp, _Alloc > ::
      _M_assign_aux ( _InputIterator __first, _InputIterator __last,
      std :: input_iterator_tag )
      {
 pointer __cur ( this -> _M_impl . _M_start );
 for (; __first != __last && __cur != this -> _M_impl . _M_finish;
      ++ __cur, ++ __first )
   * __cur = * __first;
 if ( __first == __last )
   _M_erase_at_end ( __cur );
 else
   insert ( end ( ), __first, __last );
      }

template < typename _Tp, typename _Alloc >
    template < typename _ForwardIterator >
      void
      vector < _Tp, _Alloc > ::
      _M_assign_aux ( _ForwardIterator __first, _ForwardIterator __last,
      std :: forward_iterator_tag )
      {
 const size_type __len = std :: distance ( __first, __last );

 if ( __len > capacity ( ) )
   {
     pointer __tmp ( _M_allocate_and_copy ( __len, __first, __last ) );
     std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
     _M_get_Tp_allocator ( ) );
     _M_deallocate ( this -> _M_impl . _M_start,
     this -> _M_impl . _M_end_of_storage
     - this -> _M_impl . _M_start );
     this -> _M_impl . _M_start = __tmp;
     this -> _M_impl . _M_finish = this -> _M_impl . _M_start + __len;
     this -> _M_impl . _M_end_of_storage = this -> _M_impl . _M_finish;
   }
 else if ( size ( ) >= __len )
   _M_erase_at_end ( std :: copy ( __first, __last, this -> _M_impl . _M_start ) );
 else
   {
     _ForwardIterator __mid = __first;
     std :: advance ( __mid, size ( ) );
     std :: copy ( __first, __mid, this -> _M_impl . _M_start );
     this -> _M_impl . _M_finish =
       std :: __uninitialized_copy_a ( __mid, __last,
       this -> _M_impl . _M_finish,
       _M_get_Tp_allocator ( ) );
   }
      }
# 293
template < typename _Tp, typename _Alloc >
    void
    vector < _Tp, _Alloc > ::
    _M_insert_aux ( iterator __position, const _Tp & __x )

    {
      if ( this -> _M_impl . _M_finish != this -> _M_impl . _M_end_of_storage )
 {
   this -> _M_impl . construct ( this -> _M_impl . _M_finish,
      ( * ( this -> _M_impl . _M_finish - 1 ) )
             );
   ++ this -> _M_impl . _M_finish;

   _Tp __x_copy = __x;

   std :: copy_backward ( __position . base ( ), this -> _M_impl . _M_finish - 2, this -> _M_impl . _M_finish - 1 )

                                  ;

   * __position = __x_copy;



 }
      else
 {
   const size_type __len =
     _M_check_len ( size_type ( 1 ), "vector::_M_insert_aux" );
   const size_type __elems_before = __position - begin ( );
   pointer __new_start ( this -> _M_allocate ( __len ) );
   pointer __new_finish ( __new_start );
   try
     {




       this -> _M_impl . construct ( __new_start + __elems_before,



                               __x );

       __new_finish = 0;

       __new_finish =
  std :: __uninitialized_move_a ( this -> _M_impl . _M_start,
         __position . base ( ), __new_start,
         _M_get_Tp_allocator ( ) );
       ++ __new_finish;

       __new_finish =
  std :: __uninitialized_move_a ( __position . base ( ),
         this -> _M_impl . _M_finish,
         __new_finish,
         _M_get_Tp_allocator ( ) );
     }
          catch ( ... )
     {
       if ( ! __new_finish )
  this -> _M_impl . destroy ( __new_start + __elems_before );
       else
  std :: _Destroy ( __new_start, __new_finish, _M_get_Tp_allocator ( ) );
       _M_deallocate ( __new_start, __len );
       throw;
     }
   std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
   _M_get_Tp_allocator ( ) );
   _M_deallocate ( this -> _M_impl . _M_start,
   this -> _M_impl . _M_end_of_storage
   - this -> _M_impl . _M_start );
   this -> _M_impl . _M_start = __new_start;
   this -> _M_impl . _M_finish = __new_finish;
   this -> _M_impl . _M_end_of_storage = __new_start + __len;
 }
    }

template < typename _Tp, typename _Alloc >
    void
    vector < _Tp, _Alloc > ::
    _M_fill_insert ( iterator __position, size_type __n, const value_type & __x )
    {
      if ( __n != 0 )
 {
   if ( size_type ( this -> _M_impl . _M_end_of_storage
   - this -> _M_impl . _M_finish ) >= __n )
     {
       value_type __x_copy = __x;
       const size_type __elems_after = end ( ) - __position;
       pointer __old_finish ( this -> _M_impl . _M_finish );
       if ( __elems_after > __n )
  {
    std :: __uninitialized_move_a ( this -> _M_impl . _M_finish - __n,
           this -> _M_impl . _M_finish,
           this -> _M_impl . _M_finish,
           _M_get_Tp_allocator ( ) );
    this -> _M_impl . _M_finish += __n;
    std :: copy_backward ( __position . base ( ), __old_finish - __n, __old_finish )
                                        ;
    std :: fill ( __position . base ( ), __position . base ( ) + __n,
       __x_copy );
  }
       else
  {
    std :: __uninitialized_fill_n_a ( this -> _M_impl . _M_finish,
      __n - __elems_after,
      __x_copy,
      _M_get_Tp_allocator ( ) );
    this -> _M_impl . _M_finish += __n - __elems_after;
    std :: __uninitialized_move_a ( __position . base ( ), __old_finish,
           this -> _M_impl . _M_finish,
           _M_get_Tp_allocator ( ) );
    this -> _M_impl . _M_finish += __elems_after;
    std :: fill ( __position . base ( ), __old_finish, __x_copy );
  }
     }
   else
     {
       const size_type __len =
  _M_check_len ( __n, "vector::_M_fill_insert" );
       const size_type __elems_before = __position - begin ( );
       pointer __new_start ( this -> _M_allocate ( __len ) );
       pointer __new_finish ( __new_start );
       try
  {

    std :: __uninitialized_fill_n_a ( __new_start + __elems_before,
      __n, __x,
      _M_get_Tp_allocator ( ) );
    __new_finish = 0;

    __new_finish =
      std :: __uninitialized_move_a ( this -> _M_impl . _M_start,
      __position . base ( ),
      __new_start,
      _M_get_Tp_allocator ( ) );
    __new_finish += __n;

    __new_finish =
      std :: __uninitialized_move_a ( __position . base ( ),
      this -> _M_impl . _M_finish,
      __new_finish,
      _M_get_Tp_allocator ( ) );
  }
       catch ( ... )
  {
    if ( ! __new_finish )
      std :: _Destroy ( __new_start + __elems_before,
      __new_start + __elems_before + __n,
      _M_get_Tp_allocator ( ) );
    else
      std :: _Destroy ( __new_start, __new_finish,
      _M_get_Tp_allocator ( ) );
    _M_deallocate ( __new_start, __len );
    throw;
  }
       std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
       _M_get_Tp_allocator ( ) );
       _M_deallocate ( this -> _M_impl . _M_start,
       this -> _M_impl . _M_end_of_storage
       - this -> _M_impl . _M_start );
       this -> _M_impl . _M_start = __new_start;
       this -> _M_impl . _M_finish = __new_finish;
       this -> _M_impl . _M_end_of_storage = __new_start + __len;
     }
 }
    }

template < typename _Tp, typename _Alloc >
    template < typename _InputIterator >
      void
      vector < _Tp, _Alloc > ::
      _M_range_insert ( iterator __pos, _InputIterator __first,
        _InputIterator __last, std :: input_iterator_tag )
      {
 for (; __first != __last; ++ __first )
   {
     __pos = insert ( __pos, * __first );
     ++ __pos;
   }
      }

template < typename _Tp, typename _Alloc >
    template < typename _ForwardIterator >
      void
      vector < _Tp, _Alloc > ::
      _M_range_insert ( iterator __position, _ForwardIterator __first,
        _ForwardIterator __last, std :: forward_iterator_tag )
      {
 if ( __first != __last )
   {
     const size_type __n = std :: distance ( __first, __last );
     if ( size_type ( this -> _M_impl . _M_end_of_storage
     - this -> _M_impl . _M_finish ) >= __n )
       {
  const size_type __elems_after = end ( ) - __position;
  pointer __old_finish ( this -> _M_impl . _M_finish );
  if ( __elems_after > __n )
    {
      std :: __uninitialized_move_a ( this -> _M_impl . _M_finish - __n,
      this -> _M_impl . _M_finish,
      this -> _M_impl . _M_finish,
      _M_get_Tp_allocator ( ) );
      this -> _M_impl . _M_finish += __n;
      std :: copy_backward ( __position . base ( ), __old_finish - __n, __old_finish )
                                          ;
      std :: copy ( __first, __last, __position );
    }
  else
    {
      _ForwardIterator __mid = __first;
      std :: advance ( __mid, __elems_after );
      std :: __uninitialized_copy_a ( __mid, __last,
      this -> _M_impl . _M_finish,
      _M_get_Tp_allocator ( ) );
      this -> _M_impl . _M_finish += __n - __elems_after;
      std :: __uninitialized_move_a ( __position . base ( ),
      __old_finish,
      this -> _M_impl . _M_finish,
      _M_get_Tp_allocator ( ) );
      this -> _M_impl . _M_finish += __elems_after;
      std :: copy ( __first, __mid, __position );
    }
       }
     else
       {
  const size_type __len =
    _M_check_len ( __n, "vector::_M_range_insert" );
  pointer __new_start ( this -> _M_allocate ( __len ) );
  pointer __new_finish ( __new_start );
  try
    {
      __new_finish =
        std :: __uninitialized_move_a ( this -> _M_impl . _M_start,
        __position . base ( ),
        __new_start,
        _M_get_Tp_allocator ( ) );
      __new_finish =
        std :: __uninitialized_copy_a ( __first, __last,
        __new_finish,
        _M_get_Tp_allocator ( ) );
      __new_finish =
        std :: __uninitialized_move_a ( __position . base ( ),
        this -> _M_impl . _M_finish,
        __new_finish,
        _M_get_Tp_allocator ( ) );
    }
  catch ( ... )
    {
      std :: _Destroy ( __new_start, __new_finish,
      _M_get_Tp_allocator ( ) );
      _M_deallocate ( __new_start, __len );
      throw;
    }
  std :: _Destroy ( this -> _M_impl . _M_start, this -> _M_impl . _M_finish,
         _M_get_Tp_allocator ( ) );
  _M_deallocate ( this -> _M_impl . _M_start,
         this -> _M_impl . _M_end_of_storage
         - this -> _M_impl . _M_start );
  this -> _M_impl . _M_start = __new_start;
  this -> _M_impl . _M_finish = __new_finish;
  this -> _M_impl . _M_end_of_storage = __new_start + __len;
       }
   }
      }




template < typename _Alloc >
    void
    vector < bool, _Alloc > ::
    reserve ( size_type __n )
    {
      if ( __n > this -> max_size ( ) )
 __throw_length_error ( ( "vector::reserve" ) );
      if ( this -> capacity ( ) < __n )
 {
   _Bit_type * __q = this -> _M_allocate ( __n );
   this -> _M_impl . _M_finish = _M_copy_aligned ( begin ( ), end ( ),
          iterator ( __q, 0 ) );
   this -> _M_deallocate ( );
   this -> _M_impl . _M_start = iterator ( __q, 0 );
   this -> _M_impl . _M_end_of_storage = ( __q + ( __n + int ( _S_word_bit ) - 1 )
          / int ( _S_word_bit ) );
 }
    }

template < typename _Alloc >
    void
    vector < bool, _Alloc > ::
    _M_fill_insert ( iterator __position, size_type __n, bool __x )
    {
      if ( __n == 0 )
 return;
      if ( capacity ( ) - size ( ) >= __n )
 {
   std :: copy_backward ( __position, end ( ),
        this -> _M_impl . _M_finish + difference_type ( __n ) );
   std :: fill ( __position, __position + difference_type ( __n ), __x );
   this -> _M_impl . _M_finish += difference_type ( __n );
 }
      else
 {
   const size_type __len =
     _M_check_len ( __n, "vector<bool>::_M_fill_insert" );
   _Bit_type * __q = this -> _M_allocate ( __len );
   iterator __i = _M_copy_aligned ( begin ( ), __position,
      iterator ( __q, 0 ) );
   std :: fill ( __i, __i + difference_type ( __n ), __x );
   this -> _M_impl . _M_finish = std :: copy ( __position, end ( ),
           __i + difference_type ( __n ) );
   this -> _M_deallocate ( );
   this -> _M_impl . _M_end_of_storage = ( __q + ( ( __len
           + int ( _S_word_bit ) - 1 )
          / int ( _S_word_bit ) ) );
   this -> _M_impl . _M_start = iterator ( __q, 0 );
 }
    }

template < typename _Alloc >
    template < typename _ForwardIterator >
      void
      vector < bool, _Alloc > ::
      _M_insert_range ( iterator __position, _ForwardIterator __first,
        _ForwardIterator __last, std :: forward_iterator_tag )
      {
 if ( __first != __last )
   {
     size_type __n = std :: distance ( __first, __last );
     if ( capacity ( ) - size ( ) >= __n )
       {
  std :: copy_backward ( __position, end ( ),
       this -> _M_impl . _M_finish
       + difference_type ( __n ) );
  std :: copy ( __first, __last, __position );
  this -> _M_impl . _M_finish += difference_type ( __n );
       }
     else
       {
  const size_type __len =
    _M_check_len ( __n, "vector<bool>::_M_insert_range" );
  _Bit_type * __q = this -> _M_allocate ( __len );
  iterator __i = _M_copy_aligned ( begin ( ), __position,
            iterator ( __q, 0 ) );
  __i = std :: copy ( __first, __last, __i );
  this -> _M_impl . _M_finish = std :: copy ( __position, end ( ), __i );
  this -> _M_deallocate ( );
  this -> _M_impl . _M_end_of_storage = ( __q
         + ( ( __len
             + int ( _S_word_bit ) - 1 )
            / int ( _S_word_bit ) ) );
  this -> _M_impl . _M_start = iterator ( __q, 0 );
       }
   }
      }

template < typename _Alloc >
    void
    vector < bool, _Alloc > ::
    _M_insert_aux ( iterator __position, bool __x )
    {
      if ( this -> _M_impl . _M_finish . _M_p != this -> _M_impl . _M_end_of_storage )
 {
   std :: copy_backward ( __position, this -> _M_impl . _M_finish,
        this -> _M_impl . _M_finish + 1 );
   * __position = __x;
   ++ this -> _M_impl . _M_finish;
 }
      else
 {
   const size_type __len =
     _M_check_len ( size_type ( 1 ), "vector<bool>::_M_insert_aux" );
   _Bit_type * __q = this -> _M_allocate ( __len );
   iterator __i = _M_copy_aligned ( begin ( ), __position,
      iterator ( __q, 0 ) );
   * __i ++ = __x;
   this -> _M_impl . _M_finish = std :: copy ( __position, end ( ), __i );
   this -> _M_deallocate ( );
   this -> _M_impl . _M_end_of_storage = ( __q + ( ( __len
           + int ( _S_word_bit ) - 1 )
          / int ( _S_word_bit ) ) );
   this -> _M_impl . _M_start = iterator ( __q, 0 );
 }
    }

}
# 60 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_function.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 99
template < typename _Arg, typename _Result >
    struct unary_function
    {
      typedef _Arg argument_type;


      typedef _Result result_type;
    };




template < typename _Arg1, typename _Arg2, typename _Result >
    struct binary_function
    {
      typedef _Arg1 first_argument_type;


      typedef _Arg2 second_argument_type;
      typedef _Result result_type;
    };
# 134
template < typename _Tp >
    struct plus : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x + __y; }
    };


template < typename _Tp >
    struct minus : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x - __y; }
    };


template < typename _Tp >
    struct multiplies : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x * __y; }
    };


template < typename _Tp >
    struct divides : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x / __y; }
    };


template < typename _Tp >
    struct modulus : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x % __y; }
    };


template < typename _Tp >
    struct negate : public unary_function < _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x ) const
      { return - __x; }
    };
# 198
template < typename _Tp >
    struct equal_to : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x == __y; }
    };


template < typename _Tp >
    struct not_equal_to : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x != __y; }
    };


template < typename _Tp >
    struct greater : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x > __y; }
    };


template < typename _Tp >
    struct less : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x < __y; }
    };


template < typename _Tp >
    struct greater_equal : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x >= __y; }
    };


template < typename _Tp >
    struct less_equal : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x <= __y; }
    };
# 262
template < typename _Tp >
    struct logical_and : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x && __y; }
    };


template < typename _Tp >
    struct logical_or : public binary_function < _Tp, _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x || __y; }
    };


template < typename _Tp >
    struct logical_not : public unary_function < _Tp, bool >
    {
      bool
      operator ( ) ( const _Tp & __x ) const
      { return ! __x; }
    };




template < typename _Tp >
    struct bit_and : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x & __y; }
    };

template < typename _Tp >
    struct bit_or : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x | __y; }
    };

template < typename _Tp >
    struct bit_xor : public binary_function < _Tp, _Tp, _Tp >
    {
      _Tp
      operator ( ) ( const _Tp & __x, const _Tp & __y ) const
      { return __x ^ __y; }
    };
# 345
template < typename _Predicate >
    class unary_negate
    : public unary_function < typename _Predicate :: argument_type, bool >
    {
    protected :
      _Predicate _M_pred;

    public :
      explicit
      unary_negate ( const _Predicate & __x ) : _M_pred ( __x ) { }

      bool
      operator ( ) ( const typename _Predicate :: argument_type & __x ) const
      { return ! _M_pred ( __x ); }
    };


template < typename _Predicate >
    inline unary_negate < _Predicate >
    not1 ( const _Predicate & __pred )
    { return unary_negate < _Predicate > ( __pred ); }


template < typename _Predicate >
    class binary_negate
    : public binary_function < typename _Predicate :: first_argument_type,
        typename _Predicate :: second_argument_type, bool >
    {
    protected :
      _Predicate _M_pred;

    public :
      explicit
      binary_negate ( const _Predicate & __x ) : _M_pred ( __x ) { }

      bool
      operator ( ) ( const typename _Predicate :: first_argument_type & __x,
   const typename _Predicate :: second_argument_type & __y ) const
      { return ! _M_pred ( __x, __y ); }
    };


template < typename _Predicate >
    inline binary_negate < _Predicate >
    not2 ( const _Predicate & __pred )
    { return binary_negate < _Predicate > ( __pred ); }
# 416
template < typename _Arg, typename _Result >
    class pointer_to_unary_function : public unary_function < _Arg, _Result >
    {
    protected :
      _Result ( * _M_ptr ) ( _Arg );

    public :
      pointer_to_unary_function ( ) { }

      explicit
      pointer_to_unary_function ( _Result ( * __x ) ( _Arg ) )
      : _M_ptr ( __x ) { }

      _Result
      operator ( ) ( _Arg __x ) const
      { return _M_ptr ( __x ); }
    };


template < typename _Arg, typename _Result >
    inline pointer_to_unary_function < _Arg, _Result >
    ptr_fun ( _Result ( * __x ) ( _Arg ) )
    { return pointer_to_unary_function < _Arg, _Result > ( __x ); }


template < typename _Arg1, typename _Arg2, typename _Result >
    class pointer_to_binary_function
    : public binary_function < _Arg1, _Arg2, _Result >
    {
    protected :
      _Result ( * _M_ptr ) ( _Arg1, _Arg2 );

    public :
      pointer_to_binary_function ( ) { }

      explicit
      pointer_to_binary_function ( _Result ( * __x ) ( _Arg1, _Arg2 ) )
      : _M_ptr ( __x ) { }

      _Result
      operator ( ) ( _Arg1 __x, _Arg2 __y ) const
      { return _M_ptr ( __x, __y ); }
    };


template < typename _Arg1, typename _Arg2, typename _Result >
    inline pointer_to_binary_function < _Arg1, _Arg2, _Result >
    ptr_fun ( _Result ( * __x ) ( _Arg1, _Arg2 ) )
    { return pointer_to_binary_function < _Arg1, _Arg2, _Result > ( __x ); }


template < typename _Tp >
    struct _Identity : public unary_function < _Tp, _Tp >
    {
      _Tp &
      operator ( ) ( _Tp & __x ) const
      { return __x; }

      const _Tp &
      operator ( ) ( const _Tp & __x ) const
      { return __x; }
    };

template < typename _Pair >
    struct _Select1st : public unary_function < _Pair,
           typename _Pair :: first_type >
    {
      typename _Pair :: first_type &
      operator ( ) ( _Pair & __x ) const
      { return __x . first; }

      const typename _Pair :: first_type &
      operator ( ) ( const _Pair & __x ) const
      { return __x . first; }
    };

template < typename _Pair >
    struct _Select2nd : public unary_function < _Pair,
           typename _Pair :: second_type >
    {
      typename _Pair :: second_type &
      operator ( ) ( _Pair & __x ) const
      { return __x . second; }

      const typename _Pair :: second_type &
      operator ( ) ( const _Pair & __x ) const
      { return __x . second; }
    };
# 523
template < typename _Ret, typename _Tp >
    class mem_fun_t : public unary_function < _Tp *, _Ret >
    {
    public :
      explicit
      mem_fun_t ( _Ret ( _Tp :: * __pf ) ( ) )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( _Tp * __p ) const
      { return ( __p ->* _M_f ) ( ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( );
    };



template < typename _Ret, typename _Tp >
    class const_mem_fun_t : public unary_function < const _Tp *, _Ret >
    {
    public :
      explicit
      const_mem_fun_t ( _Ret ( _Tp :: * __pf ) ( ) const )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( const _Tp * __p ) const
      { return ( __p ->* _M_f ) ( ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( ) const;
    };



template < typename _Ret, typename _Tp >
    class mem_fun_ref_t : public unary_function < _Tp, _Ret >
    {
    public :
      explicit
      mem_fun_ref_t ( _Ret ( _Tp :: * __pf ) ( ) )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( _Tp & __r ) const
      { return ( __r .* _M_f ) ( ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( );
  };



template < typename _Ret, typename _Tp >
    class const_mem_fun_ref_t : public unary_function < _Tp, _Ret >
    {
    public :
      explicit
      const_mem_fun_ref_t ( _Ret ( _Tp :: * __pf ) ( ) const )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( const _Tp & __r ) const
      { return ( __r .* _M_f ) ( ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( ) const;
    };



template < typename _Ret, typename _Tp, typename _Arg >
    class mem_fun1_t : public binary_function < _Tp *, _Arg, _Ret >
    {
    public :
      explicit
      mem_fun1_t ( _Ret ( _Tp :: * __pf ) ( _Arg ) )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( _Tp * __p, _Arg __x ) const
      { return ( __p ->* _M_f ) ( __x ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( _Arg );
    };



template < typename _Ret, typename _Tp, typename _Arg >
    class const_mem_fun1_t : public binary_function < const _Tp *, _Arg, _Ret >
    {
    public :
      explicit
      const_mem_fun1_t ( _Ret ( _Tp :: * __pf ) ( _Arg ) const )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( const _Tp * __p, _Arg __x ) const
      { return ( __p ->* _M_f ) ( __x ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( _Arg ) const;
    };



template < typename _Ret, typename _Tp, typename _Arg >
    class mem_fun1_ref_t : public binary_function < _Tp, _Arg, _Ret >
    {
    public :
      explicit
      mem_fun1_ref_t ( _Ret ( _Tp :: * __pf ) ( _Arg ) )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( _Tp & __r, _Arg __x ) const
      { return ( __r .* _M_f ) ( __x ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( _Arg );
    };



template < typename _Ret, typename _Tp, typename _Arg >
    class const_mem_fun1_ref_t : public binary_function < _Tp, _Arg, _Ret >
    {
    public :
      explicit
      const_mem_fun1_ref_t ( _Ret ( _Tp :: * __pf ) ( _Arg ) const )
      : _M_f ( __pf ) { }

      _Ret
      operator ( ) ( const _Tp & __r, _Arg __x ) const
      { return ( __r .* _M_f ) ( __x ); }

    private :
      _Ret ( _Tp :: * _M_f ) ( _Arg ) const;
    };



template < typename _Ret, typename _Tp >
    inline mem_fun_t < _Ret, _Tp >
    mem_fun ( _Ret ( _Tp :: * __f ) ( ) )
    { return mem_fun_t < _Ret, _Tp > ( __f ); }

template < typename _Ret, typename _Tp >
    inline const_mem_fun_t < _Ret, _Tp >
    mem_fun ( _Ret ( _Tp :: * __f ) ( ) const )
    { return const_mem_fun_t < _Ret, _Tp > ( __f ); }

template < typename _Ret, typename _Tp >
    inline mem_fun_ref_t < _Ret, _Tp >
    mem_fun_ref ( _Ret ( _Tp :: * __f ) ( ) )
    { return mem_fun_ref_t < _Ret, _Tp > ( __f ); }

template < typename _Ret, typename _Tp >
    inline const_mem_fun_ref_t < _Ret, _Tp >
    mem_fun_ref ( _Ret ( _Tp :: * __f ) ( ) const )
    { return const_mem_fun_ref_t < _Ret, _Tp > ( __f ); }

template < typename _Ret, typename _Tp, typename _Arg >
    inline mem_fun1_t < _Ret, _Tp, _Arg >
    mem_fun ( _Ret ( _Tp :: * __f ) ( _Arg ) )
    { return mem_fun1_t < _Ret, _Tp, _Arg > ( __f ); }

template < typename _Ret, typename _Tp, typename _Arg >
    inline const_mem_fun1_t < _Ret, _Tp, _Arg >
    mem_fun ( _Ret ( _Tp :: * __f ) ( _Arg ) const )
    { return const_mem_fun1_t < _Ret, _Tp, _Arg > ( __f ); }

template < typename _Ret, typename _Tp, typename _Arg >
    inline mem_fun1_ref_t < _Ret, _Tp, _Arg >
    mem_fun_ref ( _Ret ( _Tp :: * __f ) ( _Arg ) )
    { return mem_fun1_ref_t < _Ret, _Tp, _Arg > ( __f ); }

template < typename _Ret, typename _Tp, typename _Arg >
    inline const_mem_fun1_ref_t < _Ret, _Tp, _Arg >
    mem_fun_ref ( _Ret ( _Tp :: * __f ) ( _Arg ) const )
    { return const_mem_fun1_ref_t < _Ret, _Tp, _Arg > ( __f ); }



}
# 60 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/backward/binders.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 96
template < typename _Operation >
    class binder1st
    : public unary_function < typename _Operation :: second_argument_type,
       typename _Operation :: result_type >
    {
    protected :
      _Operation op;
      typename _Operation :: first_argument_type value;

    public :
      binder1st ( const _Operation & __x,
  const typename _Operation :: first_argument_type & __y )
      : op ( __x ), value ( __y ) { }

      typename _Operation :: result_type
      operator ( ) ( const typename _Operation :: second_argument_type & __x ) const
      { return op ( value, __x ); }



      typename _Operation :: result_type
      operator ( ) ( typename _Operation :: second_argument_type & __x ) const
      { return op ( value, __x ); }
    };


template < typename _Operation, typename _Tp >
    inline binder1st < _Operation >
    bind1st ( const _Operation & __fn, const _Tp & __x )
    {
      typedef typename _Operation :: first_argument_type _Arg1_type;
      return binder1st < _Operation > ( __fn, _Arg1_type ( __x ) );
    }


template < typename _Operation >
    class binder2nd
    : public unary_function < typename _Operation :: first_argument_type,
       typename _Operation :: result_type >
    {
    protected :
      _Operation op;
      typename _Operation :: second_argument_type value;

    public :
      binder2nd ( const _Operation & __x,
  const typename _Operation :: second_argument_type & __y )
      : op ( __x ), value ( __y ) { }

      typename _Operation :: result_type
      operator ( ) ( const typename _Operation :: first_argument_type & __x ) const
      { return op ( __x, value ); }



      typename _Operation :: result_type
      operator ( ) ( typename _Operation :: first_argument_type & __x ) const
      { return op ( __x, value ); }
    };


template < typename _Operation, typename _Tp >
    inline binder2nd < _Operation >
    bind2nd ( const _Operation & __fn, const _Tp & __x )
    {
      typedef typename _Operation :: second_argument_type _Arg2_type;
      return binder2nd < _Operation > ( __fn, _Arg2_type ( __x ) );
    }


}
# 67 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_tree.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 85
enum _Rb_tree_color { _S_red, _S_black}; 

struct _Rb_tree_node_base { 

typedef _Rb_tree_node_base *_Base_ptr; 
typedef const _Rb_tree_node_base *_Const_Base_ptr; 

_Rb_tree_color _M_color; 
_Base_ptr _M_parent; 
_Base_ptr _M_left; 
_Base_ptr _M_right; 


static _Base_ptr _S_minimum(_Base_ptr __x) 
{ 
while (__x->_M_left != (0)) { __x = __x->_M_left; }  
return __x; 
} 


static _Const_Base_ptr _S_minimum(_Const_Base_ptr __x) 
{ 
while (__x->_M_left != (0)) { __x = __x->_M_left; }  
return __x; 
} 


static _Base_ptr _S_maximum(_Base_ptr __x) 
{ 
while (__x->_M_right != (0)) { __x = __x->_M_right; }  
return __x; 
} 


static _Const_Base_ptr _S_maximum(_Const_Base_ptr __x) 
{ 
while (__x->_M_right != (0)) { __x = __x->_M_right; }  
return __x; 
} 
}; 

template < typename _Val >
    struct _Rb_tree_node : public _Rb_tree_node_base
    {
      typedef _Rb_tree_node < _Val > * _Link_type;
      _Val _M_value_field;







    };


_Rb_tree_node_base *_Rb_tree_increment(_Rb_tree_node_base * __x); 


const _Rb_tree_node_base *_Rb_tree_increment(const _Rb_tree_node_base * __x); 


_Rb_tree_node_base *_Rb_tree_decrement(_Rb_tree_node_base * __x); 


const _Rb_tree_node_base *_Rb_tree_decrement(const _Rb_tree_node_base * __x); 

template < typename _Tp >
    struct _Rb_tree_iterator
    {
      typedef _Tp value_type;
      typedef _Tp & reference;
      typedef _Tp * pointer;

      typedef bidirectional_iterator_tag iterator_category;
      typedef ptrdiff_t difference_type;

      typedef _Rb_tree_iterator < _Tp > _Self;
      typedef _Rb_tree_node_base :: _Base_ptr _Base_ptr;
      typedef _Rb_tree_node < _Tp > * _Link_type;

      _Rb_tree_iterator ( )
      : _M_node ( ) { }

      explicit
      _Rb_tree_iterator ( _Link_type __x )
      : _M_node ( __x ) { }

      reference
      operator * ( ) const
      { return static_cast < _Link_type > ( _M_node ) -> _M_value_field; }

      pointer
      operator -> ( ) const
      { return & static_cast < _Link_type > ( _M_node ) -> _M_value_field; }

      _Self &
      operator ++ ( )
      {
 _M_node = _Rb_tree_increment ( _M_node );
 return * this;
      }

      _Self
      operator ++ ( int )
      {
 _Self __tmp = * this;
 _M_node = _Rb_tree_increment ( _M_node );
 return __tmp;
      }

      _Self &
      operator -- ( )
      {
 _M_node = _Rb_tree_decrement ( _M_node );
 return * this;
      }

      _Self
      operator -- ( int )
      {
 _Self __tmp = * this;
 _M_node = _Rb_tree_decrement ( _M_node );
 return __tmp;
      }

      bool
      operator == ( const _Self & __x ) const
      { return _M_node == __x . _M_node; }

      bool
      operator != ( const _Self & __x ) const
      { return _M_node != __x . _M_node; }

      _Base_ptr _M_node;
  };

template < typename _Tp >
    struct _Rb_tree_const_iterator
    {
      typedef _Tp value_type;
      typedef const _Tp & reference;
      typedef const _Tp * pointer;

      typedef _Rb_tree_iterator < _Tp > iterator;

      typedef bidirectional_iterator_tag iterator_category;
      typedef ptrdiff_t difference_type;

      typedef _Rb_tree_const_iterator < _Tp > _Self;
      typedef _Rb_tree_node_base :: _Const_Base_ptr _Base_ptr;
      typedef const _Rb_tree_node < _Tp > * _Link_type;

      _Rb_tree_const_iterator ( )
      : _M_node ( ) { }

      explicit
      _Rb_tree_const_iterator ( _Link_type __x )
      : _M_node ( __x ) { }

      _Rb_tree_const_iterator ( const iterator & __it )
      : _M_node ( __it . _M_node ) { }

      reference
      operator * ( ) const
      { return static_cast < _Link_type > ( _M_node ) -> _M_value_field; }

      pointer
      operator -> ( ) const
      { return & static_cast < _Link_type > ( _M_node ) -> _M_value_field; }

      _Self &
      operator ++ ( )
      {
 _M_node = _Rb_tree_increment ( _M_node );
 return * this;
      }

      _Self
      operator ++ ( int )
      {
 _Self __tmp = * this;
 _M_node = _Rb_tree_increment ( _M_node );
 return __tmp;
      }

      _Self &
      operator -- ( )
      {
 _M_node = _Rb_tree_decrement ( _M_node );
 return * this;
      }

      _Self
      operator -- ( int )
      {
 _Self __tmp = * this;
 _M_node = _Rb_tree_decrement ( _M_node );
 return __tmp;
      }

      bool
      operator == ( const _Self & __x ) const
      { return _M_node == __x . _M_node; }

      bool
      operator != ( const _Self & __x ) const
      { return _M_node != __x . _M_node; }

      _Base_ptr _M_node;
    };

template < typename _Val >
    inline bool
    operator == ( const _Rb_tree_iterator < _Val > & __x,
               const _Rb_tree_const_iterator < _Val > & __y )
    { return __x . _M_node == __y . _M_node; }

template < typename _Val >
    inline bool
    operator != ( const _Rb_tree_iterator < _Val > & __x,
               const _Rb_tree_const_iterator < _Val > & __y )
    { return __x . _M_node != __y . _M_node; }


void _Rb_tree_insert_and_rebalance(const bool __insert_left, _Rb_tree_node_base * __x, _Rb_tree_node_base * __p, _Rb_tree_node_base & __header); 
# 316
_Rb_tree_node_base *_Rb_tree_rebalance_for_erase(_Rb_tree_node_base *const __z, _Rb_tree_node_base & __header); 



template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc = allocator < _Val > >
    class _Rb_tree
    {
      typedef typename _Alloc :: template rebind < _Rb_tree_node < _Val > > :: other
              _Node_allocator;

    protected :
      typedef _Rb_tree_node_base * _Base_ptr;
      typedef const _Rb_tree_node_base * _Const_Base_ptr;

    public :
      typedef _Key key_type;
      typedef _Val value_type;
      typedef value_type * pointer;
      typedef const value_type * const_pointer;
      typedef value_type & reference;
      typedef const value_type & const_reference;
      typedef _Rb_tree_node < _Val > * _Link_type;
      typedef const _Rb_tree_node < _Val > * _Const_Link_type;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Alloc allocator_type;

      _Node_allocator &
      _M_get_Node_allocator ( )
      { return * static_cast < _Node_allocator * > ( & this -> _M_impl ); }

      const _Node_allocator &
      _M_get_Node_allocator ( ) const
      { return * static_cast < const _Node_allocator * > ( & this -> _M_impl ); }

      allocator_type
      get_allocator ( ) const
      { return allocator_type ( _M_get_Node_allocator ( ) ); }

    protected :
      _Link_type
      _M_get_node ( )
      { return _M_impl . _Node_allocator :: allocate ( 1 ); }

      void
      _M_put_node ( _Link_type __p )
      { _M_impl . _Node_allocator :: deallocate ( __p, 1 ); }


      _Link_type
      _M_create_node ( const value_type & __x )
      {
 _Link_type __tmp = _M_get_node ( );
 try
   { get_allocator ( ) . construct ( & __tmp -> _M_value_field, __x ); }
 catch ( ... )
   {
     _M_put_node ( __tmp );
     throw;
   }
 return __tmp;
      }

      void
      _M_destroy_node ( _Link_type __p )
      {
 get_allocator ( ) . destroy ( & __p -> _M_value_field );
 _M_put_node ( __p );
      }



























      _Link_type
      _M_clone_node ( _Const_Link_type __x )
      {
 _Link_type __tmp = _M_create_node ( __x -> _M_value_field );
 __tmp -> _M_color = __x -> _M_color;
 __tmp -> _M_left = 0;
 __tmp -> _M_right = 0;
 return __tmp;
      }

    protected :
      template < typename _Key_compare,
        bool _Is_pod_comparator = __is_pod ( _Key_compare ) >
        struct _Rb_tree_impl : public _Node_allocator
        {
   _Key_compare _M_key_compare;
   _Rb_tree_node_base _M_header;
   size_type _M_node_count;

   _Rb_tree_impl ( )
   : _Node_allocator ( ), _M_key_compare ( ), _M_header ( ),
     _M_node_count ( 0 )
   { _M_initialize ( ); }

   _Rb_tree_impl ( const _Key_compare & __comp, const _Node_allocator & __a )
   : _Node_allocator ( __a ), _M_key_compare ( __comp ), _M_header ( ),
     _M_node_count ( 0 )
   { _M_initialize ( ); }

 private :
   void
   _M_initialize ( )
   {
     this -> _M_header . _M_color = _S_red;
     this -> _M_header . _M_parent = 0;
     this -> _M_header . _M_left = & this -> _M_header;
     this -> _M_header . _M_right = & this -> _M_header;
   }
 };

      _Rb_tree_impl < _Compare > _M_impl;

    protected :
      _Base_ptr &
      _M_root ( )
      { return this -> _M_impl . _M_header . _M_parent; }

      _Const_Base_ptr
      _M_root ( ) const
      { return this -> _M_impl . _M_header . _M_parent; }

      _Base_ptr &
      _M_leftmost ( )
      { return this -> _M_impl . _M_header . _M_left; }

      _Const_Base_ptr
      _M_leftmost ( ) const
      { return this -> _M_impl . _M_header . _M_left; }

      _Base_ptr &
      _M_rightmost ( )
      { return this -> _M_impl . _M_header . _M_right; }

      _Const_Base_ptr
      _M_rightmost ( ) const
      { return this -> _M_impl . _M_header . _M_right; }

      _Link_type
      _M_begin ( )
      { return static_cast < _Link_type > ( this -> _M_impl . _M_header . _M_parent ); }

      _Const_Link_type
      _M_begin ( ) const
      {
 return static_cast < _Const_Link_type >
   ( this -> _M_impl . _M_header . _M_parent );
      }

      _Link_type
      _M_end ( )
      { return static_cast < _Link_type > ( & this -> _M_impl . _M_header ); }

      _Const_Link_type
      _M_end ( ) const
      { return static_cast < _Const_Link_type > ( & this -> _M_impl . _M_header ); }

      static const_reference
      _S_value ( _Const_Link_type __x )
      { return __x -> _M_value_field; }

      static const _Key &
      _S_key ( _Const_Link_type __x )
      { return _KeyOfValue ( ) ( _S_value ( __x ) ); }

      static _Link_type
      _S_left ( _Base_ptr __x )
      { return static_cast < _Link_type > ( __x -> _M_left ); }

      static _Const_Link_type
      _S_left ( _Const_Base_ptr __x )
      { return static_cast < _Const_Link_type > ( __x -> _M_left ); }

      static _Link_type
      _S_right ( _Base_ptr __x )
      { return static_cast < _Link_type > ( __x -> _M_right ); }

      static _Const_Link_type
      _S_right ( _Const_Base_ptr __x )
      { return static_cast < _Const_Link_type > ( __x -> _M_right ); }

      static const_reference
      _S_value ( _Const_Base_ptr __x )
      { return static_cast < _Const_Link_type > ( __x ) -> _M_value_field; }

      static const _Key &
      _S_key ( _Const_Base_ptr __x )
      { return _KeyOfValue ( ) ( _S_value ( __x ) ); }

      static _Base_ptr
      _S_minimum ( _Base_ptr __x )
      { return _Rb_tree_node_base :: _S_minimum ( __x ); }

      static _Const_Base_ptr
      _S_minimum ( _Const_Base_ptr __x )
      { return _Rb_tree_node_base :: _S_minimum ( __x ); }

      static _Base_ptr
      _S_maximum ( _Base_ptr __x )
      { return _Rb_tree_node_base :: _S_maximum ( __x ); }

      static _Const_Base_ptr
      _S_maximum ( _Const_Base_ptr __x )
      { return _Rb_tree_node_base :: _S_maximum ( __x ); }

    public :
      typedef _Rb_tree_iterator < value_type > iterator;
      typedef _Rb_tree_const_iterator < value_type > const_iterator;

      typedef std :: reverse_iterator < iterator > reverse_iterator;
      typedef std :: reverse_iterator < const_iterator > const_reverse_iterator;

    private :
      iterator
      _M_insert_ ( _Const_Base_ptr __x, _Const_Base_ptr __y,
   const value_type & __v );



      iterator
      _M_insert_lower ( _Base_ptr __x, _Base_ptr __y, const value_type & __v );

      iterator
      _M_insert_equal_lower ( const value_type & __x );

      _Link_type
      _M_copy ( _Const_Link_type __x, _Link_type __p );

      void
      _M_erase ( _Link_type __x );

      iterator
      _M_lower_bound ( _Link_type __x, _Link_type __y,
       const _Key & __k );

      const_iterator
      _M_lower_bound ( _Const_Link_type __x, _Const_Link_type __y,
       const _Key & __k ) const;

      iterator
      _M_upper_bound ( _Link_type __x, _Link_type __y,
       const _Key & __k );

      const_iterator
      _M_upper_bound ( _Const_Link_type __x, _Const_Link_type __y,
       const _Key & __k ) const;

    public :

      _Rb_tree ( ) { }

      _Rb_tree ( const _Compare & __comp,
        const allocator_type & __a = allocator_type ( ) )
      : _M_impl ( __comp, __a ) { }

      _Rb_tree ( const _Rb_tree & __x )
      : _M_impl ( __x . _M_impl . _M_key_compare, __x . _M_get_Node_allocator ( ) )
      {
 if ( __x . _M_root ( ) != 0 )
   {
     _M_root ( ) = _M_copy ( __x . _M_begin ( ), _M_end ( ) );
     _M_leftmost ( ) = _S_minimum ( _M_root ( ) );
     _M_rightmost ( ) = _S_maximum ( _M_root ( ) );
     _M_impl . _M_node_count = __x . _M_impl . _M_node_count;
   }
      }





      ~ _Rb_tree ( )
      { _M_erase ( _M_begin ( ) ); }

      _Rb_tree &
      operator = ( const _Rb_tree & __x );


      _Compare
      key_comp ( ) const
      { return _M_impl . _M_key_compare; }

      iterator
      begin ( )
      {
 return iterator ( static_cast < _Link_type >
   ( this -> _M_impl . _M_header . _M_left ) );
      }

      const_iterator
      begin ( ) const
      {
 return const_iterator ( static_cast < _Const_Link_type >
         ( this -> _M_impl . _M_header . _M_left ) );
      }

      iterator
      end ( )
      { return iterator ( static_cast < _Link_type > ( & this -> _M_impl . _M_header ) ); }

      const_iterator
      end ( ) const
      {
 return const_iterator ( static_cast < _Const_Link_type >
         ( & this -> _M_impl . _M_header ) );
      }

      reverse_iterator
      rbegin ( )
      { return reverse_iterator ( end ( ) ); }

      const_reverse_iterator
      rbegin ( ) const
      { return const_reverse_iterator ( end ( ) ); }

      reverse_iterator
      rend ( )
      { return reverse_iterator ( begin ( ) ); }

      const_reverse_iterator
      rend ( ) const
      { return const_reverse_iterator ( begin ( ) ); }

      bool
      empty ( ) const
      { return _M_impl . _M_node_count == 0; }

      size_type
      size ( ) const
      { return _M_impl . _M_node_count; }

      size_type
      max_size ( ) const
      { return _M_get_Node_allocator ( ) . max_size ( ); }

      void



      swap ( _Rb_tree & __t );



      pair < iterator, bool >
      _M_insert_unique ( const value_type & __x );

      iterator
      _M_insert_equal ( const value_type & __x );

      iterator
      _M_insert_unique_ ( const_iterator __position, const value_type & __x );

      iterator
      _M_insert_equal_ ( const_iterator __position, const value_type & __x );

      template < typename _InputIterator >
        void
        _M_insert_unique ( _InputIterator __first, _InputIterator __last );

      template < typename _InputIterator >
        void
        _M_insert_equal ( _InputIterator __first, _InputIterator __last );

      void
      erase ( iterator __position );

      void
      erase ( const_iterator __position );

      size_type
      erase ( const key_type & __x );

      void
      erase ( iterator __first, iterator __last );

      void
      erase ( const_iterator __first, const_iterator __last );

      void
      erase ( const key_type * __first, const key_type * __last );

      void
      clear ( )
      {
        _M_erase ( _M_begin ( ) );
        _M_leftmost ( ) = _M_end ( );
        _M_root ( ) = 0;
        _M_rightmost ( ) = _M_end ( );
        _M_impl . _M_node_count = 0;
      }


      iterator
      find ( const key_type & __k );

      const_iterator
      find ( const key_type & __k ) const;

      size_type
      count ( const key_type & __k ) const;

      iterator
      lower_bound ( const key_type & __k )
      { return _M_lower_bound ( _M_begin ( ), _M_end ( ), __k ); }

      const_iterator
      lower_bound ( const key_type & __k ) const
      { return _M_lower_bound ( _M_begin ( ), _M_end ( ), __k ); }

      iterator
      upper_bound ( const key_type & __k )
      { return _M_upper_bound ( _M_begin ( ), _M_end ( ), __k ); }

      const_iterator
      upper_bound ( const key_type & __k ) const
      { return _M_upper_bound ( _M_begin ( ), _M_end ( ), __k ); }

      pair < iterator, iterator >
      equal_range ( const key_type & __k );

      pair < const_iterator, const_iterator >
      equal_range ( const key_type & __k ) const;


      bool
      __rb_verify ( ) const;
    };

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline bool
    operator == ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
        const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    {
      return __x . size ( ) == __y . size ( )
      && std :: equal ( __x . begin ( ), __x . end ( ), __y . begin ( ) );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline bool
    operator < ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
       const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    {
      return std :: lexicographical_compare ( __x . begin ( ), __x . end ( ),
       __y . begin ( ), __y . end ( ) );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline bool
    operator != ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
        const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    { return ! ( __x == __y ); }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline bool
    operator > ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
       const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    { return __y < __x; }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline bool
    operator <= ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
        const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    { return ! ( __y < __x ); }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline bool
    operator >= ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
        const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    { return ! ( __x < __y ); }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline void
    swap ( _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x,
  _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __y )
    { __x . swap ( __y ); }
# 849
template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > &
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    operator = ( const _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __x )
    {
      if ( this != & __x )
 {

   clear ( );
   _M_impl . _M_key_compare = __x . _M_impl . _M_key_compare;
   if ( __x . _M_root ( ) != 0 )
     {
       _M_root ( ) = _M_copy ( __x . _M_begin ( ), _M_end ( ) );
       _M_leftmost ( ) = _S_minimum ( _M_root ( ) );
       _M_rightmost ( ) = _S_maximum ( _M_root ( ) );
       _M_impl . _M_node_count = __x . _M_impl . _M_node_count;
     }
 }
      return * this;
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_ ( _Const_Base_ptr __x, _Const_Base_ptr __p, const _Val & __v )
    {
      bool __insert_left = ( __x != 0 || __p == _M_end ( )
       || _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ),
            _S_key ( __p ) ) );

      _Link_type __z = _M_create_node ( __v );

      _Rb_tree_insert_and_rebalance ( __insert_left, __z,
        const_cast < _Base_ptr > ( __p ),
        this -> _M_impl . _M_header );
      ++ _M_impl . _M_node_count;
      return iterator ( __z );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_lower ( _Base_ptr __x, _Base_ptr __p, const _Val & __v )
    {
      bool __insert_left = ( __x != 0 || __p == _M_end ( )
       || ! _M_impl . _M_key_compare ( _S_key ( __p ),
             _KeyOfValue ( ) ( __v ) ) );

      _Link_type __z = _M_create_node ( __v );

      _Rb_tree_insert_and_rebalance ( __insert_left, __z, __p,
        this -> _M_impl . _M_header );
      ++ _M_impl . _M_node_count;
      return iterator ( __z );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_equal_lower ( const _Val & __v )
    {
      _Link_type __x = _M_begin ( );
      _Link_type __y = _M_end ( );
      while ( __x != 0 )
 {
   __y = __x;
   __x = ! _M_impl . _M_key_compare ( _S_key ( __x ), _KeyOfValue ( ) ( __v ) ) ?
         _S_left ( __x ) : _S_right ( __x );
 }
      return _M_insert_lower ( __x, __y, __v );
    }

template < typename _Key, typename _Val, typename _KoV,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KoV, _Compare, _Alloc > :: _Link_type
    _Rb_tree < _Key, _Val, _KoV, _Compare, _Alloc > ::
    _M_copy ( _Const_Link_type __x, _Link_type __p )
    {

      _Link_type __top = _M_clone_node ( __x );
      __top -> _M_parent = __p;

      try
 {
   if ( __x -> _M_right )
     __top -> _M_right = _M_copy ( _S_right ( __x ), __top );
   __p = __top;
   __x = _S_left ( __x );

   while ( __x != 0 )
     {
       _Link_type __y = _M_clone_node ( __x );
       __p -> _M_left = __y;
       __y -> _M_parent = __p;
       if ( __x -> _M_right )
  __y -> _M_right = _M_copy ( _S_right ( __x ), __y );
       __p = __y;
       __x = _S_left ( __x );
     }
 }
      catch ( ... )
 {
   _M_erase ( __top );
   throw;
 }
      return __top;
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_erase ( _Link_type __x )
    {

      while ( __x != 0 )
 {
   _M_erase ( _S_right ( __x ) );
   _Link_type __y = _S_left ( __x );
   _M_destroy_node ( __x );
   __x = __y;
 }
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue,
        _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_lower_bound ( _Link_type __x, _Link_type __y,
     const _Key & __k )
    {
      while ( __x != 0 )
 if ( ! _M_impl . _M_key_compare ( _S_key ( __x ), __k ) )
   __y = __x, __x = _S_left ( __x );
 else
   __x = _S_right ( __x );
      return iterator ( __y );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue,
        _Compare, _Alloc > :: const_iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_lower_bound ( _Const_Link_type __x, _Const_Link_type __y,
     const _Key & __k ) const
    {
      while ( __x != 0 )
 if ( ! _M_impl . _M_key_compare ( _S_key ( __x ), __k ) )
   __y = __x, __x = _S_left ( __x );
 else
   __x = _S_right ( __x );
      return const_iterator ( __y );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue,
        _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_upper_bound ( _Link_type __x, _Link_type __y,
     const _Key & __k )
    {
      while ( __x != 0 )
 if ( _M_impl . _M_key_compare ( __k, _S_key ( __x ) ) )
   __y = __x, __x = _S_left ( __x );
 else
   __x = _S_right ( __x );
      return iterator ( __y );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue,
        _Compare, _Alloc > :: const_iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_upper_bound ( _Const_Link_type __x, _Const_Link_type __y,
     const _Key & __k ) const
    {
      while ( __x != 0 )
 if ( _M_impl . _M_key_compare ( __k, _S_key ( __x ) ) )
   __y = __x, __x = _S_left ( __x );
 else
   __x = _S_right ( __x );
      return const_iterator ( __y );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    pair < typename _Rb_tree < _Key, _Val, _KeyOfValue,
      _Compare, _Alloc > :: iterator,
  typename _Rb_tree < _Key, _Val, _KeyOfValue,
      _Compare, _Alloc > :: iterator >
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    equal_range ( const _Key & __k )
    {
      _Link_type __x = _M_begin ( );
      _Link_type __y = _M_end ( );
      while ( __x != 0 )
 {
   if ( _M_impl . _M_key_compare ( _S_key ( __x ), __k ) )
     __x = _S_right ( __x );
   else if ( _M_impl . _M_key_compare ( __k, _S_key ( __x ) ) )
     __y = __x, __x = _S_left ( __x );
   else
     {
       _Link_type __xu ( __x ), __yu ( __y );
       __y = __x, __x = _S_left ( __x );
       __xu = _S_right ( __xu );
       return pair < iterator,
            iterator > ( _M_lower_bound ( __x, __y, __k ),
        _M_upper_bound ( __xu, __yu, __k ) );
     }
 }
      return pair < iterator, iterator > ( iterator ( __y ),
          iterator ( __y ) );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    pair < typename _Rb_tree < _Key, _Val, _KeyOfValue,
      _Compare, _Alloc > :: const_iterator,
  typename _Rb_tree < _Key, _Val, _KeyOfValue,
      _Compare, _Alloc > :: const_iterator >
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    equal_range ( const _Key & __k ) const
    {
      _Const_Link_type __x = _M_begin ( );
      _Const_Link_type __y = _M_end ( );
      while ( __x != 0 )
 {
   if ( _M_impl . _M_key_compare ( _S_key ( __x ), __k ) )
     __x = _S_right ( __x );
   else if ( _M_impl . _M_key_compare ( __k, _S_key ( __x ) ) )
     __y = __x, __x = _S_left ( __x );
   else
     {
       _Const_Link_type __xu ( __x ), __yu ( __y );
       __y = __x, __x = _S_left ( __x );
       __xu = _S_right ( __xu );
       return pair < const_iterator,
            const_iterator > ( _M_lower_bound ( __x, __y, __k ),
       _M_upper_bound ( __xu, __yu, __k ) );
     }
 }
      return pair < const_iterator, const_iterator > ( const_iterator ( __y ),
        const_iterator ( __y ) );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::



    swap ( _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > & __t )

    {
      if ( _M_root ( ) == 0 )
 {
   if ( __t . _M_root ( ) != 0 )
     {
       _M_root ( ) = __t . _M_root ( );
       _M_leftmost ( ) = __t . _M_leftmost ( );
       _M_rightmost ( ) = __t . _M_rightmost ( );
       _M_root ( ) -> _M_parent = _M_end ( );

       __t . _M_root ( ) = 0;
       __t . _M_leftmost ( ) = __t . _M_end ( );
       __t . _M_rightmost ( ) = __t . _M_end ( );
     }
 }
      else if ( __t . _M_root ( ) == 0 )
 {
   __t . _M_root ( ) = _M_root ( );
   __t . _M_leftmost ( ) = _M_leftmost ( );
   __t . _M_rightmost ( ) = _M_rightmost ( );
   __t . _M_root ( ) -> _M_parent = __t . _M_end ( );

   _M_root ( ) = 0;
   _M_leftmost ( ) = _M_end ( );
   _M_rightmost ( ) = _M_end ( );
 }
      else
 {
   std :: swap ( _M_root ( ), __t . _M_root ( ) );
   std :: swap ( _M_leftmost ( ), __t . _M_leftmost ( ) );
   std :: swap ( _M_rightmost ( ), __t . _M_rightmost ( ) );

   _M_root ( ) -> _M_parent = _M_end ( );
   __t . _M_root ( ) -> _M_parent = __t . _M_end ( );
 }

      std :: swap ( this -> _M_impl . _M_node_count, __t . _M_impl . _M_node_count );
      std :: swap ( this -> _M_impl . _M_key_compare, __t . _M_impl . _M_key_compare );



      std :: __alloc_swap < _Node_allocator > ::
 _S_do_it ( _M_get_Node_allocator ( ), __t . _M_get_Node_allocator ( ) );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    pair < typename _Rb_tree < _Key, _Val, _KeyOfValue,
      _Compare, _Alloc > :: iterator, bool >
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_unique ( const _Val & __v )
    {
      _Link_type __x = _M_begin ( );
      _Link_type __y = _M_end ( );
      bool __comp = true;
      while ( __x != 0 )
 {
   __y = __x;
   __comp = _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ), _S_key ( __x ) );
   __x = __comp ? _S_left ( __x ) : _S_right ( __x );
 }
      iterator __j = iterator ( __y );
      if ( __comp )
 {
   if ( __j == begin ( ) )
     return pair < iterator, bool > ( _M_insert_ ( __x, __y, __v ), true );
   else
     -- __j;
 }
      if ( _M_impl . _M_key_compare ( _S_key ( __j . _M_node ), _KeyOfValue ( ) ( __v ) ) )
 return pair < iterator, bool > ( _M_insert_ ( __x, __y, __v ), true );
      return pair < iterator, bool > ( __j, false );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_equal ( const _Val & __v )
    {
      _Link_type __x = _M_begin ( );
      _Link_type __y = _M_end ( );
      while ( __x != 0 )
 {
   __y = __x;
   __x = _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ), _S_key ( __x ) ) ?
         _S_left ( __x ) : _S_right ( __x );
 }
      return _M_insert_ ( __x, __y, __v );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_unique_ ( const_iterator __position, const _Val & __v )
    {

      if ( __position . _M_node == _M_end ( ) )
 {
   if ( size ( ) > 0
       && _M_impl . _M_key_compare ( _S_key ( _M_rightmost ( ) ),
     _KeyOfValue ( ) ( __v ) ) )
     return _M_insert_ ( 0, _M_rightmost ( ), __v );
   else
     return _M_insert_unique ( __v ) . first;
 }
      else if ( _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ),
          _S_key ( __position . _M_node ) ) )
 {

   const_iterator __before = __position;
   if ( __position . _M_node == _M_leftmost ( ) )
     return _M_insert_ ( _M_leftmost ( ), _M_leftmost ( ), __v );
   else if ( _M_impl . _M_key_compare ( _S_key ( ( -- __before ) . _M_node ),
       _KeyOfValue ( ) ( __v ) ) )
     {
       if ( _S_right ( __before . _M_node ) == 0 )
  return _M_insert_ ( 0, __before . _M_node, __v );
       else
  return _M_insert_ ( __position . _M_node,
      __position . _M_node, __v );
     }
   else
     return _M_insert_unique ( __v ) . first;
 }
      else if ( _M_impl . _M_key_compare ( _S_key ( __position . _M_node ),
          _KeyOfValue ( ) ( __v ) ) )
 {

   const_iterator __after = __position;
   if ( __position . _M_node == _M_rightmost ( ) )
     return _M_insert_ ( 0, _M_rightmost ( ), __v );
   else if ( _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ),
       _S_key ( ( ++ __after ) . _M_node ) ) )
     {
       if ( _S_right ( __position . _M_node ) == 0 )
  return _M_insert_ ( 0, __position . _M_node, __v );
       else
  return _M_insert_ ( __after . _M_node, __after . _M_node, __v );
     }
   else
     return _M_insert_unique ( __v ) . first;
 }
      else

 return iterator ( static_cast < _Link_type >
   ( const_cast < _Base_ptr > ( __position . _M_node ) ) );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    _M_insert_equal_ ( const_iterator __position, const _Val & __v )
    {

      if ( __position . _M_node == _M_end ( ) )
 {
   if ( size ( ) > 0
       && ! _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ),
      _S_key ( _M_rightmost ( ) ) ) )
     return _M_insert_ ( 0, _M_rightmost ( ), __v );
   else
     return _M_insert_equal ( __v );
 }
      else if ( ! _M_impl . _M_key_compare ( _S_key ( __position . _M_node ),
           _KeyOfValue ( ) ( __v ) ) )
 {

   const_iterator __before = __position;
   if ( __position . _M_node == _M_leftmost ( ) )
     return _M_insert_ ( _M_leftmost ( ), _M_leftmost ( ), __v );
   else if ( ! _M_impl . _M_key_compare ( _KeyOfValue ( ) ( __v ),
        _S_key ( ( -- __before ) . _M_node ) ) )
     {
       if ( _S_right ( __before . _M_node ) == 0 )
  return _M_insert_ ( 0, __before . _M_node, __v );
       else
  return _M_insert_ ( __position . _M_node,
      __position . _M_node, __v );
     }
   else
     return _M_insert_equal ( __v );
 }
      else
 {

   const_iterator __after = __position;
   if ( __position . _M_node == _M_rightmost ( ) )
     return _M_insert_ ( 0, _M_rightmost ( ), __v );
   else if ( ! _M_impl . _M_key_compare ( _S_key ( ( ++ __after ) . _M_node ),
        _KeyOfValue ( ) ( __v ) ) )
     {
       if ( _S_right ( __position . _M_node ) == 0 )
  return _M_insert_ ( 0, __position . _M_node, __v );
       else
  return _M_insert_ ( __after . _M_node, __after . _M_node, __v );
     }
   else
     return _M_insert_equal_lower ( __v );
 }
    }

template < typename _Key, typename _Val, typename _KoV,
           typename _Cmp, typename _Alloc >
    template < class _II >
      void
      _Rb_tree < _Key, _Val, _KoV, _Cmp, _Alloc > ::
      _M_insert_unique ( _II __first, _II __last )
      {
 for (; __first != __last; ++ __first )
   _M_insert_unique_ ( end ( ), * __first );
      }

template < typename _Key, typename _Val, typename _KoV,
           typename _Cmp, typename _Alloc >
    template < class _II >
      void
      _Rb_tree < _Key, _Val, _KoV, _Cmp, _Alloc > ::
      _M_insert_equal ( _II __first, _II __last )
      {
 for (; __first != __last; ++ __first )
   _M_insert_equal_ ( end ( ), * __first );
      }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    erase ( iterator __position )
    {
      _Link_type __y =
 static_cast < _Link_type > ( _Rb_tree_rebalance_for_erase
    ( __position . _M_node,
     this -> _M_impl . _M_header ) );
      _M_destroy_node ( __y );
      -- _M_impl . _M_node_count;
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    inline void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    erase ( const_iterator __position )
    {
      _Link_type __y =
 static_cast < _Link_type > ( _Rb_tree_rebalance_for_erase
    ( const_cast < _Base_ptr > ( __position . _M_node ),
     this -> _M_impl . _M_header ) );
      _M_destroy_node ( __y );
      -- _M_impl . _M_node_count;
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: size_type
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    erase ( const _Key & __x )
    {
      pair < iterator, iterator > __p = equal_range ( __x );
      const size_type __old_size = size ( );
      erase ( __p . first, __p . second );
      return __old_size - size ( );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    erase ( iterator __first, iterator __last )
    {
      if ( __first == begin ( ) && __last == end ( ) )
 clear ( );
      else
 while ( __first != __last )
   erase ( __first ++ );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    erase ( const_iterator __first, const_iterator __last )
    {
      if ( __first == begin ( ) && __last == end ( ) )
 clear ( );
      else
 while ( __first != __last )
   erase ( __first ++ );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    void
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    erase ( const _Key * __first, const _Key * __last )
    {
      while ( __first != __last )
 erase ( * __first ++ );
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue,
        _Compare, _Alloc > :: iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    find ( const _Key & __k )
    {
      iterator __j = _M_lower_bound ( _M_begin ( ), _M_end ( ), __k );
      return ( __j == end ( )
       || _M_impl . _M_key_compare ( __k,
     _S_key ( __j . _M_node ) ) ) ? end ( ) : __j;
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue,
        _Compare, _Alloc > :: const_iterator
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    find ( const _Key & __k ) const
    {
      const_iterator __j = _M_lower_bound ( _M_begin ( ), _M_end ( ), __k );
      return ( __j == end ( )
       || _M_impl . _M_key_compare ( __k,
     _S_key ( __j . _M_node ) ) ) ? end ( ) : __j;
    }

template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    typename _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: size_type
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > ::
    count ( const _Key & __k ) const
    {
      pair < const_iterator, const_iterator > __p = equal_range ( __k );
      const size_type __n = std :: distance ( __p . first, __p . second );
      return __n;
    }


unsigned _Rb_tree_black_count(const _Rb_tree_node_base * __node, const _Rb_tree_node_base * __root); 


template < typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc >
    bool
    _Rb_tree < _Key, _Val, _KeyOfValue, _Compare, _Alloc > :: __rb_verify ( ) const
    {
      if ( _M_impl . _M_node_count == 0 || begin ( ) == end ( ) )
 return _M_impl . _M_node_count == 0 && begin ( ) == end ( )
        && this -> _M_impl . _M_header . _M_left == _M_end ( )
        && this -> _M_impl . _M_header . _M_right == _M_end ( );

      unsigned int __len = _Rb_tree_black_count ( _M_leftmost ( ), _M_root ( ) );
      for ( const_iterator __it = begin ( ); __it != end ( ); ++ __it )
 {
   _Const_Link_type __x = static_cast < _Const_Link_type > ( __it . _M_node );
   _Const_Link_type __L = _S_left ( __x );
   _Const_Link_type __R = _S_right ( __x );

   if ( __x -> _M_color == _S_red )
     if ( ( __L && __L -> _M_color == _S_red )
  || ( __R && __R -> _M_color == _S_red ) )
       return false;

   if ( __L && _M_impl . _M_key_compare ( _S_key ( __x ), _S_key ( __L ) ) )
     return false;
   if ( __R && _M_impl . _M_key_compare ( _S_key ( __R ), _S_key ( __x ) ) )
     return false;

   if ( ! __L && ! __R && _Rb_tree_black_count ( __x, _M_root ( ) ) != __len )
     return false;
 }

      if ( _M_leftmost ( ) != _Rb_tree_node_base :: _S_minimum ( _M_root ( ) ) )
 return false;
      if ( _M_rightmost ( ) != _Rb_tree_node_base :: _S_maximum ( _M_root ( ) ) )
 return false;
      return true;
    }

}
# 64 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_map.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 84
template < typename _Key, typename _Tp, typename _Compare = std :: less < _Key >,
            typename _Alloc = std :: allocator < std :: pair < const _Key, _Tp > > >
    class map
    {
    public :
      typedef _Key key_type;
      typedef _Tp mapped_type;
      typedef std :: pair < const _Key, _Tp > value_type;
      typedef _Compare key_compare;
      typedef _Alloc allocator_type;

    private :

      typedef typename _Alloc :: value_type _Alloc_value_type;





    public :
      class value_compare
      : public std :: binary_function < value_type, value_type, bool >
      {
 friend class map < _Key, _Tp, _Compare, _Alloc >;
      protected :
 _Compare comp;

 value_compare ( _Compare __c )
 : comp ( __c ) { }

      public :
 bool operator ( ) ( const value_type & __x, const value_type & __y ) const
 { return comp ( __x . first, __y . first ); }
      };

    private :

      typedef typename _Alloc :: template rebind < value_type > :: other
        _Pair_alloc_type;

      typedef _Rb_tree < key_type, value_type, _Select1st < value_type >,
         key_compare, _Pair_alloc_type > _Rep_type;


      _Rep_type _M_t;

    public :


      typedef typename _Pair_alloc_type :: pointer pointer;
      typedef typename _Pair_alloc_type :: const_pointer const_pointer;
      typedef typename _Pair_alloc_type :: reference reference;
      typedef typename _Pair_alloc_type :: const_reference const_reference;
      typedef typename _Rep_type :: iterator iterator;
      typedef typename _Rep_type :: const_iterator const_iterator;
      typedef typename _Rep_type :: size_type size_type;
      typedef typename _Rep_type :: difference_type difference_type;
      typedef typename _Rep_type :: reverse_iterator reverse_iterator;
      typedef typename _Rep_type :: const_reverse_iterator const_reverse_iterator;







      map ( )
      : _M_t ( ) { }






      explicit
      map ( const _Compare & __comp,
   const allocator_type & __a = allocator_type ( ) )
      : _M_t ( __comp, __a ) { }








      map ( const map & __x )
      : _M_t ( __x . _M_t ) { }







































      template < typename _InputIterator >
        map ( _InputIterator __first, _InputIterator __last )
 : _M_t ( )
        { _M_t . _M_insert_unique ( __first, __last ); }












      template < typename _InputIterator >
        map ( _InputIterator __first, _InputIterator __last,
     const _Compare & __comp,
     const allocator_type & __a = allocator_type ( ) )
 : _M_t ( __comp, __a )
        { _M_t . _M_insert_unique ( __first, __last ); }

















      map &
      operator = ( const map & __x )
      {
 _M_t = __x . _M_t;
 return * this;
      }







































      allocator_type
      get_allocator ( ) const
      { return _M_t . get_allocator ( ); }







      iterator
      begin ( )
      { return _M_t . begin ( ); }






      const_iterator
      begin ( ) const
      { return _M_t . begin ( ); }






      iterator
      end ( )
      { return _M_t . end ( ); }






      const_iterator
      end ( ) const
      { return _M_t . end ( ); }






      reverse_iterator
      rbegin ( )
      { return _M_t . rbegin ( ); }






      const_reverse_iterator
      rbegin ( ) const
      { return _M_t . rbegin ( ); }






      reverse_iterator
      rend ( )
      { return _M_t . rend ( ); }






      const_reverse_iterator
      rend ( ) const
      { return _M_t . rend ( ); }











































      bool
      empty ( ) const
      { return _M_t . empty ( ); }


      size_type
      size ( ) const
      { return _M_t . size ( ); }


      size_type
      max_size ( ) const
      { return _M_t . max_size ( ); }














      mapped_type &
      operator [ ] ( const key_type & __k )
      {



 iterator __i = lower_bound ( __k );

 if ( __i == end ( ) || key_comp ( ) ( __k, ( * __i ) . first ) )
          __i = insert ( __i, value_type ( __k, mapped_type ( ) ) );
 return ( * __i ) . second;
      }










      mapped_type &
      at ( const key_type & __k )
      {
 iterator __i = lower_bound ( __k );
 if ( __i == end ( ) || key_comp ( ) ( __k, ( * __i ) . first ) )
   __throw_out_of_range ( ( "map::at" ) );
 return ( * __i ) . second;
      }

      const mapped_type &
      at ( const key_type & __k ) const
      {
 const_iterator __i = lower_bound ( __k );
 if ( __i == end ( ) || key_comp ( ) ( __k, ( * __i ) . first ) )
   __throw_out_of_range ( ( "map::at" ) );
 return ( * __i ) . second;
      }


















      std :: pair < iterator, bool >
      insert ( const value_type & __x )
      { return _M_t . _M_insert_unique ( __x ); }





































      iterator
      insert ( iterator __position, const value_type & __x )
      { return _M_t . _M_insert_unique_ ( __position, __x ); }









      template < typename _InputIterator >
        void
        insert ( _InputIterator __first, _InputIterator __last )
        { _M_t . _M_insert_unique ( __first, __last ); }











      void
      erase ( iterator __position )
      { _M_t . erase ( __position ); }












      size_type
      erase ( const key_type & __x )
      { return _M_t . erase ( __x ); }












      void
      erase ( iterator __first, iterator __last )
      { _M_t . erase ( __first, __last ); }












      void



      swap ( map & __x )

      { _M_t . swap ( __x . _M_t ); }







      void
      clear ( )
      { _M_t . clear ( ); }






      key_compare
      key_comp ( ) const
      { return _M_t . key_comp ( ); }





      value_compare
      value_comp ( ) const
      { return value_compare ( _M_t . key_comp ( ) ); }













      iterator
      find ( const key_type & __x )
      { return _M_t . find ( __x ); }












      const_iterator
      find ( const key_type & __x ) const
      { return _M_t . find ( __x ); }









      size_type
      count ( const key_type & __x ) const
      { return _M_t . find ( __x ) == _M_t . end ( ) ? 0 : 1; }












      iterator
      lower_bound ( const key_type & __x )
      { return _M_t . lower_bound ( __x ); }












      const_iterator
      lower_bound ( const key_type & __x ) const
      { return _M_t . lower_bound ( __x ); }







      iterator
      upper_bound ( const key_type & __x )
      { return _M_t . upper_bound ( __x ); }







      const_iterator
      upper_bound ( const key_type & __x ) const
      { return _M_t . upper_bound ( __x ); }
















      std :: pair < iterator, iterator >
      equal_range ( const key_type & __x )
      { return _M_t . equal_range ( __x ); }
















      std :: pair < const_iterator, const_iterator >
      equal_range ( const key_type & __x ) const
      { return _M_t . equal_range ( __x ); }

      template < typename _K1, typename _T1, typename _C1, typename _A1 >
        friend bool
        operator == ( const map < _K1, _T1, _C1, _A1 > &,
     const map < _K1, _T1, _C1, _A1 > & );

      template < typename _K1, typename _T1, typename _C1, typename _A1 >
        friend bool
        operator < ( const map < _K1, _T1, _C1, _A1 > &,
    const map < _K1, _T1, _C1, _A1 > & );
    };
# 797
template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator == ( const map < _Key, _Tp, _Compare, _Alloc > & __x,
               const map < _Key, _Tp, _Compare, _Alloc > & __y )
    { return __x . _M_t == __y . _M_t; }
# 814
template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator < ( const map < _Key, _Tp, _Compare, _Alloc > & __x,
              const map < _Key, _Tp, _Compare, _Alloc > & __y )
    { return __x . _M_t < __y . _M_t; }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator != ( const map < _Key, _Tp, _Compare, _Alloc > & __x,
               const map < _Key, _Tp, _Compare, _Alloc > & __y )
    { return ! ( __x == __y ); }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator > ( const map < _Key, _Tp, _Compare, _Alloc > & __x,
              const map < _Key, _Tp, _Compare, _Alloc > & __y )
    { return __y < __x; }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator <= ( const map < _Key, _Tp, _Compare, _Alloc > & __x,
               const map < _Key, _Tp, _Compare, _Alloc > & __y )
    { return ! ( __y < __x ); }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator >= ( const map < _Key, _Tp, _Compare, _Alloc > & __x,
               const map < _Key, _Tp, _Compare, _Alloc > & __y )
    { return ! ( __x < __y ); }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline void
    swap ( map < _Key, _Tp, _Compare, _Alloc > & __x,
  map < _Key, _Tp, _Compare, _Alloc > & __y )
    { __x . swap ( __y ); }
# 869
}
# 63 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_multimap.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 83
template < typename _Key, typename _Tp,
     typename _Compare = std :: less < _Key >,
     typename _Alloc = std :: allocator < std :: pair < const _Key, _Tp > > >
    class multimap
    {
    public :
      typedef _Key key_type;
      typedef _Tp mapped_type;
      typedef std :: pair < const _Key, _Tp > value_type;
      typedef _Compare key_compare;
      typedef _Alloc allocator_type;

    private :

      typedef typename _Alloc :: value_type _Alloc_value_type;





    public :
      class value_compare
      : public std :: binary_function < value_type, value_type, bool >
      {
 friend class multimap < _Key, _Tp, _Compare, _Alloc >;
      protected :
 _Compare comp;

 value_compare ( _Compare __c )
 : comp ( __c ) { }

      public :
 bool operator ( ) ( const value_type & __x, const value_type & __y ) const
 { return comp ( __x . first, __y . first ); }
      };

    private :

      typedef typename _Alloc :: template rebind < value_type > :: other
        _Pair_alloc_type;

      typedef _Rb_tree < key_type, value_type, _Select1st < value_type >,
         key_compare, _Pair_alloc_type > _Rep_type;

      _Rep_type _M_t;

    public :


      typedef typename _Pair_alloc_type :: pointer pointer;
      typedef typename _Pair_alloc_type :: const_pointer const_pointer;
      typedef typename _Pair_alloc_type :: reference reference;
      typedef typename _Pair_alloc_type :: const_reference const_reference;
      typedef typename _Rep_type :: iterator iterator;
      typedef typename _Rep_type :: const_iterator const_iterator;
      typedef typename _Rep_type :: size_type size_type;
      typedef typename _Rep_type :: difference_type difference_type;
      typedef typename _Rep_type :: reverse_iterator reverse_iterator;
      typedef typename _Rep_type :: const_reverse_iterator const_reverse_iterator;






      multimap ( )
      : _M_t ( ) { }






      explicit
      multimap ( const _Compare & __comp,
        const allocator_type & __a = allocator_type ( ) )
      : _M_t ( __comp, __a ) { }








      multimap ( const multimap & __x )
      : _M_t ( __x . _M_t ) { }






































      template < typename _InputIterator >
        multimap ( _InputIterator __first, _InputIterator __last )
 : _M_t ( )
        { _M_t . _M_insert_equal ( __first, __last ); }












      template < typename _InputIterator >
        multimap ( _InputIterator __first, _InputIterator __last,
   const _Compare & __comp,
   const allocator_type & __a = allocator_type ( ) )
        : _M_t ( __comp, __a )
        { _M_t . _M_insert_equal ( __first, __last ); }

















      multimap &
      operator = ( const multimap & __x )
      {
 _M_t = __x . _M_t;
 return * this;
      }







































      allocator_type
      get_allocator ( ) const
      { return _M_t . get_allocator ( ); }







      iterator
      begin ( )
      { return _M_t . begin ( ); }






      const_iterator
      begin ( ) const
      { return _M_t . begin ( ); }






      iterator
      end ( )
      { return _M_t . end ( ); }






      const_iterator
      end ( ) const
      { return _M_t . end ( ); }






      reverse_iterator
      rbegin ( )
      { return _M_t . rbegin ( ); }






      const_reverse_iterator
      rbegin ( ) const
      { return _M_t . rbegin ( ); }






      reverse_iterator
      rend ( )
      { return _M_t . rend ( ); }






      const_reverse_iterator
      rend ( ) const
      { return _M_t . rend ( ); }









































      bool
      empty ( ) const
      { return _M_t . empty ( ); }


      size_type
      size ( ) const
      { return _M_t . size ( ); }


      size_type
      max_size ( ) const
      { return _M_t . max_size ( ); }














      iterator
      insert ( const value_type & __x )
      { return _M_t . _M_insert_equal ( __x ); }





















      iterator
      insert ( iterator __position, const value_type & __x )
      { return _M_t . _M_insert_equal_ ( __position, __x ); }










      template < typename _InputIterator >
        void
        insert ( _InputIterator __first, _InputIterator __last )
        { _M_t . _M_insert_equal ( __first, __last ); }
























      void
      erase ( iterator __position )
      { _M_t . erase ( __position ); }












      size_type
      erase ( const key_type & __x )
      { return _M_t . erase ( __x ); }












      void
      erase ( iterator __first, iterator __last )
      { _M_t . erase ( __first, __last ); }












      void



      swap ( multimap & __x )

      { _M_t . swap ( __x . _M_t ); }







      void
      clear ( )
      { _M_t . clear ( ); }






      key_compare
      key_comp ( ) const
      { return _M_t . key_comp ( ); }





      value_compare
      value_comp ( ) const
      { return value_compare ( _M_t . key_comp ( ) ); }













      iterator
      find ( const key_type & __x )
      { return _M_t . find ( __x ); }












      const_iterator
      find ( const key_type & __x ) const
      { return _M_t . find ( __x ); }






      size_type
      count ( const key_type & __x ) const
      { return _M_t . count ( __x ); }












      iterator
      lower_bound ( const key_type & __x )
      { return _M_t . lower_bound ( __x ); }












      const_iterator
      lower_bound ( const key_type & __x ) const
      { return _M_t . lower_bound ( __x ); }







      iterator
      upper_bound ( const key_type & __x )
      { return _M_t . upper_bound ( __x ); }







      const_iterator
      upper_bound ( const key_type & __x ) const
      { return _M_t . upper_bound ( __x ); }














      std :: pair < iterator, iterator >
      equal_range ( const key_type & __x )
      { return _M_t . equal_range ( __x ); }














      std :: pair < const_iterator, const_iterator >
      equal_range ( const key_type & __x ) const
      { return _M_t . equal_range ( __x ); }

      template < typename _K1, typename _T1, typename _C1, typename _A1 >
        friend bool
        operator == ( const multimap < _K1, _T1, _C1, _A1 > &,
     const multimap < _K1, _T1, _C1, _A1 > & );

      template < typename _K1, typename _T1, typename _C1, typename _A1 >
        friend bool
        operator < ( const multimap < _K1, _T1, _C1, _A1 > &,
    const multimap < _K1, _T1, _C1, _A1 > & );
  };
# 726
template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator == ( const multimap < _Key, _Tp, _Compare, _Alloc > & __x,
               const multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { return __x . _M_t == __y . _M_t; }
# 743
template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator < ( const multimap < _Key, _Tp, _Compare, _Alloc > & __x,
              const multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { return __x . _M_t < __y . _M_t; }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator != ( const multimap < _Key, _Tp, _Compare, _Alloc > & __x,
               const multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { return ! ( __x == __y ); }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator > ( const multimap < _Key, _Tp, _Compare, _Alloc > & __x,
              const multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { return __y < __x; }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator <= ( const multimap < _Key, _Tp, _Compare, _Alloc > & __x,
               const multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { return ! ( __y < __x ); }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline bool
    operator >= ( const multimap < _Key, _Tp, _Compare, _Alloc > & __x,
               const multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { return ! ( __x < __y ); }


template < typename _Key, typename _Tp, typename _Compare, typename _Alloc >
    inline void
    swap ( multimap < _Key, _Tp, _Compare, _Alloc > & __x,
         multimap < _Key, _Tp, _Compare, _Alloc > & __y )
    { __x . swap ( __y ); }
# 798
}
# 72 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacc/openacc.h"
extern "C" { extern const int acc_async_sync; } 


extern "C" { extern const int acc_async_noval; } 
# 96
extern "C" { typedef 
# 87
enum { 
acc_device_none, 
acc_device_default, 
acc_device_host, 
acc_device_not_host, 
acc_device_cuda, 
acc_device_opencl, 
acc_device_nvidia, 
acc_device_radeon
} acc_device_t; }
# 105
extern "C" void *acc_get_current_cuda_device(); 
# 111
extern "C" void *acc_get_current_cuda_context(); 
# 117
extern "C" void *acc_get_current_opencl_device(); 
# 123
extern "C" void *acc_get_current_opencl_context(); 
# 129
extern "C" void *acc_get_cuda_stream(int async); 
# 136
extern "C" int acc_set_cuda_stream(int async, void * stream); 
# 142
extern "C" void *acc_get_opencl_queue(int async); 
# 149
extern "C" int acc_set_opencl_queue(int async, void * queue); 
# 159
extern "C" int acc_get_num_devices(acc_device_t devicetype); 
# 167
extern "C" void acc_set_device_type(acc_device_t devicetype); 
# 176
extern "C" acc_device_t acc_get_device_type(); 
# 185
extern "C" void acc_set_device_num(int devicenum, acc_device_t devicetype); 
# 194
extern "C" int acc_get_device_num(acc_device_t devicetype); 
# 202
extern "C" int acc_async_test(int arg); 
# 208
extern "C" int acc_async_test_all(); 
# 216
extern "C" void acc_async_wait(int async_value); 

extern "C" void acc_wait(int async_value); 
# 227
extern "C" void acc_async_wait_async(int awaited_value, int async_value); 

extern "C" void acc_wait_async(int awaited_value, int async_value); 
# 235
extern "C" void acc_async_wait_all(); 

extern "C" void acc_wait_all(); 
# 245
extern "C" void acc_async_wait_all_async(int awaited_value); 

extern "C" void acc_wait_all_async(int awaited_value); 
# 255
extern "C" void acc_init(acc_device_t devicetype); 
# 263
extern "C" void acc_shutdown(acc_device_t devicetype); 
# 269
extern "C" int acc_on_device(acc_device_t devicetype); 
# 278
extern "C" void *acc_malloc(size_t bytes); 
# 286
extern "C" void acc_free(void * ptr); 
# 297
extern "C" void *acc_copyin(void * host_address, size_t bytes); 
# 308
extern "C" void *acc_present_or_copyin(void * host_address, size_t bytes); 

extern "C" void *acc_pcopyin(void * host_address, size_t bytes); 
# 320
extern "C" void *acc_create_coherent(void * host_address, size_t bytes); 
# 330
extern "C" void *acc_create(void * host_address, size_t bytes); 
# 340
extern "C" void *acc_present_or_create(void * host_address, size_t bytes); 

extern "C" void *acc_pcreate(void * host_address, size_t bytes); 
# 352
extern "C" void acc_copyout(void * host_address, size_t bytes); 
# 362
extern "C" void acc_delete(void * host_address, size_t bytes); 
# 371
extern "C" void acc_update_device(void * host_address, size_t bytes); 
# 380
extern "C" void acc_update_self(void * host_address, size_t bytes); 
# 390
extern "C" void acc_map_data(void * host_address, void * device_address, size_t bytes); 
# 398
extern "C" void acc_unmap_data(void * host_address); 
# 407
extern "C" void *acc_deviceptr(void * host_address); 
# 416
extern "C" void *acc_hostptr(void * device_address); 
# 426
extern "C" int acc_is_present(void * host_address, size_t bytes); 
# 436
extern "C" void acc_memcpy_to_device(void * dest, void * src, size_t bytes); 
# 446
extern "C" void acc_memcpy_from_device(void * dest, void * src, size_t bytes); 
# 29 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Target.h"
namespace hmpprt { 



enum Target { 

UNSPECIFIED_TARGET, 
HOST, 
C = 1, 
CUDA, 
OPENCL = 4, 
ANY_TARGET = 7
}; 

}
# 67 "/usr/include/bits/waitstatus.h" 3
extern "C" { union wait { 

int w_status; 

struct { 

unsigned __w_termsig:7; 
unsigned __w_coredump:1; 
unsigned __w_retcode:8; 
unsigned:16; 
# 84
} __wait_terminated; 

struct { 

unsigned __w_stopval:8; 
unsigned __w_stopsig:8; 
unsigned:16; 
# 97
} __wait_stopped; 
}; }
# 102 "/usr/include/stdlib.h" 3
extern "C" { typedef 
# 99
struct { 
int quot; 
int rem; 
} div_t; }
# 110
extern "C" { typedef 
# 107
struct { 
long quot; 
long rem; 
} ldiv_t; }
# 122
__extension__ extern "C" { typedef 
# 119
struct { 
long long quot; 
long long rem; 
} lldiv_t; }
# 140
extern "C" size_t __ctype_get_mb_cur_max() throw(); 




extern "C" double atof(const char * __nptr) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 

extern "C" int atoi(const char * __nptr) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 

extern "C" long atol(const char * __nptr) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 158
__extension__ extern "C" long long atoll(const char * __nptr) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 165
extern "C" double strtod(const char * __nptr, char ** __endptr) throw()

 __attribute((__nonnull__(1))); 
# 173
extern "C" float strtof(const char * __nptr, char ** __endptr) throw()
 __attribute((__nonnull__(1))); 

extern "C" long double strtold(const char * __nptr, char ** __endptr) throw()

 __attribute((__nonnull__(1))); 
# 184
extern "C" long strtol(const char * __nptr, char ** __endptr, int __base) throw()

 __attribute((__nonnull__(1))); 

extern "C" unsigned long strtoul(const char * __nptr, char ** __endptr, int __base) throw()

 __attribute((__nonnull__(1))); 
# 196
__extension__ extern "C" long long strtoq(const char * __nptr, char ** __endptr, int __base) throw()

 __attribute((__nonnull__(1))); 


__extension__ extern "C" unsigned long long strtouq(const char * __nptr, char ** __endptr, int __base) throw()

 __attribute((__nonnull__(1))); 
# 210
__extension__ extern "C" long long strtoll(const char * __nptr, char ** __endptr, int __base) throw()

 __attribute((__nonnull__(1))); 


__extension__ extern "C" unsigned long long strtoull(const char * __nptr, char ** __endptr, int __base) throw()

 __attribute((__nonnull__(1))); 
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef 
# 28
struct __locale_struct { 


struct __locale_data *__locales[13]; 


const unsigned short *__ctype_b; 
const int *__ctype_tolower; 
const int *__ctype_toupper; 


const char *__names[13]; 
} *__locale_t; }


extern "C" { typedef __locale_t locale_t; }
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char * __nptr, char ** __endptr, int __base, __locale_t __loc) throw()

 __attribute((__nonnull__(1, 4))); 

extern "C" unsigned long strtoul_l(const char * __nptr, char ** __endptr, int __base, __locale_t __loc) throw()


 __attribute((__nonnull__(1, 4))); 


__extension__ extern "C" long long strtoll_l(const char * __nptr, char ** __endptr, int __base, __locale_t __loc) throw()


 __attribute((__nonnull__(1, 4))); 


__extension__ extern "C" unsigned long long strtoull_l(const char * __nptr, char ** __endptr, int __base, __locale_t __loc) throw()


 __attribute((__nonnull__(1, 4))); 

extern "C" double strtod_l(const char * __nptr, char ** __endptr, __locale_t __loc) throw()

 __attribute((__nonnull__(1, 3))); 

extern "C" float strtof_l(const char * __nptr, char ** __endptr, __locale_t __loc) throw()

 __attribute((__nonnull__(1, 3))); 

extern "C" long double strtold_l(const char * __nptr, char ** __endptr, __locale_t __loc) throw()


 __attribute((__nonnull__(1, 3))); 
# 311
extern "C" char *l64a(long __n) throw(); 


extern "C" long a64l(const char * __s) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 31 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned char __u_char; }
extern "C" { typedef unsigned short __u_short; }
extern "C" { typedef unsigned __u_int; }
extern "C" { typedef unsigned long __u_long; }


extern "C" { typedef signed char __int8_t; }
extern "C" { typedef unsigned char __uint8_t; }
extern "C" { typedef signed short __int16_t; }
extern "C" { typedef unsigned short __uint16_t; }
extern "C" { typedef signed int __int32_t; }
extern "C" { typedef unsigned __uint32_t; }

extern "C" { typedef signed long __int64_t; }
extern "C" { typedef unsigned long __uint64_t; }
# 53
extern "C" { typedef long __quad_t; }
extern "C" { typedef unsigned long __u_quad_t; }
# 134
extern "C" { typedef unsigned long __dev_t; }
extern "C" { typedef unsigned __uid_t; }
extern "C" { typedef unsigned __gid_t; }
extern "C" { typedef unsigned long __ino_t; }
extern "C" { typedef unsigned long __ino64_t; }
extern "C" { typedef unsigned __mode_t; }
extern "C" { typedef unsigned long __nlink_t; }
extern "C" { typedef long __off_t; }
extern "C" { typedef long __off64_t; }
extern "C" { typedef int __pid_t; }
extern "C" { typedef struct { int __val[2]; } __fsid_t; }
extern "C" { typedef long __clock_t; }
extern "C" { typedef unsigned long __rlim_t; }
extern "C" { typedef unsigned long __rlim64_t; }
extern "C" { typedef unsigned __id_t; }
extern "C" { typedef long __time_t; }
extern "C" { typedef unsigned __useconds_t; }
extern "C" { typedef long __suseconds_t; }

extern "C" { typedef int __daddr_t; }
extern "C" { typedef long __swblk_t; }
extern "C" { typedef int __key_t; }


extern "C" { typedef int __clockid_t; }


extern "C" { typedef void *__timer_t; }


extern "C" { typedef long __blksize_t; }




extern "C" { typedef long __blkcnt_t; }
extern "C" { typedef long __blkcnt64_t; }


extern "C" { typedef unsigned long __fsblkcnt_t; }
extern "C" { typedef unsigned long __fsblkcnt64_t; }


extern "C" { typedef unsigned long __fsfilcnt_t; }
extern "C" { typedef unsigned long __fsfilcnt64_t; }

extern "C" { typedef long __ssize_t; }



extern "C" { typedef __off64_t __loff_t; }
extern "C" { typedef __quad_t *__qaddr_t; }
extern "C" { typedef char *__caddr_t; }


extern "C" { typedef long __intptr_t; }


extern "C" { typedef unsigned __socklen_t; }
# 34 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_char u_char; }
extern "C" { typedef __u_short u_short; }
extern "C" { typedef __u_int u_int; }
extern "C" { typedef __u_long u_long; }
extern "C" { typedef __quad_t quad_t; }
extern "C" { typedef __u_quad_t u_quad_t; }
extern "C" { typedef __fsid_t fsid_t; }




extern "C" { typedef __loff_t loff_t; }



extern "C" { typedef __ino_t ino_t; }
# 56
extern "C" { typedef __ino64_t ino64_t; }




extern "C" { typedef __dev_t dev_t; }




extern "C" { typedef __gid_t gid_t; }




extern "C" { typedef __mode_t mode_t; }




extern "C" { typedef __nlink_t nlink_t; }




extern "C" { typedef __uid_t uid_t; }
# 87
extern "C" { typedef __off_t off_t; }
# 94
extern "C" { typedef __off64_t off64_t; }




extern "C" { typedef __pid_t pid_t; }
# 105
extern "C" { typedef __id_t id_t; }




extern "C" { typedef __ssize_t ssize_t; }
# 116
extern "C" { typedef __daddr_t daddr_t; }
extern "C" { typedef __caddr_t caddr_t; }
# 123
extern "C" { typedef __key_t key_t; }
# 60 "/usr/include/time.h" 3
extern "C" { typedef __clock_t clock_t; }
# 76
extern "C" { typedef __time_t time_t; }
# 92
extern "C" { typedef __clockid_t clockid_t; }
# 104
extern "C" { typedef __timer_t timer_t; }
# 137 "/usr/include/sys/types.h" 3
extern "C" { typedef __useconds_t useconds_t; }



extern "C" { typedef __suseconds_t suseconds_t; }
# 151
extern "C" { typedef unsigned long ulong; }
extern "C" { typedef unsigned short ushort; }
extern "C" { typedef unsigned uint; }
# 195
extern "C" { typedef signed char int8_t __attribute((__mode__(__QI__))); }
extern "C" { typedef short int16_t __attribute((__mode__(__HI__))); }
extern "C" { typedef int int32_t __attribute((__mode__(__SI__))); }
extern "C" { typedef long int64_t __attribute((__mode__(__DI__))); }


extern "C" { typedef unsigned char u_int8_t __attribute((__mode__(__QI__))); }
extern "C" { typedef unsigned short u_int16_t __attribute((__mode__(__HI__))); }
extern "C" { typedef unsigned u_int32_t __attribute((__mode__(__SI__))); }
extern "C" { typedef unsigned long u_int64_t __attribute((__mode__(__DI__))); }

extern "C" { typedef long register_t __attribute((__mode__(__word__))); }
# 24 "/usr/include/bits/sigset.h" 3
extern "C" { typedef int __sig_atomic_t; }
# 32
extern "C" { typedef 
# 30
struct { 
unsigned long __val[(1024) / ((8) * sizeof(unsigned long))]; 
} __sigset_t; }
# 38 "/usr/include/sys/select.h" 3
extern "C" { typedef __sigset_t sigset_t; }
# 120 "/usr/include/time.h" 3
extern "C" { struct timespec { 

__time_t tv_sec; 
long tv_nsec; 
}; }
# 75 "/usr/include/bits/time.h" 3
extern "C" { struct timeval { 

__time_t tv_sec; 
__suseconds_t tv_usec; 
}; }
# 55 "/usr/include/sys/select.h" 3
extern "C" { typedef long __fd_mask; }
# 78
extern "C" { typedef 
# 68
struct { 



__fd_mask fds_bits[1024 / (8 * (int)sizeof(__fd_mask))]; 
# 78
} fd_set; }
# 85
extern "C" { typedef __fd_mask fd_mask; }
# 109
extern "C" int select(int __nfds, fd_set * __readfds, fd_set * __writefds, fd_set * __exceptfds, timeval * __timeout); 
# 121
extern "C" int pselect(int __nfds, fd_set * __readfds, fd_set * __writefds, fd_set * __exceptfds, const timespec * __timeout, const __sigset_t * __sigmask); 
# 31 "/usr/include/sys/sysmacros.h" 3
__extension__ extern "C" unsigned gnu_dev_major(unsigned long long __dev) throw(); 


__extension__ extern "C" unsigned gnu_dev_minor(unsigned long long __dev) throw(); 


__extension__ extern "C" unsigned long long gnu_dev_makedev(unsigned __major, unsigned __minor) throw(); 
# 229 "/usr/include/sys/types.h" 3
extern "C" { typedef __blksize_t blksize_t; }
# 236
extern "C" { typedef __blkcnt_t blkcnt_t; }



extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }



extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 263
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
extern "C" { typedef __fsfilcnt64_t fsfilcnt64_t; }
# 50 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned long pthread_t; }
# 57
extern "C" { typedef 
# 54
union { 
char __size[56]; 
long __align; 
} pthread_attr_t; }
# 65
extern "C" { typedef 
# 61
struct __pthread_internal_list { 

__pthread_internal_list *__prev; 
__pthread_internal_list *__next; 
} __pthread_list_t; }
# 104
extern "C" { typedef 
# 77
union { 
struct __pthread_mutex_s { 

int __lock; 
unsigned __count; 
int __owner; 

unsigned __nusers; 



int __kind; 

int __spins; 
__pthread_list_t __list; 
# 101
} __data; 
char __size[40]; 
long __align; 
} pthread_mutex_t; }
# 110
extern "C" { typedef 
# 107
union { 
char __size[4]; 
int __align; 
} pthread_mutexattr_t; }
# 130
extern "C" { typedef 
# 116
union { 

struct { 
int __lock; 
unsigned __futex; 
__extension__ unsigned long long __total_seq; 
__extension__ unsigned long long __wakeup_seq; 
__extension__ unsigned long long __woken_seq; 
void *__mutex; 
unsigned __nwaiters; 
unsigned __broadcast_seq; 
} __data; 
char __size[48]; 
__extension__ long long __align; 
} pthread_cond_t; }
# 136
extern "C" { typedef 
# 133
union { 
char __size[4]; 
int __align; 
} pthread_condattr_t; }



extern "C" { typedef unsigned pthread_key_t; }



extern "C" { typedef int pthread_once_t; }
# 189
extern "C" { typedef 
# 151
union { 


struct { 
int __lock; 
unsigned __nr_readers; 
unsigned __readers_wakeup; 
unsigned __writer_wakeup; 
unsigned __nr_readers_queued; 
unsigned __nr_writers_queued; 
int __writer; 
int __shared; 
unsigned long __pad1; 
unsigned long __pad2; 


unsigned __flags; 
} __data; 
# 187
char __size[56]; 
long __align; 
} pthread_rwlock_t; }
# 195
extern "C" { typedef 
# 192
union { 
char __size[8]; 
long __align; 
} pthread_rwlockattr_t; }
# 201
extern "C" { typedef volatile int pthread_spinlock_t; }
# 210
extern "C" { typedef 
# 207
union { 
char __size[32]; 
long __align; 
} pthread_barrier_t; }
# 216
extern "C" { typedef 
# 213
union { 
char __size[4]; 
int __align; 
} pthread_barrierattr_t; }
# 327 "/usr/include/stdlib.h" 3
extern "C" long random() throw(); 


extern "C" void srandom(unsigned __seed) throw(); 
# 336
extern "C" char *initstate(unsigned __seed, char * __statebuf, size_t __statelen) throw()
 __attribute((__nonnull__(2))); 



extern "C" char *setstate(char * __statebuf) throw() __attribute((__nonnull__(1))); 
# 349
extern "C" { struct random_data { 

int32_t *fptr; 
int32_t *rptr; 
int32_t *state; 
int rand_type; 
int rand_deg; 
int rand_sep; 
int32_t *end_ptr; 
}; }

extern "C" int random_r(random_data * __buf, int32_t * __result) throw()
 __attribute((__nonnull__(1, 2))); 

extern "C" int srandom_r(unsigned __seed, random_data * __buf) throw()
 __attribute((__nonnull__(2))); 

extern "C" int initstate_r(unsigned __seed, char * __statebuf, size_t __statelen, random_data * __buf) throw()


 __attribute((__nonnull__(2, 4))); 

extern "C" int setstate_r(char * __statebuf, random_data * __buf) throw()

 __attribute((__nonnull__(1, 2))); 
# 380
extern "C" int rand() throw(); 

extern "C" void srand(unsigned __seed) throw(); 




extern "C" int rand_r(unsigned * __seed) throw(); 
# 395
extern "C" double drand48() throw(); 
extern "C" double erand48(unsigned short  __xsubi[3]) throw() __attribute((__nonnull__(1))); 


extern "C" long lrand48() throw(); 
extern "C" long nrand48(unsigned short  __xsubi[3]) throw()
 __attribute((__nonnull__(1))); 


extern "C" long mrand48() throw(); 
extern "C" long jrand48(unsigned short  __xsubi[3]) throw()
 __attribute((__nonnull__(1))); 


extern "C" void srand48(long __seedval) throw(); 
extern "C" unsigned short *seed48(unsigned short  __seed16v[3]) throw()
 __attribute((__nonnull__(1))); 
extern "C" void lcong48(unsigned short  __param[7]) throw() __attribute((__nonnull__(1))); 
# 418
extern "C" { struct drand48_data { 

unsigned short __x[3]; 
unsigned short __old_x[3]; 
unsigned short __c; 
unsigned short __init; 
unsigned long long __a; 
}; }


extern "C" int drand48_r(drand48_data * __buffer, double * __result) throw()
 __attribute((__nonnull__(1, 2))); 
extern "C" int erand48_r(unsigned short  __xsubi[3], drand48_data * __buffer, double * __result) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int lrand48_r(drand48_data * __buffer, long * __result) throw()

 __attribute((__nonnull__(1, 2))); 
extern "C" int nrand48_r(unsigned short  __xsubi[3], drand48_data * __buffer, long * __result) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int mrand48_r(drand48_data * __buffer, long * __result) throw()

 __attribute((__nonnull__(1, 2))); 
extern "C" int jrand48_r(unsigned short  __xsubi[3], drand48_data * __buffer, long * __result) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int srand48_r(long __seedval, drand48_data * __buffer) throw()
 __attribute((__nonnull__(2))); 

extern "C" int seed48_r(unsigned short  __seed16v[3], drand48_data * __buffer) throw()
 __attribute((__nonnull__(1, 2))); 

extern "C" int lcong48_r(unsigned short  __param[7], drand48_data * __buffer) throw()

 __attribute((__nonnull__(1, 2))); 
# 471
extern "C" void *malloc(size_t __size) throw() __attribute((__malloc__)); 

extern "C" void *calloc(size_t __nmemb, size_t __size) throw()
 __attribute((__malloc__)); 
# 485
extern "C" void *realloc(void * __ptr, size_t __size) throw()
 __attribute((__warn_unused_result__)); 

extern "C" void free(void * __ptr) throw(); 




extern "C" void cfree(void * __ptr) throw(); 
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t __size) throw(); 
# 503 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t __size) throw() __attribute((__malloc__)); 




extern "C" int posix_memalign(void ** __memptr, size_t __alignment, size_t __size) throw()
 __attribute((__nonnull__(1))); 




extern "C" void abort() throw() __attribute((__noreturn__)); 



extern "C" int atexit(void (* __func)(void)) throw() __attribute((__nonnull__(1))); 
# 525
int at_quick_exit(void (* __func)(void)) throw() __asm__("at_quick_exit")
 __attribute((__nonnull__(1))); 
# 536
extern "C" int on_exit(void (* __func)(int __status, void * __arg), void * __arg) throw()
 __attribute((__nonnull__(1))); 
# 544
extern "C" void exit(int __status) throw() __attribute((__noreturn__)); 
# 552
extern "C" void quick_exit(int __status) throw() __attribute((__noreturn__)); 
# 560
extern "C" void _Exit(int __status) throw() __attribute((__noreturn__)); 
# 567
extern "C" char *getenv(const char * __name) throw() __attribute((__nonnull__(1))); 




extern "C" char *__secure_getenv(const char * __name) throw()
 __attribute((__nonnull__(1))); 
# 579
extern "C" int putenv(char * __string) throw() __attribute((__nonnull__(1))); 
# 585
extern "C" int setenv(const char * __name, const char * __value, int __replace) throw()
 __attribute((__nonnull__(2))); 


extern "C" int unsetenv(const char * __name) throw() __attribute((__nonnull__(1))); 
# 596
extern "C" int clearenv() throw(); 
# 606
extern "C" char *mktemp(char * __template) throw() __attribute((__nonnull__(1))); 
# 620
extern "C" int mkstemp(char * __template) __attribute((__nonnull__(1))); 
# 630
extern "C" int mkstemp64(char * __template) __attribute((__nonnull__(1))); 
# 642
extern "C" int mkstemps(char * __template, int __suffixlen) __attribute((__nonnull__(1))); 
# 652
extern "C" int mkstemps64(char * __template, int __suffixlen)
 __attribute((__nonnull__(1))); 
# 663
extern "C" char *mkdtemp(char * __template) throw() __attribute((__nonnull__(1))); 
# 674
extern "C" int mkostemp(char * __template, int __flags) __attribute((__nonnull__(1))); 
# 684
extern "C" int mkostemp64(char * __template, int __flags) __attribute((__nonnull__(1))); 
# 694
extern "C" int mkostemps(char * __template, int __suffixlen, int __flags)
 __attribute((__nonnull__(1))); 
# 706
extern "C" int mkostemps64(char * __template, int __suffixlen, int __flags)
 __attribute((__nonnull__(1))); 
# 717
extern "C" int system(const char * __command); 
# 724
extern "C" char *canonicalize_file_name(const char * __name) throw()
 __attribute((__nonnull__(1))); 
# 734
extern "C" char *realpath(const char * __name, char * __resolved) throw(); 
# 742
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }


extern "C" { typedef __compar_fn_t comparison_fn_t; }



extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 755
extern "C" void *bsearch(const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar)

 __attribute((__nonnull__(1, 2, 5))); 



extern "C" void qsort(void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
 __attribute((__nonnull__(1, 4))); 

extern "C" void qsort_r(void * __base, size_t __nmemb, size_t __size, __compar_d_fn_t __compar, void * __arg)

 __attribute((__nonnull__(1, 4))); 




extern "C" int abs(int __x) throw() __attribute((const)); 
extern "C" long labs(long __x) throw() __attribute((const)); 



__extension__ extern "C" long long llabs(long long __x) throw()
 __attribute((const)); 
# 785
extern "C" div_t div(int __numer, int __denom) throw()
 __attribute((const)); 
extern "C" ldiv_t ldiv(long __numer, long __denom) throw()
 __attribute((const)); 




__extension__ extern "C" lldiv_t lldiv(long long __numer, long long __denom) throw()

 __attribute((const)); 
# 808
extern "C" char *ecvt(double __value, int __ndigit, int * __decpt, int * __sign) throw()
 __attribute((__nonnull__(3, 4))); 




extern "C" char *fcvt(double __value, int __ndigit, int * __decpt, int * __sign) throw()
 __attribute((__nonnull__(3, 4))); 




extern "C" char *gcvt(double __value, int __ndigit, char * __buf) throw()
 __attribute((__nonnull__(3))); 




extern "C" char *qecvt(long double __value, int __ndigit, int * __decpt, int * __sign) throw()

 __attribute((__nonnull__(3, 4))); 
extern "C" char *qfcvt(long double __value, int __ndigit, int * __decpt, int * __sign) throw()

 __attribute((__nonnull__(3, 4))); 
extern "C" char *qgcvt(long double __value, int __ndigit, char * __buf) throw()
 __attribute((__nonnull__(3))); 




extern "C" int ecvt_r(double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len) throw()

 __attribute((__nonnull__(3, 4, 5))); 
extern "C" int fcvt_r(double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len) throw()

 __attribute((__nonnull__(3, 4, 5))); 

extern "C" int qecvt_r(long double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len) throw()


 __attribute((__nonnull__(3, 4, 5))); 
extern "C" int qfcvt_r(long double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len) throw()


 __attribute((__nonnull__(3, 4, 5))); 
# 860
extern "C" int mblen(const char * __s, size_t __n) throw(); 


extern "C" int mbtowc(wchar_t * __pwc, const char * __s, size_t __n) throw(); 



extern "C" int wctomb(char * __s, wchar_t __wchar) throw(); 



extern "C" size_t mbstowcs(wchar_t * __pwcs, const char * __s, size_t __n) throw(); 


extern "C" size_t wcstombs(char * __s, const wchar_t * __pwcs, size_t __n) throw(); 
# 885
extern "C" int rpmatch(const char * __response) throw() __attribute((__nonnull__(1))); 
# 896
extern "C" int getsubopt(char ** __optionp, char *const * __tokens, char ** __valuep) throw()


 __attribute((__nonnull__(1, 2, 3))); 
# 905
extern "C" void setkey(const char * __key) throw() __attribute((__nonnull__(1))); 
# 913
extern "C" int posix_openpt(int __oflag); 
# 921
extern "C" int grantpt(int __fd) throw(); 



extern "C" int unlockpt(int __fd) throw(); 




extern "C" char *ptsname(int __fd) throw(); 
# 937
extern "C" int ptsname_r(int __fd, char * __buf, size_t __buflen) throw()
 __attribute((__nonnull__(2))); 


extern "C" int getpt(); 
# 948
extern "C" int getloadavg(double  __loadavg[], int __nelem) throw()
 __attribute((__nonnull__(1))); 
# 55 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/Common.h"
namespace openacci { 


const int acc_async_unknown = (-3); 


const char *get_device_type_string(acc_device_t device_type); 


hmpprt::Target get_target(acc_device_t device_type); 

}
# 31 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/DeviceResident.h"
namespace openacci { 

struct Data; 

class DeviceResident { 


public: DeviceResident(const void *address) : array_desc_addr_((size_t *)address) 

{ } 

size_t getNbDim() { return (array_desc_addr_)[1]; } 

size_t getElemSize() { return (array_desc_addr_)[2]; } 

size_t *getBounds() { return &((array_desc_addr_)[3]); } 

size_t getNumElements(); 

void setHandle(Data *data) { (array_desc_addr_)[17] = (size_t)data; } 

Data *getHandle() { return (Data *)((array_desc_addr_)[17]); } 


void *getInitValuePtr() { return (void *)((array_desc_addr_)[18]); } 

bool isAllocated() { return (array_desc_addr_)[0] != (0); } 
void setAllocated(bool allocated = (true)) 
{ 

(array_desc_addr_)[0] = (size_t)allocated; 
} 


private: size_t *array_desc_addr_; 
}; 
}
# 42 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stringfwd.h" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _Alloc >
    class allocator;

template < class _CharT >
    struct char_traits;

template < typename _CharT, typename _Traits = char_traits < _CharT >,
           typename _Alloc = allocator < _CharT > >
    class basic_string;

template<> struct char_traits< char> ; 

typedef basic_string< char>  string; 


template<> struct char_traits< wchar_t> ; 

typedef basic_string< wchar_t>  wstring; 
# 75
}
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE; 



typedef _IO_FILE FILE; 
# 65
typedef _IO_FILE __FILE; 
# 40 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list; 
# 352 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h" 3
typedef unsigned wint_t; 
# 95 "/usr/include/wchar.h" 3
typedef 
# 84
struct { 
int __count; 

union { 

unsigned __wch; 



char __wchb[4]; 
} __value; 
} __mbstate_t; 
# 106
typedef __mbstate_t mbstate_t; 
# 134
struct tm; 
# 144
extern "C" wchar_t *wcscpy(wchar_t * __dest, const wchar_t * __src) throw(); 


extern "C" wchar_t *wcsncpy(wchar_t * __dest, const wchar_t * __src, size_t __n) throw(); 




extern "C" wchar_t *wcscat(wchar_t * __dest, const wchar_t * __src) throw(); 


extern "C" wchar_t *wcsncat(wchar_t * __dest, const wchar_t * __src, size_t __n) throw(); 




extern "C" int wcscmp(const wchar_t * __s1, const wchar_t * __s2) throw()
 __attribute((__pure__)); 

extern "C" int wcsncmp(const wchar_t * __s1, const wchar_t * __s2, size_t __n) throw()
 __attribute((__pure__)); 




extern "C" int wcscasecmp(const wchar_t * __s1, const wchar_t * __s2) throw(); 


extern "C" int wcsncasecmp(const wchar_t * __s1, const wchar_t * __s2, size_t __n) throw(); 
# 179
extern "C" int wcscasecmp_l(const wchar_t * __s1, const wchar_t * __s2, __locale_t __loc) throw(); 


extern "C" int wcsncasecmp_l(const wchar_t * __s1, const wchar_t * __s2, size_t __n, __locale_t __loc) throw(); 
# 189
extern "C" int wcscoll(const wchar_t * __s1, const wchar_t * __s2) throw(); 



extern "C" size_t wcsxfrm(wchar_t * __s1, const wchar_t * __s2, size_t __n) throw(); 
# 203
extern "C" int wcscoll_l(const wchar_t * __s1, const wchar_t * __s2, __locale_t __loc) throw(); 
# 209
extern "C" size_t wcsxfrm_l(wchar_t * __s1, const wchar_t * __s2, size_t __n, __locale_t __loc) throw(); 



extern "C" wchar_t *wcsdup(const wchar_t * __s) throw() __attribute((__malloc__)); 
# 224
extern "C" wchar_t *wcschr(const wchar_t * __wcs, wchar_t __wc) throw()
 __attribute((__pure__)); 
# 234
extern "C" wchar_t *wcsrchr(const wchar_t * __wcs, wchar_t __wc) throw()
 __attribute((__pure__)); 
# 242
extern "C" wchar_t *wcschrnul(const wchar_t * __s, wchar_t __wc) throw()
 __attribute((__pure__)); 
# 249
extern "C" size_t wcscspn(const wchar_t * __wcs, const wchar_t * __reject) throw()
 __attribute((__pure__)); 


extern "C" size_t wcsspn(const wchar_t * __wcs, const wchar_t * __accept) throw()
 __attribute((__pure__)); 
# 263
extern "C" wchar_t *wcspbrk(const wchar_t * __wcs, const wchar_t * __accept) throw()
 __attribute((__pure__)); 
# 274
extern "C" wchar_t *wcsstr(const wchar_t * __haystack, const wchar_t * __needle) throw()
 __attribute((__pure__)); 



extern "C" wchar_t *wcstok(wchar_t * __s, const wchar_t * __delim, wchar_t ** __ptr) throw(); 




extern "C" size_t wcslen(const wchar_t * __s) throw() __attribute((__pure__)); 
# 296
extern "C" wchar_t *wcswcs(const wchar_t * __haystack, const wchar_t * __needle) throw()
 __attribute((__pure__)); 
# 303
extern "C" size_t wcsnlen(const wchar_t * __s, size_t __maxlen) throw()
 __attribute((__pure__)); 
# 317
extern "C" wchar_t *wmemchr(const wchar_t * __s, wchar_t __c, size_t __n) throw()
 __attribute((__pure__)); 



extern "C" int wmemcmp(const wchar_t * __s1, const wchar_t * __s2, size_t __n) throw()

 __attribute((__pure__)); 


extern "C" wchar_t *wmemcpy(wchar_t * __s1, const wchar_t * __s2, size_t __n) throw(); 




extern "C" wchar_t *wmemmove(wchar_t * __s1, const wchar_t * __s2, size_t __n) throw(); 



extern "C" wchar_t *wmemset(wchar_t * __s, wchar_t __c, size_t __n) throw(); 
# 342
extern "C" wchar_t *wmempcpy(wchar_t * __s1, const wchar_t * __s2, size_t __n) throw(); 
# 351
extern "C" wint_t btowc(int __c) throw(); 



extern "C" int wctob(wint_t __c) throw(); 



extern "C" int mbsinit(const mbstate_t * __ps) throw() __attribute((__pure__)); 



extern "C" size_t mbrtowc(wchar_t * __pwc, const char * __s, size_t __n, mbstate_t * __p) throw(); 




extern "C" size_t wcrtomb(char * __s, wchar_t __wc, mbstate_t * __ps) throw(); 



extern "C" size_t __mbrlen(const char * __s, size_t __n, mbstate_t * __ps) throw(); 

extern "C" size_t mbrlen(const char * __s, size_t __n, mbstate_t * __ps) throw(); 
# 406
extern "C" size_t mbsrtowcs(wchar_t * __dst, const char ** __src, size_t __len, mbstate_t * __ps) throw(); 
# 412
extern "C" size_t wcsrtombs(char * __dst, const wchar_t ** __src, size_t __len, mbstate_t * __ps) throw(); 
# 421
extern "C" size_t mbsnrtowcs(wchar_t * __dst, const char ** __src, size_t __nmc, size_t __len, mbstate_t * __ps) throw(); 
# 427
extern "C" size_t wcsnrtombs(char * __dst, const wchar_t ** __src, size_t __nwc, size_t __len, mbstate_t * __ps) throw(); 
# 437
extern "C" int wcwidth(wchar_t __c) throw(); 



extern "C" int wcswidth(const wchar_t * __s, size_t __n) throw(); 
# 448
extern "C" double wcstod(const wchar_t * __nptr, wchar_t ** __endptr) throw(); 
# 455
extern "C" float wcstof(const wchar_t * __nptr, wchar_t ** __endptr) throw(); 

extern "C" long double wcstold(const wchar_t * __nptr, wchar_t ** __endptr) throw(); 
# 466
extern "C" long wcstol(const wchar_t * __nptr, wchar_t ** __endptr, int __base) throw(); 




extern "C" unsigned long wcstoul(const wchar_t * __nptr, wchar_t ** __endptr, int __base) throw(); 
# 481
__extension__ extern "C" long long wcstoll(const wchar_t * __nptr, wchar_t ** __endptr, int __base) throw(); 
# 488
__extension__ extern "C" unsigned long long wcstoull(const wchar_t * __nptr, wchar_t ** __endptr, int __base) throw(); 
# 498
__extension__ extern "C" long long wcstoq(const wchar_t * __nptr, wchar_t ** __endptr, int __base) throw(); 
# 505
__extension__ extern "C" unsigned long long wcstouq(const wchar_t * __nptr, wchar_t ** __endptr, int __base) throw(); 
# 528
extern "C" long wcstol_l(const wchar_t * __nptr, wchar_t ** __endptr, int __base, __locale_t __loc) throw(); 



extern "C" unsigned long wcstoul_l(const wchar_t * __nptr, wchar_t ** __endptr, int __base, __locale_t __loc) throw(); 




__extension__ extern "C" long long wcstoll_l(const wchar_t * __nptr, wchar_t ** __endptr, int __base, __locale_t __loc) throw(); 




__extension__ extern "C" unsigned long long wcstoull_l(const wchar_t * __nptr, wchar_t ** __endptr, int __base, __locale_t __loc) throw(); 




extern "C" double wcstod_l(const wchar_t * __nptr, wchar_t ** __endptr, __locale_t __loc) throw(); 



extern "C" float wcstof_l(const wchar_t * __nptr, wchar_t ** __endptr, __locale_t __loc) throw(); 



extern "C" long double wcstold_l(const wchar_t * __nptr, wchar_t ** __endptr, __locale_t __loc) throw(); 
# 562
extern "C" wchar_t *wcpcpy(wchar_t * __dest, const wchar_t * __src) throw(); 




extern "C" wchar_t *wcpncpy(wchar_t * __dest, const wchar_t * __src, size_t __n) throw(); 
# 578
extern "C" __FILE *open_wmemstream(wchar_t ** __bufloc, size_t * __sizeloc) throw(); 
# 585
extern "C" int fwide(__FILE * __fp, int __mode) throw(); 
# 592
extern "C" int fwprintf(__FILE * __stream, const wchar_t * __format, ...); 
# 599
extern "C" int wprintf(const wchar_t * __format, ...); 


extern "C" int swprintf(wchar_t * __s, size_t __n, const wchar_t * __format, ...) throw(); 
# 610
extern "C" int vfwprintf(__FILE * __s, const wchar_t * __format, __gnuc_va_list __arg); 
# 618
extern "C" int vwprintf(const wchar_t * __format, __gnuc_va_list __arg); 




extern "C" int vswprintf(wchar_t * __s, size_t __n, const wchar_t * __format, __gnuc_va_list __arg) throw(); 
# 633
extern "C" int fwscanf(__FILE * __stream, const wchar_t * __format, ...); 
# 640
extern "C" int wscanf(const wchar_t * __format, ...); 


extern "C" int swscanf(const wchar_t * __s, const wchar_t * __format, ...) throw(); 
# 687
extern "C" int vfwscanf(__FILE * __s, const wchar_t * __format, __gnuc_va_list __arg); 
# 695
extern "C" int vwscanf(const wchar_t * __format, __gnuc_va_list __arg); 



extern "C" int vswscanf(const wchar_t * __s, const wchar_t * __format, __gnuc_va_list __arg) throw(); 
# 743
extern "C" wint_t fgetwc(__FILE * __stream); 
extern "C" wint_t getwc(__FILE * __stream); 
# 750
extern "C" wint_t getwchar(); 
# 757
extern "C" wint_t fputwc(wchar_t __wc, __FILE * __stream); 
extern "C" wint_t putwc(wchar_t __wc, __FILE * __stream); 
# 764
extern "C" wint_t putwchar(wchar_t __wc); 
# 772
extern "C" wchar_t *fgetws(wchar_t * __ws, int __n, __FILE * __stream); 
# 779
extern "C" int fputws(const wchar_t * __ws, __FILE * __stream); 
# 787
extern "C" wint_t ungetwc(wint_t __wc, __FILE * __stream); 
# 799
extern "C" wint_t getwc_unlocked(__FILE * __stream); 
extern "C" wint_t getwchar_unlocked(); 
# 808
extern "C" wint_t fgetwc_unlocked(__FILE * __stream); 
# 816
extern "C" wint_t fputwc_unlocked(wchar_t __wc, __FILE * __stream); 
# 825
extern "C" wint_t putwc_unlocked(wchar_t __wc, __FILE * __stream); 
extern "C" wint_t putwchar_unlocked(wchar_t __wc); 
# 835
extern "C" wchar_t *fgetws_unlocked(wchar_t * __ws, int __n, __FILE * __stream); 
# 844
extern "C" int fputws_unlocked(const wchar_t * __ws, __FILE * __stream); 
# 853
extern "C" size_t wcsftime(wchar_t * __s, size_t __maxsize, const wchar_t * __format, const tm * __tp) throw(); 
# 863
extern "C" size_t wcsftime_l(wchar_t * __s, size_t __maxsize, const wchar_t * __format, const tm * __tp, __locale_t __loc) throw(); 
# 65 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cwchar" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::mbstate_t;

}
# 139
namespace std __attribute((__visibility__("default" ))) { 

using ::wint_t;

using ::btowc;
using ::fgetwc;
using ::fgetws;
using ::fputwc;
using ::fputws;
using ::fwide;
using ::fwprintf;
using ::fwscanf;
using ::getwc;
using ::getwchar;
using ::mbrlen;
using ::mbrtowc;
using ::mbsinit;
using ::mbsrtowcs;
using ::putwc;
using ::putwchar;
using ::swprintf;
using ::swscanf;
using ::ungetwc;
using ::vfwprintf;

using ::vfwscanf;

using ::vswprintf;

using ::vswscanf;

using ::vwprintf;

using ::vwscanf;

using ::wcrtomb;
using ::wcscat;
using ::wcscmp;
using ::wcscoll;
using ::wcscpy;
using ::wcscspn;
using ::wcsftime;
using ::wcslen;
using ::wcsncat;
using ::wcsncmp;
using ::wcsncpy;
using ::wcsrtombs;
using ::wcsspn;
using ::wcstod;

using ::wcstof;

using ::wcstok;
using ::wcstol;
using ::wcstoul;
using ::wcsxfrm;
using ::wctob;
using ::wmemcmp;
using ::wmemcpy;
using ::wmemmove;
using ::wmemset;
using ::wprintf;
using ::wscanf;
using ::wcschr;
using ::wcspbrk;
using ::wcsrchr;
using ::wcsstr;
using ::wmemchr;



inline wchar_t *wcschr(wchar_t *__p, wchar_t __c) 
{ return wcschr(const_cast< const wchar_t *>(__p), __c); } 


inline wchar_t *wcspbrk(wchar_t *__s1, const wchar_t *__s2) 
{ return wcspbrk(const_cast< const wchar_t *>(__s1), __s2); } 


inline wchar_t *wcsrchr(wchar_t *__p, wchar_t __c) 
{ return wcsrchr(const_cast< const wchar_t *>(__p), __c); } 


inline wchar_t *wcsstr(wchar_t *__s1, const wchar_t *__s2) 
{ return wcsstr(const_cast< const wchar_t *>(__s1), __s2); } 


inline wchar_t *wmemchr(wchar_t *__p, wchar_t __c, size_t __n) 
{ return wmemchr(const_cast< const wchar_t *>(__p), __c, __n); } 


}
# 238
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 245
using ::wcstold;
# 254
using ::wcstoll;
using ::wcstoull;


}

namespace std __attribute((__visibility__("default" ))) { 

using __gnu_cxx::wcstold;
using __gnu_cxx::wcstoll;
using __gnu_cxx::wcstoull;

}
# 70 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/postypes.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 88
typedef long streamoff; 
# 98
typedef ptrdiff_t streamsize; 
# 111
template < typename _StateT >
    class fpos
    {
    private :
      streamoff _M_off;
      _StateT _M_state;

    public :




      fpos ( )
      : _M_off ( 0 ), _M_state ( ) { }








      fpos ( streamoff __off )
      : _M_off ( __off ), _M_state ( ) { }


      operator streamoff ( ) const { return _M_off; }


      void
      state ( _StateT __st )
      { _M_state = __st; }


      _StateT
      state ( ) const
      { return _M_state; }





      fpos &
      operator += ( streamoff __off )
      {
 _M_off += __off;
 return * this;
      }





      fpos &
      operator -= ( streamoff __off )
      {
 _M_off -= __off;
 return * this;
      }







      fpos
      operator + ( streamoff __off ) const
      {
 fpos __pos ( * this );
 __pos += __off;
 return __pos;
      }







      fpos
      operator - ( streamoff __off ) const
      {
 fpos __pos ( * this );
 __pos -= __off;
 return __pos;
      }






      streamoff
      operator - ( const fpos & __other ) const
      { return _M_off - __other . _M_off; }
    };
# 214
template < typename _StateT >
    inline bool
    operator == ( const fpos < _StateT > & __lhs, const fpos < _StateT > & __rhs )
    { return streamoff ( __lhs ) == streamoff ( __rhs ); }

template < typename _StateT >
    inline bool
    operator != ( const fpos < _StateT > & __lhs, const fpos < _StateT > & __rhs )
    { return streamoff ( __lhs ) != streamoff ( __rhs ); }
# 228
typedef fpos< __mbstate_t>  streampos; 

typedef fpos< __mbstate_t>  wstreampos; 
# 239
}
# 52 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/char_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 64
template < typename _CharT >
    struct _Char_types
    {
      typedef unsigned long int_type;
      typedef std :: streampos pos_type;
      typedef std :: streamoff off_type;
      typedef std :: mbstate_t state_type;
    };
# 89
template < typename _CharT >
    struct char_traits
    {
      typedef _CharT char_type;
      typedef typename _Char_types < _CharT > :: int_type int_type;
      typedef typename _Char_types < _CharT > :: pos_type pos_type;
      typedef typename _Char_types < _CharT > :: off_type off_type;
      typedef typename _Char_types < _CharT > :: state_type state_type;

      static void
      assign ( char_type & __c1, const char_type & __c2 )
      { __c1 = __c2; }

      static bool
      eq ( const char_type & __c1, const char_type & __c2 )
      { return __c1 == __c2; }

      static bool
      lt ( const char_type & __c1, const char_type & __c2 )
      { return __c1 < __c2; }

      static int
      compare ( const char_type * __s1, const char_type * __s2, std :: size_t __n );

      static std :: size_t
      length ( const char_type * __s );

      static const char_type *
      find ( const char_type * __s, std :: size_t __n, const char_type & __a );

      static char_type *
      move ( char_type * __s1, const char_type * __s2, std :: size_t __n );

      static char_type *
      copy ( char_type * __s1, const char_type * __s2, std :: size_t __n );

      static char_type *
      assign ( char_type * __s, std :: size_t __n, char_type __a );

      static char_type
      to_char_type ( const int_type & __c )
      { return static_cast < char_type > ( __c ); }

      static int_type
      to_int_type ( const char_type & __c )
      { return static_cast < int_type > ( __c ); }

      static bool
      eq_int_type ( const int_type & __c1, const int_type & __c2 )
      { return __c1 == __c2; }

      static int_type
      eof ( )
      { return static_cast < int_type > ( ( - 1 ) ); }

      static int_type
      not_eof ( const int_type & __c )
      { return ! eq_int_type ( __c, eof ( ) ) ? __c : to_int_type ( char_type ( ) ); }
    };

template < typename _CharT >
    int
    char_traits < _CharT > ::
    compare ( const char_type * __s1, const char_type * __s2, std :: size_t __n )
    {
      for ( std :: size_t __i = 0; __i < __n; ++ __i )
 if ( lt ( __s1 [ __i ], __s2 [ __i ] ) )
   return - 1;
 else if ( lt ( __s2 [ __i ], __s1 [ __i ] ) )
   return 1;
      return 0;
    }

template < typename _CharT >
    std :: size_t
    char_traits < _CharT > ::
    length ( const char_type * __p )
    {
      std :: size_t __i = 0;
      while ( ! eq ( __p [ __i ], char_type ( ) ) )
        ++ __i;
      return __i;
    }

template < typename _CharT >
    const typename char_traits < _CharT > :: char_type *
    char_traits < _CharT > ::
    find ( const char_type * __s, std :: size_t __n, const char_type & __a )
    {
      for ( std :: size_t __i = 0; __i < __n; ++ __i )
        if ( eq ( __s [ __i ], __a ) )
          return __s + __i;
      return 0;
    }

template < typename _CharT >
    typename char_traits < _CharT > :: char_type *
    char_traits < _CharT > ::
    move ( char_type * __s1, const char_type * __s2, std :: size_t __n )
    {
      return static_cast < _CharT * > ( __builtin_memmove ( __s1, __s2,
          __n * sizeof ( char_type ) ) );
    }

template < typename _CharT >
    typename char_traits < _CharT > :: char_type *
    char_traits < _CharT > ::
    copy ( char_type * __s1, const char_type * __s2, std :: size_t __n )
    {

      std :: copy ( __s2, __s2 + __n, __s1 );
      return __s1;
    }

template < typename _CharT >
    typename char_traits < _CharT > :: char_type *
    char_traits < _CharT > ::
    assign ( char_type * __s, std :: size_t __n, char_type __a )
    {

      std :: fill_n ( __s, __n, __a );
      return __s;
    }

}

namespace std __attribute((__visibility__("default" ))) { 
# 230
template < class _CharT >
    struct char_traits : public __gnu_cxx :: char_traits < _CharT >
    { };




template<> struct char_traits< char>  { 

typedef char char_type; 
typedef int int_type; 
typedef streampos pos_type; 
typedef streamoff off_type; 
typedef mbstate_t state_type; 


static void assign(char_type &__c1, const char_type &__c2) 
{ __c1 = __c2; } 


static bool eq(const char_type &__c1, const char_type &__c2) 
{ return __c1 == __c2; } 


static bool lt(const char_type &__c1, const char_type &__c2) 
{ return __c1 < __c2; } 


static int compare(const char_type *__s1, const char_type *__s2, size_t __n) 
{ return __builtin_memcmp(__s1, __s2, __n); } 


static size_t length(const char_type *__s) 
{ return __builtin_strlen(__s); } 


static const char_type *find(const char_type *__s, size_t __n, const char_type &__a) 
{ return static_cast< const char_type *>(__builtin_memchr(__s, __a, __n)); } 


static char_type *move(char_type *__s1, const char_type *__s2, size_t __n) 
{ return static_cast< char_type *>(__builtin_memmove(__s1, __s2, __n)); } 


static char_type *copy(char_type *__s1, const char_type *__s2, size_t __n) 
{ return static_cast< char_type *>(__builtin_memcpy(__s1, __s2, __n)); } 


static char_type *assign(char_type *__s, size_t __n, char_type __a) 
{ return static_cast< char_type *>(__builtin_memset(__s, __a, __n)); } 


static char_type to_char_type(const int_type &__c) 
{ return static_cast< char_type>(__c); } 




static int_type to_int_type(const char_type &__c) 
{ return static_cast< int_type>((static_cast< unsigned char>(__c))); } 


static bool eq_int_type(const int_type &__c1, const int_type &__c2) 
{ return __c1 == __c2; } 


static int_type eof() 
{ return static_cast< int_type>((-1)); } 


static int_type not_eof(const int_type &__c) 
{ return (__c == eof()) ? 0 : __c; } 
}; 
# 308
template<> struct char_traits< wchar_t>  { 

typedef wchar_t char_type; 
typedef wint_t int_type; 
typedef streamoff off_type; 
typedef wstreampos pos_type; 
typedef mbstate_t state_type; 


static void assign(char_type &__c1, const char_type &__c2) 
{ __c1 = __c2; } 


static bool eq(const char_type &__c1, const char_type &__c2) 
{ return __c1 == __c2; } 


static bool lt(const char_type &__c1, const char_type &__c2) 
{ return __c1 < __c2; } 


static int compare(const char_type *__s1, const char_type *__s2, size_t __n) 
{ return wmemcmp(__s1, __s2, __n); } 


static size_t length(const char_type *__s) 
{ return wcslen(__s); } 


static const char_type *find(const char_type *__s, size_t __n, const char_type &__a) 
{ return wmemchr(__s, __a, __n); } 


static char_type *move(char_type *__s1, const char_type *__s2, size_t __n) 
{ return wmemmove(__s1, __s2, __n); } 


static char_type *copy(char_type *__s1, const char_type *__s2, size_t __n) 
{ return wmemcpy(__s1, __s2, __n); } 


static char_type *assign(char_type *__s, size_t __n, char_type __a) 
{ return wmemset(__s, __a, __n); } 


static char_type to_char_type(const int_type &__c) 
{ return (char_type)__c; } 


static int_type to_int_type(const char_type &__c) 
{ return (int_type)__c; } 


static bool eq_int_type(const int_type &__c1, const int_type &__c2) 
{ return __c1 == __c2; } 


static int_type eof() 
{ return static_cast< int_type>(4294967295U); } 


static int_type not_eof(const int_type &__c) 
{ return eq_int_type(__c, eof()) ? (0) : __c; } 
}; 


}
# 28 "/usr/include/bits/locale.h" 3
enum { 
__LC_CTYPE, 
__LC_NUMERIC, 
__LC_TIME, 
__LC_COLLATE, 
__LC_MONETARY, 
__LC_MESSAGES, 
__LC_ALL, 
__LC_PAPER, 
__LC_NAME, 
__LC_ADDRESS, 
__LC_TELEPHONE, 
__LC_MEASUREMENT, 
__LC_IDENTIFICATION
}; 
# 54 "/usr/include/locale.h" 3
extern "C" { struct lconv { 



char *decimal_point; 
char *thousands_sep; 
# 65
char *grouping; 
# 71
char *int_curr_symbol; 
char *currency_symbol; 
char *mon_decimal_point; 
char *mon_thousands_sep; 
char *mon_grouping; 
char *positive_sign; 
char *negative_sign; 
char int_frac_digits; 
char frac_digits; 

char p_cs_precedes; 

char p_sep_by_space; 

char n_cs_precedes; 

char n_sep_by_space; 
# 94
char p_sign_posn; 
char n_sign_posn; 


char int_p_cs_precedes; 

char int_p_sep_by_space; 

char int_n_cs_precedes; 

char int_n_sep_by_space; 
# 111
char int_p_sign_posn; 
char int_n_sign_posn; 
# 121
}; }



extern "C" char *setlocale(int __category, const char * __locale) throw(); 


extern "C" lconv *localeconv() throw(); 
# 152
extern "C" __locale_t newlocale(int __category_mask, const char * __locale, __locale_t __base) throw(); 
# 187
extern "C" __locale_t duplocale(__locale_t __dataset) throw(); 



extern "C" void freelocale(__locale_t __dataset) throw(); 
# 198
extern "C" __locale_t uselocale(__locale_t __dataset) throw(); 
# 53 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/clocale" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::lconv;
using ::setlocale;
using ::localeconv;

}
# 50 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/c++locale.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 

extern "C" __typeof__(uselocale) __uselocale; 

}


namespace std __attribute((__visibility__("default" ))) { 

typedef __locale_t __c_locale; 
# 66
inline int __convert_from_v(const __c_locale &__cloc __attribute((__unused__)), char *
__out, const int 
__size __attribute((__unused__)), const char *
__fmt, ...) 
{ 

__c_locale __old = __gnu_cxx::__uselocale(__cloc); 
# 85
__builtin_va_list __args; 
__builtin_va_start((__args),__fmt); 


const int __ret = __builtin_vsnprintf(__out, __size, __fmt, __args); 




__builtin_va_end(__args); 


__gnu_cxx::__uselocale(__old); 
# 105
return __ret; 
} 

}
# 44 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/iosfwd" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_ios;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_streambuf;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_istream;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_ostream;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_iostream;

template < typename _CharT, typename _Traits = char_traits < _CharT >,
     typename _Alloc = allocator < _CharT > >
    class basic_stringbuf;

template < typename _CharT, typename _Traits = char_traits < _CharT >,
    typename _Alloc = allocator < _CharT > >
    class basic_istringstream;

template < typename _CharT, typename _Traits = char_traits < _CharT >,
    typename _Alloc = allocator < _CharT > >
    class basic_ostringstream;

template < typename _CharT, typename _Traits = char_traits < _CharT >,
    typename _Alloc = allocator < _CharT > >
    class basic_stringstream;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_filebuf;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_ifstream;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_ofstream;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class basic_fstream;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class istreambuf_iterator;

template < typename _CharT, typename _Traits = char_traits < _CharT > >
    class ostreambuf_iterator;



class ios_base; 
# 127
typedef basic_ios< char>  ios; 
typedef basic_streambuf< char>  streambuf; 
typedef basic_istream< char>  istream; 
typedef basic_ostream< char>  ostream; 
typedef basic_iostream< char>  iostream; 
typedef basic_stringbuf< char>  stringbuf; 
typedef basic_istringstream< char>  istringstream; 
typedef basic_ostringstream< char>  ostringstream; 
typedef basic_stringstream< char>  stringstream; 
typedef basic_filebuf< char>  filebuf; 
typedef basic_ifstream< char>  ifstream; 
typedef basic_ofstream< char>  ofstream; 
typedef basic_fstream< char>  fstream; 


typedef basic_ios< wchar_t>  wios; 
typedef basic_streambuf< wchar_t>  wstreambuf; 
typedef basic_istream< wchar_t>  wistream; 
typedef basic_ostream< wchar_t>  wostream; 
typedef basic_iostream< wchar_t>  wiostream; 
typedef basic_stringbuf< wchar_t>  wstringbuf; 
typedef basic_istringstream< wchar_t>  wistringstream; 
typedef basic_ostringstream< wchar_t>  wostringstream; 
typedef basic_stringstream< wchar_t>  wstringstream; 
typedef basic_filebuf< wchar_t>  wfilebuf; 
typedef basic_ifstream< wchar_t>  wifstream; 
typedef basic_ofstream< wchar_t>  wofstream; 
typedef basic_fstream< wchar_t>  wfstream; 



}
# 49 "/usr/include/ctype.h" 3
enum { 
_ISupper = 256, 
_ISlower = 512, 
_ISalpha = 1024, 
_ISdigit = 2048, 
_ISxdigit = 4096, 
_ISspace = 8192, 
_ISprint = 16384, 
_ISgraph = 32768, 
_ISblank = 1, 
_IScntrl, 
_ISpunct = 4, 
_ISalnum = 8
}; 
# 81
extern "C" const unsigned short **__ctype_b_loc() throw()
 __attribute((const)); 
extern "C" const __int32_t **__ctype_tolower_loc() throw()
 __attribute((const)); 
extern "C" const __int32_t **__ctype_toupper_loc() throw()
 __attribute((const)); 
# 102
extern "C" int isalnum(int) throw(); 
extern "C" int isalpha(int) throw(); 
extern "C" int iscntrl(int) throw(); 
extern "C" int isdigit(int) throw(); 
extern "C" int islower(int) throw(); 
extern "C" int isgraph(int) throw(); 
extern "C" int isprint(int) throw(); 
extern "C" int ispunct(int) throw(); 
extern "C" int isspace(int) throw(); 
extern "C" int isupper(int) throw(); 
extern "C" int isxdigit(int) throw(); 



extern "C" int tolower(int __c) throw(); 


extern "C" int toupper(int __c) throw(); 
# 128
extern "C" int isblank(int) throw(); 
# 135
extern "C" int isctype(int __c, int __mask) throw(); 
# 142
extern "C" int isascii(int __c) throw(); 



extern "C" int toascii(int __c) throw(); 



extern "C" int _toupper(int) throw(); 
extern "C" int _tolower(int) throw(); 
# 247
extern "C" int isalnum_l(int, __locale_t) throw(); 
extern "C" int isalpha_l(int, __locale_t) throw(); 
extern "C" int iscntrl_l(int, __locale_t) throw(); 
extern "C" int isdigit_l(int, __locale_t) throw(); 
extern "C" int islower_l(int, __locale_t) throw(); 
extern "C" int isgraph_l(int, __locale_t) throw(); 
extern "C" int isprint_l(int, __locale_t) throw(); 
extern "C" int ispunct_l(int, __locale_t) throw(); 
extern "C" int isspace_l(int, __locale_t) throw(); 
extern "C" int isupper_l(int, __locale_t) throw(); 
extern "C" int isxdigit_l(int, __locale_t) throw(); 

extern "C" int isblank_l(int, __locale_t) throw(); 



extern "C" int __tolower_l(int __c, __locale_t __l) throw(); 
extern "C" int tolower_l(int __c, __locale_t __l) throw(); 


extern "C" int __toupper_l(int __c, __locale_t __l) throw(); 
extern "C" int toupper_l(int __c, __locale_t __l) throw(); 
# 64 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cctype" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::isalnum;
using ::isalpha;
using ::iscntrl;
using ::isdigit;
using ::isgraph;
using ::islower;
using ::isprint;
using ::ispunct;
using ::isspace;
using ::isupper;
using ::isxdigit;
using ::tolower;
using ::toupper;

}
# 46 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/localefwd.h" 3
namespace std __attribute((__visibility__("default" ))) { 


class locale; 

template < typename _Facet >
    bool
    has_facet ( const locale & ) throw ( );

template < typename _Facet >
    const _Facet &
    use_facet ( const locale & );


template < typename _CharT >
    bool
    isspace ( _CharT, const locale & );

template < typename _CharT >
    bool
    isprint ( _CharT, const locale & );

template < typename _CharT >
    bool
    iscntrl ( _CharT, const locale & );

template < typename _CharT >
    bool
    isupper ( _CharT, const locale & );

template < typename _CharT >
    bool
    islower ( _CharT, const locale & );

template < typename _CharT >
    bool
    isalpha ( _CharT, const locale & );

template < typename _CharT >
    bool
    isdigit ( _CharT, const locale & );

template < typename _CharT >
    bool
    ispunct ( _CharT, const locale & );

template < typename _CharT >
    bool
    isxdigit ( _CharT, const locale & );

template < typename _CharT >
    bool
    isalnum ( _CharT, const locale & );

template < typename _CharT >
    bool
    isgraph ( _CharT, const locale & );

template < typename _CharT >
    _CharT
    toupper ( _CharT, const locale & );

template < typename _CharT >
    _CharT
    tolower ( _CharT, const locale & );


struct ctype_base; 
template < typename _CharT >
    class ctype;
template<> class ctype< char> ; 

template<> class ctype< wchar_t> ; 

template < typename _CharT >
    class ctype_byname;


class codecvt_base; 
template < typename _InternT, typename _ExternT, typename _StateT >
    class codecvt;
template<> class codecvt< char, char, __mbstate_t> ; 

template<> class codecvt< wchar_t, char, __mbstate_t> ; 

template < typename _InternT, typename _ExternT, typename _StateT >
    class codecvt_byname;



template < typename _CharT, typename _InIter = istreambuf_iterator < _CharT > >
    class num_get;
template < typename _CharT, typename _OutIter = ostreambuf_iterator < _CharT > >
    class num_put;

template < typename _CharT > class numpunct;
template < typename _CharT > class numpunct_byname;


template < typename _CharT >
    class collate;
template < typename _CharT > class
    collate_byname;


class time_base; 
template < typename _CharT, typename _InIter = istreambuf_iterator < _CharT > >
    class time_get;
template < typename _CharT, typename _InIter = istreambuf_iterator < _CharT > >
    class time_get_byname;
template < typename _CharT, typename _OutIter = ostreambuf_iterator < _CharT > >
    class time_put;
template < typename _CharT, typename _OutIter = ostreambuf_iterator < _CharT > >
    class time_put_byname;


class money_base; 

template < typename _CharT, typename _InIter = istreambuf_iterator < _CharT > >
    class money_get;
template < typename _CharT, typename _OutIter = ostreambuf_iterator < _CharT > >
    class money_put;

template < typename _CharT, bool _Intl = false >
    class moneypunct;
template < typename _CharT, bool _Intl = false >
    class moneypunct_byname;


class messages_base; 
template < typename _CharT >
    class messages;
template < typename _CharT >
    class messages_byname;

}
# 29 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cxxabi-forced.h" 3
#pragma GCC visibility push ( default )


namespace __cxxabiv1 { 
# 41
class __forced_unwind { 

virtual ~__forced_unwind() throw(); 
virtual void __pure_dummy() = 0; 
}; 
}


#pragma GCC visibility pop
# 38 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/ostream_insert.h" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    inline void
    __ostream_write ( basic_ostream < _CharT, _Traits > & __out,
      const _CharT * __s, streamsize __n )
    {
      typedef basic_ostream < _CharT, _Traits > __ostream_type;
      typedef typename __ostream_type :: ios_base __ios_base;

      const streamsize __put = __out . rdbuf ( ) -> sputn ( __s, __n );
      if ( __put != __n )
 __out . setstate ( __ios_base :: badbit );
    }

template < typename _CharT, typename _Traits >
    inline void
    __ostream_fill ( basic_ostream < _CharT, _Traits > & __out, streamsize __n )
    {
      typedef basic_ostream < _CharT, _Traits > __ostream_type;
      typedef typename __ostream_type :: ios_base __ios_base;

      const _CharT __c = __out . fill ( );
      for (; __n > 0; -- __n )
 {
   const typename _Traits :: int_type __put = __out . rdbuf ( ) -> sputc ( __c );
   if ( _Traits :: eq_int_type ( __put, _Traits :: eof ( ) ) )
     {
       __out . setstate ( __ios_base :: badbit );
       break;
     }
 }
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    __ostream_insert ( basic_ostream < _CharT, _Traits > & __out,
       const _CharT * __s, streamsize __n )
    {
      typedef basic_ostream < _CharT, _Traits > __ostream_type;
      typedef typename __ostream_type :: ios_base __ios_base;

      typename __ostream_type :: sentry __cerb ( __out );
      if ( __cerb )
 {
   try
     {
       const streamsize __w = __out . width ( );
       if ( __w > __n )
  {
    const bool __left = ( ( __out . flags ( )
     & __ios_base :: adjustfield )
           == __ios_base :: left );
    if ( ! __left )
      __ostream_fill ( __out, __w - __n );
    if ( __out . good ( ) )
      __ostream_write ( __out, __s, __n );
    if ( __left && __out . good ( ) )
      __ostream_fill ( __out, __w - __n );
  }
       else
  __ostream_write ( __out, __s, __n );
       __out . width ( 0 );
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       __out . _M_setstate ( __ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { __out . _M_setstate ( __ios_base :: badbit ); }
 }
      return __out;
    }
# 117
extern template basic_ostream< char>  &__ostream_insert(basic_ostream< char>  & __out, const char * __s, streamsize __n);


extern template basic_ostream< wchar_t>  &__ostream_insert(basic_ostream< wchar_t>  & __out, const wchar_t * __s, streamsize __n);




}
# 30 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/gthr.h" 3
#pragma GCC visibility push ( default )
# 74 "/usr/include/bits/sched.h" 3
struct sched_param { 

int __sched_priority; 
}; 
# 83
extern "C" int clone(int (* __fn)(void * __arg), void * __child_stack, int __flags, void * __arg, ...) throw(); 



extern "C" int unshare(int __flags) throw(); 


extern "C" int sched_getcpu() throw(); 
# 101
struct __sched_param { 

int __sched_priority; 
}; 
# 116
typedef unsigned long __cpu_mask; 
# 126
typedef 
# 124
struct { 
__cpu_mask __bits[(1024) / ((8) * sizeof(__cpu_mask))]; 
} cpu_set_t; 
# 201
extern "C" int __sched_cpucount(size_t __setsize, const cpu_set_t * __setp) throw(); 

extern "C" cpu_set_t *__sched_cpualloc(size_t __count) throw(); 
extern "C" void __sched_cpufree(cpu_set_t * __set) throw(); 
# 51 "/usr/include/sched.h" 3
extern "C" int sched_setparam(__pid_t __pid, const sched_param * __param) throw(); 



extern "C" int sched_getparam(__pid_t __pid, sched_param * __param) throw(); 


extern "C" int sched_setscheduler(__pid_t __pid, int __policy, const sched_param * __param) throw(); 



extern "C" int sched_getscheduler(__pid_t __pid) throw(); 


extern "C" int sched_yield() throw(); 


extern "C" int sched_get_priority_max(int __algorithm) throw(); 


extern "C" int sched_get_priority_min(int __algorithm) throw(); 


extern "C" int sched_rr_get_interval(__pid_t __pid, timespec * __t) throw(); 
# 118
extern "C" int sched_setaffinity(__pid_t __pid, size_t __cpusetsize, const cpu_set_t * __cpuset) throw(); 



extern "C" int sched_getaffinity(__pid_t __pid, size_t __cpusetsize, cpu_set_t * __cpuset) throw(); 
# 133 "/usr/include/time.h" 3
extern "C" { struct tm { 

int tm_sec; 
int tm_min; 
int tm_hour; 
int tm_mday; 
int tm_mon; 
int tm_year; 
int tm_wday; 
int tm_yday; 
int tm_isdst; 


long tm_gmtoff; 
const char *tm_zone; 




}; }
# 161
extern "C" { struct itimerspec { 

timespec it_interval; 
timespec it_value; 
}; }


struct sigevent; 
# 183
extern "C" clock_t clock() throw(); 


extern "C" time_t time(time_t * __timer) throw(); 


extern "C" double difftime(time_t __time1, time_t __time0) throw()
 __attribute((const)); 


extern "C" time_t mktime(tm * __tp) throw(); 
# 199
extern "C" size_t strftime(char * __s, size_t __maxsize, const char * __format, const tm * __tp) throw(); 
# 207
extern "C" char *strptime(const char * __s, const char * __fmt, tm * __tp) throw(); 
# 217
extern "C" size_t strftime_l(char * __s, size_t __maxsize, const char * __format, const tm * __tp, __locale_t __loc) throw(); 
# 224
extern "C" char *strptime_l(const char * __s, const char * __fmt, tm * __tp, __locale_t __loc) throw(); 
# 233
extern "C" tm *gmtime(const time_t * __timer) throw(); 



extern "C" tm *localtime(const time_t * __timer) throw(); 
# 243
extern "C" tm *gmtime_r(const time_t * __timer, tm * __tp) throw(); 




extern "C" tm *localtime_r(const time_t * __timer, tm * __tp) throw(); 
# 255
extern "C" char *asctime(const tm * __tp) throw(); 


extern "C" char *ctime(const time_t * __timer) throw(); 
# 266
extern "C" char *asctime_r(const tm * __tp, char * __buf) throw(); 



extern "C" char *ctime_r(const time_t * __timer, char * __buf) throw(); 
# 276
extern "C" { extern char *__tzname[2]; } 
extern "C" { extern int __daylight; } 
extern "C" { extern long __timezone; } 




extern "C" { extern char *tzname[2]; } 



extern "C" void tzset() throw(); 



extern "C" { extern int daylight; } 
extern "C" { extern long timezone; } 
# 298
extern "C" int stime(const time_t * __when) throw(); 
# 313
extern "C" time_t timegm(tm * __tp) throw(); 


extern "C" time_t timelocal(tm * __tp) throw(); 


extern "C" int dysize(int __year) throw() __attribute((const)); 
# 328
extern "C" int nanosleep(const timespec * __requested_time, timespec * __remaining); 




extern "C" int clock_getres(clockid_t __clock_id, timespec * __res) throw(); 


extern "C" int clock_gettime(clockid_t __clock_id, timespec * __tp) throw(); 


extern "C" int clock_settime(clockid_t __clock_id, const timespec * __tp) throw(); 
# 347
extern "C" int clock_nanosleep(clockid_t __clock_id, int __flags, const timespec * __req, timespec * __rem); 




extern "C" int clock_getcpuclockid(pid_t __pid, clockid_t * __clock_id) throw(); 




extern "C" int timer_create(clockid_t __clock_id, sigevent * __evp, timer_t * __timerid) throw(); 




extern "C" int timer_delete(timer_t __timerid) throw(); 


extern "C" int timer_settime(timer_t __timerid, int __flags, const itimerspec * __value, itimerspec * __ovalue) throw(); 




extern "C" int timer_gettime(timer_t __timerid, itimerspec * __value) throw(); 



extern "C" int timer_getoverrun(timer_t __timerid) throw(); 
# 390
extern "C" { extern int getdate_err; } 
# 399
extern "C" tm *getdate(const char * __string); 
# 413
extern "C" int getdate_r(const char * __string, tm * __resbufp); 
# 32 "/usr/include/bits/setjmp.h" 3
typedef long __jmp_buf[8]; 
# 35 "/usr/include/pthread.h" 3
enum { 
PTHREAD_CREATE_JOINABLE, 

PTHREAD_CREATE_DETACHED

}; 




enum { 
PTHREAD_MUTEX_TIMED_NP, 
PTHREAD_MUTEX_RECURSIVE_NP, 
PTHREAD_MUTEX_ERRORCHECK_NP, 
PTHREAD_MUTEX_ADAPTIVE_NP, 


PTHREAD_MUTEX_NORMAL = 0, 
PTHREAD_MUTEX_RECURSIVE, 
PTHREAD_MUTEX_ERRORCHECK, 
PTHREAD_MUTEX_DEFAULT = 0, 



PTHREAD_MUTEX_FAST_NP = 0

}; 
# 67
enum { 
PTHREAD_MUTEX_STALLED, 
PTHREAD_MUTEX_STALLED_NP = 0, 
PTHREAD_MUTEX_ROBUST, 
PTHREAD_MUTEX_ROBUST_NP = 1
}; 
# 79
enum { 
PTHREAD_PRIO_NONE, 
PTHREAD_PRIO_INHERIT, 
PTHREAD_PRIO_PROTECT
}; 
# 116
enum { 
PTHREAD_RWLOCK_PREFER_READER_NP, 
PTHREAD_RWLOCK_PREFER_WRITER_NP, 
PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP, 
PTHREAD_RWLOCK_DEFAULT_NP = 0
}; 
# 148
enum { 
PTHREAD_INHERIT_SCHED, 

PTHREAD_EXPLICIT_SCHED

}; 




enum { 
PTHREAD_SCOPE_SYSTEM, 

PTHREAD_SCOPE_PROCESS

}; 




enum { 
PTHREAD_PROCESS_PRIVATE, 

PTHREAD_PROCESS_SHARED

}; 
# 182
struct _pthread_cleanup_buffer { 

void (*__routine)(void *); 
void *__arg; 
int __canceltype; 
_pthread_cleanup_buffer *__prev; 
}; 



enum { 
PTHREAD_CANCEL_ENABLE, 

PTHREAD_CANCEL_DISABLE

}; 

enum { 
PTHREAD_CANCEL_DEFERRED, 

PTHREAD_CANCEL_ASYNCHRONOUS

}; 
# 225
extern "C" int pthread_create(pthread_t * __newthread, const pthread_attr_t * __attr, void *(* __start_routine)(void *), void * __arg) throw()


 __attribute((__nonnull__(1, 3))); 
# 234
extern "C" void pthread_exit(void * __retval) __attribute((__noreturn__)); 
# 242
extern "C" int pthread_join(pthread_t __th, void ** __thread_return); 




extern "C" int pthread_tryjoin_np(pthread_t __th, void ** __thread_return) throw(); 
# 255
extern "C" int pthread_timedjoin_np(pthread_t __th, void ** __thread_return, const timespec * __abstime); 
# 263
extern "C" int pthread_detach(pthread_t __th) throw(); 



extern "C" pthread_t pthread_self() throw() __attribute((const)); 


extern "C" int pthread_equal(pthread_t __thread1, pthread_t __thread2) throw(); 
# 278
extern "C" int pthread_attr_init(pthread_attr_t * __attr) throw() __attribute((__nonnull__(1))); 


extern "C" int pthread_attr_destroy(pthread_attr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_attr_getdetachstate(const pthread_attr_t * __attr, int * __detachstate) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_setdetachstate(pthread_attr_t * __attr, int __detachstate) throw()

 __attribute((__nonnull__(1))); 



extern "C" int pthread_attr_getguardsize(const pthread_attr_t * __attr, size_t * __guardsize) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_setguardsize(pthread_attr_t * __attr, size_t __guardsize) throw()

 __attribute((__nonnull__(1))); 



extern "C" int pthread_attr_getschedparam(const pthread_attr_t * __attr, sched_param * __param) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_setschedparam(pthread_attr_t * __attr, const sched_param * __param) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_getschedpolicy(const pthread_attr_t * __attr, int * __policy) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_setschedpolicy(pthread_attr_t * __attr, int __policy) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_attr_getinheritsched(const pthread_attr_t * __attr, int * __inherit) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_setinheritsched(pthread_attr_t * __attr, int __inherit) throw()

 __attribute((__nonnull__(1))); 



extern "C" int pthread_attr_getscope(const pthread_attr_t * __attr, int * __scope) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_attr_setscope(pthread_attr_t * __attr, int __scope) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_attr_getstackaddr(const pthread_attr_t * __attr, void ** __stackaddr) throw()

 __attribute((__nonnull__(1, 2))) __attribute((__deprecated__)); 
# 355
extern "C" int pthread_attr_setstackaddr(pthread_attr_t * __attr, void * __stackaddr) throw()

 __attribute((__nonnull__(1))) __attribute((__deprecated__)); 


extern "C" int pthread_attr_getstacksize(const pthread_attr_t * __attr, size_t * __stacksize) throw()

 __attribute((__nonnull__(1, 2))); 




extern "C" int pthread_attr_setstacksize(pthread_attr_t * __attr, size_t __stacksize) throw()

 __attribute((__nonnull__(1))); 



extern "C" int pthread_attr_getstack(const pthread_attr_t * __attr, void ** __stackaddr, size_t * __stacksize) throw()


 __attribute((__nonnull__(1, 2, 3))); 




extern "C" int pthread_attr_setstack(pthread_attr_t * __attr, void * __stackaddr, size_t __stacksize) throw()
 __attribute((__nonnull__(1))); 
# 388
extern "C" int pthread_attr_setaffinity_np(pthread_attr_t * __attr, size_t __cpusetsize, const cpu_set_t * __cpuset) throw()


 __attribute((__nonnull__(1, 3))); 



extern "C" int pthread_attr_getaffinity_np(const pthread_attr_t * __attr, size_t __cpusetsize, cpu_set_t * __cpuset) throw()


 __attribute((__nonnull__(1, 3))); 
# 404
extern "C" int pthread_getattr_np(pthread_t __th, pthread_attr_t * __attr) throw()
 __attribute((__nonnull__(2))); 
# 413
extern "C" int pthread_setschedparam(pthread_t __target_thread, int __policy, const sched_param * __param) throw()

 __attribute((__nonnull__(3))); 


extern "C" int pthread_getschedparam(pthread_t __target_thread, int * __policy, sched_param * __param) throw()


 __attribute((__nonnull__(2, 3))); 


extern "C" int pthread_setschedprio(pthread_t __target_thread, int __prio) throw(); 
# 430
extern "C" int pthread_getname_np(pthread_t __target_thread, char * __buf, size_t __buflen) throw()

 __attribute((__nonnull__(2))); 


extern "C" int pthread_setname_np(pthread_t __target_thread, const char * __name) throw()
 __attribute((__nonnull__(2))); 
# 442
extern "C" int pthread_getconcurrency() throw(); 


extern "C" int pthread_setconcurrency(int __level) throw(); 
# 453
extern "C" int pthread_yield() throw(); 




extern "C" int pthread_setaffinity_np(pthread_t __th, size_t __cpusetsize, const cpu_set_t * __cpuset) throw()

 __attribute((__nonnull__(3))); 


extern "C" int pthread_getaffinity_np(pthread_t __th, size_t __cpusetsize, cpu_set_t * __cpuset) throw()

 __attribute((__nonnull__(3))); 
# 478
extern "C" int pthread_once(pthread_once_t * __once_control, void (* __init_routine)(void))
 __attribute((__nonnull__(1, 2))); 
# 490
extern "C" int pthread_setcancelstate(int __state, int * __oldstate); 



extern "C" int pthread_setcanceltype(int __type, int * __oldtype); 


extern "C" int pthread_cancel(pthread_t __th); 




extern "C" void pthread_testcancel(); 
# 515
extern "C" { typedef 
# 508
struct { 

struct { 
__jmp_buf __cancel_jmp_buf; 
int __mask_was_saved; 
} __cancel_jmp_buf[1]; 
void *__pad[4]; 
} __pthread_unwind_buf_t __attribute((__aligned__)); }
# 524
extern "C" { struct __pthread_cleanup_frame { 

void (*__cancel_routine)(void *); 
void *__cancel_arg; 
int __do_it; 
int __cancel_type; 
}; }




extern "C" { class __pthread_cleanup_class { 

void (*__cancel_routine)(void *); 
void *__cancel_arg; 
int __do_it; 
int __cancel_type; 


public: __pthread_cleanup_class(void (*__fct)(void *), void *__arg) : __cancel_routine(__fct), __cancel_arg(__arg), __do_it(1) 
{ } 
~__pthread_cleanup_class() { if (__do_it) { (__cancel_routine)(__cancel_arg); }  } 
void __setdoit(int __newval) { __do_it = __newval; } 
void __defer() { pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &(__cancel_type)); 
} 
void __restore() const { pthread_setcanceltype(__cancel_type, 0); } 
}; }
# 726
struct __jmp_buf_tag; 
extern "C" int __sigsetjmp(__jmp_buf_tag * __env, int __savemask) throw(); 
# 733
extern "C" int pthread_mutex_init(pthread_mutex_t * __mutex, const pthread_mutexattr_t * __mutexattr) throw()

 __attribute((__nonnull__(1))); 


extern "C" int pthread_mutex_destroy(pthread_mutex_t * __mutex) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_mutex_trylock(pthread_mutex_t * __mutex) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_mutex_lock(pthread_mutex_t * __mutex) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_mutex_timedlock(pthread_mutex_t * __mutex, const timespec * __abstime) throw()

 __attribute((__nonnull__(1, 2))); 



extern "C" int pthread_mutex_unlock(pthread_mutex_t * __mutex) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_mutex_getprioceiling(const pthread_mutex_t * __mutex, int * __prioceiling) throw()


 __attribute((__nonnull__(1, 2))); 



extern "C" int pthread_mutex_setprioceiling(pthread_mutex_t * __mutex, int __prioceiling, int * __old_ceiling) throw()


 __attribute((__nonnull__(1, 3))); 




extern "C" int pthread_mutex_consistent(pthread_mutex_t * __mutex) throw()
 __attribute((__nonnull__(1))); 

extern "C" int pthread_mutex_consistent_np(pthread_mutex_t * __mutex) throw()
 __attribute((__nonnull__(1))); 
# 790
extern "C" int pthread_mutexattr_init(pthread_mutexattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_mutexattr_destroy(pthread_mutexattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_mutexattr_getpshared(const pthread_mutexattr_t * __attr, int * __pshared) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_mutexattr_setpshared(pthread_mutexattr_t * __attr, int __pshared) throw()

 __attribute((__nonnull__(1))); 



extern "C" int pthread_mutexattr_gettype(const pthread_mutexattr_t * __attr, int * __kind) throw()

 __attribute((__nonnull__(1, 2))); 




extern "C" int pthread_mutexattr_settype(pthread_mutexattr_t * __attr, int __kind) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_mutexattr_getprotocol(const pthread_mutexattr_t * __attr, int * __protocol) throw()


 __attribute((__nonnull__(1, 2))); 



extern "C" int pthread_mutexattr_setprotocol(pthread_mutexattr_t * __attr, int __protocol) throw()

 __attribute((__nonnull__(1))); 


extern "C" int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t * __attr, int * __prioceiling) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_mutexattr_setprioceiling(pthread_mutexattr_t * __attr, int __prioceiling) throw()

 __attribute((__nonnull__(1))); 



extern "C" int pthread_mutexattr_getrobust(const pthread_mutexattr_t * __attr, int * __robustness) throw()

 __attribute((__nonnull__(1, 2))); 

extern "C" int pthread_mutexattr_getrobust_np(const pthread_mutexattr_t * __attr, int * __robustness) throw()

 __attribute((__nonnull__(1, 2))); 



extern "C" int pthread_mutexattr_setrobust(pthread_mutexattr_t * __attr, int __robustness) throw()

 __attribute((__nonnull__(1))); 

extern "C" int pthread_mutexattr_setrobust_np(pthread_mutexattr_t * __attr, int __robustness) throw()

 __attribute((__nonnull__(1))); 
# 872
extern "C" int pthread_rwlock_init(pthread_rwlock_t * __rwlock, const pthread_rwlockattr_t * __attr) throw()

 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlock_destroy(pthread_rwlock_t * __rwlock) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlock_rdlock(pthread_rwlock_t * __rwlock) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlock_tryrdlock(pthread_rwlock_t * __rwlock) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_rwlock_timedrdlock(pthread_rwlock_t * __rwlock, const timespec * __abstime) throw()

 __attribute((__nonnull__(1, 2))); 



extern "C" int pthread_rwlock_wrlock(pthread_rwlock_t * __rwlock) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlock_trywrlock(pthread_rwlock_t * __rwlock) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_rwlock_timedwrlock(pthread_rwlock_t * __rwlock, const timespec * __abstime) throw()

 __attribute((__nonnull__(1, 2))); 



extern "C" int pthread_rwlock_unlock(pthread_rwlock_t * __rwlock) throw()
 __attribute((__nonnull__(1))); 
# 918
extern "C" int pthread_rwlockattr_init(pthread_rwlockattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlockattr_destroy(pthread_rwlockattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t * __attr, int * __pshared) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_rwlockattr_setpshared(pthread_rwlockattr_t * __attr, int __pshared) throw()

 __attribute((__nonnull__(1))); 


extern "C" int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t * __attr, int * __pref) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t * __attr, int __pref) throw()
 __attribute((__nonnull__(1))); 
# 952
extern "C" int pthread_cond_init(pthread_cond_t * __cond, const pthread_condattr_t * __cond_attr) throw()

 __attribute((__nonnull__(1))); 


extern "C" int pthread_cond_destroy(pthread_cond_t * __cond) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_cond_signal(pthread_cond_t * __cond) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_cond_broadcast(pthread_cond_t * __cond) throw()
 __attribute((__nonnull__(1))); 
# 973
extern "C" int pthread_cond_wait(pthread_cond_t * __cond, pthread_mutex_t * __mutex)

 __attribute((__nonnull__(1, 2))); 
# 984
extern "C" int pthread_cond_timedwait(pthread_cond_t * __cond, pthread_mutex_t * __mutex, const timespec * __abstime)


 __attribute((__nonnull__(1, 2, 3))); 




extern "C" int pthread_condattr_init(pthread_condattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_condattr_destroy(pthread_condattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_condattr_getpshared(const pthread_condattr_t * __attr, int * __pshared) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_condattr_setpshared(pthread_condattr_t * __attr, int __pshared) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_condattr_getclock(const pthread_condattr_t * __attr, __clockid_t * __clock_id) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_condattr_setclock(pthread_condattr_t * __attr, __clockid_t __clock_id) throw()

 __attribute((__nonnull__(1))); 
# 1028
extern "C" int pthread_spin_init(pthread_spinlock_t * __lock, int __pshared) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_spin_destroy(pthread_spinlock_t * __lock) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_spin_lock(pthread_spinlock_t * __lock) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_spin_trylock(pthread_spinlock_t * __lock) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_spin_unlock(pthread_spinlock_t * __lock) throw()
 __attribute((__nonnull__(1))); 
# 1052
extern "C" int pthread_barrier_init(pthread_barrier_t * __barrier, const pthread_barrierattr_t * __attr, unsigned __count) throw()


 __attribute((__nonnull__(1))); 


extern "C" int pthread_barrier_destroy(pthread_barrier_t * __barrier) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_barrier_wait(pthread_barrier_t * __barrier) throw()
 __attribute((__nonnull__(1))); 



extern "C" int pthread_barrierattr_init(pthread_barrierattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_barrierattr_destroy(pthread_barrierattr_t * __attr) throw()
 __attribute((__nonnull__(1))); 


extern "C" int pthread_barrierattr_getpshared(const pthread_barrierattr_t * __attr, int * __pshared) throw()


 __attribute((__nonnull__(1, 2))); 


extern "C" int pthread_barrierattr_setpshared(pthread_barrierattr_t * __attr, int __pshared) throw()

 __attribute((__nonnull__(1))); 
# 1095
extern "C" int pthread_key_create(pthread_key_t * __key, void (* __destr_function)(void *)) throw()

 __attribute((__nonnull__(1))); 


extern "C" int pthread_key_delete(pthread_key_t __key) throw(); 


extern "C" void *pthread_getspecific(pthread_key_t __key) throw(); 


extern "C" int pthread_setspecific(pthread_key_t __key, const void * __pointer) throw(); 
# 1112
extern "C" int pthread_getcpuclockid(pthread_t __thread_id, __clockid_t * __clock_id) throw()

 __attribute((__nonnull__(2))); 
# 1129
extern "C" int pthread_atfork(void (* __prepare)(void), void (* __parent)(void), void (* __child)(void)) throw(); 
# 268 "/usr/include/unistd.h" 3
extern "C" { typedef __intptr_t intptr_t; }
# 275
extern "C" { typedef __socklen_t socklen_t; }
# 288
extern "C" int access(const char * __name, int __type) throw() __attribute((__nonnull__(1))); 




extern "C" int euidaccess(const char * __name, int __type) throw()
 __attribute((__nonnull__(1))); 


extern "C" int eaccess(const char * __name, int __type) throw()
 __attribute((__nonnull__(1))); 
# 305
extern "C" int faccessat(int __fd, const char * __file, int __type, int __flag) throw()
 __attribute((__nonnull__(2))); 
# 331
extern "C" __off_t lseek(int __fd, __off_t __offset, int __whence) throw(); 
# 342
extern "C" __off64_t lseek64(int __fd, __off64_t __offset, int __whence) throw(); 
# 350
extern "C" int close(int __fd); 
# 357
extern "C" ssize_t read(int __fd, void * __buf, size_t __nbytes); 
# 363
extern "C" ssize_t write(int __fd, const void * __buf, size_t __n); 
# 373
extern "C" ssize_t pread(int __fd, void * __buf, size_t __nbytes, __off_t __offset); 
# 381
extern "C" ssize_t pwrite(int __fd, const void * __buf, size_t __n, __off_t __offset); 
# 401
extern "C" ssize_t pread64(int __fd, void * __buf, size_t __nbytes, __off64_t __offset); 



extern "C" ssize_t pwrite64(int __fd, const void * __buf, size_t __n, __off64_t __offset); 
# 414
extern "C" int pipe(int  __pipedes[2]) throw(); 




extern "C" int pipe2(int  __pipedes[2], int __flags) throw(); 
# 429
extern "C" unsigned alarm(unsigned __seconds) throw(); 
# 441
extern "C" unsigned sleep(unsigned __seconds); 
# 449
extern "C" __useconds_t ualarm(__useconds_t __value, __useconds_t __interval) throw(); 
# 457
extern "C" int usleep(__useconds_t __useconds); 
# 466
extern "C" int pause(); 



extern "C" int chown(const char * __file, __uid_t __owner, __gid_t __group) throw()
 __attribute((__nonnull__(1))); 



extern "C" int fchown(int __fd, __uid_t __owner, __gid_t __group) throw(); 




extern "C" int lchown(const char * __file, __uid_t __owner, __gid_t __group) throw()
 __attribute((__nonnull__(1))); 
# 488
extern "C" int fchownat(int __fd, const char * __file, __uid_t __owner, __gid_t __group, int __flag) throw()

 __attribute((__nonnull__(2))); 



extern "C" int chdir(const char * __path) throw() __attribute((__nonnull__(1))); 



extern "C" int fchdir(int __fd) throw(); 
# 508
extern "C" char *getcwd(char * __buf, size_t __size) throw(); 
# 514
extern "C" char *get_current_dir_name() throw(); 
# 522
extern "C" char *getwd(char * __buf) throw()
 __attribute((__nonnull__(1))) __attribute((__deprecated__)); 




extern "C" int dup(int __fd) throw(); 


extern "C" int dup2(int __fd, int __fd2) throw(); 




extern "C" int dup3(int __fd, int __fd2, int __flags) throw(); 



extern "C" { extern char **__environ; } 

extern "C" { extern char **environ; } 
# 548
extern "C" int execve(const char * __path, char *const  __argv[], char *const  __envp[]) throw()
 __attribute((__nonnull__(1, 2))); 




extern "C" int fexecve(int __fd, char *const  __argv[], char *const  __envp[]) throw()
 __attribute((__nonnull__(2))); 




extern "C" int execv(const char * __path, char *const  __argv[]) throw()
 __attribute((__nonnull__(1, 2))); 



extern "C" int execle(const char * __path, const char * __arg, ...) throw()
 __attribute((__nonnull__(1, 2))); 



extern "C" int execl(const char * __path, const char * __arg, ...) throw()
 __attribute((__nonnull__(1, 2))); 



extern "C" int execvp(const char * __file, char *const  __argv[]) throw()
 __attribute((__nonnull__(1, 2))); 




extern "C" int execlp(const char * __file, const char * __arg, ...) throw()
 __attribute((__nonnull__(1, 2))); 




extern "C" int execvpe(const char * __file, char *const  __argv[], char *const  __envp[]) throw()

 __attribute((__nonnull__(1, 2))); 
# 595
extern "C" int nice(int __inc) throw(); 




extern "C" void _exit(int __status) __attribute((__noreturn__)); 
# 27 "/usr/include/bits/confname.h" 3
enum { 
_PC_LINK_MAX, 

_PC_MAX_CANON, 

_PC_MAX_INPUT, 

_PC_NAME_MAX, 

_PC_PATH_MAX, 

_PC_PIPE_BUF, 

_PC_CHOWN_RESTRICTED, 

_PC_NO_TRUNC, 

_PC_VDISABLE, 

_PC_SYNC_IO, 

_PC_ASYNC_IO, 

_PC_PRIO_IO, 

_PC_SOCK_MAXBUF, 

_PC_FILESIZEBITS, 

_PC_REC_INCR_XFER_SIZE, 

_PC_REC_MAX_XFER_SIZE, 

_PC_REC_MIN_XFER_SIZE, 

_PC_REC_XFER_ALIGN, 

_PC_ALLOC_SIZE_MIN, 

_PC_SYMLINK_MAX, 

_PC_2_SYMLINKS

}; 



enum { 
_SC_ARG_MAX, 

_SC_CHILD_MAX, 

_SC_CLK_TCK, 

_SC_NGROUPS_MAX, 

_SC_OPEN_MAX, 

_SC_STREAM_MAX, 

_SC_TZNAME_MAX, 

_SC_JOB_CONTROL, 

_SC_SAVED_IDS, 

_SC_REALTIME_SIGNALS, 

_SC_PRIORITY_SCHEDULING, 

_SC_TIMERS, 

_SC_ASYNCHRONOUS_IO, 

_SC_PRIORITIZED_IO, 

_SC_SYNCHRONIZED_IO, 

_SC_FSYNC, 

_SC_MAPPED_FILES, 

_SC_MEMLOCK, 

_SC_MEMLOCK_RANGE, 

_SC_MEMORY_PROTECTION, 

_SC_MESSAGE_PASSING, 

_SC_SEMAPHORES, 

_SC_SHARED_MEMORY_OBJECTS, 

_SC_AIO_LISTIO_MAX, 

_SC_AIO_MAX, 

_SC_AIO_PRIO_DELTA_MAX, 

_SC_DELAYTIMER_MAX, 

_SC_MQ_OPEN_MAX, 

_SC_MQ_PRIO_MAX, 

_SC_VERSION, 

_SC_PAGESIZE, 


_SC_RTSIG_MAX, 

_SC_SEM_NSEMS_MAX, 

_SC_SEM_VALUE_MAX, 

_SC_SIGQUEUE_MAX, 

_SC_TIMER_MAX, 




_SC_BC_BASE_MAX, 

_SC_BC_DIM_MAX, 

_SC_BC_SCALE_MAX, 

_SC_BC_STRING_MAX, 

_SC_COLL_WEIGHTS_MAX, 

_SC_EQUIV_CLASS_MAX, 

_SC_EXPR_NEST_MAX, 

_SC_LINE_MAX, 

_SC_RE_DUP_MAX, 

_SC_CHARCLASS_NAME_MAX, 


_SC_2_VERSION, 

_SC_2_C_BIND, 

_SC_2_C_DEV, 

_SC_2_FORT_DEV, 

_SC_2_FORT_RUN, 

_SC_2_SW_DEV, 

_SC_2_LOCALEDEF, 


_SC_PII, 

_SC_PII_XTI, 

_SC_PII_SOCKET, 

_SC_PII_INTERNET, 

_SC_PII_OSI, 

_SC_POLL, 

_SC_SELECT, 

_SC_UIO_MAXIOV, 

_SC_IOV_MAX = 60, 

_SC_PII_INTERNET_STREAM, 

_SC_PII_INTERNET_DGRAM, 

_SC_PII_OSI_COTS, 

_SC_PII_OSI_CLTS, 

_SC_PII_OSI_M, 

_SC_T_IOV_MAX, 



_SC_THREADS, 

_SC_THREAD_SAFE_FUNCTIONS, 

_SC_GETGR_R_SIZE_MAX, 

_SC_GETPW_R_SIZE_MAX, 

_SC_LOGIN_NAME_MAX, 

_SC_TTY_NAME_MAX, 

_SC_THREAD_DESTRUCTOR_ITERATIONS, 

_SC_THREAD_KEYS_MAX, 

_SC_THREAD_STACK_MIN, 

_SC_THREAD_THREADS_MAX, 

_SC_THREAD_ATTR_STACKADDR, 

_SC_THREAD_ATTR_STACKSIZE, 

_SC_THREAD_PRIORITY_SCHEDULING, 

_SC_THREAD_PRIO_INHERIT, 

_SC_THREAD_PRIO_PROTECT, 

_SC_THREAD_PROCESS_SHARED, 


_SC_NPROCESSORS_CONF, 

_SC_NPROCESSORS_ONLN, 

_SC_PHYS_PAGES, 

_SC_AVPHYS_PAGES, 

_SC_ATEXIT_MAX, 

_SC_PASS_MAX, 


_SC_XOPEN_VERSION, 

_SC_XOPEN_XCU_VERSION, 

_SC_XOPEN_UNIX, 

_SC_XOPEN_CRYPT, 

_SC_XOPEN_ENH_I18N, 

_SC_XOPEN_SHM, 


_SC_2_CHAR_TERM, 

_SC_2_C_VERSION, 

_SC_2_UPE, 


_SC_XOPEN_XPG2, 

_SC_XOPEN_XPG3, 

_SC_XOPEN_XPG4, 


_SC_CHAR_BIT, 

_SC_CHAR_MAX, 

_SC_CHAR_MIN, 

_SC_INT_MAX, 

_SC_INT_MIN, 

_SC_LONG_BIT, 

_SC_WORD_BIT, 

_SC_MB_LEN_MAX, 

_SC_NZERO, 

_SC_SSIZE_MAX, 

_SC_SCHAR_MAX, 

_SC_SCHAR_MIN, 

_SC_SHRT_MAX, 

_SC_SHRT_MIN, 

_SC_UCHAR_MAX, 

_SC_UINT_MAX, 

_SC_ULONG_MAX, 

_SC_USHRT_MAX, 


_SC_NL_ARGMAX, 

_SC_NL_LANGMAX, 

_SC_NL_MSGMAX, 

_SC_NL_NMAX, 

_SC_NL_SETMAX, 

_SC_NL_TEXTMAX, 


_SC_XBS5_ILP32_OFF32, 

_SC_XBS5_ILP32_OFFBIG, 

_SC_XBS5_LP64_OFF64, 

_SC_XBS5_LPBIG_OFFBIG, 


_SC_XOPEN_LEGACY, 

_SC_XOPEN_REALTIME, 

_SC_XOPEN_REALTIME_THREADS, 


_SC_ADVISORY_INFO, 

_SC_BARRIERS, 

_SC_BASE, 

_SC_C_LANG_SUPPORT, 

_SC_C_LANG_SUPPORT_R, 

_SC_CLOCK_SELECTION, 

_SC_CPUTIME, 

_SC_THREAD_CPUTIME, 

_SC_DEVICE_IO, 

_SC_DEVICE_SPECIFIC, 

_SC_DEVICE_SPECIFIC_R, 

_SC_FD_MGMT, 

_SC_FIFO, 

_SC_PIPE, 

_SC_FILE_ATTRIBUTES, 

_SC_FILE_LOCKING, 

_SC_FILE_SYSTEM, 

_SC_MONOTONIC_CLOCK, 

_SC_MULTI_PROCESS, 

_SC_SINGLE_PROCESS, 

_SC_NETWORKING, 

_SC_READER_WRITER_LOCKS, 

_SC_SPIN_LOCKS, 

_SC_REGEXP, 

_SC_REGEX_VERSION, 

_SC_SHELL, 

_SC_SIGNALS, 

_SC_SPAWN, 

_SC_SPORADIC_SERVER, 

_SC_THREAD_SPORADIC_SERVER, 

_SC_SYSTEM_DATABASE, 

_SC_SYSTEM_DATABASE_R, 

_SC_TIMEOUTS, 

_SC_TYPED_MEMORY_OBJECTS, 

_SC_USER_GROUPS, 

_SC_USER_GROUPS_R, 

_SC_2_PBS, 

_SC_2_PBS_ACCOUNTING, 

_SC_2_PBS_LOCATE, 

_SC_2_PBS_MESSAGE, 

_SC_2_PBS_TRACK, 

_SC_SYMLOOP_MAX, 

_SC_STREAMS, 

_SC_2_PBS_CHECKPOINT, 


_SC_V6_ILP32_OFF32, 

_SC_V6_ILP32_OFFBIG, 

_SC_V6_LP64_OFF64, 

_SC_V6_LPBIG_OFFBIG, 


_SC_HOST_NAME_MAX, 

_SC_TRACE, 

_SC_TRACE_EVENT_FILTER, 

_SC_TRACE_INHERIT, 

_SC_TRACE_LOG, 


_SC_LEVEL1_ICACHE_SIZE, 

_SC_LEVEL1_ICACHE_ASSOC, 

_SC_LEVEL1_ICACHE_LINESIZE, 

_SC_LEVEL1_DCACHE_SIZE, 

_SC_LEVEL1_DCACHE_ASSOC, 

_SC_LEVEL1_DCACHE_LINESIZE, 

_SC_LEVEL2_CACHE_SIZE, 

_SC_LEVEL2_CACHE_ASSOC, 

_SC_LEVEL2_CACHE_LINESIZE, 

_SC_LEVEL3_CACHE_SIZE, 

_SC_LEVEL3_CACHE_ASSOC, 

_SC_LEVEL3_CACHE_LINESIZE, 

_SC_LEVEL4_CACHE_SIZE, 

_SC_LEVEL4_CACHE_ASSOC, 

_SC_LEVEL4_CACHE_LINESIZE, 



_SC_IPV6 = 235, 

_SC_RAW_SOCKETS, 


_SC_V7_ILP32_OFF32, 

_SC_V7_ILP32_OFFBIG, 

_SC_V7_LP64_OFF64, 

_SC_V7_LPBIG_OFFBIG, 


_SC_SS_REPL_MAX, 


_SC_TRACE_EVENT_NAME_MAX, 

_SC_TRACE_NAME_MAX, 

_SC_TRACE_SYS_MAX, 

_SC_TRACE_USER_EVENT_MAX, 


_SC_XOPEN_STREAMS, 


_SC_THREAD_ROBUST_PRIO_INHERIT, 

_SC_THREAD_ROBUST_PRIO_PROTECT

}; 



enum { 
_CS_PATH, 


_CS_V6_WIDTH_RESTRICTED_ENVS, 



_CS_GNU_LIBC_VERSION, 

_CS_GNU_LIBPTHREAD_VERSION, 


_CS_V5_WIDTH_RESTRICTED_ENVS, 



_CS_V7_WIDTH_RESTRICTED_ENVS, 



_CS_LFS_CFLAGS = 1000, 

_CS_LFS_LDFLAGS, 

_CS_LFS_LIBS, 

_CS_LFS_LINTFLAGS, 

_CS_LFS64_CFLAGS, 

_CS_LFS64_LDFLAGS, 

_CS_LFS64_LIBS, 

_CS_LFS64_LINTFLAGS, 


_CS_XBS5_ILP32_OFF32_CFLAGS = 1100, 

_CS_XBS5_ILP32_OFF32_LDFLAGS, 

_CS_XBS5_ILP32_OFF32_LIBS, 

_CS_XBS5_ILP32_OFF32_LINTFLAGS, 

_CS_XBS5_ILP32_OFFBIG_CFLAGS, 

_CS_XBS5_ILP32_OFFBIG_LDFLAGS, 

_CS_XBS5_ILP32_OFFBIG_LIBS, 

_CS_XBS5_ILP32_OFFBIG_LINTFLAGS, 

_CS_XBS5_LP64_OFF64_CFLAGS, 

_CS_XBS5_LP64_OFF64_LDFLAGS, 

_CS_XBS5_LP64_OFF64_LIBS, 

_CS_XBS5_LP64_OFF64_LINTFLAGS, 

_CS_XBS5_LPBIG_OFFBIG_CFLAGS, 

_CS_XBS5_LPBIG_OFFBIG_LDFLAGS, 

_CS_XBS5_LPBIG_OFFBIG_LIBS, 

_CS_XBS5_LPBIG_OFFBIG_LINTFLAGS, 


_CS_POSIX_V6_ILP32_OFF32_CFLAGS, 

_CS_POSIX_V6_ILP32_OFF32_LDFLAGS, 

_CS_POSIX_V6_ILP32_OFF32_LIBS, 

_CS_POSIX_V6_ILP32_OFF32_LINTFLAGS, 

_CS_POSIX_V6_ILP32_OFFBIG_CFLAGS, 

_CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS, 

_CS_POSIX_V6_ILP32_OFFBIG_LIBS, 

_CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS, 

_CS_POSIX_V6_LP64_OFF64_CFLAGS, 

_CS_POSIX_V6_LP64_OFF64_LDFLAGS, 

_CS_POSIX_V6_LP64_OFF64_LIBS, 

_CS_POSIX_V6_LP64_OFF64_LINTFLAGS, 

_CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS, 

_CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS, 

_CS_POSIX_V6_LPBIG_OFFBIG_LIBS, 

_CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS, 


_CS_POSIX_V7_ILP32_OFF32_CFLAGS, 

_CS_POSIX_V7_ILP32_OFF32_LDFLAGS, 

_CS_POSIX_V7_ILP32_OFF32_LIBS, 

_CS_POSIX_V7_ILP32_OFF32_LINTFLAGS, 

_CS_POSIX_V7_ILP32_OFFBIG_CFLAGS, 

_CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS, 

_CS_POSIX_V7_ILP32_OFFBIG_LIBS, 

_CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS, 

_CS_POSIX_V7_LP64_OFF64_CFLAGS, 

_CS_POSIX_V7_LP64_OFF64_LDFLAGS, 

_CS_POSIX_V7_LP64_OFF64_LIBS, 

_CS_POSIX_V7_LP64_OFF64_LINTFLAGS, 

_CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS, 

_CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS, 

_CS_POSIX_V7_LPBIG_OFFBIG_LIBS, 

_CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS, 


_CS_V6_ENV, 

_CS_V7_ENV

}; 
# 609 "/usr/include/unistd.h" 3
extern "C" long pathconf(const char * __path, int __name) throw()
 __attribute((__nonnull__(1))); 


extern "C" long fpathconf(int __fd, int __name) throw(); 


extern "C" long sysconf(int __name) throw(); 



extern "C" size_t confstr(int __name, char * __buf, size_t __len) throw(); 




extern "C" __pid_t getpid() throw(); 


extern "C" __pid_t getppid() throw(); 




extern "C" __pid_t getpgrp() throw(); 
# 643
extern "C" __pid_t __getpgid(__pid_t __pid) throw(); 

extern "C" __pid_t getpgid(__pid_t __pid) throw(); 
# 652
extern "C" int setpgid(__pid_t __pid, __pid_t __pgid) throw(); 
# 669
extern "C" int setpgrp() throw(); 
# 686
extern "C" __pid_t setsid() throw(); 



extern "C" __pid_t getsid(__pid_t __pid) throw(); 



extern "C" __uid_t getuid() throw(); 


extern "C" __uid_t geteuid() throw(); 


extern "C" __gid_t getgid() throw(); 


extern "C" __gid_t getegid() throw(); 




extern "C" int getgroups(int __size, __gid_t  __list[]) throw(); 



extern "C" int group_member(__gid_t __gid) throw(); 
# 719
extern "C" int setuid(__uid_t __uid) throw(); 




extern "C" int setreuid(__uid_t __ruid, __uid_t __euid) throw(); 




extern "C" int seteuid(__uid_t __uid) throw(); 
# 736
extern "C" int setgid(__gid_t __gid) throw(); 




extern "C" int setregid(__gid_t __rgid, __gid_t __egid) throw(); 




extern "C" int setegid(__gid_t __gid) throw(); 
# 752
extern "C" int getresuid(__uid_t * __ruid, __uid_t * __euid, __uid_t * __suid) throw(); 




extern "C" int getresgid(__gid_t * __rgid, __gid_t * __egid, __gid_t * __sgid) throw(); 




extern "C" int setresuid(__uid_t __ruid, __uid_t __euid, __uid_t __suid) throw(); 




extern "C" int setresgid(__gid_t __rgid, __gid_t __egid, __gid_t __sgid) throw(); 
# 775
extern "C" __pid_t fork() throw(); 
# 783
extern "C" __pid_t vfork() throw(); 
# 789
extern "C" char *ttyname(int __fd) throw(); 



extern "C" int ttyname_r(int __fd, char * __buf, size_t __buflen) throw()
 __attribute((__nonnull__(2))); 



extern "C" int isatty(int __fd) throw(); 
# 804
extern "C" int ttyslot() throw(); 




extern "C" int link(const char * __from, const char * __to) throw()
 __attribute((__nonnull__(1, 2))); 




extern "C" int linkat(int __fromfd, const char * __from, int __tofd, const char * __to, int __flags) throw()

 __attribute((__nonnull__(2, 4))); 




extern "C" int symlink(const char * __from, const char * __to) throw()
 __attribute((__nonnull__(1, 2))); 




extern "C" ssize_t readlink(const char * __path, char * __buf, size_t __len) throw()

 __attribute((__nonnull__(1, 2))); 




extern "C" int symlinkat(const char * __from, int __tofd, const char * __to) throw()
 __attribute((__nonnull__(1, 3))); 


extern "C" ssize_t readlinkat(int __fd, const char * __path, char * __buf, size_t __len) throw()

 __attribute((__nonnull__(2, 3))); 



extern "C" int unlink(const char * __name) throw() __attribute((__nonnull__(1))); 



extern "C" int unlinkat(int __fd, const char * __name, int __flag) throw()
 __attribute((__nonnull__(2))); 



extern "C" int rmdir(const char * __path) throw() __attribute((__nonnull__(1))); 



extern "C" __pid_t tcgetpgrp(int __fd) throw(); 


extern "C" int tcsetpgrp(int __fd, __pid_t __pgrp_id) throw(); 
# 868
extern "C" char *getlogin(); 
# 876
extern "C" int getlogin_r(char * __name, size_t __name_len) __attribute((__nonnull__(1))); 




extern "C" int setlogin(const char * __name) throw() __attribute((__nonnull__(1))); 
# 59 "/usr/include/getopt.h" 3
extern "C" { extern char *optarg; } 
# 73
extern "C" { extern int optind; } 




extern "C" { extern int opterr; } 



extern "C" { extern int optopt; } 
# 152
extern "C" int getopt(int ___argc, char *const * ___argv, const char * __shortopts) throw(); 
# 898 "/usr/include/unistd.h" 3
extern "C" int gethostname(char * __name, size_t __len) throw() __attribute((__nonnull__(1))); 
# 905
extern "C" int sethostname(const char * __name, size_t __len) throw()
 __attribute((__nonnull__(1))); 



extern "C" int sethostid(long __id) throw(); 
# 916
extern "C" int getdomainname(char * __name, size_t __len) throw()
 __attribute((__nonnull__(1))); 
extern "C" int setdomainname(const char * __name, size_t __len) throw()
 __attribute((__nonnull__(1))); 
# 925
extern "C" int vhangup() throw(); 


extern "C" int revoke(const char * __file) throw() __attribute((__nonnull__(1))); 
# 936
extern "C" int profil(unsigned short * __sample_buffer, size_t __size, size_t __offset, unsigned __scale) throw()

 __attribute((__nonnull__(1))); 
# 944
extern "C" int acct(const char * __name) throw(); 



extern "C" char *getusershell() throw(); 
extern "C" void endusershell() throw(); 
extern "C" void setusershell() throw(); 
# 956
extern "C" int daemon(int __nochdir, int __noclose) throw(); 
# 963
extern "C" int chroot(const char * __path) throw() __attribute((__nonnull__(1))); 



extern "C" char *getpass(const char * __prompt) __attribute((__nonnull__(1))); 
# 976
extern "C" int fsync(int __fd); 
# 983
extern "C" long gethostid(); 


extern "C" void sync() throw(); 
# 992
extern "C" int getpagesize() throw() __attribute((const)); 




extern "C" int getdtablesize() throw(); 
# 1007
extern "C" int truncate(const char * __file, __off_t __length) throw()
 __attribute((__nonnull__(1))); 
# 1019
extern "C" int truncate64(const char * __file, __off64_t __length) throw()
 __attribute((__nonnull__(1))); 
# 1026
extern "C" int ftruncate(int __fd, __off_t __length) throw(); 
# 1036
extern "C" int ftruncate64(int __fd, __off64_t __length) throw(); 
# 1047
extern "C" int brk(void * __addr) throw(); 
# 1053
extern "C" void *sbrk(intptr_t __delta) throw(); 
# 1068
extern "C" long syscall(long __sysno, ...) throw(); 
# 1091
extern "C" int lockf(int __fd, int __cmd, __off_t __len); 
# 1101
extern "C" int lockf64(int __fd, int __cmd, __off64_t __len); 
# 1122
extern "C" int fdatasync(int __fildes); 
# 1130
extern "C" char *crypt(const char * __key, const char * __salt) throw()
 __attribute((__nonnull__(1, 2))); 



extern "C" void encrypt(char * __block, int __edflag) throw() __attribute((__nonnull__(1))); 
# 1142
extern "C" void swab(const void * __from, void * __to, ssize_t __n) throw()
 __attribute((__nonnull__(1, 2))); 
# 1151
extern "C" char *ctermid(char * __s) throw(); 
# 44 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/gthr-default.h" 3
typedef pthread_t __gthread_t; 
typedef pthread_key_t __gthread_key_t; 
typedef pthread_once_t __gthread_once_t; 
typedef pthread_mutex_t __gthread_mutex_t; 
typedef pthread_mutex_t __gthread_recursive_mutex_t; 
typedef pthread_cond_t __gthread_cond_t; 
typedef timespec __gthread_time_t; 
# 118
static __typeof__(pthread_once) __gthrw_pthread_once __attribute((__weakref__("pthread_once"))); 
static __typeof__(pthread_getspecific) __gthrw_pthread_getspecific __attribute((__weakref__("pthread_getspecific"))); 
static __typeof__(pthread_setspecific) __gthrw_pthread_setspecific __attribute((__weakref__("pthread_setspecific"))); 

static __typeof__(pthread_create) __gthrw_pthread_create __attribute((__weakref__("pthread_create"))); 
static __typeof__(pthread_join) __gthrw_pthread_join __attribute((__weakref__("pthread_join"))); 
static __typeof__(pthread_equal) __gthrw_pthread_equal __attribute((__weakref__("pthread_equal"))); 
static __typeof__(pthread_self) __gthrw_pthread_self __attribute((__weakref__("pthread_self"))); 
static __typeof__(pthread_detach) __gthrw_pthread_detach __attribute((__weakref__("pthread_detach"))); 
static __typeof__(pthread_cancel) __gthrw_pthread_cancel __attribute((__weakref__("pthread_cancel"))); 
static __typeof__(sched_yield) __gthrw_sched_yield __attribute((__weakref__("sched_yield"))); 

static __typeof__(pthread_mutex_lock) __gthrw_pthread_mutex_lock __attribute((__weakref__("pthread_mutex_lock"))); 
static __typeof__(pthread_mutex_trylock) __gthrw_pthread_mutex_trylock __attribute((__weakref__("pthread_mutex_trylock"))); 


static __typeof__(pthread_mutex_timedlock) __gthrw_pthread_mutex_timedlock __attribute((__weakref__("pthread_mutex_timedlock"))); 


static __typeof__(pthread_mutex_unlock) __gthrw_pthread_mutex_unlock __attribute((__weakref__("pthread_mutex_unlock"))); 
static __typeof__(pthread_mutex_init) __gthrw_pthread_mutex_init __attribute((__weakref__("pthread_mutex_init"))); 
static __typeof__(pthread_mutex_destroy) __gthrw_pthread_mutex_destroy __attribute((__weakref__("pthread_mutex_destroy"))); 

static __typeof__(pthread_cond_broadcast) __gthrw_pthread_cond_broadcast __attribute((__weakref__("pthread_cond_broadcast"))); 
static __typeof__(pthread_cond_signal) __gthrw_pthread_cond_signal __attribute((__weakref__("pthread_cond_signal"))); 
static __typeof__(pthread_cond_wait) __gthrw_pthread_cond_wait __attribute((__weakref__("pthread_cond_wait"))); 
static __typeof__(pthread_cond_timedwait) __gthrw_pthread_cond_timedwait __attribute((__weakref__("pthread_cond_timedwait"))); 
static __typeof__(pthread_cond_destroy) __gthrw_pthread_cond_destroy __attribute((__weakref__("pthread_cond_destroy"))); 


static __typeof__(pthread_key_create) __gthrw_pthread_key_create __attribute((__weakref__("pthread_key_create"))); 
static __typeof__(pthread_key_delete) __gthrw_pthread_key_delete __attribute((__weakref__("pthread_key_delete"))); 
static __typeof__(pthread_mutexattr_init) __gthrw_pthread_mutexattr_init __attribute((__weakref__("pthread_mutexattr_init"))); 
static __typeof__(pthread_mutexattr_settype) __gthrw_pthread_mutexattr_settype __attribute((__weakref__("pthread_mutexattr_settype"))); 
static __typeof__(pthread_mutexattr_destroy) __gthrw_pthread_mutexattr_destroy __attribute((__weakref__("pthread_mutexattr_destroy"))); 
# 238
static inline int __gthread_active_p() 
{ 
static void *const __gthread_active_ptr = __extension__ ((void *)(&__gthrw_pthread_cancel)); 

return __gthread_active_ptr != (0); 
} 
# 649
static inline int __gthread_create(__gthread_t *__threadid, void *(*__func)(void *), void *
__args) 
{ 
return __gthrw_pthread_create(__threadid, __null, __func, __args); 
} 


static inline int __gthread_join(__gthread_t __threadid, void **__value_ptr) 
{ 
return __gthrw_pthread_join(__threadid, __value_ptr); 
} 


static inline int __gthread_detach(__gthread_t __threadid) 
{ 
return __gthrw_pthread_detach(__threadid); 
} 


static inline int __gthread_equal(__gthread_t __t1, __gthread_t __t2) 
{ 
return __gthrw_pthread_equal(__t1, __t2); 
} 


static inline __gthread_t __gthread_self() 
{ 
return __gthrw_pthread_self(); 
} 


static inline int __gthread_yield() 
{ 
return __gthrw_sched_yield(); 
} 


static inline int __gthread_once(__gthread_once_t *__once, void (*__func)(void)) 
{ 
if (__gthread_active_p()) { 
return __gthrw_pthread_once(__once, __func); } else { 

return -1; }  
} 


static inline int __gthread_key_create(__gthread_key_t *__key, void (*__dtor)(void *)) 
{ 
return __gthrw_pthread_key_create(__key, __dtor); 
} 


static inline int __gthread_key_delete(__gthread_key_t __key) 
{ 
return __gthrw_pthread_key_delete(__key); 
} 


static inline void *__gthread_getspecific(__gthread_key_t __key) 
{ 
return __gthrw_pthread_getspecific(__key); 
} 


static inline int __gthread_setspecific(__gthread_key_t __key, const void *__ptr) 
{ 
return __gthrw_pthread_setspecific(__key, __ptr); 
} 


static inline int __gthread_mutex_destroy(__gthread_mutex_t *__mutex) 
{ 
if (__gthread_active_p()) { 
return __gthrw_pthread_mutex_destroy(__mutex); } else { 

return 0; }  
} 


static inline int __gthread_mutex_lock(__gthread_mutex_t *__mutex) 
{ 
if (__gthread_active_p()) { 
return __gthrw_pthread_mutex_lock(__mutex); } else { 

return 0; }  
} 


static inline int __gthread_mutex_trylock(__gthread_mutex_t *__mutex) 
{ 
if (__gthread_active_p()) { 
return __gthrw_pthread_mutex_trylock(__mutex); } else { 

return 0; }  
} 




static inline int __gthread_mutex_timedlock(__gthread_mutex_t *__mutex, const __gthread_time_t *
__abs_timeout) 
{ 
if (__gthread_active_p()) { 
return __gthrw_pthread_mutex_timedlock(__mutex, __abs_timeout); } else { 

return 0; }  
} 




static inline int __gthread_mutex_unlock(__gthread_mutex_t *__mutex) 
{ 
if (__gthread_active_p()) { 
return __gthrw_pthread_mutex_unlock(__mutex); } else { 

return 0; }  
} 
# 792
static inline int __gthread_recursive_mutex_lock(__gthread_recursive_mutex_t *__mutex) 
{ 
return __gthread_mutex_lock(__mutex); 
} 


static inline int __gthread_recursive_mutex_trylock(__gthread_recursive_mutex_t *__mutex) 
{ 
return __gthread_mutex_trylock(__mutex); 
} 




static inline int __gthread_recursive_mutex_timedlock(__gthread_recursive_mutex_t *__mutex, const __gthread_time_t *
__abs_timeout) 
{ 
return __gthread_mutex_timedlock(__mutex, __abs_timeout); 
} 




static inline int __gthread_recursive_mutex_unlock(__gthread_recursive_mutex_t *__mutex) 
{ 
return __gthread_mutex_unlock(__mutex); 
} 


static inline int __gthread_cond_broadcast(__gthread_cond_t *__cond) 
{ 
return __gthrw_pthread_cond_broadcast(__cond); 
} 


static inline int __gthread_cond_signal(__gthread_cond_t *__cond) 
{ 
return __gthrw_pthread_cond_signal(__cond); 
} 


static inline int __gthread_cond_wait(__gthread_cond_t *__cond, __gthread_mutex_t *__mutex) 
{ 
return __gthrw_pthread_cond_wait(__cond, __mutex); 
} 


static inline int __gthread_cond_timedwait(__gthread_cond_t *__cond, __gthread_mutex_t *__mutex, const __gthread_time_t *
__abs_timeout) 
{ 
return __gthrw_pthread_cond_timedwait(__cond, __mutex, __abs_timeout); 
} 


static inline int __gthread_cond_wait_recursive(__gthread_cond_t *__cond, __gthread_recursive_mutex_t *
__mutex) 
{ 
return __gthread_cond_wait(__cond, __mutex); 
} 


static inline int __gthread_cond_timedwait_recursive(__gthread_cond_t *__cond, __gthread_recursive_mutex_t *
__mutex, const __gthread_time_t *
__abs_timeout) 
{ 
return __gthread_cond_timedwait(__cond, __mutex, __abs_timeout); 
} 


static inline int __gthread_cond_destroy(__gthread_cond_t *__cond) 
{ 
return __gthrw_pthread_cond_destroy(__cond); 
} 
# 170 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/gthr.h" 3
#pragma GCC visibility pop
# 32 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/atomic_word.h" 3
typedef int _Atomic_word; 
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/ext/atomicity.h" 3
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 45
static inline _Atomic_word __exchange_and_add(volatile _Atomic_word *__mem, int __val) 
{ return __sync_fetch_and_add_4(__mem, __val); } 


static inline void __atomic_add(volatile _Atomic_word *__mem, int __val) 
{ __sync_fetch_and_add_4(__mem, __val); } 
# 62
static inline _Atomic_word __exchange_and_add_single(_Atomic_word *__mem, int __val) 
{ 
_Atomic_word __result = *__mem; 
*__mem += __val; 
return __result; 
} 


static inline void __atomic_add_single(_Atomic_word *__mem, int __val) 
{ *__mem += __val; } 


__attribute((__unused__)) static inline _Atomic_word 
__exchange_and_add_dispatch(_Atomic_word *__mem, int __val) 
{ 

if (__gthread_active_p()) { 
return __exchange_and_add(__mem, __val); } else { 

return __exchange_and_add_single(__mem, __val); }  



} 


__attribute((__unused__)) static inline void 
__atomic_add_dispatch(_Atomic_word *__mem, int __val) 
{ 

if (__gthread_active_p()) { 
__atomic_add(__mem, __val); } else { 

__atomic_add_single(__mem, __val); }  



} 

}
# 45 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_string.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 103
template < typename _CharT, typename _Traits, typename _Alloc >
    class basic_string
    {
      typedef typename _Alloc :: template rebind < _CharT > :: other _CharT_alloc_type;


    public :
      typedef _Traits traits_type;
      typedef typename _Traits :: char_type value_type;
      typedef _Alloc allocator_type;
      typedef typename _CharT_alloc_type :: size_type size_type;
      typedef typename _CharT_alloc_type :: difference_type difference_type;
      typedef typename _CharT_alloc_type :: reference reference;
      typedef typename _CharT_alloc_type :: const_reference const_reference;
      typedef typename _CharT_alloc_type :: pointer pointer;
      typedef typename _CharT_alloc_type :: const_pointer const_pointer;
      typedef __gnu_cxx :: __normal_iterator < pointer, basic_string > iterator;
      typedef __gnu_cxx :: __normal_iterator < const_pointer, basic_string >
                                                            const_iterator;
      typedef std :: reverse_iterator < const_iterator > const_reverse_iterator;
      typedef std :: reverse_iterator < iterator > reverse_iterator;

    private :














      struct _Rep_base
      {
 size_type _M_length;
 size_type _M_capacity;
 _Atomic_word _M_refcount;
      };

      struct _Rep : _Rep_base
      {

 typedef typename _Alloc :: template rebind < char > :: other _Raw_bytes_alloc;














 static const size_type _S_max_size;
 static const _CharT _S_terminal;



        static size_type _S_empty_rep_storage [ ];

        static _Rep &
        _S_empty_rep ( )
        {



   void * __p = reinterpret_cast < void * > ( & _S_empty_rep_storage );
   return * reinterpret_cast < _Rep * > ( __p );
 }

        bool
 _M_is_leaked ( ) const
        { return this -> _M_refcount < 0; }

        bool
 _M_is_shared ( ) const
        { return this -> _M_refcount > 0; }

        void
 _M_set_leaked ( )
        { this -> _M_refcount = - 1; }

        void
 _M_set_sharable ( )
        { this -> _M_refcount = 0; }

 void
 _M_set_length_and_sharable ( size_type __n )
 {

   if ( __builtin_expect ( this != & _S_empty_rep ( ), false ) )

     {
       this -> _M_set_sharable ( );
       this -> _M_length = __n;
       traits_type :: assign ( this -> _M_refdata ( ) [ __n ], _S_terminal );


     }
 }

 _CharT *
 _M_refdata ( ) throw ( )
 { return reinterpret_cast < _CharT * > ( this + 1 ); }

 _CharT *
 _M_grab ( const _Alloc & __alloc1, const _Alloc & __alloc2 )
 {
   return ( ! _M_is_leaked ( ) && __alloc1 == __alloc2 )
           ? _M_refcopy ( ) : _M_clone ( __alloc1 );
 }


 static _Rep *
 _S_create ( size_type, size_type, const _Alloc & );

 void
 _M_dispose ( const _Alloc & __a )
 {

   if ( __builtin_expect ( this != & _S_empty_rep ( ), false ) )

     if ( __gnu_cxx :: __exchange_and_add_dispatch ( & this -> _M_refcount,
             - 1 ) <= 0 )
       _M_destroy ( __a );
 }

 void
 _M_destroy ( const _Alloc & ) throw ( );

 _CharT *
 _M_refcopy ( ) throw ( )
 {

   if ( __builtin_expect ( this != & _S_empty_rep ( ), false ) )

            __gnu_cxx :: __atomic_add_dispatch ( & this -> _M_refcount, 1 );
   return _M_refdata ( );
 }

 _CharT *
 _M_clone ( const _Alloc &, size_type __res = 0 );
      };


      struct _Alloc_hider : _Alloc
      {
 _Alloc_hider ( _CharT * __dat, const _Alloc & __a )
 : _Alloc ( __a ), _M_p ( __dat ) { }

 _CharT * _M_p;
      };

    public :




      static const size_type npos = static_cast < size_type > ( - 1 );

    private :

      mutable _Alloc_hider _M_dataplus;

      _CharT *
      _M_data ( ) const
      { return _M_dataplus . _M_p; }

      _CharT *
      _M_data ( _CharT * __p )
      { return ( _M_dataplus . _M_p = __p ); }

      _Rep *
      _M_rep ( ) const
      { return & ( ( reinterpret_cast < _Rep * > ( _M_data ( ) ) ) [ - 1 ] ); }



      iterator
      _M_ibegin ( ) const
      { return iterator ( _M_data ( ) ); }

      iterator
      _M_iend ( ) const
      { return iterator ( _M_data ( ) + this -> size ( ) ); }

      void
      _M_leak ( )
      {
 if ( ! _M_rep ( ) -> _M_is_leaked ( ) )
   _M_leak_hard ( );
      }

      size_type
      _M_check ( size_type __pos, const char * __s ) const
      {
 if ( __pos > this -> size ( ) )
   __throw_out_of_range ( ( __s ) );
 return __pos;
      }

      void
      _M_check_length ( size_type __n1, size_type __n2, const char * __s ) const
      {
 if ( this -> max_size ( ) - ( this -> size ( ) - __n1 ) < __n2 )
   __throw_length_error ( ( __s ) );
      }


      size_type
      _M_limit ( size_type __pos, size_type __off ) const
      {
 const bool __testoff = __off < this -> size ( ) - __pos;
 return __testoff ? __off : this -> size ( ) - __pos;
      }


      bool
      _M_disjunct ( const _CharT * __s ) const
      {
 return ( less < const _CharT * > ( ) ( __s, _M_data ( ) )
  || less < const _CharT * > ( ) ( _M_data ( ) + this -> size ( ), __s ) );
      }



      static void
      _M_copy ( _CharT * __d, const _CharT * __s, size_type __n )
      {
 if ( __n == 1 )
   traits_type :: assign ( * __d, * __s );
 else
   traits_type :: copy ( __d, __s, __n );
      }

      static void
      _M_move ( _CharT * __d, const _CharT * __s, size_type __n )
      {
 if ( __n == 1 )
   traits_type :: assign ( * __d, * __s );
 else
   traits_type :: move ( __d, __s, __n );
      }

      static void
      _M_assign ( _CharT * __d, size_type __n, _CharT __c )
      {
 if ( __n == 1 )
   traits_type :: assign ( * __d, __c );
 else
   traits_type :: assign ( __d, __n, __c );
      }



      template < class _Iterator >
        static void
        _S_copy_chars ( _CharT * __p, _Iterator __k1, _Iterator __k2 )
        {
   for (; __k1 != __k2; ++ __k1, ++ __p )
     traits_type :: assign ( * __p, * __k1 );
 }

      static void
      _S_copy_chars ( _CharT * __p, iterator __k1, iterator __k2 )
      { _S_copy_chars ( __p, __k1 . base ( ), __k2 . base ( ) ); }

      static void
      _S_copy_chars ( _CharT * __p, const_iterator __k1, const_iterator __k2 )
      { _S_copy_chars ( __p, __k1 . base ( ), __k2 . base ( ) ); }

      static void
      _S_copy_chars ( _CharT * __p, _CharT * __k1, _CharT * __k2 )
      { _M_copy ( __p, __k1, __k2 - __k1 ); }

      static void
      _S_copy_chars ( _CharT * __p, const _CharT * __k1, const _CharT * __k2 )
      { _M_copy ( __p, __k1, __k2 - __k1 ); }

      static int
      _S_compare ( size_type __n1, size_type __n2 )
      {
 const difference_type __d = difference_type ( __n1 - __n2 );

 if ( __d > __gnu_cxx :: __numeric_traits < int > :: __max )
   return __gnu_cxx :: __numeric_traits < int > :: __max;
 else if ( __d < __gnu_cxx :: __numeric_traits < int > :: __min )
   return __gnu_cxx :: __numeric_traits < int > :: __min;
 else
   return int ( __d );
      }

      void
      _M_mutate ( size_type __pos, size_type __len1, size_type __len2 );

      void
      _M_leak_hard ( );

      static _Rep &
      _S_empty_rep ( )
      { return _Rep :: _S_empty_rep ( ); }

    public :







      inline
      basic_string ( );




      explicit
      basic_string ( const _Alloc & __a );






      basic_string ( const basic_string & __str );






      basic_string ( const basic_string & __str, size_type __pos,
     size_type __n = npos );







      basic_string ( const basic_string & __str, size_type __pos,
     size_type __n, const _Alloc & __a );










      basic_string ( const _CharT * __s, size_type __n,
     const _Alloc & __a = _Alloc ( ) );





      basic_string ( const _CharT * __s, const _Alloc & __a = _Alloc ( ) );






      basic_string ( size_type __n, _CharT __c, const _Alloc & __a = _Alloc ( ) );
















      template < class _InputIterator >
        basic_string ( _InputIterator __beg, _InputIterator __end,
       const _Alloc & __a = _Alloc ( ) );




      ~ basic_string ( )
      { _M_rep ( ) -> _M_dispose ( this -> get_allocator ( ) ); }





      basic_string &
      operator = ( const basic_string & __str )
      { return this -> assign ( __str ); }





      basic_string &
      operator = ( const _CharT * __s )
      { return this -> assign ( __s ); }








      basic_string &
      operator = ( _CharT __c )
      {
 this -> assign ( 1, __c );
 return * this;
      }



















      iterator
      begin ( )
      {
 _M_leak ( );
 return iterator ( _M_data ( ) );
      }





      const_iterator
      begin ( ) const
      { return const_iterator ( _M_data ( ) ); }





      iterator
      end ( )
      {
 _M_leak ( );
 return iterator ( _M_data ( ) + this -> size ( ) );
      }





      const_iterator
      end ( ) const
      { return const_iterator ( _M_data ( ) + this -> size ( ) ); }






      reverse_iterator
      rbegin ( )
      { return reverse_iterator ( this -> end ( ) ); }






      const_reverse_iterator
      rbegin ( ) const
      { return const_reverse_iterator ( this -> end ( ) ); }






      reverse_iterator
      rend ( )
      { return reverse_iterator ( this -> begin ( ) ); }






      const_reverse_iterator
      rend ( ) const
      { return const_reverse_iterator ( this -> begin ( ) ); }

    public :



      size_type
      size ( ) const
      { return _M_rep ( ) -> _M_length; }



      size_type
      length ( ) const
      { return _M_rep ( ) -> _M_length; }


      size_type
      max_size ( ) const
      { return _Rep :: _S_max_size; }











      void
      resize ( size_type __n, _CharT __c );











      void
      resize ( size_type __n )
      { this -> resize ( __n, _CharT ( ) ); }





      size_type
      capacity ( ) const
      { return _M_rep ( ) -> _M_capacity; }


















      void
      reserve ( size_type __res_arg = 0 );




      void
      clear ( )
      { _M_mutate ( 0, this -> size ( ), 0 ); }




      bool
      empty ( ) const
      { return this -> size ( ) == 0; }












      const_reference
      operator [ ] ( size_type __pos ) const
      {
                                       ;
 return _M_data ( ) [ __pos ];
      }











      reference
      operator [ ] ( size_type __pos )
      {

                                       ;

                                         ;
 _M_leak ( );
 return _M_data ( ) [ __pos ];
      }











      const_reference
      at ( size_type __n ) const
      {
 if ( __n >= this -> size ( ) )
   __throw_out_of_range ( ( "basic_string::at" ) );
 return _M_data ( ) [ __n ];
      }












      reference
      at ( size_type __n )
      {
 if ( __n >= size ( ) )
   __throw_out_of_range ( ( "basic_string::at" ) );
 _M_leak ( );
 return _M_data ( ) [ __n ];
      }







      basic_string &
      operator += ( const basic_string & __str )
      { return this -> append ( __str ); }






      basic_string &
      operator += ( const _CharT * __s )
      { return this -> append ( __s ); }






      basic_string &
      operator += ( _CharT __c )
      {
 this -> push_back ( __c );
 return * this;
      }

















      basic_string &
      append ( const basic_string & __str );













      basic_string &
      append ( const basic_string & __str, size_type __pos, size_type __n );







      basic_string &
      append ( const _CharT * __s, size_type __n );






      basic_string &
      append ( const _CharT * __s )
      {
                               ;
 return this -> append ( __s, traits_type :: length ( __s ) );
      }









      basic_string &
      append ( size_type __n, _CharT __c );




















      template < class _InputIterator >
        basic_string &
        append ( _InputIterator __first, _InputIterator __last )
        { return this -> replace ( _M_iend ( ), _M_iend ( ), __first, __last ); }





      void
      push_back ( _CharT __c )
      {
 const size_type __len = 1 + this -> size ( );
 if ( __len > this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
   this -> reserve ( __len );
 traits_type :: assign ( _M_data ( ) [ this -> size ( ) ], __c );
 _M_rep ( ) -> _M_set_length_and_sharable ( __len );
      }






      basic_string &
      assign ( const basic_string & __str );













      basic_string &
      assign ( const basic_string & __str, size_type __pos, size_type __n )
      { return this -> assign ( __str . _M_data ( )
       + __str . _M_check ( __pos, "basic_string::assign" ),
       __str . _M_limit ( __pos, __n ) ); }











      basic_string &
      assign ( const _CharT * __s, size_type __n );










      basic_string &
      assign ( const _CharT * __s )
      {
                               ;
 return this -> assign ( __s, traits_type :: length ( __s ) );
      }










      basic_string &
      assign ( size_type __n, _CharT __c )
      { return _M_replace_aux ( size_type ( 0 ), this -> size ( ), __n, __c ); }









      template < class _InputIterator >
        basic_string &
        assign ( _InputIterator __first, _InputIterator __last )
        { return this -> replace ( _M_ibegin ( ), _M_iend ( ), __first, __last ); }
























      void
      insert ( iterator __p, size_type __n, _CharT __c )
      { this -> replace ( __p, __p, __n, __c ); }












      template < class _InputIterator >
        void
        insert ( iterator __p, _InputIterator __beg, _InputIterator __end )
        { this -> replace ( __p, __p, __beg, __end ); }
























      basic_string &
      insert ( size_type __pos1, const basic_string & __str )
      { return this -> insert ( __pos1, __str, size_type ( 0 ), __str . size ( ) ); }



















      basic_string &
      insert ( size_type __pos1, const basic_string & __str,
      size_type __pos2, size_type __n )
      { return this -> insert ( __pos1, __str . _M_data ( )
       + __str . _M_check ( __pos2, "basic_string::insert" ),
       __str . _M_limit ( __pos2, __n ) ); }

















      basic_string &
      insert ( size_type __pos, const _CharT * __s, size_type __n );
















      basic_string &
      insert ( size_type __pos, const _CharT * __s )
      {
                               ;
 return this -> insert ( __pos, __s, traits_type :: length ( __s ) );
      }

















      basic_string &
      insert ( size_type __pos, size_type __n, _CharT __c )
      { return _M_replace_aux ( _M_check ( __pos, "basic_string::insert" ),
         size_type ( 0 ), __n, __c ); }













      iterator
      insert ( iterator __p, _CharT __c )
      {
                                                                 ;
 const size_type __pos = __p - _M_ibegin ( );
 _M_replace_aux ( __pos, size_type ( 0 ), size_type ( 1 ), __c );
 _M_rep ( ) -> _M_set_leaked ( );
 return iterator ( _M_data ( ) + __pos );
      }















      basic_string &
      erase ( size_type __pos = 0, size_type __n = npos )
      {
 _M_mutate ( _M_check ( __pos, "basic_string::erase" ),
    _M_limit ( __pos, __n ), size_type ( 0 ) );
 return * this;
      }









      iterator
      erase ( iterator __position )
      {

                               ;
 const size_type __pos = __position - _M_ibegin ( );
 _M_mutate ( __pos, size_type ( 1 ), size_type ( 0 ) );
 _M_rep ( ) -> _M_set_leaked ( );
 return iterator ( _M_data ( ) + __pos );
      }










      iterator
      erase ( iterator __first, iterator __last );

















      basic_string &
      replace ( size_type __pos, size_type __n, const basic_string & __str )
      { return this -> replace ( __pos, __n, __str . _M_data ( ), __str . size ( ) ); }



















      basic_string &
      replace ( size_type __pos1, size_type __n1, const basic_string & __str,
       size_type __pos2, size_type __n2 )
      { return this -> replace ( __pos1, __n1, __str . _M_data ( )
        + __str . _M_check ( __pos2, "basic_string::replace" ),
        __str . _M_limit ( __pos2, __n2 ) ); }


















      basic_string &
      replace ( size_type __pos, size_type __n1, const _CharT * __s,
       size_type __n2 );
















      basic_string &
      replace ( size_type __pos, size_type __n1, const _CharT * __s )
      {
                               ;
 return this -> replace ( __pos, __n1, __s, traits_type :: length ( __s ) );
      }

















      basic_string &
      replace ( size_type __pos, size_type __n1, size_type __n2, _CharT __c )
      { return _M_replace_aux ( _M_check ( __pos, "basic_string::replace" ),
         _M_limit ( __pos, __n1 ), __n2, __c ); }














      basic_string &
      replace ( iterator __i1, iterator __i2, const basic_string & __str )
      { return this -> replace ( __i1, __i2, __str . _M_data ( ), __str . size ( ) ); }















      basic_string &
      replace ( iterator __i1, iterator __i2, const _CharT * __s, size_type __n )
      {

                          ;
 return this -> replace ( __i1 - _M_ibegin ( ), __i2 - __i1, __s, __n );
      }














      basic_string &
      replace ( iterator __i1, iterator __i2, const _CharT * __s )
      {
                               ;
 return this -> replace ( __i1, __i2, __s, traits_type :: length ( __s ) );
      }















      basic_string &
      replace ( iterator __i1, iterator __i2, size_type __n, _CharT __c )
      {

                          ;
 return _M_replace_aux ( __i1 - _M_ibegin ( ), __i2 - __i1, __n, __c );
      }















      template < class _InputIterator >
        basic_string &
        replace ( iterator __i1, iterator __i2,
  _InputIterator __k1, _InputIterator __k2 )
        {

                            ;
                                             ;
   typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
   return _M_replace_dispatch ( __i1, __i2, __k1, __k2, _Integral ( ) );
 }



      basic_string &
      replace ( iterator __i1, iterator __i2, _CharT * __k1, _CharT * __k2 )
      {

                          ;
                                           ;
 return this -> replace ( __i1 - _M_ibegin ( ), __i2 - __i1,
        __k1, __k2 - __k1 );
      }

      basic_string &
      replace ( iterator __i1, iterator __i2,
       const _CharT * __k1, const _CharT * __k2 )
      {

                          ;
                                           ;
 return this -> replace ( __i1 - _M_ibegin ( ), __i2 - __i1,
        __k1, __k2 - __k1 );
      }

      basic_string &
      replace ( iterator __i1, iterator __i2, iterator __k1, iterator __k2 )
      {

                          ;
                                           ;
 return this -> replace ( __i1 - _M_ibegin ( ), __i2 - __i1,
        __k1 . base ( ), __k2 - __k1 );
      }

      basic_string &
      replace ( iterator __i1, iterator __i2,
       const_iterator __k1, const_iterator __k2 )
      {

                          ;
                                           ;
 return this -> replace ( __i1 - _M_ibegin ( ), __i2 - __i1,
        __k1 . base ( ), __k2 - __k1 );
      }




















    private :
      template < class _Integer >
 basic_string &
 _M_replace_dispatch ( iterator __i1, iterator __i2, _Integer __n,
       _Integer __val, __true_type )
        { return _M_replace_aux ( __i1 - _M_ibegin ( ), __i2 - __i1, __n, __val ); }

      template < class _InputIterator >
 basic_string &
 _M_replace_dispatch ( iterator __i1, iterator __i2, _InputIterator __k1,
       _InputIterator __k2, __false_type );

      basic_string &
      _M_replace_aux ( size_type __pos1, size_type __n1, size_type __n2,
       _CharT __c );

      basic_string &
      _M_replace_safe ( size_type __pos1, size_type __n1, const _CharT * __s,
        size_type __n2 );



      template < class _InIterator >
        static _CharT *
        _S_construct_aux ( _InIterator __beg, _InIterator __end,
    const _Alloc & __a, __false_type )
 {
          typedef typename iterator_traits < _InIterator > :: iterator_category _Tag;
          return _S_construct ( __beg, __end, __a, _Tag ( ) );
 }



      template < class _Integer >
        static _CharT *
        _S_construct_aux ( _Integer __beg, _Integer __end,
    const _Alloc & __a, __true_type )
        { return _S_construct ( static_cast < size_type > ( __beg ), __end, __a ); }

      template < class _InIterator >
        static _CharT *
        _S_construct ( _InIterator __beg, _InIterator __end, const _Alloc & __a )
 {
   typedef typename std :: __is_integer < _InIterator > :: __type _Integral;
   return _S_construct_aux ( __beg, __end, __a, _Integral ( ) );
        }


      template < class _InIterator >
        static _CharT *
         _S_construct ( _InIterator __beg, _InIterator __end, const _Alloc & __a,
        input_iterator_tag );



      template < class _FwdIterator >
        static _CharT *
        _S_construct ( _FwdIterator __beg, _FwdIterator __end, const _Alloc & __a,
       forward_iterator_tag );

      static _CharT *
      _S_construct ( size_type __req, _CharT __c, const _Alloc & __a );

    public :












      size_type
      copy ( _CharT * __s, size_type __n, size_type __pos = 0 ) const;








      void
      swap ( basic_string & __s );








      const _CharT *
      c_str ( ) const
      { return _M_data ( ); }







      const _CharT *
      data ( ) const
      { return _M_data ( ); }




      allocator_type
      get_allocator ( ) const
      { return _M_dataplus; }












      size_type
      find ( const _CharT * __s, size_type __pos, size_type __n ) const;











      size_type
      find ( const basic_string & __str, size_type __pos = 0 ) const
      { return this -> find ( __str . data ( ), __pos, __str . size ( ) ); }











      size_type
      find ( const _CharT * __s, size_type __pos = 0 ) const
      {
                               ;
 return this -> find ( __s, __pos, traits_type :: length ( __s ) );
      }











      size_type
      find ( _CharT __c, size_type __pos = 0 ) const;











      size_type
      rfind ( const basic_string & __str, size_type __pos = npos ) const
      { return this -> rfind ( __str . data ( ), __pos, __str . size ( ) ); }












      size_type
      rfind ( const _CharT * __s, size_type __pos, size_type __n ) const;











      size_type
      rfind ( const _CharT * __s, size_type __pos = npos ) const
      {
                               ;
 return this -> rfind ( __s, __pos, traits_type :: length ( __s ) );
      }











      size_type
      rfind ( _CharT __c, size_type __pos = npos ) const;











      size_type
      find_first_of ( const basic_string & __str, size_type __pos = 0 ) const
      { return this -> find_first_of ( __str . data ( ), __pos, __str . size ( ) ); }












      size_type
      find_first_of ( const _CharT * __s, size_type __pos, size_type __n ) const;











      size_type
      find_first_of ( const _CharT * __s, size_type __pos = 0 ) const
      {
                               ;
 return this -> find_first_of ( __s, __pos, traits_type :: length ( __s ) );
      }













      size_type
      find_first_of ( _CharT __c, size_type __pos = 0 ) const
      { return this -> find ( __c, __pos ); }











      size_type
      find_last_of ( const basic_string & __str, size_type __pos = npos ) const
      { return this -> find_last_of ( __str . data ( ), __pos, __str . size ( ) ); }












      size_type
      find_last_of ( const _CharT * __s, size_type __pos, size_type __n ) const;











      size_type
      find_last_of ( const _CharT * __s, size_type __pos = npos ) const
      {
                               ;
 return this -> find_last_of ( __s, __pos, traits_type :: length ( __s ) );
      }













      size_type
      find_last_of ( _CharT __c, size_type __pos = npos ) const
      { return this -> rfind ( __c, __pos ); }











      size_type
      find_first_not_of ( const basic_string & __str, size_type __pos = 0 ) const
      { return this -> find_first_not_of ( __str . data ( ), __pos, __str . size ( ) ); }












      size_type
      find_first_not_of ( const _CharT * __s, size_type __pos,
   size_type __n ) const;











      size_type
      find_first_not_of ( const _CharT * __s, size_type __pos = 0 ) const
      {
                               ;
 return this -> find_first_not_of ( __s, __pos, traits_type :: length ( __s ) );
      }











      size_type
      find_first_not_of ( _CharT __c, size_type __pos = 0 ) const;











      size_type
      find_last_not_of ( const basic_string & __str, size_type __pos = npos ) const
      { return this -> find_last_not_of ( __str . data ( ), __pos, __str . size ( ) ); }













      size_type
      find_last_not_of ( const _CharT * __s, size_type __pos,
         size_type __n ) const;










      size_type
      find_last_not_of ( const _CharT * __s, size_type __pos = npos ) const
      {
                               ;
 return this -> find_last_not_of ( __s, __pos, traits_type :: length ( __s ) );
      }











      size_type
      find_last_not_of ( _CharT __c, size_type __pos = npos ) const;













      basic_string
      substr ( size_type __pos = 0, size_type __n = npos ) const
      { return basic_string ( * this,
       _M_check ( __pos, "basic_string::substr" ), __n ); }














      int
      compare ( const basic_string & __str ) const
      {
 const size_type __size = this -> size ( );
 const size_type __osize = __str . size ( );
 const size_type __len = std :: min ( __size, __osize );

 int __r = traits_type :: compare ( _M_data ( ), __str . data ( ), __len );
 if ( ! __r )
   __r = _S_compare ( __size, __osize );
 return __r;
      }


















      int
      compare ( size_type __pos, size_type __n, const basic_string & __str ) const;






















      int
      compare ( size_type __pos1, size_type __n1, const basic_string & __str,
       size_type __pos2, size_type __n2 ) const;















      int
      compare ( const _CharT * __s ) const;





















      int
      compare ( size_type __pos, size_type __n1, const _CharT * __s ) const;























      int
      compare ( size_type __pos, size_type __n1, const _CharT * __s,
       size_type __n2 ) const;
  };

template < typename _CharT, typename _Traits, typename _Alloc >
    inline basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( )

    : _M_dataplus ( _S_empty_rep ( ) . _M_refdata ( ), _Alloc ( ) ) { }
# 2159
template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc >
    operator + ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    {
      basic_string < _CharT, _Traits, _Alloc > __str ( __lhs );
      __str . append ( __rhs );
      return __str;
    }
# 2175
template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc >
    operator + ( const _CharT * __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs );
# 2186
template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc >
    operator + ( _CharT __lhs, const basic_string < _CharT, _Traits, _Alloc > & __rhs );
# 2196
template < typename _CharT, typename _Traits, typename _Alloc >
    inline basic_string < _CharT, _Traits, _Alloc >
    operator + ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
      const _CharT * __rhs )
    {
      basic_string < _CharT, _Traits, _Alloc > __str ( __lhs );
      __str . append ( __rhs );
      return __str;
    }
# 2212
template < typename _CharT, typename _Traits, typename _Alloc >
    inline basic_string < _CharT, _Traits, _Alloc >
    operator + ( const basic_string < _CharT, _Traits, _Alloc > & __lhs, _CharT __rhs )
    {
      typedef basic_string < _CharT, _Traits, _Alloc > __string_type;
      typedef typename __string_type :: size_type __size_type;
      __string_type __str ( __lhs );
      __str . append ( __size_type ( 1 ), __rhs );
      return __str;
    }
# 2230
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator == ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __lhs . compare ( __rhs ) == 0; }

template < typename _CharT >
    inline
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value, bool > :: __type
    operator == ( const basic_string < _CharT > & __lhs,
        const basic_string < _CharT > & __rhs )
    { return ( __lhs . size ( ) == __rhs . size ( )
       && ! std :: char_traits < _CharT > :: compare ( __lhs . data ( ), __rhs . data ( ),
          __lhs . size ( ) ) ); }
# 2251
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator == ( const _CharT * __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __rhs . compare ( __lhs ) == 0; }
# 2263
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator == ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const _CharT * __rhs )
    { return __lhs . compare ( __rhs ) == 0; }
# 2276
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator != ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return ! ( __lhs == __rhs ); }
# 2288
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator != ( const _CharT * __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return ! ( __lhs == __rhs ); }
# 2300
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator != ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const _CharT * __rhs )
    { return ! ( __lhs == __rhs ); }
# 2313
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator < ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __lhs . compare ( __rhs ) < 0; }
# 2325
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator < ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
       const _CharT * __rhs )
    { return __lhs . compare ( __rhs ) < 0; }
# 2337
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator < ( const _CharT * __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __rhs . compare ( __lhs ) > 0; }
# 2350
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator > ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __lhs . compare ( __rhs ) > 0; }
# 2362
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator > ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
       const _CharT * __rhs )
    { return __lhs . compare ( __rhs ) > 0; }
# 2374
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator > ( const _CharT * __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __rhs . compare ( __lhs ) < 0; }
# 2387
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator <= ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __lhs . compare ( __rhs ) <= 0; }
# 2399
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator <= ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const _CharT * __rhs )
    { return __lhs . compare ( __rhs ) <= 0; }
# 2411
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator <= ( const _CharT * __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __rhs . compare ( __lhs ) >= 0; }
# 2424
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator >= ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __lhs . compare ( __rhs ) >= 0; }
# 2436
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator >= ( const basic_string < _CharT, _Traits, _Alloc > & __lhs,
        const _CharT * __rhs )
    { return __lhs . compare ( __rhs ) >= 0; }
# 2448
template < typename _CharT, typename _Traits, typename _Alloc >
    inline bool
    operator >= ( const _CharT * __lhs,
      const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { return __rhs . compare ( __lhs ) <= 0; }
# 2461
template < typename _CharT, typename _Traits, typename _Alloc >
    inline void
    swap ( basic_string < _CharT, _Traits, _Alloc > & __lhs,
  basic_string < _CharT, _Traits, _Alloc > & __rhs )
    { __lhs . swap ( __rhs ); }
# 2478
template < typename _CharT, typename _Traits, typename _Alloc >
    basic_istream < _CharT, _Traits > &
    operator >> ( basic_istream < _CharT, _Traits > & __is,
        basic_string < _CharT, _Traits, _Alloc > & __str );



template<> basic_istream< char>  &operator>>(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str); 
# 2496
template < typename _CharT, typename _Traits, typename _Alloc >
    inline basic_ostream < _CharT, _Traits > &
    operator << ( basic_ostream < _CharT, _Traits > & __os,
        const basic_string < _CharT, _Traits, _Alloc > & __str )
    {


      return __ostream_insert ( __os, __str . data ( ), __str . size ( ) );
    }
# 2519
template < typename _CharT, typename _Traits, typename _Alloc >
    basic_istream < _CharT, _Traits > &
    getline ( basic_istream < _CharT, _Traits > & __is,
     basic_string < _CharT, _Traits, _Alloc > & __str, _CharT __delim );
# 2536
template < typename _CharT, typename _Traits, typename _Alloc >
    inline basic_istream < _CharT, _Traits > &
    getline ( basic_istream < _CharT, _Traits > & __is,
     basic_string < _CharT, _Traits, _Alloc > & __str )
    { return getline ( __is, __str, __is . widen ( '\n' ) ); }



template<> basic_istream< char>  &getline(basic_istream< char>  & __in, basic_string< char, char_traits< char> , allocator< char> >  & __str, char __delim); 
# 2550
template<> basic_istream< wchar_t>  &getline(basic_istream< wchar_t>  & __in, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str, wchar_t __delim); 



}
# 46 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_string.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits, typename _Alloc >
    const typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    _Rep :: _S_max_size = ( ( ( npos - sizeof ( _Rep_base ) ) / sizeof ( _CharT ) ) - 1 ) / 4;

template < typename _CharT, typename _Traits, typename _Alloc >
    const _CharT
    basic_string < _CharT, _Traits, _Alloc > ::
    _Rep :: _S_terminal = _CharT ( );

template < typename _CharT, typename _Traits, typename _Alloc >
    const typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > :: npos;



template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > :: _Rep :: _S_empty_rep_storage [
    ( sizeof ( _Rep_base ) + sizeof ( _CharT ) + sizeof ( size_type ) - 1 ) /
      sizeof ( size_type ) ];
# 74
template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InIterator >
      _CharT *
      basic_string < _CharT, _Traits, _Alloc > ::
      _S_construct ( _InIterator __beg, _InIterator __end, const _Alloc & __a,
     input_iterator_tag )
      {

 if ( __beg == __end && __a == _Alloc ( ) )
   return _S_empty_rep ( ) . _M_refdata ( );


 _CharT __buf [ 128 ];
 size_type __len = 0;
 while ( __beg != __end && __len < sizeof ( __buf ) / sizeof ( _CharT ) )
   {
     __buf [ __len ++ ] = * __beg;
     ++ __beg;
   }
 _Rep * __r = _Rep :: _S_create ( __len, size_type ( 0 ), __a );
 _M_copy ( __r -> _M_refdata ( ), __buf, __len );
 try
   {
     while ( __beg != __end )
       {
  if ( __len == __r -> _M_capacity )
    {

      _Rep * __another = _Rep :: _S_create ( __len + 1, __len, __a );
      _M_copy ( __another -> _M_refdata ( ), __r -> _M_refdata ( ), __len );
      __r -> _M_destroy ( __a );
      __r = __another;
    }
  __r -> _M_refdata ( ) [ __len ++ ] = * __beg;
  ++ __beg;
       }
   }
 catch ( ... )
   {
     __r -> _M_destroy ( __a );
     throw;
   }
 __r -> _M_set_length_and_sharable ( __len );
 return __r -> _M_refdata ( );
      }

template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InIterator >
      _CharT *
      basic_string < _CharT, _Traits, _Alloc > ::
      _S_construct ( _InIterator __beg, _InIterator __end, const _Alloc & __a,
     forward_iterator_tag )
      {

 if ( __beg == __end && __a == _Alloc ( ) )
   return _S_empty_rep ( ) . _M_refdata ( );


 if ( __builtin_expect ( __gnu_cxx :: __is_null_pointer ( __beg )
        && __beg != __end, 0 ) )
   __throw_logic_error ( ( "basic_string::_S_construct NULL not valid" ) );

 const size_type __dnew = static_cast < size_type > ( std :: distance ( __beg,
              __end ) );

 _Rep * __r = _Rep :: _S_create ( __dnew, size_type ( 0 ), __a );
 try
   { _S_copy_chars ( __r -> _M_refdata ( ), __beg, __end ); }
 catch ( ... )
   {
     __r -> _M_destroy ( __a );
     throw;
   }
 __r -> _M_set_length_and_sharable ( __dnew );
 return __r -> _M_refdata ( );
      }

template < typename _CharT, typename _Traits, typename _Alloc >
    _CharT *
    basic_string < _CharT, _Traits, _Alloc > ::
    _S_construct ( size_type __n, _CharT __c, const _Alloc & __a )
    {

      if ( __n == 0 && __a == _Alloc ( ) )
 return _S_empty_rep ( ) . _M_refdata ( );


      _Rep * __r = _Rep :: _S_create ( __n, size_type ( 0 ), __a );
      if ( __n )
 _M_assign ( __r -> _M_refdata ( ), __n, __c );

      __r -> _M_set_length_and_sharable ( __n );
      return __r -> _M_refdata ( );
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( const basic_string & __str )
    : _M_dataplus ( __str . _M_rep ( ) -> _M_grab ( _Alloc ( __str . get_allocator ( ) ),
       __str . get_allocator ( ) ),
    __str . get_allocator ( ) )
    { }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( const _Alloc & __a )
    : _M_dataplus ( _S_construct ( size_type ( ), _CharT ( ), __a ), __a )
    { }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( const basic_string & __str, size_type __pos, size_type __n )
    : _M_dataplus ( _S_construct ( __str . _M_data ( )
          + __str . _M_check ( __pos,
      "basic_string::basic_string" ),
          __str . _M_data ( ) + __str . _M_limit ( __pos, __n )
          + __pos, _Alloc ( ) ), _Alloc ( ) )
    { }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( const basic_string & __str, size_type __pos,
   size_type __n, const _Alloc & __a )
    : _M_dataplus ( _S_construct ( __str . _M_data ( )
          + __str . _M_check ( __pos,
      "basic_string::basic_string" ),
          __str . _M_data ( ) + __str . _M_limit ( __pos, __n )
          + __pos, __a ), __a )
    { }


template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( const _CharT * __s, size_type __n, const _Alloc & __a )
    : _M_dataplus ( _S_construct ( __s, __s + __n, __a ), __a )
    { }


template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( const _CharT * __s, const _Alloc & __a )
    : _M_dataplus ( _S_construct ( __s, __s ? __s + traits_type :: length ( __s ) :
          __s + npos, __a ), __a )
    { }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( size_type __n, _CharT __c, const _Alloc & __a )
    : _M_dataplus ( _S_construct ( __n, __c, __a ), __a )
    { }


template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InputIterator >
    basic_string < _CharT, _Traits, _Alloc > ::
    basic_string ( _InputIterator __beg, _InputIterator __end, const _Alloc & __a )
    : _M_dataplus ( _S_construct ( __beg, __end, __a ), __a )
    { }
# 241
template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    assign ( const basic_string & __str )
    {
      if ( _M_rep ( ) != __str . _M_rep ( ) )
 {

   const allocator_type __a = this -> get_allocator ( );
   _CharT * __tmp = __str . _M_rep ( ) -> _M_grab ( __a, __str . get_allocator ( ) );
   _M_rep ( ) -> _M_dispose ( __a );
   _M_data ( __tmp );
 }
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    assign ( const _CharT * __s, size_type __n )
    {
                                             ;
      _M_check_length ( this -> size ( ), __n, "basic_string::assign" );
      if ( _M_disjunct ( __s ) || _M_rep ( ) -> _M_is_shared ( ) )
 return _M_replace_safe ( size_type ( 0 ), this -> size ( ), __s, __n );
      else
 {

   const size_type __pos = __s - _M_data ( );
   if ( __pos >= __n )
     _M_copy ( _M_data ( ), __s, __n );
   else if ( __pos )
     _M_move ( _M_data ( ), __s, __n );
   _M_rep ( ) -> _M_set_length_and_sharable ( __n );
   return * this;
 }
     }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    append ( size_type __n, _CharT __c )
    {
      if ( __n )
 {
   _M_check_length ( size_type ( 0 ), __n, "basic_string::append" );
   const size_type __len = __n + this -> size ( );
   if ( __len > this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
     this -> reserve ( __len );
   _M_assign ( _M_data ( ) + this -> size ( ), __n, __c );
   _M_rep ( ) -> _M_set_length_and_sharable ( __len );
 }
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    append ( const _CharT * __s, size_type __n )
    {
                                             ;
      if ( __n )
 {
   _M_check_length ( size_type ( 0 ), __n, "basic_string::append" );
   const size_type __len = __n + this -> size ( );
   if ( __len > this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
     {
       if ( _M_disjunct ( __s ) )
  this -> reserve ( __len );
       else
  {
    const size_type __off = __s - _M_data ( );
    this -> reserve ( __len );
    __s = _M_data ( ) + __off;
  }
     }
   _M_copy ( _M_data ( ) + this -> size ( ), __s, __n );
   _M_rep ( ) -> _M_set_length_and_sharable ( __len );
 }
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    append ( const basic_string & __str )
    {
      const size_type __size = __str . size ( );
      if ( __size )
 {
   const size_type __len = __size + this -> size ( );
   if ( __len > this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
     this -> reserve ( __len );
   _M_copy ( _M_data ( ) + this -> size ( ), __str . _M_data ( ), __size );
   _M_rep ( ) -> _M_set_length_and_sharable ( __len );
 }
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    append ( const basic_string & __str, size_type __pos, size_type __n )
    {
      __str . _M_check ( __pos, "basic_string::append" );
      __n = __str . _M_limit ( __pos, __n );
      if ( __n )
 {
   const size_type __len = __n + this -> size ( );
   if ( __len > this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
     this -> reserve ( __len );
   _M_copy ( _M_data ( ) + this -> size ( ), __str . _M_data ( ) + __pos, __n );
   _M_rep ( ) -> _M_set_length_and_sharable ( __len );
 }
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
     basic_string < _CharT, _Traits, _Alloc > &
     basic_string < _CharT, _Traits, _Alloc > ::
     insert ( size_type __pos, const _CharT * __s, size_type __n )
     {
                                              ;
       _M_check ( __pos, "basic_string::insert" );
       _M_check_length ( size_type ( 0 ), __n, "basic_string::insert" );
       if ( _M_disjunct ( __s ) || _M_rep ( ) -> _M_is_shared ( ) )
         return _M_replace_safe ( __pos, size_type ( 0 ), __s, __n );
       else
         {

           const size_type __off = __s - _M_data ( );
           _M_mutate ( __pos, 0, __n );
           __s = _M_data ( ) + __off;
           _CharT * __p = _M_data ( ) + __pos;
           if ( __s + __n <= __p )
             _M_copy ( __p, __s, __n );
           else if ( __s >= __p )
             _M_copy ( __p, __s + __n, __n );
           else
             {
        const size_type __nleft = __p - __s;
               _M_copy ( __p, __s, __nleft );
               _M_copy ( __p + __nleft, __p + __n, __n - __nleft );
             }
           return * this;
         }
     }

template < typename _CharT, typename _Traits, typename _Alloc >
     typename basic_string < _CharT, _Traits, _Alloc > :: iterator
     basic_string < _CharT, _Traits, _Alloc > ::
     erase ( iterator __first, iterator __last )
     {

                           ;




       const size_type __size = __last - __first;
       if ( __size )
  {
    const size_type __pos = __first - _M_ibegin ( );
    _M_mutate ( __pos, __size, size_type ( 0 ) );
    _M_rep ( ) -> _M_set_leaked ( );
    return iterator ( _M_data ( ) + __pos );
  }
       else
  return __first;
     }

template < typename _CharT, typename _Traits, typename _Alloc >
     basic_string < _CharT, _Traits, _Alloc > &
     basic_string < _CharT, _Traits, _Alloc > ::
     replace ( size_type __pos, size_type __n1, const _CharT * __s,
      size_type __n2 )
     {
                                               ;
       _M_check ( __pos, "basic_string::replace" );
       __n1 = _M_limit ( __pos, __n1 );
       _M_check_length ( __n1, __n2, "basic_string::replace" );
       bool __left;
       if ( _M_disjunct ( __s ) || _M_rep ( ) -> _M_is_shared ( ) )
         return _M_replace_safe ( __pos, __n1, __s, __n2 );
       else if ( ( __left = __s + __n2 <= _M_data ( ) + __pos )
  || _M_data ( ) + __pos + __n1 <= __s )
  {

    size_type __off = __s - _M_data ( );
    __left ? __off : ( __off += __n2 - __n1 );
    _M_mutate ( __pos, __n1, __n2 );
    _M_copy ( _M_data ( ) + __pos, _M_data ( ) + __off, __n2 );
    return * this;
  }
       else
  {

    const basic_string __tmp ( __s, __n2 );
    return _M_replace_safe ( __pos, __n1, __tmp . _M_data ( ), __n2 );
  }
     }

template < typename _CharT, typename _Traits, typename _Alloc >
    void
    basic_string < _CharT, _Traits, _Alloc > :: _Rep ::
    _M_destroy ( const _Alloc & __a ) throw ( )
    {
      const size_type __size = sizeof ( _Rep_base ) +
                        ( this -> _M_capacity + 1 ) * sizeof ( _CharT );
      _Raw_bytes_alloc ( __a ) . deallocate ( reinterpret_cast < char * > ( this ), __size );
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    void
    basic_string < _CharT, _Traits, _Alloc > ::
    _M_leak_hard ( )
    {

      if ( _M_rep ( ) == & _S_empty_rep ( ) )
 return;

      if ( _M_rep ( ) -> _M_is_shared ( ) )
 _M_mutate ( 0, 0, 0 );
      _M_rep ( ) -> _M_set_leaked ( );
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    void
    basic_string < _CharT, _Traits, _Alloc > ::
    _M_mutate ( size_type __pos, size_type __len1, size_type __len2 )
    {
      const size_type __old_size = this -> size ( );
      const size_type __new_size = __old_size + __len2 - __len1;
      const size_type __how_much = __old_size - __pos - __len1;

      if ( __new_size > this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
 {

   const allocator_type __a = get_allocator ( );
   _Rep * __r = _Rep :: _S_create ( __new_size, this -> capacity ( ), __a );

   if ( __pos )
     _M_copy ( __r -> _M_refdata ( ), _M_data ( ), __pos );
   if ( __how_much )
     _M_copy ( __r -> _M_refdata ( ) + __pos + __len2,
      _M_data ( ) + __pos + __len1, __how_much );

   _M_rep ( ) -> _M_dispose ( __a );
   _M_data ( __r -> _M_refdata ( ) );
 }
      else if ( __how_much && __len1 != __len2 )
 {

   _M_move ( _M_data ( ) + __pos + __len2,
    _M_data ( ) + __pos + __len1, __how_much );
 }
      _M_rep ( ) -> _M_set_length_and_sharable ( __new_size );
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    void
    basic_string < _CharT, _Traits, _Alloc > ::
    reserve ( size_type __res )
    {
      if ( __res != this -> capacity ( ) || _M_rep ( ) -> _M_is_shared ( ) )
        {

   if ( __res < this -> size ( ) )
     __res = this -> size ( );
   const allocator_type __a = get_allocator ( );
   _CharT * __tmp = _M_rep ( ) -> _M_clone ( __a, __res - this -> size ( ) );
   _M_rep ( ) -> _M_dispose ( __a );
   _M_data ( __tmp );
        }
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    void
    basic_string < _CharT, _Traits, _Alloc > ::
    swap ( basic_string & __s )
    {
      if ( _M_rep ( ) -> _M_is_leaked ( ) )
 _M_rep ( ) -> _M_set_sharable ( );
      if ( __s . _M_rep ( ) -> _M_is_leaked ( ) )
 __s . _M_rep ( ) -> _M_set_sharable ( );
      if ( this -> get_allocator ( ) == __s . get_allocator ( ) )
 {
   _CharT * __tmp = _M_data ( );
   _M_data ( __s . _M_data ( ) );
   __s . _M_data ( __tmp );
 }

      else
 {
   const basic_string __tmp1 ( _M_ibegin ( ), _M_iend ( ),
        __s . get_allocator ( ) );
   const basic_string __tmp2 ( __s . _M_ibegin ( ), __s . _M_iend ( ),
        this -> get_allocator ( ) );
   * this = __tmp2;
   __s = __tmp1;
 }
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: _Rep *
    basic_string < _CharT, _Traits, _Alloc > :: _Rep ::
    _S_create ( size_type __capacity, size_type __old_capacity,
       const _Alloc & __alloc )
    {


      if ( __capacity > _S_max_size )
 __throw_length_error ( ( "basic_string::_S_create" ) );
























      const size_type __pagesize = 4096;
      const size_type __malloc_header_size = 4 * sizeof ( void * );







      if ( __capacity > __old_capacity && __capacity < 2 * __old_capacity )
 __capacity = 2 * __old_capacity;




      size_type __size = ( __capacity + 1 ) * sizeof ( _CharT ) + sizeof ( _Rep );

      const size_type __adj_size = __size + __malloc_header_size;
      if ( __adj_size > __pagesize && __capacity > __old_capacity )
 {
   const size_type __extra = __pagesize - __adj_size % __pagesize;
   __capacity += __extra / sizeof ( _CharT );

   if ( __capacity > _S_max_size )
     __capacity = _S_max_size;
   __size = ( __capacity + 1 ) * sizeof ( _CharT ) + sizeof ( _Rep );
 }



      void * __place = _Raw_bytes_alloc ( __alloc ) . allocate ( __size );
      _Rep * __p = new ( __place ) _Rep;
      __p -> _M_capacity = __capacity;







      __p -> _M_set_sharable ( );
      return __p;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    _CharT *
    basic_string < _CharT, _Traits, _Alloc > :: _Rep ::
    _M_clone ( const _Alloc & __alloc, size_type __res )
    {

      const size_type __requested_cap = this -> _M_length + __res;
      _Rep * __r = _Rep :: _S_create ( __requested_cap, this -> _M_capacity,
      __alloc );
      if ( this -> _M_length )
 _M_copy ( __r -> _M_refdata ( ), _M_refdata ( ), this -> _M_length );

      __r -> _M_set_length_and_sharable ( this -> _M_length );
      return __r -> _M_refdata ( );
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    void
    basic_string < _CharT, _Traits, _Alloc > ::
    resize ( size_type __n, _CharT __c )
    {
      const size_type __size = this -> size ( );
      _M_check_length ( __size, __n, "basic_string::resize" );
      if ( __size < __n )
 this -> append ( __n - __size, __c );
      else if ( __n < __size )
 this -> erase ( __n );

    }

template < typename _CharT, typename _Traits, typename _Alloc >
    template < typename _InputIterator >
      basic_string < _CharT, _Traits, _Alloc > &
      basic_string < _CharT, _Traits, _Alloc > ::
      _M_replace_dispatch ( iterator __i1, iterator __i2, _InputIterator __k1,
     _InputIterator __k2, __false_type )
      {
 const basic_string __s ( __k1, __k2 );
 const size_type __n1 = __i2 - __i1;
 _M_check_length ( __n1, __s . size ( ), "basic_string::_M_replace_dispatch" );
 return _M_replace_safe ( __i1 - _M_ibegin ( ), __n1, __s . _M_data ( ),
          __s . size ( ) );
      }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    _M_replace_aux ( size_type __pos1, size_type __n1, size_type __n2,
     _CharT __c )
    {
      _M_check_length ( __n1, __n2, "basic_string::_M_replace_aux" );
      _M_mutate ( __pos1, __n1, __n2 );
      if ( __n2 )
 _M_assign ( _M_data ( ) + __pos1, __n2, __c );
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc > &
    basic_string < _CharT, _Traits, _Alloc > ::
    _M_replace_safe ( size_type __pos1, size_type __n1, const _CharT * __s,
      size_type __n2 )
    {
      _M_mutate ( __pos1, __n1, __n2 );
      if ( __n2 )
 _M_copy ( _M_data ( ) + __pos1, __s, __n2 );
      return * this;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc >
    operator + ( const _CharT * __lhs,
       const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    {
                                      ;
      typedef basic_string < _CharT, _Traits, _Alloc > __string_type;
      typedef typename __string_type :: size_type __size_type;
      const __size_type __len = _Traits :: length ( __lhs );
      __string_type __str;
      __str . reserve ( __len + __rhs . size ( ) );
      __str . append ( __lhs, __len );
      __str . append ( __rhs );
      return __str;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_string < _CharT, _Traits, _Alloc >
    operator + ( _CharT __lhs, const basic_string < _CharT, _Traits, _Alloc > & __rhs )
    {
      typedef basic_string < _CharT, _Traits, _Alloc > __string_type;
      typedef typename __string_type :: size_type __size_type;
      __string_type __str;
      const __size_type __len = __rhs . size ( );
      __str . reserve ( __len + 1 );
      __str . append ( __size_type ( 1 ), __lhs );
      __str . append ( __rhs );
      return __str;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    copy ( _CharT * __s, size_type __n, size_type __pos ) const
    {
      _M_check ( __pos, "basic_string::copy" );
      __n = _M_limit ( __pos, __n );
                                             ;
      if ( __n )
 _M_copy ( __s, _M_data ( ) + __pos, __n );

      return __n;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find ( const _CharT * __s, size_type __pos, size_type __n ) const
    {
                                             ;
      const size_type __size = this -> size ( );
      const _CharT * __data = _M_data ( );

      if ( __n == 0 )
 return __pos <= __size ? __pos : npos;

      if ( __n <= __size )
 {
   for (; __pos <= __size - __n; ++ __pos )
     if ( traits_type :: eq ( __data [ __pos ], __s [ 0 ] )
  && traits_type :: compare ( __data + __pos + 1,
     __s + 1, __n - 1 ) == 0 )
       return __pos;
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find ( _CharT __c, size_type __pos ) const
    {
      size_type __ret = npos;
      const size_type __size = this -> size ( );
      if ( __pos < __size )
 {
   const _CharT * __data = _M_data ( );
   const size_type __n = __size - __pos;
   const _CharT * __p = traits_type :: find ( __data + __pos, __n, __c );
   if ( __p )
     __ret = __p - __data;
 }
      return __ret;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    rfind ( const _CharT * __s, size_type __pos, size_type __n ) const
    {
                                             ;
      const size_type __size = this -> size ( );
      if ( __n <= __size )
 {
   __pos = std :: min ( size_type ( __size - __n ), __pos );
   const _CharT * __data = _M_data ( );
   do
     {
       if ( traits_type :: compare ( __data + __pos, __s, __n ) == 0 )
  return __pos;
     }
   while ( __pos -- > 0 );
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    rfind ( _CharT __c, size_type __pos ) const
    {
      size_type __size = this -> size ( );
      if ( __size )
 {
   if ( -- __size > __pos )
     __size = __pos;
   for ( ++ __size; __size -- > 0; )
     if ( traits_type :: eq ( _M_data ( ) [ __size ], __c ) )
       return __size;
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find_first_of ( const _CharT * __s, size_type __pos, size_type __n ) const
    {
                                             ;
      for (; __n && __pos < this -> size ( ); ++ __pos )
 {
   const _CharT * __p = traits_type :: find ( __s, __n, _M_data ( ) [ __pos ] );
   if ( __p )
     return __pos;
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find_last_of ( const _CharT * __s, size_type __pos, size_type __n ) const
    {
                                             ;
      size_type __size = this -> size ( );
      if ( __size && __n )
 {
   if ( -- __size > __pos )
     __size = __pos;
   do
     {
       if ( traits_type :: find ( __s, __n, _M_data ( ) [ __size ] ) )
  return __size;
     }
   while ( __size -- != 0 );
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find_first_not_of ( const _CharT * __s, size_type __pos, size_type __n ) const
    {
                                             ;
      for (; __pos < this -> size ( ); ++ __pos )
 if ( ! traits_type :: find ( __s, __n, _M_data ( ) [ __pos ] ) )
   return __pos;
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find_first_not_of ( _CharT __c, size_type __pos ) const
    {
      for (; __pos < this -> size ( ); ++ __pos )
 if ( ! traits_type :: eq ( _M_data ( ) [ __pos ], __c ) )
   return __pos;
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find_last_not_of ( const _CharT * __s, size_type __pos, size_type __n ) const
    {
                                             ;
      size_type __size = this -> size ( );
      if ( __size )
 {
   if ( -- __size > __pos )
     __size = __pos;
   do
     {
       if ( ! traits_type :: find ( __s, __n, _M_data ( ) [ __size ] ) )
  return __size;
     }
   while ( __size -- );
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    typename basic_string < _CharT, _Traits, _Alloc > :: size_type
    basic_string < _CharT, _Traits, _Alloc > ::
    find_last_not_of ( _CharT __c, size_type __pos ) const
    {
      size_type __size = this -> size ( );
      if ( __size )
 {
   if ( -- __size > __pos )
     __size = __pos;
   do
     {
       if ( ! traits_type :: eq ( _M_data ( ) [ __size ], __c ) )
  return __size;
     }
   while ( __size -- );
 }
      return npos;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    int
    basic_string < _CharT, _Traits, _Alloc > ::
    compare ( size_type __pos, size_type __n, const basic_string & __str ) const
    {
      _M_check ( __pos, "basic_string::compare" );
      __n = _M_limit ( __pos, __n );
      const size_type __osize = __str . size ( );
      const size_type __len = std :: min ( __n, __osize );
      int __r = traits_type :: compare ( _M_data ( ) + __pos, __str . data ( ), __len );
      if ( ! __r )
 __r = _S_compare ( __n, __osize );
      return __r;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    int
    basic_string < _CharT, _Traits, _Alloc > ::
    compare ( size_type __pos1, size_type __n1, const basic_string & __str,
     size_type __pos2, size_type __n2 ) const
    {
      _M_check ( __pos1, "basic_string::compare" );
      __str . _M_check ( __pos2, "basic_string::compare" );
      __n1 = _M_limit ( __pos1, __n1 );
      __n2 = __str . _M_limit ( __pos2, __n2 );
      const size_type __len = std :: min ( __n1, __n2 );
      int __r = traits_type :: compare ( _M_data ( ) + __pos1,
         __str . data ( ) + __pos2, __len );
      if ( ! __r )
 __r = _S_compare ( __n1, __n2 );
      return __r;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    int
    basic_string < _CharT, _Traits, _Alloc > ::
    compare ( const _CharT * __s ) const
    {
                                    ;
      const size_type __size = this -> size ( );
      const size_type __osize = traits_type :: length ( __s );
      const size_type __len = std :: min ( __size, __osize );
      int __r = traits_type :: compare ( _M_data ( ), __s, __len );
      if ( ! __r )
 __r = _S_compare ( __size, __osize );
      return __r;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    int
    basic_string < _CharT, _Traits, _Alloc > ::
    compare ( size_type __pos, size_type __n1, const _CharT * __s ) const
    {
                                    ;
      _M_check ( __pos, "basic_string::compare" );
      __n1 = _M_limit ( __pos, __n1 );
      const size_type __osize = traits_type :: length ( __s );
      const size_type __len = std :: min ( __n1, __osize );
      int __r = traits_type :: compare ( _M_data ( ) + __pos, __s, __len );
      if ( ! __r )
 __r = _S_compare ( __n1, __osize );
      return __r;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    int
    basic_string < _CharT, _Traits, _Alloc > ::
    compare ( size_type __pos, size_type __n1, const _CharT * __s,
     size_type __n2 ) const
    {
                                              ;
      _M_check ( __pos, "basic_string::compare" );
      __n1 = _M_limit ( __pos, __n1 );
      const size_type __len = std :: min ( __n1, __n2 );
      int __r = traits_type :: compare ( _M_data ( ) + __pos, __s, __len );
      if ( ! __r )
 __r = _S_compare ( __n1, __n2 );
      return __r;
    }


template < typename _CharT, typename _Traits, typename _Alloc >
    basic_istream < _CharT, _Traits > &
    operator >> ( basic_istream < _CharT, _Traits > & __in,
        basic_string < _CharT, _Traits, _Alloc > & __str )
    {
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef basic_string < _CharT, _Traits, _Alloc > __string_type;
      typedef typename __istream_type :: ios_base __ios_base;
      typedef typename __istream_type :: int_type __int_type;
      typedef typename __string_type :: size_type __size_type;
      typedef ctype < _CharT > __ctype_type;
      typedef typename __ctype_type :: ctype_base __ctype_base;

      __size_type __extracted = 0;
      typename __ios_base :: iostate __err = __ios_base :: goodbit;
      typename __istream_type :: sentry __cerb ( __in, false );
      if ( __cerb )
 {
   try
     {

       __str . erase ( );
       _CharT __buf [ 128 ];
       __size_type __len = 0;
       const streamsize __w = __in . width ( );
       const __size_type __n = __w > 0 ? static_cast < __size_type > ( __w )
                                : __str . max_size ( );
       const __ctype_type & __ct = use_facet < __ctype_type > ( __in . getloc ( ) );
       const __int_type __eof = _Traits :: eof ( );
       __int_type __c = __in . rdbuf ( ) -> sgetc ( );

       while ( __extracted < __n
       && ! _Traits :: eq_int_type ( __c, __eof )
       && ! __ct . is ( __ctype_base :: space,
     _Traits :: to_char_type ( __c ) ) )
  {
    if ( __len == sizeof ( __buf ) / sizeof ( _CharT ) )
      {
        __str . append ( __buf, sizeof ( __buf ) / sizeof ( _CharT ) );
        __len = 0;
      }
    __buf [ __len ++ ] = _Traits :: to_char_type ( __c );
    ++ __extracted;
    __c = __in . rdbuf ( ) -> snextc ( );
  }
       __str . append ( __buf, __len );

       if ( _Traits :: eq_int_type ( __c, __eof ) )
  __err |= __ios_base :: eofbit;
       __in . width ( 0 );
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       __in . _M_setstate ( __ios_base :: badbit );
       throw;
     }
   catch ( ... )
     {



       __in . _M_setstate ( __ios_base :: badbit );
     }
 }

      if ( ! __extracted )
 __err |= __ios_base :: failbit;
      if ( __err )
 __in . setstate ( __err );
      return __in;
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    basic_istream < _CharT, _Traits > &
    getline ( basic_istream < _CharT, _Traits > & __in,
     basic_string < _CharT, _Traits, _Alloc > & __str, _CharT __delim )
    {
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef basic_string < _CharT, _Traits, _Alloc > __string_type;
      typedef typename __istream_type :: ios_base __ios_base;
      typedef typename __istream_type :: int_type __int_type;
      typedef typename __string_type :: size_type __size_type;

      __size_type __extracted = 0;
      const __size_type __n = __str . max_size ( );
      typename __ios_base :: iostate __err = __ios_base :: goodbit;
      typename __istream_type :: sentry __cerb ( __in, true );
      if ( __cerb )
 {
   try
     {
       __str . erase ( );
       const __int_type __idelim = _Traits :: to_int_type ( __delim );
       const __int_type __eof = _Traits :: eof ( );
       __int_type __c = __in . rdbuf ( ) -> sgetc ( );

       while ( __extracted < __n
       && ! _Traits :: eq_int_type ( __c, __eof )
       && ! _Traits :: eq_int_type ( __c, __idelim ) )
  {
    __str += _Traits :: to_char_type ( __c );
    ++ __extracted;
    __c = __in . rdbuf ( ) -> snextc ( );
  }

       if ( _Traits :: eq_int_type ( __c, __eof ) )
  __err |= __ios_base :: eofbit;
       else if ( _Traits :: eq_int_type ( __c, __idelim ) )
  {
    ++ __extracted;
    __in . rdbuf ( ) -> sbumpc ( );
  }
       else
  __err |= __ios_base :: failbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       __in . _M_setstate ( __ios_base :: badbit );
       throw;
     }
   catch ( ... )
     {



       __in . _M_setstate ( __ios_base :: badbit );
     }
 }
      if ( ! __extracted )
 __err |= __ios_base :: failbit;
      if ( __err )
 __in . setstate ( __err );
      return __in;
    }
# 1134
extern template class basic_string< char, char_traits< char> , allocator< char> > ;
extern template basic_istream< char>  &operator>>(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str);


extern template basic_ostream< char>  &operator<<(basic_ostream< char>  & __os, const basic_string< char, char_traits< char> , allocator< char> >  & __str);


extern template basic_istream< char>  &getline(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str, char __delim);


extern template basic_istream< char>  &getline(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str);




extern template class basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> > ;
extern template basic_istream< wchar_t>  &operator>>(basic_istream< wchar_t>  & __is, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str);


extern template basic_ostream< wchar_t>  &operator<<(basic_ostream< wchar_t>  & __os, const basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str);


extern template basic_istream< wchar_t>  &getline(basic_istream< wchar_t>  & __is, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str, wchar_t __delim);


extern template basic_istream< wchar_t>  &getline(basic_istream< wchar_t>  & __is, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str);
# 1165
}
# 65 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Common.h"
namespace hmpprt { 
# 30 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/environment.def"
extern const std::vector< std::basic_string< char, std::char_traits< char> , std::allocator< char> > >  PATH; 
extern const bool DISABLE_LOCKER; 
extern const std::string CHECK_TRANSFERS; 
extern const std::string DUMP_DATA_PATH; 
extern const int MAX_THREADS; 
extern const int HOST_DEVICES; 



extern const bool DISABLE_CUDA; 

extern const int DEFAULT_CUDA_DEVICE; 




extern const std::string CUDA_DRIVER; 



extern const std::string OPENCL_DRIVER; 


extern const bool FORCE_CU_LAUNCH_GRID; 



extern const bool DISABLE_OPENCL; 

extern const int DEFAULT_OPENCL_DEVICE; 
extern const bool AUTO_PAGE_LOCK; 
extern const std::string OPENCL_DEVICE_TYPE; 
# 73 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Common.h"
class AutoIndent { 



public: AutoIndent(int indent = (2)) : inc_(indent) 

{ 
indent_ += inc_; 
} 


~AutoIndent() 
{ 
indent_ -= inc_; 
} 


static void inc(int indent = (2)) 
{ 
indent_ += indent; 
} 


static void dec(int indent = (2)) 
{ 
indent_ -= indent; 
} 


static int get() 
{ 
return indent_; 
} 


private: static __thread int indent_; 

int inc_; 
}; 

}
# 29 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/NonCopyable.h"
namespace hmpprt { 


class NonCopyable { 


public: NonCopyable() { } 


private: NonCopyable(const NonCopyable &); 
NonCopyable &operator=(const NonCopyable &); 
}; 

}
# 31 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/MemorySpace.h"
namespace hmpprt { 



enum MemorySpace { 
# 26 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/MemorySpace.def"
MS_NONE, 
MS_HOST, 
MS_HOST_CIPHER, 

MS_CUDA_GLOB = 1001, 
MS_CUDA_LOCAL, 
MS_CUDA_SHARED, 
MS_CUDA_CONST, 
MS_CUDA_PINNED, 
MS_CUDA_SHARED_REDUCTION, 
MS_CUDA_UVA, 

MS_OPENCL_GLOB = 2001, 
MS_OPENCL_SHARED, 
MS_OPENCL_CONST, 
MS_OPENCL_SHARED_REDUCTION, 
MS_OPENCL_LOCAL, 
MS_OPENCL_IMAGE, 
MS_OPENCL_ALLOC, 
MS_OPENCL_PERSISTENT, 
MS_COMMON_COHERENT, 
# 40 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/MemorySpace.h"
MS_MAX
}; 



const char *get_memory_space_name(MemorySpace memory_space); 

}
# 37 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Device.h"
namespace hmpprt { 


class HostDevice; 
class CUDADevice; 
class OpenCLDevice; 
class Codelet; 
class ArgumentList; 
class Device; 
class Queue; 
class Data; 



const char *get_target_name(Target target); 


Target get_target_from_string(const std::string & target); 



void raise_transfer_error_warning(void * src, void * dst, bool uploading); 


typedef std::vector< Device *>  DeviceList; 


class Device : private NonCopyable { 




public: virtual ~Device(); 
# 76
void acquire(); 




bool tryAcquire(); 




void release(); 

virtual void createContext() = 0; 



void call(Codelet * codelet, ArgumentList & arguments, Queue * q = 0); 



virtual MemorySpace getDefaultMemorySpace() const = 0; 



virtual bool hasDoublePrecision() const = 0; 



virtual bool hasHostMemoryIntegration() const = 0; 



virtual unsigned getDeviceMaxClockRate() const = 0; 



unsigned long getId() const; 



const std::string &getLabel() const; 




virtual void allocate(Data * data) = 0; 




virtual void free(Data * data) = 0; 
# 133
virtual Data *createSubData(Data * data, size_t size, size_t offset) = 0; 
# 142
virtual void upload(Data * data, const void * host_address, size_t offset, size_t size, Queue * q = 0) = 0; 
# 151
virtual void download(Data * data, void * host_address, size_t offset, size_t size, Queue * q = 0) = 0; 



virtual void setmem(Data * data, int value = (0)) = 0; 



virtual void copy(Data * dst_data, Data * src_data, Queue * q = 0); 


virtual void *getVendorDeviceHandle() = 0; 


virtual void *getVendorDeviceContext() = 0; 


virtual void releaseHandle(void * handle) = 0; 


virtual void synchronize(Queue * queue = 0) = 0; 


virtual bool isPageLocked(void * host_address, size_t size) = 0; 


virtual void replaceAllocs(int) = 0; 


virtual void mapBuffer(Data * data, Queue * queue = 0); 


virtual void unMapBuffer(Data * data, Queue * queue = 0); 




virtual bool checkDeviceData(void * device_address, void * host_address, size_t size, Queue * queue) = 0; 


virtual bool hasPhysicalAddresses() = 0; 


protected: Device(unsigned long id, const std::string & label); 



private: unsigned long id_; 
std::string label_; 
}; 

}
# 33 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/DeviceManager.h"
namespace hmpprt { 
# 39
class DeviceManager : private NonCopyable { 




public: static DeviceManager *getInstance(); 



void cleanUp(Target target = (ANY_TARGET)); 


static bool hasInstance(); 
# 57
void searchDevices(Target target, DeviceList & output); 
# 65
void acquireDevices(Target target, size_t number, DeviceList & output); 



Device *getHostDevice(); 




Device *acquireCUDADevice(); 




Device *acquireOpenCLDevice(); 



Device *acquireDevice(Target target); 



private: typedef std::map< Target, std::vector< Device *> >  DeviceMap; 

DeviceMap devices_; 


void *mutex_; 



public: DeviceManager(); 

~DeviceManager(); 

}; 

}
# 36 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Grouplet.h"
namespace hmpprt { 


class Codelet; 


typedef std::vector< Codelet *>  CodeletList; 



class Grouplet : private NonCopyable { 
# 54
public: explicit Grouplet(const std::string & file_name); 
# 60
Grouplet(const std::string & source_file, Target target); 


~Grouplet(); 



const std::string &getFileName() const; 



Target getTarget() const; 



CodeletList listCodelets(); 



Codelet *getCodeletByName(const std::string & codelet_name); 
# 85
void setTarget(Target target); 



void addSignature(const char * codelet_name, const char * signature_string); 



bool hasSignature(const std::string & codelet_name); 



private: typedef std::map< std::basic_string< char, std::char_traits< char> , std::allocator< char> > , Codelet *>  CodeletsByName; 
typedef std::vector< void *>  SignatureList; 

SignatureList signatures_; 

std::string file_name_; 
void *handle_; 
Target target_; 
CodeletList codelets_; 
CodeletsByName codelets_by_name_; 

void load(); 
void unload(); 

}; 

}
# 44 "/usr/include/string.h" 3
extern "C" void *memcpy(void * __dest, const void * __src, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" void *memmove(void * __dest, const void * __src, size_t __n) throw()
 __attribute((__nonnull__(1, 2))); 
# 57
extern "C" void *memccpy(void * __dest, const void * __src, int __c, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 
# 65
extern "C" void *memset(void * __s, int __c, size_t __n) throw() __attribute((__nonnull__(1))); 


extern "C" int memcmp(const void * __s1, const void * __s2, size_t __n) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 95
extern "C" void *memchr(const void * __s, int __c, size_t __n) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 109
extern "C" void *rawmemchr(const void * __s, int __c) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 120
extern "C" void *memrchr(const void * __s, int __c, size_t __n) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 128
extern "C" char *strcpy(char * __dest, const char * __src) throw()
 __attribute((__nonnull__(1, 2))); 

extern "C" char *strncpy(char * __dest, const char * __src, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 


extern "C" char *strcat(char * __dest, const char * __src) throw()
 __attribute((__nonnull__(1, 2))); 

extern "C" char *strncat(char * __dest, const char * __src, size_t __n) throw()
 __attribute((__nonnull__(1, 2))); 


extern "C" int strcmp(const char * __s1, const char * __s2) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 

extern "C" int strncmp(const char * __s1, const char * __s2, size_t __n) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 


extern "C" int strcoll(const char * __s1, const char * __s2) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 

extern "C" size_t strxfrm(char * __dest, const char * __src, size_t __n) throw()

 __attribute((__nonnull__(2))); 
# 165
extern "C" int strcoll_l(const char * __s1, const char * __s2, __locale_t __l) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3))); 

extern "C" size_t strxfrm_l(char * __dest, const char * __src, size_t __n, __locale_t __l) throw()
 __attribute((__nonnull__(2, 4))); 
# 175
extern "C" char *strdup(const char * __s) throw()
 __attribute((__malloc__)) __attribute((__nonnull__(1))); 
# 183
extern "C" char *strndup(const char * __string, size_t __n) throw()
 __attribute((__malloc__)) __attribute((__nonnull__(1))); 
# 235
extern "C" char *strchr(const char * __s, int __c) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 262
extern "C" char *strrchr(const char * __s, int __c) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 276
extern "C" char *strchrnul(const char * __s, int __c) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 284
extern "C" size_t strcspn(const char * __s, const char * __reject) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 


extern "C" size_t strspn(const char * __s, const char * __accept) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 314
extern "C" char *strpbrk(const char * __s, const char * __accept) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 342
extern "C" char *strstr(const char * __haystack, const char * __needle) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 




extern "C" char *strtok(char * __s, const char * __delim) throw()
 __attribute((__nonnull__(2))); 




extern "C" char *__strtok_r(char * __s, const char * __delim, char ** __save_ptr) throw()


 __attribute((__nonnull__(2, 3))); 

extern "C" char *strtok_r(char * __s, const char * __delim, char ** __save_ptr) throw()

 __attribute((__nonnull__(2, 3))); 
# 373
extern "C" char *strcasestr(const char * __haystack, const char * __needle) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 382
extern "C" void *memmem(const void * __haystack, size_t __haystacklen, const void * __needle, size_t __needlelen) throw()

 __attribute((__pure__)) __attribute((__nonnull__(1, 3))); 



extern "C" void *__mempcpy(void * __dest, const void * __src, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 
extern "C" void *mempcpy(void * __dest, const void * __src, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 
# 399
extern "C" size_t strlen(const char * __s) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 406
extern "C" size_t strnlen(const char * __string, size_t __maxlen) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 413
extern "C" char *strerror(int __errnum) throw(); 
# 438
extern "C" char *strerror_r(int __errnum, char * __buf, size_t __buflen) throw()
 __attribute((__nonnull__(2))); 
# 445
extern "C" char *strerror_l(int __errnum, __locale_t __l) throw(); 
# 451
extern "C" void __bzero(void * __s, size_t __n) throw() __attribute((__nonnull__(1))); 



extern "C" void bcopy(const void * __src, void * __dest, size_t __n) throw()
 __attribute((__nonnull__(1, 2))); 


extern "C" void bzero(void * __s, size_t __n) throw() __attribute((__nonnull__(1))); 


extern "C" int bcmp(const void * __s1, const void * __s2, size_t __n) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 489
extern "C" char *index(const char * __s, int __c) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 517
extern "C" char *rindex(const char * __s, int __c) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1))); 




extern "C" int ffs(int __i) throw() __attribute((const)); 




extern "C" int ffsl(long __l) throw() __attribute((const)); 

__extension__ extern "C" int ffsll(long long __ll) throw()
 __attribute((const)); 




extern "C" int strcasecmp(const char * __s1, const char * __s2) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 


extern "C" int strncasecmp(const char * __s1, const char * __s2, size_t __n) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 547
extern "C" int strcasecmp_l(const char * __s1, const char * __s2, __locale_t __loc) throw()

 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3))); 

extern "C" int strncasecmp_l(const char * __s1, const char * __s2, size_t __n, __locale_t __loc) throw()

 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 4))); 
# 559
extern "C" char *strsep(char ** __stringp, const char * __delim) throw()

 __attribute((__nonnull__(1, 2))); 




extern "C" char *strsignal(int __sig) throw(); 


extern "C" char *__stpcpy(char * __dest, const char * __src) throw()
 __attribute((__nonnull__(1, 2))); 
extern "C" char *stpcpy(char * __dest, const char * __src) throw()
 __attribute((__nonnull__(1, 2))); 



extern "C" char *__stpncpy(char * __dest, const char * __src, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 
extern "C" char *stpncpy(char * __dest, const char * __src, size_t __n) throw()

 __attribute((__nonnull__(1, 2))); 




extern "C" int strverscmp(const char * __s1, const char * __s2) throw()
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 


extern "C" char *strfry(char * __string) throw() __attribute((__nonnull__(1))); 


extern "C" void *memfrob(void * __s, size_t __n) throw() __attribute((__nonnull__(1))); 
# 606
extern "C" char *basename(const char * __filename) throw() __attribute((__nonnull__(1))); 
# 74 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cstring" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::memchr;
using ::memcmp;
using ::memcpy;
using ::memmove;
using ::memset;
using ::strcat;
using ::strcmp;
using ::strcoll;
using ::strcpy;
using ::strcspn;
using ::strerror;
using ::strlen;
using ::strncat;
using ::strncmp;
using ::strncpy;
using ::strspn;
using ::strtok;
using ::strxfrm;
using ::strchr;
using ::strpbrk;
using ::strrchr;
using ::strstr;



inline void *memchr(void *__p, int __c, size_t __n) 
{ return memchr(const_cast< const void *>(__p), __c, __n); } 


inline char *strchr(char *__s1, int __n) 
{ return __builtin_strchr(const_cast< const char *>(__s1), __n); } 


inline char *strpbrk(char *__s1, const char *__s2) 
{ return __builtin_strpbrk(const_cast< const char *>(__s1), __s2); } 


inline char *strrchr(char *__s1, int __n) 
{ return __builtin_strrchr(const_cast< const char *>(__s1), __n); } 


inline char *strstr(char *__s1, const char *__s2) 
{ return __builtin_strstr(const_cast< const char *>(__s1), __s2); } 


}
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Data.h"
namespace hmpprt { 


class Device; 
class Queue; 



class Data { 
# 53
public: Data(Device * device, void * address, size_t size, size_t offset, MemorySpace memory_space, void * host_address = 0); 
# 62
Data(Device * device, size_t size, size_t offset, MemorySpace memory_space, void * host_address = 0); 
# 70
Data(Device * device, size_t size, MemorySpace memory_space, void * host_address = 0); 
# 78
Data(Device * device, size_t size, size_t offset = (0), void * host_address = 0); 


Data(const Data &); 


~Data(); 



Device *getDevice(); 



void setDevice(Device *device) { device_ = device; } 



size_t getSize() const; 



void setSize(size_t size) { size_ = size; } 



MemorySpace getMemorySpace() const; 



void setMemorySpace(MemorySpace ms) { memory_space_ = ms; } 



const char *getMemorySpaceName() const; 
# 118
void *getAddress() const; 
# 124
void setAddress(void * device_address); 



void allocate(); 



void free(); 
# 138
Data *createSubData(size_t size, size_t offset); 



void upload(const void * host_address, Queue * queue = 0); 
# 148
void upload(const void * host_address, size_t offset, size_t size, Queue * queue = 0); 



void download(void * host_address, Queue * queue = 0); 
# 158
void download(void * host_address, size_t offset, size_t size, Queue * queue = 0); 



void setmem(int value = (0)); 
# 168
void *getHandle() { return handle_; } 

void setHandle(void *h) { handle_ = h; } 
# 176
void *getHostAddress() { return host_address_; } 

void setHostAddress(void *host_address) { host_address_ = host_address; } 
# 184
void mapBuffer(Queue * queue = 0); 


void unMapBuffer(Queue * queue = 0); 
# 194
size_t getOffset() { return offset_; } 



void setOffset(size_t offset) { offset_ = offset; } 




bool isSubData() const { return is_subdata_; } 

void setIsSubData(bool is_subdata) { is_subdata_ = is_subdata; } 

void inhibateZeroCopy(bool zero_copy) { inhibate_zerocopy_overloading_ = zero_copy; } 
bool inhibateZeroCopy() { return inhibate_zerocopy_overloading_; } 
# 214
protected: Device *device_; 
size_t size_; 
size_t offset_; 
MemorySpace memory_space_; 
void *device_address_; 
void *host_address_; 
void *handle_; 
bool is_subdata_; 

bool inhibate_zerocopy_overloading_; 

}; 

}
# 63 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_list.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 71
struct _List_node_base { 

_List_node_base *_M_next; 
_List_node_base *_M_prev; 


static void swap(_List_node_base & __x, _List_node_base & __y); 


void transfer(_List_node_base *const __first, _List_node_base *const __last); 



void reverse(); 


void hook(_List_node_base *const __position); 


void unhook(); 
}; 


template < typename _Tp >
    struct _List_node : public _List_node_base
    {

      _Tp _M_data;






    };
# 112
template < typename _Tp >
    struct _List_iterator
    {
      typedef _List_iterator < _Tp > _Self;
      typedef _List_node < _Tp > _Node;

      typedef ptrdiff_t difference_type;
      typedef std :: bidirectional_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef _Tp * pointer;
      typedef _Tp & reference;

      _List_iterator ( )
      : _M_node ( ) { }

      explicit
      _List_iterator ( _List_node_base * __x )
      : _M_node ( __x ) { }


      reference
      operator * ( ) const
      { return static_cast < _Node * > ( _M_node ) -> _M_data; }

      pointer
      operator -> ( ) const
      { return & static_cast < _Node * > ( _M_node ) -> _M_data; }

      _Self &
      operator ++ ( )
      {
 _M_node = _M_node -> _M_next;
 return * this;
      }

      _Self
      operator ++ ( int )
      {
 _Self __tmp = * this;
 _M_node = _M_node -> _M_next;
 return __tmp;
      }

      _Self &
      operator -- ( )
      {
 _M_node = _M_node -> _M_prev;
 return * this;
      }

      _Self
      operator -- ( int )
      {
 _Self __tmp = * this;
 _M_node = _M_node -> _M_prev;
 return __tmp;
      }

      bool
      operator == ( const _Self & __x ) const
      { return _M_node == __x . _M_node; }

      bool
      operator != ( const _Self & __x ) const
      { return _M_node != __x . _M_node; }


      _List_node_base * _M_node;
    };
# 187
template < typename _Tp >
    struct _List_const_iterator
    {
      typedef _List_const_iterator < _Tp > _Self;
      typedef const _List_node < _Tp > _Node;
      typedef _List_iterator < _Tp > iterator;

      typedef ptrdiff_t difference_type;
      typedef std :: bidirectional_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef const _Tp * pointer;
      typedef const _Tp & reference;

      _List_const_iterator ( )
      : _M_node ( ) { }

      explicit
      _List_const_iterator ( const _List_node_base * __x )
      : _M_node ( __x ) { }

      _List_const_iterator ( const iterator & __x )
      : _M_node ( __x . _M_node ) { }



      reference
      operator * ( ) const
      { return static_cast < _Node * > ( _M_node ) -> _M_data; }

      pointer
      operator -> ( ) const
      { return & static_cast < _Node * > ( _M_node ) -> _M_data; }

      _Self &
      operator ++ ( )
      {
 _M_node = _M_node -> _M_next;
 return * this;
      }

      _Self
      operator ++ ( int )
      {
 _Self __tmp = * this;
 _M_node = _M_node -> _M_next;
 return __tmp;
      }

      _Self &
      operator -- ( )
      {
 _M_node = _M_node -> _M_prev;
 return * this;
      }

      _Self
      operator -- ( int )
      {
 _Self __tmp = * this;
 _M_node = _M_node -> _M_prev;
 return __tmp;
      }

      bool
      operator == ( const _Self & __x ) const
      { return _M_node == __x . _M_node; }

      bool
      operator != ( const _Self & __x ) const
      { return _M_node != __x . _M_node; }


      const _List_node_base * _M_node;
    };

template < typename _Val >
    inline bool
    operator == ( const _List_iterator < _Val > & __x,
        const _List_const_iterator < _Val > & __y )
    { return __x . _M_node == __y . _M_node; }

template < typename _Val >
    inline bool
    operator != ( const _List_iterator < _Val > & __x,
               const _List_const_iterator < _Val > & __y )
    { return __x . _M_node != __y . _M_node; }



template < typename _Tp, typename _Alloc >
    class _List_base
    {
    protected :













      typedef typename _Alloc :: template rebind < _List_node < _Tp > > :: other
        _Node_alloc_type;

      typedef typename _Alloc :: template rebind < _Tp > :: other _Tp_alloc_type;

      struct _List_impl
      : public _Node_alloc_type
      {
 _List_node_base _M_node;

 _List_impl ( )
 : _Node_alloc_type ( ), _M_node ( )
 { }

 _List_impl ( const _Node_alloc_type & __a )
 : _Node_alloc_type ( __a ), _M_node ( )
 { }
      };

      _List_impl _M_impl;

      _List_node < _Tp > *
      _M_get_node ( )
      { return _M_impl . _Node_alloc_type :: allocate ( 1 ); }

      void
      _M_put_node ( _List_node < _Tp > * __p )
      { _M_impl . _Node_alloc_type :: deallocate ( __p, 1 ); }

  public :
      typedef _Alloc allocator_type;

      _Node_alloc_type &
      _M_get_Node_allocator ( )
      { return * static_cast < _Node_alloc_type * > ( & this -> _M_impl ); }

      const _Node_alloc_type &
      _M_get_Node_allocator ( ) const
      { return * static_cast < const _Node_alloc_type * > ( & this -> _M_impl ); }

      _Tp_alloc_type
      _M_get_Tp_allocator ( ) const
      { return _Tp_alloc_type ( _M_get_Node_allocator ( ) ); }

      allocator_type
      get_allocator ( ) const
      { return allocator_type ( _M_get_Node_allocator ( ) ); }

      _List_base ( )
      : _M_impl ( )
      { _M_init ( ); }

      _List_base ( const allocator_type & __a )
      : _M_impl ( __a )
      { _M_init ( ); }











      ~ _List_base ( )
      { _M_clear ( ); }

      void
      _M_clear ( );

      void
      _M_init ( )
      {
        this -> _M_impl . _M_node . _M_next = & this -> _M_impl . _M_node;
        this -> _M_impl . _M_node . _M_prev = & this -> _M_impl . _M_node;
      }
    };
# 416
template < typename _Tp, typename _Alloc = std :: allocator < _Tp > >
    class list : protected _List_base < _Tp, _Alloc >
    {

      typedef typename _Alloc :: value_type _Alloc_value_type;



      typedef _List_base < _Tp, _Alloc > _Base;
      typedef typename _Base :: _Tp_alloc_type _Tp_alloc_type;

    public :
      typedef _Tp value_type;
      typedef typename _Tp_alloc_type :: pointer pointer;
      typedef typename _Tp_alloc_type :: const_pointer const_pointer;
      typedef typename _Tp_alloc_type :: reference reference;
      typedef typename _Tp_alloc_type :: const_reference const_reference;
      typedef _List_iterator < _Tp > iterator;
      typedef _List_const_iterator < _Tp > const_iterator;
      typedef std :: reverse_iterator < const_iterator > const_reverse_iterator;
      typedef std :: reverse_iterator < iterator > reverse_iterator;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Alloc allocator_type;

    protected :


      typedef _List_node < _Tp > _Node;

      using _Base :: _M_impl;
      using _Base :: _M_put_node;
      using _Base :: _M_get_node;
      using _Base :: _M_get_Tp_allocator;
      using _Base :: _M_get_Node_allocator;







      _Node *
      _M_create_node ( const value_type & __x )
      {
 _Node * __p = this -> _M_get_node ( );
 try
   {
     _M_get_Tp_allocator ( ) . construct ( & __p -> _M_data, __x );
   }
 catch ( ... )
   {
     _M_put_node ( __p );
     throw;
   }
 return __p;
      }




















    public :





      list ( )
      : _Base ( ) { }





      explicit
      list ( const allocator_type & __a )
      : _Base ( __a ) { }









      explicit
      list ( size_type __n, const value_type & __value = value_type ( ),
    const allocator_type & __a = allocator_type ( ) )
      : _Base ( __a )
      { _M_fill_initialize ( __n, __value ); }








      list ( const list & __x )
      : _Base ( __x . _M_get_Node_allocator ( ) )
      { _M_initialize_dispatch ( __x . begin ( ), __x . end ( ), __false_type ( ) ); }




































      template < typename _InputIterator >
        list ( _InputIterator __first, _InputIterator __last,
      const allocator_type & __a = allocator_type ( ) )
        : _Base ( __a )
        {

   typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
   _M_initialize_dispatch ( __first, __last, _Integral ( ) );
 }
















      list &
      operator = ( const list & __x );











































      void
      assign ( size_type __n, const value_type & __val )
      { _M_fill_assign ( __n, __val ); }













      template < typename _InputIterator >
        void
        assign ( _InputIterator __first, _InputIterator __last )
        {

   typedef typename std :: __is_integer < _InputIterator > :: __type _Integral;
   _M_assign_dispatch ( __first, __last, _Integral ( ) );
 }















      allocator_type
      get_allocator ( ) const
      { return _Base :: get_allocator ( ); }






      iterator
      begin ( )
      { return iterator ( this -> _M_impl . _M_node . _M_next ); }






      const_iterator
      begin ( ) const
      { return const_iterator ( this -> _M_impl . _M_node . _M_next ); }






      iterator
      end ( )
      { return iterator ( & this -> _M_impl . _M_node ); }






      const_iterator
      end ( ) const
      { return const_iterator ( & this -> _M_impl . _M_node ); }






      reverse_iterator
      rbegin ( )
      { return reverse_iterator ( end ( ) ); }






      const_reverse_iterator
      rbegin ( ) const
      { return const_reverse_iterator ( end ( ) ); }






      reverse_iterator
      rend ( )
      { return reverse_iterator ( begin ( ) ); }






      const_reverse_iterator
      rend ( ) const
      { return const_reverse_iterator ( begin ( ) ); }












































      bool
      empty ( ) const
      { return this -> _M_impl . _M_node . _M_next == & this -> _M_impl . _M_node; }


      size_type
      size ( ) const
      { return std :: distance ( begin ( ), end ( ) ); }


      size_type
      max_size ( ) const
      { return _M_get_Node_allocator ( ) . max_size ( ); }











      void
      resize ( size_type __new_size, value_type __x = value_type ( ) );






      reference
      front ( )
      { return * begin ( ); }





      const_reference
      front ( ) const
      { return * begin ( ); }





      reference
      back ( )
      {
 iterator __tmp = end ( );
 -- __tmp;
 return * __tmp;
      }





      const_reference
      back ( ) const
      {
 const_iterator __tmp = end ( );
 -- __tmp;
 return * __tmp;
      }












      void
      push_front ( const value_type & __x )
      { this -> _M_insert ( begin ( ), __x ); }
























      void
      pop_front ( )
      { this -> _M_erase ( begin ( ) ); }











      void
      push_back ( const value_type & __x )
      { this -> _M_insert ( end ( ), __x ); }























      void
      pop_back ( )
      { this -> _M_erase ( iterator ( this -> _M_impl . _M_node . _M_prev ) ); }






























      iterator
      insert ( iterator __position, const value_type & __x );















































      void
      insert ( iterator __position, size_type __n, const value_type & __x )
      {
 list __tmp ( __n, __x, _M_get_Node_allocator ( ) );
 splice ( __position, __tmp );
      }














      template < typename _InputIterator >
        void
        insert ( iterator __position, _InputIterator __first,
        _InputIterator __last )
        {
   list __tmp ( __first, __last, _M_get_Node_allocator ( ) );
   splice ( __position, __tmp );
 }
















      iterator
      erase ( iterator __position );



















      iterator
      erase ( iterator __first, iterator __last )
      {
 while ( __first != __last )
   __first = erase ( __first );
 return __last;
      }










      void



      swap ( list & __x )

      {
 _List_node_base :: swap ( this -> _M_impl . _M_node, __x . _M_impl . _M_node );



 std :: __alloc_swap < typename _Base :: _Node_alloc_type > ::
   _S_do_it ( _M_get_Node_allocator ( ), __x . _M_get_Node_allocator ( ) );
      }







      void
      clear ( )
      {
        _Base :: _M_clear ( );
        _Base :: _M_init ( );
      }













      void



      splice ( iterator __position, list & __x )

      {
 if ( ! __x . empty ( ) )
   {
     _M_check_equal_allocators ( __x );

     this -> _M_transfer ( __position, __x . begin ( ), __x . end ( ) );
   }
      }










      void



      splice ( iterator __position, list & __x, iterator __i )

      {
 iterator __j = __i;
 ++ __j;
 if ( __position == __i || __position == __j )
   return;

 if ( this != & __x )
   _M_check_equal_allocators ( __x );

 this -> _M_transfer ( __position, __i, __j );
      }













      void




      splice ( iterator __position, list & __x, iterator __first,
      iterator __last )

      {
 if ( __first != __last )
   {
     if ( this != & __x )
       _M_check_equal_allocators ( __x );

     this -> _M_transfer ( __position, __first, __last );
   }
      }












      void
      remove ( const _Tp & __value );












      template < typename _Predicate >
        void
        remove_if ( _Predicate );











      void
      unique ( );













      template < typename _BinaryPredicate >
        void
        unique ( _BinaryPredicate );










      void



      merge ( list & __x );














      template < typename _StrictWeakOrdering >
        void



        merge ( list &, _StrictWeakOrdering );







      void
      reverse ( )
      { this -> _M_impl . _M_node . reverse ( ); }







      void
      sort ( );







      template < typename _StrictWeakOrdering >
        void
        sort ( _StrictWeakOrdering );

    protected :






      template < typename _Integer >
        void
        _M_initialize_dispatch ( _Integer __n, _Integer __x, __true_type )
        { _M_fill_initialize ( static_cast < size_type > ( __n ), __x ); }


      template < typename _InputIterator >
        void
        _M_initialize_dispatch ( _InputIterator __first, _InputIterator __last,
          __false_type )
        {
   for (; __first != __last; ++ __first )
     push_back ( * __first );
 }



      void
      _M_fill_initialize ( size_type __n, const value_type & __x )
      {
 for (; __n > 0; -- __n )
   push_back ( __x );
      }








      template < typename _Integer >
        void
        _M_assign_dispatch ( _Integer __n, _Integer __val, __true_type )
        { _M_fill_assign ( __n, __val ); }


      template < typename _InputIterator >
        void
        _M_assign_dispatch ( _InputIterator __first, _InputIterator __last,
      __false_type );



      void
      _M_fill_assign ( size_type __n, const value_type & __val );



      void
      _M_transfer ( iterator __position, iterator __first, iterator __last )
      { __position . _M_node -> transfer ( __first . _M_node, __last . _M_node ); }



      void
      _M_insert ( iterator __position, const value_type & __x )
      {
        _Node * __tmp = _M_create_node ( __x );
        __tmp -> hook ( __position . _M_node );
      }











      void
      _M_erase ( iterator __position )
      {
        __position . _M_node -> unhook ( );
        _Node * __n = static_cast < _Node * > ( __position . _M_node );



 _M_get_Tp_allocator ( ) . destroy ( & __n -> _M_data );

        _M_put_node ( __n );
      }


      void
      _M_check_equal_allocators ( list & __x )
      {
 if ( std :: __alloc_neq < typename _Base :: _Node_alloc_type > ::
     _S_do_it ( _M_get_Node_allocator ( ), __x . _M_get_Node_allocator ( ) ) )
   __throw_runtime_error ( ( "list::_M_check_equal_allocators" ) );
      }
    };
# 1454
template < typename _Tp, typename _Alloc >
    inline bool
    operator == ( const list < _Tp, _Alloc > & __x, const list < _Tp, _Alloc > & __y )
    {
      typedef typename list < _Tp, _Alloc > :: const_iterator const_iterator;
      const_iterator __end1 = __x . end ( );
      const_iterator __end2 = __y . end ( );

      const_iterator __i1 = __x . begin ( );
      const_iterator __i2 = __y . begin ( );
      while ( __i1 != __end1 && __i2 != __end2 && * __i1 == * __i2 )
 {
   ++ __i1;
   ++ __i2;
 }
      return __i1 == __end1 && __i2 == __end2;
    }
# 1483
template < typename _Tp, typename _Alloc >
    inline bool
    operator < ( const list < _Tp, _Alloc > & __x, const list < _Tp, _Alloc > & __y )
    { return std :: lexicographical_compare ( __x . begin ( ), __x . end ( ),
       __y . begin ( ), __y . end ( ) ); }


template < typename _Tp, typename _Alloc >
    inline bool
    operator != ( const list < _Tp, _Alloc > & __x, const list < _Tp, _Alloc > & __y )
    { return ! ( __x == __y ); }


template < typename _Tp, typename _Alloc >
    inline bool
    operator > ( const list < _Tp, _Alloc > & __x, const list < _Tp, _Alloc > & __y )
    { return __y < __x; }


template < typename _Tp, typename _Alloc >
    inline bool
    operator <= ( const list < _Tp, _Alloc > & __x, const list < _Tp, _Alloc > & __y )
    { return ! ( __y < __x ); }


template < typename _Tp, typename _Alloc >
    inline bool
    operator >= ( const list < _Tp, _Alloc > & __x, const list < _Tp, _Alloc > & __y )
    { return ! ( __x < __y ); }


template < typename _Tp, typename _Alloc >
    inline void
    swap ( list < _Tp, _Alloc > & __x, list < _Tp, _Alloc > & __y )
    { __x . swap ( __y ); }
# 1531
}
# 60 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/list.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _Tp, typename _Alloc >
    void
    _List_base < _Tp, _Alloc > ::
    _M_clear ( )
    {
      typedef _List_node < _Tp > _Node;
      _Node * __cur = static_cast < _Node * > ( this -> _M_impl . _M_node . _M_next );
      while ( __cur != & this -> _M_impl . _M_node )
 {
   _Node * __tmp = __cur;
   __cur = static_cast < _Node * > ( __cur -> _M_next );



   _M_get_Tp_allocator ( ) . destroy ( & __tmp -> _M_data );

   _M_put_node ( __tmp );
 }
    }
# 95
template < typename _Tp, typename _Alloc >
    typename list < _Tp, _Alloc > :: iterator
    list < _Tp, _Alloc > ::
    insert ( iterator __position, const value_type & __x )
    {
      _Node * __tmp = _M_create_node ( __x );
      __tmp -> hook ( __position . _M_node );
      return iterator ( __tmp );
    }

template < typename _Tp, typename _Alloc >
    typename list < _Tp, _Alloc > :: iterator
    list < _Tp, _Alloc > ::
    erase ( iterator __position )
    {
      iterator __ret = iterator ( __position . _M_node -> _M_next );
      _M_erase ( __position );
      return __ret;
    }

template < typename _Tp, typename _Alloc >
    void
    list < _Tp, _Alloc > ::
    resize ( size_type __new_size, value_type __x )
    {
      iterator __i = begin ( );
      size_type __len = 0;
      for (; __i != end ( ) && __len < __new_size; ++ __i, ++ __len )
        ;
      if ( __len == __new_size )
        erase ( __i, end ( ) );
      else
        insert ( end ( ), __new_size - __len, __x );
    }

template < typename _Tp, typename _Alloc >
    list < _Tp, _Alloc > &
    list < _Tp, _Alloc > ::
    operator = ( const list & __x )
    {
      if ( this != & __x )
 {
   iterator __first1 = begin ( );
   iterator __last1 = end ( );
   const_iterator __first2 = __x . begin ( );
   const_iterator __last2 = __x . end ( );
   for (; __first1 != __last1 && __first2 != __last2;
        ++ __first1, ++ __first2 )
     * __first1 = * __first2;
   if ( __first2 == __last2 )
     erase ( __first1, __last1 );
   else
     insert ( __last1, __first2, __last2 );
 }
      return * this;
    }

template < typename _Tp, typename _Alloc >
    void
    list < _Tp, _Alloc > ::
    _M_fill_assign ( size_type __n, const value_type & __val )
    {
      iterator __i = begin ( );
      for (; __i != end ( ) && __n > 0; ++ __i, -- __n )
        * __i = __val;
      if ( __n > 0 )
        insert ( end ( ), __n, __val );
      else
        erase ( __i, end ( ) );
    }

template < typename _Tp, typename _Alloc >
    template < typename _InputIterator >
      void
      list < _Tp, _Alloc > ::
      _M_assign_dispatch ( _InputIterator __first2, _InputIterator __last2,
    __false_type )
      {
        iterator __first1 = begin ( );
        iterator __last1 = end ( );
        for (; __first1 != __last1 && __first2 != __last2;
      ++ __first1, ++ __first2 )
          * __first1 = * __first2;
        if ( __first2 == __last2 )
          erase ( __first1, __last1 );
        else
          insert ( __last1, __first2, __last2 );
      }

template < typename _Tp, typename _Alloc >
    void
    list < _Tp, _Alloc > ::
    remove ( const value_type & __value )
    {
      iterator __first = begin ( );
      iterator __last = end ( );
      iterator __extra = __last;
      while ( __first != __last )
 {
   iterator __next = __first;
   ++ __next;
   if ( * __first == __value )
     {



       if ( & * __first != & __value )
  _M_erase ( __first );
       else
  __extra = __first;
     }
   __first = __next;
 }
      if ( __extra != __last )
 _M_erase ( __extra );
    }

template < typename _Tp, typename _Alloc >
    void
    list < _Tp, _Alloc > ::
    unique ( )
    {
      iterator __first = begin ( );
      iterator __last = end ( );
      if ( __first == __last )
 return;
      iterator __next = __first;
      while ( ++ __next != __last )
 {
   if ( * __first == * __next )
     _M_erase ( __next );
   else
     __first = __next;
   __next = __first;
 }
    }

template < typename _Tp, typename _Alloc >
    void
    list < _Tp, _Alloc > ::



    merge ( list & __x )

    {


      if ( this != & __x )
 {
   _M_check_equal_allocators ( __x );

   iterator __first1 = begin ( );
   iterator __last1 = end ( );
   iterator __first2 = __x . begin ( );
   iterator __last2 = __x . end ( );
   while ( __first1 != __last1 && __first2 != __last2 )
     if ( * __first2 < * __first1 )
       {
  iterator __next = __first2;
  _M_transfer ( __first1, __first2, ++ __next );
  __first2 = __next;
       }
     else
       ++ __first1;
   if ( __first2 != __last2 )
     _M_transfer ( __last1, __first2, __last2 );
 }
    }

template < typename _Tp, typename _Alloc >
    template < typename _StrictWeakOrdering >
      void
      list < _Tp, _Alloc > ::



      merge ( list & __x, _StrictWeakOrdering __comp )

      {


 if ( this != & __x )
   {
     _M_check_equal_allocators ( __x );

     iterator __first1 = begin ( );
     iterator __last1 = end ( );
     iterator __first2 = __x . begin ( );
     iterator __last2 = __x . end ( );
     while ( __first1 != __last1 && __first2 != __last2 )
       if ( __comp ( * __first2, * __first1 ) )
  {
    iterator __next = __first2;
    _M_transfer ( __first1, __first2, ++ __next );
    __first2 = __next;
  }
       else
  ++ __first1;
     if ( __first2 != __last2 )
       _M_transfer ( __last1, __first2, __last2 );
   }
      }

template < typename _Tp, typename _Alloc >
    void
    list < _Tp, _Alloc > ::
    sort ( )
    {

      if ( this -> _M_impl . _M_node . _M_next != & this -> _M_impl . _M_node
   && this -> _M_impl . _M_node . _M_next -> _M_next != & this -> _M_impl . _M_node )
      {
        list __carry;
        list __tmp [ 64 ];
        list * __fill = & __tmp [ 0 ];
        list * __counter;

        do
   {
     __carry . splice ( __carry . begin ( ), * this, begin ( ) );

     for ( __counter = & __tmp [ 0 ];
  __counter != __fill && ! __counter -> empty ( );
  ++ __counter )
       {
  __counter -> merge ( __carry );
  __carry . swap ( * __counter );
       }
     __carry . swap ( * __counter );
     if ( __counter == __fill )
       ++ __fill;
   }
 while ( ! empty ( ) );

        for ( __counter = & __tmp [ 1 ]; __counter != __fill; ++ __counter )
          __counter -> merge ( * ( __counter - 1 ) );
        swap ( * ( __fill - 1 ) );
      }
    }

template < typename _Tp, typename _Alloc >
    template < typename _Predicate >
      void
      list < _Tp, _Alloc > ::
      remove_if ( _Predicate __pred )
      {
        iterator __first = begin ( );
        iterator __last = end ( );
        while ( __first != __last )
   {
     iterator __next = __first;
     ++ __next;
     if ( __pred ( * __first ) )
       _M_erase ( __first );
     __first = __next;
   }
      }

template < typename _Tp, typename _Alloc >
    template < typename _BinaryPredicate >
      void
      list < _Tp, _Alloc > ::
      unique ( _BinaryPredicate __binary_pred )
      {
        iterator __first = begin ( );
        iterator __last = end ( );
        if ( __first == __last )
   return;
        iterator __next = __first;
        while ( ++ __next != __last )
   {
     if ( __binary_pred ( * __first, * __next ) )
       _M_erase ( __next );
     else
       __first = __next;
     __next = __first;
   }
      }

template < typename _Tp, typename _Alloc >
    template < typename _StrictWeakOrdering >
      void
      list < _Tp, _Alloc > ::
      sort ( _StrictWeakOrdering __comp )
      {

 if ( this -> _M_impl . _M_node . _M_next != & this -> _M_impl . _M_node
     && this -> _M_impl . _M_node . _M_next -> _M_next != & this -> _M_impl . _M_node )
   {
     list __carry;
     list __tmp [ 64 ];
     list * __fill = & __tmp [ 0 ];
     list * __counter;

     do
       {
  __carry . splice ( __carry . begin ( ), * this, begin ( ) );

  for ( __counter = & __tmp [ 0 ];
      __counter != __fill && ! __counter -> empty ( );
      ++ __counter )
    {
      __counter -> merge ( __carry, __comp );
      __carry . swap ( * __counter );
    }
  __carry . swap ( * __counter );
  if ( __counter == __fill )
    ++ __fill;
       }
     while ( ! empty ( ) );

     for ( __counter = & __tmp [ 1 ]; __counter != __fill; ++ __counter )
       __counter -> merge ( * ( __counter - 1 ), __comp );
     swap ( * ( __fill - 1 ) );
   }
      }

}
# 37 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/ArgumentList.h"
namespace hmpprt { 


class Codelet; 
class Data; 
class Context; 


typedef void GlobalDataProxy(Context *); 




class ArgumentList { 



public: ArgumentList(GlobalDataProxy * proxy = 0); 

ArgumentList(const ArgumentList &); 

~ArgumentList(); 




void addDataArgument(Data *data) { this->addArgument().data = data; } 

void addDataArgument(Data &data) { this->addDataArgument(&data); } 

void addArgument(Data *data) { this->addDataArgument(data); } 

void addArgument(Data &data) { this->addDataArgument(&data); } 
# 75
void addArgumentByCopy(const void * addr, size_t size); 
template < typename T >
  void addArgument ( const T & n ) { addArgumentByCopy ( & n, sizeof ( T ) ); }




int getNumberOfArguments() const { return args_count_; } 



void getArgumentValues(void * args[]); 



void mapData(Context * context); 



Data *getDataAt(int i) { return this->getArgumentAt(i).data; } 



void addArgumentFrom(const ArgumentList &source, int i) { source.getArgumentAt(i).clone(this->addArgument()); } 


private: GlobalDataProxy *proxy_; 

struct Argument { 

void clone(Argument &) const; 

Data *data; 
char *value; 
size_t size; 
}; 

const Argument &getArgumentAt(int i) const { return this->ptArgs()[i]; } 
Argument &addArgument(); 

static const int ARGS_COUNT = 10; 
Argument st_args_[ARGS_COUNT]; 
int args_count_; 
std::vector< Argument>  dn_args_; 

const Argument *ptArgs() const { return (args_count_ <= ARGS_COUNT) ? (st_args_) : (dn_args_).data(); } 
Argument *ptArgs() { return (args_count_ <= ARGS_COUNT) ? (st_args_) : (dn_args_).data(); } 

ArgumentList &operator=(const ArgumentList &); 
}; 


}
# 29 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Intent.h"
namespace hmpprt { 



enum Intent { 

INTENT_UNUSED, 
INTENT_IN, 
INTENT_OUT, 
INTENT_INOUT
}; 


const char *get_intent_name(Intent intent); 

}
# 35 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Queue.h"
namespace hmpprt { 

class Operation { 


public: virtual ~Operation(); 
virtual const char *name() const = 0; 
virtual std::string dump() const = 0; 
virtual void run(Queue * parent) = 0; 
}; 

class OperationList { 


public: OperationList() : size_(0), top_(0), heap_() 



{ } 
void *allocate(); 
void push() { ++size_; } 
void clear() { size_ = 0; top_ = 0; } 
bool empty() { return size_ == 0; } 
bool pop(Operation *); 


private: int size_; 
int top_; 
std::vector< char>  heap_; 
}; 

class Queue : private NonCopyable { 



public: Queue(); 


~Queue(); 




void start(); 
# 85
bool wait(size_t timeout_ms); 




void wait(); 




void execute(); 



void clear(); 



bool finished(); 




void enqueueAcquire(Device * d); 

void enqueueRelease(Device * d); 

void enqueueCall(Device * d, Codelet * c, ArgumentList & a); 

void enqueueAllocate(Data * d); 

void enqueueReshape(Data * dst, Data * src); 

void enqueueSetMultiDimPointers(Data * d, size_t * offsets_arrays, size_t offsets_arrays_size, size_t offsets_arrays_nb_elem); 

void enqueueFree(Data * d); 

void enqueueUpload(Data * d, const void * ha); 

void enqueueUpload(Data * d, const void * ha, size_t offset, size_t size); 

void enqueueDownload(Data * d, void * ha); 

void enqueueDownload(Data * d, void * ha, size_t offset, size_t size); 

void enqueueCopy(Data * dst, Data * src); 

void enqueueExecute(Queue * q); 

void enqueueStart(Queue * q); 

void enqueueWait(Queue * q); 

void enqueueWait(Queue * q, size_t timeout_ms); 

void enqueueClear(Queue * q); 

void enqueueDelete(Data * d); 



static void create_thread_pool(); 




void *getHandle(); 

void registerHandle(Device *, void *); 
# 159
void enqueueMap(Data * d); 

void enqueueUnmap(Data * d); 
# 167
void runOperations(); 


private: bool runOneOperation(); 
void propagateException(void *); 

void *sem_; 
void *mutex_; 
int waiters_; 
void *handle_; 
void *result_; 
bool started_; 
Device *device_; 
OperationList operations_; 
}; 



inline void acquire(Device *d) { d->acquire(); } 
inline void release(Device *d) { d->release(); } 
inline void call(Device *d, Codelet *c, ArgumentList &a) { d->call(c, a); } 
inline void allocate(Data *d) { d->allocate(); } 

void setMultiDimPointers(Data * d, size_t * offsets_arrays, size_t offsets_arrays_size, size_t offsets_arrays_nb_elem); 
inline void reshape(Data *dst, Data *src) { dst->setAddress(src->getAddress()); } 
inline void free(Data *d) { d->free(); } 
inline void upload(Data *d, const void *ha) { d->upload(ha); } 
inline void upload(Data *d, const void *ha, size_t offset, size_t size) { d->upload(ha, offset, size); } 
inline void download(Data *d, void *ha) { d->download(ha); } 
inline void download(Data *d, void *ha, size_t offset, size_t size) { d->download(ha, offset, size); } 
inline void setmem(Data *d, int value) { d->setmem(value); } 

void copy(Data * dst, Data * src, Queue * q = 0); 
inline void execute(Queue *q) { q->execute(); } 
inline void start(Queue *q) { q->start(); } 
inline void wait(Queue *q) { q->wait(); } 
inline void wait(Queue *q, size_t timeout_ms) { q->wait(timeout_ms); } 
inline void clear(Queue *q) { q->clear(); } 

}
# 37 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Codelet.h"
namespace hmpprt { 


class Grouplet; 
class Device; 
class ArgumentList; 
# 50
class Codelet : private NonCopyable { 

friend class Grouplet; 


Codelet(Grouplet * grouplet, const std::string & name, void (* function)(void), void * signature); 



public: ~Codelet(); 



Grouplet *getGrouplet(); 
# 69
MemorySpace getMemorySpaceByIndex(int index); 
# 75
MemorySpace getMemorySpaceByName(const std::string & name); 




Intent getIntentByIndex(int index); 



const std::string &getName() const; 



void call(Device * device, ArgumentList & arguments, Queue * queue = 0); 



int getNumberOfParameters() const; 




bool getValueSizeByIndex(int index, size_t & size) const; 



std::string getNameByIndex(int index) const; 


private: Grouplet *grouplet_; 
std::string name_; 
void (*function_)(void); 
void *signature_; 
void *ffi_; 

}; 

}
# 31 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/HostDevice.h"
namespace hmpprt { 




class HostDevice : public Device { 



public: static void create_devices(DeviceList &); 

virtual ~HostDevice(); 

virtual MemorySpace getDefaultMemorySpace() const; 

virtual bool hasDoublePrecision() const; 

virtual bool hasHostMemoryIntegration() const; 


virtual unsigned getDeviceMaxClockRate() const; 

virtual void allocate(Data * data); 

virtual void free(Data * data); 

virtual Data *createSubData(Data * data, size_t size, size_t offset); 

virtual void upload(Data * data, const void * host_address, size_t offset, size_t size, Queue * q = 0); 

virtual void download(Data * data, void * host_address, size_t offset, size_t size, Queue * q = 0); 

virtual void setmem(Data * data, int value = (0)); 

virtual void releaseHandle(void * handle); 

virtual void synchronize(Queue * queue = 0); 

virtual bool isPageLocked(void * host_address, size_t size); 

virtual void replaceAllocs(int substitute); 

virtual bool checkDeviceData(void * device_address, void * host_address, size_t size, Queue * queue); 

virtual bool hasPhysicalAddresses(); 


virtual void createContext(); 

virtual void *getVendorDeviceHandle() { return 0; } 

virtual void *getVendorDeviceContext() { return 0; } 


protected: HostDevice(unsigned long id, const std::string & label); 

}; 

}
# 29 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Measure.h"
namespace hmpprt { 


unsigned long get_time_microseconds(); 


unsigned long get_time_cycles(); 
}
# 45 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/locale_classes.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 61
class locale { 




public: typedef int category; 


class facet; 
class id; 
class _Impl; 

friend class facet; 
friend class _Impl; 

template < typename _Facet >
      friend bool
      has_facet ( const locale & ) throw ( );

template < typename _Facet >
      friend const _Facet &
      use_facet ( const locale & );

template < typename _Cache >
      friend struct __use_cache;
# 97
static const category none = 0; 
static const category ctype = (1L << 0); 
static const category numeric = (1L << 1); 
static const category collate = (1L << 2); 
static const category time = (1L << 3); 
static const category monetary = (1L << 4); 
static const category messages = (1L << 5); 
static const category all = (((((ctype | numeric) | collate) | time) | monetary) | messages); 
# 116
locale() throw(); 
# 125
locale(const locale & __other) throw(); 
# 136
explicit locale(const char * __s); 
# 150
locale(const locale & __base, const char * __s, category __cat); 
# 163
locale(const locale & __base, const locale & __add, category __cat); 
# 175
template < typename _Facet >
      locale ( const locale & __other, _Facet * __f );


~locale() throw(); 
# 190
const locale &operator=(const locale & __other) throw(); 
# 204
template < typename _Facet >
      locale
      combine ( const locale & __other ) const;
# 214
string name() const; 
# 224
bool operator==(const locale & __other) const throw(); 
# 233
bool operator!=(const locale &__other) const throw() 
{ return !this->operator==(__other); } 
# 251
template < typename _Char, typename _Traits, typename _Alloc >
      bool
      operator ( ) ( const basic_string < _Char, _Traits, _Alloc > & __s1,
   const basic_string < _Char, _Traits, _Alloc > & __s2 ) const;
# 268
static locale global(const locale &); 
# 274
static const locale &classic(); 



private: _Impl *_M_impl; 


static _Impl *_S_classic; 


static _Impl *_S_global; 
# 290
static const char *const *const _S_categories; 
# 302
enum { _S_categories_size = 12}; 


static __gthread_once_t _S_once; 



explicit locale(_Impl *) throw(); 


static void _S_initialize(); 


static void _S_initialize_once(); 


static category _S_normalize_category(category); 


void _M_coalesce(const locale & __base, const locale & __add, category __cat); 
}; 
# 335
class locale::facet { 


friend class locale; 
friend class _Impl; 

mutable _Atomic_word _M_refcount; 


static __c_locale _S_c_locale; 


static const char _S_c_name[2]; 


static __gthread_once_t _S_once; 



static void _S_initialize_once(); 
# 367
protected: explicit facet(size_t __refs = (0)) throw() : _M_refcount((__refs) ? 1 : 0) 
{ } 



virtual ~facet(); 


static void _S_create_c_locale(__c_locale & __cloc, const char * __s, __c_locale __old = 0); 



static __c_locale _S_clone_c_locale(__c_locale & __cloc); 


static void _S_destroy_c_locale(__c_locale & __cloc); 




static __c_locale _S_get_c_locale(); 


static const char *_S_get_c_name(); 



private: void _M_add_reference() const throw() 
{ __gnu_cxx::__atomic_add_dispatch(&(_M_refcount), 1); } 


void _M_remove_reference() const throw() 
{ 
if (__gnu_cxx::__exchange_and_add_dispatch(&(_M_refcount), -1) == 1) 
{ 
try 
{ delete this; } 
catch (...) 
{ }  
}  
} 

facet(const facet &); 


facet &operator=(const facet &); 
}; 
# 426
class locale::id { 


friend class locale; 
friend class _Impl; 

template < typename _Facet >
      friend const _Facet &
      use_facet ( const locale & );

template < typename _Facet >
      friend bool
      has_facet ( const locale & ) throw ( );




mutable size_t _M_index; 


static _Atomic_word _S_refcount; 


void operator=(const id &); 

id(const id &); 
# 457
public: id() { } 


size_t _M_id() const; 
}; 



class locale::_Impl { 



friend class locale; 
friend class facet; 

template < typename _Facet >
      friend bool
      has_facet ( const locale & ) throw ( );

template < typename _Facet >
      friend const _Facet &
      use_facet ( const locale & );

template < typename _Cache >
      friend struct __use_cache;



_Atomic_word _M_refcount; 
const facet **_M_facets; 
size_t _M_facets_size; 
const facet **_M_caches; 
char **_M_names; 
static const id *const _S_id_ctype[]; 
static const id *const _S_id_numeric[]; 
static const id *const _S_id_collate[]; 
static const id *const _S_id_time[]; 
static const id *const _S_id_monetary[]; 
static const id *const _S_id_messages[]; 
static const id *const *const _S_facet_categories[]; 


void _M_add_reference() throw() 
{ __gnu_cxx::__atomic_add_dispatch(&(_M_refcount), 1); } 


void _M_remove_reference() throw() 
{ 
if (__gnu_cxx::__exchange_and_add_dispatch(&(_M_refcount), -1) == 1) 
{ 
try 
{ delete this; } 
catch (...) 
{ }  
}  
} 

_Impl(const _Impl &, size_t); 
_Impl(const char *, size_t); 
_Impl(size_t) throw(); 

~_Impl() throw(); 

_Impl(const _Impl &); 


void operator=(const _Impl &); 


bool _M_check_same_name() 
{ 
bool __ret = true; 
if ((_M_names)[1]) { 

for (size_t __i = (0); __ret && __i < (_S_categories_size) - 1; ++__i) { 
__ret = __builtin_strcmp((_M_names)[__i], (_M_names)[__i + (1)]) == 0; }  }  
return __ret; 
} 


void _M_replace_categories(const _Impl *, category); 


void _M_replace_category(const _Impl *, const id *const *); 


void _M_replace_facet(const _Impl *, const id *); 


void _M_install_facet(const id *, const facet *); 

template < typename _Facet >
      void
      _M_init_facet ( _Facet * __facet )
      { _M_install_facet ( & _Facet :: id, __facet ); }


void _M_install_cache(const facet *, size_t); 
}; 
# 569
template < typename _Facet >
    bool
    has_facet ( const locale & __loc ) throw ( );
# 586
template < typename _Facet >
    const _Facet &
    use_facet ( const locale & __loc );
# 603
template < typename _CharT >
    class collate : public locale :: facet
    {
    public :



      typedef _CharT char_type;
      typedef basic_string < _CharT > string_type;


    protected :


      __c_locale _M_c_locale_collate;

    public :

      static locale :: id id;








      explicit
      collate ( size_t __refs = 0 )
      : facet ( __refs ), _M_c_locale_collate ( _S_get_c_locale ( ) )
      { }










      explicit
      collate ( __c_locale __cloc, size_t __refs = 0 )
      : facet ( __refs ), _M_c_locale_collate ( _S_clone_c_locale ( __cloc ) )
      { }













      int
      compare ( const _CharT * __lo1, const _CharT * __hi1,
       const _CharT * __lo2, const _CharT * __hi2 ) const
      { return this -> do_compare ( __lo1, __hi1, __lo2, __hi2 ); }















      string_type
      transform ( const _CharT * __lo, const _CharT * __hi ) const
      { return this -> do_transform ( __lo, __hi ); }











      long
      hash ( const _CharT * __lo, const _CharT * __hi ) const
      { return this -> do_hash ( __lo, __hi ); }


      int
      _M_compare ( const _CharT *, const _CharT * ) const;

      size_t
      _M_transform ( _CharT *, const _CharT *, size_t ) const;

  protected :

      virtual
      ~ collate ( )
      { _S_destroy_c_locale ( _M_c_locale_collate ); }













      virtual int
      do_compare ( const _CharT * __lo1, const _CharT * __hi1,
   const _CharT * __lo2, const _CharT * __hi2 ) const;













      virtual string_type
      do_transform ( const _CharT * __lo, const _CharT * __hi ) const;











      virtual long
      do_hash ( const _CharT * __lo, const _CharT * __hi ) const;
    };

template < typename _CharT >
    locale :: id collate < _CharT > :: id;




template<> int collate< char> ::_M_compare(const char *, const char *) const; 



template<> size_t collate< char> ::_M_transform(char *, const char *, size_t) const; 




template<> int collate< wchar_t> ::_M_compare(const wchar_t *, const wchar_t *) const; 



template<> size_t collate< wchar_t> ::_M_transform(wchar_t *, const wchar_t *, size_t) const; 



template < typename _CharT >
    class collate_byname : public collate < _CharT >
    {
    public :


      typedef _CharT char_type;
      typedef basic_string < _CharT > string_type;


      explicit
      collate_byname ( const char * __s, size_t __refs = 0 )
      : collate < _CharT > ( __refs )
      {
 if ( __builtin_strcmp ( __s, "C" ) != 0
     && __builtin_strcmp ( __s, "POSIX" ) != 0 )
   {
     this -> _S_destroy_c_locale ( this -> _M_c_locale_collate );
     this -> _S_create_c_locale ( this -> _M_c_locale_collate, __s );
   }
      }

    protected :
      virtual
      ~ collate_byname ( ) { }
    };

}
# 39 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/locale_classes.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _Facet >
    locale ::
    locale ( const locale & __other, _Facet * __f )
    {
      _M_impl = new _Impl ( * __other . _M_impl, 1 );

      try
 { _M_impl -> _M_install_facet ( & _Facet :: id, __f ); }
      catch ( ... )
 {
   _M_impl -> _M_remove_reference ( );
   throw;
 }
      delete [ ] _M_impl -> _M_names [ 0 ];
      _M_impl -> _M_names [ 0 ] = 0;
    }

template < typename _Facet >
    locale
    locale ::
    combine ( const locale & __other ) const
    {
      _Impl * __tmp = new _Impl ( * _M_impl, 1 );
      try
 {
   __tmp -> _M_replace_facet ( __other . _M_impl, & _Facet :: id );
 }
      catch ( ... )
 {
   __tmp -> _M_remove_reference ( );
   throw;
 }
      return locale ( __tmp );
    }

template < typename _CharT, typename _Traits, typename _Alloc >
    bool
    locale ::
    operator ( ) ( const basic_string < _CharT, _Traits, _Alloc > & __s1,
        const basic_string < _CharT, _Traits, _Alloc > & __s2 ) const
    {
      typedef std :: collate < _CharT > __collate_type;
      const __collate_type & __collate = use_facet < __collate_type > ( * this );
      return ( __collate . compare ( __s1 . data ( ), __s1 . data ( ) + __s1 . length ( ),
    __s2 . data ( ), __s2 . data ( ) + __s2 . length ( ) ) < 0 );
    }


template < typename _Facet >
    bool
    has_facet ( const locale & __loc ) throw ( )
    {
      const size_t __i = _Facet :: id . _M_id ( );
      const locale :: facet * * __facets = __loc . _M_impl -> _M_facets;
      return ( __i < __loc . _M_impl -> _M_facets_size

       && dynamic_cast < const _Facet * > ( __facets [ __i ] ) );



    }

template < typename _Facet >
    const _Facet &
    use_facet ( const locale & __loc )
    {
      const size_t __i = _Facet :: id . _M_id ( );
      const locale :: facet * * __facets = __loc . _M_impl -> _M_facets;
      if ( __i >= __loc . _M_impl -> _M_facets_size || ! __facets [ __i ] )
        __throw_bad_cast ( );

      return dynamic_cast < const _Facet & > ( * __facets [ __i ] );



    }



template < typename _CharT >
    int
    collate < _CharT > :: _M_compare ( const _CharT *, const _CharT * ) const
    { return 0; }


template < typename _CharT >
    size_t
    collate < _CharT > :: _M_transform ( _CharT *, const _CharT *, size_t ) const
    { return 0; }

template < typename _CharT >
    int
    collate < _CharT > ::
    do_compare ( const _CharT * __lo1, const _CharT * __hi1,
        const _CharT * __lo2, const _CharT * __hi2 ) const
    {


      const string_type __one ( __lo1, __hi1 );
      const string_type __two ( __lo2, __hi2 );

      const _CharT * __p = __one . c_str ( );
      const _CharT * __pend = __one . data ( ) + __one . length ( );
      const _CharT * __q = __two . c_str ( );
      const _CharT * __qend = __two . data ( ) + __two . length ( );




      for (;; )
 {
   const int __res = _M_compare ( __p, __q );
   if ( __res )
     return __res;

   __p += char_traits < _CharT > :: length ( __p );
   __q += char_traits < _CharT > :: length ( __q );
   if ( __p == __pend && __q == __qend )
     return 0;
   else if ( __p == __pend )
     return - 1;
   else if ( __q == __qend )
     return 1;

   __p ++;
   __q ++;
 }
    }

template < typename _CharT >
    typename collate < _CharT > :: string_type
    collate < _CharT > ::
    do_transform ( const _CharT * __lo, const _CharT * __hi ) const
    {
      string_type __ret;


      const string_type __str ( __lo, __hi );

      const _CharT * __p = __str . c_str ( );
      const _CharT * __pend = __str . data ( ) + __str . length ( );

      size_t __len = ( __hi - __lo ) * 2;

      _CharT * __c = new _CharT [ __len ];

      try
 {



   for (;; )
     {

       size_t __res = _M_transform ( __c, __p, __len );


       if ( __res >= __len )
  {
    __len = __res + 1;
    delete [ ] __c, __c = 0;
    __c = new _CharT [ __len ];
    __res = _M_transform ( __c, __p, __len );
  }

       __ret . append ( __c, __res );
       __p += char_traits < _CharT > :: length ( __p );
       if ( __p == __pend )
  break;

       __p ++;
       __ret . push_back ( _CharT ( ) );
     }
 }
      catch ( ... )
 {
   delete [ ] __c;
   throw;
 }

      delete [ ] __c;

      return __ret;
    }

template < typename _CharT >
    long
    collate < _CharT > ::
    do_hash ( const _CharT * __lo, const _CharT * __hi ) const
    {
      unsigned long __val = 0;
      for (; __lo < __hi; ++ __lo )
 __val =
   * __lo + ( ( __val << 7 )
     | ( __val >> ( __gnu_cxx :: __numeric_traits < unsigned long > ::
    __digits - 7 ) ) );
      return static_cast < long > ( __val );
    }
# 244
extern template class collate< char> ;
extern template class collate_byname< char> ;

extern template const collate< char>  &use_facet< collate< char> > (const locale &);



extern template bool has_facet< collate< char> > (const locale &) throw();




extern template class collate< wchar_t> ;
extern template class collate_byname< wchar_t> ;

extern template const collate< wchar_t>  &use_facet< collate< wchar_t> > (const locale &);



extern template bool has_facet< collate< wchar_t> > (const locale &) throw();
# 269
}
# 54 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/ios_base.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 60
enum _Ios_Fmtflags { 

_S_boolalpha = 1, 
_S_dec, 
_S_fixed = 4, 
_S_hex = 8, 
_S_internal = 16, 
_S_left = 32, 
_S_oct = 64, 
_S_right = 128, 
_S_scientific = 256, 
_S_showbase = 512, 
_S_showpoint = 1024, 
_S_showpos = 2048, 
_S_skipws = 4096, 
_S_unitbuf = 8192, 
_S_uppercase = 16384, 
_S_adjustfield = 176, 
_S_basefield = 74, 
_S_floatfield = 260, 
_S_ios_fmtflags_end = 65536
}; 


inline _Ios_Fmtflags operator&(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
{ return (_Ios_Fmtflags)(static_cast< int>(__a) & static_cast< int>(__b)); } 


inline _Ios_Fmtflags operator|(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
{ return (_Ios_Fmtflags)(static_cast< int>(__a) | static_cast< int>(__b)); } 


inline _Ios_Fmtflags operator^(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
{ return (_Ios_Fmtflags)(static_cast< int>(__a) ^ static_cast< int>(__b)); } 


inline _Ios_Fmtflags &operator|=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b) 
{ return __a = (__a | __b); } 


inline _Ios_Fmtflags &operator&=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b) 
{ return __a = (__a & __b); } 


inline _Ios_Fmtflags &operator^=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b) 
{ return __a = (__a ^ __b); } 


inline _Ios_Fmtflags operator~(_Ios_Fmtflags __a) 
{ return (_Ios_Fmtflags)(~(static_cast< int>(__a))); } 


enum _Ios_Openmode { 

_S_app = 1, 
_S_ate, 
_S_bin = 4, 
_S_in = 8, 
_S_out = 16, 
_S_trunc = 32, 
_S_ios_openmode_end = 65536
}; 


inline _Ios_Openmode operator&(_Ios_Openmode __a, _Ios_Openmode __b) 
{ return (_Ios_Openmode)(static_cast< int>(__a) & static_cast< int>(__b)); } 


inline _Ios_Openmode operator|(_Ios_Openmode __a, _Ios_Openmode __b) 
{ return (_Ios_Openmode)(static_cast< int>(__a) | static_cast< int>(__b)); } 


inline _Ios_Openmode operator^(_Ios_Openmode __a, _Ios_Openmode __b) 
{ return (_Ios_Openmode)(static_cast< int>(__a) ^ static_cast< int>(__b)); } 


inline _Ios_Openmode &operator|=(_Ios_Openmode &__a, _Ios_Openmode __b) 
{ return __a = (__a | __b); } 


inline _Ios_Openmode &operator&=(_Ios_Openmode &__a, _Ios_Openmode __b) 
{ return __a = (__a & __b); } 


inline _Ios_Openmode &operator^=(_Ios_Openmode &__a, _Ios_Openmode __b) 
{ return __a = (__a ^ __b); } 


inline _Ios_Openmode operator~(_Ios_Openmode __a) 
{ return (_Ios_Openmode)(~(static_cast< int>(__a))); } 


enum _Ios_Iostate { 

_S_goodbit, 
_S_badbit, 
_S_eofbit, 
_S_failbit = 4, 
_S_ios_iostate_end = 65536
}; 


inline _Ios_Iostate operator&(_Ios_Iostate __a, _Ios_Iostate __b) 
{ return (_Ios_Iostate)(static_cast< int>(__a) & static_cast< int>(__b)); } 


inline _Ios_Iostate operator|(_Ios_Iostate __a, _Ios_Iostate __b) 
{ return (_Ios_Iostate)(static_cast< int>(__a) | static_cast< int>(__b)); } 


inline _Ios_Iostate operator^(_Ios_Iostate __a, _Ios_Iostate __b) 
{ return (_Ios_Iostate)(static_cast< int>(__a) ^ static_cast< int>(__b)); } 


inline _Ios_Iostate &operator|=(_Ios_Iostate &__a, _Ios_Iostate __b) 
{ return __a = (__a | __b); } 


inline _Ios_Iostate &operator&=(_Ios_Iostate &__a, _Ios_Iostate __b) 
{ return __a = (__a & __b); } 


inline _Ios_Iostate &operator^=(_Ios_Iostate &__a, _Ios_Iostate __b) 
{ return __a = (__a ^ __b); } 


inline _Ios_Iostate operator~(_Ios_Iostate __a) 
{ return (_Ios_Iostate)(~(static_cast< int>(__a))); } 

enum _Ios_Seekdir { 

_S_beg, 
_S_cur, 
_S_end, 
_S_ios_seekdir_end = 65536
}; 
# 207
class ios_base { 
# 217
public: class failure : public exception { 
# 223
public: explicit failure(const string & __str) throw(); 




virtual ~failure() throw(); 


virtual const char *what() const throw(); 


private: string _M_msg; 
}; 
# 263
typedef _Ios_Fmtflags fmtflags; 


static const fmtflags boolalpha = _S_boolalpha; 


static const fmtflags dec = _S_dec; 


static const fmtflags fixed = _S_fixed; 


static const fmtflags hex = _S_hex; 




static const fmtflags internal = _S_internal; 



static const fmtflags left = _S_left; 


static const fmtflags oct = _S_oct; 



static const fmtflags right = _S_right; 


static const fmtflags scientific = _S_scientific; 



static const fmtflags showbase = _S_showbase; 



static const fmtflags showpoint = _S_showpoint; 


static const fmtflags showpos = _S_showpos; 


static const fmtflags skipws = _S_skipws; 


static const fmtflags unitbuf = _S_unitbuf; 



static const fmtflags uppercase = _S_uppercase; 


static const fmtflags adjustfield = _S_adjustfield; 


static const fmtflags basefield = _S_basefield; 


static const fmtflags floatfield = _S_floatfield; 
# 338
typedef _Ios_Iostate iostate; 



static const iostate badbit = _S_badbit; 


static const iostate eofbit = _S_eofbit; 




static const iostate failbit = _S_failbit; 


static const iostate goodbit = _S_goodbit; 
# 369
typedef _Ios_Openmode openmode; 


static const openmode app = _S_app; 


static const openmode ate = _S_ate; 




static const openmode binary = _S_bin; 


static const openmode in = _S_in; 


static const openmode out = _S_out; 


static const openmode trunc = _S_trunc; 
# 401
typedef _Ios_Seekdir seekdir; 


static const seekdir beg = _S_beg; 


static const seekdir cur = _S_cur; 


static const seekdir end = _S_end; 


typedef int io_state; 
typedef int open_mode; 
typedef int seek_dir; 

typedef std::streampos streampos; 
typedef std::streamoff streamoff; 
# 427
enum event { 

erase_event, 
imbue_event, 
copyfmt_event
}; 
# 444
typedef void (*event_callback)(event, ios_base &, int); 
# 457
void register_callback(event_callback __fn, int __index); 
# 464
protected: streamsize _M_precision; 
streamsize _M_width; 
fmtflags _M_flags; 
iostate _M_exception; 
iostate _M_streambuf_state; 




struct _Callback_list { 


_Callback_list *_M_next; 
event_callback _M_fn; 
int _M_index; 
_Atomic_word _M_refcount; 

_Callback_list(event_callback __fn, int __index, _Callback_list *
__cb) : _M_next(__cb), _M_fn(__fn), _M_index(__index), _M_refcount(0) 
{ } 


void _M_add_reference() { __gnu_cxx::__atomic_add_dispatch(&(_M_refcount), 1); } 



int _M_remove_reference() 
{ return __gnu_cxx::__exchange_and_add_dispatch(&(_M_refcount), -1); } 
}; 

_Callback_list *_M_callbacks; 


void _M_call_callbacks(event __ev) throw(); 


void _M_dispose_callbacks(); 


struct _Words { 

void *_M_pword; 
long _M_iword; 
_Words() : _M_pword(0), _M_iword(0) { } 
}; 


_Words _M_word_zero; 



enum { _S_local_word_size = 8}; 
_Words _M_local_word[_S_local_word_size]; 


int _M_word_size; 
_Words *_M_word; 


_Words &_M_grow_words(int __index, bool __iword); 


locale _M_ios_locale; 


void _M_init(); 
# 537
public: class Init { 

friend class ios_base; 

public: Init(); 
~Init(); 


private: static _Atomic_word _S_refcount; 
static bool _S_synced_with_stdio; 
}; 
# 555
fmtflags flags() const 
{ return _M_flags; } 
# 566
fmtflags flags(fmtflags __fmtfl) 
{ 
fmtflags __old = _M_flags; 
_M_flags = __fmtfl; 
return __old; 
} 
# 582
fmtflags setf(fmtflags __fmtfl) 
{ 
fmtflags __old = _M_flags; 
(_M_flags |= __fmtfl); 
return __old; 
} 
# 599
fmtflags setf(fmtflags __fmtfl, fmtflags __mask) 
{ 
fmtflags __old = _M_flags; 
(_M_flags &= (~__mask)); 
(_M_flags |= (__fmtfl & __mask)); 
return __old; 
} 
# 614
void unsetf(fmtflags __mask) 
{ (_M_flags &= (~__mask)); } 
# 625
streamsize precision() const 
{ return _M_precision; } 
# 634
streamsize precision(streamsize __prec) 
{ 
streamsize __old = _M_precision; 
_M_precision = __prec; 
return __old; 
} 
# 648
streamsize width() const 
{ return _M_width; } 
# 657
streamsize width(streamsize __wide) 
{ 
streamsize __old = _M_width; 
_M_width = __wide; 
return __old; 
} 
# 676
static bool sync_with_stdio(bool __sync = (true)); 
# 688
locale imbue(const locale & __loc); 
# 699
locale getloc() const 
{ return _M_ios_locale; } 
# 710
const locale &_M_getloc() const 
{ return _M_ios_locale; } 
# 729
static int xalloc() throw(); 
# 745
long &iword(int __ix) 
{ 
_Words &__word = (__ix < _M_word_size) ? ((_M_word)[__ix]) : this->_M_grow_words(__ix, true); 

return __word._M_iword; 
} 
# 766
void *&pword(int __ix) 
{ 
_Words &__word = (__ix < _M_word_size) ? ((_M_word)[__ix]) : this->_M_grow_words(__ix, false); 

return __word._M_pword; 
} 
# 782
virtual ~ios_base(); 


protected: ios_base(); 




private: ios_base(const ios_base &); 


ios_base &operator=(const ios_base &); 
}; 




inline ios_base &boolalpha(ios_base &__base) 
{ 
__base.setf(ios_base::boolalpha); 
return __base; 
} 



inline ios_base &noboolalpha(ios_base &__base) 
{ 
__base.unsetf(ios_base::boolalpha); 
return __base; 
} 



inline ios_base &showbase(ios_base &__base) 
{ 
__base.setf(ios_base::showbase); 
return __base; 
} 



inline ios_base &noshowbase(ios_base &__base) 
{ 
__base.unsetf(ios_base::showbase); 
return __base; 
} 



inline ios_base &showpoint(ios_base &__base) 
{ 
__base.setf(ios_base::showpoint); 
return __base; 
} 



inline ios_base &noshowpoint(ios_base &__base) 
{ 
__base.unsetf(ios_base::showpoint); 
return __base; 
} 



inline ios_base &showpos(ios_base &__base) 
{ 
__base.setf(ios_base::showpos); 
return __base; 
} 



inline ios_base &noshowpos(ios_base &__base) 
{ 
__base.unsetf(ios_base::showpos); 
return __base; 
} 



inline ios_base &skipws(ios_base &__base) 
{ 
__base.setf(ios_base::skipws); 
return __base; 
} 



inline ios_base &noskipws(ios_base &__base) 
{ 
__base.unsetf(ios_base::skipws); 
return __base; 
} 



inline ios_base &uppercase(ios_base &__base) 
{ 
__base.setf(ios_base::uppercase); 
return __base; 
} 



inline ios_base &nouppercase(ios_base &__base) 
{ 
__base.unsetf(ios_base::uppercase); 
return __base; 
} 



inline ios_base &unitbuf(ios_base &__base) 
{ 
__base.setf(ios_base::unitbuf); 
return __base; 
} 



inline ios_base &nounitbuf(ios_base &__base) 
{ 
__base.unsetf(ios_base::unitbuf); 
return __base; 
} 




inline ios_base &internal(ios_base &__base) 
{ 
__base.setf(ios_base::internal, ios_base::adjustfield); 
return __base; 
} 



inline ios_base &left(ios_base &__base) 
{ 
__base.setf(ios_base::left, ios_base::adjustfield); 
return __base; 
} 



inline ios_base &right(ios_base &__base) 
{ 
__base.setf(ios_base::right, ios_base::adjustfield); 
return __base; 
} 




inline ios_base &dec(ios_base &__base) 
{ 
__base.setf(ios_base::dec, ios_base::basefield); 
return __base; 
} 



inline ios_base &hex(ios_base &__base) 
{ 
__base.setf(ios_base::hex, ios_base::basefield); 
return __base; 
} 



inline ios_base &oct(ios_base &__base) 
{ 
__base.setf(ios_base::oct, ios_base::basefield); 
return __base; 
} 




inline ios_base &fixed(ios_base &__base) 
{ 
__base.setf(ios_base::fixed, ios_base::floatfield); 
return __base; 
} 



inline ios_base &scientific(ios_base &__base) 
{ 
__base.setf(ios_base::scientific, ios_base::floatfield); 
return __base; 
} 

}
# 46 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/streambuf" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    streamsize
    __copy_streambufs_eof ( basic_streambuf < _CharT, _Traits > *,
     basic_streambuf < _CharT, _Traits > *, bool & );
# 113
template < typename _CharT, typename _Traits >
    class basic_streambuf
    {
    public :






      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type :: int_type int_type;
      typedef typename traits_type :: pos_type pos_type;
      typedef typename traits_type :: off_type off_type;




      typedef basic_streambuf < char_type, traits_type > __streambuf_type;


      friend class basic_ios < char_type, traits_type >;
      friend class basic_istream < char_type, traits_type >;
      friend class basic_ostream < char_type, traits_type >;
      friend class istreambuf_iterator < char_type, traits_type >;
      friend class ostreambuf_iterator < char_type, traits_type >;

      friend streamsize
      __copy_streambufs_eof < > ( __streambuf_type *, __streambuf_type *, bool & );

      template < bool _IsMove, typename _CharT2 >
        friend typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value,
            _CharT2 * > :: __type
        __copy_move_a2 ( istreambuf_iterator < _CharT2 >,
         istreambuf_iterator < _CharT2 >, _CharT2 * );

      template < typename _CharT2 >
        friend typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value,
      istreambuf_iterator < _CharT2 > > :: __type
        find ( istreambuf_iterator < _CharT2 >, istreambuf_iterator < _CharT2 >,
      const _CharT2 & );

      template < typename _CharT2, typename _Traits2 >
        friend basic_istream < _CharT2, _Traits2 > &
        operator >> ( basic_istream < _CharT2, _Traits2 > &, _CharT2 * );

      template < typename _CharT2, typename _Traits2, typename _Alloc >
        friend basic_istream < _CharT2, _Traits2 > &
        operator >> ( basic_istream < _CharT2, _Traits2 > &,
     basic_string < _CharT2, _Traits2, _Alloc > & );

      template < typename _CharT2, typename _Traits2, typename _Alloc >
        friend basic_istream < _CharT2, _Traits2 > &
        getline ( basic_istream < _CharT2, _Traits2 > &,
  basic_string < _CharT2, _Traits2, _Alloc > &, _CharT2 );

    protected :








      char_type * _M_in_beg;
      char_type * _M_in_cur;
      char_type * _M_in_end;
      char_type * _M_out_beg;
      char_type * _M_out_cur;
      char_type * _M_out_end;


      locale _M_buf_locale;

  public :

      virtual
      ~ basic_streambuf ( )
      { }









      locale
      pubimbue ( const locale & __loc )
      {
 locale __tmp ( this -> getloc ( ) );
 this -> imbue ( __loc );
 _M_buf_locale = __loc;
 return __tmp;
      }









      locale
      getloc ( ) const
      { return _M_buf_locale; }










      __streambuf_type *
      pubsetbuf ( char_type * __s, streamsize __n )
      { return this -> setbuf ( __s, __n ); }

      pos_type
      pubseekoff ( off_type __off, ios_base :: seekdir __way,
   ios_base :: openmode __mode = ios_base :: in | ios_base :: out )
      { return this -> seekoff ( __off, __way, __mode ); }

      pos_type
      pubseekpos ( pos_type __sp,
   ios_base :: openmode __mode = ios_base :: in | ios_base :: out )
      { return this -> seekpos ( __sp, __mode ); }

      int
      pubsync ( ) { return this -> sync ( ); }











      streamsize
      in_avail ( )
      {
 const streamsize __ret = this -> egptr ( ) - this -> gptr ( );
 return __ret ? __ret : this -> showmanyc ( );
      }








      int_type
      snextc ( )
      {
 int_type __ret = traits_type :: eof ( );
 if ( __builtin_expect ( ! traits_type :: eq_int_type ( this -> sbumpc ( ),
             __ret ), true ) )
   __ret = this -> sgetc ( );
 return __ret;
      }









      int_type
      sbumpc ( )
      {
 int_type __ret;
 if ( __builtin_expect ( this -> gptr ( ) < this -> egptr ( ), true ) )
   {
     __ret = traits_type :: to_int_type ( * this -> gptr ( ) );
     this -> gbump ( 1 );
   }
 else
   __ret = this -> uflow ( );
 return __ret;
      }









      int_type
      sgetc ( )
      {
 int_type __ret;
 if ( __builtin_expect ( this -> gptr ( ) < this -> egptr ( ), true ) )
   __ret = traits_type :: to_int_type ( * this -> gptr ( ) );
 else
   __ret = this -> underflow ( );
 return __ret;
      }









      streamsize
      sgetn ( char_type * __s, streamsize __n )
      { return this -> xsgetn ( __s, __n ); }











      int_type
      sputbackc ( char_type __c )
      {
 int_type __ret;
 const bool __testpos = this -> eback ( ) < this -> gptr ( );
 if ( __builtin_expect ( ! __testpos ||
        ! traits_type :: eq ( __c, this -> gptr ( ) [ - 1 ] ), false ) )
   __ret = this -> pbackfail ( traits_type :: to_int_type ( __c ) );
 else
   {
     this -> gbump ( - 1 );
     __ret = traits_type :: to_int_type ( * this -> gptr ( ) );
   }
 return __ret;
      }










      int_type
      sungetc ( )
      {
 int_type __ret;
 if ( __builtin_expect ( this -> eback ( ) < this -> gptr ( ), true ) )
   {
     this -> gbump ( - 1 );
     __ret = traits_type :: to_int_type ( * this -> gptr ( ) );
   }
 else
   __ret = this -> pbackfail ( );
 return __ret;
      }














      int_type
      sputc ( char_type __c )
      {
 int_type __ret;
 if ( __builtin_expect ( this -> pptr ( ) < this -> epptr ( ), true ) )
   {
     * this -> pptr ( ) = __c;
     this -> pbump ( 1 );
     __ret = traits_type :: to_int_type ( __c );
   }
 else
   __ret = this -> overflow ( traits_type :: to_int_type ( __c ) );
 return __ret;
      }












      streamsize
      sputn ( const char_type * __s, streamsize __n )
      { return this -> xsputn ( __s, __n ); }

    protected :









      basic_streambuf ( )
      : _M_in_beg ( 0 ), _M_in_cur ( 0 ), _M_in_end ( 0 ),
      _M_out_beg ( 0 ), _M_out_cur ( 0 ), _M_out_end ( 0 ),
      _M_buf_locale ( locale ( ) )
      { }













      char_type *
      eback ( ) const { return _M_in_beg; }

      char_type *
      gptr ( ) const { return _M_in_cur; }

      char_type *
      egptr ( ) const { return _M_in_end; }








      void
      gbump ( int __n ) { _M_in_cur += __n; }









      void
      setg ( char_type * __gbeg, char_type * __gnext, char_type * __gend )
      {
 _M_in_beg = __gbeg;
 _M_in_cur = __gnext;
 _M_in_end = __gend;
      }













      char_type *
      pbase ( ) const { return _M_out_beg; }

      char_type *
      pptr ( ) const { return _M_out_cur; }

      char_type *
      epptr ( ) const { return _M_out_end; }








      void
      pbump ( int __n ) { _M_out_cur += __n; }








      void
      setp ( char_type * __pbeg, char_type * __pend )
      {
 _M_out_beg = _M_out_cur = __pbeg;
 _M_out_end = __pend;
      }















      virtual void
      imbue ( const locale & )
      { }












      virtual basic_streambuf < char_type, _Traits > *
      setbuf ( char_type *, streamsize )
      { return this; }








      virtual pos_type
      seekoff ( off_type, ios_base :: seekdir,
       ios_base :: openmode = ios_base :: in | ios_base :: out )
      { return pos_type ( off_type ( - 1 ) ); }








      virtual pos_type
      seekpos ( pos_type,
       ios_base :: openmode = ios_base :: in | ios_base :: out )
      { return pos_type ( off_type ( - 1 ) ); }









      virtual int
      sync ( ) { return 0; }




















      virtual streamsize
      showmanyc ( ) { return 0; }














      virtual streamsize
      xsgetn ( char_type * __s, streamsize __n );




















      virtual int_type
      underflow ( )
      { return traits_type :: eof ( ); }










      virtual int_type
      uflow ( )
      {
 int_type __ret = traits_type :: eof ( );
 const bool __testeof = traits_type :: eq_int_type ( this -> underflow ( ),
       __ret );
 if ( ! __testeof )
   {
     __ret = traits_type :: to_int_type ( * this -> gptr ( ) );
     this -> gbump ( 1 );
   }
 return __ret;
      }











      virtual int_type
      pbackfail ( int_type = traits_type :: eof ( ) )
      { return traits_type :: eof ( ); }















      virtual streamsize
      xsputn ( const char_type * __s, streamsize __n );























      virtual int_type
      overflow ( int_type = traits_type :: eof ( ) )
      { return traits_type :: eof ( ); }



    public :








      void
      stossc ( )
      {
 if ( this -> gptr ( ) < this -> egptr ( ) )
   this -> gbump ( 1 );
 else
   this -> uflow ( );
      }


    private :


      basic_streambuf ( const __streambuf_type & __sb )
      : _M_in_beg ( __sb . _M_in_beg ), _M_in_cur ( __sb . _M_in_cur ),
      _M_in_end ( __sb . _M_in_end ), _M_out_beg ( __sb . _M_out_beg ),
      _M_out_cur ( __sb . _M_out_cur ), _M_out_end ( __sb . _M_out_cur ),
      _M_buf_locale ( __sb . _M_buf_locale )
      { }

      __streambuf_type &
      operator = ( const __streambuf_type & ) { return * this; };
    };




template<> streamsize __copy_streambufs_eof(basic_streambuf< char, char_traits< char> >  * __sbin, basic_streambuf< char, char_traits< char> >  * __sbout, bool & __ineof); 




template<> streamsize __copy_streambufs_eof(basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbin, basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbout, bool & __ineof); 



}
# 40 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/streambuf.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    streamsize
    basic_streambuf < _CharT, _Traits > ::
    xsgetn ( char_type * __s, streamsize __n )
    {
      streamsize __ret = 0;
      while ( __ret < __n )
 {
   const streamsize __buf_len = this -> egptr ( ) - this -> gptr ( );
   if ( __buf_len )
     {
       const streamsize __remaining = __n - __ret;
       const streamsize __len = std :: min ( __buf_len, __remaining );
       traits_type :: copy ( __s, this -> gptr ( ), __len );
       __ret += __len;
       __s += __len;
       this -> gbump ( __len );
     }

   if ( __ret < __n )
     {
       const int_type __c = this -> uflow ( );
       if ( ! traits_type :: eq_int_type ( __c, traits_type :: eof ( ) ) )
  {
    traits_type :: assign ( * __s ++, traits_type :: to_char_type ( __c ) );
    ++ __ret;
  }
       else
  break;
     }
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    streamsize
    basic_streambuf < _CharT, _Traits > ::
    xsputn ( const char_type * __s, streamsize __n )
    {
      streamsize __ret = 0;
      while ( __ret < __n )
 {
   const streamsize __buf_len = this -> epptr ( ) - this -> pptr ( );
   if ( __buf_len )
     {
       const streamsize __remaining = __n - __ret;
       const streamsize __len = std :: min ( __buf_len, __remaining );
       traits_type :: copy ( this -> pptr ( ), __s, __len );
       __ret += __len;
       __s += __len;
       this -> pbump ( __len );
     }

   if ( __ret < __n )
     {
       int_type __c = this -> overflow ( traits_type :: to_int_type ( * __s ) );
       if ( ! traits_type :: eq_int_type ( __c, traits_type :: eof ( ) ) )
  {
    ++ __ret;
    ++ __s;
  }
       else
  break;
     }
 }
      return __ret;
    }




template < typename _CharT, typename _Traits >
    streamsize
    __copy_streambufs_eof ( basic_streambuf < _CharT, _Traits > * __sbin,
     basic_streambuf < _CharT, _Traits > * __sbout,
     bool & __ineof )
    {
      streamsize __ret = 0;
      __ineof = true;
      typename _Traits :: int_type __c = __sbin -> sgetc ( );
      while ( ! _Traits :: eq_int_type ( __c, _Traits :: eof ( ) ) )
 {
   __c = __sbout -> sputc ( _Traits :: to_char_type ( __c ) );
   if ( _Traits :: eq_int_type ( __c, _Traits :: eof ( ) ) )
     {
       __ineof = false;
       break;
     }
   ++ __ret;
   __c = __sbin -> snextc ( );
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    inline streamsize
    __copy_streambufs ( basic_streambuf < _CharT, _Traits > * __sbin,
        basic_streambuf < _CharT, _Traits > * __sbout )
    {
      bool __ineof;
      return __copy_streambufs_eof ( __sbin, __sbout, __ineof );
    }
# 149
extern template class basic_streambuf< char, char_traits< char> > ;
extern template streamsize __copy_streambufs(basic_streambuf< char, char_traits< char> >  * __sbin, basic_streambuf< char, char_traits< char> >  * __sbout);



extern template streamsize __copy_streambufs_eof< char, char_traits< char> > (basic_streambuf< char, char_traits< char> >  *, basic_streambuf< char, char_traits< char> >  *, bool &);
# 160
extern template class basic_streambuf< wchar_t, char_traits< wchar_t> > ;
extern template streamsize __copy_streambufs(basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbin, basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbout);



extern template streamsize __copy_streambufs_eof< wchar_t, char_traits< wchar_t> > (basic_streambuf< wchar_t, char_traits< wchar_t> >  *, basic_streambuf< wchar_t, char_traits< wchar_t> >  *, bool &);
# 172
}
# 53 "/usr/include/wctype.h" 3
typedef unsigned long wctype_t; 
# 73
enum { 
__ISwupper, 
__ISwlower, 
__ISwalpha, 
__ISwdigit, 
__ISwxdigit, 
__ISwspace, 
__ISwprint, 
__ISwgraph, 
__ISwblank, 
__ISwcntrl, 
__ISwpunct, 
__ISwalnum, 

_ISwupper = 16777216, 
_ISwlower = 33554432, 
_ISwalpha = 67108864, 
_ISwdigit = 134217728, 
_ISwxdigit = 268435456, 
_ISwspace = 536870912, 
_ISwprint = 1073741824, 
_ISwgraph = (-2147483647-1), 
_ISwblank = 65536, 
_ISwcntrl = 131072, 
_ISwpunct = 262144, 
_ISwalnum = 524288
}; 
# 112
extern "C" int iswalnum(wint_t __wc) throw(); 
# 118
extern "C" int iswalpha(wint_t __wc) throw(); 


extern "C" int iswcntrl(wint_t __wc) throw(); 



extern "C" int iswdigit(wint_t __wc) throw(); 



extern "C" int iswgraph(wint_t __wc) throw(); 




extern "C" int iswlower(wint_t __wc) throw(); 


extern "C" int iswprint(wint_t __wc) throw(); 




extern "C" int iswpunct(wint_t __wc) throw(); 




extern "C" int iswspace(wint_t __wc) throw(); 




extern "C" int iswupper(wint_t __wc) throw(); 




extern "C" int iswxdigit(wint_t __wc) throw(); 
# 163
extern "C" int iswblank(wint_t __wc) throw(); 
# 172
extern "C" wctype_t wctype(const char * __property) throw(); 



extern "C" int iswctype(wint_t __wc, wctype_t __desc) throw(); 
# 187
extern "C" { typedef const __int32_t *wctrans_t; }
# 195
extern "C" wint_t towlower(wint_t __wc) throw(); 


extern "C" wint_t towupper(wint_t __wc) throw(); 
# 219
extern "C" wctrans_t wctrans(const char * __property) throw(); 


extern "C" wint_t towctrans(wint_t __wc, wctrans_t __desc) throw(); 
# 231
extern "C" int iswalnum_l(wint_t __wc, __locale_t __locale) throw(); 
# 237
extern "C" int iswalpha_l(wint_t __wc, __locale_t __locale) throw(); 


extern "C" int iswcntrl_l(wint_t __wc, __locale_t __locale) throw(); 



extern "C" int iswdigit_l(wint_t __wc, __locale_t __locale) throw(); 



extern "C" int iswgraph_l(wint_t __wc, __locale_t __locale) throw(); 




extern "C" int iswlower_l(wint_t __wc, __locale_t __locale) throw(); 


extern "C" int iswprint_l(wint_t __wc, __locale_t __locale) throw(); 




extern "C" int iswpunct_l(wint_t __wc, __locale_t __locale) throw(); 




extern "C" int iswspace_l(wint_t __wc, __locale_t __locale) throw(); 




extern "C" int iswupper_l(wint_t __wc, __locale_t __locale) throw(); 




extern "C" int iswxdigit_l(wint_t __wc, __locale_t __locale) throw(); 




extern "C" int iswblank_l(wint_t __wc, __locale_t __locale) throw(); 



extern "C" wctype_t wctype_l(const char * __property, __locale_t __locale) throw(); 




extern "C" int iswctype_l(wint_t __wc, wctype_t __desc, __locale_t __locale) throw(); 
# 299
extern "C" wint_t towlower_l(wint_t __wc, __locale_t __locale) throw(); 


extern "C" wint_t towupper_l(wint_t __wc, __locale_t __locale) throw(); 



extern "C" wctrans_t wctrans_l(const char * __property, __locale_t __locale) throw(); 



extern "C" wint_t towctrans_l(wint_t __wc, wctrans_t __desc, __locale_t __locale) throw(); 
# 76 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cwctype" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::wctrans_t;
using ::wctype_t;


using ::iswalnum;
using ::iswalpha;

using ::iswblank;

using ::iswcntrl;
using ::iswctype;
using ::iswdigit;
using ::iswgraph;
using ::iswlower;
using ::iswprint;
using ::iswpunct;
using ::iswspace;
using ::iswupper;
using ::iswxdigit;
using ::towctrans;
using ::towlower;
using ::towupper;
using ::wctrans;
using ::wctype;

}
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/ctype_base.h" 3
namespace std __attribute((__visibility__("default" ))) { 


struct ctype_base { 


typedef const int *__to_type; 



typedef unsigned short mask; 
static const mask upper = (_ISupper); 
static const mask lower = (_ISlower); 
static const mask alpha = (_ISalpha); 
static const mask digit = (_ISdigit); 
static const mask xdigit = (_ISxdigit); 
static const mask space = (_ISspace); 
static const mask print = (_ISprint); 
static const mask graph = (((_ISalpha) | (_ISdigit)) | (_ISpunct)); 
static const mask cntrl = (_IScntrl); 
static const mask punct = (_ISpunct); 
static const mask alnum = ((_ISalpha) | (_ISdigit)); 
}; 

}
# 40 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/streambuf_iterator.h" 3
namespace std __attribute((__visibility__("default" ))) { 



template < typename _CharT, typename _Traits >
    class istreambuf_iterator
    : public iterator < input_iterator_tag, _CharT, typename _Traits :: off_type,
        _CharT *, _CharT & >
    {
    public :



      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename _Traits :: int_type int_type;
      typedef basic_streambuf < _CharT, _Traits > streambuf_type;
      typedef basic_istream < _CharT, _Traits > istream_type;


      template < typename _CharT2 >
 friend typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value,
                      ostreambuf_iterator < _CharT2 > > :: __type
 copy ( istreambuf_iterator < _CharT2 >, istreambuf_iterator < _CharT2 >,
      ostreambuf_iterator < _CharT2 > );

      template < bool _IsMove, typename _CharT2 >
 friend typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value,
            _CharT2 * > :: __type
 __copy_move_a2 ( istreambuf_iterator < _CharT2 >,
         istreambuf_iterator < _CharT2 >, _CharT2 * );

      template < typename _CharT2 >
 friend typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value,
               istreambuf_iterator < _CharT2 > > :: __type
 find ( istreambuf_iterator < _CharT2 >, istreambuf_iterator < _CharT2 >,
      const _CharT2 & );

    private :







      mutable streambuf_type * _M_sbuf;
      mutable int_type _M_c;

    public :

      istreambuf_iterator ( ) throw ( )
      : _M_sbuf ( 0 ), _M_c ( traits_type :: eof ( ) ) { }


      istreambuf_iterator ( istream_type & __s ) throw ( )
      : _M_sbuf ( __s . rdbuf ( ) ), _M_c ( traits_type :: eof ( ) ) { }


      istreambuf_iterator ( streambuf_type * __s ) throw ( )
      : _M_sbuf ( __s ), _M_c ( traits_type :: eof ( ) ) { }




      char_type
      operator * ( ) const
      {







 return traits_type :: to_char_type ( _M_get ( ) );
      }


      istreambuf_iterator &
      operator ++ ( )
      {


                        ;
 if ( _M_sbuf )
   {
     _M_sbuf -> sbumpc ( );
     _M_c = traits_type :: eof ( );
   }
 return * this;
      }


      istreambuf_iterator
      operator ++ ( int )
      {


                        ;

 istreambuf_iterator __old = * this;
 if ( _M_sbuf )
   {
     __old . _M_c = _M_sbuf -> sbumpc ( );
     _M_c = traits_type :: eof ( );
   }
 return __old;
      }





      bool
      equal ( const istreambuf_iterator & __b ) const
      { return _M_at_eof ( ) == __b . _M_at_eof ( ); }

    private :
      int_type
      _M_get ( ) const
      {
 const int_type __eof = traits_type :: eof ( );
 int_type __ret = __eof;
 if ( _M_sbuf )
   {
     if ( ! traits_type :: eq_int_type ( _M_c, __eof ) )
       __ret = _M_c;
     else if ( ! traits_type :: eq_int_type ( ( __ret = _M_sbuf -> sgetc ( ) ),
            __eof ) )
       _M_c = __ret;
     else
       _M_sbuf = 0;
   }
 return __ret;
      }

      bool
      _M_at_eof ( ) const
      {
 const int_type __eof = traits_type :: eof ( );
 return traits_type :: eq_int_type ( _M_get ( ), __eof );
      }
    };

template < typename _CharT, typename _Traits >
    inline bool
    operator == ( const istreambuf_iterator < _CharT, _Traits > & __a,
        const istreambuf_iterator < _CharT, _Traits > & __b )
    { return __a . equal ( __b ); }

template < typename _CharT, typename _Traits >
    inline bool
    operator != ( const istreambuf_iterator < _CharT, _Traits > & __a,
        const istreambuf_iterator < _CharT, _Traits > & __b )
    { return ! __a . equal ( __b ); }


template < typename _CharT, typename _Traits >
    class ostreambuf_iterator
    : public iterator < output_iterator_tag, void, void, void, void >
    {
    public :



      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef basic_streambuf < _CharT, _Traits > streambuf_type;
      typedef basic_ostream < _CharT, _Traits > ostream_type;


      template < typename _CharT2 >
 friend typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value,
                      ostreambuf_iterator < _CharT2 > > :: __type
 copy ( istreambuf_iterator < _CharT2 >, istreambuf_iterator < _CharT2 >,
      ostreambuf_iterator < _CharT2 > );

    private :
      streambuf_type * _M_sbuf;
      bool _M_failed;

    public :

      ostreambuf_iterator ( ostream_type & __s ) throw ( )
      : _M_sbuf ( __s . rdbuf ( ) ), _M_failed ( ! _M_sbuf ) { }


      ostreambuf_iterator ( streambuf_type * __s ) throw ( )
      : _M_sbuf ( __s ), _M_failed ( ! _M_sbuf ) { }


      ostreambuf_iterator &
      operator = ( _CharT __c )
      {
 if ( ! _M_failed &&
     _Traits :: eq_int_type ( _M_sbuf -> sputc ( __c ), _Traits :: eof ( ) ) )
   _M_failed = true;
 return * this;
      }


      ostreambuf_iterator &
      operator * ( )
      { return * this; }


      ostreambuf_iterator &
      operator ++ ( int )
      { return * this; }


      ostreambuf_iterator &
      operator ++ ( )
      { return * this; }


      bool
      failed ( ) const throw ( )
      { return _M_failed; }

      ostreambuf_iterator &
      _M_put ( const _CharT * __ws, streamsize __len )
      {
 if ( __builtin_expect ( ! _M_failed, true )
     && __builtin_expect ( this -> _M_sbuf -> sputn ( __ws, __len ) != __len,
    false ) )
   _M_failed = true;
 return * this;
      }
    };


template < typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
                           ostreambuf_iterator < _CharT > > :: __type
    copy ( istreambuf_iterator < _CharT > __first,
  istreambuf_iterator < _CharT > __last,
  ostreambuf_iterator < _CharT > __result )
    {
      if ( __first . _M_sbuf && ! __last . _M_sbuf && ! __result . _M_failed )
 {
   bool __ineof;
   __copy_streambufs_eof ( __first . _M_sbuf, __result . _M_sbuf, __ineof );
   if ( ! __ineof )
     __result . _M_failed = true;
 }
      return __result;
    }

template < bool _IsMove, typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
            ostreambuf_iterator < _CharT > > :: __type
    __copy_move_a2 ( _CharT * __first, _CharT * __last,
     ostreambuf_iterator < _CharT > __result )
    {
      const streamsize __num = __last - __first;
      if ( __num > 0 )
 __result . _M_put ( __first, __num );
      return __result;
    }

template < bool _IsMove, typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
        ostreambuf_iterator < _CharT > > :: __type
    __copy_move_a2 ( const _CharT * __first, const _CharT * __last,
     ostreambuf_iterator < _CharT > __result )
    {
      const streamsize __num = __last - __first;
      if ( __num > 0 )
 __result . _M_put ( __first, __num );
      return __result;
    }

template < bool _IsMove, typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
            _CharT * > :: __type
    __copy_move_a2 ( istreambuf_iterator < _CharT > __first,
     istreambuf_iterator < _CharT > __last, _CharT * __result )
    {
      typedef istreambuf_iterator < _CharT > __is_iterator_type;
      typedef typename __is_iterator_type :: traits_type traits_type;
      typedef typename __is_iterator_type :: streambuf_type streambuf_type;
      typedef typename traits_type :: int_type int_type;

      if ( __first . _M_sbuf && ! __last . _M_sbuf )
 {
   streambuf_type * __sb = __first . _M_sbuf;
   int_type __c = __sb -> sgetc ( );
   while ( ! traits_type :: eq_int_type ( __c, traits_type :: eof ( ) ) )
     {
       const streamsize __n = __sb -> egptr ( ) - __sb -> gptr ( );
       if ( __n > 1 )
  {
    traits_type :: copy ( __result, __sb -> gptr ( ), __n );
    __sb -> gbump ( __n );
    __result += __n;
    __c = __sb -> underflow ( );
  }
       else
  {
    * __result ++ = traits_type :: to_char_type ( __c );
    __c = __sb -> snextc ( );
  }
     }
 }
      return __result;
    }

template < typename _CharT >
    typename __gnu_cxx :: __enable_if < __is_char < _CharT > :: __value,
          istreambuf_iterator < _CharT > > :: __type
    find ( istreambuf_iterator < _CharT > __first,
  istreambuf_iterator < _CharT > __last, const _CharT & __val )
    {
      typedef istreambuf_iterator < _CharT > __is_iterator_type;
      typedef typename __is_iterator_type :: traits_type traits_type;
      typedef typename __is_iterator_type :: streambuf_type streambuf_type;
      typedef typename traits_type :: int_type int_type;

      if ( __first . _M_sbuf && ! __last . _M_sbuf )
 {
   const int_type __ival = traits_type :: to_int_type ( __val );
   streambuf_type * __sb = __first . _M_sbuf;
   int_type __c = __sb -> sgetc ( );
   while ( ! traits_type :: eq_int_type ( __c, traits_type :: eof ( ) )
   && ! traits_type :: eq_int_type ( __c, __ival ) )
     {
       streamsize __n = __sb -> egptr ( ) - __sb -> gptr ( );
       if ( __n > 1 )
  {
    const _CharT * __p = traits_type :: find ( __sb -> gptr ( ),
       __n, __val );
    if ( __p )
      __n = __p - __sb -> gptr ( );
    __sb -> gbump ( __n );
    __c = __sb -> sgetc ( );
  }
       else
  __c = __sb -> snextc ( );
     }

   if ( ! traits_type :: eq_int_type ( __c, traits_type :: eof ( ) ) )
     __first . _M_c = __c;
   else
     __first . _M_sbuf = 0;
 }
      return __first;
    }

}
# 52 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/locale_facets.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 64
template < typename _Tv >
    void
    __convert_to_v ( const char * __in, _Tv & __out, ios_base :: iostate & __err,
     const __c_locale & __cloc );




template<> void __convert_to_v(const char *, float &, ios_base::iostate &, const __c_locale &); 




template<> void __convert_to_v(const char *, double &, ios_base::iostate &, const __c_locale &); 




template<> void __convert_to_v(const char *, long double &, ios_base::iostate &, const __c_locale &); 




template < typename _CharT, typename _Traits >
    struct __pad
    {
      static void
      _S_pad ( ios_base & __io, _CharT __fill, _CharT * __news,
      const _CharT * __olds, streamsize __newlen, streamsize __oldlen );
    };
# 100
template < typename _CharT >
    _CharT *
    __add_grouping ( _CharT * __s, _CharT __sep,
     const char * __gbeg, size_t __gsize,
     const _CharT * __first, const _CharT * __last );




template < typename _CharT >
    inline
    ostreambuf_iterator < _CharT >
    __write ( ostreambuf_iterator < _CharT > __s, const _CharT * __ws, int __len )
    {
      __s . _M_put ( __ws, __len );
      return __s;
    }


template < typename _CharT, typename _OutIter >
    inline
    _OutIter
    __write ( _OutIter __s, const _CharT * __ws, int __len )
    {
      for ( int __j = 0; __j < __len; __j ++, ++ __s )
 * __s = __ws [ __j ];
      return __s;
    }
# 143
template < typename _CharT >
    class __ctype_abstract_base : public locale :: facet, public ctype_base
    {
    public :


      typedef _CharT char_type;











      bool
      is ( mask __m, char_type __c ) const
      { return this -> do_is ( __m, __c ); }














      const char_type *
      is ( const char_type * __lo, const char_type * __hi, mask * __vec ) const
      { return this -> do_is ( __lo, __hi, __vec ); }













      const char_type *
      scan_is ( mask __m, const char_type * __lo, const char_type * __hi ) const
      { return this -> do_scan_is ( __m, __lo, __hi ); }













      const char_type *
      scan_not ( mask __m, const char_type * __lo, const char_type * __hi ) const
      { return this -> do_scan_not ( __m, __lo, __hi ); }











      char_type
      toupper ( char_type __c ) const
      { return this -> do_toupper ( __c ); }












      const char_type *
      toupper ( char_type * __lo, const char_type * __hi ) const
      { return this -> do_toupper ( __lo, __hi ); }











      char_type
      tolower ( char_type __c ) const
      { return this -> do_tolower ( __c ); }












      const char_type *
      tolower ( char_type * __lo, const char_type * __hi ) const
      { return this -> do_tolower ( __lo, __hi ); }














      char_type
      widen ( char __c ) const
      { return this -> do_widen ( __c ); }
















      const char *
      widen ( const char * __lo, const char * __hi, char_type * __to ) const
      { return this -> do_widen ( __lo, __hi, __to ); }
















      char
      narrow ( char_type __c, char __dfault ) const
      { return this -> do_narrow ( __c, __dfault ); }



















      const char_type *
      narrow ( const char_type * __lo, const char_type * __hi,
       char __dfault, char * __to ) const
      { return this -> do_narrow ( __lo, __hi, __dfault, __to ); }

    protected :
      explicit
      __ctype_abstract_base ( size_t __refs = 0 ) : facet ( __refs ) { }

      virtual
      ~ __ctype_abstract_base ( ) { }














      virtual bool
      do_is ( mask __m, char_type __c ) const = 0;

















      virtual const char_type *
      do_is ( const char_type * __lo, const char_type * __hi,
     mask * __vec ) const = 0;
















      virtual const char_type *
      do_scan_is ( mask __m, const char_type * __lo,
   const char_type * __hi ) const = 0;
















      virtual const char_type *
      do_scan_not ( mask __m, const char_type * __lo,
    const char_type * __hi ) const = 0;















      virtual char_type
      do_toupper ( char_type ) const = 0;















      virtual const char_type *
      do_toupper ( char_type * __lo, const char_type * __hi ) const = 0;














      virtual char_type
      do_tolower ( char_type ) const = 0;















      virtual const char_type *
      do_tolower ( char_type * __lo, const char_type * __hi ) const = 0;

















      virtual char_type
      do_widen ( char ) const = 0;



















      virtual const char *
      do_widen ( const char * __lo, const char * __hi,
        char_type * __dest ) const = 0;



















      virtual char
      do_narrow ( char_type, char __dfault ) const = 0;






















      virtual const char_type *
      do_narrow ( const char_type * __lo, const char_type * __hi,
  char __dfault, char * __dest ) const = 0;
    };
# 604
template < typename _CharT >
    class ctype : public __ctype_abstract_base < _CharT >
    {
    public :

      typedef _CharT char_type;
      typedef typename __ctype_abstract_base < _CharT > :: mask mask;


      static locale :: id id;

      explicit
      ctype ( size_t __refs = 0 ) : __ctype_abstract_base < _CharT > ( __refs ) { }

   protected :
      virtual
      ~ ctype ( );

      virtual bool
      do_is ( mask __m, char_type __c ) const;

      virtual const char_type *
      do_is ( const char_type * __lo, const char_type * __hi, mask * __vec ) const;

      virtual const char_type *
      do_scan_is ( mask __m, const char_type * __lo, const char_type * __hi ) const;

      virtual const char_type *
      do_scan_not ( mask __m, const char_type * __lo,
    const char_type * __hi ) const;

      virtual char_type
      do_toupper ( char_type __c ) const;

      virtual const char_type *
      do_toupper ( char_type * __lo, const char_type * __hi ) const;

      virtual char_type
      do_tolower ( char_type __c ) const;

      virtual const char_type *
      do_tolower ( char_type * __lo, const char_type * __hi ) const;

      virtual char_type
      do_widen ( char __c ) const;

      virtual const char *
      do_widen ( const char * __lo, const char * __hi, char_type * __dest ) const;

      virtual char
      do_narrow ( char_type, char __dfault ) const;

      virtual const char_type *
      do_narrow ( const char_type * __lo, const char_type * __hi,
  char __dfault, char * __dest ) const;
    };

template < typename _CharT >
    locale :: id ctype < _CharT > :: id;
# 674
template<> class ctype< char>  : public locale::facet, public ctype_base { 




public: typedef char char_type; 



protected: __c_locale _M_c_locale_ctype; 
bool _M_del; 
__to_type _M_toupper; 
__to_type _M_tolower; 
const mask *_M_table; 
mutable char _M_widen_ok; 
mutable char _M_widen[1 + static_cast< unsigned char>((-1))]; 
mutable char _M_narrow[1 + static_cast< unsigned char>((-1))]; 
mutable char _M_narrow_ok; 




public: static locale::id id; 

static const size_t table_size = (1 + static_cast< unsigned char>((-1))); 
# 711
explicit ctype(const mask * __table = 0, bool __del = (false), size_t __refs = (0)); 
# 724
explicit ctype(__c_locale __cloc, const mask * __table = 0, bool __del = (false), size_t __refs = (0)); 
# 737
inline bool is(mask __m, char __c) const; 
# 752
inline const char *is(const char * __lo, const char * __hi, mask * __vec) const; 
# 766
inline const char *scan_is(mask __m, const char * __lo, const char * __hi) const; 
# 780
inline const char *scan_not(mask __m, const char * __lo, const char * __hi) const; 
# 795
char_type toupper(char_type __c) const 
{ return this->do_toupper(__c); } 
# 812
const char_type *toupper(char_type *__lo, const char_type *__hi) const 
{ return this->do_toupper(__lo, __hi); } 
# 828
char_type tolower(char_type __c) const 
{ return this->do_tolower(__c); } 
# 845
const char_type *tolower(char_type *__lo, const char_type *__hi) const 
{ return this->do_tolower(__lo, __hi); } 
# 865
char_type widen(char __c) const 
{ 
if (_M_widen_ok) { 
return (_M_widen)[static_cast< unsigned char>(__c)]; }  
this->_M_widen_init(); 
return this->do_widen(__c); 
} 
# 892
const char *widen(const char *__lo, const char *__hi, char_type *__to) const 
{ 
if (_M_widen_ok == 1) 
{ 
__builtin_memcpy(__to, __lo, __hi - __lo); 
return __hi; 
}  
if (!_M_widen_ok) { 
this->_M_widen_init(); }  
return this->do_widen(__lo, __hi, __to); 
} 
# 923
char narrow(char_type __c, char __dfault) const 
{ 
if ((_M_narrow)[static_cast< unsigned char>(__c)]) { 
return (_M_narrow)[static_cast< unsigned char>(__c)]; }  
const char __t = this->do_narrow(__c, __dfault); 
if (__t != __dfault) { 
(_M_narrow)[static_cast< unsigned char>(__c)] = __t; }  
return __t; 
} 
# 956
const char_type *narrow(const char_type *__lo, const char_type *__hi, char 
__dfault, char *__to) const 
{ 
if (__builtin_expect(_M_narrow_ok == 1, true)) 
{ 
__builtin_memcpy(__to, __lo, __hi - __lo); 
return __hi; 
}  
if (!_M_narrow_ok) { 
this->_M_narrow_init(); }  
return this->do_narrow(__lo, __hi, __dfault, __to); 
} 
# 974
const mask *table() const throw() 
{ return _M_table; } 



static const mask *classic_table() throw(); 
# 989
protected: virtual ~ctype(); 
# 1005
virtual char_type do_toupper(char_type) const; 
# 1022
virtual const char_type *do_toupper(char_type * __lo, const char_type * __hi) const; 
# 1038
virtual char_type do_tolower(char_type) const; 
# 1055
virtual const char_type *do_tolower(char_type * __lo, const char_type * __hi) const; 
# 1075
virtual char_type do_widen(char __c) const 
{ return __c; } 
# 1098
virtual const char *do_widen(const char *__lo, const char *__hi, char_type *__dest) const 
{ 
__builtin_memcpy(__dest, __lo, __hi - __lo); 
return __hi; 
} 
# 1124
virtual char do_narrow(char_type __c, char) const 
{ return __c; } 
# 1150
virtual const char_type *do_narrow(const char_type *__lo, const char_type *__hi, char, char *
__dest) const 
{ 
__builtin_memcpy(__dest, __lo, __hi - __lo); 
return __hi; 
} 


private: void _M_narrow_init() const; 
void _M_widen_init() const; 
}; 
# 1175
template<> class ctype< wchar_t>  : public __ctype_abstract_base< wchar_t>  { 




public: typedef wchar_t char_type; 
typedef wctype_t __wmask_type; 


protected: __c_locale _M_c_locale_ctype; 


bool _M_narrow_ok; 
char _M_narrow[128]; 
wint_t _M_widen[1 + static_cast< unsigned char>((-1))]; 


mask _M_bit[16]; 
__wmask_type _M_wmask[16]; 




public: static locale::id id; 
# 1208
explicit ctype(size_t __refs = (0)); 
# 1219
explicit ctype(__c_locale __cloc, size_t __refs = (0)); 



protected: __wmask_type _M_convert_to_wmask(const mask __m) const; 



virtual ~ctype(); 
# 1243
virtual bool do_is(mask __m, char_type __c) const; 
# 1262
virtual const char_type *do_is(const char_type * __lo, const char_type * __hi, mask * __vec) const; 
# 1280
virtual const char_type *do_scan_is(mask __m, const char_type * __lo, const char_type * __hi) const; 
# 1298
virtual const char_type *do_scan_not(mask __m, const char_type * __lo, const char_type * __hi) const; 
# 1315
virtual char_type do_toupper(char_type) const; 
# 1332
virtual const char_type *do_toupper(char_type * __lo, const char_type * __hi) const; 
# 1348
virtual char_type do_tolower(char_type) const; 
# 1365
virtual const char_type *do_tolower(char_type * __lo, const char_type * __hi) const; 
# 1385
virtual char_type do_widen(char) const; 
# 1407
virtual const char *do_widen(const char * __lo, const char * __hi, char_type * __dest) const; 
# 1430
virtual char do_narrow(char_type, char __dfault) const; 
# 1456
virtual const char_type *do_narrow(const char_type * __lo, const char_type * __hi, char __dfault, char * __dest) const; 




void _M_initialize_ctype(); 
}; 



template < typename _CharT >
    class ctype_byname : public ctype < _CharT >
    {
    public :
      typedef typename ctype < _CharT > :: mask mask;

      explicit
      ctype_byname ( const char * __s, size_t __refs = 0 );

    protected :
      virtual
      ~ ctype_byname ( ) { };
    };



template<> class ctype_byname< char>  : public ctype< char>  { 



public: explicit ctype_byname(const char * __s, size_t __refs = (0)); 



protected: virtual ~ctype_byname(); 
}; 



template<> class ctype_byname< wchar_t>  : public ctype< wchar_t>  { 



public: explicit ctype_byname(const char * __s, size_t __refs = (0)); 



protected: virtual ~ctype_byname(); 
}; 


}
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/ctype_inline.h" 3
namespace std __attribute((__visibility__("default" ))) { 



inline bool ctype< char> ::is(mask __m, char __c) const 
{ return (_M_table)[static_cast< unsigned char>(__c)] & __m; } 



inline const char *ctype< char> ::is(const char *__low, const char *__high, mask *__vec) const 
{ 
while (__low < __high) { 
*(__vec++) = (_M_table)[static_cast< unsigned char>((*(__low++)))]; }  
return __high; 
} 



inline const char *ctype< char> ::scan_is(mask __m, const char *__low, const char *__high) const 
{ 
while (__low < __high && !((_M_table)[static_cast< unsigned char>((*__low))] & __m)) { 

++__low; }  
return __low; 
} 



inline const char *ctype< char> ::scan_not(mask __m, const char *__low, const char *__high) const 
{ 
while (__low < __high && ((_M_table)[static_cast< unsigned char>((*__low))] & __m) != 0) { 

++__low; }  
return __low; 
} 

}
# 1512 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/locale_facets.h" 3
namespace std __attribute((__visibility__("default" ))) { 


class __num_base { 
# 1521
public: enum { 
_S_ominus, 
_S_oplus, 
_S_ox, 
_S_oX, 
_S_odigits, 
_S_odigits_end = 20, 
_S_oudigits = 20, 
_S_oudigits_end = 36, 
_S_oe = 18, 
_S_oE = 34, 
_S_oend = 36
}; 
# 1540
static const char *_S_atoms_out; 



static const char *_S_atoms_in; 


enum { 
_S_iminus, 
_S_iplus, 
_S_ix, 
_S_iX, 
_S_izero, 
_S_ie = 18, 
_S_iE = 24, 
_S_iend = 26
}; 




static void _S_format_float(const ios_base & __io, char * __fptr, char __mod); 
}; 

template < typename _CharT >
    struct __numpunct_cache : public locale :: facet
    {
      const char * _M_grouping;
      size_t _M_grouping_size;
      bool _M_use_grouping;
      const _CharT * _M_truename;
      size_t _M_truename_size;
      const _CharT * _M_falsename;
      size_t _M_falsename_size;
      _CharT _M_decimal_point;
      _CharT _M_thousands_sep;





      _CharT _M_atoms_out [ __num_base :: _S_oend ];





      _CharT _M_atoms_in [ __num_base :: _S_iend ];

      bool _M_allocated;

      __numpunct_cache ( size_t __refs = 0 ) : facet ( __refs ),
      _M_grouping ( __null ), _M_grouping_size ( 0 ), _M_use_grouping ( false ),
      _M_truename ( __null ), _M_truename_size ( 0 ), _M_falsename ( __null ),
      _M_falsename_size ( 0 ), _M_decimal_point ( _CharT ( ) ),
      _M_thousands_sep ( _CharT ( ) ), _M_allocated ( false )
      { }

      ~ __numpunct_cache ( );

      void
      _M_cache ( const locale & __loc );

    private :
      __numpunct_cache &
      operator = ( const __numpunct_cache & );

      explicit
      __numpunct_cache ( const __numpunct_cache & );
    };

template < typename _CharT >
    __numpunct_cache < _CharT > :: ~ __numpunct_cache ( )
    {
      if ( _M_allocated )
 {
   delete [ ] _M_grouping;
   delete [ ] _M_truename;
   delete [ ] _M_falsename;
 }
    }
# 1635
template < typename _CharT >
    class numpunct : public locale :: facet
    {
    public :



      typedef _CharT char_type;
      typedef basic_string < _CharT > string_type;

      typedef __numpunct_cache < _CharT > __cache_type;

    protected :
      __cache_type * _M_data;

    public :

      static locale :: id id;






      explicit
      numpunct ( size_t __refs = 0 ) : facet ( __refs ), _M_data ( __null )
      { _M_initialize_numpunct ( ); }










      explicit
      numpunct ( __cache_type * __cache, size_t __refs = 0 )
      : facet ( __refs ), _M_data ( __cache )
      { _M_initialize_numpunct ( ); }










      explicit
      numpunct ( __c_locale __cloc, size_t __refs = 0 )
      : facet ( __refs ), _M_data ( __null )
      { _M_initialize_numpunct ( __cloc ); }










      char_type
      decimal_point ( ) const
      { return this -> do_decimal_point ( ); }










      char_type
      thousands_sep ( ) const
      { return this -> do_thousands_sep ( ); }




























      string
      grouping ( ) const
      { return this -> do_grouping ( ); }










      string_type
      truename ( ) const
      { return this -> do_truename ( ); }










      string_type
      falsename ( ) const
      { return this -> do_falsename ( ); }

    protected :

      virtual
      ~ numpunct ( );









      virtual char_type
      do_decimal_point ( ) const
      { return _M_data -> _M_decimal_point; }









      virtual char_type
      do_thousands_sep ( ) const
      { return _M_data -> _M_thousands_sep; }










      virtual string
      do_grouping ( ) const
      { return _M_data -> _M_grouping; }










      virtual string_type
      do_truename ( ) const
      { return _M_data -> _M_truename; }










      virtual string_type
      do_falsename ( ) const
      { return _M_data -> _M_falsename; }


      void
      _M_initialize_numpunct ( __c_locale __cloc = __null );
    };

template < typename _CharT >
    locale :: id numpunct < _CharT > :: id;


template<> numpunct< char> ::~numpunct(); 



template<> void numpunct< char> ::_M_initialize_numpunct(__c_locale __cloc); 



template<> numpunct< wchar_t> ::~numpunct(); 



template<> void numpunct< wchar_t> ::_M_initialize_numpunct(__c_locale __cloc); 



template < typename _CharT >
    class numpunct_byname : public numpunct < _CharT >
    {
    public :
      typedef _CharT char_type;
      typedef basic_string < _CharT > string_type;

      explicit
      numpunct_byname ( const char * __s, size_t __refs = 0 )
      : numpunct < _CharT > ( __refs )
      {
 if ( __builtin_strcmp ( __s, "C" ) != 0
     && __builtin_strcmp ( __s, "POSIX" ) != 0 )
   {
     __c_locale __tmp;
     this -> _S_create_c_locale ( __tmp, __s );
     this -> _M_initialize_numpunct ( __tmp );
     this -> _S_destroy_c_locale ( __tmp );
   }
      }

    protected :
      virtual
      ~ numpunct_byname ( ) { }
    };
# 1907
template < typename _CharT, typename _InIter >
    class num_get : public locale :: facet
    {
    public :



      typedef _CharT char_type;
      typedef _InIter iter_type;



      static locale :: id id;








      explicit
      num_get ( size_t __refs = 0 ) : facet ( __refs ) { }
























      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, bool & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }
































      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, long & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, unsigned short & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, unsigned int & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, unsigned long & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }


      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, long long & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, unsigned long long & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }





























      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, float & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, double & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, long double & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }




























      iter_type
      get ( iter_type __in, iter_type __end, ios_base & __io,
   ios_base :: iostate & __err, void * & __v ) const
      { return this -> do_get ( __in, __end, __io, __err, __v ); }

    protected :

      virtual ~ num_get ( ) { }

      iter_type
      _M_extract_float ( iter_type, iter_type, ios_base &, ios_base :: iostate &,
         string & ) const;

      template < typename _ValueT >
        iter_type
        _M_extract_int ( iter_type, iter_type, ios_base &, ios_base :: iostate &,
         _ValueT & ) const;

      template < typename _CharT2 >
      typename __gnu_cxx :: __enable_if < __is_char < _CharT2 > :: __value, int > :: __type
        _M_find ( const _CharT2 *, size_t __len, _CharT2 __c ) const
        {
   int __ret = - 1;
   if ( __len <= 10 )
     {
       if ( __c >= _CharT2 ( '0' ) && __c < _CharT2 ( _CharT2 ( '0' ) + __len ) )
  __ret = __c - _CharT2 ( '0' );
     }
   else
     {
       if ( __c >= _CharT2 ( '0' ) && __c <= _CharT2 ( '9' ) )
  __ret = __c - _CharT2 ( '0' );
       else if ( __c >= _CharT2 ( 'a' ) && __c <= _CharT2 ( 'f' ) )
  __ret = 10 + ( __c - _CharT2 ( 'a' ) );
       else if ( __c >= _CharT2 ( 'A' ) && __c <= _CharT2 ( 'F' ) )
  __ret = 10 + ( __c - _CharT2 ( 'A' ) );
     }
   return __ret;
 }

      template < typename _CharT2 >
      typename __gnu_cxx :: __enable_if < ! __is_char < _CharT2 > :: __value,
          int > :: __type
        _M_find ( const _CharT2 * __zero, size_t __len, _CharT2 __c ) const
        {
   int __ret = - 1;
   const char_type * __q = char_traits < _CharT2 > :: find ( __zero, __len, __c );
   if ( __q )
     {
       __ret = __q - __zero;
       if ( __ret > 15 )
  __ret -= 6;
     }
   return __ret;
 }
















      virtual iter_type
      do_get ( iter_type, iter_type, ios_base &, ios_base :: iostate &, bool & ) const;

      virtual iter_type
      do_get ( iter_type __beg, iter_type __end, ios_base & __io,
      ios_base :: iostate & __err, long & __v ) const
      { return _M_extract_int ( __beg, __end, __io, __err, __v ); }

      virtual iter_type
      do_get ( iter_type __beg, iter_type __end, ios_base & __io,
      ios_base :: iostate & __err, unsigned short & __v ) const
      { return _M_extract_int ( __beg, __end, __io, __err, __v ); }

      virtual iter_type
      do_get ( iter_type __beg, iter_type __end, ios_base & __io,
      ios_base :: iostate & __err, unsigned int & __v ) const
      { return _M_extract_int ( __beg, __end, __io, __err, __v ); }

      virtual iter_type
      do_get ( iter_type __beg, iter_type __end, ios_base & __io,
      ios_base :: iostate & __err, unsigned long & __v ) const
      { return _M_extract_int ( __beg, __end, __io, __err, __v ); }


      virtual iter_type
      do_get ( iter_type __beg, iter_type __end, ios_base & __io,
      ios_base :: iostate & __err, long long & __v ) const
      { return _M_extract_int ( __beg, __end, __io, __err, __v ); }

      virtual iter_type
      do_get ( iter_type __beg, iter_type __end, ios_base & __io,
      ios_base :: iostate & __err, unsigned long long & __v ) const
      { return _M_extract_int ( __beg, __end, __io, __err, __v ); }


      virtual iter_type
      do_get ( iter_type, iter_type, ios_base &, ios_base :: iostate & __err,
      float & ) const;

      virtual iter_type
      do_get ( iter_type, iter_type, ios_base &, ios_base :: iostate & __err,
      double & ) const;







      virtual iter_type
      do_get ( iter_type, iter_type, ios_base &, ios_base :: iostate & __err,
      long double & ) const;


      virtual iter_type
      do_get ( iter_type, iter_type, ios_base &, ios_base :: iostate & __err,
      void * & ) const;








    };

template < typename _CharT, typename _InIter >
    locale :: id num_get < _CharT, _InIter > :: id;
# 2244
template < typename _CharT, typename _OutIter >
    class num_put : public locale :: facet
    {
    public :



      typedef _CharT char_type;
      typedef _OutIter iter_type;



      static locale :: id id;








      explicit
      num_put ( size_t __refs = 0 ) : facet ( __refs ) { }
















      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill, bool __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }







































      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill, long __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }

      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill,
   unsigned long __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }


      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill, long long __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }

      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill,
   unsigned long long __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }













































      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill, double __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }

      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill,
   long double __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }

















      iter_type
      put ( iter_type __s, ios_base & __f, char_type __fill,
   const void * __v ) const
      { return this -> do_put ( __s, __f, __fill, __v ); }

    protected :
      template < typename _ValueT >
        iter_type
        _M_insert_float ( iter_type, ios_base & __io, char_type __fill,
   char __mod, _ValueT __v ) const;

      void
      _M_group_float ( const char * __grouping, size_t __grouping_size,
       char_type __sep, const char_type * __p, char_type * __new,
       char_type * __cs, int & __len ) const;

      template < typename _ValueT >
        iter_type
        _M_insert_int ( iter_type, ios_base & __io, char_type __fill,
        _ValueT __v ) const;

      void
      _M_group_int ( const char * __grouping, size_t __grouping_size,
     char_type __sep, ios_base & __io, char_type * __new,
     char_type * __cs, int & __len ) const;

      void
      _M_pad ( char_type __fill, streamsize __w, ios_base & __io,
      char_type * __new, const char_type * __cs, int & __len ) const;


      virtual
      ~ num_put ( ) { };















      virtual iter_type
      do_put ( iter_type, ios_base &, char_type __fill, bool __v ) const;

      virtual iter_type
      do_put ( iter_type __s, ios_base & __io, char_type __fill, long __v ) const
      { return _M_insert_int ( __s, __io, __fill, __v ); }

      virtual iter_type
      do_put ( iter_type __s, ios_base & __io, char_type __fill,
      unsigned long __v ) const
      { return _M_insert_int ( __s, __io, __fill, __v ); }


      virtual iter_type
      do_put ( iter_type __s, ios_base & __io, char_type __fill,
      long long __v ) const
      { return _M_insert_int ( __s, __io, __fill, __v ); }

      virtual iter_type
      do_put ( iter_type __s, ios_base & __io, char_type __fill,
      unsigned long long __v ) const
      { return _M_insert_int ( __s, __io, __fill, __v ); }


      virtual iter_type
      do_put ( iter_type, ios_base &, char_type __fill, double __v ) const;






      virtual iter_type
      do_put ( iter_type, ios_base &, char_type __fill, long double __v ) const;


      virtual iter_type
      do_put ( iter_type, ios_base &, char_type __fill, const void * __v ) const;







    };

template < typename _CharT, typename _OutIter >
    locale :: id num_put < _CharT, _OutIter > :: id;
# 2519
template < typename _CharT >
    inline bool
    isspace ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: space, __c ); }


template < typename _CharT >
    inline bool
    isprint ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: print, __c ); }


template < typename _CharT >
    inline bool
    iscntrl ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: cntrl, __c ); }


template < typename _CharT >
    inline bool
    isupper ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: upper, __c ); }


template < typename _CharT >
    inline bool
    islower ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: lower, __c ); }


template < typename _CharT >
    inline bool
    isalpha ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: alpha, __c ); }


template < typename _CharT >
    inline bool
    isdigit ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: digit, __c ); }


template < typename _CharT >
    inline bool
    ispunct ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: punct, __c ); }


template < typename _CharT >
    inline bool
    isxdigit ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: xdigit, __c ); }


template < typename _CharT >
    inline bool
    isalnum ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: alnum, __c ); }


template < typename _CharT >
    inline bool
    isgraph ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . is ( ctype_base :: graph, __c ); }


template < typename _CharT >
    inline _CharT
    toupper ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . toupper ( __c ); }


template < typename _CharT >
    inline _CharT
    tolower ( _CharT __c, const locale & __loc )
    { return use_facet < ctype < _CharT > > ( __loc ) . tolower ( __c ); }

}
# 37 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/locale_facets.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 



template < typename _Facet >
    struct __use_cache
    {
      const _Facet *
      operator ( ) ( const locale & __loc ) const;
    };


template < typename _CharT >
    struct __use_cache < __numpunct_cache < _CharT > >
    {
      const __numpunct_cache < _CharT > *
      operator ( ) ( const locale & __loc ) const
      {
 const size_t __i = numpunct < _CharT > :: id . _M_id ( );
 const locale :: facet * * __caches = __loc . _M_impl -> _M_caches;
 if ( ! __caches [ __i ] )
   {
     __numpunct_cache < _CharT > * __tmp = __null;
     try
       {
  __tmp = new __numpunct_cache < _CharT >;
  __tmp -> _M_cache ( __loc );
       }
     catch ( ... )
       {
  delete __tmp;
  throw;
       }
     __loc . _M_impl -> _M_install_cache ( __tmp, __i );
   }
 return static_cast < const __numpunct_cache < _CharT > * > ( __caches [ __i ] );
      }
    };

template < typename _CharT >
    void
    __numpunct_cache < _CharT > :: _M_cache ( const locale & __loc )
    {
      _M_allocated = true;

      const numpunct < _CharT > & __np = use_facet < numpunct < _CharT > > ( __loc );

      _M_grouping_size = __np . grouping ( ) . size ( );
      char * __grouping = new char [ _M_grouping_size ];
      __np . grouping ( ) . copy ( __grouping, _M_grouping_size );
      _M_grouping = __grouping;
      _M_use_grouping = ( _M_grouping_size
    && static_cast < signed char > ( _M_grouping [ 0 ] ) > 0
    && ( _M_grouping [ 0 ]
        != __gnu_cxx :: __numeric_traits < char > :: __max ) );

      _M_truename_size = __np . truename ( ) . size ( );
      _CharT * __truename = new _CharT [ _M_truename_size ];
      __np . truename ( ) . copy ( __truename, _M_truename_size );
      _M_truename = __truename;

      _M_falsename_size = __np . falsename ( ) . size ( );
      _CharT * __falsename = new _CharT [ _M_falsename_size ];
      __np . falsename ( ) . copy ( __falsename, _M_falsename_size );
      _M_falsename = __falsename;

      _M_decimal_point = __np . decimal_point ( );
      _M_thousands_sep = __np . thousands_sep ( );

      const ctype < _CharT > & __ct = use_facet < ctype < _CharT > > ( __loc );
      __ct . widen ( __num_base :: _S_atoms_out,
   __num_base :: _S_atoms_out + __num_base :: _S_oend, _M_atoms_out );
      __ct . widen ( __num_base :: _S_atoms_in,
   __num_base :: _S_atoms_in + __num_base :: _S_iend, _M_atoms_in );
    }
# 122
bool __verify_grouping(const char * __grouping, size_t __grouping_size, const string & __grouping_tmp); 




template < typename _CharT, typename _InIter >
    _InIter
    num_get < _CharT, _InIter > ::
    _M_extract_float ( _InIter __beg, _InIter __end, ios_base & __io,
       ios_base :: iostate & __err, string & __xtrc ) const
    {
      typedef char_traits < _CharT > __traits_type;
      typedef __numpunct_cache < _CharT > __cache_type;
      __use_cache < __cache_type > __uc;
      const locale & __loc = __io . _M_getloc ( );
      const __cache_type * __lc = __uc ( __loc );
      const _CharT * __lit = __lc -> _M_atoms_in;
      char_type __c = char_type ( );


      bool __testeof = __beg == __end;


      if ( ! __testeof )
 {
   __c = * __beg;
   const bool __plus = __c == __lit [ __num_base :: _S_iplus ];
   if ( ( __plus || __c == __lit [ __num_base :: _S_iminus ] )
       && ! ( __lc -> _M_use_grouping && __c == __lc -> _M_thousands_sep )
       && ! ( __c == __lc -> _M_decimal_point ) )
     {
       __xtrc += __plus ? '+' : '-';
       if ( ++ __beg != __end )
  __c = * __beg;
       else
  __testeof = true;
     }
 }


      bool __found_mantissa = false;
      int __sep_pos = 0;
      while ( ! __testeof )
 {
   if ( ( __lc -> _M_use_grouping && __c == __lc -> _M_thousands_sep )
       || __c == __lc -> _M_decimal_point )
     break;
   else if ( __c == __lit [ __num_base :: _S_izero ] )
     {
       if ( ! __found_mantissa )
  {
    __xtrc += '0';
    __found_mantissa = true;
  }
       ++ __sep_pos;

       if ( ++ __beg != __end )
  __c = * __beg;
       else
  __testeof = true;
     }
   else
     break;
 }


      bool __found_dec = false;
      bool __found_sci = false;
      string __found_grouping;
      if ( __lc -> _M_use_grouping )
 __found_grouping . reserve ( 32 );
      const char_type * __lit_zero = __lit + __num_base :: _S_izero;

      if ( ! __lc -> _M_allocated )

 while ( ! __testeof )
   {
     const int __digit = _M_find ( __lit_zero, 10, __c );
     if ( __digit != - 1 )
       {
  __xtrc += '0' + __digit;
  __found_mantissa = true;
       }
     else if ( __c == __lc -> _M_decimal_point
       && ! __found_dec && ! __found_sci )
       {
  __xtrc += '.';
  __found_dec = true;
       }
     else if ( ( __c == __lit [ __num_base :: _S_ie ]
        || __c == __lit [ __num_base :: _S_iE ] )
       && ! __found_sci && __found_mantissa )
       {

  __xtrc += 'e';
  __found_sci = true;


  if ( ++ __beg != __end )
    {
      __c = * __beg;
      const bool __plus = __c == __lit [ __num_base :: _S_iplus ];
      if ( __plus || __c == __lit [ __num_base :: _S_iminus ] )
        __xtrc += __plus ? '+' : '-';
      else
        continue;
    }
  else
    {
      __testeof = true;
      break;
    }
       }
     else
       break;

     if ( ++ __beg != __end )
       __c = * __beg;
     else
       __testeof = true;
   }
      else
 while ( ! __testeof )
   {


     if ( __lc -> _M_use_grouping && __c == __lc -> _M_thousands_sep )
       {
  if ( ! __found_dec && ! __found_sci )
    {


      if ( __sep_pos )
        {
   __found_grouping += static_cast < char > ( __sep_pos );
   __sep_pos = 0;
        }
      else
        {


   __xtrc . clear ( );
   break;
        }
    }
  else
    break;
       }
     else if ( __c == __lc -> _M_decimal_point )
       {
  if ( ! __found_dec && ! __found_sci )
    {



      if ( __found_grouping . size ( ) )
        __found_grouping += static_cast < char > ( __sep_pos );
      __xtrc += '.';
      __found_dec = true;
    }
  else
    break;
       }
     else
       {
  const char_type * __q =
    __traits_type :: find ( __lit_zero, 10, __c );
  if ( __q )
    {
      __xtrc += '0' + ( __q - __lit_zero );
      __found_mantissa = true;
      ++ __sep_pos;
    }
  else if ( ( __c == __lit [ __num_base :: _S_ie ]
     || __c == __lit [ __num_base :: _S_iE ] )
    && ! __found_sci && __found_mantissa )
    {

      if ( __found_grouping . size ( ) && ! __found_dec )
        __found_grouping += static_cast < char > ( __sep_pos );
      __xtrc += 'e';
      __found_sci = true;


      if ( ++ __beg != __end )
        {
   __c = * __beg;
   const bool __plus = __c == __lit [ __num_base :: _S_iplus ];
   if ( ( __plus || __c == __lit [ __num_base :: _S_iminus ] )
       && ! ( __lc -> _M_use_grouping
     && __c == __lc -> _M_thousands_sep )
       && ! ( __c == __lc -> _M_decimal_point ) )
        __xtrc += __plus ? '+' : '-';
   else
     continue;
        }
      else
        {
   __testeof = true;
   break;
        }
    }
  else
    break;
       }

     if ( ++ __beg != __end )
       __c = * __beg;
     else
       __testeof = true;
   }



      if ( __found_grouping . size ( ) )
        {

   if ( ! __found_dec && ! __found_sci )
     __found_grouping += static_cast < char > ( __sep_pos );

          if ( ! std :: __verify_grouping ( __lc -> _M_grouping,
          __lc -> _M_grouping_size,
          __found_grouping ) )
     __err = ios_base :: failbit;
        }

      return __beg;
    }

template < typename _CharT, typename _InIter >
    template < typename _ValueT >
      _InIter
      num_get < _CharT, _InIter > ::
      _M_extract_int ( _InIter __beg, _InIter __end, ios_base & __io,
       ios_base :: iostate & __err, _ValueT & __v ) const
      {
        typedef char_traits < _CharT > __traits_type;
 using __gnu_cxx :: __add_unsigned;
 typedef typename __add_unsigned < _ValueT > :: __type __unsigned_type;
 typedef __numpunct_cache < _CharT > __cache_type;
 __use_cache < __cache_type > __uc;
 const locale & __loc = __io . _M_getloc ( );
 const __cache_type * __lc = __uc ( __loc );
 const _CharT * __lit = __lc -> _M_atoms_in;
 char_type __c = char_type ( );


 const ios_base :: fmtflags __basefield = __io . flags ( )
                                        & ios_base :: basefield;
 const bool __oct = __basefield == ios_base :: oct;
 int __base = __oct ? 8 : ( __basefield == ios_base :: hex ? 16 : 10 );


 bool __testeof = __beg == __end;


 bool __negative = false;
 if ( ! __testeof )
   {
     __c = * __beg;
     __negative = __c == __lit [ __num_base :: _S_iminus ];
     if ( ( __negative || __c == __lit [ __num_base :: _S_iplus ] )
  && ! ( __lc -> _M_use_grouping && __c == __lc -> _M_thousands_sep )
  && ! ( __c == __lc -> _M_decimal_point ) )
       {
  if ( ++ __beg != __end )
    __c = * __beg;
  else
    __testeof = true;
       }
   }



 bool __found_zero = false;
 int __sep_pos = 0;
 while ( ! __testeof )
   {
     if ( ( __lc -> _M_use_grouping && __c == __lc -> _M_thousands_sep )
  || __c == __lc -> _M_decimal_point )
       break;
     else if ( __c == __lit [ __num_base :: _S_izero ]
       && ( ! __found_zero || __base == 10 ) )
       {
  __found_zero = true;
  ++ __sep_pos;
  if ( __basefield == 0 )
    __base = 8;
  if ( __base == 8 )
    __sep_pos = 0;
       }
     else if ( __found_zero
       && ( __c == __lit [ __num_base :: _S_ix ]
    || __c == __lit [ __num_base :: _S_iX ] ) )
       {
  if ( __basefield == 0 )
    __base = 16;
  if ( __base == 16 )
    {
      __found_zero = false;
      __sep_pos = 0;
    }
  else
    break;
       }
     else
       break;

     if ( ++ __beg != __end )
       {
  __c = * __beg;
  if ( ! __found_zero )
    break;
       }
     else
       __testeof = true;
   }



 const size_t __len = ( __base == 16 ? __num_base :: _S_iend
         - __num_base :: _S_izero : __base );


 string __found_grouping;
 if ( __lc -> _M_use_grouping )
   __found_grouping . reserve ( 32 );
 bool __testfail = false;
 bool __testoverflow = false;
 const __unsigned_type __max =
   ( __negative && __gnu_cxx :: __numeric_traits < _ValueT > :: __is_signed )
   ? - __gnu_cxx :: __numeric_traits < _ValueT > :: __min
   : __gnu_cxx :: __numeric_traits < _ValueT > :: __max;
 const __unsigned_type __smax = __max / __base;
 __unsigned_type __result = 0;
 int __digit = 0;
 const char_type * __lit_zero = __lit + __num_base :: _S_izero;

 if ( ! __lc -> _M_allocated )

   while ( ! __testeof )
     {
       __digit = _M_find ( __lit_zero, __len, __c );
       if ( __digit == - 1 )
  break;

       if ( __result > __smax )
  __testoverflow = true;
       else
  {
    __result *= __base;
    __testoverflow |= __result > __max - __digit;
    __result += __digit;
    ++ __sep_pos;
  }

       if ( ++ __beg != __end )
  __c = * __beg;
       else
  __testeof = true;
     }
 else
   while ( ! __testeof )
     {


       if ( __lc -> _M_use_grouping && __c == __lc -> _M_thousands_sep )
  {


    if ( __sep_pos )
      {
        __found_grouping += static_cast < char > ( __sep_pos );
        __sep_pos = 0;
      }
    else
      {
        __testfail = true;
        break;
      }
  }
       else if ( __c == __lc -> _M_decimal_point )
  break;
       else
  {
    const char_type * __q =
      __traits_type :: find ( __lit_zero, __len, __c );
    if ( ! __q )
      break;

    __digit = __q - __lit_zero;
    if ( __digit > 15 )
      __digit -= 6;
    if ( __result > __smax )
      __testoverflow = true;
    else
      {
        __result *= __base;
        __testoverflow |= __result > __max - __digit;
        __result += __digit;
        ++ __sep_pos;
      }
  }

       if ( ++ __beg != __end )
  __c = * __beg;
       else
  __testeof = true;
     }



 if ( __found_grouping . size ( ) )
   {

     __found_grouping += static_cast < char > ( __sep_pos );

     if ( ! std :: __verify_grouping ( __lc -> _M_grouping,
     __lc -> _M_grouping_size,
     __found_grouping ) )
       __err = ios_base :: failbit;
   }



 if ( ( ! __sep_pos && ! __found_zero && ! __found_grouping . size ( ) )
     || __testfail )
   {
     __v = 0;
     __err = ios_base :: failbit;
   }
 else if ( __testoverflow )
   {
     if ( __negative
  && __gnu_cxx :: __numeric_traits < _ValueT > :: __is_signed )
       __v = __gnu_cxx :: __numeric_traits < _ValueT > :: __min;
     else
       __v = __gnu_cxx :: __numeric_traits < _ValueT > :: __max;
     __err = ios_base :: failbit;
   }
 else
   __v = __negative ? - __result : __result;

 if ( __testeof )
   __err |= ios_base :: eofbit;
 return __beg;
      }



template < typename _CharT, typename _InIter >
    _InIter
    num_get < _CharT, _InIter > ::
    do_get ( iter_type __beg, iter_type __end, ios_base & __io,
           ios_base :: iostate & __err, bool & __v ) const
    {
      if ( ! ( __io . flags ( ) & ios_base :: boolalpha ) )
        {



   long __l = - 1;
          __beg = _M_extract_int ( __beg, __end, __io, __err, __l );
   if ( __l == 0 || __l == 1 )
     __v = bool ( __l );
   else
     {


       __v = true;
       __err = ios_base :: failbit;
       if ( __beg == __end )
  __err |= ios_base :: eofbit;
     }
        }
      else
        {

   typedef __numpunct_cache < _CharT > __cache_type;
   __use_cache < __cache_type > __uc;
   const locale & __loc = __io . _M_getloc ( );
   const __cache_type * __lc = __uc ( __loc );

   bool __testf = true;
   bool __testt = true;
   bool __donef = __lc -> _M_falsename_size == 0;
   bool __donet = __lc -> _M_truename_size == 0;
   bool __testeof = false;
   size_t __n = 0;
   while ( ! __donef || ! __donet )
     {
       if ( __beg == __end )
  {
    __testeof = true;
    break;
  }

       const char_type __c = * __beg;

       if ( ! __donef )
  __testf = __c == __lc -> _M_falsename [ __n ];

       if ( ! __testf && __donet )
  break;

       if ( ! __donet )
  __testt = __c == __lc -> _M_truename [ __n ];

       if ( ! __testt && __donef )
  break;

       if ( ! __testt && ! __testf )
  break;

       ++ __n;
       ++ __beg;

       __donef = ! __testf || __n >= __lc -> _M_falsename_size;
       __donet = ! __testt || __n >= __lc -> _M_truename_size;
     }
   if ( __testf && __n == __lc -> _M_falsename_size && __n )
     {
       __v = false;
       if ( __testt && __n == __lc -> _M_truename_size )
  __err = ios_base :: failbit;
       else
  __err = __testeof ? ios_base :: eofbit : ios_base :: goodbit;
     }
   else if ( __testt && __n == __lc -> _M_truename_size && __n )
     {
       __v = true;
       __err = __testeof ? ios_base :: eofbit : ios_base :: goodbit;
     }
   else
     {


       __v = false;
       __err = ios_base :: failbit;
       if ( __testeof )
  __err |= ios_base :: eofbit;
     }
 }
      return __beg;
    }

template < typename _CharT, typename _InIter >
    _InIter
    num_get < _CharT, _InIter > ::
    do_get ( iter_type __beg, iter_type __end, ios_base & __io,
    ios_base :: iostate & __err, float & __v ) const
    {
      string __xtrc;
      __xtrc . reserve ( 32 );
      __beg = _M_extract_float ( __beg, __end, __io, __err, __xtrc );
      std :: __convert_to_v ( __xtrc . c_str ( ), __v, __err, _S_get_c_locale ( ) );
      if ( __beg == __end )
 __err |= ios_base :: eofbit;
      return __beg;
    }

template < typename _CharT, typename _InIter >
    _InIter
    num_get < _CharT, _InIter > ::
    do_get ( iter_type __beg, iter_type __end, ios_base & __io,
           ios_base :: iostate & __err, double & __v ) const
    {
      string __xtrc;
      __xtrc . reserve ( 32 );
      __beg = _M_extract_float ( __beg, __end, __io, __err, __xtrc );
      std :: __convert_to_v ( __xtrc . c_str ( ), __v, __err, _S_get_c_locale ( ) );
      if ( __beg == __end )
 __err |= ios_base :: eofbit;
      return __beg;
    }
# 715
template < typename _CharT, typename _InIter >
    _InIter
    num_get < _CharT, _InIter > ::
    do_get ( iter_type __beg, iter_type __end, ios_base & __io,
           ios_base :: iostate & __err, long double & __v ) const
    {
      string __xtrc;
      __xtrc . reserve ( 32 );
      __beg = _M_extract_float ( __beg, __end, __io, __err, __xtrc );
      std :: __convert_to_v ( __xtrc . c_str ( ), __v, __err, _S_get_c_locale ( ) );
      if ( __beg == __end )
 __err |= ios_base :: eofbit;
      return __beg;
    }

template < typename _CharT, typename _InIter >
    _InIter
    num_get < _CharT, _InIter > ::
    do_get ( iter_type __beg, iter_type __end, ios_base & __io,
           ios_base :: iostate & __err, void * & __v ) const
    {

      typedef ios_base :: fmtflags fmtflags;
      const fmtflags __fmt = __io . flags ( );
      __io . flags ( ( __fmt & ~ ios_base :: basefield ) | ios_base :: hex );

      typedef __gnu_cxx :: __conditional_type < ( sizeof ( void * )
          <= sizeof ( unsigned long ) ),
 unsigned long, unsigned long long > :: __type _UIntPtrType;

      _UIntPtrType __ul;
      __beg = _M_extract_int ( __beg, __end, __io, __err, __ul );


      __io . flags ( __fmt );

      __v = reinterpret_cast < void * > ( __ul );
      return __beg;
    }



template < typename _CharT, typename _OutIter >
    void
    num_put < _CharT, _OutIter > ::
    _M_pad ( _CharT __fill, streamsize __w, ios_base & __io,
    _CharT * __new, const _CharT * __cs, int & __len ) const
    {


      __pad < _CharT, char_traits < _CharT > > :: _S_pad ( __io, __fill, __new,
        __cs, __w, __len );
      __len = static_cast < int > ( __w );
    }



template < typename _CharT, typename _ValueT >
    int
    __int_to_char ( _CharT * __bufend, _ValueT __v, const _CharT * __lit,
    ios_base :: fmtflags __flags, bool __dec )
    {
      _CharT * __buf = __bufend;
      if ( __builtin_expect ( __dec, true ) )
 {

   do
     {
       * -- __buf = __lit [ ( __v % 10 ) + __num_base :: _S_odigits ];
       __v /= 10;
     }
   while ( __v != 0 );
 }
      else if ( ( __flags & ios_base :: basefield ) == ios_base :: oct )
 {

   do
     {
       * -- __buf = __lit [ ( __v & 7 ) + __num_base :: _S_odigits ];
       __v >>= 3;
     }
   while ( __v != 0 );
 }
      else
 {

   const bool __uppercase = __flags & ios_base :: uppercase;
   const int __case_offset = __uppercase ? __num_base :: _S_oudigits
                                         : __num_base :: _S_odigits;
   do
     {
       * -- __buf = __lit [ ( __v & 15 ) + __case_offset ];
       __v >>= 4;
     }
   while ( __v != 0 );
 }
      return __bufend - __buf;
    }



template < typename _CharT, typename _OutIter >
    void
    num_put < _CharT, _OutIter > ::
    _M_group_int ( const char * __grouping, size_t __grouping_size, _CharT __sep,
   ios_base &, _CharT * __new, _CharT * __cs, int & __len ) const
    {
      _CharT * __p = std :: __add_grouping ( __new, __sep, __grouping,
     __grouping_size, __cs, __cs + __len );
      __len = __p - __new;
    }

template < typename _CharT, typename _OutIter >
    template < typename _ValueT >
      _OutIter
      num_put < _CharT, _OutIter > ::
      _M_insert_int ( _OutIter __s, ios_base & __io, _CharT __fill,
      _ValueT __v ) const
      {
 using __gnu_cxx :: __add_unsigned;
 typedef typename __add_unsigned < _ValueT > :: __type __unsigned_type;
 typedef __numpunct_cache < _CharT > __cache_type;
 __use_cache < __cache_type > __uc;
 const locale & __loc = __io . _M_getloc ( );
 const __cache_type * __lc = __uc ( __loc );
 const _CharT * __lit = __lc -> _M_atoms_out;
 const ios_base :: fmtflags __flags = __io . flags ( );


 const int __ilen = 5 * sizeof ( _ValueT );
 _CharT * __cs = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
            * __ilen ) );



 const ios_base :: fmtflags __basefield = __flags & ios_base :: basefield;
 const bool __dec = ( __basefield != ios_base :: oct
       && __basefield != ios_base :: hex );
 const __unsigned_type __u = ( ( __v > 0 || ! __dec )
         ? __unsigned_type ( __v )
         : - __unsigned_type ( __v ) );
  int __len = __int_to_char ( __cs + __ilen, __u, __lit, __flags, __dec );
 __cs += __ilen - __len;


 if ( __lc -> _M_use_grouping )
   {


     _CharT * __cs2 = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
          * ( __len + 1 )
          * 2 ) );
     _M_group_int ( __lc -> _M_grouping, __lc -> _M_grouping_size,
    __lc -> _M_thousands_sep, __io, __cs2 + 2, __cs, __len );
     __cs = __cs2 + 2;
   }


 if ( __builtin_expect ( __dec, true ) )
   {

     if ( __v >= 0 )
       {
  if ( bool ( __flags & ios_base :: showpos )
      && __gnu_cxx :: __numeric_traits < _ValueT > :: __is_signed )
    * -- __cs = __lit [ __num_base :: _S_oplus ], ++ __len;
       }
     else
       * -- __cs = __lit [ __num_base :: _S_ominus ], ++ __len;
   }
 else if ( bool ( __flags & ios_base :: showbase ) && __v )
   {
     if ( __basefield == ios_base :: oct )
       * -- __cs = __lit [ __num_base :: _S_odigits ], ++ __len;
     else
       {

  const bool __uppercase = __flags & ios_base :: uppercase;
  * -- __cs = __lit [ __num_base :: _S_ox + __uppercase ];

  * -- __cs = __lit [ __num_base :: _S_odigits ];
  __len += 2;
       }
   }


 const streamsize __w = __io . width ( );
 if ( __w > static_cast < streamsize > ( __len ) )
   {
     _CharT * __cs3 = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
          * __w ) );
     _M_pad ( __fill, __w, __io, __cs3, __cs, __len );
     __cs = __cs3;
   }
 __io . width ( 0 );



 return std :: __write ( __s, __cs, __len );
      }

template < typename _CharT, typename _OutIter >
    void
    num_put < _CharT, _OutIter > ::
    _M_group_float ( const char * __grouping, size_t __grouping_size,
     _CharT __sep, const _CharT * __p, _CharT * __new,
     _CharT * __cs, int & __len ) const
    {



      const int __declen = __p ? __p - __cs : __len;
      _CharT * __p2 = std :: __add_grouping ( __new, __sep, __grouping,
      __grouping_size,
      __cs, __cs + __declen );


      int __newlen = __p2 - __new;
      if ( __p )
 {
   char_traits < _CharT > :: copy ( __p2, __p, __len - __declen );
   __newlen += __len - __declen;
 }
      __len = __newlen;
    }
# 951
template < typename _CharT, typename _OutIter >
    template < typename _ValueT >
      _OutIter
      num_put < _CharT, _OutIter > ::
      _M_insert_float ( _OutIter __s, ios_base & __io, _CharT __fill, char __mod,
         _ValueT __v ) const
      {
 typedef __numpunct_cache < _CharT > __cache_type;
 __use_cache < __cache_type > __uc;
 const locale & __loc = __io . _M_getloc ( );
 const __cache_type * __lc = __uc ( __loc );


 const streamsize __prec = __io . precision ( ) < 0 ? 6 : __io . precision ( );

 const int __max_digits =
   __gnu_cxx :: __numeric_traits < _ValueT > :: __digits10;


 int __len;

 char __fbuf [ 16 ];
 __num_base :: _S_format_float ( __io, __fbuf, __mod );




 int __cs_size = __max_digits * 3;
 char * __cs = static_cast < char * > ( __builtin_alloca ( __cs_size ) );
 __len = std :: __convert_from_v ( _S_get_c_locale ( ), __cs, __cs_size,
          __fbuf, __prec, __v );


 if ( __len >= __cs_size )
   {
     __cs_size = __len + 1;
     __cs = static_cast < char * > ( __builtin_alloca ( __cs_size ) );
     __len = std :: __convert_from_v ( _S_get_c_locale ( ), __cs, __cs_size,
       __fbuf, __prec, __v );
   }





















 const ctype < _CharT > & __ctype = use_facet < ctype < _CharT > > ( __loc );

 _CharT * __ws = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
            * __len ) );
 __ctype . widen ( __cs, __cs + __len, __ws );


 _CharT * __wp = 0;
 const char * __p = char_traits < char > :: find ( __cs, __len, '.' );
 if ( __p )
   {
     __wp = __ws + ( __p - __cs );
     * __wp = __lc -> _M_decimal_point;
   }




 if ( __lc -> _M_use_grouping
     && ( __wp || __len < 3 || ( __cs [ 1 ] <= '9' && __cs [ 2 ] <= '9'
          && __cs [ 1 ] >= '0' && __cs [ 2 ] >= '0' ) ) )
   {


     _CharT * __ws2 = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
          * __len * 2 ) );

     streamsize __off = 0;
     if ( __cs [ 0 ] == '-' || __cs [ 0 ] == '+' )
       {
  __off = 1;
  __ws2 [ 0 ] = __ws [ 0 ];
  __len -= 1;
       }

     _M_group_float ( __lc -> _M_grouping, __lc -> _M_grouping_size,
      __lc -> _M_thousands_sep, __wp, __ws2 + __off,
      __ws + __off, __len );
     __len += __off;

     __ws = __ws2;
   }


 const streamsize __w = __io . width ( );
 if ( __w > static_cast < streamsize > ( __len ) )
   {
     _CharT * __ws3 = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
          * __w ) );
     _M_pad ( __fill, __w, __io, __ws3, __ws, __len );
     __ws = __ws3;
   }
 __io . width ( 0 );



 return std :: __write ( __s, __ws, __len );
      }

template < typename _CharT, typename _OutIter >
    _OutIter
    num_put < _CharT, _OutIter > ::
    do_put ( iter_type __s, ios_base & __io, char_type __fill, bool __v ) const
    {
      const ios_base :: fmtflags __flags = __io . flags ( );
      if ( ( __flags & ios_base :: boolalpha ) == 0 )
        {
          const long __l = __v;
          __s = _M_insert_int ( __s, __io, __fill, __l );
        }
      else
        {
   typedef __numpunct_cache < _CharT > __cache_type;
   __use_cache < __cache_type > __uc;
   const locale & __loc = __io . _M_getloc ( );
   const __cache_type * __lc = __uc ( __loc );

   const _CharT * __name = __v ? __lc -> _M_truename
                              : __lc -> _M_falsename;
   int __len = __v ? __lc -> _M_truename_size
                   : __lc -> _M_falsename_size;

   const streamsize __w = __io . width ( );
   if ( __w > static_cast < streamsize > ( __len ) )
     {
       const streamsize __plen = __w - __len;
       _CharT * __ps
  = static_cast < _CharT * > ( __builtin_alloca ( sizeof ( _CharT )
       * __plen ) );

       char_traits < _CharT > :: assign ( __ps, __plen, __fill );
       __io . width ( 0 );

       if ( ( __flags & ios_base :: adjustfield ) == ios_base :: left )
  {
    __s = std :: __write ( __s, __name, __len );
    __s = std :: __write ( __s, __ps, __plen );
  }
       else
  {
    __s = std :: __write ( __s, __ps, __plen );
    __s = std :: __write ( __s, __name, __len );
  }
       return __s;
     }
   __io . width ( 0 );
   __s = std :: __write ( __s, __name, __len );
 }
      return __s;
    }

template < typename _CharT, typename _OutIter >
    _OutIter
    num_put < _CharT, _OutIter > ::
    do_put ( iter_type __s, ios_base & __io, char_type __fill, double __v ) const
    { return _M_insert_float ( __s, __io, __fill, char ( ), __v ); }
# 1137
template < typename _CharT, typename _OutIter >
    _OutIter
    num_put < _CharT, _OutIter > ::
    do_put ( iter_type __s, ios_base & __io, char_type __fill,
    long double __v ) const
    { return _M_insert_float ( __s, __io, __fill, 'L', __v ); }

template < typename _CharT, typename _OutIter >
    _OutIter
    num_put < _CharT, _OutIter > ::
    do_put ( iter_type __s, ios_base & __io, char_type __fill,
           const void * __v ) const
    {
      const ios_base :: fmtflags __flags = __io . flags ( );
      const ios_base :: fmtflags __fmt = ~ ( ios_base :: basefield
      | ios_base :: uppercase );
      __io . flags ( ( __flags & __fmt ) | ( ios_base :: hex | ios_base :: showbase ) );

      typedef __gnu_cxx :: __conditional_type < ( sizeof ( const void * )
          <= sizeof ( unsigned long ) ),
 unsigned long, unsigned long long > :: __type _UIntPtrType;

      __s = _M_insert_int ( __s, __io, __fill,
     reinterpret_cast < _UIntPtrType > ( __v ) );
      __io . flags ( __flags );
      return __s;
    }
# 1174
template < typename _CharT, typename _Traits >
    void
    __pad < _CharT, _Traits > :: _S_pad ( ios_base & __io, _CharT __fill,
       _CharT * __news, const _CharT * __olds,
       streamsize __newlen, streamsize __oldlen )
    {
      const size_t __plen = static_cast < size_t > ( __newlen - __oldlen );
      const ios_base :: fmtflags __adjust = __io . flags ( ) & ios_base :: adjustfield;


      if ( __adjust == ios_base :: left )
 {
   _Traits :: copy ( __news, __olds, __oldlen );
   _Traits :: assign ( __news + __oldlen, __plen, __fill );
   return;
 }

      size_t __mod = 0;
      if ( __adjust == ios_base :: internal )
 {



          const locale & __loc = __io . _M_getloc ( );
   const ctype < _CharT > & __ctype = use_facet < ctype < _CharT > > ( __loc );

   if ( __ctype . widen ( '-' ) == __olds [ 0 ]
       || __ctype . widen ( '+' ) == __olds [ 0 ] )
     {
       __news [ 0 ] = __olds [ 0 ];
       __mod = 1;
       ++ __news;
     }
   else if ( __ctype . widen ( '0' ) == __olds [ 0 ]
     && __oldlen > 1
     && ( __ctype . widen ( 'x' ) == __olds [ 1 ]
         || __ctype . widen ( 'X' ) == __olds [ 1 ] ) )
     {
       __news [ 0 ] = __olds [ 0 ];
       __news [ 1 ] = __olds [ 1 ];
       __mod = 2;
       __news += 2;
     }

 }
      _Traits :: assign ( __news, __plen, __fill );
      _Traits :: copy ( __news + __plen, __olds + __mod, __oldlen - __mod );
    }

template < typename _CharT >
    _CharT *
    __add_grouping ( _CharT * __s, _CharT __sep,
     const char * __gbeg, size_t __gsize,
     const _CharT * __first, const _CharT * __last )
    {
      size_t __idx = 0;
      size_t __ctr = 0;

      while ( __last - __first > __gbeg [ __idx ]
      && static_cast < signed char > ( __gbeg [ __idx ] ) > 0
      && __gbeg [ __idx ] != __gnu_cxx :: __numeric_traits < char > :: __max )
 {
   __last -= __gbeg [ __idx ];
   __idx < __gsize - 1 ? ++ __idx : ++ __ctr;
 }

      while ( __first != __last )
 * __s ++ = * __first ++;

      while ( __ctr -- )
 {
   * __s ++ = __sep;
   for ( char __i = __gbeg [ __idx ]; __i > 0; -- __i )
     * __s ++ = * __first ++;
 }

      while ( __idx -- )
 {
   * __s ++ = __sep;
   for ( char __i = __gbeg [ __idx ]; __i > 0; -- __i )
     * __s ++ = * __first ++;
 }

      return __s;
    }
# 1264
extern template class numpunct< char> ;
extern template class numpunct_byname< char> ;
extern template class num_get< char, istreambuf_iterator< char, char_traits< char> > > ;
extern template class num_put< char, ostreambuf_iterator< char, char_traits< char> > > ;


extern template const ctype< char>  &use_facet< ctype< char> > (const locale &);



extern template const numpunct< char>  &use_facet< numpunct< char> > (const locale &);



extern template const num_put< char, ostreambuf_iterator< char, char_traits< char> > >  &use_facet< num_put< char, ostreambuf_iterator< char, char_traits< char> > > > (const locale &);



extern template const num_get< char, istreambuf_iterator< char, char_traits< char> > >  &use_facet< num_get< char, istreambuf_iterator< char, char_traits< char> > > > (const locale &);



extern template bool has_facet< ctype< char> > (const locale &) throw();



extern template bool has_facet< numpunct< char> > (const locale &) throw();



extern template bool has_facet< num_put< char, ostreambuf_iterator< char, char_traits< char> > > > (const locale &) throw();



extern template bool has_facet< num_get< char, istreambuf_iterator< char, char_traits< char> > > > (const locale &) throw();




extern template class numpunct< wchar_t> ;
extern template class numpunct_byname< wchar_t> ;
extern template class num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > > ;
extern template class num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > > ;


extern template const ctype< wchar_t>  &use_facet< ctype< wchar_t> > (const locale &);



extern template const numpunct< wchar_t>  &use_facet< numpunct< wchar_t> > (const locale &);



extern template const num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > >  &use_facet< num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &);



extern template const num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > >  &use_facet< num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &);



extern template bool has_facet< ctype< wchar_t> > (const locale &) throw();



extern template bool has_facet< numpunct< wchar_t> > (const locale &) throw();



extern template bool has_facet< num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &) throw();



extern template bool has_facet< num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &) throw();
# 1343
}
# 42 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_ios.h" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _Facet >
    inline const _Facet &
    __check_facet ( const _Facet * __f )
    {
      if ( ! __f )
 __throw_bad_cast ( );
      return * __f;
    }
# 61
template < typename _CharT, typename _Traits >
    class basic_ios : public ios_base
    {
    public :






      typedef _CharT char_type;
      typedef typename _Traits :: int_type int_type;
      typedef typename _Traits :: pos_type pos_type;
      typedef typename _Traits :: off_type off_type;
      typedef _Traits traits_type;






      typedef ctype < _CharT > __ctype_type;
      typedef num_put < _CharT, ostreambuf_iterator < _CharT, _Traits > >
           __num_put_type;
      typedef num_get < _CharT, istreambuf_iterator < _CharT, _Traits > >
           __num_get_type;



    protected :
      basic_ostream < _CharT, _Traits > * _M_tie;
      mutable char_type _M_fill;
      mutable bool _M_fill_init;
      basic_streambuf < _CharT, _Traits > * _M_streambuf;


      const __ctype_type * _M_ctype;

      const __num_put_type * _M_num_put;

      const __num_get_type * _M_num_get;

    public :







      operator void * ( ) const
      { return this -> fail ( ) ? 0 : const_cast < basic_ios * > ( this ); }

      bool
      operator ! ( ) const
      { return this -> fail ( ); }









      iostate
      rdstate ( ) const
      { return _M_streambuf_state; }








      void
      clear ( iostate __state = goodbit );







      void
      setstate ( iostate __state )
      { this -> clear ( this -> rdstate ( ) | __state ); }




      void
      _M_setstate ( iostate __state )
      {


 _M_streambuf_state |= __state;
 if ( this -> exceptions ( ) & __state )
   throw;
      }







      bool
      good ( ) const
      { return this -> rdstate ( ) == 0; }







      bool
      eof ( ) const
      { return ( this -> rdstate ( ) & eofbit ) != 0; }








      bool
      fail ( ) const
      { return ( this -> rdstate ( ) & ( badbit | failbit ) ) != 0; }







      bool
      bad ( ) const
      { return ( this -> rdstate ( ) & badbit ) != 0; }








      iostate
      exceptions ( ) const
      { return _M_exception; }
































      void
      exceptions ( iostate __except )
      {
        _M_exception = __except;
        this -> clear ( _M_streambuf_state );
      }







      explicit
      basic_ios ( basic_streambuf < _CharT, _Traits > * __sb )
      : ios_base ( ), _M_tie ( 0 ), _M_fill ( ), _M_fill_init ( false ), _M_streambuf ( 0 ),
 _M_ctype ( 0 ), _M_num_put ( 0 ), _M_num_get ( 0 )
      { this -> init ( __sb ); }







      virtual
      ~ basic_ios ( ) { }











      basic_ostream < _CharT, _Traits > *
      tie ( ) const
      { return _M_tie; }









      basic_ostream < _CharT, _Traits > *
      tie ( basic_ostream < _CharT, _Traits > * __tiestr )
      {
        basic_ostream < _CharT, _Traits > * __old = _M_tie;
        _M_tie = __tiestr;
        return __old;
      }







      basic_streambuf < _CharT, _Traits > *
      rdbuf ( ) const
      { return _M_streambuf; }























      basic_streambuf < _CharT, _Traits > *
      rdbuf ( basic_streambuf < _CharT, _Traits > * __sb );












      basic_ios &
      copyfmt ( const basic_ios & __rhs );







      char_type
      fill ( ) const
      {
 if ( ! _M_fill_init )
   {
     _M_fill = this -> widen ( ' ' );
     _M_fill_init = true;
   }
 return _M_fill;
      }










      char_type
      fill ( char_type __ch )
      {
 char_type __old = this -> fill ( );
 _M_fill = __ch;
 return __old;
      }













      locale
      imbue ( const locale & __loc );


















      char
      narrow ( char_type __c, char __dfault ) const
      { return __check_facet ( _M_ctype ) . narrow ( __c, __dfault ); }
















      char_type
      widen ( char __c ) const
      { return __check_facet ( _M_ctype ) . widen ( __c ); }

    protected :







      basic_ios ( )
      : ios_base ( ), _M_tie ( 0 ), _M_fill ( char_type ( ) ), _M_fill_init ( false ),
 _M_streambuf ( 0 ), _M_ctype ( 0 ), _M_num_put ( 0 ), _M_num_get ( 0 )
      { }







      void
      init ( basic_streambuf < _CharT, _Traits > * __sb );

      void
      _M_cache_locale ( const locale & __loc );
    };

}
# 36 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/basic_ios.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    void
    basic_ios < _CharT, _Traits > :: clear ( iostate __state )
    {
      if ( this -> rdbuf ( ) )
 _M_streambuf_state = __state;
      else
   _M_streambuf_state = __state | badbit;
      if ( this -> exceptions ( ) & this -> rdstate ( ) )
 __throw_ios_failure ( ( "basic_ios::clear" ) );
    }

template < typename _CharT, typename _Traits >
    basic_streambuf < _CharT, _Traits > *
    basic_ios < _CharT, _Traits > :: rdbuf ( basic_streambuf < _CharT, _Traits > * __sb )
    {
      basic_streambuf < _CharT, _Traits > * __old = _M_streambuf;
      _M_streambuf = __sb;
      this -> clear ( );
      return __old;
    }

template < typename _CharT, typename _Traits >
    basic_ios < _CharT, _Traits > &
    basic_ios < _CharT, _Traits > :: copyfmt ( const basic_ios & __rhs )
    {


      if ( this != & __rhs )
 {




   _Words * __words = ( __rhs . _M_word_size <= _S_local_word_size ) ?
                      _M_local_word : new _Words [ __rhs . _M_word_size ];


   _Callback_list * __cb = __rhs . _M_callbacks;
   if ( __cb )
     __cb -> _M_add_reference ( );
   _M_call_callbacks ( erase_event );
   if ( _M_word != _M_local_word )
     {
       delete [ ] _M_word;
       _M_word = 0;
     }
   _M_dispose_callbacks ( );


   _M_callbacks = __cb;
   for ( int __i = 0; __i < __rhs . _M_word_size; ++ __i )
     __words [ __i ] = __rhs . _M_word [ __i ];
   _M_word = __words;
   _M_word_size = __rhs . _M_word_size;

   this -> flags ( __rhs . flags ( ) );
   this -> width ( __rhs . width ( ) );
   this -> precision ( __rhs . precision ( ) );
   this -> tie ( __rhs . tie ( ) );
   this -> fill ( __rhs . fill ( ) );
   _M_ios_locale = __rhs . getloc ( );
   _M_cache_locale ( _M_ios_locale );

   _M_call_callbacks ( copyfmt_event );


   this -> exceptions ( __rhs . exceptions ( ) );
 }
      return * this;
    }


template < typename _CharT, typename _Traits >
    locale
    basic_ios < _CharT, _Traits > :: imbue ( const locale & __loc )
    {
      locale __old ( this -> getloc ( ) );
      ios_base :: imbue ( __loc );
      _M_cache_locale ( __loc );
      if ( this -> rdbuf ( ) != 0 )
 this -> rdbuf ( ) -> pubimbue ( __loc );
      return __old;
    }

template < typename _CharT, typename _Traits >
    void
    basic_ios < _CharT, _Traits > :: init ( basic_streambuf < _CharT, _Traits > * __sb )
    {

      ios_base :: _M_init ( );


      _M_cache_locale ( _M_ios_locale );













      _M_fill = _CharT ( );
      _M_fill_init = false;

      _M_tie = 0;
      _M_exception = goodbit;
      _M_streambuf = __sb;
      _M_streambuf_state = __sb ? goodbit : badbit;
    }

template < typename _CharT, typename _Traits >
    void
    basic_ios < _CharT, _Traits > :: _M_cache_locale ( const locale & __loc )
    {
      if ( __builtin_expect ( has_facet < __ctype_type > ( __loc ), true ) )
 _M_ctype = & use_facet < __ctype_type > ( __loc );
      else
 _M_ctype = 0;

      if ( __builtin_expect ( has_facet < __num_put_type > ( __loc ), true ) )
 _M_num_put = & use_facet < __num_put_type > ( __loc );
      else
 _M_num_put = 0;

      if ( __builtin_expect ( has_facet < __num_get_type > ( __loc ), true ) )
 _M_num_get = & use_facet < __num_get_type > ( __loc );
      else
 _M_num_get = 0;
    }
# 178
extern template class basic_ios< char, char_traits< char> > ;


extern template class basic_ios< wchar_t, char_traits< wchar_t> > ;



}
# 43 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/ostream" 3
namespace std __attribute((__visibility__("default" ))) { 
# 54
template < typename _CharT, typename _Traits >
    class basic_ostream : virtual public basic_ios < _CharT, _Traits >
    {
    public :

      typedef _CharT char_type;
      typedef typename _Traits :: int_type int_type;
      typedef typename _Traits :: pos_type pos_type;
      typedef typename _Traits :: off_type off_type;
      typedef _Traits traits_type;


      typedef basic_streambuf < _CharT, _Traits > __streambuf_type;
      typedef basic_ios < _CharT, _Traits > __ios_type;
      typedef basic_ostream < _CharT, _Traits > __ostream_type;
      typedef num_put < _CharT, ostreambuf_iterator < _CharT, _Traits > >
             __num_put_type;
      typedef ctype < _CharT > __ctype_type;









      explicit
      basic_ostream ( __streambuf_type * __sb )
      { this -> init ( __sb ); }






      virtual
      ~ basic_ostream ( ) { }


      class sentry;
      friend class sentry;











      __ostream_type &
      operator << ( __ostream_type & ( * __pf ) ( __ostream_type & ) )
      {



 return __pf ( * this );
      }

      __ostream_type &
      operator << ( __ios_type & ( * __pf ) ( __ios_type & ) )
      {



 __pf ( * this );
 return * this;
      }

      __ostream_type &
      operator << ( ios_base & ( * __pf ) ( ios_base & ) )
      {



 __pf ( * this );
 return * this;
      }





























      __ostream_type &
      operator << ( long __n )
      { return _M_insert ( __n ); }

      __ostream_type &
      operator << ( unsigned long __n )
      { return _M_insert ( __n ); }

      __ostream_type &
      operator << ( bool __n )
      { return _M_insert ( __n ); }

      __ostream_type &
      operator << ( short __n );

      __ostream_type &
      operator << ( unsigned short __n )
      {


 return _M_insert ( static_cast < unsigned long > ( __n ) );
      }

      __ostream_type &
      operator << ( int __n );

      __ostream_type &
      operator << ( unsigned int __n )
      {


 return _M_insert ( static_cast < unsigned long > ( __n ) );
      }


      __ostream_type &
      operator << ( long long __n )
      { return _M_insert ( __n ); }

      __ostream_type &
      operator << ( unsigned long long __n )
      { return _M_insert ( __n ); }


      __ostream_type &
      operator << ( double __f )
      { return _M_insert ( __f ); }

      __ostream_type &
      operator << ( float __f )
      {


 return _M_insert ( static_cast < double > ( __f ) );
      }

      __ostream_type &
      operator << ( long double __f )
      { return _M_insert ( __f ); }

      __ostream_type &
      operator << ( const void * __p )
      { return _M_insert ( __p ); }






















      __ostream_type &
      operator << ( __streambuf_type * __sb );































      __ostream_type &
      put ( char_type __c );


      void
      _M_write ( const char_type * __s, streamsize __n )
      {
 const streamsize __put = this -> rdbuf ( ) -> sputn ( __s, __n );
 if ( __put != __n )
   this -> setstate ( ios_base :: badbit );
      }

















      __ostream_type &
      write ( const char_type * __s, streamsize __n );











      __ostream_type &
      flush ( );









      pos_type
      tellp ( );









      __ostream_type &
      seekp ( pos_type );










       __ostream_type &
      seekp ( off_type, ios_base :: seekdir );

    protected :
      basic_ostream ( )
      { this -> init ( 0 ); }

      template < typename _ValueT >
        __ostream_type &
        _M_insert ( _ValueT __v );
    };
# 376
template < typename _CharT, typename _Traits >
    class basic_ostream < _CharT, _Traits > :: sentry
    {

      bool _M_ok;
      basic_ostream < _CharT, _Traits > & _M_os;

    public :











      explicit
      sentry ( basic_ostream < _CharT, _Traits > & __os );








      ~ sentry ( )
      {

 if ( bool ( _M_os . flags ( ) & ios_base :: unitbuf ) && ! uncaught_exception ( ) )
   {

     if ( _M_os . rdbuf ( ) && _M_os . rdbuf ( ) -> pubsync ( ) == - 1 )
       _M_os . setstate ( ios_base :: badbit );
   }
      }








      operator bool ( ) const
      { return _M_ok; }
    };
# 444
template < typename _CharT, typename _Traits >
    inline basic_ostream < _CharT, _Traits > &
    operator << ( basic_ostream < _CharT, _Traits > & __out, _CharT __c )
    { return __ostream_insert ( __out, & __c, 1 ); }

template < typename _CharT, typename _Traits >
    inline basic_ostream < _CharT, _Traits > &
    operator << ( basic_ostream < _CharT, _Traits > & __out, char __c )
    { return ( __out << __out . widen ( __c ) ); }


template < class _Traits >
    inline basic_ostream < char, _Traits > &
    operator << ( basic_ostream < char, _Traits > & __out, char __c )
    { return __ostream_insert ( __out, & __c, 1 ); }


template < class _Traits >
    inline basic_ostream < char, _Traits > &
    operator << ( basic_ostream < char, _Traits > & __out, signed char __c )
    { return ( __out << static_cast < char > ( __c ) ); }

template < class _Traits >
    inline basic_ostream < char, _Traits > &
    operator << ( basic_ostream < char, _Traits > & __out, unsigned char __c )
    { return ( __out << static_cast < char > ( __c ) ); }
# 486
template < typename _CharT, typename _Traits >
    inline basic_ostream < _CharT, _Traits > &
    operator << ( basic_ostream < _CharT, _Traits > & __out, const _CharT * __s )
    {
      if ( ! __s )
 __out . setstate ( ios_base :: badbit );
      else
 __ostream_insert ( __out, __s,
    static_cast < streamsize > ( _Traits :: length ( __s ) ) );
      return __out;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    operator << ( basic_ostream < _CharT, _Traits > & __out, const char * __s );


template < class _Traits >
    inline basic_ostream < char, _Traits > &
    operator << ( basic_ostream < char, _Traits > & __out, const char * __s )
    {
      if ( ! __s )
 __out . setstate ( ios_base :: badbit );
      else
 __ostream_insert ( __out, __s,
    static_cast < streamsize > ( _Traits :: length ( __s ) ) );
      return __out;
    }


template < class _Traits >
    inline basic_ostream < char, _Traits > &
    operator << ( basic_ostream < char, _Traits > & __out, const signed char * __s )
    { return ( __out << reinterpret_cast < const char * > ( __s ) ); }

template < class _Traits >
    inline basic_ostream < char, _Traits > &
    operator << ( basic_ostream < char, _Traits > & __out, const unsigned char * __s )
    { return ( __out << reinterpret_cast < const char * > ( __s ) ); }
# 536
template < typename _CharT, typename _Traits >
    inline basic_ostream < _CharT, _Traits > &
    endl ( basic_ostream < _CharT, _Traits > & __os )
    { return flush ( __os . put ( __os . widen ( '\n' ) ) ); }
# 547
template < typename _CharT, typename _Traits >
    inline basic_ostream < _CharT, _Traits > &
    ends ( basic_ostream < _CharT, _Traits > & __os )
    { return __os . put ( _CharT ( ) ); }
# 557
template < typename _CharT, typename _Traits >
    inline basic_ostream < _CharT, _Traits > &
    flush ( basic_ostream < _CharT, _Traits > & __os )
    { return __os . flush ( ); }

}
# 43 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/ostream.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > :: sentry ::
    sentry ( basic_ostream < _CharT, _Traits > & __os )
    : _M_ok ( false ), _M_os ( __os )
    {

      if ( __os . tie ( ) && __os . good ( ) )
 __os . tie ( ) -> flush ( );

      if ( __os . good ( ) )
 _M_ok = true;
      else
 __os . setstate ( ios_base :: failbit );
    }

template < typename _CharT, typename _Traits >
    template < typename _ValueT >
      basic_ostream < _CharT, _Traits > &
      basic_ostream < _CharT, _Traits > ::
      _M_insert ( _ValueT __v )
      {
 sentry __cerb ( * this );
 if ( __cerb )
   {
     ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
     try
       {
  const __num_put_type & __np = __check_facet ( this -> _M_num_put );
  if ( __np . put ( * this, * this, this -> fill ( ), __v ) . failed ( ) )
    __err |= ios_base :: badbit;
       }
     catch ( __cxxabiv1 :: __forced_unwind & )
       {
  this -> _M_setstate ( ios_base :: badbit );
  throw;
       }
     catch ( ... )
       { this -> _M_setstate ( ios_base :: badbit ); }
     if ( __err )
       this -> setstate ( __err );
   }
 return * this;
      }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    operator << ( short __n )
    {


      const ios_base :: fmtflags __fmt = this -> flags ( ) & ios_base :: basefield;
      if ( __fmt == ios_base :: oct || __fmt == ios_base :: hex )
 return _M_insert ( static_cast < long > ( static_cast < unsigned short > ( __n ) ) );
      else
 return _M_insert ( static_cast < long > ( __n ) );
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    operator << ( int __n )
    {


      const ios_base :: fmtflags __fmt = this -> flags ( ) & ios_base :: basefield;
      if ( __fmt == ios_base :: oct || __fmt == ios_base :: hex )
 return _M_insert ( static_cast < long > ( static_cast < unsigned int > ( __n ) ) );
      else
 return _M_insert ( static_cast < long > ( __n ) );
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    operator << ( __streambuf_type * __sbin )
    {
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this );
      if ( __cerb && __sbin )
 {
   try
     {
       if ( ! __copy_streambufs ( __sbin, this -> rdbuf ( ) ) )
  __err |= ios_base :: failbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: failbit ); }
 }
      else if ( ! __sbin )
 __err |= ios_base :: badbit;
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    put ( char_type __c )
    {






      sentry __cerb ( * this );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       const int_type __put = this -> rdbuf ( ) -> sputc ( __c );
       if ( traits_type :: eq_int_type ( __put, traits_type :: eof ( ) ) )
  __err |= ios_base :: badbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    write ( const _CharT * __s, streamsize __n )
    {







      sentry __cerb ( * this );
      if ( __cerb )
 {
   try
     { _M_write ( __s, __n ); }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    flush ( )
    {



      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      try
 {
   if ( this -> rdbuf ( ) && this -> rdbuf ( ) -> pubsync ( ) == - 1 )
     __err |= ios_base :: badbit;
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    typename basic_ostream < _CharT, _Traits > :: pos_type
    basic_ostream < _CharT, _Traits > ::
    tellp ( )
    {
      pos_type __ret = pos_type ( - 1 );
      try
 {
   if ( ! this -> fail ( ) )
     __ret = this -> rdbuf ( ) -> pubseekoff ( 0, ios_base :: cur, ios_base :: out );
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    seekp ( pos_type __pos )
    {
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      try
 {
   if ( ! this -> fail ( ) )
     {


       const pos_type __p = this -> rdbuf ( ) -> pubseekpos ( __pos,
            ios_base :: out );


       if ( __p == pos_type ( off_type ( - 1 ) ) )
  __err |= ios_base :: failbit;
     }
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    basic_ostream < _CharT, _Traits > ::
    seekp ( off_type __off, ios_base :: seekdir __dir )
    {
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      try
 {
   if ( ! this -> fail ( ) )
     {


       const pos_type __p = this -> rdbuf ( ) -> pubseekoff ( __off, __dir,
            ios_base :: out );


       if ( __p == pos_type ( off_type ( - 1 ) ) )
  __err |= ios_base :: failbit;
     }
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_ostream < _CharT, _Traits > &
    operator << ( basic_ostream < _CharT, _Traits > & __out, const char * __s )
    {
      if ( ! __s )
 __out . setstate ( ios_base :: badbit );
      else
 {


   const size_t __clen = char_traits < char > :: length ( __s );
   try
     {
       struct __ptr_guard
       {
  _CharT * __p;
  __ptr_guard ( _CharT * __ip ) : __p ( __ip ) { }
  ~ __ptr_guard ( ) { delete [ ] __p; }
  _CharT * __get ( ) { return __p; }
       } __pg ( new _CharT [ __clen ] );

       _CharT * __ws = __pg . __get ( );
       for ( size_t __i = 0; __i < __clen; ++ __i )
  __ws [ __i ] = __out . widen ( __s [ __i ] );
       __ostream_insert ( __out, __ws, __clen );
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       __out . _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { __out . _M_setstate ( ios_base :: badbit ); }
 }
      return __out;
    }
# 360
extern template class basic_ostream< char, char_traits< char> > ;
extern template basic_ostream< char, char_traits< char> >  &endl(basic_ostream< char, char_traits< char> >  & __os);
extern template basic_ostream< char, char_traits< char> >  &ends(basic_ostream< char, char_traits< char> >  & __os);
extern template basic_ostream< char, char_traits< char> >  &flush(basic_ostream< char, char_traits< char> >  & __os);
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, char __c);
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, unsigned char __c);
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, signed char __c);
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, const char * __s);
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, const unsigned char * __s);
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, const signed char * __s);

extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(long __v);
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(unsigned long __v);
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(bool __v);

extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(long long __v);
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(unsigned long long __v);

extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(double __v);
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(long double __v);
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(const void * __v);


extern template class basic_ostream< wchar_t, char_traits< wchar_t> > ;
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &endl(basic_ostream< wchar_t, char_traits< wchar_t> >  & __os);
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &ends(basic_ostream< wchar_t, char_traits< wchar_t> >  & __os);
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &flush(basic_ostream< wchar_t, char_traits< wchar_t> >  & __os);
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, wchar_t __c);
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, char __c);
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, const wchar_t * __s);
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, const char * __s);

extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(long __v);
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(unsigned long __v);
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(bool __v);

extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(long long __v);
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(unsigned long long __v);

extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(double __v);
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(long double __v);
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(const void * __v);



}
# 43 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/istream" 3
namespace std __attribute((__visibility__("default" ))) { 
# 54
template < typename _CharT, typename _Traits >
    class basic_istream : virtual public basic_ios < _CharT, _Traits >
    {
    public :

      typedef _CharT char_type;
      typedef typename _Traits :: int_type int_type;
      typedef typename _Traits :: pos_type pos_type;
      typedef typename _Traits :: off_type off_type;
      typedef _Traits traits_type;


      typedef basic_streambuf < _CharT, _Traits > __streambuf_type;
      typedef basic_ios < _CharT, _Traits > __ios_type;
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef num_get < _CharT, istreambuf_iterator < _CharT, _Traits > >
        __num_get_type;
      typedef ctype < _CharT > __ctype_type;

    protected :





      streamsize _M_gcount;

    public :








      explicit
      basic_istream ( __streambuf_type * __sb )
      : _M_gcount ( streamsize ( 0 ) )
      { this -> init ( __sb ); }






      virtual
      ~ basic_istream ( )
      { _M_gcount = streamsize ( 0 ); }


      class sentry;
      friend class sentry;











      __istream_type &
      operator >> ( __istream_type & ( * __pf ) ( __istream_type & ) )
      { return __pf ( * this ); }

      __istream_type &
      operator >> ( __ios_type & ( * __pf ) ( __ios_type & ) )
      {
 __pf ( * this );
 return * this;
      }

      __istream_type &
      operator >> ( ios_base & ( * __pf ) ( ios_base & ) )
      {
 __pf ( * this );
 return * this;
      }






























      __istream_type &
      operator >> ( bool & __n )
      { return _M_extract ( __n ); }

      __istream_type &
      operator >> ( short & __n );

      __istream_type &
      operator >> ( unsigned short & __n )
      { return _M_extract ( __n ); }

      __istream_type &
      operator >> ( int & __n );

      __istream_type &
      operator >> ( unsigned int & __n )
      { return _M_extract ( __n ); }

      __istream_type &
      operator >> ( long & __n )
      { return _M_extract ( __n ); }

      __istream_type &
      operator >> ( unsigned long & __n )
      { return _M_extract ( __n ); }


      __istream_type &
      operator >> ( long long & __n )
      { return _M_extract ( __n ); }

      __istream_type &
      operator >> ( unsigned long long & __n )
      { return _M_extract ( __n ); }


      __istream_type &
      operator >> ( float & __f )
      { return _M_extract ( __f ); }

      __istream_type &
      operator >> ( double & __f )
      { return _M_extract ( __f ); }

      __istream_type &
      operator >> ( long double & __f )
      { return _M_extract ( __f ); }

      __istream_type &
      operator >> ( void * & __p )
      { return _M_extract ( __p ); }





















      __istream_type &
      operator >> ( __streambuf_type * __sb );








      streamsize
      gcount ( ) const
      { return _M_gcount; }





























      int_type
      get ( );












      __istream_type &
      get ( char_type & __c );

























      __istream_type &
      get ( char_type * __s, streamsize __n, char_type __delim );









      __istream_type &
      get ( char_type * __s, streamsize __n )
      { return this -> get ( __s, __n, this -> widen ( '\n' ) ); }




















      __istream_type &
      get ( __streambuf_type & __sb, char_type __delim );








      __istream_type &
      get ( __streambuf_type & __sb )
      { return this -> get ( __sb, this -> widen ( '\n' ) ); }


























      __istream_type &
      getline ( char_type * __s, streamsize __n, char_type __delim );









      __istream_type &
      getline ( char_type * __s, streamsize __n )
      { return this -> getline ( __s, __n, this -> widen ( '\n' ) ); }





















      __istream_type &
      ignore ( );

      __istream_type &
      ignore ( streamsize __n );

      __istream_type &
      ignore ( streamsize __n, int_type __delim );









      int_type
      peek ( );
















      __istream_type &
      read ( char_type * __s, streamsize __n );

















      streamsize
      readsome ( char_type * __s, streamsize __n );














      __istream_type &
      putback ( char_type __c );













      __istream_type &
      unget ( );
















      int
      sync ( );












      pos_type
      tellg ( );













      __istream_type &
      seekg ( pos_type );














      __istream_type &
      seekg ( off_type, ios_base :: seekdir );


    protected :
      basic_istream ( )
      : _M_gcount ( streamsize ( 0 ) )
      { this -> init ( 0 ); }

      template < typename _ValueT >
        __istream_type &
        _M_extract ( _ValueT & __v );
    };
# 594
template<> basic_istream< char, char_traits< char> >  &basic_istream< char, char_traits< char> > ::getline(char_type * __s, streamsize __n, char_type __delim); 




template<> basic_istream< char, char_traits< char> >  &basic_istream< char, char_traits< char> > ::ignore(streamsize __n); 




template<> basic_istream< char, char_traits< char> >  &basic_istream< char, char_traits< char> > ::ignore(streamsize __n, int_type __delim); 
# 610
template<> basic_istream< wchar_t, char_traits< wchar_t> >  &basic_istream< wchar_t, char_traits< wchar_t> > ::getline(char_type * __s, streamsize __n, char_type __delim); 




template<> basic_istream< wchar_t, char_traits< wchar_t> >  &basic_istream< wchar_t, char_traits< wchar_t> > ::ignore(streamsize __n); 




template<> basic_istream< wchar_t, char_traits< wchar_t> >  &basic_istream< wchar_t, char_traits< wchar_t> > ::ignore(streamsize __n, int_type __delim); 
# 631
template < typename _CharT, typename _Traits >
    class basic_istream < _CharT, _Traits > :: sentry
    {
    public :

      typedef _Traits traits_type;
      typedef basic_streambuf < _CharT, _Traits > __streambuf_type;
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef typename __istream_type :: __ctype_type __ctype_type;
      typedef typename _Traits :: int_type __int_type;






















      explicit
      sentry ( basic_istream < _CharT, _Traits > & __is, bool __noskipws = false );








      operator bool ( ) const
      { return _M_ok; }

    private :
      bool _M_ok;
    };
# 693
template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    operator >> ( basic_istream < _CharT, _Traits > & __in, _CharT & __c );

template < class _Traits >
    inline basic_istream < char, _Traits > &
    operator >> ( basic_istream < char, _Traits > & __in, unsigned char & __c )
    { return ( __in >> reinterpret_cast < char & > ( __c ) ); }

template < class _Traits >
    inline basic_istream < char, _Traits > &
    operator >> ( basic_istream < char, _Traits > & __in, signed char & __c )
    { return ( __in >> reinterpret_cast < char & > ( __c ) ); }
# 734
template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    operator >> ( basic_istream < _CharT, _Traits > & __in, _CharT * __s );




template<> basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, char * __s); 

template < class _Traits >
    inline basic_istream < char, _Traits > &
    operator >> ( basic_istream < char, _Traits > & __in, unsigned char * __s )
    { return ( __in >> reinterpret_cast < char * > ( __s ) ); }

template < class _Traits >
    inline basic_istream < char, _Traits > &
    operator >> ( basic_istream < char, _Traits > & __in, signed char * __s )
    { return ( __in >> reinterpret_cast < char * > ( __s ) ); }
# 762
template < typename _CharT, typename _Traits >
    class basic_iostream
    : public basic_istream < _CharT, _Traits >,
      public basic_ostream < _CharT, _Traits >
    {
    public :



      typedef _CharT char_type;
      typedef typename _Traits :: int_type int_type;
      typedef typename _Traits :: pos_type pos_type;
      typedef typename _Traits :: off_type off_type;
      typedef _Traits traits_type;


      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef basic_ostream < _CharT, _Traits > __ostream_type;







      explicit
      basic_iostream ( basic_streambuf < _CharT, _Traits > * __sb )
      : __istream_type ( __sb ), __ostream_type ( __sb ) { }




      virtual
      ~ basic_iostream ( ) { }

    protected :
      basic_iostream ( )
      : __istream_type ( ), __ostream_type ( ) { }
    };
# 823
template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    ws ( basic_istream < _CharT, _Traits > & __is );

}
# 43 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/istream.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > :: sentry ::
    sentry ( basic_istream < _CharT, _Traits > & __in, bool __noskip ) : _M_ok ( false )
    {
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      if ( __in . good ( ) )
 {
   if ( __in . tie ( ) )
     __in . tie ( ) -> flush ( );
   if ( ! __noskip && bool ( __in . flags ( ) & ios_base :: skipws ) )
     {
       const __int_type __eof = traits_type :: eof ( );
       __streambuf_type * __sb = __in . rdbuf ( );
       __int_type __c = __sb -> sgetc ( );

       const __ctype_type & __ct = __check_facet ( __in . _M_ctype );
       while ( ! traits_type :: eq_int_type ( __c, __eof )
       && __ct . is ( ctype_base :: space,
    traits_type :: to_char_type ( __c ) ) )
  __c = __sb -> snextc ( );




       if ( traits_type :: eq_int_type ( __c, __eof ) )
  __err |= ios_base :: eofbit;
     }
 }

      if ( __in . good ( ) && __err == ios_base :: goodbit )
 _M_ok = true;
      else
 {
   __err |= ios_base :: failbit;
   __in . setstate ( __err );
 }
    }

template < typename _CharT, typename _Traits >
    template < typename _ValueT >
      basic_istream < _CharT, _Traits > &
      basic_istream < _CharT, _Traits > ::
      _M_extract ( _ValueT & __v )
      {
 sentry __cerb ( * this, false );
 if ( __cerb )
   {
     ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
     try
       {
  const __num_get_type & __ng = __check_facet ( this -> _M_num_get );
  __ng . get ( * this, 0, * this, __err, __v );
       }
     catch ( __cxxabiv1 :: __forced_unwind & )
       {
  this -> _M_setstate ( ios_base :: badbit );
  throw;
       }
     catch ( ... )
       { this -> _M_setstate ( ios_base :: badbit ); }
     if ( __err )
       this -> setstate ( __err );
   }
 return * this;
      }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    operator >> ( short & __n )
    {


      long __l;
      _M_extract ( __l );
      if ( ! this -> fail ( ) )
 {
   if ( __gnu_cxx :: __numeric_traits < short > :: __min <= __l
       && __l <= __gnu_cxx :: __numeric_traits < short > :: __max )
     __n = short ( __l );
   else
     this -> setstate ( ios_base :: failbit );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    operator >> ( int & __n )
    {


      long __l;
      _M_extract ( __l );
      if ( ! this -> fail ( ) )
 {
   if ( __gnu_cxx :: __numeric_traits < int > :: __min <= __l
       && __l <= __gnu_cxx :: __numeric_traits < int > :: __max )
     __n = int ( __l );
   else
     this -> setstate ( ios_base :: failbit );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    operator >> ( __streambuf_type * __sbout )
    {
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this, false );
      if ( __cerb && __sbout )
 {
   try
     {
       bool __ineof;
       if ( ! __copy_streambufs_eof ( this -> rdbuf ( ), __sbout, __ineof ) )
  __err |= ios_base :: failbit;
       if ( __ineof )
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: failbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: failbit ); }
 }
      else if ( ! __sbout )
 __err |= ios_base :: failbit;
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    typename basic_istream < _CharT, _Traits > :: int_type
    basic_istream < _CharT, _Traits > ::
    get ( void )
    {
      const int_type __eof = traits_type :: eof ( );
      int_type __c = __eof;
      _M_gcount = 0;
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   try
     {
       __c = this -> rdbuf ( ) -> sbumpc ( );

       if ( ! traits_type :: eq_int_type ( __c, __eof ) )
  _M_gcount = 1;
       else
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
 }
      if ( ! _M_gcount )
 __err |= ios_base :: failbit;
      if ( __err )
 this -> setstate ( __err );
      return __c;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    get ( char_type & __c )
    {
      _M_gcount = 0;
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   try
     {
       const int_type __cb = this -> rdbuf ( ) -> sbumpc ( );

       if ( ! traits_type :: eq_int_type ( __cb, traits_type :: eof ( ) ) )
  {
    _M_gcount = 1;
    __c = traits_type :: to_char_type ( __cb );
  }
       else
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
 }
      if ( ! _M_gcount )
 __err |= ios_base :: failbit;
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    get ( char_type * __s, streamsize __n, char_type __delim )
    {
      _M_gcount = 0;
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   try
     {
       const int_type __idelim = traits_type :: to_int_type ( __delim );
       const int_type __eof = traits_type :: eof ( );
       __streambuf_type * __sb = this -> rdbuf ( );
       int_type __c = __sb -> sgetc ( );

       while ( _M_gcount + 1 < __n
       && ! traits_type :: eq_int_type ( __c, __eof )
       && ! traits_type :: eq_int_type ( __c, __idelim ) )
  {
    * __s ++ = traits_type :: to_char_type ( __c );
    ++ _M_gcount;
    __c = __sb -> snextc ( );
  }
       if ( traits_type :: eq_int_type ( __c, __eof ) )
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
 }


      if ( __n > 0 )
 * __s = char_type ( );
      if ( ! _M_gcount )
 __err |= ios_base :: failbit;
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    get ( __streambuf_type & __sb, char_type __delim )
    {
      _M_gcount = 0;
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   try
     {
       const int_type __idelim = traits_type :: to_int_type ( __delim );
       const int_type __eof = traits_type :: eof ( );
       __streambuf_type * __this_sb = this -> rdbuf ( );
       int_type __c = __this_sb -> sgetc ( );
       char_type __c2 = traits_type :: to_char_type ( __c );

       while ( ! traits_type :: eq_int_type ( __c, __eof )
       && ! traits_type :: eq_int_type ( __c, __idelim )
       && ! traits_type :: eq_int_type ( __sb . sputc ( __c2 ), __eof ) )
  {
    ++ _M_gcount;
    __c = __this_sb -> snextc ( );
    __c2 = traits_type :: to_char_type ( __c );
  }
       if ( traits_type :: eq_int_type ( __c, __eof ) )
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
 }
      if ( ! _M_gcount )
 __err |= ios_base :: failbit;
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    getline ( char_type * __s, streamsize __n, char_type __delim )
    {
      _M_gcount = 0;
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      sentry __cerb ( * this, true );
      if ( __cerb )
        {
          try
            {
              const int_type __idelim = traits_type :: to_int_type ( __delim );
              const int_type __eof = traits_type :: eof ( );
              __streambuf_type * __sb = this -> rdbuf ( );
              int_type __c = __sb -> sgetc ( );

              while ( _M_gcount + 1 < __n
                     && ! traits_type :: eq_int_type ( __c, __eof )
                     && ! traits_type :: eq_int_type ( __c, __idelim ) )
                {
                  * __s ++ = traits_type :: to_char_type ( __c );
                  __c = __sb -> snextc ( );
                  ++ _M_gcount;
                }
              if ( traits_type :: eq_int_type ( __c, __eof ) )
                __err |= ios_base :: eofbit;
              else
                {
                  if ( traits_type :: eq_int_type ( __c, __idelim ) )
                    {
                      __sb -> sbumpc ( );
                      ++ _M_gcount;
                    }
                  else
                    __err |= ios_base :: failbit;
                }
            }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
          catch ( ... )
            { this -> _M_setstate ( ios_base :: badbit ); }
        }


      if ( __n > 0 )
 * __s = char_type ( );
      if ( ! _M_gcount )
        __err |= ios_base :: failbit;
      if ( __err )
        this -> setstate ( __err );
      return * this;
    }




template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    ignore ( void )
    {
      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       const int_type __eof = traits_type :: eof ( );
       __streambuf_type * __sb = this -> rdbuf ( );

       if ( traits_type :: eq_int_type ( __sb -> sbumpc ( ), __eof ) )
  __err |= ios_base :: eofbit;
       else
  _M_gcount = 1;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    ignore ( streamsize __n )
    {
      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb && __n > 0 )
        {
          ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
          try
            {
              const int_type __eof = traits_type :: eof ( );
              __streambuf_type * __sb = this -> rdbuf ( );
              int_type __c = __sb -> sgetc ( );








       bool __large_ignore = false;
       while ( true )
  {
    while ( _M_gcount < __n
    && ! traits_type :: eq_int_type ( __c, __eof ) )
      {
        ++ _M_gcount;
        __c = __sb -> snextc ( );
      }
    if ( __n == __gnu_cxx :: __numeric_traits < streamsize > :: __max
        && ! traits_type :: eq_int_type ( __c, __eof ) )
      {
        _M_gcount =
   __gnu_cxx :: __numeric_traits < streamsize > :: __min;
        __large_ignore = true;
      }
    else
      break;
  }

       if ( __large_ignore )
  _M_gcount = __gnu_cxx :: __numeric_traits < streamsize > :: __max;

       if ( traits_type :: eq_int_type ( __c, __eof ) )
                __err |= ios_base :: eofbit;
            }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
          catch ( ... )
            { this -> _M_setstate ( ios_base :: badbit ); }
          if ( __err )
            this -> setstate ( __err );
        }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    ignore ( streamsize __n, int_type __delim )
    {
      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb && __n > 0 )
        {
          ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
          try
            {
              const int_type __eof = traits_type :: eof ( );
              __streambuf_type * __sb = this -> rdbuf ( );
              int_type __c = __sb -> sgetc ( );


       bool __large_ignore = false;
       while ( true )
  {
    while ( _M_gcount < __n
    && ! traits_type :: eq_int_type ( __c, __eof )
    && ! traits_type :: eq_int_type ( __c, __delim ) )
      {
        ++ _M_gcount;
        __c = __sb -> snextc ( );
      }
    if ( __n == __gnu_cxx :: __numeric_traits < streamsize > :: __max
        && ! traits_type :: eq_int_type ( __c, __eof )
        && ! traits_type :: eq_int_type ( __c, __delim ) )
      {
        _M_gcount =
   __gnu_cxx :: __numeric_traits < streamsize > :: __min;
        __large_ignore = true;
      }
    else
      break;
  }

       if ( __large_ignore )
  _M_gcount = __gnu_cxx :: __numeric_traits < streamsize > :: __max;

              if ( traits_type :: eq_int_type ( __c, __eof ) )
                __err |= ios_base :: eofbit;
       else if ( traits_type :: eq_int_type ( __c, __delim ) )
  {
    if ( _M_gcount
        < __gnu_cxx :: __numeric_traits < streamsize > :: __max )
      ++ _M_gcount;
    __sb -> sbumpc ( );
  }
            }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
          catch ( ... )
            { this -> _M_setstate ( ios_base :: badbit ); }
          if ( __err )
            this -> setstate ( __err );
        }
      return * this;
    }

template < typename _CharT, typename _Traits >
    typename basic_istream < _CharT, _Traits > :: int_type
    basic_istream < _CharT, _Traits > ::
    peek ( void )
    {
      int_type __c = traits_type :: eof ( );
      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       __c = this -> rdbuf ( ) -> sgetc ( );
       if ( traits_type :: eq_int_type ( __c, traits_type :: eof ( ) ) )
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return __c;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    read ( char_type * __s, streamsize __n )
    {
      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       _M_gcount = this -> rdbuf ( ) -> sgetn ( __s, __n );
       if ( _M_gcount != __n )
  __err |= ( ios_base :: eofbit | ios_base :: failbit );
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    streamsize
    basic_istream < _CharT, _Traits > ::
    readsome ( char_type * __s, streamsize __n )
    {
      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {

       const streamsize __num = this -> rdbuf ( ) -> in_avail ( );
       if ( __num > 0 )
  _M_gcount = this -> rdbuf ( ) -> sgetn ( __s, std :: min ( __num, __n ) );
       else if ( __num == - 1 )
  __err |= ios_base :: eofbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return _M_gcount;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    putback ( char_type __c )
    {


      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       const int_type __eof = traits_type :: eof ( );
       __streambuf_type * __sb = this -> rdbuf ( );
       if ( ! __sb
    || traits_type :: eq_int_type ( __sb -> sputbackc ( __c ), __eof ) )
  __err |= ios_base :: badbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    unget ( void )
    {


      _M_gcount = 0;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       const int_type __eof = traits_type :: eof ( );
       __streambuf_type * __sb = this -> rdbuf ( );
       if ( ! __sb
    || traits_type :: eq_int_type ( __sb -> sungetc ( ), __eof ) )
  __err |= ios_base :: badbit;
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return * this;
    }

template < typename _CharT, typename _Traits >
    int
    basic_istream < _CharT, _Traits > ::
    sync ( void )
    {


      int __ret = - 1;
      sentry __cerb ( * this, true );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       __streambuf_type * __sb = this -> rdbuf ( );
       if ( __sb )
  {
    if ( __sb -> pubsync ( ) == - 1 )
      __err |= ios_base :: badbit;
    else
      __ret = 0;
  }
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       this -> _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { this -> _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     this -> setstate ( __err );
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_istream < _CharT, _Traits > :: pos_type
    basic_istream < _CharT, _Traits > ::
    tellg ( void )
    {


      pos_type __ret = pos_type ( - 1 );
      try
 {
   if ( ! this -> fail ( ) )
     __ret = this -> rdbuf ( ) -> pubseekoff ( 0, ios_base :: cur,
           ios_base :: in );
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    seekg ( pos_type __pos )
    {


      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      try
 {
   if ( ! this -> fail ( ) )
     {

       const pos_type __p = this -> rdbuf ( ) -> pubseekpos ( __pos,
            ios_base :: in );


       if ( __p == pos_type ( off_type ( - 1 ) ) )
  __err |= ios_base :: failbit;
     }
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    basic_istream < _CharT, _Traits > ::
    seekg ( off_type __off, ios_base :: seekdir __dir )
    {


      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      try
 {
   if ( ! this -> fail ( ) )
     {

       const pos_type __p = this -> rdbuf ( ) -> pubseekoff ( __off, __dir,
            ios_base :: in );


       if ( __p == pos_type ( off_type ( - 1 ) ) )
  __err |= ios_base :: failbit;
     }
 }
      catch ( __cxxabiv1 :: __forced_unwind & )
 {
   this -> _M_setstate ( ios_base :: badbit );
   throw;
 }
      catch ( ... )
 { this -> _M_setstate ( ios_base :: badbit ); }
      if ( __err )
 this -> setstate ( __err );
      return * this;
    }


template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    operator >> ( basic_istream < _CharT, _Traits > & __in, _CharT & __c )
    {
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef typename __istream_type :: int_type __int_type;

      typename __istream_type :: sentry __cerb ( __in, false );
      if ( __cerb )
 {
   ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
   try
     {
       const __int_type __cb = __in . rdbuf ( ) -> sbumpc ( );
       if ( ! _Traits :: eq_int_type ( __cb, _Traits :: eof ( ) ) )
  __c = _Traits :: to_char_type ( __cb );
       else
  __err |= ( ios_base :: eofbit | ios_base :: failbit );
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       __in . _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { __in . _M_setstate ( ios_base :: badbit ); }
   if ( __err )
     __in . setstate ( __err );
 }
      return __in;
    }

template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    operator >> ( basic_istream < _CharT, _Traits > & __in, _CharT * __s )
    {
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef basic_streambuf < _CharT, _Traits > __streambuf_type;
      typedef typename _Traits :: int_type int_type;
      typedef _CharT char_type;
      typedef ctype < _CharT > __ctype_type;

      streamsize __extracted = 0;
      ios_base :: iostate __err = ios_base :: iostate ( ios_base :: goodbit );
      typename __istream_type :: sentry __cerb ( __in, false );
      if ( __cerb )
 {
   try
     {

       streamsize __num = __in . width ( );
       if ( __num <= 0 )
  __num = __gnu_cxx :: __numeric_traits < streamsize > :: __max;

       const __ctype_type & __ct = use_facet < __ctype_type > ( __in . getloc ( ) );

       const int_type __eof = _Traits :: eof ( );
       __streambuf_type * __sb = __in . rdbuf ( );
       int_type __c = __sb -> sgetc ( );

       while ( __extracted < __num - 1
       && ! _Traits :: eq_int_type ( __c, __eof )
       && ! __ct . is ( ctype_base :: space,
     _Traits :: to_char_type ( __c ) ) )
  {
    * __s ++ = _Traits :: to_char_type ( __c );
    ++ __extracted;
    __c = __sb -> snextc ( );
  }
       if ( _Traits :: eq_int_type ( __c, __eof ) )
  __err |= ios_base :: eofbit;



       * __s = char_type ( );
       __in . width ( 0 );
     }
   catch ( __cxxabiv1 :: __forced_unwind & )
     {
       __in . _M_setstate ( ios_base :: badbit );
       throw;
     }
   catch ( ... )
     { __in . _M_setstate ( ios_base :: badbit ); }
 }
      if ( ! __extracted )
 __err |= ios_base :: failbit;
      if ( __err )
 __in . setstate ( __err );
      return __in;
    }


template < typename _CharT, typename _Traits >
    basic_istream < _CharT, _Traits > &
    ws ( basic_istream < _CharT, _Traits > & __in )
    {
      typedef basic_istream < _CharT, _Traits > __istream_type;
      typedef basic_streambuf < _CharT, _Traits > __streambuf_type;
      typedef typename __istream_type :: int_type __int_type;
      typedef ctype < _CharT > __ctype_type;

      const __ctype_type & __ct = use_facet < __ctype_type > ( __in . getloc ( ) );
      const __int_type __eof = _Traits :: eof ( );
      __streambuf_type * __sb = __in . rdbuf ( );
      __int_type __c = __sb -> sgetc ( );

      while ( ! _Traits :: eq_int_type ( __c, __eof )
      && __ct . is ( ctype_base :: space, _Traits :: to_char_type ( __c ) ) )
 __c = __sb -> snextc ( );

       if ( _Traits :: eq_int_type ( __c, __eof ) )
  __in . setstate ( ios_base :: eofbit );
      return __in;
    }
# 971
extern template class basic_istream< char, char_traits< char> > ;
extern template basic_istream< char, char_traits< char> >  &ws(basic_istream< char, char_traits< char> >  & __is);
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, char & __c);
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  &, char *);
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, unsigned char & __c);
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, signed char & __c);
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, unsigned char * __s);
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, signed char * __s);

extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned short & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(long & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned long & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(bool & __v);

extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(long long & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned long long & __v);

extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(float & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(double & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(long double & __v);
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(void *& __v);

extern template class basic_iostream< char, char_traits< char> > ;


extern template class basic_istream< wchar_t, char_traits< wchar_t> > ;
extern template basic_istream< wchar_t, char_traits< wchar_t> >  &ws(basic_istream< wchar_t, char_traits< wchar_t> >  & __is);
extern template basic_istream< wchar_t, char_traits< wchar_t> >  &operator>>(basic_istream< wchar_t, char_traits< wchar_t> >  & __in, wchar_t & __c);
extern template basic_istream< wchar_t, char_traits< wchar_t> >  &operator>>(basic_istream< wchar_t, char_traits< wchar_t> >  &, wchar_t *);

extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned short & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(long & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned long & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(bool & __v);

extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(long long & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned long long & __v);

extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(float & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(double & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(long double & __v);
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(void *& __v);

extern template class basic_iostream< wchar_t, char_traits< wchar_t> > ;



}
# 43 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/iostream" 3
namespace std __attribute((__visibility__("default" ))) { 
# 58
extern istream cin; 
extern ostream cout; 
extern ostream cerr; 
extern ostream clog; 


extern wistream wcin; 
extern wostream wcout; 
extern wostream wcerr; 
extern wostream wclog; 




static ios_base::Init __ioinit; 

}
# 40 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/Context.h"
namespace hmpprt { 


class CUDADevice; 
class OpenCLDevice; 
class Grouplet; 


template < MemorySpace MS, typename T >
struct DeviceAccess;

template < MemorySpace MS, typename T >
struct DevicePtr;

template < MemorySpace MS, typename T >
struct DeviceAccess;

template < MemorySpace MS, typename T >
struct DevicePtr
{
  T * addr;


  template < typename O >
  DevicePtr ( const DevicePtr < MS, O > & other )
    : addr ( ( T * ) other . addr )
  { }

  explicit DevicePtr ( void * value = 0 )
      : addr ( ( T * ) value )
  { }

  inline DevicePtr < MS, T > operator = ( void * host_address );



  DevicePtr < MS, T > operator ++ ( )
  {
    addr += 1;
    return * this;
  }
  DevicePtr < MS, T > operator -- ( )
  {
    addr -= 1;
    return * this;
  }
  DevicePtr < MS, T > operator ++ ( int )
  {
    DevicePtr < MS, T > p ( * this );
    addr += 1;
    return p;
  }
  DevicePtr < MS, T > operator -- ( int )
  {
    DevicePtr < MS, T > p ( * this );
    addr -= 1;
    return p;
  }




























  DevicePtr < MS, T > operator += ( signed char offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( signed char offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, signed char offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, signed char offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( signed char offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( unsigned char offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( unsigned char offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, unsigned char offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, unsigned char offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( unsigned char offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( short int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( short int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, short int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, short int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( short int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( long int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( long int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, long int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, long int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( long int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( long long int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( long long int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, long long int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, long long int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( long long int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( unsigned short int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( unsigned short int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, unsigned short int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, unsigned short int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( unsigned short int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( unsigned int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( unsigned int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, unsigned int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, unsigned int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( unsigned int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( unsigned long int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( unsigned long int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, unsigned long int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, unsigned long int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( unsigned long int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }
  DevicePtr < MS, T > operator += ( unsigned long long int offset ) { addr += offset; return * this; } DevicePtr < MS, T > operator -= ( unsigned long long int offset ) { addr -= offset; return * this; } friend DevicePtr < MS, T > operator + ( DevicePtr < MS, T > p, unsigned long long int offset ) { p . addr += offset; return p; } friend DevicePtr < MS, T > operator - ( DevicePtr < MS, T > p, unsigned long long int offset ) { p . addr -= offset; return p; } friend DevicePtr < MS, T > operator + ( unsigned long long int offset, DevicePtr < MS, T > p ) { p . addr += offset; return p; }



  operator bool ( )
  {
    return addr != 0;
  }
  friend ptrdiff_t operator - ( DevicePtr < MS, T > left, DevicePtr < MS, T > right )
  {
    return left . addr - right . addr;
  }
  friend bool operator == ( DevicePtr < MS, T > left, DevicePtr < MS, T > right )
  {
    return left . addr == right . addr;
  }
  friend bool operator != ( DevicePtr < MS, T > left, DevicePtr < MS, T > right )
  {
    return left . addr != right . addr;
  }

  DeviceAccess < MS, T > operator * ( )
  {
    return operator [ ] ( 0 );
  }

  inline DeviceAccess < MS, T > operator [ ] ( size_t index );

  inline DeviceAccess < MS, T > operator -> ( );

  T * host ( );

};

template < MemorySpace MS, typename T >
T * DevicePtr < MS, T > :: host ( )
{
  return ( ( * this ) [ 0 ] ) . read ( );
}


template < MemorySpace MS, typename T >
struct DeviceAccess
{
  DeviceAccess ( T * addr, size_t index )
    : addr ( addr ), index ( index )
  {
  }

  T * addr;
  size_t index;

  DevicePtr < MS, T > operator & ( )
  {
    DevicePtr < MS, T > ptr;
    ptr . addr = addr + index;
    return ptr;
  }

  operator T ( )
  {
    return * read ( );
  }

  DeviceAccess < MS, T > operator = ( T t )
  {
    write ( t );
    return * this;
  }

  inline void write ( T t );
  inline T * read ( );

  DeviceAccess < MS, T > operator = ( DeviceAccess < MS, T > other )
  {
    return operator = ( ( T ) other );
  }

  T * operator -> ( )
  {
    return read ( );
  }
};



class Context : private NonCopyable { 



public: static Context *getInstance(); 

Context(); 
~Context(); 



void setGrouplet(Grouplet * grouplet); 

Grouplet *getGrouplet(); 

void setDevice(Device * device); 




Device *getDevice(); 




CUDADevice *getCUDADevice(); 




OpenCLDevice *getOpenCLDevice(); 



void addData(Data * data); 


void *read_from_host(Data *); 




void allocate(void ** src, MemorySpace memory_space, size_t size); 

void free(void ** src); 




void invalidate(); 

std::map< void *, Data *> ::iterator getDataFromHostAddress(void * a); 

std::map< void *, Data *> ::iterator getDataFromDeviceAddress(void * a); 


Queue *getQueue() { return queue_; } 

void setQueue(Queue *queue) { queue_ = queue; } 


private: static __thread Context *instance_; 


Grouplet *grouplet_; 
Device *device_; 
Queue *queue_; 

std::map< void *, Data *>  host_map_; 
std::map< void *, Data *>  device_map_; 
}; 



template < MemorySpace MS, typename T >
inline DeviceAccess < MS, T > DevicePtr < MS, T > :: operator [ ] ( size_t index )
{
  return DeviceAccess < MS, T > ( addr, index );
}

template < MemorySpace MS, typename T >
inline DevicePtr < MS, T > DevicePtr < MS, T > :: operator = ( void * host_address )
{
  Context * ctx = Context :: getInstance ( );
  std :: map < void *, Data * > :: iterator it = ctx -> getDataFromHostAddress ( host_address );
  void * ha_base = it -> first;
  size_t offset = ( ( char * ) host_address ) - ( ( char * ) ha_base );
  Data * d = it -> second;
  addr = ( T * ) ( ( ( char * ) d -> getAddress ( ) ) + offset );
  return * this;
}

template < MemorySpace MS, typename T >
DeviceAccess < MS, T > DevicePtr < MS, T > :: operator -> ( )
{
  return operator [ ] ( 0 );
}




template < MemorySpace MS, typename T >
inline void DeviceAccess < MS, T > :: write ( T t )
{
  * read ( ) = t;
}

template < MemorySpace MS, typename T >
inline T * DeviceAccess < MS, T > :: read ( )
{
  Context * ctx = Context :: getInstance ( );
  std :: map < void *, Data * > :: iterator it = ctx -> getDataFromDeviceAddress ( addr );
  void * addr_base = it -> first;
  size_t offset = ( ( char * ) addr ) - ( ( char * ) addr_base );
  Data * d = it -> second;
  T * host_addr = ( T * ) ctx -> read_from_host ( d );

  return ( T * ) ( ( ( char * ) ( host_addr + index ) ) + offset );
}

}
# 49 "/usr/include/stdint.h" 3
typedef unsigned char uint8_t; 
typedef unsigned short uint16_t; 

typedef unsigned uint32_t; 



typedef unsigned long uint64_t; 
# 66
typedef signed char int_least8_t; 
typedef short int_least16_t; 
typedef int int_least32_t; 

typedef long int_least64_t; 
# 77
typedef unsigned char uint_least8_t; 
typedef unsigned short uint_least16_t; 
typedef unsigned uint_least32_t; 

typedef unsigned long uint_least64_t; 
# 91
typedef signed char int_fast8_t; 

typedef long int_fast16_t; 
typedef long int_fast32_t; 
typedef long int_fast64_t; 
# 104
typedef unsigned char uint_fast8_t; 

typedef unsigned long uint_fast16_t; 
typedef unsigned long uint_fast32_t; 
typedef unsigned long uint_fast64_t; 
# 123
typedef unsigned long uintptr_t; 
# 135
typedef long intmax_t; 
typedef unsigned long uintmax_t; 
# 30 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/HostTypes.h"
namespace hmpprt { 



struct cipher_t; 


typedef uint8_t u08; 
typedef uint16_t u16; 
typedef uint32_t u32; 
typedef uint64_t u64; 

typedef int8_t s08; 
typedef int16_t s16; 
typedef int32_t s32; 
typedef int64_t s64; 
# 58
}
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/CUDADevice.h"
namespace hmpprt { 


class CUDAGrid; 

class CUDAGridCall; 



class CUDADevice : public HostDevice { 

friend class CUDAContextLocker; 




public: static void initialize(); 


static void create_devices(DeviceList &); 


virtual void createContext(); 

virtual void *getVendorDeviceHandle(); 

virtual void *getVendorDeviceContext(); 

virtual ~CUDADevice(); 

virtual MemorySpace getDefaultMemorySpace() const; 

virtual bool hasDoublePrecision() const; 

virtual bool hasHostMemoryIntegration() const; 

virtual unsigned getDeviceMaxClockRate() const; 


virtual bool hasECCEnabled() const; 



const std::string &getCUDADeviceName() const; 

int getCUDADriverVersion() const; 

void getCUDADeviceComputeCapability(int & major, int & minor) const; 

size_t getCUDADeviceTotalMemory() const; 


bool hasCUDAInteropCapabilities(); 


virtual void allocate(Data * data); 

virtual void free(Data * data); 

virtual Data *createSubData(Data * data, size_t size, size_t offset); 

virtual void upload(Data * data, const void * host_address, size_t offset, size_t size, Queue * q = 0); 

virtual void download(Data * data, void * host_address, size_t offset, size_t size, Queue * q = 0); 

virtual void setmem(Data * data, int value = (0)); 



void launchGrid(CUDAGrid * grid, CUDAGridCall * call, Queue * q = 0); 
static void unloadModule(void * module); 
void lockContext(); 
void unlockContext(); 
virtual void releaseHandle(void * handle); 
void *getHandle(); 
virtual void synchronize(Queue * q = 0); 
void synchronizeWithoutSettingContext(Queue * q = 0); 
virtual bool isPageLocked(void * host_address, size_t size); 
virtual void replaceAllocs(int); 



virtual bool checkDeviceData(void * device_address, void * host_address, size_t size, Queue * queue); 


virtual bool hasPhysicalAddresses(); 



private: void uploadConstants(void * module, std::string function_name, std::map< std::basic_string< char, std::char_traits< char> , std::allocator< char> > , void *>  * pointers, std::map< std::basic_string< char, std::char_traits< char> , std::allocator< char> > , void *>  * values, Queue * q = 0)
# 123
; 

void *handle_; 

CUDADevice(unsigned long id, const std::string & label, void * handle); 



}; 
# 137
class CUDAContextLocker { 
# 144
public: explicit CUDAContextLocker(CUDADevice * device); 


~CUDAContextLocker(); 

void unlock(); 



private: CUDADevice *device_; 
bool locked_; 

}; 

}
# 35 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmppmem/hmppmem.h"
extern "C" { typedef void *(*HmppMemMallocFunc)(size_t); }
extern "C" { typedef void *(*HmppMemReallocFunc)(void *, size_t); }
extern "C" { typedef void (*HmppMemFreeFunc)(void *); }
extern "C" { typedef size_t (*HmppMemGetSizeFunc)(void *); }

extern "C" { struct HmppMemDescriptor { 

HmppMemMallocFunc malloc_func; 
HmppMemGetSizeFunc getsize_func; 
HmppMemFreeFunc free_func; 
}; }
# 51
extern "C" void hmppmem_set_callbacks(HmppMemDescriptor * descriptor); 


extern "C" HmppMemMallocFunc get_real_malloc(); 


extern "C" HmppMemReallocFunc get_real_realloc(); 


extern "C" HmppMemFreeFunc get_real_free(); 
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/hmpprt/MallocManager.h"
namespace hmpprt { 

class MallocManager { 



public: MallocManager(); 


void *getUserData() { return userData_; } 


static MallocManager *getInstance(); 


void loadHmppmemLibrary(); 


~MallocManager(); 


void setHooks(HmppMemMallocFunc malloc_func, HmppMemFreeFunc free_func, void * userData); 



bool disableHooks(); 



void enableHooks(); 


private: typedef void (*HmppMemSetCallbacks)(HmppMemDescriptor * descriptor); 

HmppMemDescriptor descriptor; 
HmppMemSetCallbacks set_callbacks_func_; 

HmppMemMallocFunc malloc_func_; 
HmppMemFreeFunc free_func_; 
void *userData_; 

bool enabled_; 

std::map< void *, unsigned long>  allocatedBuffers_; 

static size_t get_allocated_size(void *); 
static void *allocate(size_t); 
static void free(void *); 

static MallocManager *instance_; 
}; 



namespace { 


struct HandleHookDisabler { 

HandleHookDisabler() 
{ 
malloc_was_enabled_ = MallocManager::getInstance()->disableHooks(); 
} 

~HandleHookDisabler() 
{ 
if (malloc_was_enabled_) 
{ 
MallocManager::getInstance()->enableHooks(); 
}  
} 

bool malloc_was_enabled_; 
}; 
}
}
# 69 "/usr/include/assert.h" 3
extern "C" void __assert_fail(const char * __assertion, const char * __file, unsigned __line, const char * __function) throw()

 __attribute((__noreturn__)); 


extern "C" void __assert_perror_fail(int __errnum, const char * __file, unsigned __line, const char * __function) throw()


 __attribute((__noreturn__)); 




extern "C" void __assert(const char * __assertion, const char * __file, int __line) throw()
 __attribute((__noreturn__)); 
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/Data.h"
namespace openacci { 


class Mirror; 




struct Data { 


Data(Mirror * mirror, const char * varname, void * host_address, size_t size); 

Data(Mirror * mirror, const char * varname, void * host_address, size_t start, size_t length, size_t elemsize); 
virtual ~Data(); 

void useBufferOf(Data * parent); 
void useSubBufferOf(Data * parent); 
void useDevicePtr(hmpprt::Device * device, hmpprt::MemorySpace, void * addr); 
void updateDeviceResidentShape(DeviceResident * dr); 
void useDeviceResident(DeviceResident * dr); 

hmpprt::Data *getBuffer() { return buffer_; } 

size_t getSize() { return (buffer_)->getSize(); } 
void setSize() { } 

void *getDeviceAddress() { return (buffer_)->getAddress(); } 
size_t getOffset() { return (buffer_)->getOffset(); } 
hmpprt::MemorySpace getMemorySpace() { return (buffer_)->getMemorySpace(); } 
void setMemorySpace(hmpprt::MemorySpace ms) { (buffer_)->setMemorySpace(ms); } 
hmpprt::Device *getDevice() { return (buffer_)->getDevice(); } 

virtual void allocate(const char * file_name, int line_number, hmpprt::Device * device, hmpprt::MemorySpace memory_space, hmpprt::Queue * queue, const char * qdesc); 
# 74
void free(const char * file_name, int line_number, hmpprt::Queue * queue, const char * qdesc); 




void dispose(hmpprt::Queue * queue); 

virtual void upload(const char * file_name, int line_number, hmpprt::Queue * queue, const char * qdesc); 




virtual void download(const char * file_name, int line_number, hmpprt::Queue * queue, const char * qdesc); 




void partialUpload(const char * file_name, int line_number, size_t offset, size_t size, hmpprt::Queue * queue, const char * qdesc); 
# 98
void partialDownload(const char * file_name, int line_number, size_t offset, size_t size, hmpprt::Queue * queue, const char * qdesc); 
# 105
bool contains(void * host_address, size_t size); 

void setVariableName(const char *s) 
{ 
(variable_name_ = s); 
} 

Mirror *getMirror() { return mirror_; } 


void *getHostAddress() { return host_address_; } 


void *getStartHostAddress() { return (char *)(host_address_) + this->getOffset(); } 

const char *getVariableName() { return (variable_name_).c_str(); } 
size_t getNumElements() { return length_; } 
size_t getFirstElement() { return start_; } 
size_t getElementSize() { return element_size_; } 

bool pushed; 
bool allocated; 
bool copyin; 
bool copyout; 
bool device_resident; 

bool value() { return buffer_ == (0); } 

int *getValue4Bytes() { return &(value4bytes_); } 


friend class Mirror; 



private: std::string variable_name_; 
size_t start_; 
size_t length_; 
size_t element_size_; 



void *host_address_; 
int value4bytes_; 

Mirror *mirror_; 

hmpprt::Data *buffer_; 
Data *parent_data_; 

void *device_resident_init_value_ptr_; 

friend struct MultiDimData; 
Data(Mirror * mirror, const char * varname, void * host_address); 
}; 

struct MultiDimData : public Data { 

MultiDimData(Mirror * mirror, const char * varname, void * host_address, size_t nb_dimensions, const size_t * starts, const size_t * lengths, const char * dim_desc, size_t elemsize); 
virtual ~MultiDimData(); 

virtual void allocate(const char * file_name, int line_number, hmpprt::Device * device, hmpprt::MemorySpace memory_space, hmpprt::Queue * queue, const char * qdesc); 
# 173
virtual void upload(const char * file_name, int line_number, hmpprt::Queue * queue, const char * qdesc); 




virtual void download(const char * file_name, int line_number, hmpprt::Queue * queue, const char * qdesc); 




void partialUpload(const char * file_name, int line_number, size_t start, size_t length, hmpprt::Queue * queue, const char * qdesc); 
# 190
void partialDownload(const char * file_name, int line_number, size_t start, size_t length, hmpprt::Queue * queue, const char * qdesc); 
# 197
static size_t computeBaseSize(size_t nb_dimensions, const size_t * starts, const size_t * lengths, const char * dim_desc, size_t elemsize); 
static size_t computeFullSize(size_t nb_dimensions, const size_t * starts, const size_t * lengths, const char * dim_desc, size_t elemsize); 
static size_t computeStrideForFirstDim(size_t nb_dimensions, const size_t * starts, const size_t * lengths, const char * dim_desc, size_t elemsize); 

friend struct Data; 
friend class Context; 

private: size_t nb_dimensions_; 
size_t *starts_; 
size_t *lengths_; 
size_t data_mem_size_; 
char *dim_desc_; 
size_t *device_offsets_arrays_; 
void **host_pointers_arrays_; 
size_t pointers_arrays_size_; 
size_t pointers_arrays_nb_elem_; 
size_t pointers_arrays_last_level_start_; 
size_t mem_size_pointed_by_last_level_; 
}; 


}
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/Mirror.h"
namespace openacci { 

struct Data; 



class Mirror { 


public: Mirror(void *host_address, size_t size) : host_address_(host_address), fullsize_(size) 
{ } 


Data *lookupData(void * host_address, ssize_t size); 


size_t getSize() { return fullsize_; } 

Data *topData() { return (data_stack_).back(); } 

Data *baseData() { return (data_stack_).front(); } 

void pushData(Data *data) { (data_stack_).push_back(data); data->mirror_ = this; } 

bool empty() { return (data_stack_).empty(); } 

void popData() { (data_stack_).pop_back(); } 

void removeData(Data * data); 

void *getHostAddress() { return host_address_; } 


private: void *host_address_; 
size_t fullsize_; 
std::vector< Data *>  data_stack_; 
}; 
}
# 31 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/MirrorManager.h"
namespace openacci { 

typedef std::map< void *, Mirror>  MirrorMap; 

class MirrorManager { 


public: MirrorManager(); 
~MirrorManager(); 

Mirror *createMirror(void * host_address, size_t size); 

void removeMirror(void * host_address); 
void removeMirror(Mirror *mirror) { this->removeMirror(mirror->getHostAddress()); } 



Mirror *lookupMirror(void * host_address); 



Mirror *getMirrorFromDeviceAddress(void * device_address); 



Mirror *lookupMirrorBadOverlap(void * host_address, size_t size); 

void clear(); 


private: MirrorMap mirror_map_; 

}; 

}
# 31 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/AsyncManager.h"
namespace openacci { 

struct Region; 
class Context; 

class AsyncManager { 


public: void wait(const char * file_name, int line_number, int awaited_value, int async_value); 




bool test(const char * file_name, int line_number, int async_value); 



void clean(); 
# 54
hmpprt::Queue *getOrCreateQueue(int & queue_id, std::string & qdesc); 


void setQueue(Region * region, int new_async_value); 



private: typedef std::map< int, hmpprt::Queue *>  QueueMap; 
QueueMap queue_map_; 


typedef std::vector< hmpprt::Queue *>  QueueList; 
QueueList queue_list_; 
}; 
}
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/Region.h"
namespace openacci { 

class Context; 


struct Region { 

Region() : async_value(acc_async_unknown), queue(0) 


{ 
} 

const char *getName() const; 
bool isKernels() const; 
bool isParallel() const; 
bool isDeclare() const; 
bool isData() const; 
bool isHostData() const; 

int kind; 
int num_args; 
int async_value; 
hmpprt::Queue *queue; 
std::string qdesc; 
unsigned instance_id; 




std::string region_file_name; 
int region_line_number; 

std::vector< Data *>  datas; 
}; 

}
# 34 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/Codelet.h"
namespace openacci { 

struct Codelet { 

Codelet(const char * module_name, const char * function_name, acc_device_t device_type); 

~Codelet(); 

int getNumberOfParameters() 
{ 
return (handle_)->getNumberOfParameters(); 
} 

hmpprt::MemorySpace getMemorySpaceByIndex(int i) 
{ 
return (handle_)->getMemorySpaceByIndex(i); 
} 

hmpprt::Intent getIntentByIndex(int i) 
{ 
return (handle_)->getIntentByIndex(i); 
} 

std::string getNameByIndex(int i) 
{ 
return (handle_)->getNameByIndex(i); 
} 

hmpprt::Codelet *getHandle() { return handle_; } 


private: hmpprt::Grouplet *grouplet_; 
hmpprt::Codelet *handle_; 
}; 

typedef std::map< std::basic_string< char, std::char_traits< char> , std::allocator< char> > , Codelet *>  CodeletMap; 
}
# 102 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h" 3
typedef __gnuc_va_list va_list; 
# 54 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cstdarg" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::va_list;

}
# 63 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_set.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 85
template < typename _Key, typename _Compare = std :: less < _Key >,
    typename _Alloc = std :: allocator < _Key > >
    class set
    {

      typedef typename _Alloc :: value_type _Alloc_value_type;





    public :



      typedef _Key key_type;
      typedef _Key value_type;
      typedef _Compare key_compare;
      typedef _Compare value_compare;
      typedef _Alloc allocator_type;


    private :
      typedef typename _Alloc :: template rebind < _Key > :: other _Key_alloc_type;

      typedef _Rb_tree < key_type, value_type, _Identity < value_type >,
         key_compare, _Key_alloc_type > _Rep_type;
      _Rep_type _M_t;

    public :


      typedef typename _Key_alloc_type :: pointer pointer;
      typedef typename _Key_alloc_type :: const_pointer const_pointer;
      typedef typename _Key_alloc_type :: reference reference;
      typedef typename _Key_alloc_type :: const_reference const_reference;



      typedef typename _Rep_type :: const_iterator iterator;
      typedef typename _Rep_type :: const_iterator const_iterator;
      typedef typename _Rep_type :: const_reverse_iterator reverse_iterator;
      typedef typename _Rep_type :: const_reverse_iterator const_reverse_iterator;
      typedef typename _Rep_type :: size_type size_type;
      typedef typename _Rep_type :: difference_type difference_type;






      set ( )
      : _M_t ( ) { }






      explicit
      set ( const _Compare & __comp,
   const allocator_type & __a = allocator_type ( ) )
      : _M_t ( __comp, __a ) { }










      template < typename _InputIterator >
        set ( _InputIterator __first, _InputIterator __last )
 : _M_t ( )
        { _M_t . _M_insert_unique ( __first, __last ); }












      template < typename _InputIterator >
        set ( _InputIterator __first, _InputIterator __last,
     const _Compare & __comp,
     const allocator_type & __a = allocator_type ( ) )
 : _M_t ( __comp, __a )
        { _M_t . _M_insert_unique ( __first, __last ); }








      set ( const set & __x )
      : _M_t ( __x . _M_t ) { }




































      set &
      operator = ( const set & __x )
      {
 _M_t = __x . _M_t;
 return * this;
      }









































      key_compare
      key_comp ( ) const
      { return _M_t . key_comp ( ); }

      value_compare
      value_comp ( ) const
      { return _M_t . key_comp ( ); }

      allocator_type
      get_allocator ( ) const
      { return _M_t . get_allocator ( ); }






      iterator
      begin ( ) const
      { return _M_t . begin ( ); }






      iterator
      end ( ) const
      { return _M_t . end ( ); }






      reverse_iterator
      rbegin ( ) const
      { return _M_t . rbegin ( ); }






      reverse_iterator
      rend ( ) const
      { return _M_t . rend ( ); }








































      bool
      empty ( ) const
      { return _M_t . empty ( ); }


      size_type
      size ( ) const
      { return _M_t . size ( ); }


      size_type
      max_size ( ) const
      { return _M_t . max_size ( ); }












      void



      swap ( set & __x )

      { _M_t . swap ( __x . _M_t ); }















      std :: pair < iterator, bool >
      insert ( const value_type & __x )
      {
 std :: pair < typename _Rep_type :: iterator, bool > __p =
   _M_t . _M_insert_unique ( __x );
 return std :: pair < iterator, bool > ( __p . first, __p . second );
      }




















      iterator
      insert ( iterator __position, const value_type & __x )
      { return _M_t . _M_insert_unique_ ( __position, __x ); }










      template < typename _InputIterator >
        void
        insert ( _InputIterator __first, _InputIterator __last )
        { _M_t . _M_insert_unique ( __first, __last ); }























      void
      erase ( iterator __position )
      { _M_t . erase ( __position ); }












      size_type
      erase ( const key_type & __x )
      { return _M_t . erase ( __x ); }












      void
      erase ( iterator __first, iterator __last )
      { _M_t . erase ( __first, __last ); }







      void
      clear ( )
      { _M_t . clear ( ); }











      size_type
      count ( const key_type & __x ) const
      { return _M_t . find ( __x ) == _M_t . end ( ) ? 0 : 1; }















      iterator
      find ( const key_type & __x )
      { return _M_t . find ( __x ); }

      const_iterator
      find ( const key_type & __x ) const
      { return _M_t . find ( __x ); }














      iterator
      lower_bound ( const key_type & __x )
      { return _M_t . lower_bound ( __x ); }

      const_iterator
      lower_bound ( const key_type & __x ) const
      { return _M_t . lower_bound ( __x ); }









      iterator
      upper_bound ( const key_type & __x )
      { return _M_t . upper_bound ( __x ); }

      const_iterator
      upper_bound ( const key_type & __x ) const
      { return _M_t . upper_bound ( __x ); }


















      std :: pair < iterator, iterator >
      equal_range ( const key_type & __x )
      { return _M_t . equal_range ( __x ); }

      std :: pair < const_iterator, const_iterator >
      equal_range ( const key_type & __x ) const
      { return _M_t . equal_range ( __x ); }


      template < typename _K1, typename _C1, typename _A1 >
        friend bool
        operator == ( const set < _K1, _C1, _A1 > &, const set < _K1, _C1, _A1 > & );

      template < typename _K1, typename _C1, typename _A1 >
        friend bool
        operator < ( const set < _K1, _C1, _A1 > &, const set < _K1, _C1, _A1 > & );
    };
# 637
template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator == ( const set < _Key, _Compare, _Alloc > & __x,
        const set < _Key, _Compare, _Alloc > & __y )
    { return __x . _M_t == __y . _M_t; }
# 654
template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator < ( const set < _Key, _Compare, _Alloc > & __x,
       const set < _Key, _Compare, _Alloc > & __y )
    { return __x . _M_t < __y . _M_t; }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator != ( const set < _Key, _Compare, _Alloc > & __x,
        const set < _Key, _Compare, _Alloc > & __y )
    { return ! ( __x == __y ); }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator > ( const set < _Key, _Compare, _Alloc > & __x,
       const set < _Key, _Compare, _Alloc > & __y )
    { return __y < __x; }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator <= ( const set < _Key, _Compare, _Alloc > & __x,
        const set < _Key, _Compare, _Alloc > & __y )
    { return ! ( __y < __x ); }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator >= ( const set < _Key, _Compare, _Alloc > & __x,
        const set < _Key, _Compare, _Alloc > & __y )
    { return ! ( __x < __y ); }


template < typename _Key, typename _Compare, typename _Alloc >
    inline void
    swap ( set < _Key, _Compare, _Alloc > & __x, set < _Key, _Compare, _Alloc > & __y )
    { __x . swap ( __y ); }
# 706
}
# 63 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/stl_multiset.h" 3
namespace std __attribute((__visibility__("default" ))) { 
# 82
template < typename _Key, typename _Compare = std :: less < _Key >,
     typename _Alloc = std :: allocator < _Key > >
    class multiset
    {

      typedef typename _Alloc :: value_type _Alloc_value_type;





    public :

      typedef _Key key_type;
      typedef _Key value_type;
      typedef _Compare key_compare;
      typedef _Compare value_compare;
      typedef _Alloc allocator_type;

    private :

      typedef typename _Alloc :: template rebind < _Key > :: other _Key_alloc_type;

      typedef _Rb_tree < key_type, value_type, _Identity < value_type >,
         key_compare, _Key_alloc_type > _Rep_type;

      _Rep_type _M_t;

    public :
      typedef typename _Key_alloc_type :: pointer pointer;
      typedef typename _Key_alloc_type :: const_pointer const_pointer;
      typedef typename _Key_alloc_type :: reference reference;
      typedef typename _Key_alloc_type :: const_reference const_reference;



      typedef typename _Rep_type :: const_iterator iterator;
      typedef typename _Rep_type :: const_iterator const_iterator;
      typedef typename _Rep_type :: const_reverse_iterator reverse_iterator;
      typedef typename _Rep_type :: const_reverse_iterator const_reverse_iterator;
      typedef typename _Rep_type :: size_type size_type;
      typedef typename _Rep_type :: difference_type difference_type;





      multiset ( )
      : _M_t ( ) { }






      explicit
      multiset ( const _Compare & __comp,
        const allocator_type & __a = allocator_type ( ) )
      : _M_t ( __comp, __a ) { }










      template < typename _InputIterator >
        multiset ( _InputIterator __first, _InputIterator __last )
 : _M_t ( )
        { _M_t . _M_insert_equal ( __first, __last ); }












      template < typename _InputIterator >
        multiset ( _InputIterator __first, _InputIterator __last,
   const _Compare & __comp,
   const allocator_type & __a = allocator_type ( ) )
 : _M_t ( __comp, __a )
        { _M_t . _M_insert_equal ( __first, __last ); }








      multiset ( const multiset & __x )
      : _M_t ( __x . _M_t ) { }




































      multiset &
      operator = ( const multiset & __x )
      {
 _M_t = __x . _M_t;
 return * this;
      }









































      key_compare
      key_comp ( ) const
      { return _M_t . key_comp ( ); }

      value_compare
      value_comp ( ) const
      { return _M_t . key_comp ( ); }

      allocator_type
      get_allocator ( ) const
      { return _M_t . get_allocator ( ); }






      iterator
      begin ( ) const
      { return _M_t . begin ( ); }






      iterator
      end ( ) const
      { return _M_t . end ( ); }






      reverse_iterator
      rbegin ( ) const
      { return _M_t . rbegin ( ); }






      reverse_iterator
      rend ( ) const
      { return _M_t . rend ( ); }








































      bool
      empty ( ) const
      { return _M_t . empty ( ); }


      size_type
      size ( ) const
      { return _M_t . size ( ); }


      size_type
      max_size ( ) const
      { return _M_t . max_size ( ); }












      void



      swap ( multiset & __x )

      { _M_t . swap ( __x . _M_t ); }













      iterator
      insert ( const value_type & __x )
      { return _M_t . _M_insert_equal ( __x ); }





















      iterator
      insert ( iterator __position, const value_type & __x )
      { return _M_t . _M_insert_equal_ ( __position, __x ); }









      template < typename _InputIterator >
        void
        insert ( _InputIterator __first, _InputIterator __last )
        { _M_t . _M_insert_equal ( __first, __last ); }
























      void
      erase ( iterator __position )
      { _M_t . erase ( __position ); }












      size_type
      erase ( const key_type & __x )
      { return _M_t . erase ( __x ); }












      void
      erase ( iterator __first, iterator __last )
      { _M_t . erase ( __first, __last ); }







      void
      clear ( )
      { _M_t . clear ( ); }








      size_type
      count ( const key_type & __x ) const
      { return _M_t . count ( __x ); }















      iterator
      find ( const key_type & __x )
      { return _M_t . find ( __x ); }

      const_iterator
      find ( const key_type & __x ) const
      { return _M_t . find ( __x ); }














      iterator
      lower_bound ( const key_type & __x )
      { return _M_t . lower_bound ( __x ); }

      const_iterator
      lower_bound ( const key_type & __x ) const
      { return _M_t . lower_bound ( __x ); }









      iterator
      upper_bound ( const key_type & __x )
      { return _M_t . upper_bound ( __x ); }

      const_iterator
      upper_bound ( const key_type & __x ) const
      { return _M_t . upper_bound ( __x ); }


















      std :: pair < iterator, iterator >
      equal_range ( const key_type & __x )
      { return _M_t . equal_range ( __x ); }

      std :: pair < const_iterator, const_iterator >
      equal_range ( const key_type & __x ) const
      { return _M_t . equal_range ( __x ); }

      template < typename _K1, typename _C1, typename _A1 >
        friend bool
        operator == ( const multiset < _K1, _C1, _A1 > &,
     const multiset < _K1, _C1, _A1 > & );

      template < typename _K1, typename _C1, typename _A1 >
        friend bool
        operator < ( const multiset < _K1, _C1, _A1 > &,
     const multiset < _K1, _C1, _A1 > & );
    };
# 623
template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator == ( const multiset < _Key, _Compare, _Alloc > & __x,
        const multiset < _Key, _Compare, _Alloc > & __y )
    { return __x . _M_t == __y . _M_t; }
# 640
template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator < ( const multiset < _Key, _Compare, _Alloc > & __x,
       const multiset < _Key, _Compare, _Alloc > & __y )
    { return __x . _M_t < __y . _M_t; }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator != ( const multiset < _Key, _Compare, _Alloc > & __x,
        const multiset < _Key, _Compare, _Alloc > & __y )
    { return ! ( __x == __y ); }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator > ( const multiset < _Key, _Compare, _Alloc > & __x,
       const multiset < _Key, _Compare, _Alloc > & __y )
    { return __y < __x; }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator <= ( const multiset < _Key, _Compare, _Alloc > & __x,
        const multiset < _Key, _Compare, _Alloc > & __y )
    { return ! ( __y < __x ); }


template < typename _Key, typename _Compare, typename _Alloc >
    inline bool
    operator >= ( const multiset < _Key, _Compare, _Alloc > & __x,
        const multiset < _Key, _Compare, _Alloc > & __y )
    { return ! ( __x < __y ); }


template < typename _Key, typename _Compare, typename _Alloc >
    inline void
    swap ( multiset < _Key, _Compare, _Alloc > & __x,
  multiset < _Key, _Compare, _Alloc > & __y )
    { __x . swap ( __y ); }
# 695
}
# 40 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/Context.h"
namespace openacci { 


class Context { 



public: Context(); 


~Context(); 


static Context *getInstance(); 


void init(acc_device_t); 


void setDeviceType(acc_device_t, int num = (0)); 


void setDeviceHint(int device_type); 


acc_device_t getDeviceType() const; 


void *getDeviceHandle(); 


void *getDeviceContext(); 


void *getQueueHandle(int async); 


void setQueueHandle(int async, void * handle); 


bool onDeviceType(acc_device_t dt) const; 


int getDeviceNum(acc_device_t dt) const; 


void shutdown(acc_device_t type); 


hmpprt::Device *getDevice(); 


void *getGlobal(const char * variable); 


void call(const char *file_name, int 
line_number, const char *
function_name) 
{ 
this->call(file_name, line_number, function_name, function_name); 
} 



void call(const char * file_name, int line_number, const char * module_name, const char * function_name); 
# 111
void fallback(const char * file_name, int line_number, const char * function_name); 
# 117
void enterRegion(const char * file_name, int line_number, int region_kind, int num_arguments, int async_value); 
# 125
void enterGlobalRegion(const char * file_name, int line_number, int region_kind, int num_arguments, int async_value); 
# 133
void leaveGlobalRegion(const char * file_name, int line_number); 




void leaveRegion(const char * file_name, int line_number); 




bool isInitialized(const void * module_address); 



void recordModule(const void * module_address); 



void pushGlobalData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t start, size_t length, size_t element_size, int transfer_mode); 
# 162
void pushGlobalData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t * starts, size_t * lengths, size_t nb_dimensions, const char * dim_desc, size_t element_size, int transfer_mode); 
# 177
void pushData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t start, size_t length, size_t element_size, int transfer_mode); 
# 190
void pushData(const char * file_name, int line_number, const char * variable_name, const void * host_address, const size_t * starts, const size_t * lengths, size_t nb_dimensions, const char * dim_desc, size_t element_size, int transfer_mode); 
# 203
void enterData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t start, size_t length, size_t element_size, int transfer_mode, int async_value); 
# 215
void enterData(const char * file_name, int line_number, const char * variable_name, const void * host_address, const size_t * starts, const size_t * lengths, size_t nb_dimensions, const char * dim_desc, size_t element_size, int transfer_mode, int async_value); 
# 229
void exitData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t start, size_t length, size_t element_size, int transfer_mode, int async_value); 
# 241
void exitData(const char * file_name, int line_number, const char * variable_name, const void * host_address, const size_t * starts, const size_t * lengths, size_t nb_dimensions, const char * dim_desc, size_t element_size, int transfer_mode, int async_value); 
# 255
void trackData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t size); 
# 263
void untrackData(const char * file_name, int line_number, const char * variable_name, const void * host_address); 
# 270
void updateDatas(const char * file_name, int line_number, int async_value, int nb_variables, const char ** variable_names, const void ** host_addresses, const size_t * starts, const size_t * lengths, const size_t * elements_sizes, const int * update_sides); 
# 283
void updateDatas(const char * file_name, int line_number, int async_value, int nb_variables, const char ** variable_names, const void ** host_addresses, const size_t ** starts, const size_t ** lengths, const size_t * nb_dimensions, const size_t * elements_sizes, const int * update_sides); 
# 297
void allocateDeviceResident(const char * file_name, const int & line_number, const void * desc_address, const int & num_argument, va_list ap); 
# 304
void deallocateDeviceResident(const char * file_name, const int & line_number, const void * desc_address); 
# 310
void wait(const char * file_name, int line_number, int awaited_value, int async_value); 
# 316
bool test(const char * file_name, int line_number, int async_value); 




void *malloc(size_t size); 


void free(void * ptr); 



Mirror *getOrCreateMirror(void * host_address, size_t size); 


Data *presentData(void * host_address); 


Data *createData(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::MemorySpace ms, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 345
void *copyin(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 355
void *present_or_copyin(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 365
void *createCoherentData(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 375
void *create(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 384
void *present_or_create(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 393
void copyout(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 403
void delete_(const char * file_name, int line_number, const char * variable_name, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 413
void update_device(const char * file_name, int line_number, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 422
void update_self(const char * file_name, int line_number, void * host_address, size_t size, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 431
void map_data(const char * variable_name, void * host_address, void * device_address, size_t size); 
# 437
void unmap_data(const char * file_name, int line_number, void * host_address); 




void *getDevicePointer(const char * file_name, int line_number, const void * host_address); 




void *getHostPointer(const char * file_name, int line_number, const void * host_address); 




void *devicePtr(const char * file_name, int line_number, const void * host_address); 




void *hostPtr(const char * file_name, int line_number, const void * host_address); 




int isPresent(void * host_address, size_t size); 


void memcpyToDevice(void * dest, void * src, size_t size, const char * file_name, int line_number, const char * variable_name, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 476
void memcpyFromDevice(void * dest, void * src, size_t size, const char * file_name, int line_number, const char * variable_name, hmpprt::Queue * queue, const char * qdesc, int async_value); 
# 487
private: static void createInstance(Context ** instance); 

hmpprt::Device *device_; 
AsyncManager asyncManager_; 


CodeletMap codelet_map_; 
Codelet *lookupCodelet(const char * module_name, const char * function_name); 


std::list< Region>  region_stack_; 


typedef std::map< void *, hmpprt::Data *>  DevicePtrMap; 
DevicePtrMap device_ptr_map_; 

struct GlobalData { 

Mirror *mirror; 
std::string file_name; 
int line_number; 
}; 

typedef std::map< std::basic_string< char, std::char_traits< char> , std::allocator< char> > , GlobalData *>  GlobalMap; 
GlobalMap global_map_; 

std::set< const void *>  initialized_modules_; 

MirrorManager *mirror_manager_; 

acc_device_t device_type_; 
int device_num_; 
acc_device_t device_hint_; 

void clean(); 

void updateData(const char * file_name, int line_number, const char * variable_name, const void * host_address, size_t start, size_t length, size_t element_size, int update_side, int async_value); 
# 533
void updateData(const char * file_name, int line_number, const char * variable_name, const void * host_address, const size_t * starts, const size_t * lengths, size_t nb_dimensions, size_t element_size, int update_side, int async_value); 
# 544
void enterBasicRegion(const char * file_name, int line_number, int region_kind, int num_arguments, int async_value, std::list< Region>  & region_stack); 
# 551
void leaveBasicRegion(const char * file_name, int line_number, std::list< Region>  & region_stack); 




void pushDataInRegion(const char * file_name, int line_number, const char * variable_name, const void * host_address_, size_t start, size_t length, size_t element_size, int transfer_mode, Region * region); 
# 566
void pushDataInRegion(const char * file_name, int line_number, const char * variable_name, const void * host_address_, const size_t * starts, const size_t * lengths, size_t nb_dimensions, const char * dim_desc, size_t element_size, int transfer_mode, Region * region); 
# 578
static void dataProxy(hmpprt::Context *); 

}; 
}
# 29 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/LocalDeclare.h"
namespace openacci { 


class LocalDeclare { 



public: LocalDeclare(const char *file_name, int 
line_num, int 
region_kind, int 
num_arguments, int 
async_value) : file_name(file_name), line_number(line_num) 

{ 
ctxt = Context::getInstance(); 
(ctxt)->enterRegion(file_name, line_num, region_kind, num_arguments, async_value); 




} 


~LocalDeclare() 
{ 
(ctxt)->leaveRegion(file_name, line_number); 
} 
# 61
void pushData(const char *file_name, int 
line_num, const char *
variable_name, const void *
host_address, size_t 
start, size_t 
length, size_t 
element_size, int 
transfer_mode) 
{ 
(ctxt)->pushData(file_name, line_num, variable_name, host_address, start, length, element_size, transfer_mode); 
# 78
} 


private: const char *file_name; 
int line_number; 
Context *ctxt; 
}; 
}
# 29 "/home/lijing/tools/CAPSCompilers-3.4.4/include/openacci/GlobalDeclare.h"
namespace openacci { 


class GlobalDeclare { 



public: GlobalDeclare(const char *file_name, int 
line_num, int 
device_hint, int 
region_kind, int 
num_arguments, int 
async_value, const char **
variable_names, const void **
host_addresses, size_t *
starts, size_t *
lengths, size_t *
element_sizes, int *
transfer_modes) : file_name(file_name), line_number(line_num) 

{ 
ctxt = Context::getInstance(); 
(ctxt)->setDeviceHint(device_hint); 
(ctxt)->enterRegion(file_name, line_num, region_kind, num_arguments, async_value); 




for (int i = 0; i < num_arguments; i++) 
{ 
(ctxt)->pushData(file_name, line_num, variable_names[i], host_addresses[i], starts[i], lengths[i], element_sizes[i], transfer_modes[i]); 
# 67
}  
} 


GlobalDeclare(const char *file_name, int 
line_num, int 
device_hint, int 
region_kind, int 
num_arguments, int 
async_value, const char **
variable_names, const void **
host_addresses, const size_t **
starts, const size_t **
lengths, const size_t *
nb_dimensions, const char **
dim_descs, const size_t *
element_sizes, int *
transfer_modes) : file_name(file_name), line_number(line_num) 

{ 
ctxt = Context::getInstance(); 
(ctxt)->setDeviceHint(device_hint); 
(ctxt)->enterRegion(file_name, line_num, region_kind, num_arguments, async_value); 




for (int i = 0; i < num_arguments; i++) 
{ 
if (nb_dimensions[i] > (1)) 
{ 
(ctxt)->pushData(file_name, line_num, variable_names[i], host_addresses[i], starts[i], lengths[i], nb_dimensions[i], dim_descs[i], element_sizes[i], transfer_modes[i]); 
# 108
} else 

{ 
(ctxt)->pushData(file_name, line_num, variable_names[i], host_addresses[i], (starts[i])[0], (lengths[i])[0], element_sizes[i], transfer_modes[i]); 
# 119
}  
}  
} 


~GlobalDeclare() 
{ 
(ctxt)->leaveRegion(file_name, line_number); 
} 


private: const char *file_name; 
int line_number; 
Context *ctxt; 
}; 
}
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef 
# 23
struct { 
__off_t __pos; 
__mbstate_t __state; 
} _G_fpos_t; }




extern "C" { typedef 
# 28
struct { 
__off64_t __pos; 
__mbstate_t __state; 
} _G_fpos64_t; }
# 53
extern "C" { typedef short _G_int16_t __attribute((__mode__(__HI__))); }
extern "C" { typedef int _G_int32_t __attribute((__mode__(__SI__))); }
extern "C" { typedef unsigned short _G_uint16_t __attribute((__mode__(__HI__))); }
extern "C" { typedef unsigned _G_uint32_t __attribute((__mode__(__SI__))); }
# 170 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE; 
# 180
extern "C" { typedef void _IO_lock_t; }
# 186
extern "C" { struct _IO_marker { 
_IO_marker *_next; 
_IO_FILE *_sbuf; 



int _pos; 
# 203
}; }


enum __codecvt_result { 

__codecvt_ok, 
__codecvt_partial, 
__codecvt_error, 
__codecvt_noconv
}; 
# 271
extern "C" { struct _IO_FILE { 
int _flags; 




char *_IO_read_ptr; 
char *_IO_read_end; 
char *_IO_read_base; 
char *_IO_write_base; 
char *_IO_write_ptr; 
char *_IO_write_end; 
char *_IO_buf_base; 
char *_IO_buf_end; 

char *_IO_save_base; 
char *_IO_backup_base; 
char *_IO_save_end; 

_IO_marker *_markers; 

_IO_FILE *_chain; 

int _fileno; 



int _flags2; 

__off_t _old_offset; 



unsigned short _cur_column; 
signed char _vtable_offset; 
char _shortbuf[1]; 



_IO_lock_t *_lock; 
# 319
__off64_t _offset; 
# 328
void *__pad1; 
void *__pad2; 
void *__pad3; 
void *__pad4; 
size_t __pad5; 

int _mode; 

char _unused2[((15) * sizeof(int) - (4) * sizeof(void *)) - sizeof(size_t)]; 

}; }
# 344
struct _IO_FILE_plus; 

extern "C" { extern _IO_FILE_plus _IO_2_1_stdin_; } 
extern "C" { extern _IO_FILE_plus _IO_2_1_stdout_; } 
extern "C" { extern _IO_FILE_plus _IO_2_1_stderr_; } 
# 364
extern "C" { typedef __ssize_t __io_read_fn(void * __cookie, char * __buf, size_t __nbytes); }
# 372
extern "C" { typedef __ssize_t __io_write_fn(void * __cookie, const char * __buf, size_t __n); }
# 381
extern "C" { typedef int __io_seek_fn(void * __cookie, __off64_t * __pos, int __w); }


extern "C" { typedef int __io_close_fn(void * __cookie); }




extern "C" { typedef __io_read_fn cookie_read_function_t; }
extern "C" { typedef __io_write_fn cookie_write_function_t; }
extern "C" { typedef __io_seek_fn cookie_seek_function_t; }
extern "C" { typedef __io_close_fn cookie_close_function_t; }
# 401
extern "C" { typedef 
# 396
struct { 
__io_read_fn *read; 
__io_write_fn *write; 
__io_seek_fn *seek; 
__io_close_fn *close; 
} _IO_cookie_io_functions_t; }
extern "C" { typedef _IO_cookie_io_functions_t cookie_io_functions_t; }

struct _IO_cookie_file; 


extern "C" void _IO_cookie_init(_IO_cookie_file * __cfile, int __read_write, void * __cookie, _IO_cookie_io_functions_t __fns); 
# 416
extern "C" int __underflow(_IO_FILE *); 
extern "C" int __uflow(_IO_FILE *); 
extern "C" int __overflow(_IO_FILE *, int); 
# 460
extern "C" int _IO_getc(_IO_FILE * __fp); 
extern "C" int _IO_putc(int __c, _IO_FILE * __fp); 
extern "C" int _IO_feof(_IO_FILE * __fp) throw(); 
extern "C" int _IO_ferror(_IO_FILE * __fp) throw(); 

extern "C" int _IO_peekc_locked(_IO_FILE * __fp); 
# 471
extern "C" void _IO_flockfile(_IO_FILE *) throw(); 
extern "C" void _IO_funlockfile(_IO_FILE *) throw(); 
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw(); 
# 490
extern "C" int _IO_vfscanf(_IO_FILE *, const char *, __gnuc_va_list, int *); 

extern "C" int _IO_vfprintf(_IO_FILE *, const char *, __gnuc_va_list); 

extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t); 
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t); 

extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int); 
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int); 

extern "C" void _IO_free_backup_area(_IO_FILE *) throw(); 
# 111 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos_t fpos_t; }
# 117
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 165
extern "C" { extern _IO_FILE *stdin; } 
extern "C" { extern _IO_FILE *stdout; } 
extern "C" { extern _IO_FILE *stderr; } 
# 177
extern "C" int remove(const char * __filename) throw(); 

extern "C" int rename(const char * __old, const char * __new) throw(); 




extern "C" int renameat(int __oldfd, const char * __old, int __newfd, const char * __new) throw(); 
# 194
extern "C" FILE *tmpfile(); 
# 204
extern "C" FILE *tmpfile64(); 



extern "C" char *tmpnam(char * __s) throw(); 
# 214
extern "C" char *tmpnam_r(char * __s) throw(); 
# 226
extern "C" char *tempnam(const char * __dir, const char * __pfx) throw()
 __attribute((__malloc__)); 
# 236
extern "C" int fclose(FILE * __stream); 




extern "C" int fflush(FILE * __stream); 
# 251
extern "C" int fflush_unlocked(FILE * __stream); 
# 261
extern "C" int fcloseall(); 
# 271
extern "C" FILE *fopen(const char * __filename, const char * __modes); 
# 277
extern "C" FILE *freopen(const char * __filename, const char * __modes, FILE * __stream); 
# 296
extern "C" FILE *fopen64(const char * __filename, const char * __modes); 

extern "C" FILE *freopen64(const char * __filename, const char * __modes, FILE * __stream); 
# 305
extern "C" FILE *fdopen(int __fd, const char * __modes) throw(); 
# 311
extern "C" FILE *fopencookie(void * __magic_cookie, const char * __modes, _IO_cookie_io_functions_t __io_funcs) throw(); 
# 318
extern "C" FILE *fmemopen(void * __s, size_t __len, const char * __modes) throw(); 
# 324
extern "C" FILE *open_memstream(char ** __bufloc, size_t * __sizeloc) throw(); 
# 331
extern "C" void setbuf(FILE * __stream, char * __buf) throw(); 



extern "C" int setvbuf(FILE * __stream, char * __buf, int __modes, size_t __n) throw(); 
# 342
extern "C" void setbuffer(FILE * __stream, char * __buf, size_t __size) throw(); 



extern "C" void setlinebuf(FILE * __stream) throw(); 
# 355
extern "C" int fprintf(FILE * __stream, const char * __format, ...); 
# 361
extern "C" int printf(const char * __format, ...); 

extern "C" int sprintf(char * __s, const char * __format, ...) throw(); 
# 370
extern "C" int vfprintf(FILE * __s, const char * __format, __gnuc_va_list __arg); 
# 376
extern "C" int vprintf(const char * __format, __gnuc_va_list __arg); 

extern "C" int vsprintf(char * __s, const char * __format, __gnuc_va_list __arg) throw(); 
# 385
extern "C" int snprintf(char * __s, size_t __maxlen, const char * __format, ...) throw()

 __attribute((__format__(__printf__, 3, 4))); 

extern "C" int vsnprintf(char * __s, size_t __maxlen, const char * __format, __gnuc_va_list __arg) throw()

 __attribute((__format__(__printf__, 3, 0))); 
# 398
extern "C" int vasprintf(char ** __ptr, const char * __f, __gnuc_va_list __arg) throw()

 __attribute((__format__(__printf__, 2, 0))); 
extern "C" int __asprintf(char ** __ptr, const char * __fmt, ...) throw()

 __attribute((__format__(__printf__, 2, 3))); 
extern "C" int asprintf(char ** __ptr, const char * __fmt, ...) throw()

 __attribute((__format__(__printf__, 2, 3))); 
# 416
extern "C" int vdprintf(int __fd, const char * __fmt, __gnuc_va_list __arg)

 __attribute((__format__(__printf__, 2, 0))); 
extern "C" int dprintf(int __fd, const char * __fmt, ...)
 __attribute((__format__(__printf__, 2, 3))); 
# 429
extern "C" int fscanf(FILE * __stream, const char * __format, ...); 
# 435
extern "C" int scanf(const char * __format, ...); 

extern "C" int sscanf(const char * __s, const char * __format, ...) throw(); 
# 475
extern "C" int vfscanf(FILE * __s, const char * __format, __gnuc_va_list __arg)

 __attribute((__format__(__scanf__, 2, 0))); 
# 483
extern "C" int vscanf(const char * __format, __gnuc_va_list __arg)
 __attribute((__format__(__scanf__, 1, 0))); 


extern "C" int vsscanf(const char * __s, const char * __format, __gnuc_va_list __arg) throw()

 __attribute((__format__(__scanf__, 2, 0))); 
# 535
extern "C" int fgetc(FILE * __stream); 
extern "C" int getc(FILE * __stream); 
# 542
extern "C" int getchar(); 
# 554
extern "C" int getc_unlocked(FILE * __stream); 
extern "C" int getchar_unlocked(); 
# 565
extern "C" int fgetc_unlocked(FILE * __stream); 
# 577
extern "C" int fputc(int __c, FILE * __stream); 
extern "C" int putc(int __c, FILE * __stream); 
# 584
extern "C" int putchar(int __c); 
# 598
extern "C" int fputc_unlocked(int __c, FILE * __stream); 
# 606
extern "C" int putc_unlocked(int __c, FILE * __stream); 
extern "C" int putchar_unlocked(int __c); 
# 614
extern "C" int getw(FILE * __stream); 


extern "C" int putw(int __w, FILE * __stream); 
# 626
extern "C" char *fgets(char * __s, int __n, FILE * __stream); 
# 634
extern "C" char *gets(char * __s); 
# 644
extern "C" char *fgets_unlocked(char * __s, int __n, FILE * __stream); 
# 660
extern "C" __ssize_t __getdelim(char ** __lineptr, size_t * __n, int __delimiter, FILE * __stream); 


extern "C" __ssize_t getdelim(char ** __lineptr, size_t * __n, int __delimiter, FILE * __stream); 
# 673
extern "C" __ssize_t getline(char ** __lineptr, size_t * __n, FILE * __stream); 
# 684
extern "C" int fputs(const char * __s, FILE * __stream); 
# 690
extern "C" int puts(const char * __s); 
# 697
extern "C" int ungetc(int __c, FILE * __stream); 
# 704
extern "C" size_t fread(void * __ptr, size_t __size, size_t __n, FILE * __stream); 
# 710
extern "C" size_t fwrite(const void * __ptr, size_t __size, size_t __n, FILE * __s); 
# 721
extern "C" int fputs_unlocked(const char * __s, FILE * __stream); 
# 732
extern "C" size_t fread_unlocked(void * __ptr, size_t __size, size_t __n, FILE * __stream); 

extern "C" size_t fwrite_unlocked(const void * __ptr, size_t __size, size_t __n, FILE * __stream); 
# 744
extern "C" int fseek(FILE * __stream, long __off, int __whence); 




extern "C" long ftell(FILE * __stream); 




extern "C" void rewind(FILE * __stream); 
# 768
extern "C" int fseeko(FILE * __stream, __off_t __off, int __whence); 




extern "C" __off_t ftello(FILE * __stream); 
# 793
extern "C" int fgetpos(FILE * __stream, fpos_t * __pos); 




extern "C" int fsetpos(FILE * __stream, const fpos_t * __pos); 
# 813
extern "C" int fseeko64(FILE * __stream, __off64_t __off, int __whence); 
extern "C" __off64_t ftello64(FILE * __stream); 
extern "C" int fgetpos64(FILE * __stream, fpos64_t * __pos); 
extern "C" int fsetpos64(FILE * __stream, const fpos64_t * __pos); 




extern "C" void clearerr(FILE * __stream) throw(); 

extern "C" int feof(FILE * __stream) throw(); 

extern "C" int ferror(FILE * __stream) throw(); 




extern "C" void clearerr_unlocked(FILE * __stream) throw(); 
extern "C" int feof_unlocked(FILE * __stream) throw(); 
extern "C" int ferror_unlocked(FILE * __stream) throw(); 
# 841
extern "C" void perror(const char * __s); 
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; } 
extern "C" { extern const char *const sys_errlist[]; } 


extern "C" { extern int _sys_nerr; } 
extern "C" { extern const char *const _sys_errlist[]; } 
# 853 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE * __stream) throw(); 




extern "C" int fileno_unlocked(FILE * __stream) throw(); 
# 868
extern "C" FILE *popen(const char * __command, const char * __modes); 
# 874
extern "C" int pclose(FILE * __stream); 
# 880
extern "C" char *ctermid(char * __s) throw(); 
# 886
extern "C" char *cuserid(char * __s); 




struct obstack; 


extern "C" int obstack_printf(obstack * __obstack, const char * __format, ...) throw()

 __attribute((__format__(__printf__, 2, 3))); 
extern "C" int obstack_vprintf(obstack * __obstack, const char * __format, __gnuc_va_list __args) throw()


 __attribute((__format__(__printf__, 2, 0))); 
# 908
extern "C" void flockfile(FILE * __stream) throw(); 



extern "C" int ftrylockfile(FILE * __stream) throw(); 


extern "C" void funlockfile(FILE * __stream) throw(); 
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" double acos(double __x) throw(); extern "C" double __acos(double __x) throw(); 

extern "C" double asin(double __x) throw(); extern "C" double __asin(double __x) throw(); 

extern "C" double atan(double __x) throw(); extern "C" double __atan(double __x) throw(); 

extern "C" double atan2(double __y, double __x) throw(); extern "C" double __atan2(double __y, double __x) throw(); 


extern "C" double cos(double __x) throw(); extern "C" double __cos(double __x) throw(); 

extern "C" double sin(double __x) throw(); extern "C" double __sin(double __x) throw(); 

extern "C" double tan(double __x) throw(); extern "C" double __tan(double __x) throw(); 




extern "C" double cosh(double __x) throw(); extern "C" double __cosh(double __x) throw(); 

extern "C" double sinh(double __x) throw(); extern "C" double __sinh(double __x) throw(); 

extern "C" double tanh(double __x) throw(); extern "C" double __tanh(double __x) throw(); 




extern "C" void sincos(double __x, double * __sinx, double * __cosx) throw(); extern "C" void __sincos(double __x, double * __sinx, double * __cosx) throw(); 
# 89
extern "C" double acosh(double __x) throw(); extern "C" double __acosh(double __x) throw(); 

extern "C" double asinh(double __x) throw(); extern "C" double __asinh(double __x) throw(); 

extern "C" double atanh(double __x) throw(); extern "C" double __atanh(double __x) throw(); 
# 101
extern "C" double exp(double __x) throw(); extern "C" double __exp(double __x) throw(); 


extern "C" double frexp(double __x, int * __exponent) throw(); extern "C" double __frexp(double __x, int * __exponent) throw(); 


extern "C" double ldexp(double __x, int __exponent) throw(); extern "C" double __ldexp(double __x, int __exponent) throw(); 


extern "C" double log(double __x) throw(); extern "C" double __log(double __x) throw(); 


extern "C" double log10(double __x) throw(); extern "C" double __log10(double __x) throw(); 


extern "C" double modf(double __x, double * __iptr) throw(); extern "C" double __modf(double __x, double * __iptr) throw(); 




extern "C" double exp10(double __x) throw(); extern "C" double __exp10(double __x) throw(); 

extern "C" double pow10(double __x) throw(); extern "C" double __pow10(double __x) throw(); 
# 129
extern "C" double expm1(double __x) throw(); extern "C" double __expm1(double __x) throw(); 


extern "C" double log1p(double __x) throw(); extern "C" double __log1p(double __x) throw(); 


extern "C" double logb(double __x) throw(); extern "C" double __logb(double __x) throw(); 
# 142
extern "C" double exp2(double __x) throw(); extern "C" double __exp2(double __x) throw(); 


extern "C" double log2(double __x) throw(); extern "C" double __log2(double __x) throw(); 
# 154
extern "C" double pow(double __x, double __y) throw(); extern "C" double __pow(double __x, double __y) throw(); 


extern "C" double sqrt(double __x) throw(); extern "C" double __sqrt(double __x) throw(); 
# 163
extern "C" double hypot(double __x, double __y) throw(); extern "C" double __hypot(double __x, double __y) throw(); 
# 170
extern "C" double cbrt(double __x) throw(); extern "C" double __cbrt(double __x) throw(); 
# 179
extern "C" double ceil(double __x) throw() __attribute((const)); extern "C" double __ceil(double __x) throw() __attribute((const)); 


extern "C" double fabs(double __x) throw() __attribute((const)); extern "C" double __fabs(double __x) throw() __attribute((const)); 


extern "C" double floor(double __x) throw() __attribute((const)); extern "C" double __floor(double __x) throw() __attribute((const)); 


extern "C" double fmod(double __x, double __y) throw(); extern "C" double __fmod(double __x, double __y) throw(); 




extern "C" int __isinf(double __value) throw() __attribute((const)); 


extern "C" int __finite(double __value) throw() __attribute((const)); 
# 202
extern "C" int isinf(double __value) throw() __attribute((const)); 


extern "C" int finite(double __value) throw() __attribute((const)); 


extern "C" double drem(double __x, double __y) throw(); extern "C" double __drem(double __x, double __y) throw(); 



extern "C" double significand(double __x) throw(); extern "C" double __significand(double __x) throw(); 
# 218
extern "C" double copysign(double __x, double __y) throw() __attribute((const)); extern "C" double __copysign(double __x, double __y) throw() __attribute((const)); 
# 225
extern "C" double nan(const char * __tagb) throw() __attribute((const)); extern "C" double __nan(const char * __tagb) throw() __attribute((const)); 
# 231
extern "C" int __isnan(double __value) throw() __attribute((const)); 



extern "C" int isnan(double __value) throw() __attribute((const)); 


extern "C" double j0(double) throw(); extern "C" double __j0(double) throw(); 
extern "C" double j1(double) throw(); extern "C" double __j1(double) throw(); 
extern "C" double jn(int, double) throw(); extern "C" double __jn(int, double) throw(); 
extern "C" double y0(double) throw(); extern "C" double __y0(double) throw(); 
extern "C" double y1(double) throw(); extern "C" double __y1(double) throw(); 
extern "C" double yn(int, double) throw(); extern "C" double __yn(int, double) throw(); 
# 250
extern "C" double erf(double) throw(); extern "C" double __erf(double) throw(); 
extern "C" double erfc(double) throw(); extern "C" double __erfc(double) throw(); 
extern "C" double lgamma(double) throw(); extern "C" double __lgamma(double) throw(); 
# 259
extern "C" double tgamma(double) throw(); extern "C" double __tgamma(double) throw(); 
# 265
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw(); 
# 272
extern "C" double lgamma_r(double, int * __signgamp) throw(); extern "C" double __lgamma_r(double, int * __signgamp) throw(); 
# 280
extern "C" double rint(double __x) throw(); extern "C" double __rint(double __x) throw(); 


extern "C" double nextafter(double __x, double __y) throw() __attribute((const)); extern "C" double __nextafter(double __x, double __y) throw() __attribute((const)); 

extern "C" double nexttoward(double __x, long double __y) throw() __attribute((const)); extern "C" double __nexttoward(double __x, long double __y) throw() __attribute((const)); 



extern "C" double remainder(double __x, double __y) throw(); extern "C" double __remainder(double __x, double __y) throw(); 



extern "C" double scalbn(double __x, int __n) throw(); extern "C" double __scalbn(double __x, int __n) throw(); 



extern "C" int ilogb(double __x) throw(); extern "C" int __ilogb(double __x) throw(); 




extern "C" double scalbln(double __x, long __n) throw(); extern "C" double __scalbln(double __x, long __n) throw(); 



extern "C" double nearbyint(double __x) throw(); extern "C" double __nearbyint(double __x) throw(); 



extern "C" double round(double __x) throw() __attribute((const)); extern "C" double __round(double __x) throw() __attribute((const)); 



extern "C" double trunc(double __x) throw() __attribute((const)); extern "C" double __trunc(double __x) throw() __attribute((const)); 




extern "C" double remquo(double __x, double __y, int * __quo) throw(); extern "C" double __remquo(double __x, double __y, int * __quo) throw(); 
# 326
extern "C" long lrint(double __x) throw(); extern "C" long __lrint(double __x) throw(); 
extern "C" long long llrint(double __x) throw(); extern "C" long long __llrint(double __x) throw(); 



extern "C" long lround(double __x) throw(); extern "C" long __lround(double __x) throw(); 
extern "C" long long llround(double __x) throw(); extern "C" long long __llround(double __x) throw(); 



extern "C" double fdim(double __x, double __y) throw(); extern "C" double __fdim(double __x, double __y) throw(); 


extern "C" double fmax(double __x, double __y) throw(); extern "C" double __fmax(double __x, double __y) throw(); 


extern "C" double fmin(double __x, double __y) throw(); extern "C" double __fmin(double __x, double __y) throw(); 



extern "C" int __fpclassify(double __value) throw()
 __attribute((const)); 


extern "C" int __signbit(double __value) throw()
 __attribute((const)); 



extern "C" double fma(double __x, double __y, double __z) throw(); extern "C" double __fma(double __x, double __y, double __z) throw(); 
# 364
extern "C" double scalb(double __x, double __n) throw(); extern "C" double __scalb(double __x, double __n) throw(); 
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" float acosf(float __x) throw(); extern "C" float __acosf(float __x) throw(); 

extern "C" float asinf(float __x) throw(); extern "C" float __asinf(float __x) throw(); 

extern "C" float atanf(float __x) throw(); extern "C" float __atanf(float __x) throw(); 

extern "C" float atan2f(float __y, float __x) throw(); extern "C" float __atan2f(float __y, float __x) throw(); 


extern "C" float cosf(float __x) throw(); extern "C" float __cosf(float __x) throw(); 

extern "C" float sinf(float __x) throw(); extern "C" float __sinf(float __x) throw(); 

extern "C" float tanf(float __x) throw(); extern "C" float __tanf(float __x) throw(); 




extern "C" float coshf(float __x) throw(); extern "C" float __coshf(float __x) throw(); 

extern "C" float sinhf(float __x) throw(); extern "C" float __sinhf(float __x) throw(); 

extern "C" float tanhf(float __x) throw(); extern "C" float __tanhf(float __x) throw(); 




extern "C" void sincosf(float __x, float * __sinx, float * __cosx) throw(); extern "C" void __sincosf(float __x, float * __sinx, float * __cosx) throw(); 
# 89
extern "C" float acoshf(float __x) throw(); extern "C" float __acoshf(float __x) throw(); 

extern "C" float asinhf(float __x) throw(); extern "C" float __asinhf(float __x) throw(); 

extern "C" float atanhf(float __x) throw(); extern "C" float __atanhf(float __x) throw(); 
# 101
extern "C" float expf(float __x) throw(); extern "C" float __expf(float __x) throw(); 


extern "C" float frexpf(float __x, int * __exponent) throw(); extern "C" float __frexpf(float __x, int * __exponent) throw(); 


extern "C" float ldexpf(float __x, int __exponent) throw(); extern "C" float __ldexpf(float __x, int __exponent) throw(); 


extern "C" float logf(float __x) throw(); extern "C" float __logf(float __x) throw(); 


extern "C" float log10f(float __x) throw(); extern "C" float __log10f(float __x) throw(); 


extern "C" float modff(float __x, float * __iptr) throw(); extern "C" float __modff(float __x, float * __iptr) throw(); 




extern "C" float exp10f(float __x) throw(); extern "C" float __exp10f(float __x) throw(); 

extern "C" float pow10f(float __x) throw(); extern "C" float __pow10f(float __x) throw(); 
# 129
extern "C" float expm1f(float __x) throw(); extern "C" float __expm1f(float __x) throw(); 


extern "C" float log1pf(float __x) throw(); extern "C" float __log1pf(float __x) throw(); 


extern "C" float logbf(float __x) throw(); extern "C" float __logbf(float __x) throw(); 
# 142
extern "C" float exp2f(float __x) throw(); extern "C" float __exp2f(float __x) throw(); 


extern "C" float log2f(float __x) throw(); extern "C" float __log2f(float __x) throw(); 
# 154
extern "C" float powf(float __x, float __y) throw(); extern "C" float __powf(float __x, float __y) throw(); 


extern "C" float sqrtf(float __x) throw(); extern "C" float __sqrtf(float __x) throw(); 
# 163
extern "C" float hypotf(float __x, float __y) throw(); extern "C" float __hypotf(float __x, float __y) throw(); 
# 170
extern "C" float cbrtf(float __x) throw(); extern "C" float __cbrtf(float __x) throw(); 
# 179
extern "C" float ceilf(float __x) throw() __attribute((const)); extern "C" float __ceilf(float __x) throw() __attribute((const)); 


extern "C" float fabsf(float __x) throw() __attribute((const)); extern "C" float __fabsf(float __x) throw() __attribute((const)); 


extern "C" float floorf(float __x) throw() __attribute((const)); extern "C" float __floorf(float __x) throw() __attribute((const)); 


extern "C" float fmodf(float __x, float __y) throw(); extern "C" float __fmodf(float __x, float __y) throw(); 




extern "C" int __isinff(float __value) throw() __attribute((const)); 


extern "C" int __finitef(float __value) throw() __attribute((const)); 
# 202
extern "C" int isinff(float __value) throw() __attribute((const)); 


extern "C" int finitef(float __value) throw() __attribute((const)); 


extern "C" float dremf(float __x, float __y) throw(); extern "C" float __dremf(float __x, float __y) throw(); 



extern "C" float significandf(float __x) throw(); extern "C" float __significandf(float __x) throw(); 
# 218
extern "C" float copysignf(float __x, float __y) throw() __attribute((const)); extern "C" float __copysignf(float __x, float __y) throw() __attribute((const)); 
# 225
extern "C" float nanf(const char * __tagb) throw() __attribute((const)); extern "C" float __nanf(const char * __tagb) throw() __attribute((const)); 
# 231
extern "C" int __isnanf(float __value) throw() __attribute((const)); 



extern "C" int isnanf(float __value) throw() __attribute((const)); 


extern "C" float j0f(float) throw(); extern "C" float __j0f(float) throw(); 
extern "C" float j1f(float) throw(); extern "C" float __j1f(float) throw(); 
extern "C" float jnf(int, float) throw(); extern "C" float __jnf(int, float) throw(); 
extern "C" float y0f(float) throw(); extern "C" float __y0f(float) throw(); 
extern "C" float y1f(float) throw(); extern "C" float __y1f(float) throw(); 
extern "C" float ynf(int, float) throw(); extern "C" float __ynf(int, float) throw(); 
# 250
extern "C" float erff(float) throw(); extern "C" float __erff(float) throw(); 
extern "C" float erfcf(float) throw(); extern "C" float __erfcf(float) throw(); 
extern "C" float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw(); 
# 259
extern "C" float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw(); 
# 265
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw(); 
# 272
extern "C" float lgammaf_r(float, int * __signgamp) throw(); extern "C" float __lgammaf_r(float, int * __signgamp) throw(); 
# 280
extern "C" float rintf(float __x) throw(); extern "C" float __rintf(float __x) throw(); 


extern "C" float nextafterf(float __x, float __y) throw() __attribute((const)); extern "C" float __nextafterf(float __x, float __y) throw() __attribute((const)); 

extern "C" float nexttowardf(float __x, long double __y) throw() __attribute((const)); extern "C" float __nexttowardf(float __x, long double __y) throw() __attribute((const)); 



extern "C" float remainderf(float __x, float __y) throw(); extern "C" float __remainderf(float __x, float __y) throw(); 



extern "C" float scalbnf(float __x, int __n) throw(); extern "C" float __scalbnf(float __x, int __n) throw(); 



extern "C" int ilogbf(float __x) throw(); extern "C" int __ilogbf(float __x) throw(); 




extern "C" float scalblnf(float __x, long __n) throw(); extern "C" float __scalblnf(float __x, long __n) throw(); 



extern "C" float nearbyintf(float __x) throw(); extern "C" float __nearbyintf(float __x) throw(); 



extern "C" float roundf(float __x) throw() __attribute((const)); extern "C" float __roundf(float __x) throw() __attribute((const)); 



extern "C" float truncf(float __x) throw() __attribute((const)); extern "C" float __truncf(float __x) throw() __attribute((const)); 




extern "C" float remquof(float __x, float __y, int * __quo) throw(); extern "C" float __remquof(float __x, float __y, int * __quo) throw(); 
# 326
extern "C" long lrintf(float __x) throw(); extern "C" long __lrintf(float __x) throw(); 
extern "C" long long llrintf(float __x) throw(); extern "C" long long __llrintf(float __x) throw(); 



extern "C" long lroundf(float __x) throw(); extern "C" long __lroundf(float __x) throw(); 
extern "C" long long llroundf(float __x) throw(); extern "C" long long __llroundf(float __x) throw(); 



extern "C" float fdimf(float __x, float __y) throw(); extern "C" float __fdimf(float __x, float __y) throw(); 


extern "C" float fmaxf(float __x, float __y) throw(); extern "C" float __fmaxf(float __x, float __y) throw(); 


extern "C" float fminf(float __x, float __y) throw(); extern "C" float __fminf(float __x, float __y) throw(); 



extern "C" int __fpclassifyf(float __value) throw()
 __attribute((const)); 


extern "C" int __signbitf(float __value) throw()
 __attribute((const)); 



extern "C" float fmaf(float __x, float __y, float __z) throw(); extern "C" float __fmaf(float __x, float __y, float __z) throw(); 
# 364
extern "C" float scalbf(float __x, float __n) throw(); extern "C" float __scalbf(float __x, float __n) throw(); 
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acosl(long double __x) throw(); extern "C" long double __acosl(long double __x) throw(); 

extern "C" long double asinl(long double __x) throw(); extern "C" long double __asinl(long double __x) throw(); 

extern "C" long double atanl(long double __x) throw(); extern "C" long double __atanl(long double __x) throw(); 

extern "C" long double atan2l(long double __y, long double __x) throw(); extern "C" long double __atan2l(long double __y, long double __x) throw(); 


extern "C" long double cosl(long double __x) throw(); extern "C" long double __cosl(long double __x) throw(); 

extern "C" long double sinl(long double __x) throw(); extern "C" long double __sinl(long double __x) throw(); 

extern "C" long double tanl(long double __x) throw(); extern "C" long double __tanl(long double __x) throw(); 




extern "C" long double coshl(long double __x) throw(); extern "C" long double __coshl(long double __x) throw(); 

extern "C" long double sinhl(long double __x) throw(); extern "C" long double __sinhl(long double __x) throw(); 

extern "C" long double tanhl(long double __x) throw(); extern "C" long double __tanhl(long double __x) throw(); 




extern "C" void sincosl(long double __x, long double * __sinx, long double * __cosx) throw(); extern "C" void __sincosl(long double __x, long double * __sinx, long double * __cosx) throw(); 
# 89
extern "C" long double acoshl(long double __x) throw(); extern "C" long double __acoshl(long double __x) throw(); 

extern "C" long double asinhl(long double __x) throw(); extern "C" long double __asinhl(long double __x) throw(); 

extern "C" long double atanhl(long double __x) throw(); extern "C" long double __atanhl(long double __x) throw(); 
# 101
extern "C" long double expl(long double __x) throw(); extern "C" long double __expl(long double __x) throw(); 


extern "C" long double frexpl(long double __x, int * __exponent) throw(); extern "C" long double __frexpl(long double __x, int * __exponent) throw(); 


extern "C" long double ldexpl(long double __x, int __exponent) throw(); extern "C" long double __ldexpl(long double __x, int __exponent) throw(); 


extern "C" long double logl(long double __x) throw(); extern "C" long double __logl(long double __x) throw(); 


extern "C" long double log10l(long double __x) throw(); extern "C" long double __log10l(long double __x) throw(); 


extern "C" long double modfl(long double __x, long double * __iptr) throw(); extern "C" long double __modfl(long double __x, long double * __iptr) throw(); 




extern "C" long double exp10l(long double __x) throw(); extern "C" long double __exp10l(long double __x) throw(); 

extern "C" long double pow10l(long double __x) throw(); extern "C" long double __pow10l(long double __x) throw(); 
# 129
extern "C" long double expm1l(long double __x) throw(); extern "C" long double __expm1l(long double __x) throw(); 


extern "C" long double log1pl(long double __x) throw(); extern "C" long double __log1pl(long double __x) throw(); 


extern "C" long double logbl(long double __x) throw(); extern "C" long double __logbl(long double __x) throw(); 
# 142
extern "C" long double exp2l(long double __x) throw(); extern "C" long double __exp2l(long double __x) throw(); 


extern "C" long double log2l(long double __x) throw(); extern "C" long double __log2l(long double __x) throw(); 
# 154
extern "C" long double powl(long double __x, long double __y) throw(); extern "C" long double __powl(long double __x, long double __y) throw(); 


extern "C" long double sqrtl(long double __x) throw(); extern "C" long double __sqrtl(long double __x) throw(); 
# 163
extern "C" long double hypotl(long double __x, long double __y) throw(); extern "C" long double __hypotl(long double __x, long double __y) throw(); 
# 170
extern "C" long double cbrtl(long double __x) throw(); extern "C" long double __cbrtl(long double __x) throw(); 
# 179
extern "C" long double ceill(long double __x) throw() __attribute((const)); extern "C" long double __ceill(long double __x) throw() __attribute((const)); 


extern "C" long double fabsl(long double __x) throw() __attribute((const)); extern "C" long double __fabsl(long double __x) throw() __attribute((const)); 


extern "C" long double floorl(long double __x) throw() __attribute((const)); extern "C" long double __floorl(long double __x) throw() __attribute((const)); 


extern "C" long double fmodl(long double __x, long double __y) throw(); extern "C" long double __fmodl(long double __x, long double __y) throw(); 




extern "C" int __isinfl(long double __value) throw() __attribute((const)); 


extern "C" int __finitel(long double __value) throw() __attribute((const)); 
# 202
extern "C" int isinfl(long double __value) throw() __attribute((const)); 


extern "C" int finitel(long double __value) throw() __attribute((const)); 


extern "C" long double dreml(long double __x, long double __y) throw(); extern "C" long double __dreml(long double __x, long double __y) throw(); 



extern "C" long double significandl(long double __x) throw(); extern "C" long double __significandl(long double __x) throw(); 
# 218
extern "C" long double copysignl(long double __x, long double __y) throw() __attribute((const)); extern "C" long double __copysignl(long double __x, long double __y) throw() __attribute((const)); 
# 225
extern "C" long double nanl(const char * __tagb) throw() __attribute((const)); extern "C" long double __nanl(const char * __tagb) throw() __attribute((const)); 
# 231
extern "C" int __isnanl(long double __value) throw() __attribute((const)); 



extern "C" int isnanl(long double __value) throw() __attribute((const)); 


extern "C" long double j0l(long double) throw(); extern "C" long double __j0l(long double) throw(); 
extern "C" long double j1l(long double) throw(); extern "C" long double __j1l(long double) throw(); 
extern "C" long double jnl(int, long double) throw(); extern "C" long double __jnl(int, long double) throw(); 
extern "C" long double y0l(long double) throw(); extern "C" long double __y0l(long double) throw(); 
extern "C" long double y1l(long double) throw(); extern "C" long double __y1l(long double) throw(); 
extern "C" long double ynl(int, long double) throw(); extern "C" long double __ynl(int, long double) throw(); 
# 250
extern "C" long double erfl(long double) throw(); extern "C" long double __erfl(long double) throw(); 
extern "C" long double erfcl(long double) throw(); extern "C" long double __erfcl(long double) throw(); 
extern "C" long double lgammal(long double) throw(); extern "C" long double __lgammal(long double) throw(); 
# 259
extern "C" long double tgammal(long double) throw(); extern "C" long double __tgammal(long double) throw(); 
# 265
extern "C" long double gammal(long double) throw(); extern "C" long double __gammal(long double) throw(); 
# 272
extern "C" long double lgammal_r(long double, int * __signgamp) throw(); extern "C" long double __lgammal_r(long double, int * __signgamp) throw(); 
# 280
extern "C" long double rintl(long double __x) throw(); extern "C" long double __rintl(long double __x) throw(); 


extern "C" long double nextafterl(long double __x, long double __y) throw() __attribute((const)); extern "C" long double __nextafterl(long double __x, long double __y) throw() __attribute((const)); 

extern "C" long double nexttowardl(long double __x, long double __y) throw() __attribute((const)); extern "C" long double __nexttowardl(long double __x, long double __y) throw() __attribute((const)); 



extern "C" long double remainderl(long double __x, long double __y) throw(); extern "C" long double __remainderl(long double __x, long double __y) throw(); 



extern "C" long double scalbnl(long double __x, int __n) throw(); extern "C" long double __scalbnl(long double __x, int __n) throw(); 



extern "C" int ilogbl(long double __x) throw(); extern "C" int __ilogbl(long double __x) throw(); 




extern "C" long double scalblnl(long double __x, long __n) throw(); extern "C" long double __scalblnl(long double __x, long __n) throw(); 



extern "C" long double nearbyintl(long double __x) throw(); extern "C" long double __nearbyintl(long double __x) throw(); 



extern "C" long double roundl(long double __x) throw() __attribute((const)); extern "C" long double __roundl(long double __x) throw() __attribute((const)); 



extern "C" long double truncl(long double __x) throw() __attribute((const)); extern "C" long double __truncl(long double __x) throw() __attribute((const)); 




extern "C" long double remquol(long double __x, long double __y, int * __quo) throw(); extern "C" long double __remquol(long double __x, long double __y, int * __quo) throw(); 
# 326
extern "C" long lrintl(long double __x) throw(); extern "C" long __lrintl(long double __x) throw(); 
extern "C" long long llrintl(long double __x) throw(); extern "C" long long __llrintl(long double __x) throw(); 



extern "C" long lroundl(long double __x) throw(); extern "C" long __lroundl(long double __x) throw(); 
extern "C" long long llroundl(long double __x) throw(); extern "C" long long __llroundl(long double __x) throw(); 



extern "C" long double fdiml(long double __x, long double __y) throw(); extern "C" long double __fdiml(long double __x, long double __y) throw(); 


extern "C" long double fmaxl(long double __x, long double __y) throw(); extern "C" long double __fmaxl(long double __x, long double __y) throw(); 


extern "C" long double fminl(long double __x, long double __y) throw(); extern "C" long double __fminl(long double __x, long double __y) throw(); 



extern "C" int __fpclassifyl(long double __value) throw()
 __attribute((const)); 


extern "C" int __signbitl(long double __value) throw()
 __attribute((const)); 



extern "C" long double fmal(long double __x, long double __y, long double __z) throw(); extern "C" long double __fmal(long double __x, long double __y, long double __z) throw(); 
# 364
extern "C" long double scalbl(long double __x, long double __n) throw(); extern "C" long double __scalbl(long double __x, long double __n) throw(); 
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; } 
# 199
enum { 
FP_NAN, 

FP_INFINITE, 

FP_ZERO, 

FP_SUBNORMAL, 

FP_NORMAL

}; 
# 298
extern "C" { typedef 
# 292
enum { 
_IEEE_ = (-1), 
_SVID_ = 0, 
_XOPEN_, 
_POSIX_, 
_ISOC_
} _LIB_VERSION_TYPE; }




extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; } 
# 314
extern "C" { struct __exception { 




int type; 
char *name; 
double arg1; 
double arg2; 
double retval; 
}; }


extern "C" int matherr(__exception * __exc) throw(); 
# 57 "/usr/include/sys/time.h" 3
extern "C" { struct timezone { 

int tz_minuteswest; 
int tz_dsttime; 
}; }

extern "C" { typedef struct timezone *__timezone_ptr_t; }
# 73
extern "C" int gettimeofday(timeval * __tv, __timezone_ptr_t __tz) throw()
 __attribute((__nonnull__(1))); 




extern "C" int settimeofday(const timeval * __tv, const struct timezone * __tz) throw()

 __attribute((__nonnull__(1))); 
# 87
extern "C" int adjtime(const timeval * __delta, timeval * __olddelta) throw(); 
# 93
enum __itimer_which { 


ITIMER_REAL, 


ITIMER_VIRTUAL, 



ITIMER_PROF

}; 



extern "C" { struct itimerval { 


timeval it_interval; 

timeval it_value; 
}; }
# 122
extern "C" { typedef int __itimer_which_t; }




extern "C" int getitimer(__itimer_which_t __which, itimerval * __value) throw(); 
# 133
extern "C" int setitimer(__itimer_which_t __which, const itimerval * __new, itimerval * __old) throw(); 
# 140
extern "C" int utimes(const char * __file, const timeval  __tvp[2]) throw()
 __attribute((__nonnull__(1))); 



extern "C" int lutimes(const char * __file, const timeval  __tvp[2]) throw()
 __attribute((__nonnull__(1))); 


extern "C" int futimes(int __fd, const timeval  __tvp[2]) throw(); 
# 156
extern "C" int futimesat(int __fd, const char * __file, const timeval  __tvp[2]) throw(); 
# 42 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/codecvt.h" 3
namespace std __attribute((__visibility__("default" ))) { 


class codecvt_base { 


public: enum result { 

ok, 
partial, 
error, 
noconv
}; 
}; 
# 66
template < typename _InternT, typename _ExternT, typename _StateT >
    class __codecvt_abstract_base
    : public locale :: facet, public codecvt_base
    {
    public :

      typedef codecvt_base :: result result;
      typedef _InternT intern_type;
      typedef _ExternT extern_type;
      typedef _StateT state_type;






































      result
      out ( state_type & __state, const intern_type * __from,
   const intern_type * __from_end, const intern_type * & __from_next,
   extern_type * __to, extern_type * __to_end,
   extern_type * & __to_next ) const
      {
 return this -> do_out ( __state, __from, __from_end, __from_next,
       __to, __to_end, __to_next );
      }






























      result
      unshift ( state_type & __state, extern_type * __to, extern_type * __to_end,
       extern_type * & __to_next ) const
      { return this -> do_unshift ( __state, __to, __to_end, __to_next ); }





































      result
      in ( state_type & __state, const extern_type * __from,
  const extern_type * __from_end, const extern_type * & __from_next,
  intern_type * __to, intern_type * __to_end,
  intern_type * & __to_next ) const
      {
 return this -> do_in ( __state, __from, __from_end, __from_next,
      __to, __to_end, __to_next );
      }

      int
      encoding ( ) const throw ( )
      { return this -> do_encoding ( ); }

      bool
      always_noconv ( ) const throw ( )
      { return this -> do_always_noconv ( ); }

      int
      length ( state_type & __state, const extern_type * __from,
      const extern_type * __end, size_t __max ) const
      { return this -> do_length ( __state, __from, __end, __max ); }

      int
      max_length ( ) const throw ( )
      { return this -> do_max_length ( ); }

    protected :
      explicit
      __codecvt_abstract_base ( size_t __refs = 0 ) : locale :: facet ( __refs ) { }

      virtual
      ~ __codecvt_abstract_base ( ) { }








      virtual result
      do_out ( state_type & __state, const intern_type * __from,
      const intern_type * __from_end, const intern_type * & __from_next,
      extern_type * __to, extern_type * __to_end,
      extern_type * & __to_next ) const = 0;

      virtual result
      do_unshift ( state_type & __state, extern_type * __to,
   extern_type * __to_end, extern_type * & __to_next ) const = 0;

      virtual result
      do_in ( state_type & __state, const extern_type * __from,
     const extern_type * __from_end, const extern_type * & __from_next,
     intern_type * __to, intern_type * __to_end,
     intern_type * & __to_next ) const = 0;

      virtual int
      do_encoding ( ) const throw ( ) = 0;

      virtual bool
      do_always_noconv ( ) const throw ( ) = 0;

      virtual int
      do_length ( state_type &, const extern_type * __from,
  const extern_type * __end, size_t __max ) const = 0;

      virtual int
      do_max_length ( ) const throw ( ) = 0;
    };



template < typename _InternT, typename _ExternT, typename _StateT >
    class codecvt
    : public __codecvt_abstract_base < _InternT, _ExternT, _StateT >
    {
    public :

      typedef codecvt_base :: result result;
      typedef _InternT intern_type;
      typedef _ExternT extern_type;
      typedef _StateT state_type;

    protected :
      __c_locale _M_c_locale_codecvt;

    public :
      static locale :: id id;

      explicit
      codecvt ( size_t __refs = 0 )
      : __codecvt_abstract_base < _InternT, _ExternT, _StateT > ( __refs ) { }

      explicit
      codecvt ( __c_locale __cloc, size_t __refs = 0 );

    protected :
      virtual
      ~ codecvt ( ) { }

      virtual result
      do_out ( state_type & __state, const intern_type * __from,
      const intern_type * __from_end, const intern_type * & __from_next,
      extern_type * __to, extern_type * __to_end,
      extern_type * & __to_next ) const;

      virtual result
      do_unshift ( state_type & __state, extern_type * __to,
   extern_type * __to_end, extern_type * & __to_next ) const;

      virtual result
      do_in ( state_type & __state, const extern_type * __from,
     const extern_type * __from_end, const extern_type * & __from_next,
     intern_type * __to, intern_type * __to_end,
     intern_type * & __to_next ) const;

      virtual int
      do_encoding ( ) const throw ( );

      virtual bool
      do_always_noconv ( ) const throw ( );

      virtual int
      do_length ( state_type &, const extern_type * __from,
  const extern_type * __end, size_t __max ) const;

      virtual int
      do_max_length ( ) const throw ( );
    };

template < typename _InternT, typename _ExternT, typename _StateT >
    locale :: id codecvt < _InternT, _ExternT, _StateT > :: id;



template<> class codecvt< char, char, __mbstate_t>  : public __codecvt_abstract_base< char, char, __mbstate_t>  { 




public: typedef char intern_type; 
typedef char extern_type; 
typedef mbstate_t state_type; 


protected: __c_locale _M_c_locale_codecvt; 


public: static locale::id id; 


explicit codecvt(size_t __refs = (0)); 


explicit codecvt(__c_locale __cloc, size_t __refs = (0)); 



protected: virtual ~codecvt(); 


virtual result do_out(state_type & __state, const intern_type * __from, const intern_type * __from_end, const intern_type *& __from_next, extern_type * __to, extern_type * __to_end, extern_type *& __to_next) const; 
# 362
virtual result do_unshift(state_type & __state, extern_type * __to, extern_type * __to_end, extern_type *& __to_next) const; 



virtual result do_in(state_type & __state, const extern_type * __from, const extern_type * __from_end, const extern_type *& __from_next, intern_type * __to, intern_type * __to_end, intern_type *& __to_next) const; 
# 372
virtual int do_encoding() const throw(); 


virtual bool do_always_noconv() const throw(); 


virtual int do_length(state_type &, const extern_type * __from, const extern_type * __end, size_t __max) const; 



virtual int do_max_length() const throw(); 
}; 




template<> class codecvt< wchar_t, char, __mbstate_t>  : public __codecvt_abstract_base< wchar_t, char, __mbstate_t>  { 




public: typedef wchar_t intern_type; 
typedef char extern_type; 
typedef mbstate_t state_type; 


protected: __c_locale _M_c_locale_codecvt; 


public: static locale::id id; 


explicit codecvt(size_t __refs = (0)); 


explicit codecvt(__c_locale __cloc, size_t __refs = (0)); 



protected: virtual ~codecvt(); 


virtual result do_out(state_type & __state, const intern_type * __from, const intern_type * __from_end, const intern_type *& __from_next, extern_type * __to, extern_type * __to_end, extern_type *& __to_next) const; 
# 420
virtual result do_unshift(state_type & __state, extern_type * __to, extern_type * __to_end, extern_type *& __to_next) const; 




virtual result do_in(state_type & __state, const extern_type * __from, const extern_type * __from_end, const extern_type *& __from_next, intern_type * __to, intern_type * __to_end, intern_type *& __to_next) const; 
# 432
virtual int do_encoding() const throw(); 


virtual bool do_always_noconv() const throw(); 


virtual int do_length(state_type &, const extern_type * __from, const extern_type * __end, size_t __max) const; 



virtual int do_max_length() const throw(); 
}; 



template < typename _InternT, typename _ExternT, typename _StateT >
    class codecvt_byname : public codecvt < _InternT, _ExternT, _StateT >
    {
    public :
      explicit
      codecvt_byname ( const char * __s, size_t __refs = 0 )
      : codecvt < _InternT, _ExternT, _StateT > ( __refs )
      {
 if ( __builtin_strcmp ( __s, "C" ) != 0
     && __builtin_strcmp ( __s, "POSIX" ) != 0 )
   {
     this -> _S_destroy_c_locale ( this -> _M_c_locale_codecvt );
     this -> _S_create_c_locale ( this -> _M_c_locale_codecvt, __s );
   }
      }

    protected :
      virtual
      ~ codecvt_byname ( ) { }
    };
# 472
extern template class codecvt_byname< char, char, __mbstate_t> ;

extern template const codecvt< char, char, __mbstate_t>  &use_facet< codecvt< char, char, __mbstate_t> > (const locale &);



extern template bool has_facet< codecvt< char, char, __mbstate_t> > (const locale &) throw();




extern template class codecvt_byname< wchar_t, char, __mbstate_t> ;

extern template const codecvt< wchar_t, char, __mbstate_t>  &use_facet< codecvt< wchar_t, char, __mbstate_t> > (const locale &);



extern template bool has_facet< codecvt< wchar_t, char, __mbstate_t> > (const locale &) throw();
# 495
}
# 93 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/cstdio" 3
namespace std __attribute((__visibility__("default" ))) { 

using ::FILE;
using ::fpos_t;

using ::clearerr;
using ::fclose;
using ::feof;
using ::ferror;
using ::fflush;
using ::fgetc;
using ::fgetpos;
using ::fgets;
using ::fopen;
using ::fprintf;
using ::fputc;
using ::fputs;
using ::fread;
using ::freopen;
using ::fscanf;
using ::fseek;
using ::fsetpos;
using ::ftell;
using ::fwrite;
using ::getc;
using ::getchar;
using ::gets;
using ::perror;
using ::printf;
using ::putc;
using ::putchar;
using ::puts;
using ::remove;
using ::rename;
using ::rewind;
using ::scanf;
using ::setbuf;
using ::setvbuf;
using ::sprintf;
using ::sscanf;
using ::tmpfile;
using ::tmpnam;
using ::ungetc;
using ::vfprintf;
using ::vprintf;
using ::vsprintf;

}
# 150
namespace __gnu_cxx __attribute((__visibility__("default" ))) { 
# 165
using ::snprintf;
using ::vfscanf;
using ::vscanf;
using ::vsnprintf;
using ::vsscanf;


}

namespace std __attribute((__visibility__("default" ))) { 

using __gnu_cxx::snprintf;
using __gnu_cxx::vfscanf;
using __gnu_cxx::vscanf;
using __gnu_cxx::vsnprintf;
using __gnu_cxx::vsscanf;

}
# 40 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/c++io.h" 3
namespace std __attribute((__visibility__("default" ))) { 

typedef __gthread_mutex_t __c_lock; 


typedef FILE __c_file; 

}
# 44 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/x86_64-redhat-linux/bits/basic_file.h" 3
namespace std __attribute((__visibility__("default" ))) { 


template < typename _CharT >
    class __basic_file;



template<> class __basic_file< char>  { 


__c_file *_M_cfile; 


bool _M_cfile_created; 


public: __basic_file(__c_lock * __lock = 0); 


std::__basic_file< char>  *open(const char * __name, ios_base::openmode __mode, int __prot = (436)); 


std::__basic_file< char>  *sys_open(__c_file * __file, ios_base::openmode); 


std::__basic_file< char>  *sys_open(int __fd, ios_base::openmode __mode); 


std::__basic_file< char>  *close(); 


bool is_open() const; 


int fd(); 


__c_file *file(); 

~__basic_file(); 


streamsize xsputn(const char * __s, streamsize __n); 


streamsize xsputn_2(const char * __s1, streamsize __n1, const char * __s2, streamsize __n2); 



streamsize xsgetn(char * __s, streamsize __n); 


streamoff seekoff(streamoff __off, ios_base::seekdir __way); 


int sync(); 


streamsize showmanyc(); 
}; 

}
# 49 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/fstream" 3
namespace std __attribute((__visibility__("default" ))) { 
# 66
template < typename _CharT, typename _Traits >
    class basic_filebuf : public basic_streambuf < _CharT, _Traits >
    {
    public :

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type :: int_type int_type;
      typedef typename traits_type :: pos_type pos_type;
      typedef typename traits_type :: off_type off_type;

      typedef basic_streambuf < char_type, traits_type > __streambuf_type;
      typedef basic_filebuf < char_type, traits_type > __filebuf_type;
      typedef __basic_file < char > __file_type;
      typedef typename traits_type :: state_type __state_type;
      typedef codecvt < char_type, char, __state_type > __codecvt_type;

      friend class ios_base;

    protected :


      __c_lock _M_lock;


      __file_type _M_file;


      ios_base :: openmode _M_mode;


      __state_type _M_state_beg;




      __state_type _M_state_cur;



      __state_type _M_state_last;


      char_type * _M_buf;






      size_t _M_buf_size;


      bool _M_buf_allocated;








      bool _M_reading;
      bool _M_writing;







      char_type _M_pback;
      char_type * _M_pback_cur_save;
      char_type * _M_pback_end_save;
      bool _M_pback_init;



      const __codecvt_type * _M_codecvt;






      char * _M_ext_buf;




      streamsize _M_ext_buf_size;






      const char * _M_ext_next;
      char * _M_ext_end;






      void
      _M_create_pback ( )
      {
 if ( ! _M_pback_init )
   {
     _M_pback_cur_save = this -> gptr ( );
     _M_pback_end_save = this -> egptr ( );
     this -> setg ( & _M_pback, & _M_pback, & _M_pback + 1 );
     _M_pback_init = true;
   }
      }






      void
      _M_destroy_pback ( ) throw ( )
      {
 if ( _M_pback_init )
   {

     _M_pback_cur_save += this -> gptr ( ) != this -> eback ( );
     this -> setg ( _M_buf, _M_pback_cur_save, _M_pback_end_save );
     _M_pback_init = false;
   }
      }

    public :







      basic_filebuf ( );




      virtual
      ~ basic_filebuf ( )
      { this -> close ( ); }





      bool
      is_open ( ) const throw ( )
      { return _M_file . is_open ( ); }








































      __filebuf_type *
      open ( const char * __s, ios_base :: openmode __mode );
























      __filebuf_type *
      close ( );

    protected :
      void
      _M_allocate_internal_buffer ( );

      void
      _M_destroy_internal_buffer ( ) throw ( );


      virtual streamsize
      showmanyc ( );






      virtual int_type
      underflow ( );

      virtual int_type
      pbackfail ( int_type __c = _Traits :: eof ( ) );








      virtual int_type
      overflow ( int_type __c = _Traits :: eof ( ) );



      bool
      _M_convert_to_external ( char_type *, streamsize );













      virtual __streambuf_type *
      setbuf ( char_type * __s, streamsize __n );

      virtual pos_type
      seekoff ( off_type __off, ios_base :: seekdir __way,
       ios_base :: openmode __mode = ios_base :: in | ios_base :: out );

      virtual pos_type
      seekpos ( pos_type __pos,
       ios_base :: openmode __mode = ios_base :: in | ios_base :: out );


      pos_type
      _M_seek ( off_type __off, ios_base :: seekdir __way, __state_type __state );

      virtual int
      sync ( );

      virtual void
      imbue ( const locale & __loc );

      virtual streamsize
      xsgetn ( char_type * __s, streamsize __n );

      virtual streamsize
      xsputn ( const char_type * __s, streamsize __n );


      bool
      _M_terminate_output ( );













      void
      _M_set_buffer ( streamsize __off )
      {
  const bool __testin = _M_mode & ios_base :: in;
  const bool __testout = _M_mode & ios_base :: out;

 if ( __testin && __off > 0 )
   this -> setg ( _M_buf, _M_buf, _M_buf + __off );
 else
   this -> setg ( _M_buf, _M_buf, _M_buf );

 if ( __testout && __off == 0 && _M_buf_size > 1 )
   this -> setp ( _M_buf, _M_buf + _M_buf_size - 1 );
 else
   this -> setp ( __null, __null );
      }
    };
# 413
template < typename _CharT, typename _Traits >
    class basic_ifstream : public basic_istream < _CharT, _Traits >
    {
    public :

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type :: int_type int_type;
      typedef typename traits_type :: pos_type pos_type;
      typedef typename traits_type :: off_type off_type;


      typedef basic_filebuf < char_type, traits_type > __filebuf_type;
      typedef basic_istream < char_type, traits_type > __istream_type;

    private :
      __filebuf_type _M_filebuf;

    public :








      basic_ifstream ( ) : __istream_type ( ), _M_filebuf ( )
      { this -> init ( & _M_filebuf ); }











      explicit
      basic_ifstream ( const char * __s, ios_base :: openmode __mode = ios_base :: in )
      : __istream_type ( ), _M_filebuf ( )
      {
 this -> init ( & _M_filebuf );
 this -> open ( __s, __mode );
      }

























      ~ basic_ifstream ( )
      { }








      __filebuf_type *
      rdbuf ( ) const
      { return const_cast < __filebuf_type * > ( & _M_filebuf ); }





      bool
      is_open ( )
      { return _M_filebuf . is_open ( ); }



      bool
      is_open ( ) const
      { return _M_filebuf . is_open ( ); }












      void
      open ( const char * __s, ios_base :: openmode __mode = ios_base :: in )
      {
 if ( ! _M_filebuf . open ( __s, __mode | ios_base :: in ) )
   this -> setstate ( ios_base :: failbit );
 else


   this -> clear ( );
      }




























      void
      close ( )
      {
 if ( ! _M_filebuf . close ( ) )
   this -> setstate ( ios_base :: failbit );
      }
    };
# 581
template < typename _CharT, typename _Traits >
    class basic_ofstream : public basic_ostream < _CharT, _Traits >
    {
    public :

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type :: int_type int_type;
      typedef typename traits_type :: pos_type pos_type;
      typedef typename traits_type :: off_type off_type;


      typedef basic_filebuf < char_type, traits_type > __filebuf_type;
      typedef basic_ostream < char_type, traits_type > __ostream_type;

    private :
      __filebuf_type _M_filebuf;

    public :








      basic_ofstream ( ) : __ostream_type ( ), _M_filebuf ( )
      { this -> init ( & _M_filebuf ); }












      explicit
      basic_ofstream ( const char * __s,
       ios_base :: openmode __mode = ios_base :: out | ios_base :: trunc )
      : __ostream_type ( ), _M_filebuf ( )
      {
 this -> init ( & _M_filebuf );
 this -> open ( __s, __mode );
      }


























      ~ basic_ofstream ( )
      { }








      __filebuf_type *
      rdbuf ( ) const
      { return const_cast < __filebuf_type * > ( & _M_filebuf ); }





      bool
      is_open ( )
      { return _M_filebuf . is_open ( ); }



      bool
      is_open ( ) const
      { return _M_filebuf . is_open ( ); }












      void
      open ( const char * __s,
    ios_base :: openmode __mode = ios_base :: out | ios_base :: trunc )
      {
 if ( ! _M_filebuf . open ( __s, __mode | ios_base :: out ) )
   this -> setstate ( ios_base :: failbit );
 else


   this -> clear ( );
      }





























      void
      close ( )
      {
 if ( ! _M_filebuf . close ( ) )
   this -> setstate ( ios_base :: failbit );
      }
    };
# 754
template < typename _CharT, typename _Traits >
    class basic_fstream : public basic_iostream < _CharT, _Traits >
    {
    public :

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type :: int_type int_type;
      typedef typename traits_type :: pos_type pos_type;
      typedef typename traits_type :: off_type off_type;


      typedef basic_filebuf < char_type, traits_type > __filebuf_type;
      typedef basic_ios < char_type, traits_type > __ios_type;
      typedef basic_iostream < char_type, traits_type > __iostream_type;

    private :
      __filebuf_type _M_filebuf;

    public :








      basic_fstream ( )
      : __iostream_type ( ), _M_filebuf ( )
      { this -> init ( & _M_filebuf ); }









      explicit
      basic_fstream ( const char * __s,
      ios_base :: openmode __mode = ios_base :: in | ios_base :: out )
      : __iostream_type ( __null ), _M_filebuf ( )
      {
 this -> init ( & _M_filebuf );
 this -> open ( __s, __mode );
      }























      ~ basic_fstream ( )
      { }








      __filebuf_type *
      rdbuf ( ) const
      { return const_cast < __filebuf_type * > ( & _M_filebuf ); }





      bool
      is_open ( )
      { return _M_filebuf . is_open ( ); }



      bool
      is_open ( ) const
      { return _M_filebuf . is_open ( ); }












      void
      open ( const char * __s,
    ios_base :: openmode __mode = ios_base :: in | ios_base :: out )
      {
 if ( ! _M_filebuf . open ( __s, __mode ) )
   this -> setstate ( ios_base :: failbit );
 else


   this -> clear ( );
      }





























      void
      close ( )
      {
 if ( ! _M_filebuf . close ( ) )
   this -> setstate ( ios_base :: failbit );
      }
    };

}
# 43 "/usr/lib/gcc/x86_64-redhat-linux/4.4.7/../../../../include/c++/4.4.7/bits/fstream.tcc" 3
namespace std __attribute((__visibility__("default" ))) { 

template < typename _CharT, typename _Traits >
    void
    basic_filebuf < _CharT, _Traits > ::
    _M_allocate_internal_buffer ( )
    {


      if ( ! _M_buf_allocated && ! _M_buf )
 {
   _M_buf = new char_type [ _M_buf_size ];
   _M_buf_allocated = true;
 }
    }

template < typename _CharT, typename _Traits >
    void
    basic_filebuf < _CharT, _Traits > ::
    _M_destroy_internal_buffer ( ) throw ( )
    {
      if ( _M_buf_allocated )
 {
   delete [ ] _M_buf;
   _M_buf = __null;
   _M_buf_allocated = false;
 }
      delete [ ] _M_ext_buf;
      _M_ext_buf = __null;
      _M_ext_buf_size = 0;
      _M_ext_next = __null;
      _M_ext_end = __null;
    }

template < typename _CharT, typename _Traits >
    basic_filebuf < _CharT, _Traits > ::
    basic_filebuf ( ) : __streambuf_type ( ), _M_lock ( ), _M_file ( & _M_lock ),
    _M_mode ( ios_base :: openmode ( 0 ) ), _M_state_beg ( ), _M_state_cur ( ),
    _M_state_last ( ), _M_buf ( __null ), _M_buf_size ( 8192 ),
    _M_buf_allocated ( false ), _M_reading ( false ), _M_writing ( false ), _M_pback ( ),
    _M_pback_cur_save ( 0 ), _M_pback_end_save ( 0 ), _M_pback_init ( false ),
    _M_codecvt ( 0 ), _M_ext_buf ( 0 ), _M_ext_buf_size ( 0 ), _M_ext_next ( 0 ),
    _M_ext_end ( 0 )
    {
      if ( has_facet < __codecvt_type > ( this -> _M_buf_locale ) )
 _M_codecvt = & use_facet < __codecvt_type > ( this -> _M_buf_locale );
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: __filebuf_type *
    basic_filebuf < _CharT, _Traits > ::
    open ( const char * __s, ios_base :: openmode __mode )
    {
      __filebuf_type * __ret = __null;
      if ( ! this -> is_open ( ) )
 {
   _M_file . open ( __s, __mode );
   if ( this -> is_open ( ) )
     {
       _M_allocate_internal_buffer ( );
       _M_mode = __mode;


       _M_reading = false;
       _M_writing = false;
       _M_set_buffer ( - 1 );


       _M_state_last = _M_state_cur = _M_state_beg;


       if ( ( __mode & ios_base :: ate )
    && this -> seekoff ( 0, ios_base :: end, __mode )
    == pos_type ( off_type ( - 1 ) ) )
  this -> close ( );
       else
  __ret = this;
     }
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: __filebuf_type *
    basic_filebuf < _CharT, _Traits > ::
    close ( )
    {
      if ( ! this -> is_open ( ) )
 return __null;

      bool __testfail = false;
      {

 struct __close_sentry
 {
   basic_filebuf * __fb;
   __close_sentry ( basic_filebuf * __fbi ) : __fb ( __fbi ) { }
   ~ __close_sentry ( )
   {
     __fb -> _M_mode = ios_base :: openmode ( 0 );
     __fb -> _M_pback_init = false;
     __fb -> _M_destroy_internal_buffer ( );
     __fb -> _M_reading = false;
     __fb -> _M_writing = false;
     __fb -> _M_set_buffer ( - 1 );
     __fb -> _M_state_last = __fb -> _M_state_cur = __fb -> _M_state_beg;
   }
 } __cs ( this );

 try
   {
     if ( ! _M_terminate_output ( ) )
       __testfail = true;
   }
 catch ( __cxxabiv1 :: __forced_unwind & )
   {
     _M_file . close ( );
     throw;
   }
 catch ( ... )
   { __testfail = true; }
      }

      if ( ! _M_file . close ( ) )
 __testfail = true;

      if ( __testfail )
 return __null;
      else
 return this;
    }

template < typename _CharT, typename _Traits >
    streamsize
    basic_filebuf < _CharT, _Traits > ::
    showmanyc ( )
    {
      streamsize __ret = - 1;
      const bool __testin = _M_mode & ios_base :: in;
      if ( __testin && this -> is_open ( ) )
 {


   __ret = this -> egptr ( ) - this -> gptr ( );







   if ( __check_facet ( _M_codecvt ) . encoding ( ) >= 0 )

     __ret += _M_file . showmanyc ( ) / _M_codecvt -> max_length ( );
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: int_type
    basic_filebuf < _CharT, _Traits > ::
    underflow ( )
    {
      int_type __ret = traits_type :: eof ( );
      const bool __testin = _M_mode & ios_base :: in;
      if ( __testin && ! _M_writing )
 {



   _M_destroy_pback ( );

   if ( this -> gptr ( ) < this -> egptr ( ) )
     return traits_type :: to_int_type ( * this -> gptr ( ) );


   const size_t __buflen = _M_buf_size > 1 ? _M_buf_size - 1 : 1;


   bool __got_eof = false;

   streamsize __ilen = 0;
   codecvt_base :: result __r = codecvt_base :: ok;
   if ( __check_facet ( _M_codecvt ) . always_noconv ( ) )
     {
       __ilen = _M_file . xsgetn ( reinterpret_cast < char * > ( this -> eback ( ) ),
          __buflen );
       if ( __ilen == 0 )
  __got_eof = true;
     }
   else
     {


       const int __enc = _M_codecvt -> encoding ( );
       streamsize __blen;
       streamsize __rlen;
       if ( __enc > 0 )
  __blen = __rlen = __buflen * __enc;
       else
  {
    __blen = __buflen + _M_codecvt -> max_length ( ) - 1;
    __rlen = __buflen;
  }
       const streamsize __remainder = _M_ext_end - _M_ext_next;
       __rlen = __rlen > __remainder ? __rlen - __remainder : 0;



       if ( _M_reading && this -> egptr ( ) == this -> eback ( ) && __remainder )
  __rlen = 0;



       if ( _M_ext_buf_size < __blen )
  {
    char * __buf = new char [ __blen ];
    if ( __remainder )
      __builtin_memcpy ( __buf, _M_ext_next, __remainder );

    delete [ ] _M_ext_buf;
    _M_ext_buf = __buf;
    _M_ext_buf_size = __blen;
  }
       else if ( __remainder )
  __builtin_memmove ( _M_ext_buf, _M_ext_next, __remainder );

       _M_ext_next = _M_ext_buf;
       _M_ext_end = _M_ext_buf + __remainder;
       _M_state_last = _M_state_cur;

       do
  {
    if ( __rlen > 0 )
      {



        if ( _M_ext_end - _M_ext_buf + __rlen > _M_ext_buf_size )
   {
     __throw_ios_failure ( ( "basic_filebuf::underflow codecvt::max_length() is not valid" )

                          );
   }
        streamsize __elen = _M_file . xsgetn ( _M_ext_end, __rlen );
        if ( __elen == 0 )
   __got_eof = true;
        else if ( __elen == - 1 )
   break;
        _M_ext_end += __elen;
      }

    char_type * __iend = this -> eback ( );
    if ( _M_ext_next < _M_ext_end )
      __r = _M_codecvt -> in ( _M_state_cur, _M_ext_next,
      _M_ext_end, _M_ext_next,
      this -> eback ( ),
      this -> eback ( ) + __buflen, __iend );
    if ( __r == codecvt_base :: noconv )
      {
        size_t __avail = _M_ext_end - _M_ext_buf;
        __ilen = std :: min ( __avail, __buflen );
        traits_type :: copy ( this -> eback ( ),
     reinterpret_cast < char_type * >
     ( _M_ext_buf ), __ilen );
        _M_ext_next = _M_ext_buf + __ilen;
      }
    else
      __ilen = __iend - this -> eback ( );




    if ( __r == codecvt_base :: error )
      break;

    __rlen = 1;
  }
       while ( __ilen == 0 && ! __got_eof );
     }

   if ( __ilen > 0 )
     {
       _M_set_buffer ( __ilen );
       _M_reading = true;
       __ret = traits_type :: to_int_type ( * this -> gptr ( ) );
     }
   else if ( __got_eof )
     {



       _M_set_buffer ( - 1 );
       _M_reading = false;


       if ( __r == codecvt_base :: partial )
  __throw_ios_failure ( ( "basic_filebuf::underflow incomplete character in file" )
                                       );
     }
   else if ( __r == codecvt_base :: error )
     __throw_ios_failure ( ( "basic_filebuf::underflow invalid byte sequence in file" )
                                    );
   else
     __throw_ios_failure ( ( "basic_filebuf::underflow error reading the file" )
                             );
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: int_type
    basic_filebuf < _CharT, _Traits > ::
    pbackfail ( int_type __i )
    {
      int_type __ret = traits_type :: eof ( );
      const bool __testin = _M_mode & ios_base :: in;
      if ( __testin && ! _M_writing )
 {


   const bool __testpb = _M_pback_init;
   const bool __testeof = traits_type :: eq_int_type ( __i, __ret );
   int_type __tmp;
   if ( this -> eback ( ) < this -> gptr ( ) )
     {
       this -> gbump ( - 1 );
       __tmp = traits_type :: to_int_type ( * this -> gptr ( ) );
     }
   else if ( this -> seekoff ( - 1, ios_base :: cur ) != pos_type ( off_type ( - 1 ) ) )
     {
       __tmp = this -> underflow ( );
       if ( traits_type :: eq_int_type ( __tmp, __ret ) )
  return __ret;
     }
   else
     {





       return __ret;
     }



   if ( ! __testeof && traits_type :: eq_int_type ( __i, __tmp ) )
     __ret = __i;
   else if ( __testeof )
     __ret = traits_type :: not_eof ( __i );
   else if ( ! __testpb )
     {
       _M_create_pback ( );
       _M_reading = true;
       * this -> gptr ( ) = traits_type :: to_char_type ( __i );
       __ret = __i;
     }
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: int_type
    basic_filebuf < _CharT, _Traits > ::
    overflow ( int_type __c )
    {
      int_type __ret = traits_type :: eof ( );
      const bool __testeof = traits_type :: eq_int_type ( __c, __ret );
      const bool __testout = _M_mode & ios_base :: out;
      if ( __testout && ! _M_reading )
 {
   if ( this -> pbase ( ) < this -> pptr ( ) )
     {

       if ( ! __testeof )
  {
    * this -> pptr ( ) = traits_type :: to_char_type ( __c );
    this -> pbump ( 1 );
  }



       if ( _M_convert_to_external ( this -> pbase ( ),
      this -> pptr ( ) - this -> pbase ( ) ) )
  {
    _M_set_buffer ( 0 );
    __ret = traits_type :: not_eof ( __c );
  }
     }
   else if ( _M_buf_size > 1 )
     {



       _M_set_buffer ( 0 );
       _M_writing = true;
       if ( ! __testeof )
  {
    * this -> pptr ( ) = traits_type :: to_char_type ( __c );
    this -> pbump ( 1 );
  }
       __ret = traits_type :: not_eof ( __c );
     }
   else
     {

       char_type __conv = traits_type :: to_char_type ( __c );
       if ( __testeof || _M_convert_to_external ( & __conv, 1 ) )
  {
    _M_writing = true;
    __ret = traits_type :: not_eof ( __c );
  }
     }
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    bool
    basic_filebuf < _CharT, _Traits > ::
    _M_convert_to_external ( _CharT * __ibuf, streamsize __ilen )
    {

      streamsize __elen;
      streamsize __plen;
      if ( __check_facet ( _M_codecvt ) . always_noconv ( ) )
 {
   __elen = _M_file . xsputn ( reinterpret_cast < char * > ( __ibuf ), __ilen );
   __plen = __ilen;
 }
      else
 {


   streamsize __blen = __ilen * _M_codecvt -> max_length ( );
   char * __buf = static_cast < char * > ( __builtin_alloca ( __blen ) );

   char * __bend;
   const char_type * __iend;
   codecvt_base :: result __r;
   __r = _M_codecvt -> out ( _M_state_cur, __ibuf, __ibuf + __ilen,
    __iend, __buf, __buf + __blen, __bend );

   if ( __r == codecvt_base :: ok || __r == codecvt_base :: partial )
     __blen = __bend - __buf;
   else if ( __r == codecvt_base :: noconv )
     {

       __buf = reinterpret_cast < char * > ( __ibuf );
       __blen = __ilen;
     }
   else
     __throw_ios_failure ( ( "basic_filebuf::_M_convert_to_external conversion error" )
                           );

   __elen = _M_file . xsputn ( __buf, __blen );
   __plen = __blen;


   if ( __r == codecvt_base :: partial && __elen == __plen )
     {
       const char_type * __iresume = __iend;
       streamsize __rlen = this -> pptr ( ) - __iend;
       __r = _M_codecvt -> out ( _M_state_cur, __iresume,
        __iresume + __rlen, __iend, __buf,
        __buf + __blen, __bend );
       if ( __r != codecvt_base :: error )
  {
    __rlen = __bend - __buf;
    __elen = _M_file . xsputn ( __buf, __rlen );
    __plen = __rlen;
  }
       else
  __throw_ios_failure ( ( "basic_filebuf::_M_convert_to_external conversion error" )
                        );
     }
 }
      return __elen == __plen;
    }

template < typename _CharT, typename _Traits >
     streamsize
     basic_filebuf < _CharT, _Traits > ::
     xsgetn ( _CharT * __s, streamsize __n )
     {

       streamsize __ret = 0;
       if ( _M_pback_init )
  {
    if ( __n > 0 && this -> gptr ( ) == this -> eback ( ) )
      {
        * __s ++ = * this -> gptr ( );
        this -> gbump ( 1 );
        __ret = 1;
        -- __n;
      }
    _M_destroy_pback ( );
  }




       const bool __testin = _M_mode & ios_base :: in;
       const streamsize __buflen = _M_buf_size > 1 ? _M_buf_size - 1 : 1;

       if ( __n > __buflen && __check_facet ( _M_codecvt ) . always_noconv ( )
    && __testin && ! _M_writing )
  {

    const streamsize __avail = this -> egptr ( ) - this -> gptr ( );
    if ( __avail != 0 )
      {
        if ( __avail == 1 )
   * __s = * this -> gptr ( );
        else
   traits_type :: copy ( __s, this -> gptr ( ), __avail );
        __s += __avail;
        this -> gbump ( __avail );
        __ret += __avail;
        __n -= __avail;
      }



    streamsize __len;
    for (;; )
      {
        __len = _M_file . xsgetn ( reinterpret_cast < char * > ( __s ),
          __n );
        if ( __len == - 1 )
   __throw_ios_failure ( ( "basic_filebuf::xsgetn error reading the file" )
                               );
        if ( __len == 0 )
   break;

        __n -= __len;
        __ret += __len;
        if ( __n == 0 )
   break;

        __s += __len;
      }

    if ( __n == 0 )
      {
        _M_set_buffer ( 0 );
        _M_reading = true;
      }
    else if ( __len == 0 )
      {



        _M_set_buffer ( - 1 );
        _M_reading = false;
      }
  }
       else
  __ret += __streambuf_type :: xsgetn ( __s, __n );

       return __ret;
     }

template < typename _CharT, typename _Traits >
     streamsize
     basic_filebuf < _CharT, _Traits > ::
     xsputn ( const _CharT * __s, streamsize __n )
     {



       streamsize __ret = 0;
       const bool __testout = _M_mode & ios_base :: out;
       if ( __check_facet ( _M_codecvt ) . always_noconv ( )
    && __testout && ! _M_reading )
 {

   const streamsize __chunk = 1UL << 10;
   streamsize __bufavail = this -> epptr ( ) - this -> pptr ( );


   if ( ! _M_writing && _M_buf_size > 1 )
     __bufavail = _M_buf_size - 1;

   const streamsize __limit = std :: min ( __chunk, __bufavail );
   if ( __n >= __limit )
     {
       const streamsize __buffill = this -> pptr ( ) - this -> pbase ( );
       const char * __buf = reinterpret_cast < const char * > ( this -> pbase ( ) );
       __ret = _M_file . xsputn_2 ( __buf, __buffill,
           reinterpret_cast < const char * > ( __s ),
           __n );
       if ( __ret == __buffill + __n )
  {
    _M_set_buffer ( 0 );
    _M_writing = true;
  }
       if ( __ret > __buffill )
  __ret -= __buffill;
       else
  __ret = 0;
     }
   else
     __ret = __streambuf_type :: xsputn ( __s, __n );
 }
       else
  __ret = __streambuf_type :: xsputn ( __s, __n );
       return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: __streambuf_type *
    basic_filebuf < _CharT, _Traits > ::
    setbuf ( char_type * __s, streamsize __n )
    {
      if ( ! this -> is_open ( ) )
 {
   if ( __s == 0 && __n == 0 )
     _M_buf_size = 1;
   else if ( __s && __n > 0 )
     {








       _M_buf = __s;
       _M_buf_size = __n;
     }
 }
      return this;
    }




template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: pos_type
    basic_filebuf < _CharT, _Traits > ::
    seekoff ( off_type __off, ios_base :: seekdir __way, ios_base :: openmode )
    {
      int __width = 0;
      if ( _M_codecvt )
 __width = _M_codecvt -> encoding ( );
      if ( __width < 0 )
 __width = 0;

      pos_type __ret = pos_type ( off_type ( - 1 ) );
      const bool __testfail = __off != 0 && __width <= 0;
      if ( this -> is_open ( ) && ! __testfail )
 {

   _M_destroy_pback ( );






   __state_type __state = _M_state_beg;
   off_type __computed_off = __off * __width;
   if ( _M_reading && __way == ios_base :: cur )
     {
       if ( _M_codecvt -> always_noconv ( ) )
  __computed_off += this -> gptr ( ) - this -> egptr ( );
       else
  {



    const int __gptr_off =
      _M_codecvt -> length ( _M_state_last, _M_ext_buf, _M_ext_next,
           this -> gptr ( ) - this -> eback ( ) );
    __computed_off += _M_ext_buf + __gptr_off - _M_ext_end;



    __state = _M_state_last;
  }
     }
   __ret = _M_seek ( __computed_off, __way, __state );
 }
      return __ret;
    }
# 736
template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: pos_type
    basic_filebuf < _CharT, _Traits > ::
    seekpos ( pos_type __pos, ios_base :: openmode )
    {
      pos_type __ret = pos_type ( off_type ( - 1 ) );
      if ( this -> is_open ( ) )
 {

   _M_destroy_pback ( );
   __ret = _M_seek ( off_type ( __pos ), ios_base :: beg, __pos . state ( ) );
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    typename basic_filebuf < _CharT, _Traits > :: pos_type
    basic_filebuf < _CharT, _Traits > ::
    _M_seek ( off_type __off, ios_base :: seekdir __way, __state_type __state )
    {
      pos_type __ret = pos_type ( off_type ( - 1 ) );
      if ( _M_terminate_output ( ) )
 {

   __ret = pos_type ( _M_file . seekoff ( __off, __way ) );
   if ( __ret != pos_type ( off_type ( - 1 ) ) )
     {
       _M_reading = false;
       _M_writing = false;
       _M_ext_next = _M_ext_end = _M_ext_buf;
       _M_set_buffer ( - 1 );
       _M_state_cur = __state;
       __ret . state ( _M_state_cur );
     }
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    bool
    basic_filebuf < _CharT, _Traits > ::
    _M_terminate_output ( )
    {

      bool __testvalid = true;
      if ( this -> pbase ( ) < this -> pptr ( ) )
 {
   const int_type __tmp = this -> overflow ( );
   if ( traits_type :: eq_int_type ( __tmp, traits_type :: eof ( ) ) )
     __testvalid = false;
 }


      if ( _M_writing && ! __check_facet ( _M_codecvt ) . always_noconv ( )
   && __testvalid )
 {



   const size_t __blen = 128;
   char __buf [ __blen ];
   codecvt_base :: result __r;
   streamsize __ilen = 0;

   do
     {
       char * __next;
       __r = _M_codecvt -> unshift ( _M_state_cur, __buf,
     __buf + __blen, __next );
       if ( __r == codecvt_base :: error )
  __testvalid = false;
       else if ( __r == codecvt_base :: ok ||
         __r == codecvt_base :: partial )
  {
    __ilen = __next - __buf;
    if ( __ilen > 0 )
      {
        const streamsize __elen = _M_file . xsputn ( __buf, __ilen );
        if ( __elen != __ilen )
   __testvalid = false;
      }
  }
     }
   while ( __r == codecvt_base :: partial && __ilen > 0 && __testvalid );

   if ( __testvalid )
     {




       const int_type __tmp = this -> overflow ( );
       if ( traits_type :: eq_int_type ( __tmp, traits_type :: eof ( ) ) )
  __testvalid = false;
     }
 }
      return __testvalid;
    }

template < typename _CharT, typename _Traits >
    int
    basic_filebuf < _CharT, _Traits > ::
    sync ( )
    {


      int __ret = 0;
      if ( this -> pbase ( ) < this -> pptr ( ) )
 {
   const int_type __tmp = this -> overflow ( );
   if ( traits_type :: eq_int_type ( __tmp, traits_type :: eof ( ) ) )
     __ret = - 1;
 }
      return __ret;
    }

template < typename _CharT, typename _Traits >
    void
    basic_filebuf < _CharT, _Traits > ::
    imbue ( const locale & __loc )
    {
      bool __testvalid = true;

      const __codecvt_type * _M_codecvt_tmp = 0;
      if ( __builtin_expect ( has_facet < __codecvt_type > ( __loc ), true ) )
 _M_codecvt_tmp = & use_facet < __codecvt_type > ( __loc );

      if ( this -> is_open ( ) )
 {

   if ( ( _M_reading || _M_writing )
       && __check_facet ( _M_codecvt ) . encoding ( ) == - 1 )
     __testvalid = false;
   else
     {
       if ( _M_reading )
  {
    if ( __check_facet ( _M_codecvt ) . always_noconv ( ) )
      {
        if ( _M_codecvt_tmp
     && ! __check_facet ( _M_codecvt_tmp ) . always_noconv ( ) )
   __testvalid = this -> seekoff ( 0, ios_base :: cur, _M_mode )
                 != pos_type ( off_type ( - 1 ) );
      }
    else
      {

        _M_ext_next = _M_ext_buf
   + _M_codecvt -> length ( _M_state_last, _M_ext_buf, _M_ext_next,
          this -> gptr ( ) - this -> eback ( ) );
        const streamsize __remainder = _M_ext_end - _M_ext_next;
        if ( __remainder )
   __builtin_memmove ( _M_ext_buf, _M_ext_next, __remainder );

        _M_ext_next = _M_ext_buf;
        _M_ext_end = _M_ext_buf + __remainder;
        _M_set_buffer ( - 1 );
        _M_state_last = _M_state_cur = _M_state_beg;
      }
  }
       else if ( _M_writing && ( __testvalid = _M_terminate_output ( ) ) )
  _M_set_buffer ( - 1 );
     }
 }

      if ( __testvalid )
 _M_codecvt = _M_codecvt_tmp;
      else
 _M_codecvt = 0;
    }
# 911
extern template class basic_filebuf< char, char_traits< char> > ;
extern template class basic_ifstream< char, char_traits< char> > ;
extern template class basic_ofstream< char, char_traits< char> > ;
extern template class basic_fstream< char, char_traits< char> > ;


extern template class basic_filebuf< wchar_t, char_traits< wchar_t> > ;
extern template class basic_ifstream< wchar_t, char_traits< wchar_t> > ;
extern template class basic_ofstream< wchar_t, char_traits< wchar_t> > ;
extern template class basic_fstream< wchar_t, char_traits< wchar_t> > ;



}
# 11 "histogram.cpp"
timeval start_cpu[10]; 
timeval end_cpu[10]; 
#ifdef __HMPP_CG__
#pragma hmppcg entrypoint as hmpp_acc_region_main_103
void hmpp_acc_region_main_103(int w, int h, int *dstData, int mapPixel[256]) { 
#pragma acc  parallel loop
{ 
# 107
for (int i = 0; i < h; i++) 
{ 
#pragma cap loop id(1)
#pragma acc loop
for (int j = 0; j < w; j++) 
{ 
dstData[i * w + j] = (mapPixel)[dstData[i * w + j]]; 
}  
}  } } 
#endif // __HMPP_CG__


# 14
int main() 
{ 
int w = 8192; 
int h = 8192; 
int *dstData = (int *)malloc((sizeof(int) * w) * h); 
int *dstData_CPU = (int *)malloc((sizeof(int) * w) * h); 
double *srcArray = (double *)malloc(sizeof(double) * (256)); 

printf("----Hist(%d*%d)----\n", w, h); 
for (int ii = 0; ii < 10; ii++) 
{ 
srand(0); 
for (int i = 0; i < h * w; i++) 
{ 
dstData[i] = rand() % 256; 
}  
for (int i = 0; i < 256; i++) 
{ 
srcArray[i] = rand() % 256; 
}  

double dstHist[256]; 
memset(dstHist, 0, (256) * sizeof(double)); 

double dstArray[256]; 
memset(dstArray, 0, (256) * sizeof(double)); 


{ 

for (int i = 0; i < h; i++) 
{ 
for (int j = 0; j < w; j++) 
{ 
int k = dstData[i * w + j]; 

((dstHist)[k])++; 
}  
}  
} 

double m_Bytes = w * h; 
(dstArray)[0] = (dstHist)[0]; 
for (int i = 1; i < 256; i++) 
{ 
(dstArray)[i] = (dstArray)[i - 1] + (dstHist)[i]; 
}  

for (int i = 0; i < 256; i++) 
{ 
(dstArray)[i] /= m_Bytes; 
}  

double m_diffA, m_diffB; 
int k = 0; 
int mapPixel[256]; 
memset(mapPixel, 0, (256) * sizeof(int)); 
for (int i = 0; i < 256; i++) 
{ 
m_diffB = (1); 
for (int j = k; j < 256; j++) 
{ 
m_diffA = fabs((dstArray)[i] - srcArray[j]); 
if (m_diffA - m_diffB < (1.000000000000000082e-05)) 
{ 
m_diffB = m_diffA; 
k = j; 
} else 

{ 
k = j - 1; 
break; 
}  
}  
if (k == 255) 
{ 
for (int l = i; l < 256; l++) 
{ 
(mapPixel)[l] = (int)k; 
}  
break; 
}  
(mapPixel)[i] = (int)k; 
}  

gettimeofday(&((start_cpu)[ii]), __null); 

#pragma cap data copy(dstData[0:w*h]) copyin(mapPixel[0:256])

{
#ifndef __HMPP_CG__
openacci::Context * ctx = 0;
if (true) {
  ctx = openacci::Context::getInstance();
  ctx->setDeviceHint(4);
  ctx->enterRegion("histogram.cpp", 100, 4 /* data */
, 2
, acc_async_sync
);
ctx->pushData(
  /* file_name     = */ "histogram.cpp",
  /* line_number   = */ 100,
  /* variable_name = */ "dstData",
  /* host_address  = */ dstData,
  /* start         = */ 0,
  /* length        = */ w*h,
  /* element_size  = */ sizeof(dstData[0]),
  /* transfer_mode = */ 11/* copy */);
ctx->pushData(
  /* file_name     = */ "histogram.cpp",
  /* line_number   = */ 100,
  /* variable_name = */ "mapPixel",
  /* host_address  = */ mapPixel,
  /* start         = */ 0,
  /* length        = */ 256,
  /* element_size  = */ sizeof(mapPixel[0]),
  /* transfer_mode = */ 9/* copyin */);
}

{ 

#pragma cap parallel
#pragma cap map thread([0:1][1:0]) threadblock([0:1][1:0])
#pragma cap loop id(0)
{ 
{
#ifndef __HMPP_CG__
openacci::Context * ctx = 0;
if (true) {
  ctx = openacci::Context::getInstance();
  ctx->setDeviceHint(4);
  ctx->enterRegion("histogram.cpp", 103, 65 /* parallel loop */
, 4
, acc_async_sync
);
ctx->pushData(
  /* file_name     = */ "histogram.cpp",
  /* line_number   = */ 103,
  /* variable_name = */ "w",
  /* host_address  = */ & w,
  /* start         = */ 0,
  /* length        = */ 1,
  /* element_size  = */ sizeof(w),
  /* transfer_mode = */ 4/* value */);
ctx->pushData(
  /* file_name     = */ "histogram.cpp",
  /* line_number   = */ 103,
  /* variable_name = */ "h",
  /* host_address  = */ & h,
  /* start         = */ 0,
  /* length        = */ 1,
  /* element_size  = */ sizeof(h),
  /* transfer_mode = */ 4/* value */);
ctx->pushData(
  /* file_name     = */ "histogram.cpp",
  /* line_number   = */ 103,
  /* variable_name = */ "dstData",
  /* host_address  = */ dstData,
  /* start         = */ 0,
  /* length        = */ -1,
  /* element_size  = */ sizeof(dstData[0]),
  /* transfer_mode = */ 283/* ipcopy */);
ctx->pushData(
  /* file_name     = */ "histogram.cpp",
  /* line_number   = */ 103,
  /* variable_name = */ "mapPixel",
  /* host_address  = */ mapPixel,
  /* start         = */ 0,
  /* length        = */ 256 - 0,
  /* element_size  = */ sizeof(mapPixel[0]),
  /* transfer_mode = */ 283/* ipcopy */);
ctx->call("histogram.cpp", 103, "histogram", "hmpp_acc_region_main_103");
} else {
#endif // !__HMPP_CG__
#ifdef __HMPP_CG__

hmpp_acc_region_main_103(w, h, dstData, mapPixel);
#endif // __HMPP_CG__
#ifndef __HMPP_CG__
}
if(ctx)
  ctx->leaveRegion("histogram.cpp", 103);
#endif // !__HMPP_CG__
}

 } 
# 116
}
if(ctx)
  ctx->leaveRegion("histogram.cpp", 100);
#endif // !__HMPP_CG__
}

 
gettimeofday(&((end_cpu)[ii]), __null); 

printf("%d\n", dstData[0]); 

}  
for (int i = 0; i < 10; i++) 
{ 
double duration_cpu = (1000) * (((end_cpu)[i]).tv_sec - ((start_cpu)[i]).tv_sec) + (((end_cpu)[i]).tv_usec - ((start_cpu)[i]).tv_usec) / (1000.0); 
printf("Hist exe time OPENACC:\t%f ms\n", duration_cpu); 
}  


srand(0); 
for (int i = 0; i < h * w; i++) 
{ 
dstData_CPU[i] = rand() % 256; 
}  
for (int i = 0; i < 256; i++) 
{ 
srcArray[i] = rand() % 256; 
}  

double dstHist[256]; 
memset(dstHist, 0, (256) * sizeof(double)); 

double dstArray[256]; 
memset(dstArray, 0, (256) * sizeof(double)); 

for (int i = 0; i < h; i++) 
{ 
for (int j = 0; j < w; j++) 
{ 
int k = dstData_CPU[i * w + j]; 

((dstHist)[k])++; 
}  
}  

double m_Bytes = w * h; 
(dstArray)[0] = (dstHist)[0]; 
for (int i = 1; i < 256; i++) 
{ 
(dstArray)[i] = (dstArray)[i - 1] + (dstHist)[i]; 
}  

for (int i = 0; i < 256; i++) 
{ 
(dstArray)[i] /= m_Bytes; 
}  

double m_diffA, m_diffB; 
int k = 0; 
int mapPixel[256]; 
memset(mapPixel, 0, (256) * sizeof(int)); 
for (int i = 0; i < 256; i++) 
{ 
m_diffB = (1); 
for (int j = k; j < 256; j++) 
{ 
m_diffA = fabs((dstArray)[i] - srcArray[j]); 
if (m_diffA - m_diffB < (1.000000000000000082e-05)) 
{ 
m_diffB = m_diffA; 
k = j; 
} else 

{ 
k = j - 1; 
break; 
}  
}  
if (k == 255) 
{ 
for (int l = i; l < 256; l++) 
{ 
(mapPixel)[l] = (int)k; 
}  
break; 
}  
(mapPixel)[i] = (int)k; 
}  

for (int i = 0; i < h; i++) 
{ 
for (int j = 0; j < w; j++) 
{ 
dstData_CPU[i * w + j] = (mapPixel)[dstData_CPU[i * w + j]]; 
}  
}  

bool correct = true; 
for (int i = 0; i < h; i++) 
{ 
for (int j = 0; j < w; j++) 
{ 
if (dstData_CPU[i * w + j] != dstData[i * w + j]) { 
correct = false; }  
}  
}  
if (correct == (false)) { 
printf("Error\n"); } else { 

printf("OK\n"); }  



return 0; 
} 
