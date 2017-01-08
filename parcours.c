#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tpa 
/*
*Definit la structure d'un noeud, avec un charactére (a->z) a l'intérieur et des
*noeuds / feuille pour fg fd (feuille gauche feuille droite)
*/
{
	char etiq ; 
	int val ;
	struct tpa *fg ;
	struct tpa *fd ;
} noeud, *pt_noeud ;

pt_noeud cree_feuille( char c ) {
	pt_noeud n = (pt_noeud)malloc(sizeof(noeud)) ;
	n->etiq = c ;
	n->fg = NULL ;
	n->fd = NULL ;
	return n ;
}

pt_noeud cree_noeud( char c , pt_noeud g , pt_noeud d ) {
	pt_noeud n = (pt_noeud)malloc(sizeof(noeud)) ;
	n->etiq = c ;
	n->fg = g ;
	n->fd = d ;
	return n ;
}

int est_feuille( pt_noeud n ) {
	return ( n->fg == NULL && n->fd == NULL ) ;
}

pt_noeud arbre_fg( pt_noeud n ) {
	assert (( n != NULL ) && ( n->fg != NULL )) ; 
	return n->fg ;
} 

pt_noeud arbre_fd( pt_noeud n ) {
	assert (( n != NULL ) && ( n->fd != NULL )) ; 
	return n->fd ;
}

char noeud_etiq( pt_noeud n ) {
	return n->etiq ;
}

int val_feuille( pt_noeud n ) {
	if ( est_feuille )
		return n->val ;
	return 0 ;
}

void parcours_prof( pt_noeud n ) {
	assert( n == NULL ) ;
	printf( "%c" , noeud_etiq ( n ) ) ;
	printf( "[" ) ;
	if( n->fg != NULL )
		parcours_prof( n->fg ) ;
	printf ( "," ) ;
	if ( n->fd != NULL ) 
		parcours_prof( n-> fd ) ;
	printf( "]" ) ;
}

/*-------------------------------------------------------------*/


int parcours_prof_comptage_feuille( pt_noeud n ) {
	if( est_feuille )
		return 1 ;
	return parcours_prof_comptage_feuille( n->fg ) + parcours_prof_comptage_feuille( n-> fd ) ;
}

int parcours_prof_comptage_noeud( pt_noeud n ) {
	if( est_feuille )
		return 0 ;
	return parcours_prof_comptage_noeud( n->fg ) + parcours_prof_comptage_noeud( n-> fd ) + 1 ;
}

int parcours_prof_comptage_hauteur( pt_noeud n ) {
	if( est_feuille )
		return 1 ;
	return max(parcours_prof_comptage_hauteur( n->fg ), parcours_prof_comptage_hauteur( n-> fd )) + 1 ;
}

int somme_feuille_arbre ( pt_noeud n ) {
	if( est_feuille )
		return val_feuille( n ) ;
	return somme_feuille_arbre( n->fg ) + somme_feuille_arbre( n->fd ) ;
}

void impression_arbre ( pt_noeud n ) {
	assert ( n == NULL ) ;
	printf( "%c" , noeud_etiq( n ) ) ;
	printf( "[" ) ;
	if( n->fg != NULL )
		parcours_prof( n->fd ) ;
	printf( "]" ) ;
}

/*-------------------------------------------------------------*/

int max( int a , int b ) {
	if ( a >= b ) return a ;
	return b ;
}

int min( int a , int b ) {
	if ( a >= b ) return b ;
	return a ; 
}

int minmax( int n , int a , int b ) {
	if(n) return max( a , b ) ;
	return min( a , b ) ;
}

void parcours( pt_noeud n ) {
/*Ne fonctionne pas du tout*/
	assert( n == NULL ) ;
	int i = i + 1 ;
	int valeur = minmax(i, val_feuille( arbre_fd ) , val_feuille( arbre_fg )) ;
	if( i%2 )
		parcours( n->fg ) ;
	if ( i%2 != 1 ) 
		parcours( n-> fd ) ;
}

/*-------------------------------------------------------------*/
