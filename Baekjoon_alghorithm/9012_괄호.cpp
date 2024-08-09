#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    getchar(); // 개행문자 제거

    for (int i = 0; i < T; i++) {
        char c;
        int len = 0;
        int NO = 0;

        while ((c = getchar()) != '\n' && c != EOF) {
            if (c == ')') { //만약 len이 음수가 되면 NO
                if (len == 0) {
                    NO++;
                }
                else {
                    len--;
                }
            }
            else if (c == '(') {
                len++;
            }
        }

        if (len == 0 && NO == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}