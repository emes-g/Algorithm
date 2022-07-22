#include <iostream>
#include <vector>
using namespace std;
bool a[2000][2000];
vector<vector<int>> g;
vector<pair<int, int>> edges;

// 인접 행렬	: 특정 두 정점 사이 간선의 존재 유무 → O(1)
// 인접 리스트	: 특정 정점과 연결된 모든 정점 찾기 → O(degree)
// 간선 리스트	: 간선 그 자체를 일차원 배열에 저장

int main() {
	// 1. input
	int n, m;
	cin >> n >> m;
	g.assign(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
		edges.push_back({ from,to });
		edges.push_back({ to,from });
	}

	// 2. solve
	for (int i = 0; i < edges.size(); i++) {
		// A -> B (간선 리스트)
		int A = edges[i].first;
		int B = edges[i].second;
		for (int j = 0; j < edges.size(); j++) {
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
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
