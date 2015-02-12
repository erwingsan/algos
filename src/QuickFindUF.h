

#ifndef QUICKFINDUF_H_
#define QUICKFINDUF_H_

#include <iostream>
#include <vector>

using namespace std;

class QuickFindUF {
public:
	QuickFindUF(int N);
	bool connected(int p, int q);
	void makeUnion(int p, int q);

private:
	vector<int> id;
};

#endif /* QUICKFINDUF_H_ */
