//
// Created by HP on 13/12/2022.
//
/*------------------------***********************--------------------**********************/
#define Maxbloc 1024 //la taille d'un bloc du fihcier principal
#define Maxsize 1024 //la taille d'un bloc du fichier d'index

typedef struct //declaration de la structure des elements de la table d'index
{
    int cle;
    int numblk;  // pour garder le numero de bloc
    int numenrg; // pour garder le numero de l'enregistrement

}Tindex;
/* l'enregistrement "Tindex"*/
typedef struct //la structure de la table d'index
{
    Tindex tab [888888];
    int nbl; //le nommbre d'element dans la table d'index

}index;

typedef struct // la declaration de bloc du fichier d'indexs
{
    Tindex tab [Maxsize];
    int nb;
}Tblocindex;

typedef struct  //la tete du fichier d'index
{
    int nbblc;
} Tindexentete;

typedef struct  //la structure d'un fichier TOF en MS (le fichier qui va contenir la table d'index en MS)
{
    FILE *f ;
    Tindexentete ientete;
} TOF;



void rech_index (int cle,Tindex *ind,int taille , int *trouv , int *ligne ) //rech d'un enregistrement a base de sa cle dans la table d'index (sil nexiste pas elle retourne la position ou il devait existait )
{
    int bi = 0 , bs = taille-1 ;
    int t = 0 ;

    while ((!t)  &&  (bi<=bs)) {
        *ligne = (bi + bs) / 2;
        if (ind[*ligne].cle == cle)
        {
            t = 1;
        }

        else {
            if (cle < ind[*ligne].cle)
                bs = *ligne - 1;
            else bi = *ligne + 1;
        }
    }
    *trouv = t;
    if (!t) *ligne = bi;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

//void rech_index (int cle,Tindex *ind,int taille , int *trouv , int *ligne ) //rech d'un enregistrement a base de sa cle dans la table d'index (sil nexiste pas elle retourne la position ou il devait existait )
void sauv_index (char *nomfich , Tindex *ind , int taille) //sauvegarder la table d'index dnas un ficheir en MS TOF
{
    int j = 0, i=0 , k=0;
    Tblocindex buf ;
    TOF ifichier;
    ifichier.f = fopen (nomfich , "wb+");
    if (ifichier.f != NULL)
    {
        fseek(ifichier.f, sizeof(Tindexentete), SEEK_SET); // sde positionner en premier bloc
        for (k = 0 ; k< taille ; k++)
        {

            if (j < 1024) //bloc n'est pas encore plein
            {
                buf.tab[j] = ind [k];
                j++;
            }
            else //bloc plein
            {
                buf.nb = j;
                fwrite(&buf, sizeof(Tblocindex), 1, ifichier.f); //ecriture du bloc dans le fichier
                i++;
                buf.tab[0] = ind[k];
                j = 1;
            }
        }
        // ecriture du dernier bloc
        buf.nb = j;
        fwrite(&buf, sizeof(Tblocindex), 1, ifichier.f); //ecriture du bloc dans le fichier
        // modification de l'entete
        ifichier.ientete.nbblc = i;
        rewind(ifichier.f); //se positionner
        // ecriture du l'entete dans le fichier
        fwrite(&(ifichier.ientete), sizeof(Tindexentete), 1, ifichier.f);
        fclose(ifichier.f);
    }
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/

//void rech_index (int cle,Tindex *ind,int taille , int *trouv , int *ligne ) //rech d'un enregistrement a base de sa cle dans la table d'index (sil nexiste pas elle retourne la position ou il devait existait )
void chargement_ind (char *nomfich ,Tindex *ind , int *taille) //charger la table d'index a partir d'un ficheir en MS
{
    int j = 0, i=0 , k=0;
    Tblocindex buf ;
    TOF ifichier;
    int cpt;
    ifichier.f = fopen (nomfich , "rb"); //ouverture en mode lecture binaire
    if (ifichier.f != NULL)
    {
        fread(&ifichier.ientete, sizeof(Tindexentete), 1, ifichier.f); //lecture d'entete
        cpt = 0 ;//initialiser le nombre d'element de la table d'index à 0
        for (i = 0 ; i<= ifichier.ientete.nbblc ; i++)
        {
            fread(&buf, sizeof(Tblocindex), 1, ifichier.f); //lecture du bloc ieme bloc dans buf
            for (j = 0; j < buf.nb; j++) //l'ecriture des enregistrements de bloc dans la table
            {
                ind[k] = buf.tab[j] ;
                k++;
                cpt++ ;
            }

        }
    }
    *taille = cpt;
    fclose(ifichier.f);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
//void rech_index (int cle,Tindex *ind,int taille , int *trouv , int *ligne ) //rech d'un enregistrement a base de sa cle dans la table d'index (sil nexiste pas elle retourne la position ou il devait existait )
void insert_ind ( int cle , Tindex *ind ,int taille , int place , int enr , int blc )
{
     int l = taille ;
     ind [l+1] = ind[l]; //pour garder le dernier enregistrement dans la table d'index
    while (l > place)
    {
        ind [l] = ind [l-1] ; //decalage
        l=l-1;

    }
    ind  [l].cle = cle ;
    ind[l].numblk = blc;
    ind[l].numenrg = enr;
     //fin de l'insersation */
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void supp_ind ( int cle,  Tindex *ind , int taille)
{
    int stop = 0 , trouv , i;
    rech_index (cle , ind ,taille, &trouv , &i);
    for (i ; i< taille-1 ; i++) //on decale
    {
        ind [i] = ind[i+1];
    }
}
