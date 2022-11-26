#include<list>
using namespace std;

template<class T>
class Stack:protected List<T>{
    public:
        Stack(){};
        ~Stack(){};
        bool push(const T& v){List<T>::push_front(v);}
        using List<T>::empty();
}