/*************************************************************************
Ville  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Ville (fichier Ville.h) ----------------
#if ! defined ( VILLE_H )
#define VILLE_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Ville
//
//
//------------------------------------------------------------------------

class Ville
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  friend ostream & operator<<(ostream & out, const Ville & ville);

  bool estValide() const;
  // Mode d'emploi : Renvoie vrai ou faux selon si la ville est valide ou non
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - Le nom de la ville est NULL
  //  - Le nom de la ville est vide (aucun caractère ou enchaînement d'espaces)
  //

  //-------------------------------------------- Constructeurs - destructeur

  Ville ( const char* nom );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Ville ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  /**
  * Nom de la ville
  */
  const char* nom;

};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // VILLE_H
