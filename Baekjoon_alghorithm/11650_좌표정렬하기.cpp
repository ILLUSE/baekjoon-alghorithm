/*
����
2���� ��� ���� �� N���� �־�����.
��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����.
��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����.(-100,000 �� xi, yi �� 100,000)
��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.

-key point
1.��ǥ�� �����ؼ� ����ü��
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
	else return pointA -> y - pointB -> y; //x�� ������ y���� ���� ���� 
	
}

int main() {
	int n = 0;
	scanf("%d", &n);
	
	Point* p = (Point*)malloc(sizeof(Point) * n); //����ü �迭 ����

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