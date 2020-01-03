/*************************************************************************
GestionnaireSauvegardeTrajets  -  Un gestionnaire permettant d'écrire et de lire
des sauvegardes de liste de trajets
-------------------
début                : 18/12/2019
copyright            : (C) 2019 par Charles Javerliat, Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr, fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionnaireSauvegardeTrajets> (fichier GestionnaireSauvegardeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <stack>
#include <cstdlib>
#include <locale>

//------------------------------------------------------ Include personnel
#include "GestionnaireSauvegardeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "MaillonListeChaineeTrajets.h"
#include "StringHelper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void GestionnaireSauvegardeTrajets::ecrireSauvegarde(const ListeChaineeTrajets& uneListe, const std::string unNomFichier) const {

  std::ofstream s;
  s.open(unNomFichier, ios::out);

  if(s.is_open()) {

    MaillonListeChaineeTrajets* maillonAct = uneListe.getPremierMaillon();

    while(maillonAct != nullptr) {
      ecrireTrajet(s, maillonAct->getTrajet());
      maillonAct = maillonAct->getMaillonSuivant();
    }

    s.close();
  } else {
    std::cerr << "Impossible d'ouvrir le fichier " << unNomFichier << std::endl;
  }

}

TrajetSimple* GestionnaireSauvegardeTrajets::lireTrajetSimple(std::ifstream& s, unsigned int & ligneAct) const {

  std::string villeDepart;
  std::string villeArrivee;
  std::string typeTransport;

  //Lecture de la ville de départ
  ++ligneAct;

  if(!getline(s, villeDepart)) {
    throw std::string("Attribut villeDepart manquant pour le trajet simple.");
  }

  //Lecture de la ville d'arrivée
  ++ligneAct;

  if(!getline(s, villeArrivee)) {
    throw std::string("Attribut villeArrivee manquant pour le trajet simple.");
  }

  //Lecture du type de transport
  ++ligneAct;

  if(!getline(s, typeTransport)) {
    throw std::string("Attribut typeTransport manquant pour le trajet simple.");
  }

  TrajetSimple* ts = new TrajetSimple(villeDepart.c_str(), villeArrivee.c_str(), typeTransport.c_str());

  //Vérification de la validité des attributs
  if(!ts->estValide()) {
    delete ts;
    throw std::string("Attributs du TrajetSimple invalides.");
  }

  return ts;
}

TrajetCompose* GestionnaireSauvegardeTrajets::lireTrajetCompose(std::ifstream& s, unsigned int & ligneAct) const {

  TrajetCompose* tc = new TrajetCompose;
  std::string nSousTrajetsStr;
  unsigned int nSousTrajets;
  std::string token;

  //Lecture brute du nombre de sous-trajets
  ++ligneAct;

  if(!getline(s, nSousTrajetsStr)) {
    delete tc;
    throw std::string("Attribut nSousTrajets manquant pour le trajet simple.");
  }

  //Vérification de la nature de l'attribut (entier naturel) et conversion en entier
  if(!estEntierNaturel(nSousTrajetsStr.c_str()) || (nSousTrajets = std::stoi(nSousTrajetsStr)) <= 0) {
    delete tc;
    throw std::string("Le nombre de trajets composants le trajet composé doit être un entier strictement supérieur à 0.");
  }

  //Lecture des nSousTrajets TrajetSimple
  for(unsigned int i = 0; i < nSousTrajets; i++) {

    //Lecture du token
    ++ligneAct;

    if(!getline(s, token)) {
      delete tc;
      throw std::string("Sous-trajet attendu mais manquant pour le trajet composé.");
    }

    //On vérifie qu'il s'agit d'un trajet simple, on a pas le droit de rajouter des trajets
    //composés dans des trajets composés d'après le cahier des charges
    if(token != Token::TS) {
      delete tc;
      throw std::string("Token invalide " + token + ", le trajet composé ne peut contenir que des trajets simples.");
    }

    TrajetSimple* ts = lireTrajetSimple(s, ligneAct);
    tc->ajouter(ts);
  }

  //Vérification de la validité du TrajetCompose
  if(!tc->estValide()) {
    delete tc;
    throw std::string("Sous-trajets du TrajetCompose invalides.");
  }

  return tc;
}

ListeChaineeTrajets & GestionnaireSauvegardeTrajets::lireSauvegarde(ListeChaineeTrajets & liste,const std::string unNomFichier) const
{

  std::ifstream s(unNomFichier);
  std::string token;

  //Ligne actuellement lue, permet d'indiquer où se trouve le problème dans les
  //erreurs de formattage.
  unsigned int ligneAct(1);

  if(s.is_open()) {

    try {

      //Lecture du token
      while(getline(s, token)) {

        //On lit un TrajetSimple
        if(token == Token::TS) {
          liste.ajouter(lireTrajetSimple(s, ligneAct));
        }
        //On lit un TrajetCompose
        else if(token == Token::TC) {
          liste.ajouter(lireTrajetCompose(s, ligneAct));
        }
        //Token inconnu (autre que TS ou TC)
        else {
          throw std::string("Token inconnu " + token);
        }

        ++ligneAct;
      }

    } catch(const std::string & errMsg) {
      std::cerr << "Erreur de formattage à la ligne " << ligneAct << ": " << errMsg << std::endl;
      s.close();

      //On vide la liste
      liste.effacerEnProfondeur();
      return liste;
    }

  } else {
    std::cerr << "Impossible d'ouvrir le fichier " << unNomFichier << std::endl;
  }

  s.close();
  return liste;

}

//-------------------------------------------- Constructeurs - destructeur

GestionnaireSauvegardeTrajets::GestionnaireSauvegardeTrajets ( )
{
  #ifdef MAP
  cout << "Appel au constructeur de GestionnaireSauvegardeTrajets" << endl;
  #endif
} //----- Fin de GestionnaireSauvegardeTrajets


GestionnaireSauvegardeTrajets::~GestionnaireSauvegardeTrajets ( )
{
  #ifdef MAP
  cout << "Appel au destructeur de GestionnaireSauvegardeTrajets" << endl;
  #endif
} //----- Fin de ~GestionnaireSauvegardeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void GestionnaireSauvegardeTrajets::ecrireTrajet(std::ofstream& s, const Trajet* t) const {

  const TrajetSimple* ts = dynamic_cast<const TrajetSimple*>(t);
  const TrajetCompose* tc = dynamic_cast<const TrajetCompose*>(t);

  if(ts != nullptr)
  {
    s << Token::TS << std::endl;
    s << ts->getVilleDepart() << std::endl;
    s << ts->getVilleArrivee() << std::endl;
    s << ts->getTypeTransport() << std::endl;
  } else if(tc != nullptr) {
    s << Token::TC << std::endl;
    s << tc->getTaille() << std::endl;

    MaillonListeChaineeTrajets* maillonAct = tc->getPremierMaillon();

    while(maillonAct != nullptr) {
      ecrireTrajet(s, maillonAct->getTrajet());
      maillonAct = maillonAct->getMaillonSuivant();
    }
  }

}
