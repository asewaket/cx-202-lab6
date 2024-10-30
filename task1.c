#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b;

    // Prompt the user for the size of each vector
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    // Allocate memory dynamically for the arrays
    int *x = (int*)malloc(n * sizeof(int));
    int *y = (int*)malloc(n * sizeof(int));
    int *z = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (x == NULL || y == NULL || z == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read scalar values and vector elements
    printf("Enter the scalar values a and b: ");
    scanf("%d %d", &a, &b);

    printf("Enter the elements of vector x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter the elements of vector y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    // Compute the axpy operation
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + b * y[i];
    }

    // Print the result vector z
    printf("The result vector z is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(x);
    free(y);
    free(z);

    return 0;
}
