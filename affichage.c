#include <stdio.h>
#include <stdlib.h>

void main ( void ) {
	int l, h ;
	int largeur_plus_un = 12+1 ;
	int hauteur = 15 ;
	int plateau[l][h] ;
	printf("  ") ;
	for (h=1;h<=largeur_plus_un;h++) 
	{ 
		if (h<=10)
			printf("  %d", h) ;
		else printf(" %d", h) ;
	}
	for (l=1;l<=hauteur;l++)
	{
		if (l==6) printf("\n\n ") ;
		else if(l>=6) printf("\n\n%d", l-1) ;
		else printf("\n\n%d", l) ;
		if (l<=10) printf(" ") ;

		for (h=1;h<=hauteur+1;h++)
		{
			if (h==7) printf("  |") ;
			else printf("  x") ;
			/*
			if (l<10 & h<10)
				printf("   ") ;
			else if (l>=10 && h>=10)
				printf(" ") ;
			else 
				printf("  ") ;
			printf("  [%d,%d]", l, h) ;
			*/
		}
	}
	printf("\n\n") ;
}




