#include <stdio.h>


#define EXO1

int main() {

   printf("Hello, World! \n");

#ifdef EXO1


   int nb;
   int n;
   int tableau[50];

   printf("Entrez la dimension du tableau (maximum 50) : ");
   scanf("%d", &n);

   if (n > 50) {
      printf("Erreur : dimension trop grande.\n");
      return 1;
   }

   for (int i = 0; i < n; i++) {
      printf("Entrez un nombre : ");
      scanf("%d", &nb);
      tableau[i] = nb;
   }

   printf("Voici votre tableau : ");
   for (int i = 0; i < n; i++) {
      printf("\n %d", tableau[i]);
   }
   printf("\n");

#endif


   return 0;
   
}