/******************************************************************************

Definir de forma aleatoria una matriz de 5x6 de tipo double.
Usar funciones calcular la transpuesta, el valor máximo, el valor mínimo.
Buscar un valor específico definido por el usuario e indicar en que posición se encuentra.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define MATRIX_ROWS 5
#define MATRIX_COLUMNS 6
#define RAND_UPPER 45
#define RAND_LOWER 1

void init(double *nums);
void calculateResults(double *nums, double *numsTrans, double *minValue, double *maxValue, double *selectedNum);
void displayData(double *nums, double *numsTrans, double *minValue, double *maxValue, double * selectedNum);

int main(void){
  double nums[MATRIX_ROWS][MATRIX_COLUMNS];
  double numsTrans[MATRIX_COLUMNS][MATRIX_ROWS];
  double minValue, maxValue, selectedNum;

  initUtils();
  init((double *) nums);

  calculateResults((double *) nums, (double *) numsTrans, &minValue, &maxValue, &selectedNum);
  displayData((double *) nums, (double *) numsTrans, &minValue, &maxValue, &selectedNum);
  return 0;
}

void init(double *nums){
  matrixRows = MATRIX_ROWS;
  matrixColumns = MATRIX_COLUMNS;
  fillMatrixWithRandom((double *) nums, MATRIX_ROWS, MATRIX_COLUMNS, RAND_UPPER, RAND_LOWER);
  printf("- Initial Random Matrix:\n");
  displayMatrix((double *) nums, MATRIX_ROWS, MATRIX_COLUMNS);
}

void calculateResults(double *nums, double *numsTrans, double *minValue, double *maxValue, double *selectedNum){
  int row, column;
  getMatrixTransponse((double *) nums, (double *) numsTrans, MATRIX_ROWS, MATRIX_COLUMNS);
  *minValue = getMatrixMinVal((double *) nums, MATRIX_ROWS, MATRIX_COLUMNS);
  *maxValue = getMatrixMaxVal((double *) nums, MATRIX_ROWS, MATRIX_COLUMNS);
  printf("Select a matrix row: ");
  scanf("%d",&row);
  printf("Select a matrix column: ");
  scanf("%d",&column);
  *selectedNum = getValueInMatrix((double *) nums, row, column, MATRIX_ROWS);
}

void displayData(double *nums, double *numsTrans, double *minValue, double *maxValue, double *selectedNum){
  displayResultsHeader();
  printf("- Transponse Matrix:\n");
  displayMatrix((double *) numsTrans, MATRIX_COLUMNS, MATRIX_ROWS);
  printf("- Minimum value in matrix: %.2f\n",*minValue);
  printf("- Maximum value in matrix: %.2f\n",*maxValue);
  printf("- Selected value in matrix: %.2f\n",*selectedNum);

  displayEnd();
}