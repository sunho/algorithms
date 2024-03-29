/**************************************************************
# 문제 설명 
 어떤 수 n이 입력되면 n의 각 자릿수의 합이 한 자리가 될때까지 계산하여 출력하시오.

예) 1234567
1234567 → 1+2+3+4+5+6+7 = 28 → 2 + 8 = 10 → 1 + 0 = 1
 
# 입력 
 자연수 n이 입력된다. (1 <= n <= 10,000,000)
 
# 출력 
 자릿수의 합이 한자리가 될때까지 계산하여 출력한다.
 
# 입력 예시 
 1234567 
# 출력 예시 
 1 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num,i,num2=0;
    cin>>num;
    while(1)
    {
        while(num)
        {
            num2+=num %10;
            num = num / 10;
        }
        num=num2;
        num2=0;
        if(num%10==num) break;
    }
    cout<<num;
    return 0;
}

/**************************************************************
	문제번호: 1620
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

