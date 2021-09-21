/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 20
#define UPPER 45
#define LOWER 1

void _init(int nums[], int randNums[], int retVal[], int *suma);
void _displayData(int nums[], int randNums[], int retVal[], int suma);
void _printArray(int arraySize, int array[]);

int main(void){
  int nums[ARRAY_LEN];
  int randNums[ARRAY_LEN];
  int retVal[ARRAY_LEN];
  int suma = 0;

  _init(nums, randNums, retVal, &suma);
  _displayData(nums, randNums, retVal, suma);
  return 0;
}

void _init(int nums[], int randNums[], int retVal[], int *suma){
  int i;
  printf("Program started...\n");
  srand(time(0));

  for (i = 0; i < ARRAY_LEN; i++){
    printf("Nums[%d]: ",i);
    scanf("%d",&nums[i]);
    randNums[i]= (rand() % (UPPER - LOWER + 1)) + LOWER;
    retVal[i] = randNums[i] * nums[i];
    *suma += nums[i];
  }
}

void _displayData(int nums[], int randNums[], int retVal[], int suma){
  printf("\n====================================================================================\n");
  printf("===================================== RESULTS ======================================\n");
  printf("====================================================================================\n\n");

  printf("nums: ");
  _printArray(ARRAY_LEN,nums);
  printf("suma: %d\n", suma);

  printf("randNums: ");
  _printArray(ARRAY_LEN,randNums);

  printf("retVal: ");
  _printArray(ARRAY_LEN,retVal);

  printf("\n\n\n");
}

void _printArray(int arraySize, int array[]){
  int i;
  for (i = 0; i < arraySize; i++){
    printf("%d", array[i]);
    if(i == arraySize - 1){
      printf("\n");
    }else{
      printf(", ");
    }
  }
}
