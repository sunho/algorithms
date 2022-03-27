/**************************************************************
# 문제 설명 
 N개의 입력 데이터가 주어지면 정렬해서 출력하시오.

입력 예)
5
2 5 8 1 2
출력 예)
1 2 2 5 8

 
# 입력 
 첫 줄에 데이터의 개수 N이 입력된다. ( 1 <= N <= 4,500,000 ) ※ 조건수정(2012.12.20)
둘째 줄에 공백으로 분리되어 N개의 데이터가 입력된다. ( 데이터 값의 범위 : 0 ~ 100,000 )

 
# 출력 
 데이터를 오름차순으로 정렬하여 출력한다. 
# 입력 예시 
 5
2 6 4 8 6 
# 출력 예시 
 2 4 6 6 8  
# 도움말 
 ※ 데이터 값의 범위가 있는 것이 힌트!
 일반 정렬 기법으론 풀지 못합니다.(시간초과) 배열 활용.

 
# 출처 
  

*************************************************************/
#include <stdio.h>
#include <algorithm>

using namespace std;
void quick(int *arr, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
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
	int arr[4500000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quick(arr,0,n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

/**************************************************************
	문제번호: 3014
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:1984 ms
	메모리 사용량:18552 kb
****************************************************************/

