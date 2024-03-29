/**************************************************************
# 문제 설명 
 [문제4] 격자길 (22점, 제한시간 1초)
n×m 격자에서 왼쪽 위(0,0)에서 오른쪽 아래(n,m)까지 갈 수 있는 길의 수를 헤아리고자 한다.   
길을 갈 때 몇 가지 제약사항이 있다.
(1) 격자 위의 선을 따라간다.
(2) 아래쪽 또는 오른쪽으로만 갈 수 있다.
(3) (0,0)과 (n,m)을 잇는 대각선보다 위쪽에 있는 점들은 통과할 수 없다. (대각선에 위치하는 점은 통과할 수 있다.) 아래의 그림에서 흰점은 통과할 수 없는 점이고 검은 점은 통과할 수 있는 점이다.

   
예를 들어, 3×4 격자에서 갈 수 있는 길은 다음과 같이 5가지가 있다.

   
격자의 크기가 입력되었을 때 (0,0)부터 (n,m)까지 갈 수 있는 길의 수를 출력하는 프로그램을 작성하시오.
 
# 입력 
 1. 두 개의 정수 n과 m이 입력된다. (1≤n,m≤15)
2. n은 격자의 세로 크기를, m은 격자의 가로 크기를 각각 나타낸다.
 
# 출력 
 1. (0,0)에서 (n,m)까지 갈 수 있는 길의 수를 출력한다.
 
# 입력 예시 
 3 4 
# 출력 예시 
 5 
# 도움말 
  
# 출처 
 2009 교원프로그래밍경진대회 

*************************************************************/
#include <iostream>
#include <queue>
using namespace std;
int n,m;
int total;
int ma[2][2]={{0,1},{1,0}};
void dfs(int x,int y)
{
          if(x>m) return;
          if(y>n) return;
          if(x==m&&y==n)
          {
                    total++;
                    return;
          }
          for(int i=0;i<2;i++)
          {
                    int mx=x+ma[i][0];
                    int my=y+ma[i][1];
                    if(my>=mx*(float)n/m)
                    {
                              dfs(mx,my);
                    }
          }
}
int main()
{
          cin>>n>>m;
          dfs(0,0);
          cout<<total;
}

/**************************************************************
	문제번호: 4029
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:716 ms
	메모리 사용량:1696 kb
****************************************************************/

