COMP=g++
FLAGS=-g -ansi -pedantic -Wall -std=c++11 -DMAP
EXEC=catalogue

catalogue: main.o
	$(COMP) -o $@ $^

main.o: Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o

#Crée un fichier binaire à partir d'un fichier source .cpp
%.o: %.cpp %.h
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(EXEC)

.PHONY: clean
