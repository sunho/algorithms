/**************************************************************
# 문제 설명 
 문제2)
명보네 동네 가게의 현금 출납기에는 k 가지 동전이 각각 n1, n2, … , nk개 씩 들어있다. 가게 주인은 명보에게 T원의 지폐를 동전으로 바꿔 주려고 한다. 이때, 동전 교환 방법은 여러 가지가 있을 수 있다. 예를 들어, 10원 짜리, 5원 짜리, 1원 짜리 동전이 각각 2개, 3개, 5개씩 있을 때, 20원 짜리 지폐를 다음과 같은 4가지 방법으로 교환할 수 있다.
20 = 10×2 
20 = 10×1 + 5×2 
20 = 10×1 + 5×1 + 1×5 
20 = 5×3 + 1×5
입력으로 지폐의 금액 T, 동전의 가지 수 k, 각 동전 하나의 금액 pi와 개수 ni가 주어질 때 (i=1, 2,…, k) 지폐를 동전으로 교환하는 방법의 가지 수를 계산하는 프로그램을 작성하시오. 방법 의 수는 231을 초과하지 않는 것으로 가정한다.
 
# 입력 
 첫째 줄에는 지폐의 금액 T(0＜T≤10,000), 둘째 줄에는 동전의 가지 수 k(0＜k≤100), 셋째 줄부터 마지막 줄까지는 각 줄에 동전의 금액 pi(0＜pi≤T)와 개수 ni(0＜ni≤1,000)가 주어진다. pi와 ni사이에는 빈칸이 하나씩 있다.
 
# 출력 
 첫째 줄에 동전 교환 방법의 가지 수를 출력한다. 방법이 없을 때는 0을 출력한다. 
# 입력 예시 
 20
3
5 3
10 2
1 5 
# 출력 예시 
 4 
# 도움말 
  
# 출처 
 2002 KOI 중등 

*************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

 typedef struct{
    int price,quantity;
 }coin;
 bool compare(const coin& a,const coin&b)
 {
     return a.price<b.price;
 }
int main()
{
    int goal;
    coin coins[101];
    int size;
    cin>>goal;
    cin>>size;
    coins[0].price=0;
    coins[0].quantity=0;
    for(int i=1;i<=size;i++)
    {
        cin>>coins[i].price;
        cin>>coins[i].quantity;
    }
    sort(coins,coins+size,compare);

    int DP[101][10001]={0};
    DP[0][0]=1;
    for(int i=1;i<=size;i++)
    {
        DP[i][0]=1;
        for(int j=1;j<=goal;j++)
        {
            for(int z=0;z<=coins[i].quantity;z++)
            {
                if(coins[i].price*z>j) break;
                DP[i][j]+=DP[i-1][j-coins[i].price*z];
            }
        }
    }
    cout<<DP[size][goal];
    return 0;
}

/**************************************************************
	문제번호: 4484
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:8 ms
	메모리 사용량:5528 kb
****************************************************************/

