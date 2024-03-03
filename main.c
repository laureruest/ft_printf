/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:03:35 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/03 17:20:16 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comm_ent & Uncomment where necessary
#include <stdio.h>
//#include "libftprintf.h"

int	main(void)
{
	// starting with data for generator and for tests
	char	battery_test_strings[5][3] = {
		{"\0Esto es una cadena de formato NULL%s", "Esto es un string que\
		no se imprimira", "Esto tampoco"};
		{"En esta prueba imprimimos un caracter S: %c Adios\0 y a partir \
			de aqui nada mas", "Se imprimio	solo la \0primera s", ""};
		{"En esta prueba imprimimos un cadena \34Se imprimio solo la \34, el re\
		   sto se ignora:\34%s\34 Adios\0 y a partir de aqui nada mas", \
			   "Se imprimio	solo la \0primera s", "Esta ni entrara a printf"};
		{"En esta prueba imprimimos el primer caracter de la cadena \34Se impr\
			imio solo la \34 que por lo tanto es la S: %c\nY ahora la cadena\
				completa \34Se imprimio solo la \34: %s", "Se imprimio solo \
				la ", "Se imprimio solo la "};
		{"En esta prueba imprimimos el signo \34\37\34: %%. Y ahora el primer\
		   	caracter de la cadena \34Se imprimio solo la \34, que por lo tanto\
			   	es la S: %c\nY ahora la cadena completa \34Se imprimio solo la \
				34: %s", "Se imprimio solo la ", "Se imprimio solo la \0y esto\
			   	no se imprime"};
	};
	char	for_nb_format_ptr = 
		{"Ahora imprimimos la direccion de un puntero: %p\0que deberia imprimir \
			el puntero en hexadecimal: %p\0 y nada de esto"};
	void	*ptr[8];
	long long int	i;
	long double	f;
	int nreturned;

	ptr[0] = (void *) 0;
	ptr[1] = (void *) 255;
	ptr[2] = (void *) 65535;
	ptr[3] = (void *) 167777215;
	ptr[4] = (void *) 4294967295;
	ptr[5] = (void *) 1099511627775;
	ptr[6] = (void *) 281474976710655;
	ptr[7] = (void *) 281474976710654;
	for (i = 0, i < 5, i++)
	{
		nreturned = printf(&battery_test_strings[i][0], &battery_test_strings\
				[i][1], &battery_test_strings[2]);
	//nreturned = ft_printf(&battery_test_strings[i][0], &battery_test_strings\
				[i][1], &battery_test_strings[2]);
	}
	nreturned = printf("Imprimimos un monton de caracteres iniciales de cuatro \
			cadenas diferentes %c %c %c y un string %s", "Ahora la A", "Bamos \
			con la B", "Continuamos con la C", "Esto es la cadena completa");
//	nreturned = ft_printf("Imprimimos un monton de caracteres iniciales de \
			cuatro cadenas diferentes %c %c %c y un string %s", "Ahora la a", \
			"Bamos con la B", "Continuamos con la C", "Esto es la cadena com\
			pleta");
	for (i = 0, i < 7, i += 2)
	{
		nreturned = printf("Imprimo el puntero numero %i: %p\n", i, p[i], i + 1\
				, p[i + 1]);
	//	nreturned = ft_printf("Imprimo el puntero numero %i: %p\n", i, p[i]\
				, i + 1, p[i + 1]);
	}
	for (i = −9223372036854775808, i < 9223372036854775808, i++)
		nreturned = printf("Imprimo el entero %i\n", i);
	//	nreturned = ft_printf("Imprimo el entero %i\n", i);
	//	NOW WE WORKS IN DECIMAL VERY LITTLE AN VERY BIG
	for (f = -1, f <= 1, f += 0.00001)
		nreturned = printf("Imprimo en decimal %d\n", f);
	//	nreturned = ft_printf("Imprimo en decimal %d", f);
	for (f = −9223372036854775808, i < 9223372036854775808, i+= 20.77)
		nreturned = printf("Imprimo en decimal %d\n", f);
	//	nreturned = ft_printf("Imprimo en decimal %d", f);
	//	NOW WE WORKS IN UNSIGNED DECIMAL, PASSING NEGATIVE VALUES
	//	FOR VERY LITTLE AND FOR VERY BIG NUMBERS
	for (f = -1, f <= 1, f += 0.00001)
		nreturned = printf("Imprimo en decimal %u\n", f);
	//	nreturned = ft_printf("Imprimo en decimal %u\n", f);
	for (f = −9223372036854775808, i < 9223372036854775808, i+= 20.77)
		nreturned = printf("Imprimo en decimal %u\n", f);
	//	nreturned = ft_printf("Imprimo en decimal %u\n", f);
	
		
	


}
