/*************************************************************************
ListeChaineeTrajets  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe ListeChaineeTrajets (fichier ListeChaineeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool ListeChaineeTrajets::ajouter(Trajet* unTrajet)
// Algorithme :
//
{
  if(unTrajet == NULL)
  {
    cerr << "Impossible d'ajouter un trajet NULL." << endl;
    return false;
  }
  else if(contient(unTrajet))
  {
    cerr << "La liste contient déjà ce trajet." << endl;
    return false;
  }
  else
  {
    MaillonListeChaineeTrajets* nouvMaillon = new MaillonListeChaineeTrajets(unTrajet);

    if(estVide()) {
      premierMaillon = nouvMaillon;
      dernierMaillon = nouvMaillon;
    } else {
      dernierMaillon->setMaillonSuivant(nouvMaillon);
      dernierMaillon = nouvMaillon;
    }

    ++taille;
    return true;
  }

} //----- Fin de ajouter

bool ListeChaineeTrajets::supprimer(Trajet* unTrajet)
// Algorithme :
//
{
  if(unTrajet == NULL)
  {
    cerr << "Impossible de supprimer un trajet NULL." << endl;
    return false;
  }
  else if(!contient(unTrajet))
  {
    cerr << "La liste ne contient pas ce trajet." << endl;
    return false;
  }
  else
  {
    MaillonListeChaineeTrajets* maillonPrec = nullptr;
    MaillonListeChaineeTrajets* maillonAct = premierMaillon;

    while(maillonAct != nullptr) {

      if(maillonAct->getTrajet() == unTrajet) {

        if(maillonAct == premierMaillon) {
          premierMaillon = maillonAct->getMaillonSuivant();
        }

        if(maillonAct == dernierMaillon) {
          dernierMaillon = maillonPrec;
        }

        if(maillonPrec != nullptr) {
          maillonPrec->setMaillonSuivant(maillonAct->getMaillonSuivant());
        }

        delete maillonAct;
        --taille;
        return true;
      } else {
        maillonPrec = maillonAct;
        maillonAct = maillonAct->getMaillonSuivant();
      }
    }

    return false;
  }
}

MaillonListeChaineeTrajets* ListeChaineeTrajets::getMaillonListeChaineeTrajets(unsigned int index) const
{
  if(index >= getTaille())
  {
    return nullptr;
  }
  else
  {
    unsigned int i = 0;
    MaillonListeChaineeTrajets* maillonAct = premierMaillon;

    while(maillonAct != nullptr) {

      if(i == index) {
        return maillonAct;
      }

      maillonAct = maillonAct->getMaillonSuivant();
      ++i;
    }

    return nullptr;
  }
}

unsigned int ListeChaineeTrajets::getTaille() const
{
  return taille;
}

bool ListeChaineeTrajets::contient(const Trajet* unTrajet) const
// Algorithme :
//
{
  MaillonListeChaineeTrajets* maillonAct = premierMaillon;

  while(maillonAct != nullptr)
  {
    if(maillonAct->getTrajet() == unTrajet)
    {
      return true;
    }
    maillonAct = maillonAct->getMaillonSuivant();
  }

  return false;

} //----- Fin de contient

bool ListeChaineeTrajets::estVide() const
{
  return taille == 0;
} //----- Fin de estVide

//-------------------------------------------- Constructeurs - destructeur

ListeChaineeTrajets::ListeChaineeTrajets ( ) : premierMaillon(nullptr), dernierMaillon(nullptr)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de ListeChaineeTrajets" << endl;
  #endif

  taille = 0;
} //----- Fin de ListeChaineeTrajets


ListeChaineeTrajets::~ListeChaineeTrajets ( )
// Algorithme : Parcourt la liste chainée et supprime les maillons un à un
//
{
  #ifdef MAP
  cout << "Appel au destructeur de ListeChaineeTrajets" << endl;
  #endif

  MaillonListeChaineeTrajets* maillonActuel = premierMaillon;
  MaillonListeChaineeTrajets* tmp;

  while(maillonActuel != nullptr) {
    tmp = maillonActuel;
    maillonActuel = maillonActuel->getMaillonSuivant();
    delete tmp;
  }

} //----- Fin de ~ListeChaineeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
