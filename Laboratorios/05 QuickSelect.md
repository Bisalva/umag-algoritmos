
# QuickSelect

### archivo `quickselect.c`

```c
#include <stdio.h>  
  
void swap(int *a, int *b);  
int partition(int arr[], int low, int high);  
int quickselect(int arr[], int low, int high, int k);
  
void swap(int *a, int *b) {  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
int partition(int arr[], int low, int high) {  
    int pivot = arr[high];  
    int i = low - 1;  
  
    for (int j = low; j < high; j++) {  
        if (arr[j] <= pivot) {  
            i++;  
            swap(&arr[i], &arr[j]);  
    }  
    }  
    swap(&arr[i + 1], &arr[high]); // Siempre pone al pivote en su posición.  
    return i + 1;  
}  
  
int quickselect(int arr[], int low_idx, int high_idx, int k_idx_elem) {

    int pivot_idx = partition(arr, low_idx, high_idx);      
      
    if (pivot_idx == k_idx_elem)       
        return arr[pivot_idx];      
    else if (k_idx_elem < pivot_idx)   
           return quickselect(arr, low_idx, pivot_idx - 1, k_idx_elem);
    else               
        return quickselect(arr, pivot_idx + 1, high_idx, k_idx_elem);  
}  
  
int main() {  
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    int k = 1;                                              // Índice buscado (0-based): k=2 → 3er elemento más pequeño  
    int resultado = quickselect(arr, 0, n - 1, k);         // Llama a quickselect sobre el arreglo completo  
    printf("\nEl elemento %d-ésimo más pequeño es: %d\n", k + 1, resultado); // Muestra el resultado final  
    return 0;  
}
```


### Diferencia entre QuickSort y QuickSelect

En vez de función `quicksort`, se tiene:

```c
int quickselect(int arr[], int low_idx, int high_idx, int k_idx_elem) {

    int pivot_idx = partition(arr, low_idx, high_idx);      
      
    if (pivot_idx == k_idx_elem)       
        return arr[pivot_idx];      
    else if (k_idx_elem < pivot_idx)   
           return quickselect(arr, low_idx, pivot_idx - 1, k_idx_elem);
    else               
        return quickselect(arr, pivot_idx + 1, high_idx, k_idx_elem);  
}  
```