/*************************************************************************
Catalogue  -  Un catalogue est un ensemble de trajets
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
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

// Algorithme : Attribue un indice au trajet, puis essaie de l'ajouter,
// si une erreur survient (trajet non valide), on procède à un retour en arrière.
bool Catalogue::ajouter(Trajet* unTrajet)
{
  //Affecte un indice au trajet
  if(unTrajet != nullptr)
  {
    unTrajet->setIndice(getTaille());
  }

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

// Algorithme : Essaie de supprimer un trajet du Catalogue.
// Décrèmente l'indice de tous les trajets suivants si il est effectivement supprimé.
// Si une erreur survient (trajet non valide), on procède à un retour en arrière.
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

// Algorithme : Vérifie de manière itérative que tous les trajets du catalogue
// sont valides.
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

// Algorithme : Cherche de manière itérative dans le catalogue les trajets ayant
// pour ville de départ la ville donnée en argument.
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

// Algorithme: Cherche de manière itérative un trajet du catalogue respectant
// la contrainte de ville de départ et d'arrivée.
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

// Algorithme : Cherche toutes les combinaisons de trajets respectant la contrainte
// de manière récursive dans le graphe de trajets.
bool Catalogue::rechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee) const
{
  //Le nombre d'arêtes du graphe
  unsigned int nbTrajets = getTaille();
  //Vrai pour une arête si elle a déjà été parcourue (initialisé à false)
  bool* trajetsParcourus = new bool[nbTrajets]();
  //Liste des trajets constituant le chemin
  ListeChaineeTrajets chemin;

  bool found = sousRechercheTrajetAvancee(villeDepart, villeArrivee, trajetsParcourus, &chemin);
  delete [] trajetsParcourus;

  //Vrai si un trajet a été trouvé
  return found;

} //----- Fin de rechercheTrajetAvancee

// Algorithme: Affiche de manière itérative tous les trajets dans le flux de sortie
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

//-------------------------------------------- Constructeurs - destructeur

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

// Algorithme : Cherche toutes les combinaisons de trajets respectant la contrainte
// de manière récursive dans le graphe de trajets.
bool Catalogue::sousRechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee, bool* trajetsParcourus, ListeChaineeTrajets* chemin) const
{
  ListeChaineeTrajets trajets = rechercheTrajetsEnDepartDe(villeDepart);
  MaillonListeChaineeTrajets* maillonAct = trajets.getPremierMaillon();

  //Vrai si un trajet a été trouvé
  bool found = false;

  //Pour chaque trajet possible à partir de la ville de départ donné en argument
  //on fait un appel récursif pour afficher les trajets possibles.
  while(maillonAct != nullptr)
  {
    if(!trajetsParcourus[maillonAct->getTrajet()->getIndice()])
    {
      Trajet* trajet = maillonAct->getTrajet();

      //On ne repassera pas par cette arête dans les appels fils
      trajetsParcourus[trajet->getIndice()] = true;
      chemin->ajouter(trajet);

      //Si la ville d'arrivée du trajet correspond à la ville d'arrivée qu'on cherche
      if(strcmp(trajet->getVilleArrivee(), villeArrivee) == 0)
      {
        found = true;

        //-----------------  Affichage d'un trajet solution --------------------
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
        //----------------------------------------------------------------------
      }

      found |= sousRechercheTrajetAvancee(trajet->getVilleArrivee(), villeArrivee, trajetsParcourus, chemin);

      //On rend à nouveau le trajet disponible pour les autres noeuds du même niveau du graphe
      chemin->supprimer(trajet);
      trajetsParcourus[trajet->getIndice()] = false;
    }

    maillonAct = maillonAct->getMaillonSuivant();
  }

  return found;
}
