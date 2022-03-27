/**************************************************************
# 문제 설명 
 10개의 수가 입력된다.
10개의 수 중 5의 배수를 하나만 출력한다.
만약 5의 배수가 없다면 0을 출력한다. 
# 입력 
 10개의 자연수가 입력된다 
# 출력 
 10개의 수 중 5의 배수가 있으면 그 중 하나만 출력하고, 없다면 0을 출력한다.
 
# 입력 예시 
 1 2 3 4 5 6 7 8 9 10 
# 출력 예시 
 5 
# 도움말 
  
# 출처 
  

*************************************************************/
#include<stdio.h>
int main(){
	int i=0;
	int num=0;
	int d[10];
	for(i=0;i<10;i++){
		scanf("%d",&d[i]);
	}
	for(i=0;i<10;i++){
		if(d[i]%5==0){
			if(num==0){
				num=d[i];
			}
		}
	}
	printf("%d",num);
}

/**************************************************************
	문제번호: 1261
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1092 kb
****************************************************************/

