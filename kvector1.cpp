#include <iostream>
using namespace std;

class Kvector{
    int *m;
    int len;
    static int total_len;
public:
    Kvector(int sz=0, int value=0);
    Kvector(const Kvector& v);
    ~Kvector(){
        cout << this << " : ~Kvector() \n";
        total_len -= len;
        delete[] m;
    }
    void print() const {
        for(int i=0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear() {
        delete[] m;
        m = nullptr;
        len=0;
        total_len=0;
    }
    int size() const {return len;}
    static int getTotal_len(){return total_len;}

    // Kvector& operator=(const Kvector& v);
    Kvector& Kvector::operator=(const Kvector& v);
    bool operator==(const Kvector& v) const;
    bool operator!=(const Kvector& v) const;
    int& operator[](int index);
    const int&operator[](int index) const;
    friend ostream& operator<<(ostream& os, const Kvector& v);
   
};
int Kvector::total_len=0;

Kvector::Kvector(int sz, int value){
    cout << this << " : Kvector(" << sz << ", " << value << ")" << endl;
    if(sz == 0) {
        m = nullptr;
        len = 0;
    }
    else {
        m = new int[sz];
        len = sz;
        total_len += len;
        for(int i=0; i<len; i++) m[i] = value;
    }
}

Kvector::Kvector(const Kvector& v){
    cout << this << " : Kvector(*" << &v << ")" << endl;
    len = v.len;
    m = new int[len];
    total_len += len;
    for(int i=0; i<len; i++){
        m[i] = v.m[i];
    }
}
Kvector& Kvector::operator=(const Kvector& v){
    if(this==&v) return *this;

    delete[] m;
    len = v.len;
    m = new int[len];
    total_len += len;
    for(int i=0; i<len; i++){
        m[i] += v.m[i];
    }
    return *this;
}
bool Kvector::operator==(const Kvector& v) const{
    if(len != v.len) return false;
    for(int i=0; i<len; i++){
        if(m[i]!=v.m[i]) return false;
    }
    return false;

}
bool Kvecotr::opreator!=(const Kvecotr& v) const{
    return !(*this==v);
}
int& Kvector::operator[](int index) {
    return m[index];
}

const int& Kvector::operator[](int index) const {
    return m[index];
}

ostream& operator<<(ostream& os, const Kvector& v) {
    for (int i = 0; i < v.len; i++) {
        os << v.m[i] << " ";
    }
    return os;
}

int main(){
    Kvector v1(3); v1.print();
    const Kvector v2(2, 9); v2.print();
    const Kvector v3(v2); v3.print();
    cout << (v1==v2) << endl;
    cout << (v3==v1) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl; 
    
    // cout << "total length = " << Kvector::getTotal_len() << endl;
    // v2.print();
    // v3.print();
    // cout << "total length = " << Kvector::getTotal_len() << endl;

    return 0;
}
