#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   
#include<stdlib.h>

//��� ��, �̸��ڴ� �쿬�� ��Ÿ����� ��� N�� ���Ҵ�.
//�̸��ڴ� 30�̶� ���� �����ϱ� ������, �״� ��Ÿ����� ã�� ���� ���Ե� ���ڵ��� ���� 30�� ����� �Ǵ� ���� ū ���� ����� �;��Ѵ�.
//�̸��ڸ� ���� �װ� ����� �;��ϴ� ���� ����ϴ� ���α׷��� �ۼ��϶�.
//N�� �Է¹޴´�. N�� �ִ� 105���� ���ڷ� �����Ǿ� ������, 0���� �������� �ʴ´�.

//�ϴ� 0�� �ʼ��� �� �ڿ� �־����
//30�� ����� 3�� ����̸鼭 ���� �ڸ��� 0�� ���̴�
//3�� �����  �� �ڸ� ���� ���� 3�� ����� ���̴�

int descending_comp(const void* a, const void* b)
{
	return(*(int*)b - *(int*)a); //�������� 
}

int main() {

	char a[100001];
	scanf("%s", a);

    char* ptr = strchr(a, '0');     //0������ -1 ���

	if (ptr == NULL) {
		printf("-1");
		return 0;
   }

	long sum = 0;
	for (int i = 0; i < strlen(a); i++) { //3�� ������� Ȯ��
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

	qsort(b, strlen(a), sizeof(int), descending_comp); //������������ ����

	for (int i = 0; i < strlen(a); i++) {
		printf("%d", b[i]);
	}
	return 0;
}