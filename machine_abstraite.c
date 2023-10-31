//
// Created by HP on 11/12/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.c"

/* declaration des structures */

/* le Tenreg model */

typedef struct
{
    int matricule ;

    char nom [15];

    char prenom [15];

    char date_naissance [11];

    char sexe [10];

    char groupe_sanguin [4];

    char date_recrutement [11] ;

    char grade [50];

    char specialite [50];

    char dernier_diplome [50];

    char etablissement_univ [255];

    char wilaya_naissance [40];

}Tenreg;

//on definit la structure de bloc
typedef struct  {
    Tenreg tab [Maxbloc];
    int suiv;         //pour presicer le bloc suivant
    int nb;           // nombre d'element du bloc
}Tbloc;

/* entete fichier (premier bloc : entier , dernier bloc : entier ) */

typedef struct  {
    int tete ;
    int queue ;
} Tentete;

/* declaration de fichier vu comme Liste non ordonn�e qui contienne des enregistrments de taille fixe */

typedef struct  {
    FILE *f ;
    Tentete *entete;
} LObF;


/****************AFF_ENTETE*******************/
void Aff_Entete (LObF *fichier,int i,int val)//affecter � la caracteristique i la val
{
    switch(i)
    {
        case 1:fichier->entete->tete=val; break;
        case 2:fichier->entete->queue=val; break;
        default: printf("\n\t\t<<Le numero errone>>");
    }
}


/*******************EN_TETE*********************/
int Entete (LObF *fichier,int i )//retourner la cracterstique i dans val
{int val;
    switch(i)
    {
        case 1:val=fichier->entete->tete; break;
        case 2:val=fichier->entete->queue; break;
        default: printf("\n\t\t<<Le numero errone>>");
    }
    return val;
}


void ouvrir (LObF *fichier,char nom_fich[30],const char mode)//ouvrir un fichier de type LNOF en mode voulu
{
    fichier->entete = malloc(sizeof(Tentete));//allouer dynamiquement une zone en m�mo centrale pour l'en_tete
    if ((mode=='n')||(mode=='N'))//si le mode est nouveau ie:le fichier n'existe pas d�j� alors
    {   fichier->f=fopen(nom_fich,"wb+");//ouvrir un fichier en mode ecriture binaire
        Aff_Entete (fichier , 1 , 1);//initialiser les champs 1 ET 2 de l'en_tete � 1
        Aff_Entete (fichier , 2 , 1);
        fwrite(fichier->entete,sizeof(Tentete),1,fichier->f);//ecrire l'en_tete ds le fichier binaire
    }
    else
    {
        if ((mode=='a')||(mode=='A'))//si le mode est ancien ie:le fichier existe
        {
            fichier->f=fopen(nom_fich,"rb+");//ouvrir le fichier en mode lecture binaire
            if (fichier->f==NULL) printf("\n\t\t<<Le fichier n'existe pas...>>");//si erreur d'ouverture
            else//sinon
            fread(fichier->entete,sizeof(Tentete),1,fichier->f);//recuperer le contenu de l'entete ds la variable en_tete

        }
        else printf("le mode errone.");
    }
}

/************FERMITURE***************/
void fermer (LObF *fichier)//fermer un fichier
{   rewind(fichier->f);//on se positionne au debut de fichier
    fwrite(fichier->entete,sizeof(Tentete),1,fichier->f);//on enregistre les modifications effectu�es sur l'en_tete
    fclose(fichier->f);//on ferme le fichier
    free(fichier->entete);//liberer la zone en_tete reserv�e
}

/***************ECRITURE DIRECTE***********/
void EcrireDir(LObF *fichier,int i,Tbloc *buf)//ecriture directe du contenu de buf ds le fichier � la position i
{   rewind(fichier->f);
    fseek(fichier->f,sizeof(Tentete)+i*sizeof(Tbloc),SEEK_SET);//se positionner � la place exacte
    fwrite(buf,sizeof(Tbloc),1,fichier->f);//ecriture
}

/****************LECTURE DIRECTE*************/
void LireDir (LObF *fichier,int i,Tbloc *buf)//lecture directe du contenu de fichier � la position i ds le buf
{   rewind(fichier->f);
    fseek(fichier->f,sizeof(Tentete)+i*sizeof(Tbloc),SEEK_SET);//se positionner � la place exacte
    fread(buf,sizeof(Tbloc),1,fichier->f);//lecture
}


//*******************
