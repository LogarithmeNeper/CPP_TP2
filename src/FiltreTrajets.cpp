/*************************************************************************
FiltreTrajets  -  Filtre de trajets
-------------------
début                : 18/12/2019
copyright            : (C) 2019 par Charles Javerliat, Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr, fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <FiltreTrajets> (fichier FiltreTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
//------------------------------------------------------ Include personnel
#include "FiltreTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "MaillonListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ListeChaineeTrajets* FiltreTrajets::filtrerParType(const ListeChaineeTrajets& trajets, TypeTrajet typeTrajet)
{
  ListeChaineeTrajets* listeFiltree = new ListeChaineeTrajets;

  MaillonListeChaineeTrajets* maillonAct = trajets.getPremierMaillon();

  while(maillonAct != nullptr)
  {
    //Trajet actuel
    Trajet* t = maillonAct->getTrajet();

    //Si le type de filtrage est SIMPLE et que le trajet est une instance de TrajetSimple, on l'ajoute à la nouvelle liste
    //Si le type de filtrage est COMPOSE et que le trajet est une instance de TrajetCompose, on l'ajoute à la nouvelle liste
    if((typeTrajet == TypeTrajet::SIMPLE && dynamic_cast<TrajetSimple*>(t) != nullptr)
    || (typeTrajet == TypeTrajet::COMPOSE && dynamic_cast<TrajetCompose*>(t) != nullptr))
    {
      listeFiltree->ajouter(t);
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }

  return listeFiltree;
} //----- Fin de filtrerParType

ListeChaineeTrajets* FiltreTrajets::filtrerParVilleDepart(const ListeChaineeTrajets& trajets, const std::string& villeDepart)
{
  ListeChaineeTrajets* listeFiltree = new ListeChaineeTrajets;

  MaillonListeChaineeTrajets* maillonAct = trajets.getPremierMaillon();

  while(maillonAct != nullptr)
  {
    //Trajet actuel
    Trajet* t = maillonAct->getTrajet();

    //Si la ville de départ est strictement égale (comparaison caractère par caractère en interne)
    //au paramètre villeDepart du filtre, on l'ajoute à la nouvelle liste
    if(t->getVilleDepart() == villeDepart)
    {
      listeFiltree->ajouter(t);
    }
    maillonAct = maillonAct->getMaillonSuivant();
  }

  return listeFiltree;
} //----- Fin de filtrerParVilleDepart

ListeChaineeTrajets* FiltreTrajets::filtrerParVilleArrivee(const ListeChaineeTrajets& trajets, const std::string& villeArrivee)
{
  ListeChaineeTrajets* listeFiltree = new ListeChaineeTrajets;

  MaillonListeChaineeTrajets* maillonAct = trajets.getPremierMaillon();

  while(maillonAct != nullptr)
  {
    //Trajet actuel
    Trajet* t = maillonAct->getTrajet();

    //Si la ville d'arrivée est strictement égale (comparaison caractère par caractère en interne)
    //au paramètre villeArrivee du filtre, on l'ajoute à la nouvelle liste
    if(t->getVilleArrivee() == villeArrivee)
    {
      listeFiltree->ajouter(t);
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }
  return listeFiltree;
} //----- Fin de filtrerParVilleArrivee

ListeChaineeTrajets* FiltreTrajets::filtrerParVilleDepartEtArrivee(const ListeChaineeTrajets& trajets, const std::string& villeDepart, const std::string& villeArrivee)
{
  ListeChaineeTrajets* listeFiltree = new ListeChaineeTrajets;

  MaillonListeChaineeTrajets* maillonAct = trajets.getPremierMaillon();

  while(maillonAct != nullptr)
  {
    //Trajet actuel
    Trajet* t = maillonAct->getTrajet();

    //Si la ville d'arrivée et de départ sont strictements égales (comparaison caractère par caractère en interne)
    //aux paramètres villeDepart et villeArrivee du filtre, on l'ajoute à la nouvelle liste
    if(t->getVilleArrivee() == villeArrivee && t->getVilleDepart() == villeDepart)
    {
      listeFiltree->ajouter(t);
    }
    maillonAct = maillonAct->getMaillonSuivant();
  }

  return listeFiltree;
} //----- Fin de filtrerParVilleDepartEtArrivee

ListeChaineeTrajets* FiltreTrajets::filtrerParIntervalle(const ListeChaineeTrajets& trajets, const unsigned int n, const unsigned int m)
{
  ListeChaineeTrajets* listeFiltree = new ListeChaineeTrajets;

  MaillonListeChaineeTrajets* maillonAct = trajets.getPremierMaillon();

  unsigned int cpt(0);

  while(maillonAct != nullptr)
  {
    //Trajet actuel
    Trajet* t = maillonAct->getTrajet();

    //Si l'indice du trajet se trouve dans l'intervalle, on l'ajoute à la nouvelle liste
    if(cpt >= n && cpt <= m) {
      listeFiltree->ajouter(t);
    }

    maillonAct = maillonAct->getMaillonSuivant();
    ++cpt;
  }

  return listeFiltree;
} //----- Fin de filtrerParIntervalle
