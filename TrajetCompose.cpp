/*************************************************************************
TrajetCompose  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe TrajetCompose (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool TrajetCompose::estValide() const
// Algorithme :
//
{
  MaillonListeChaineeTrajets* maillonAct = listeTrajetsSimples->getPremierMaillon();

  while(maillonAct != nullptr)
  {
    if(!maillonAct->getTrajet()->estValide())
    {
      std::cerr << "Le sous-trajet " << maillonAct->getTrajet()->getNom() << " est invalide." << std::endl;
      return false;
    }
    maillonAct = maillonAct->getMaillonSuivant();
  }

  return Trajet::estValide();
} //----- Fin de estValide

void TrajetCompose::ajouter(TrajetSimple* unTrajetSimple)
// Algorithme :
//
{
  listeTrajetsSimples->ajouter(unTrajetSimple);
} //----- Fin de ajouter

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ( const char* unNom ) : Trajet(unNom)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de TrajetCompose" << endl;
  #endif

  listeTrajetsSimples = new ListeChaineeTrajets;

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au destructeur de TrajetCompose" << endl;
  #endif

  delete listeTrajetsSimples;

} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TrajetCompose::print(ostream & out) const
{
  MaillonListeChaineeTrajets* maillonAct = listeTrajetsSimples->getPremierMaillon();

  out << nom << " = ";

  while(maillonAct != nullptr)
  {
    out << "(" << *maillonAct->getTrajet() << ")";

    if(maillonAct->getMaillonSuivant() != nullptr)
    {
      out << " - ";
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }
}
