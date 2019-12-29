#include <iostream>
#include <cstring>

#include "TrajetSimpleTest.h"
#include "TrajetComposeTest.h"
#include "FiltreTrajetsTest.h"
#include "GestionnaireSauvegardeTrajetsTest.h"
#include "ANSIColors.h"

int main(void)
{
  std::cout << BOLD << GREEN << ">>>>>>> Tests unitaires pour la classe TrajetSimple <<<<<<<" << RESET << std::endl;
  std::cout << std::endl;
  TrajetSimpleTest trajetSimpleTest;
  trajetSimpleTest.testEstValide();

  std::cout << BOLD << GREEN << ">>>>>>> Tests unitaires pour la classe TrajetCompose <<<<<<<" << RESET << std::endl;
  std::cout << std::endl;
  TrajetComposeTest trajetComposeTest;
  trajetComposeTest.testEstValide();

  std::cout << BOLD << GREEN << ">>>>>>> Tests unitaires pour la classe FiltreTrajets <<<<<<<" << RESET << std::endl;
  std::cout << std::endl;
  FiltreTrajetsTest filtreTest;
  filtreTest.testFiltrerParType();
  filtreTest.testFiltrerParVilleDepart();
  filtreTest.testFiltrerParVilleArrivee();
  filtreTest.testFiltrerParVilleDepartEtVilleArrivee();
  filtreTest.testFiltrerParIntervalle();

  std::cout << BOLD << GREEN << ">>>>>>> Tests unitaires pour la classe GestionnaireSauvegardeTrajets <<<<<<<" << RESET << std::endl;
  std::cout << std::endl;
  GestionnaireSauvegardeTrajetsTest gestionnaireTest;
  gestionnaireTest.testEcrireSauvegarde();
  gestionnaireTest.testLireSauvegarde();


  return 0;
}
