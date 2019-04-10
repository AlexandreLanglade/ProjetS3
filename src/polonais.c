#include "../include/polonais.h"

// Initialisation des équations
void
init(int taille_equation, double *equation, coord *position, char *chaine)
{
    int i;
    for(i = 0; i < taille_equation;  i ++){
        if(chaine[i] == '*'){
            equation[i] = (int)'*';
        }else if(chaine[i] == '/'){
            equation[i] = (int)'/';
        }else if(chaine[i] == '+'){
            equation[i] = (int)'+';
        }else if(chaine[i] == '-'){
            equation[i] = (int)'-';
        }else if(chaine[i] == 'x'){
            equation[i] = position->x;
        }else if(chaine[i] == 'y'){
            equation[i] = position->y;
        }else if(chaine[i] == 'z'){
            equation[i] = position->z;
        }else{
            printf("parametre = ");
            equation[i] = lire_double();
        }
    }
}

// Paramétrage
void
parametres(int taille_equation, double *equation, coord *position, double *pos)
{
    int i;
    for(i = 0; i < taille_equation; i++)
    {
        if(equation[i] == pos[0]){
            equation[i] = position->x;
        }else if(equation[i] == pos[1]){
            equation[i] = position->y;
        }else if(equation[i] == pos[2]){
            equation[i] = position->z;
        }
    }
}

// Calculer la nouvelle position
double
calcul_position(int taille_equation, double *equation, double pos_coor, double dt)
{
    int i, k;
    double *var;
    var = malloc(taille_equation*sizeof(double));
    for(i = 0; i < taille_equation; i++){
        var[i] = 0;
    }
    var[0] = equation[0];
    for(i = 0; i < taille_equation; i++){
        if(equation[i] == '*'){
            var[0] = var[0] * var[1];
            for(k = 2; k < taille_equation; k++){
                var[k-1] = var[k];
            }
        }else if(equation[i] == '/'){
            var[0] = var[0] / var[1];
            for(k = 2; k < taille_equation; k++){
                var[k-1] = var[k];
            }
        }else if(equation[i] == '+'){
            var[0] = var[0] + var[1];
            for(k = 2; k < taille_equation; k++){
                var[k-1] = var[k];
            }
        }else if(equation[i] == '-'){
            var[0] = var[0] - var[1];
            for(k = 2; k < taille_equation; k++){
                var[k-1] = var[k];
            }
        }else{
            k = 0;
            for(k = taille_equation-1; k > 0; k--){
                var[k] = var[k-1];
            }
            var[0] = (double)equation[i];
        }
    }
    pos_coor += var[0]*dt;
    return pos_coor;
}

// Déroulement de l'algorithme principal
void
algo_polonais()
{
    clean_fich();
    double t, dt;
    char chaine1[100];
    char chaine2[100];
    char chaine3[100];
    double pos[3];
    printf("Xinit : ");
    pos[0] = lire_double();
    printf("Yinit : ");
    pos[1] = lire_double();
    printf("Zinit : ");
    pos[2] = lire_double();
    coord position = new_coord(pos[0], pos[1], pos[2]);
    printf("Tmax : ");
    t = lire_double();
    printf("dt : ");
    dt = lire_double();
    double i;
    int taille_equation[3];
    for(i = 0; i < 3; i++){
        taille_equation[(int)i] = 0;
    }
    printf("dx/dt = ");
    scanf("%s", chaine1);
    printf("dy/dt = ");
    scanf("%s", chaine2);
    printf("dz/dt = ");
    scanf("%s", chaine3);
    taille_equation[0] = strlen(chaine1);
    taille_equation[1] = strlen(chaine2);
    taille_equation[2] = strlen(chaine3);

    double *equation_dx = NULL;
    double *equation_dy = NULL;
    double *equation_dz = NULL;
    equation_dx = malloc(taille_equation[0] * sizeof(double));
    equation_dy = malloc(taille_equation[1] * sizeof(double));
    equation_dz = malloc(taille_equation[2] * sizeof(double));
    add(0, &position);
    init(taille_equation[0], equation_dx, &position, chaine1);
    init(taille_equation[1], equation_dy, &position, chaine2);
    init(taille_equation[2], equation_dz, &position, chaine3);

    for(i = 0; i <= t; i += dt){
        parametres(taille_equation[0], equation_dx, &position, pos);
        parametres(taille_equation[1], equation_dy, &position, pos);
        parametres(taille_equation[2], equation_dz, &position, pos);
        pos[0] = position.x;
        pos[1] = position.y;
        pos[2] = position.z;
        position.x = calcul_position(taille_equation[0], equation_dx, position.x, dt);
        position.y = calcul_position(taille_equation[1], equation_dy, position.y, dt);
        position.z = calcul_position(taille_equation[2], equation_dz, position.z, dt);
        add(dt*i*100+dt, &position);
    }
    free(equation_dx);
    free(equation_dy);
    free(equation_dz);
}