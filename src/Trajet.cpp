/*************************************************************************
Trajet  -  Une abstraction de trajet
-------------------
début                : 20/11/2019
copyright            : (C) 2019 par Charles Javerliat
e-mail               : charles.javerliat@insa-lyon.fr, pierre.sibut-bourde@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe Trajet (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

unsigned int Trajet::getIndice() const
{
  return indice;
}

void Trajet::setIndice(unsigned int unIndice)
{
  indice = unIndice;
}

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet() : indice(0) {}

Trajet::~Trajet( ) {}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
