#include <iostream>
using namespace std;

struct Queue {
	int begin, end;
	int data[10000];
	Queue() {
		begin = end = 0;
	}

	void push(int x) {
		data[end++] = x;
	}
	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return data[begin];
		}
	}
	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return data[end - 1];
		}
	}
	int size() {
		return end - begin;
	}
	bool empty() {
		if (size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return data[begin++];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	Queue q;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "front") {
			cout << q.front() << '\n';
		}
		else if (cmd == "back") {
			cout << q.back() << '\n';
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << (q.empty() ? 1 : 0) << '\n';
		}
		else {
			cout << q.pop() << '\n';
		}
	}
	return 0;
}