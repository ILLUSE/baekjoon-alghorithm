/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����.
�� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

-key point
1.qsort
2.���� �𸣰����� �׳� �迭�� a[1,000,000]�� �����ϸ� �ȵǰ� malloc ���ִ� ��... ����?

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h> 

int compare(const void* first, const void* second);

int main() {
	int n = 0;
	scanf("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n); //�����Ҵ�

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

