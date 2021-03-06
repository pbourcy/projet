#include <math.h>

/***************************************/

#include "backtrack.h"
#include "regle.h"
#include "affichage.h"
#include "jeux.h"
#include "vah.h"

/***************************************/

int camp ;
int valeur ;
int *echiquier ;
int pionsRentreAI ;
int pionsRentreJoueur ;

int backtrack ( int prof ) 
{
	int i , j ;
	PointTuple CoupPossible = tableauTuple( j ) ; //j = 15 trés souvent
	
	int tmp , prof_max = 3 ;

	if ( prof < prof_max ) 
	{
		for ( i = 0 ; i < sizeof(CoupPossible) ; i++ )
		{
			Tuple coup = CoupPossible[i] ;
			play( coup , camp ) ; 
			valeur = backtrack( prof + 1 ) ;

			if (camp)
				tmp = Min( tmp , valeur , CoupPossible ) ;
			else
				tmp = Max( tmp , valeur , CoupPossible ) ; 

			deplay( coup , camp ) ; 
		}
		return tmp ; 
	}
	else
	{
		valeur = evaluation( camp , pionsRentreAI , pionsRentreJoueur ) ;
		return valeur ;
	}
}

int Min( int tmp , int prof , PointTuple CoupPossible )
{
	if(( prof == 0 ) && (conditionVictoire( pionsRentreAI , pionsRentreJoueur , camp ) != 1 ))
	{
		return evaluation( camp , pionsRentreAI , pionsRentreJoueur ) ;
	}
	int min = 99999 ;
	int i ; 
	for ( i = 0 ; i < sizeof(CoupPossible) ; i++ )
	{
		tmp = Max( tmp , prof - 1 , CoupPossible ) ;
		if(tmp < min)
		{
			min = tmp;
		}
	}
	return min;
}

int Max( int tmp , int prof , PointTuple CoupPossible ) 
{
	if(( prof == 0 ) && (conditionVictoire( pionsRentreAI , pionsRentreJoueur , camp ) != 1 ))
	{
		return evaluation( camp , pionsRentreAI , pionsRentreJoueur );
	}
	int max = 0 ;
	int i ; 
	for ( i = 0 ; i < sizeof(CoupPossible) ; i++ )
	{
		tmp = Min( tmp , prof - 1 , CoupPossible ) ;
		if(tmp > max)
		{
			max = tmp;
		}
	}
	return max;
}

int evaluation ( int camp , int pionsRentreAI , int pionsRentreJoueur ) {
	int i ;
	int valeurEchiquier = 0 ; 
	for( i = 1 ; i < 25 ; i++ )
		{
			if ( ( echiquier[ i ] < 0 ) && ( echiquier[ i ] > 0 ) ) 
			{
				if ( ( echiquier[ i ] / fabs( echiquier[ i ] ) ) == camp ) 
				{
					if ( camp == - 1 )
					{
						valeurEchiquier = valeurEchiquier + ( 24 - i * echiquier[ i ] ) ;
					}
					else valeurEchiquier = valeurEchiquier + i * echiquier[ i ] ;
				}
			}
		}
	if ( camp == 1 ) valeurEchiquier = valeurEchiquier + 30 * pionsRentreJoueur ;
	else valeurEchiquier = valeurEchiquier + 30 * pionsRentreAI ;
	return valeurEchiquier ;
}
