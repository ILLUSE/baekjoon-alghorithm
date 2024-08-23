#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int age;
	char name[100];
	int order;
}Person;

//qsort compare 함수
//양수 return : 순서 바꾸기
//음수 return : 그대로
int compare(const void* a, const void* b);

Person p[100000];

int main() {
	int n = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) { //구조체에 입력받기
		scanf("%d", &p[i].age);
		scanf("%s", p[i].name);
		p[i].order = i;
	}

	//회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬
	qsort(p, n, sizeof(Person), compare); 
	
	//정렬된 구조체 배열 출력
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
	else return personA->order - personB->order; //나이가 같을때 order순대로
}