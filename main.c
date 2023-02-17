#include <stdio.h>


#define EXO1

int main() {

   // printf("Hello, World! \n");

#ifdef EXO1
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


#endif


#ifdef EXO3


#endif


#ifdef EXO4


#endif


#ifdef EXO5


#endif



   return 0;
   
}