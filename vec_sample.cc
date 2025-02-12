#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <ext/pool_allocator.h>
#include <list>
using namespace std;
int main() {

    int ia[6] = {27, 210, 12, 47, 109, 83};
    list<int, allocator<int> > vi; // container allocator
    auto c = vi.begin();
    cout << count_if(vi.begin(), vi.end(), // iterator(begin(), end()) algorithm(count_if) adapter(bind2nd) functor(less)
           not1(bind2nd(less<int>(), 40)) ) << endl;
    return 0;
}