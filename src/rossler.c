#include "../include/rossler.h"

// Initialiser les paramètres du système de Rossler
void
param_ross(double * parametre, coord * position)
{
	char noms[5][5] = {"a","b","c","Tmax","dt"};
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
calcul_ross(double * parametre, coord * position)
{
	double tempx = position->x;
	double tempy = position->y;
	double tempz = position->z;

	position->x = tempx + ((-tempy-tempz) * *(parametre+4));
	position->y = tempy + ((tempx+*(parametre+0)*tempy)**(parametre+4));
	position->z = tempz + ((*(parametre+1)+tempz*(tempx-*(parametre+2)))**(parametre+4));
}

// Gère le déroulement de l'algorithme pour un système de Rossler
void
algo_rossler()
{
	clean_fich();
	coord position;
	double parametre[5];
	param_ross(parametre, &position);
	double j;
	for(j=0;j<(*(parametre+3));j+=(*(parametre+4))){
		add(j,&position);
		calcul_ross(parametre, &position);	
	}
	add(*(parametre+3),&position);
}
