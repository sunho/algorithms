/**************************************************************
# 문제 설명 
 영문자 한 개를 입력받아 아스키코드 10진수값으로 출력하는 프로그램을 작성해보자.
 
# 입력 
 영문자 한 개가 입력된다.
 
# 출력 
 입력 받은 문자에 해당되는 아스키코드값을 10진수로 출력한다.
 
# 입력 예시 
 A 
# 출력 예시 
 65 
# 도움말 
 아스키(ASCII, 미국표준코드, American Standard Code for Information Interchange) 코드표는 영문자, 특수문자 등을 사용할 때 사용하는 표준 코드이다.

컴퓨터로 저장되는 모든 데이터는 2진 정수화되어 저장되는데, 영문자와 특수기호 등을 저장하는 방법으로 아스키코드를 일반적으로 사용한다.

예를 들어 영문 대문자 'A'는 10진수 65에 해당하는 2진수 값으로 저장된다.
 
# 출처 
 정보컴퓨터교사 연구회/카페 (기초100제 v1.0) 

*************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    char n;
    scanf("%c",&n);
    printf("%d",n);
}

/**************************************************************
	문제번호: 1036
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

