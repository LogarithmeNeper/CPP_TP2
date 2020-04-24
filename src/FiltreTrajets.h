/*************************************************************************
FiltreTrajets  -  Filtre de trajets
-------------------
début                : 18/12/2019
copyright            : (C) 2019 par Charles Javerliat, Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr, fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <FiltreTrajets> (fichier FiltreTrajets.h) ----------------
#if ! defined ( FILTRE_TRAJETS_H )
#define FILTRE_TRAJETS_H

//--------------------------------------------------- Interfaces utilisées

#include <string>

#include "ListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef enum TypeTrajet_ {
  SIMPLE,
  COMPOSE
} TypeTrajet;

//------------------------------------------------------------------------
// Rôle de la classe <FiltreTrajets>
//
// La classe FiltreTrajets permet de filtrer une ListeChaineeTrajets selon
// des critères particuliers (ville de départ, d'arrivée, type du trajet, ...)
// et de renvoyer les extraits sous forme de nouvelles instances de ListeChaineeTrajets.
//------------------------------------------------------------------------

class FiltreTrajets
{
public:
  static ListeChaineeTrajets* filtrerParType(const ListeChaineeTrajets& trajets, TypeTrajet typeTrajet);
  // Mode d'emploi : Filtre la liste de trajets donnée en paramètre. Renvoie une nouvelle instance
  // de ListeChaineeTrajets contenant uniquement les trajets de type: typeTrajet.
  //
  // Contrat :
  //  - Renvoie une ListeChaineeTrajets contenant uniquement des trajets de type: typeTrajet.
  //  - Renvoie une liste vide si aucun trajet n'a passé le filtre.
  //

  static ListeChaineeTrajets* filtrerParVilleDepart(const ListeChaineeTrajets& trajets, const std::string& villeDepart);
  // Mode d'emploi : Filtre la liste de trajets donnée en paramètre. Renvoie une nouvelle instance
  // de ListeChaineeTrajets contenant uniquement les trajets ayant pour ville de départ: villeDepart.
  //
  // Contrat :
  //  - Renvoie une ListeChaineeTrajets contenant uniquement des trajets ayant pour ville de départ: villeDepart.
  //  - Renvoie une liste vide si aucun trajet n'a passé le filtre.
  //

  static ListeChaineeTrajets* filtrerParVilleArrivee(const ListeChaineeTrajets& trajets, const std::string& villeArrivee);
  // Mode d'emploi : Filtre la liste de trajets donnée en paramètre. Renvoie une nouvelle instance
  // de ListeChaineeTrajets contenant uniquement les trajets ayant pour ville d'arrivée: villeArrivee.
  //
  // Contrat :
  //  - Renvoie une ListeChaineeTrajets contenant uniquement des trajets ayant pour ville d'arrivée: villeArrivee.
  //  - Renvoie une liste vide si aucun trajet n'a passé le filtre.
  //

  static ListeChaineeTrajets* filtrerParVilleDepartEtArrivee(const ListeChaineeTrajets& trajets, const std::string& villeDepart, const std::string& villeArrivee);
  // Mode d'emploi : Filtre la liste de trajets donnée en paramètre. Renvoie une nouvelle instance
  // de ListeChaineeTrajets contenant uniquement les trajets ayant pour ville de départ: villeDepart; et pour ville d'arrivée: villeArrivee.
  //
  // Contrat :
  //  - Renvoie une ListeChaineeTrajets contenant uniquement des trajets ayant pour ville de départ: villeDepart; et pour ville d'arrivée: villeArrivee.
  //  - Renvoie une liste vide si aucun trajet n'a passé le filtre.
  //

  static ListeChaineeTrajets* filtrerParIntervalle(const ListeChaineeTrajets& trajets, const unsigned int n, const unsigned int m);
  // Mode d'emploi : Filtre la liste de trajets donnée en paramètre. Renvoie une nouvelle instance
  // de ListeChaineeTrajets contenant uniquement les trajets d'indice allant de n à m inclus.
  //
  // Contrat :
  //  - Renvoie une ListeChaineeTrajets contenant au maximum (m-n+1) trajets.
  //  - Renvoie une liste vide si aucun trajet n'a passé le filtre.
  //
};

//-------------------------------- Autres définitions dépendantes de <FiltreTrajets>

#endif // FILTRE_TRAJETS_H
