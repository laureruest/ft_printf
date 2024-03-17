/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:15:38 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/14 20:21:24 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# ifndef STDLIB_H
#  include <stdlib.h>
#  define STDLIB_H
# endif
# ifndef UNISTD_H
#  include <unistd.h>
#  define UNISTD_H
# endif

struct	s_buffer
{
	long long int	idx;
	long long int	mxlen;
	char			buf[BUFFER_SIZE];
};

struct	s_nl
{
	long long int	o_size;
	long long int	nw_size;
	char			*o_ln;
	char			*nw_ln;
};

// implicit BUFFER_SIZE for get_next_line is 4096 bytes
// for reference look instructions for get_next_line in last lines
// in this archive, for recompiling with make this library
char	*get_next_line(int fd);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_ullitohex(unsigned long long int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
# define LIBFT_H
#endif
/*

	
*****************************************************************************	
		*  ft_isalpha
	 * The input value is unsigned char and represents a character in ASCII 
	 * codes.
	 * The return values is type int. Zero or non-Zero means False or True,
	 * respectively..
	 * LIBRARY
	     libft Library (libft.a, libft.h)

	SYNOPSIS
	     #include "libft.h"

	int
    	 ft_isalpha(int c);

	DESCRIPTION
    	 The ft_isalpha() function tests for any character for which isupper(3)
		 or islower(3) is true, like in libc library.  The value of the argument
		 must be representable as an unsigned char or the value of EOF.

	     In the ASCII character set, this includes the following characters 
		 (preceded by their numeric values, in octal):

     101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
     106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
     113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
     120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
     125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
     132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
     145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
     152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
     157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
     164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
     171 ``y''     172 ``z''

	RETURN VALUES
    	 The ft_isalpha() function returns zero if the character tests false and
	     returns non-zero if the character tests true
	
**********************************************************************
 	ft_isdigit
 *  	 * The input value is unsigned char and represents a character in ASCII
 *  	 codes.
		 * The return values is type int. Zero or non-Zero means False or True,
		 * respectively.
		 * LIBRARY
	     libft Library (libft.a, libft.h)

	SYNOPSIS
    	 #include "libft.h"

    	 int
    		 ft_isdigit(int c);

	DESCRIPTION
	     The ft_isdigit() function tests for a decimal digit character.
	   	 Regardless of locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''

    	 The value of the argument must be representable as an unsigned char or
	 	the value of EOF.

	RETURN VALUES
     The ft_isdigit() function return zero if the character tests false
     and return non-zero if the character tests true.

************************************************************************
   ft_isalnum 

	LIBRARY
    	 libft Library (libft.a, libft.h)

	SYNOPSIS
    	 #include "libft.h"

  	   int
    	 ft_isalnum(int c);

	DESCRIPTION
    	 The ft_isalnum() function tests for any character for which
		 ft_isalpha(3) or ft_isdigit(3) is true.  The value of the argument must
		 be representable as an unsigned char or the value of EOF.

    	 In the ASCII character set, this includes the following characters 
		 (preceded by their numeric values, in octal):

     060 ``0''     061 ``1''     062 ``2''     063 ``3''     064 ``4''
     065 ``5''     066 ``6''     067 ``7''     070 ``8''     071 ``9''
     101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
     106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
     113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
     120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
     125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
     132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
     145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
     152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
     157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
     164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
     171 ``y''     172 ``z''

	RETURN VALUES
    	 The ft_isalnum() function returns zero if the character tests false and
		 returns non-zero if the character tests true.
	*************************************************************************	
	 * NAME ft_isascii -- test for ASCII character
	 *
		LIBRARY
     		libft Library (libft.a, libft.h)

		SYNOPSIS	
     		#include <libft.h>

   		  int
    		 ft_isascii(int c);

	DESCRIPTION
    	 The isascii() function tests for an ASCII character, which is any
		 character between 0 and octal 0177 inclusive.

	RETURN VALUE
	 	If input value is an integer (or unsigned char) between 0 and 127,
		inclusive, returns non-zero, returning zero in other cases.
********************************************************************************

FT_ISPRINT               LIBFT Library Functions Manual       FT_ISPRINT

NAME
     ft_isprint -- printing character test (space character inclusive)

LIBRARY
     LIBFT LIBRAY(libft.a, libft.h)

SYNOPSIS
     #include "libft.h#

     int
     ft_isprint(int c);

DESCRIPTION
     The ft_isprint() function tests for any printing character, including space
     (` ').  The value of the argument must be representable as an unsigned
     char or the value of EOF.

     In the ASCII character set, this includes the following characters (pre-
     ceded by their numeric values, in octal):

     040 sp        041 ``!''     042 ``"''     043 ``#''     044 ``$''
     045 ``%''     046 ``&''     047 ``'''     050 ``(''     051 ``)''
     052 ``*''     053 ``+''     054 ``,''     055 ``-''     056 ``.''
     057 ``/''     060 ``0''     061 ``1''     062 ``2''     063 ``3''
     064 ``4''     065 ``5''     066 ``6''     067 ``7''     070 ``8''
     071 ``9''     072 ``:''     073 ``;''     074 ``<''     075 ``=''
     076 ``>''     077 ``?''     100 ``@''     101 ``A''     102 ``B''
     103 ``C''     104 ``D''     105 ``E''     106 ``F''     107 ``G''
     110 ``H''     111 ``I''     112 ``J''     113 ``K''     114 ``L''
     115 ``M''     116 ``N''     117 ``O''     120 ``P''     121 ``Q''
     122 ``R''     123 ``S''     124 ``T''     125 ``U''     126 ``V''
     127 ``W''     130 ``X''     131 ``Y''     132 ``Z''     133 ``[''
     134 ``\''     135 ``]''     136 ``^''     137 ``_''     140 ```''
     141 ``a''     142 ``b''     143 ``c''     144 ``d''     145 ``e''
     146 ``f''     147 ``g''     150 ``h''     151 ``i''     152 ``j''
     153 ``k''     154 ``l''     155 ``m''     156 ``n''     157 ``o''
     160 ``p''     161 ``q''     162 ``r''     163 ``s''     164 ``t''
     165 ``u''     166 ``v''     167 ``w''     170 ``x''     171 ``y''
     172 ``z''     173 ``{''     174 ``|''     175 ``}''     176 ``~''

RETURN VALUES
     The ft_isprint() function returns zero if the character tests false and
     returns non-zero if the character tests true.

SEE ALSO
     ft_isalnum_l(3), ft_isascii(7)

STANDARDS
     The isprint() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
********************************************************************************

FT_STRLEN                LIBFT Library Functions Manual                FT_STRLEN

NAME
     ft_strlen -- find length of string

LIBRARY
     LIBFT Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     t_size
     ft_strlen(const char *s);

     being t_size an alias of unsigned long

DESCRIPTION
     The ft_strlen() function computes the length of the string s.

RETURN VALUES
     The ft_strlen() function returns the number of characters that precede the
     terminating NUL character.
********************************************************************************

FT_MEMSET         LIBFT Library Functions Manual                FT_MEMSET

NAME
     ft_memset -- fill a byte string with a byte value

LIBRARY
     LIBFT Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     void* 
     ft_memset(void *b, int c, t_size len);

DESCRIPTION
     The ft_memset() function writes len bytes of value c (converted to an
			 unsigned char) to the string b.
APPLICATIONS
	Usable to initialize memory positions.
		Warning: Be carefull, you must to asure you are not out of your 
				memory assignation.

RETURN VALUES
     The ft_memset() function returns its first argument.

SEE ALSO
     ft_bzero

*******************************************************************************
FT_BZERO				LIBFT LIBRARY								FT_BZERO

NAME
     ft_bzero -- write zeroes to a byte string

LIBRARY
     LIBFT Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     void
     ft_bzero(void *s, t_size n);

DESCRIPTION
     The ft_bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.

SEE ALSO
     ft_memset

********************************************************************************
FT_MEMCPY                LIBFT Library Functions Manual              FT_MEMCPY

NAME
     ft_memcpy -- copy memory area

LIBRARY
     Libft Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     void *
     ft_memcpy(void *dst, const void *src, size_t n);

DESCRIPTION
     The ft_memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use ft_memmove(3) instead.
	 
	 
	 
	 Para desarrollar y tener mismo comportamiento que memcpy con el puntero 
		src, crear una cadena de n bytes para archivar el valor original, la 
		cual servira para copiar a dst.
		
	RETURN VALUES
     The ft_memcpy() function returns the original value of dst.

	IMPORTANT
		Like you Know the Standard Libraries installed in 42 are BSD Librarys,
			in fact	from a lot of years ago, memcpy and memmove uses bcopy
			function to do transferences, for that memcpy and memmove do its
			work in the same manner. 
********************************************************************************
FT_MEMMOVE               LIBFT Library Functions Manual               MEMMOVE

NAME
     ft_memmove -- copy byte string

LIBRARY
     Libft Library (libft.h, libft.a)

SYNOPSIS
     #include "libft.h>

     void *
     ft_memmove(void *dst, const void *src, size_t len);

DESCRIPTION
     The ft_memmove() function copies len bytes from string src to string dst.
   	 The two strings may overlap; the copy is always done in a non-destructive
	 manner.

RETURN VALUES
     The ft_memmove() function returns the original value of dst.

SEE ALSO
     ft_memcpy

 IMPORTANT
        Like you Know the Standard Libraries installed in 42 are BSD Librarys,
            in fact from a lot of years ago, memcpy and memmove uses bcopy
R           function to do transferences, for that memcpy and memmove do its
            work in the same manner.
*******************************************************************************

FT_STRLCPY               LIBFT Library Functions Manual               FT_STRLCPY
FT_STRLCAT               LIBFT Library Functions Manual               FT_STRLCAT

     ft_strlcpy, ft_strlcat -- size-bounded string copying and concatenation

LIBRARY
     Libft Library (libft.h, libft.a)

SYNOPSIS
     #include "libft"

     size_t
     ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);


     ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);

DESCRIPTION
     The ft_strlcpy() and ft_strlcat() functions copy and concatenate strings
	 with the same input parameters and output result as snprintf(3) in BSD
	 Standard C Library.  They are designed to be safer, more consistent, and
	 less error prone replacements for the easily misused functions strncpy(3)
	and strncat(3), both included in the BSD Standard C Library <strings.h>.

     ft_strlcpy() and ft_strlcat() take the full size of the destination buffer,
	 and guarantee NUL-termination if there is room.  Note that room for the NUL
	 should be included in dstsize.

     ft_strlcpy() copies up to dstsize - 1 characters from the string src to
	 dst, NUL-terminating the result if dstsize is not 0.

     ft_strlcat() appends string src to the end of dst.  It will append at most
	 dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
	 dstsize is 0 or the original dst string was longer than dstsize (in 
	 practice this should not happen as it means that either dstsize is in-
	 correct or that dst is not a proper string).
	 ft_strlcat() agrega la cadena src al final de dst. Se agregará como máximo
     dstsize - ft_strlen(dst) - 1 carácter. Luego terminará en NUL, a menos que
     dstsize es 0 o la cadena dst original era más larga que dstsize
     En la práctica, esto no debería suceder, ya que significa que cualquiera,
	 dstsize es incorrecto o que dst no es una cadena adecuada).


     If the src and dst strings overlap, the behavior is undefined.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal hand-
	 ler safety (snprintf(3) is not entirely safe on some systems), the 
	 following two are equivalent:

           n = ft_strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src); (function in Standard C Library)

     Like snprintf(3), (in STD C Libary), the ft_strlcpy() and ft_strlcat()
	 functions return the total length of the string they tried to create. For
	 ft_strlcpy() that means the length of src.  For strlcat() that means the
	 initial length of dst plus the length of src.


	 Special Cases for ft_strlcat:
	 	If input parameter dstsize = 0 returns len (dest) + len (src)
		Cases left:
			Take len(dst) or dstsize (the lower), and add len(src)
		If you call ft_strlcat(x, y , 0) you will get (necesary) len for dst to
			do the concatenation.

HOW TO USE RETURN VALUES, TO KNOW IF OUTPUT STRING WAS TRUNCATED
	 If the return value is >= dstsize, the output string has been truncated.
	 It is the caller's responsibility to handle this.

*******************************************************************************


FT_TOUPPER               LIBFT Library Functions Manual               FT_TOUPPER

NAME
     ft_toupper  -- lower case to upper case letter conversion

LIBRARY
     Libft Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     int
     ft_toupper(int c);

DESCRIPTION
     The ft_toupper() function converts a lower-case letter to the corresponding
	 upper-case letter.The argument must be representable as an unsigned char 
	 or the value of EOF.

RETURN VALUES
     If the argument is a lower-case letter, the ft_toupper() function returns
	 the corresponding upper-case letter if there is one; otherwise, the argu-
	 ment is returned unchanged.

********************************************************************************


FT_TOLOWER               LIBFT Library Functions Manual               FT_TOLOWER

NAME
     ft_tolower -- upper case to lower case letter conversion

LIBRARY
     Libft C Library (libft.h, libft.a)

SYNOPSIS
     #include "libft.h"

     int
     ft_tolower(int c);

DESCRIPTION
     The ft_tolower() function converts an upper-case letter to the corres-
	 ponding lower-case letter.  The argument must be representable as an
	 unsigned char or the value of EOF.

RETURN VALUES
     If the argument is an upper-case letter, the ft_tolower() function returns
	 the corresponding lower-case letter if there is one; otherwise, the argu-
	 ment is returned unchanged.

********************************************************************************

FT_STRCHR               LIBFT Library Functions Manual                FT_STRCHR

FT_STRRCHR              LIBFT Library Functions Manual                FT_STRRCHR


NAME
     ft_strchr, ft_strrchr -- locate character in string

LIBRARY
     Libft C Library (libft.h, libft.a)

SYNOPSIS
     #include "libft.h"

     char *
     ft_strchr(const char *s, int c);

     char *
     ft_strrchr(const char *s, int c);

DESCRIPTION
     The ft_strchr() function locates the first occurrence of c (converted to a
	 char) in the string pointed to by s. The terminating null character is
	 considered to be part of the string; therefore if c is `\0', the functions
	 locate the terminating `\0'.

     The ft_strrchr() function is identical to ft_strchr(), except it locates
	 the last occurrence of c.

RETURN VALUES
     The functions ft_strchr() and ft_strrchr() return a pointer to the located
	 character, or NULL if the character does not appear in the string.


********************************************************************************

FT_STRNCMP               LIBFT Library Functions Manual               FT_STRNCMP

NAME
     ft_strncmp -- compare strings

LIBRARY
     Libft C Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     int
     ft_strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
     The ft_strncmp() function lexicographically compare the null-terminated
	 strings s1 and s2.

     The ft_strncmp() function compares not more than n characters.  Because
	 ft_strncmp() is designed for comparing strings rather than binary data, 
	 characters that appear after a `\0' character are not compared.

RETURN VALUES
     The ft_strncmp() function return an integer greater than, equal to, or less
	 than 0, according as the string s1 is greater than, equal to, or less than
	 the string s2.  The comparison is done using unsigned characters, so that
	 `\200' is greater than `\0'.

SEE ALSO
     ft_memcmp

********************************************************************************

FT_MEMCHR                LIBFT Library Functions Manual                FT_MEMCHR


NAME
     ft_memchr -- locate byte in byte string

LIBRARY
     Libft C Library (libft.a, libft.h)

SYNOPSIS
     #include "libft.h"

     void *
     ft_memchr(const void *s, int c, size_t n);

DESCRIPTION
     The ft_memchr() function locates the first occurrence of c (converted to
	 an unsigned char) in string s.

RETURN VALUES
     The ft_memchr() function returns a pointer to the byte located, or NULL if
	 no such byte exists within n bytes.

SEE ALSO
     ft_strchr, ft_strrchr(3)

********************************************************************************

FT_MEMCMP                LIBFT Library Functions Manual                FT_MEMCMP

NAME
     ft_memcmp -- compare byte string

LIBRARY
     Libft C Library (libc, -lc)

SYNOPSIS
     #include "libft.h"

     int
     ft_memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
     The ft_memcmp() function compares byte string s1 against byte string s2.
   	 Both strings are assumed to be n bytes long.

RETURN VALUES
     The ft_memcmp() function returns zero if the two strings are identical,
	 otherwise returns the difference between the first two differing bytes
	 (treated as unsigned char values, so that `\200' is greater than `\0',
	 for example). Zero-length strings are always identical.  This
     behavior is not required by C and portable code should only depend on the
	 sign of the returned value.

********************************************************************************

FT_STRNSTR                LIBFT Library Functions Manual             FT_ STRNSTR

NAME
     FT_strnstr -- locate a substring in a string

LIBRARY
     Libft C Library (libft.h, libft.a)

SYNOPSIS
     #include "libft"

     char *
     strnstr(const char *haystack, const char *needle, size_t len);

DESCRIPTION
     The ft_strnstr() function locates the first occurrence of the null-termi-
	 nated string needle in the string haystack, where not more than len
	 characters are searched.  Characters that appear after a `\0' character are
	 not searched.
	 
RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occursnowhere
	 in haystack, NULL is returned; otherwise a pointer to the first character
	 of the first occurrence of needle is returned.

EXAMPLES
	 The following sets the pointer ptr to the "Bar Baz" portion of largestring:

     	   const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring,8);
     The following sets the pointer ptr to NULL, because only the first 4 cha-
	 racters of largestring are searched:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4);

SEE ALSO
     ft_memchr, ft_strchr, ft_strrchr

********************************************************************************

 FT_ATOI                  LIBFT Library Functions Manual                 FT_ATOI

NAME
     ft_atoi   -- convert ASCII string to integer

LIBRARY
     Libft C Library (libft.h, libft.a)

SYNOPSIS
     #include "libft.h"

     int
     atoi(const char *str);

DESCRIPTION
     The ft_atoi() function converts the initial portion of the string pointed
	 to by str to int representation.
	The string may begin with an arbitrary amount of white spaces (chr$(32))
	,followed by a single optional `+' or `-' sign, and later number digits


ERRORS
     The function atoi() need not affect the value of errno on an error.

********************************************************************************
FT_CALLOC                LIBFT Library Functions Manual                FT_CALLOC

NAME
     ft_calloc -- memory allocation

SYNOPSIS
     #include "libft.h"

     void *
     ft_calloc(t_size count, t_size size);

DESCRIPTION
     The ft_calloc() function allocate memory.  The allocated memory is aligned
	 such that it can be used for any data type, including AltiVec- and
	 SSE-related types. The free() function (in Standard C library, stdlib.h)
	 function frees allocations that were created via the preceding allocation
	 function.

     The ft_calloc() function contiguously allocates enough space for count
	 objects that are size bytes of memory each and returns a pointer to the
	 allocated memory.  The allocated memory is filled with bytes of value zero.

     The free() function (in Standard C Library, stdlib.h), deallocates the me-
	 mory allocation pointed to by ptr. If ptr is a NULL pointer, no operation
	 is performed.

RETURN VALUES
     If successful, ft_calloc() functions return a pointer to allocated memory.
	 If there is an error, it return a NULL pointer.
     The free() function (in Standard C Library, stdlibn.h) does not return a
	 value.

********************************************************************************

FT_STRDUP                LIBFT Library Functions Manual                FT_STRDUP

NAME
     ft_strdup -- save a copy of a string

LIBRARY
     Libft C Library (libft.h, libft.a)

SYNOPSIS
     #include "libft.h"

     char *
     ft_strdup(const char *s1);

DESCRIPTION
     The ft_strdup() function allocates sufficient memory for a copy of the
	 string s1, does the copy, and RETURNS a pointer to it.  The pointer may
	 subsequently be used as an argument to the function free() (in BSD Stan-
	 dard C Library).

     If insufficient memory is available, NULL is RETURNED.
********************************************************************************
FT_SUBSTR				LIBFT C FUNCTIONS LIBRARY					FT_SUBSTR

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_substr

Abstract:	Esta funcion extrae una string desde <s>(paso por puntero), empezan-
			do	a extraer desde la posicion de indice <start>.
			Los datos extraidos, son insertados en una nueva string,
			(la funcion devuelve un puntero a esta nueva string).
			El tamanyo maximo de la nueva string es <len>.
			La funcion solo reserva la cantidad de memoria necesaria.
   	

Prototipo:  char *ft_substr(char const *s, unsigned int start, size_t len);

Archivos a entregar:  -

Parámetros: 
		s:	 	La string desde la que crear la substring.
		
		start: El índice del caracter en ’s’ desde el que empezar la substring.

		len: 	La longitud máxima de la substring.

Valor devuelto:
				La substring resultante.
				NULL si falla la reserva de memoria.

Funciones autorizadas:
			   	malloc
 
Descripción:

				Reserva (con malloc(3)) y devuelve una substring de la string
				’s’. La substring empieza desde el índice ’start’ y tiene una
				longitud máxima ’len’.

********************************************************************************
FT_STRJOIN             LIBFT C FUNCTIONS LIBRARY                   FT_STRJOIN

Library: Libft C Library(libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_strjoin

Abstract:   Esta funcion calcula el tamanyo de string s1+s2, reserva la canti-
			dad de memoria necesaria para ese tamanyo, y devuelve un puntero
			a un nuevo string cuyo contenido es la concatenacion de s1 y s2.

Prototipo:  char *ft_strjoin(char const *s1, char const *s2);

Archivos a entregar:  -

Parámetros:	s1: La primera string.
			s2: La string a añadir a ’s1’.

Valor devuelto:
			La nueva string.
			NULL si falla la reserva de memoria.

Funciones autorizadas: 
			malloc.

Descripción:
			Reserva (con malloc(3)) y devuelve una nueva string, formada por la
			concatenación de ’s1’ y ’s2’.

********************************************************************************
FT_STRTRIM             LIBFT C FUNCTIONS LIBRARY                   FT_STRTRIM

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_strtrim

Prototipo:	char *ft_strtrim(char const *s1, char const *set);

Archivos a entregar:	-

Parámetros:
			s1: La string que debe ser recortada.
			set: Los caracteres a eliminar de la string.

Valor devuelto:
		   		La string recortada.
				NULL si falla la reserva de memoria.

Funciones autorizadas: malloc

Descripción:	Elimina todos los caracteres de la string ’set’ desde el princi-
				pio y desde el final de ’s1’, hasta encontrar un caracter no
				perteneciente a ’set’. La string resultante se devuelve con una
				reserva de malloc(3).


********************************************************************************

FT_SPLIT             LIBFT C FUNCTIONS LIBRARY                   FT_SPLIT

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_split

Prototipo:  char **ft_split(char const *s, char c);

Archivos a entregar:    -

Parámetros:
            s: La string a separar.
            c: El caracter delimitador.

Valor devuelto:
                La array de nuevas strings resultante de la separacion.
                NULL si falla la reserva de memoria.

Funciones autorizadas: malloc, free

Descripción:    Reserva (utilizando malloc(3)) un array de strings resultante
				de separar la string ’s’ en substrings utilizando el caracter
				’c’ como delimitador. El array debe terminar con un puntero
				NULL.


*******************************************************************************

FT_ITOA             LIBFT C FUNCTIONS LIBRARY                   FT_ITOA


Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_itoa

Prototipo:  char *ft_itoa(int n);

Archivos a entregar:    -

Parámetros:		n: el entero a convertir

Valor devuelto:	La string que represente el numero.
                NULL si falla la reserva de memoria.

Funciones autorizadas: malloc

Descripción:    Reserva (utilizando malloc(3)),  genera una string que represen-
				te el valor entero recibido como argumento. Los números negati-
				vos tienen que gestionarse.


******************************************************************************* 
                                                                                
FT_ULLITOHEX             LIBFT C FUNCTIONS LIBRARY                 FT_ULLITOHEX         


Library: Libft C Library (libft.h, libft.a)                                     
                                                                                
Usage: include "libft.h"                                                        
                                                                                
Nombre de función: ft_ullitohex                                                      
                                                                                 
Prototipo:  char *ft_ullitohex(unsigned long long int n);                    
                                                   
                                                      
                                                                               
Parámetros:             n: el entero sin signo a convertir                              
                                                                                 
Valor devuelto: La string que represente el numero en base 16.                           
	               NULL si falla la reserva de memoria.                            
                                                                        
Funciones autorizadas: malloc                                                   
                                                                               
Descripción:    Reserva (utilizando malloc(3)),  genera una string que represen-
                te el valor entero sin signo largo largo, recibido como argumen-
		to.                                                              
                                                                              
***************************************************************************

FT_STRMAPI             LIBFT C FUNCTIONS LIBRARY                   FT_STRMAPI

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_strmapi

Prototipo: char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

Archivos a entregar:    -

Parámetros:     s: La string que iterar.
				f: La función a aplicar sobre cada carácter.

Valor devuelto:	La string creada tras el correcto uso de ’f’ sobre cada
				carácter. 
                NULL si falla la reserva de memoria.

Funciones autorizadas: malloc

Descripción:   	A cada carácter de la string ’s’, aplica la función ’f’ dando
				como parámetros el índice de cada carácter dentro de ’s’ y el
				propio carácter. Genera una nueva string con el resultado del
				uso sucesivo de ’f’


*******************************************************************************

FT_STRITERI             LIBFT C FUNCTIONS LIBRARY                   FT_STRITERI

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_striteri

Prototipo: void ft_striteri(char *s, void (*f)(unsigned int, char*));

Archivos a entregar:    -

Parámetros:     s: La string que iterar.
                f: La función a aplicar sobre cada carácter.

Valor devuelto:	Nada

Funciones autorizadas: Ninguna

Descripción:    A cada carácter de la string ’s’, aplica la función ’f’ dando
                como parámetros el índice de cada carácter dentro de ’s’ y 
                la direccion del propio carácter, que podra modificarse si es
				necesario.


*******************************************************************************


FT_PUTCHAR_FD           LIBFT C FUNCTIONS LIBRARY                 FT_PUTCHAR_FD

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_putchar_fd

Prototipo:		void ft_putchar_fd(char c, int fd);

Archivos a entregar:    -

Parámetros:     c: El caracter a enviar.
				fd: El file descriptor sobre el que escribir.

Valor devuelto: Nada

Funciones autorizadas: write

Descripción:	Envía el carácter ’c’ al file descriptor especificado. 


*******************************************************************************


FT_PUTSTR_FD           LIBFT C FUNCTIONS LIBRARY                 FT_PUTSTR_FD

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_putstr_fd

Prototipo:      void ft_putstr_fd(char *s, int fd);

Archivos a entregar:    -

Parámetros:     s: La string a enviar.
                fd: El file descriptor sobre el que escribir.

Valor devuelto: Nada

Funciones autorizadas: write

Descripción:    Envía la string 's' al file descriptor especificado.


*******************************************************************************



FT_PUTENDL_FD           LIBFT C FUNCTIONS LIBRARY                 FT_PUTENDL_FD

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_putendl_fd

Prototipo:      void ft_putendl_fd(char *s, int fd);

Archivos a entregar:    -

Parámetros:     s: La string a enviar.
                fd: El file descriptor sobre el que escribir.

Valor devuelto: Nada

Funciones autorizadas: write

Descripción:    Envía la string 's' al file descriptor especificado, seguido
				de un salto de linea..

*******************************************************************************



FT_PUTNBR_FD           LIBFT C FUNCTIONS LIBRARY                 FT_PUTNBR_FD

Library: Libft C Library (libft.h, libft.a)

Usage: include "libft.h"

Nombre de función: ft_putnbr_fd

Prototipo:      void ft_putnbr_fd(int n, int fd);

Archivos a entregar:    -

Parámetros:     n: El numero que enviar.
                fd: El file descriptor sobre el que escribir.

Valor devuelto: Nada

Funciones autorizadas: write

Descripción:    Envía el numero 'n' al file descriptor dado.


******************************************************************************


	Function name:	get_next_line
	Prototype:		char *get_next_line(int fd);
	Usage:			Including in libraries with get_next_line.h
	Compiling:
					With CC **-D BUFFER_SIZE={size bytes}
					Implicit BUFFER_SIZE = 4096 bytes
				   			(stat -f %k /Users/lruiz-es)
					To change compilation go to three last lines in archive
					Makefile.
					Implicit makefile behavior is to test stat -f %k /
					and compile whith -D BUFFER_SIZE={size} FLAG with the
					cluster size in compilation time
					See	Makefile.h and edit it!

	Parameters:		fd: The file descriptor to read from
	Return value:	Read line: correct behavior
					NULL: there is no nothing else to read, or an error ocurred

	Description: 	The function returns a line readed from a file descriptor

*******************************************************************************
*/
