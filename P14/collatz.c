#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

int main() {
    int max = 0;
    int maxNum = 0;
    for (int i = 2; i < MAX; i++) {
        long num = i;
        int count = 0;
        while (num != 1) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = 3 * num + 1;
            }
            count++;
        }

        if (count > max) {
            max = count;
            maxNum = i;
        }
    }
    printf("%d\n", maxNum);
    return 0;
}