/*************************************************************************
TrajetSimple  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe TrajetSimple (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool TrajetSimple::estValide() const
// Algorithme : Vérifie toutes les conditions de validité de manière séquentielle
//
{

  if(villeDepart == NULL) {
    std::cerr << "La ville de départ est invalide : NULL non autorisé." << std::endl;
    return false;
  }

  if(villeArrivee == NULL) {
    std::cerr << "La ville d'arrivée est invalide : NULL non autorisé." << std::endl;
    return false;
  }

  if(!villeDepart->estValide()) {
    std::cerr << "La ville de départ est invalide." << std::endl;
    return false;
  }

  if(!villeArrivee->estValide()) {
    std::cerr << "La ville d'arrivée est invalide." << std::endl;
    return false;
  }

  if(villeDepart == villeArrivee) {
    std::cerr << "La ville d'arrivée ne peut pas être identique à la ville de départ." << std::endl;
    return false;
  }

  if(typeTransport == NULL) {
    std::cerr << "Le type de transport est invalide : NULL non autorisé." << std::endl;
    return false;
  }

  if(!typeTransport->estValide()) {
    std::cerr << "Le type de transport est invalide." << std::endl;
    return false;
  }

  return Trajet::estValide();
} //----- Fin de estValide


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const char* unNom, Ville* uneVilleDepart, Ville* uneVilleArrivee, TypeTransport* unTypeTransport )
  : Trajet(unNom), villeDepart(uneVilleDepart), villeArrivee(uneVilleArrivee), typeTransport(unTypeTransport)
{
  #ifdef MAP
  cout << "Appel au constructeur de TrajetSimple" << endl;
  #endif
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple (  )
{
  #ifdef MAP
  cout << "Appel au destructeur de TrajetSimple" << endl;
  #endif
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TrajetSimple::print(ostream & out) const
{
  out << nom << " = de " << *villeDepart << " à " << *villeArrivee << " en " << *typeTransport;
}
