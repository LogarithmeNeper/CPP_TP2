/*************************************************************************
Catalogue  -  Classe permettant de gérer une liste de Trajets, et notamment
à procéder à des recherches de trajets entre deux villes.
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) ----------------

#if !defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
using namespace std;

#include "Trajet.h"
#include "ListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue
//
// La classe Catalogue permet de gérer une liste de Trajets, et notamment
// à procéder à des recherches simples ou avancées d'itinéraire entre deux villes.
//
//------------------------------------------------------------------------

class Catalogue : public ListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  bool ajouter(Trajet* unTrajet) override;
  // Mode d'emploi : Ajoute un trajet au catalogue, retourne vrai si l'action a été
  // effectuée avec succès.
  //
  // Contrat :
  // - Ne rajoute pas le trajet si il rend le catalogue invalide.
  // - Attribue un indice au trajet ajouté.
  // - Retourne vrai si le trajet a bien été rajouté.
  // - Affiche un message d'erreur sur la sortie standard d'erreur si une des conditions n'est pas respectée.

  bool supprimer(Trajet* unTrajet) override;
  // Mode d'emploi : Supprime un trajet du catalogue, retourne vrai si l'action a été
  // effectuée avec succès.
  //
  // Contrat :
  // - Ne supprime pas le trajet si il rend le catalogue invalide.
  // - Met à jour l'indice des trajets suivant le trajet supprimé.
  // - Retourne vrai si le trajet a bien été supprimé.
  // - Affiche un message d'erreur sur la sortie standard d'erreur si une des conditions n'est pas respectée.

  bool estValide() const;
  // Mode d'emploi : Renvoie vrai ou faux selon si le catalogue est valide
  //
  // Contrat : Renvoie faux dans les cas suivants:
  //  - L'un des trajets n'est pas valide
  // Affiche un message d'erreur sur la sortie standard d'erreur si une des conditions n'est pas respectée
  //

  ListeChaineeTrajets rechercheTrajetsEnDepartDe(const char* villeDepart) const;
  // Mode d'emploi : Renvoie la liste des trajets en départ de villeDepart
  //
  // Contrat :
  // - Renvoie la liste contenant les trajets en départ de villeDepart
  // - Renvoie une liste vide si aucun trajet n'est trouvé.

  bool rechercheTrajetSimple(const char* villeDepart, const char* villeArrivee) const;
  // Mode d'emploi : Affiche les trajets directs possibles pour aller de villeDepart
  // à villeArrivee et retourne vrai si au moins un est trouvé.
  //
  // Contrat :
  // - Affiche les trajets trouvés sur la sortie standard
  // - Renvoie vrai si au moins un trajet est trouvé.
  //

  bool rechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee) const;
  // Mode d'emploi : Affiche les trajets ou combinaisons de trajets possibles pour
  // aller de villeDepart à villeArrivee et retourne vrai si au moins un est trouvé.
  //
  // Contrat :
  // - Affiche les trajets trouvés sur la sortie standard
  // - Renvoie vrai si au moins un trajet est trouvé.

  void afficher(ostream & out) const;
  // Mode d'emploi : Affiche le catalogue sur le flux de sortie
  //
  // Contrat : Affiche le catalogue sur le flux de sortie au format:
  // * Si le catalogue n'est pas vide:
  // "Trajet i - {définition trajet_i}" n fois avec un saut de ligne entre chaque trajet
  // * Sinon:
  // "Le catalogue est vide."
  //
  // Sans retour à la ligne à la fin
  //
  //

  //-------------------------------------------- Constructeurs - destructeur

  Catalogue ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Catalogue ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  bool sousRechercheTrajetAvancee(const char* villeDepart, const char* villeArrivee, bool* trajetsParcourus, ListeChaineeTrajets* chemin) const;
  // Mode d'emploi : Affiche les trajets ou combinaisons de trajets possibles pour
  // aller de villeDepart à villeArrivee et retourne vrai si au moins un est trouvé.
  //
  // Contrat :
  // - Affiche les trajets trouvés sur la sortie standard
  // - Renvoie vrai si au moins un trajet est trouvé.
  // - trajetsParcourus[i] est vrai si le i_ème trajet a déjà été traité dans la branche de récursion actuelle.
  // - chemin contient l'ensemble des trajets empruntés dans la branche de récursion actuelle.

  //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de Catalogue

#endif // CATALOGUE_H
