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

	int N = 0; //��� ��
	int p[1000] = {0,}; //����ð�

	scanf_s("%d", &N); //N �Է¹ޱ�
	
	if (N < 1 || N>1000) { //���� 1 <= N <=1000 �� �ƴ϶�� ������
		printf("N should be 1 <= N <=1000");
		return 0;
	}

	int i = 0; 
	for (i = 0; i < N; i++) { //��� ����ŭ ���� �ð� �Է¹ޱ�
		scanf_s(" %d",&p[i]);
		

		if (p[i] < 1 || p[i]>1000) { //���� 1 <= P <=1000 �� �ƴ϶�� ������
			printf("P should be 1 <= P <=1000");
			return 0;
		}
	}

	qsort(p, N, sizeof(int), compare); //�迭�� ������������ ����
	
	int j = 0;
	int sum = 0;
	int sum2 = 0;
	for (j = 0; j < N; j++) { //�� ���ϱ�

		sum = sum + p[j];

		sum2 = sum2 + sum;
	}

	printf("%d", sum2);

	return 0;
}
