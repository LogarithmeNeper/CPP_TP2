COMP=g++
FLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP
EXEC=catalogue catalogue-test

#Répertoire des sources (.cpp et .h)
SRC_DIR=src
#Répertoire des sources pour les tests
SRC_TEST_DIR=test
#Répertoire des fichiers objets (.o)
OBJ_DIR=build
#Répertoire des exécutables
BIN_DIR=bin

#Récupère la liste des fichiers .cpp sauf le main.cpp
SRC := $(shell find $(SRC_DIR) -name '*.cpp' ! -name 'main.cpp')

#Récupère tous les headers des sources
HEADERS := $(shell find $(SRC_DIR) -name '*.h')

#Récupère la liste $(SRC) et remplace le répertoire $(SRC_DIR) par $(OBJ_DIR) et
#toutes les extensions .cpp en .o
OBJ	:= $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

CATALOGUE_SRC = $(SRC_DIR)/main.cpp $(SRC)
CATALOGUE_OBJ = $(OBJ_DIR)/main.o $(OBJ)

CATALOGUE_TEST_SRC = $(SRC_TEST_DIR)/test.cpp $(SRC)
CATALOGUE_TEST_OBJ = $(OBJ_DIR)/test.o $(OBJ)

all:
	make catalogue
	make catalogue-test
	@echo
	@echo ">>> Pour lancer le programme principal: './bin/catalogue'"
	@echo ">>> Pour lancer les tests: './bin/catalogue-test'"

catalogue: $(CATALOGUE_OBJ) $(HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(CATALOGUE_OBJ)

catalogue-test: $(CATALOGUE_TEST_OBJ) $(HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(CATALOGUE_TEST_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: $(SRC_TEST_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: clean
