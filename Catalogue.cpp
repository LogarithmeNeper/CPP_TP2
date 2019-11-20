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

void Catalogue::ajouterTrajet(Trajet* unTrajet)
// Algorithme : Ajoute un trajet à la liste de trajets.
// Si la liste n'est pas assez grande, multiplie sa capacité par 2.
//
{

  if(nbTrajets == capaciteTrajets) {
    //On élargit la liste
    Trajet** newTrajets = new Trajet*[capaciteTrajets * 2];

    //Copie l'ancienne liste des trajets dans la nouvelle
    for(int i = 0; i < nbTrajets; i++) {
      newTrajets[i] = trajets[i];
    }

    delete [] trajets;
    trajets = newTrajets;
  }

  //On rajoute l'élément dans la liste
  trajets[nbTrajets++] = unTrajet;

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
