/*
Gère les intermédiaires entre le programme C et le fichier de data
*/

#ifndef FICHIER_H
#define FICHIER_H

#include <stdlib.h>
#include <stdio.h>
#include "../include/coord.h"

void add(double temps, coord * position);
void clean_fich();

#endif
