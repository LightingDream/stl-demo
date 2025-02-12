// #include <iostream>


template <typename T>
struct ListNode {
    typedef ListNode<T>* pointer;
    pointer prev;
    pointer next;
    T data;
    ListNode(const T& _data) 
        : data(_data)
        , prev(this)
        , next(this)
    {}
    ListNode(const T& _data, const pointer& _prev, const pointer& _next) 
        : data(_data)
        , prev(_prev)
        , next(_next)
    {}
};

template <typename T, typename Ref, typename Ptr>
struct ListIterator {
    typedef T value_type;
    typedef Ref reference;
    typedef Ptr pointer;
    typedef ListNode<T>* link_node;
    typedef ListIterator<T, Ref, Ptr> self;
    ListIterator(const link_node& _node) {
        node = _node;
    }
    bool operator!=(const ListIterator& rhs) const {
        return node != rhs.node;
    }
    self& operator++() {
        node = node->next;
        return *this;
    }
    self operator++(int) {
        self tmp = *this;
        ++(*this);
        return tmp;
    }
    reference operator*() const {
        return (*node).data;
    }
    pointer operator->() const {
        return &(operator*());
    }
private:
    link_node node;
};

template <typename T>
class list {

protected:
    typedef ListNode<T> link_node;
    typedef link_node* link_type;

public:
    typedef ListIterator<T, T&, T*> iterator;

protected:
    link_type node;

public:
    list() {
        node = new ListNode(-1);
    }
    iterator begin() const {
        return iterator(node->next);
    }

    iterator end() const {
        return iterator(node);
    }
    void push_front(const T& data) {
        link_type tmp_node = new ListNode(data);
        tmp_node->next = node->next;
        tmp_node->next->prev = tmp_node;
        tmp_node->prev = node;
        node->next = tmp_node;
    }

    void push_back(const T& data) {
        link_type tmp_node = new ListNode(data);
        tmp_node->prev = node->prev;
        tmp_node->prev->next = tmp_node;
        tmp_node->next = node;
        node->prev = tmp_node;
    }
};

int main() {
    list<int> l;
    list<int>::iterator it = l.begin();
    l.push_front(8);
    l.push_front(0);
    l.push_back(1);
    l.push_back(5);
    for (auto it = l.begin(); it != l.end(); ++it) {
        // std::cout << *it << std::endl;
    }
    
    return 0;
};