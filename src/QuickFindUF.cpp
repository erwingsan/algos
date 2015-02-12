

#include "QuickFindUF.h"

QuickFindUF::QuickFindUF(int N) {

	for(int i=0; i<N; ++i)
		id[i] = i;
}

bool QuickFindUF::connected(int p, int q){
	return id[p] == id[q];
}


void QuickFindUF::makeUnion(int p, int q){

	int idp = id[p];

	for(int i=0;i<id.size();++i){
		if(id[i]==idp)
			id[i] = id[q];
	}
}
