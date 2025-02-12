#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
struct MyIteratorTraits {
    typedef typename T::value_type           value_type;
    typedef typename T::iterator_category    iterator_category;
    typedef typename T::difference_type      difference_type;
    typedef typename T::pointer              pointer;
    typedef typename T::reference            renference;
};

template <typename T>
struct MyIteratorTraits<T*> {
    typedef T                               value_type;
    typedef random_access_iterator_tag      iterator_category;
    typedef ptrdiff_t                       difference_type;
    typedef T*                              pointer;
    typedef T&                              renference;
};

template <typename T>
struct MyIteratorTraits<const T*> {
    typedef T                               value_type;
    typedef random_access_iterator_tag      iterator_category;
    typedef ptrdiff_t                       difference_type;
    typedef const T*                        pointer;
    typedef const T&                        renference;
};


template <typename RandomAccessIterator>
void my_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (last - first <= 1) { return; } 
    typedef typename MyIteratorTraits<RandomAccessIterator>::value_type value_type;
    RandomAccessIterator l = first;
    RandomAccessIterator r = last - 1;
    value_type pivot_value = *r;
    RandomAccessIterator pivot_iterator = l;
    for (RandomAccessIterator iter = l; iter <= r; ++iter) {
        if (*iter <= pivot_value) {
            int tmp = *pivot_iterator;
            *pivot_iterator = *iter;
            *iter = tmp;
            ++pivot_iterator;
        }
    }
    my_sort(first, pivot_iterator - 1);
    my_sort(pivot_iterator, last);
}

int main() {
    int* orin_pointer = new int[4];
    orin_pointer[0] = 0;
    orin_pointer[1] = 8;
    orin_pointer[2] = 1;
    orin_pointer[3] = 5;
    my_sort(orin_pointer, orin_pointer + 4);
    for (int i = 0; i < 4; ++i) {
        cout << orin_pointer[i] << ' ';
    }
    cout << endl;
    delete orin_pointer;
    vector<int> l;
    l.push_back(0);
    l.push_back(8);
    l.push_back(1);
    l.push_back(5);
    my_sort(l.begin(), l.end());
    for (auto e : l) {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}