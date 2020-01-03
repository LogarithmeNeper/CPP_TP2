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


  static bool ecrireSauvegarde(const ListeChaineeTrajets& uneListe, const std::string unNomFichier);

  static ListeChaineeTrajets* lireSauvegarde(const std::string unNomFichier);

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  static void ecrireTrajet(std::ofstream& s, const Trajet* t);

  static TrajetSimple* lireTrajetSimple(std::ifstream& s, unsigned int & ligneAct);

  static TrajetCompose* lireTrajetCompose(std::ifstream& s, unsigned int & ligneAct);

  //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GestionnaireSauvegardeTrajets>

#endif // GESTIONNAIRE_SAUVEGARDE_TRAJETS_H
