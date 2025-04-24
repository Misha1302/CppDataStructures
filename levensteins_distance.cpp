// #pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>
#include <cmath>

// defines
#define cto static_cast
#define int i64
#define float f80

// types
typedef __int128_t i128;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef double f64;
typedef long double f80;

template<typename T>
using matrix = std::vector<std::vector<T> >;

// constants
template<typename T>
constexpr T inf = T{};

template<>
constexpr i64 inf<i64> = 4e18;
template<>
constexpr f80 inf<f80> = 1e100;
template<>
constexpr i32 inf<i32> = 2e9;

constexpr i64 mod = 1e9 + 7;
constexpr f64 eps6 = 1e-6;
constexpr f64 eps10 = 1e-10;
constexpr i32 max_log_of_two = 24;

// io
void optimize_in_out_put() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void redirect_in_out_put(const char *input, const char *output) {
    if (input != nullptr) freopen(input, "r", stdin);
    if (output != nullptr) freopen(output, "w", stdout);
}


// main code
using namespace std;

struct LevensteinsDistance {
    string a, b;
    vector<vector<int> > A;
    int repc, addc, ersc, swapc;

    void build() {
        A.resize(a.size(), vector(b.size(), inf<int>));

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if (i == 0 or j == 0) A[i][j] = i * addc + j * addc;
                else if (a[i] == b[j]) A[i][j] = A[i - 1][j - 1];
                else A[i][j] = min(A[i - 1][j - 1] + repc, min(A[i - 1][j] + addc, A[i][j - 1] + ersc));

                if (i > 1 and j > 1 and a[i] == b[j - 1] and a[i - 1] == b[j])
                    A[i][j] = min(A[i][j], A[i - 2][j - 2] + swapc);
            }
        }
    }

    [[nodiscard]] pair<string, string> get_aligned() const {
        string c, d;
        int i = a.size() - 1, j = b.size() - 1;
        while (i != 0 and j != 0) {
            if (a[i] == b[j]) {
                c.push_back(a[i]), d.push_back(b[j]);
                i--, j--;
                continue;
            }

            if (i - 1 >= 0 and A[i][j] == A[i - 1][j] + 1) {
                c.push_back(a[i]), d.push_back('_');
                i--;
                continue;
            }

            if (j - 1 >= 0 and A[i][j] == A[i][j - 1] + 1) {
                c.push_back('_'), d.push_back(b[j]);
                j--; 
                continue;
            }

            c.push_back(a[i]), d.push_back(b[j]);
            i--, j--;
        }

        reverse(c.begin(), c.end());
        reverse(d.begin(), d.end());
        return {c, d};
    }

    void print_aligned() const {
        auto [a, b] = get_aligned();
        cout << a << "\n" << b << "\n";
        for (int i = 0; i < a.size(); ++i) {
            cout << (a[i] == b[i] ? "*" : "_");
        }
    }

    LevensteinsDistance(
        const string &a, const string &b,
        int repc = 1, int addc = 1, int ersc = 1, int swapc = inf<int>
    ) : a(a), b(b), repc(repc), addc(addc), ersc(ersc), swapc(swapc) {
        this->a.insert(0, "\1"), this->b.insert(0, "\1");
        build();
    }

    void print() const {
        for (const auto &i: A) {
            for (long j: i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    [[nodiscard]] int get_dist() const {
        return A.back().back();
    }
};

void solve() {
    string a, b;
    cin >> a >> b;

    const LevensteinsDistance d(a, b);
    d.print();
    cout << d.get_dist() << "\n";

    d.print_aligned();
}

signed main() {
    optimize_in_out_put();
    redirect_in_out_put("input.txt", "output.txt");

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
