#include <stdio.h>

#define MAX 4000000

int main() {
    int sum = 0;
    int a = 1;
    int b = 1;
    while (b < MAX) {
        if (b % 2 == 0) {
            sum += b;
        }
        int temp = a;
        a = b;
        b += temp;
    }
    printf("%d\n", sum);
    return 0;
}