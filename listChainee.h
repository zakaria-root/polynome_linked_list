#include <stdio.h>
#include <stdlib.h>
#include "listSimplementChainee.h"

poly_t *creerMonome(monome_t element)
{
  poly_t *p;
  p = (poly_t *)malloc(sizeof(poly_t));
  p->element.c = element.c;
  p->element.d = element.d;
  p->suive = NULL;
  return p;
}

// -------------------- CREE UN NOEUD ----------------------------

// poly_t *ajouterMonome(poly_t *debut, monome_t element)
// {
//   poly_t *noeud = creerMonome(element);
//   if (debut == NULL)
//     debut = noeud;
//   else
//   {
//     noeud->suive = debut;
//     debut = noeud;
//   }
//   return debut;
// }

// -------------------- AJOUTER UN NOEUD AU DEBUT ----------------------------

poly_t* additionPoly(poly_t* poly1, poly_t* poly2,poly_t* poly3){
  if (poly1 == NULL)
  return poly2;
  if (poly2 == NULL)
  return poly1;

  monome_t element;
  element.d=0;
  poly_t* temp1 = poly1;
  poly_t* temp2 = poly2;
  while (temp1 != NULL || temp2 != NULL)
  {
    if (temp1 == NULL)
    element.c = temp2->element.c;

    if (temp2 == NULL)
    element.c = temp1->element.c;

    if (temp1 != NULL && temp2 != NULL)
    element.c = temp1->element.c + temp2->element.c;

    if (element.c != 0)
    poly3 = ajouterEnFin(poly3, element);
    if (temp1 != NULL)
    temp1 = temp1->suive;
    if (temp2 != NULL)
    temp2 = temp2->suive;
    element.d += 1;
  }
  
  
  return poly3;
}

// -------------------- ADDITION DES DEUX POLYNOMES ----------------------------

poly_t* produitPoly(poly_t* poly1, poly_t* poly2,poly_t* poly3){
  
}

// -------------------- PRODUIT DES DEUX POLYNOMES ----------------------------

poly_t *ajouterEnFin(poly_t *debut, monome_t element)
{
  poly_t *noeud = creerMonome(element);
  if (debut == NULL)
    return noeud; 
  else
  {
    poly_t *temp = debut;
    if (temp->element.d == element.d)
    {
      debut = debut->suive;
      free(temp);
      return debut;
    }
    
    poly_t *pred =NULL;
    while (temp != NULL && temp->element.d != element.d)
      { 
        pred = temp;
        temp = temp->suive;
      }
      
if (temp != NULL)
{
        temp->element.c += element.c;
        if (temp->element.c == 0)
        {
          pred->suive = temp->suive;
          free(temp);

        }
        return debut;
  }
  temp = debut;
    while (temp->suive != NULL)
      temp = temp->suive;
    temp->suive = noeud;

  }
  return debut;

    
}

// -------------------- AJOUTER UN MONOMEA LE POLYNOMIAL  ----------------------------






// noeud_t *ajouterApreElement(noeud_t *debut, objet_t valeur, objet_t element)
// {
//   noeud_t *noeud = creeNoeud(valeur);
//   if (debut == NULL)
//     debut = noeud;
//   else
//   {
//     noeud_t *temp = debut;
//     while (temp != NULL && temp->valeur != element)
//       temp = temp->suive;
//     if (temp != NULL)
//     {
//       noeud->suive = temp->suive;
//       temp->suive = noeud;
//     }
//   }
//   return debut;
// }

// -------------------- AJOUTER UN NOEUD APRES UN ELEMNT ----------------------------

// noeud_t *ajouteravantElement(noeud_t *debut, objet_t valeur, objet_t element)
// {
//   noeud_t *noeud = creeNoeud(valeur);
//   if (debut == NULL)
//     debut = noeud;
//   else
//   {
//     if (debut->valeur == element)
//     {
//       noeud->suive = debut;
//       debut = noeud;
//     }
//     else
//     {
//       noeu_t *temp = debut;
//       while (temp->suive != NULL && temp->valeur != element)
//         temp = temp->suive;
//       if (temp->suive != NULL)
//       {
//         noeud->suive = temp->suive;
//         temp->suive = noeud;
//       }
//     }
//   }
//   return debut;
// }

// -------------------- AJOUTER UN NOEUD AVANT UN ELEMNT ----------------------------

// void supprimerAuDebut(noeud_t **debut)
// {
//   if (*debut != NULL)
//   {
//     noeud_t *temp = *debut;
//     *debut = (*debut)->suive;
//     free(temp);
//   }
// }

// -------------------- SUPPRIMER AU DEBUT ----------------------------

// void supprimerEnFin(noeud_t **debut)
// {
//   if (*debut != NULL)
//   {
//     noeud_t *temp = *debut;
//     noeud_t *temp1;
//     while (temp->suive->suive != NULL)
//       temp = temp->suive;
//     temp1 = temp->suive;
//     temp->suive = NULL;
//     free(temp1);
//   }
// }

// -------------------- SUPPRIMER A LA FIN ----------------------------

// void supprimerApreElement(noeud_t **debut, objet_t element)
// {
//   if (*debut != NULL)
//   {
//     noeud_t *temp1;
//     if ((*debut)->valeur == element)
//     {
//       temp1 = (*debut)->suive;
//       (*debut)->suive = (*debut)->suive->suive;
//     }
//     else
//     {
//       noeud_t *temp = *debut;
//       while (temp->suive->suive != NULL && temp->suive->valeur != element)
//         temp = temp->suive;
//       if (temp->suive->suive != NULL)
//       {
//         temp1 = temp->suive;
//         temp->suive = temp->suive->suive;
//       }
//     }
//     free(temp1);
//   }
// }

// -------------------- SUPPRIMER APRES UN ELEMNT ----------------------------

// void supprimeravantElement(noeud_t **debut, objet_t element)
// {
//   if (*debut != NULL)
//   {
//     noeud_t *temp1;
//     if ((*debut)->suive->valeur == element)
//     {
//       temp1 = *debut;
//       (*debut) = (*debut)->suive;
//     }
//     else
//     {
//       noeud_t *temp = *debut;
//       noeud_t *pred = NULL;
//       while (temp->suive->suive != NULL && temp->suive->valeur != element)
//       {
//         pred->suive = temp;
//         temp = temp->suive;
//       }
//       if (temp->suive->suive != NULL)
//       {
//         temp1 = temp;
//         pred->suive = temp->suive;
//       }
//     }
//     free(temp1);
//   }
// }

// -------------------- SUPPRIMER AVANT UN ELEMENT ----------------------------

void afficherList(poly_t *debut)
{
  if (debut == NULL)
    printf("le polynome est vide \n");
  else
  {
    poly_t *temp = debut;
    printf("P(X) = ");
    
    while (temp != NULL)
    {
      (temp->element.c < 0 ?
            (temp->element.d != 0 ? (printf(" - %.1f X^%1d",temp->element.c*-1,temp->element.d)) : printf(" %.1f",temp->element.c*-1))
            :
            (temp->element.d != 0 ? ( printf(" + %.1f X^%1d", temp->element.c,temp->element.d)) : printf(" %.1f",temp->element.c))
            );
      temp = temp->suive;
    }

  }
}

// -------------------- AFFICHER LE POLYNOME ----------------------------
