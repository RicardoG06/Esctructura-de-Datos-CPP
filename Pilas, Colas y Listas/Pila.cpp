#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
}*primero = NULL;


void insertarNodo();
void desplegarPila();
void buscarNodo();
void modificarNodo();
void eliminarNodo();

int main(){
	int opcion_menu=0;
	do{
		cout<<endl << "|------------------------------------|";
		cout<<endl << "|               ° Pila °             |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << "| 1. Insertar      | 4. Eliminar     |";
		cout<<endl << "| 2. Buscar        | 5. Desplegar    |";
		cout<<endl << "| 3. Modificar     | 6. Salir        |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << endl << "Escoja una opcion: ";
		cin>>opcion_menu;
		switch(opcion_menu){
			case 1:
				cout<< endl << endl << "Inserta nodo en la pila" << endl << endl;
				insertarNodo();
				break;
			case 2:
				buscarNodo();
				cout<< endl << endl << "Buscar un nodo en la pila" << endl << endl;
				break;
			case 3:
				cout<< endl << endl << "Modificar un nodo de la pila" << endl << endl;
				modificarNodo();
				break;
			case 4:
				cout<< endl << endl << "Eliminar un nodo de la pila" << endl << endl;
				eliminarNodo();
				break;
			case 5:
				cout<< endl << endl << "Desplegar pila de nodos" << endl << endl;
				desplegarPila();
				break;
			case 6:
				cout<< endl << endl << "Programa finalizado..." << endl << endl;
				break;
			default:
				cout<< endl << endl << "Opcion no valida" << endl << endl;
		} 
	}while (opcion_menu != 6);
	
	return 0;
}

//Si ingreso un 4, luego 7 y luego 5 :
//Pila -   5 -> 7-> 4 -> Null

void insertarNodo(){
	nodo *nuevo = new nodo();
	cout<<"Ingrese el dato que contendra el nuevo Nodo: ";
	cin>>nuevo->dato;
	nuevo->siguiente = primero;
	primero = nuevo;	
	
	cout<<" Nodo Ingresado " <<endl<<endl;
}

void desplegarPila(){
	nodo *actual = new nodo();
	actual = primero;
	if (primero!= NULL){
		while(actual!=NULL){
			cout<< endl << " " <<"| "<< actual->dato<<" |";
			actual = actual->siguiente;
		}
	}
	else{
		cout <<endl <<" La Pila se encuentra vacia" <<endl << endl;
	}
}

void buscarNodo(){
	
	nodo *actual = new nodo();
	actual = primero;
	int nodobuscado =0;
	bool encontrado = false;
	cout<<" Ingrese el dato del Nodo a buscar: ";
	cin >> nodobuscado;
	
	if (primero!= NULL){
		while(actual!=NULL && encontrado != true){
			if (actual->dato == nodobuscado){
				encontrado = true;
				cout<< " Nodo con el dato (" << nodobuscado << ") fue encontrado" << endl << endl;
			}
			actual = actual->siguiente;
		}
		if (encontrado == false){
			cout << endl << " Nodo no encontrado" << endl;
		}
	}
	else{
		cout <<endl <<" La Pila se encuentra vacia" <<endl << endl;
	}
}

void modificarNodo(){
	nodo *actual = new nodo();
	actual = primero;
	int nodobuscado =0;
	bool encontrado = false;
	cout<<" Ingrese el dato del Nodo a buscar para modificar: ";
	cin >> nodobuscado;
	
	if (primero!= NULL){
		while(actual!=NULL && encontrado != true){
			if (actual->dato == nodobuscado){
				cout<< "Nodo con el dato (" << nodobuscado << ") fue encontrado" << endl << endl;
				cout<<"Ingrese el nuevo dato para este Nodo: ";
				cin>> actual->dato;
				cout<<endl<< "Nodo modificado" <<endl <<endl;
				encontrado = true;
			}
			actual = actual->siguiente;
		}
		if (encontrado == false){
			cout << endl << " Nodo no encontrado" << endl;
		}
	}
	else{
		cout <<endl <<" La Pila se encuentra vacia" <<endl << endl;
	}	
}

void eliminarNodo(){
	nodo *actual = new nodo();
	actual = primero;
	nodo *anterior = new nodo();
	anterior = NULL;
		
	int nodobuscado =0;
	bool encontrado = false;
	cout<<" Ingrese el dato del Nodo a buscar para eliminar: ";
	cin >> nodobuscado;
	
	if (primero!= NULL){
		while(actual!=NULL && encontrado != true){
			if (actual->dato == nodobuscado){
				encontrado = true;
				cout<< " Nodo con el dato (" << nodobuscado << ") fue encontrado" << endl;
				if(actual == primero){
					primero = primero ->siguiente;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				cout<< endl <<" Nodo eliminado" <<endl << endl;
				
			}
			anterior = actual;
			actual = actual ->siguiente;
		}
		if (encontrado == false){
			cout << endl << " Nodo no encontrado" << endl;
		}
	}
	else{
		cout <<endl <<" La Pila se encuentra vacia" <<endl << endl;
	}
}

