/**************************************************************
# 문제 설명 
 [문제2] 저울추 (18점, 제한시간 1초)
평형저울을 이용하여 1kg 이하의 물건의 무게를 재려고 한다. 준비되어 있는 추는 1g, 3g, 9g, 27g, 81g, 243g, 729g과 같이 7개의 추뿐이다. 평형저울의 양쪽 접시에 물건과 추를 적절히 놓음으로서 물건의 무게를 잴 수 있는데, 예를 들어, 25g의 물건을 재기 위해서는 다음과 같이 저울에 올려놓으면 된다.
   
  물건(25g) 3g          1g 27g 
   |_____________________|
   
물건의 무게가 입력되었을 때 양쪽의 접시에 어떤 추들을 올려놓아야 평형을 이루는지를 결정하는 프로그램을 작성하시오.
 
# 입력 
 1. 물건의 무게를 나타내는 하나의 정수 n이 입력된다. (1≤n≤1,000)
2. n은 물건의 무게가 몇 그람인지를 나타낸다.
 
# 출력 
 1. 저울의 왼쪽 접시와 오른쪽 접시에 올려지는 추를 0으로 구분하여 출력한다.
2. 각 접시에 올려지는 추들은 무게가 가벼운 추부터 하나의 공백으로 구분하여 출력한다.
3. 물건의 무게를 왼쪽 접시의 처음에 표시한다.
 
# 입력 예시 
 25 
# 출력 예시 
 25 3 0 1 27 
# 도움말 
 
    
        
            
            40  ->
            
            
            40 0 1 3 9 27
            
        
        
            
            5  ->
            
            
            5 1 3 0 9
            
        
    

 
# 출처 
 2009 교원프로그래밍경진대회 

*************************************************************/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int quit=false;
string itos(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}
int* intcpy(int* arr)
{
    int* narr=new int[7];
    for(int i=0;i<7;i++)
    {
        narr[i]=arr[i];
    }
    return narr;
}
void dfs(int w,int w2,int weights[],string sw,string sw2)
{
    if(quit) return;
    if(w==w2)
    {
        cout<<sw<<"0 "<<sw2;
        quit=true;
        return;
    }
    for(int i=0;i<7;i++)
    {
        if(weights[i]!=0)
        {
            int* nweights=intcpy(weights);
            nweights[i]=0;
            dfs(w+weights[i],w2,nweights,sw+itos(weights[i])+" ",sw2);
            dfs(w,w2+weights[i],nweights,sw,sw2+itos(weights[i])+" ");
            delete nweights;
        }
    }
}
int main()
{
   int w;
   cin>>w;
   int arr[]={ 1, 3, 9, 27, 81, 243, 729};
   dfs(w,0,arr,itos(w)+" ","");
   return 0;
}

/**************************************************************
	문제번호: 4027
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:564 ms
	메모리 사용량:1728 kb
****************************************************************/

