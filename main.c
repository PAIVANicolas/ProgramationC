#include <stdio.h>   
#define EXO1

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

   char c;

    // Demande à l'utilisateur d'entrer un caractère
    printf("Entrez un caractere : ");
    scanf("%c", &c);

    // Affiche le code ASCII du caractère
    printf("Le code ASCII de %c est %d.\n", c, c);

#endif

#ifdef EXO5

   int x;

   x = - 3 + 4 * 5 - 6 ; printf ("%d\n",x);
   x = 3 + 4 % 5 - 6 ; printf ("%d\n",x);
   x = - 3 + 4 % -6 / 5 ; printf ("%d\n",x);
   x = (7 + 6 ) % 5 / 2 ; printf ("%d\n",x); 
#endif

#ifdef EXO6
#define PRINTX printf("%d\n",x)

   int x = 2, y, z ;

   x *= 3 + 2 ; PRINTX;
   x *= y = z = 4 ;
   x = y == z ; PRINTX;
   x == (y = z) ; PRINTX;

#endif

#ifdef EXO7
#define PRINT(int) printf("%d\n", int) 

   int x, y, z;

   x = 2 ; y = 1; z = 0;
   x = x && y || z;
   PRINT(x);
   PRINT(x || ! y && z);
   x = y = 1;
   z = x ++ - 1; PRINT(x) ; PRINT(z);
   z += - x ++ + ++ y; PRINT(x) ; PRINT(z);
   z = x / ++ x; PRINT(z);

#endif

#ifdef EXO8
#define PRINT(int) printf(#int "= %d\n", int) 

   int x, y, z;

   x = 03 ; y = 02 ; z = 01 ;
   PRINT( x | y & z);
   PRINT( x | y & ~z);
   PRINT( x ^ y & ~z);
   PRINT( x & y && z);
   x= 1 ; y= -1;
   PRINT( !x | x);
   PRINT( ~x | x);
   PRINT( x ^ x);
   x <<= 3 ; PRINT(x);
   y <<= 3 ; PRINT(y);
   y >>= 3 ; PRINT(y); 
#endif

#ifdef EXO9
#define PRINT(int) printf(#int "= %d\n", int)

   int x=1, y=1, z=1;

   x += y += z;
   PRINT (x < y ? y : x);
   PRINT(x < y ? x ++ : y ++) ;
   PRINT(x) ; PRINT(y);
   PRINT(z += x < y ? x ++ : y ++);
   PRINT(y) ; PRINT(z);
   x=3 ; y=z=4;
   PRINT( (z>= y >=x) ? 1 : 0);
   PRINT( z >= y && y >= x);

#endif

   return 0;
}

