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

void TrajetSimple::afficher() const
// Algorithme :
//
{

} //----- Fin de afficher

bool TrajetSimple::estValide() const
// Algorithme : Vérifie toutes les conditions de validité de manière séquentielle
//
{
  //Si au moins un des deux noms est NULL
  if(villeDepart == NULL || villeArrivee == NULL) {
    return false;
  }

  //Si au moins un des deux noms est vide
  if(strempty(villeDepart) || strempty(villeArrivee)) {
    return false;
  }

  //Si la ville d'arrivée est égale à la vide de départ
  if(strcmp(villeDepart, villeArrivee) == 0) {
    return false;
  }

  //Si le type de transport est NULL
  if(typeTransport == NULL) {
    return false;
  }

  //Si le type de transport est vide
  if(strempty(typeTransport)) {
    return false;
  }

  return true;
} //----- Fin de estValide


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de TrajetSimple" << endl;
  #endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au destructeur de TrajetSimple" << endl;
  #endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Méthodes privées

bool TrajetSimple::strempty(const char* str)
// Algorithme : Parcourt tous les caractères de la chaîne de caractère
// Dès qu'un caractère différent d'une espace est rencontré, retourne faux
// Si la chaîne de caractères ne contient aucun caractère ou que des espaces, retourne vrai
{

  for(unsigned int i = 0; i < strlen(str); i++)
  {
    if(str[i] != ' ')
    {
      return false;
    }
  }
  return true;
}
