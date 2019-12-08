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

bool TrajetCompose::ajouter(Trajet* unTrajet)
{
  ListeChaineeTrajets::ajouter(unTrajet);

  //Si le trajet n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::supprimer(unTrajet);
    return false;
  }

  return true;
}

bool TrajetCompose::supprimer(Trajet* unTrajet)
{
  ListeChaineeTrajets::supprimer(unTrajet);

  //Si le trajet n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::ajouter(unTrajet);
    return false;
  }

  return true;
}

bool TrajetCompose::estValide() const
// Algorithme : On vérifie d'abord si la liste est vide. Sinon, on parcourt tous
// les sous-trajets pour vérifier qu'ils soient tous valides.
//
{
  if(estVide())
  {
    cerr << "Le trajet composé est vide." << endl;
    return false;
  }
  else if(strcmp(getVilleDepart(), getVilleArrivee()) == 0)
  {
    cerr << "Le trajet composé est invalide. La ville de départ ne peut pas être égale à la ville d'arrivée." << endl;
    return false;
  }
  else
  {
    MaillonListeChaineeTrajets* maillonAct = premierMaillon;

    //On vérifie que chaque trajet composant le trajet composé est valide
    while(maillonAct != nullptr)
    {

      if(!maillonAct->getTrajet()->estValide())
      {
        cerr << "Le sous-trajet (";
        maillonAct->getTrajet()->afficher(cerr);
        cerr << ") est invalide." << endl;
        return false;
      }
      else if(maillonAct->getMaillonSuivant() != nullptr
              && strcmp(maillonAct->getMaillonSuivant()->getTrajet()->getVilleDepart(), maillonAct->getTrajet()->getVilleArrivee()) != 0)
      {
        cerr << "Les trajets (";
        maillonAct->getTrajet()->afficher(cerr);
        cerr << ") et (";
        maillonAct->getMaillonSuivant()->getTrajet()->afficher(cerr);
        cerr << ") ne coïncident pas (t1.villeArrivee != t2.villeDepart)." << endl;
        return false;
      }

      maillonAct = maillonAct->getMaillonSuivant();
    }
  }

  return true;
} //----- Fin de estValide

void TrajetCompose::afficher(ostream & out) const
// Algorithme : On parcourt tous les sous-trajets pour les afficher un par un
// à la suite dans le flux de sortie.
//
{
  if(estVide())
  {
    out << "Le trajet composé est vide.";
  }
  else
  {
    MaillonListeChaineeTrajets* maillonAct = premierMaillon;

    out << "Trajet composé: ";

    while(maillonAct != nullptr)
    {
      out << '(';
      maillonAct->getTrajet()->afficher(out);
      out << ')';

      if(maillonAct->getMaillonSuivant() != nullptr)
      {
        out << " + ";
      }

      maillonAct = maillonAct->getMaillonSuivant();
    }
  }
}

const char* TrajetCompose::getVilleDepart() const
{
  if(estVide())
  {
    return nullptr;
  }
  else
  {
    return premierMaillon->getTrajet()->getVilleDepart();
  }
}

const char* TrajetCompose::getVilleArrivee() const
{
  if(estVide())
  {
    return nullptr;
  }
  else
  {
    return dernierMaillon->getTrajet()->getVilleArrivee();
  }
}

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ( ) : ListeChaineeTrajets()
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de TrajetCompose" << endl;
  #endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au destructeur de TrajetCompose" << endl;
  #endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
