#ifndef CLION_DEBUG
// #pragma GCC optimize("O2")
#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("avx2")
// #pragma GCC optimize("O0")
#endif

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
using ordered_multiset = __gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    std::less_equal<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

template<typename T>
using matrix = std::vector<std::vector<T> >;

// defines
#define cto static_cast
#define int i64
#define float f64

// constants
template<typename T>
constexpr T inf = T{};

template<>
constexpr i64 inf<i64> = 2e18;
template<>
constexpr f80 inf<f80> = 1e100;
template<>
constexpr f64 inf<f64> = 1e100;
template<>
constexpr i32 inf<i32> = 1e9;

constexpr i64 prime18 = 447421542630798497;
constexpr i64 mod = 1e9 + 7;
//constexpr i64 mod = 998244353;
//constexpr i64 mod = 617980241;
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

int read_time() {
    int a, b;
    char c;
    std::cin >> a >> c >> b;
    return a * 60 + b;
}

template<typename T>
std::pair<T, T> operator+(const std::pair<T, T> &lhs, const std::pair<T, T> &rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

template<typename T>
bool operator==(const std::pair<T, T> &lhs, const std::pair<T, T> &rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template<typename T>
T sign(T v) {
    return v > 0 ? 1 : v == 0 ? 0 : -1;
}

float gettm() {
    return (float) clock() / CLOCKS_PER_SEC;
}

struct pair_hash {
    template<typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const {
        return ((i128) std::hash<T>()(x.first) * (i128) std::hash<U>()(x.second)) % prime18;
    }
};

#ifdef CLION_DEBUG
#define debug_assert(c) assert(c)
#else
#define debug_assert(c)
#endif


// main code
using namespace std;


void solve() {
}

void init() {
}

signed main() {
    init();

    optimize_in_out_put();
#ifdef CLION_DEBUG
    redirect_in_out_put("../input.txt", "../output.txt");
#else
    // ... //
#endif


    int T = 1;
    // cin >> T;
    while (T--) solve();
    cout.flush(), cerr.flush();

    return 0;
}
