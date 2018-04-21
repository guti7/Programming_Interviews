/*
* Finds the maximum value stored in an array of non-negative integers. 
* The size of the array is `n`.
* Demonstrates two approaches for educational purposes:
* "compare to max" and "compare to all" 
*
* Programming Interviews Exposed, 3rd, Mongan, Giguere, Kindler
* Created by @guti7 on April 14 2018
*/

#include <stdio.h>
#include <stdbool.h>

// Prototypes
int compareToMax(int array[], int n);
int compareToAll(int array[], int n);

int main(void) {
  int array[] = { 11, 1, 3, 9, 0 };
  int size = sizeof(array) / sizeof(array[0]);
  
  int maxCompareToMax = compareToMax(array, size);
  int maxCompareToAll = compareToAll(array, size);
  
  printf("Array max:\n");
  printf("compareToMax(): %i\n", maxCompareToMax);
  printf("compareToAll(): %i\n", maxCompareToAll);
  
  return 0;
}

/* 
 * Returns the largest value in an array of non-negative integers 
 * Keeps track of the current largerst number as the function iterates
 * through the array and returns that value at end of iterations.
 * 
 * Analysis:
 * Each array element is compared once to a maximum value. 
 * The `n` input items are examined once, resulting in `n` examinations:
 * Linear time: O(n).
 * The time required to run the algorithm increases linearly with the number
 * of input items.
 * 
 */
int compareToMax(int array[], int n) {
  int currMax, i;
  
  // Check for valid array size
  if (n <= 0) {
    return -1;
  }
  
  // Set largest number so far to initial element
  currMax = array[0];
  
  // Compare every element with the largest seen so far
  for (i = 1; i < n; i++) {
    if (array[i] > currMax) {
      currMax = array[i];
    }
  }
  
  return currMax;
}

/*
 * Compares each value to all the other values. If all other values are less
 * than or equal to a given value, that value must be the maximum value.
 * 
 * Analysis:
 * An intial assumption is made to where the largest number is located.
 * Assuming the array is at the end/start of the array, the function may compare
 * `n` elements to `n` other elements, doing n*n examinations: O(n^2)
 * 
 */
int compareToAll(int array[], int n) {
  
  int i, j;
  bool isMax;
  
  // Check for valid array size
  if (n <= 0) {
    return -1;
  }
  
  for (i = 0; i < n; i++) {
    isMax = true; // element at i is set to be the current max until you find one greater
    for (j = n - 1; j > 0; j--) {
      // check for any value greater than current at `i`
      if (array[j] > array[i]) {
        isMax = false;
        break; // Stop checking and move to next `i`
      }
    }
    
    if (isMax) {
      break; // if you didn't find a greater one after one comparison with all elements
    }
  }
  
  // Element at `i` is the max (when the outer loop was terminated)
  return array[i];
}

