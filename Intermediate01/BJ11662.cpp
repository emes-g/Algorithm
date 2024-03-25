#include <iostream>
#include <cmath>
using namespace std;

// <삼분 탐색>
// 값이 커지다가 작아지거나, 작아지다가 커지는 경우에 사용가능
// → 위 or 아래로 볼록한 상황에서 사용가능

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double ternary_search(double left, double right) {
	double x1, y1, x2, y2, x3, y3, x4, y4, dx1, dy1, dx2, dy2, d1, d2;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	dx1 = x2 - x1;
	dy1 = y2 - y1;
	dx2 = x4 - x3;
	dy2 = y4 - y3;
	for (int i = 0; i < 100; i++) {	// 충분한 범위 커버 가능
		double m1 = left + (right - left) / 3;
		double m2 = right - (right - left) / 3;
		
		double m1x1, m1y1, m1x2, m1y2, m2x1, m2y1, m2x2, m2y2;
		m1x1 = x1 + m1 * dx1;
		m1y1 = y1 + m1 * dy1;
		m1x2 = x3 + m1 * dx2;
		m1y2 = y3 + m1 * dy2;
		m2x1 = x1 + m2 * dx1;
		m2y1 = y1 + m2 * dy1;
		m2x2 = x3 + m2 * dx2;
		m2y2 = y3 + m2 * dy2;
		d1 = dist(m1x1, m1y1, m1x2, m1y2);
		d2 = dist(m2x1, m2y1, m2x2, m2y2);
		if (d1 < d2) {
			right = m2;
		}
		else {
			left = m1;
		}
	}
	return d1;
}

int main() {
	printf("%.10lf", ternary_search(0.0, 1.0));	// 비율로 문제 해결
}