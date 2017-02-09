CC=gcc                    # Nom de compilater.

# Les fichiers à compiler.
MAIN=main
VAR=var
JEUX=jeux
REGLE=regle
AFFICHAGE=affichage
BACKTRACK=backtrack

all: ${BACKTRACK} ${AFFICHAGE}.o ${REGLE}.o ${JEUX}.o ${MAIN}.o
	${CC} -o ${VAR} ${MAIN}.o ${JEUX}.o ${REGLE}.o ${AFFICHAGE}.o


${MAIN}.o: ${MAIN}.c
	${CC} -o ${MAIN}.o -c ${MAIN}.c

${JEUX}.o: ${JEUX}.c
	${CC} -o ${JEUX}.o -c ${JEUX}.c

${REGLE}.o: ${REGLE}.c
	${CC} -o ${REGLE}.o -c ${REGLE}.c

${AFFICHAGE}.o: ${AFFICHAGE}.c
	${CC} -o ${AFFICHAGE}.o -c ${AFFICHAGE}.c

${BACKTRACK}.o: ${BACKTRACK}.c
	${CC} -o ${BACKTRACK}.o -c ${BACKTRACK}.c

clean:
	rm *.o
