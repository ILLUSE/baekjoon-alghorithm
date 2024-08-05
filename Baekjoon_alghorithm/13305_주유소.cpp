#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	long long int N = 0; //도시 개수
	long long int city[100000]; //도시 사이의 거리
	long long int gas[100000]; //주유소의 기름 가격

	scanf("%lld", &N);
	for (int i = 0; i < N - 1; i++)
		scanf("%lld", &city[i]);
	for (int i = 0; i < N; i++)
		scanf("%lld", &gas[i]);


	long long int sum = 0; //총 기름 가격
	long long int skip = -1; //
	for (int i = 0; i < N-1; i++) {

		if (i <= skip)
			continue;

		long long int km = 0; //가야할 거리

		if (gas[i] <= gas[i + 1]) { //다음 도시가 더 비싸거나 가격이 같다면

			km = city[i];

			for(int j=i+1;j<N-1;j++){

				if (gas[i] <= gas[j]) { //더 싼 도시까지의 거리 구하기
					km += city[j];
					skip = j;
				}
				else { //gas[i] > gas[j]
					break;
				}
			}

		}

		if (gas[i] > gas[i + 1]) { //다음 도시가 더 싸면
			km = city[i];
		}

		sum += gas[i] * km; //합 = 가스값 * 거리

	}

	printf("%lld", sum);
}