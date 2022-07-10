#include <iostream>
#include <algorithm>
using namespace std;
char a[15], pw[15];

// 시간 복잡도 : O(2^c)

void go(int level, int index, int consonant, int vowel, int l, int c) {
	if (level == l) {
		if (consonant >= 2 && vowel >= 1) {
			for (int i = 0; i < l; i++) {
				cout << pw[i];
			}
			cout << '\n';
		}
		return;
	}
	else if (index >= c) {
		return;
	}
	pw[level] = a[index];
	if (a[index] == 'a' || a[index] == 'e' || a[index] == 'i' || a[index] == 'o' || a[index] == 'u') {
		go(level + 1, index + 1, consonant, vowel + 1, l, c);
	}
	else {
		go(level + 1, index + 1, consonant + 1, vowel, l, c);
	}
	pw[level] = 0;
	go(level, index + 1, consonant, vowel, l, c);
}

int main() {
	int l, c;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a, a + c);
	go(0, 0, 0, 0, l, c);
	return 0;
}