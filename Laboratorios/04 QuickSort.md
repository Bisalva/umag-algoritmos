# QuickSort

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // pivote = último elemento
    int i = low - 1;         // índice del menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // pivote a su posición
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```


|Caso|Cuándo ocurre|Orden|
|---|---|---|
|**Mejor caso**|Pivote siempre divide a la mitad|O(n log n)|
|**Caso promedio**|Particiones razonablemente balanceadas|O(n log n)|
|**Peor caso**|Arreglo ya ordenado + pivote = último|O(n²)|

```c
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    printf("  Pivote elegido: %d  (subarreglo índices [%d..%d])\n",
           pivot, low, high);  // ← estudiante 1 propone esto

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
```

```c
// Agregar esta función auxiliar
void print_subarray(int arr[], int low, int high) {
    printf("  [ ");
    for (int i = low; i <= high; i++) printf("%d ", arr[i]);
    printf("]\n");
}

// Y llamarla al inicio de partition:
print_subarray(arr, low, high);
```