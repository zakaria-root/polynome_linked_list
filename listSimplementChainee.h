#ifndef __LIST_SIMLEMENT_CHAINEE
#define __LIST_SIMLEMENT_CHAINEE
typedef struct
{
  float c;
  int d;
}monome_t;

typedef struct poly_t
{
  monome_t element;
  struct poly_t *suive;
} poly_t;

poly_t *creerMonome(monome_t);
// poly_t *ajouterMonome(poly_t *, monome_t);
poly_t *ajouterEnFin(poly_t *, monome_t);
poly_t *additionPoly(poly_t*, poly_t*, poly_t*);
poly_t* produitPoly(poly_t*, poly_t*,poly_t*);
// noeud_t *ajouterApreElement(noeud_t *, objet_t, objet_t);
// noeud_t *ajouteravantElement(noeud_t *, objet_t, objet_t);
// void supprimerAuDebut(noeud_t **);
// void supprimerEnFin(noeud_t **debut);
// void supprimerApreElement(noeud_t **debut, objet_t element);
// void supprimeravantElement(noeud_t **debut, objet_t element);
void afficherList(poly_t *);

#endif