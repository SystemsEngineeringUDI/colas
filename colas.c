/*
@autor:
 * César Villalobos
 * Estudiante: Ing.Sistemas UDI
 * 29/09/2018
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int dato;
	struct node* sgte;
}*nodo,TipoDato;

typedef struct{
	nodo primero;
	nodo ultimo;
	int longitud;
}*cola,tipoCola;

cola crearCola(){
	cola queue=(cola)(malloc(sizeof(tipoCola)));
	queue->primero=NULL;
	queue->ultimo=NULL;
	queue->longitud=0;
	return queue;
}

nodo crearnodo(int valor){
	nodo elemento=(nodo)malloc(sizeof(nodo));
	elemento -> dato=valor;
	elemento -> sgte=NULL;
	return elemento;
}

void encolar(int valor,cola queue){
	nodo nuevo=crearnodo(valor);
	if(queue->primero==NULL && queue->ultimo==NULL){
		queue->primero=nuevo;
		queue->ultimo=nuevo;
		nuevo->sgte=NULL;
	}else{
		queue->ultimo->sgte=nuevo;
		queue->ultimo=nuevo;
		nuevo->sgte=NULL;
	}
	queue->longitud++;
}

int desencolar(cola queue){
	int dato;
	if(queue->primero==queue->ultimo){
		dato=queue->primero->dato;
		queue->primero=NULL;
		queue->ultimo=NULL;
	}else{
		dato=queue->primero->dato;
		queue->primero=queue->primero->sgte;
	}
	queue->longitud--;
	return dato;
}

int front(cola queue){
	int dato;
	dato=queue->primero->dato;
	return dato;
}

int colaTamano(cola queue){
	return queue->longitud;
}

int colaVacia(cola queue){
	return(queue->primero==NULL);
}

int main(){

}

