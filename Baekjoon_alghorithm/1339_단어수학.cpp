#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {

   
    

    int n;
    char a[10][8];

    // ���ڿ� ���� �Է�
    scanf("%d", &n);

    // ���ڿ� �Է�
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    // ���ڿ� ���̼����� �������� ����
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strlen(a[i]) < strlen(a[j])) {
                char temp[8];
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
    //���ڿ����� �� �ڷ� ������Ű��
    for (int i = 0; i < n; i++) {
        if (strlen(a[i]) == 8); //���ڿ��� 8���ڸ�
        else if (strlen(a[i]) == 7) { //���ڿ��� 7���ڸ�
            for (int j = 7; j > 0; j--) {
                a[i][j] = a[i][j-1];
                a[i][j-1] = NULL;
            }
        }
        else if (strlen(a[i]) == 6) { //���ڿ��� 6���ڸ�
            for (int j = 7; j > 1; j--) {
                a[i][j] = a[i][j - 2];
                a[i][j-2] = NULL;
            }
        }
        else if (strlen(a[i]) == 5) { //���ڿ��� 5���ڸ�
            for (int j = 7; j > 2; j--) {
                a[i][j] = a[i][j - 3];
                a[i][j - 3] = NULL;
            }
        }
        else if (strlen(a[i]) == 4) { //���ڿ��� 4���ڸ�
            for (int j = 7; j > 3; j--) {
                a[i][j] = a[i][j - 4];
                a[i][j - 4] = NULL;
            }
        }
        else if (strlen(a[i]) == 3) { //���ڿ��� 3���ڸ�
            for (int j = 7; j > 4; j--) {
                a[i][j] = a[i][j - 5];
                a[i][j - 5] = NULL;
            }
        }
        else if (strlen(a[i]) == 2) { //���ڿ��� 2���ڸ�
            for (int j = 7; j > 5; j--) {
                a[i][j] = a[i][j - 6];
                a[i][j - 6] = NULL;
            }
        }
        else if (strlen(a[i]) == 1) { //���ڿ��� 1���ڸ�
            a[i][7] = a[i][0];
            a[i][0] = NULL;
        }
    }


    int change = 9;
    char save[10];
    int aton[10];
    int k = 0;
    //�ٲ��ٶ����� ��ü ���鼭 ���� �ܾ� ġȯ���ֱ� ����ߵ�!
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < n; j++) {
            if ((a[j][i] >= 'A' && a[j][i] <= 'Z')) { //���� ���ڶ�� change�� �ٲ��ֱ�
                if (strchr(save, a[j][i])) {//���� save�迭 �ȿ� �ִ� �ܾ�� ġȯ�� continue;
                    //ġȯ���ֱ�

                    continue;
                }
                char ch;
                
                save[k] = a[j][i];
                aton[k] = change;
                k++;
                sprintf(&ch, "%d", change);
                change--;
                a[j][i] == ch;
            }
        }
    }
   
    //�ٽ� ���ڿ��� �� ������ ����
    //���ڷ� �ٲ� �� �����ֱ�
    //�� ���
    return 0;
}