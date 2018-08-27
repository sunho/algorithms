#include <iostream>
#include <math.h>

int main() {
	long long n, m, a;
	std::cin >> n >> m >> a;
	auto l = n / a;
	auto w  = m / a;
	if(n % a != 0) l++;
	if(m % a != 0) w++;
	std::cout << l*w << std::endl;
}
