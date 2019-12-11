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
  //Affecte un indice au trajet
  unTrajet->setIndice(getTaille());

  ListeChaineeTrajets::ajouter(unTrajet);

  //Si le catalogue n'est pas valide en l'état, on revient en arrière
  if(!estValide())
  {
    ListeChaineeTrajets::supprimer(unTrajet);

    //Supprime le trajet du tas
    delete unTrajet;

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

  //On décrémente tous les indices des trajets suivants
  MaillonListeChaineeTrajets* maillonAct = get(unTrajet->getIndice());

  while(maillonAct != nullptr)
  {
    maillonAct->getTrajet()->setIndice(maillonAct->getTrajet()->getIndice() - 1);
    maillonAct = maillonAct->getMaillonSuivant();
  }

  //Supprime le trajet du tas
  delete unTrajet;

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

bool Catalogue::rechercheTrajetSimple(const char* villeDepart, const char* villeArrivee) const
{
  bool found = false;
  MaillonListeChaineeTrajets* maillonAct = premierMaillon;

  while(maillonAct != nullptr) {
    if(strcmp(maillonAct->getTrajet()->getVilleDepart(), villeDepart) == 0
    && strcmp(maillonAct->getTrajet()->getVilleArrivee(), villeArrivee) == 0)
    {
      cout << endl << " - ";
      maillonAct->getTrajet()->afficher(cout);
      found = true;
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }

  return found;

} //----- Fin de rechercheTrajetSimple

ListeChaineeTrajets Catalogue::rechercheTrajetsEnDepartDe(const char* villeDepart) const
{
  ListeChaineeTrajets liste;

  MaillonListeChaineeTrajets* maillonAct = premierMaillon;

  while(maillonAct != nullptr)
  {
    if(strcmp(maillonAct->getTrajet()->getVilleDepart(), villeDepart) == 0)
    {
      liste.ajouter(maillonAct->getTrajet());
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }

  return liste;
}

bool Catalogue::sousRechercheTrajetAvancee(Trajet* trajet, const char* villeArrivee, bool* trajetsParcourus, ListeChaineeTrajets* chemin) const
{
  bool found = false;
  trajetsParcourus[trajet->getIndice()] = true;
  chemin->ajouter(trajet);

  if(strcmp(trajet->getVilleArrivee(), villeArrivee) == 0)
  {
    found = true;

    //Affiche le trajet
    MaillonListeChaineeTrajets* maillonAct = chemin->getPremierMaillon();

    cout << endl << " - ";

    while(maillonAct != nullptr)
    {
      maillonAct->getTrajet()->afficher(cout);

      if(maillonAct->getMaillonSuivant() != nullptr)
      {
        cout << " + ";
      }

      maillonAct = maillonAct->getMaillonSuivant();
    }
  }
  else
  {
    ListeChaineeTrajets adj = rechercheTrajetsEnDepartDe(trajet->getVilleArrivee());
    MaillonListeChaineeTrajets* maillonAct = adj.getPremierMaillon();

    while(maillonAct != nullptr)
    {
      if(!trajetsParcourus[maillonAct->getTrajet()->getIndice()])
      {
        found |= sousRechercheTrajetAvancee(maillonAct->getTrajet(), villeArrivee, trajetsParcourus, chemin);
      }
      maillonAct = maillonAct->getMaillonSuivant();
    }
  }

  chemin->supprimer(trajet);
  trajetsParcourus[trajet->getIndice()] = false;

  return found;
}

bool Catalogue::rechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee) const
{
  bool found = false;
  unsigned int nbTrajets = getTaille();

  bool* trajetsParcourus = new bool[nbTrajets];
  ListeChaineeTrajets chemin;

  for(unsigned int i = 0; i < nbTrajets; i++)
  {
    trajetsParcourus[i] = false;
  }

  ListeChaineeTrajets adj = rechercheTrajetsEnDepartDe(villeDepart);
  MaillonListeChaineeTrajets* maillonAct = adj.getPremierMaillon();

  while(maillonAct != nullptr)
  {
    found |= sousRechercheTrajetAvancee(maillonAct->getTrajet(), villeArrivee, trajetsParcourus, &chemin);
    maillonAct = maillonAct->getMaillonSuivant();
  }

  return found;

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
      out << " (indice = " << maillonAct->getTrajet()->getIndice() << ")";

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

  //Suppression des trajets sur le tas
  MaillonListeChaineeTrajets* maillonAct = premierMaillon;

  while(maillonAct != nullptr)
  {
    delete maillonAct->getTrajet();
    maillonAct = maillonAct->getMaillonSuivant();
  }

} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
