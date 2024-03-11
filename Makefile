# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 07:59:23 by lruiz-es          #+#    #+#              #
#    Updated: 2024/03/11 19:54:33 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
#MACRO VARIABLES DEFINITION FOR FILE INCLUSION
LIB_NAMES = libft
# *************INSERT HERE IDENTIFICATION FOR SOURCE FILES******************** #
SRC_FILES = p_p_args.c ft_printf.c
HDR_FILES = libftprintf.h
#DEBUGGING FLAGS
CC_DEBUF_FLAGS = -g -fsanitize=address
#
#
#MAKE MACRO VARIABLES FOR MAKEFILE WORKING
SRC_DIR = src
HDR_DIR = headers
OBJ_DIR = obj
LOCAL_LIB_PATH = libraries
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
HDR = $(addprefix $(HDR_DIR)/, $(HDR_FILES))
CC = cc
CC_FLAGS = -Wall -Werror -Wextra -c
LINKER = ar
LINKER_FLAGS = -r
.PHONY = all clean fclean re
all : $(NAME)
	

$(NAME) : $(LIB_NAMES:=.a) $(LIB_NAMES:=.h) $(NAME:%.a=%.h) $(OBJ)
	$(LINKER) $(LINKER_FLAGS) $@ $?

$(LIB_NAMES:=.a) : 
	@cd $(LOCAL_LIB_PATH)/$*; echo Compiling LIBRARY: $@ .............; 	make re
	@cp $(LOCAL_LIB_PATH)/$*/$@ $@

$(LIB_NAMES:=.h) : 
	@cp $(LOCAL_LIB_PATH)/$*/$@ $@
	@cp $(LOCAL_LIB_PATH)/$*/$@ $(SRC_DIR)/$@

$(NAME:%.a=%.h) :
	@cp $(HDR_DIR)/* .

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o $@ $<

clean : 
	@echo Cleaning Oject Files
	@find . -name "*.o" -delete

fclean : clean
	@echo Cleaning all objects, executables and libraries
	@rm -f $(NAME)
	@find . -name "*.a" -delete
	@rm -f *.h

re : fclean all
	

obj/ft_printf.o : src/ft_printf.c obj/p_p_args.o $(NAME:%.a=%.h) $(LIB_NAMES:%=%.a) $(LIB_NAMES:%=%.h)
	echo estoy probando esta
	$(CC) $(CC_FLAGS) $(CC_DEBUF_FLAGS) src/ft_printf.c obj/p_p_args.o $(LIB_NAMES:%=%.a)

# FIN DE MAKE
