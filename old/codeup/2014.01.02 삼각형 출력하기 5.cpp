/**************************************************************
# 문제 설명 
 어떤 수 n을 입력받으면 다음과 같은 삼각형을 출력한다.

여기서 입력되는 n은 반드시 홀수이다.

 
# 입력 
 3부터 99 까지의 홀수 중 하나가 입력된다.
 
# 출력 
 Sample Output 같은 삼각형을 출력한다.
 
# 입력 예시 
 5 
# 출력 예시 
   *
 ***
***** 
# 도움말 
  ※ 불필요한 공백을 출력하면 표현 에러를 유발합니다.
.은 공백을 말합니다.
..*
.***
***** 
# 출처 
  

*************************************************************/
#include<stdio.h>
int main(){
	int i=0;
	int j=0;
	int d=0;
	scanf("%d",&d);
	int s=d;
	for(i=0;i<=(d-1)/2;i++){
		for(j=0;j<(d-1)/2-i;j++){
			printf(" ");
		}
		for(j=0;j<i*2+1;j++){
			printf("*");
		}
		if(i!=(d-1)/2){
		printf("\n");
		}
	}
}

/**************************************************************
	문제번호: 1358
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1084 kb
****************************************************************/

