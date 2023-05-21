#include <iostream>
using namespace std;

class Kvector{
    int *m;
    int len;

public:
    Kvector(int sz=0, int value=0);
    Kvector(const Kvector& v);
    ~Kvector(){
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }

    void print() const {
        for (int i = 0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }

    void clear() {
        delete[] m;
        m = nullptr;
        len = 0;
    }

    int size() { return len; }

    Kvector& operator=(const Kvector& v);

    friend bool operator==(const Kvector& v, const Kvector& w);
    friend bool operator!=(const Kvector& v, const Kvector& w);

    int& operator[](int idx) { return m[idx]; }
    const int& operator[](int idx) const { return m[idx]; }

    friend ostream& operator<<(ostream& os, const Kvector& v);
};
Kvector::Kvector(int sz, int value){
    cout << this << " : Kvector(" << sz << ", " << value << ")" << endl;
    if(sz == 0) {
        m = nullptr;
        len = 0;
    }
    else {
        m = new int[sz];
        len = sz;
        for(int i=0; i<len; i++) m[i] = value;
    }
}

Kvector::Kvector(const Kvector& v){
    cout << this << " : Kvector(*" << &v << ")" << endl;
    len = v.len;
    m = new int[len];
    for(int i=0; i<len; i++){
        m[i] = v.m[i];
    }
}

Kvector& Kvector::operator=(const Kvector& v){
    delete[] m;
    len = v.len;
    m = new int[len];
    for(int i=0; i<len; i++)m[i] = v.m[i];
    return *this;
}

bool operator==(const Kvector& v, const Kvector& w){
    if(v.len != w.len) return false;
    for(int i=0; i<v.len; i++)
        if(v.m[i] != w.m[i]) return false;
    return true;
}

bool operator!=(const Kvector& v, const Kvector& w){
    return !(v==w);
}

ostream& operator<<(ostream& os, const Kvector& v){
    for(int i=0; i<v.len; i++) os << v.m[i] << " ";
    return os;
}

int main(){
    Kvector v1(3);
    v1.print();
    Kvector v2(2,9);
    v2.print();
    Kvector v3(v2);
    v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << " v2: " << v2 << " v3: " << v3 << endl;
    return 0;
}