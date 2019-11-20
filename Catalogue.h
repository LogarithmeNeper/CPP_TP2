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

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

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

  void ajouterTrajet(Trajet* unTrajet);
  // Mode d'emploi : Ajoute le trajet au catalogue si ce dernier est valide
  //
  // Contrat : Déclenche une erreur si le trajet est NULL, déjà présent, ou non valide (cf Trajet#estValide)
  // Rajoute le trajet dans tous les autres cas.
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

  bool contient(const Trajet* unTrajet) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //----------------------------------------------------- Attributs protégés
  /**
  * Nombre de trajets dans le catalogue
  */
  unsigned int nbTrajets;

  /**
  * Capacité de la liste de trajets
  */
  unsigned int capaciteTrajets;

  /**
  * Liste des trajets du catalogue
  */
  Trajet** trajets;

};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
