/**************************************************************
# 문제 설명 
 생명 게임을 일반화 시켜보자.
이번에는 격자판의 크기 a * b가 주어지고,
생명이 태어나기 위한 조건(x), 생명을 유지하기 위한 최소 조건(y), 생명이 죽는 최소 조건(z)이 입력으로 주어진다.
룰은 아래 링크를 따라 생명게임 1을 참고하고(생명게임 1에서 조건들을 일반화 시킴),
k세대가 지난 후의 모습을 출력하시오. 


참고) 생명게임 1

 
# 입력 
 첫번째 줄에 격자판의 크기 행 a, 열 b가 입력된다. (1<=a<=170, 1<=b<=170)
두번째 줄에는 생명이 태어나기 위한 이웃의 수 x, 생명이 살기 위해 필요한 최소 이웃 수 y, 생명이 죽는 최소 이웃수 z가 입력된다. (0 <= x, y, z <= 8)
세번째 줄부터는 a*b 격자판의 크기에 격자값이 입력된다. 1은 생명이 존재하는 것이고, 0은 생명이 존재하지 않는다는 것이다.
마지막 줄에 k가 입력된다. ( 1 <= k <= 1,000 ) 
# 출력 
 k 세대가 지난 후의 모습을 출력하시오.
 
# 입력 예시 
 5 5
2 1 5
1 1 1 0 0
0 1 0 1 1
0 0 1 1 0
0 1 0 1 0
0 0 1 1 1
1 
# 출력 예시 
 1 1 1 0 1 
0 1 0 1 1 
1 0 0 1 0 
0 1 0 0 0 
0 1 1 1 1 
 
# 도움말 
 격자판의 크기 5*5가 입력됩니다.
주변에 2마리의 생명이 존재하면 생명이 탄생하고,
생명을 유지하기 위해선 최소 1명의 이웃이 있어야 되고,
5명 이상의 이웃이 있을 시 죽습니다.
한 세대가 지난 후에 생명이 있는 경우를 1, 없는 경우를 0으로 출력합니다.
k가 1이므로 1세대 지난 후의 모습을 출력한 것입니다. 
# 출처 
 gbs91413 

*************************************************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int **arr;
int **arr2;
int getSurrounding(int y,int x)
{
    return arr[y-1][x-1]+arr[y-1][x]+arr[y-1][x+1]+
            arr[y][x-1]+arr[y][x+1]+
            arr[y+1][x-1]+arr[y+1][x]+arr[y+1][x+1];
}
int** arrMalloc(int sizeY,int sizeX)
{
    int **arr3 = new int*[sizeY];
    for(int i=0; i<sizeY; i++){
        arr3[i] = new int[sizeX];
        memset(arr3[i],0,sizeof(int)*sizeX);
    }
    return arr3;
}
int main()
{
    int n,n2;
    int x,y,z;
    scanf("%d %d",&n,&n2);
    arr = arrMalloc(n+2,n2+2);
    arr2 = arrMalloc(n+2,n2+2);

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n2+1;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int s;
    scanf("%d",&s);
    for(int d=0;d<s;d++)
    {
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                if(arr[i][j]==1)
                {
                    if(getSurrounding(i,j)>=y)
                    {
                        arr2[i][j]=1;
                    }
                    if(getSurrounding(i,j)>=z)
                    {
                        arr2[i][j]=0;
                    }
                }
                else if(arr[i][j]==0)
                {
                    if(getSurrounding(i,j)==x)
                    {
                        arr2[i][j]=1;
                    }
                }
            }
        }
        arr=arr2;
        arr2=arrMalloc(n+2,n2+2);
    }

    for(int i=1;i<n+1;i++, puts(""))
    {
        for(int j=1;j<n2+1;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
}

/**************************************************************
	문제번호: 1520
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:344 ms
	메모리 사용량:52300 kb
****************************************************************/

