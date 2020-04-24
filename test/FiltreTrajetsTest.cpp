#include <iostream>

#include "../src/Catalogue.h"
#include "../src/TrajetSimple.h"
#include "../src/TrajetCompose.h"
#include "../src/ListeChaineeTrajets.h"

#include "FiltreTrajetsTest.h"
#include "ANSIColors.h"

void FiltreTrajetsTest::testFiltrerParType() const {

  std::cout << BOLD << YELLOW << "> Test de la méthode filtrerParType <" << RESET << std::endl << std::endl;

  //Cas de filtre sur une liste vide, filtre de n'importe quel type
  //Résultat attendu: liste vide
  {
    std::cout << ITALIC << CYAN << "TU1 : " << RESET << endl;
    ListeChaineeTrajets liste;
    ListeChaineeTrajets* listeFiltree1 = filtre.filtrerParType(liste, TypeTrajet::SIMPLE);
    ListeChaineeTrajets* listeFiltree2 = filtre.filtrerParType(liste, TypeTrajet::COMPOSE);

    if(listeFiltree1->estVide() && listeFiltree2->estVide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    delete listeFiltree1;
    delete listeFiltree2;

    std::cout << std::endl;
  }

  //Cas du filtre sur une liste homogène d'un type autre que celui du filtre
  //Résultat attendu: liste vide
  {
    std::cout << ITALIC << CYAN << "TU2 : " << RESET << endl;
    //Liste uniquement composée de trajets composés
    ListeChaineeTrajets listeTC;
    TrajetCompose tc1;
    tc1.ajouter(new TrajetSimple("a","b","TGV"));
    tc1.ajouter(new TrajetSimple("b","c","TGV"));
    listeTC.ajouter(&tc1);
    TrajetCompose tc2;
    tc2.ajouter(new TrajetSimple("x","y","TGV"));
    tc2.ajouter(new TrajetSimple("y","z","TGV"));
    listeTC.ajouter(&tc2);

    //Liste uniquement composée de trajets simples
    ListeChaineeTrajets listeTS;
    TrajetSimple ts1("a","b","TGV");
    TrajetSimple ts2("b","c","TGV");
    listeTS.ajouter(&ts1);
    listeTS.ajouter(&ts2);

    ListeChaineeTrajets* listeFiltree1 = filtre.filtrerParType(listeTC, TypeTrajet::SIMPLE);
    ListeChaineeTrajets* listeFiltree2 = filtre.filtrerParType(listeTS, TypeTrajet::COMPOSE);

    if(listeFiltree1->estVide() && listeFiltree2->estVide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    }  else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    delete listeFiltree1;
    delete listeFiltree2;
  }

  //Cas du filtre sur une liste homogène d'un type correspondant à celui du filtre
  //Résultat attendu: liste de même contenu
  {
    std::cout << ITALIC << CYAN << "TU3 : " << RESET << endl;
    //Liste uniquement composée de trajets composés
    ListeChaineeTrajets listeTC;
    TrajetCompose tc1;
    tc1.ajouter(new TrajetSimple("a","b","TGV"));
    tc1.ajouter(new TrajetSimple("b","c","TGV"));
    listeTC.ajouter(&tc1);
    TrajetCompose tc2;
    tc2.ajouter(new TrajetSimple("x","y","TGV"));
    tc2.ajouter(new TrajetSimple("y","z","TGV"));
    listeTC.ajouter(&tc2);

    //Liste uniquement composée de trajets simples
    ListeChaineeTrajets listeTS;
    TrajetSimple ts1("a","b","TGV");
    TrajetSimple ts2("b","c","TGV");
    listeTS.ajouter(&ts1);
    listeTS.ajouter(&ts2);

    ListeChaineeTrajets* listeFiltree1 = filtre.filtrerParType(listeTC, TypeTrajet::COMPOSE);
    ListeChaineeTrajets* listeFiltree2 = filtre.filtrerParType(listeTS, TypeTrajet::SIMPLE);

    if(listeFiltree1->getTaille() == listeTC.getTaille() && listeFiltree2->getTaille() == listeTS.getTaille())
    {
      std::cout << GREEN << "OK" << RESET << std::endl;
    }
    else
    {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    delete listeFiltree1;
    delete listeFiltree2;
  }

  //Cas du filtre sur une liste hétérogène avec des trajets de tous types
  //Résultat attendu: liste avec uniquement dew trajets du type du filtre
  {
    std::cout << ITALIC << CYAN << "TU4 : " << RESET << endl;

    //Liste hétérogène de trajets
    ListeChaineeTrajets listeHeterogene;

    TrajetCompose tc1;
    tc1.ajouter(new TrajetSimple("a","b","TGV"));
    tc1.ajouter(new TrajetSimple("b","c","TGV"));
    listeHeterogene.ajouter(&tc1);

    TrajetCompose tc2;
    tc2.ajouter(new TrajetSimple("x","y","TGV"));
    tc2.ajouter(new TrajetSimple("y","z","TGV"));
    listeHeterogene.ajouter(&tc2);

    TrajetSimple ts1("a","b","TGV");
    listeHeterogene.ajouter(&ts1);

    TrajetSimple ts2("b","c","TGV");
    listeHeterogene.ajouter(&ts2);

    ListeChaineeTrajets* listeFiltree1 = filtre.filtrerParType(listeHeterogene, TypeTrajet::SIMPLE);
    ListeChaineeTrajets* listeFiltree2 = filtre.filtrerParType(listeHeterogene, TypeTrajet::COMPOSE);

    bool typeValide = true;
    MaillonListeChaineeTrajets* maillonAct = nullptr;

    // ------------ Vérifie le contenu de la première liste
    maillonAct = listeFiltree1->getPremierMaillon();

    while(maillonAct != nullptr && typeValide) {

      if(!dynamic_cast<TrajetSimple*>(maillonAct->getTrajet())) {
        typeValide = false;
      }

      maillonAct = maillonAct->getMaillonSuivant();
    }
    //------------------------------------------------------

    // ------------ Vérifie le contenu de la seconde liste
    maillonAct = listeFiltree2->getPremierMaillon();

    while(maillonAct != nullptr && typeValide) {

      if(!dynamic_cast<TrajetCompose*>(maillonAct->getTrajet())) {
        typeValide = false;
      }

      maillonAct = maillonAct->getMaillonSuivant();
    }
    //------------------------------------------------------

    if(typeValide) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    delete listeFiltree1;
    delete listeFiltree2;
  }

}

void FiltreTrajetsTest::testFiltrerParVilleDepart() const {}

void FiltreTrajetsTest::testFiltrerParVilleArrivee() const {}

void FiltreTrajetsTest::testFiltrerParVilleDepartEtVilleArrivee() const {}

void FiltreTrajetsTest::testFiltrerParIntervalle() const {}
