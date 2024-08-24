/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다.
이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

-key point
1.qsort
2.왠진 모르겠으나 그냥 배열을 a[1,000,000]로 설정하면 안되고 malloc 해주니 됨... 왜지?

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h> 

int compare(const void* first, const void* second);

int main() {
	int n = 0;
	scanf("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n); //동적할당

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	qsort(a,n,sizeof(int),compare);

	printf("%d\n", a[0]);
	for (int i = 1; i < n; i++) {
		if(a[i-1] != a[i])
			printf("%d\n", a[i]);
	}

	free(a);

	return 0;
}

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

