#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int main() {

	int N = 0; //사람 수
	int p[1000] = {0,}; //인출시간

	scanf_s("%d", &N); //N 입력받기
	
	if (N < 1 || N>1000) { //만약 1 <= N <=1000 이 아니라면 끝내기
		printf("N should be 1 <= N <=1000");
		return 0;
	}

	int i = 0; 
	for (i = 0; i < N; i++) { //사람 수만큼 인출 시간 입력받기
		scanf_s(" %d",&p[i]);
		

		if (p[i] < 1 || p[i]>1000) { //만약 1 <= P <=1000 이 아니라면 끝내기
			printf("P should be 1 <= P <=1000");
			return 0;
		}
	}

	qsort(p, N, sizeof(int), compare); //배열을 오름차순으로 정렬
	
	int j = 0;
	int sum = 0;
	int sum2 = 0;
	for (j = 0; j < N; j++) { //합 구하기

		sum = sum + p[j];

		sum2 = sum2 + sum;
	}

	printf("%d", sum2);

	return 0;
}
