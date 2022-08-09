#include <iostream>
#include <cmath>
using namespace std;

// <삼분 탐색>
// 값이 커지다가 작아지거나, 작아지다가 커지는 경우에 사용가능
// → 위 or 아래로 볼록한 상황에서 사용가능

// 정수에서 사용할 때는 정확한 값보다는 근사 범위를 알아내는 것이 목적
// 이후, 브루트 포스로 문제 해결

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

double ternary_search(double left, double right) {
	double x1, y1, z1, x2, y2, z2, x3, y3, z3, dx, dy, dz, d1, d2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	for (int i = 0; i < 100; i++) {	// 충분한 범위 커버 가능
		double m1 = left + (right - left) / 3;
		double m2 = right - (right - left) / 3;
		
		double m1x, m1y, m1z, m2x, m2y, m2z;
		m1x = x1 + m1 * dx;
		m1y = y1 + m1 * dy;
		m1z = z1 + m1 * dz;
		m2x = x1 + m2 * dx;
		m2y = y1 + m2 * dy;
		m2z = z1 + m2 * dz;
		d1 = dist(m1x, m1y, m1z, x3, y3, z3);
		d2 = dist(m2x, m2y, m2z, x3, y3, z3);
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