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
#define CLAVE 4
int rows = CLAVE;
int columns, orgStrLen, totalChars, orgStrLen;
char *_tempString;


void _encodeString(char *originalString, char **encodedString);
void _decodeString(char *encodedString, char **decodedString);

int main(void){
    char *originalString;
    char *encodedString;
    char *decodedString;

    initUtils();
    printf("Text: ");
    originalString = getString();

    orgStrLen = strlen(originalString);
    columns = orgStrLen / rows;
    if(orgStrLen % rows){
      columns++;
    }
    totalChars = columns * rows;

    _encodeString(originalString, &encodedString);
    printf("encodedString: %s\n",encodedString);
    printf("encodedString: %p\n",encodedString);
    printf("encodedString: %p\n",&encodedString);
    _tempString = encodedString;
    _decodeString(encodedString, &decodedString); // ! Send correct encodedString
    printf("\n\nDecoded: %s\n",decodedString);
    displayEnd();
    return 0;
}


void _encodeString(char *originalString, char **encodedString){
  char tempString[totalChars + 1];
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
      tempString[k] = matrix[i][j];
    }
    printf ("\n");
  }
  tempString[k] = '\0';
  *encodedString = tempString;
  //encodedString = tempString;
  printf("tempString: %s\n",tempString);
  printf("tempString: %p\n",&tempString);
  printf("encodedString: %s\n",encodedString);
  printf("encodedString: %p\n",encodedString);
  printf("encodedString: %p\n",&encodedString);
  printf(" === BACK TO MAIN === \n");
}

void _decodeString(char *encodedString, char **decodedString){ // ! Update params with correct econdedString data type
  char *encString = "hsoXlXaX"; // ! Remove 
  char tempString[totalChars + 1];
  char matrix[rows][columns];
  int row, column, rslt, i, j, k = 0;
  //printf("\nHERE 1: %s\n",encString);
  printf(" === ON DECODE FUNCTION === \n");
  printf("encodedString: %s\n",encodedString); // ! Recieve correct econdedString
  printf("encodedString: %p\n",encodedString); // ! Recieve correct econdedString
  printf("encodedString: %p\n",&encodedString); // ! Recieve correct econdedString

  printf("_tempString: %s\n",_tempString); // ! Recieve correct econdedString
  printf("_tempString: %p\n",_tempString); // ! Recieve correct econdedString
  printf("_tempString: %p\n",&_tempString); // ! Recieve correct econdedString
  printf(" === BACK TO MAIN === \n");

  //  De-form encodedString to obtain decodedString 
  for (i = 0; i < columns; i++){
    for (j = 0; j < rows; j++, k++){
      rslt = i + (j * 2);
      tempString[k] = encString[rslt];
      // ! tempString[k] = encodedString[rslt];
    }
  }
  tempString[k] = '\0';  
  *decodedString = tempString;
}