
//
// Created by HP on 14/12/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "affichage.c"




int main()
    {
    LObF fichier;
    char key [30];
    index *ind = malloc( sizeof (index));
    int i , n , trouv , i1 , mat;
    int nbrecriredir = 0 , nbrliredir = 0 , menu1 ;
    Tenreg e;
    Tbloc buffer;
    ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    acceuil ();
       debut: system("cls");
       textcolor (BLUE);
    printf ("\n\n");
printf("\t\t\t                                                                                                       ___         \n");
printf("\t\t\t                                                            .-.                   .-.                 (   )        \n");
printf("\t\t\t ___ .-. .-.    .--.  ___ .-.  ___  ___     .-..  ___ .-.  ( __) ___ .-.   .--.  ( __)  .-..    .---.  | |  .--.   \n");
printf("\t\t\t(   )   '   \  /    \(   )   \(   )(   )   /    \(   )   \ (''\")(   )   \ /    \ (''\") /    \  / .-, \ | | /    \  \n");
printf("\t\t\t |  .-.  .-. ;|  .-. ;|  .-. . | |  | |   ' .-,  ;| ' .-. ; | |  |  .-. .|  .-. ; | | ' .-,  ;(__) ; | | ||  .-. ; \n");
printf("\t\t\t | |  | |  | ||  | | || |  | | | |  | |   | |  . ||  / (___)| |  | |  | ||  |(___)| | | |  . |  .'`  | | ||  | | | \n");
printf("\t\t\t | |  | |  | ||  |/  || |  | | | |  | |   | |  | || |       | |  | |  | ||  |     | | | |  | | / .'| | | ||  |/  | \n");
printf("\t\t\t | |  | |  | ||  ' _.'| |  | | | |  | |   | |  | || |       | |  | |  | ||  | ___ | | | |  | || /  | | | ||  ' _.' \n");
printf("\t\t\t | |  | |  | ||  .'.-.| |  | | | |  ; '   | |  ' || |       | |  | |  | ||  '(   )| | | |  ' |; |  ; | | ||  .'.-. \n");
printf("\t\t\t | |  | |  | |'  `-' /| |  | | ' `-'  /   | `-'  '| |       | |  | |  | |'  `-' | | | | `-'  '' `-'  | | |'  `-' / \n");
printf("\t\t\t(___)(___)(___)`.__.'(___)(___) '.__.'    | \__.'(___)     (___)(___)(___)`.__,' (___)| \__.' `.__.'_.(___)`.__.'  \n");
printf("\t\t\t                                          | |                                         | |                          \n");
printf("\t\t\t                                         (___)                                       (___)                         \n");

printf ("\n\n\n\n\n");
textcolor (WHITE);
printf ("\t\tVEUILLEZ SVP FAIRE VOTRE CHOIX ");
textcolor (BLUE);
printf ("\"EN UTILISANT LES FLECHES DE VOTRE CLAVIER \"\n\n\n");
        menu1 = menu(15, "\t\t\t1> CONSTRUIRE LE FICHIER ENSEIGNANT-MESRS.bin", "\t\t\t2> AFFICHAGE DU FICHIER ENSEIGNANT-MESRS.bin",
                      "\t\t\t3> AJOUTER UN NOUVEAU ENSEIGNANT AU FICHIER ENSEIGNANT-MESRS.bin","\t\t\t4> SUPPPRIMER UN ENSEIGNANT DU FICHIER ENSEIGNANT-MESRS.bin",
                      "\t\t\t5> LA MODIFICATION DE L'ETABLISSEMENT D'UN ENSEIGNANT" , "\t\t\t6> SUPPRESSION D4UNE SPECIALITEE DU FICHIER ENSEIGNANT-MESRS.bin" ,
                      "\t\t\t7> AFFICHAGE DE TOUS LES ENSEIGNANTS EXERCANT DANS UN ETABLISSEMENT DONNE AYANT UNE ANCIENTEE DONNEE","\t\t\t8> CONSULTATION DE TOUS LES ENSEIGNANTS EXERCANT DANS UNE REGION DONNEE",
                      "\t\t\t9> CODER LE FICHIER ENSEIGNANT-MESRS.bin", "\t\t\t10> AFFICHER LE FICHIER CODE",
                      "\t\t\t11> DECODER LE FICHIER ENSEIGNANT-MESRS-CODED.bin","\t\t\t12> AFFICHIER LE FICHIER DECODEE",
                      "\t\t\t13> AFFICHAGE DE NOMBRE DE LIREDIR", "\t\t\t14> AFFICHAGE DE NOMBRE D'ECRIRE DIR" , "\t\t\t15> QITTER" );
        system("cls||clear");
        while (menu1!=15)
        {
            switch (menu1)
            {
                case 1 :
                    printf("   NOMBRE D'ENREGISTREMENT \n");
                    printf (" ->");
                    scanf("%d", &n);
                    chargementInitial("ENSEIGNANT-MESRS.bin", n, &fichier , ind , &nbrecriredir); //on vient d'ecraser l'ansien fichier et le recharger par nouvelles valeurs
                    sauv_index("ind" , &ind->tab , ind->nbl); //le chargement initial consiste � remplir la table d'index, et on a besoin de la sauvegarder
                    printf ("   VOTRE FICHIER EST BIEN CREE \n\n"   );
                    break;
                case 2 :
                    textcolor (WHITE);
                    affichage(&fichier, "ENSEIGNANT-MESRS.bin", &nbrliredir); //le fichier est deja cree
                    break;
                case 3: //insertion d'un nouvel enseignant
                    printf("donnez nous la matricule de l'enseignat : ");
                    scanf("%d" , &mat);
                    ajouter_ens (&fichier , mat , &nbrecriredir , &nbrliredir);
                    break;
                case 4:
                    printf("donner la matricule de l'enseignant que vous voulez supprime : ");
                    scanf("%d" , &mat);
                    supp_ens (&fichier , mat , &nbrecriredir , &nbrliredir); //en suppression on a deux lecture et deux ecriture
                    break;
                case 5:
                    mutation (&fichier,&nbrecriredir , &nbrliredir);
                    break;
                case 6:
                    supp_specialite(&fichier , &nbrecriredir , &nbrliredir);
                    break;
                case 7:
                    textcolor (WHITE);
                    affichage2(&fichier, "ENSEIGNANT-MESRS.bin"  , &nbrliredir);
                    break;
                case 8:
                    textcolor (WHITE);
                    affichage3(&fichier, "ENSEIGNANT-MESRS.bin" , &nbrliredir);
                    break;
                    case 9:
                         printf("Entrer la cle pour coder le fichier ENSEIGNANT-MESRS.bin : \n");
                         fflush(stdin);
                         gets(key);
                         fflush(stdin);
                         codage_fichier(&fichier ,"ENSEIGNANT-MESRS.bin", "ENSEIGNANT-MESRS-CODED.bin" , key);
                    break;
                case 10:
                        affichage(&fichier, "ENSEIGNANT-MESRS-CODED.bin", &nbrliredir);
                    break;
                case 11:
                         printf("Entrer la cle pour decoder le fichier ENSEIGNANT-MESRS-CODED.bin : \n");
                         fflush(stdin);
                         gets(key);
                         fflush(stdin
                                );
                         decodage_fichier(&fichier ,"ENSEIGNANT-MESRS-CODED.bin", "ENSEIGNANT-MESRS-DECODED.bin" , key);
                    break;
                   case 12:
                        affichage(&fichier, "ENSEIGNANT-MESRS-DECODED.bin", &nbrliredir);
                    break;
                   case 13:
                       printf ("\t\t\t LE NOMBRE DE LIRE DIR DEPUIS QUE LA COSOLE EST OUVERTE EST : %d\n" , nbrliredir);
                    break;
                   case 14:
                       printf ("\t\t\t LE NOMBRE D'ECRIREDIR DEPUIS QUE LA COSOLE EST OUVERTE EST : %d\n" , nbrecriredir);
                    break;
                default :
                    printf ("mauvais choix \n");
                    break ;

            }
            printf("Press Any Key to Continue\n");
            getch();
            goto debut;
        }
    }


