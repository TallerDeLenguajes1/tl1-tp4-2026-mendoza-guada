#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

typedef struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo * Siguiente;
} Nodo;

Nodo * CrearListaVacia();
Nodo * CrearNodo(int tarea, char * descripcion, int duracion);
void InsertarNodo(Nodo ** cabeza, Nodo *nuevoNodo);

int main(){
    Nodo * C_TareasPendientes, *TareasPendientes;
    C_TareasPendientes=CrearListaVacia();
    srand(time(NULL));

    int opcion;
    printf("\nElija la opción de la tarea a realizar: \n\n1- Ingresar una nueva tarea pendiente. \n2- Marcar una tarea como completada.\n3- Chequear la lista de tareas pendientes.\n");
    scanf("%d", &opcion);
    char buffer[MAX];
    int ultimoID=999;
    if (opcion==1){
        printf("\n\n========================\n NUEVA TAREA PENDIENTE \n========================\n");
       /* printf("\nIngrese su nombre: ")*/
        printf("Ingrese la descripción de la tarea: ");
        scanf("%s", buffer);
        int lenght_buffer=strlen(buffer);
        char *descripcion= (char *) malloc(sizeof(char)*(lenght_buffer+1));
        strcpy(descripcion, buffer);
        int tarea_duracion=10+rand()%100;
        ultimoID++;
        int tarea_id=ultimoID;
        TareasPendientes=CrearNodo(tarea_id, descripcion, tarea_duracion);
        InsertarNodo(&C_TareasPendientes, TareasPendientes);
        
    }
    

}

Nodo * CrearListaVacia(){
    return NULL;
}

Nodo * CrearNodo(int tarea, char * descripcion, int duracion){
    Nodo * nuevoNodo= (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T.TareaID=tarea;
    nuevoNodo->T.Duracion=duracion;
    nuevoNodo->T.Descripcion=descripcion;
    nuevoNodo->Siguiente=NULL;

    return nuevoNodo;
}

void InsertarNodo(Nodo ** cabeza, Nodo *nuevoNodo){
    nuevoNodo->Siguiente= *cabeza;
    *cabeza=nuevoNodo;
}