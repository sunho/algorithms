/**************************************************************
# 문제 설명 
 0과 1로 이루어진 길이가 n(n<=12)인 이진수가 있다.
여기서 1의 개수가 k개인 수열을 모두 출력하고자 한다.
예를 들어 길이 n이 3이고, 1의 개수 k가 2인 경우,
011 101 110
이다. 
# 입력 
 정수 n과  k가 입력된다.( 1 <= k <= n <= 12 ) 
 
# 출력 
 가능한 경우를 공백으로 분리하여 하나씩 출력하되 오름차순으로 출력한다.

 
# 입력 예시 
 3 2 
# 출력 예시 
 011 101 110  
# 도움말 
  
# 출처 
 MSP 11월 

*************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> result;
void yee(int n, int k, string str)
{
    if (n==0)
    {
        if(k==0)
            result.push_back(str);
        return;
    }
    yee(n-1,k-1,str+"1");
    yee(n-1,k,str+"0");
}
int main()
{
    int n,k;
    cin>>n>>k;
    yee(n,k,"");
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}

/**************************************************************
	문제번호: 3440
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1708 kb
****************************************************************/

