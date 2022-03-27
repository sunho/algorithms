/**************************************************************
# 문제 설명 
 무지개 마을과 달님 마을을 연결하는 외기인 기찻길이 있다.
두 마을의 중간에 T자 모양의 교차로를 설치하기로 했다.
교차로에서의 작업은 다음 두 가지가 있을 수 있다.

S작업:무지개 마을에서 오는 기차를 교차로로 넣는다.
X작업:교차로에 있는 기차를 달님 마을로 보낸다.
1, 2, .. N의 번호를 가진 N대의 기차가 있다고 가정하자.
이 기차들이 무지개 마을에서 어떤 순서로 출발하더라도 달님 마을에 번호 순서대로 도착하게 하려한다.
예를 들어, 무지개 마을에서 4 3 2 1의 순서로 출발시켰다면 교차로에서는 SSSSXXXX의 작업을 수행하면 달님 마을에는 무사히 원하는 순서대로 기차를 보낼 수 있게 된다.
만약 도착하지 못한다면 IMPOSSIBLE를 출력한다.
기차의 출발 순서를 입력 받아, 기차를 달님 마을에 번호 순서대로 도착하게 하는 S, X작업 순서를 출력하는 프로그램을 작성하시오. 
# 입력 
 첫째 줄에 기차의 대수인 N이 입력된다. ( 1 <= N <= 1,000 )
둘째 줄에 출발하는 기차 번호가 공백으로 구분되어 차례대로 입력된다.
 
# 출력 
 순서대로 도착하기 위한 조작법을 출력한다.
만약 불가능한 순서이면 "IMPOSSIBLE"을 출력한다.
 
# 입력 예시 
 4
4 3 2 1  
# 출력 예시 
 SSSSXXXX 
# 도움말 
  
# 출처 
 jin1sun 

*************************************************************/
#include<cstdio>
#define USE_STACK
#define STACK_PRINT_ERROR
#ifdef USE_STACK
/*
    SSSSS   TTTTT   AAAAA   CCCCC   K  K    1       1
    S         T     A   A   C       K K     1       1
    SSSSS     T     AAAAA   C       KK      1       1
        S     T     A   A   C       K K     1       1
    SSSSS     T     A   A   CCCCC   K  K    1   .   1
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
                        by sunhokim.
*/
class stack
{
 private:
     int len;
     int index;
     int *st;
 public:
    //stack 1.1 by sunhokim
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
    int getIndex(){
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
            return 0;
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
int go[1024];
int ai=0;
void push2(int n){
    go[ai]=n;
    ai++;
}
int splash(stack &st){
    int max;
    while(st.getIndex()!=0){
        int n=st.pop();
        if(n>max){
            max=n;
        }
        push2(1);
    }
    return max;
}
int main(){
    int n,N,t=1;
    scanf("%d",&N);
    stack st(N);
    bool sr=false;
    for(int i=0;i<N;i++){
        scanf("%d",&n);
        if(t==n){
            push2(0);
            push2(1);
            if(st.getIndex()!=0){
                t=splash(st);
            }
            t++;
        }
        else if(t<n){
            st.push(n);
            push2(0);
        }
        else{
            sr=true;
            break;
        }
    }
    if(sr==false){
        for(int i=0;i<ai;i++){
        if(go[i]==0){
            printf("S");
        }
        else{
            printf("X");
        }
    }
    }
    else{
        printf("IMPOSSIBLE");
    }

}

/**************************************************************
	문제번호: 3140
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1212 kb
****************************************************************/

