/*
Module pour l'étude d'un système de Lorenz
*/

#ifndef LORENTZ_H
#define LORENTZ_H

#include "coord.h"
#include "entree.h"
#include "fichier.h"
#include <stdio.h>

void param(double * parametre, coord * position);

void calcul(double * parametre, coord * position);

void algo_lorentz();

#endif