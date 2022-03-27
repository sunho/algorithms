/**************************************************************
# 문제 설명 
 LIS(Longest Increasing subsequence)란 최장 증가 부분수열을 말한다.
프로그래밍 문제를 풀 다 보면 이것을 응용하는 문제가 많이 출제되고 있고, 동적계획법의 대표적인 사용 예 중 하나이다.
다음과 같은 원소의 개수가 8개(N)인 수열이 있을 때,
1 3 2 9 7 8 5 10 
LIS = 1 2 7 8 10 으로 그 길이는 5이다.

 
# 입력 
 첫째줄에 수열의 원소개수 N이 입력된다.( 1 <= N <= 1000 )
둘째 줄에 N개의 원소가 순서대로 공백으로 구분되어 입력된다. ( 1 ~ 30,000 )
 
# 출력 
 최장 증가 부분수열의 길이를 출력한다.
 
# 입력 예시 
 8
1 3 2 9 7 8 5 10  
# 출력 예시 
 5 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[1000];
    int siz;
    cin>>siz;
    for(int i=0;i<siz;i++)
    {
        cin>>arr[i];
    }
    int lis[1000];
    int siz2=0;
    lis[0]=arr[0];
    for(int i=1;i<siz;i++)
    {
        if(arr[i]>lis[siz2])
        {
            siz2++;
            lis[siz2]=arr[i];
            continue;
        }
        (*lower_bound(lis,lis+siz2+1,arr[i]))=arr[i];
    }
    cout<<siz2+1;
    return 0;
}

/**************************************************************
	문제번호: 3735
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1712 kb
****************************************************************/
