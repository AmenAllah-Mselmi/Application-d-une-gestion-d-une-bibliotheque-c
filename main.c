#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<windows.h>
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
typedef struct{
	int annee;
	int mois ;
	int jours;
}date;
typedef struct{
	 int nbr_effectues;
	 int nbr_encours;
	 int nbr_depasses;
}nb_emprunt;
typedef struct{
	char nom[30];
	char prenom[30];
	int identifiant;
	char adresse[30];
	char type[30];
	int duree;
	 int nbrdocuments;
}adherent;
typedef struct{
	char nomauteur[30];
	date datepub;
	char titre[30];
	int code;
	char localisation[30];
	int nbrfoisenpruntes ;
	int nombre;
}articles;
typedef struct{
	 char nomauteur[30];
	 char nomediteur[30];
	 date datedition;
	 char titre[30];
	 int code;
	 char localisation[30];
	 	int nbrfoisenpruntes ;
	int nombre;
}livres;
typedef struct{
	 int frequence;
	 int code;
	 char titre[30];
	 char localisation[30];
	 	int nbrfoisenpruntes ;
	int nombre;
} magazines;         
typedef struct{
	int code;
	char nom[30];
	char prenom[30];
	int nbrdocuments;
	date d1;
}listerouge;  
typedef struct{
		int code;
	char nom[30];
	char prenom[30];
	int nbrdocuments;
	date d1;
	date d2;
}listeencours;
typedef struct{
	int code ;
	int p1;
}vis; 
typedef struct{
	int code;
	int p1;
	int p2;
}etu;
typedef struct{
	int code;
	int p1;
	int p2;
	int p3;
	int p4;
}ens;         
int compdate(date* d1,date* d2){
	if(d1->annee>d2->annee){
		return 0;
	}
	else if(d1->annee<d2->annee){
		return 1;
	}
	else {
		if(d1->mois>d2->mois){
			return 0;
		}
		else if(d1->mois<d2->mois){
			return 1;
		}
		else{
			if(d1->jours>d2->jours){
				return 0;
			}
			else if(d1->jours<d2->jours){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}
void supplisterouge(listerouge* t,int* n,int s){
	listerouge* p1;
	listerouge* p2;
	listerouge* p3;
	for(p1=t;p1<*n+t;p1++){
		if(p1->code==s){
			for(p2=p1;p2<*n+t-1;p2++){
			p3=p2+1;
			p2->code=p3->code;
			p2->d1.annee=p3->d1.annee;
			p2->d1.jours=p3->d1.jours;
			p2->d1.mois=p3->d1.mois;
			p2->nbrdocuments=p3->nbrdocuments;
			strcpy(p2->nom,p3->nom);
			strcpy(p2->prenom,p3->prenom);
			}
			p1--;
			*n=*n-1;
		}
	}
}
void supplisteencours(listeencours* t,int* n,int s){
	listeencours* p1;
	listeencours* p2;
	listeencours* p3;
	for(p1=t;p1<*n+t;p1++){
		if(p1->code==s){
			for(p2=p1;p2<*n+t-1;p2++){
			p3=p2+1;
			p2->code=p3->code;
			p2->d1.annee=p3->d1.annee;
			p2->d1.jours=p3->d1.jours;
			p2->d1.mois=p3->d1.mois;
			p2->d2.annee=p3->d2.annee;
			p2->d2.jours=p3->d2.jours;
			p2->d2.mois=p3->d2.mois;
			p2->nbrdocuments=p3->nbrdocuments;
			strcpy(p2->nom,p3->nom);
			strcpy(p2->prenom,p3->prenom);
			}
			p1--;
			*n=*n-1;
		}
	}
}
void supp1(adherent* t,int* n,int s){
		adherent* p1;
adherent* p2;
adherent* p3;
	for(p1=t;p1<*n+t;p1++){
		if(p1->identifiant ==s){
			for(p2=p1;p2<*n+t-1;p2++){
			p3=p2+1;
			p2->duree=p3->duree;
			p2->identifiant=p3->identifiant;
			p2->nbrdocuments=p3->nbrdocuments;
			strcpy(p2->adresse,p3->adresse);
			strcpy(p2->nom,p3->nom);
			strcpy(p2->prenom,p3->prenom);
			strcpy(p2->type,p3->type);
			}
			*n=*n-1;
		}
	}
}
void ajouter1(int*t,int* n,int s){
	int* p;
	p=t;
		*n++;
	*(p+*n-1)=s;
}
void ajouter2(adherent* t,adherent* a,int* n){
	adherent* p;
	*n=*n+1;
	p=t+*n-1;
	strcpy(p->adresse ,a->adresse);
	p->duree=a->duree;
	p->identifiant=a->identifiant;
	p->nbrdocuments=a->nbrdocuments;
	strcpy(p->nom,a->nom);
    strcpy(	p->prenom,a->prenom);
    strcpy(p->type,a->type);	
}
int recherche(int* t,int n,int s){
	int pr=0;
	int i=0;
	do
	{
		if(t[i]==s){
			pr=1;
		}
		i++;
	}while(i<n||pr==0);
	return pr;
}
void acc(char ch[30],int* n){
	if(strcmp(ch,"etudiant")==0){
		*n=2;
	}
	else if(strcmp(ch,"enseignant")==0){
		*n=4;
	}
	else{
		*n=1;
	}
}
void acc1(char ch[30],int* n){
		if(strcmp(ch,"etudiant")==0){
		*n=1;
	}
	else if(strcmp(ch,"enseignant")==0){
		*n=3;
	}
	else{
		*n=1;
	}
}
void ajouterunjour(date* d){

          if(d->mois==1||d->mois==3||d->mois==5||d->mois==7||d->mois==8||d->mois==10||d->mois==12) {
		if(d->jours<=30&&d->jours>=1){
			d->jours=d->jours+1;
		}
		else {
			if(d->mois==12){
				d->annee=d->annee+1;
				d->mois=1;
				d->jours=1;
			}
			else{
				d->jours=1;
				d->mois=d->mois+1;
			}
		}
	}
	else if(d->mois==4||d->mois==6||d->mois==9||d->mois==11){
			if(d->jours<=29&&d->jours>=1){
				d->jours=d->jours+1;
			}
			else{
				d->jours=1;
				d->mois=d->mois+1;
			}
	}
	else{
			if(d->jours<=27&&d->jours>=1){
				d->jours=d->jours+1;
			}
			else{
			
		  if(d->annee% 4==0){
			d->jours=d->jours+1;
		}
		else{
			d->jours=1;
			d->mois=d->mois+1;
		}
	}
}
}
int recherche1(listerouge* t,int s,int n){
	int pr=0;
	listerouge* p;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(pr==0&&p<t+n);
	return pr;
}
void sasienregi(date* d){
	printf("donner les informations concernons la date du debut");
	printf("\n");
	do{
	printf("le jour de debut est :");
	scanf("%d",&(d->jours));
      }while(d->jours<1||d->jours>31);
	do{
	printf("le mois de debut est :");
	scanf("%d",&(d->mois));
      }while(d->mois>12||d->mois<1);
	do{
	printf("l'annee du debut est :");
	scanf("%d",&(d->annee));
}while(d->annee<0);
}
int saisie(){
	int n;
	do{
		printf("donner le nombre de client de ce jour");
		scanf("%d",&n);
	}while(n<0);
	return n;
}

void afficher1(adherent* p){
	printf("%s\t",p->nom);
	printf("%s\t",p->prenom);
	printf("%dsemaines\t",p->duree);
	printf("%s\t",p->adresse);
	printf("%d\t",p->nbrdocuments);
	printf("%d\t",p->identifiant);
	printf("%s\t",p->type);
}
void afficher2(livres* p){
	printf("%s\t",p->titre);
	printf("%d\t",p->code);
	printf("%s\t",p->nomediteur);
	printf("%s\t",p->nomauteur);
	printf("%d/%d/%d\t",p->datedition.jours,p->datedition.mois,p->datedition.annee);
	printf("%s\t",p->localisation);
		printf("%d\t",p->nombre);
	printf("%d\t",p->nbrfoisenpruntes);
}
void afficher3(articles* p){
	printf("%d\t",p->code);
		printf("%d/%d/%d\t",p->datepub.jours,p->datepub.mois,p->datepub.annee);
		printf("%s\t",p->nomauteur);
		printf("%s\t",p->titre);
		printf("%s\t",p->localisation);
			printf("%d\t",p->nombre);
	printf("%d\t",p->nbrfoisenpruntes);
}
void afficher4(magazines* p){
	printf("%d\t",p->code);
	printf("%d\t",p->frequence);
	printf("%s\t",p->titre);
	printf("%s\t",p->localisation);
	printf("%d\t",p->nombre);
	printf("%d\t",p->nbrfoisenpruntes);
}
void affichagetabenregistrement0(adherent* t,int n){
		adherent* p;
		Color(2,0);
		for(p=t;p<n+t;p++){
			afficher1(p);
			printf("\n");
		}
}
void affichagetabenregistrement1(livres* t,int n){
		livres* p;
		Color(2,0);
		for(p=t;p<n+t;p++){
			afficher2(p);
			printf("\n");
		}
}
void affichagetabenregistrement2(articles* t,int n){
		articles* p;
		Color(2,0);
		for(p=t;p<n+t;p++){
			afficher3(p);
			printf("\n");
		}
}
void affichagetabenregistrement3(magazines* t,int n){
		magazines* p;
		Color(2,0);
		for(p=t;p<n+t;p++){
			afficher4(p);
			printf("\n");
		}
}
void date1(date* p){
	printf("%d/%d/%d",p->jours,p->mois,p->annee);
	printf("\n------------------------------------------------------");
}
void semaine1(date* d,listeencours* a){
	   if(d->mois==1||d->mois==3||d->mois==5||d->mois==7||d->mois==8||d->mois==10||d->mois==12) {
		if(d->jours<=23&&d->jours>=1){
			a->d1.jours=d->jours+7;
			a->d1.mois=d->mois;
			a->d1.annee=d->annee;
		}
		else {
			if(d->mois==12){
				a->d1.annee=d->annee+1;
				a->d1.mois=1;
				a->d1.jours=(7-(31-d->jours));
			}
			else{
			a->d1.jours=(7-(31-d->jours));
			a->d1.mois=d->mois+1;
			a->d1.annee=d->annee;
			}
		}
	}
	else if(d->mois==4||d->mois==6||d->mois==9||d->mois==11){
			if(d->jours<=23&&d->jours>=1){
				a->d1.jours=d->jours+7;
				a->d1.mois=d->mois;
				a->d1.annee=d->annee;
			}
			else{
			a->d1.jours=(7-(30-d->jours));
					a->d1.mois=d->mois+1;
					a->d1.annee=d->annee;
			}
	}
	else{
			if(d->jours<=21&&d->jours>=1){
				a->d1.jours=d->jours+7;
				a->d1.mois=d->mois;
				a->d1.annee=d->annee;
			}
			else{
			
		  if(d->annee % 4==0){
			if(d->jours==22){
				a->d1.jours=29;
				a->d1.mois=d->mois;
				a->d1.annee=d->annee;
			}
			else{
				a->d1.jours=7-(29-(d->jours));
				a->d1.mois=d->mois+1;
				a->d1.annee=d->annee;
			}
		}
		else{
		a->d1.jours=7-(28-(d->jours));
				a->d1.mois=d->mois+1;
				a->d1.annee=d->annee;
		}
	}
}
}
void semaine3(date* d,listeencours* a){
	if(d->mois==1||d->mois==3||d->mois==5||d->mois==7||d->mois==8||d->mois==10||d->mois==12) {
		if(d->jours<=10&&d->jours>=1){
			a->d1.jours=d->jours+21;
			a->d1.mois=d->mois;
			a->d1.annee=d->annee;
		}
		else {
			if(d->mois==12){
				a->d1.annee=d->annee+1;;
				a->d1.mois=1;
				a->d1.jours=(21-(31-d->jours));
			}
			else{
				a->d1.jours=(21-(31-d->jours));
				a->d1.mois=d->mois+1;
				a->d1.annee=d->annee;
			}
		}
	}
	if(d->mois==4||d->mois==6||d->mois==9||d->mois==11){
			if(d->jours<=9&&d->jours>=1){
				a->d1.jours=d->jours+21;
				a->d1.annee=d->annee;
				a->d1.mois=d->mois;
			}
			else{
			a->d1.jours=(21-(30-d->jours));
					a->d1.mois=d->mois+1;
					a->d1.annee=d->annee;
			}
	}
	else{
			if(d->jours<=10&&d->jours>=1){
				a->d1.jours=d->jours+21;
				a->d1.mois=d->mois;
				a->d1.annee=d->annee;
			}
			else{
			
		  if(d->annee % 4==0){
			if(d->jours==8){
				a->d1.jours=29;
				a->d1.mois=d->mois;
				a->d1.annee=d->annee;
			}
			else{
				a->d1.jours=21-(29-(d->jours));
				a->d1.mois=d->mois+1;
				a->d1.annee=d->annee;
			}
		}
		else{
		a->d1.jours=21-(28-(d->jours));
				a->d1.mois=d->mois+1;
				a->d1.annee=d->annee;
		}
	}
}
}
int recherche1000(livres* t,int s,int n){
	int pr=0;
	livres* p;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;
}
int recherche1001(articles* t,int s,int n){
	int pr=0;
	articles* p;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;
}
int recherche1002(magazines* t,int s,int n){
	int pr=0;
	magazines* p;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;
}
void date_derendre(listeencours* a,date* d,adherent* h){
	if(strcmp(h->type,"etudiant")==0){
	       semaine1(d,a);
	}
	if(strcmp(h->type,"enseignant")==0){
		semaine3(d,a);
	}
	if(strcmp(h->type,"visiteur")==0){
		semaine1(d,a);
	}
}
void saisir5(listerouge* a){
	listerouge* p;
	Color(1,0);
	printf("donner le jour de  date limite\n");
	scanf("%d",(&(p->d1.jours)));
	printf("donner le mois de  date limite\n");
	scanf("%d",&(p->d1.mois));
	printf("donner l'annee' de  date limite\n");
	scanf("%d",&(p->d1.annee));
	printf("donner le code\n");
	scanf("%d",&(p->code));
	printf("donner le nombre de documents\n");
	scanf("%d",&(p->nbrdocuments));
	printf("donner le nom\n");
	scanf("%s",&(p->nom));
	printf("donner le prenom");
	scanf("%s",&(p->prenom));
}
void remplir_enre5(listerouge* t,int n){
	listerouge* p;
	for(p=t;p<n+t;p++){
		saisir5(p);
	}
}
void affiche5(listerouge* p){
	printf("%d/%d/%d \t",p->d1.jours,p->d1.mois,p->d1.annee);
	printf("%d\t",p->code);
	printf("%d\t",p->nbrdocuments);
	printf("%s\t",p->nom);
	printf("%s\t",p->prenom);
}
void aff_enr5(listerouge* t,int n){
	Color(11,0);
	listerouge* p;
	for(p=t;p<n+t;p++){
		affiche5(p);
		printf("\n");
	}
}
void affiche6(listeencours* p){
		int code;
	char nom[30];
	char prenom;
	int nbrdocuments;
	date d1;
	printf("%s\t",p->nom);
	printf("%s\t",p->prenom);
	printf("%d\t",p->code);
	printf("%d\t",p->nbrdocuments);
	printf("%d/%d/%d\t",p->d1.jours,p->d1.mois,p->d1.annee);
		printf("%d/%d/%d",p->d2.jours,p->d2.mois,p->d2.annee);
}
void aff_enr6(listeencours* t,int n){
	listeencours* p;
	Color(14,0);
	for(p=t;p<n+t;p++){
		affiche6(p);
		printf("\n");
	}
}
int compar1(date* a,listeencours* h){
int pr;
if(compdate(a,&(h->d1))==0){
	pr=0;
}
else{
	pr=1;
}
return pr;	
}
void ajouter6(listeencours* t,int* n,listeencours* e,date* d){
	listeencours* p;
	*n=*n+1;
	p=*n+t-1;
	p->d1.jours=e->d1.jours;
	p->d1.mois=e->d1.mois;
	p->d1.annee=e->d1.annee;
	p->code=e->code;
	p->nbrdocuments=e->nbrdocuments;
	strcpy(p->nom,e->nom);
	strcpy(p->prenom,e->prenom);
	p->d2.annee=d->annee;
	p->d2.jours=d->jours;
	p->d2.mois=d->mois;
}
void ajouter5(listerouge*t,int* n,listeencours* e){
	listerouge* p;
		*n=*n+1;
	p=*n+t-1;
	p->code=e->code;
	p->d1.annee=e->d1.annee;
	p->d1.jours=e->d1.jours;
	p->d1.mois=e->d1.mois;
	p->nbrdocuments=e->nbrdocuments;
	strcpy(p->nom,e->nom);
	strcpy(p->prenom,e->prenom);
}
void ajouter8(livres* t,int* n,livres* e){
	livres* p;
	*n=*n+1;
	p=*n+t-1;
	p->code=e->code;
	p->datedition.annee=e->datedition.annee;
	p->datedition.jours=e->datedition.jours;
	p->datedition.mois=e->datedition.mois;
	strcpy(p->localisation,e->localisation);
	p->nbrfoisenpruntes=0;
	strcpy(p->nomauteur,e->nomauteur);
	p->nombre=e->nombre;
	strcpy(p->nomediteur,e->nomediteur);
	strcpy(p->titre,e->titre);
}
void ajouter9(articles* t,int* n,articles* e){
	articles* p;
	*n=*n+1;
	p=*n+t-1;
	p->code=e->code;
	p->datepub.annee=e->datepub.annee;
	p->datepub.jours=e->datepub.jours;
	p->datepub.mois=e->datepub.mois;
	strcpy(p->localisation,e->localisation);
	p->nbrfoisenpruntes=e->nbrfoisenpruntes;
	strcpy(p->nomauteur,e->nomauteur);
	strcpy(p->titre,e->titre);
	p->nombre=e->nombre;
}
void ajouter10(magazines* t,int* n,magazines* e){
	magazines* p;
	*n=*n+1;
	p=*n+t-1;
	p->code=e->code;
	p->frequence=e->frequence;
	strcpy(p->localisation,e->localisation);
	p->nbrfoisenpruntes=e->nbrfoisenpruntes;
	p->nombre=e->nombre;
	strcpy(p->titre,e->titre);
}
int recherche3(char ch[30],livres* t,int n){
	livres* p=t;
	int g=0;
	do{
		if(strcmp(ch,p->titre)==0){
			g=1;
		}
		p++;
	}while(p<n+t&&g==0);
	return g;
}
int recherche4(char ch[30],articles* t,int n){
	articles* p=t;
	int g=0;
	do{
		if(strcmp(ch,p->titre)==0){
			g=1;
		}
		p++;
	}while(p<n+t&&g==0);
	return g;
}
int recherche5(char ch[30],magazines* t,int n){
	magazines* p=t;
	int g=0;
	do{
		if(strcmp(ch,p->titre)==0){
			g=1;
		}
		p++;
	}while(p<n+t&&g==0);
	return g;
}
int ind1(char ch[30],livres*t,int n){
	int g=0;
	int pr=0;
	livres* p=t;
	do{
		if(strcmp(ch,p->titre)==0){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int ind2(char ch[30],articles*t,int n){
	int g=0;
	int pr=0;
	articles* p=t;
	do{
		if(strcmp(ch,p->titre)==0){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int ind3(char ch[30],magazines*t,int n){
	int g=0;
	int pr=0;
	magazines* p=t;
	do{
		if(strcmp(ch,p->titre)==0){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int nbr1(char ch[30],livres* t,int n){
	int n1;
	livres* p;
	int g;
	g=ind1(ch,t,n);
	p=t+g;
	n1=p->nombre;
	return n1;
}
int nbr2(char ch[30],articles* t,int n){
	articles* p;
	int n1;
	int g;
	g=ind2(ch,t,n);
	p=t+g;
	n1=p->nombre;
	return n1;
}
int nbr3(char ch[30],magazines* t,int n){
	magazines* p;
	int n1;
	int g;
	g=ind3(ch,t,n);
	p=t+g;
	n1=p->nombre;
	return n1;
}
void emprunter(livres* t1,articles* t2,magazines* t3,int n1,int n2,int n3,int* g){
	livres* p1;
	magazines* p3;
	articles* p2;
	int h1,h2,h3,e=0;
	char ch[30];
	do{
		Color(1,0);
		printf("donner le nom du document que vous chercher");
		scanf("%s",ch);
	if(recherche3(ch,t1,n1)==1){
		h1=ind1(ch,t1,n1);
		if(nbr1(ch,t1,n1)==0){
			Color(4,0);
			printf("\n desole monsieur  il n'ya plus de livres de ce type la pour enprunter \n");
		}
		else{
			e=1;
		p1=t1+h1;
		p1->nombre=p1->nombre-1;
		p1->nbrfoisenpruntes=p1->nbrfoisenpruntes+1;
		*g=p1->code;
		}
	}
	else if(recherche4(ch,t2,n2)==1){
		h2=ind2(ch,t2,n2);
		if(nbr2(ch,t2,n2)==0){
			Color(4,0);
			printf("desole monsieur  il n'ya plus de livres de ce type la pour enprunter\n");
		}
		else{
			e=1;
		p2=t2+h2;
		p2->nombre=p2->nombre-1;
		p2->nbrfoisenpruntes=p2->nbrfoisenpruntes+1;
		*g=p2->code;
		}
	}
	 else if(recherche5(ch,t3,n3)==1){
		h3=ind3(ch,t3,n3);
	
		if(nbr3(ch,t3,n3)==0){
			Color(4,0);
			printf("desole monsieur il n'ya plus de livres de ce type la pour enprunter\n");
		}
		else{
			e=1;
		p3=t3+h3;
		p3->nombre=p3->nombre-1;
		p3->nbrfoisenpruntes=p3->nbrfoisenpruntes+1;
		*g=p3->code;
		}
	}
	else{
		Color(4,0);
		printf("\n desole ce document n'existe pas\n");
	}
	}while(e==0);
}
int recherche2(listeencours* t,int s,int n){
	int pr=0;
	listeencours* p;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;
}
int recherche9(adherent* t,int s,int n){
		int pr=0;
	adherent* p;
	p=t;
	do{
		if(p->identifiant==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;
}
void miseenpage1(date* d){
	Color(2,0);
	printf("***************************************************\n\n");
	printf("                                                           %d/%d/%d  \n",d->jours,d->mois,d->annee);
	printf("1-inscription\n");
	printf("2-emprunter\n");
	printf("3-rendre\n");
	printf("4-ajouter un livre\n");
	printf("5-ajouter un article\n");
	printf("6-ajouter une magazine\n");
	printf("7-voir la liste des adherents\n");
	printf("8-voir la liste en cours d'emprunts\n");
	printf("9-voir la liste des retardataires\n");
	printf("10-voir la liste des livres\n");
	printf("11-voir la liste des articles\n");
	printf("12-voir la liste des magazines\n");
	printf("13-supprimer un identifiant\n");
	printf("14-chercher\n");
	printf("15-Modifier\n");
	printf("16-fermer\n");
}
void find(adherent* t,int s,adherent* a){
	 adherent* p;
	 p=t;
	while(p->identifiant!=s){
		p++;
	}
	strcpy(a->adresse,p->adresse);
	a->duree=p->duree;
	a->identifiant=p->identifiant;
	a->nbrdocuments=p->nbrdocuments;
	strcpy(a->nom,p->nom);
	strcpy(a->prenom,p->prenom);
	strcpy(a->type,p->type);
}
void lef(adherent* a,listeencours* t){
	t->code=a->identifiant;
	t->nbrdocuments=a->nbrdocuments;
	strcpy(t->nom,a->nom);
	strcpy(t->prenom,a->prenom);
}
void ajouter11(listerouge* t,int* n,listeencours* a){
	listerouge* p;
	*n=*n+1;
	p=t+*n-1;
	p->code=a->code;
	p->d1.jours=a->d1.jours;
	p->d1.mois=a->d1.mois;
	p->d1.annee=a->d1.annee;
	p->nbrdocuments=a->nbrdocuments;
	strcpy(p->nom,a->nom);
	strcpy(p->prenom,a->prenom);
}
int recherche11(int s,listeencours* t,int n){
	listeencours* p;
	int pr=0;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;
}
void ajouter13(int* t,vis* t1,int* n){
	vis* p;
		*n=*n+1;
	p=t1+*n-1;
	p->code=*(t);
	p->p1=*(t+1);
}
void ajouter14(int* t,etu* t1,int* n){
	etu* p;
	*n=*n+1;
		p=t1+*n-1;
	p->code=*(t);
	p->p1=*(t+1);
	p->p2=*(t+2);
}
void ajouter15(int* t,ens* t1,int* n){
	ens* p;
	*n=*n+1;
	p=t1+*n-1;
	p->code=*(t);
	p->p1=*(t+1);
	p->p2=*(t+2);
	p->p3=*(t+3);
	p->p4=*(t+4);
}
int recherche20(int s,vis* t,int n){
vis* p;
	int pr=0;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;	
}
int recherche21(int s,etu* t,int n){
	etu* p;
	int pr=0;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;	
}
int ind11(int s,vis* t,int n){
		int g=0;
	int pr=0;
	vis* p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int ind12(int s,etu* t,int n){
		int g=0;
	int pr=0;
	etu* p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int ind13(int s,ens* t,int n){
		int g=0;
	int pr=0;
	ens* p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int recherche30(int s,livres* t,int n){
	livres* p;
	int pr=0;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;	
}
int recherche31(int s,articles* t,int n){
	articles* p;
	int pr=0;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;	
}
int recherche32(int s,magazines* t,int n){
	magazines* p;
	int pr=0;
	p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		p++;
	}while(p<n+t&&pr==0);
	return pr;	
}
int ind100(int s,livres* t,int n){
		int g=0;
	int pr=0;
	livres* p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int ind101(int s,articles* t,int n){
		int g=0;
	int pr=0;
	articles* p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
int ind102(int s,magazines* t,int n){
		int g=0;
	int pr=0;
	magazines* p=t;
	do{
		if(p->code==s){
			pr=1;
		}
		else{
			p++;
			g++;
		}
	}while(p<n+t&&pr==0);
	return g;
}
void rendre(livres* t1,articles* t2,magazines* t3,vis* t4,etu* t5,ens* t6,int s,int nb1,int nb2,int nb3,int nb4,int nb5,int nb6){
	int h;
	int h1,h2,h3,h4;
	livres* p1;
	articles* p2;
	magazines* p3;
	vis* p4;
	etu* p5;
	ens* p6;
	if(recherche20(s,t4,nb4)==1){
		h=ind11(s,t4,nb4);
		p4=t4+h;
		if(recherche30(p4->p1,t1,nb1)==1){
			h1=ind100(p4->p1,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p4->p1,t2,nb2)==1){
			h1=ind101(p4->p1,t2,nb2);
			p2=t2+h1;
			p2->nombre=p2->nombre+1;
		}
		else{
				h1=ind102(p4->p1,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}
	}
	else if(recherche21(s,t5,nb5)==1){
		h=ind12(s,t5,nb5);
		p5=t5+h;
		if(recherche30(p5->p1,t1,nb1)==1){
			h1=ind100(p5->p1,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p5->p1,t2,nb2)==1){
			h1=ind101(p5->p1,t2,nb2);
			p2=t2+h1;
			p2->nombre=p2->nombre+1;
		}
		else{
				h1=ind102(p5->p1,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}
		if(recherche30(p5->p2,t1,nb1)==1){
			h1=ind100(p5->p1,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p5->p2,t2,nb2)==1){
			h1=ind101(p5->p2,t2,nb2);
			p2=t2+h1;
			p2->nombre=p1->nombre+1;
		}
		else{
				h1=ind102(p5->p2,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}
	}
	else{
		h=ind13(s,t6,nb6);
			p6=t6+h;
		if(recherche30(p6->p1,t1,nb1)==1){
			h1=ind100(p6->p1,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p6->p1,t2,nb2)==1){
			h1=ind101(p6->p1,t2,nb2);
			p2=t2+h1;
			p2->nombre=p2->nombre+1;
		}
		else{
				h1=ind102(p6->p1,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}
		if(recherche30(p6->p2,t1,nb1)==1){
			h1=ind100(p6->p1,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p6->p2,t2,nb2)==1){
			h1=ind101(p6->p2,t2,nb2);
			p2=t2+h1;
			p2->nombre=p1->nombre+1;
		}
		else{
				h1=ind102(p6->p2,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}	
		if(recherche30(p6->p3,t1,nb1)==1){
			h1=ind100(p6->p3,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p6->p3,t2,nb2)==1){
			h1=ind101(p6->p3,t2,nb2);
			p2=t2+h1;
			p2->nombre=p2->nombre+1;
		}
		else{
				h1=ind102(p6->p3,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}
		if(recherche30(p6->p4,t1,nb1)==1){
			h1=ind100(p6->p4,t1,nb1);
			p1=t1+h1;
			p1->nombre=p1->nombre+1;
		}
		else if(recherche31(p6->p4,t2,nb2)==1){
			h1=ind101(p6->p4,t2,nb2);
			p2=t2+h1;
			p2->nombre=p1->nombre+1;
		}
		else{
				h1=ind102(p6->p4,t3,nb3);
			p3=t3+h1;
			p3->nombre=p3->nombre+1;
		}
	}
}
void cherche(livres* t1,articles* t2,magazines* t3,int n1,int n2,int n3){
	int pr;
	int h1,h2,h3;
	char ch[30];
	livres* p1;
	magazines* p3;
	articles* p2;
	do{
		Color(1,0);
	printf("\n veuillez selectionner le document a chercher\n");
	scanf("%s",ch);

if(recherche3(ch,t1,n1)==1){
		h1=ind1(ch,t1,n1);
		p1=t1+h1;
		printf("\n");
		printf("titre:%s",p1->titre);
		printf("code:%d\n",p1->code);
		printf("date edition:%d/%d/%d\n",p1->datedition.jours,p1->datedition.mois,p1->datedition.annee);
		printf("Localisation:%s\n",p1->localisation);
		printf("nombre de fois empruntes:%d\n",p1->nbrfoisenpruntes);
		printf("nom d'auteur:'%s\n",p1->nomauteur);
		printf("Nombre:%d\n",p1->nombre);
		printf("Nom editeur:%s\n",p1->nomediteur);
}
else if(recherche4(ch,t2,n2)==1){
		h2=ind2(ch,t2,n2);
		p2=t2+h2;
		printf("\n");
			printf("titre:%s\n",p2->titre);
		printf("code:%d\n",p2->code);
		printf("date edition:%d/%d/%d\n",p2->datepub.jours,p2->datepub.mois,p1->datedition.annee);
		printf("localisation:%s\n",p2->localisation);
		printf("nbrfoisenpruntes:%d\n",p2->nbrfoisenpruntes);
		printf("nom auteur:%s\n",p2->nomauteur);
			printf("nombre:%d\n",p2->nombre);
}
else if(recherche5(ch,t3,n3)==1){
		h3=ind3(ch,t3,n3);
		p3=t3+h3;
		printf("\n");
			printf("titre:%s",p3->titre);
		printf("code:%d",p3->code);
		printf("frequence:%d",p3->frequence);
		printf("localisation:%s",p3->localisation);
		printf("nbrfoisenpruntes:%d",p3->nbrfoisenpruntes);
		printf("nombre:%d",p3->nombre);
}
else{
	Color(4,0);
		printf("\n desole ce document n'existe pas\n");
}
	do{
		Color(1,0);
		printf("\n veuiller selectionner 1 pour continuer ou 2 pour fermer \n");
		scanf("%d",&pr);
	}while(pr==1);
	printf("\n");
	}while(pr==1);
}
void affichage(){
	Color(7,0);
	printf("\n***********************************************************************************\n");
	printf("1-Modifier Nom\n");
	printf("2-Modifier prenom\n");
	printf("3-Modifier identifiant\n");
	printf("4-Modifier adresse\n");
	printf("5-Modifier le type\n");
	printf("6-retourner au Menu\n");
}
int ind200(adherent* t,int n,int s){
	int h=0;
	adherent* p=t;
	while(p->identifiant!=s){
		p++;
		h++;
	}
	return h;
}
int ind500(listeencours* t,int n,int s){
	int h=0;
	listeencours* p=t;
		while(p->code!=s){
		p++;
		h++;
	}
	return h;
}
void modifier(adherent* t1,listeencours* t2,int nb1,int nb2,int s){
	adherent* p1=t1;
	listeencours* p2=t2;
	int h;
	int e;
	int g;
	h=ind200(t1,nb1,s);
	p1=t1+h;
	g=p1->identifiant;
	char ch[30];
	int pr,c;
	do{
		Color(10,0);
		affichage();
	do{
		Color(1,0);
			printf("\n veuillez saisir votre choix");
		scanf("%d",&pr);
	}while(pr<0||pr>6);
	if(pr==1){
	do{
		Color(1,0);
			printf("\ndonner votre nouveau Nom\n");
		scanf("%s",ch);
	}while(strcmp(ch,p1->nom)==0);
	strcpy(p1->nom,ch);
		if(recherche11(s,t2,nb2)==1){
	e=ind500(t2,nb2,s);	
		p2=t2+e;
		strcpy(p2->nom,ch);	
		}
	}
	else if(pr==2){
		do{
			Color(1,0);
			printf("\ndonner votre nouveau prenom\n");
		scanf("%s",ch);
		}while(strcmp(ch,p1->prenom)==0);
		strcpy(p1->prenom,ch);
			if(recherche11(s,t2,nb2)==1){
					e=ind500(t2,nb2,s);	
					p2=t2+e;
					strcpy(p2->prenom,ch);
			}
	}
	else if(pr==3){
		do{
			Color(1,0);
			printf("\ndonner votre nouveau identifiant");
			scanf("%d",&c);
		}while((c>99999||c<=9999)&&(p1->identifiant==c));
		p1->identifiant=c;
			if(recherche11(s,t2,nb2)==1){
					e=ind500(t2,nb2,s);	
						p2=t2+e;
						p2->code=c;
			}
	}
	else if(pr==4){
	do{
		Color(1,0);
			printf("\ndonner votre nouvelle adresse\n");
		scanf("%s",ch);
	}while(strcmp(ch,p1->adresse)==0);
	strcpy(p1->adresse,ch);
	}
	else if(pr==5){
			if(recherche11(g,t2,nb2)==1){
					Color(4,0);
				printf("\n deole vous ne pouvez pas effectuer cette tache\n");
			}
			else{
				Color(1,0);
				do{
			printf("\ndonner votre nouveau type\n");
			scanf("%s",ch);
		}while(strcmp(ch,"etudiant")!=0&&strcmp(ch,"enseignant")!=0&&strcmp(ch,"visiteur")!=0);
		strcpy(p1->type,ch);
		if(strcmp(ch,"etudiant")==0){
			p1->nbrdocuments=2;
			p1->duree=1;
		}
		else if(strcmp(ch,"enseignant")==0){
			p1->nbrdocuments=4;
			p1->duree=3;
		}
		else{
			p1->nbrdocuments=1;
			p1->duree=1;
		}	
			}
	}
	}while(pr!=6);
}
void saisir100(FILE* fp,adherent* t,int n){
adherent* p=t;
fp=fopen("lnb4.txt","w");
for(p=t;p<n+t;p++){
	fprintf(fp,"%s %s %d %s %d %d %s\n",p->nom,p->prenom,p->duree,p->adresse,p->nbrdocuments,p->identifiant,p->type);
}
fclose(fp);
}
void lire100(FILE* fp,adherent* t,int n){
int i;
fp=fopen("lnb4.txt","r");
for(i=0;i<n;i++){
	fscanf(fp,"%s %s %d %s %d %d %s\n",&t[i].nom,&t[i].prenom,&t[i].duree,&t[i].adresse,&t[i].nbrdocuments,&t[i].identifiant,&t[i].type);
}
fclose(fp);
}
void saisir101(FILE* fp,listerouge* t,int n){
	listerouge* p=t;
	fp=fopen("lnb6.txt","w");
	for(p=t;p<n+t;p++){
		fprintf(fp,"%d %d %d %d %d %s %s\n",p->d1.jours,p->d1.mois,p->d1.annee,p->code,p->nbrdocuments,p->nom,p->prenom);
	}
	fclose(fp);
}
void lire101(FILE* fp,listerouge* t,int n){
	listerouge* p=t;
	fp=fopen("lnb6.txt","r");
	for(p=t;p<n+t;p++){
		fscanf(fp,"%d %d %d %d %d %s %s\n",&(p->d1.jours),&(p->d1.mois),&(p->d1.annee),&(p->code),&(p->nbrdocuments),p->nom,p->prenom);
	}
	fclose(fp);
}
void saisir102(FILE* fp,listeencours* t,int n){
	listeencours* p=t;
	fp=fopen("lnb7.txt","w");
	for(p=t;p<n+t;p++){
		fprintf(fp,"%s %s %d %d %d %d %d %d %d %d\n",p->nom,p->prenom,p->code,p->d1.jours,p->d1.mois,p->d1.annee,p->d2.jours,p->d2.mois,p->d2.annee,p->nbrdocuments);
	}
	fclose(fp);
}
void lire102(FILE* fp,listeencours* t,int n){
		listeencours* p=t;
	fp=fopen("lnb7.txt","r");
	for(p=t;p<n+t;p++){
		fscanf(fp,"%s %s %d %d %d %d %d %d %d %d\n",(p->nom),(p->prenom),(&p->code),&(p->d1.jours),&(p->d1.mois),&(p->d1.annee),&(p->d2.jours),&(p->d2.mois),&(p->d2.annee),&(p->nbrdocuments));
	}
	fclose(fp);
}
void saisir103(FILE* fp,livres* t,int n){
	livres* p=t;
	fp=fopen("lnb1.txt","w");
	for(p=t;p<n+t;p++){
		fprintf(fp,"%s %d %s %s %d %d %d %s %d %d\n",(p->titre),&(p->code),p->nomediteur,p->nomauteur,&(p->datedition.jours),&(p->datedition.mois),&(p->datedition.annee),(p->localisation),&(p->nombre),&(p->nbrfoisenpruntes));
	}
	fclose(fp);
}
void lire103(FILE* fp,livres* t,int n){
		livres* p=t;
	fp=fopen("lnb1.txt","r");
	for(p=t;p<n+t;p++){
	fscanf(fp,"%s %d %s %s %d %d %d %s %d %d\n",(p->titre),&(p->code),p->nomediteur,p->nomauteur,&(p->datedition.jours),&(p->datedition.mois),&(p->datedition.annee),(p->localisation),&(p->nombre),&(p->nbrfoisenpruntes));
}
	fclose(fp);
}
void lire105(FILE* fp,magazines* t,int n){
	magazines* p=t;
	fp=fopen("lnb3.txt","r");
	for(p=t;p<n+t;p++){
		fscanf(fp,"%d %d %s %d %d %s\n",&(p->code),&(p->frequence),(p->localisation),&(p->nbrfoisenpruntes),&(p->nombre),(p->titre));
	}
	fclose(fp);
}
void saisir105(FILE* fp,magazines* t,int n){
	magazines* p=t;
	fp=fopen("lnb3.txt","w");
	for(p=t;p<n+t;p++){
		fprintf(fp,"%d %d %s %d %d %s\n",(p->code),(p->frequence),(p->localisation),(p->nbrfoisenpruntes),(p->nombre),(p->titre));
	}
	fclose(fp);
}
void lire104(FILE* fp,articles* t,int n){
	articles* p=t;
	fp=fopen("lnb2.txt","r");
	for(p=t;p<n+t;p++){
		fscanf(fp,"%d %d %d %d %s %d %s %d %s\n",&(p->code),&(p->datepub.jours),&(p->datepub.mois),&(p->datepub.annee),(p->localisation),&(p->nbrfoisenpruntes),(p->nomauteur),&(p->nombre),p->titre);
	}
	fclose(fp);
}
void saisir104(FILE* fp,articles* t,int n){
	articles* p=t;
	fp=fopen("lnb2.txt","w");
	for(p=t;p<n+t;p++){
		fprintf(fp,"%d %d %d %d %s %d %s %d %s\n",(p->code),(p->datepub.jours),(p->datepub.mois),(p->datepub.annee),(p->localisation),(p->nbrfoisenpruntes),(p->nomauteur),(p->nombre),p->titre);
	}
	fclose(fp);
}
void remplir_enregistrement(adherent* a,int nb4,adherent* tab4){
	Color(1,0);
	printf("donner le nom");
	scanf("%s",&(a->nom));
	printf("donner le prenom");
	scanf("%s",&(a->prenom));
		printf("donner l'adresse");
	scanf("%s",&(a->adresse));
		do{
	printf("donner l'identifiant");
	scanf("%d",&(a->identifiant));
}while((a->identifiant>99999||a->identifiant<=9999)||(recherche9(tab4,a->identifiant,nb4)==1));
do{
	printf("donner le type");
	scanf("%s",&(a->type));
}while(strcmp(a->type,"etudiant")!=0&&strcmp(a->type,"enseignant")!=0&&strcmp(a->type,"visiteur")!=0);
	acc(a->type,&(a->nbrdocuments));
	acc1(a->type,&(a->duree));
printf("la duree est %d semaines:",a->duree);
printf("le nbr de documents est: %d",a->nbrdocuments);
}
void saisir1(livres* p,livres* tab1,int nb1){
	Color(1,0);
	printf("donner le nom de l'auteur");
	scanf("%s",&(p->nomauteur));
	printf("donner le nom de l'editeur");
	scanf("%s",&(p->nomediteur));
	printf("donner le titre");
	scanf("%s",&(p->titre));
	do{
		printf("donner le code de ce livre");
	scanf("%d",&(p->code));	
	}while(recherche1000(tab1,p->code,nb1)==1);
	printf("donner le jour de la date de l'edition");
	scanf("%d",&(p->datedition.jours));
	printf("donner le mois de la date de l'edition");
	scanf("%d",&(p->datedition.mois));
	printf("donner l'annee de la date de l'edition");
	scanf("%d",&(p->datedition.annee));
		printf("donner la localisation");
	scanf("%s",&(p->localisation));
		printf("donner le nombre des  livres");
	scanf("%d",&(p->nombre));
		printf("donner le nombre de fois empruntes");
	scanf("%d",&(p->nbrfoisenpruntes));
}
void saisir2(articles* p,articles* tab2,int nb2){
	Color(1,0);
	printf("donner le nom de l'auteur ");
	scanf("%s",&(p->nomauteur));
	printf("donner le titre");
	scanf("%s",&(p->titre));
	do{
		printf("donner le code de ce livre");
	scanf("%d",&(p->code));
	}while(recherche1001(tab2,p->code,nb2)==1);
	printf("donner la localisation");
	scanf("%s",&(p->localisation));
		printf("donner le jour de la date de l'edition");
	scanf("%d",&(p->datepub.jours));
	printf("donner le mois de la date de l'edition");
	scanf("%d",&(p->datepub.mois));
	printf("donner l'annee de la date de l'edition");
	scanf("%d",&(p->datepub.annee));
		printf("donner le nombre des  livres");
	scanf("%d",&(p->nombre));
		printf("donner le nombre de fois empruntes");
	scanf("%d",&(p->nbrfoisenpruntes));
}
void saisir3(magazines* p,magazines* tab3,int nb3 ){
	Color(1,0);
	do{
		printf("donner le code");
	scanf("%d",&(p->code));
	}while(recherche1002(tab3,p->code,nb3)==1);
	printf("donner la frequence");
	scanf("%d",&(p->frequence));
	printf("donner le titre");
	scanf("%s",p->titre);
	printf("donner la localisation");
	scanf("%s",(p->localisation));
		printf("donner le nombre des  livres");
	scanf("%d",&(p->nombre));
		printf("donner le nombre de fois empruntes");
	scanf("%d",&(p->nbrfoisenpruntes));
}
int main(){
	date d;
	date d1;
	int s;
	int nb;
	listerouge m;
	listeencours t;
  livres tab1[100];
articles  tab2[100];
magazines tab3[100];
adherent tab4[100];
nb_emprunt  tab5[100];
listerouge tab6[100];
listeencours tab7[100];
vis tab8[100];
etu tab9[100];
ens tab10[100];
int nb8=1;
int nb9=1;
int nb10=1;
int rep,nb1;
int nb2;
int nb3;
int n,g;
int e;
int nb5;
int nb6 ;
int nb7;
int k;
adherent a;
listerouge u;
char ch[30];
nb2=nb1;
nb3=nb1;
int nb4=nb1;
livres p;
articles f;
magazines h;
listeencours* y;
FILE* lnb1;
FILE* lnb2;
FILE* lnb3;
FILE*  lnb4;
FILE* lnb5;
FILE* lnb6;
FILE* lnb7;
FILE* hlnb1;
FILE* hlnb2;
FILE* hlnb3;
FILE*  hlnb4;
FILE* hlnb5;
FILE* hlnb6;
FILE* hlnb7;
time_t now;
	time(&now);
	struct tm* local=localtime(&now);
	d.jours=local->tm_mday;
	d.mois=local->tm_mon+1;
	d.annee=local->tm_year+1900;
do{
	for(y=tab7;y<tab7+nb7;y++){
		if(compdate(&d,&(y->d1))==0){
			ajouter5(tab6,&nb6,y);
		}
	}
	do{
miseenpage1(&d);
printf("\n\n");
do{
	Color(1,0);
printf("veuiller saisir votre choix");
scanf("%d",&g);
}while(g<=0||g>16);
if(g==4){
	hlnb1=fopen("hlnb1.txt","r");
	fscanf(hlnb1,"%d",&nb1);
	fclose(hlnb1);
	lire103(lnb1,tab1,nb1);
	saisir1(&p,tab1,nb1);
	ajouter8(tab1,&nb1,&p);
	lnb1=fopen("hlnb1.txt","w");
	fprintf(hlnb1,"%d",nb1);
fclose(hlnb1);
saisir103(lnb1,tab1,nb1);
}
else if(g==5){
	hlnb2=fopen("hlnb2.txt","r");
	fscanf(hlnb2,"%d",&nb2);
	fclose(hlnb2);
	lire104(lnb2,tab2,nb2);
	saisir2(&f,tab2,nb2);
	ajouter9(tab2,&nb2,&f);
		hlnb2=fopen("hlnb2.txt","w");
		fprintf(hlnb2,"%d",nb2);
		fclose(hlnb2);
		saisir104(lnb2,tab2,nb2);
}
else if(g==6){
		hlnb3=fopen("hlnb3.txt","r");
	fscanf(hlnb3,"%d",&nb3);
	fclose(hlnb3);
	lire105(lnb3,tab3,nb3);
	saisir3(&h,tab3,nb3);
	ajouter10(tab3,&nb3,&h);
	hlnb3=fopen("hlnb3.txt","w");
	fprintf(hlnb3,"%d",nb3);
	fclose(hlnb3);
	saisir105(lnb3,tab3,nb3);
}
else if(g==10){
	printf("\n\n");
	hlnb1=fopen("hlnb1.txt","r");
	fscanf(hlnb1,"%d",&nb1);
	fclose(hlnb1);
	lire103(lnb1,tab1,nb1);
affichagetabenregistrement1(tab1,nb1);
printf("\n\n");
}
else if(g==11){
	printf("\n\n");
	hlnb2=fopen("hlnb2.txt","r");
	fscanf(hlnb2,"%d",&nb2);
	fclose(hlnb2);
	lire104(lnb2,tab2,nb2);
affichagetabenregistrement2(tab2,nb2);
printf("\n\n");
}
else if(g==12){
	hlnb3=fopen("hlnb3.txt","r");
	fscanf(hlnb3,"%d",&nb3);
	fclose(hlnb3);
	lire105(lnb3,tab3,nb3);
	printf("\n\n");
affichagetabenregistrement3(tab3,nb3);
printf("\n\n");
}
else if(g==7){
	Color(2,0);
	hlnb4=fopen("hlnb4.txt","r");
	fscanf(hlnb4,"%d",&nb4);
	fclose(hlnb4);
	lire100(lnb4,tab4,nb4);
affichagetabenregistrement0(tab4,nb4);
printf("\n\n");
}
else if(g==1){
	hlnb4=fopen("hlnb4.txt","a");
	fclose(hlnb4);
		hlnb4=fopen("hlnb4.txt","r");
		fscanf(hlnb4,"%d",&nb4);
		fclose(hlnb4);
	lire100(lnb1,tab4,nb4);
	remplir_enregistrement(&a,nb4,tab4);
	ajouter2(tab4,&a,&nb4);
	hlnb4=fopen("hlnb4.txt","w");
	fprintf(hlnb4,"%d",nb4);
	fclose(hlnb4);
	saisir100(lnb1,tab4,nb4);
}
else if(g==8){
	Color(2,0);
	hlnb7=fopen("hlnb7.txt","r");
	fscanf(hlnb7,"%d",&nb7);
	fclose(hlnb7);
	lire102(lnb7,tab7,nb7);
	printf("\n");
	aff_enr6(tab7,nb7);
	printf("\n\n");
}
else if(g==9){
	printf("\n");
	hlnb6=fopen("hlnb6.txt","r");
	fscanf(hlnb6,"%d",&nb6);
	fclose(hlnb6);
	lire101(lnb6,tab6,nb6);
	aff_enr5(tab6,nb6);
	printf("\n\n");
}
else if(g==2){
printf("\n");
	hlnb4=fopen("hlnb4.txt","r");
		fscanf(hlnb4,"%d",&nb4);
		fclose(hlnb4);
			lire100(lnb1,tab4,nb4);
			hlnb7=fopen("hlnb7.txt","a");
			fclose(hlnb7);
			hlnb7=fopen("hlnb7.txt","r");
			fscanf(hlnb7,"%d",&nb7);
			fclose(hlnb7);
			lire102(lnb7,tab7,nb7);
	hlnb3=fopen("hlnb3.txt","r");
	fscanf(hlnb3,"%d",&nb3);
	fclose(hlnb3);
	hlnb2=fopen("hlnb2.txt","r");
	fscanf(hlnb2,"%d",&nb2);
	fclose(hlnb2);
	hlnb1=fopen("hlnb1.txt","r");
	fscanf(hlnb1,"%d",&nb1);
	fclose(hlnb1);
	lire103(lnb1,tab1,nb1);
	lire104(lnb2,tab2,nb2);
	lire105(lnb3,tab3,nb3);
do{
	Color(1,0);
	printf("donner votre code");
	scanf("%d",&s);
}while(s>99999||s<9999);	
if(recherche9(tab4,s,nb4)==0){
	Color(4,0);
	printf("\n desole monsieur vous devez incrire tout d'abord pour pouvoir effectuer cette tache");
}
else{
	if(recherche2(tab7,s,nb7)==1){
		Color(4,0);
		printf("\n desole monsieur il faut d'abord rendre les documents que vous avez emprunté");
	}
	else{
		e=0;
		find(tab4,s,&a);
		acc(a.type,&nb);
		int* gh;
		int* m;
		gh=(int*)malloc((nb+1)*sizeof(int));
		m=gh;
		*m=a.identifiant;
		m++;
		do{
		emprunter(tab1,tab2,tab3,nb1,nb2,nb3,&k);
		e=e+1;	
		*m=k;
		m++;
		}while(e<nb);
		date_derendre(&t,&d,&a);
		lef(&a,&t);
	ajouter6(tab7,&nb7,&t,&d);
	if(nb==1){
		 ajouter13(gh,tab8,&nb8);
	}
	else if(nb==2){
		ajouter14(gh,tab9,&nb9);
	}
	else{
		ajouter15(gh,tab10,&nb10);
	}
	free(gh);	
	}
}
hlnb7=fopen("hlnb7.txt","w");
fprintf(hlnb7,"%d",nb7);
fclose(hlnb7);
saisir102(lnb7,tab7,nb7);
hlnb1=fopen("hlnb1.txt","w");
hlnb2=fopen("hlnb2.txt","w");
hlnb3=fopen("hlnb3.txt","w");
fprintf(hlnb1,"%d",nb1);
fprintf(hlnb2,"%d",nb2);
fprintf(hlnb3,"%d",nb3);
fclose(hlnb1);
fclose(hlnb2);
fclose(hlnb3);
saisir103(lnb1,tab1,nb1);
saisir104(lnb2,tab2,nb2);
saisir105(lnb3,tab3,nb3);
}
else if(g==13){
		hlnb4=fopen("hlnb4.txt","r");
		fscanf(hlnb4,"%d",&nb4);
		fclose(hlnb4);
			lire100(lnb4,tab4,nb4);
	do{
		Color(1,0);
	printf("donner votre code");
	scanf("%d",&s);
}while(s>99999||s<9999);
if(recherche9(tab4,s,nb4)==0){
	Color(4,0);
	printf("\n desole monsieur vous n'etes pas inscrit\n");
}
else{
	if(recherche2(tab7,s,nb7)==1){
		Color(4,0);
			printf("\n vous ne pouvez pas effectuer cette tache\n");
	}
	else{
		supp1(tab4,&nb4,s);
			hlnb4=fopen("hlnb4.txt","w");
	fprintf(hlnb4,"%d",nb4);
	fclose(hlnb4);
	saisir100(lnb4,tab4,nb4);
	}
}
}
else if(g==3){
	printf("\n");
	hlnb4=fopen("hlnb4.txt","r");
		fscanf(hlnb4,"%d",&nb4);
		fclose(hlnb4);
			lire100(lnb1,tab4,nb4);
			hlnb7=fopen("hlnb7.txt","a");
			fclose(hlnb7);
			hlnb7=fopen("hlnb7.txt","r");
			fscanf(hlnb7,"%d",&nb7);
			fclose(hlnb7);
			lire102(lnb7,tab7,nb7);
	hlnb3=fopen("hlnb3.txt","r");
	fscanf(hlnb3,"%d",&nb3);
	fclose(hlnb3);
	hlnb2=fopen("hlnb2.txt","r");
	fscanf(hlnb2,"%d",&nb2);
	fclose(hlnb2);
	hlnb1=fopen("hlnb1.txt","r");
	fscanf(hlnb1,"%d",&nb1);
	fclose(hlnb1);
	lire103(lnb1,tab1,nb1);
	lire104(lnb2,tab2,nb2);
	lire105(lnb3,tab3,nb3);
do{
	printf("donner votre code");
	scanf("%d",&s);
}while(s>99999||s<9999);
if(recherche9(tab4,s,nb4)==0){
	Color(4,0);
	printf("\n desole monsieur vous n'etes pas inscrit\n");
}
else{
	if(recherche11(s,tab7,nb7)==0){
		Color(4,0);
		printf("\n vous ne pouvez pas effectuer cette tache\n");
	}
	else{
		rendre(tab1,tab2,tab3,tab8,tab9,tab10,s,nb1,nb2,nb3,nb8,nb9,nb10);
	if(recherche11(s,tab7,nb7)==1){
	supplisteencours(tab7,&nb7,s);	
	}
	if(recherche1(tab6,s,nb6)==1){
		supplisterouge(tab6,&nb6,s);
	}	
	}
}
hlnb7=fopen("hlnb7.txt","w");
fprintf(hlnb7,"%d",nb7);
fclose(hlnb7);
saisir102(lnb7,tab7,nb7);
hlnb1=fopen("hlnb1.txt","w");
hlnb2=fopen("hlnb2.txt","w");
hlnb3=fopen("hlnb3.txt","w");
fprintf(hlnb1,"%d",nb1);
fprintf(hlnb2,"%d",nb2);
fprintf(hlnb3,"%d",nb3);
fclose(hlnb1);
fclose(hlnb2);
fclose(hlnb3);
saisir103(lnb1,tab1,nb1);
saisir104(lnb2,tab2,nb2);
saisir105(lnb3,tab3,nb3);
}
else if(g==14){
		hlnb3=fopen("hlnb3.txt","r");
	fscanf(hlnb3,"%d",&nb3);
	fclose(hlnb3);
	lire105(lnb3,tab3,nb3);
		hlnb2=fopen("hlnb2.txt","r");
	fscanf(hlnb2,"%d",&nb2);
	fclose(hlnb2);
	lire104(lnb2,tab2,nb2);
		hlnb1=fopen("hlnb1.txt","r");
	fscanf(hlnb1,"%d",&nb1);
	fclose(hlnb1);
	lire103(lnb1,tab1,nb1);
	cherche(tab1,tab2,tab3,nb1,nb2,nb3);
}
else if(g==15){
	hlnb4=fopen("hlnb4.txt","r");
		fscanf(hlnb4,"%d",&nb4);
		fclose(hlnb4);
			lire100(lnb4,tab4,nb4);
			hlnb7=fopen("hlnb7.txt","r");
			fscanf(hlnb7,"%d",&nb7);
			fclose(hlnb7);
		lire102(lnb7,tab7,nb7);	
	do{
	printf("donner votre code");
	scanf("%d",&s);
}while(s>99999||s<9999);
if(recherche9(tab4,s,nb4)==0){
	printf("\n desole monsieur vous n'etes pas inscrit\n");
}
else{
	if(recherche1(tab6,s,nb6)==1){
		Color(4,0);
	printf("\nvous ne pouvez pas effectuer cette tache\n");	
	}
	else{
		Color(2,0);
	modifier(tab4,tab7,nb4,nb7,s);	
	}				
}	
				hlnb4=fopen("hlnb4.txt","w");
		fprintf(hlnb4,"%d",nb4);
		fclose(hlnb4);
		saisir100(lnb4,tab4,nb4);
			hlnb7=fopen("hlnb7.txt","w");
			fprintf(hlnb7,"%d",nb7);
			fclose(hlnb7);
	saisir102(lnb7,tab7,nb7);	
}
printf("\n\n");
}while(g!=16);
 ajouterunjour(&d);
 do{
  printf("est ce que vous vouler continuer le jour suivant si oui taper 1 sinon taper 0 ");
  scanf("%d",&rep);
}while(rep>1);
}while(rep==1);
//sasienregi(&d);
     return 0;
}
