/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Charles Javerliat
    e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe Trajet (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "StringHelper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ostream & operator<< (ostream & out, const Trajet & unTrajet)
// Algorithme :
//
{
  unTrajet.print(out);
  return out;
}

bool Trajet::estValide() const
// Algorithme :
//
{

  if(nom == NULL) {
    std::cerr << "Le nom du trajet est invalide : NULL non autorisé." << std::endl;
    return false;
  }

  if(strempty(nom)) {
    std::cerr << "Le nom du trajet est invalide : nom vide non autorisé." << std::endl;
    return false;
  }

  return true;

} //----- Fin de estValide

const char* Trajet::getNom() const
// Algorithme :
//
{
  return nom;
} //----- Fin de getNom

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const char* unNom ) : nom(unNom)
{
#ifdef MAP
    cout << "Appel au constructeur de Trajet" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de Trajet" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
