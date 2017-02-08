#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int lancerDee ( void ) {
	/*Fonction qui renvoie un chiffre au hasard entre 1 et 6*/
	srand(time(NULL));
	int dee = rand() % 6 ;
	return dee+1 ;
}

char pionJoueur ( void ) {
	return "w" ; 
}
	
char pionAI ( void ) {
	return "g" ; 
}	

void main ( void ) 
{
	int i , j ;
	printf("13 14 15 16 17 18 19 20 2122 23 24") ; //début
	/*premiére version avec juste des chiffres et non pas des points*/
	for( i = 0 ; i < 13 ; i++ ) 
	{
		if ( echiquier[i] == 0 ) printf("0 ") ;
		else printf("%d ", echiquier[i] ) ; 
	}
	
	printf("\n") ;
	printf("\n") ;
	
	for( j = 0 ; j < 13 ; j++ ) 
	{
		if ( echiquier[j] == 0 ) printf("0") ;
		else printf("%i", echiquier[i] ) ; 
	}
	printf("1  2  3  4  5  6  7  8  9 10 11 12") ; //fin 
	
	printf("Nombre de pion mort pour l'ia = %i", pionsMortIA ) ;
	printf("Nombre de pion mort pour le joueur = %i", pionsMortJoueur ) ;

	if ( conditionPhaseFinale == 1 ) 
	{
		printf("On est en fin de partie") ;
		printf("Le nombre de pions que l'AI a retiré : %i", pionsretireAI ) ;
		printf("Le nombre de pions que le joueur a retiré : %i", pionsretireJoueur ) ;
	}

	if (camp == 1) printf("C'est a l'IA de jouer") ;
	else printf("C'est au tour du joueur") ; 
}

void main2 ( void )  
	/*Seconde version*/
{
	int i , j ;
	printf("13 14 15 16 17 18 19 20 2122 23 24") ; //début
	
	/*On peut faire sans les 10 for mais c'est trop compliqué pour pas grand chose, juste un print de 10 chiffre va pas alourdir le programme.*/
	for( j = 0 , j < 6 , j++ ) 
	{
		for( i = 0 , i < 13 , i++ ) 
		{
			if( echiquier[i] == 0 ) printf("0 ") ; 
			else printf("%i ", echiquier[i]) ; 
		}
		printf("\n") ;
	}

	printf("\n") ;
	printf("\n") ;

	for( j = 0 , j < 6 , j++ ) 
	{
		for( i = 13 , i < 25 , i++ ) 
		{
			if( echiquier[i] == 0 ) printf("0 ") ; 
			else printf("%i ", echiquier[i]) ; 
		}
		printf("\n") ;

	printf("Nombre de pion mort pour l'ia = %i", pionsMortIA ) ;
	printf("Nombre de pion mort pour le joueur = %i", pionsMortJoueur ) ;

	if ( conditionPhaseFinale == 1 ) 
	{
		printf("On est en fin de partie") ;
		printf("Le nombre de pions que l'AI a retiré : %i", pionsretireAI ) ;
		printf("Le nombre de pions que le joueur a retiré : %i", pionsretireJoueur ) ;
	}

	if (camp == 1) printf("C'est a l'IA de jouer") ;
	else printf("C'est au tour du joueur") ; 
}
	}

	printf("1  2  3  4  5  6  7  8  9 10 11 12") ; //fin 

}


void autreAffichage ( int de1, int de2 , tTuple CP ) 
{
	printf("\n");
	/* Les dées et les coups possibles qu'on peut afficher dans une différente couleur / char par exemple */
	printf("Le resultat du de n°1 = %i", de1) ;
	printf("Le resultat du de n°2 = %i", de2) ;

	/*CP a remettre dans le main affichage, dans la boucle d'affichage*/
	for( i = 0 ; i < 16 ; i++ ) 
	{
		if( echiquier[i] == CP[i].int2val )
			printf("P ") ;
	}

	if (conditionVictoire == 1 || camp == 1) 
		printf("L'IA a gagné") ;
	else if (conditionVictoire == 1 || camp != 0 ) 
		printf("L'IA a perdu") ;
}




//précédente version
void brouillon ( void ) {
	/*Supprime ce qui a été écrit précédemment dans la console, ne fonctionne que pour linux, pour window utiliser system("cls")*/
	printf("\e[1;1H\e[2J");
	/*l largeur, h hauteur, n numéro du tour.*/
	int l, h ;
	int n = 1 ;
	
	/*Nous avons 12 cases en largeur ou l'on peut placer les pions.
	Le plateau du backgammon est divisé en deux parties, avec une délimitation entre les deux parties.
	Nous avons donc 12 cases et la délimitation.*/
	int largeur_plus_un = 12+1 ;
	int hauteur = 12 ;
	
	/*Nous pouvons placer jusqu'a 5 pions sur chaque case
	Pour que ce soit plus agréable a regarder nous ajoutons 3 espaces vides au milieu du plateau.*/
	int plateau[l][h] ;
	
	/**********************************************************************************
	*AFFICHAGE DES NUMEROS DE COLONNES
	**********************************************************************************/
	printf("  ") ;
	for (h=1;h<=largeur_plus_un-1;h++) 
	/*On crée une boucle qui va afficher les numéros de cases, numérotés de 1 à 13.*/	
	{ 
		if (h<=6) printf("  %d", h) ;
		if (h==7) printf("   ") ;
		/*Pour éviter qu'un décalage ne se crée, on va afficher deux espaces si c'est un chiffre, sinon un seul*/
		if (h>=7) {
			if (h<=10) printf("  %d", h) ;
			else printf(" %d", h) ;
			}


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
		if ((l==6) || (l==7)) printf("\n\n ") ;
		
		/*Partie basse du plateau, on affiche le numéro l-1 comme la 6eme ligné est compté*/
		else if(l>=7) printf("\n\n%d", l-2) ;
		
		/*Partie haute du plateau, on affiche le numéro l*/
		else printf("\n\n%d", l) ;
		
		/*Si le numéro est supérieur a 10, alors pour éviter un décalage on ajoute un espace a tous les chiffres précédant 10.
		Sauf que l'affichage =/= les chiffres de lignes, donc ici il faut que l <= 11.*/
		if (l<=11) printf(" ") ;

		for (h=1;h<=largeur_plus_un;h++)
		/*Colonnes*/
		{
			/*Affiche la ligne de démarcation entre les deux portions du plateau.*/
			if (h==7) printf("  |") ;
			else if ((l==6) || (l==7)) printf("   ") ;
			/*On affiche des x, l'implémentation du tableau n'existe pas encore*/
			else printf("  o") ;
			
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
	
	/*Affiche les résultats des dées avec la fonction lancerDee*/
	printf("-----------------------------------------------\n") ;
	printf("Resultat du lancee de dee, Dee 1 : %d , ", lancerDee()) ;
	/*Sleep for re-init la fonction random utilisé dans lancerDee()*/
	sleep(1) ;
	printf("Dee 2 : %d\n", lancerDee()) ;

	/*Si n est pair c'est au tour de L'IA, sinon au joueur.*/
	if (n%2==0) printf("C'est a l'ordinateur de jouer.") ;
	else printf("C'est a vous de jouer.") ;
	printf("\n") ;

}
