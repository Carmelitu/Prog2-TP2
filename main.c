#include <stdio.h>
#include <stdlib.h>

// Estructura
typedef struct {
      char nombre[30];
      char genero;
      int edad;
}persona;

// Variables
int dimension = 30;
int arregloPersonas[30];

// Proto
int cargarPersonas (persona arreglo[], int dimension);
void mostrarPersonas (persona arreglo [], int validos);
int cantidadGenero (persona A[], int validos, char genero);
int posicionMenor (persona A[], int pos, int validos);
void ordenarPersonasSelec (persona A[], int validos);


int main()
{
    int validos = cargarPersonas(arregloPersonas, 30);
    mostrarPersonas(arregloPersonas, validos);
    int validosGenero = cantidadGenero(arregloPersonas, validos, 'm');
    ordenarPersonasSelec(arregloPersonas, validos);
    mostrarPersonas(arregloPersonas, validos);


    return 0;
}

/*  1. a. Crear un arreglo estático de 30 elementos de esta estructura y cargarlo mediante una función. */

int cargarPersonas (persona arreglo[], int dimension)
{
    int i = 0;
    char control = 's';

    while (i<dimension && control == 's')
    {
        printf("Ingrese el nombre de la persona: \n");
        fflush(stdin);
        gets(arreglo[i].nombre);

        printf("Ingrese el genero de la persona: m/f/n \n");
        fflush(stdin);
        scanf("%c", &arreglo[i].genero);

        printf("Ingrese la edad de la persona:\n");
        fflush(stdin);
        scanf("%i", &arreglo[i].edad);

        printf("Desea seguir ingresando alumnos? Ingrese s/n \n");
        fflush(stdin);
        scanf("%c", &control);

        i++;

    }
    return i;
}

void mostrarPersonas (persona arreglo [], int validos)
{
    int i=0;
    while(i<validos)
    {
        printf("\nEl nombre de la persona es: %s \n", arreglo[i].nombre);
        printf("La edad de la persona es: %d \n", arreglo[i].edad);
        printf("El genero de la persona es: %c \n", arreglo[i].genero);
        i++;
    }
}



 /*   b. Hacer una función que cuente la cantidad de un género determinado. */

 int cantidadGenero (persona A[], int validos, char genero)
{
    int i = 0;
    int validosGenero = 0;
    for (i=0; i<validos; i++)
    {
        if (genero == A[i].genero)
        {
            validosGenero++;
        }
    }
    return validosGenero;
}

 /*   c. Hacer una función que copie los datos de todos los registros de un género determinado del arreglo anterior en otro arreglo del tamaño justo.
    Usar malloc dentro de la función y retornarlo o usar dos parámetros de tipo arreglo y crear el arreglo dinámico antes de la invocación. */

/* 2. Codificar el algoritmo de ordenamiento por selección, sobre la estructura anterior teniendo en cuenta la edad como criterio de ordenación. */

int posicionMenor (persona A[], int pos, int validos)
{
    int menor = A[pos].edad;
    int posmenor = pos;
    int i = pos +1;
    while (i<validos)
    {
        if (menor > A[i].edad)
        {
            menor = A[i].edad;
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenarPersonasSelec (persona A[], int validos)
{
    int posmenor = 0;
    persona aux;
    int i = 0;
    while (i<validos-1)
    {
        posmenor = posicionMenor(A,i,validos);

        aux = A[posmenor];
        A[posmenor] = A[i];
        A[i] = aux;

        i++;
    }
}
