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

ostream & operator<<(ostream & out, const Catalogue & catalogue)
{
  out << *catalogue.trajets;
  return out;
}

void Catalogue::ajouter(Trajet* unTrajet)
// Algorithme : Ajoute un trajet à la liste de trajets.
// Si la liste n'est pas assez grande, multiplie sa capacité par 2.
//
{
  if(unTrajet == NULL)
  {
    cerr << "Impossible d'ajouter un trajet NULL au catalogue." << endl;
  }
  else if(trajets->contient(unTrajet))
  {
    cerr << "Le catalogue contient déjà ce trajet." << endl;
  }
  else
  {
    trajets->ajouter(unTrajet);
  }

} //----- Fin de ajouter

void Catalogue::supprimer(Trajet* unTrajet)
{
  if(unTrajet == NULL)
  {
    cerr << "Impossible de supprimer un trajet NULL du catalogue." << endl;
  }
  else if(!trajets->contient(unTrajet))
  {
    cerr << "Le catalogue ne contient pas ce trajet." << endl;
  }
  else
  {
    trajets->supprimer(unTrajet);
  }
} //----- Fin de supprimer

void Catalogue::rechercheParcours(const Ville & villeDepart, const Ville & villeArrivee) const
{

  

} //----- Fin de rechercheParcours

Catalogue::Catalogue ( )
// Algorithme : Crée le tableau de trajets sur le tas
//
{
  #ifdef MAP
  cout << "Appel au constructeur de Catalogue" << endl;
  #endif

  trajets = new ListeChaineeTrajets;

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme : Détruit le tableau de trajets
//
{
  #ifdef MAP
  cout << "Appel au destructeur de Catalogue" << endl;
  #endif

  delete trajets;

} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
