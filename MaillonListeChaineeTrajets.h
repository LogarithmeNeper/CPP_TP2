/*************************************************************************
MaillonListeChaineeTrajets  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe MaillonListeChaineeTrajets (fichier MaillonListeChaineeTrajets.h) ----------------
#if ! defined ( MAILLON_LISTE_CHAINEE_TRAJETS_H )
#define MAILLON_LISTE_CHAINEE_TRAJETS_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe MaillonListeChaineeTrajets
//
//
//------------------------------------------------------------------------

class MaillonListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  friend ostream & operator<<(ostream & out, const MaillonListeChaineeTrajets & maillon);

  MaillonListeChaineeTrajets* getMaillonSuivant() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  void setMaillonSuivant(MaillonListeChaineeTrajets* unMaillon);
  // Mode d'emploi :
  //
  // Contrat :
  //

  Trajet* getTrajet() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur

  MaillonListeChaineeTrajets ( Trajet* unTrajet );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~MaillonListeChaineeTrajets ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  Trajet* trajet;

  MaillonListeChaineeTrajets* maillonSuivant;

};

//-------------------------------- Autres définitions dépendantes de MaillonListeChaineeTrajets

#endif // MAILLON_LISTE_CHAINEE_TRAJETS_H
