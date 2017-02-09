#define TRUE 1 

/***************************************/

#include <math.h>
#include <stdio.h>

/***************************************/

#include "affichage.h"
#include "regle.h"
#include "jeux.h"
#include "vah.h"

/***************************************/

int camp ;
int *echiquier ;
int pionsRentreAI ;
int pionsRentreJoueur ;

int play( Tuple Coup , int camp )
{
	if ( Coup.arrive > 24 )
		pionsRentreJoueur = pionsRentreJoueur + 1 ;
	else if ( Coup.arrive < 0 ) 
		pionsRentreAI = pionsRentreAI + 1 ;
	echiquier[Coup.depart] = echiquier[Coup.depart] - camp ;
	if(echiquier[Coup.arrive] != 0 )
		echiquier[Coup.arrive] = camp ;
	echiquier[Coup.arrive] = echiquier[Coup.arrive] + camp ;
	return * echiquier ;
}

int deplay( Tuple Coup , int camp )
{
	if ( Coup.arrive > 24 )
		pionsRentreJoueur = pionsRentreJoueur - 1 ;
	else if ( Coup.arrive < 0 ) 
		pionsRentreAI = pionsRentreAI - 1 ;
	echiquier[Coup.depart] = echiquier[Coup.depart] + camp ;
	if(echiquier[Coup.arrive] != 0 )
		echiquier[Coup.arrive] = camp ;
	echiquier[Coup.arrive] = echiquier[Coup.arrive] - camp ;
	return * echiquier ;
}

Tuple coupJoueur( int de1 , int de2 , int deJoue ) 
{
	int i , k , l , j = 15 ;
	int x , de ; 

	PointTuple CoupPossibleDe1 = Jouable( de1 , j ) ; 
	PointTuple CoupPossibleDe2 = Jouable( de2 , j ) ;

	int departi , arrivei ; 

	if( deJoue == 0 ) 
	{
		l = 30 ;
		PointTuple CoupPossible = tableauTuple( 30 ) ;
		for( k = 1 ; k < 31 ; k++ )
			{
			if ( k >= 16 ) CoupPossible[ k ] = CoupPossibleDe2[ k ] ;
			else CoupPossible[ k ] = CoupPossibleDe1[ k - 15 ] ;
			}
		for( i = 0 ; i < l+1 ; i++ ) 
		{
			departi = CoupPossible[i].depart ;
			arrivei = CoupPossible[i].arrive ;
			printf("N°%i - Case depart : %i et case d'arrive : %i", i , departi , arrivei ) ;
		}

		while(TRUE) 
		{
			scanf("Entrer le numero du coup que vous voulez jouer %i", &x ) ; 
			if ((x > 0) && (i > x))
			{
				printf(" Coup valide ") ;
				return CoupPossible[x] ;
			}
			printf(" Coup invalide, recommencez " ) ;
		}
	}
	else 
	{

		l = 15 ;
		PointTuple CoupPossible = tableauTuple( 15 ) ; 
		if( deJoue == de1 ) 
		{
			de = de2 ;
			CoupPossible = CoupPossibleDe2 ;
		}
		else 
		{
			de = de1 ; 
			CoupPossible = CoupPossibleDe1 ;
		}
		for( i = 0 ; i < l+1 ; i++ ) 
		{
			departi = CoupPossible[i].depart ;
			arrivei = CoupPossible[i].arrive ;
			printf("N°%i - Case depart : %i et case d'arrive : %i", i , departi , arrivei ) ;
		}

		while(TRUE) //define TRUE 1 
		{
			scanf("Entrer le numero du coup que vous voulez jouer %i", &x ) ; 
			if ((x > 0) && (i > x))
			{
				printf(" Coup valide ") ;
				return CoupPossible[x] ;
			}
			printf(" Coup invalide, recommencez " ) ;
		}
	}
}
