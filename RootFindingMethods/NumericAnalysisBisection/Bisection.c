#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
#define EPS 0.00001
double dizikoy(double dizi[],double x,int a){
	int i,j;
	double dizipow[SIZE],tmp,fx;
	/*Sayiyi fonksiyona koyan blok.*/
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
	int a,i;
	/*Denklemi diziye tanimlayan blok*/
	printf("Denklem kacinci dereceden?\n");
	scanf("%d",&a);
	double x1,x2,x3,fx1=1,fx2=1,fx3=1,dx,tmp,dizi[SIZE];
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
	/*Fonksiyonu yazdiran blok*/
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
	/*Kok aralýgýný alan blok*/
	printf("\nKok aralik baslangici giriniz:");
	scanf("%lf",&x1);
	printf("\nKok aralik bitisi giriniz:");
	scanf("%lf",&x2);
	/*Bisection algoritmasi*/
	do{
		fx1=dizikoy(dizi,x1,a);
		fx2=dizikoy(dizi,x2,a);
		printf("\nf(%f)=%f\tf(%f)=%f",x1,fx1,x2,fx2);
		x3=(x1+x2)/2;
		fx3=dizikoy(dizi,x3,a);
		printf("\nMetod uygulaniyor...\tf(%f)=%f",x3,fx3);		
		if(fx1*fx3<=0){
			x2=x3;
		}
		else if(fx2*fx3<=0){
			x1=x3;
		}
		dx=fx3;
		if(dx<0){
			dx*=-1;
		}
	}while(dx>EPS);
	printf("\nKok=%f",x3);
	printf("\nCikis icin bir tusa basiniz...");
	getch();
}
