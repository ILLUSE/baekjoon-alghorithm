#define _CRT_SECURE_NO_WARNINGS
#define MAX 1002
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T = 0;
    scanf("%d", &T); 
    getchar();
    for (int i = 0; i < T; i++) {
        char string[MAX];
        fgets(string, sizeof(string), stdin);

        // fgets �� ���� ���� ����
        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0'; // ���� ���ڸ� �� ���ڷ� ��ü
        }

        int last = strlen(string) - 1;

        // ���ڿ��� �Ųٷ� ������
        for (int j = 0; j <= last; j++) {
            printf("%c",string[last - j]);
        }
        printf("\n");
    }

    // ������ ���ڿ� ���
   
    return 0;
}