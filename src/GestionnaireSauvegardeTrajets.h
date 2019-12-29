/*************************************************************************
GestionnaireSauvegardeTrajets  -  Un gestionnaire permettant d'écrire et de lire
des sauvegardes de liste de trajets
-------------------
début                : 18/12/2019
copyright            : (C) 2019 par Charles Javerliat, Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr, fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionnaireSauvegardeTrajets> (fichier GestionnaireSauvegardeTrajets.h) ----------------
#if ! defined ( GESTIONNAIRE_SAUVEGARDE_TRAJETS_H )
#define GESTIONNAIRE_SAUVEGARDE_TRAJETS_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include "ListeChaineeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

namespace Token {
  const std::string TS = "#TS";
  const std::string TC = "#TC";
}

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionnaireSauvegardeTrajets>
//
//
//------------------------------------------------------------------------

class GestionnaireSauvegardeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques


  void ecrireSauvegarde(const ListeChaineeTrajets& uneListe, const std::string unNomFichier) const;

  ListeChaineeTrajets* lireSauvegarde(const std::string unNomFichier) const;

  GestionnaireSauvegardeTrajets ( );

  virtual ~GestionnaireSauvegardeTrajets ( );

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  void ecrireTrajet(std::ofstream& s, const Trajet* t) const;

  TrajetSimple* lireTrajetSimple(std::ifstream& s, unsigned int & ligneAct) const;

  TrajetCompose* lireTrajetCompose(std::ifstream& s, unsigned int & ligneAct) const;

  //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GestionnaireSauvegardeTrajets>

#endif // GESTIONNAIRE_SAUVEGARDE_TRAJETS_H
