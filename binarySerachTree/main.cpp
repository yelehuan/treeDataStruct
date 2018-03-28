#include <iostream>
#include <string>
#include <vector>
#include "bstree.h"
using namespace std;

int main(int argc, char** argv)
{
/*
	string str("ab+cde+**");
	ExpressionTree expTree;
	expTree.exec(str);		
	expTree.orderMidleOut();
*/
	vector<char> testData = {'f','b','e','a','c','g','n','m'};
	BiSerachTree st;
	st.loadData(testData);
	cout << "is contains z: " << st.contains('z') << endl;
	st.printTree();	
	cout << endl;
	cout << "min: " << st.findMin() << endl;
	cout << "max: " << st.findMax() << endl;
	
	return 0;
}
