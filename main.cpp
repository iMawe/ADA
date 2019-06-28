
#include "TST.h"

int main() {
 
	TSTNode *root = NULL;
	root = Insert(root, "boats");
	root = Insert(root, "boat");
	root = Insert(root, "bat");
	root = Insert(root, "bats");
	root = Insert(root, "batsqweqwe");
	root = Insert(root, "stages");

	/*if(SearchTST(root, "boat")){
		cout<< "si esta"<<endl;
	}*/
	
	Searchprefi(root,"bat");
	//PrintAllStringsInTST(root);
	
	//printArbol();

	return 0;
}