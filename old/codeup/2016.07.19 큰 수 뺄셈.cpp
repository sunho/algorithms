/**************************************************************
# 문제 설명 
 큰 수 덧셈에 성공했다.
이번에는 큰 수 뺄셈에 도전하자.
 
# 입력 
 큰 수 a, b가 두 줄에 걸쳐 입력된다. (a, b는 100자리 이하)
 
# 출력 
 a-b의 결과를 출력한다.
 
# 입력 예시 
 11232412
3 
# 출력 예시 
 11232409 
# 도움말 
  
# 출처 
  

*************************************************************/
#include <iostream>
#include <string.h>
using namespace std;
class BigInt
{
public:
    BigInt()
        :_length(0),
        _minus(false)
    {
    }
    BigInt(const char* str, bool minuss)
        :_length(strlen(str)),
        _minus(minuss)
    {
        for(int i=0;i<length();i++)
        {
            _numbers[i]=str[i]-'0';
        }
    }
    ~BigInt(){}
    int& operator[](int index)
    {
        return _numbers[index];
    }
    bool operator>=(BigInt& other)
    {
        if(length()>other.length())
            return true;
        if(length()<other.length())
            return false;
        for(int i=0;i<length();i++)
        {
            if((*this)[i]>other[i])
                return true;
            if((*this)[i]<other[i])
                return false;
        }
        return true;
    }
    void operator-=(BigInt& other)
    {
        BigInt a,b;
        if((*this)>=other)
        {
            a=*this;
            b=other;
        }
        else
        {
            a=other;
            b=*this;
            _minus=true;
        }
        int n1,n2;
        n1=a.length();
        n2=b.length();
        while(n1!=0 || n2!=0)
        {
            int d1,d2;
            if(n1!=0) d1=a[--n1];
            else d1=0;
            if(n2!=0) d2=b[--n2];
            else d2=0;
            int d=d1-d2;
            if(d<0)
            {
                a[n1-1]--;
                d+=10;
            }
            a[n1]=d;
        }

        int newLength=0;
        bool meatZero=false;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=0)
            {
                meatZero=true;
                newLength++;
                (*this)[newLength-1]=a[i];
            }
            else if(meatZero)
            {
                newLength++;
                (*this)[newLength-1]=a[i];
            }
        }
        if(newLength==0)
        {
            (*this)[0]=0;
            newLength=1;
        }
        _length=newLength;
    }
    int length() const {return _length;};
    bool isMinus() const {return _minus;};
    void print()
    {
        if(isMinus()) cout<<'-';
        for(int i=0;i<length();i++)
        {
            cout<<(*this)[i];
        }
    }
private:
    bool _minus;
    int _length;
    int _numbers[200];
};
int main()
{
    char num1[100],num2[100];
    cin>>num1;
    cin>>num2;
    BigInt i1(num1,0);
    BigInt i2(num2,0);
    i1-=i2;
    i1.print();
    return 0;
}

/**************************************************************
	문제번호: 3022
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1700 kb
****************************************************************/

