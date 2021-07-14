#include <iostream>

static const int N = 10000;

int main() {
    int p, q, id[N];
    for(int i = 0; i < N; ++i) id[i] = i;
    while(std::cin >> p >> q) {
        for(int i = p; i != id[i]; i = id[i]) ;
        for(int j = q; j != id[j]; j = id[j]) ;

        if(i == j) continue;
        id[i] = j;

        std::cout << ' ' << p << ' ' << q << std::endl;
    }
}
