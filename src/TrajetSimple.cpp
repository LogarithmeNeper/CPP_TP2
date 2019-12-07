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
#include "StringHelper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool TrajetSimple::estValide() const
// Algorithme : Vérifie toutes les conditions de validité de manière séquentielle
//
{
  #ifdef MAP
  cout << "Appel de TrajetCompose::estValide" << endl;
  #endif

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
  #ifdef MAP
  cout << "Appel de TrajetCompose::afficher" << endl;
  #endif

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

TrajetSimple::TrajetSimple ( const char* uneVilleDepart, const char* uneVilleArrivee, const char* unTypeTransport )
  : villeDepart(uneVilleDepart), villeArrivee(uneVilleArrivee), typeTransport(unTypeTransport)
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
