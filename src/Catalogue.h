/*************************************************************************
Catalogue  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) ----------------
#if !defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
using namespace std;

#include "Trajet.h"
#include "ListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue
//
//
//------------------------------------------------------------------------

class Catalogue : public ListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  bool ajouter(Trajet* unTrajet) override;

  bool supprimer(Trajet* unTrajet) override;

  bool estValide() const;
  // Mode d'emploi : Renvoie vrai ou faux selon si le catalogue est valide
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - L'un des trajets n'est pas valide
  // Affiche un message d'erreur sur la sortie standard d'erreur si une des conditions n'est pas respectée
  //

  ListeChaineeTrajets rechercheTrajetsEnDepartDe(const char* villeDepart) const;

  bool rechercheTrajetSimple(const char* villeDepart, const char* villeArrivee) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool sousRechercheTrajetAvancee(Trajet* trajet, const char* villeArrivee, bool* trajetsParcourus, ListeChaineeTrajets* chemin) const;

  bool rechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  void afficher(ostream & out) const;
  // Mode d'emploi : Affiche le catalogue sur le flux de sortie
  //
  // Contrat : Affiche le catalogue sur le flux de sortie au format:
  // Si le catalogue n'est pas vide:
  // "Trajet i - {définition trajet_i}" n fois avec un saut de ligne entre chaque trajet
  // Sinon:
  // "Le catalogue est vide."
  //
  // Sans retour à la ligne à la fin
  //
  //

  //-------------------------------------------- Constructeurs - destructeur

  Catalogue ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Catalogue ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
