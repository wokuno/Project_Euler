#include <stdio.h>

#define MAX 600851475143

int main() {
    long num = MAX;
    long largest = 0;
    for (long i = 2; i <= num; i++) {
        while (num % i == 0) {
            num /= i;
            largest = i;
        }
    }
    printf("%ld\n", largest);
    return 0;
}