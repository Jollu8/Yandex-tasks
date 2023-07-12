#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(N+1, vector<int>(M+1));
    for (int i = 1; i <= N; i++) {
        int ans = 0;
        for (int j = 1; j <= M; j++) {
            ans += a[i-1][j-1];
            b[i][j] = ans + b[i-1][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = b[x2][y2]-b[x2][y1-1]-b[x1-1][y2]+b[x1-1][y1-1];
        cout << ans << endl;
    }
}
