#include <stdio.h>

#define MAX 2000000

int main() {
    long sum = 0;
    for (int i = 2; i < MAX; i++) {
        int prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            sum += i;
        }
    }
    printf("%ld\n", sum);
    return 0;
}