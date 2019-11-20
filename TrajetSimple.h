/*************************************************************************
TrajetSimple  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe TrajetSimple (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe TrajetSimple
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void afficher() const override;
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool estValide() const override;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur

  TrajetSimple ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TrajetSimple ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  /**
  * Nom de la ville de départ du trajet
  */
  char* villeDepart;
  /**
  * Nom de la ville d'arrivée du trajet
  */
  char* villeArrivee;
  /**
  * Type de transport pour aller d'une ville à l'autre
  */
  char* typeTransport;

private:

  static bool strempty(const char* str);
  // Mode d'emploi : Retourne vrai si la chaîne de caractères est vide
  //
  // Contrat : Si la chaîne de caractère ne contient aucun caractères ou que des espaces, retourne vrai
  //

};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // TRAJET_SIMPLE_H
