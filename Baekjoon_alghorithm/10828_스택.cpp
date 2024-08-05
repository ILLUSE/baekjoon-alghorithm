#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// do_command : �Է¹��� ��ɾ ��������ִ� �Լ�
// push X : ���� X�� ���ÿ� �ִ� �����̴�.
// pop : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
// size : ���ÿ� ����ִ� ������ ������ ����Ѵ�.
// empty : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
// top : ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

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
    getchar(); // ���� �ִ� ���� ���� ����

    for (int i = 0; i < N; i++) {
        char command[15];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // ���๮�� ����
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
    else if (strcmp(text, "pop") == 0) { // pop �Լ� ����
        pop();
    }
    else if (strcmp(text, "size") == 0) { // size �Լ� ����
        size();
    }
    else if (strcmp(text, "empty") == 0) { // empty �Լ� ����
        empty();
    }
    else if (strcmp(text, "top") == 0) { // top �Լ� ����
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
        printf("-1\n"); // ���� ����ٸ� -1 ���
        return 0;
    }

    for (int i = 0; i < MAX; i++) {
        if (stack[i] == -1) {
            printf("%d\n", stack[i - 1]); // ���� ���� �ִ� �� ���
            stack[i - 1] = -1; // ���� ���� �ִ� �� -1�� �ʱ�ȭ
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
        printf("1\n"); // ���� ����ٸ� 1 ���
        return 0;
    }
    else {
        printf("0\n"); // �ƴϸ� 0 ���
        return 0;
    }
}

int top() {
    if (stack[0] == -1) {
        printf("-1\n"); // ���� ����ٸ� -1 ���
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
