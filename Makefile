COMP=g++
FLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP
EXEC=catalogue

OBJS=main.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Ville.o TypeTransport.o \
ListeChaineeTrajets.o MaillonListeChaineeTrajets.o

HEADERS=Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h Ville.h TypeTransport.h \
ListeChaineeTrajets.h MaillonListeChaineeTrajets.h

catalogue: $(OBJS) $(HEADERS)
	$(COMP) -o $@ $^

#Crée un fichier binaire à partir d'un fichier source .cpp
%.o: %.cpp %.h
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf *.o $(EXEC)

.PHONY: clean
