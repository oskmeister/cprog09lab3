# INFO ######################################################################
#																			#
# Note: `make clean` removes the directory obj and all its contents.		#
#############################################################################

# VARS ######################################################################

CC			= gcc
CXX			= g++ 
CFLAGS		= -Wall -Wextra -pedantic
CXXFLAGS	= $(CFLAGS) -Wnon-virtual-dtor -Wreorder -Weffc++ \
			  -Woverloaded-virtual

SRC			= src
BIN			= obj
CLEAN		= $(BIN) game

# RULES #####################################################################

all : game

game : $(BIN)/main.o $(BIN)/actor.o
	$(CXX) $(CXXFLAGS) $^ -o $@

doc :
	doxygen

# DEPENDENCIES ##############################################################

$(BIN)/actor.o : $(SRC)/actor.cpp $(SRC)/actor.h $(SRC)/item.h \
	$(SRC)/scene.h

$(BIN)/item.o : $(SRC)/item.h $(SRC)/item.cpp

# GENERAL RULES #############################################################

$(BIN)/%.o : $(SRC)/%.o
	mkdir -p $(BIN)
	mv $< $@

clean :
	 touch $(CLEAN) 2>/dev/null
	-rm -r $(CLEAN) 2>/dev/null

#############################################################################
