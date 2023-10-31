//
// Created by HP on 14/12/2022.
//
//
// Created by HP on 11/12/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine_abstraite.c"
#include <windows.h>
//#include "index.c"


#define Maxbloc 1024


/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------construction du modules demand�s-----------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
int Color(int couleurDuTexte, int couleurDeFond)
    {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
    }


void Maj_string (char str[255])
{
    int i;
    for (i = 0; str[i]!='\0'; i++)
     {
     /* si les caractères sont en minuscules, convertissez-les
        en majuscules en soustrayant 32 de leur valeur ASCII. */
      if(str[i] >= 'a' && str[i] <= 'z')
        {
         str[i] = str[i] -32;
        }
    }
}


void Vider_string (char string[255])  // EN UTILISANT LES CHAINE DANS LES BOUCLES ON A BESOIN DE LES VIDER A CHAQUE FOIS, DONC CETTE PROCEDURE JOUE CE ROLE
{

    int i ;

    for(i=0 ;i<=255 ;i++)
    {
        string[i] ='\0';
    }

}




int generate_matricule () //son role est de generer une matricule (entier) entre 111111 et 999999
{
    // le principe est de faire une generation de 3 nombres en 3 positions chaquns, puis les concatener (car il est impossible de generer un nombre alea avec 6 positions)
    return ((rand () % (999 + 1 - 111) + 111)*1000 +(rand () % (999 + 1 - 111) + 111));
    //return (rand () % (2 + 1 - 1) + 1);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/


char *generate_nom ()//son role est de generer le nom de l'enseignant d'une fa�con aleatoire (le nom est entre 4 et 15 caracteres)
{

    char caract; int i ;
    int nbc = rand ()%(11) + 4; //on genere le nombre de caractere
    char *nom = malloc((nbc+1) * sizeof(char)); // alocation dynamique du nom
    for (i=0 ; i<nbc ; i++)
    {
        caract = 65 +rand () %(26 ); //pour obtenir un caractere en majuscule entre 'A' et 'Z' (code ASCII)
        nom [i] = caract;
    }
    nom [nbc] = '\0'; //fin de la chaine de caracteres
    return nom ;
}



/*-----------------------------------------------------------------------------------------------------------------------------------------*/


char *generate_prenom ()//son role est de generer le prenom de l'enseignant d'une fa�con aleatoire (le nom est entre 4 et 15 caracteres)
{

    char caract; int i ;
    int nbc = rand ()%(11) + 4; //on genere le nombre de caractere
    char *nom = malloc((nbc+1 ) * sizeof(char)); // alocation dynamique du nom
    for (i=0 ; i<nbc ; i++)
    {
        caract = 65 +rand () %(26 ); //pour obtenir un caractere en majuscule entre 'A' et 'Z' (code ASCII)
        nom [i] = caract;
    }
    nom [nbc] = '\0'; //fin de la chaine de caracteres
    return nom ;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------module de date de naissance----------------------------------------------------*/

int an_bitextile (int an) //une fonction qui retourne un si l'an est bitextil
{
    if ((an %4)==0)
    {
        if ((an % 100) != 0) //si l'ann�e est un multiple de 4 et non pas de 100 donc elle est bitextile
            return 1;
        else
        {
            if ((an % 400) == 0)//si l'an est un mutiple de 100 et au meme temps de 400 onc il est bitextile
                return 1;
            else return 0;
        }
    }
    else return 0;
}


char *generate_datenaissance ()
{

      int jour ,m1, a ,n ,m2 , mois ,j ,r , an;
    char *date = malloc((11) * sizeof(char));
    date[6]='1';
    date[7]='9';
    a = rand()%(4)+5;
    date[8]=a+'0';
    if (a == 5)
    {
        n = rand()%(6)+3;
        date[9]=n+'0';
    }
     if (a==6 || a==7 || a==8)
    {
        n = rand()%(9);
        date[9]=n+'0';
    }
    else if (a == 9)
    {
        n =rand()%(8);
        date[9]=n+'0';
    }
    m1 = rand ()%(1);
    date[3]=m1+'0';
    if (m1 == 0)
    {
        m2 = rand()%(9)+1;
        date[4]=m2+'0';
    }
    else if(m1 == 1)
    {
        m2 =rand()%(2);
        date[4]=m2+'0';
    }
    date[5]='/';
    mois = m1*10 + m2;
    an =1900+a*10+n;
    int jrMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((mois != 2) || ((mois == 2 )&& (an_bitextile (an)==0)))
    {
        jour = rand ()%(28) + 1;
    }
    else
    {
        jour = rand ()%(29) + 1;
    }
    j = jour % 10;
    r = (jour - j) / 10;
    date[0] = r+'0';
    date[1] = j+'0';
    date[2] ='/';
    date[10] = '\0';
    return date;
}


/*---------------------------------------------------------------module de wilaya----------------------------------------------------------*/

char *generate_wilaya ()
{
    char *w = malloc( 255 * sizeof(char));
    char *line = malloc( 255 * sizeof(char));
    int h;
    int i;
    int nb;
    nb = rand ()%(58) + 1;
    FILE *programme = fopen("Wilaya.txt","r"); //OUVERTURE DU FICHIER EN MODE LECTURE.

    for(i=1; i<=nb ;i++)
    {
        Vider_string(line); // VIDAGE DES CHAINES A CHAQUE FOIS ON PASSE A UNE NOUVELLE LIGNE
        fgets(line, 255, programme);
        h = 0;
        do
        {
            if(line[h] == '\n')
            {
                line[h] = '\0';
            }
            h++;
        }
        while (line[h] != '\0');
        /***********************************************************/
        strcpy(w , line);

    }

    fclose(programme);
    return (w) ;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

char *generate_sexe ()
{
    char *sexe = malloc((10) * sizeof(char));
    int nbr;
    nbr =   (rand ()%(2 + 1- 1) + 1); //on geenre un nombre, si c'etait 1 sexe est masculin; sinon cest feminin
    if (nbr == 1)
        strcpy(sexe, "masculin");
    else strcpy(sexe, "feminin");
    return sexe;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/


char *generate_gpsanguin ()//son role est de generer le x de l'enseignant d'une fa�con aleatoire
{

    int nb;
    nb = rand ()%(8)+1  ; //on genere le nombre de caractere
    char *groupe_sanguin = malloc( 5 * sizeof(char));
    switch(nb)
    {
        case 1:
            strcpy(groupe_sanguin,"O+");
            break;

        case 2:
            strcpy(groupe_sanguin,"A+");
            break;
        case 3:
            strcpy(groupe_sanguin,"B+");

            break;

        case 4:
            strcpy(groupe_sanguin,"O-");

            break;
        case 5:
            strcpy(groupe_sanguin,"A-");

            break;

        case 6:
            strcpy(groupe_sanguin,"AB+");

            break;
        case 7:
            strcpy(groupe_sanguin,"B-");

            break;

        case 8:
            strcpy(groupe_sanguin,"AB-");

            break;

    }
    groupe_sanguin[strlen(groupe_sanguin)+1] = '\0';
    return groupe_sanguin ;
}




/*-----------------------------------------------------------------------------------------------------------------------------------------*/

char *generate_specialite ()//son role est de generer le x de l'enseignant d'une fa�con aleatoire
{

    int nb;
    nb = (rand ()%(39 + 1- 1) + 1); //on genere le nombre de caractere
    char *c = malloc( 50 * sizeof(char));
    char specialite [50][40] = {"Aeronautique","Automatique","Electromecanique","Electronique",
                              "Electrotechnique","Energies renouvelables","Genie biomedical","Genie civil","Genie climatique","Genie de procedes","Genie industriel"
            ,"Genie maritime","Genie m�canique","Chimie","Physique","Informatique","Mathematiques","Biotechnologies","Ecologie et environnement"
            ,"Hydrobiologie marine et continentale","Sciences agronomiques","Geologie","Sciences commerciales"
            ,"Sciences de gestion","Sciences economiques","Droit","Sciences politiques","langues","Sciences humaines"
            ,"Sciences islamiques","sport","Arts","Architecture","Urbanisme","Metiers de la ville","Pharmacie","Medecine dentaire","Medcine"};
    strcpy(c ,specialite[nb-1]);

    return c ;
}



/*-----------------------------------------------------------------------------------------------------------------------------------------*/
char *generate_Etablissement_Univ ()
{
    char *line = malloc( 255 * sizeof(char));
    char *etablissement = malloc( 255 * sizeof(char));
    int h;
    int i;
    int nb;
    nb = rand ()%(112) + 1;
    FILE *programme = fopen("Etablisement_univ.txt","r"); //OUVERTURE DU FICHIER EN MODE LECTURE.

    for(i=1; i<=nb ;i++)
    {
        Vider_string(line); // VIDAGE DES CHAINES A CHAQUE FOIS ON PASSE A UNE NOUVELLE LIGNE
        fgets(line, 255, programme);
        h = 0;
        do
        {
            if(line[h] == '\n')
            {
                line[h] = '\0';
            }
            h++;
        }
        while (line[h] != '\0');
        /***********************************************************/
        strcpy(etablissement , line);

    }

    fclose(programme);
    return (etablissement) ;
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/
char *generate_Dernier_Diplome ()//son role est de generer le x de l'enseignant d'une fa�con aleatoire
{

    int nb;
    nb = rand ()%(6) +1 ; //on genere le nombre de caractere
    char *Diplome = malloc( 50 * sizeof(char));
    switch(nb)
    {
        case 1:
            strcpy(Diplome,"Doctorat d Etat");
            break;

        case 2:
            strcpy(Diplome,"Doctorat en sciences");
            break;
        case 3:
            strcpy(Diplome,"Doctorat D-LMD");

            break;

        case 4:
            strcpy(Diplome,"PhD");

            break;
        case 5:
            strcpy(Diplome,"Habilitation Universitaire");

            break;

        case 6:
            strcpy(Diplome,"Magistere");

            break;
    }
    return Diplome ;
}


char *generate_grade ()//son role est de generer le x de l'enseignant d'une fa�con aleatoire
{

    int nb;
    nb = rand ()%(6) +1 ; //on genere le nombre de caractere
    char *grade = malloc( 50 * sizeof(char));
    switch(nb)
    {
        case 1:
            strcpy(grade,"Professeur(e)");
            break;

        case 2:
            strcpy(grade,"Maitre de conferences Rang A");
            break;
        case 3:
            strcpy(grade,"Maitre de conferences Rang B");

            break;

        case 4:
            strcpy(grade,"Maitre assistant(e)Rang A");

            break;
        case 5:
            strcpy(grade,"Maitre assistant(e) Rang B");

            break;

        case 6:
            strcpy(grade,"Assistant(e)");

            break;
    }
    return grade ;
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/

char *generate_Date_Recrutement (char date[10])
{

    int daten , mois , jour;
    int a1 , a2 , a3 ,a4 , m ,o ,y , r;
    char date1[5];
    char daterec[10];
    daten =  (date[9] - '0') + (date[8] - '0')*10 + (date[7] - '0')*100 +(date[6] - '0')*1000 ;
    char *date2 = malloc( 11 * sizeof(char));
    int j = daten + 22;
    int k ;
    if (1985 < j)
        k = j;
    else if (1985 >= j)
        k = 1985;
    int nb  = rand ()%(2022 - k) + k;
    mois = (rand ()%(12) + 1);
    int jrMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((mois != 2) || ((mois == 2 )&& (an_bitextile (nb)==0)))
    {
        jour = (rand ()%(28 + 1- 1) + 1);
    }
    else
    {
        jour = (rand ()%(29 + 1- 1) + 1);
    }
    a1 = nb % 10;
    a2 = ((nb - a1)/10) % 10;
    a3 = ((nb -a1 -a2*10)/100) %10;
    a4 = (nb -a1 -a2*10 -a3*100)/1000 ;
    date2[9] = a1 +'0';
    date2[8] = a2 +'0';
    date2[7] = a3 +'0';
    date2[6] = a4 +'0';
    date2[5] ='/';
    y = jour % 10;
    r =  (jour -y)/10;
    date2[0] = r+'0';
    date2[1] = y+'0';
    date2[2] = '/';
    m =mois %10;
    o = (mois -m)/ 10;
    date2[3] = o+'0';
    date2[4] = m+'0';
    date2[10]='\0';
    return date2;
}



void init_enr (Tenreg *e )
{
    e->matricule = generate_matricule();
    strcpy (e->sexe , generate_sexe());
    strcpy (e->nom , generate_nom());
    strcpy (e->prenom , generate_prenom());
    strcpy (e->date_naissance , generate_datenaissance());
    strcpy (e->dernier_diplome , generate_Dernier_Diplome());
    strcpy (e->groupe_sanguin , generate_gpsanguin());
    strcpy (e->grade , generate_grade());
    strcpy (e->specialite , generate_specialite());
    strcpy (e->wilaya_naissance , generate_wilaya());
    strcpy (e->etablissement_univ , generate_Etablissement_Univ());
    strcpy (e->date_recrutement , generate_Date_Recrutement(e->date_naissance));
}



void chargementInitial(char *nomf, int n, LObF *fichier , index *ind , int *nbrecriredir )
{

    Tenreg e;
    int i, j;
    Tbloc buf;
    ouvrir(fichier, nomf, 'N'); //on ouvre le fichier en mode new
    i = 1; //le numero de bloc
    j = 0;//numero d'enreg
    int i1 , trouv ;

    for (int k = 0; k < n; k++)
    {
        init:init_enr(&e); //on initialise e par les informations necessaire
        rech_index (e.matricule , &ind->tab , k , &trouv , &i1); // on recherche si la matricule deja existée
        if (!trouv) {
            ind->nbl++;
            if (j < Maxbloc){
                insert_ind(e.matricule, &ind->tab, k, i1, j, i); //la position de l'enreg dans le bloc est j
            }
                 else
                insert_ind(e.matricule, &ind->tab, k, i1, 0, i+1);//par contre ici ca sera 0 (nouveau bloc)
        }
        else goto init;   //si on a trouvé la clé deja inseree on revient a changer la clé pour eviter la repitition
        if (j < Maxbloc)
        {
            buf.tab[j] = e;
            j++;
        }

        else
        {
            buf.nb = j;
            buf.suiv = i + 1;
            EcrireDir(fichier, i, &buf);
            j = 0;
            i++;
            buf.tab[j] = e;
            j = 1;
        }
    }
    buf.nb = j;
    buf.suiv = -1;
    EcrireDir(fichier, i, &buf);
    Aff_Entete(fichier, 1, 1);
    Aff_Entete(fichier, 2, i);
    *nbrecriredir = i;
    fermer(fichier);
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void ajouter_ens ( LObF *fichier , int mat , int *nbrecriredir ,int *nbrliredir )
{
    int i , n , trouv , i1 ;
    Tenreg e;
    Tbloc buffer;
    index *ind = malloc( sizeof (index));
    e.matricule = mat;
    chargement_ind("ind" , ind->tab , &ind->nbl); //on charge la table d'index dans la MC
    rech_index (e.matricule , &ind->tab , ind->nbl , &trouv , &i1); //on recherche s'il n'existe pas dans notre fichier � partir de table d'index
    if (!trouv) //si on a pas trouv� on le met dans le fichier
    {
         //printf("le reste des informations va se remplir d'une maniere aleatoire\n");
            strcpy (e.sexe , generate_sexe());
            strcpy (e.nom , generate_nom());
            strcpy (e.prenom , generate_prenom());
            strcpy (e.date_naissance , generate_datenaissance());
            strcpy (e.date_recrutement , generate_datenaissance());
            strcpy (e.dernier_diplome , generate_Dernier_Diplome());
            strcpy (e.groupe_sanguin , generate_gpsanguin());
            strcpy (e.grade , generate_grade());
            strcpy (e.specialite , generate_specialite());
            strcpy (e.wilaya_naissance , generate_wilaya());
            strcpy(e.etablissement_univ , generate_Etablissement_Univ());


        ouvrir(&fichier , "ENSEIGNANT-MESRS.bin" , 'a' );
        n = Entete(&fichier , 2);
        LireDir(&fichier , n , &buffer );
        *nbrliredir = *nbrliredir +1;
        if (buffer.nb < Maxbloc )
        {
            buffer.tab[buffer.nb] = e;//la derniere place libre
            insert_ind(e.matricule , ind , ind->nbl , i1 ,buffer.nb , n); //on insert aussi en table d'index puis la sauvegarder
            ind->nbl ++;
            buffer.nb ++;
            EcrireDir(&fichier , n , &buffer);
            *nbrecriredir = *nbrecriredir +1;
            }
        else{ //bloc rempli
            buffer.suiv = n+1;
            EcrireDir(&fichier , n , &buffer);
            *nbrecriredir = *nbrecriredir +1;
            n++;
            buffer.nb = 1;
            buffer.tab[0] = e;
            buffer.suiv = -1;
            EcrireDir(&fichier , n , &buffer);
            *nbrecriredir = *nbrecriredir +1;
            Aff_Entete(&fichier , 2 , n);
            insert_ind(e.matricule , ind , 0 , i1 ,buffer.nb , n);
            ind->nbl ++;
        }
        sauv_index("ind" , &ind->tab , ind->nbl);
        //printf("enseignant bien ajote");
        fermer(&fichier);
        printf ("\t\t\ -> ENSEIGNANT BIEN AJOUTE <-");

    }
    else printf ("matricule deja existee"); //(trouv)
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void supp_ens ( LObF *fichier , int mat , int *nbrecriredir , int *nbrliredir)
{
    int i, j  , trouv , i1 , s;
    Tenreg e;
    Tbloc buffer;
    index *ind = malloc( sizeof (index));
    chargement_ind("ind" , ind->tab , &ind->nbl); //on charge la table d'index dans la MC
    rech_index (mat , &ind->tab , ind->nbl , &trouv , &i1); //on recherche s'il existe dans notre fichier � partir de table d'index
    if (trouv) //si on trouv la matricule dans la table d'index donc elle existe dans le fichier
    {
        ouvrir(&fichier , "ENSEIGNANT-MESRS.bin" , 'a' );
        i = ind->tab[i1].numblk;
        j = ind->tab[i1].numenrg;
        s = Entete(&fichier , 2);
        LireDir(&fichier , s, &buffer);//on lit le dernier bloc
        e = buffer.tab[buffer.nb];//on recupere le dernier enregistrement
        buffer.nb--; //on dicrimente le nombre d'enregistrement dans le dernier bloc "le dernier on le met a la place d'enregistrement effacé"
        EcrireDir(&fichier , Entete(&fichier , 2) , &buffer); //on ecrit le dernier bloc
        LireDir(&fichier , i , &buffer);//on lit le iéme bloc ou se trouve l'enregistremrnt de l'enseignant disigné
        buffer.tab[j] = buffer.tab[buffer.nb];//on ecrase le bloc disiné par le dernier bloc de fichier
        EcrireDir(&fichier , i , &buffer);//on ecrit le iéme bloc
        // la suupression au niveau de table d'index
        /*for (i1 ; i1<ind->nbl ; i1++)
        {
            ind->tab[i1] = ind->tab[i+1];
        }*/
        supp_ind(mat , ind->tab , ind->nbl);
        ind->nbl --;
        sauv_index("ind" , &ind->tab , ind->nbl);
        fermer(&fichier);
        printf("\t\t\t -> enseignant bien suprime <- \n");
         *nbrecriredir = *nbrecriredir +2;
        *nbrliredir = *nbrliredir +2;
    }
    else printf("enseignant n'existe pas\n");

}
void mutation ( LObF *fichier , int *nbrecriredir , int *nbrliredir ) {
    FILE *programme = fopen("Etablisement_univ.txt", "r"); //OUVERTURE DU FICHIER EN MODE LECTURE.
    int i, n, trouv, i1, mat, j, cpt = 1 , h , k;
    char *line = malloc( 255 * sizeof(char));
    char ligne [100];
    Tenreg e;
    Tbloc buffer;
    index *ind = malloc(sizeof(index));
    printf("donnez nous la matricule de l'enseignat pour faire la mutation : ");
    scanf("%d", &mat);
    chargement_ind("ind", ind->tab, &ind->nbl); //on charge la table d'index dans la MC
    rech_index(mat, &ind->tab, ind->nbl, &trouv,
               &i1); //on recherche s'il existe dans notre fichier � partir de table d'index
    if (trouv) //si on trouv la matricule dans la table d'index donc elle existe dans le fichier
    {
        ouvrir(&fichier, "ENSEIGNANT-MESRS.bin", 'a');
        i = ind->tab[i1].numblk;
        j = ind->tab[i1].numenrg;
       // printf(" i = %d , j = %d\n", i, j);
        LireDir(&fichier, i, &buffer);//on lit le ieme bloc dans buffer
        printf("hello world !\n");
        printf("l'etablissement actuelle de l'enseignant %s est : %s\n", buffer.tab[j].nom,
               buffer.tab[j].etablissement_univ);
        //affichage du fichier text
        if (programme == NULL) {
            printf("error");
        }
        printf("-------  La liste des etablissements : ---------\n");
        printf("-----------------------------------------\n");
        while (!feof(programme)) {
            if (/* lire discription */ fgets(ligne, sizeof(ligne), programme) != NULL) {
                printf("%d - %s", cpt, ligne);
                cpt++;
            }
        }//fin de la boucle d'affichage
        printf("\nveillez choisissez le nouveau etablissement par donner le nemureau qui corespend :");
        scanf("%d", &cpt);
        k = 0;
        programme = fopen("Etablisement_univ.txt", "r");
        while (!feof(programme)&&(k<cpt)) {
            if (/* lire discription */ fgets(ligne, sizeof(ligne), programme) != NULL){
                    k++;
            }
        }
        h = 0;
        do {
            if (ligne[h] == '\n') {
                ligne[h] = '\0';
            }
            h++;
        } while (ligne[h] != '\0');
            /***********************************************************/

        strcpy(buffer.tab[j].etablissement_univ, ligne);
        EcrireDir(&fichier, i, &buffer);
        printf("l'etablissement est bien changee");
        fermer(&fichier);
        fclose(programme);
        *nbrecriredir = *nbrecriredir +1;
        *nbrliredir = *nbrliredir +1; //on une lecture et une ecriture dans chaque mutation
    }
    else printf("enseignant n'existe pas\n");
}
void supp_specialite (LObF *fichier , int *nbrecriredir , int *nbrliredir)
{
    int i , s ;
    char sp[50];
    Tbloc buffer ;
    Tenreg e;
    index *ind = malloc( sizeof (index));
    chargement_ind("ind" , ind->tab , &ind->nbl); //on charge la table d'index dans la MC
    char specialite [50][42] = {"Aeronautique","Automatique","Electromecanique","Electronique",
                                "Electrotechnique","Energies renouvelables","Genie biomedical","Genie civil","Genie climatique","Genie de procedes","Genie industriel"
            ,"Genie maritime","Genie m�canique","Chimie","Physique","Informatique","Mathematiques","Biotechnologies","Ecologie et environnement"
            ,"Hydrobiologie marine et continentale","Sciences agronomiques","Geographie et amenagement du territoire","Geologie","Sciences commerciales"
            ,"Sciences de gestion","Sciences economiques","Sciences financi�res et comptabilit�","Droit","Sciences politiques","langues","Sciences humaines"
            ,"Sciences islamiques","sport","Arts","Architecture","Urbanisme","Metiers de la ville","Pharmacie","Medecine dentaire","Medcine"};
    for (i=0 ; i<=39 ; i++) //affichage de specialitée
    {
        printf("- %d - %s\n" , i+1 , specialite[i] );
    }
    printf("precisez la specialite que vous voulez supprimer :");
    scanf("%d" , &s);
    strcpy(sp , specialite[s-1]);
    ouvrir(&fichier , "ENSEIGNANT-MESRS.bin" , 'a' );
    for (i=1 ; i<= Entete(&fichier , 2) ; i++) //parcours de blocs (intra bloc)
    {
        //supp:
        LireDir(&fichier , i, &buffer);//on lit le ieme bloc
        *nbrliredir = *nbrliredir + 1;
        for (s=0 ; s<buffer.nb ; s++)//le pacours des enregistrements (inter bloc)
        {
            supp:if (strcmp(buffer.tab[s].specialite , sp) == 0)
            {
                LireDir(&fichier , Entete(&fichier , 2), &buffer);//on lit le dernier bloc
                *nbrliredir = *nbrliredir + 1;
                e = buffer.tab[buffer.nb];//on recupere le dernier enregistrement
                buffer.nb--; //on dicrimente le nombre d'enregistrement dans le dernier bloc "le dernier on le met a la place d'enregistrement effacé"
                EcrireDir(&fichier , Entete(&fichier , 2) , &buffer); //on ecrit le dernier bloc
                *nbrecriredir = *nbrecriredir +1;
                LireDir(&fichier , i , &buffer);//on lit le iéme bloc ou se trouve l'enregistremrnt de l'enseignant disigné
                *nbrliredir = *nbrliredir + 1;
                buffer.tab[s] = buffer.tab[buffer.nb];//on ecrase le bloc disiné par le dernier bloc de fichier
                EcrireDir(&fichier , i , &buffer);//on ecrit le iéme bloc
                *nbrecriredir = *nbrecriredir +1;
                supp_ind(buffer.tab[s].matricule , ind->tab , ind->nbl);
                ind->nbl --;
                sauv_index("ind" , &ind->tab , ind->nbl);
                goto supp; //on verifie si on a pas remplacé l'enreg supprimé par un qui doit etre aussi supprimé
            }
        }
    }
    fermer(&fichier);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void affichage (LObF *fichier,char nom_fich[30] , int *nbrliredir)
{
    int i,j,n , cpt ,k ,l;
    Tbloc buf;
    char *etaf = malloc((255) * sizeof(char));
    ouvrir(fichier,nom_fich,'A');//ouvrir le fichier en mode ancien
    if(fichier->f!=NULL)//si le fichier existe
    {i=Entete(fichier,1);//recup�rer le num�ro du premier bloc
        n=Entete(fichier,2);//recup�rer le nombre d'enregistrements                                                                                                |
        *nbrliredir = n+*nbrliredir;
        cpt =0;

    printf("\n _________ ____________________ ____________________ ________ ____________________ __________ ____________________________________ __________ ___ ___________________________________\n");
    printf("|         |                    |                    |        |                    |          |                                    |          |   |                                   |\n");
    printf("|Matricule|        Nom         |       Prenom       |  sexe  |  Wilaya Naissance  | DateNai  |        Specialite                  | DtaeRe   |ABO|        Grade                      |\n");
    printf("|_________|____________________|____________________|________|____________________|__________|____________________________________|__________|___|___________________________________|\n");
    printf("|         |                    |                    |        |                    |          |                                    |          |   |                                   |\n");
        while((i<=n) && (i<=3))//tant qu'on est pas arriv� � la fin de fichier
        {
            LireDir(fichier,i,&buf);//lire le buf i
            for (j=0 ; j<buf.nb ; j++)
            {
                k = 2;
                l = 0;
                   for(k = 2; buf.tab[j].etablissement_univ[k] != '\0'; k++)
                        {

                           etaf[l] = buf.tab[j].etablissement_univ[k];
                           l++;
                        }
                       etaf[l] = '\0';



    printf("|");

    printf("%9d", buf.tab[j].matricule);

    printf("|");

    printf("%-20s", buf.tab[j].nom);

    printf("|");

    printf("%-20s", buf.tab[j].prenom);

    printf("|");

    printf("%-8s", buf.tab[j].sexe);

    printf("|");

    printf("%-20s", buf.tab[j].wilaya_naissance);

    printf("|");

    printf("%-10s", buf.tab[j].date_naissance);

    printf("|");

    printf("%-36s", buf.tab[j].specialite);

    printf("|");

    printf("%-10s", buf.tab[j].date_recrutement);

    printf("|");

    printf("%3s", buf.tab[j].groupe_sanguin);

    printf("|");
    printf("%-35s", buf.tab[j].grade);
    printf("|\n");


                cpt++;
            }
            i ++;
        }
    }
    fermer (fichier);
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void affichage2 (LObF *fichier,char nom_fich[30] , int *nbrliredir)
{

    char *etaf = malloc((255) * sizeof(char));
    char *eta = malloc((255) * sizeof(char));
    char etaf1[255];
    int ane , mo ,jr ;
    int ane0 , mo0 ,jr0 ;
    int an2 , mo2 ,jr2 , nummin ,num2 ,nummax;
    int anc1 , anc2 ,anc3 ;
    int trouv ,trouv2 = 0;
    int day, month, year;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

     char *line = malloc( 255 * sizeof(char));
    char *etablissement = malloc( 255 * sizeof(char));
        char *etab = malloc( 255 * sizeof(char));
    FILE *programme = fopen("Etablisement_univ.txt","r");
	int u , h ,k ,l;
	int y = 1;
	while (!(feof(programme)))
    {
      Vider_string(line); // VIDAGE DES CHAINES A CHAQUE FOIS ON PASSE A UNE NOUVELLE LIGNE
        fgets(line, 255, programme);
        h = 0;
        do
        {
            if(line[h] == '\n')
            {
                line[h] = '\0';
            }
            h++;
        }
        while (line[h] != '\0');
        /***********************************************************/
        char text[255];
        line[0] = '-';
        sprintf(text, "%d", y);
        strcpy(etablissement , text);
         int s = strlen(etablissement);
        strcat(text , line );
		printf("%s\n" ,text );
        y++;

	}
	fclose(programme);
    printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
	printf("Selectionnez l'etablissement par numero : ");
	scanf("%d" , &u);
    printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");

        FILE *programme1 = fopen("Etablisement_univ.txt","r");
	for ( int h =1 ; h<=u ;h++)
    {
      Vider_string(line); // VIDAGE DES CHAINES A CHAQUE FOIS ON PASSE A UNE NOUVELLE LIGNE
        fgets(line, 255, programme1);

	}
	 h = 0;
        do
        {
            if(line[h] == '\n')
            {
                line[h] = '\0';
            }
            h++;
        }
        while (line[h] != '\0');
        /***********************************************************/
	strcpy(etab , line);
	fclose(programme1);
	k = 2;
    l = 0;
     for(k = 2; etab[k] != '\0'; k++)
        {
           eta[l] = etab[k];
           l++;
        }
    eta[l] = '\0';
    printf("Vous avez choisi l etablissment suivant : %s \n" , eta);
    printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("Entrer L anciennete Minimale: \n");
    printf("A- En Anne : \n");
    scanf("%d" , &ane);
    printf("B- En Mois : \n");
    scanf("%d" , &mo);
    printf("A- En Jours : \n");
    scanf("%d" , &jr);

    printf("Entrer L anciennete Maximale: \n");
    printf("A- En Anne : \n");
    scanf("%d" , &ane0);
    printf("B- En Mois : \n");
    scanf("%d" , &mo0);
    printf("A- En Jours : \n");
    scanf("%d" , &jr0);
    nummax = ane0*365 +mo0*30 +jr0;
    nummin = ane *365 +mo*30 +jr ;
    int i,j,n , cpt  ;
    Tbloc buf;
    ouvrir(fichier,nom_fich,'A');//ouvrir le fichier en mode ancien
    if(fichier->f!=NULL)//si le fichier existe
    {i=Entete(fichier,1);//recup�rer le num�ro du premier bloc
        n=Entete(fichier,2);//recup�rer le nombre d'enregistrements
        *nbrliredir = n+*nbrliredir;
        cpt =0;
        printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("La Liste des enseignants exerçant dans L etablissement %s avec une anciennete entre %d jours et %d jours sont :\n", eta ,nummin , nummax);
        printf("\n");

        while(i<=n)//tant qu'on est pas arriv� � la fin de fichier
        {
            LireDir(fichier,i,&buf);//lire le buf i
            for (j=0 ; j<buf.nb ; j++)
            {
                k = 2;
                l = 0;
                   for(k = 2; buf.tab[j].etablissement_univ[k] != '\0'; k++)
                        {

                           etaf[l] = buf.tab[j].etablissement_univ[k];
                           l++;
                        }
                       etaf[l] = '\0';
                       trouv = 1;
                 if (strcmp(etaf,eta) == 0)
                  {
                         an2 = (buf.tab[j].date_recrutement[9] - '0') + (buf.tab[j].date_recrutement[8] - '0')*10 + (buf.tab[j].date_recrutement[7] - '0')*100 +(buf.tab[j].date_recrutement[6] - '0')*1000 ;
                         mo2 = (buf.tab[j].date_recrutement[4] - '0') + (buf.tab[j].date_recrutement[3] - '0')*10 ;
                         jr2 = (buf.tab[j].date_recrutement[1] - '0') + (buf.tab[j].date_recrutement[0] - '0')*10 ;
                         anc1 = year - an2  ;
                         anc2 = month - mo2 ;
                         anc3 = day - jr2 ;
                         num2 = anc1*365 + anc2*30 +anc3;


                         if(nummin > num2 || num2 >nummax)
                         {
                             trouv = 0;
                         }

                        if (trouv == 1)
                        {
                            trouv2 = 1;

        printf("|");

    printf("%9d", buf.tab[j].matricule);

    printf("|");

    printf("%-20s", buf.tab[j].nom);

    printf("|");

    printf("%-20s", buf.tab[j].prenom);

    printf("|");

    printf("%-8s", buf.tab[j].sexe);

    printf("|");

    printf("%-20s", buf.tab[j].wilaya_naissance);

    printf("|");

    printf("%-10s", buf.tab[j].date_naissance);

    printf("|");

    printf("%-36s", buf.tab[j].specialite);

    printf("|");

    printf("%-10s", buf.tab[j].date_recrutement);

    printf("|");

    printf("%3s", buf.tab[j].groupe_sanguin);

    printf("|");
    printf("%-35s", buf.tab[j].grade);
    printf("|\n");
                        }

                  }

            }
            i++;
        }
    }
    if (trouv2 == 0)
    {
        printf(".............. Il y a pas d'ensegnants.\n");
    }
    fermer (fichier);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void affichage3 (LObF *fichier,char nom_fich[30] ,int *nbrliredir )
{

    char *region = malloc((255) * sizeof(char));
    char *region2 = malloc((255) * sizeof(char));

    do
    {
    printf("Entrer La Region (Est-Ouest-Centre): \n");
    fflush(stdin);
    gets(region);
    fflush(stdin);
    strcpy(region2 , region);
    Maj_string(region2);
    }
    while  ( ( strcmp( region2 , "CENTRE") != 0) && (strcmp(region2 , "EST") != 0) && (strcmp(region2 , "OUEST") != 0) );
    printf("La Region que vous avez choisi est :%s \n", region);
    int i,j,n , cpt ,trouv  , trouv2 = 0 ;
    Tbloc buf;
    ouvrir(fichier,nom_fich,'A');//ouvrir le fichier en mode ancien
    if(fichier->f!=NULL)//si le fichier existe
    {i=Entete(fichier,1);//recup�rer le num�ro du premier bloc
        n=Entete(fichier,2);//recup�rer le nombre d'enregistrements
        *nbrliredir = n+*nbrliredir;
        cpt =0;
        printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("La Liste des enseignants exerçant dans La Region %s sont :\n", region);
        while(i<=n)//tant qu'on est pas arriv� � la fin de fichier
        {
            LireDir(fichier,i,&buf);//lire le buf i
            for (j=0 ; j<buf.nb ; j++)
            {

                       trouv = 0;

                         if(buf.tab[j].etablissement_univ[0] == toupper(region[0]) )
                         {
                             trouv = 1;
                         }

                        if (trouv == 1)
                        {
                         trouv2 = 1;
                        printf("|");

    printf("%9d", buf.tab[j].matricule);

    printf("|");

    printf("%-20s", buf.tab[j].nom);

    printf("|");

    printf("%-20s", buf.tab[j].prenom);

    printf("|");

    printf("%-8s", buf.tab[j].sexe);

    printf("|");

    printf("%-20s", buf.tab[j].wilaya_naissance);

    printf("|");

    printf("%-10s", buf.tab[j].date_naissance);

    printf("|");

    printf("%-36s", buf.tab[j].specialite);

    printf("|");

    printf("%-10s", buf.tab[j].date_recrutement);

    printf("|");

    printf("%3s", buf.tab[j].groupe_sanguin);

    printf("|");
    printf("%-35s", buf.tab[j].grade);
    printf("|\n");
                        }

                  }


            i++;
        }
    }
        if (trouv2 == 0)
    {
        printf(".............. Il y a pas d'ensegnants.\n");
    }
    fermer (fichier);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void codage_enreg (Tenreg *e ,  char cle [20])
{

    int t , k ,l , p =1;
    int i = 0, j = 0;
 for (l=0 ;l<strlen(cle) ;l++)
 {
   k = (cle[l] - '0')*p;
   p = p*10;
 }
 k = k % 1000000;
 e->matricule = e->matricule - k;


 while ( e->wilaya_naissance[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->wilaya_naissance[i] + cle[j];
e->wilaya_naissance[i] = e->wilaya_naissance[i] + cle[j];
 while ( t > 126 ) {

 e->wilaya_naissance[i] = e->wilaya_naissance[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
  while ( e->nom[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->nom[i] + cle[j];
e->nom[i] = e->nom[i] + cle[j];
  while ( t > 126 ) {

 e->nom[i] = e->nom[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
 while ( e->prenom[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->prenom[i] + cle[j];
e->prenom[i] = e->prenom[i] + cle[j];
  while ( t > 126 ) {

 e->prenom[i] = e->prenom[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->date_naissance[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->date_naissance[i] + cle[j];
e->date_naissance[i] = e->date_naissance[i] + cle[j];
  while ( t > 126 ) {

 e->date_naissance[i] = e->date_naissance[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;

/**************************************************************************************************************/
while ( e->date_recrutement[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->date_recrutement[i] + cle[j];
e->date_recrutement[i] = e->date_recrutement[i] + cle[j];
  while ( t > 126 ) {

 e->date_recrutement[i] = e->date_recrutement[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->specialite[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->specialite[i] + cle[j];
e->specialite[i] = e->specialite[i] + cle[j];
  while ( t > 126 ) {

 e->specialite[i] = e->specialite[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->grade[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->grade[i] + cle[j];
e->grade[i] = e->grade[i] + cle[j];
  while ( t > 126 ) {

 e->grade[i] = e->grade[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->groupe_sanguin[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->groupe_sanguin[i] + cle[j];
e->groupe_sanguin[i] = e->groupe_sanguin[i] + cle[j];
  while ( t > 126 ) {

 e->groupe_sanguin[i] = e->groupe_sanguin[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->etablissement_univ[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->etablissement_univ[i] + cle[j];
e->etablissement_univ[i] = e->etablissement_univ[i] + cle[j];
  while ( t > 126 )
    {

 e->etablissement_univ[i] = e->etablissement_univ[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->sexe[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->sexe[i] + cle[j];
e->sexe[i] = e->sexe[i] + cle[j];
  while ( t > 126 ) {

 e->sexe[i] = e->sexe[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
while ( e->dernier_diplome[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
  t = e->dernier_diplome[i] + cle[j];
e->dernier_diplome[i] = e->dernier_diplome[i] + cle[j];
  while ( t > 126 ) {

 e->dernier_diplome[i] = e->dernier_diplome[i] - 127 + 32;
 t =  t - 127 + 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126
 }
 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé

 }
 i=0;
 j=0;
 t=0;
/**************************************************************************************************************/
}




/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void codage_fichier (LObF *fichier ,char nom_fich1[30] , char nom_fich2[30] , char cle[30])
{
    LObF *fichier2;
   int i,l,n , cpt;
    Tbloc buf;
    Tenreg e;
    ouvrir(fichier2,nom_fich2,'N');

    ouvrir(fichier,nom_fich1,'A');//ouvrir le fichier en mode ancien


    if(fichier->f!=NULL)//si le fichier existe
    {
	   i = Entete(fichier,1);//recup�rer le num�ro du premier bloc
       n = Entete(fichier,2);
	   while(i<=n)//tant qu'on est pas arriv� � la fin de fichier
        {
            LireDir(fichier,i,&buf);//lire le buf i
            for (l=0 ; l<buf.nb ; l++)
            {
                e = buf.tab[l];
			   codage_enreg (&e , cle);
			   buf.tab[l] = e;


            }
            EcrireDir(fichier2,i,&buf);
            i++;
        }

    }
    Aff_Entete(fichier2,1,1);
    Aff_Entete(fichier2,2,n);
    fermer(fichier);
    fermer(fichier2);

}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/


void decodage_enreg (Tenreg *e ,  char cle [20])
{
     int i = 0, j = 0;
     int l , k ,p=1;
     for (l=0 ;l<strlen(cle) ;l++)
     {
      k = (cle[l] - '0')*p;
      p = p*10;
     }
 k = k % 1000000;
 e->matricule = e->matricule + k;

 while ( e->wilaya_naissance[i] != '\0' ){ //Tant que ce n'est pas la fin du premier champ
 if (e->wilaya_naissance[i] >= 32 && e->wilaya_naissance[i] < 127)
 {
 e->wilaya_naissance[i] = e->wilaya_naissance[i] - cle[j];
 while ( e->wilaya_naissance[i] < 32 )
 e->wilaya_naissance[i] = e->wilaya_naissance[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;
/*******************************************************************************************************************************************************/
while ( e->nom[i] != '\0' ) {//Tant que ce n'est pas la fin du premier champ
 if (e->nom[i] >= 32 && e->nom[i] < 127)
 {
 e->nom[i] = e->nom[i] - cle[j];
 while ( e->nom[i] < 32 )
 e->nom[i] = e->nom[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
i=0;
 j=0;
/*******************************************************************************************************************************************************/

while ( e->prenom[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->prenom[i] >= 32 && e->prenom[i] < 127)
 {
 e->prenom[i] = e->prenom[i] - cle[j];
 while ( e->prenom[i] < 32 )
 e->prenom[i] = e->prenom[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;
 /*******************************************************************************************************************************************************/

while ( e->date_naissance[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->date_naissance[i] >= 32 && e->date_naissance[i] < 127)
 {
 e->date_naissance[i] = e->date_naissance[i] - cle[j];
 while ( e->date_naissance[i] < 32 )
 e->date_naissance[i] = e->date_naissance[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;

  /*******************************************************************************************************************************************************/

while ( e->date_recrutement[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->date_recrutement[i] >= 32 && e->date_recrutement[i] < 127)
 {
 e->date_recrutement[i] = e->date_recrutement[i] - cle[j];
 while ( e->date_recrutement[i] < 32 )
 e->date_recrutement[i] = e->date_recrutement[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;

   /*******************************************************************************************************************************************************/

while ( e->grade[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->grade[i] >= 32 && e->grade[i] < 127)
 {
 e->grade[i] = e->grade[i] - cle[j];
 while ( e->grade[i] < 32 )
 e->grade[i] = e->grade[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;
/*******************************************************************************************************************************************************/

while ( e->sexe[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->sexe[i] >= 32 && e->sexe[i] < 127)
 {
 e->sexe[i] = e->sexe[i] - cle[j];
 while ( e->sexe[i] < 32 )
 e->sexe[i] = e->sexe[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;

/*******************************************************************************************************************************************************/

while ( e->specialite[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->specialite[i] >= 32 && e->specialite[i] < 127)
 {
 e->specialite[i] = e->specialite[i] - cle[j];
 while ( e->specialite[i] < 32 )
 e->specialite[i] = e->specialite[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;

 /*******************************************************************************************************************************************************/

while ( e->etablissement_univ[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->etablissement_univ[i] >= 32 && e->etablissement_univ[i] < 127)
 {
 e->etablissement_univ[i] = e->etablissement_univ[i] - cle[j];
 while ( e->etablissement_univ[i] < 32 )
 e->etablissement_univ[i] = e->etablissement_univ[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;

  /*******************************************************************************************************************************************************/

while ( e->groupe_sanguin[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->groupe_sanguin[i] >= 32 && e->groupe_sanguin[i] < 127)
 {
 e->groupe_sanguin[i] = e->groupe_sanguin[i] - cle[j];
 while ( e->groupe_sanguin[i] < 32 )
 e->groupe_sanguin[i] = e->groupe_sanguin[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;

   /*******************************************************************************************************************************************************/

while ( e->dernier_diplome[i] != '\0' )
    { //Tant que ce n'est pas la fin du premier champ
 if (e->dernier_diplome[i] >= 32 && e->dernier_diplome[i] < 127)
 {
 e->dernier_diplome[i] = e->dernier_diplome[i] - cle[j];
 while ( e->dernier_diplome[i] < 32 )
 e->dernier_diplome[i] = e->dernier_diplome[i] + 127 - 32;
 // pour que le code obtenu reste un caractere affichable
 // les caract affichables ont un code ascii entre 32 et 126

 i++;
 j++;
 if (cle[j] == '\0') j = 0; // si c'est la fin de la chaine de caractère du mot ou de la clé
 }
 else
 i++;
 }
 i=0;
 j=0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void decodage_fichier (LObF *fichier ,char nom_fich1[30] , char nom_fich2[30] , char cle[30])
{
    LObF *fichier2;
   int i,l,n , cpt;
    Tbloc buf;
    Tenreg e;
    ouvrir(fichier2,nom_fich2,'N');

    ouvrir(fichier,nom_fich1,'A');//ouvrir le fichier en mode ancien


    if(fichier->f!=NULL)//si le fichier existe
    {
	   i = Entete(fichier,1);//recup�rer le num�ro du premier bloc
       n = Entete(fichier,2);
	   while(i<=n)//tant qu'on est pas arriv� � la fin de fichier
        {
            LireDir(fichier,i,&buf);//lire le buf i
            for (l=0 ; l<buf.nb ; l++)
            {
                e = buf.tab[l];
			   decodage_enreg (&e , cle);
			   buf.tab[l] = e;


            }
            EcrireDir(fichier2,i,&buf);
            i++;
        }

    }
    Aff_Entete(fichier2,1,1);
    Aff_Entete(fichier2,2,n);
    fermer(fichier);
    fermer(fichier2);

}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

