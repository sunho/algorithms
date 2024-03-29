/**************************************************************
# 문제 설명 
 문제3) 내리막 길(고등3)


  여행을 떠난 영수는 지도를 하나 구하였다. 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도상에서 상하좌우로 이웃한 곳끼리만 가능하다.
   
  현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 영수는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다. 그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.
   
  지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.

 
# 입력 
 첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다. 
이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다. M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.
 
# 출력 
 첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.
 
# 입력 예시 
 4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10 
# 출력 예시 
 3 
# 도움말 
  
# 출처 
 2006 지역본선 고등 

*************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int memo[500][500];
int myMap[500][500];
int w,h;
int trace(int x,int y,int hi)
{
    if(x<0||x>=w) return 0;
    if(y<0||y>=h) return 0;
    if(myMap[y][x]>=hi) return 0;
    if(y==h-1&&x==w-1) return 1;
    hi=myMap[y][x];
    if(!memo[y][x])memo[y][x]=trace(x-1,y,hi)+trace(x+1,y,hi)
    +trace(x,y-1,hi)+trace(x,y+1,hi);
    return memo[y][x];
}
int main()
{
    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>myMap[i][j];
        }
    }
    cout<<trace(0,0,myMap[0][0]+1);
}

/**************************************************************
	문제번호: 4573
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:8 ms
	메모리 사용량:3648 kb
****************************************************************/

