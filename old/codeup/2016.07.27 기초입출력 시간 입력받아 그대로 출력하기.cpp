/**************************************************************
# 문제 설명 
 시간이 특정 형식에 맞추어 입력될 때 그대로 출력하는 프로그램을 작성 해보자.
 
# 입력 
 시(hour)와 분(minute)이 ":"(콜론)으로 구분되어 입력된다.
 
# 출력 
 입력받은 시간을 "시:분"으로 출력한다.
 
# 입력 예시 
 3:16 
# 출력 예시 
 3:16 
# 도움말 
 scanf( ) 함수는 형식(format)에 맞추어 입력 받는 함수이기 때문에 입력 받고자 하는 형식에 맞게 적어주면 된다.

[예시]
scanf("%d:%d", &h, &m); //h와 m에 값이 10진수로 저장된다.
 
# 출처 
 정보컴퓨터교사 연구회/카페 (기초100제 v1.0) 

*************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    scanf("%d:%d",&a,&b);
    cout<<a<<":"<<b;
}

/**************************************************************
	문제번호: 1018
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

