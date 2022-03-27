/**************************************************************
# 문제 설명 
 하나의 정수 N을 입력받아 다음과 같이 지그재그로 출력하시오.
N이 3이라면,
1 6 7
2 5 8
3 4 9
 
# 입력 
 정수 n이 입력된다. ( 1 <= n <= 100)
 
# 출력 
 n * n 배열을 수직으로 채워서 출력한다.
 
# 입력 예시 
 3 
# 출력 예시 
 1 6 7 
2 5 8 
3 4 9 
 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <stdio.h>

int main()
{
    int size;
    int number=1;
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(j%2==0)
            {
                //짝수
                printf("%d ",(j*size)+i+1);
            }
            else
            {
                //홀수
                printf("%d ",((j+1)*size)-i);
            }
        }
        printf("\n");
    }
}

/**************************************************************
	문제번호: 1504
	아이디: ksunhokim
	사용언어: C
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1092 kb
****************************************************************/

