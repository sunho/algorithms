/**************************************************************
# 문제 설명 
 순서없이 적힌 스케줄 메모가 있다.
메모는 스케줄명, 연, 월, 일 의 형태로 구성되어 있다.
이 메모를 토대로 날짜가 빠른 순서로 정렬하여 출력하고자 한다.
만약 날짜가 동일한 경우 스케줄명의 사전식 순서로 오름차순 정렬한다. 
# 입력 
 첫째줄에 데이터의 개수 n이 입력된다.(1<=n<=100)
그 다음줄부터 n개의 데이터가 스케줄명, 년, 월, 일 형태로 한 줄에 하나씩 입력된다. 스케줄명은 공백없이 알파벳소문자 99글자 이하, 년월일은 유효한 날짜만 입력된다.
 
# 출력 
 가장 먼저 해야 할 스케줄명부터 정렬하여  출력한다.
 
# 입력 예시 
 5
sleep 2014 05 23
golf 2014 06 02
travel 2015 11 22
baseball 2013 02 01
study 2014 05 23
 
# 출력 예시 
 baseball
sleep
study
golf
travel

 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
class schedule
{
public:
    schedule(string _name,int _year,int _month,int _day)
    :year(_year),
    month(_month),
    day(_day),
    name(_name)
    {
    }
    int totalDay() const
    {
        return year*365+month*30+day;
    }
    bool operator>(const schedule& d)
    {
        if(totalDay()==d.totalDay())
        {
            int na=min(name.size(),d.name.size());
            for(int i=0;i<na;i++)
            {
                if(name.c_str()[i]>d.name.c_str()[i])
                    return true;
                else if(name.c_str()[i]<d.name.c_str()[i])
                    return false;
            }
            if(name.size()>d.name.size())
                return true;
        }
        else if(totalDay()>d.totalDay())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int year,month,day;
    string name;
private:
    schedule();
    schedule(const schedule&);
    schedule& operator=(const schedule&);
};
int main()
{
    schedule* arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;
        int year,month,day;
        cin>>name;
        cin>>year;
        cin>>month;
        cin>>day;
        schedule* s=new schedule(name,year,month,day);
        arr[i]=s;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((*arr[j])>(*arr[j+1]))
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]->name<<endl;
    }
}

/**************************************************************
	문제번호: 3019
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

