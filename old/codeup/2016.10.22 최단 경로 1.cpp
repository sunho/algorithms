/**************************************************************
# 문제 설명 
 각 지점과 길이 있는 두 지점 사이의 거리가 주어질 때, 시작점과 끝점을 입력받아 두 지점 사이의 최단 경로를 찾는 프로그램을 작성하시오.
예를 들어 그림에서 A와 D사이의 최단경로는 A->B->C->D D와 E사이의 최단경로는 D->G->E가 된다.
 
# 입력 
 첫 번째 줄에 지점의 개수 N과 두 지점을 잇는 거리의 개수 M이 주어진다.
이어 M줄에는 두 지점과 그 두 지점 사이의 거리가 주어진다.
마지막 줄에는 출발지점과 도착지점이 주어진다.
지점의 이름은 A부터 시작하여 영문자 대문자이고 N은 26이하의 자연수이다. 
# 출력 
 최단 거리를 출력한다. 단, 출발지점과 도착지점 사이의 경로가 없다면 -1을 출력한다.
 
# 입력 예시 
 7 10
A B 2
A E 5
B E 6
A F 9
E G 2
F G 1
G D 4
E D 7
B C 3
C D 5
A D 
# 출력 예시 
 10 
# 도움말 
  
# 출처 
 jin1sun 

*************************************************************/
#include <iostream>

using namespace std;
static const int N=26;
static const int M=100;
static const int INF=99999;
int capital2i(char c)
{
    return c-'A';
}
int main()
{
    int graph[N][N];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)graph[i][j]=INF;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        char a,b;
        int d;
        cin>>a>>b>>d;
        graph[capital2i(a)][capital2i(b)]=d;
        graph[capital2i(b)][capital2i(a)]=d;
    }
    char a,b;
    cin>>a>>b;
    int s,e;
    s=capital2i(a);
    e=capital2i(b);

    int dist[N];
    for(int i=0;i<n;i++) dist[i]=INF;
    int visit[N]={0};
    dist[s]=0;
    for(int i=0;i<n;i++)
    {
        int v,min=INF;
        for(int j=0;j<n;j++)
        {
            if(min>=dist[j]&&visit[j]==0)
            {
                min=dist[j];
                v=j;
            }
        }
        visit[v]=1;
        for(int j=0;j<n;j++)
        {
            if(graph[v][j]+dist[v]<dist[j])
            {
                dist[j]=graph[v][j]+dist[v];
            }
        }
    }
    if(dist[e]==INF) dist[e]=-1;
    cout<<dist[e];
    return 0;
}

/**************************************************************
	문제번호: 3215
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

