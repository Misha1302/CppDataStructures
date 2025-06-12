// speed up in 5 times!
// #pragma GCC optimize("O2")
// #pragma GCC optimize("Ofast,inline,unroll-loops")
// #pragma GCC optimize("O0")

#include <bits/stdc++.h>
#include <cmath>
#include <ext/rope>

// types
typedef __int128_t i128;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef double f64;
typedef long double f80;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<typename T>
using ordered_set = __gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    std::less<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

template<typename T>
using matrix = std::vector<std::vector<T> >;

// defines
#define cto static_cast
#define int i64
#define float f80

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
// constexpr i64 mod = 998244353;
constexpr f64 eps6 = 1e-6;
constexpr f64 eps10 = 1e-10;

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


bool kuhn(const vector<vector<i64> > &g, vector<i64> &mt, vector<i64> &used, i64 c, int u) {
    if (used[u] == c) return false;

    used[u] = c;

    for (auto v: g[u]) {
        if (mt[v] == -1 or kuhn(g, mt, used, c, mt[v])) {
            mt[v] = u;
            return true;
        }
    }

    return false;
}

void solve() {
}


void init() {
}

signed main() {
    init();

    optimize_in_out_put();
#ifdef CLION_DEBUG
    redirect_in_out_put("input.txt", "output.txt");
#endif

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
