#include <stdio.h>
#include <string.h>
#include <math.h>

/***************************************/

#include "affichage.h"
#include "regle.h"
#include "vah.h"

/***************************************/

int camp ;
int valeur ;
int *echiquier ;
int pionsMortJoueur ;
int pionsMortAI ;
int pionsRentreAI ;
int pionsRentreJoueur ;

PointTuple tableauTuple ( int j ) {
	PointTuple CoupPossible[ 15 ] = { 0 } ;
	int i ; 
	for( i = 1 ; i < j+1 ; i++ )
	{
		CoupPossible[i] = (Tuple*)malloc(sizeof(Tuple)) ;
		CoupPossible[i]->depart = 0 ;
		CoupPossible[i]->arrive = 0 ; 
	}
	return * CoupPossible ; 
}

void affichage1 ( void ) 
{
	int i , j ;
	int camp = 1 ;
	printf("13 14 15 16 17 18 19  20 21 22 23 24\n") ;
	for( i = 0 ; i < 13 ; i++ ) 
	{
		if ( echiquier[i] == 0 ) printf("0 ") ;
		else if ( echiquier[i] < 0 ) printf("%d  ", echiquier[i] ) ; 
		else printf("%d  ", echiquier[i] ) ; 
	}
	
	printf("\n") ;
	printf("\n") ;
	
	for( j = 0 ; j < 13 ; j++ ) 
	{
		if ( echiquier[j] == 0 ) printf("0 ") ;
		else printf("%i ", echiquier[i] ) ; 
	}
	printf("\n") ;
	printf("12 11 10 9  8  7  6  5  4  3  2  1\n") ; //fin 
	
	printf("Nombre de pion mort pour l'ia = %i\n", pionsMortAI ) ;
	printf("Nombre de pion mort pour le joueur = %i\n", pionsMortJoueur ) ;

	if ( conditionPhaseFinal() == 1 ) 
	{
		printf("On est en fin de partie\n") ;
		printf("Le nombre de pions que l'AI a retiré : %i\n", pionsRentreAI ) ;
		printf("Le nombre de pions que le joueur a retiré : %i\n", pionsRentreJoueur ) ;
	}

	if (camp == 1) printf("C'est a l'IA de jouer\n") ;
	else printf("C'est au tour du joueur\n") ; 
}

void affichage2 ( void ) 
{
	int i , j , camp = 1 ;
	printf("13 14 15 16 17 18 19 20 2122 23 24 \n") ;
	for( j = 0 ; j < 6 ; j++ ) 
	{
		for( i = 0 ; i < 13 ; i++ ) 
		{
			if( echiquier[i] == 0 ) printf("0 ") ; 
			else printf("%i ", echiquier[i]) ; 
		}
		printf("\n") ;
	}

	printf("\n") ;
	printf("\n") ;

	for( j = 0 ; j < 6 ; j++ ) 
	{
		for( i = 13 ; i < 25 ; i++ ) 
		{
			if( echiquier[i] == 0 ) printf("0 ") ; 
			else printf("%i ", echiquier[i]) ; 
		}
		printf("\n") ;
	}

	printf("Nombre de pion mort pour l'ia = %i \n", pionsMortAI ) ;
	printf("Nombre de pion mort pour le joueur = %i \n", pionsMortJoueur ) ;

	if ( conditionPhaseFinal() == 1 ) 
	{
		printf("On est en fin de partie\n") ;
		printf("Le nombre de pions que l'AI a retiré : %i \n", pionsRentreAI ) ;
		printf("Le nombre de pions que le joueur a retiré : %i \n", pionsRentreJoueur ) ;
	}

	if (camp == 1) printf("C'est a l'IA de jouer\n") ;
	else printf("C'est au tour du joueur\n") ; 

	printf("1  2  3  4  5  6  7  8  9 10 11 12\n") ; //fin 
}

void autreAffichage ( int de1, int de2 , PointTuple CoupPossible ) 
{
	int camp ;
	int pionGagne ;
	int i ;
	printf("\n");
	printf("Le resultat du de n°1 = %i\n", de1) ;
	printf("Le resultat du de n°2 = %i\n", de2) ;

	for( i = 0 ; i < 16 ; i++ ) 
	{
		if( echiquier[i] == CoupPossible[i].arrive )
			printf("P ") ;
	}

	if ( conditionVictoire( pionsRentreAI , pionsRentreJoueur , camp ) == 1 || camp == 1) 
		printf("L'IA a gagné\n") ;
	else if ( conditionVictoire( pionsRentreAI , pionsRentreJoueur , camp ) == 1 || camp != 0 ) 
		printf("L'IA a perdu\n") ;
}
