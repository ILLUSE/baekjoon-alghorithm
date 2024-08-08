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

        // fgets 후 개행 문자 제거
        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0'; // 개행 문자를 널 문자로 대체
        }

        int last = strlen(string) - 1;

        // 문자열을 거꾸로 뒤집기
        for (int j = 0; j <= last; j++) {
            printf("%c",string[last - j]);
        }
        printf("\n");
    }

    // 뒤집은 문자열 출력
   
    return 0;
}