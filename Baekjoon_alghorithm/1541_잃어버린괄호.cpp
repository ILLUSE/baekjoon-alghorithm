#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {

	char string[50]; //���ڿ��� �Է¹��� �迭

	scanf("%s", string); // ���ڿ� �Է¹ޱ�
	//printf("%s\n", string); //Ȯ�ο�

	char* token_minus[50] = { NULL , }; //-�� �������� �ɰ� ���ڿ� ��ū���� ������ �迭
	int i = 0;

	char* ptr = strtok(string, "-"); //-�� �������� string�� ���� ù ��° ��ū ��������

	while (ptr != NULL) {
		token_minus[i++] = ptr;  // ��ū�� �迭�� ����
		ptr = strtok(NULL, "-");
	}
	/* //Ȯ�ο� ���
	printf("Token_minus\n");
	for (int h = 0; h < i; h++) { 
		printf("%s\n", token_minus[h]);
	}
	printf("--------------\n");
	*/

	
	int minimum = 0; //�ּҰ�

	for (int k = 0; k < i; k++) {
		int sum = 0; //token_minus�� �� �ε����� ����
		char* token_plus[50] = { NULL , }; //+�� �������� �ɰ� ���ڿ� ��ū���� ������ �迭
		int j = 0;

		char* ptr2 = strtok(token_minus[k], "+"); //+�� �������� token_minus�� ���� ù ��° ��ū ��������
		sum += atoi(ptr2);

		while (ptr2 != NULL) {
			token_plus[j++] = ptr2;  // ��ū�� �迭�� ����
			ptr2 = strtok(NULL, "+");
			if(ptr2!=NULL) //sum�� �����ֱ�
				sum += atoi(ptr2);
		}
		/* //Ȯ�ο� ���
		printf("Token_plus\n");
		for (int h = 0; h < i; h++) { 
			printf("%s\n", token_plus[h]);
		}
		printf("--------------\n");
		*/
		if (k == 0) //ù��°�� �����
			minimum = sum;
		else if (k != 0) //�� �ڴ� ��� �������
			minimum -= sum;
		
	}

	printf("%d", minimum); //�ּҰ� ���
	

	return 0;
}