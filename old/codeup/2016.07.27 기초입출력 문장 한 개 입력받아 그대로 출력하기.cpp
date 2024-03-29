/**************************************************************
# 문제 설명 
 한 개의 문장을 입력받아 그대로 출력하는 프로그램을 작성해보자.
 
# 입력 
 한 개의 문장이 입력된다.
(문장은 여러 개의 단어로 구성될 수 있고 문장의 입력은 엔터키로 끝나며, 문장의 길이는 공백을 포함하여 2000글자를 넘지 않는다.)
 
# 출력 
 입력한 문장을 그대로 출력한다.
 
# 입력 예시 
 C++ programming is very fun!! 
# 출력 예시 
 C++ programming is very fun!! 
# 도움말 
 char data[2001];
fgets(data, 2000, stdin);
printf("%s", data);

를 실행하면 공백이 포함된 문장을 키보드(stdin)로 입력 받아 최대 2000 문자(영문자)까지 data[] 공간에 저장하고 출력할 수 있다.
한글의 경우 1000글자까지 가능하다.

%s 는 문자열(string)로 출력하라는 의미이다.
 
# 출처 
 정보컴퓨터교사 연구회/카페 (기초100제 v1.0) 

*************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    char s[100];
    gets(s);
    cout<<s;
}

/**************************************************************
	문제번호: 1022
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

