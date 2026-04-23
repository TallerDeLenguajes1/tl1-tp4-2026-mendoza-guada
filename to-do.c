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
Nodo * BuscarTarea(Nodo *Lista, int id);
void MostrarListasPendientes (Nodo *cabeza);

int main(){
    Nodo * C_TareasPendientes, *TareasPendientes;
    C_TareasPendientes=CrearListaVacia();
    srand(time(NULL));

    int opcion;
    int ultimoID=999;
    do {
        printf("\n\n=====================MENU=====================\n");
        printf("Elija la opción de la tarea a realizar: \n\n1- Ingresar una nueva tarea pendiente. \n2- Marcar una tarea como completada.\n3- Chequear la lista de tareas pendientes.\n4- Buscar una tarea por ID.\n5- Salir\n");
        printf("==============================================\n");
        scanf("%d", &opcion);
        switch (opcion){
            case 1:{
                printf("Ingrese la descripción de la tarea: ");
                char buffer[MAX];
                getchar();
                //scanf("%s", buffer);
                fgets(buffer, MAX, stdin);
                int lenght_buffer=strlen(buffer);
                char *descripcion= (char *) malloc(sizeof(char)*(lenght_buffer+1));
                strcpy(descripcion, buffer);
                int tarea_duracion=10+rand()%91;
                ultimoID++;
                int tarea_id=ultimoID;
                TareasPendientes=CrearNodo(tarea_id, descripcion, tarea_duracion);
                InsertarNodo(&C_TareasPendientes, TareasPendientes);
                }
                printf("\n\nTarea ID %d agregada a TAREAS PENDIENTES.\n---------------------------------\n", ultimoID);
            break;
            case 3: {
                printf("\n--------TAREAS PENDIENTES--------\n");
                MostrarListasPendientes(C_TareasPendientes);
            }
            break;
            case 4:{
                int id_b;
                printf("\nIndicar el ID a buscar: ");
                scanf("%d", &id_b);
                Nodo * buscado;
                buscado= BuscarTarea(C_TareasPendientes, id_b);
                if(buscado!=NULL){
                    printf("\nID Tarea: %d\nDescripción tarea: %s\nDuración: %d minutos.\n\n ", buscado->T.TareaID, buscado->T.Descripcion, buscado->T.Duracion);
                } else {
                    printf("\nNo se encontró una tarea con ese ID.\n\n");
                }
            }
            break;
            case 5:{
                exit(0);
            }
            break;
        }
       /* if (opcion==1){
            printf("\n\n========================\n NUEVA TAREA PENDIENTE \n========================\n");
         printf("\nIngrese su nombre: ")
            
*/
            // ESTO NO IRA EN EL IF PERO VOY A PROBAR POR ACÁ HASTA QUE MODIFIQUE LA INTERFAZ //
           
    } while (opcion!=5);

    getchar();
    return 0;
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

Nodo * BuscarTarea(Nodo *cabeza, int id_buscado){
    Nodo * Aux = cabeza;
    while (Aux && Aux->T.TareaID != id_buscado){
        Aux=Aux->Siguiente;
    }
    return Aux;
}

void MostrarListasPendientes (Nodo *cabeza){
    Nodo * aux;
    aux=cabeza;
    if(aux!=NULL){
        while(aux!=NULL){
            printf("\nID Tarea: %d\nDescripción tarea: %s\nDuración: %d minutos.\n------------\n ", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
            aux=aux->Siguiente;
        }
    }else{
        printf("\nNo hay tareas pendientes.\n");
    }
}