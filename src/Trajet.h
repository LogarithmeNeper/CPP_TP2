/*************************************************************************
   Trajet  -  description
   -------------------
   début                : 20/11/2019
   copyright            : (C) 2019 par Charles Javerliat
   e-mail               : charles.javerliat@insa-lyon.fr
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
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

virtual bool estValide() const = 0;
// Mode d'emploi :
//
// Contrat :
//

virtual void afficher(ostream & out) const = 0;
// Mode d'emploi : Affiche le trajet sur le flux de sortie (cout, cerr, ...)
//
// Contrat : Spécifique au type de trajet (Cf. TrajetSimple et TrajetCompose)
//

virtual const char* getVilleDepart() const = 0;

virtual const char* getVilleArrivee() const = 0;

void setIndice(unsigned int unIndice);

unsigned int getIndice() const;

//-------------------------------------------- Constructeurs - destructeur

Trajet();

virtual ~Trajet( ) = 0;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

  unsigned int indice;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJET_H
