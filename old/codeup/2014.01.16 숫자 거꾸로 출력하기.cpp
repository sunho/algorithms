/**************************************************************
# 문제 설명 
 현우는 숫자를 좋아한다. 항상 숫자를 가지고 장난을 하고 숫자로 무언가 만들기를 취미생활로 즐기고 있다.
하루는 어떤 숫자를 쓰고, 그 수를 거꾸로 쓰기로 했다.
어떤 수 N이 입력되면 그 수를 거꾸로 출력하는 프로그램을 작성하시오.
예)
입력 : 2571
출력 : 1752

입력 : 1200
출력 : 0021


 
# 입력 
 입력되는 수 N은 0이상의 정수이다. 
# 출력 
 입력된 수를 거꾸로 출력한다.
 
# 입력 예시 
 123456 
# 출력 예시 
 654321 
# 도움말 
  
# 출처 
 2012교내프로그래밍대회 

*************************************************************/
#include <stdio.h>
#include<string.h>
int main()
{
    char C[1024];
    int i=0;
    scanf("%s",&C);
    for(i=strlen(C)-1;i>=0;i--){
        printf("%c",C[i]);
    }
    return 0;
}

/**************************************************************
	문제번호: 1714
	아이디: ksunhokim
	사용언어: C
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1084 kb
****************************************************************/

