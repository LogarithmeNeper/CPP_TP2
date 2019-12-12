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
#Répertoire de la documentation (compte rendu + diagramme)
DOC_DIR=doc

PLANTUML_PATH=$(DOC_DIR)/plantuml.jar

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

doc:
	make -B class-diagram
	make -B memory-diagram
	make -B graph1-diagram
	make -B graph2-diagram
	make -B graph3-diagram

class-diagram: $(DOC_DIR)/class-diagram.pu

memory-diagram: $(DOC_DIR)/memory-diagram.pu

graph1-diagram: $(DOC_DIR)/graph1.pu

graph2-diagram: $(DOC_DIR)/graph2.pu

graph3-diagram: $(DOC_DIR)/graph3.pu

%.pu:
	java -jar $(PLANTUML_PATH) -tsvg $@
	java -jar $(PLANTUML_PATH) -tpng $@

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
	rm -rf $(DOC_DIR)/diagram.latex $(DOC_DIR)/diagram.png

.PHONY: clean doc
