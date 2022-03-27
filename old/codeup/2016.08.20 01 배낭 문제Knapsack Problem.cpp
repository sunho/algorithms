/**************************************************************
# 문제 설명 
 어떤 배낭에 W무게 만큼 물건을 담을 수 있다.
물건들은 (무게 Wi, 가격 Vi) 정보를 가지고 있는데, 물건들을 조합해서 담아 가격의 총합이 최대가 되게 하려고 한다.
물건들은 한 종류씩 밖에 없으며, 절대 배낭의 무게를 초과해서는 안 된다.


 
# 입력 
 첫째 줄에 물건의 개수 N(1<= N <= 100)과 배낭의 무게 W( 1 <= W <= 10000 )가 입력된다.
둘째 줄부터 N+1째줄 까지 물건들의 정보가 wi, vi가 한 줄에 하나씩 입력된다. ( 1 <= Wi, Vi <= 100 )
 
# 출력 
 배낭의 무게 W를 초과하지 않으면서 물건의 가격의 총합의 최대값을 출력한다.
 
# 입력 예시 
 4 5
2 3
1 2
3 3
2 2
 
# 출력 예시 
 7 
# 도움말 
 1, 2, 4번 물건을 고른 결과이다.

유사 발전 문제) 2013 KOI 고등부 4번 앱 문제
※ 이 문제를 풀었으면 꼭 풀어 보시기 바랍니다.

 
# 출처 
 유명한 문제 

*************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
typedef struct
{
   int weight,price;
}jew;
int main()
{
    int ar[101][10001]={0};
    jew jews[101];
    int n,pag;
    cin>>n>>pag;
    for(int i=1;i<=n;i++)
    {
        int w,p;
        cin>>w>>p;
        jews[i].weight=w;
        jews[i].price=p;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
        {
            for(int j=1;j<jews[i].weight;j++)
            {
                ar[i][j]=ar[i-1][j];
            }
        }
        for(int j=jews[i].weight;j<=pag;j++)
        {
            int t=j-jews[i].weight;
            int s=jews[i].price;
            if(t!=0) s=jews[i].price+ar[i-1][t];
            ar[i][j]=max(ar[i-1][j],s);
        }
    }
    cout<<ar[n][pag];
}


/**************************************************************
	문제번호: 3740
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:8 ms
	메모리 사용량:5524 kb
****************************************************************/

