/*알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
길이가 짧은 것부터
길이가 같으면 사전 순으로
단, 중복된 단어는 하나만 남기고 제거해야 한다. 

첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 
둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
주어지는 문자열의 길이는 50을 넘지 않는다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);

typedef struct {
	char str[50];
	int len;
}String;

int main() {
	int n = 0;
	scanf("%d", &n);

	String* p = (String*)malloc(sizeof(String) * n);

	for (int i = 0; i < n; i++) { 
		scanf("%s", p[i].str);
		p[i].len = strlen(p[i].str);
	}

	qsort(p, n, sizeof(String), compare); //

	printf("%s\n", p[0].str);
	for(int i = 1; i < n; i++){
		if(strcmp(p[i-1].str,p[i].str)!=0) //만약 전 문장과 같지 않다면 출력
			printf("%s\n", p[i].str);
	}

	free(p);
	return 0;
}

int compare(const void* a, const void* b) { //길이 순대로 정렬

	String* strA = (String*)a;
	String* strB = (String*)b;

	if (strA->len > strB->len)return 1;
	else if (strA->len < strB->len)return -1;
	else return strcmp(strA->str, strB->str); //사전순으로 정렬
}