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
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //


  //------------------------------------------------- Surcharge d'opérateurs
  Catalogue & operator = ( const Catalogue & unCatalogue );
  // Mode d'emploi :
  //
  // Contrat :
  //


  //-------------------------------------------- Constructeurs - destructeur
  Catalogue ( const Catalogue & unCatalogue );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

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
  * Liste des trajets du catalogue
  */
  Trajet** trajets;

};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
