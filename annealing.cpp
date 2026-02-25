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


int n, m;
vector<vector<int> > g;
vector<float> costs;


float calc_temperature(const float x) {
    // 0.8 -> 0.05
    // return 0.8 / pow(x + 1, 6);
    return 0.8 / exp((x + 1) * 1.791759469228055);
}

template<bool do_changes>
float flip(int u, float old_cost, vector<bool> &vertices) {
    auto new_cost = old_cost;

    if (not vertices[u]) {
        // add
        for (const auto v: g[u]) {
            if (not vertices[v]) continue;

            new_cost -= costs[v];

            if constexpr (do_changes) vertices[v] = false;
        }

        if constexpr (do_changes) vertices[u] = true;
        new_cost += costs[u];
    } else {
        // erase
        new_cost -= costs[u];
        if constexpr (do_changes) vertices[u] = false;
    }

    return new_cost;
}

void init_base_answer(float &current_answer, vector<bool> &vertices) {
    for (int i = 0; i < n; i++) {
        if (rand() % 2)
            current_answer = flip<true>(i, current_answer, vertices);
    }
}

float annealing(const float ST_TIME, const float END_TIME) {
#define VALUE (elapsed / DURATION)

    const float DURATION = END_TIME - ST_TIME;

    float best_answer = -inf<float>;
    float current_cost = 0;
    vector vertices(n, false);
    float elapsed = gettm() - ST_TIME;
    float t = calc_temperature(VALUE);

    init_base_answer(current_cost, vertices);

    int cnt = 0;
    while (VALUE < 1) {
        cnt++;
        if (cnt % 256 == 0) {
            elapsed = gettm() - ST_TIME;
            t = calc_temperature(VALUE);
        }

        int u = rand() % n;
        auto new_cost = flip<false>(u, current_cost, vertices);
        float delta = new_cost - current_cost;
        if (delta >= 0 or exp(delta / t) > (float) rand() / RAND_MAX) {
            current_cost = new_cost;
            flip<true>(u, current_cost, vertices);
        }

        best_answer = max(best_answer, current_cost);
    }

    // cout << cnt << "!  ";

    return best_answer;
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    costs.resize(n);

    for (int i = 0; i < n; ++i) cin >> costs[i];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    float max_cost = *max_element(costs.begin(), costs.end());
    if (max_cost <= eps6) {
        cout << 0 << "\n";
        return;
    }
    for (auto &cost: costs) { cost /= max_cost; }

    float best_answer = 0;
    constexpr float TOTAL_DURATION = 0.25;
    constexpr int RUNS_COUNT = 5;
    constexpr float STEP = TOTAL_DURATION / RUNS_COUNT;
    for (int i = 0; i < RUNS_COUNT; i++) {
        float st_time = gettm();
        float end_time = STEP * (i + 1);
        if (end_time <= st_time) continue;

        srand(clock());
        float current_answer = annealing(st_time, end_time) * max_cost;
#ifdef CLION_DEBUG
        cout << current_answer << " ";
#endif
        best_answer = max(best_answer, current_answer);
    }
#ifdef CLION_DEBUG
    cout << "\nBEST ANS: ";
#endif
    cout << (int) (best_answer + 1e-2) << "\n";
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
