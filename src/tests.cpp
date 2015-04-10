// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
 };

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
void printList(ListNode *l);
int bsearch(vector<int> &v, int start, int end, int val);

int mainTTT() {
    int val;
    cin >> val;

 //   cout << "Value " << val << endl;
    int n;
    cin >> n;

 //   cout << "Size " << n << endl;

    vector<int> arr;
    for(int i=0; i<n; ++i){
        int elem;
        cin >> elem;
        arr.push_back(elem);
     //   cout << elem;
    }

    //print
//     for(int i=0; i<n; ++i){
//        cout << arr[i] << " - ";
//    }
    int pos = bsearch(arr, 0, n-1, val);

    cout << "Result:  " << pos;

    return pos;
}


int bsearch(vector<int> &v, int start, int end, int val){

    int middle = (end-start)/2 + start;
    if(v[middle] == val) return middle;

    cout << "Start: " << start << " End: " << end <<  " Middle: " << middle << endl;

    if(v[middle]>val){
        return bsearch(v, start, middle-1, val);
    }
    else{
        return bsearch(v, middle+1, end, val);
    }
}

int mainXXX()
{

  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);

  l1->next = new ListNode(1);
  cout << "Starting" << endl;

  printList(l1);
  printList(l2);

  ListNode *res = addTwoNumbers(l1, l2);

  cout << "Res : ";


 printList(res);
//  while(res != 0){
//        cout << res->val << "->";
//        res = res->next;
//    }
    
    return 0;

}


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *result = new ListNode(0);

        int carry = 0;
        ListNode *cn1=l1;
        ListNode *cn2=l2;
        ListNode *pRes = result;


        while(cn1 != 0 || cn2 != 0 || carry != 0){
            int cval1=0, cval2=0;


            if(cn1 != 0){
                cval1 = cn1->val;
                cn1 = cn1->next;
            }
            if(cn2 != 0){
                cval2 = cn2->val;
                cn2 = cn2->next;
            }

            int ctot = cval1 + cval2 + carry;
            cout << "ctot: " << ctot << endl;
            carry = ctot/10;
            ctot = ctot % 10;


            ListNode *myNode = new ListNode(ctot);
            pRes->next = myNode;
            pRes = pRes->next;


        }

        return result->next;
}

void printList(ListNode *l){

    ListNode *c = l;
    while(c != 0){
        cout << c->val << "->";
        c = c->next;
    }

    cout << "Null" << endl;

}
