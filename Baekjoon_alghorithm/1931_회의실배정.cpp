#include <stdio.h>
#include <stdlib.h> 

//for������ ���� ������  �������Ѿ��Ҷ� while ����ϱ�
//�ִ��� malloc ���ϰ� �׳� �迭 ����

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
	scanf_s("%d", &N); //ȸ�� �� N�Է¹ޱ� (1 �� N �� 100,000)

	meeting time[100010];


	for (int i = 0; i < N; i++) { //����,���� �ð��� �Է¹ޱ�

		scanf_s("%d %d", &time[i].start, &time[i].finish);

	}

	qsort(time, N, sizeof(meeting), compare); //����

	
	int count = 1;//������ �Ѱ��� �Ǵϱ� 1�� ����
	int i = 1; //
	int j = 0;
	while (i < N)
	{
		if (time[j].finish <= time[i].start) // ���� j��° ����ð��� i��° ���۽ð����� �۰ų� ���ٸ�
		{
			j = i; // ���ǿ� �����ϸ� j�� i�� ������Ʈ
			count++; // ���� ����
		}
		i++;
	}

	printf("%d", count);

	

	return 0;
}