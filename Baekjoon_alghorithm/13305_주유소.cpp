#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	long long int N = 0; //���� ����
	long long int city[100000]; //���� ������ �Ÿ�
	long long int gas[100000]; //�������� �⸧ ����

	scanf("%lld", &N);
	for (int i = 0; i < N - 1; i++)
		scanf("%lld", &city[i]);
	for (int i = 0; i < N; i++)
		scanf("%lld", &gas[i]);


	long long int sum = 0; //�� �⸧ ����
	long long int skip = -1; //
	for (int i = 0; i < N-1; i++) {

		if (i <= skip)
			continue;

		long long int km = 0; //������ �Ÿ�

		if (gas[i] <= gas[i + 1]) { //���� ���ð� �� ��ΰų� ������ ���ٸ�

			km = city[i];

			for(int j=i+1;j<N-1;j++){

				if (gas[i] <= gas[j]) { //�� �� ���ñ����� �Ÿ� ���ϱ�
					km += city[j];
					skip = j;
				}
				else { //gas[i] > gas[j]
					break;
				}
			}

		}

		if (gas[i] > gas[i + 1]) { //���� ���ð� �� �θ�
			km = city[i];
		}

		sum += gas[i] * km; //�� = ������ * �Ÿ�

	}

	printf("%lld", sum);
}