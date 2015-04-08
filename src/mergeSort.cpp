#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;


void printvv(int ar_size, int *  ar) {
    for(int i=0; i<ar_size; ++i){
        cout << ar[i] << " ";
    }
    cout << endl;
}
void mergeSort(int *ar, int f, int l, int s) {
    
    //Divide
    if(l-f == 0) // only one element
        return;
    
    mergeSort(ar, f, f+(l-f)/2, s);
    mergeSort(ar, f+1+(l-f)/2, l, s);
    
    // Merge
    int tmp[l-f+1];
    int p1 = f;
    int p2 = f+1+(l-f)/2;
    
    for(int i = 0; i<=l-f; ++i){
        if(p2>l){
            tmp[i] = ar[p1];
            ++p1;
        }else
            if(p1>f+(l-f)/2){
                tmp[i] = ar[p2];
                ++p2;
            }
        else
            if(ar[p1] < ar[p2]){
                tmp[i] = ar[p1];
                ++p1;
        }
        else{
            tmp[i] = ar[p2];
            ++p2;
        }
    }
    
    for(int i = 0; i<=l-f; ++i){
        ar[i+f] = tmp[i];
    }
    
    printvv(s, ar);
    
    
}
int main(void) {
    
    int _ar_size;
    cout << "Merge" << endl;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]);
    }
    
    mergeSort(_ar, 0, _ar_size-1, _ar_size);
    //printvv(_ar_size, _ar);
    
    return 0;
}
