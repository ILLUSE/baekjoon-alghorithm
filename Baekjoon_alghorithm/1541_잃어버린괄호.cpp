#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {

	char string[50]; //문자열을 입력받을 배열

	scanf("%s", string); // 문자열 입력받기
	//printf("%s\n", string); //확인용

	char* token_minus[50] = { NULL , }; //-를 기준으로 쪼갠 문자열 토큰들을 저장할 배열
	int i = 0;

	char* ptr = strtok(string, "-"); //-를 기준으로 string을 나눠 첫 번째 토큰 가져오기

	while (ptr != NULL) {
		token_minus[i++] = ptr;  // 토큰을 배열에 저장
		ptr = strtok(NULL, "-");
	}
	/* //확인용 출력
	printf("Token_minus\n");
	for (int h = 0; h < i; h++) { 
		printf("%s\n", token_minus[h]);
	}
	printf("--------------\n");
	*/

	
	int minimum = 0; //최소값

	for (int k = 0; k < i; k++) {
		int sum = 0; //token_minus의 한 인덱스의 총합
		char* token_plus[50] = { NULL , }; //+를 기준으로 쪼갠 문자열 토큰들을 저장할 배열
		int j = 0;

		char* ptr2 = strtok(token_minus[k], "+"); //+를 기준으로 token_minus를 나눠 첫 번째 토큰 가져오기
		sum += atoi(ptr2);

		while (ptr2 != NULL) {
			token_plus[j++] = ptr2;  // 토큰을 배열에 저장
			ptr2 = strtok(NULL, "+");
			if(ptr2!=NULL) //sum에 더해주기
				sum += atoi(ptr2);
		}
		/* //확인용 출력
		printf("Token_plus\n");
		for (int h = 0; h < i; h++) { 
			printf("%s\n", token_plus[h]);
		}
		printf("--------------\n");
		*/
		if (k == 0) //첫번째만 양수고
			minimum = sum;
		else if (k != 0) //그 뒤는 모두 음수취급
			minimum -= sum;
		
	}

	printf("%d", minimum); //최소값 출력
	

	return 0;
}