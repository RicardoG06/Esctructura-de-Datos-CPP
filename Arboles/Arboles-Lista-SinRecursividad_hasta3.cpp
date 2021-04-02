#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;


struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
}*arbol= NULL, *aux = NULL, *arbol1=NULL, *arbol2=NULL;

Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}
//Funcion para insertar elementos en el arbol
void insertar(Nodo *&arbol, int n, Nodo *padre){
	
	if(arbol == NULL){//Si el arbol está vacio
		Nodo *nuevo_nodo = crearNodo(n,padre);
		arbol = nuevo_nodo;
	}else{	// Si el arbol tiene un nodo o más
		
		int valorRaiz = arbol->dato;//Obtenemos el valor de la raiz
		if(n<valorRaiz){
			if(arbol->izq == NULL){//Si el arbol está vacio
				Nodo *nuevo_nodo = crearNodo(n,arbol);
				arbol->izq = nuevo_nodo;
			}else{
				int valorRaiz = arbol->izq->dato;//Obtenemos el valor de la raiz
				if(n<valorRaiz){
					if(arbol->izq->izq == NULL){//Si el arbol está vacio
						Nodo *nuevo_nodo = crearNodo(n,arbol->izq);
						arbol->izq->izq = nuevo_nodo;}
					else{
						cout<<"Solo se puede insertar hasta el nivel 3.";
					}
				}
				else{
					if(arbol->izq->der == NULL){//Si el arbol está vacio
						Nodo *nuevo_nodo = crearNodo(n,arbol->izq);
						arbol->izq->der = nuevo_nodo;}
					else{
						cout<<"Solo se puede insertar hasta el nivel 3.";
					}
				}
			}				
		}	
		else{//Si el elemento es mayor a la raiz, insertamos en der
			if(arbol->der == NULL){//Si el arbol está vacio
				Nodo *nuevo_nodo = crearNodo(n,arbol);
				arbol->der = nuevo_nodo;
			}else{
				int valorRaiz = arbol->der->dato;//Obtenemos el valor de la raiz
				if(n<valorRaiz){	
					if(arbol->der->izq == NULL){//Si el arbol está vacio
						Nodo *nuevo_nodo = crearNodo(n,arbol->der);
						arbol->der->izq = nuevo_nodo;}
					else{
						cout<<"Solo se puede insertar hasta el nivel 3.";
					}
				}else{
					if(arbol->der->der == NULL){//Si el arbol está vacio
						Nodo *nuevo_nodo = crearNodo(n,arbol->der);
						arbol->der->der = nuevo_nodo;}
					else{
						cout<<"Solo se puede insertar hasta el nivel 3.";
					}
				}
			}
		}	
	}
}
void mostrarArbol(Nodo *&arbol,int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}


void preOrden(Nodo *&arbol){
	
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(Nodo *&arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *&arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

//Funcion para destruir un nodo


void menu(){
	int dato,opc,contador=0;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Recorrer el arbol en preOrden"<<endl;
		cout<<"4. Recorrer el arbol en inOrden"<<endl;
		cout<<"5. Recorrer el arbol en postOrden"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion : ";
		cin>>opc;
		
		switch(opc){
			case 1:	cout<<"\nDigite un numero: ";
					cin>>dato;
					insertar(arbol,dato,NULL);
					cout<<"\n";
					break;
			case 2: cout<<"\nMostrando el arbol completo:\n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n";
					break;
			case 3: cout<<"\nRecorrido en PreOrden: ";
					preOrden(arbol);
					cout<<"\n\n";
					break;
			case 4: cout<<"\nRecorrido en InOrden: ";
					inOrden(arbol);
					cout<<"\n\n";
					break;
			case 5: cout<<"\nRecorrido en PostOrden: ";
					postOrden(arbol);
					cout<<"\n\n";
					break;
			
		}
		system("pause");
		system("cls");
	}while(opc!=6);
}

int main(){
	
	menu();
	
	getch();
	return 0;
}
