#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int n = 0;// �� ��Ÿ�� ����
	int m = 0;// �귣�� ����

	scanf("%d %d", &n, &m);

	int pack = 0; //��Ű�� ����(6��)
	int each = 0; //���� ����
	int cheapest_pack = 1001;
	int cheapest_each = 1001;

	for (int i = 0; i < m; i++) { //���� �� ��Ű�� ����,���� �� ���� ���� ã��
		scanf("%d %d", &pack, &each);
		if (pack < cheapest_pack)cheapest_pack = pack;
		if (each < cheapest_each)cheapest_each = each;
		
	}
	//printf("\ncheapest : %d %d\n", cheapest_pack, cheapest_each);

	int total = 0;
	if (cheapest_each * 6 <= cheapest_pack) { //������ 6�� ��� �� ������ ��� �ͺ��� �ΰų� ������
		total = cheapest_each * n; //�׳� �� ������ ���!
		
	}
	else {
		total = cheapest_pack * (n / 6);
		n = n % 6;
		if (n > 0 && n * cheapest_each > cheapest_pack) { //���� * �������� ������ ��°ͺ��� ��θ�
			total += cheapest_pack;
			
		}
		else if (n > 0 && n * cheapest_each <= cheapest_pack) {
			total += n * cheapest_each;
			
		}
		
	}

	printf("%d", total);
	return 0;
}