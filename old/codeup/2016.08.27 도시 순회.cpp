/**************************************************************
# 문제 설명 
 포화이진트리(full binary tree) 형태로 연결된 도시들이 있다.
높이가 3일때는 다음그림과 같다.

우리는 차로 모든 도시를 단 한번씩만 방문하고 싶다. (즉, 한번 지나간 길은 다시 갈수 없다.)
트리의 높이 H가 주어질 때 필요한 자동차 갯수의 최솟값을 출력하라. 
# 입력 
 높이 H가 입력된다. ( 2 <= H <= 61 )
 
# 출력 
 필요한 자동차의 수를 출력한다.
 
# 입력 예시 
 3 
# 출력 예시 
 3 
# 도움말 
 다음과 같이 최소 3대의 자동차가 필요하다.

 
# 출처 
 gijun0102 

*************************************************************/
#include <iostream>
using namespace std;

int main()
{
    long long dp[62]={0};
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=1;
        for(int j=i-2;j>=1;j--)
        {
            dp[i]+=dp[j]*2;
        }
    }
    cout<<dp[n];
}

/**************************************************************
	문제번호: 3725
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

