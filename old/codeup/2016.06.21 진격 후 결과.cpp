/**************************************************************
# 문제 설명 
 10*10 크기의 보드판이 있다.
각 말들은 제일 아래쪽에서 위쪽 방향으로 진격한다.
장애물은 0이 아닌 숫자로 나타내며, 0보다 크면 블럭 장애물, 0보다 작으면 구덩이 장애물, 0이면 평지이다.
10*10 보드판의 정보가 입력되고, 각 세로줄 아래에 말이 있으면 1, 없으면 0이 입력될 때 각 말의 생존여부를 구하는 프로그램을 구현하시오. 
# 입력 
 10*10의 보드판의 정보가 입력된다.
11째줄에 각 말의 위치 여부가 입력된다.(1:있음, 0:없음)
 
# 출력 
 블럭 장애물에 부딪혀서 실패시 "세로줄 번호 crash", 
구덩이에 떨어져서 실패시 "세로줄 번호 fall",
무사히 통과하면 "세로줄 번호 safe"를 출력한다.
(단, 말이 없는 줄은 아무결과도 출력하지 않는다.)
 
# 입력 예시 
 0 0 0 0 0 0 0 0 0 0 
0 2 0 0 0 0 0 0 0 0 
0 0 -1 0 0 0 0 0 2 0 
0 0 0 0 0 0 0 6 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 -4 2 0 0 0 
0 0 2 0 0 0 0 0 0 0 
0 0 0 0 3 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
1 1 0 0 1 1 0 1 0 1 
 
# 출력 예시 
 1 safe
2 crash
5 crash
6 fall
8 crash
10 safe
 
# 도움말 
 1번 줄 말은 무사 통과
2번 줄 말은 2 크기의 장애물에서 부딪혀 실패.
5번 줄 말은 3 장애물에서 부딪혀 실패
6번 줄 말은 -4 장애물에서 빠져 실패
8번 줄 말은 6 장애물에서 부딪혀 실패
10번 줄 말은 무사 통과 
# 출처 
 moonrabbit2 

*************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int arr[11][10];
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<10;j++)
        {
           scanf("%d",&arr[i][j]);
        }
    }
    for(int j=0;j<10;j++)
    {
        if(arr[10][j] == 1)
        {

            for(int i=9;i>=0;i--)
            {
                if(arr[i][j]>0)
                {
                    cout<<j+1<<" crash\n";
                    break;
                }
                else if(arr[i][j]<0)
                {
                    cout<<j+1<<" fall\n";
                    break;
                }
                else if(i==0)
                {
                    cout<<j+1<<" safe\n";
                }
            }
        }
    }
}

/**************************************************************
	문제번호: 1509
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

