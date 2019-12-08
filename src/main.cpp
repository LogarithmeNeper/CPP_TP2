#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#include <string.h>

#include <iostream>
using namespace std;

static void afficherCatalogue(const Catalogue & catalogue)
{
  cout << endl << " ======  CATALOGUE ====== " << endl << endl;
  catalogue.afficher(cout);
  cout << endl << endl << " === FIN DU CATALOGUE === " << endl << endl;
}

static void ajouterTrajetSimple(Catalogue & catalogue)
{
  cout << endl << " ===  AJOUT D'UN TRAJET SIMPLE === " << endl << endl;
  TrajetSimple* trajetSimple = nullptr;
  char* villeDepart = new char[100];
  char* villeArrivee = new char[100];
  char* typeTransport = new char[100];

  do {
    delete trajetSimple;
    cout << "Ville de départ: ";
    cin >> villeDepart;
    cout << "Ville d'arrivée: ";
    cin >> villeArrivee;
    cout << "Type de transport: ";
    cin >> typeTransport;
    trajetSimple = new TrajetSimple(villeDepart, villeArrivee, typeTransport);
  } while(!catalogue.ajouter(trajetSimple));

  cout << endl << " ======== FIN DE L'AJOUT ======== " << endl << endl;
}

static void ajouterTrajetCompose(Catalogue & catalogue)
{
  cout << endl << " ===  AJOUT D'UN TRAJET COMPOSE === " << endl;
  TrajetCompose* trajetCompose = new TrajetCompose();
  char ajouterTrajetSimple;

  do
  {
    do
    {
      TrajetSimple* trajetSimple = nullptr;

      do
      {
        char* villeDepart = new char[100];
        char* villeArrivee = new char[100];
        char* typeTransport = new char[100];
        cout << endl << ">>> Ajout d'un trajet simple <<<" << endl;
        cout << "Ville de départ: ";
        cin >> villeDepart;
        cout << "Ville d'arrivée: ";
        cin >> villeArrivee;
        cout << "Type de transport: ";
        cin >> typeTransport;
        trajetSimple = new TrajetSimple(villeDepart, villeArrivee, typeTransport);
      } while(!trajetCompose->ajouter(trajetSimple));

      do
      {
        cout << endl << "Ajouter un autre trajet simple (o/n) ? ";
        cin >> ajouterTrajetSimple;

        if(ajouterTrajetSimple != 'o' && ajouterTrajetSimple != 'n')
        {
          cout << "Veuillez écrire o ou n." << endl;
        }
      } while(ajouterTrajetSimple != 'o' && ajouterTrajetSimple != 'n');

    } while(ajouterTrajetSimple == 'o');

  } while(!catalogue.ajouter(trajetCompose));

  cout << " ======== FIN DE L'AJOUT ======== " << endl << endl;
}

static void supprimerTrajet(Catalogue & catalogue)
{
  cout << endl << " ===  SUPPRESSION D'UN TRAJET === " << endl;

  if(catalogue.estVide())
  {
    cout << "Aucun trajet à supprimer." << endl;
  }
  else
  {
    unsigned int numeroTrajet;

    do
    {
      cout << "Entrez le numéro de trajet à supprimer (entre 1 et " << catalogue.getTaille() << "): ";
      cin >> numeroTrajet;

      if(numeroTrajet < 1 || numeroTrajet > catalogue.getTaille())
      {
        cout << "Numéro de trajet invalide." << endl;
      }
    } while(numeroTrajet < 1 || numeroTrajet > catalogue.getTaille());

    catalogue.supprimer(catalogue.getMaillonListeChaineeTrajets(numeroTrajet - 1)->getTrajet());
  }
  cout << " ====== FIN DE LA SUPPRESSION ====== " << endl << endl;
}

static void rechercheTrajetSimple(Catalogue & catalogue)
{
  cout << endl << " =====  RECHERCHE DE TRAJET SIMPLE ===== " << endl << endl;
  char villeDepart[100];
  char villeArrivee[100];
  cout << "Ville de départ: ";
  cin >> villeDepart;
  cout << "Ville d'arrivée: ";
  cin >> villeArrivee;
  catalogue.rechercheTrajetSimple(villeDepart, villeArrivee);
  cout << endl << " ==  FIN DE RECHERCHE DE TRAJET SIMPLE == " << endl;
}

static void rechercheTrajetAvancee(Catalogue & catalogue)
{
  cout << endl << " =====  RECHERCHE DE TRAJET AVANCEE ===== " << endl << endl;
  char villeDepart[100];
  char villeArrivee[100];
  cout << "Ville de départ: ";
  cin >> villeDepart;
  cout << "Ville d'arrivée: ";
  cin >> villeArrivee;
  catalogue.rechercheTrajetAvancee(villeDepart, villeArrivee);
  cout << endl << " ==  FIN DE RECHERCHE DE TRAJET AVANCEE == " << endl;
}

int main(void)
{
  //Instance unique du Catalogue
  Catalogue catalogue;

  unsigned short choix;

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
    cout << "\t7 - Quitter" << endl;

    do {
      cout << "Entrez votre choix: ";
      cin >> choix;

      if(choix < 1 || choix > 7) {
        cout << "Choix invalide." << endl;
      }

    } while(choix < 1 || choix > 7);

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
      default:
      break;
    }

  } while(choix != 7);

  cout << " === FERMETURE DU PROGRAMME === " << endl;

  return 0;
}
