#include "../include/lorentz.h"

// Initialiser les paramètres du système de Lorenz
void
param(double * parametre, coord * position)
{
	char noms[5][6] = {"Sigma","Rho","Beta","Tmax","dt"};
	int i;
	for(i=0;i<5;i++){
		printf("%s : ", noms+i);
		*(parametre+i)=lire_double();		
	}
	

	printf("Xinit : ");
	position->x=lire_double();
	printf("Yinit : ");
	position->y=lire_double();
	printf("Zinit : ");
	position->z=lire_double();
}

// Calculer la nouvelle position pour une incrémentation de dt
void
calcul(double * parametre, coord * position)
{
	double tempx = position->x;
	double tempy = position->y;
	double tempz = position->z;

	position->x = tempx + ( *(parametre+0) * ( tempy - tempx ) ) * *(parametre+4) ;
	position->y = tempy + ( tempx * ( *(parametre+1) - tempz ) -tempy ) * *(parametre+4) ;
	position->z = tempz + ( tempx * tempy - *(parametre+2) * tempz ) * *(parametre+4) ;
}

// Gère le déroulement de l'algorithme pour un système de Lorenz
void
algo_lorentz()
{
	clean_fich();
	coord position;
	double parametre[5];
	param(parametre, &position);
	double j;
	for(j=0;j<(*(parametre+3));j+=(*(parametre+4))){
		add(j,&position);
		calcul(parametre, &position);	
	}
	add(*(parametre+3),&position);
}
