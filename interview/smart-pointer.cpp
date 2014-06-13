#include<iostream>
using namespace std;

struct node{
    int a, b;
    node(int a, int b):a(a), b(b){}
};

template <class T>
class SmartPtr{
private:
    T *ptr;
public:
    explicit SmartPtr(T *p = NULL) {ptr = p;}
    ~SmartPtr(){delete(ptr);};
    T& operator *() { return *ptr; }
    T* operator -> () { return ptr; }
};

int main(){
    SmartPtr<node> p1(new node(1,2));
    cout << p1->a << endl;
}
