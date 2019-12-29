#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

#include "GestionnaireSauvegardeTrajetsTest.h"
#include "ANSIColors.h"
#include "../src/TrajetSimple.h"
#include "../src/TrajetCompose.h"
#include "../src/ListeChaineeTrajets.h"

const char* tmpSaveFile = "tmp_save_test.txt";

void GestionnaireSauvegardeTrajetsTest::testEcrireSauvegarde() const {

  std::cout << BOLD << YELLOW << "> Test de la méthode ecrireSauvegarde <" << RESET << std::endl << std::endl;

  //Cas d'une liste vide
  //Résultat attendu: fichier vide
  {
    std::cout << ITALIC << CYAN << "TU1 : " << RESET << endl;
    ListeChaineeTrajets liste;
    gestionnaire.ecrireSauvegarde(liste, tmpSaveFile);

    //Récupère la taille du fichier et le supprime
    std::ifstream in(tmpSaveFile, ios::ate | ios::binary);
    int size = in.tellg();
    remove(tmpSaveFile);

    if(size == 0) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  //Cas d'un TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU2 : " << RESET << endl;
    ListeChaineeTrajets liste;

    TrajetSimple ts("a", "b", "c");
    liste.ajouter(&ts);

    std::string resultatAttendu = Token::TS + "\na\nb\nc\n";

    gestionnaire.ecrireSauvegarde(liste, tmpSaveFile);

    //Vérification du contenu du fichier
    if(resultatAttendu == lireContenuFichier(tmpSaveFile)) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    remove(tmpSaveFile);

    std::cout << std::endl;
  }

  //Cas d'un TrajetCompose
  {
    std::cout << ITALIC << CYAN << "TU3 : " << RESET << endl;
    ListeChaineeTrajets liste;

    TrajetCompose tc;
    tc.ajouter(new TrajetSimple("a", "b", "c"));
    liste.ajouter(&tc);

    std::string resultatAttendu = Token::TC + "\n1\n" + Token::TS + "\na\nb\nc\n";

    gestionnaire.ecrireSauvegarde(liste, tmpSaveFile);

    //Vérification du contenu du fichier
    if(resultatAttendu == lireContenuFichier(tmpSaveFile)) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    remove(tmpSaveFile);

    std::cout << std::endl;
  }

  //Cas d'un TrajetCompose et d'un TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU4 : " << RESET << endl;
    ListeChaineeTrajets liste;

    TrajetCompose tc;
    tc.ajouter(new TrajetSimple("a", "b", "c"));
    liste.ajouter(&tc);
    TrajetSimple ts("d", "e", "f");
    liste.ajouter(&ts);

    std::string resultatAttendu = Token::TC + "\n1\n" + Token::TS + "\na\nb\nc\n" + Token::TS + "\nd\ne\nf\n";

    gestionnaire.ecrireSauvegarde(liste, tmpSaveFile);

    //Vérification du contenu du fichier
    if(resultatAttendu == lireContenuFichier(tmpSaveFile)) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    remove(tmpSaveFile);

    std::cout << std::endl;
  }

}

void GestionnaireSauvegardeTrajetsTest::testLireSauvegarde() const {

  std::cout << BOLD << YELLOW << "> Test de la méthode lireSauvegarde <" << RESET << std::endl << std::endl;

  //Cas d'un fichier vide
  {
    std::cout << ITALIC << CYAN << "TU1 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, "");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    if(liste->estVide()) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    remove(tmpSaveFile);
    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas d'un TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU2 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TS + "\na\nb\nc\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);
    TrajetSimple* ts;

    if(liste->getTaille() == 1
    && (ts = dynamic_cast<TrajetSimple*>(liste->get(0)->getTrajet())) != nullptr
    && strcmp(ts->getVilleDepart(), "a") == 0
    && strcmp(ts->getVilleArrivee(), "b") == 0
    && strcmp(ts->getTypeTransport(), "c") == 0) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas d'un TrajetCompose composé d'un unique TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU3 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TC + "\n1\n" + Token::TS + "\na\nb\nc\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);
    TrajetCompose* tc;
    TrajetSimple * ts1;

    if(liste->getTaille() == 1
    && (tc = dynamic_cast<TrajetCompose*>(liste->get(0)->getTrajet())) != nullptr
    && tc->getTaille() == 1
    && (ts1 = dynamic_cast<TrajetSimple*>(tc->get(0)->getTrajet())) != nullptr
    && strcmp(ts1->getVilleDepart(), "a") == 0
    && strcmp(ts1->getVilleArrivee(), "b") == 0
    && strcmp(ts1->getTypeTransport(), "c") == 0) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas d'un TrajetCompose composé de deux TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU4 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TC + "\n2\n" + Token::TS + "\na\nb\nc\n" + Token::TS + "\nb\nc\nd\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);
    TrajetCompose* tc;
    TrajetSimple * ts1;
    TrajetSimple * ts2;

    if(liste->getTaille() == 1
    && (tc = dynamic_cast<TrajetCompose*>(liste->get(0)->getTrajet())) != nullptr
    && tc->getTaille() == 2
    && (ts1 = dynamic_cast<TrajetSimple*>(tc->get(0)->getTrajet())) != nullptr
    && strcmp(ts1->getVilleDepart(), "a") == 0
    && strcmp(ts1->getVilleArrivee(), "b") == 0
    && strcmp(ts1->getTypeTransport(), "c") == 0
    && (ts2 = dynamic_cast<TrajetSimple*>(tc->get(1)->getTrajet())) != nullptr
    && strcmp(ts2->getVilleDepart(), "b") == 0
    && strcmp(ts2->getVilleArrivee(), "c") == 0
    && strcmp(ts2->getTypeTransport(), "d") == 0) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas de deux TrajetCompose composé de deux TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU5 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TC + "\n2\n" + Token::TS + "\na\nb\nc\n" + Token::TS + "\nb\nc\nd\n"+ Token::TC + "\n2\n" + Token::TS + "\na\nb\nc\n" + Token::TS + "\nb\nc\nd\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    TrajetCompose* tc1;
    TrajetSimple * tc1_ts1;
    TrajetSimple * tc1_ts2;

    TrajetCompose* tc2;
    TrajetSimple * tc2_ts1;
    TrajetSimple * tc2_ts2;

    bool tc1Valide =
    (tc1 = dynamic_cast<TrajetCompose*>(liste->get(0)->getTrajet())) != nullptr
    && tc1->getTaille() == 2
    && (tc1_ts1 = dynamic_cast<TrajetSimple*>(tc1->get(0)->getTrajet())) != nullptr
    && strcmp(tc1_ts1->getVilleDepart(), "a") == 0
    && strcmp(tc1_ts1->getVilleArrivee(), "b") == 0
    && strcmp(tc1_ts1->getTypeTransport(), "c") == 0
    && (tc1_ts2 = dynamic_cast<TrajetSimple*>(tc1->get(1)->getTrajet())) != nullptr
    && strcmp(tc1_ts2->getVilleDepart(), "b") == 0
    && strcmp(tc1_ts2->getVilleArrivee(), "c") == 0
    && strcmp(tc1_ts2->getTypeTransport(), "d") == 0;

    bool tc2Valide =
    (tc2 = dynamic_cast<TrajetCompose*>(liste->get(1)->getTrajet())) != nullptr
    && tc2->getTaille() == 2
    && (tc2_ts1 = dynamic_cast<TrajetSimple*>(tc2->get(0)->getTrajet())) != nullptr
    && strcmp(tc2_ts1->getVilleDepart(), "a") == 0
    && strcmp(tc2_ts1->getVilleArrivee(), "b") == 0
    && strcmp(tc2_ts1->getTypeTransport(), "c") == 0
    && (tc2_ts2 = dynamic_cast<TrajetSimple*>(tc2->get(1)->getTrajet())) != nullptr
    && strcmp(tc2_ts2->getVilleDepart(), "b") == 0
    && strcmp(tc2_ts2->getVilleArrivee(), "c") == 0
    && strcmp(tc2_ts2->getTypeTransport(), "d") == 0;

    if(liste->getTaille() == 2 && tc1Valide && tc2Valide) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas d'un TrajetCompose composé d'un TrajetSimple et d'un TrajetSimple indépendant
  {
    std::cout << ITALIC << CYAN << "TU6 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TC + "\n1\n" + Token::TS + "\na\nb\nc\n" + Token::TS + "\nd\ne\nf\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    TrajetCompose* tc;
    TrajetSimple * ts1;

    TrajetSimple * ts2;

    if(liste->getTaille() == 2
    && (tc = dynamic_cast<TrajetCompose*>(liste->get(0)->getTrajet())) != nullptr
    && tc->getTaille() == 1
    && (ts1 = dynamic_cast<TrajetSimple*>(tc->get(0)->getTrajet())) != nullptr
    && strcmp(ts1->getVilleDepart(), "a") == 0
    && strcmp(ts1->getVilleArrivee(), "b") == 0
    && strcmp(ts1->getTypeTransport(), "c") == 0

    && (ts2 = dynamic_cast<TrajetSimple*>(liste->get(1)->getTrajet())) != nullptr
    && strcmp(ts2->getVilleDepart(), "d") == 0
    && strcmp(ts2->getVilleArrivee(), "e") == 0
    && strcmp(ts2->getTypeTransport(), "f") == 0) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas d'un TrajetSimple indépendant et d'un TrajetCompose composé d'un TrajetSimple
  {
    std::cout << ITALIC << CYAN << "TU7 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TS + "\na\nb\nc\n" + Token::TC + "\n1\n" + Token::TS + "\nd\ne\nf\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    TrajetSimple * ts1;

    TrajetCompose* tc;
    TrajetSimple * ts2;

    if(liste->getTaille() == 2
    && (ts1 = dynamic_cast<TrajetSimple*>(liste->get(0)->getTrajet())) != nullptr
    && strcmp(ts1->getVilleDepart(), "a") == 0
    && strcmp(ts1->getVilleArrivee(), "b") == 0
    && strcmp(ts1->getTypeTransport(), "c") == 0
    && (tc = dynamic_cast<TrajetCompose*>(liste->get(1)->getTrajet())) != nullptr
    && tc->getTaille() == 1
    && (ts2 = dynamic_cast<TrajetSimple*>(tc->get(0)->getTrajet())) != nullptr
    && strcmp(ts2->getVilleDepart(), "d") == 0
    && strcmp(ts2->getVilleArrivee(), "e") == 0
    && strcmp(ts2->getTypeTransport(), "f") == 0) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
    liste->effacerEnProfondeur();
    delete liste;
  }

  //Cas d'un TrajetCompose composé d'un TrajetCompose
  //Résultat attendu: impossible
  {
    std::cout << ITALIC << CYAN << "TU8 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TC + "\n1\n" + Token::TC + "\n1\n" + Token::TS + "\na\nb\nc\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    if(liste == nullptr) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  //Cas d'un attribut manquant pour un TrajetSimple (1)
  {
    std::cout << ITALIC << CYAN << "TU9 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TS + "\na\nb\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    if(liste == nullptr) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

  //Cas d'un attribut manquant pour un TrajetSimple (2)
  {
    std::cout << ITALIC << CYAN << "TU10 : " << RESET << endl;
    ecrireContenuFichier(tmpSaveFile, Token::TS + "\na\nb\n" + Token::TC + "\n1\n" + Token::TS + "\nd\ne\nf\n");
    ListeChaineeTrajets* liste = gestionnaire.lireSauvegarde(tmpSaveFile);

    if(liste == nullptr) {
      std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
      std::cout << RED << "FAILED" << RESET << std::endl;
    }

    std::cout << std::endl;
  }

}

std::string GestionnaireSauvegardeTrajetsTest::lireContenuFichier(const std::string unNomFichier) const {

  std::ifstream in(unNomFichier);
  std::string line;
  std::string text;

  if(in.is_open()) {
    while(getline(in, line)) {
      text += line + '\n';
    }
  }

  return text;
}

void GestionnaireSauvegardeTrajetsTest::ecrireContenuFichier(const std::string unNomFichier, const std::string contenu) const {

  std::ofstream out;
  out.open(unNomFichier);

  if(out.is_open()) {
    out << contenu;
  }

  out.close();

}
