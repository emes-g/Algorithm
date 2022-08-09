#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double x, y, c;

// <문제 분석>
// 실수에서의 이분 탐색 문제
// 1. left = mid + 1, right = mid - 1 방식으로 진행 불가
// 2. 반환값은 크게 중요하지 않다.

// 결정 문제 : 두 빌딩 사이의 너비가 mid이어도 되는가?
// (단, 오차는 0.001까지 허용한다.)
 
// 왜 "right - left > 1e-3"인지?
// 두 빌딩 사이의 너비(d)는 항상 구간 [left, right]에 존재하므로,
// left와 right간 간격이 0.001 이하라면 d는 항상 left나 right에게 있어, 
// 0.001 범위 내에 있게 된다.

double binary_search(double left, double right) {
	while (right - left > 1e-3) {
		double mid = (left + right) / 2;
		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);
		double c1 = h1 * h2 / (h1 + h2);
		if (c1 <= c) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	return left;	// right를 반환하여도 무관
}

int main() {
	cin >> x >> y >> c;
	double res = binary_search(0, min(x, y));
	printf("%.3lf", res);
}