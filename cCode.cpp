#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > dir = {
    {1, 1}, {-1, 0}, {0, 1}, {-1, 1}, {0, -1}, {-1, 0}, {1, -1}, {-1, -1}
};

bool isValid(int i, int j, int n) {
    return (i>=0 and j>=0 and i<n and j<n);
}

void solve() {
    int n;
    cin >> n;
    int i = 1;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int curx = 0, cury = 0;
    mat[curx][cury] = i++;
    while(i <= n*n) {
        for(auto d : dir) {
            int x = (curx+d.first +n)%n;
            int y = (cury+d.second +n)%n;
            if(isValid(x, y, n)) {
                if(mat[x][y] == 0) {
                    mat[x][y] = i++;
                    curx = x;
                    cury = y;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
