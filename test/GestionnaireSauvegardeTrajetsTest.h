#if !defined(GESTIONNAIRE_SAUVEGARDE_TRAJETS_TEST_H)
#define GESTIONNAIRE_SAUVEGARDE_TRAJETS_TEST_H

#include <string>

#include "../src/GestionnaireSauvegardeTrajets.h"

class GestionnaireSauvegardeTrajetsTest {

public:

  void testEcrireSauvegarde() const;

  void testLireSauvegarde() const;

protected:

  std::string lireContenuFichier(const std::string unNomFichier) const;

  void ecrireContenuFichier(const std::string unNomFichier, const std::string contenu) const;

};

#endif //GESTIONNAIRE_SAUVEGARDE_TRAJETS_TEST_H
