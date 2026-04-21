#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100;

typedef struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
    Tarea T;
    Nodo *Siguiente;
} Nodo;

Nodo * CrearListaVacia();
Nodo * CrearNodo(int tarea, char * descripcion, int duracion);

int main(){
    Nodo * TareasPendientes;
    TareasPendientes=CrearListaVacia();

}

Nodo * CrearListaVacia(){
    return NULL;
}

Nodo * CrearNodo(int tarea, char * descripcion, int duracion){
    Nodo * nuevoNodo= (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T.TareaID=tarea;
    nuevoNodo->T.Duracion=duracion;
    char buffer[MAX];
}