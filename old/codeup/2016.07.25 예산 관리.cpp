/**************************************************************
# 문제 설명 
 정보 선생님은 예산이 많은 부서에서 일하고 있다.
학기말이 가까워지면서 부서의 예산을 가급적 모두 집행해야 될 상황이 되었다.
정보 선생님은 예산 범위를 넘지 않는 범위 내에서 다양한 활동을 하고 싶어한다.
지금 남은 예산(B)이 40이고(단위:만원), 예산을 사용할 수 있는 활동(N)이 6개가 있다.
6개의 활동에 각각 드는 비용은 7, 13, 17, 19, 29, 31이다.
여기서 40을 채울 수 있는 활동의 개수는 상관이 없다.
40을 넘지 않는 범위에서 활동 비용을 조합해보면,
7 + 13 + 17 = 37
7 + 31 = 38
7 + 13 + 19 = 39
...
따라서 40을 초과하지 않으면서 예산을 최대로 사용할 수 있는 비용은 39이다.
정보 선생님을 도와 줄 수 있는 프로그램을 작성하시오. 
# 입력 
 첫째 줄에 남은 예산(B)가 입력된다. ( 10 <= B <= 35,000 )
둘째 줄에 예산을 사용할 수 있는 활동의 수(N)이 입력된다. (1 <= N <= 21 )
셋째 줄에 공백을 기준으로 N개의 활동비가 양의 정수로 입력된다.
 
# 출력 
 남은 예산을 초과하지 않으면서 최대로 사용할 수 있는 비용액을 출력하시오.
 
# 입력 예시 
 40
6
7 13 17 19 29 31 
# 출력 예시 
 39 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
using namespace std;

int minimum;
void intcpy(int* dst,int* src,int n)
{
    for(int i=0;i<n;i++)
    {
        dst[i]=src[i];
    }
    dst[n]=-1;
}
void yee(int n,int arr[],int size)
{
    if(minimum>n)
    {
        minimum=n;
    }
    for(int i=0;arr[i]!=-1;i++)
    {
        if(arr[i]!=-2)
        {
            if(n-arr[i]>0)
            {
                int *newArr=new int[size+1];
                intcpy(newArr,arr,size);
                newArr[i]=-2;
                yee(n-arr[i],newArr,size);
            }
        }
    }
}
int main()
{
    int n;
    int size;
    cin>>n>>size;
    int arr[30];
    for(int i=0;i<size;i++)
    {
        int d;cin>>d;
        arr[i]=d;
    }
    arr[size]=-1;
    minimum=n;
    yee(n,arr,size);
    cout<<n-minimum;
}

/**************************************************************
	문제번호: 3510
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1960 kb
****************************************************************/

