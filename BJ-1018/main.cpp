#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int M, N;
char chess[51][51];

string start_W[8]{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string start_B[8]{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int F_B(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i + x][j + y] != start_B[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int F_W(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i + x][j + y] != start_W[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	/*int SP_m = 0;
	int SP_n = 0;*/
	int ans = INT_MAX;
	int temp = 0;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		cin >> chess[i];
	}
	for (int i = 0; i <= M - 8; i++) {
		for (int j = 0; j <= N - 8; j++) {
			/*if (chess[i][j] == 'W') {
				temp = F_W(i, j);
				ans = min(ans, temp);
			}
			else {
				temp = F_B(i, j);
				ans = min(ans, temp);
			}*/
			temp = min(F_W(i, j), F_B(i, j));
			ans = min(ans, temp);
		}
	}
	cout << ans << '\n';
	return 0;
}