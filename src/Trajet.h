/*************************************************************************
Trajet  -  Une abstraction de trajet
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Trajet (fichier Trajet.h) ----------------
#if !defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Trajet
// Classe abstraite contenant les attributs et méthodes communes de tous les types trajets.
//
//------------------------------------------------------------------------

class Trajet
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  virtual bool estValide() const = 0;
  // Mode d'emploi : Renvoie vrai si le trajet est valide
  //
  // Contrat : Spécifique au type de trajet (Cf. TrajetSimple et TrajetCompose)
  //

  virtual void afficher(ostream & out) const = 0;
  // Mode d'emploi : Affiche le trajet sur le flux de sortie (cout, cerr, ...)
  //
  // Contrat : Spécifique au type de trajet (Cf. TrajetSimple et TrajetCompose)
  //

  virtual const char* getVilleDepart() const = 0;
  // Mode d'emploi : Renvoie la ville de départ du trajet
  //
  // Contrat : Spécifique au type de trajet (Cf. TrajetSimple et TrajetCompose)
  //

  virtual const char* getVilleArrivee() const = 0;
  // Mode d'emploi : Renvoie la ville d'arrivée du trajet
  //
  // Contrat : Spécifique au type de trajet (Cf. TrajetSimple et TrajetCompose)
  //

  unsigned int getIndice() const;
  // Mode d'emploi : Renvoie l'indice du trajet dans le catalogue

  void setIndice(unsigned int unIndice);
  // Mode d'emploi : Met à jour l'indice du trajet dans le catalogue
  //
  // Contrat :
  // - Doit changer l'indice du trajet

  //-------------------------------------------- Constructeurs - destructeur

  Trajet();

  virtual ~Trajet( );

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //L'indice du trajet dans le catalogue
  unsigned int indice;

  //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJET_H
