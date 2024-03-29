/**************************************************************
# 문제 설명 
 Kninfo 학교에서는 10개의 과목을 시험친다.
이번에 성적 처리를 맡게 된 vega선생님은 올해부터는 성적표를 그래프로 출력하기로 결정했다.
하지만 일일이 그래프를 그리기에는 시간이 너무 걸린다.
vega선생님을 위해 10개의 과목 점수가 입력되면 막대그래프로 출력하는 프로그램을 작성하시오.
10점당 #을 출력하고, 10점 미만은 #을 출력하지 않는다. 100점은 #이 10개임.
(그래프 형식은 아래 출력예시를 참고할것) 
# 입력 
 10과목의 점수가 공백으로 구분되어 입력된다.
(과목의 점수는 0~100점 사이이다.)
 
# 출력 
 입력된 점수에 따라 출력예시를 참고하여 막대그래프를 출력한다.
 
# 입력 예시 
 25 20 30 40 56 79 8 15 90 52 
# 출력 예시 
                     
                #   
                #   
          #     #   
          #     #   
        # #     # # 
      # # #     # # 
    # # # #     # # 
# # # # # #     # # 
# # # # # #   # # # 
 
# 도움말 
 2차원 배열 활용.
각 줄의 마지막에 공백을 하나 넣어 출력해야 합니다. (안 넣으면 표현 오류 발생)
예) printf("%d ", a[i][j]);
 
# 출처 
 2012진주시정보화경진대회 

*************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int points[10][10]={0};
    int point;
    for(int i=0;i<10;i++)
    {
        cin>>point;
        for(int j=0;j<point/10;j++)
        {
            points[9-j][i]=1;
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(points[i][j]==1)
            {
                cout<<"# ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

/**************************************************************
	문제번호: 2603
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

