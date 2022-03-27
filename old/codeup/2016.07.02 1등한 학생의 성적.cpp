/**************************************************************
# 문제 설명 
 세종이는 정보과학 선생님인 $JH$를 도와주기 위해 정보과학 성적처리 프로그램을 만들기로 했다.
$JH$ 선생님은 특정 과목에서 $1$등한 학생이 다른 과목에서는 어떤 성적을 얻었는지 관심이 많다.
다음 조건을 만족하는 프로그램을 작성해 보자. 
# 입력 
 첫째 줄에 데이터의 개수 $n$ ($3 <= n <= 100$)
둘째 줄부터 $n+1$줄에 학생 이름과 $3$과목 점수들이 공백으로 구분되어 입력된다. (입력 예시 참고)
단 이름의 길이는 최대 $10$바이트 이내이다 
# 출력 
 첫 번째 과목을 $1$등한 학생의 이름과 두 번째, 세 번째 과목의 석차를 공백으로 구분하여 출력한다.
단 첫 번째 과목의 $1$등은 $1$명이라고 가정한다. 
# 입력 예시 
 4
Jeon 95 80 100
Kim 59 85 75
Lee 90 100 75
Bae 100 82 80
 
# 출력 예시 
 Bae 3 2 
# 도움말 
  
# 출처 
 wildsam 

*************************************************************/
#include <iostream>

using namespace std;
typedef struct
{
    char name[10];
    int first,second,third;
    int rankFirst,rankSecond,rankThird;
}student;
void increaseRank(int& x,int& y,int& z)
{
    if(x<y)
    {
        z++;
    }
}
int main()
{
   student students[100];
   int size;
   cin>>size;
   for(int i=0;i<size;i++)
   {
       cin>>students[i].name;
       cin>>students[i].first;
       cin>>students[i].second;
       cin>>students[i].third;
       students[i].rankFirst=0;
       students[i].rankSecond=0;
       students[i].rankThird=0;
   }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            increaseRank(students[i].first,students[j].first,students[i].rankFirst);
            increaseRank(students[i].second,students[j].second,students[i].rankSecond);
            increaseRank(students[i].third,students[j].third,students[i].rankThird);
        }
    }
    for(int i=0;i<size;i++)
    {
        if(students[i].rankFirst==0)
        {
            cout<<students[i].name<<" "<<
            students[i].rankSecond+1<<" "<<
            students[i].rankThird+1;
            break;
        }
    }
}
/**************************************************************
	문제번호: 3016
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

