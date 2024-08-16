#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   
#include<stdlib.h>

//어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다.
//미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
//미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.
//N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

//일단 0은 필수로 맨 뒤에 있어야함
//30의 배수는 3의 배수이면서 일의 자리가 0인 수이다
//3의 배수는  각 자리 수의 합이 3의 배수인 수이다

int descending_comp(const void* a, const void* b)
{
	return(*(int*)b - *(int*)a); //내림차순 
}

int main() {

	char a[100001];
	scanf("%s", a);

    char* ptr = strchr(a, '0');     //0없으면 -1 출력

	if (ptr == NULL) {
		printf("-1");
		return 0;
   }

	long sum = 0;
	for (int i = 0; i < strlen(a); i++) { //3의 배수인지 확인
		int num = a[i] - '0';
		sum += num;
	}
	if (sum % 3 != 0) {
		printf("-1");
		return 0;
	}

	int b[100001] = {0,};
	for (int i = 0; i < strlen(a); i++) {
		b[i] = a[i] - '0';
	}

	qsort(b, strlen(a), sizeof(int), descending_comp); //내림차순으로 정렬

	for (int i = 0; i < strlen(a); i++) {
		printf("%d", b[i]);
	}
	return 0;
}