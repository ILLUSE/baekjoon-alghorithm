#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {

   
    

    int n;
    char a[10][8];

    // 문자열 개수 입력
    scanf("%d", &n);

    // 문자열 입력
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    // 문자열 길이순으로 내림차순 정렬
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
    //문자열들을 맨 뒤로 밀착시키기
    for (int i = 0; i < n; i++) {
        if (strlen(a[i]) == 8); //문자열이 8글자면
        else if (strlen(a[i]) == 7) { //문자열이 7글자면
            for (int j = 7; j > 0; j--) {
                a[i][j] = a[i][j-1];
                a[i][j-1] = NULL;
            }
        }
        else if (strlen(a[i]) == 6) { //문자열이 6글자면
            for (int j = 7; j > 1; j--) {
                a[i][j] = a[i][j - 2];
                a[i][j-2] = NULL;
            }
        }
        else if (strlen(a[i]) == 5) { //문자열이 5글자면
            for (int j = 7; j > 2; j--) {
                a[i][j] = a[i][j - 3];
                a[i][j - 3] = NULL;
            }
        }
        else if (strlen(a[i]) == 4) { //문자열이 4글자면
            for (int j = 7; j > 3; j--) {
                a[i][j] = a[i][j - 4];
                a[i][j - 4] = NULL;
            }
        }
        else if (strlen(a[i]) == 3) { //문자열이 3글자면
            for (int j = 7; j > 4; j--) {
                a[i][j] = a[i][j - 5];
                a[i][j - 5] = NULL;
            }
        }
        else if (strlen(a[i]) == 2) { //문자열이 2글자면
            for (int j = 7; j > 5; j--) {
                a[i][j] = a[i][j - 6];
                a[i][j - 6] = NULL;
            }
        }
        else if (strlen(a[i]) == 1) { //문자열이 1글자면
            a[i][7] = a[i][0];
            a[i][0] = NULL;
        }
    }


    int change = 9;
    char save[10];
    int aton[10];
    int k = 0;
    //바꿔줄때마다 전체 돌면서 같은 단어 치환해주기 해줘야됨!
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < n; j++) {
            if ((a[j][i] >= 'A' && a[j][i] <= 'Z')) { //만약 문자라면 change로 바꿔주기
                if (strchr(save, a[j][i])) {//만약 save배열 안에 있는 단어면 치환후 continue;
                    //치환해주기

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
   
    //다시 문자열들 맨 앞으로 밀착
    //숫자로 바꾼 후 합해주기
    //값 출력
    return 0;
}