#include <math.h>

/***************************************/

#include "affichage.h"
#include "regle.h"
#include "vah.h"

/***************************************/

int camp ;
int *echiquier ;
int pionsMortJoueur ;
int pionsMortAI ;
int pionsRentreAI ;
int pionsRentreJoueur ;

int deplacement_possible( int de , int i , int camp ) {
	if ( echiquier[i+de] >= camp || i + de <= 24 ) {
		return 1 ;
	}
	return 0 ;
}

int conditionPhaseFinal( void ) {
	int i ;
	while ( i <= 18 && echiquier[i] >= 1 )
	{
		i = i + 1 ; 
		if ( i >= 18 ) return( 1 ) ;
	}
	return( 0 ) ;
}

int conditionVictoire( int pionsRentreAI , int pionsRentreJoueur , int camp ) 
{
	if ( pionsRentreJoueur == 15 ) 
		return( 1 ) ;
	else if ( pionsRentreAI == 15 ) 
		return( 0 ) ;
	else return( -1 ) ;
}

PointTuple Jouable( int de , int j ) //CP = coup possible
{
	PointTuple CoupPossible = tableauTuple( j ) ; //j = 15 trés souvent
	int camp = 1 ; 
	int i , a ;
	if ( pionsMortJoueur >= 1 && pionsMortAI )
	{
			i = 1 ; 
			int a = deplacement_possible( de, i, 1 ) ; 
			if ( a == 1 ) 
			{
				if (camp == 1) //joueur
				{
					CoupPossible[0].depart = 0 ;
					CoupPossible[0].arrive = i + de ; //y'a un truc qui va pas avec le cp.int2val
				}
				else // l'ia psk -1 
				{
					CoupPossible[0].depart = 25 ;
					CoupPossible[0].arrive = 25 - i - de ;
				}
			}
	}
	else 
	{
		for( i = 1 ; i<25 ; i++ ) 
		{
			if ( (echiquier[ i + 1 ] > 0) || (camp == 1) )  //joueur
			{
				a = deplacement_possible ( de , i, 1 ) ; //faut remplacer le 1 et -1 par qqchose
				if ( a == 1 ) 
					{
						CoupPossible[i].depart = i ;
						CoupPossible[i].arrive = i + de ;	
					}
			}
			else if ((echiquier[ i + 1 ] < 0) || (camp == - 1) )
			{
				a = deplacement_possible ( de , i, -1 ) ; 
				if ( a == -1 ) 
				{
					CoupPossible[i].depart = 25 - i ;
					CoupPossible[i].arrive = 25 - i - de ;	
				}
			}
		}
	}
	return CoupPossible ;
}