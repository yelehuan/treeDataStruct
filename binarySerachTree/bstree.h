#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
	TreeNode(char data) 
		: mData(data)
		, mLeftChild(NULL)
		, mRightChild(NULL)
		, mParent(NULL)
	{ }

	~TreeNode(){
		cout << "~TreeNode()" << endl;
	}

	void setParent(TreeNode* p);
	void setLeftChild(TreeNode* lchild);
	void setRightChild(TreeNode* rchild);

	inline char data() { return mData;}
	inline TreeNode* leftChild() { return mLeftChild;}
	inline TreeNode* rightChild() { return mRightChild;}
	inline TreeNode* parent() { return mParent;}
	
	char mData;	
	TreeNode* mLeftChild;
	TreeNode* mRightChild;
	TreeNode* mParent;
};

struct TreeBase {
	TreeBase() : mRoot(NULL)
	{ cout << "TreeBase() " << endl;}
	virtual ~TreeBase();
	inline TreeNode* getRoot() const { return mRoot;}
	void destroyTree(TreeNode *root);

	void preOrderTrave(TreeNode* root) const;
	void midleOrderTrave(TreeNode* root) const;
	TreeNode* createNode(char data, TreeNode* parent = NULL, bool left = true);	
	

	TreeNode* mRoot;
};

class BiSerachTree : public TreeBase{
public:
	explicit BiSerachTree()
	{
		cout << "BiSearchTree()" << endl;
	}
		
	~BiSerachTree();
	void loadData(const vector<char>& datas);

	const char findMin() const;
	const char findMax() const;
	bool contains(const char& x) const;
	bool isEmpty() const;
	void printTree() const;

	void insert(const char& data);
	void remove(const char& data);
private:
	void insert(const char& item, TreeNode* & root);
	bool contains(const char& item, TreeNode* root) const;
	TreeNode* findMin(TreeNode* root) const;
	TreeNode* findMax(TreeNode* root) const;
	void remove(const char& item, TreeNode* &root);
};

class ExpressionTree : public TreeBase {
public:
	explicit ExpressionTree()
	{
		cout << "Expression construct" << endl;
	}
	~ExpressionTree();
	
	bool exec(const string& expression);
	void orderOut();
	void orderMidleOut();
private:
	static bool isOperator(char d);
	static vector<char> operators;
};
