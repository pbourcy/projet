
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
	return CP ; 
}

tTuple Jouable(int de , int j ) //CP = coup possible
	{
		tTuple CP = tableauTuple( j ) ; //j = 15 trés souvent
		if ( pion_mort >= 1 ) {
			i = 1 ; 
			a = deplacement_possible( de, i ) ;
			if ( a == 1 ) {
				CP.int1Val = CP.int1Val + i ;
				CP.int2Val = CP.int2Val + i + de ;
		}
		else {
			for( i = 1 ; i<25 ; i++ ) 
			{
				if ( echiquier [ i + 1 ] > 0 ) 
				{
					a = deplacement_possible ( de , i ) ;
					if ( a == 1 ) 
					{
						CP.int1Val = CP.int1Val + i ;
						CP.int2Val = CP.int2Val + i + de ;
					}
				}
			}
		}
		return CP ;
	}

int conditionPhaseFinal( void ) {
	int i ;
	while ( i <= 18 && echiquier[i] >= 1 )
		i = i + 1 ; 
		if ( i >= 18 ) return 1 ;
	return 0 ;
}

int evaluation ( int c , int camp , int pionsRentreAI , int pionsRentreJoueur ) {
	int echiquierVirtuel = echiquier ; 
	int valeurEchiquier = 0 ; 
	if ( echiquierVirtuel [ c ] == camp * ( -1 ) ) echiquierVirtuel[ c ] = camp ; 
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

tTuple concatenation( tTuple CP1 , tTuple CP2 , tTuple CP ) {
	int i ;
	for( i == 1 ; i < 31 ; i++ )
	{
		if (i>=16) CP[ i ] = CP2[i] ;
		else CP[ i ] = CP1[ i - 15 ] ;
	}
	return CP ;
}

tTuple coupJoueur( int de1 , int de2 , int deJoue )
	int l ; 
	tTuple CPvide = tableauTuple( 15 ) ;
	tTuple CP1 = Jouable( de1 , CPvide ) ;
	tTuple CP2 = Jouable( de2 , CPvide ) ; 
	if ( deJoue == 0 ) {
		l = 30 ;
		tTuple CP = tableauTuple( 30 ) ; 
		CP = concatenation ( CP1 , CP2 , CP ) ;
	else 
	{
		l = 15
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

	for( i = 0 ; i < l+1 ; i++ ) printf("N°%i - Case depart : %i et case d'arrive : %i", i , CP[i].int1Val , CP[i].int2Val ) ;


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

/* INITIALISATION */

int echiquier = {24}
int echiquierVirtuel = {24}

echiquier[1] = 2 ;
echiquier[6] = -5 ;
echiquier[8] = -3 ;
echiquier[12] = 5 ;
echiquier[13] = -5 ;
echiquier[17] = 3 ;
echiquier[19] = 5 ;
echiquier[24] = -2 ;

int pion_mort , pionsRentreAI , pionsRentreJoueur ;
int pionGagneJoueur , pionGagneAI ;
























