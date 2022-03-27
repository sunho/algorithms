/**************************************************************
# 문제 설명 
 1~N까지 차례대로 적힌 수열이 있다.
수들 사이에 " ", "+", "-" 중 하나를 집어 넣어서 전체 계산결과 0이 되도록 만들어보자.
단, 첫 수앞에는 연산을 넣을 수 없으며, 공백을 넣게 되면 이전수와 연결된 숫자가 된다.즉 2 3이면 23으로 처리된다.)
N을 입력받아서 0을 만드는 수식을 모두 출력하시오.

 
# 입력 
 정수 N이 입력된다.( 3 <= N <= 9 )
 
# 출력 
 0으로 만드는 모든 수식을 출력한다.
출력 순서는 공백, +, - 순서로 출력한다.
 
# 입력 예시 
 7 
# 출력 예시 
 1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7 
# 도움말 
  
# 출처 
 USACO 

*************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
string itos(int n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}
class unit
{
public:
    unit(int n):_num(true),_n(n){};
    unit(char c):_num(false),_c(c){};
    ~unit(){};
    bool isNum() const{return _num;};
    int getNum() const{return _n;};
    char getChar() const{return _c;};
    void attach(int n){_n=_n*10+n;};
private:
    int _n;
    char _c;
    bool _num;
};
class sick
{
public:
    sick(){};
    ~sick(){};
    const sick operator+(int n)
    {
        sick s=*this;
        if(_arr.size()==0)
        {
            s.push(n);
            return s;
        }
        if(s.last().isNum())
        {
            s.last().attach(n);
        }
        else
        {
            s.push(n);
        }
        return s;
    }
    const sick operator+(char c)
    {
        sick s=*this;
        s.push(c);
        return s;
    }
    void push(int n)
    {
        _arr.push_back(n);
    }
    void push(char c)
    {
        _arr.push_back(c);
    }
    unit& last()
    {
        return _arr[_arr.size()-1];
    }
    int sum()
    {
        int total=_arr[0].getNum();
        for(int i=1;i<_arr.size();i++)
        {
            if(!_arr[i].isNum())
            {
                char c=_arr[i].getChar();
                if(c=='+')
                {
                    total+=_arr[i+1].getNum();
                }
                else
                {
                    total-=_arr[i+1].getNum();
                }
            }
        }
        return total;
    }
private:
    vector<unit> _arr;
};
int end2;
vector<string> ar2;
vector<sick> ar;
void dfs(int i,sick s,string s2)
{
    s=s+i;
    s2+=itos(i);
    if(end2==i)
    {
        ar.push_back(s);
        ar2.push_back(s2);
        return;
    }
    dfs(i+1,s+'+',s2+'+');
    dfs(i+1,s+'-',s2+'-');
    dfs(i+1,s,s2+' ');
}
int main()
{
    cin>>end2;
    dfs(1,sick(),"");
    vector<string> rights;
    for(int i=0;i<ar.size();i++)
    {
        if(ar[i].sum()==0)
        {
            rights.push_back(ar2[i]);
        }
    }
    sort(rights.begin(),rights.end());
    for(int i=0;i<rights.size();i++)
    {
        cout<<rights[i]<<endl;
    }
}


/**************************************************************
	문제번호: 3540
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:40 ms
	메모리 사용량:3296 kb
****************************************************************/

