# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 07:59:23 by lruiz-es          #+#    #+#              #
#    Updated: 2024/03/30 10:54:10 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER_NAME = ft_printf.h
#MACRO VARIABLES DEFINITION FOR FILE INCLUSION
# *************INSERT HERE IDENTIFICATION FOR SOURCE FILES******************** #
SRC_FILES = lr_prints.c ft_printf.c uitoa.c uitohex.c 
#
#
#DEBUGGING FLAGS
#CC_DEBUF_FLAGS = -g -fsanitize=address
#
#
#MAKE MACRO VARIABLES FOR MAKEFILE WORKING
SRC_DIR = src
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
CC = cc
CC_FLAGS = -Wall -Werror -Wextra -I $(HEADERS_LIBRARIES_DIR) -c
LINKER = ar
LINKER_FLAGS = -r
.PHONY = all clean fclean re
all : $(NAME)
	

$(NAME) : $(OBJ)
	$(LINKER) $(LINKER_FLAGS) $@ $?

$(HEADER_NAME) : 
	@echo "Te has borrado el archivo ft_printf.h, recuperatelo";

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@if ! [ -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o $@ $<

clean : 
	@echo Cleaning Oject Files
	@find . -name "*.o" -delete

fclean : clean
	@echo Cleaning all objects, executables and libraries
	@rm -f $(NAME)
	@find . -name "*.a" -delete
	@rm -f include/*
	@rm -f lib/*

re : fclean all
	

obj/ft_printf.o : src/ft_printf.c obj/lr_prints.o $(HEADER_NAME)
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o obj/ft_printf.o src/ft_printf.c

obj/lr_prints.o : src/lr_prints.c obj/uitoa.o obj/uitohex.o $(HEADER_NAME)
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o obj/lr_prints.o src/lr_prints.c

# FIN DE MAKE
