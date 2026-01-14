#include <stdio.h>
int obratenBroj(int);
int sumaNaCifri(int);
void pechatiVoInterval(int ,int);
int sumaNaCifri (int broj){
	int pomoshna, zbir=0;
	while(broj > 0)
	{
		pomoshna = (broj% 10);
		zbir=zbir+pomoshna;
		broj=broj/10;
	}
	return zbir;
}
int obratenBroj(int broj){
	int pomoshna, obraten=0;
	while(broj > 0)
	{
		pomoshna = (broj% 10);
		obraten = obraten*10 + pomoshna;
		broj=broj/10;
	}
	return obraten;
}
void pechatiVoInterval(int a ,int b){
	int i,p,zbirNaDvaBroja=0,p2;
	for(i=a;i<=b;i++){
		p=obratenBroj(i);
		zbirNaDvaBroja=p+i;
		p2=sumaNaCifri(zbirNaDvaBroja);
		if(zbirNaDvaBroja%p2==0)
		{
			printf("%d\n",i);
		}
		
	}
}
int main (){
	int a,b;
	scanf("%d %d",&a,&b);
	pechatiVoInterval(a,b);
	return 0;
}



