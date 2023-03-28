#include <stdio.h>

int globalDigits[5] = {-1, -1, -1, -1, -1};
char globalTable[4][5][4];

void createLED() {
    for (int i = 0;i < 4;i++) {
        for(int j = 0;j < 5;j++) {
            for (int k = 0;k < 4;k++) {
                if ((j == 1 && (k == 1 || k == 2)) || (j == 3 && (k == 1 || k ==2)))
                    globalTable[i][j][k] = ' ';
                else
                    globalTable[i][j][k] = '.';
            }
        }
    }
}

void numberProcesses(int number) {

    if (number != 0 && number > 0) {
        int tempArray[4], digitNum = 0;

        while (number > 0) {
            int temp = number % 10;
            number /= 10;
            tempArray[digitNum] = temp;
            digitNum++;
        }

        globalDigits[0] = digitNum;

        for (int i = 0;i < digitNum;i++) {
            globalDigits[i+1] = tempArray[i];
        }
    }

    else {
        globalDigits[0] = 1;
        globalDigits[1] = 0;
    }
}

void setLED(int number) {
    numberProcesses(number);

    int temp = 3;

    for (int i = 0;i < globalDigits[0];i++) {
        switch (globalDigits[i+1]) {
            case 0:
                for (int j = 0;j < 5;j++) {
                    for (int k = 0;k < 4;k++) {
                        if (j == 0 || j == 4)
                            globalTable[temp][j][k] = '0';
                        else
                            if (k == 0 || k == 3)
                                globalTable[temp][j][k] = '0';
                        }
                    }
                    break;
                case 1:
                    for (int j = 0;j < 5;j++)
                        globalTable[temp][j][3] = '0';
                    break;
                case 2:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j % 2 == 0)
                                globalTable[temp][j][k] = '0';
                            else {
                                if (j == 1)
                                    globalTable[temp][j][3] = '0';
                                else if (j == 3)
                                    globalTable[temp][j][0] = '0';
                            }
                        }
                    }
                    break;
                case 3:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j % 2 == 0)
                                globalTable[temp][j][k] = '0';
                            else
                                globalTable[temp][j][3] = '0';
                        }
                    }
                    break;
                case 4:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j == 0 || j == 1) {
                                globalTable[temp][j][0] = '0';
                                globalTable[temp][j][3] = '0';
                            }
                            else if (j == 2)
                                globalTable[temp][j][k] = '0';
                            else if (j == 3 || j == 4)
                                globalTable[temp][j][3] = '0';
                        }
                    }
                    break;
                case 5:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j % 2 == 0)
                                globalTable[temp][j][k] = '0';
                            else {
                                if (j == 1)
                                    globalTable[temp][j][0] = '0';
                                else if (j == 3)
                                    globalTable[temp][j][3] = '0';
                            }
                        }
                    }
                    break;
                case 6:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j % 2 == 0)
                                globalTable[temp][j][k] = '0';
                            else {
                                if (j == 1)
                                    globalTable[temp][j][0] = '0';
                                else if (j == 3) {
                                    globalTable[temp][j][0] = '0';
                                    globalTable[temp][j][3] = '0';
                                }
                            }
                        }
                    }
                    break;
                case 7:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j == 0)
                                globalTable[temp][j][k] = '0';
                            else
                                globalTable[temp][j][3] = '0';
                            }
                        }
                    break;
                case 8:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j % 2 == 0)
                                globalTable[temp][j][k] = '0';
                            else {
                                globalTable[temp][j][0] = '0';
                                globalTable[temp][j][3] = '0';
                            }
                        }
                    }
                    break;
                case 9:
                    for (int j = 0;j < 5;j++) {
                        for (int k = 0;k < 4;k++) {
                            if (j % 2 == 0)
                                globalTable[temp][j][k] = '0';
                            else if (j == 1) {
                                globalTable[temp][j][0] = '0';
                                globalTable[temp][j][3] = '0';
                            }
                            else if (j == 3)
                                globalTable[temp][j][3] = '0';
                        }
                    }
                    break;
            }
            temp--;
        }
    }

void display(int number) {
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < 4;j++) {
            for (int k = 0;k < 4;k++) {
                printf("%c", globalTable[j][i][k]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int number;

    printf("Enter the number: ");
    scanf("%d", &number);

    createLED();
    setLED(number);
    display(number);
}

