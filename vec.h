#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED

struct Vec
{
    double x, y;
};

typedef struct Vec Vec;

Vec add(Vec A, Vec B); // somme vectorielle

Vec sub(Vec A, Vec B); // soustraction vectorielle

double scal(Vec A, Vec B); // produit scalaire

double vec(Vec A, Vec B); // produit vectoriel

double norm(Vec A); // norme
double normSquared(Vec A); // carré de la norme, plus rapide que la norme

double angle(Vec A); // angle que forme A avec l'horizontale
double angleBetween(Vec A, Vec B); // angle entre les deux vecteurs A et B
Vec getVectWithNorm(Vec A, double norm); // calcule le vecteur colinéaire à A de norme norm

Vec rot(Vec A, double angle); // renvoie le vecteur A tourné d'un certain angle

#endif // VEC_H_INCLUDED
