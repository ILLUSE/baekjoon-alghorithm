#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//do_command :입력받은 명령어를 실행시켜주는 함수
//push X : 정수 X를 스택에 넣는 연산이다.
//pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
//size : 스택에 들어있는 정수의 개수를 출력한다.
//empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
//top : 스택의 가장 위에 있는 정수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.




int main() {

	int N = 0;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		char command[15];
		scanf("%s", &command);

		do_command(command);
	}

}