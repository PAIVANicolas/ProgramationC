#include <stdio.h>

#define Exo3

int main() {


#ifdef Exo1
/*
Ecrire un programme déclarant une variable numérique v et l'initialisant.
Déclarer un pointeur de type correspondant à cette variable et le faire pointer sur v.
Modifier la valeur de v indirectement en utilisant le pointeur.
Contrôler l'adresse et la valeur des variables au fur et à mesure des différentes instructions au moyen de
nombreuses instructions printf. 
*/

   int v = 42; // déclare une variable numérique v et l'initialise à 42
   printf("Adresse de v : %p\n", &v); // affiche l'adresse de v
   printf("Valeur de v : %d\n", v); // affiche la valeur de v

   int* p = &v; // déclare un pointeur de type correspondant à v et le fait pointer sur v
   printf("Adresse de p : %p\n", &p); // affiche l'adresse de p
   printf("Valeur de p : %p\n", p); // affiche la valeur de p (l'adresse de v)

   *p = 84; // modifie la valeur de v indirectement en utilisant le pointeur
   printf("Nouvelle valeur de v : %d\n", v); // affiche la nouvelle valeur de v


#endif

#ifdef Exo2 // Pointeur de pointeur
/*
Ecrire un programme déclarant une variable numérique v et l'initialisant.  
Déclarer un pointeur pv de type correspondant à cette variable et le faire pointer sur v.  
Déclarer un autre pointeur ppv de type approprié pour pouvoir pointer sur le pointeur pv.  
Faire pointer ppv sur pv.  
Modifier la valeur de v indirectement en utilisant le pointeur ppv.  
Faire un schéma de la mémoire pour bien comprendre, 
contrôler l'adresse et la valeur des variables au fur et à mesure des différentes instructions au moyen de nombreuses instructions printf. 
*/


   int v = 42;// déclare une variable numérique v et l'initialise à 42
   int* pv = &v;// déclare un pointeur de type correspondant à v et le fait pointer sur v
   int **ppv;// déclare un pointeur de type correspondant à pv
   ppv = &pv;// le fait pointer sur pv

   printf("Adresse de v : %p\n", &v);
    printf("Adresse de pv : %p\n", &pv);
    printf("Adresse de ppv : %p\n", &ppv);

    printf("Contenu de v : %d\n", v);
    printf("Contenu de pv : %p\n", pv);
    printf("Contenu de ppv : %p\n", ppv);

   **ppv = 10;

   printf("Nouvelle valeur de v : %d\n", v); // affiche la nouvelle valeur de v

#endif

#ifdef Exo3 // Passage de paramètre par référence

/*
Ecrire et appeler une fonction qui calcule la somme et la différence de deux entiers passés en paramètres. 
Comme la fonction doit renvoyer deux valeurs (la somme et la différence) 
il n'est pas possible d'utiliser le mécanisme de valeur de retour associée à return, 
on utilisera donc deux paramètres supplémentaires de type pointeur. 
Écrivez une fonction void somme(int *som, int *diff, int x, int y)
*/
//#include "main.h"

void somme(int *som, int *diff, int x, int y);


int x = 5, y = 3;
int s, d;
somme(&s, &d, x, y);
printf("La somme de %d et %d est %d\n", x, y, s);
printf("La différence de %d et %d est %d\n", x, y, d);
return 0;


#endif

#ifdef Exo4 //Pointeurs et Tableaux
/*
Ecrire une fonction qui convertit les entiers négatifs d'un tableau d'entiers non nuls (0 est utilisé pour marquer la fin du tableau) 
passé en paramètre en entiers positifs. 
Ne pas utiliser de variable d'indice mais un pointeur.
*/


#endif

#ifdef Exo5 // Pointeurs et Tableaux
/*
Réécrire la fonction strlen suivant renvoie la longueur d'une chaîne de caractères en utilisant les pointeurs 

int strlen(char s[]) 
{ 
   int i; 
   int len = 0; 
   for (i=0; s[i]!=0; i++) { 
      len++; 
   } 
   return len; 
} 

En fait comme s est un pointeur, on peut s'en servir pour parcourir la chaîne plutôt que d'utiliser une variable supplémentaire i.  
Il suffit pour cela de l'incrémenter pour le faire pointer successivement vers les différents caractères de la chaîne.

- Réécrire ainsi la fonction strlen en utilisant une seule variable locale. 
*/


#endif

#ifdef Exo6 //Pointeurs et Tableaux
/*
- Ecrire la fonction strcat(char *s, char *t) qui permet de rajouter la chaîne t à la fin de la chaîne s 
   (en supposant que s soit contenue dans un tableau de caractères de taille suffisante) 
   en utilisant des pointeurs et non une indexation par une variable entière. 
-  Ecrire de même la fonction strcpy(char *s, char *t) qui permet de copier la chaîne t dans la chaîne s. 
*/


#endif

#ifdef Exo7 //Structure simple
/*
Écrire un programme qui permet de saisir et d’afficher une structure personne contenant les champs : 

-  Nom 
-  Prénom 
-  Date de naissance 

Vous créerez pour cela une structure date qui sera imbriquée dans la structure personne. 
Déclarez un pointeur sur structure personne que vous initialiserez sur une personne créée précédemment 
puis accédez aux champs par l’intermédiaire de l’opérateur -> . 
*/



#endif

#ifdef Exo8 //Tableau de structure
/*
Écrire un programme qui permet de déclarer et saisir un tableau de structure personne. 
Dans un premier temps, le tableau sera déclaré statiquement, puis dynamiquement (allocation de mémoire). 
Trier le tableau de personnes en utilisant la fonction qsort de la bibliothèque stdlib
*/


#endif

#ifdef Exo9 // Structures
/*
Ecrire un programme C qui définit une structure point qui contiendra les deux coordonnées réelles d'un point du plan. 
Ecrire une fonction qui demande deux points. 
Ecrire une fonction qui affiche la distance entre deux points passés en paramètres
*/


#endif
   return 0;
   
}

void somme(int *som, int *diff, int x, int y) {
    *som = x + y;
    *diff = x - y;
}