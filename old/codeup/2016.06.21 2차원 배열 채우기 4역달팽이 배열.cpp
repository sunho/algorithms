/**************************************************************
# 문제 설명 
 
평소 호기심이 많은 남호는 정보고 사이트에 있는 달팽이 배열 문제를 다르게 만들고 싶었다.
입력 예시와 출력 예시를 참고 하여 n을 입력 받아 출력하는 프로그램을 작성하시오. 
# 입력 
 배열의 크기 n이 입력된다. (n은 15보다 작은 홀수) 
# 출력 
 역 달팽이 배열을 출력한다. 
# 입력 예시 
 5 
# 출력 예시 
 1 16 15 14 13 
2 17 24 23 12 
3 18 25 22 11 
4 19 20 21 10 
5 6 7 8 9 
 
# 도움말 
  
# 출처 
 salia 

*************************************************************/
#include <stdio.h>
typedef struct
{
    int x,y;
}vec2;

int dir = 0;
vec2 dirVs[4]={{1,0},{0,1},{-1,0},{0,-1}};

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
	문제번호: 1506
	아이디: ksunhokim
	사용언어: C
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1092 kb
****************************************************************/

