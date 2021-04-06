#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;


struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
}*arbol= NULL;

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
	}else{// Si el arbol tiene un nodo o más
		
		int valorRaiz = arbol->dato;//Obtenemos el valor de la raiz
		if(n<valorRaiz){//Si el elemento es menor a la raiz, insertamos en izq
			insertar(arbol->izq,n,arbol);
		}
		else{//Si el elemento es mayor a la raiz, insertamos en der
			insertar(arbol->der,n,arbol);
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

bool busqueda(Nodo *&arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n) {
		return true;	
	}
	else if(n<arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
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
void destruirNodo(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	
	delete nodo;
}

void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//arbol->padre hay que asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		//Procedemos a asigarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

//Funcion para determinar el nodo más izq posible
Nodo *minimo(Nodo *arbol){
	
	if(arbol == NULL){ //Si el arbol está vacio
		return NULL;
	}
	if(arbol->izq){ //Si tiene hijo izq posible
		return minimo(arbol->izq);
	}else{
		return arbol;
	}
}

void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){//Si el nodo tiene hijo der e izq 
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato= menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar,nodoEliminar->izq);//Si el nodo tiene hijo izq
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar,nodoEliminar->der); //Si el nodo tiene hijo der
		destruirNodo(nodoEliminar);
	}
	else{//No tiene hijos
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
	
}

void eliminar(Nodo *&arbol,int n){
	if(arbol==NULL){
		return;
	}
	else if(n < arbol->dato){ // Si el valor es menor
		eliminar(arbol->izq,n); // Busca por la izq
	}
	else if(n > arbol->dato){// Si el valor es mayor
		eliminar(arbol->der,n); // Busca por la der
	}
	else{
		eliminarNodo(arbol);
	}
}


void menu(){
	int dato,opc,contador=0;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en preOrden"<<endl;
		cout<<"5. Recorrer el arbol en inOrden"<<endl;
		cout<<"6. Recorrer el arbol en postOrden"<<endl;
		cout<<"7. Eliminar un nodo del arbol"<<endl;
		cout<<"8. Salir"<<endl;
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
			case 3: cout<<"Digite el elemento a buscar: ";
					cin>>dato;
					if(busqueda(arbol,dato)){
						cout<<"\nElemento"<<dato<<" ha sido encontrado en el arbol";
					}
					else{
						cout<<"\nElemento no encontrado\n";
					}
					cout<<"\n";
					break;
			case 4: cout<<"\nRecorrido en PreOrden: ";
					preOrden(arbol);
					cout<<"\n\n";
					break;
			case 5: cout<<"\nRecorrido en InOrden: ";
					inOrden(arbol);
					cout<<"\n\n";
					break;
			case 6: cout<<"\nRecorrido en PostOrden: ";
					postOrden(arbol);
					cout<<"\n\n";
					break;
			case 7: cout<<"\nDigite el numero a eliminar: ";
					cin>>dato;
					eliminar(arbol,dato);
					cout<<"\n\n";
					break;
			
		}
		system("pause");
		system("cls");
	}while(opc!=8);
}

int main(){
	
	menu();
	
	getch();
	return 0;
}
