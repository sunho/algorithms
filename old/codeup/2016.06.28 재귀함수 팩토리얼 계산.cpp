/**************************************************************
# 문제 설명 
 팩토리얼(!)은 다음과 같이 정의된다.
$n!=n\times(n-1)\times(n-2)\times\cdots \times2\times1$
즉, $5! = 5 \times 4 \times 3 \times 2 \times 1 = 120$ 이다.

$n$이 입력되면 $n!$의 값을 출력하시오.
이 문제는 반복문 for, while 등을 이용하여 풀수 없습니다.
 
# 입력 
 자연수 $n$이 입력된다. $(n <= 12)$
 
# 출력 
 $n!$의 값을 출력한다.
 
# 입력 예시 
 5 
# 출력 예시 
 120 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int getInt(int end,int start=1)
{
    if(start!=end)
    {
        return getInt(end,start+1)*start;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<getInt(n);
}

/**************************************************************
	문제번호: 1912
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

