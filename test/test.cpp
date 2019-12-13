#include <iostream>
#include <cstring>
#include "../src/Catalogue.h"
#include "../src/TrajetSimple.h"
#include "../src/TrajetCompose.h"

void tu1();
// Test unitaire pour validité trajet simple
// Cas avec 3 chaînes de catactères distinctes
// (arg1, arg2, arg3) tous différentes

void tu2();
// Test unitaire pour validité trajet simple
// Cas a -> a
// (arg1, arg1, arg3) tous différentes

void tu3();
// Test unitaire pour validité trajet simple
// Cas a -> b par a
// (arg1, arg2, arg1) tous différentes

void tu4();
// Test unitaire pour validité trajet simple
// Cas a -> b par b
// (arg1, arg2, arg2) tous différentes

void tu5();
// Test unitaire pour validité trajet simple
// Cas nullptr -> b par c
// (nullptr, arg2, arg3) tous différentes

void tu6();
// Test unitaire pour validité trajet simple
// Cas a -> nullptr par c
// (arg1, nullptr, arg3) tous différentes

void tu7();
// Test unitaire pour validité trajet simple
// Cas a -> nullptr par c
// (arg1, arg2, nullptr) tous différentes

void tu8();
// Test unitaire pour validité trajet simple
// Cas d'espace en première position

void tu9();
// Test unitaire pour validité trajet simple
// Cas d'espace en première position

void tu10();
// Test unitaire pour validité trajet simple
// Cas d'espace en première position

// Pour les trajets composés, on s'appuie sur les tests précédents, tous seront valides.
// On suppose pour 2 trajets donc pour tous (par récurrence)
void tu11();
// Test unitaire pour validité trajet composé
// Cas vide

void tu12();
// Test unitaire pour validité trajet composé
// Cas unique

void tu13();
// Test unitaire pour validité trajet composé
// Cas d'une concaténation réussie

void tu14();
// Test unitaire pour validité trajet composé
// Cas de a->b->...->a

void tu15();
// Test unitaire pour validité trajet composé
// Cas de non recollement


int main(void)
{
  Catalogue catalogue();
  std::cout << "Validité pour un trajet simple" << endl;
  tu1();
  tu2();
  tu3();
  tu4();
  tu5();
  tu6();
  tu7();
  tu8();
  tu9();
  tu10();

  std::cout << "Validité pour un trajet composé" << endl;
  std::cout << endl;
  tu11();
  tu12();
  tu13();
  tu14();
  tu15();
  return 0;
}


/* -------------------------------------------------------------
FONCTIONS
------------------------------------------------------------- */

void tu1()
{
  TrajetSimple trajet("a","b","c");
  std::cout << "TU1 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU1 : ";
  if(trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu2()
{
  TrajetSimple trajet("a","a","c");
  std::cout << "TU2 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU2 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}


void tu3()
{
  TrajetSimple trajet("a","b","a");
  std::cout << "TU3 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU3 : ";
  if(trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu4()
{
  TrajetSimple trajet("a","b","b");
  std::cout << "TU4 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU4 : ";
  if(trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu5()
{
  TrajetSimple trajet(nullptr,"b","c");
  std::cout << "TU5 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU5 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu6()
{
  TrajetSimple trajet("a",nullptr,"c");
  std::cout << "TU6 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU6 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu7()
{
  TrajetSimple trajet("a","b",nullptr);
  std::cout << "TU7 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU7 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu8()
{
  TrajetSimple trajet(" ","b","c");
  std::cout << "TU8 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU8 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu9()
{
  TrajetSimple trajet("a"," ","c");
  std::cout << "TU9 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU9 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu10()
{
  TrajetSimple trajet("a","b"," ");
  std::cout << "TU10 : " << endl;
  trajet.afficher(std::cout);
  std::cout << endl;

  std::cout << "TU10 : ";
  if(!trajet.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu11()
{
  TrajetCompose trajetcmp;

  std::cout << "TU11 : " << endl;
  trajetcmp.afficher(std::cout);
  std::cout << endl;
  std::cout << "TU11 : ";
  if(!trajetcmp.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu12()
{
  TrajetCompose trajetcmp;
  trajetcmp.ajouter(new TrajetSimple("a","b","0"));
  std::cout << "TU12 : " << endl;
  trajetcmp.afficher(std::cout);
  std::cout << endl;
  std::cout << "TU12 : ";
  if(trajetcmp.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu13()
{
  TrajetCompose trajetcmp;
  trajetcmp.ajouter(new TrajetSimple("a","b","0"));
  trajetcmp.ajouter(new TrajetSimple("b","c","0"));
  std::cout << "TU13 : " << endl;
  trajetcmp.afficher(std::cout);
  std::cout << endl;
  std::cout << "TU13 : ";
  if(trajetcmp.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu14()
{
  TrajetCompose trajetcmp;
  trajetcmp.ajouter(new TrajetSimple("a","b","0"));
  trajetcmp.ajouter(new TrajetSimple("b","a","0"));
  std::cout << "TU14 : " << endl;
  trajetcmp.afficher(std::cout);
  std::cout << endl;
  std::cout << "TU14 : ";
  if(trajetcmp.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}

void tu15()
{
  TrajetCompose trajetcmp;
  trajetcmp.ajouter(new TrajetSimple("a","b","0"));
  trajetcmp.ajouter(new TrajetSimple("c","b","0"));
  std::cout << "TU15 : " << endl;
  trajetcmp.afficher(std::cout);
  std::cout << endl;
  std::cout << "TU15 : ";
  if(trajetcmp.estValide())
  {
    std::cout << "OK" << endl;
  }
  else
  {
    std::cout << "FAILED" << endl;
  }
  std::cout << endl;
}
