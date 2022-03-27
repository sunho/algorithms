/**************************************************************
# 문제 설명 
 문제1에서는 판을 보고 전부 뭉칠 수 있는지를 확인했다.
이번에는 판의 상태가 입력되면, 위로 올린 결과를 출력한다.
예를 들어, 다음 판이 있는 경우,

    
        
            2
            2
            2
            2
        
        
            2
            2
            2
            2
        
        
            2
            0
            2
            0
        
        
            4
            0
            0
            0
        
    

위로 올린 결과는,

    
        
            4
            4
            4
            4
        
        
            2
            0
            2
            0
        
        
            4
            0
            0
            0
        
        
            0
            0
            0
            0
        
    

이다.

 
# 입력 
 4*4의 판이 입력된다. (게임 방법은 앞의 문제를 참고 바람)
 
# 출력 
 위로 한번 올린 결과를 출력한다. 
 
# 입력 예시 
 2 2 2 2 
0 0 0 0 
4 4 4 4 
4 4 4 4 
 
# 출력 예시 
 2 2 2 2 
8 8 8 8 
0 0 0 0 
0 0 0 0 
 
# 도움말 
  
# 출처 
 expoint 

*************************************************************/
#include <iostream>
using namespace std;
class tile;
typedef tile* (*tileArr)[4];
class tile
{
public:
	tile(int x, int y, int n, tileArr tArr) :_n(n), _x(x), _y(y), _arr(tArr),_isMoved(0) {};
	int isEmpty() { return !_n; };
	int N() { return _n; };
	void moveDown()
	{
		for (; _y >= 1; _y--)
		{
			if (!isEmpty())
			{
				if (_arr[_y-1][_x]->isEmpty())
				{
					_arr[_y-1][_x] = this;
					_arr[_y][_x] = new tile(_x, _y, 0, _arr);
				}
				else
				{
					if (_arr[_y - 1][_x]->_n == _n&& _n != 2048 && !_isMoved&& !_arr[_y - 1][_x]->_isMoved)
					{
						_isMoved = 1;
						_n *= 2;
						_arr[_y-1][_x] = this;
						_arr[_y][_x] = new tile(_x, _y, 0, _arr);
					}
					else
					{
						_arr[_y - 1][_x]->moveDown();
						if(!_arr[_y-1][_x]->isEmpty()) break;
						_y++;
					}
					
				}
			}
			else
			{
				_arr[_y - 1][_x]->moveDown();
				break;
			}
		}
	}
private:
	tileArr _arr;
	int _isMoved;
	int _x, _y;
	int _n;
};
int main()
{
	tile* arr[4][4];
	int n;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			cin >> n;
			arr[i][j] = new tile(j, i, n, arr);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		arr[3][i]->moveDown();
	}
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			cout << arr[i][j]->N() << " ";
		}
		cout << endl;
	}
	return 0;
}


/**************************************************************
	문제번호: 2049
	아이디: ksunhokim
	사용언어: C++
	결과: 정확한 풀이
	수행 시간:0 ms
	메모리 사용량:1696 kb
****************************************************************/

