#include <iostream>
#include <cstdlib>
using namespace std;

int *makeArray1D(int *sz);
void destroyArray1D(int *arr, int *sz);

int main(int argc, char *argv[]){
    if(argc < 2){
        cout << "usage : ./str 1d 2d 3d ... nd \n";
        return -1;
    }
    int i,dim=argc-1;
    int *size = new int[dim];

    for(int i=1; i<argc; i++) size[i-1]=atoi(argv[i]);

    int *arr1d = NULL;

    arr1d = makeArray1D(size);
    for(int i=0; i<size[0]; i++) arr1d[i] = i;
    for(int i=0; i<size[0]; i++) cout << arr1d[i] << " ";
    cout << endl;
    cout << argv[1] << argv[0] << argc << endl;
    destroyArray1D(arr1d, size);
    return 0;
}
int *makeArray1D(int *sz){
    int n = sz[0];
    int *arr = new int[n];
    return arr;
}
void destroyArray1D(int *arr, int *sz){
    delete[] arr;
}