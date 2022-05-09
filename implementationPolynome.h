#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"
#include "assert.h"
poly_t *creerMonome(monome_t element)
{
  assert(element.d >= 0);
  poly_t *p;
  p = (poly_t *)malloc(sizeof(poly_t));
  p->element.c = element.c;
  p->element.d = element.d;
  p->suive = NULL;
  return p;
}

// -------------------- CREER UN MONOME ----------------------------

poly_t *additionPoly(poly_t *poly1, poly_t *poly2, poly_t *poly3)
{
  if (poly1 == NULL)
    return poly2;
  if (poly2 == NULL)
    return poly1;
  poly3 = NULL;

  monome_t element1;
  monome_t element2;
  poly_t *temp1 = poly1;
  poly_t *temp2 = poly2;
  int egaux;
  while (temp1 != NULL || temp2 != NULL)
  {
    egaux = 1;
    if (temp1 == NULL)
    {
      element1.c = temp2->element.c;
      element1.d = temp2->element.d;
    }

    if (temp2 == NULL)
    {
      element1.c = temp1->element.c;
      element1.d = temp1->element.d;
    }

    if (temp1 != NULL && temp2 != NULL)
    {
      if (temp1->element.d == temp2->element.d)
      {
        element1.c = temp1->element.c + temp2->element.c;
        element1.d = temp2->element.d;
      }
      else
      {
        element1.c = temp1->element.c;
        element1.d = temp1->element.d;
        element2.c = temp2->element.c;
        element2.d = temp2->element.d;
        egaux = 0;
      }
    }

    if (element1.c != 0)
      poly3 = ajouterEnFin(poly3, element1);
    if (egaux == 0)
      poly3 = ajouterEnFin(poly3, element2);

    if (temp1 != NULL)
      temp1 = temp1->suive;
    if (temp2 != NULL)
      temp2 = temp2->suive;
  }

  return poly3;
}

// -------------------- ADDITION DES DEUX POLYNOMES ----------------------------

poly_t *produitPoly(poly_t *poly1, poly_t *poly2, poly_t *poly3)
{
  if (poly1 == NULL)
    return NULL;
  if (poly2 == NULL)
    return NULL;
  poly3 = NULL;
  poly_t *temp1 = poly1;
  while (temp1 != NULL)
  {
    poly_t *temp2 = poly2;
    while (temp2 != NULL)
    {
      monome_t element;
      element.c = temp1->element.c * temp2->element.c;
      element.d = temp1->element.d + temp2->element.d;
      poly3 = ajouterEnFin(poly3, element);
      temp2 = temp2->suive;
    }
    temp1 = temp1->suive;
  }
  return poly3;
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
    poly_t *pred = NULL;
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
    pred = NULL;
    while (temp != NULL && temp->element.d <= element.d)
    {
      pred = temp;
      temp = temp->suive;
    }
    if (temp != NULL)
    {
      noeud->suive = temp;
      pred->suive = noeud;
    }
    else
    {
      pred->suive = noeud;
    }
  }
  return debut;
}

// -------------------- AJOUTER UN MONOMEA LE POLYNOMIAL  ----------------------------

poly_t *supprimerPoly(poly_t *poly)
{
  if (poly != NULL)
  {
    poly_t *curr;
    do
    {
      curr = poly;
      if (curr->suive == NULL)
      {
        free(curr);
        return NULL;
      }

      while (curr->suive->suive != NULL)
        curr = curr->suive;

      poly_t *temp = curr->suive;
      curr->suive = NULL;
      free(temp);
    } while (curr != NULL);
    return poly;
  }
  return poly;
}

// -------------------- SUPPRIMER LE POLYNOME  ----------------------------

void afficherPoly(poly_t *debut)
{
  if (debut == NULL)
    printf("le polynome est vide \n");
  else
  {
    poly_t *temp = debut;
    printf("P(X) = ");

    while (temp != NULL)
    {
      (temp->element.c < 0 ? (temp->element.d != 0 ? (printf(" - %.1f X^%1d", temp->element.c * -1, temp->element.d)) : printf(" %.1f", temp->element.c * -1))
                           : (temp->element.d != 0 ? (printf(" + %.1f X^%1d", temp->element.c, temp->element.d)) : printf(" %.1f", temp->element.c)));
      temp = temp->suive;
    }
  }
}

// -------------------- AFFICHER LE POLYNOME ----------------------------

poly_t *deriverPoly(poly_t *debut, poly_t *poly2)
{
  if (debut != NULL)
  {
    poly_t *temp = debut;
    while (temp != NULL)
    {
      if (temp->element.d != 0)
      {
        monome_t m;
        m.c = temp->element.c * temp->element.d;
        m.d = temp->element.d - 1;
        poly2 = ajouterEnFin(poly2, m);
      }
      temp = temp->suive;
    }
    return poly2;
  }
  return debut;
}

// -------------------- DERIVER DU POLYNOME ----------------------------

poly_t *integralePoly(poly_t *debut, poly_t *poly2)
{
  if (debut != NULL)
  {
    poly_t *temp = debut;
    while (temp != NULL)
    {
      monome_t mon;

      if (temp->element.d > 0)
        mon.c = temp->element.c / (temp->element.d + 1);
      else
        mon.c = temp->element.c;
      mon.d = temp->element.d + 1;
      poly2 = ajouterEnFin(poly2, mon);
      temp = temp->suive;
    }
    return poly2;
  }
  return debut;
}

// -------------------- INTEGRALE DU POLYNOME ----------------------------
