/**************************************************************
# 문제 설명 
 정수를 한 개 입력받아 1을 더해 출력하는 프로그램을 작성해보자.
(단, 정수는 -2147483648 ~ 2147483647 의 범위로 입력된다.)

주의 : 계산되고 난 후의 데이터 범위에 주의한다.
 
# 입력 
 정수 한 개가 입력된다.
(단, -2147483648 ~ 2147483647 의 범위로 입력된다.)
 
# 출력 
 입력된 정수에 1을 더해 출력한다.
 
# 입력 예시 
 2147483647 
# 출력 예시 
 2147483648 
# 도움말 
 어떤 변수(a)에 값을 저장한 후  a+1 의 값을 출력할 수도 있고,
++a 후 출력할 수도 있다.

++a, --a, a++, a-- 와 같이 어떤 변수의 앞이나 뒤에 붙여 변수에 저장되어 있는 값을 1씩 더하거나 빼주는 연산자를 증감연산자라고 한다.

증감연산자를 변수 앞에 붙이면 그 변수를 사용하기 전에 증감을 먼저 수행하고,

증감연산자를 변수 뒤에 붙이면 일단 변수에 저장되어 있는 값을 먼저 사용하고 난 후에 증감을 수행한다.
 
# 출처 
 정보컴퓨터교사 연구회/카페 (기초100제 v1.0) 

*************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    long a;
    cin>>a;
    cout<<a+1;
}

/**************************************************************
	문제번호: 1044
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

