#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// do_command : 입력받은 명령어를 실행시켜주는 함수
// push X : 정수 X를 스택에 넣는 연산이다.
// pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size : 스택에 들어있는 정수의 개수를 출력한다.
// empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
// top : 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int stack[MAX];

void do_command(char* command);
int push(int num);
int pop();
void size();
int empty();
int top();

int main() {
    for (int i = 0; i < MAX; i++) {
        stack[i] = -1;
    }

    int N = 0;
    scanf("%d", &N);
    getchar(); // 남아 있는 개행 문자 제거

    for (int i = 0; i < N; i++) {
        char command[15];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // 개행문자 제거
        do_command(command);
    }

    return 0;
}

void do_command(char* command) {
    char text[100] = "";
    int num;

    if (sscanf(command, "%s %d", text, &num) == 2) {
        if (strcmp(text, "push") == 0)
            push(num);
    }
    else if (strcmp(text, "pop") == 0) { // pop 함수 실행
        pop();
    }
    else if (strcmp(text, "size") == 0) { // size 함수 실행
        size();
    }
    else if (strcmp(text, "empty") == 0) { // empty 함수 실행
        empty();
    }
    else if (strcmp(text, "top") == 0) { // top 함수 실행
        top();
    }
}

int push(int num) {
    for (int i = 0; i < MAX; i++) {
        if (stack[i] == -1) {
            stack[i] = num;
            return 0;
        }
    }
    return 0;
}

int pop() {
    if (stack[0] == -1) {
        printf("-1\n"); // 만약 비었다면 -1 출력
        return 0;
    }

    for (int i = 0; i < MAX; i++) {
        if (stack[i] == -1) {
            printf("%d\n", stack[i - 1]); // 가장 위에 있는 수 출력
            stack[i - 1] = -1; // 가장 위에 있는 수 -1로 초기화
            return 0;
        }
    }
    return 0;
}

void size() {
    int size = 0;
    for (int i = 0; i < MAX; i++) {
        if (stack[i] != -1)
            size++;
    }
    printf("%d\n", size);
}

int empty() {
    if (stack[0] == -1) {
        printf("1\n"); // 만약 비었다면 1 출력
        return 0;
    }
    else {
        printf("0\n"); // 아니면 0 출력
        return 0;
    }
}

int top() {
    if (stack[0] == -1) {
        printf("-1\n"); // 만약 비었다면 -1 출력
        return 0;
    }

    for (int i = 0; i < MAX; i++) {
        if (stack[i] == -1) {
            printf("%d\n", stack[i - 1]);
            return 0;
        }
    }
    return 0;
}
