#if !defined(FILTRE_TRAJETS_TEST_H)
#define FILTRE_TRAJETS_TEST_H

#include "../src/FiltreTrajets.h"

class FiltreTrajetsTest {

public:
  void testFiltrerParType() const;

  void testFiltrerParVilleDepart() const;

  void testFiltrerParVilleArrivee() const;

  void testFiltrerParVilleDepartEtVilleArrivee() const;

  void testFiltrerParIntervalle() const;

protected:

  FiltreTrajets filtre;

};

#endif // FILTRE_TRAJETS_TEST_H
