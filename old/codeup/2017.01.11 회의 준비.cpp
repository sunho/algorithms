/**************************************************************
# 문제 설명 
 문제3) 회의준비 (중등3, 고등3)

KOI 준비를 위해 회의를 개최하려 한다. 주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 이상의 위원회를 구성하려고 한다. 위원회를 구성하는 방식은 다음과 같다.

1. 서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
2. 효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.

이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다. 각 위원회의 대표만이 회의 시간 중 발언권을 가지며, 따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 자신의 의견을 전달해야 한다. 그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다. 대표에게 의견을 전달하는 경로가 여러 개 있를 경우에는 가장 적은 사람을 거치는 경로로 의견을 전달하며 이 때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.
위원회에서 모든 참석자들의 의사전달시간 중 최대값이 최소가 되도록 대표를 정하는 프로그램을 작성하시오.
예를 들어 1번, 2번, 3번 세 사람으로 구성되어 있는 위원회에서 1번과 2번, 2번과 3번이 서로 알고 있다고 하자. 1번이 대표가 되면 3번이 대표인 1번에게 의견을 전달하기 위해서 2번을 거쳐야만 한다. 반대로 3번이 대표가 되어도 1번이 대표인 3번에게 의견을 전달하려면 2번을 거쳐야만 한다. 하지만 2번이 대표가 되면 1번과 3번 둘 다 아무도 거치지 않고 대표에게 직접 의견을 전달 할 수 있다. 따라서 이와 같은 경우 2번이 대표가 되어야 한다.

 
# 입력 
 첫째 중에 회의에 참석하는 사람의 수 N이 주어진다. 참석자들은 1부터 N까지의 자연수로 표현되며 회의에 참석하는 인원은 100 이하이다.
둘째 줄에는 서로 알고 있는 관계의 수 M이 주어진다.
이어 M개의 각 줄에는 서로 아는 사이인 참석자를 나타내는 두개의 자연수가 주어진다.
 
# 출력 
 첫째 줄에는 구성되는 위원회의 수 K를 출력한다. 다음 K줄에는 각 위원회의 대표 번호를 작은 수부터 차례로 한 줄에 하나씩 출력한다. 한 위원회의 대표가 될 수 있는 사람이 둘 이상일 경우 그중 한 명만 출력하면 된다.
 
# 입력 예시 
 8
7
1 2
2 3
4 5
5 6
4 6
6 7
7 4 
# 출력 예시 
 3
2
4
8
 
# 도움말 
 ※ 스페셜져지 적용됨(2013. 06. 09) 
# 출처 
 2004 지역본선 중등 

*************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct
{
    int mdis;
    int dis;
    int name;
}vertex;
int vertex_size;
int table[101][101];
vertex info[101];
bool compare(const vertex& a,const vertex& b)
{
    return a.mdis<b.mdis;
}
bool final_visit[101];
void dfs(int n)
{
    final_visit[n]=1;
    for(int i=1;i<=vertex_size;i++)
    {
        if(table[n][i]&&!final_visit[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    int connection_size;
    cin>>vertex_size;
    cin>>connection_size;
    for(int i=1;i<=vertex_size;i++)
    {
        info[i].mdis=0;
        info[i].name=i;
    }
    int a,b;
    for(int i=1;i<=connection_size;i++)
    {
        cin>>a>>b;
        table[a][b]=1;
        table[b][a]=1;
    }
    queue<int> qu;
    for(int i=1;i<=vertex_size;i++)
    {
        bool visit[101]={0};
        qu.push(i);
        visit[i]=1;
        info[i].dis=0;
        while(!qu.empty())
        {
            int here=qu.front();
            qu.pop();
            if(info[here].dis>info[i].mdis)
                info[i].mdis=info[here].dis;
            for(int j=1;j<=vertex_size;j++)
            {
                if(table[here][j]&&!visit[j])
                {
                    visit[j]=1;
                    info[j].dis=info[here].dis+1;
                    qu.push(j);
                }
            }
        }
    }
    vector<int> finals;
    sort(info+1,info+vertex_size+1,compare);
    for(int i=1;i<=vertex_size;i++)
    {
        if(!final_visit[info[i].name])
        {
            finals.push_back(info[i].name);
            dfs(info[i].name);
        }
    }
    sort(finals.begin(),finals.end());
    cout<<finals.size()<<endl;
    for(int i=0;i<finals.size();i++)
    {
        cout<<finals[i]<<endl;
    }
    return 0;
}

/**************************************************************
	문제번호: 4508
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:4 ms
	메모리 사용량:1760 kb
****************************************************************/

