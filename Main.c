#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Exo4

#define MAX_LINE_LENGTH 256

int main() {

#ifdef Exo1 // Lecture puis Ecriture 
/*
Ecrire un programme qui permet d’écrire dans un fichier et de lire un fichier.
Le nom du fichier peut être passé en ligne de commande ou en fonctionnement.
La lecture du fichier sera suivie de l’affichage des lignes de ce même fichier dans la console.
Afficher aussi le nombre de ligne du fichier.
Ré-ouvrir le fichier en mode append ‘a’.
Ecrire une phrase.
Contrôler le fichier en question. La phrase est-elle présente ? 
*/

   FILE* file;
   char filename[MAX_LINE_LENGTH];
   char line[MAX_LINE_LENGTH];
   char search_phrase[MAX_LINE_LENGTH];
   int line_count = 0;
   int found = 0;

   // Obtention du nom de fichier en cours d'exécution
   printf("Veuillez saisir le nom de fichier : ");
   fgets(filename, MAX_LINE_LENGTH, stdin);
   filename[strcspn(filename, "\n")] = '\0';

   // Écriture dans le fichier
   file = fopen(filename, "w");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier en écriture\n");
      exit(1);
   }
   fprintf(file, "Bonjour\n");
   fprintf(file, "Comment ça va ?\n");
   fprintf(file, "Au revoir\n");
   fclose(file);

   // Lecture du fichier et affichage des lignes dans la console
   file = fopen(filename, "r");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier en lecture\n");
      exit(1);
   }
   while (fgets(line, MAX_LINE_LENGTH, file)) {
      printf("%s", line);
      line_count++;
   }
   fclose(file);
   printf("Nombre de lignes : %d\n", line_count);

   // Ré-ouverture du fichier en mode append et écriture d'une phrase
   file = fopen(filename, "a");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier en mode append\n");
      exit(1);
   }
   fprintf(file, "À bientôt\n");
   fclose(file);

   // Recherche de la phrase dans le fichier
   printf("Veuillez saisir une phrase à rechercher dans le fichier : ");
   fgets(search_phrase, MAX_LINE_LENGTH, stdin);
   search_phrase[strcspn(search_phrase, "\n")] = '\0';

   file = fopen(filename, "r");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier en lecture\n");
      exit(1);
   }
   while (fgets(line, MAX_LINE_LENGTH, file)) {
      if (strstr(line, search_phrase) != NULL) {
         found = 1;
         break;
      }
   }
   fclose(file);

   if (found) {
      printf("La phrase \"%s\" a été trouvée dans le fichier\n", search_phrase);
   } else {
      printf("La phrase \"%s\" n'a pas été trouvée dans le fichier\n", search_phrase);
   }

#endif

#ifdef Exo2 // Modification de fichie
/*
Ecrire un programme qui change le contenu d’un fichier textuel en mettant tout en majuscule. Lire et
afficher le fichier avant et après traitement.
Vous utiliserez int toupper(int c) de ctype.h ou une fonction qui soustrait 32 pour un caractère minuscule
ASCII donné.
*/
   FILE* file;
   char filename[MAX_LINE_LENGTH];
   char line[MAX_LINE_LENGTH];
   int c;

   // Obtention du nom de fichier en cours d'exécution
   printf("Veuillez saisir le nom de fichier : ");
   fgets(filename, MAX_LINE_LENGTH, stdin);
   filename[strcspn(filename, "\n")] = '\0';

   // Ouverture du fichier en lecture/écriture
   file = fopen(filename, "r+");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier\n");
      return 1;
   }

   // Lecture du fichier, transformation en majuscules et écriture dans le même fichier
   while ((c = fgetc(file)) != EOF) {
      fseek(file, -1, SEEK_CUR);  // Retour au caractère lu pour l'écraser
      fputc(toupper(c), file);
   }

   // Fermeture du fichier
   fclose(file);

   // Affichage du contenu du fichier après traitement
   printf("\nContenu du fichier après traitement :\n");
   file = fopen(filename, "r");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier\n");
      return 1;
   }
   while (fgets(line, MAX_LINE_LENGTH, file)) {
      printf("%s", line);
   }
   fclose(file);


#endif

#ifdef Exo3 // Ouverture en lecture/écriture 
/*
Ecrire un programme qui crée un nouveau fichier en lecture/écriture.
Ecrire une phrase.
Afficher la position courante (ftell).
Faire un retour à la position initiale.
Afficher la position courante (ftell). Afficher le fichier.
Ecrire une phrase. Va-t-elle écraser la phrase précédente ?

Oui la phrase précédente est écrasé
*/

   FILE* file;
   char filename[] = "test.txt";
   char text1[] = "Première phrase\n";
   char text2[] = "Deuxième phrase\n";
   long initial_position;

   // Création du fichier en lecture/écriture
   file = fopen(filename, "w+");
   if (file == NULL) {
      printf("Erreur : Impossible de créer le fichier\n");
      exit(1);
   }

   // Ecriture de la première phrase dans le fichier
   fputs(text1, file);

   // Affichage de la position courante
   printf("Position courante : %ld\n", ftell(file));

   // Déplacement de la position courante et affichage de la nouvelle position courante
   fseek(file, 0, SEEK_SET);
   printf("Nouvelle position courante : %ld\n", ftell(file));

   // Affichage du contenu du fichier
   printf("Contenu du fichier :\n");
   char c;
   while ((c = getc(file)) != EOF) {
      putchar(c);
   }

   // Retour à la position initiale et écriture de la deuxième phrase dans le fichier
   fseek(file, 0, SEEK_SET);
   fputs(text2, file);

   // Affichage du contenu du fichier
   printf("\nNouveau contenu du fichier :\n");
   fseek(file, 0, SEEK_SET);
   while ((c = getc(file)) != EOF) {
      putchar(c);
   }

   // Fermeture du fichier
   fclose(file);


#endif

#ifdef Exo4 //Annuaire (utilisation de fprintf et fscanf) 
/*
Créez un fichier texte qui contient 4 descriptions de personnes organisées selon les champs suivants :
- Nom
- Prenom
- Age
- email
Ecrire un programme qui lit ce fichier et affiche les différentes personnes.
Ecrire ensuite le programme qui permet d’ajouter une personne à la fin de ce fichier.
Utiliser maintenant une structure personne et modifier le programme initial 
*/
struct personne {
   char nom[MAX_LINE_LENGTH];
   char prenom[MAX_LINE_LENGTH];
   int age;
   char email[MAX_LINE_LENGTH];
};


   FILE* file;
   char line[MAX_LINE_LENGTH];
   char filename[MAX_LINE_LENGTH];
   struct personne p;

   // Obtention du nom de fichier en cours d'exécution
   printf("Veuillez saisir le nom de fichier : ");
   fgets(filename, MAX_LINE_LENGTH, stdin);
   filename[strlen(filename) - 1] = '\0';  // Retrait du caractère de fin de ligne

   // Ouverture du fichier en lecture seule
   file = fopen(filename, "r");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier\n");
      return 1;
   }

   // Lecture du fichier et affichage des différentes personnes
   printf("\nListe des personnes :\n");
   while (fgets(p.nom, MAX_LINE_LENGTH, file)) {
      fgets(p.prenom, MAX_LINE_LENGTH, file);
      fgets(line, MAX_LINE_LENGTH, file);
      p.age = atoi(line);
      fgets(p.email, MAX_LINE_LENGTH, file);

      printf("Nom : %s", p.nom);
      printf("Prenom : %s", p.prenom);
      printf("Age : %d\n", p.age);
      printf("Email : %s", p.email);
      printf("\n");
   }

   // Fermeture du fichier
   fclose(file);

   // Ajout d'une personne à la fin du fichier
   file = fopen(filename, "a");
   if (file == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier\n");
      return 1;
   }

   printf("Veuillez saisir les informations de la nouvelle personne :\n");
   printf("Nom : ");
   fgets(p.nom, MAX_LINE_LENGTH, stdin);
   printf("Prenom : ");
   fgets(p.prenom, MAX_LINE_LENGTH, stdin);
   printf("Age : ");
   fgets(line, MAX_LINE_LENGTH, stdin);
   p.age = atoi(line);
   printf("Email : ");
   fgets(p.email, MAX_LINE_LENGTH, stdin);

   fprintf(file, "%s", p.nom);
   fprintf(file, "%s", p.prenom);
   fprintf(file, "%d\n", p.age);
   fprintf(file, "%s", p.email);

   // Fermeture du fichier
   fclose(file);

#endif

#ifdef Exo5 //Fichier binaire (utilisation de fwrite et fread) 
/*
Créez un fichier qui servira à stocker les mêmes informations précédentes mais en mode binaire. Lire
d’abord le fichier texte précédent, puis stocker dans un fichier binaire. Faire la lecture de ce fichier binaire
et vérifier que les valeurs lues sont correctes.
Vous pouvez commencer par sauvegarder une variable de type int dans un fichier puis la récupérer depuis
ce fichier de sauvegarde. Essayez ensuite en utilisant une structure personne. Editer le fichier binaire
produit avec un éditeur hexadécimal. 
*/


#endif

#ifdef Exo6 //Fichier Texte 
/*
Implémentez une fonction qui créé un fichier texte (.txt) dans le répertoire de l'exe et ecrit un
contenu.
Le nom du fichier et son contenu sera passé en paramètre de cette fonction.
- Implémentez une fonction qui Lit un fichier texte (.txt). Le nom du fichier à lire sera passé en
paramètre. Le fichier sera localisé dans le répertoire de l'exe.
Chacune des fonctions ferme le fichier après son utilisation. 
*/


#endif

#ifdef Exo7 // Fichier "Banque.txt"
/*
Ecrivez un programme qui permet la gestion d'un fichier "Banque.txt".
Ce fichier contiendra les informations de 2 clients de la banque. Chaque client fera l'objet d'un
enregistrement dans le fichier. Le fichier sera de type texte avec un enregistrement par ligne et un
séparateur de champ le caractère ;
Un enregistrement sera composé de :
Nom;Solde;NombreOpérations
On représentera les informations d'un client dans une structure ST_Compte :
struct ST_Compte {
char NomClient[32];
int Solde;
int NbreOperations;
};
- Implémentez une fonction qui permet de saisir les informations d'un Compte de client.
Prototype : SaisieCompte(struct *ST_Compte)
- Implémentez une fonction qui permet d'afficher les informations d'un Compte de client.
Prototype : AfficherCompte(struct *ST_Compte)
- Implémentez une fonction qui permet d'ajouter les informations d'un Compte dans le fichier
Prototype : AjoutCompte(char *, struct *ST_Compte)
le char * permettra de faire référence au nom du fichier "banque.txt"
- Implémentez une fonction qui permet de lire le contenu du fichier et stocke les informations lues
dans un tableau de St_Compte passé en paramètre de la fonction
Prototype : LireFichierComptes(char *, ….)
le char * permettra de faire référence au nom du fichier "banque.txt"
- Implémentez une fonction qui permet de modifier les informations d'un Compte dans le fichier
Prototype : ModifieCompte(char *, struct *ST_Compte,int)
le char * permettra de faire référence au nom du fichier "banque.txt"
Le int permet de savoir quel est l'enregistrement à mettre à jour. ( 1 ou 2)
- Implémentez une fonction qui permet de lire les informations d'un Compte dans le fichier
Prototype : LectureCompte(char *, struct *ST_Compte, int)
le char * permettra de faire référence au nom du fichier "banque.txt"
struct *ST_Compte permettra de stocker les informations du compte lu
Le int permet de savoir quel est l'enregistrement à lire. ( 1 ou 2)
Chacune des fonctions ouvre ferme le fichier au besoin. 
*/



#endif
   return 0;
   
}
