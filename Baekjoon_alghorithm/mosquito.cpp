#include <stdio.h>

int main() {

    int N; // 붐힐 마을의 크기
    int M; // 물풍선의 범위

    scanf_s("%d %d", &N, &M);  //N,M 입력받기
    
    int arr[50][50]; //붐힐마을 모기 수가 들어갈 배열

    int i, j;
    for (i = 0; i < N; i++) { //모기 수 입력받기
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
    for (x = 0; x < N; x++) { //십자 물풍선 터지는 로직
        
        for (y = 0; y < N; y++) {
            
            count = 0;

            for (a = 1; a <= M; a++) { //물풍선으로 잡은 모기 수 구하기
                
                if(x + a < N) //아래쪽
                    count = count + arr[x + a][y];
                if(x - a >= 0) //윗쪽
                    count = count + arr[x - a][y];
                if(y + a < N) //오른쪽
                    count = count + arr[x][y + a];
                if (y - a >= 0) //왼쪽
                    count = count + arr[x][y - a];
                
            }
            count = count + arr[x][y]; //가운데

            if (max < count)  //좌표마다 count 구한 뒤, 기존 max 보다 크면 넣기
                max = count;
            
        }
            
    }

    x = 0;
    y = 0;
    a = 0;
    int max2 = 0;
    count = 0;
    for (x = 0; x < N; x++) { //X자 물풍선 터지는 로직

        for (y = 0; y < N; y++) {
            count = 0;

            for (a = 1; a <= M; a++) {
            if(x+a < N && y + a < N) //우측 상단
                count = count + arr[x + a][y+a];
            if (x + a < N && y - a >= 0) //우측 하단
                count = count + arr[x + a][y - a];
            if (x - a >= 0 && y + a < N) //좌측 상단
                count = count + arr[x - a][y + a];
            if (x - a >= 0 && y - a >= 0) //좌측 하단
                count = count + arr[x - a][y - a];
            }
            count = count + arr[x][y]; //가운데

            if (max2 < count)  //좌표마다 count 구한 뒤, 기존 max 보다 크면 넣기
                max2 = count;
        }

    }

    if(max > max2)
        printf("%d", max);
    else printf("%d", max2);

    return 0;
}