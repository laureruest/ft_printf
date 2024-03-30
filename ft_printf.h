/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:33:53 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/24 08:53:24 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

int	ft_printf(const char *s_format, ...);
# define FT_PRINTF_H
#endif
/*
DESCRIPTION

       The function ft_printf() produce output according to
       a format as described below, writing output to stdout,
	   the standard output stream.
       Function ft_printf() is called with a  variable number of
       arguments.  These functions do not call the va_end macro.
       Because they invoke the va_arg macro, the value of ap is
       undefined after the call.  See stdarg(3).

       This function write the output under the control of a
       format string that specifies how subsequent arguments are
	   converted for output.

   Format of the format string
       The format string is a character string, beginning and ending in
       its initial shift state, if any.  The format string is composed
       of zero or more directives: ordinary characters (not %), which
       are copied unchanged to the output stream; and conversion
       specifications, each of which results in fetching zero or more
       subsequent arguments.  Each conversion specification is
       introduced by the character %n specifier.

       The overall syntax of a conversion specification is:

           %conversion

       The arguments must correspond properly (after type promotion)
       with the conversion specifier.
	   The arguments are used in the order given, and each conversion
	   specifier asks for the next argument (and it is an error if
	   insufficiently many arguments are given).
           printf("Directivers..%{conversor}..Can be more directives
		   		and/or conversor specifiers", <Subsequent arguments splited
				commas>");

       Conversion specifier can be mixed with "%%" formats, which do not
       consume an argument.

   Conversion specifiers(%_) Where _ is conversion specifier.
       A character that specifies the type of conversion to be applied.
       The conversion specifiers and their meanings are:

       d or i   The int argument is converted to signed decimal notation.
              The precision is 1.

       u, x, X
              The unsigned int argument is converted to unsigned decimal (u),
			  or unsigned hexadecimal (x and X) notation.  The letters abcdef
			  are used for x conversions; the letters ABCDEF are used for X
              conversions. Note then specifing one of these conversion
			  specifiers, if it subministrated an int argument, if value is
			  negative, the output will be a positive value corresponding
			  to the binary representation in two's complement of that value,
			  taken as is was a binary representation without sign.

       c      The int argument (char for extension) is converted
              to an unsigned char, and the resulting character is
              written.

       s      The respective const char * argument is expected to be
	   		  a pointer to an array of character type (pointer to a string).
			  Characters from the array are written up to (but not including)
			  a terminating null byte ('\0').
			  The array must contain a terminating null wide character.

       p      The void * pointer argument is printed in hexadecimal (as
              if by %x).

       %      A '%' is written.  No argument is converted/consumed.
	  		  The complete conversion specification is '%%'.

RETURN VALUE

       Upon successful return, this function returns the number of
       characters printed (excluding the null byte used to end output to
       strings).

       If an output error is encountered, a negative value is returned.
*/
