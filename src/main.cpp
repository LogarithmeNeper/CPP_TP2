/*************************************************************************
Main  -  Classe principale servant d'interface entre l'utilisateur et le
système de gestion du catalogue
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "StringHelper.h"
#include "GestionnaireSauvegardeTrajets.h"
#include "FiltreTrajets.h"

// Contrat : Affiche le catalogue dans le terminal
static void afficherCatalogue(const Catalogue & catalogue)
{
  cout << endl << " ======  CATALOGUE ====== " << endl << endl;
  catalogue.afficher(cout);
  cout << endl << endl << " === FIN DU CATALOGUE === " << endl << endl;
}

// Contrat : Ajoute un trajet simple au Catalogue en demandant à l'utilisateur
// de renseigner les informations du trajet.
static void ajouterTrajetSimple(Catalogue & catalogue)
{
  cout << endl << " ===  AJOUT D'UN TRAJET SIMPLE === " << endl << endl;
  TrajetSimple* trajetSimple = nullptr;

  do
  {
    delete trajetSimple;
    char villeDepart[100];
    char villeArrivee[100];
    char typeTransport[100];

    //Prompt de la ville de départ
    do {
      villeDepart[0] = '\0';
      cout << "Ville de départ: ";
      cin.clear();
      cin.getline(villeDepart, sizeof(villeDepart));
    } while(cin.fail());

    //Prompt de la ville d'arrivée
    do {
      villeArrivee[0] = '\0';
      cout << "Ville d'arrivée: ";
      cin.clear();
      cin.getline(villeArrivee, sizeof(villeArrivee));
    } while(cin.fail());

    //Prompt du type de transport
    do {
      typeTransport[0] = '\0';
      cout << "Type de transport: ";
      cin.clear();
      cin.getline(typeTransport, sizeof(typeTransport));
    } while(cin.fail());

    trajetSimple = new TrajetSimple(villeDepart, villeArrivee, typeTransport);

    //On essaie d'ajouter le trajet, si il n'est pas valide on recommence
  } while(!catalogue.ajouter(trajetSimple));

  cout << endl << " ======== FIN DE L'AJOUT ======== " << endl << endl;
}

// Contrat : Ajoute un trajet composé au Catalogue en demandant à l'utilisateur
// de renseigner les informations du trajet, aka les différents trajets simples
// qui le constitue.
static void ajouterTrajetCompose(Catalogue & catalogue)
{
  cout << endl << " ===  AJOUT D'UN TRAJET COMPOSE === " << endl;
  TrajetCompose* trajetCompose = nullptr;

  //Variable contenant la valeur de retour (o/n) à la question de si
  //on souhaite rajouter un autre trajet simple
  char ajouterTrajetSimple;

  do
  {
    delete trajetCompose;
    trajetCompose = new TrajetCompose();

    do
    {
      TrajetSimple* trajetSimple = nullptr;

      //-------------------- Ajout d'un sous-trajet simple --------------------
      do
      {
        char villeDepart[100];
        char villeArrivee[100];
        char typeTransport[100];
        cout << endl << ">>> Ajout d'un trajet simple <<<" << endl;

        //Prompt de la ville de départ
        do {
          villeDepart[0] = '\0';
          cout << "Ville de départ: ";
          cin.clear();
          cin.getline(villeDepart, sizeof(villeDepart));
        } while(cin.fail());

        //Prompt de la ville d'arrivée
        do {
          villeArrivee[0] = '\0';
          cout << "Ville d'arrivée: ";
          cin.clear();
          cin.getline(villeArrivee, sizeof(villeArrivee));
        } while(cin.fail());

        //Prompt du type de transport
        do {
          typeTransport[0] = '\0';
          cout << "Type de transport: ";
          cin.clear();
          cin.getline(typeTransport, sizeof(typeTransport));
        } while(cin.fail());

        trajetSimple = new TrajetSimple(villeDepart, villeArrivee, typeTransport);

        //On essaie d'ajouter le trajet, si il n'est pas valide on recommence
      } while(!trajetCompose->ajouter(trajetSimple));
      //------------------------------------------------------------------------

      do
      {
        cout << endl << "Ajouter un autre trajet simple (o/n) ? ";
        cin.clear();
        cin >> ajouterTrajetSimple;
        cin.ignore(10000, '\n');

        if(cin.fail() || (ajouterTrajetSimple != 'o' && ajouterTrajetSimple != 'n'))
        {
          cout << "Veuillez écrire o ou n." << endl;
        }

        //Tant que l'utilisateur ne répond pas 'o' ou 'n', on recommence
      } while(cin.fail() || (ajouterTrajetSimple != 'o' && ajouterTrajetSimple != 'n'));

    } while(ajouterTrajetSimple == 'o');

    //On essaie d'ajouter le trajet, si il n'est pas valide on recommence
  } while(!catalogue.ajouter(trajetCompose));

  cout << " ======== FIN DE L'AJOUT ======== " << endl << endl;
}

// Contrat : Supprime un trajet du Catalogue en demandant à l'utilisateur
// de renseigner le numéro du trajet à supprimer.
static void supprimerTrajet(Catalogue & catalogue)
{
  cout << endl << " ===  SUPPRESSION D'UN TRAJET === " << endl;

  if(catalogue.estVide())
  {
    cout << endl << "Aucun trajet à supprimer." << endl;
  }
  else
  {
    unsigned int numeroTrajet;

    do
    {
      cout << endl << "Entrez le numéro de trajet à supprimer (entre 1 et " << catalogue.getTaille() << "): ";
      cin.clear();
      cin >> numeroTrajet;

      if(cin.fail() || numeroTrajet < 1 || numeroTrajet > catalogue.getTaille())
      {
        cout << "Numéro de trajet invalide." << endl;
        cin.clear();
      }
    } while(numeroTrajet < 1 || numeroTrajet > catalogue.getTaille());

    cin.ignore(10000, '\n');

    catalogue.supprimer(catalogue.get(numeroTrajet - 1)->getTrajet());
  }
  cout << endl << " ====== FIN DE LA SUPPRESSION ====== " << endl << endl;
}

// Contrat : Liste tous les trajets allant d'une ville à l'autre sans tester
// de combinaisons possibles de trajets. Demande à l'utilisateur d'entrée la
// ville de départ et d'arrivée.
static void rechercheTrajetSimple(Catalogue & catalogue)
{
  cout << endl << " =====  RECHERCHE DE TRAJET SIMPLE ===== " << endl << endl;
  char villeDepart[100];
  char villeArrivee[100];

  //Prompt de la ville de départ
  do
  {
    villeDepart[0] = '\0';
    cout << "Ville de départ: ";
    cin.clear();
    cin.getline(villeDepart, 100);

    if(cin.fail())
    {
      cout << "Entrée invalide." << endl;
    }
  } while(cin.fail());

  //Prompt de la ville d'arrivée
  do
  {
    villeArrivee[0] = '\0';
    cout << "Ville d'arrivée: ";
    cin.clear();
    cin.getline(villeArrivee, 100);

    if(cin.fail())
    {
      cout << "Entrée invalide." << endl;
    }

  } while(cin.fail());

  bool found = catalogue.rechercheTrajetSimple(villeDepart, villeArrivee);

  if(!found)
  {
    cout << endl << "Aucun trajet trouvé entre " << villeDepart << " et " << villeArrivee;
  }

  cout << endl << endl << " ==  FIN DE RECHERCHE DE TRAJET SIMPLE == " << endl << endl;
}

// Contrat : Liste tous les trajets allant d'une ville à l'autre en testant
// les combinaisons possibles de trajets. Demande à l'utilisateur d'entrée la
// ville de départ et d'arrivée.
static void rechercheTrajetAvancee(Catalogue & catalogue)
{
  cout << endl << " =====  RECHERCHE DE TRAJET AVANCEE ===== " << endl << endl;
  char villeDepart[100];
  char villeArrivee[100];

  //Prompt de la ville de départ
  do
  {
    villeDepart[0] = '\0';
    cout << "Ville de départ: ";
    cin.clear();
    cin.getline(villeDepart, 100);

    if(cin.fail())
    {
      cout << "Entrée invalide." << endl;
    }
  } while(cin.fail());

  //Prompt de la ville d'arrivée
  do
  {
    villeArrivee[0] = '\0';
    cout << "Ville d'arrivée: ";
    cin.clear();
    cin.getline(villeArrivee, 100);

    if(cin.fail())
    {
      cout << "Entrée invalide." << endl;
    }
  } while(cin.fail());

  bool found = catalogue.rechercheTrajetAvancee(villeDepart, villeArrivee);

  if(!found)
  {
    cout << endl << "Aucun trajet trouvé entre " << villeDepart << " et " << villeArrivee;
  }

  cout << endl << endl << " ==  FIN DE RECHERCHE DE TRAJET AVANCEE == " << endl << endl;
}

static ListeChaineeTrajets* appliquerFiltre(const ListeChaineeTrajets & liste) {

  ListeChaineeTrajets* listeFiltree = nullptr;
  unsigned int choix;

  unsigned int typeTrajet;

  string villeDepart;
  string villeArrivee;

  unsigned int indiceDebut;
  unsigned int indiceFin;

  cout << endl << "Type de filtre à appliquer" << endl;
  cout << "\t1 - Aucun filtre" << endl;
  cout << "\t2 - Filtre sur le type de trajet" << endl;
  cout << "\t3 - Filtre sur la ville de départ" << endl;
  cout << "\t4 - Filtre sur la ville d'arrivée" << endl;
  cout << "\t5 - Filtre sur la ville de départ et d'arrivée" << endl;
  cout << "\t6 - Filtre sur un intervalle (trajet numéro n à trajet numéro m inclus)" << endl;
  cout << "\t7 - Quitter" << endl;

  //Prompt de l'action à effectuer pour la sauvegarde
  do {
    cout << "Entrez votre choix: ";
    cin >> choix;

    if(cin.fail() || choix < 1 || choix > 7) {
      cout << "Choix invalide." << endl;
      cin.clear();
    }

    cin.ignore(10000, '\n');

  } while(choix < 1 || choix > 7);

  switch(choix) {

    case 1: {
      //Simple copie de la liste
      listeFiltree = new ListeChaineeTrajets;

      MaillonListeChaineeTrajets* maillonAct = liste.getPremierMaillon();
      while(maillonAct != nullptr) {
        listeFiltree->ajouter(maillonAct->getTrajet());
        maillonAct = maillonAct->getMaillonSuivant();
      }
      break;
    }

    case 2: {
      //Prompt du type de trajet à conserver
      do {
        cout << "Type de trajet (1) Simple ou (2) Compose : ";
        cin >> typeTrajet;

        if(cin.fail() || typeTrajet < 1 || typeTrajet > 2) {
          cout << "Choix invalide." << endl;
          cin.clear();
        }

        cin.ignore(10000, '\n');
      } while(typeTrajet < 1 || typeTrajet > 2);

      listeFiltree = FiltreTrajets::filtrerParType(liste, typeTrajet == 1 ? TypeTrajet::SIMPLE : TypeTrajet::COMPOSE);
      break;
    }

    case 3: {
      cout << "Ville de départ : ";
      cin.clear();
      getline(cin, villeDepart);

      if(cin.fail()) {
        cout << "Entrée invalide." << endl;
        break;
      }

      listeFiltree = FiltreTrajets::filtrerParVilleDepart(liste, villeDepart);
      break;
    }

    case 4: {
      cout << "Ville d'arrivée : ";
      cin.clear();
      getline(cin, villeArrivee);

      if(cin.fail()) {
        cout << "Entrée invalide." << endl;
        break;
      }

      listeFiltree = FiltreTrajets::filtrerParVilleArrivee(liste, villeArrivee);
      break;
    }

    case 5: {
      cout << "Ville de départ : ";
      cin.clear();
      getline(cin, villeDepart);
      if(cin.fail()) {
        cout << "Entrée invalide." << endl;
        break;
      }
      cout << "Ville d'arrivée : ";
      cin.clear();
      getline(cin, villeArrivee);
      if(cin.fail()) {
        cout << "Entrée invalide." << endl;
        break;
      }
      listeFiltree = FiltreTrajets::filtrerParVilleDepartEtArrivee(liste, villeDepart, villeArrivee);
      break;
    }

    case 6: {
      if(!liste.estVide()) {

        do {
          cout << "Début de l'intervalle (entre 1 et " << liste.getTaille() << ") : ";
          cin >> indiceDebut;

          if(cin.fail() || indiceDebut < 1 || indiceDebut > liste.getTaille()) {
            cout << "Choix invalide." << endl;
            cin.clear();
          }

          cin.ignore(10000, '\n');

        } while(indiceDebut < 1 || indiceDebut > liste.getTaille());

        indiceDebut--;

        do {
          cout << "Fin de l'intervalle (entre " << (indiceDebut+1) << " et " << liste.getTaille() << "): ";
          cin >> indiceFin;

          if(cin.fail() || indiceFin < indiceDebut + 1 || indiceFin > liste.getTaille()) {
            cout << "Choix invalide." << endl;
            cin.clear();
          }

          cin.ignore(10000, '\n');

        } while(indiceFin < indiceDebut + 1 || indiceFin > liste.getTaille());

        indiceFin--;

        listeFiltree = FiltreTrajets::filtrerParIntervalle(liste, indiceDebut, indiceFin);
      } else {
        cout << "Liste de trajets vide. Le filtre donne une liste vide.";
        listeFiltree = new ListeChaineeTrajets;
      }
      break;
    }

    default:
    break;
  }

  return listeFiltree;
}

static void sauvegarde(const Catalogue & catalogue)
{
  string nomFichier;

  //Lecture du chemin de sauvegarde
  cout << endl << "Nom du fichier de sauvegarde : ";
  cin.clear();
  getline(cin, nomFichier);

  ListeChaineeTrajets* listeFiltree = appliquerFiltre(catalogue);

  if(GestionnaireSauvegardeTrajets::ecrireSauvegarde(*listeFiltree, nomFichier)) {
    cout << endl << "Sauvegarde réussie !" << endl << endl;
  } else {
    cout << endl << "Erreur de sauvegarde." << endl << endl;
  }

  delete listeFiltree;
}

static void lecture(Catalogue & catalogue)
{
  string nomFichier;

  cout << endl << "Nom du fichier à lire : ";
  cin.clear();
  getline(cin, nomFichier);

  ListeChaineeTrajets* liste = GestionnaireSauvegardeTrajets::lireSauvegarde(nomFichier);

  if(liste != nullptr) {

    ListeChaineeTrajets* listeFiltree = appliquerFiltre(*liste);

    catalogue.ajouterListeTrajets(*listeFiltree);
    cout << endl << "Chargement réussi !" << endl << endl;

    //Supprime tous les trajets chargés mais qui ne sont finalement pas utilisés
    MaillonListeChaineeTrajets* maillonAct = liste->getPremierMaillon();
    while(maillonAct != nullptr) {
      if(!listeFiltree->contient(maillonAct->getTrajet())) {
        delete maillonAct->getTrajet();
      }
      maillonAct = maillonAct->getMaillonSuivant();
    }

    delete listeFiltree;
    delete liste;

  } else {
    cout << endl << "Erreur de chargement." << endl << endl;
  }
}

int main(void)
{
  //Instance unique du Catalogue sur la pile
  Catalogue catalogue;

  unsigned short choix = 0;

  cout << " === PROGRAMME DE GESTION DE CATALOGUE === " << endl;

  do
  {
    cout << "Que désirez-vous faire ?" << endl;
    cout << "\t1 - Afficher le catalogue" << endl;
    cout << "\t2 - Ajouter un trajet simple" << endl;
    cout << "\t3 - Ajouter un trajet composé" << endl;
    cout << "\t4 - Supprimer un trajet" << endl;
    cout << "\t5 - Recherche de trajet simple" << endl;
    cout << "\t6 - Recherche de trajet avancée" << endl;
    cout << "\t7 - Sauvegarde dans un fichier" << endl;
    cout << "\t8 - Lecture et ajout de trajets depuis un fichier" << endl;
    cout << "\t9 - Quitter" << endl;

    //Prompt de l'action à effectuer sur la Catalogue
    do {
      cout << "Entrez votre choix: ";
      cin >> choix;

      if(cin.fail() || choix < 1 || choix > 9) {
        cout << "Choix invalide." << endl;
        cin.clear();
      }

      cin.ignore(10000, '\n');

    } while(choix < 1 || choix > 9);

    switch(choix) {

      case 1:
      afficherCatalogue(catalogue);
      break;
      case 2:
      ajouterTrajetSimple(catalogue);
      break;
      case 3:
      ajouterTrajetCompose(catalogue);
      break;
      case 4:
      supprimerTrajet(catalogue);
      break;
      case 5:
      rechercheTrajetSimple(catalogue);
      break;
      case 6:
      rechercheTrajetAvancee(catalogue);
      break;
      case 7:
      sauvegarde(catalogue);
      break;
      case 8:
      lecture(catalogue);
      break;
      default:
      break;
    }

  } while(choix != 9);

  cout << endl << " === FERMETURE DU PROGRAMME === " << endl;

  return 0;
}
