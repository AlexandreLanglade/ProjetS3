/*
Module pour l'étude d'un système que définira l'utilisateur
*/

#ifndef POLONAIS_H
#define POLONAIS_H

#include "coord.h"
#include "entree.h"
#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init(int , double* , coord* ,char* );
void parametres(int , double *, coord*, double* );
double calcul_position(int , double* , double , double );
void algo_polonais();

#endif