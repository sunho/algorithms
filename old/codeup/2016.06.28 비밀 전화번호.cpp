/**************************************************************
# 문제 설명 
 코드업 초등학교에 재학중인 명철이는 친구들과 함께 비밀방범대를 만들었다.
그래서 서로 연락처를 공유하던 중, 명철이는 연락처가 새어나가지 않도록 암호로 바꿔서 공유하기로 했다.
여기서 암호를 해독하는 방법은 다음과 같다.
예)

    
        
            0
            1
            2
            3
            4
            5
            6
            7
            8
            9
        
        
            l
            o
            h
            c
            g
            p
            d
            a
            b
            k
        
    

 
# 입력 
 첫 번째 줄에 코드표의 문자 10개가 주어진다. (순서대로 0~9이다. 알파벳 소문자만 입력됨. 중복x)
두번째 줄에 암호화된 전화번호 3블럭이 띄워쓰기로 구분되어 입력된다.
 
# 출력 
 암호를 풀은 전화번호를 출력한다. 
주의) 반드시 블럭간에 띄워쓰기를 하여 출력한다.(표현오류)
 
# 입력 예시 
 lohcgpdabk
lol abk abk 
# 출력 예시 
 010 789 789 
# 도움말 
  
# 출처 
 hgss1004 

*************************************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int code['z'-'a'+1]={0};
    char c;
    char phone[12]={0};
    char phone2[7]={0};
    for(int i=0;i<10;i++)
    {
        scanf("%c",&c);
        code[c-'a']=i+'0';
    }
    for(int i=0;i<3;i++)
    {
        cin>>phone2;
        for(int j=0;phone2[j]!=0;j++)
        {
            printf("%c",code[phone2[j]-'a']);
        }
        cout<<" ";
    }
}


/**************************************************************
	문제번호: 1760
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

