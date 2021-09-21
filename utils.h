#include <time.h>
#include <string.h>

// ===== GLOBAL VARIABLES =====
#define CHUNK 10
int matrixRows, matrixColumns;
int randUpperLimit, randLowerLimit;

// ============================

void initUtils()
{
  printf("====================================================================================\n");
  printf("================================== PROGRAM START ===================================\n");
  printf("====================================================================================\n\n");
  srand(time(0));
}

int getRandNumRange(int upper, int lower)
{
  return (rand() % (upper - lower + 1)) + lower;
}

void displayArray(int arraySize, int array[])
{
  int i;
  for (i = 0; i < arraySize; i++)
  {
    printf("%d", array[i]);
    if (i == arraySize - 1)
    {
      printf("\n");
    }
    else
    {
      printf(", ");
    }
  }
}

//* USE: displayMatrixOfDoubles((double *) nums, MATRIX_ROWS, MATRIX_COLUMNS);
void displayMatrixOfDoubles(double *matrix, int rows, int columns){
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      printf("%.2f", *((matrix + (i * rows + j))));
      if (j == columns - 1)
      {
        printf("\n");
      }
      else
      {
        printf(" | ");
      }
    }
    printf("\n");
  }
}

//* USE: displayMatrixOfChars((char *) nums, MATRIX_ROWS, MATRIX_COLUMNS);
void displayMatrixOfChars(char *matrix, int rows, int columns){
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      printf("%c", *((matrix + (i * rows + j))));
      if (j == columns - 1)
      {
        printf("\n");
      }
      else
      {
        printf(" | ");
      }
    }
    printf("\n");
  }
}

void fillMatrixWithInput(double *matrix, int rows, int columns)
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns + 1; j++)
    {
      printf("m[%d][%d] - %d: ", i, j, ((matrix + i * rows) + j));
      scanf("%f", ((matrix + i * rows) + j));
    }
  }
}

void fillMatrixWithRandom(double *matrix, int rows, int columns, int upper, int lower)
{
  int i, j, add;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      *(matrix + ((i * rows) + j)) = (double)getRandNumRange(upper, lower);
    }
  }
}

//================== TESTING ==================
void displayMatrixOfDoubles2(double matrix[matrixRows][matrixColumns])
{
  int i, j;
  for (i = 0; i < matrixRows; i++)
  {
    for (j = 0; j < matrixColumns; j++)
    {
      printf("%.2f", matrix[i][j]);
      if (j == matrixColumns - 1)
      {
        printf("\n");
      }
      else
      {
        printf(" | ");
      }
    }
    printf("\n");
  }
}
void fillMatrixWithRandom2(double (*matrix)[matrixColumns], int upper, int lower)
{
  int i, j, add;
  for (i = 0; i < matrixRows; i++)
  {
    for (j = 0; j < matrixColumns; j++)
    {
      matrix[i][j] = (double)getRandNumRange(upper, lower);
    }
  }
}
//===========================================

void getMatrixTransponse(double *matrix, double *transponse, int rows, int columns)
{
  int i, j;
  double temp;
  for (i = 0; i < columns; i++)
  {
    for (j = 0; j < rows; j++)
    {
      temp = *((matrix + j * rows) + i);
      *((transponse + i * columns) + j) = temp;
    }
  }
}

double getMatrixMinVal(double *matrix, int rows, int columns)
{
  int i, j;
  double minValue = 99999.0, temp;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      temp = *(matrix + ((i * rows) + j));
      if (temp < minValue)
      {
        minValue = temp;
      }
    }
  }
  return minValue;
}

double getMatrixMaxVal(double *matrix, int rows, int columns)
{
  int i, j;
  double maxValue = -99999.0, temp;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      temp = *(matrix + ((i * rows) + j));
      if (temp > maxValue)
      {
        maxValue = temp;
      }
    }
  }
  return maxValue;
}

double getValueInMatrix(double *matrix, int row, int column, int rows)
{
  double selectedValue;
  selectedValue = *(matrix + (row * rows + column));
  return selectedValue;
}

void displayResultsHeader()
{
  printf("\n====================================================================================\n");
  printf("===================================== RESULTS ======================================\n");
  printf("====================================================================================\n\n");
}

void displayEnd()
{
  printf("\n\n====================================================================================\n");
  printf("=================================== PROGRAM END ====================================\n");
  printf("====================================================================================\n\n");
}

//================== EXTERN ==================
//* USE: strcpy(originalString, getString());
char *getString()
{
  char *line = NULL, *tmp = NULL;
  size_t size = 0, index = 0;
  int ch = EOF;

  while (ch)
  {
    ch = getc(stdin);

    /* Check if we need to stop. */
    if (ch == EOF || ch == '\n')
      ch = 0;

    /* Check if we need to expand. */
    if (size <= index)
    {
      size += CHUNK;
      tmp = realloc(line, size);
      if (!tmp)
      {
        free(line);
        line = NULL;
        break;
      }
      line = tmp;
    }

    /* Actually store the thing. */
    line[index++] = ch;
  }

  return line;
}

int getStringSize(char *s)
{
  char *t;
  int size = 0;
  for (t = s; *t != '\0'; t++)
  {
    size++;
  }
  return size;
}