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
#include "Ville.h"
#include "TypeTransport.h"

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
  //  - Le nom du trajet est vide ou NULL
  //  - La ville de départ est NULL
  //  - La ville d'arrivée est NULL
  //  - La ville d'arrivée est invalide (Cf. Ville#estValide)
  //  - La ville de départ est invalide (Cf. Ville#estValide)
  //  - La ville de départ est égale à la ville d'arrivée
  //  - Le type de transport est NULL
  //  - Le type de transport est invalide (Cf. Transport#estValide)
  //

  //-------------------------------------------- Constructeurs - destructeur

  TrajetSimple ( const char* unNom, Ville* uneVilleDepart, Ville* uneVilleArrivee, TypeTransport* unTypeTransport );
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

  void print(ostream & out) const override;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //----------------------------------------------------- Attributs protégés

  /**
  * Ville de départ du trajet
  */
  Ville* villeDepart;
  /**
  * Ville d'arrivée du trajet
  */
  Ville* villeArrivee;
  /**
  * Type de transport pour aller d'une ville à l'autre
  */
  TypeTransport* typeTransport;

};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // TRAJET_SIMPLE_H
