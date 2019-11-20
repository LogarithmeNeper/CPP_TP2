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
  // type Méthode ( liste des paramètres );
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

};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // TRAJET_SIMPLE_H
