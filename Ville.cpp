/*************************************************************************
Ville  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe Ville (fichier Ville.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ville.h"
#include "StringHelper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ostream & operator<<(ostream & out, const Ville & ville)
{
  out << ville.nom;
  return out;
}

bool Ville::estValide() const
// Algorithme :
//
{
  if(nom == NULL) {
    std::cerr << "Le nom de la ville est invalide : NULL non autorisé." << std::endl;
    return false;
  }

  if(strempty(nom)) {
    std::cerr << "Le nom de la ville est invalide : nom vide non autorisé." << std::endl;
    return false;
  }

  return true;
}

//-------------------------------------------- Constructeurs - destructeur

Ville::Ville ( const char* unNom ) : nom(unNom)
{
  #ifdef MAP
  cout << "Appel au constructeur de Ville" << endl;
  #endif
} //----- Fin de Ville

Ville::~Ville (  )
{
  #ifdef MAP
  cout << "Appel au destructeur de Ville" << endl;
  #endif
} //----- Fin de ~Ville


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
