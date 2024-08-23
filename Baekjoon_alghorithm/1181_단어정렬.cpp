/*���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���̰� ª�� �ͺ���
���̰� ������ ���� ������
��, �ߺ��� �ܾ�� �ϳ��� ����� �����ؾ� �Ѵ�. 

ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000) 
��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����.
�־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.
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
		if(strcmp(p[i-1].str,p[i].str)!=0) //���� �� ����� ���� �ʴٸ� ���
			printf("%s\n", p[i].str);
	}

	free(p);
	return 0;
}

int compare(const void* a, const void* b) { //���� ����� ����

	String* strA = (String*)a;
	String* strB = (String*)b;

	if (strA->len > strB->len)return 1;
	else if (strA->len < strB->len)return -1;
	else return strcmp(strA->str, strB->str); //���������� ����
}