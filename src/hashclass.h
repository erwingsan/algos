//
//  hashclass.h
//

#ifndef __algos__hashclass__
#define __algos__hashclass__

#include <stdio.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class hashclass{
public:
    hashclass();
    int hash(string key);
    bool insert(string key, int content);
    int search(string key);
   
private:
    struct NodeHash{
        string key;
        int content;
       // NodeHash *next;
       // NodeHash *prev;
    };
    vector<list<NodeHash>> table;
    int size;
    int used;
    int mods[3] = {7, 17, 29};
    int cmod;
    
};



#endif /* defined(__algos__hashclass__) */
