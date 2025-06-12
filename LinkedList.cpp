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

template<typename T>
class List {
public:
    struct Node {
        T value;
        Node *next;

        Node(T value, Node *next): value(value), next(next) {
        }

        explicit Node(Node *node) {
            value = node->value;
            next = node->next;
        }
    };

    List() {
        _head = new Node(0, nullptr);
    }


    void InsertHead(T value) {
        Node *head_copy = new Node(_head);
        _head = new Node(value, head_copy);
    }

    bool TryInsertHead(Node *before, T value) {
        if (before == nullptr) {
            InsertHead(value);
            return true;
        }
        return false;
    }

    // nullptr = new head
    void InsertAfter(Node *after, T value) {
        if (TryInsertHead(after, value)) return;

        after->next = new Node(value, after->next);
    }

    // nullptr = new head
    void InsertBefore(Node *before, T value) {
        if (TryInsertHead(before, value)) return;

        Node *beforeCopy = new Node(before);
        *before = *new Node(value, beforeCopy);
    }

    void Print() {
        ForwardForeach(_head, [](Node *t) { cout << t->value << " "; });
        cout << "\n";
    }

    void PrintReversed() {
        BackwardForeach(_head, [](Node *t) { cout << t->value << " "; });
        cout << "\n";
    }

    void DeleteAll() {
        if (_head == nullptr) return;
        BackwardForeach(_head, [](Node *t) { delete t; });
        _head = nullptr;
    }

    void ForwardForeach(Node *q, void (*f)(Node *t)) {
        while (q->next != nullptr) {
            f(q);
            q = q->next;
        }
    }

    void BackwardForeach(Node *q, void (*f)(Node *t)) {
        if (q->next == nullptr) return;
        BackwardForeach(q->next, f);
        f(q);
    }

    Node *GetHead() {
        return _head;
    }

    ~List() {
        DeleteAll();
    }

    void Reverse() {
        Node *start = _head;
        Node *cur = _head;
        Node *prev = nullptr;
        while (cur->next != nullptr) {
            _head = cur;

            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

            if (cur->next == nullptr) {
                start->next = cur;
            }
        }
    }

private:
    Node *_head{};
};

void solve() {
    int n;
    cin >> n;

    List<int> list;
    List<int>::Node *end = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        list.InsertAfter(end, x);
        if (end != nullptr)
            end = end->next;
        if (end == nullptr)
            end = list.GetHead();
    }

    list.Reverse();
    list.Print();
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
    // cin >> T;
    while (T--) solve();

    return 0;
}
