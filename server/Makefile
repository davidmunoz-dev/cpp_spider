##
## Makefile for make in /home/lezard/rendu/C++/tek3/cpp_spider/server
## 
## Made by Lezard
## Login   <lucas.onillon@epitech.eu>
## 
## Started on  Mon Oct  2 15:33:55 2017 Lezard
## Last update Mon Nov  6 17:28:18 2017 Lezard
##

TARGET	 = ./spider

CC	 = g++

SRC      = 	main.cpp		\
			Server.cpp		\
			Session.cpp	\
			SessionManager.cpp	\
			CommandInput.cpp\
			PacketManager.cpp

LIBS	+= -L/usr/lib/x86_64-linux-gnu -lboost_system -lpthread -lboost_serialization

CFLAGS   = -I./include/ -W -Werror -Wall -ansi -pedantic -std=c++11 $(LIBS)

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) ${LIBS}
	@echo $(TARGET)" compiled !"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "Binary files deleted"

fclean  : clean
	@$(rm) $(TARGET) $(LINK)
	@echo "Binary and executable files are deleted"

re      : fclean all

.PHONY: all clean fclean re
