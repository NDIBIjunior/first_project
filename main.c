#include<stdio.h>
#include<stdlib.h>

int fibo_iter(int n)
{
	int fib,i;
	int * tab;
	if(n==1 || n==2)
    {
        fib = 1;
    }
	if(n>2)
	{
		tab = (int *)malloc(n*sizeof(int));
		tab[0] = 1;
		tab[1] = 1;
		for(i=2;i<n;i++)
		{
			tab[i]= tab[i-1] + tab[i-2];
		}
		fib = tab[n-1];
		free(tab);
	}
	return fib;
}

int fibo_rec(int n)
{
	int f;
	if(n==0 || n== 1)
	{
		f = n;
	}
	else 
	{
		return (fibo_rec(n-2) + fibo_rec(n-1));
	}
}

/* PROGRAMME PRINCIPAL */

int main()
{
    int n,choix;
    printf("Bonjour!\n Veuillez entrer le rang de la suite FIBONACCI souhaite\n");
    scanf("%d",&n);
    printf("vous avez deux choix\n1= utiliser la fonction iterative\n2= utiliser la fonction recursive\n");
    scanf("%d",&choix);
    if(choix == 1)
    {
        printf("le %d terme que la fonction ietrative a calcule est egal a %d", n, fibo_iter(n));
    }
    if(choix == 2)
    {
        printf("le %d terme que la fonction recursive a calculee est egal a %d",n,fibo_rec(n));
    }
    if(choix != 1 && choix != 2)
    {
        do
        {
            printf("tapez soit 1 soit 2 pour que le programme puisse effectuer son calcul");
            scanf("%d",choix);
        }
		while (choix != 1 && choix != 2);
        if(choix == 1)
        {
            printf("le %d terme que la fonction ietrative a calcule est egal a %d", n, fibo_iter(n));
        }
         if(choix == 2)
        {
            printf("le %d terme que la fonction recursive a calculee est egal a %d",n,fibo_rec(n));
        }
        
    }
    return 0;
}
