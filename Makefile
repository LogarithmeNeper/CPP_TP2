COMP=g++
FLAGS=-ansi -pedantic -Wall -std=c++11 -DMAP

catalogue: main.o

main.o: Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o

#Crée un fichier binaire à partir d'un fichier source .cpp
%.o: %.cpp %.h
	$(COMP) $(FLAGS) -o $@ -c $^
