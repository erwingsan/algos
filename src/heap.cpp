
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define PARENT(x) (x/2)

using namespace std;

void build_max_heap(vector<int> &hh);
void printh(const vector<int> hh);
void max_heapify(vector<int> &hh, int pos, int size);
// Priority Queue
int heap_extract_maximum(vector<int> &hh);
int heap_maximum(vector<int> hh);
void heap_increase(vector<int> &hh, int pos, int key);
void heap_insert(vector<int> &hh, int key);

int main(){
    int s;
    cout<<"Heap size: ";
    cin >> s;
    vector<int> hh;
    
    for(int i=0; i<s ; ++i){
        int e;
        cin>>e;
        hh.push_back(e);
    }
    
    build_max_heap(hh);
    
    cout << "sort" << endl;
    
    //sort
    //switch maximum with edge and heapify root
    /*
     * Sorting 
     *
    int size = hh.size();
    while(size >= 2){
        swap(hh[0], hh[size-1]);
        max_heapify(hh, 1, --size);
        printh(hh);
    }
    */
    
    // Removing Max (priority queue)
    
    cout << " Removing Max: " << endl;
    cout << heap_extract_maximum(hh) << endl;
    printh(hh);
    cout << heap_extract_maximum(hh) << endl;
    printh(hh);
    
    // Increase element
    cout << "Increase pos 3:" << endl;
    heap_increase(hh, 3, 15);
    printh(hh);
    
    // Insert element
    cout << "Insert" << endl;
    heap_insert(hh, 20);
    printh(hh);

    
}

void build_max_heap(vector<int> &hh){
    //Create max heap
    //suppose starting index 1
    //correct shift in max_heapify
    
    for(int i = hh.size()/2; i>0; --i){
        max_heapify(hh, i, hh.size());
        printh(hh);
    }
    
}

void max_heapify(vector<int> &hh, int pos, int size){
    
    int left = 2*pos-1; //original: 2*pos
    int right = 2*pos; //original: 2*pos + 1
    pos = pos-1; // shift correction
    int larger = pos;
    
    if(left < size && hh[left] > hh[pos])
        larger = left;
    if(right < size && hh[right] > hh[larger])
        larger = right;
    
    if(larger != pos){
        swap(hh[pos], hh[larger]);
        max_heapify(hh, larger+1, size);
    }
    
}
// Priority queue functions

int heap_maximum(vector<int> hh){
    return hh[0];
}

int heap_extract_maximum(vector<int> &hh){
    
    int max = hh[0];
    
    swap(hh[0], hh[hh.size()-1]);
    
    hh.erase(hh.begin()+hh.size()-1);
    
    max_heapify(hh, 1, hh.size());
    
    return max;
}

void heap_increase(vector<int> &hh, int pos, int key){
    
    if (hh[pos-1] > key){
        cout << "Error" << endl;
        return;
    }
    
    hh[pos-1] = key;
    
    while(pos > 1 && hh[PARENT(pos)-1] < hh[pos-1]){
        max_heapify(hh, PARENT(pos), hh.size());
        pos = PARENT(pos);
    }
    
}

void heap_insert(vector<int> &hh, int key){
    // insert element in the last position
    hh.push_back(INT_MIN);
    
    heap_increase(hh, hh.size(), key);
    
}

void printh(const vector<int> hh){
    for(int i = 0; i<hh.size(); ++i){
        cout << hh[i] << " ";
    }
    cout << endl;
}