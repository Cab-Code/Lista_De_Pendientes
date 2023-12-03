#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

void agregarPendiente(char pendiente[]){
    FILE *db = fopen("dataBase.txt","a");
        if (db == NULL){
        printf("Error al abrir el archivo");
    }
    fputs(pendiente, db);
    fclose(db);
}

void eliminarPendientes(int item, int i, char originalDatos[][101]){
    strcpy(originalDatos[item], "");

        
        FILE *db = fopen("dataBase.txt", "w");
        fputs("", db);
        fclose(db);

        db = fopen("dataBase.txt", "a");
        int elmi = 0;

        while(elmi < i){
            fputs(originalDatos[elmi], db);
            elmi = elmi + 1;
        }
        fclose(db);
}

int cli(){
    system("cls");
    printf("\n****************************************************************************************************\n");
    printf("***************************************-LISTA DE PENDIENTES-****************************************\n");
    printf("****************************************************************************************************\n");
        
    int i = 0;
    char originalDatos[100][101];
    FILE *db = fopen("dataBase.txt","r");
    if (db == NULL){
        printf("Error al abrir el archivo");
    }
    while (feof(db) ==0){ 
            fgets (originalDatos[i], 101, db); 
            i = i + 1;
            int k = 0;
        }
    fclose(db);
    int j = 0;
    
    while(j < i){
        printf("| %d |  %s\n",j , originalDatos[j]); 
        j = j + 1;
    }
    printf("\n");

    char accion[10];
    scanf("%s", &accion);

    if(strcmp(accion, "agregar") == 0){
        char newPendiente[101];
        printf("| %d |", i - 1);
        strcpy(originalDatos[i -1 ], " ");
        fflush(stdin);
        fgets(newPendiente, 101, stdin);
        agregarPendiente(newPendiente);
        cli();
    }
    else if(strcmp(accion, "eliminar") == 0){
        int item = 0;
        scanf("%d", &item);
        eliminarPendientes(item, i, originalDatos);
        cli();


    }
    else if(strcmp(accion, "salir") == 0){
        printf("Cerrando programa ...");
    }
    else{
        printf("----------------------Comando inexistente----------------------");
        int v = 0;
        fflush(stdin);
        getchar();
        cli();
    }
}

int main (int argc, char *argv[]){
    char command[5];
    if(argv[1] == NULL){
        strcpy(command, "-gui");
    }else{
        strcpy(command, argv[1]);
    }

    if(strcmp(command, "-cli") == 0){
        cli();
    }
    else if(strcmp(command, "-gui") == 0){
        printf("Funcionamiento GUI:");
    }
    else if(strcmp(command, "-hlp") == 0){
        system("cls");
        printf("\n\nArgumentos de inicio de programa:\n\n");
        printf("-cli : Inicia el programa con vista en Linea de comandos\n");
        printf("    Comandos dentro de la vista cli\n");
        printf("        agregar : Permite que en la siguiete linea se agregue un pendiente al final de la lista\n");
        printf("        eliminar : Elimina el Pendiente especificado mediante su numero de indice\n");
        printf("        salir : Cierra el programa de manera segura\n");
        printf("-gui : Inicia el programa con vista Interfaz Grafica\n");
        printf("-hlp : Muestra los comandos validos a utilizarse en el programa\n\n");

    }
    else{
        printf("Comando inexistente");
    }

}

