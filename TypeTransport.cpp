/*************************************************************************
TypeTransport  -  description
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe TypeTransport (fichier TypeTransport.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TypeTransport.h"
#include "StringHelper.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ostream & operator<<(ostream & out, const TypeTransport & typeTransport)
{
  out << typeTransport.nom;
  return out;
}

bool TypeTransport::estValide() const
// Algorithme :
//
{
  if(nom == NULL) {
    std::cerr << "Le nom du type de transport est invalide : NULL non autorisé." << std::endl;
    return false;
  }

  if(strempty(nom)) {
    std::cerr << "Le nom du type de transport est invalide : nom vide non autorisé." << std::endl;
    return false;
  }

  return true;
}

//-------------------------------------------- Constructeurs - destructeur

TypeTransport::TypeTransport ( const char* unNom ) : nom(unNom)
{
  #ifdef MAP
  cout << "Appel au constructeur de TypeTransport" << endl;
  #endif
} //----- Fin de TypeTransport

TypeTransport::~TypeTransport (  )
{
  #ifdef MAP
  cout << "Appel au destructeur de TypeTransport" << endl;
  #endif
} //----- Fin de ~TypeTransport

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
