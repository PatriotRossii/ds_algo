#include <iostream>

static const int N = 10000;

int main() {
    int p, q, id[N], sz[N];
    for(int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
    while(std::cin >> p >> q) {
        for(int i = p; i != id[i]; i = id[i]) ;
        for(int j = q; j != id[j]; j = id[j]) ;

        if(i == j) continue;

        if(sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }

        std::cout << ' ' << p << ' ' << q << std::endl;
    }
}
