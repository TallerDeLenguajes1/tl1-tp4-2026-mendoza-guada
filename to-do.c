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
Nodo * CrearNodo(int tarea, /*char * descripcion,*/ int duracion);

int main(){
    Nodo * TareasPendientes;
    TareasPendientes=CrearListaVacia();
    srand(time(NULL));

    int opcion;
    printf("\nElija la opción de la tarea a realizar: \n\n1- Ingresar una nueva tarea pendiente. \n2- Marcar una tarea como completada.\n3- Chequear la lista de tareas pendientes.\n");
    scanf("%d", &opcion);
    if (opcion==1){
        printf("\n\n========================\n\n====NUEVA TAREA PENDIENTE====\n========================\n");
       /* printf("\nIngrese su nombre: ")*/
        int tarea_duracion=10+rand()%100;
        int tarea_id=1000+rand();
        TareasPendientes=CrearNodo(tarea_id, tarea_duracion);
    }
    

}

Nodo * CrearListaVacia(){
    return NULL;
}

Nodo * CrearNodo(int tarea, /*char * descripcion,*/ int duracion){
    Nodo * nuevoNodo= (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T.TareaID=tarea;
    nuevoNodo->T.Duracion=duracion;
    /*char buffer[MAX];*/
    nuevoNodo->Siguiente=NULL;

    return nuevoNodo;
}