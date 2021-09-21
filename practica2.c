/*
Objetivo:	Implementar en C un codificador y un decodificador de
texto mediante la técnica de transposición por filas o 
columnas. Emplear funciones y apuntadores. Los elementos 
no usados de la matriz de codificación se deben rellenar 
con el carácter x.

Ejemplo:
Texto: DIME CON QUIEN ANDAS Y TE DIRE QUIEN ERES
Clave: 4 filas
Programa: Se debe guardar el texto en una matriz con 4 filas y añadir n caracteres “x” de relleno como en la Figura 1. La codificación se almacena en la matriz C. 
Pasos:
1.	Contabilizar las letras del mensaje.
2.	Dividir el número resultante por la clave de filas F (6) para obtener el valor de las columnas C.
3.	Escribir y almacenar el texto cifrado en filas de izquierda a derecha hasta la columna C, continuando con la fila siguiente hasta finalizar. 

*/
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// ====== GLOBALES ======
#define CLAVE 5
int rows = CLAVE;
int columns, orgStrLen, totalChars, orgStrLen;
char tempString[50];
char _encodedString[50];
char _decodedString[50];


void _encodeString(char *originalString, char **encodedString, char *testString);
void _decodeString(char *encodedString, char **decodedString);

int main(void){
    char *originalString;
    char *encodedString;
    char *testString;
    char *decodedString;
    int x;
    initUtils();
    for (x = 0; x < 5; x++){
      printf("Text: ");
      originalString = getString();

      orgStrLen = strlen(originalString);
      columns = orgStrLen / rows;
      if(orgStrLen % rows){
        columns++;
      }
      totalChars = columns * rows;

      _encodeString(originalString, &encodedString, testString);
      printf("Encoded: %s\n",_encodedString);
      _decodeString(encodedString, &decodedString);
      printf("Decoded: %s\n",_decodedString);
      displayEnd();
    }

    return 0;
}


void _encodeString(char *originalString, char **encodedString, char *testString){
  char matrix[rows][columns];
  int row, column, i, j, k = 0;
  
  //  Form matrix with encoded string 
  for (i = 0; i < totalChars; i++){
    column = i / CLAVE;
    row = i % CLAVE;
    if(i >= orgStrLen){
      matrix[row][column] = 'X';
    }else{
      matrix[row][column] = originalString[i];
    }
  }

  //  Print matrix with encoded string and obtain tempString
  for (i = 0; i < rows; i++){
    for (j = 0; j < columns; j++, k++){
      printf("%c ",matrix[i][j]);
      _encodedString[k] = matrix[i][j];
    }
    printf ("\n");
  }
  _encodedString[k] = '\0';
  *encodedString = _encodedString;
}

void _decodeString(char *encodedString, char **decodedString){
  char tempString[totalChars + 1];
  char matrix[rows][columns];
  int row, column, rslt, i, j, k = 0;
  //  De-form encodedString to obtain decodedString 
  for (i = 0; i < columns; i++){
    for (j = 0; j < rows; j++, k++){
      rslt = i + (j * columns);
      _decodedString[k] = encodedString[rslt];
    }
  }
  _decodedString[k] = '\0';  
  *decodedString = _decodedString;
}