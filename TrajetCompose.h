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
#include "TrajetSimple.h"
#include "ListeChaineeTrajets.h"

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>

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

  bool estValide() const override;
  // Mode d'emploi : Renvoie vrai ou faux selon si le trajet est valide ou non
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - Le nom du trajet est vide ou NULL
  //  - L'un des trajets simples n'est pas valide
  //  - Le trajet composé est vide
  //

  void ajouter(TrajetSimple* unTrajetSimple);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur

  TrajetCompose ( const char* unNom );
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

  void print(ostream & out) const override;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //----------------------------------------------------- Attributs protégés

  /**
  * Liste chainée de trajets simples
  */
  ListeChaineeTrajets* listeTrajetsSimples;

};

//-------------------------------- Autres définitions dépendantes de TrajetCompose

#endif // TRAJET_COMPOSE_H
