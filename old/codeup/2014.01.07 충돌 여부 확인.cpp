/**************************************************************
# 문제 설명 
 범진이는 닷지 게임을 만들기 위해 열공중이다. 닷지 게임은 아래와 같이 미사일을 피하는 게임이다.

여기서 범진이는 아군 비행기와 붉은 점 미사일의 충돌 여부를 프로그래밍 해야 한다.
아군 비행기는 사각형, 미사일은 한 점이며 (x, y)의 좌표가 입력되면 충돌여부를 결정하는 프로그램을 작성하시오. 단, 사각형 꼭지점이나 모서리에 점의 좌표가 일치하는 경우도 충돌한 것으로 본다.
(※ 사각형의 좌표는 왼쪽 아래 꼭지점(x1, y1)과 오른쪽 위 꼭지점(x2, y2)의 좌표가 차례대로 입력된다.)

예) 



.


 
# 입력 
 첫 줄에 사각형의 왼쪽 아래 좌표 (x1, y1)가 공백으로 구분되어 입력 되고,
둘째 줄에 사각형의 오른쪽 위 좌표 (x2, y2)가 공백으로 구분되어 입력된다.
셋째 줄에 점 미사일의 좌표 (x3, y3)가 공백으로 구분되어 입력된다.
(모든 x, y의 값은 0보다 크다) 
# 출력 
 충돌여부를 다음과 같이 출력하시오. 
사각형과 점이 충돌한다면 "충돌", 사각형과 점이 충돌하지 않는다면 "비충돌"을 출력하시오. 
# 입력 예시 
 10 3
15 8
12 6 
# 출력 예시 
 충돌 
# 도움말 
  
# 출처 
 2012교내프로그래밍대회 

*************************************************************/
#include<stdio.h>
typedef struct point
{
	int x;
	int y;
}Point;
int main()
{
	int x,y;
	Point rocket,bDownLeft,bDownRight,bUpLeft,bUpRight;
	scanf("%d %d",&x,&y);
	bDownLeft.x=x;
	bDownLeft.y=y;
	scanf("%d %d",&x,&y);
	bUpRight.x=x;
	bUpRight.y=y;
	scanf("%d %d",&x,&y);
	rocket.x=x;
	rocket.y=y;
	bUpLeft.x=bDownLeft.x;
	bUpLeft.y=bUpRight.y;
	bDownRight.x=bUpRight.x;
	bDownRight.y=bDownLeft.y;
	//printf("(%d,%d),(%d,%d)(%d,%d),(%d,%d) ",bUpLeft.x,bUpLeft.y,bUpRight.x,bUpRight.y,bDownLeft.x,bDownLeft.y,bDownRight.x,bDownRight.y);
	if((x>=bUpLeft.x&&x<=bUpRight.x)&&(y>=bDownLeft.y&&y<=bUpLeft.y)){
		printf("충돌");
	}
	else{
		printf("비충돌");
	}
	return 0;
}

/**************************************************************
	문제번호: 1711
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1092 kb
****************************************************************/

