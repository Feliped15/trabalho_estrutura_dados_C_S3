#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void swap(int arrValores[], int a, int b);
void imprimir(int arrValores[], int tamanho);
int particiona(int arrValores[], int inicio, int fim);
void quickSort(int arrValores[], int inicio, int fim);
int medianaDeTres(int arrValores[], int inicio, int meio, int fim);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int valores[] = {7, 12, 10, 8, 5, 19, 3, 90, 12};
    int qtd = sizeof(valores) / sizeof(valores[0]);

    quickSort(valores, 0, qtd - 1);

    imprimir(valores, qtd);
}

void swap(int arrValores[], int a, int b)
{
    int aux;

    aux = arrValores[a];
    arrValores[a] = arrValores[b];
    arrValores[b] = aux;
}

void imprimir(int arrValores[], int tamanho)
{
    int f = 0;

    for (f = 0; f < tamanho; f++)
    {
        printf("Posicao %i: %i\n", f, arrValores[f]);
    }
}

int medianaDeTres(int arrValores[], int inicio, int meio, int fim)
{
    if (arrValores[inicio] > arrValores[meio])
        swap(arrValores, inicio, meio);

    if (arrValores[inicio] > arrValores[fim])
        swap(arrValores, inicio, fim);

    if (arrValores[meio] > arrValores[fim])
        swap(arrValores, meio, fim);

    return meio;
}

int particiona(int arrValores[], int inicio, int fim)
{
    int meio = inicio + (fim - inicio) / 2;
    int pivotIndex = medianaDeTres(arrValores, inicio, meio, fim);
    int pivot = arrValores[pivotIndex];

    swap(arrValores, pivotIndex, fim);

    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (arrValores[j] <= pivot)
        {
            i++;
            swap(arrValores, i, j);
        }
    }

    i++;
    swap(arrValores, i, fim);

    return i;
}

void quickSort(int arrValores[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int indexPivot = particiona(arrValores, inicio, fim);
        quickSort(arrValores, inicio, indexPivot - 1);
        quickSort(arrValores, indexPivot + 1, fim);
    }
}