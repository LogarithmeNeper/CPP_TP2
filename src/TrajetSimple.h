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

  bool estValide() const override;
  // Mode d'emploi : Renvoie vrai ou faux selon si le trajet est valide ou non
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - Le nom de la ville de départ est NULL
  //  - Le nom de la ville de départ est vide
  //  - Le nom de la ville d'arrivée est NULL
  //  - Le nom de la ville d'arrivée est vide
  //  - Le nom de la ville de départ est égale à la ville d'arrivée (sensible à la casse)
  //  - Le nom du type de transport est NULL
  //  - Le nom du type de transport est vide
  // Affiche un message d'erreur sur la sortie standard d'erreur si une des conditions n'est pas respectée
  //

  void afficher(ostream & out) const override;
  // Mode d'emploi : Affiche la définition du trajet sur le flux de sortie
  //
  // Contrat : Affiche la description du trajet sur le flux de sortie au format:
  // "Trajet simple de {villeDepart} à {villeArrivee} en {typeTransport}"
  // Sans retour à la ligne
  //

  const char* getVilleDepart() const override;

  const char* getVilleArrivee() const override;

  //-------------------------------------------- Constructeurs - destructeur

  TrajetSimple ( const char* uneVilleDepart, const char* uneVilleArrivee, const char* unTypeTransport );
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
  const char* villeDepart;
  /**
  * Nom de la ville d'arrivée du trajet
  */
  const char* villeArrivee;
  /**
  * Nom du type de transport pour aller d'une ville à l'autre
  */
  const char* typeTransport;

};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // TRAJET_SIMPLE_H
