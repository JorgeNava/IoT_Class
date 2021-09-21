/******************************************************************************

Hacer un programa utilizando estructuras para almacenar los datos de un 
trabajador de una empresa para guardar la información de un trabajador fijo 
y otro temporal, teniendo en cuenta los siguientes campos: nombre, apellido, 
edad, puesto. Emplear una función de paso por referencia para imprimir la 
estructura del trabajador fijo y temporal.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct trabajador{
  char nombre[20];
  char apellido[20];
  char puesto[20];
  int edad;
};
typedef struct trabajador Trabajador;

void _init(Trabajador *pers1, Trabajador *pers2);
void _displayResults(Trabajador *pers1, Trabajador *pers2);

int main(void){
  Trabajador persona1, persona2;
  Trabajador *pers1 = &persona1;
  Trabajador *pers2 = &persona2;
  
  _init(pers1, pers2);
  _displayResults(pers1, pers2);
  return 0;
}

void _init(Trabajador *pers1, Trabajador *pers2){
  initUtils();
  strcpy(pers1->nombre,"Jorge");
  strcpy(pers1->apellido,"Nava");
  strcpy(pers1->puesto,"Fijo");
  pers1->edad = 21;

  strcpy(pers2->nombre,"Nathali");
  strcpy(pers2->apellido,"Moreno");
  strcpy(pers2->puesto,"Temporal");
  pers2->edad = 19;
}

void _displayResults(Trabajador *pers1, Trabajador *pers2){
  if(!strcmp(pers1->puesto,"Fijo") && !strcmp(pers2->puesto,"Fijo")){
    printf("Ambos, %s %s y %s %s, son trabajadores fijos", pers1->nombre, pers1->apellido, pers2->nombre, pers2->apellido);
  }else if(!strcmp(pers1->puesto,"Fijo")){
    printf("%s %s es un trabajador fijo.",pers1->nombre, pers1->apellido);
  }else if(!strcmp(pers2->puesto,"Fijo")){
    printf("%s %s es un trabajador fijo.",pers2->nombre, pers2->apellido);
  }else{
    printf("Ambos, %s %s y %s %s, son trabajadores fijos", pers1->nombre, pers1->apellido, pers2->nombre, pers2->apellido);
  }
  displayEnd();
}