// Madison Manankil
// cop 3502
// Lab 6
// Febuary 23,2024
#include <stdio.h>
#include <stdlib.h>
// This function is used to perform Binary search
int search(int numbers[], int low, int high, int value) {
  while (low <= high) { // while loop used to loop until the low is < or equal
                        // to the high point
    int mid = low + (high - low) / 2;
    // if statement saying if the value is found at the middle point THEN it
    // must return the index point of the value
    if (numbers[mid] == value) {
      return mid;
    } else if (numbers[mid] <
               value) { // Else statement used to tell if middle point is < than
                        // the value THENNN update the low pointedd index to the
                        // middle index
      low = mid + 1;
    } else { // represents that if the middle point is greater than the value
             // THEN it must update the high NDEX POInt
      high = mid - 1;
    }
  }
  // in the end if the value is not found in the array then it will return -1
  // rip
  return -1;
}
// this is function to print the the element ogf aray
void printArray(int numbers[], int sz) {
  int i;
  printf("Number array : "); // print
  for (i = 0; i < sz; ++i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

int main(void) {
  int i, numInputs;
  char *str;
  float average;
  int value;
  int index;
  int *numArray = NULL;
  int countOfNums;
  FILE *inFile = fopen("input.txt", "r");
  // this scans from the input txt file
  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &countOfNums); // reads the number of each inpu
    numArray = (int *)malloc(countOfNums * sizeof(int));
    average = 0;
    for (i = 0; i < countOfNums;
         i++) { // this is whats reads the information then calculates the
                // averages, then stores in aray
      fscanf(inFile, " %d", &value);
      numArray[i] = value;
      average += numArray[i];
    }
    // print array nums
    printArray(numArray, countOfNums);
    value = average / countOfNums;
    index =
        search(numArray, 0, countOfNums - 1,
               value); // This what binary search happens to find avg and print
    if (index >= 0) {
      printf("Item %d exists in the number array at index %d!\n", value, index);
    } else {
      printf("Item %d does not exist in the number array!\n", value);
    }

    free(numArray);
  }

  fclose(inFile);
}