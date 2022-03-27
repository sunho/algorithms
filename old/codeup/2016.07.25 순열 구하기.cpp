/**************************************************************
# 문제 설명 
 n과 r을 입력받아 n을 입력받아 n개의 문자 중 r개를 택하여 순열을 구하는 프로그램을 작성하시오.
n개의 문자는 A부터 시작하는 알파벳 대문자이다.
※ 서로 다른 n개 중에서 r개(n≥r)를 취하여 그들을 일렬로 세울 때, 늘어 세운 것 하나하나를 n개 중에서 r개 취한 순열이라 한다. 
# 입력 
 n은 10이하의 자연수이며 r은 5이하이면서 동시에 n이하의 자연수이다. 
# 출력 
 첫째 줄엔 순열의 수 m을 출력한다.
둘째 줄부터 m줄에 걸쳐 한 줄에 하나씩 순열을 출력한다.(순열을 출력하는 순서는 사전 순서로 한다.) 
# 입력 예시 
 4 2 
# 출력 예시 
 12
AB
AC
AD
BA
BC
BD
CA
CB
CD
DA
DB
DC
 
# 도움말 
  
# 출처 
 jin1sun 

*************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <string.h>
using namespace std;

vector<string> result;
void yee(int n, char arr[] ,string str)
{
    if(n==0)
    {
        result.push_back(str);
        return;
    }
    for(int i=0;arr[i]!=0;i++)
    {
        if(arr[i]!='0')
        {
            char newArr[10];
            strcpy(newArr,arr);
            newArr[i]='0';
            yee(n-1,newArr,str+arr[i]);
        }
    }
}
char* makeList(int n)
{
    char* arr=new char[n];
    for(int i=0;i<n;i++)
    {
        arr[i]='A'+i;
    }
    arr[n]=0;
    return arr;
}
int main()
{
    int n,k;
    cin>>k>>n;
    yee(n,makeList(k),"");
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
}

/**************************************************************
	문제번호: 3450
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:324 ms
	메모리 사용량:3312 kb
****************************************************************/

