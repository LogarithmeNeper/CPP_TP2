/*************************************************************************
TypeTransport  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Ville (fichier Ville.h) ----------------
#if ! defined ( TYPE_TRANSPORT_H )
#define TYPE_TRANSPORT_H

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

class TypeTransport
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  friend ostream & operator<<(ostream & out, const TypeTransport & typeTransport);

  bool estValide() const;
  // Mode d'emploi : Renvoie vrai ou faux selon si le type de transport est valide ou non
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - Le nom du type de transport est NULL
  //  - Le nom du type de transport est vide (aucun caractère ou enchaînement d'espaces)
  //

  //-------------------------------------------- Constructeurs - destructeur

  TypeTransport ( const char* nom );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TypeTransport ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  /**
  * Nom du type de trajet
  */
  const char* nom;

};

//-------------------------------- Autres définitions dépendantes de TrajetSimple

#endif // TYPE_TRANSPORT_H
