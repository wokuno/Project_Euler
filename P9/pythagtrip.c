#include <stdio.h>

#define SUM 1000

int main() {
    for (int a = 1; a < SUM; a++) {
        for (int b = a + 1; b < SUM; b++) {
            for (int c = b + 1; c < SUM; c++) {
                if ((a * a + b * b == c * c) && (a + b + c == SUM)) {
                    printf("%d\n", a * b * c);
                    return 0;
                }
            }
        }
    }
    return 0;
}