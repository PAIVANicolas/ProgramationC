#include <stdio.h>


#define EXO2


int main() {

#ifdef EXO1

// a) Ecrire un programme qui lit la dimension N d'un tableau T du type int (dimension maximale: 50
// composantes), remplit le tableau par des valeurs entrées au clavier et affiche le tableau.
// b) Effacer ensuite toutes les occurrences de la valeur 0 dans le tableau T et "tasser" les éléments
// restants. Afficher le tableau résultant, puis afficher ensuite la taille totale réservée pour le tableau
// en octets puis la taille de la partie occupée du tableau. 

   int n;
   int tableau[50];

   printf("Entrez la dimension du tableau (maximum 50) : ");
   scanf("%d", &n);

   if (n > 50) {
      printf("Erreur : dimension trop grande.\n");
      return 1;
   }

   // Remplissage du tableau
   for (int i = 0; i < n; i++) {
      printf("Entrez un nombre : ");
      scanf("%d", &tableau[i]);
   }

   // Suppression des 0 et tassage des éléments
   int taille = n;
   for (int i = 0; i < taille; i++) {
      if (tableau[i] == 0) {
         taille--;
         for (int j = i; j < taille; j++) {
            tableau[j] = tableau[j+1];
         }
         i--;
      }
   }

   // Affichage du tableau résultant
   printf("Voici votre tableau après suppression des 0 : ");
   for (int i = 0; i < taille; i++) {
      printf("%d ", tableau[i]);
   }
   printf("\n");

   // Tailles en octets
   int taille_totale = sizeof(tableau);
   int taille_occupee = taille * sizeof(int);
   printf("Taille totale du tableau : %d octets\n", taille_totale);
   printf("Taille occupée du tableau : %d octets\n", taille_occupee);

#endif

#ifdef EXO2
//Réutilisez le tableau précédant (2.1 a) dans lequel vous rangerez les éléments du tableau T dans l'ordre
// inverse de saisie sans utiliser de tableau d'aide. Afficher le tableau résultant. 

   int tailleTableau;
   int tableau[50];

   printf("Entrez la dimension du tableau (maximum 50) : ");
   scanf("%d", &tailleTableau);

   if (tailleTableau > 50) {
      printf("Erreur : dimension trop grande.\n");
      return 1;
   }

   // Remplissage du tableau
   for (int i = 0; i < tailleTableau; i++) {
      printf("Entrez un nombre : ");
      scanf("%d", &tableau[i]);
   }

   // Affichage du tableau résultant
   printf("Voici votre tableau avec les valeurs dans le sens inverse : ");
   for (int i = tailleTableau - 1; i >= 0; i--) {
      printf("%d ", tableau[i]);
   }
   printf("\n");


#endif


#ifdef EXO3


#endif


#ifdef EXO4


#endif


#ifdef EXO5


#endif



   return 0;
   
}