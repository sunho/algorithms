/**************************************************************
# 문제 설명 
 구글 입사 시험으로 1 ~ 1,000,000까지 1의 개수를 묻는 문제가 나온적이 있다.
우리는 이 문제를 풀기에는 아직 힘이 든다.
우리는 이 문제를 조금 쉽게 바꾸어 풀려고한다.
어떤 수 n이 주어지면 1부터 n까지의 수 중 맨 마지막 자리에 1이 몇 번 들어 있는지 알아내는 프로그램을 작성하시오.

 
# 입력 
 n이 입력된다. ( 1 <= n <= 1,000,000 ) 
# 출력 
 맨 마지막 자리에 1이 몇 번 들어 있는지 출력한다. 
# 입력 예시 
 35 
# 출력 예시 
 4 
# 도움말 
 맨 마지막에 1이 나오는 경우는 1, 11, 21, 31  이므로 4번이다. 
# 출처 
  

*************************************************************/
#include<stdio.h>
#include<string.h>
int main(){
	int i=0;
	int num=0;
	int j=0;
	int da=0;
	scanf("%d",&da);
	for(i=0;i<=da;i++){
		if(i%10==1){
			num+=1;
		}
	}
	printf("%d",num);
}

/**************************************************************
	문제번호: 1270
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:4 ms
	메모리 사용량:1092 kb
****************************************************************/

