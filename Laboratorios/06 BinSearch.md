# BinSearch

### Archivo `binsearch.c` a implementar

```c
int binsearch_iterativo(int arr[], int n, int objetivo) {  
    printf("Aun no implementado...\n");  
}  
  
int binsearch_recursivo(int arr[], int izq, int der, int objetivo) {  
    printf("Aun no implementado...\n");  
}  
  
/* ─── Main ──────────────────────────────────────────────────────────────── */  
  
int main(void) {  
    int arr[]  = {1, 3, 7, 9, 15, 20, 28, 36, 42, 51};  
    int n      = sizeof(arr) / sizeof(arr[0]);  
    int objetivo = 28;  
  
    /* Llamada a la versión recursiva */  
    //int resultado = binsearch_recursivo(arr, 0, n - 1, objetivo);  
  
    /* resultado == índice encontrado  (ó -1 si no existe) */  
    //printf("Objetivo: arr[%d] = %d\n", resultado, arr[resultado]);  
    return 0;  
}
```