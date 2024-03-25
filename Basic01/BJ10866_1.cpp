#include <iostream>
using namespace std;

struct Deque {
	int begin, end;
	int data[20000];
	Deque() {
		end = 10000;
		begin = end - 1;
	}

	void push_back(int x) {
		data[end++] = x;
	}
	void push_front(int x) {
		data[begin--] = x;
	}
	int front() {
		if (!empty()) {
			return data[begin + 1];
		}
		else {
			return -1;
		}
	}
	int back() {
		if (!empty()) {
			return data[end - 1];
		}
		else {
			return -1;
		}
	}
	int size() {
		return end - begin - 1;
	}
	bool empty() {
		if (size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int pop_front() {
		if (!empty()) {
			return data[++begin];
		}
		else {
			return -1;
		}
	}
	int pop_back() {
		if (!empty()) {
			return data[--end];
		}
		else {
			return -1;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	Deque d;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (cmd == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (cmd == "pop_front") {
			cout << d.pop_front() << '\n';
		}
		else if (cmd == "pop_back") {
			cout << d.pop_back() << '\n';
		}
		else if (cmd == "front") {
			cout << d.front() << '\n';
		}
		else if (cmd == "back") {
			cout << d.back() << '\n';
		}
		else if (cmd == "size") {
			cout << d.size() << '\n';
		}
		else {
			cout << (d.empty() ? 1 : 0) << '\n';
		}
	}
	return 0;
}