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

void Catalogue::ajouter(Trajet* unTrajet)
{
  #ifdef MAP
  cout << "Appel de Catalogue::ajouter" << endl;
  #endif

  ListeChaineeTrajets::ajouter(unTrajet);

  //Si le catalogue n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::supprimer(unTrajet);
  }
}

void Catalogue::supprimer(Trajet* unTrajet)
{
  #ifdef MAP
  cout << "Appel de Catalogue::supprimer" << endl;
  #endif

  ListeChaineeTrajets::supprimer(unTrajet);

  //Si le catalogue n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::ajouter(unTrajet);
  }
}

bool Catalogue::estValide() const
{
  #ifdef MAP
  cout << "Appel de Catalogue::estValide" << endl;
  #endif

  MaillonListeChaineeTrajets* maillonAct = premierMaillon;

  while(maillonAct != nullptr)
  {
    if(!maillonAct->getTrajet()->estValide())
    {
      return false;
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }

  return true;
}

void Catalogue::rechercheParcours(const char* villeDepart, const char* villeArrivee) const
{
  #ifdef MAP
  cout << "Appel de Catalogue::rechercheParcours" << endl;
  #endif


} //----- Fin de rechercheParcours

void Catalogue::afficher(ostream & out) const
{
  #ifdef MAP
  cout << "Appel de Catalogue::afficher" << endl;
  #endif

  if(estVide())
  {
    out << "Le catalogue est vide.";
  }
  else
  {
    MaillonListeChaineeTrajets* maillonAct = premierMaillon;

    while(maillonAct != nullptr) {

      out << "- ";
      maillonAct->getTrajet()->afficher(out);

      if(maillonAct->getMaillonSuivant() != nullptr)
      {
        out << endl;
      }

      maillonAct = maillonAct->getMaillonSuivant();
    }
  }

} //----- Fin de afficher

Catalogue::Catalogue ( )
// Algorithme : Crée le tableau de trajets sur le tas
//
{
  #ifdef MAP
  cout << "Appel au constructeur de Catalogue" << endl;
  #endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme : Détruit le tableau de trajets
//
{
  #ifdef MAP
  cout << "Appel au destructeur de Catalogue" << endl;
  #endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
