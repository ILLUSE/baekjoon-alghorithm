#include <stdio.h>

int main() {

    int N; // ���� ������ ũ��
    int M; // ��ǳ���� ����

    scanf_s("%d %d", &N, &M);  //N,M �Է¹ޱ�
    
    int arr[50][50]; //�������� ��� ���� �� �迭

    int i, j;
    for (i = 0; i < N; i++) { //��� �� �Է¹ޱ�
        for (j = 0; j < N; j++) 
            scanf_s("%d",&arr[i][j]);
    }

    if (N == 1) {
        printf("%d", arr[0][0]);
        return 0;
    }

    int x, y, a;
    int max = 0;
    int count = 0;
    for (x = 0; x < N; x++) { //���� ��ǳ�� ������ ����
        
        for (y = 0; y < N; y++) {
            
            count = 0;

            for (a = 1; a <= M; a++) { //��ǳ������ ���� ��� �� ���ϱ�
                
                if(x + a < N) //�Ʒ���
                    count = count + arr[x + a][y];
                if(x - a >= 0) //����
                    count = count + arr[x - a][y];
                if(y + a < N) //������
                    count = count + arr[x][y + a];
                if (y - a >= 0) //����
                    count = count + arr[x][y - a];
                
            }
            count = count + arr[x][y]; //���

            if (max < count)  //��ǥ���� count ���� ��, ���� max ���� ũ�� �ֱ�
                max = count;
            
        }
            
    }

    x = 0;
    y = 0;
    a = 0;
    int max2 = 0;
    count = 0;
    for (x = 0; x < N; x++) { //X�� ��ǳ�� ������ ����

        for (y = 0; y < N; y++) {
            count = 0;

            for (a = 1; a <= M; a++) {
            if(x+a < N && y + a < N) //���� ���
                count = count + arr[x + a][y+a];
            if (x + a < N && y - a >= 0) //���� �ϴ�
                count = count + arr[x + a][y - a];
            if (x - a >= 0 && y + a < N) //���� ���
                count = count + arr[x - a][y + a];
            if (x - a >= 0 && y - a >= 0) //���� �ϴ�
                count = count + arr[x - a][y - a];
            }
            count = count + arr[x][y]; //���

            if (max2 < count)  //��ǥ���� count ���� ��, ���� max ���� ũ�� �ֱ�
                max2 = count;
        }

    }

    if(max > max2)
        printf("%d", max);
    else printf("%d", max2);

    return 0;
}