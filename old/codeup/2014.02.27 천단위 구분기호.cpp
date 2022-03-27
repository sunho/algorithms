/**************************************************************
# 문제 설명 
 우리는 흔히 숫자를 쓸때 천단위 구분기호인 콤마(,)를 많이 쓴다.
숫자가 입력되면 천단위 구분기호를 넣어 숫자를 출력하시오.
 
# 입력 
 첫째 줄에 숫자의 길이 n이 입력된다. (1 <= n <= 200)
둘째 줄에 길이가 n인 숫자가 입력된다.
 
# 출력 
 첫단위 구분기호 콤마를 넣어 출력하시오.
 
# 입력 예시 
 8
12421421 
# 출력 예시 
 12,421,421 
# 도움말 
  
# 출처 
  

*************************************************************/
#include<cstdio>
#define USE_STACK
//#define STACK_PRINT_ERROR
#ifdef USE_STACK
/*
    SSSSS   TTTTT   AAAAA   CCCCC   K  K    1       1       1
    S         T     A   A   C       K K     1       1       1
    SSSSS     T     AAAAA   C       KK      1       1       1
        S     T     A   A   C       K K     1       1       1
    SSSSS     T     A   A   CCCCC   K  K    1   .   1   .   1
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
                        by sunhokim.
*/
class stack
{
 private:
     int len;
     int index;
     int *st;
 public:
    //stack 1.1.1 by sunhokim
    stack(int lens){
        if(lens>0){
            st=new int[lens];
            index=0;
            len=lens;
        }
        else{
            #ifdef STACK_PRINT_ERROR
            printf("\n---stack length error---\n");
            #endif
        }
    }
    bool push(int n){
        if(index<len){
            st[index]=n;
            index++;
            return true;
        }
        else{
            #ifdef STACK_PRINT_ERROR
            printf("\n---stack over error---\n");
            #endif
            return false;
        }
    }
    int pop(){
        if(index>0){
            index--;
            return st[index];
        }
        else{
            #ifdef STACK_PRINT_ERROR
            printf("\n---stack min error---\n");
            #endif
        }
    }
    #ifndef STACK_MORE_SHORT
    int getTop(){
        return index;
    }
    int getLen(){
        return len;
    }
    #ifndef STACK_SHORT
    int spop(){
        if(index>0){
            return st[index-1];
        }
        else{
            #ifdef STACK_PRINT_ERROR
            printf("\n---stack min error---\n");
            #endif
            return -279958905890;
        }
    }
    int getVal(int idx){
        if(idx<len){
            if(idx<=index){
                return st[idx];
            }
        }
        else{
            #ifdef STACK_PRINT_ERROR
            printf("\n---no val---\n");
            #endif
            return 0;
        }
    }
    #endif
    #endif
};
#endif
#include<cstring>
int main(){
    char str[1024];
    int N;
    scanf("%d",&N);
    scanf("%s",str);
    int sl=strlen(str);
    int s=(sl-(sl%3))/3;
    N-=1;
    int d=(N-N%3)/3;
    int n=0;
    stack st(N);
    for(int i=sl-1;i>=0;i--){
        if(n==3){
            st.push(i);
            n=0;
        }
        n++;
            //printf("%d\n",i);
    }
   // printf("d\n");

    for(int i=0;i<sl;i++){
        if(st.spop()+1==i){
            printf(",");
            st.pop();
        }
        printf("%c",str[i]);

      //  printf("%d %d\n",st.spop(),i);
    }
}

/**************************************************************
	문제번호: 2016
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1208 kb
****************************************************************/

