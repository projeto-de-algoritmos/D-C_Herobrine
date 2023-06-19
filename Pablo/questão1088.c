#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left; // Índice do subarray esquerdo
    int j = mid + 1; // Índice do subarray direito
    int k = left; // Índice do array temporário
    int inv_count = 0; // Contador de inversões

    // Mesclar os subarrays ordenando e contando as inversões
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // Incrementar o contador de inversões
        }
    }

    // Copiar os elementos restantes do subarray esquerdo (se houver)
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copiar os elementos restantes do subarray direito (se houver)
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copiar os elementos ordenados do array temporário de volta para o array original
    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }

    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // Dividir a sequência em partes menores
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Combinar as contagens de inversões das partes menores
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

char* determineWinner(int arr[], int n) {
    int temp[n]; // Array temporário para mesclar os subarrays

    int inversions = mergeSort(arr, temp, 0, n - 1);

    // Determinar o vencedor com base no número de inversões
    if (inversions % 2 == 0) {
        return "Carlos";
    } else {
        return "Marcelo";
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        char* winner = determineWinner(arr, n);
        printf("%s\n", winner);
    }

    return 0;
}