#include <stdio.h>
#include <time.h>

#define X 1.001
#define k 1000000

clock_t start, stop;
clock_t duration;

int main() {
    // Array of different values of N (problem sizes)
    int N[8] = {1000, 5000, 10000, 20000, 40000, 60000, 80000, 100000};

    for (int h = 0; h < 8; h++) {
        double x = X;
        long n = N[h];

        // Run the algorithm k times to calculate the average time
        clock_t time[k + 1];
        long double result = 1;

        for (int i = 0; i < k + 1; i++) {
            // Initialize the result, x, and n
            result = 1;
            x = X;
            n = N[h];

            start = clock();  // Start timing

            // Main algorithm: Compute x^n using binary exponentiation
            while (n != 0) {
                if (n % 2) {
                    result *= x;
                }
                x = x * x;
                n /= 2;
            }

            stop = clock();  // End timing

            duration = stop - start;  // Calculate the time taken

            // Store the duration in the 'time' array
            time[i] = duration;
        }

        // Calculate the average time
        long double aver = 0;
        clock_t temp = 0;

        for (int i = 1; i < k + 1; i++) {
            temp += time[i];
        }

        // Convert the total time to seconds and print
        aver = ((long double)temp / CLOCKS_PER_SEC);
        printf("ticks: %.0Lf\n", (long double)temp);  // Print the total clock ticks
        printf("total time: %.8Lf\n", aver);  // Print the total time in seconds
        aver /= k;  // Calculate the average time
        printf("average time: %.8Lf\n", aver);  // Print the average time in seconds
        printf("result: %Lf\n", result);  // Print the final result for this N
    }
}
