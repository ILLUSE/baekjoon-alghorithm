#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int descending_comp(const void* a, const void* b)
{
	return(*(int*)b - *(int*)a); //내림차순 
}

int main() {

	int N = 0; //N 입력받기
	scanf("%d", &N);

	int rope[100000]; //로프의 최대중량이 들어갈 배열
	for (int i = 0; i < N; i++) {
		scanf("%d", &rope[i]);
	}

	qsort(rope, N, sizeof(int), descending_comp); //로프들의 최대중량의 내림차순으로 배열 정렬

	/*
	printf("rope after sort\n"); //확인용
	for (int i = 0; i < N; i++) {
		printf("%d\n", rope[i]);
	}
	*/
	int arr[100000]; //로프를 i개 썼을때 최대중량이 들어갈 배열
	
	for (int i = 0; i < N; i++) {
		
		if(i==0)
			arr[i] = rope[i];
		else
			arr[i] = rope[i]*(i+1);

	}

	int max = 0;
	for (int i = 0; i < N; i++) { //arr 중 최대값 찾기
		if (max < arr[i])
			max = arr[i];
	}

	printf("%d", max);
	return 0;
}