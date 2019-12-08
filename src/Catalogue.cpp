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

#include <string.h>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Catalogue::ajouter(Trajet* unTrajet)
{
  ListeChaineeTrajets::ajouter(unTrajet);

  //Si le catalogue n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::supprimer(unTrajet);
    return false;
  }

  return true;
}

bool Catalogue::supprimer(Trajet* unTrajet)
{
  ListeChaineeTrajets::supprimer(unTrajet);

  //Si le catalogue n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::ajouter(unTrajet);
    return false;
  }

  return true;
}

bool Catalogue::estValide() const
{
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

void Catalogue::rechercheTrajetSimple(const char* villeDepart, const char* villeArrivee) const
{

  MaillonListeChaineeTrajets* maillonAct = premierMaillon;

  while(maillonAct != nullptr) {
    if(strcmp(maillonAct->getTrajet()->getVilleDepart(), villeDepart) == 0
      && strcmp(maillonAct->getTrajet()->getVilleArrivee(), villeArrivee) == 0)
    {
      cout << "- ";
      maillonAct->getTrajet()->afficher(cout);
      cout << endl;

      maillonAct = maillonAct->getMaillonSuivant();
    }
  }

} //----- Fin de rechercheTrajetSimple

void Catalogue::rechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee) const
{


} //----- Fin de rechercheTrajetAvancee


void Catalogue::afficher(ostream & out) const
{
  if(estVide())
  {
    out << "Le catalogue est vide.";
  }
  else
  {
    int i = 1;
    MaillonListeChaineeTrajets* maillonAct = premierMaillon;

    while(maillonAct != nullptr) {

      out << "Trajet " << i << " - ";
      maillonAct->getTrajet()->afficher(out);

      if(maillonAct->getMaillonSuivant() != nullptr)
      {
        out << endl;
      }

      maillonAct = maillonAct->getMaillonSuivant();
      ++i;
    }
  }

} //----- Fin de afficher

Catalogue::Catalogue ( ) : ListeChaineeTrajets()
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
