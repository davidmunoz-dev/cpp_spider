##
## Makefile for  in /home/beche/rendu/cpp_spider/server
## 
## Made by beche
## Login   <francois.beche@epitech.eu>
## 
## Started on  Wed Oct  4 12:55:38 2017 beche
## Last update Sun Nov  5 23:30:44 2017 beche
##

CC	=	 g++

RM	=	rm -rf

SRC	=	test.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	 = -Wall -Werror -ansi -lboost_system -I./include -lpthread -lboost_serialization -g


INC	=	-I./include

NAME	=	client

$(NAME)	:	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

all:		$(NAME)
		@echo $(SRC)


clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
