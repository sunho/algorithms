/**************************************************************
# 문제 설명 
 실수 한 개를 입력받는다.

입력 받은 실수를 정수 부분과 실수 부분으로 나누어 따로 출력한다.
 
# 입력 
 실수 한 개가 입력된다.
(단, 입력 값은 절댓값이 정수부가 $100,000$을 넘지 않으며, 소수점 이하는 0으로 시작하지 않으며, 6자리이하이다.)
 
# 출력 
 첫 번째 줄에 정수 부분을,
두 번째 줄에 실수 부분을 입력된 자릿수만큼 그대로 출력한다.
 
# 입력 예시 
 1.414213 
# 출력 예시 
 1
414213 
# 도움말 
 int a, b;
scanf("%d.%d", &a, &b); 
의 방법도 사용할 수 있다.
 
# 출처 
 정보컴퓨터교사 연구회/카페 (기초100제 v1.0) 

*************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    int a, b;
    scanf("%d.%d", &a, &b);
    cout<<a<<endl<<b;
}

/**************************************************************
	문제번호: 1023
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

