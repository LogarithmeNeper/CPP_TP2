#include "Trajet.h"

Trajet::Trajet() : indice(0) {}

Trajet::~Trajet( ) {}

void Trajet::setIndice(unsigned int unIndice)
{
  indice = unIndice;
}

unsigned int Trajet::getIndice() const
{
  return indice;
}
