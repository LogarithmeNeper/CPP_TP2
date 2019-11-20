/*************************************************************************
TrajetCompose  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe TrajetCompose (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe TrajetCompose
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //


  //------------------------------------------------- Surcharge d'opérateurs
  TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
  // Mode d'emploi :
  //
  // Contrat :
  //


  //-------------------------------------------- Constructeurs - destructeur
  TrajetCompose ( const TrajetCompose & unTrajetCompose );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  TrajetCompose ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TrajetCompose ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  /**
  * Liste ordonnée de trajets simples
  */
  TrajetSimple** trajetsSimples;

};

//-------------------------------- Autres définitions dépendantes de TrajetCompose

#endif // TRAJET_COMPOSE_H
