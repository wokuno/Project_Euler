#include <stdio.h>

#define MAX 1000

int main() {
    int largest = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int product = i * j;
            int reversed = 0;
            int temp = product;
            while (temp != 0) {
                reversed = reversed * 10 + temp % 10;
                temp /= 10;
            }
            if (product == reversed && product > largest) {
                largest = product;
            }
        }
    }
    printf("%d\n", largest);
    return 0;
}