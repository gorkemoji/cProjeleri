#include <stdio.h>

char LED[4][7][4];
int digits[4] = {-1, -1, -1, -1};
int digitNumber;

void createLED () {
    for (int i = 0;i < 4;i++) {
        for(int j = 0;j < 7;j++) {
            for (int k = 0;k < 4;k++) {
                if ((j == 0 || ((j == 3) || (j == 6))) && (k == 0 || k == 3))
                    LED[i][j][k] = ' ';
                else if (((k == 1 || k == 2)) && ((j == 1 || j == 2) || (j == 4 || j == 5)))
                    LED[i][j][k] = ' ';
                else
                    LED[i][j][k] = '.';
            }
        }
    }
}

void parse (int number) {
    int counter = 0, unitsDigit, temp[4], i = 0;

    if(number > 0) {
        while (number > 0) {
            unitsDigit = number % 10;
            number /= 10;
            temp[i] = unitsDigit;
            i++;
            counter++;
        }

        digitNumber = counter;

        for(int j = 0;j < digitNumber;j++)
            digits[j] = temp[j];
    }

    else {
        digitNumber = 1;
        digits[0] = 0;
    }
}

void enableSegments (int digit, int digitNum, char segment) {
    switch (segment) {
        case 'a':
            for(int i = 1;i < 3;i++)
                LED[digitNum][0][i] = 219;
            break;
        case 'b':
            for(int i = 1;i < 3;i++)
                LED[digitNum][i][3] = 219;
            break;
        case 'c':
            for(int i = 4;i < 6;i++)
                LED[digitNum][i][3] = 219;
            break;
        case 'd':
            for(int i = 1;i < 3;i++)
                LED[digitNum][6][i] = 219;
            break;
        case 'e':
            for(int i = 4;i < 6;i++)
                LED[digitNum][i][0] = 219;
            break;
        case 'f':
            for(int i = 1;i < 3;i++)
                LED[digitNum][i][0] = 219;
            break;
        case 'g':
            for(int i = 1;i < 3;i++)
                LED[digitNum][3][i] = 219;
            break;
    }
}

void display (int number) {
    parse(number);

    int digitNum = 3;

    for(int i = 0;i < digitNumber;i++) {
        switch (digits[i]) {
            case 0:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'c');
                enableSegments(digits[i], digitNum, 'd');
                enableSegments(digits[i], digitNum, 'e');
                enableSegments(digits[i], digitNum, 'f');
                break;
            case 1:
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'c');
                break;
            case 2:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'g');
                enableSegments(digits[i], digitNum, 'e');
                enableSegments(digits[i], digitNum, 'd');
                break;
            case 3:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'g');
                enableSegments(digits[i], digitNum, 'c');
                enableSegments(digits[i], digitNum, 'd');
                break;
            case 4:
                enableSegments(digits[i], digitNum, 'f');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'g');
                enableSegments(digits[i], digitNum, 'c');
                break;
            case 5:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'f');
                enableSegments(digits[i], digitNum, 'g');
                enableSegments(digits[i], digitNum, 'c');
                enableSegments(digits[i], digitNum, 'd');
                break;
            case 6:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'f');
                enableSegments(digits[i], digitNum, 'g');
                enableSegments(digits[i], digitNum, 'c');
                enableSegments(digits[i], digitNum, 'd');
                enableSegments(digits[i], digitNum, 'e');
                break;
            case 7:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'c');
                break;
            case 8:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'c');
                enableSegments(digits[i], digitNum, 'd');
                enableSegments(digits[i], digitNum, 'e');
                enableSegments(digits[i], digitNum, 'f');
                enableSegments(digits[i], digitNum, 'g');
                break;
            case 9:
                enableSegments(digits[i], digitNum, 'a');
                enableSegments(digits[i], digitNum, 'b');
                enableSegments(digits[i], digitNum, 'c');
                enableSegments(digits[i], digitNum, 'd');
                enableSegments(digits[i], digitNum, 'f');
                enableSegments(digits[i], digitNum, 'g');
                break;
        }
        digitNum--;
    }

    for (int i = 0;i < 7;i++) {
        for (int j = 0;j < 4;j++) {
            for (int k = 0;k < 4;k++) {
                printf("%c", LED[j][i][k]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

void main () {
    int number;

    printf("Enter the number: ");
    scanf("%d", &number);

    createLED();
    display(number);
}