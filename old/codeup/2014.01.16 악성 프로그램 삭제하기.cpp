/**************************************************************
# 문제 설명 
 현준이는 컴퓨터 인터넷이 느린 것을 알고, 제어판에 들어가 보니 여러 악성 프로그램이 설치 되어 있었다.
현준이 컴퓨터 인터넷이 빨라지도록 도와주기 위해 제어판에 있는 프로그램을 입력하면 악성 프로그램과, 컴퓨터의 위험도를 출력하는 프로그램을 작성하시오. 
# 입력 
 첫째 줄에 프로그램이 입력될 갯수  정수 n이 입력된다.(1<=n<=100)
둘째 줄부터 n줄에 걸쳐 프로그램명인  문자열이 입력된다.(글자 수 : 50글자 이내) 
# 출력 
 1. 악성 프로그램인지 아닌지 확인하는 방법 :
  가. 프로그램명이 3글자 이하면 악성 프로그램이다.
  나. 프로그램명에 tap이 들어가면 악성 프로그램이다.
  다. 프로그램명에 xocure이 들어가면 악성 프로그램이다.
2. 컴퓨터의 위험도 출력 방법 :
  가. 입력된 프로그램명 중에서 악성 프로그램 수가 0~3개이면 safe,
  나. 악성 프로그램 수가 4~6개이면 warning,
  다. 악성 프로그램 수가 7개 이상이면 danger을 출력하시오. 
# 입력 예시 
 8
windows tap
hi
microsoft office 2013
xocure web player
xecure safe
goclean
alyac
von
 
# 출력 예시 
 windows tap
hi
xocure web player
von
warning
 
# 도움말 
 문자열 처리 문제입니다.
첫번째 n을 입력받을 때 아래와 같이 처리해야 정신적 스트레스를 줄일 수 있습니다.
scanf("%d\n", &n);
프로그램 명에 공백이 있을 수 있으니 scanf보단 gets를 사용하는 것이 좋습니다.
 
# 출처 
 hgss1004 

*************************************************************/
#include <stdio.h>
#include<string.h>
int main()
{
    int badPointer[1024],maxi=0,i=0,j=0,t=0;
    char str[1024][1024],*temp,trash[1024];
    scanf("%d\n",&maxi);
    for(i=0;i<maxi;i++){
        gets(str[i]);
    }
    for(i=0;i<maxi;i++){
        if(strlen(str[i])<=3){
            badPointer[t]=i;
            t++;
            continue;
        }
        else if(strstr(str[i],"tap")){
             badPointer[t]=i;
            t++;
            continue;
        }
        else if(strstr(str[i],"xocure")){
             badPointer[t]=i;
            t++;
            continue;
        }
    }
        for(i=0;i<t;i++){
            printf("%s\n",str[badPointer[i]]);
        }
        if(t<=3){
            printf("safe");
        }
        else if(t<=6){
            printf("warning");
        }
        else if(t>=7){
            printf("danger");
        }

    return 0;
}

/**************************************************************
	문제번호: 1640
	아이디: ksunhokim
	사용언어: C
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:2004 kb
****************************************************************/

