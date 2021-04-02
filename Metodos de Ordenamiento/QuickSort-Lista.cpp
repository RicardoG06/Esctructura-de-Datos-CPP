#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
}*primero = NULL, *ultimo=NULL;



void insertarNodo(int dato);
int getTamanho();
Nodo *getNodoXPos(int pos);
void quickSort(int low, int n);
void mostrarLista();

int main(){
	
	//12,9,4,99
	//,120,1,3,10,13
	
	insertarNodo(12);
	insertarNodo(9);
	insertarNodo(4);
	insertarNodo(99);
	insertarNodo(120);
	insertarNodo(1);
	insertarNodo(3);
	insertarNodo(10);
	insertarNodo(13);
	cout<<"\n\n";
	mostrarLista();
	cout<<"\n\n";
	quickSort(1,getTamanho());
	mostrarLista();
	cout<<"\n\n";
	
	getch();
	return 0;
}

void insertarNodo(int dato){
	Nodo *nuevo = new Nodo();
	nuevo->dato = dato;
	
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = primero;
	}
	else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
}

int getTamanho(){
	int n=0;
	Nodo *aux=primero;
	while(aux!=NULL){
		n++;
		aux=aux->siguiente;
	}
	return n;
}

Nodo *getNodoXPos(int pos){
	Nodo *aux=primero;
	int i=1;
	while(aux!=NULL && pos!=i){
		aux=aux->siguiente;
		i++;
	}
	
	return aux;
	
}


void quickSort(int low, int n){
	Nodo *Pivote=NULL;
	
	int lo = low;
	int hi = n;
	if(lo >=hi){
		return;
	}
	Pivote=getNodoXPos(low);
	
    while (lo < hi) {
    	while (lo<hi && Pivote->dato < getNodoXPos(hi)->dato) {
              hi--;
        }
        if(!(Pivote->dato < getNodoXPos(hi)->dato)){
        	int aux = Pivote->dato;
        	Pivote->dato = getNodoXPos(hi)->dato;
        	getNodoXPos(hi)->dato = aux;
        	Pivote = getNodoXPos(hi);
        	
		}
    	while (lo<hi && getNodoXPos(lo)->dato < Pivote->dato) {
              lo++;
        }
        if(!(getNodoXPos(lo)->dato < Pivote->dato)){
        	int aux = Pivote->dato;
        	Pivote->dato = getNodoXPos(lo)->dato;
        	getNodoXPos(lo)->dato = aux;
        	Pivote = getNodoXPos(lo);
        	
		}
        
      }
    if (hi < lo) {
          int auxN = hi;
          hi = lo;
          lo = auxN;
    }
    quickSort(low, lo);
    quickSort(lo == low ? lo+1 : lo, n);
	
}

void mostrarLista(){
	Nodo *aux1 = primero;
	
	while(aux1!=NULL){
		cout<<aux1->dato<<" -> ";
		aux1 = aux1->siguiente;
		
	}
}



