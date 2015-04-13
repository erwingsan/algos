//
//  hashclass.cpp
//
#include <climits>
#include <iostream>
#include "hashclass.h"

using namespace std;

int mainHC(){
    
    hashclass myhash;
    
    myhash.insert("test", 10);
    myhash.insert("one", 1);
    myhash.insert("two", 2);
    myhash.insert("three", 3);
    myhash.insert("four", 4);
    myhash.insert("five", 5);
    myhash.insert("six", 6);
    myhash.insert("seven", 7);
    myhash.insert("eight",8);
    myhash.insert("nine", 9);
    myhash.insert("ten", 10);
    myhash.insert("eleven", 11);

    cout << "hash" <<endl;
    
    cout << myhash.search("test") << endl;
    cout << myhash.search("eleven") << endl;
    cout << myhash.search("NonExist") << endl;
    
    
    
    return 0;
}



hashclass::hashclass():table(10){
    size = 10;
    used = 0;
    cmod = 0;
    //table.resize(size);
}

int hashclass::hash(string key){
    //calculate pre hash of string
    
    long int strint = 0;
    
    for(int i=0; i< key.size(); ++i){
        strint = 31*(strint % mods[cmod]) + key[i];
    }
    
    //hash
    return strint % mods[cmod];
}

bool hashclass::insert(string key, int content){
    int hkey = hash(key);
    
    //push element in list
    NodeHash myel;
    myel.key = key;
    myel.content = content;
    table[hkey].push_front(myel);
    
    return true;
}

int hashclass::search(string key){
    int hkey = hash(key);
    
    list<NodeHash> myl= table[hkey];
    for(list<NodeHash>::iterator it = myl.begin(); it!=myl.end(); ++it){
        if((*it).key == key)
            return (*it).content;
    }
    
    return INT_MIN;
    
}





