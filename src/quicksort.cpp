

#include <iostream>
#include <algorithm>


using namespace std;


void printvv1(int ar_size, int *  ar) {
    for(int i=0; i<ar_size; ++i){
        cout << ar[i] << " ";
    }
    cout << endl;
}
void quickSort(int *ar, int f, int l, int s) {
    
    
    if(f<l){
    
    //Divide
    //Pivot
    int pivot = ar[f];
    
    int i = f;
    int j = f + 1;
    
    while(j<=l){
        if(ar[j] <= pivot){
            swap(ar[j], ar[i+1]);
            i++;
        }
        j++;
    }
    
    swap(ar[f], ar[i]);
    
    quickSort(ar, f, i-1, s);
    quickSort(ar, i+1, l, s);
    
    
    
    
    printvv1(s, ar);
        
    }
    
    
}
int main(void) {
    
    int _ar_size;
    cout << "Quick Sort" << endl;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]);
    }
    
   quickSort(_ar, 0, _ar_size-1, _ar_size);
    
    return 0;
}
