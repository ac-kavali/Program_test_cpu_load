#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t start = time(NULL);
    double x = 0.0;

    while (time(NULL) - start < 60) {   // run for 60 seconds
        // Heavy calculations
        for (long i = 0; i < 10000000; i++) {
            x += i * 0.0000001;
            x = x / 1.0000001;
        }

        // Sleep a bit to keep CPU around 50–60%
        usleep(50000); // 50ms
    }

    // Prevent compiler optimizing out the loop
    printf("Done. Final x = %f\n", x);
    return 0;
}