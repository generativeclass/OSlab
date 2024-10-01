#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("Enter size of array: ");
    int n, sumEven = 0, sumOdd = 0;
    scanf("%d", &n);
    
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter elements of array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int f = fork();
    
    if (f > 0) {
        // Parent process
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                sumEven += arr[i];
            }
        }
        printf("Parent process \n");
        printf("Sum of even numbers: %d \n", sumEven);
    } 
    else if (f == 0) {
        // Child process
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                sumOdd += arr[i];
            }
        }
        printf("Child process \n");
        printf("Sum of odd numbers: %d \n", sumOdd);
    } 
    else {
        // Fork failed
        printf("Fork failed\n");
        return 1;
    }

    free(arr);
    return 0;
}
