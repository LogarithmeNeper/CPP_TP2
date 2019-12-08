/*************************************************************************
TrajetCompose  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe TrajetCompose (fichier TrajetCompose.h) ----------------
#if !defined ( TRAJET_COMPOSE_H )
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

class TrajetCompose : public Trajet, public ListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  bool ajouter(Trajet* unTrajet) override;

  bool supprimer(Trajet* unTrajet) override;

  bool estValide() const override;
  // Mode d'emploi : Renvoie vrai ou faux selon si le trajet est valide
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - L'un des trajets simples n'est pas valide
  //  - Pour deux trajets successifs, la ville d'arrivée du premier ne correspond
  //    pas à la ville de départ de l'autre
  //  - Le trajet composé est vide
  //  - La ville de départ est égale à la ville d'arrivée
  // Affiche un message d'erreur sur la sortie standard d'erreur si une des conditions n'est pas respectée
  //

  void afficher(ostream & out) const override;
  // Mode d'emploi : Affiche la définition du trajet sur la sortie standard
  //
  // Contrat : Affiche la description du trajet sur le stdout au format:
  // Si le trajet composé n'est pas vide:
  // "Trajet composé: ({description trajetSimple1}) + ({description trajetSimple2}) + ({...})"
  // Sinon:
  // "Le trajet composé est vide."
  //
  // Sans retour à la ligne
  //

  const char* getVilleDepart() const override;

  const char* getVilleArrivee() const override;

  //-------------------------------------------- Constructeurs - destructeur

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

};

//-------------------------------- Autres définitions dépendantes de TrajetCompose

#endif // TRAJET_COMPOSE_H
