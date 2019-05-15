#include <stdio.h>
#define SIZE 50
void matrisYaz(float Matris[][2*SIZE],int N){
	int i,j;
	printf("\n");
	for(i=0;i<N;i++){
		printf("|");
		for(j=0;j<N;j++){
			printf(" %f ",Matris[i][j]);
		}
		printf("|\n");
	}
}
/*Gauss Jordan Yöntemi*/
void matrisInverse(float Matris[][2*SIZE],float MatrisInverse[][2*SIZE],int N){
	int i,j,k;
	float tmp;
	for(i=0;i<N;i++){
		for(j=N;j<2*N;j++){
			if(i+N==j){
				Matris[i][j]=1;
			}
			else{
				Matris[i][j]=0;
			}
		}
	}
	/*Alt ucgen sifirlama*/
	for(i=0;i<N;i++){
		tmp=Matris[i][i];
		for(j=0;j<2*N;j++){
			Matris[i][j]/=tmp;
		}
		for(j=i+1;j<N;j++){
			tmp=Matris[j][i];
			for(k=0;k<2*N;k++){
				Matris[j][k]-=tmp*Matris[i][k];
			}
		}
	}
	/*Ust ucgen sifirlama*/
	for(i=N;i>=0;i--){
		for(j=i-1;j>=0;j--){
			tmp=Matris[j][i];
			for(k=0;k<2*N;k++){
				Matris[j][k]-=tmp*Matris[i][k];
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			MatrisInverse[i][j]=Matris[i][j+N];
		}
	}
}
int main() {
	int i,j,N;
	printf("Kare matris kac satir?\n");
	scanf("%d",&N);
	float Matris[SIZE][2*SIZE],MatrisInverse[SIZE][2*SIZE];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Matrisin %d.Satir %d.Sutun elemani nedir?",i+1,j+1);
			scanf("%f",&Matris[i][j]);
		}
	}
	printf("\nMatrisiniz:\n");
	matrisYaz(Matris,N);
	matrisInverse(Matris,MatrisInverse,N);
	printf("\nMatrisinizin tersi:\n");
	matrisYaz(MatrisInverse,N);
	getch();
}
