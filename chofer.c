/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define GAS_TANK 50
#define GAS_PRICE 15
#define KM_PER_LT 17

#define DIST_1 120
#define DIST_2 400
#define DIST_3 250
#define GAS_1 0.25
#define GAS_2 0.5
#define GAS_3 0.75
#define GAS_4 1

int main(){
  const float distances[3] = {DIST_1,DIST_2,DIST_3};
  const float gas_qty[4] = {GAS_1,GAS_2,GAS_3,GAS_4};
  float dist, initial_gas, gas_needed, money_needed;
  int input;

  printf("1) Destiny #1 - %dkm\n",DIST_1);
  printf("2) Destiny #2 - %dkm\n",DIST_2);
  printf("3) Destiny #3 - %dkm\n",DIST_3);
  printf("Enter destiny: ");
  scanf("%d",&input);
  dist = distances[input-1];
  printf("=================");
  printf("\n1) 1/4 tank\n");
  printf("2) 1/2 tank\n");
  printf("3) 3/4 tank\n");
  printf("4) Full tank\n");
  printf("Enter initial gas: ");
  scanf("%d",&input);
  initial_gas = gas_qty[input-1] * GAS_TANK;
  printf("=================\n");

  gas_needed = (dist / KM_PER_LT) - initial_gas;
  if(gas_needed < 0){
    gas_needed = 0;
  }
  money_needed = gas_needed * GAS_PRICE;

  printf("Gas needed: %f Money needed: %f",gas_needed,money_needed);
  return 0;
}
