#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

int main() {
	std::ios::sync_with_stdio(false);
	int testcase, n, m, x, y;
	cin >> testcase;
	while (testcase--) {
		vector<pair<int, int>> origin;
		vector<pair<int, int>> cmpArr;
		int cmpState[1001][1001] = { 0, };
		//origin
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			pair<int, int> temp;
			temp.first = x;
			temp.second = y;
			origin.push_back(temp);
		}
		//compare
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			pair<int, int> temp;
			temp.first = x;
			temp.second = y;
			cmpArr.push_back(temp);
			cmpState[x][y] = 1;
		}
		sort(origin.begin(), origin.end(), cmp);
		sort(cmpArr.begin(), cmpArr.end(), cmp);

		int diffFirst, diffSecond, testX, testY, falseCount, k = 1, j = 1;
		int cmpratio = n / 10;
		bool check;
		while (true) {
			check = true;
			falseCount = 0;

			diffFirst = cmpArr[m - k].first - origin[n - j].first;
			diffSecond = cmpArr[m - k].second - origin[n - j].second;

			for (auto temp : origin) {
				testX = temp.first + diffFirst;
				testY = temp.second + diffSecond;
				if (testX < 0 || testX > 1000 || testY < 0 || testY > 1000) {
					falseCount++;
				}
				else if (cmpState[testX][testY] != 1) {
					falseCount++;
				}
				if (falseCount > cmpratio) {
					check = false;
					k++;
					break;
				}
			}
			if (check) {
				cout << 1 << endl;
				break;
			}
			else if (k == m + 1) {
				j++;
				k = 1;
				if (j == n + 1) {
					cout << 0 << endl;
					break;
				}
			}
		}

	}
	return 0;
}