#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **nums = NULL;
char *sum = NULL;
int width = 0, height = 0, sumWidth = 0;

int allocateNums() {
    nums = malloc(height * sizeof(char *));
    if (nums == NULL) {
        return 1;
    }
    for (int i = 0; i < height; i++) {
        nums[i] = malloc(width * sizeof(char));
        if (nums[i] == NULL) {
            return 1;
        }
    }

    sum = malloc(width * sizeof(char));
    if (sum == NULL) {
        return 1;
    }

    return 0;
}

int freeNums() {
    for (int i = 0; i < height; i++) {
        if (nums[i] != NULL) {
            free(nums[i]);
        }
    }
    if (nums != NULL) {
        free(nums);
    }

    if (sum != NULL) {
        free(sum);
    }

    return 0;
}

int openNums() {
    FILE *file = fopen("nums.txt", "r");
    if (file == NULL) {
        return 1;
    }
    width = 0;
    height = 0;

    // get width of line, max 256 characters
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        if (len > width) {
            width = len;
        }
        height++;
    }
    width--; // remove newline
    sumWidth = width;
    printf("Width: %d, Height: %d\n", width, height);


    fclose(file);

    return 0;
}

int readNums() {
    FILE *file = fopen("nums.txt", "r");
    if (file == NULL) {
        return 1;
    }

    for (int i = 0; i < height; i++) {
        fgets(nums[i], width+1, file);
        char newline[2];
        fgets(newline, sizeof(newline), file);
    }

    fclose(file);
    return 0;
}

int printSum() {
    for (int i = 0; i < sumWidth; i++) {
        printf("%c", sum[i]);
    }
    return 0;
}

int printNum(int i){
    for (int j = 0; j < width; j++) {
        printf("%c", nums[i][j]);
    }
    return 0;
}

int printNums() {
    for (int i = 0; i < height; i++) {
       fprintf(stdout, "Line %d: ", i);
        printNum(i);
        fprintf(stdout, "\n");
        fflush(stdout);
    }
    return 0;
}

char * addNums(char* a, char* b) {
    int widthA = strlen(a);
    int widthB = strlen(b);
    int width = widthA > widthB ? widthA : widthB;
    if (a[0] - '0' + b[0] - '0' > 8) {
        width++;
    }
    int widthSum = width;

    char *sum = malloc(width * sizeof(char));
    if (sum == NULL) {
        return NULL;
    }

    for (int i = 0; i < width; i++) {
        sum[i] = '0';
    }

    int carry = 0;
    while (widthA > 0 || widthB > 0) {
        int digitA = 0;
        if (widthA > 0) {
            digitA = a[widthA - 1] - '0';
            widthA--;
        }
        int digitB = 0;
        if (widthB > 0) {
            digitB = b[widthB - 1] - '0';
            widthB--;
        }

        int sumDigit = digitA + digitB + carry;
        if (sumDigit > 9) {
            carry = 1;
            sumDigit -= 10;
        } else {
            carry = 0;
        }

        sum[width - 1] = sumDigit + '0';
        width--;
    }

    if (carry) {
        sum[width - 1] = carry + '0';
        width--;
    }

    // if (width > 0) {
    //     return NULL;
    // }

    if (sum[0] == '0') {
        for (int i = 0; i < widthSum; i++) {
            sum[i] = sum[i + 1];
        }
        widthSum--;
    } else {
        sumWidth++;
    }

    char *out = malloc(widthSum * sizeof(char));
    if (out == NULL) {
        return NULL;
    }

    for (int i = 0; i < widthSum; i++) {
        out[i] = sum[i];
    }

    free(sum);

    return out;
}

int main() {
    int err = 0;
    err = openNums();
    if (err) {
        return 1;
    }

    err = allocateNums();
    if (err) {
        return 1;
    }

    err = readNums();
    if (err) {
        return 1;
    }

    // err = printNums();
    // if (err) {
    //     return 1;
    // }

    for (int i = 0; i < width; i++) {
        sum[i] = '0';
    }

    // char * out = addNums("923", "456");
    // if (out == NULL) {
    //     return 1;
    // }

    // printf("%s\n", out);

    // free(out);

    for (int i = 0; i < height; i++) {
        char * out = addNums(sum, nums[i]);
        if (out == NULL) {
            fprintf(stderr, "Error adding numbers\n");
            return 1;
        }
        free(sum);
        sum = out;
        fprintf(stdout, "Sum: ");
        err = printSum();
        if (err) {
            return 1;
        }
        fprintf(stdout, "\n");
        fflush(stdout);
    }



    err = freeNums();
    if (err) {
        return 1;
    }

    return 0;
}

