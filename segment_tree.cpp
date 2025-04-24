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


struct SegmentTree {
    vector<int> b;
    int _n;

    explicit SegmentTree(vector<int> &a) {
        b.resize(4 * a.size(), inf<int>);
        _n = (int)a.size();
        build(0, 0, _n - 1, a);
    }

    int build(int u, int l, int r, vector<int> &a) {
        return b[u] =
               r == l
                   ? a[l]
                   : min(
                       build(2 * u + 1, l, (l + r) / 2, a),
                       build(2 * u + 2, (l + r) / 2 + 1, r, a)
                   );
    }

    int get_min(int u, int l, int r, int lq, int rq) {
        if (l >= lq && r <= rq) return b[u];
        if (r < lq || l > rq) return inf<int>;

        return min(
            get_min(2 * u + 1, l, (l + r) / 2, lq, rq),
            get_min(2 * u + 2, (l + r) / 2 + 1, r, lq, rq)
        );
    }

    void add_one(int u, int l, int r, int lq, int rq) {
        if (l >= lq && r <= rq) {
            b[u]++;
            return;
        }
        if (r < lq || l > rq) return;

        add_one(2 * u + 1, l, (l + r) / 2, lq, rq);
        add_one(2 * u + 2, (l + r) / 2 + 1, r, lq, rq);
        b[u] = min(b[2 * u + 1], b[2 * u + 2]);
    }
};
