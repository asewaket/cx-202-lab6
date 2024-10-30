#include <stdio.h>
#include <stdlib.h>

int main() {
    int *samples = NULL;
    int num_samples = 0, sample, average;

    while (1) {
        printf("Enter a sample integer value: ");
        scanf("%d", &sample);

        // Reallocate memory for the new sample
        samples = (int*)realloc(samples, (num_samples + 1) * sizeof(int));
        if (samples == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        samples[num_samples] = sample;
        num_samples++;

        printf("Do you want to add more samples? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // Calculate the average
    average = 0;
    for (int i = 0; i < num_samples; i++) {
        average += samples[i];
    }
    average /= num_samples;

    // Perform DC shift and print the results
    printf("You entered the following samples: ");
    for (int i = 0; i < num_samples; i++) {
        printf("%d ", samples[i]);
    }
    printf("\n");

    printf("Calculated average (DC value): %d\n", average);
    printf("Final adjusted samples after DC shift:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%d ", samples[i] - average);
    }
    printf("\n");

    // Free the allocated memory
    free(samples);

    return 0;
}
