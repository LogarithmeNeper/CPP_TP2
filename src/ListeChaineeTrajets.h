/*************************************************************************
ListeChaineeTrajets  -  Liste chaînée de MaillonListeChaineeTrajets
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe ListeChaineeTrajets (fichier ListeChaineeTrajets.h) ----------------
#if !defined ( LISTE_CHAINEE_TRAJETS_H )
#define LISTE_CHAINEE_TRAJETS_H

//--------------------------------------------------- Interfaces utilisées

#include "MaillonListeChaineeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe ListeChaineeTrajets
//
// La classe ListeChaineeTrajets permet de gérer une liste chaînée de Trajets,
// eux mêmes encapsulés dans des maillons (Cf. MaillonListeChaineeTrajets)
//
//------------------------------------------------------------------------

class ListeChaineeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  virtual bool ajouter(Trajet* unTrajet);
  // Mode d'emploi : Ajoute un maillon contenant le trajet à la liste chaînée et
  // retourne vrai si l'action a été réalisée avec succès.
  //
  // Contrat :
  // - N'ajoute pas le trajet si il est null
  // - N'ajoute pas le trajet si il est déjà dans la liste
  // - Met à jour la taille de la liste
  //

  virtual bool supprimer(Trajet* unTrajet);
  // Mode d'emploi : Supprime le maillon d'un trajet de la liste chaînée et retourne
  // vrai si l'action a été réalisée avec succès.
  //
  // Contrat :
  // - Ne supprime pas le maillon du trajet si il est null
  // - Ne supprime pas le maillon du trajet si il n'est pas dans la liste
  // - Met à jour la taille de la liste
  // - Met à jour les relations entre les maillons

  MaillonListeChaineeTrajets* get(unsigned int index) const;
  // Mode d'emploi : Retourne le pointeur vers le i_ème maillon de la liste,
  // ou nullptr si il n'existe pas
  //
  // Contrat :
  // - Renvoie nullptr si le maillon n'existe pas (index < 0 ou index >= taille)

  MaillonListeChaineeTrajets* getPremierMaillon() const;
  // Mode d'emploi : Retourne le pointeur vers le premier maillon

  MaillonListeChaineeTrajets* getDernierMaillon() const;
  // Mode d'emploi : Retourne le pointeur vers le premier maillon

  unsigned int getTaille() const;
  // Mode d'emploi : Retourne la taille de la liste
  // Contrat:
  // - La taille doit correspondre au nombre de maillons de la liste

  bool estVide() const;
  // Mode d'emploi : Retourne vrai si la liste est vide
  //
  // Contrat :
  // - Doit retourner vrai si la taille est de 0 uniquement

  bool contient(const Trajet* unTrajet) const;
  // Mode d'emploi : Retourne vrai si le trajet est contenu dans la liste

  //-------------------------------------------- Constructeurs - destructeur

  ListeChaineeTrajets ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~ListeChaineeTrajets ( );
  // Mode d'emploi :
  //
  // Contrat : Supprime l'ensemble des maillons de la liste chainée en mémoire
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  //Le pointeur vers le premier maillon de la liste
  MaillonListeChaineeTrajets* premierMaillon;

  //Le pointeur vers le dernier maillon de la liste
  MaillonListeChaineeTrajets* dernierMaillon;

  //La taille de la liste, correspond au nombre de maillons
  unsigned int taille;

};

//-------------------------------- Autres définitions dépendantes de ListeChaineeTrajets

#endif // LISTE_CHAINEE_TRAJETS_H
