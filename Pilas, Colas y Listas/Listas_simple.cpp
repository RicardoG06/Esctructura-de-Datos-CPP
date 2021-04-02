#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
}*primero = NULL, *ultimo=NULL;

void insertarNodo();
void desplegarLista();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void insertarNodoInicio();
void insertarXPos();

int main(){
	int     opcion_menu=0;
	do{
		cout<<endl << "|------------------------------------|";
		cout<<endl << "|           ° Lista Simple°          |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << "| 1. Insertar      | 5. Eliminar     |";
		cout<<endl << "| 2. Ins.porIni.   | 6. Desplegar    |";
		cout<<endl << "| 3. Buscar        | 7. AgregarXPos  |";
		cout<<endl << "| 4. Modificar     | 8. Salir        |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << endl << "Escoja una opcion: ";
		cin>>opcion_menu;
		switch(opcion_menu){
			case 1:
				cout<< endl << endl << "Inserta nodo en la lista simple" << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout<< endl << endl << "Inserta nodo por el inicio en la lista simple" << endl << endl;
				insertarNodoInicio();
				break;
			case 3:
				cout<< endl << endl << "Buscar un nodo en la lista simple" << endl << endl;
				buscarNodo();
				break;
			case 4:
				cout<< endl << endl << "Modificar un nodo de la lista simple" << endl << endl;
				modificarNodo();
				break;
			case 5:
				cout<< endl << endl << "Eliminar un nodo de la lista simple" << endl << endl;
				eliminarNodo();
				break;
			case 6:
				cout<< endl << endl << "Desplegar lista simple de nodos" << endl << endl;
				desplegarLista();
				break;      
			case 7:
				cout<< endl << endl << "Agregar por posicion en la lista simple" << endl << endl;
				insertarXPos();
				break;
			case 8:
				cout<< endl << endl << "Programa finalizado..." << endl << endl;
				break;
			default:
				cout<< endl << endl << "Opcion no valida" << endl << endl;
		} 
	}while (opcion_menu != 8);
	
		
	return 0;
}

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


void insertarNodoInicio(){
	nodo *nuevo = new nodo();
	cout <<"Ingrese el dato del nuevo nodo: ";
	cin>>nuevo->dato;
	nuevo->siguiente = primero;
	primero=nuevo;
}


void desplegarLista(){
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
		cout << endl << " La lista simple se encuentra vacia "<< endl;
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
				cout<< " Nodo con el dato (" << nodoBuscado << ") fue encontrado." << endl << endl;
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				cout<<"\n Nodo Eliminado con exito.";
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

void insertarXPos(){
	nodo* nuevo = new nodo();
	cout<<"\nIngrese el dato que desea agregar: ";
	cin >>nuevo->dato;
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int posicion =0;
	int x = 1;
	cout<<"\nIngrese la posicion donde quiere ingresar un dato ";
	cin >>posicion;
	if(primero != NULL){
		while(actual!= NULL && encontrado != true){
			if (x == posicion - 1){
				
				nuevo->siguiente = actual->siguiente;
				actual->siguiente = nuevo;
				
				cout<<"\n Nodo agregado con exito.";
				encontrado = true;
			}
			actual = actual->siguiente;
			x = x +1;
		}
		if (encontrado == false){
			cout << endl << " Nodo no encontrado" << endl;
		}
	}
	else{
		cout << endl << " La cola se encuentra vacia "<< endl;
	}	
}

