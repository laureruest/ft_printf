# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 07:59:23 by lruiz-es          #+#    #+#              #
#    Updated: 2024/03/10 17:40:13 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
#MACRO VARIABLES DEFINITION FOR FILE INCLUSION
LIB_NAMES = libft
# *************INSERT HERE IDENTIFICATION FOR SOURCE FILES******************** #
SRC_FILES = ft_printf.c p_p_args.c
#DEBUGGING FLAGS
CC_DEBUF_FLAGS = -g -fsanitize=address
#
#
#MAKE MACRO VARIABLES FOR MAKEFILE WORKING
SRC_DIR = src
OBJ_DIR = obj
LOCAL_LIB_PATH = libraries
OBJ_FILES = $(SRC_FILES:*.c=*.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
CC = cc
CC_FLAGS = -Wall -Werror -Wextra -c
LINKER = ar
LINKER_FLAGS = -r
.PHONY = all clean fclean re
all : $(NAME)


$(NAME) : $(OBJ)
	$(LINKER) $(LINKER_FLAGS) $@ $?

$(OBJ) : $(LIB_NAMES:=*.a) $(LIB_NAMES:=*.h) $(NAME:.a=.h)
	

$(LIB_NAMES:=*.a) : 
	@cd $(LOCAL_LIB_PATH)/$(@:.a=)
	@echo Compiling LIBRARY: $(@:.a=) .............
	@make re
	@cp $@ ../../$@
	@cd ../..

$(LIB_NAMES:=*.h) : 
	@cp $(LOCAL_LIB_PATH)/$(@:.h=)/$@ $@

$(OBJ_DIR).%o : $(SRC_DIR).%c libft.a
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) $@ $< $(LIB_NAMES:=*.a)

clean : 
	@echo Cleaning Oject Files
	@rm -f **/*.o

fclean : clean
	@echo Cleaning all objects, executables and libraries
	@rm -f $(NAME)
	@rm -f **/*.a

re : fclean all
	

obj/ft_printf.o : src/ft_printf.c obj/p_p_args.o $(NAME:.a=.h) $(LIB_NAMES:=*.a) $(LIB_NAMES:=*.h)
	$(CC) $(CC_FLAGS) $(CC_DEBUF_FLAGS) $@ src/ft_printf.c src/p_p_args.c $(LIB_NAMES:=*.a)

# FIN DE MAKE
