#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::string;
using std::vector;
using std::mt19937;
using std::ios;
using std::multiset;


using ll = long long;
using db = long double; // or double, if TL is tight
using str = string;

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp = make_pair;
#define f first
#define s second

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

// vectors
#define ins insert
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

const int MOD = (int) 1e9 + 7; // 998244353;
const int N = (int) 2e5 + 5;
const ll BIG = 1e18;
const db PI = acos((db) -1);

int n, k;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.pb(t);
    }
    multiset<int> jollu;
    for (int i = 0; i < k; i++)
        jollu.ins(a[i]);
    cout << *jollu.begin() << "\n";
    int i = 0, j = k;
    while (j < n) {
        jollu.erase(--jollu.ub(a[i]));
        i++;
        jollu.ins(a[j]);
        j++;
        cout << *jollu.begin() << "\n";
    }
}
