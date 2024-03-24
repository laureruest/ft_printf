# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 07:59:23 by lruiz-es          #+#    #+#              #
#    Updated: 2024/03/24 09:19:17 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER_NAME = ft_printf.h
#MACRO VARIABLES DEFINITION FOR FILE INCLUSION
LIB_NAMES = libft
# *************INSERT HERE IDENTIFICATION FOR SOURCE FILES******************** #
SRC_FILES = lr_prints.c ft_printf.c uitoa.c uitohex.c
OBJ_FILES_LIBRARIES = ft_put_fd.o ft_strlen.o ft_ullitohex.o ft_toupper.o ft_itoa.o
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
CC_FLAGS = -Wall -Werror -Wextra -I $(HEADERS_LIBRARIES_DIR) -c
LINKER = ar
LINKER_FLAGS = -r
.PHONY = all clean fclean re
all : $(NAME)
	

$(NAME) : $(OBJ_LIBRARIES) $(OBJ)
	$(LINKER) $(LINKER_FLAGS) $@ $?

$(OBJ_LIBRARIES_DIR)/$(LIB_NAMES:=.a) : $(HEADERS_LIBRARIES_DIR)/$(LIB_NAMES:=.h)
	@if ! [ -d $(OBJ_LIBRARIES_DIR) ]; then mkdir $(OBJ_LIBRARIES_DIR); fi
	@cd $(LOCAL_LIB_PATH)/$(*F); echo Compiling LIBRARY: $(*F).........; make re
	@cp $(LOCAL_LIB_PATH)/$(*F)/$(@F) $@

$(HEADERS_LIBRARIES_DIR)/$(LIB_NAMES:=.h) : 
	@if ! [ -d $(HEADERS_LIBRARIES_DIR) ]; then mkdir $(HEADERS_LIBRARIES_DIR); fi
	@cp $(LOCAL_LIB_PATH)/$(*F)/$(@F) $@

$(HEADER_NAME) : 
	@echo "Te has borrado el archivo ft_printf.h, recuperatelo";

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@if ! [ -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
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
	

obj/ft_printf.o : src/ft_printf.c obj/lr_prints.o $(HEADER_NAME) $(OBJ_LIBRARIES_DIR)/$(LIB_NAMES:=.a) $(HEADERS_LIBRARIES_DIR)/$(LIB_NAMES:=.h)
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o obj/ft_printf.o src/ft_printf.c

obj/lr_prints.o : src/lr_prints.c obj/uitoa.o obj/uitohex.o $(HEADER_NAME) $(OBJ_LIBRARIES_DIR)/$(LIB_NAMES:=.a) $(HEADERS_LIBRARIES_DIR)/$(LIB_NAMES:=.h)
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -o obj/lr_prints.o src/lr_prints.c

# FIN DE MAKE
