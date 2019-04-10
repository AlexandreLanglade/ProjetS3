bin/principal : src/principal.c lib/libentree.a lib/liblorentz.a lib/libcoord.a lib/libfichier.a lib/libpolonais.a lib/librossler.a lib/libtracer.a
	gcc -o bin/principal src/principal.c -I include -L lib -llorentz -lfichier -lpolonais -lrossler -ltracer -lentree -lcoord

lib/libtracer.a : lib/tracer.o
	ar rcs lib/libtracer.a lib/tracer.o

lib/librossler.a : lib/rossler.o
	ar rcs lib/librossler.a lib/rossler.o

lib/liblorentz.a : lib/lorentz.o
	ar rcs lib/liblorentz.a lib/lorentz.o

lib/libfichier.a : lib/fichier.o
	ar rcs lib/libfichier.a lib/fichier.o

lib/libpolonais.a : lib/polonais.o
	ar rcs lib/libpolonais.a lib/polonais.o

lib/libentree.a : lib/entree.o
	ar rcs lib/libentree.a lib/entree.o

lib/libcoord.a : lib/coord.o
	ar rcs lib/libcoord.a lib/coord.o

lib/tracer.o : src/tracer.c
	gcc -c src/tracer.c -o lib/tracer.o

lib/fichier.o : src/fichier.c
	gcc -c src/fichier.c -o lib/fichier.o

lib/lorentz.o : src/lorentz.c
	gcc -c src/lorentz.c -o lib/lorentz.o

lib/polonais.o : src/polonais.c
	gcc -c src/polonais.c -o lib/polonais.o

lib/rossler.o : src/rossler.c
	gcc -c src/rossler.c -o lib/rossler.o

lib/entree.o : src/entree.c
	gcc -c src/entree.c -o lib/entree.o

lib/coord.o : src/coord.c
	gcc -c src/coord.c -o lib/coord.o