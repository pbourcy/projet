
/* INITIALISATION */

#define TRUE 1 

#include <stdio.h>
#include <math.h>
#include <string.h>

int echiquier[24] = { 0 , 2 , 0 , 0 , 0 , 0 , -5 , 0 , -3 , 0 , 0 , 0 , 5 , -5 , 0 , 0 , 0 , 3 , 0 , 5 , 0 , 0 , 0 , -2 } ;
int echiquierVirtuel[24] = { 0 } ;

Tuple tableauTuple ( int j ) ;
Tuple Jouable( int de , int j ) ;
tTuple coupJoueur( int de1 , int de2 , int deJoue ) ;

void conditionVictoire( int pionGagne , int camp ) ;

int min_max( void ) ;
int lancerDee( void ) ;
int conditionPhaseFinal( void ) ;
int deplacement_possible( int de , int i , int camp ) ;
int play( int caseDepart , int caseArrive , int camp ) ;
int deplay ( int caseDepart , int caseArrive , int camp ) ;
int evaluation ( int c , int camp , int pionsRentreAI , int pionsRentreJoueur ) ;
int evaluation ( int c , int camp , int pionsRentreAI , int pionsRentreJoueur )  ;

int pion_mort , pionsRentreAI , pionsRentreJoueur ;
int pionGagneJoueur , pionGagneAI ;
/*
int camp est en fait le camp en train de jouer donc qui c'est qui joue
1 joueur
-1 IA 
*/

int lancerDee( void ) 
{
	srand( time( NULL )) ;
	return rand() % 6
}

int de1 = lancerDee() + 1 ;
int de2 = lancerDee() + 1 ; 

int backtrack ( int prof ) 
{
	Tuple CoupPossible = tableauTuple( j ) ; //j = 15 trés souvent
	
	int tmp = min , n , prof_max = 3 ; // ou max faut voir

	if ( prof < prof_max ) 
	{
		for ( i = 0 ; i < sizeof(CoupPossible) ; i++ ) // for c € C :  pour i dans la liste de coup, donc on fait une boucle qui donne pour chaque coup
		{
			n = n + 1 ; 
			tTuple coup = CoupPossible[i]->arrive ;
			jouer(c) //on va ajouter 1 ou -1 a  la case i+de 
			
			v = backtrack( prof + 1 ) ;
			tmp = min_max( tmp , v ) ;

			dejouer(c) //on va retirer 1 ou -1 a la case i+de
		}
		return tmp ; 
	}
	else //prof_max ~ feuille
	{
		v = evaluation( c , n%n , pionsRentreAI , pionsRentreJoueur ) ;//echiquier ( donc fonction evaluation())
		return v ;
	}
}

int min_max( int n ) 
{
	return( 0 ) ;
}

int play( int caseDepart , int caseArrive , int camp )
{
	int echiquierVirtuel[caseDepart] = echiquierVirtuel[caseDepart] - camp ;
	int echiquierVirtuel[caseArrive] = echiquierVirtuel[caseArrive] + camp ;
	return * echiquierVirtuel ;
}

int deplay( int caseDepart , int caseArrive , int camp )
{
	int echiquierVirtuel[caseDepart] = echiquierVirtuel[caseArrive] + camp ;
	int echiquierVirtuel[caseArrive] = echiquierVirtuel[caseDepart] - camp ;
	return * echiquierVirtuel ;
}

int deplacement_possible( int de , int i , int camp ) {
	if ( echiquier[i+de] >= camp || i + de <= 24) {
		return 1 ;
	}
	return 0 ;
}

typedef struct {
	int depart; 
	int arrive;
} Tuple , *Tuple ;


Tuple tableauTuple ( int j ) {
	/*
	*Tuple CP ;
	CP = (Tuple*)malloc(sizeof(Tuple)); //ça init une seule valeur.
	*/
	Tuple *CoupPossible[ j ] = { 0 } ;
	int i ; 
	for( i == 1 ; i < j+1 ; i++ )
	{
		CoupPossible[i] = (Tuple*)malloc(sizeof(Tuple)) ;
		CoupPossible[i]->depart = 0 ;
		CoupPossible[i]->arrive = 0 ; 
	}
	return CoupPossible ; //Un truc chelou, return CP fonctionne pas ici mais dans jouable oui
}

/*
student* students = malloc(numStudents * sizeof *students);
for (x = 0; x < numStudents; x++)
{
    students[x].firstName = "John"; 
    students[x].lastName = "Smith"; 
    students[x].day = 1;
    students[x].month = 12;
    students[x].year = 1983;
}
On a oublié qu'il faut assigner de la mémoire en plus avec malloc, car on a init un tableau et pas un tableau de struct de deux valeurs, le probléme en c qui apparait jamais en python.
Faudra aussi test avec CP[i].int2val <- valeur 

*/
	
Tuple Jouable( int de , int j ) //CP = coup possible
{
		Tuple CoupPossible = tableauTuple( j ) ; //j = 15 trés souvent

		if ( pion_mort >= 1 )
		{
			int i = 1 ; 
			int a = deplacement_possible( de, i, 1 ) ; 
			if ( a == 1 ) 
				{
				if (camp == 1) //joueur
				{
					CoupPossible[0]->depart = 0 ;
					CoupPossible[0]->arrive = i + de ; //y'a un truc qui va pas avec le cp.int2val
				}
				else // l'ia psk -1 
				{
					CoupPossible[0]->depart = 25 ;
					CoupPossible[0]->arrive = 25 - i - de ;
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
						CoupPossible[i]->depart = i ;
						CoupPossible[i]->arrive = i + de ;	
					}
				}
				else if ((echiquer[ i + 1 ] < 0) || (camp == - 1) )
				{
					a = deplacement_possible ( de , i, -1 ) ; 
					if ( a == -1 ) 
					{
						CoupPossible[i]->depart = 25 - i ;
						CoupPossible[i]->arrive = 25 - i - de ;	
					}
				}
			}
		}
		return CoupPossible ;
		}
}

int conditionPhaseFinal( void ) {
	int i ;
	while ( i <= 18 && echiquier[i] >= 1 )
		i = i + 1 ; 
		if ( i >= 18 ) return 1 ;
	return 0 ;
}

int evaluation ( int c , int camp , int pionsRentreAI , int pionsRentreJoueur ) {
	
	/*On peut pas copier des arrays/tableau juste en faisant l'un égale l'autre, donc on utilise la fonction memcpy*/
	memcpy(echiquier, echiquierVirtuel, sizeof(echiquier)) ;
	/*echiquierVirtuel = echiquier ; */
	
	int i ;
	int valeurEchiquier = 0 ; 
	if ( echiquierVirtuel[ c ] == camp * ( -1 ) ) echiquierVirtuel[ c ] = camp ; 
	for(i = 1 ; i < 25 ; i++ ) //24 valeurs 
		{
			if ( ( echiquierVirtuel[ i ] < 0 ) && ( echiquierVirtuel[ i ] > 0 ) ) 
			{
				if ((echiquier[ i ] / fabs(echiquier[ i ])) == camp) 
				{
					if ( camp == - 1 ) // IA
					{
						valeurEchiquier = valeurEchiquier + ( 24 - i * echiquier[ i ] ) ;
					}
					else valeurEchiquier = valeurEchiquier + i * echiquier[ i ] ; //joueur
				}
			}
		}
	if ( camp == 1 ) valeurEchiquier = valeurEchiquier + 30 * pionsRentreJoueur ;
	else valeurEchiquier = valeurEchiquier + 30 * pionsRentreAI ;
	return valeurEchiquier ;
}

/*A mettre dans le main*/
void conditionVictoire( int pionGagne , int camp ) {
	if ( pionGagne == 15 )
		{
		if (camp)
			printf("le joueur gagne") ;
		else
			printf("L'IA gagne") ;}
}

/*
Tuple concatenation( tTuple CP1, tTuple CP2, tTuple CP ) //erreur d'écriture besoin pointeur et non tableau
{
	int i ;
	for( i == 1 ; i < 31 ; i++ )
	{
		if (i>=16) CP[ i ] = CP2[i] ;
		else CP[ i ] = CP1[ i - 15 ] ;
	}
	return * CP ;
}
*/

tTuple coupJoueur( int de1 , int de2 , int deJoue ) 
{
	int i , k , j = 15 ;
	/*
	tTuple CPvide = tableauTuple( 15 ) ;
	tTuple CP1 = Jouable( int de1 , tTuple CPvide ) ;   //ON PEUT PAS CAR JOUABLE ACCEPTE QUE ( INT DE, INT J )
	tTuple CP2 = Jouable( int de2 , tTuple CPvide ) ; 	//ON PEUT PAS CAR JOUABLE ACCEPTE QUE ( INT DE, INT J )
	*/
	Tuple CoupPossibleDe1 = Jouable( de1 , j ) ; 
	Tuple CoupPossibleDe2 = Jouable( de2 , j ) ;

	if( deJoue == 0 ) 
		{
		l = 30 ;
		Tuple CP = tableauTuple( 30 ) ; 
		//CP = concatenation( CP1 , CP2 , CP ) ;
		for( k == 1 ; k < 31 ; k++ )
			{
			if (k>=16) CoupPossible[ k ] = CoupPossibleDe2[ k ] ;
			else CoupPossible[ k ] = CoupPossibleDe1[ k - 15 ] ;
			}
		}
	else 
	{
		l = 15 ;
		tTuple CoupPossible = tableauTuple( 15 ) ; 
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
	}
	int i ;
	for( i = 0 ; i < l+1 ; i++ ) printf("N°%i - Case depart : %i et case d'arrive : %i", i , CoupPossible[i]->depart , CoupPossible[i]->arrive ) ;

	int x ;
	while(TRUE) //define TRUE 1 
	{
		scanf("Entrer le numero du coup que vous voulez jouer", &x ) ; 
		if ((x > 0) && (i > x))
		{
			printf(" Coup valide ") ;
			return CoupPossible[x] ;
		}
		printf(" Coup invalide, recommencez " ) ;
	}
}
