#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define TARGET 'e'

int main(int argc, char *argv[]){
    if(argc < 2) {cout << "one command line argument needed\n"; return -1;}
    int n = strlen(argv[1]);
    char *a = new char[n*2+3];
    if(!a) {cout << "allocation failed.\n"; return -1;}
    a[0] = '!';  
    for(int i=0; i<n+1; i++){
        a[i+1] = argv[1][i];
    }
    a[n+1]='.';

    for(int i=0; i<n*2+3; i++){
        if(a[i]=='e'){
            for(int j=n*2+3; j>i; j--){ 
                a[j+1]=a[j];
            }
            a[i+1]='e';
            i += 2;
            i--;
        }else continue;
    }
    
    cout << a << endl;
    delete[] a;
    

    string s = "!";
    s += argv[1];
    s +=".";
    int pos =0;
    while((pos=s.find("e",pos))!=string::npos){
        s.replace(pos,1,"ee");
        pos +=2;
    }

    cout << s << endl;
    return 0;
}   