#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int comparisons = 0;
static int swaps = 0;

void *good (int N, long long int *array) {
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }
}

void *bad (int N, long long int *array) {
    for (int i = 0; i < N; ++i) {
        array[i] = N - i - 1;
    }
}

void *generate (int N, long long int *array) {
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        array[i] = rand() * rand() * rand() * rand() * rand();
    }
}

void *bubblesort (int N, long long int *array) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            comparisons++;
            if (array[j] > array[j + 1]) {
                long long int ch = array[j];
                array[j] = array[j + 1];
                array[j + 1] = ch;
                swaps++;
            }
        }
    }
}

void ShellsSort(int N, long long int *array) {
    int i,j,k;
    long long int t;
    for(k = N/2; k > 0; k /=2) {
        for (i = k; i < N; i++) {
            t = array[i];
            for (j = i; j >= k; j -= k) {
                comparisons++;
                if (t < array[j - k]) {
                    array[j] = array[j - k];
                    swaps++;
                }
                else
                    break;
            }
            array[j] = t;
        }
    }
}

int main(void) {
    int N = 0;
    printf("Enter a size of array\n");
    N = 10000;
    long long int *array = malloc(N * sizeof(long long int));
    printf("Good variant\n");
    good(N, array);
    bubblesort(N, array);
    printf("BubbleSort\n");
    printf("%d %d \n", comparisons, swaps);
    comparisons = 0;
    swaps = 0;
    good(N, array);
    ShellsSort(N, array);
    printf("ShellSort\n");
    printf("%d %d \n", comparisons, swaps);
    comparisons = 0;
    swaps = 0;
    printf("\n");
    printf("Bad variant\n");
    bad(N, array);
    bubblesort(N, array);
    printf("BubbleSort\n");
    printf("%d %d \n", comparisons, swaps);
    comparisons = 0;
    swaps = 0;
    bad(N, array);
    ShellsSort(N, array);
    printf("ShellSort\n");
    printf("%d %d \n", comparisons, swaps);
    comparisons = 0;
    swaps = 0;
    printf("\n");
    printf("Random variant\n");
    generate(N, array);
    bubblesort(N, array);
    printf("BubbleSort\n");
    printf("%d %d \n", comparisons, swaps);
    comparisons = 0;
    swaps = 0;
    generate(N, array);
    ShellsSort(N, array);
    printf("ShellSort\n");
    printf("%d %d \n", comparisons, swaps);
    comparisons = 0;
    swaps = 0;
    printf("\n");
    free(array);
    return 0;
}