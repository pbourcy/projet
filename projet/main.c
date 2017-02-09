#define TRUE 1 

/***************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/***************************************/

#include "var."
#include "jeux.h"
#include "affichage.h"

typedef struct {
	int depart; 
	int arrive;
} Tuple , *PointTuple ;

int main ( void )
{
	srand(time( NULL )) ; 
	int de1 = randomde() + 1 ;
	int de2 = randomde() + 1 ;
	int dejoue ;
	Tuple dejoue2 ;

	int prof = 3 ;
	while(TRUE) 
	{
		dejoue = coupJoueur( de1 , de2 , 0 ).depart - coupJoueur( de1 , de2 , 0 ).arrive ;
		dejoue2 = coupJoueur( de1 , de2 , dejoue ) ;
		backtrack ;
	}
	return( 0 ) ;
}