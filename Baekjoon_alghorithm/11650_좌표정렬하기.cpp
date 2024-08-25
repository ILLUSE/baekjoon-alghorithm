/*
문제
2차원 평면 위의 점 N개가 주어진다.
좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.(-100,000 ≤ xi, yi ≤ 100,000)
좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

-key point
1.좌표는 웬만해선 구조체다
2.qsort
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y; 
}Point;

int compare(const void *a,const void *b) {

	Point* pointA = (Point*)a;
	Point* pointB = (Point*)b;
	if (pointA->x > pointB->x)return 1;
	else if (pointA->x < pointB->x)return -1;
	else return pointA -> y - pointB -> y; //x값 같으면 y값에 따라 정렬 
	
}

int main() {
	int n = 0;
	scanf("%d", &n);
	
	Point* p = (Point*)malloc(sizeof(Point) * n); //구조체 배열 선언

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	qsort(p, n, sizeof(Point), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
	
	free(p);

	return 0;
}