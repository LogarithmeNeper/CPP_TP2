COMP=g++
FLAGS=-g -ansi -pedantic -Wno-unused-function -Wall -std=c++11 #-DMAP
EXEC=catalogue catalogue-test

#Répertoire des sources (.cpp et .h)
MAIN_SRC_DIR=src
#Répertoire des sources pour les tests
TEST_SRC_DIR=test
#Répertoire des fichiers objets (.o)
OBJ_DIR=build
#Répertoire des exécutables
BIN_DIR=bin

PLANTUML_PATH=$(DOC_DIR)/plantuml.jar

#Récupère la liste des fichiers .cpp dans src/ sauf le main.cpp
MAIN_SRC := $(shell find $(MAIN_SRC_DIR) -name '*.cpp' ! -name 'main.cpp')
#Récupère tous les headers des sources dans src/
MAIN_SRC_HEADERS := $(shell find $(MAIN_SRC_DIR) -name '*.h')
#Récupère la liste $(SRC) et remplace le répertoire $(SRC_DIR) par $(OBJ_DIR) et
#toutes les extensions .cpp en .o
MAIN_OBJ := $(patsubst $(MAIN_SRC_DIR)/%, $(OBJ_DIR)/%, $(MAIN_SRC:.cpp=.o))

#Récupère la liste des fichiers .cpp dans test/
TEST_SRC := $(shell find $(TEST_SRC_DIR) -name '*.cpp' ! -name 'test.cpp')
#Récupère tous les headers des sources dans test/
TEST_HEADERS := $(shell find $(TEST_SRC_DIR) -name '*.h')
#Récupère la liste $(TEST_SRC) et remplace le répertoire $(SRC_DIR) par $(OBJ_DIR) et
#toutes les extensions .cpp en .o
TEST_OBJ := $(patsubst $(TEST_SRC_DIR)/%, $(OBJ_DIR)/%, $(TEST_SRC:.cpp=.o))

all:
	make catalogue
	make catalogue-test
	@echo
	@echo ">>> Pour lancer le programme principal: './bin/catalogue'"
	@echo ">>> Pour lancer les tests: './bin/catalogue-test'"

catalogue: $(MAIN_OBJ) $(OBJ_DIR)/main.o $(MAIN_SRC_HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(MAIN_OBJ) $(OBJ_DIR)/main.o

catalogue-test: $(TEST_OBJ) $(MAIN_OBJ) $(OBJ_DIR)/test.o $(MAIN_SRC_HEADERS) $(TEST_SRC_HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(TEST_OBJ) $(MAIN_OBJ) $(OBJ_DIR)/test.o

$(OBJ_DIR)/%.o: $(MAIN_SRC_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: clean
