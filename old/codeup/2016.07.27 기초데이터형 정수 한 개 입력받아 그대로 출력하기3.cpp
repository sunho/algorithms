/**************************************************************
# 문제 설명 
 정수 한 개를 입력받아 그대로 출력해보자.
(단, 입력되는 정수의 범위는 –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 이다.)
 
# 입력 
 정수 한 개가 입력된다.
(단, 입력되는 정수의 범위는 –9223372036854775808 ~ 9223372036854775807 이다.)
 
# 출력 
 입력된 정수가 그대로 출력된다.
 
# 입력 예시 
 -2147483649 
# 출력 예시 
 -2147483649 
# 도움말 
 -2147483648 ~ +2147483647 범위의 정수를 저장하고 처리하기 위해서는 int 데이터형을 사용해 변수를 선언하면된다.
(int 로 선언하고 %d나 %i 로 입력 받거나 출력하면 된다.)

하지만 이 범위를 넘어가는 정수를 저장하기 위해서는 보다 큰 범위를 저장할 수 있는 다른 데이터형을 사용해야 정상적으로 저장시킬 수 있다.

long long int 데이터형을 사용하면 –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 범위의 정수를 저장할 수 있다.

[예시]

long long int n;
scanf("%lld", &n);
printf("%lld", n);
 
# 출처 
 정보컴퓨터교사 연구회/카페 (기초100제 v1.0) 

*************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    cout<<n;
}

/**************************************************************
	문제번호: 1030
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

