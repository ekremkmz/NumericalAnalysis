#include <stdio.h>
#include <math.h>
#define SIZE 50
#define EPS 0.00001
float gaussSeidal(float Matris[][SIZE],float root[], int i, int N,float *max){
	int j;
	float tmp=0,dx;
	for(j=0;j<N;j++){
		if(i!=j){
			tmp+=-1*Matris[i][j]*root[j];
		}
	}
	tmp+=Matris[i][N];
	tmp/=Matris[i][i];
	dx=fabs(root[i]-tmp);
	if(dx>*max ){
		*max=dx;
	}
	return tmp;
}
int main() {
	int i,j,N;
	printf("\nKac bilinmeyenli denklem giriceksiniz?\n");
	scanf("%d",&N);
	printf("Denklemleri girerken en buyuk sayilari matrisin kosegenine denk getirin.Aksi halde irsaksama olur.\n");
	float max,tmp[SIZE],dx,Matris[SIZE][SIZE],root[SIZE];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d. denklemdeki x%d nin katsayisi nedir?",i+1,j+1);
			scanf("%f",&Matris[i][j]);
		}
		printf("%d. denklemin esiti nedir?",i+1);
		scanf("%f",&Matris[i][N]);
	}
	for(i=0;i<N;i++){
		tmp[i]=1;
	}
	for(i=0;i<N;i++){
		printf("|");
		for(j=0;j<N;j++){
			printf(" %f ",Matris[i][j]);
		}
		printf("/ %f |\n",Matris[i][N]);
	}
	do{
		max=0;
		for(i=0;i<N;i++){
			root[i]=gaussSeidal(Matris,root,i,N,&max);
		}
		dx=max;
	}while(dx>EPS);
	printf("\n\nKokler: ");
	for(i=0;i<N;i++){
		printf(" x%d=%f ",i+1,root[i]);
	}
	getch();
}

