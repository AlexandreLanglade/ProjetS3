#include "../include/lorentz.h"
#include "../include/rossler.h"
#include "../include/entree.h"
#include "../include/polonais.h"
#include "../include/tracer.h"
#include <stdio.h>


int
main(int argc, char * argv[])
{
	// Choix du système

	int choix;
	printf("Système ?\n(1)Lorenz (2)Rossler (3)Equations personnalisées\n");
	scanf("%d",&choix);

	if(choix==1){
		algo_lorentz();
	}
	else if(choix == 2){
		algo_rossler();
	}
	else if(choix == 3){
		algo_polonais();
	}

	printf("Done.\n");

	// Choix d'afficher le Gnuplot ou non

	int choix_gnup1;
	printf("Afficher la courbe ? (1)pour oui (2)pour non : ");
	scanf("%d",&choix_gnup1);
	if(choix_gnup1==1){

		// Choix d'afficher la couleur ou non

		int choix_gnup2;
		printf("Couleur en fonction du temps ? (1)pour oui (2)pour non : ");
		scanf("%d",&choix_gnup2);
		gnuplot_ctrl * h;
		h = gnuplot_init();
		gnuplot_cmd(h,"set parametric");

		// Avec couleur

		if(choix_gnup2==1){
			gnuplot_cmd(h,"rgb(r,g,b) = 1000000*int(r) + 1000000*int(g) + 1000000*int(b)");
			gnuplot_cmd(h,"splot \"positions.dat\" u 2:3:4:(rgb($1,$1,$1)) with points lc rgb variable");
		}

		// Sans couleur
		
		else{
			gnuplot_cmd(h,"splot \"positions.dat\" u 2:3:4");
		}

		// Retenir la fermeture de gnuplot

		printf("N'importe quel chiffre pour fermer : ");
		scanf("%d",&choix_gnup1);
		gnuplot_close(h);
	}

	return 0;
}
