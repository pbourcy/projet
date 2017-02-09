
/* INITIALISATION */

#define TRUE 1 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int echiquier[24] = { 2 , 0 , 0 , 0 , 0 , -5 , 0 , -3 , 0 , 0 , 0 , 5 , -5 , 0 , 0 , 0 , 3 , 0 , 5 , 0 , 0 , 0 , 0 , -2 } ;

typedef struct {
	int depart; 
	int arrive;
} Tuple , *PointTuple ;

PointTuple tableauTuple ( int j ) ;
PointTuple Jouable( int de , int j ) ;
Tuple coupJoueur( int de1 , int de2 , int deJoue ) ;

int Max( int tmp , int prof , PointTuple CoupPossible ) ;
int Min( int tmp , int prof , PointTuple CoupPossible ) ;
int randomde ( void ) ;
int lancerDee( void ) ;
int conditionPhaseFinal( void ) ;
int play( Tuple Coup , int camp ) ;
int deplay ( Tuple Coup , int camp ) ;
int conditionVictoire( int pionsRentreAI , int pionsRentreJoueur , int camp ) ;
int deplacement_possible( int de , int i , int camp ) ;
int evaluation ( int camp , int pionsRentreAI , int pionsRentreJoueur ) ;

int pionsMortJoueur , pionsMortAI ;
int pionsRentreAI , pionsRentreJoueur ;

/*int camp est en fait le camp en train de jouer donc qui c'est qui joue 1 joueur -1 IA */

int randomde ( void ) 
{
	return rand() % 6 ;
}

int camp ;
int valeur ;

int backtrack ( int prof ) 
{
	int i , j ;
	PointTuple CoupPossible = tableauTuple( j ) ; //j = 15 trés souvent
	
	int tmp , prof_max = 3 ; // ou max faut voir

	if ( prof < prof_max ) 
	{
		for ( i = 0 ; i < sizeof(CoupPossible) ; i++ ) // for c € C :  pour i dans la liste de coup, donc on fait une boucle qui donne pour chaque coup
		{
			Tuple coup = CoupPossible[i] ;
			play( coup , camp ) ; //on va ajouter 1 ou -1 a  la case i+de 
			valeur = backtrack( prof + 1 ) ;

			if (camp)
				tmp = Min( tmp , valeur , CoupPossible ) ;
			else
				tmp = Max( tmp , valeur , CoupPossible ) ; 

			deplay( coup , camp ) ; //on va retirer 1 ou -1 a la case i+de
		}
		return tmp ; 
	}
	else //prof_max ~ feuille
	{
		valeur = evaluation( camp , pionsRentreAI , pionsRentreJoueur ) ;//echiquier ( donc fonction evaluation())
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

int deplacement_possible( int de , int i , int camp ) {
	if ( echiquier[i+de] >= camp || i + de <= 24 ) {
		return 1 ;
	}
	return 0 ;
}

PointTuple tableauTuple ( int j ) {
	PointTuple CoupPossible[ 15 ] = { 0 } ;
	int i ; 
	for( i = 1 ; i < j+1 ; i++ )
	{
		CoupPossible[i] = (Tuple*)malloc(sizeof(Tuple)) ;
		CoupPossible[i]->depart = 0 ;
		CoupPossible[i]->arrive = 0 ; 
	}
	return * CoupPossible ; //Un truc chelou, return CP fonctionne pas ici mais dans jouable oui
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

int conditionPhaseFinal( void ) {
	int i ;
	while ( i <= 18 && echiquier[i] >= 1 )
	{
		i = i + 1 ; 
		if ( i >= 18 ) return( 1 ) ;
	}
	return( 0 ) ;
}

/*A mettre dans le main*/
int conditionVictoire( int pionsRentreAI , int pionsRentreJoueur , int camp ) 
{
	if ( pionsRentreJoueur == 15 ) 
		return( 1 ) ;
	else if ( pionsRentreAI == 15 ) 
		return( 0 ) ;
	else return( -1 ) ;
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
		//CP = concatenation( CP1 , CP2 , CP ) ;
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

void main1 ( void ) 
{
	int i , j ;
	int camp = 1 ;
	printf("13 14 15 16 17 18 19  20 21 22 23 24\n") ; //début
	/*premiére version avec juste des chiffres et non pas des points*/
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

void main2 ( void ) 
{
	int i , j , camp = 1 ;
	printf("13 14 15 16 17 18 19 20 2122 23 24 \n") ; //début
	
	/*On peut faire sans les 10 for mais c'est trop compliqué pour pas grand chose, juste un print de 10 chiffre va pas alourdir le programme.*/
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
	/* Les dées et les coups possibles qu'on peut afficher dans une différente couleur / char par exemple */
	printf("Le resultat du de n°1 = %i\n", de1) ;
	printf("Le resultat du de n°2 = %i\n", de2) ;

	/*CP a remettre dans le main affichage, dans la boucle d'affichage*/
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
