#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int n = 0;// 살 기타줄 개수
	int m = 0;// 브랜드 개수

	scanf("%d %d", &n, &m);

	int pack = 0; //패키지 가격(6개)
	int each = 0; //낱개 가격
	int cheapest_pack = 1001;
	int cheapest_each = 1001;

	for (int i = 0; i < m; i++) { //가장 싼 패키지 가격,가장 싼 낱개 가격 찾기
		scanf("%d %d", &pack, &each);
		if (pack < cheapest_pack)cheapest_pack = pack;
		if (each < cheapest_each)cheapest_each = each;
		
	}
	//printf("\ncheapest : %d %d\n", cheapest_pack, cheapest_each);

	int total = 0;
	if (cheapest_each * 6 <= cheapest_pack) { //낱개로 6개 사는 게 팩으로 사는 것보다 싸거나 같으면
		total = cheapest_each * n; //그냥 다 낱개로 사기!
		
	}
	else {
		total = cheapest_pack * (n / 6);
		n = n % 6;
		if (n > 0 && n * cheapest_each > cheapest_pack) { //낱개 * 나머지가 팩으로 사는것보다 비싸면
			total += cheapest_pack;
			
		}
		else if (n > 0 && n * cheapest_each <= cheapest_pack) {
			total += n * cheapest_each;
			
		}
		
	}

	printf("%d", total);
	return 0;
}