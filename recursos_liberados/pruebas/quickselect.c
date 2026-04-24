#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
int quickselect(int arr[], int low, int high, int k); // Nueva firma: recibe k (índice buscado)

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

int quickselect(int arr[], int low_idx, int high_idx, int k_idx_elem) { // Busca el k-ésimo elemento más pequeño (índice 0-based)
    int pivot_idx = partition(arr, low_idx, high_idx);                 // Ubica el pivote en su posición final
    
    printf("Este es mi pivote:D %d\n",pivot_idx);
    
    if (pivot_idx == k_idx_elem) {           // Caso base: el pivote ya es el k-ésimo elemento
        return arr[pivot_idx];      // Retorna el valor encontrado
    } else if (k_idx_elem < pivot_idx) {     // El k-ésimo está en la mitad izquierda
       	printf("Recursividad izq: [%d - %d]\n", low_idx, pivot_idx -1);
	       return quickselect(arr, low_idx, pivot_idx - 1, k_idx_elem);     // Recursión solo por la izquierda
    } else {                // El k-ésimo está en la mitad derecha
			    //
       	printf("Recursividad def: [%d - %d]\n", pivot_idx + 1, high_idx);
        return quickselect(arr, pivot_idx + 1, high_idx, k_idx_elem);    // Recursión solo por la derecha
    }
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 1;                                              // Índice buscado (0-based): k=2 → 3er elemento más pequeño
    int resultado = quickselect(arr, 0, n - 1, k);         // Llama a quickselect sobre el arreglo completo
    printf("\nEl elemento %d-ésimo más pequeño es: %d\n", k, resultado); // Muestra el resultado final
    return 0;
}
