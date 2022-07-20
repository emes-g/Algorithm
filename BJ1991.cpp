#include <iostream>
using namespace std;
struct Node {
	int left;
	int right;
};
Node a[26];

void preorder(int x) {
	if (x == -1) {
		return;
	}
	cout << static_cast<char>(x + 'A');
	preorder(a[x].left);
	preorder(a[x].right);
}

void inorder(int x) {
	if (x == -1) {
		return;
	}
	inorder(a[x].left);
	cout << static_cast<char>(x + 'A');
	inorder(a[x].right);
}

void postorder(int x) {
	if (x == -1) {
		return;
	}
	postorder(a[x].left);
	postorder(a[x].right);
	cout << static_cast<char>(x + 'A');
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		a[x].left = (y == '.' ? -1 : y - 'A');
		a[x].right = (z == '.' ? -1 : z - 'A');
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
} 
