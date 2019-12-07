#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#include <iostream>
using namespace std;

int main(void) {

  Catalogue catalogue;

  TrajetSimple ts1("Lyon", "Lyon", "Train");
  TrajetSimple ts2("Paris", "Montpellier", "Voiture");

  TrajetCompose tc1;
  tc1.ajouter(&ts1);
  tc1.ajouter(&ts2);

  catalogue.ajouter(&ts2);
  catalogue.ajouter(&tc1);
  catalogue.ajouter(&ts1);

  catalogue.afficher(cout);
  cout << endl;

  return 0;
}
