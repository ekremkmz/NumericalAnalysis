#include <stdio.h>
#define EPS 0.00001
#define DELTA 1
int main() {
	int a,i,j;
	/*Denklemi diziye tan�mlayan blok*/
	printf("Denklem kacinci dereceden?\n");
	scanf("%d",&a);
	double x,x1,x2,fx1=1,fx2=1,dx,tmp,kok,dizi[a+1],dizipow[a+1];
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
	/*Tahmini kok alan blok*/
	printf("\nTahmini koku giriniz:");
	scanf("%lf",&x1);
	/*Koke yaklasan blok*/
	dx=DELTA;
	while(dx>EPS/2){
		x2=x1+dx;
		x=x1;
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
		fx1=tmp;
		printf("\n\nf(%lf)=%lf\t",x1,fx1);
		x=x2;
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
		fx2=tmp;
		printf("f(%lf)=%lf\tDelta=%lf",x2,fx2,dx);
		/*Fonksiyon sonuclar�na gore islem yapan blok.*/
		if(fx1*fx2>0){
			x1=x2;
		}
		else if(fx1*fx2<0){
			dx/=2;
			if(dx>EPS){
			printf("\n\nDelta 2 ye bolunuyor. Yeni delta=%lf",dx);
			}
		}
		if(dx<EPS){
			kok=x1;
		}
		if(fx1==0){
			kok=x1;
			dx=0;
		}
		else if(fx2==0){
			kok=x2;
			dx=0;
		}	
	}
	printf("\n\nKokunuz %lf hata payi ile %lf olarak hesaplanmistir.",2*dx,kok);
	return 0;	
}
