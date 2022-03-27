/**************************************************************
# 문제 설명 
 그래프가 주어지면 위상정렬을 해 보자.

위 그래프를 위상정렬을 한 결과는 
1 → 2﻿ → 3 → 4 → 5 → 6
이다. 
우선 순위가 같을 땐 낮은 숫자를 먼저 처리한다.
위상 정렬이란?

 
# 입력 
 첫째 줄에 정점의 개수 v (2 <= v <= 200)와 간선의 개수 n이 입력된다. (만약, v가 6이라면 정점번호는 1~6)
둘째 줄 부터 간선의 정보 (a, b)가 쌍으로 입력된다. (a → b를 의미)

 
# 출력 
 위상 정렬의 결과를 출력한다. 
우선 순위가 같을 땐 정점의 번호가 낮은 것을 우선으로 한다.
사이클이 존재하여 위상정렬을 할 수 없다면 -1을 출력한다.
 
# 입력 예시 
 6 8
1 2
2 3
2 4
3 4
3 6
4 5
4 6
5 6 
# 출력 예시 
 1
2
3
4
5
6 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <list>

using namespace std;

typedef struct
{
    list<int> pointing;
    int pointed;
}point;
int main()
{
    point graph[201];
    for(int i=0;i<201;i++){graph[i].pointed=0;graph[i].pointing=list<int>();}
    int p,l;
    cin>>p>>l;
    int a,b;
    for(int i=0;i<l;i++)
    {
        cin>>a>>b;
        graph[a].pointing.push_back(b);
        graph[b].pointed++;
    }

    int order[200]={0};
    int last=0;
    int start=0;
    while(true)
    {
        bool anyroopd=false;
        for(int i=1;i<=p;i++)
        {
            if(graph[i].pointed==0)
            {
                anyroopd=true;
                for(int j=start;j<=last;j++)
                {
                    if(order[j]>i||order[j]==0)
                    {
                        order[j]=i;
                        last=j+1;
                        break;
                    }
                }
                for(list<int>::const_iterator iter=graph[i].pointing.begin();iter!=graph[i].pointing.end();++iter)
                {
                    graph[(*iter)].pointed--;
                }
                graph[i].pointed=-1;
            }
        }
        start=last;
        if(!anyroopd) break;
    }
    if(last!=p)
    {
        cout<<-1;
    }
    else
    {
        for(int i=0;i<p;i++)
        {
            cout<<order[i]<<endl;
        }
    }
    return 0;
}

/**************************************************************
	문제번호: 3212
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1700 kb
****************************************************************/

