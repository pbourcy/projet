CC=gcc                    # Nom de compilater.

# Les fichiers à compiler.
MAIN=main
VAR=var
JEUX=jeux
REGLE=regle
AFFICHAGE=affichage
BACKTRACK=backtrack

# all construit l'executable final et exige que MAIN soit faite.
all: ${BACKTRACK} ${AFFICHAGE}.o ${REGLE}.o ${JEUX}.o ${MAIN}.o
	${CC} -o ${VAR} ${MAIN}.o ${JEUX}.o ${REGLE}.o ${AFFICHAGE}.o

# MAIN compile le main.c et créer un fichier objet main.o, il pourra être
# linké dans all.
${MAIN}.o: ${MAIN}.c
	${CC} -o ${MAIN}.o -c ${MAIN}.c

# Idem mais avec JEUX.
${JEUX}.o: ${JEUX}.c
	${CC} -o ${JEUX}.o -c ${JEUX}.c

# Tu as compris...
${REGLE}.o: ${REGLE}.c
	${CC} -o ${REGLE}.o -c ${REGLE}.c

${AFFICHAGE}.o: ${AFFICHAGE}.c
	${CC} -o ${AFFICHAGE}.o -c ${AFFICHAGE}.c

${BACKTRACK}.o: ${BACKTRACK}.c
	${CC} -o ${BACKTRACK}.o -c ${BACKTRACK}.c

# Virer les fichiers .o.
clean:
	rm *.o
