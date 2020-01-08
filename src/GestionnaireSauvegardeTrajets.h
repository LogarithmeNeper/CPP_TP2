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
  // Mode d'emploi : sauvegarde une liste de trajets dans le fichier de nom "unNomFichier" en
  // respectant le format donné dans le compte rendu
  //
  // Contrat :
  //  - Renvoie vrai si la sauvegarde s'est bien passée, faux sinon

  static ListeChaineeTrajets* lireSauvegarde(const std::string unNomFichier);
  // Mode d'emploi : lit une liste de trajets contenus dans un fichier de nom "unNomFichier"
  //
  // Contrat :
  //  - Renvoie la liste lue si tout s'est bien passé
  //  - Renvoie nullptr sinon
  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  static void ecrireTrajet(std::ofstream& s, const Trajet* t);
  // Mode d'emploi : écrit un trajet t dans le flux s en respectant le format donné dans le compte rendu
  // t peut être un trajet simple ou composé

  static TrajetSimple* lireTrajetSimple(std::ifstream& s, unsigned int & ligneAct);
  // Mode d'emploi : lit un trajet simple dans le flux s en respectant le format donné dans le compte rendu
  //
  // Contrat :
  //  - Renvoie le trajet simple lu si tout s'est bien passé
  //  - Lève une exception en cas d'erreur
  // - Incrémente ligneAct à chaque attribut du trajet lu

  static TrajetCompose* lireTrajetCompose(std::ifstream& s, unsigned int & ligneAct);
  // Mode d'emploi : lit un trajet composé dans le flux s en respectant le format donné dans le compte rendu
  //
  // Contrat :
  //  - Renvoie le trajet composé lu si tout s'est bien passé
  //  - Lève une exception en cas d'erreur
  // - Incrémente ligneAct à chaque attribut du trajet lu

  //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GestionnaireSauvegardeTrajets>

#endif // GESTIONNAIRE_SAUVEGARDE_TRAJETS_H
