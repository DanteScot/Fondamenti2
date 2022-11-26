//file vector.h

#ifndef vector_h    //if not defined
#define vector_h

//#include<iostream> se prevediamo di utilizzarla
#include<assert.h>

template<class R>
class Vector{
    R* vec;
    int sz,cap;

    public:
        Vector();/**/
        Vector(const Vector<R>&);/**/
        Vector(const R v[],const int dim);
        ~Vector(); //alt+126, distruttore /**/
        int size() const {return sz;}/**/
        int capacity() const {return cap;}/**/
        R operator[](int) const;/**/
        R& operator[](int);/**/
        Vector& operator=(const Vector<R>&);
        void push_back(const R&);/**/
        const R& back() const;
        void pop_back();
        void reserve(int);/**/
        void resize(int);/**/
};

template<class R>
Vector<R>::Vector(){
    sz=0;
    cap=1;

    vec=new R[cap];
}

template<class R>
Vector<R>::Vector(const Vector& v){
    sz=v.sz;
    cap=v.cap;

    vec=new R[cap];

    for (int i = 0; i < sz; i++)    vec[i]=v.vec[i];
}

template<class R>
Vector<R>::Vector(const R v[],const int dim){
    sz=cap=dim;

    vec=new R[cap];

    for (int i = 0; i < sz; i++)    vec[i]=v[i];
}

template<class R>
Vector<R>::~Vector(){
    delete[] vec;
}

template<class R>
R Vector<R>::operator[](int i) const{
    assert(i>=0 && i<sz);   //se la cond non è soddisfatta blocca il programma
    return vec[i];
}

template<class R>
R& Vector<R>::operator[](int i){
    assert(i>=0 && i<sz);
    return vec[i];
}

template<class R>
void Vector<R>::push_back(const R& e){
    if(sz==cap) reserve(sz*2);
    vec[sz]=e;
    sz++;
}

template<class R>
void Vector<R>::reserve(int size){
    if(size>cap){
        cap=size;
        R* temp=new R[cap];
        for (int i = 0; i < sz; i++)
        {
            temp[i]=vec[i];
        }
        delete vec;
        vec=temp;
    }
}

template<class R>
void Vector<R>::resize(int size){
    reserve(size);
    sz=size;
}


#endif