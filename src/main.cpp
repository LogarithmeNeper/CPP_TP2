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

static void sauvegarde(Catalogue & catalogue)
{
    string path;
    unsigned int choix;
    cout << "Emplacement pour la sauvegarde du fichier : ";
    cin.clear();
    getline(cin,path);
    path = path + ".txt";
    GestionnaireSauvegardeTrajets gestionnaire;
    string vDep,vArr;
    unsigned int indiceDep,indiceFin;
    cout << "Type de sauvegarde" << endl;
    cout << "\t1 - Aucun filtre" << endl;
    cout << "\t2 - Filtre sur le type de trajet" << endl;
    cout << "\t3 - Filtre sur la ville de départ" << endl;
    cout << "\t4 - Filtre sur la ville d'arrivée" << endl;
    cout << "\t5 - Filtre sur la ville de départ et d'arrivée" << endl;
    cout << "\t6 - Filtre sur un intervalle (indice de départ et indice de fin)" << endl;
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

    case 1:
      gestionnaire.ecrireSauvegarde(catalogue,path);
      cout << "Sauvegarde effectuée !" << endl;
    break;
    case 2:
      do {
        cout << "Type de trajet (1) Simple ou (2) Compose : ";
        cin >> choix;

        if(cin.fail() || choix < 1 || choix > 2) {
          cout << "Choix invalide." << endl;
          cin.clear();
        }

        cin.ignore(10000, '\n');

      } while(choix < 1 || choix > 2);
      if(choix == 1)
      {
          gestionnaire.ecrireSauvegarde(FiltreTrajets::filtrerParType(catalogue,TypeTrajet::SIMPLE),path);
      } else
        {
            gestionnaire.ecrireSauvegarde(FiltreTrajets::filtrerParType(catalogue,TypeTrajet::COMPOSE),path);
        }
      cout << "Sauvegarde effectuée !" << endl;
    break;
    case 3:
      cout << "Ville de départ : ";
      cin.clear();
      getline(cin,vDep);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      gestionnaire.ecrireSauvegarde(FiltreTrajets::filtrerParVilleDepart(catalogue, vDep),path);
      cout << "Sauvegarde effectuée !" << endl;
    break;
    case 4:
      cout << "Ville d'arrivée : ";
      cin.clear();
      getline(cin,vArr);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      gestionnaire.ecrireSauvegarde(FiltreTrajets::filtrerParVilleArrivee(catalogue,vArr),path);
      cout << "Sauvegarde effectuée !" << endl;
    break;
    case 5:
      cout << "Ville de départ : ";
      cin.clear();
      getline(cin,vDep);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      cout << "Ville d'arrivée : ";
      cin.clear();
      getline(cin,vArr);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      gestionnaire.ecrireSauvegarde(FiltreTrajets::filtrerParVilleDepartEtArrivee(catalogue,vDep,vArr),path);
      cout << "Sauvegarde effectuée !" << endl;
    break;
    case 6:
      cout << "Indice de début : ";
      cin >> indiceDep;
      cout << "Indice de fin : ";
      cin >> indiceFin;
      gestionnaire.ecrireSauvegarde(FiltreTrajets::filtrerParIntervalle(catalogue,indiceDep,indiceFin),path);
      cout << "Sauvegarde effectuée !" << endl;
    break;
    default:
    break;
    }
}

static void lecture (Catalogue & catalogue)
{
    string path;
    unsigned int choix;
    cout << "Nom du fichier : ";
    cin.clear();
    getline(cin,path);
    path = path + ".txt";
    GestionnaireSauvegardeTrajets gestionnaire;
    string vDep,vArr;
    unsigned int indiceDep,indiceFin;
    cout << "Type de lecture" << endl;
    cout << "\t1 - Aucun filtre" << endl;
    cout << "\t2 - Filtre sur le type de trajet" << endl;
    cout << "\t3 - Filtre sur la ville de départ" << endl;
    cout << "\t4 - Filtre sur la ville d'arrivée" << endl;
    cout << "\t5 - Filtre sur la ville de départ et d'arrivée" << endl;
    cout << "\t6 - Filtre sur un intervalle (indice de départ et indice de fin)" << endl;
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
    ListeChaineeTrajets listeComplete;
    listeComplete = gestionnaire.lireSauvegarde(listeComplete,path);
    switch(choix) {

    case 1:
      catalogue.ajouterListeTrajets(listeComplete);
    break;
    case 2:
      do {
        cout << "Type de trajet (1) Simple ou (2) Compose : ";
        cin >> choix;

        if(cin.fail() || choix < 1 || choix > 2) {
          cout << "Choix invalide." << endl;
          cin.clear();
        }

        cin.ignore(10000, '\n');

      } while(choix < 1 || choix > 2);
      if(choix == 1)
      {
          catalogue.ajouterListeTrajets(FiltreTrajets::filtrerParTypeAvecSuppression(listeComplete,TypeTrajet::SIMPLE));
      } else
        {
            catalogue.ajouterListeTrajets(FiltreTrajets::filtrerParTypeAvecSuppression(listeComplete,TypeTrajet::COMPOSE));
        }
    break;
    case 3:
      cout << "Ville de départ : ";
      cin.clear();
      getline(cin,vDep);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      catalogue.ajouterListeTrajets(FiltreTrajets::filtrerParVilleDepartAvecSuppression(listeComplete, vDep));
    break;
    case 4:
      cout << "Ville d'arrivée : ";
      cin.clear();
      getline(cin,vArr);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      catalogue.ajouterListeTrajets(FiltreTrajets::filtrerParVilleArriveeAvecSuppression(listeComplete,vArr));
    break;
    case 5:
      cout << "Ville de départ : ";
      cin.clear();
      getline(cin,vDep);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      cout << "Ville d'arrivée : ";
      cin.clear();
      getline(cin,vArr);
      if(cin.fail())
      {
        cout << "Entrée invalide." << endl;
        break;
      }
      catalogue.ajouterListeTrajets(FiltreTrajets::filtrerParVilleDepartEtArriveeAvecSuppression(listeComplete,vDep,vArr));
    break;
    case 6:
      cout << "Indice de début : ";
      cin >> indiceDep;
      cout << "Indice de fin : ";
      cin >> indiceFin;
      catalogue.ajouterListeTrajets(FiltreTrajets::filtrerParIntervalleAvecSuppression(listeComplete,indiceDep,indiceFin));
    break;
    default:
    break;
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
