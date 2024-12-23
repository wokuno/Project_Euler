#include <stdio.h>

#define MAX 100

int main() {
    int sum = 0;
    int sumOfSquares = 0;
    for (int i = 1; i <= MAX; i++) {
        sum += i;
        sumOfSquares += i * i;
    }
    int squareOfSum = sum * sum;
    printf("%d\n", squareOfSum - sumOfSquares);
    return 0;
}