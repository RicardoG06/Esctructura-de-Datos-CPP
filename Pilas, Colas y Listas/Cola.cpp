#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
}*primero = NULL, *ultimo = NULL;

void insertarNodo();
void desplegarCola();
void buscarNodo();
void modificarNodo();
void eliminarNodo();

int main(){
	int opcion_menu=0;
	do{
		cout<<endl << "|------------------------------------|";
		cout<<endl << "|               ° Cola °             |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << "| 1. Insertar      | 4. Eliminar     |";
		cout<<endl << "| 2. Buscar        | 5. Desplegar    |";
		cout<<endl << "| 3. Modificar     | 6. Salir        |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << endl << "Escoja una opcion: ";
		cin>>opcion_menu;
		switch(opcion_menu){
			case 1:
				cout<< endl << endl << "Inserta nodo en la cola" << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout<< endl << endl << "Buscar un nodo en la cola" << endl << endl;
				buscarNodo();
				break;
			case 3:
				cout<< endl << endl << "Modificar un nodo de la cola" << endl << endl;
				modificarNodo();
				break;
			case 4:
				cout<< endl << endl << "Eliminar un nodo de la cola" << endl << endl;
				eliminarNodo();
				break;
			case 5:
				cout<< endl << endl << "Desplegar cola de nodos" << endl << endl;
				desplegarCola();
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

// insertar 45,6,7,12

//cola    45 -> 6 -> 7 -> 12 -> NULL      


void insertarNodo(){
	nodo *nuevo = new nodo();
	cout <<"Ingrese el dato del nuevo nodo: ";
	cin>>nuevo->dato;
	
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
	cout<< endl << " Nodo Ingresado " << endl << endl;
}

void desplegarCola(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){
		while(actual!= NULL){
			cout << actual->dato << " -> ";
			actual = actual->siguiente;
		}
		cout << "NULL" <<endl;
	}
	else{
		cout << endl << " La cola se encuentra vacia "<< endl;
	}
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado =0;
	cout<<"Ingrese el dato del nodo a buscar: ";
	cin >>nodoBuscado;
	if(primero != NULL){
		while(actual!= NULL && encontrado != true){
			if (actual->dato == nodoBuscado){
				cout<< " Nodo con el dato (" << nodoBuscado << ") fue encontrado" << endl << endl;
				encontrado = true;
			}
			actual = actual->siguiente;
		}
		if (encontrado == false){
			cout << endl << " Nodo no encontrado" << endl;
		}
	}
	else{
		cout << endl << " La cola se encuentra vacia "<< endl;
	}	
}
void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado =0;
	cout<<"Ingrese el dato del nodo a buscar para modificar: ";
	cin >>nodoBuscado;
	if(primero != NULL){
		while(actual!= NULL && encontrado != true){
			
			if (actual->dato == nodoBuscado){
				cout<< "Nodo con el dato (" << nodoBuscado << ") fue encontrado" << endl << endl;
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
		cout << endl << " La cola se encuentra vacia "<< endl;
	}	
}
//cola    45 -> 6 -> 7 -> 12 -> NULL   
void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo *anterior = new nodo();
	anterior = NULL;
	
	bool encontrado = false;
	int nodoBuscado =0;
	cout<<"Ingrese el dato del nodo a buscar para eliminar: ";
	cin >>nodoBuscado;
	if(primero != NULL){
		while(actual!= NULL && encontrado != true){
			if (actual->dato == nodoBuscado){
				cout<< " Nodo con el dato (" << nodoBuscado << ") fue eliminado con exito." << endl << endl;
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if (encontrado == false){
			cout << endl << " Nodo no encontrado" << endl;
		}
	}
	else{
		cout << endl << " La cola se encuentra vacia "<< endl;
	}	
}




