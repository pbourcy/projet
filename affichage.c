#include <stdio.h>
#include <stdlib.h>

void main ( void ) {
	
	/*
	* l largeur, h hauteur.
	*/
	int l, h ;
	
	/*
	*Nous avons 12 cases en largeur ou l'on peut placer les pions.
	*Le plateau du backgammon est divisé en deux parties, avec une délimitation entre les deux parties.
	*Nous avons donc 12 cases et la délimitation.
	*/
	int largeur_plus_un = 12+1 ;
	
	int hauteur = 15 ;
	/*
	*Nous pouvons placer jusqu'a 5 pions sur chaque cases
	*Pour que ce soit plus agréable a regarder nous ajoutons 3 espaces vides au milieu du plateau.
	*/
	int plateau[l][h] ;
	
	/**********************************************************************************
	*AFFICHAGE DES NOMBRES
	**********************************************************************************/
	printf("  ") ;
	for (h=1;h<=largeur_plus_un;h++) 
	/*
	*On crée une boucle qui va afficher les numéros de cases, numérotés de 1 à 13.
	*/	
	{ 
		/*
		*Pour éviter qu'un décalage ne se crée, par exemple 8 9 12 13 14 
		*						    1 1 1 1 1 1
		*On va afficher deux espaces si c'est un chiffre, sinon un seul, ce qui donne
		*						8  9 12 13 14
								1  1  1  1  1
		*/
		if (h<=10)
			printf("  %d", h) ;
		else printf(" %d", h) ;
	}
	
	/**********************************************************************************
	*AFFICHAGE DU PLATEAU
	**********************************************************************************/
	for (l=1;l<=hauteur;l++)
	/*Lignes*/
	{
		/*
		*Double retour a la ligne pour un tableau espacé 1  2  3  4
		*						
		*						 5  6  7  8
		*Cela rend mieux dans la console.
		*/
		
		/*Si 6eme ligne, on n'affiche rien (pas de numéro de ligne)*/
		if (l==6) printf("\n\n ") ;
		
		/*Partie basse du plateau, on affiche le numéro l-1 comme la 6eme ligné est compté*/
		else if(l>=6) printf("\n\n%d", l-1) ;
		
		/*Partie haute du plateau, on affiche le numéro l*/
		else printf("\n\n%d", l) ;
		
		/*Si le numéro est supérieur a 10, alors pour éviter un décalage on ajoute un espace a tous les chiffres précédant 10.*/
		if (l<=10) printf(" ") ;

		for (h=1;h<=hauteur+1;h++)
		/*Colonnes*/
		{
			/*
			*Affiche la ligne de démarcation entre les deux portions du plateau.
			*/
			if (h==7) printf("  |") ;
			else printf("  x") ;
			
			/*Test pour afficher le numéro de la case, format [l,h], ex [10,14]
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




