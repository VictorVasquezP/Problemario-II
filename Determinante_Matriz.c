#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int recurdet(int **matriz,int n);
int main(int argc, char *argv[]) {
	int **matriz;
	int a,n;
	printf("Filas y columnas del mismo tamaño\n\n");
	printf("Tamaño de la matriz n x n: ");
	scanf("%d",&n);
	matriz=(int **)malloc(n*sizeof(int*));
	for(int a=0;a<n;a++){
		matriz[a]=(int*)malloc(n*sizeof(int));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("[%d][%d]: ",i+1,j+1);
			scanf("%d",&a);
			matriz[i][j]=a;
		}	
	}
	printf("\nDeterminante: %d",recurdet(matriz,n));
	return 0;
}

int recurdet(int **matriz,int n){
	int **aux;
	int cont=0,ac;
	aux=(int **)malloc((n-1)*sizeof(int*));
	for(int cont=0;cont<(n-1);cont++){
		aux[cont]=(int*)malloc((n-1)*sizeof(int));
	}
	if(n==1){
		return matriz[0][0];
	}
	else{
		for(int i=0;i<n;i++){
			ac=0;
			for(int k=0;k<n-1;k++){
				if(k==i){
					ac++;	
				}
				for(int f=0;f<n-1;f++){
					aux[k][f]=matriz[ac][f+1];
				}
				ac++;
			}
			cont+=matriz[i][0]*(pow(-1,i))*recurdet(aux,n-1);
		}
		return cont;
	}
}



