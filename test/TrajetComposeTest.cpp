#include <iostream>

#include "ANSIColors.h"
#include "TrajetComposeTest.h"

void TrajetComposeTest::testEstValide() const {

  std::cout << BOLD << YELLOW << "> Test de la méthode estValide <" << RESET << std::endl << std::endl;

  // Cas vide
  // Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU1 : " << RESET << std::endl;

    TrajetCompose tc;
    tc.afficher(std::cout);
    std::cout << std::endl;

    if(!tc.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }
    std::cout << std::endl;
  }

  // Cas unique
  // Résultat attendu: trajet valide
  {
    std::cout << ITALIC << CYAN << "TU2 : " << RESET << std::endl;

    TrajetCompose tc;
    tc.ajouter(new TrajetSimple("a","b","TGV"));
    tc.afficher(std::cout);
    std::cout << std::endl;

    if(tc.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }
    std::cout << std::endl;
  }

  // Cas d'une concaténation réussie
  // Résultat attendu: trajet valide
  {
    std::cout << ITALIC << CYAN << "TU3 : " << RESET << std::endl;

    TrajetCompose tc;
    tc.ajouter(new TrajetSimple("a","b","TGV"));
    tc.ajouter(new TrajetSimple("b","c","TGV"));
    tc.afficher(std::cout);
    std::cout << std::endl;

    if(tc.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }
    std::cout << std::endl;
  }

  // Cas de a->b->...->a
  // Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU4 : " << RESET << std::endl;
    TrajetCompose tc;
    tc.ajouter(new TrajetSimple("a","b","TGV"));
    tc.ajouter(new TrajetSimple("b","a","TGV"));
    tc.afficher(std::cout);
    std::cout << std::endl;

    if(tc.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }
    std::cout << std::endl;
  }

  // Cas de non recollement
  // Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU5 : " << RESET << std::endl;

    TrajetCompose tc;
    tc.ajouter(new TrajetSimple("a","b","TGV"));
    tc.ajouter(new TrajetSimple("c","b","TGV"));
    tc.afficher(std::cout);
    std::cout << std::endl;

    if(tc.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }
    std::cout << std::endl;
  }


}
