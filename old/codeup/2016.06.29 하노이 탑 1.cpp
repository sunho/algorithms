/**************************************************************
# 문제 설명 
 하노이 탑 문제를 프로그래밍해보자.

하노이탑의 규칙은 다음과 같다.
1. 각 탑의 제일 위의 원판만 이동할 수 있다.
2. 한번에 하나의 원판을 이동할 수 있다.
3. 이동하는 원판보다 작은 원판 위로는 이동할 수 없다. (반드시 큰 원판이 아래에 있어야 한다.)

By André Karwath aka Aka (자작) [CC-BY-SA-2.5], via Wikimedia Commons
원판의 개수가 주어질 때 이동하는 최단 경로를 출력하시오.
 
# 입력 
 원판의 개수가 입력된다.(1<=n<=10)
 
# 출력 
 원판이 이동되는 최단 경로를 양식에 맞추어 출력하시오.
 
# 입력 예시 
 3 
# 출력 예시 
 Disk 1 : A to C
Disk 2 : A to B
Disk 1 : C to B
Disk 3 : A to C
Disk 1 : B to A
Disk 2 : B to C
Disk 1 : A to C
 
# 도움말 
 중간에 공백을 잘보고 표현 오류를 조심하시기 바랍니다.(콜론(:) 앞뒤로 공백있음)

 
# 출처 
  

*************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
void hanoi(int n,char from,char mid,char to)
{
    if(n==1)
    {
        printf("Disk %d : %c to %c\n",n,from,to);
    }
    else
    {
        hanoi(n-1,from,to,mid);
        printf("Disk %d : %c to %c\n",n,from,to);
        hanoi(n-1,mid,from,to);
    }
}
int main()
{
   int n;
   cin>>n;
   hanoi(n,'A','B','C');
}
/**************************************************************
	문제번호: 3420
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

