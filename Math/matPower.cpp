#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define ll long long

const int mod = 1e9 + 7;
typedef vector<vector<ll>> Mat;
struct Mul {
    int sz = 1;
    Mat operator()(const Mat &a, const Mat &b) const {
        Mat ret(a.size(), vector<ll>(b[0].size()));
        for (int i = 0; i < ret.size(); i++) {//row in first matrix
            for (int j = 0; j < ret[0].size(); j++) {//col in second matrix
                for (int k = 0; k < b.size(); k++) {
                    ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
                }
            }
        }
        return ret;
    }
};

Mat identity_element(const Mul &mul) {
    Mat ret(mul.sz, vector<ll>(mul.sz));
    for (int i = 0; i < mul.sz; i++)ret[i][i] = 1;
    return ret;
}

int main() {
//    freopen("input.txt", "r", stdin);
    int t;
//    scanf("%d", &t);
//    while (t--) {
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    Mat v(n, vector<ll>(n));
    Mul multiplyOperator;
    multiplyOperator.sz = n * n;

    Mat ans = power(v, k, multiplyOperator);
//    }

}
