/**************************************************************
# 문제 설명 
 $n$이 입력되면 다음과 같은 삼각형을 출력하시오.

예)
$n$ 이 $5$ 이면
*
**
***
****
*****

이 문제는 반복문 for, while 등을 이용하여 풀수 없습니다. 
# 입력 
 길이 $n$이 입력된다.$(1<=n<=150)$
 
# 출력 
 삼각형을 출력한다.
 
# 입력 예시 
 3 
# 출력 예시 
 *
**
*** 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
using namespace std;
/*void convert(int n,int n2)
{
    if(n!=1&&n!=0)
    {
        n2=n%2;
        n/=2;
        convert(n,n2);
    }
    else
    {
        n2=n;
    }
    cout<<n2;
}
int main()
{
    int n;
    cin>>n;
    convert(n,1);
}
*/
void printStar(int n)
{
    if(n!=0)
    {
        cout<<"*";
        printStar(n-1);
    }
}
void printStars(int n,int p=1)
{
    if(n+1!=p)
    {
        printStar(p);
        cout<<endl;
        printStars(n,p+1);
    }
}
int main()
{
    int n;
    cin>>n;
    printStars(n);
}

/**************************************************************
	문제번호: 1953
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

