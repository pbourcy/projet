#ifndef BACKTRACK_H
#define BACKTRACK_H

int backtrack ( int prof ) ;
int Max( int tmp , int prof , PointTuple CoupPossible ) ;
int Min( int tmp , int prof , PointTuple CoupPossible ) ;
int evaluation ( int camp , int pionsRentreAI , int pionsRentreJoueur ) ;

#endif