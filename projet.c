
/* INITIALISATION */

#define TRUE 1 

#include <stdio.h>
#include <math.h>
#include <string.h>

int echiquier[24] = { 0 , 2 , 0 , 0 , 0 , 0 , -5 , 0 , -3 , 0 , 0 , 0 , 5 , -5 , 0 , 0 , 0 , 3 , 0 , 5 , 0 , 0 , 0 , -2 } ;
int echiquierVirtuel[24] = { 0 } ;

/*
int echiquier[24] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
echiquier[1] = 2 ;
echiquier[6] = -5 ;
echiquier[8] = -3 ;
echiquier[12] = 5 ;
echiquier[13] = -5 ;
echiquier[17] = 3 ;
echiquier[19] = 5 ;
echiquier[24] = -2 ;
*/

int pion_mort , pionsRentreAI , pionsRentreJoueur ;
int pionGagneJoueur , pionGagneAI ;

int backtrack ( int prof ) 
{
	tTuple CP = tableauTuple( j ) ; // C'pas ça mais en gros la liste des coups possible donc on appelle la fonction jouable pour l'ordi. 
	int tmp = min ; // ou max faut voir 

	if ( prof < prof_max ) 
	{
		for (i=0;i<longueurCP;i++) // for c € C :  pour i dans la liste de coup, donc on fait une boucle qui donne pour chaque coup
		{
			tTuple coup = CP[i].int2val ;
			jouer(c) //on va ajouter 1 ou -1 a  la case i+de 
			
			v = backtrack( prof + 1 );
			tmp = min_max( tmp , v ) ;

			dejouer(c) //on va retirer 1 ou -1 a la case i+de
		}
		return tmp
	}
	else //profmax ~ feuille
	{
		v = evaluation //echiquier ( donc fonction evaluation())
		return v ;
	}
}

int play ( int caseDepart , int caseArrive , int camp )
{
	int echiquierVirtuel[caseDepart] = -camp ;
	int echiquierVirtuel[caseArrive] = camp ;
	return * echiquierVirtuel ;
}

int deplay ( int caseDepart , int caseArrive , int camp )
{
	int echiquierVirtuel[caseDepart] = camp ;
	int echiquierVirtuel[caseArrive] = -camp ;
	return * echiquierVirtuel ;
}

int deplacement_possible(int de, int i, int camp) {
	if ( echiquier[i+de] >= camp || i + de <= 24) {
		return 1 ;
	}
	return 0 ;
}

typedef struct {
	int int1Val; 
	int int2Val;
} tTuple;

tTuple tableauTuple ( int j ) {
	tTuple CP[ j ] ; 
	tTuple tuplezero ;
	tuplezero.int1Val = 0 ;
	tuplezero.int2Val = 0 ;  
	int i ; 
	for( i == 1 ; i < j+1 ; i++ )
	{
		CP[i] = tuplezero ; 
	}
	return * CP ; //Un truc chelou, return CP fonctionne pas ici mais dans jouable oui
}

tTuple Jouable( int de , int j ) //CP = coup possible
	{
		tTuple CP = tableauTuple( j ) ; //j = 15 trés souvent

		if ( pion_mort >= 1 )
		{
			int i = 1 ; 
			int a = deplacement_possible( de, i, 1 ) ; 
			if ( a == 1 ) 
				{
				if (camp == 1)
				{
					CP[0].int1Val = 0 ;
					CP[0].int2Val = i + de ; //y'a un truc qui va pas avec le cp.int2val
				}
				else // l'ia psk -1 
				{
					CP[0].int1Val = 25 ;
					CP[0].int2Val = 25 - i - de ;
				}
		}
		else 
		{
			/*
			for( i = 1 ; i<25 ; i++ ) 
			{
				if ( echiquier[ i + 1 ] > 0 ) 
				{
					a = deplacement_possible ( de , i, 1 ) ; 
					if ( a == 1 ) 
					{
						if (camp == 1) 
						{
							CP[i].int1Val = i ;
							CP[i].int2Val = i + de ;
						}
						else 
						{
							CP[i].int1Val = i ;
							CP[i].int2Val = 25 - i - de ;
						}
					}
				}
			}
			*/
			for( i = 1 ; i<25 ; i++ ) 
			{
				if ( (echiquier[ i + 1 ] > 0) || (camp == 1) ) 
				{
					a = deplacement_possible ( de , i, 1 ) ; 
					if ( a == 1 ) 
					{
						CP[i].int1Val = i ;
						CP[i].int2Val = i + de ;	
					}
				}
				else if ((echiquer[ i + 1 ] < 0) || (camp == - 1) )
					a = deplacement_possible ( de , i, -1 ) ; 
					if ( a == -1 ) 
					{
						CP[i].int1Val = 25 - i ;
						CP[i].int2Val = 25 - i - de ;	
					}
			}
		}
		return * CP ;
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

void conditionVictoire( int pionGagne , int camp ) {
	if ( pionGagne == 15 ) printf("le camp %i a gagne", &camp ) ;
}

tTuple concatenation( tTuple CP1[] , tTuple CP2[] , tTuple CP[] ) //erreur d'écriture besoin pointeur et non tableau
{
	int i ;
	for( i == 1 ; i < 31 ; i++ )
	{
		if (i>=16) CP[ i ] = CP2[i] ;
		else CP[ i ] = CP1[ i - 15 ] ;
	}
	return * CP ;
}

tTuple coupJoueur( int de1 , int de2 , int deJoue ) 
{
	int j = 15 ;
	int l ; 
	/*
	tTuple CPvide = tableauTuple( 15 ) ;
	tTuple CP1 = Jouable( int de1 , tTuple CPvide ) ;   //ON PEUT PAS CAR JOUABLE ACCEPTE QUE ( INT DE, INT J )
	tTuple CP2 = Jouable( int de2 , tTuple CPvide ) ; 	//ON PEUT PAS CAR JOUABLE ACCEPTE QUE ( INT DE, INT J )
	*/
	tTuple CP1 = Jouable( de1 , j ) ; 
	tTuple CP2 = Jouable( de2 , j ) ;

	if( deJoue == 0 ) 
		{
		l = 30 ;
		tTuple CP = tableauTuple( 30 ) ; 
		CP = concatenation( CP1 , CP2 , CP ) ;
		}
	else 
	{
		l = 15 ;
		tTuple CP = tableauTuple( 15 ) ; 
		if( deJoue == de1 ) 
		{
			de = de2 ;
			CP = CP2 ;
		}
		else 
		{
			de = de1 ; 
			CP = CP1 ;
		}
	}
	int i ;
	for( i = 0 ; i < l+1 ; i++ ) printf("N°%i - Case depart : %i et case d'arrive : %i", i , CP[i].int1Val , CP[i].int2Val ) ;

	int x ;
	while(TRUE) //define TRUE 1 
	{
		scanf("Entrer le numero du coup que vous voulez jouer", &x ) ; 
		if ((x > 0) && (i > x))
		{
			printf(" Coup valide ") ;
			return CP[x] ;
		}
		printf(" Coup invalide, recommencez " ) ;
	}
}

