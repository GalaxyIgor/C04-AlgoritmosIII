#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left; // Início do subvetor esquerdo
    int j = mid + 1; // Início do subvetor direito
    int k = left; // Início do subvetor temporário
    int inv_count = 0;

    // Mergir os subvetores enquanto conta as inversões
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // Contar inversões
        }
    }

    // Copiar os elementos restantes do subvetor esquerdo, se houver
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copiar os elementos restantes do subvetor direito, se houver
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copiar os elementos do vetor temporário de volta para o vetor original
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    int temp[N]; // Array temporário para auxiliar na ordenação e contagem

    // Leitura do vetor
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Contar inversões
    int inv_count = mergeSortAndCount(arr, temp, 0, N - 1);

    // Imprimir o resultado
    cout << inv_count << endl;

    return 0;
}
/*Uma inversão em um vetor é um par de elementos tal que i < j e v[i] > v[j], ou seja, 
se tivermos um elemento que aparece antes no vetor, porém tem um valor maior que o elemento que aparece depois, 
chamamos isso de inversão. Com essa definição, faça um programa que utilize da estratégia de divisão 
e conquista para contar quantas inversões temos em um vetor qualquer.

Entrada
A primeira linha contém um inteiro N que é o número de elementos no vetor. 
Seguem N números que serão inseridos no vetor.

Saída
O programa deve mostrar o número de inversões contidas no vetor.

Exemplo de Entrada:  
Ex1
5
1 3 5 2 4
Ex2
6
9 5 6 4 7 1

Exemplo de Saída
Ex1
3
Ex2
11
*/