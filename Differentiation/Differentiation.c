#include <stdio.h>
#include <stdlib.h>
#define EPS 0.0000001
double dizikoy(double dizi[],double x,int a){
	int i,j;
	double dizipow[100],tmp,fx;
	/*Say�y� fonksiyona koyan blok.*/
		for(i=a;i>=0;i--){
			tmp=1;
			for(j=i;j>=1;j--){
				tmp*=x;
			}
			tmp*=dizi[i];
			dizipow[i]=tmp;
		}
		tmp=0;
		for(i=a;i>=0;i--){
			tmp+=dizipow[i];	
		}
		fx=tmp;
		
		return fx;
}
int main() {
	int a,i,j;
	/*Denklemi diziye tan�mlayan blok*/
	printf("Denklem kacinci dereceden?\n");
	scanf("%d",&a);
	double x,fturx,dizi[a+1];
	for(i=a; i>=0 ;i--){
		if(i>0){
			printf("%d. dereceli terimin katsayisini giriniz.\n", i);
			scanf("%lf",&dizi[i]);
		}
		else{
			printf("Sabit terimi giriniz.\n");
			scanf("%lf",&dizi[i]);
		}	
	}
	/*Fonksiyonu yazd�ran blok*/
	printf("Fonksiyonunuz: \t");
	for(i=a; i>=2 ;i--){
		if(dizi[i]==(int)dizi[i]){
			printf("%dx^%d",(int)dizi[i],i);
		}
		else{
			printf("%lfx^%d",dizi[i],i);
		}
		while(i>2&&dizi[i-1]==0){
			i--;
		}
		if(i>2&&dizi[i-1]>0){
			printf("+");
		}
	}
	if(dizi[1]>0){
			printf("+");
	}
	if(dizi[1]!=0&&dizi[1]==(int)dizi[1]){
		printf("%dx",(int)dizi[1]);
	}
	else if(dizi[1]!=0){
		printf("%lfx",dizi[1]);
	}
	if(dizi[0]>0){
			printf("+");
	}
	if(dizi[0]!=0&&dizi[0]==(int)dizi[0]){
		printf("%d",(int)dizi[0]);
	}
	else if(dizi[0]!=0){
		printf("%lf",dizi[0]);
	}
	printf("\nHangi noktadaki turevi hesaplansin?");
	scanf("%lf",&x);
	/*Say�y� turev fonksiyonuna koyan blok.*/
	fturx=(dizikoy(dizi,x,a)-dizikoy(dizi,x+EPS,a))/(x-(x+EPS));
	printf("\n\nf'(%.7f)=%.7f",x,fturx);
		
}

