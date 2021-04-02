#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
	nodo *atras;
}*primero = NULL, *ultimo=NULL;

void insertarNodo();
void desplegarListaPU();
void desplegarListaUP();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void insertarNodoInicio();
void insertarXPos();
int main(){
	int     opcion_menu=0;
	do{
		cout<<endl << "|------------------------------------|";
		cout<<endl << "|           ° Lista Doble°           |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << "| 1. Insertar      | 6. DesplegarPU  |";
		cout<<endl << "| 2. Ins.porIni.   | 7. DesplegarUP  |";
		cout<<endl << "| 3. Buscar        | 8. AgregarXPos  |";
		cout<<endl << "| 4. Modificar     | 9. Salir        |";
		cout<<endl << "| 5. Eliminar      |                 |";
		cout<<endl << "|------------------|-----------------|";
		cout<<endl << endl << "Escoja una opcion: ";
		cin>>opcion_menu;
		switch(opcion_menu){
			case 1:
				cout<< endl << endl << "Inserta nodo en la lista doble" << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout<< endl << endl << "Inserta nodo por el inicio en la lista doble" << endl << endl;
				insertarNodoInicio();
				break;
			case 3:
				cout<< endl << endl << "Buscar un nodo en la lista doble" << endl << endl;
				buscarNodo();
				break;
			case 4:
				cout<< endl << endl << "Modificar un nodo de la lista doble" << endl << endl;
				modificarNodo();
				break;
			case 5:
				cout<< endl << endl << "Eliminar un nodo de la lista doble" << endl << endl;
				eliminarNodo();
				break;
			case 6:
				cout<< endl << endl << "Desplegar lista doble de nodos desde el primero al ultimo" << endl << endl;
				desplegarListaPU();
				break;
			case 7:
				cout<< endl << endl << "Desplegar lista doble de nodos desde el ultimo al primero" << endl << endl;
				desplegarListaUP();
				break;
			case 8:
				cout<< endl << endl << "Agregar por posicion en la lista doble" << endl << endl;
				insertarXPos();
				break;
			case 9:
				cout<< endl << endl << "Programa finalizado..." << endl << endl;
				break;
			
			default:
				cout<< endl << endl << "Opcion no valida" << endl << endl;
		} 
	}while (opcion_menu != 9);
	
	return 0;
}

void insertarNodo(){
	nodo *nuevo = new nodo();
	cout <<"Ingrese el dato que contendra el nuevo nodo: ";
	cin >> nuevo->dato;
	
	if (primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}
	else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n ";
}

void insertarNodoInicio(){
	nodo *nuevo = new nodo();
	cout <<"Ingrese el dato del nuevo nodo: ";
	cin>>nuevo->dato;
	nuevo->siguiente = primero;
	primero->atras = nuevo;
	primero=nuevo;
}



void desplegarListaPU(){
	nodo *actual = new nodo();
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

void desplegarListaUP(){
	nodo *actual = new nodo();
	actual = ultimo;
	if(primero != NULL){
		while(actual!= NULL){
			cout << actual->dato << " <- ";
			actual = actual->atras;
		}
		cout << "NULL" <<endl;
	}
	else{
		cout << endl << " La lista simple se encuentra vacia "<< endl;
	}
}

void buscarNodo(){
	nodo *actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Nodo a Buscar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!= NULL && encontrado!= true){
			if (actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado <<" ) encontrado.\n";
				encontrado = true;
			}


			actual = actual->siguiente;
		}
		if(!encontrado){
			cout<< "\n Nodo no encontrado\n";
		}
	}else{
		cout << endl << " La lista simple se encuentra vacia "<< endl;
	}
}

void modificarNodo(){
	nodo *actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del Nodo a Buscar para modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!= NULL && encontrado!= true){
			if (actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado <<" ) encontrado.\n";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin>> actual->dato;
				cout<<endl<< "Nodo modificado" <<endl <<endl;
				encontrado = true;
			}
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout<< "\n Nodo no encontrado\n";
		}
	}else{
		cout << endl << " La lista simple se encuentra vacia "<< endl;
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
					primero->atras = NULL;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
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
	nodo *anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int posicion =0;
	int x = 1;
	cout<<"\nIngrese la posicion donde quiere ingresar un dato ";
	cin >>posicion;
	if(primero != NULL){
		while(actual!= NULL && encontrado != true){
			if (x == posicion - 1){
				
				nuevo->siguiente = actual->siguiente;
				actual->siguiente->atras = nuevo;
				actual->siguiente = nuevo;
				nuevo->atras = actual;
				
				cout<<"\n Nodo agregado con exito.";
				encontrado = true;
			}
			anterior = actual;
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



