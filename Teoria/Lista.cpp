template<class T>
class Node{
    T value;
    Node<T>* nextNode;
    friend class List<T>;
    friend class Iterator<T>;

    public:
        Node(const T& v):nextNode(nullptr),value(v){}
        T getValue() const {return value;}
        Node<T>* getNextNode() const {return nextNode;}
};



template<class T>
class List{
    protected:
        Node<T>* first, *last;
        Node<T>* newNode(const T&);

    public:
        List():first(nullptr),last(nullptr){}
        ~list();/**/
        void push_front(const T&);/**/
        void push_back(const T&);
        bool pop_front(T& v);
        bool pop_back(T& v);/**/
        bool empty(){return first==nullptr;}
        Node<T>* front();
        void remove(const T& v);
        void delNode(Node<T>*&)
};




template<class T>
List<T>::~List(){
    if(first==nullptr)  return;

    Node<T>* curr=first, *tmp;
    while (curr!=nullptr)
    {
        tmp=curr;
        curr=curr->nextNode;
        delete tmp;
    }
}

template<calss T>
void List<T>::push_front(const T& v){
    Node<T>* n=newNode(v);
    if(empty()) first=last=n;
    else
    {
        n->nextNode=first;
        first=n;
    }
    
}

template<class T>
bool List<T>::pop_back(T& v){
    if(empty()) return false;

    Node<T>* tmp=last;
    
    if(first==last) first=last=nullptr;
    else
    {
        Node<T>* curr=first;
        while(curr->nextNode!=last) curr=curr->nextNode;

        last=curr;
        last->nextNode=nullptr;
    }

    v=tmp->value;
    delete tmp;

    return true;
}

template<class T>
class Iterator
{
Node<T>* prec, *curr;
Lista<T>& l;
public:
    Iterator(List<T>& lista):l(lista),curr(lista.first),prec(nullptr);
    T operator*{return curr->value}
    void operator++{prec=curr; curr=curr->nextNode;}
    void insert(const T& val);
};

Iterator::Iterator(List<T>& lista):l(lista),curr(lista.first),prec(nullptr)
{
}


template<class T>
void Iterator<T>::insert(const T& val){
    if(curr==l.first){
        l.push_front(val);
        curr=l.first;
        prec=nullptr;
    }else if(prec==l.last){
        l.push_back(val);
        corr=l.last;
    }else{
        Node<T>* n=newNode(val);
        n->nextNode=curr;
        prec->nextNode=n;
        curr=n
    }
}