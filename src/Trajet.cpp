#include "Trajet.h"

Trajet::Trajet() : indice(0) {}

Trajet::~Trajet( ) {}

unsigned int Trajet::getIndice() const
{
  return indice;
}

void Trajet::setIndice(unsigned int unIndice)
{
  indice = unIndice;
}
