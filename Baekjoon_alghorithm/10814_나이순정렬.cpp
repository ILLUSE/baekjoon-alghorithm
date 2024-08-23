#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int age;
	char name[100];
	int order;
}Person;

//qsort compare �Լ�
//��� return : ���� �ٲٱ�
//���� return : �״��
int compare(const void* a, const void* b);

Person p[100000];

int main() {
	int n = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) { //����ü�� �Է¹ޱ�
		scanf("%d", &p[i].age);
		scanf("%s", p[i].name);
		p[i].order = i;
	}

	//ȸ������ ���̰� �����ϴ� ������, ���̰� ������ ���� ������ ����� �տ� ���� ������ ����
	qsort(p, n, sizeof(Person), compare); 
	
	//���ĵ� ����ü �迭 ���
	for (int i = 0; i < n; i++) {             
		printf("%d %s\n", p[i].age, p[i].name);
	}
	return 0;
}

int compare(const void* a, const void* b) {

	Person* personA = (Person*)a;
	Person* personB = (Person*)b;
	if (personA->age > personB->age)return 1;
	else if (personA->age < personB->age)return -1;
	else return personA->order - personB->order; //���̰� ������ order�����
}