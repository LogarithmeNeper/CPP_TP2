/*************************************************************************
Catalogue  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe Catalogue (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ajouterTrajet(Trajet* unTrajet)
// Algorithme :
//
{

} //----- Fin de Méthode

Catalogue::Catalogue ( )
// Algorithme : Crée le tableau de trajets sur le tas
//
{
  #ifdef MAP
  cout << "Appel au constructeur de Catalogue" << endl;
  #endif

  nbTrajets = 0;
  capaciteTrajets = 10;
  trajets = new Trajet[capaciteTrajets];

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme : Détruit le tableau de trajets
//
{
  #ifdef MAP
  cout << "Appel au destructeur de Catalogue" << endl;
  #endif

  delete [] trajets;

} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
