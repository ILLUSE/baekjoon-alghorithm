#include <stdio.h>
#include <stdlib.h> 

//for문에서 도는 조건을  점프시켜야할땐 while 사용하기
//최대한 malloc 안하고 그냥 배열 쓰기

typedef struct{

	int start;
	int finish;

}meeting;

int compare(const void* a, const void* b) {
	meeting ptr1 = *(meeting *)a;
	meeting ptr2 = *(meeting *)b;

	if (ptr1.finish > ptr2.finish)
		return 1;
	else if (ptr1.finish == ptr2.finish) {
		if (ptr1.start > ptr2.start)
			return 1;
		else return -1;
	}
	else return -1;
};

int main() {

	int N = 0;
	scanf_s("%d", &N); //회의 수 N입력받기 (1 ≤ N ≤ 100,000)

	meeting time[100010];


	for (int i = 0; i < N; i++) { //시작,종료 시간들 입력받기

		scanf_s("%d %d", &time[i].start, &time[i].finish);

	}

	qsort(time, N, sizeof(meeting), compare); //정렬

	
	int count = 1;//무조건 한개는 되니까 1로 시작
	int i = 1; //
	int j = 0;
	while (i < N)
	{
		if (time[j].finish <= time[i].start) // 만약 j번째 종료시간이 i번째 시작시간보다 작거나 같다면
		{
			j = i; // 조건에 만족하면 j를 i로 업데이트
			count++; // 갯수 세줌
		}
		i++;
	}

	printf("%d", count);

	

	return 0;
}