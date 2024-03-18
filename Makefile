# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 07:59:23 by lruiz-es          #+#    #+#              #
#    Updated: 2024/03/18 21:39:24 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
#MACRO VARIABLES DEFINITION FOR FILE INCLUSION
LIB_NAMES = libft
# *************INSERT HERE IDENTIFICATION FOR SOURCE FILES******************** #
SRC_FILES = lr_prints.c ft_printf.c
OBJ_FILES_LIBRARIES = ft_put_fd.o ft_strlen.o ft_ullitohex.o
#
#
#DEBUGGING FLAGS
CC_DEBUF_FLAGS = -g -fsanitize=address
#
#
#MAKE MACRO VARIABLES FOR MAKEFILE WORKING
SRC_DIR = src
OBJ_DIR = obj
OBJ_LIBRARIES_DIR = lib
HEADERS_LIBRARIES_DIR = include
LOCAL_LIB_PATH = libraries
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
HDR = $(addprefix $(HDR_DIR)/, $(HDR_FILES))
OBJ_LIBRARIES = $(addprefix $(OBJ_LIBRARIES_DIR)/, $(OBJ_FILES_LIBRARIES))
CC = cc
CC_FLAGS = -Wall -Werror -Wextra -I include -c
LINKER = ar
LINKER_FLAGS = -r
.PHONY = all clean fclean re
all : $(NAME)
	

$(NAME) : $(OBJ_LIBRARIES) $(OBJ)
	$(LINKER) $(LINKER_FLAGS) $@ $<

$(OBJ_LIBRARIES_DIR)/$(LIB_NAMES:=.a) : $(HEADERS_LIBRARIES_DIR)/$(LIB_NAMES:=.h)
	mkdir $(OBJ_LIBRARIES_DIR)
	@cd $(LOCAL_LIB_PATH)/$(*F); echo Compiling LIBRARY: $(*F).........; make re
	@cp $(LOCAL_LIB_PATH)/$(*F)/$(@F) $@

$(HEADERS_LIBRARIES_DIR)/$(LIB_NAMES:=.h) : 
	mkdir $(HEADERS_LIBRARIES_DIR)
	@cp $(LOCAL_LIB_PATH)/$(*F)/$(@F) $@

$(NAME:%.a=%.h) : $(HDR)
	@cp $< $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o $@ $<

$(OBJ_LIBRARIES) : $(OBJ_LIBRARIES_DIR)/$(LIB_NAMES:=.a)
	@cd $(OBJ_LIBRARIES_DIR); $(LINKER) -x $(<F) $(@F)

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
	

obj/ft_printf.o : src/ft_printf.c obj/lr_prints.o $(NAME:%.a=%.h) lib/$(LIB_NAMES:=.a) include/$(LIB_NAMES:=.h)
	@echo estoy probando esta
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o obj/ft_printf.o src/ft_printf.c

# FIN DE MAKE
