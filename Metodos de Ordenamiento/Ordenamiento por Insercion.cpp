#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int main(){
	
	int numeros[] = {4,1,6,2,9};
	int i,pos,aux;
	
	for(i=0;i<5;i++){
		pos = i;
		aux = numeros[i];
		
		while((pos>0) && (numeros[pos-1] > aux)){
			numeros[pos] = numeros[pos-1];
			pos--;
			
		}
		numeros[pos] = aux;
		
		
	}
	cout<<"Orden Ascendente: ";
	for(i=0;i<5;i++){
		cout<<numeros[i]<<" ";
	}
	
	getch();
	return 0;
}
