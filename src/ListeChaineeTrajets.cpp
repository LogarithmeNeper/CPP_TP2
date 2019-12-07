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

void ListeChaineeTrajets::ajouter(Trajet* unTrajet)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel de ListeChaineeTrajets::ajouter" << endl;
  #endif

  if(unTrajet == NULL)
  {
    cerr << "Impossible d'ajouter un trajet NULL." << endl;
  }
  else if(contient(unTrajet))
  {
    cerr << "La liste contient déjà ce trajet." << endl;
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
  }

} //----- Fin de ajouter

void ListeChaineeTrajets::supprimer(Trajet* unTrajet)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel de ListeChaineeTrajets::supprimer" << endl;
  #endif

  if(unTrajet == NULL)
  {
    cerr << "Impossible de supprimer un trajet NULL." << endl;
  }
  else if(!contient(unTrajet))
  {
    cerr << "La liste ne contient pas ce trajet." << endl;
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
        break;
      } else {
        maillonPrec = maillonAct;
        maillonAct = maillonAct->getMaillonSuivant();
      }
    }
  }
}

bool ListeChaineeTrajets::contient(const Trajet* unTrajet) const
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel de ListeChaineeTrajets::contient" << endl;
  #endif

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
  #ifdef MAP
  cout << "Appel de ListeChaineeTrajets::estVide" << endl;
  #endif

  return premierMaillon == nullptr && dernierMaillon == nullptr;
} //----- Fin de estVide

//-------------------------------------------- Constructeurs - destructeur

ListeChaineeTrajets::ListeChaineeTrajets ( ) : premierMaillon(nullptr), dernierMaillon(nullptr)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de ListeChaineeTrajets" << endl;
  #endif

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
