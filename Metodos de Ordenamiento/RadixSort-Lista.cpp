#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
}*primero = NULL, *ultimo=NULL;

typedef struct Nodo *Cola0;
Cola0 primero0;
Cola0 ultimo0;

typedef struct Nodo *Cola1;
Cola1 primero1;
Cola1 ultimo1;

typedef struct Nodo *Cola2;
Cola1 primero2;
Cola1 ultimo2;

typedef struct Nodo *Cola3;
Cola1 primero3;
Cola1 ultimo3;

typedef struct Nodo *Cola4;
Cola1 primero4;
Cola1 ultimo4;

typedef struct Nodo *Cola5;
Cola1 primero5;
Cola1 ultimo5;

typedef struct Nodo *Cola6;
Cola1 primero6;
Cola1 ultimo6;

typedef struct Nodo *Cola7;
Cola1 primero7;
Cola1 ultimo7;

typedef struct Nodo *Cola8;
Cola1 primero8;
Cola1 ultimo8;

typedef struct Nodo *Cola9;
Cola1 primero9;
Cola1 ultimo9;

void insertarNodo(int dato);
void mostrarLista();
void CrearCola0(int n);
void CrearCola1(int n);
void CrearCola2(int n);
void CrearCola3(int n);
void CrearCola4(int n);
void CrearCola5(int n);
void CrearCola6(int n);
void CrearCola7(int n);
void CrearCola8(int n);
void CrearCola9(int n);
void MandarListaAlasCola();
void ColocarUnidadesenlaLista();

int main(){
	//12,9,4,99
	//,120,1,3,10,13
	insertarNodo(12);
	insertarNodo(98);
	insertarNodo(45);
	insertarNodo(99);
	insertarNodo(120);
	insertarNodo(16);
	insertarNodo(31);
	insertarNodo(10);
	insertarNodo(13);
	cout<<"\n\n";
	mostrarLista();	
	MandarListaAlasCola();
	ColocarUnidadesenlaLista();
	cout<<"\n\n";
	mostrarLista();	
	
	
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

void mostrarLista(){
	Nodo *aux1 = primero;
	if(primero != NULL){
		while(aux1!= NULL){
			cout << aux1->dato << " -> ";
			aux1 = aux1->siguiente;
		}
		cout << "NULL" <<endl;
	}
	else{
		cout << endl << " La lista simple se encuentra vacia "<< endl;
	}
}

void CrearCola0(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero0 == NULL){
		primero0 = nuevo;
		primero0->siguiente = NULL;
		ultimo0 = primero0;
	}
	else{
		ultimo0->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo0 = nuevo;
	}
}

void CrearCola1(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero1 == NULL){
		primero1 = nuevo;
		primero1->siguiente = NULL;
		ultimo1 = primero1;
	}
	else{
		ultimo1->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo1 = nuevo;
	}
}

void CrearCola2(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero2 == NULL){
		primero2 = nuevo;
		primero2->siguiente = NULL;
		ultimo2 = primero2;
	}
	else{
		ultimo2->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo2 = nuevo;
	}
}

void CrearCola3(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero3 == NULL){
		primero3 = nuevo;
		primero3->siguiente = NULL;
		ultimo3 = primero3;
	}
	else{
		ultimo3->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo3 = nuevo;
	}
}

void CrearCola4(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero4 == NULL){
		primero4 = nuevo;
		primero4->siguiente = NULL;
		ultimo4 = primero4;
	}
	else{
		ultimo4->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo4 = nuevo;
	}
}

void CrearCola5(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero5 == NULL){
		primero5 = nuevo;
		primero5->siguiente = NULL;
		ultimo5 = primero5;
	}
	else{
		ultimo5->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo5 = nuevo;
	}
}

void CrearCola6(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero6 == NULL){
		primero6 = nuevo;
		primero6->siguiente = NULL;
		ultimo6 = primero6;
	}
	else{
		ultimo6->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo6 = nuevo;
	}
}

void CrearCola7(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero7 == NULL){
		primero7 = nuevo;
		primero7->siguiente = NULL;
		ultimo7 = primero7;
	}
	else{
		ultimo7->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo7 = nuevo;
	}
}

void CrearCola8(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero8 == NULL){
		primero8 = nuevo;
		primero8->siguiente = NULL;
		ultimo8 = primero8;
	}
	else{
		ultimo8->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo8 = nuevo;
	}
}

void CrearCola9(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	
	if(primero9 == NULL){
		primero9 = nuevo;
		primero9->siguiente = NULL;
		ultimo9 = primero9;
	}
	else{
		ultimo9->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo9 = nuevo;
	}
}

void MandarListaAlasCola(){
	Nodo *aux1 = primero;
	Nodo *anterior = NULL;
	while(aux1!=NULL){
		if(aux1->dato % 10 == 0){
			CrearCola0(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 1){
			CrearCola1(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 2){
			CrearCola2(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 3){
			CrearCola3(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 4){
			CrearCola4(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}		
		else if(aux1->dato % 10 == 5){
			CrearCola5(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 6){
			CrearCola6(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 7){
			CrearCola7(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		else if(aux1->dato % 10 == 8){
			CrearCola8(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}	
		else if(aux1->dato % 10 == 9){
			CrearCola9(aux1->dato);
			if(aux1 == primero){
				primero = primero->siguiente;
			}else if(aux1 == ultimo){
				anterior->siguiente = NULL;
				ultimo = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		anterior = aux1;
		aux1 = aux1->siguiente;	
	}
}

void ColocarUnidadesenlaLista(){
	Nodo *aux0 = primero0;
	Nodo *aux1 = primero1;
	Nodo *aux2 = primero2;
	Nodo *aux3 = primero3;
	Nodo *aux4 = primero4;
	Nodo *aux5 = primero5;
	Nodo *aux6 = primero6;
	Nodo *aux7 = primero7;
	Nodo *aux8 = primero8;
	Nodo *aux9 = primero9;	
	Nodo *anterior = NULL;
	
	while(aux0 != NULL){
		if(aux0 != NULL){
			insertarNodo(aux0->dato);
			if(aux0 == primero0){
				primero0 = primero0->siguiente;
			}else if(aux0 == ultimo0){
				anterior->siguiente = NULL;
				ultimo0 = anterior;
			}else{
				anterior->siguiente = aux0->siguiente;
			}
		}
		anterior = aux0;
		aux0 = aux0->siguiente;
	}
	while(aux1 != NULL){
		if(aux1 != NULL){
			insertarNodo(aux1->dato);
			if(aux1 == primero1){
				primero1 = primero1->siguiente;
			}else if(aux1 == ultimo1){
				anterior->siguiente = NULL;
				ultimo1 = anterior;
			}else{
				anterior->siguiente = aux1->siguiente;
			}
		}
		anterior = aux1;
		aux1 = aux1->siguiente;
	}
	while(aux2 != NULL){
		if(aux2 != NULL){
			insertarNodo(aux2->dato);
			if(aux2 == primero2){
				primero2 = primero2->siguiente;
			}else if(aux2 == ultimo2){
				anterior->siguiente = NULL;
				ultimo2 = anterior;
			}else{
				anterior->siguiente = aux2->siguiente;
			}
		}
		anterior = aux2;
		aux2 = aux2->siguiente;
	}
	while(aux3 != NULL){
		if(aux3 != NULL){
			insertarNodo(aux3->dato);
			if(aux3 == primero3){
				primero3 = primero3->siguiente;
			}else if(aux3 == ultimo3){
				anterior->siguiente = NULL;
				ultimo3 = anterior;
			}else{
				anterior->siguiente = aux3->siguiente;
			}
		}
		anterior = aux3;
		aux3 = aux3->siguiente;
	}
	while(aux4 != NULL){
		if(aux4 != NULL){
			insertarNodo(aux4->dato);
			if(aux4 == primero4){
				primero4 = primero4->siguiente;
			}else if(aux4 == ultimo4){
				anterior->siguiente = NULL;
				ultimo4 = anterior;
			}else{
				anterior->siguiente = aux4->siguiente;
			}
		}
		anterior = aux4;
		aux4 = aux4->siguiente;
	}
	while(aux5 != NULL){
		if(aux5 != NULL){
			insertarNodo(aux5->dato);
			if(aux5 == primero5){
				primero5 = primero5->siguiente;
			}else if(aux5 == ultimo5){
				anterior->siguiente = NULL;
				ultimo5 = anterior;
			}else{
				anterior->siguiente = aux5->siguiente;
			}
		}
		anterior = aux5;
		aux5 = aux5->siguiente;
	}
	while(aux6 != NULL){
		if(aux6 != NULL){
			insertarNodo(aux6->dato);
			if(aux6 == primero6){
				primero6 = primero6->siguiente;
			}else if(aux6 == ultimo6){
				anterior->siguiente = NULL;
				ultimo6 = anterior;
			}else{
				anterior->siguiente = aux6->siguiente;
			}
		}
		anterior = aux6;
		aux6 = aux6->siguiente;
	}
	while(aux7 != NULL){
		if(aux7 != NULL){
			insertarNodo(aux7->dato);
			if(aux7 == primero7){
				primero7 = primero7->siguiente;
			}else if(aux7 == ultimo7){
				anterior->siguiente = NULL;
				ultimo7 = anterior;
			}else{
				anterior->siguiente = aux7->siguiente;
			}
		}
		anterior = aux7;
		aux7 = aux7->siguiente;
	}
	while(aux8 != NULL){
		if(aux8 != NULL){
			insertarNodo(aux8->dato);
			if(aux8 == primero3){
				primero8 = primero8->siguiente;
			}else if(aux8 = ultimo8){
				anterior->siguiente = NULL;
				ultimo8 = anterior;
			}else{
				anterior->siguiente = aux8->siguiente;
			}
		}
		anterior = aux8;
		aux8 = aux8->siguiente;
	}
	while(aux9 != NULL){
		if(aux9 != NULL){
			insertarNodo(aux9->dato);
			if(aux9 == primero9){
				primero9 = primero9->siguiente;
			}else if(aux9 == ultimo9){
				anterior->siguiente = NULL;
				ultimo9 = anterior;
			}else{
				anterior->siguiente = aux9->siguiente;
			}
		}
		anterior = aux9;
		aux9 = aux9->siguiente;
	}		
}






