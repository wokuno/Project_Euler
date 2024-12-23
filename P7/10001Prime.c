#include <stdio.h>

#define MAX 10001

int main() {
    int count = 0;
    int i = 2;
    while (1) {
        int prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            count++;
        }
        if (count == MAX) {
            printf("%d\n", i);
            break;
        }
        i++;
    }
    return 0;
}