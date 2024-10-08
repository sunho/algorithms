/**************************************************************
# 문제 설명 
   데이터를 입력받아 내림차순으로 정렬하는 프로그램을 작성하시오.
 
# 입력 
   첫줄에는 데이터의 개수를 입력받는다.(100이하의 정수)
  다음 줄에는 데이터가 입력된다.(100이하의 정수)
 
# 출력 
   정렬된 데이터가 출력된다.
 
# 입력 예시 
 7
51 44 81 1 9 12 25 
# 출력 예시 
 81 51 44 25 12 9 1  
# 도움말 
  
# 출처 
 2012 3학년 프그 수행 

*************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

/**************************************************************
	문제번호: 1709
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

