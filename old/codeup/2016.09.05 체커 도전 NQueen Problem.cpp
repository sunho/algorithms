/**************************************************************
# 문제 설명 
 체스에서 퀸(queen)은 가로, 세로, 대각선에 같은 퀸을 배치하지 못한다.
각 체커는 각 행에 1개, 각 열에 1개씩 밖에 배치할 수 없다. 
6*6체커보드에서 6개의 체커들은 다음과 같이 퀸을 배치할 수 있다.


    
        
            
            1
            2
            3
            4
            5
            6
        
        
            1
            
            Q
            
            
            
            
        
        
            2
            
            
            
            Q
            
            
        
        
            3
            
            
            
            
            
            Q
        
        
            4
            Q
            
            
            
            
            
        
        
            5
            
            
            Q
            
            
            
        
        
            6
            
            
            
            
            Q
            
        
    


이 상태의 열 번호는 2 4 6 1 3 5로 나타낼 수 있다.
체스판의 크기가 N이 주어질 때, 퀸을 놓을 수 있는 모든 배치의 개수를 구하시오.





 
# 입력 
 체스판의 크기 N이 입력된다( 6 <= N <= 13 )
 
# 출력 
 처음 세 줄은 가능한 해법 3가지를 출력한다. 이때 열번호가 적은 순서부터 오름차순으로 세 가지만 출력한다.
네째 줄에 가능한 퀸의 배치 개수를 출력한다.
 
# 입력 예시 
 6 
# 출력 예시 
 2 4 6 1 3 5 
3 6 2 5 1 4 
4 1 5 2 6 3 
4 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int siz;
struct _cais
{
    int arr[13];
    bool operator>(const struct _cais& other)
    {
        for(int i=0;i<siz;i++)
        {
            if(arr[i]>other.arr[i]) return true;
            else if(arr[i]<other.arr[i]) return false;
        }
        return false;
    };
    int& operator[](int index) {return arr[index];};
    bool empty(){return !arr[0];};
};
typedef _cais cais;
vector<cais> caiss;
cais thi;

int able[13][13];
int dir[4][2]={{1,1},{-1,-1},{-1,1},{1,-1}};

void visit(int x,int y,int d)
{
    for(int i=0;i<siz;i++)
    {
        able[i][x]+=d;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x,dy=y;
        while(true)
        {
            dx+=dir[i][0];
            dy+=dir[i][1];
            if(dx==-1||dy==-1||dx==siz||dy==siz) break;
            able[dy][dx]+=d;
        }
    }
}

void dfs(int y)
{
    for(int x=0;x<siz;x++)
    {
        if(able[y][x]==0)
        {
            thi[y]=x;
            if(y==siz)
            {
                caiss.push_back(thi);
                return;
            }
            visit(x,y,1);
            dfs(y+1);
            visit(x,y,-1);
        }
    }
}

int main()
{
    cin>>siz;
    dfs(0);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<siz;j++)
        {
            cout<<caiss[i][j]+1<<" ";
        }
        cout<<endl;
    }
    cout<<caiss.size();
    return 0;
}

/**************************************************************
	문제번호: 3520
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:1992 ms
	메모리 사용량:11688 kb
****************************************************************/

