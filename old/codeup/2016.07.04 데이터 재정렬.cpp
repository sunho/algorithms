/**************************************************************
# 문제 설명 
 프로그래밍 문제를 풀다 보면 뒤죽박죽인 N개의 데이터를 숫자의 크기 순으로 0 ~ N-1까지의 숫자로 재정렬 해야되는 경우가 종종 있다.
예를 들어 N=5 이고,
50 23 54 24 123
이라는 데이터가 있다면,
2 0 3 1 4
가 된다.
데이터를 재정렬하는 프로그램을 작성하시오.
 
# 입력 
 첫째 줄에 데이터의 개수 N이 입력된다. ( 1 <= N <= 50,000)
둘째 줄에 공백으로 분리되어 N개의 서로 다른 데이터가 입력된다. (값의 범위:0~500,000)
 
# 출력 
 N개의 데이터를 0 ~ N-1로 재정렬하여 출력하라.
 
# 입력 예시 
 5
50 23 54 24 123  
# 출력 예시 
 2 0 3 1 4  
# 도움말 
 50 23 54 24 123 에서
23, 24, 50, 54, 123 순서로 0, 1, 2, 3, 4 가 된다.
그리고 원래의 위치대로 출력한다.
 
# 출처 
  

*************************************************************/
#include <stdio.h>
#include <algorithm>

using namespace std;
void quick(int (*arr)[2], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2][0];

	/* partition */
	while (i <= j) {
		while (arr[i][0] < pivot)
			i++;
		while (arr[j][0] > pivot)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quick(arr, left, j);
	if (i < right)
		quick(arr, i, right);
}
int main(void)
{
	int arr[50000][2];
	int rank[50000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i][0]);
		arr[i][1] = i;
	}
	quick(arr,0,n-1);
	for (int i = 0; i < n; i++)
	{
		rank[arr[i][1]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", rank[i]);
	}
	return 0;
}

/**************************************************************
	문제번호: 3004
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:32 ms
	메모리 사용량:1560 kb
****************************************************************/

