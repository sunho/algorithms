/**************************************************************
# 문제 설명 
 두 정수 a, b의 약수를 모두 출력하는 프로그램을 작성하시오.

 
# 입력 
 두 정수 a, b가 입력된다. (1 <= a <= b <= 1,000,000,000)
 
# 출력 
 두 정수 a, b의 약수를 오름차순으로 출력한다.
(중복된 약수는 한번만 출력한다.) 
# 입력 예시 
 6 14 
# 출력 예시 
 1 2 3 6 7 14  
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
int arr[100000];
int index;
int search(int a)
{
    int low=0, high = index,mid;
    while(low<=high)
    {

        mid=(low+high)/2;
        if(arr[mid]>a) high=mid-1;
        else if(arr[mid]<a) low=mid+1;
        else return mid;
    }
    return -1;
}
void push(int a)
{
    int mid=search(a);
    if(mid==-1)
    {
        if(index==0)
        {
            arr[0]=a;
            index++;
        }
        else
        {
            int j;
            for(j=index-1;j>=0&&arr[j]>a;j--)
                arr[j+1]=arr[j];
            arr[j+1]=a;
            index++;
        }
    }
}
int main()
{
    int a,b,i;
    cin>>a;
    cin>>b;
    for(i=1;i*i<a;i++)
    {
        if(a%i==0)
        {
             push(i);
            push(a/i);
        }
    }
    if(i*i==a) push(i);
    for(i=1;i*i<b;i++)
    {
        if(b%i==0)
        {
            push(i);
            push(b/i);
        }
    }
    if(i*i==b) push(i);
    for(i=0;i<index;i++)
    {
        cout<<arr[i]<<" ";
    }
}

/**************************************************************
	문제번호: 2055
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:2088 kb
****************************************************************/

