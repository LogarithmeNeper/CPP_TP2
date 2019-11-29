#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#include "Ville.h"
#include "TypeTransport.h"

#include <iostream>
using namespace std;

int main(void) {

  Catalogue catalogue;

  Ville montpellier("Montpellier");
  Ville lyon("Lyon");
  Ville marseille("Marseille");
  Ville paris("Paris");

  TypeTransport train("Train");
  TypeTransport bateau("Bateau");
  TypeTransport avion("Avion");
  TypeTransport voiture("Voiture");

  TrajetSimple ts1("TS1", &lyon, &marseille, &train);

  TrajetSimple ts2("TS2", &paris, &montpellier, &voiture);

  TrajetCompose tc1("TC1");
  tc1.ajouter(&ts1);
  tc1.ajouter(&ts2);

  catalogue.ajouter(&ts2);
  catalogue.ajouter(&tc1);
  catalogue.ajouter(&ts1);

  cout << catalogue << endl;

  return 0;
}
