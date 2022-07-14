#include <iostream>
#include <vector>
using namespace std;
bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

int main() {
	// 1. input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
		edges.push_back({ from, to });
		edges.push_back({ to, from });
	}
	m *= 2;

	// 2. solve
	for (int i = 0; i < m; i++) {
		// A -> B (간선 리스트)
		int A = edges[i].first;
		int B = edges[i].second;
		for (int j = 0; j < m; j++) {
			// C -> D (간선 리스트)
			int C = edges[j].first;
			int D = edges[j].second;
			if (A == C || A == D || B == C || B == D) {
				continue;
			}
			// B -> C (인접 행렬)
			else if (!a[B][C]) {
				continue;
			}
			// D -> E (인접 리스트)
			for (int E : g[D]) {
				if (E == A || E == B || E == C || E == D) {
					continue;
				}
				else {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}
