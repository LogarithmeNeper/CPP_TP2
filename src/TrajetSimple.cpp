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
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "StringHelper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool TrajetSimple::estValide() const
// Algorithme : Vérifie toutes les conditions de validité de manière séquentielle
//
{
  if(villeDepart == NULL) {
    cerr << "La ville de départ est invalide : NULL non autorisé." << endl;
    return false;
  }

  if(strempty(villeDepart)) {
    cerr << "Le nom de la ville de départ est invalide : nom vide non autorisé." << endl;
    return false;
  }

  if(villeArrivee == NULL) {
    cerr << "La ville d'arrivée est invalide : NULL non autorisé." << endl;
    return false;
  }

  if(strempty(villeArrivee)) {
    cerr << "Le nom de la ville d'arrivée est invalide : nom vide non autorisé." << endl;
    return false;
  }

  if(strcmp(villeDepart, villeArrivee) == 0) {
    cerr << "Le nom de la ville d'arrivée ne peut pas être identique au nom de la ville de départ." << endl;
    return false;
  }

  if(typeTransport == NULL) {
    cerr << "Le type de transport est invalide : NULL non autorisé." << endl;
    return false;
  }

  if(strempty(typeTransport)) {
    cerr << "Le nom du type de transport est invalide : nom vide non autorisé." << endl;
    return false;
  }

  return true;
} //----- Fin de estValide

void TrajetSimple::afficher(ostream & out) const
{
  out << "Trajet simple de " << villeDepart << " à " << villeArrivee << " en " << typeTransport;
}

const char* TrajetSimple::getVilleDepart() const
{
  return villeDepart;
}

const char* TrajetSimple::getVilleArrivee() const
{
  return villeArrivee;
}

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const char* uneVilleDepart, const char* uneVilleArrivee, const char* unTypeTransport ) : Trajet()
{
  #ifdef MAP
  cout << "Appel au constructeur de TrajetSimple" << endl;
  #endif

  //On copie le contenu des char* pour ne pas modifier les valeurs de l'appelant
  char* villeDepartCopy = new char[strlen(uneVilleDepart) + 1];
  char* villeArriveeCopy = new char[strlen(uneVilleArrivee) + 1];
  char* typeTransportCopy = new char[strlen(unTypeTransport) + 1];
  strcpy(villeDepartCopy, uneVilleDepart);
  strcpy(villeArriveeCopy, uneVilleArrivee);
  strcpy(typeTransportCopy, unTypeTransport);
  villeDepart = villeDepartCopy;
  villeArrivee = villeArriveeCopy;
  typeTransport = typeTransportCopy;

} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple (  )
{
  #ifdef MAP
  cout << "Appel au destructeur de TrajetSimple" << endl;
  #endif

  delete [] villeDepart;
  delete [] villeArrivee;
  delete [] typeTransport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
