#include <stdio.h>
#include <string.h>

//define Tableau, pour les exos 1,2,3
//#define Tableau

#define Exo_15

int main() {

#ifdef Tableau
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

#endif

#ifdef Exo_1
/*
   a) Ecrire un programme qui lit la dimension N d'un tableau T du type int (dimension maximale: 50
composantes), remplit le tableau par des valeurs entrées au clavier et affiche le tableau.

   b) Effacer ensuite toutes les occurrences de la valeur 0 dans le tableau T et "tasser" les éléments
restants. Afficher le tableau résultant, puis afficher ensuite la taille totale réservée pour le tableau
en octets puis la taille de la partie occupée du tableau.
*/
 

// Suppression des 0 et tassage des éléments
int taille = tailleTableau;
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

#ifdef Exo_2
/*
Réutilisez le tableau précédant (2.1 a) dans lequel vous rangerez les éléments du tableau T dans l'ordre
inverse de saisie sans utiliser de tableau d'aide. Afficher le tableau résultant. 
*/
// Affichage du tableau résultant
printf("Voici votre tableau avec les valeurs dans le sens inverse : ");
for (int i = tailleTableau - 1; i >= 0; i--) {
   printf("%d ", tableau[i]);
}
printf("\n");


#endif


#ifdef Exo_3
/*
Rechercher dans un tableau d'entiers A une valeur VAL entrée au clavier.
(Vous pouvez réutiliser le tableau (2.1 a) )
Afficher la position de VAL si elle se trouve dans le tableau, sinon afficher un message correspondant.
La valeur POS qui est utilisée pour mémoriser la position de la valeur dans le tableau, aura la valeur -1 aussi
longtemps que VAL n'a pas été trouvée.
*/ 

// Affichage du tableau résultant
printf("Voici votre tableau : ");
for (int i = 0 ; i < tailleTableau; i++) {
   printf("%d ", tableau[i]);
}
printf("\n");

int valeurRechercher;

printf("Quelle valeur voulez-vous rechercher ? \n");
scanf("%d", &valeurRechercher);

for(int i = 0; i < tailleTableau; i++){
   if(valeurRechercher == tableau[i]){
      printf("Voici la possition de la valeur recherché : %d", i); 
   }
};

printf("\n");


#endif


#ifdef Exo_4
/*
Ecrire un programme qui transfère un tableau M à deux dimensions L et C (dimensions maximales: 10
lignes et 10 colonnes) dans un tableau V à une dimension L*C. 
*/

#include <stdio.h>

#define MAX_LIGNES 10
#define MAX_COLONNES 10


int M[MAX_LIGNES][MAX_COLONNES];
int V[MAX_LIGNES * MAX_COLONNES];
int L, C;

printf("Entrez le nombre de lignes du tableau M (maximum %d) : ", MAX_LIGNES);
scanf("%d", &L);

printf("Entrez le nombre de colonnes du tableau M (maximum %d) : ", MAX_COLONNES);
scanf("%d", &C);

if (L > MAX_LIGNES || C > MAX_COLONNES) {
   printf("Erreur : dimensions trop grandes.\n");
   return 1;
}

// Remplissage du tableau M
for (int i = 0; i < L; i++) {
   for (int j = 0; j < C; j++) {
      printf("Entrez l'élément M[%d][%d] : ", i, j);
      scanf("%d", &M[i][j]);
   }
}

// Transfert des éléments de M à V
int k = 0;
for (int i = 0; i < L; i++) {
   for (int j = 0; j < C; j++) {
      V[k++] = M[i][j];
   }
}

// Affichage du tableau V
printf("Tableau V à une dimension (taille %d) :\n", L*C);
for (int i = 0; i < L*C; i++) {
   printf("%d ", V[i]);
}
printf("\n");

#endif


#ifdef Exo_5
/*
Ecrire un programme qui construit et affiche une matrice carrée unitaire U de dimension N. Une matrice
unitaire est une matrice, telle que: Uij = 1 si i=j et Uij = 0 sinon. 
*/

int N;

printf("Entrez la dimension N de la matrice carrée unitaire : ");
scanf("%d", &N);

// Construire la matrice carrée unitaire
int U[N][N];
for (int i = 0; i < N; i++) {
   for (int j = 0; j < N; j++) {
      if (i == j) {
            U[i][j] = 1;
      } else {
            U[i][j] = 0;
      }
   }
}

// Afficher la matrice carrée unitaire
printf("Matrice carrée unitaire U de dimension %d :\n", N);
for (int i = 0; i < N; i++) {
   for (int j = 0; j < N; j++) {
      printf("%d ", U[i][j]);
   }
   printf("\n");
}

#endif

#ifdef Exo_6
/*
Ecrire un programme qui effectue la transposition tA d'une matrice A de dimensions N et M en une matrice
de dimensions M et N.
a) La matrice transposée sera mémorisée dans une deuxième matrice B qui sera ensuite affichée.
b) La matrice A sera transposée par permutation des éléments.
*/
int N, M;
int matriceA [N][M];

printf("Taille de la dimensions N de la mattrice A :");
scanf("%d ", &N);

printf("Taille de la dimensions M de la mattrice A :");
scanf("%d ", &M);



#endif

#ifdef Exo_7

#endif

#ifdef Exo_8


#endif


#ifdef Exo_9


#endif

#ifdef Exo_10


#endif


#ifdef Exo_11


#endif


#ifdef Exo_12


#endif


#ifdef Exo_13


#endif


#ifdef Exo_14


#endif


#ifdef Exo_15
/*
Le Pendu
Ecrire un programme qui implémente le jeu du pendu. Utilisez les éléments suivants pour créer le
programme.
*/

char mot_secret[100];
char mot_decouvert[100];
int nb_essais = 10;
int longueur_mot;
int gagne = 0;

printf("Joueur 1, entrez un mot secret : ");
scanf("%s", mot_secret);

longueur_mot = strlen(mot_secret);
for (int i = 0; i < longueur_mot; i++) {
   mot_decouvert[i] = '_';
}
mot_decouvert[longueur_mot] = '\0';

while (nb_essais > 0 && gagne == 0) {
   printf("\nIl vous reste %d essais\n", nb_essais);
   printf("Mot à deviner : %s\n", mot_decouvert);
   printf("Proposez une lettre : ");
   char lettre;
   scanf(" %c", &lettre);

   int lettre_trouvee = 0;
   for (int i = 0; i < longueur_mot; i++) {
   if (mot_secret[i] == lettre) {
      mot_decouvert[i] = lettre;
      lettre_trouvee = 1;
   }
   }

   if (lettre_trouvee) {
   printf("Bravo ! La lettre %c est dans le mot.\n", lettre);
   } else {
   printf("Dommage... La lettre %c n'est pas dans le mot.\n", lettre);
   nb_essais--;
   }

   if (strcmp(mot_secret, mot_decouvert) == 0) {
   gagne = 1;
   }
}

if (gagne) {
   printf("Bravo, vous avez gagné ! Le mot était bien %s.\n", mot_secret);
} else {
   printf("Perdu... Le mot était %s.\n", mot_secret);
}





#endif



return 0;

}