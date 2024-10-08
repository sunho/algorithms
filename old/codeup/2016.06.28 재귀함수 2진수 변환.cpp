/**************************************************************
# 문제 설명 
 어떤 $10$진수 $n$이 주어지면 $2$진수로 변환해서 출력하시오.

예)
10    ----->  1010
0    ----->  0
1    ----->  1
2    ----->  10
1024    ----->  10000000000
이 문제는 반복문을 이용하여 풀 수 없습니다.
 
# 입력 
 $10$진수 정수 $n$이 입력된다.
$(0<=n<=2,100,000,000)$
 
# 출력 
 $2$진수로 변환해서 출력한다.
 
# 입력 예시 
 7 
# 출력 예시 
 111 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
using namespace std;
void convert(int n,int n2)
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

/**************************************************************
	문제번호: 1920
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

