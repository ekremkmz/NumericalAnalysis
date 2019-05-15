#include <stdio.h>
#include <stdlib.h>
#define EPS 0.0000000000001
double dizikoy(double dizi[],double x,int a){
	int i,j;
	double dizipow[100],tmp,fx;
	/*Sayýyý fonksiyona koyan blok.*/
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
	/*Denklemi diziye tanýmlayan blok*/
	printf("Denklem kacinci dereceden?\n");
	scanf("%d",&a);
	double x,x1,x2,fx1=1,fturx1,hata,tmp,dizitur[a],atur,dizi[a+1],dizipow[a+1],diziturpow[a+1];
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
	/*Fonksiyonu yazdýran blok*/
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
	//Turev fonksiyonu tanýmlayan blok
	for(i=1; i<=a ;i++){
		if(dizi[i]!=0){
			dizitur[i-1]=dizi[i];
			dizitur[i-1]*=i;
		}
	}
	atur=a-1;
	/*Tahmini kok alan blok*/
	printf("\nTahmini koku giriniz:");
	scanf("%lf",&x2);
	
	/*Koke yaklasan blok*/
	do{
		x1=x2;
		/*Sayýyý fonksiyona koyan blok.*/
		x=x1;
		fx1=dizikoy(dizi,x,a);
		/*Sayýyý turev fonksiyonuna koyan blok.*/
		fturx1=(dizikoy(dizi,x,a)-dizikoy(dizi,x+EPS,a))/(x-(x+EPS));
		/*Algoritma*/
		x2=x1-(fx1/fturx1);
		if(x1-x2<0){
			hata=x2-x1;
		}
		else{
			hata=x1-x2;
		}
		printf("\nx2=x1-f(x)/f'(x)\tx=%lf-(%lf/%lf)\tx=%lf\n",x1,fx1,fturx1,x2);
	}
	while(hata>EPS);
		
	
	printf("\n\nKokunuz %.15f hata payi ile %.15f olarak hesaplanmistir.",hata,x2);
	return 0;	
}
