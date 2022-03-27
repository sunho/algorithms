/**************************************************************
# 문제 설명 
 n이 입력되면 크기가 n인 다음과 같은 2차원 배열을 출력하시오.

입력 예)
3
출력 예)
1 2 3
8 9 4
7 6 5

 
# 입력 
 2차원 배열의 크기 n이 입력된다.(n<=50)
 
# 출력 
 크기가 n인 달팽이 배열을 출력한다.(설명참조)
 
# 입력 예시 
 2 
# 출력 예시 
 1 2 
4 3 
 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <stdio.h>
typedef struct
{
    int x,y;
}vec2;

int dir = 0;
vec2 dirVs[4]={{0,1},{1,0},{0,-1},{-1,0}};

void turn()
{
    if(dir==3)
    {
        dir=0;
    }
    else
    {
        dir++;
    }
}

vec2 dirV()
{
    return dirVs[dir];
}

int main()
{
    int arr[50][50]={0};
    int number = 0;
    int size;
    scanf("%d",&size);
    vec2 arrV = {0,0};

    int maxSize = size*size;
    while(number != maxSize)
    {
        arr[arrV.x][arrV.y]=++number;

        arrV.x += dirV().x;
        arrV.y += dirV().y;

        if(arrV.x==size||
           arrV.x==-1||
           arrV.y==size||
           arrV.y==-1)
        {
            arrV.x-= dirV().x;
            arrV.y-= dirV().y;
            turn();
            arrV.x += dirV().x;
            arrV.y += dirV().y;
        }
        else if(arr[arrV.x][arrV.y] != 0)
        {
            arrV.x-= dirV().x;
            arrV.y-= dirV().y;
            turn();
            arrV.x += dirV().x;
            arrV.y += dirV().y;
        }
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

/**************************************************************
	문제번호: 1505
	아이디: ksunhokim
	사용언어: C
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1092 kb
****************************************************************/

