/**************************************************************
# 문제 설명 
 수식이 입력되면 수식의 결과를 출력하는 계산기를 만드시오.
나눗셈일 경우 0으로 나누는 경우(불능)는 입력되지 않는다.

예)
123+5    ===> 128
130-(5*6)  ===>  100
  
# 입력 
 수식의 최대 길이는 100글자이다.
입력으로 들어오는 숫자는 int범위를 넘어 서지 않으며, 계산 결과도 int범위를 넘지 않는다. 그리고 나눗셈의 결과도 정수로 나타낸다.(나머지 버림) 
# 출력 
 계산 결과를 정수로 출력한다.
 
# 입력 예시 
 20+(6/2) 
# 출력 예시 
 23 
# 도움말 
 스택을 이용하여 풀면 자료구조 공부에 도움이 됩니다.
 
# 출처 
  

*************************************************************/
#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;
class unit
{
public:
    unit(){};
    unit(int n) : _n(n), _type(0){}
    unit(char c) : _c(c), _type(1){}
    int type() const {return _type;}
    int data() {if(type()==0){return _n;} else {return _c;}}
private:
    int _type;
    int _n;
    char _c;
};
int isNumber(char c)
{
    return c>='0'&&c<='9';
}
int isYunSan(char c)
{
    return c=='*'||c=='-'||
            c=='+'||c=='/';
}
int u(char c)
{
    if(c=='+') return 1;
    if(c=='-') return 1;
    if(c=='*') return 2;
    if(c=='/') return 2;
    if(c=='(') return 0;
    if(c==')') return 0;
}
int chartoi(const char* str)
{
    int n;
    sscanf(str,"%d",&n);
    return n;
}
int pop(stack<int>& st)
{
    int d=st.top();
    st.pop();
    return d;
}
int main()
{
    stack<char> st;
    char str[400];
    cin>>str;

    vector<unit> dS;
    int index=0;

    for(int i=0;i<strlen(str)+1;i++)
    {
        if(isNumber(str[i]))
        {
            int start=i;
            for(;isNumber(str[i]);i++);

            char *s=new char[10];
            strncpy(s,str+start,i-start);
            s[i-start+1]=0;
            i--;
            int d = chartoi(s);
            dS.push_back(d);
        }
        else
        {
            if(isYunSan(str[i]))
            {
                if(st.empty())
                {
                    st.push(str[i]);
                    continue;
                }
                if(u(str[i])<=u(st.top()))
                {
                    dS.push_back(st.top());
                    st.pop();
                    st.push(str[i]);
                }
                else
                {
                    st.push(str[i]);
                }
            }
            else if(str[i]=='(')
            {
                st.push(str[i]);
            }
            else if(str[i]==')')
            {
                while(st.top()!='(')
                {
                    dS.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        dS.push_back(st.top());
        st.pop();
    }
    stack<int> st2;
    for(int i=0;i<dS.size();i++)
    {
        if(dS[i].type()==1)
        {
            if(dS[i].data()=='*')
            {
                st2.push(pop(st2)*pop(st2));
            }
            else if(dS[i].data()=='+')
            {
                st2.push(pop(st2)+pop(st2));
            }
            else if(dS[i].data()=='-')
            {
                int d=pop(st2);
                int d2=pop(st2);
                st2.push(d2-d);
            }
            else if(dS[i].data()=='/')
            {
                int d=pop(st2);
                int d2=pop(st2);
                int d3=d2/d;
                st2.push(d3);
            }
        }
        else
        {
            st2.push(dS[i].data());
        }
    }
    cout<<st2.top();
    return 0;
}

/**************************************************************
	문제번호: 3115
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1736 kb
****************************************************************/

