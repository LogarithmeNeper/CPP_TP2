/*************************************************************************
MaillonListeChaineeTrajets  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe MaillonListeChaineeTrajets (fichier MaillonListeChaineeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MaillonListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

MaillonListeChaineeTrajets* MaillonListeChaineeTrajets::getMaillonSuivant() const
{
  return maillonSuivant;
}

void MaillonListeChaineeTrajets::setMaillonSuivant(MaillonListeChaineeTrajets* unMaillon)
{
  maillonSuivant = unMaillon;
}

Trajet* MaillonListeChaineeTrajets::getTrajet() const
{
  return trajet;
}

//-------------------------------------------- Constructeurs - destructeur

MaillonListeChaineeTrajets::MaillonListeChaineeTrajets ( Trajet* unTrajet ) : trajet(unTrajet), maillonSuivant(nullptr)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de MaillonListeChaineeTrajets" << endl;
  #endif

} //----- Fin de MaillonListeChaineeTrajets

MaillonListeChaineeTrajets::~MaillonListeChaineeTrajets ( )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au destructeur de MaillonListeChaineeTrajets" << endl;
  #endif

  delete trajet;
} //----- Fin de ~MaillonListeChaineeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
