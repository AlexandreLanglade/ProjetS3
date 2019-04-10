/*
Définition de la struct coord et fonctions associées
*/

#ifndef COORD_H
#define COORD_H

struct coord_s{
	double x;
	double y;
	double z;
};


typedef struct coord_s coord;

coord new_coord(double a, double b, double c);

#endif
