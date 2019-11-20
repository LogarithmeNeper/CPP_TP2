/*************************************************************************
Catalogue  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue
//
//
//------------------------------------------------------------------------

class Catalogue
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void ajouterTrajet(Trajet* unTrajet);
  // Mode d'emploi : Appeler 
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur

  Catalogue ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Catalogue ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  /**
  * Nombre de trajets dans le catalogue
  */
  unsigned int nbTrajets;

  /**
  * Capacité de la liste de trajets
  */
  unsigned int capaciteTrajets;

  /**
  * Liste des trajets du catalogue
  */
  Trajet** trajets;

};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
