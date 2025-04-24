#pragma GCC optimize("Ofast,unroll-loops")

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


int get_cost(const vector<int> &indices, const vector<string> &strs, string &answer) {
    return -1;
}

int get_ms() {
    return lround((float) clock() / CLOCKS_PER_SEC * 1000);
}


string annigilation(const vector<string> &strs, int duration_in_ms) {
    vector<int> indices(strs.size());
    for (int i = 0; i < indices.size(); ++i) indices[i] = i;

    float START_T = 0.7;
    float END_T = 0.1;
    float START_TIME = get_ms();
    float DURATION = duration_in_ms;
    float END_TIME = get_ms() + DURATION;


    float t;
    string min_str;
    while (min_str.size() < 1'000'000) min_str.push_back('Q');
    int max_cost = -inf<int>;
    int iter = 0;
    while (get_ms() < END_TIME) {
        t = START_T * pow(END_T / START_T, (get_ms() - START_TIME) / DURATION);
        if (++iter % 2'500'000 == 0) srand(time(nullptr));

        int i = rand() % indices.size(), j = rand() % indices.size();

        swap(indices[i], indices[j]);

        string new_str;
        int new_cost = get_cost(indices, strs, new_str);

        if (min_str.size() > new_str.size())
            min_str = new_str;

        if (max_cost < new_cost or (float) rand() / RAND_MAX < exp((new_cost - max_cost) / t)) {
            max_cost = new_cost;
        } else {
            swap(indices[i], indices[j]);
        }
    }

    return min_str;
}
