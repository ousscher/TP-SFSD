#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "bib.c"
#include "conio.c"
#include <dirent.h>


#define selected_color 0
#define not_selected_color 15
#define not_selected_background 0
int couleurPrincipale = 10;


void acceuil()
{
    int i;
    printf("\n\n\n\n");
    textcolor(BLUE);
    char msg1 [264] = "\t\t\t -- ## ---------------------------------------------------------------------------------------------------------------- ## --\n";
    char msg2 [264] = "\t\t\t  ########################################################################################################################## \n";
    char msg3 [264] = "\t\t\t    ##                                                                                                                  ## \n";
    char msg4 [20] = "\t\t\t    ## ";
    for (int i=0;i<strlen(msg1);i++)
    {

                printf("%c",msg1[i]);
                usleep(1000);
    }


    for (int i=0;i<strlen(msg2);i++)
    {

                printf("%c",msg2[i]);
                usleep(1000);
    }


     for (int i=0;i<strlen(msg1);i++)
    {

                printf("%c",msg1[i]);
                usleep(1000);
    }

     for (int i=0;i<strlen(msg3);i++)
    {

                printf("%c",msg3[i]);
                usleep(600);
    }

     for (int i=0;i<strlen(msg3);i++)
    {

                printf("%c",msg3[i]);
                usleep(600);
    }



    printf ("%s" , msg4);
    textcolor(WHITE);
    char msg5 [255] = "          $$$$  $$$$$  $$$$$                                 ECOLE NATIONALE SUPERIEUR D'INFORMATIQUE           ";
    //printf("          $$$$  $$$$$  $$$$$                                                                                    ");
    for (int i=0;i<strlen(msg5);i++)
    {

                printf("%c",msg5[i]);
                usleep(1000);
    }
    textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg4);
    textcolor(WHITE);
    printf("          $     $        $                                                                                      ");
    textcolor(BLUE);
    printf(" ## \n");
     printf("%s" , msg4);
    textcolor(WHITE);
    char msg6 [255] = "          $$$$  $$$$$    $                                         2EME ANNE CYCLE PREPARATOIRE                 ";
    for (int i=0;i<strlen(msg6);i++)
    {

                printf("%c",msg6[i]);
                usleep(1000);
    }
   textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg4);
    textcolor(WHITE);
    printf("          $         $    $                                                                                      ");
    textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg4);
    textcolor(WHITE);
    char msg7 [255] = "          $$$$  $$$$$  $$$$$                                                MODULE SFSD                         ";
    for (int i=0;i<strlen(msg7);i++)
    {

                printf("%c",msg7[i]);
                usleep(1000);
    }
    textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg4);
    textcolor(WHITE);
     char msg8 [255] = "                                   TP : GESTION DE STRUCTURE DE FICHIER SIMPLE                                  ";
     for (int i=0;i<strlen(msg8);i++)
    {

                printf("%c",msg8[i]);
                usleep(1000);
    }
    textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg4);
    textcolor(WHITE);
    char msg9 [255] = "        Realise par :     CHERGUELAINE OUSSAMA    MERABAT RIAD          G02                                     ";
     for (int i=0;i<strlen(msg9);i++)
    {

                printf("%c",msg9[i]);
                usleep(1000);
    }
    textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg4);
    textcolor(WHITE);
    printf("        Encadre par :");
    textcolor(WHITE);
    printf(" DR. Kermi Adel                                                                            ");
    textcolor(BLUE);
    printf(" ## \n");
    printf("%s" , msg3);
    printf("%s" , msg3);

    textcolor(BLUE);
    printf("%s" , msg3);
    printf("%s" , msg3);
    printf("%s" , msg4);
    textcolor(WHITE);
    char msg10 [255] = "                              APPUYER SUR LA TOUCHE ENTREE POUR CONTINUER                                       ";
     for (int i=0;i<strlen(msg10);i++)
    {

                printf("%c",msg10[i]);
                usleep(1000);
    }
    textcolor(BLUE);
    printf(" ## \n");
     for (int i=0;i<strlen(msg1);i++)
    {

                printf("%c",msg1[i]);
                usleep(1000);
    }


    for (int i=0;i<strlen(msg2);i++)
    {

                printf("%c",msg2[i]);
                usleep(1000);
    }


     for (int i=0;i<strlen(msg1);i++)
    {

                printf("%c",msg1[i]);
                usleep(1000);
    }
    gotoxy(1, 1);
    getch();
}



int menu(int max, ...)
{
    if (max > 0)
    {

        int choi, a, i, b, d, y;
        char p[50];
        char **choix = NULL;
        choix = malloc(max * sizeof(p));
        va_list marker;
        va_start(marker, max); /* Initialize variable arguments. */
        for (i = 0; i < max; i++)
        {
            choix[i] = va_arg(marker, char *);
        }
        va_end(marker);
        d = wherey();
        y = d;
        textcolor(WHITE);
        textbackground(BLUE);
        printf("%s\n", choix[0]);
        textbackground(not_selected_background);
        textcolor(not_selected_color);
        for (i = 1; i < max; i++)
        {
            printf("%s\n", choix[i]);
        }
    eticette:
        while ((a = getch()) == 224)
        {
            b = getch();
            if ((b == 80) && (y < d + max - 1))
            {
                gotoxy(1, y);
                textcolor(not_selected_color);
                i = y - d;
                textbackground(not_selected_background);
                printf("%s", choix[i]);
                y++;
                textcolor(WHITE);
                gotoxy(1, y);
                textbackground(BLUE);
                printf("%s", choix[i + 1]);
            }
            if (b == 72 && y > d)
            {
                gotoxy(1, y);
                textcolor(not_selected_color);
                i = y - d;
                textbackground(not_selected_background);
                printf("%s", choix[i]);
                y--;
                textcolor(WHITE);
                gotoxy(1, y);
                textbackground(BLUE);
                printf("%s", choix[i - 1]);
            }
        }
        if (a != 13)
            goto eticette;

        choi = y - d;
        textbackground(not_selected_background);
        textcolor(not_selected_color);
        gotoxy(1, d + max);
        return choi + 1;
    }
    else
        return -1;
}

int menuTab(int max, char **choix)
{

    if (max > 0)
    {

        int choi, a, i, b, d, y;

        d = wherey();
        y = d;
        textcolor(couleurPrincipale);
        printf("\t\t\t[ 1]- %s\n", choix[0]);
        textbackground(not_selected_background);
        textcolor(not_selected_color);
        for (i = 1; i < max; i++)
        {
            printf("\t\t\t[%2d]- %s\n", i + 1, choix[i]);
        }
    eticette:
        while ((a = getch()) == 224)
        {
            b = getch();
            if (b == 80 && y < d + max - 1)
            {
                gotoxy(1, y);
                textcolor(not_selected_color);
                i = y - d;
                textbackground(not_selected_background);
                printf("\t\t\t[%2d]- %s\n", i + 1, choix[i]);
                y++;
                textcolor(selected_color);
                gotoxy(1, y);
                textbackground(couleurPrincipale);
                printf("\t\t\t[%2d]- %s\n", i + 2, choix[i + 1]);
            }
            if (b == 72 && y > d)
            {
                gotoxy(1, y);
                textcolor(not_selected_color);
                i = y - d;
                textbackground(not_selected_background);
                printf("\t\t\t[%2d]- %s\n", i + 1, choix[i]);
                y--;
                textcolor(selected_color);
                gotoxy(1, y);
                textbackground(couleurPrincipale);
                printf("\t\t\t[%2d]- %s\n", i, choix[i - 1]);
            }
        }
        if (a != 13)
            goto eticette;

        choi = y - d;
        textbackground(not_selected_background);
        textcolor(not_selected_color);
        gotoxy(1, d + max);
        return choi + 1;
    }
    else
        return -1;
}



void home()
{

    printf("\n\n\n\n");
    textcolor(YELLOW);
    printf("\t\t\t\t __| |________________________________________________________________________________________________________________| |__\n\t\t\t\t");
    printf("(__   ________________________________________________________________________________________________________________   __)\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |");
    textcolor(WHITE);
    printf("          ___  ___ _                                                                                            ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |");
    textcolor(WHITE);
    printf("         / _ \\/ __| |                                                                                           ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |");
    textcolor(WHITE);
    printf("        |  __/\\__ \\ |                 Ecole Nationale Superieure d'informatique   (ex INI)                      ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |");
    textcolor(WHITE);
    printf("         \\___||___/_|                 Cycle preparatoire integre (2CPI)                                         ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |");
    textcolor(couleurPrincipale);
    printf("        Programe :");
    textcolor(WHITE);
    printf("  Base de donnees de l'armmee national des six regions militaire .                            ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |");
    textcolor(couleurPrincipale);
    printf("        Realise par :");
    textcolor(WHITE);
    printf("     BENBETKA Marouane    TIHAMI Hicham                                                    ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |");
    textcolor(WHITE);
    printf("                                 section C Groupe 07                                                            ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |");
    textcolor(couleurPrincipale);
    printf("        Encadre par :");
    textcolor(WHITE);
    printf(" Mr. Kermi Adel                                                                            ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |");
    textcolor(couleurPrincipale);
    printf("        Version :  ");
    textcolor(WHITE);
    printf("15-01-2022                                                                                   ");

    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    printf("   | |");
    textcolor(WHITE);
    printf("                              APPUYER SUR LA TOUCHE ENTREE POUR CONTINUER                                       ");
    textcolor(YELLOW);
    printf("| |\n\t\t\t\t");
    printf(" __| |_______________________________________________________________________________________________________________ | |__\n\t\t\t\t");
    printf("(__   ________________________________________________________________________________________________________________   __)\n\t\t\t\t");
    printf("   | |                                                                                                                | |\n\t\t\t\t");
    gotoxy(1, 1);
    getch();
}


void retour()
{
    textcolor(couleurPrincipale);
    printf("\n\n\t\t _____________________________________________________\n");
    printf("\t\t|                                                     |\n");
    printf("\t\t|   ");
    textcolor(YELLOW);
    printf("Appuyer ENTRER pour retourner au MENU PRINCIPAL");
    textcolor(couleurPrincipale);
    printf("   |\n");
    printf("\t\t|_____________________________________________________|\n");

    textcolor(WHITE);
}
