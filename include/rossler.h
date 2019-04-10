/*
Module pour l'étude d'un système de Rossler
*/

#ifndef ROSSLER_H
#define ROSSLER_H

#include "../include/coord.h"
#include "../include/entree.h"
#include "../include/fichier.h"
#include <stdio.h>

void param_ross(double * parametre, coord * position);

void calcul_ross(double * parametre, coord * position);

void algo_rossler();

#endif