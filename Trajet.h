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

using namespace std;
#include <iostream>

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

  friend ostream & operator<< (ostream & out, const Trajet & unTrajet);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual bool estValide() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  const char* getNom() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur

  Trajet ( const char* unNom );
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

  virtual void print(ostream & out) const = 0;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //----------------------------------------------------- Attributs protégés

  /**
  * Le nom du trajet
  */
  const char* nom;

};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJET_H
