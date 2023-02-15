#include <stdio.h>
#define EXO4

int main() {

#ifdef EXO1
   int ageLu;

   printf("Veulliez entre votre age : ");
   scanf("%d", &ageLu);
   printf("Votre age est : %d \n", ageLu);

#endif

#ifdef EXO2
   printf("\n %lu octets pour variable de type char ",sizeof(char));

   printf("\n %lu octets pour variable de type unsigned char ",sizeof(unsigned char));

   printf("\n %lu octets pour variable de type short_int ",sizeof(short int));

   printf("\n %lu octets pour variable de type int ",sizeof(int));

   printf("\n %lu octets pour variable de type long int ",sizeof(long int));

   printf("\n %lu octets pour variable de type float ",sizeof(float));

   printf("\n %lu octets pour variable de type double ",sizeof(double));

   printf("\n %lu octets pour adresse vers variable de type char ",sizeof(char * ));

   printf("\n %lu octets pour adresse vers variable de type unsigned char ",sizeof(unsigned char * ));

   printf("\n %lu octets pour adresse vers variable de type short_int ",sizeof(short int * ));

   printf("\n %lu octets pour adresse vers variable de type int ",sizeof(int ));

   printf("\n %lu octets pour adresse vers variable de type long int ",sizeof(long int));

   printf("\n %lu octets pour adresse vers variable de type float ",sizeof(float ));

   printf("\n %lu octets pour adresse vers variable de type double ",sizeof(double));

   printf("\n");

#endif

#ifdef EXO3
   int annee;

    // Demande à l'utilisateur d'entrer une année
    printf("Entrez une annee : ");
    scanf("%d", &annee);

    // Vérifie si l'année est bissextile
    if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) {
        printf("%d est une annee bissextile.", annee);
    } else {
        printf("%d n'est pas une annee bissextile.", annee);
    }
   printf("\n");

#endif

#ifdef EXO4




#endif

#ifdef EXO5

#endif

   return 0;
}

