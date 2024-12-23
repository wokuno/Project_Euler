#include <stdio.h>

#define MAX -1
#define divisors 500

int main() {
    int i = 1, max = 0;
    long long tri;
    while (1) {
        int count = 1;
        tri = i * (i + 1) / 2;
        for (long long k = 1; k <= (tri / 2); k++) {
            if (tri % k == 0) {
                count++;
            }
        }

        if (count > max) {
            max = count;
            printf("Number: %d, Tri: %lld, Divisors: %d\n", i, tri, count);
        }

        if (count > divisors) {
            break;
        }


        i++;
    }

    printf("Number: %d, Tri: %lld\n", i, tri);
    return 0;
}