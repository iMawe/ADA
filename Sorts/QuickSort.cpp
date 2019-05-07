#include<stdlib.h> 
#include<stdio.h>
#include <time.h>
#include <iostream>

using namespace std;
  

/* C++ implementation of QuickSort using Hoare's 
   partition scheme. */
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[low]; 
    int i = low - 1, j = high + 1; 
  
    while (true) { 
  
        // Find leftmost element greater than 
        // or equal to pivot 
        do { 
            i++; 
        } while (arr[i] < pivot); 
  
        // Find rightmost element smaller than 
        // or equal to pivot 
        do { 
            j--; 
        } while (arr[j] > pivot); 
  
        // If two pointers met. 
        if (i >= j) 
            return j; 
  
        swap(arr[i], arr[j]); 
    } 
} 
  
// Generates Random Pivot, swaps pivot with 
// end element and calls the partition function 
// In Hoare partition the low element is selected 
// as first pivot 
int partition_r(int arr[], int low, int high) 
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random], arr[low]); 
  
    return partition(arr, low, high); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition_r(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi); 
        quickSort(arr, pi + 1, high); 
    } 
} 


// Driver program to test above functions 
int main() 
{ 
    int num, tam = 1000000; 
    int arr[tam];
    int arr_size = sizeof(arr)/sizeof(arr[0]); 

    

    srand(time(NULL));

    int X[tam];

    for(int i = 0; i < tam; i++){
        num = 1 + rand() % (101 - 1);
        X[i] = num; 
    }

    unsigned t0, t1;

    t0 = clock();
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    t1 = clock();
     
    double time = (double(t1 - t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0; 
} 