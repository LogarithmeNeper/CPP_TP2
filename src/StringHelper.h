#if ! defined(STRING_HELPER_H)
#define STRING_HELPER_H

#include <string.h>
#include <stdlib.h>

static bool strempty(const char* str)
// Mode d'emploi :
//    Retourne vrai si la chaîne de caractères est vide
//
// Contrat :
//    Retourne vrai si la chaîne de caractère ne contient aucun caractères, que des espaces, tabulations, ou si elle est nulle
//
// Algorithme :
//    Parcourt tous les caractères de la chaîne de caractère
//    Dès qu'un caractère différent d'une espace est rencontré, retourne faux
//    Si la chaîne de caractères ne contient aucun caractère ou que des espaces, retourne vrai
{
  if(str == nullptr)
  {
    return true;
  }

  for(unsigned int i = 0; i < strlen(str); ++i)
  {
    if(str[i] != ' ' && str[i] != '\t')
    {
      return false;
    }
  }
  return true;
}

static bool estEntierNaturel(const char* str)
// Mode d'emploi :
//    Retourne vrai si la chaîne de caractères est un nombre entier naturel
//
// Contrat :
//    Retourne vrai si la chaîne de caractère ne contient que des caractères entre 0 et 9
//
// Algorithme :
//    Parcourt tous les caractères de la chaîne de caractère
//    Dès qu'un caractère différent d'un digit est rencontré, retourne faux
//    Si la chaîne de caractères ne contient aucun caractère ou que des espaces, retourne faux
{
  if(strempty(str)) {
    return false;
  }

  for(unsigned int i = 0; i < strlen(str); ++i) {
    if(!std::isdigit(str[i])) {
      return false;
    }
  }

  return true;
}

#endif
