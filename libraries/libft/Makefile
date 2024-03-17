# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 17:37:51 by lruiz-es          #+#    #+#              #
#    Updated: 2024/03/14 21:13:37 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#MACRO VARIABLES DEFINITIONS

OBJ_DIR = obj/
OBJ =	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
		ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o\
		ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o\
		ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o\
	   	ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o\
		ft_split.o ft_itoa.o ft_ullitohex.o ft_strmapi.o ft_striteri.o ft_put_fd.o\
		ft_putnbr_fd.o get_next_line.o get_next_line_utils.o

OBJ_COMP_PATH = $(addprefix $(OBJ_DIR), $(OBJ))
SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_split.c ft_itoa.c ft_ullitohex.c ft_strmapi.c ft_striteri.c ft_put_fd.c\
		ft_putnbr_fd.c get_next_line.c get_next_line_utils.c

ST_LIB_PKGER = ar
PKGERFLAGS = -r
CC = cc
CFLAGS = -Wall -Werror -Wextra -c
VOID_FUNCTION_SKELETON = void func(void) {}

PROJECT = libft
LIBRARY_NAME = $(NAME) 
.PHONY: all $(PROJECT) clean fclean re
all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) : 
	@mkdir obj/

$(NAME) : $(OBJ_COMP_PATH)
	$(ST_LIB_PKGER) $(PKGERFLAGS) $@ $?	

$(PROJECT) : all
	

$(OBJ_DIR)%.o : %.c libft.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -f -r $(OBJ_DIR)

fclean: clean
	@rm -f $(LIBRARY_NAME)

re: fclean all
	

obj/ft_isalnum.o : obj/ft_isalpha.o obj/ft_isdigit.o ft_isalnum.c libft.h
	$(CC) $(CFLAGS) -o $@ ft_isalnum.c

obj/ft_bzero.o : obj/ft_memset.o libft.h ft_memset.c
	$(CC) $(CFLAGS) -o $@ ft_bzero.c

obj/ft_strlcpy.o : obj/ft_strlen.o libft.h ft_strlcpy.c
	$(CC) $(CFLAGS) -o $@ ft_strlcpy.c

obj/ft_strlcat.o : obj/ft_strlen.o libft.h ft_strlcat.c
	$(CC) $(CFLAGS) -o $@ ft_strlcat.c

obj/ft_strnstr.o : obj/ft_strlen.o libft.h ft_strnstr.c
	$(CC) $(CFLAGS) -o $@ ft_strnstr.c

obj/ft_atoi.o : obj/ft_isdigit.o obj/ft_strlen.o libft.h ft_atoi.c
	$(CC) $(CFLAGS) -o $@ ft_atoi.c

obj/ft_strdup.o : obj/ft_strlen.o libft.h ft_strdup.c
	$(CC) $(CFLAGS) -o $@ ft_strdup.c

obj/ft_substr.o : obj/ft_strlen.o libft.h ft_substr.c
	$(CC) $(CFLAGS) -o $@ ft_substr.c

obj/ft_strjoin.o : obj/ft_strlen.o libft.h ft_strjoin.c
	$(CC) $(CFLAGS) -o $@ ft_strjoin.c

obj/ft_strtrim.o : obj/ft_strlen.o libft.h ft_strtrim.c
	$(CC) $(CFLAGS) -o $@ ft_strtrim.c

obj/ft_split.o : obj/ft_substr.o obj/ft_strdup.o obj/ft_calloc.o\
	obj/ft_strlen.o libft.h ft_split.c
	$(CC) $(CFLAGS) -o $@ ft_split.c

obj/ft_strmapi.o : obj/ft_strlen.o ft_strmapi.c libft.h
	$(CC) $(CFLAGS) -o $@ ft_strmapi.c

obj/ft_put_fd.o : obj/ft_strlen.o ft_put_fd.c libft.h
	$(CC) $(CFLAGS) -o $@ ft_put_fd.c

obj/ft_putnbr_fd.o : obj/ft_strlen.o ft_putnbr_fd.c libft.h
	$(CC) $(CFLAGS) -o $@ ft_putnbr_fd.c

obj/get_next_line_utils.o : get_next_line_utils.c libft.h
	@#NWSIZE=$$(stat -f %k /) && $(CC) $(CFLAGS) -D BUFFER_SIZE=$$NWSIZE -o $@ get_next_line_utils.c
	@# YOU MUST USE THE SAME -D BUFFER_SIZE IN THIS RULE THAN IN THEN NEXT RULE
	@# BE CAREFULL ABOUT USING SAME BUFFER_SIZE IN THIS AND THE NEXT RULE
	$(CC) $(CFLAGS) -o $@ get_next_line_utils.c

obj/get_next_line.o : get_next_line.c obj/get_next_line_utils.o libft.h
	@#NWSIZE=$$(stat -f %k /)	&& $(CC) $(CFLAGS) -D BUFFER_SIZE=$$NWSIZE -o $@ get_next_line.c
	@# INSTRUCTIONS for BUFFER_SIZE PARAMETER
	@# YOU MUST USE THE SAME -D BUFFER_SIZE IN THIS RULE THAN IN RULE ABOVE
	@# IF YOU DONT EDIT IT WILL COMPILE WITH THE SIZE OF CLUSTER IN PARTITON /
	@# FOR COMPILING WHIT OTHER SIZES COMMENT NWSIZE LINE ABOVE
	@# COPY THAT LINE TO RULE ABOVE THIS INSTRUCTIONS AND UNCOMEMNT
	@# NEXT LINE EDITING IT
	@#$(CC) $(CFLAGS) -D BUFFER_SIZE={size_bytes_of_fs_block} -o $@
	$(CC) $(CFLAGS) -o $@ get_next_line.c
	@# 	get_next_line.c get_next_line_utils.c
	@# OR IF YOU WANT TO COMPILE WITH DEFAULT BUFFER_SIZE=4096
	@#	UNCOMMENT NEXT LINE
	@# $(CC) $(CFLAGS) -o $@ get_next_line.c
	@# AND REMEMBER, SAME BUFFER_SIZE IN LAST 2 RULES

#FIN DE MAKE
