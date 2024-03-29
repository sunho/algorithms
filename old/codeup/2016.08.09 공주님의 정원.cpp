/**************************************************************
# 문제 설명 
 문제3) 공주님의 정원 (중등2)
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.

  총  $N$개의 꽃이 있는 데, 꽃은 모두 같은 해에 피어서 같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 정해져 있다. 예를 들어, $5$월 $8$일 피어서 $6$월 $13$일 지는 꽃은 $5$월 $8$일부터 $6$월 $12$일까지는 꽃이 피어 있고, $6$월 $13$일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다. (올해는 $4, 6, 9, 11$월은 $30$일까지 있고, $1, 3, 5, 7, 8, 10, 12$월은 $31$일까지 있으며, $2$월은 $28$일까지만 있다.)

  이러한 $N$개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 선택하고 싶다.

1. 공주가 가장 좋아하는 계절인 $3$월 $1$일부터 $11$월 $30$일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.

2. 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.

 $N$개의 꽃들 중에서 위의 두 조건을 만족하는, 즉 $3$월 $1$일부터 $11$월 $30$일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택할 때, 선택한 꽃들의 최소 개수를 출력하는 프로그램을 작성하시오.  
# 입력 
  첫째 줄에는 꽃들의 총 개수 $N$ ($1 <= N <= 100,000$)이 주어진다.
다음 $N$개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 주어진다. 하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 예를 들어서, $3$ $8$ $7$ $31$은 꽃이 $3$월 $8$일에 피어서 $7$월 $31$일에 진다는 것을 나타낸다.  
# 출력 
  첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 $0$을 출력한다. 
# 입력 예시 
 4
1 1 5 31
1 1 6 30
5 15 8 31
6 10 12 10 
# 출력 예시 
 2 
# 도움말 
  
# 출처 
 2011 지역본선 초등 

*************************************************************/
#include <cstdio> 
#include<algorithm> 
using namespace std; 
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
struct data{ 
int s,e; 
bool operator <(const data &r)const{ 
if(s==r.s) return e>r.e; 
return s<r.s; 
} 
}arr[100004]; 
int s[100004],e[100004],cnt=1; 
 
int main() 
{ 
int i,n,sm,sd,em,ed,t=301,tt=301; 
//반복문 i, 곷의 개수, 시작월,시작일, 꽅달, 끝일, 시작점, 끝 점 
scanf("%d",&n); 
for(i=0;i<n;i++){ 
scanf("%d %d %d %d",&sm,&sd,&em,&ed); 
arr[i].s=sm*100+sd; 
arr[i].e=em*100+ed; 
} 
sort(arr,arr+n); //s로 정렬 
for(i=0;i<n;i++){ 
if(arr[i].s>tt) break; //중간에 꽃이 비어있으면 나가기 
if(arr[i].s<=t) { //꽃이 시작점보다 적은 동안 <- 조건이라고 정의 
if(arr[i].e>tt) tt=arr[i].e; // 최대한 e를 늘린다. 조건에 만족하는 동안 
} 
else{ 
if(arr[i].e>tt){ //그 후 조건에 안 맞으면 
t=tt; //시작점에 끝 점을 넣고 
tt=arr[i].e; //임의의 끝 점을 정한 후 
cnt++; //꽃의 개수 증가 
} 
} 
if(tt>1130) break; //11월 30일 보다 늦으면 나ㄹ가기; 
} 
if(tt>1130) //정상적으로 끝났으면 
printf("%d",cnt); 
else //중간에 꽃이 비었으면 
printf("0"); 
return 0; 
} 
/**************************************************************
	문제번호: 4713
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:60 ms
	메모리 사용량:2656 kb
****************************************************************/

