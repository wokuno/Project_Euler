#include <stdio.h>

#define MAX 20

int main() {
    int smallest = 0;
    int i = 1;
    while (1) {
        int found = 1;
        for (int j = 1; j <= MAX; j++) {
            if (i % j != 0) {
                found = 0;
                break;
            }
        }
        if (found) {
            smallest = i;
            break;
        }
        i++;
    }
    printf("%d\n", smallest);
    return 0;
}