/**************************************************************
# 문제 설명 
 [문제3] 자리바꿈 소수  (20점, 제한시간 1초)
소수(prime number)는 1과 자신을 제외하고는 약수가 없는 수이다. 어떤 수에서 자리수의 위치를 바꾸었을 때 소수의 여부가 달라질 수 있다. 예를 들어, 23은 소수이지만, 십의 자리와 일의 자리의 수를 바꾸어 32가 되면 소수가 아니다.
   
입력되는 정수의 자리수를 바꾸어서 만들어질 수 있는 소수를 출력하는 프로그램을 작성하시오.
   
예를 들어, 113의 자리수를 바꾸면 113, 131, 311을 만들 수 있고(자신도 포함), 이들 중에서 소수는 113, 131, 311이다.
 
# 입력 
 1. 하나의 정수 n이 입력된다. (1≤n≤10,000)
 
# 출력 
 1. n의 자리수를 바꾸어서 만들어지는 모든 소수를 하나의 공백으로 분리하여 출력한다.
2. 출력되는 수는 크기가 작은 수부터 큰 수의 순으로 출력한다.
3. 같은 수가 중복되어 출력되면 안된다.
4. 만들어지는 소수가 없으면 0을 출력한다.
 
# 입력 예시 
 1234 
# 출력 예시 
 1423 2143 2341 4231 
# 도움말 
  
# 출처 
 2009 교원프로그래밍경진대회 

*************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
set<int> so;
string intToString(int n)
{
    stringstream s;
    s << n;
    return s.str();
}
void makeN(vector<int> remain,string num)
{
    for(int i=0;i<remain.size();i++)
    {
        vector<int> remain2=remain;
        remain2.erase(remain2.begin()+i);
        string num2=num+intToString(remain[i]);
        makeN(remain2,num2);
    }
    if(remain.size()==0)
    {
        int num2;
        stringstream(num)>>num2;
        so.insert(num2);
    }
}
bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    while(n!=0)
    {
        arr.push_back(n%10);
        n/=10;
    }
    makeN(arr,"");
    int d=0;
    for(set<int>::iterator iter=so.begin();iter!=so.end();++iter)
    {
        if(isPrime(*iter))
        {
            cout<<*iter<<" ";
            d++;
        }
    }
    if(d==0)
    {
        cout<<0;
    }
    return 0;
}

/**************************************************************
	문제번호: 4028
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1744 kb
****************************************************************/

