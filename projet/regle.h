#ifndef REGLE_H
#define REGLE_H

int deplacement_possible( int de , int i , int camp ) ;
int conditionPhaseFinal( void ) ;
int conditionVictoire( int pionsRentreAI , int pionsRentreJoueur , int camp ) ;
PointTuple Jouable( int de , int j ) ;

#endif