#include "../include/fichier.h"

// Réinitialiser le fichier de data pour qu'il soit vide
void
clean_fich()
{
	FILE* fichier = NULL;
	fichier = fopen("positions.dat","w+");

	fclose(fichier);
}

// Ajouter une position à un moment donné au fichier de data
void 
add(double temps, coord * position)
{
	FILE* fichier = NULL;
	fichier = fopen("positions.dat","a");

	fprintf(fichier,"%lf %lf %lf %lf\n",temps,position->x,position->y,position->z);

	fclose(fichier);
	
}

