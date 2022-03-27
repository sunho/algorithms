/**************************************************************
# 문제 설명 
 a,b를 입력받아 a/b를 소수로 출력하는 프로그램을 작성하시오.
모든 유리수는 유한소수 또는 순환하는 무한소수로 표현된다.
a/b의 반복되는 부분을 괄호로 묶어 표시하시오.
입력 예)
1 5
출력 예)
0.2(0) 
# 입력 
 분자(a)와 분모(b)가 공백으로 분리되어 입력된다.(1<=a,b<=1,000,000,000)

 
# 출력 
 순환소수로 출력하되 반복되는 부분은 (, )괄호로 묶어 출력한다. 출력예시 참고.
단, 출력되는 순환마디의 길이는 999개 미만이다. 
# 입력 예시 
 9 7 
# 출력 예시 
 1.(285714) 
# 도움말 
 
 
# 출처 
 2012 창원과고 교내경시대회 

*************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    int digits[200];
    int index=0;

    bool fin=false;
    int bstart=1;
    int bend=1;
    int remain=a%b,digit=a/b;
    while(index!=200)
    {
        digits[index++]=digit;
        digit=remain*10/b;
        remain=remain*10%b;
    }
    for(int i=1;i<=index-2;i++)
    {
        int length=(index-i)/3;
        for(int z=1;z<=length;z++)
        {
            bool isCir=true;
            for(int j=i;j<=z+i;j++)
            {
                if(digits[j]!=digits[j+z]||digits[j]!=digits[j+z+z])
                {
                    isCir=false;
                    break;
                }
            }
            if(isCir)
            {
                bstart=i;
                bend=i+z-1;
                cout<<digits[0]<<".";
                for(int i=1;i<=bend;i++)
                {
                    if(bstart==i) cout<<"(";
                    cout<<digits[i];
                    if(i==bend) cout<<")";
                }
                return 0;
            }
        }
    }
}

/**************************************************************
	문제번호: 2609
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

