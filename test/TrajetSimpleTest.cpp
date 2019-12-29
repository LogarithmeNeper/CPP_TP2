#include <iostream>
#include "ANSIColors.h"

#include "TrajetSimpleTest.h"

void TrajetSimpleTest::testEstValide() const {

  std::cout << BOLD << YELLOW << "> Test de la méthode estValide <" << RESET << std::endl << std::endl;

  // Cas avec 3 chaînes de catactères distinctes
  // (arg1, arg2, arg3)
  //Résultat attendu: trajet valide
  {
    std::cout << ITALIC << CYAN << "TU1 : " << RESET << std::endl;

    TrajetSimple ts("a","b","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas a -> a
  // (arg1, arg1, arg3)
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU2 : " << RESET << std::endl;

    TrajetSimple ts("a","a","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas a -> b via un transport a
  // (arg1, arg2, arg1)
  //Résultat attendu: trajet valide
  {
    std::cout << ITALIC << CYAN << "TU3 : " << RESET << std::endl;

    TrajetSimple ts("a","b","a");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas a -> b via un transport b
  // (arg1, arg2, arg2)
  //Résultat attendu: trajet valide
  {
    std::cout << ITALIC << CYAN << "TU4 : " << RESET << std::endl;

    TrajetSimple ts("a","b","b");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas nullptr -> b via un transport c
  // (nullptr, arg2, arg3)
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU5 : " << RESET << std::endl;

    TrajetSimple ts(nullptr,"b","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas a -> nullptr via un transport c
  // (arg1, nullptr, arg3)
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU6 : " << RESET << std::endl;

    TrajetSimple ts("a",nullptr,"c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas a -> nullptr via un transport c
  // (arg1, arg2, nullptr)
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU7 : " << RESET << std::endl;

    TrajetSimple ts("a",nullptr,"c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas d'espace en première position
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU8 : " << RESET << std::endl;

    TrajetSimple ts(" ","b","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas d'espace en deuxième position
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU9 : " << RESET << std::endl;

    TrajetSimple ts("a"," ","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  //Cas d'espace en dernière position
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU10 : " << RESET << std::endl;

    TrajetSimple ts("a","b"," ");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas tabulation en première position
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU11 : " << RESET << std::endl;

    TrajetSimple ts("\t","b","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas tabulation en deuxième position
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU11 : " << RESET << std::endl;

    TrajetSimple ts("a","\t","c");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  // Cas tabulation en dernière position
  //Résultat attendu: trajet invalide
  {
    std::cout << ITALIC << CYAN << "TU12 : " << RESET << std::endl;

    TrajetSimple ts("a","b","\t");
    ts.afficher(std::cout);
    std::cout << std::endl;

    if(!ts.estValide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

}
