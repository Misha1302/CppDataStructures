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

void solve() {
}

signed main() {
    optimize_in_out_put();
    redirect_in_out_put("input.txt", "output.txt");

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
