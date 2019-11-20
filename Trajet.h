/*************************************************************************
Trajet  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Trajet (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Trajet
//
//
//------------------------------------------------------------------------

class Trajet
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
  Trajet & operator = ( const Trajet & unTrajet );
  // Mode d'emploi :
  //
  // Contrat :
  //


  //-------------------------------------------- Constructeurs - destructeur
  Trajet ( const Trajet & unTrajet );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Trajet ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Trajet ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  /**
  * Le nom du trajet
  */
  char* nom;

};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJET_H
