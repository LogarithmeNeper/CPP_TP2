/*************************************************************************
MaillonListeChaineeTrajets  -  Maillon d'une liste chaînée contenant un trajet
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
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
// La classe MaillonListeChaineeTrajets permet de contenir un trajet dans une
// liste chaînée (Cf ListeChaineeTrajets) et de pointer vers le maillon suivant.
//
//------------------------------------------------------------------------

class MaillonListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  MaillonListeChaineeTrajets* getMaillonSuivant() const;
  // Mode d'emploi : Retourne le pointeur vers le maillon suivant le maillon actuel
  //
  // Contrat :
  // - Renvoie nullptr si il n'y a pas de maillon suivant
  //

  void setMaillonSuivant(MaillonListeChaineeTrajets* unMaillon);
  // Mode d'emploi : Met à jour le pointeur vers le maillon suivant
  //
  // Contrat :
  // - Met à jour le pointeur vers le maillon suivant

  Trajet* getTrajet() const;
  // Mode d'emploi : Retourne le pointeur du trajet contenu dans le maillon
  //
  // Contrat :
  // - Retourne le pointeur du trajet contenu dans le maillon

  //-------------------------------------------- Constructeurs - destructeur

  MaillonListeChaineeTrajets ( Trajet* unTrajet );

  virtual ~MaillonListeChaineeTrajets ( );

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  //Le pointeur du trajet contenu dans le maillon
  Trajet* trajet;

  //Le pointeur vers le maillon suivant
  MaillonListeChaineeTrajets* maillonSuivant;

};

//-------------------------------- Autres définitions dépendantes de MaillonListeChaineeTrajets

#endif // MAILLON_LISTE_CHAINEE_TRAJETS_H
