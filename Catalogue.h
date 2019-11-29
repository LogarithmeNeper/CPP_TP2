/*************************************************************************
Catalogue  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
using namespace std;

#include "Ville.h"
#include "Trajet.h"
#include "ListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue
//
//
//------------------------------------------------------------------------

class Catalogue
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  friend ostream & operator<<(ostream & out, const Catalogue & catalogue);

  void ajouter(Trajet* unTrajet);
  // Mode d'emploi : Ajoute le trajet au catalogue si ce dernier est valide
  //
  // Contrat : Déclenche une erreur si le trajet est NULL, déjà présent, ou non valide (cf Trajet#estValide)
  // Rajoute le trajet dans tous les autres cas.
  //

  void supprimer(Trajet* unTrajet);
  // Mode d'emploi :
  //
  // Contrat :
  //

  void rechercheParcours(const Ville & villeDepart, const Ville & villeArrivee) const;
  // Mode d'emploi :
  //
  // Contrat :
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

  /**
  * Liste des trajets du catalogue
  */
  ListeChaineeTrajets* trajets;

};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
