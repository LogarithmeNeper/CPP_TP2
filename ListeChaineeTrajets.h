/*************************************************************************
ListeChaineeTrajets  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe ListeChaineeTrajets (fichier ListeChaineeTrajets.h) ----------------
#if ! defined ( LISTE_CHAINEE_TRAJETS_H )
#define LISTE_CHAINEE_TRAJETS_H

//--------------------------------------------------- Interfaces utilisées

#include "MaillonListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe ListeChaineeTrajets
//
//
//------------------------------------------------------------------------

class ListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  friend ostream & operator<<(ostream & out, const ListeChaineeTrajets & listeChaineeTrajets);

  void ajouter(Trajet* unTrajet);
  // Mode d'emploi :
  //
  // Contrat :
  //

  void supprimer(Trajet* unTrajet);
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool estVide() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool contient(const Trajet* unTrajet) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  MaillonListeChaineeTrajets* getPremierMaillon();
  // Mode d'emploi :
  //
  // Contrat :
  //

  MaillonListeChaineeTrajets* getDernierMaillon();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur

  ListeChaineeTrajets ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~ListeChaineeTrajets ( );
  // Mode d'emploi :
  //
  // Contrat : Supprime l'ensemble des maillons de la liste chainée en mémoire
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  MaillonListeChaineeTrajets* premierMaillon;

  MaillonListeChaineeTrajets* dernierMaillon;

};

//-------------------------------- Autres définitions dépendantes de ListeChaineeTrajets

#endif // LISTE_CHAINEE_TRAJETS_H
