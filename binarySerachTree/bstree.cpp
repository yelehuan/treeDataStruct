#include "bstree.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> //find
using namespace std;

vector<char> ExpressionTree::operators = {'+','-','*','/','%'};

void TreeNode::setParent(TreeNode* p)
{
	mParent = p;
}

void TreeNode::setLeftChild(TreeNode* lchild)
{
	mLeftChild = lchild;	
}	


void TreeNode::setRightChild(TreeNode* rchild)
{
	mRightChild = rchild;
}

TreeNode* TreeBase::createNode(char data, TreeNode* parent, bool left)
{
	TreeNode *node = new TreeNode(data);
	if (parent) {
		if (left) {
			parent->mLeftChild = node;
		} else {
			parent->mRightChild = node;
		}
		node->setParent(parent);
	}
	return node;
}

bool ExpressionTree::isOperator(char d)
{
	auto it = find(operators.begin(), operators.end(), d);
	if (it != operators.end())	
		return true;
	return false;
}

void TreeBase::preOrderTrave(TreeNode* root) const
{
	if (root == NULL)
		return;
	cout << root->data();
	preOrderTrave(root->leftChild());
	preOrderTrave(root->rightChild());
}

void TreeBase::midleOrderTrave(TreeNode* root) const
{
	if (root == NULL)
		return;
	midleOrderTrave(root->leftChild());
	cout << root->data();
	midleOrderTrave(root->rightChild());
}

void ExpressionTree::orderOut()
{
	cout << "orderOut: ";
	preOrderTrave(mRoot);
	cout << endl;
}

void ExpressionTree::orderMidleOut()
{
	cout << "midle order out : ";
	midleOrderTrave(mRoot);
	cout << endl;
}

bool ExpressionTree::exec(const string& expression)
{
	stack<TreeNode*> workStack;
	for(auto c : expression){
		if (mRoot == NULL) {
			mRoot = createNode(c);	
			workStack.push(mRoot);
		} else {
			TreeNode* newNode = createNode(c);
			if (isOperator(c)){
				TreeNode* rNodePtr = workStack.top();	
				newNode->setRightChild(rNodePtr);
				workStack.pop();
				TreeNode* lNodePtr = workStack.top();
				workStack.pop();
				newNode->setLeftChild(lNodePtr);
			} 
			mRoot = newNode;
			workStack.push(newNode);
		}
	}
}

void TreeBase::destroyTree(TreeNode *root)
{
	if (root == NULL)	
		return;
	destroyTree(root->leftChild());	
	destroyTree(root->rightChild());
	delete root;
	root = NULL;
}

TreeBase::~TreeBase()
{
	destroyTree(mRoot);
	cout << "~TreeBase" << endl;
}



ExpressionTree::~ExpressionTree()
{
	cout << "~ExpressTree" << endl;
}

BiSerachTree::~BiSerachTree()
{
	cout << "~BiSerachTree()" << endl;
}

void BiSerachTree::loadData(const vector<char>& datas)
{
	if (datas.empty())
		return;
	for (const char& item : datas){
		insert(item);
	}
}

TreeNode* BiSerachTree::findMin(TreeNode* root) const
{
	if (root == NULL)	
		return NULL;
	if (root->leftChild() == NULL)
		return root;
	return findMin(root->leftChild());
}

const char BiSerachTree::findMin() const
{
	TreeNode* maxNode = findMax(getRoot());
	TreeNode* minNode = findMin(getRoot());
	if (minNode == NULL)
		return ' ';
	return minNode->data();	
}

TreeNode* BiSerachTree::findMax(TreeNode* root) const
{
	if (root == NULL)
		return NULL;
	while(root->rightChild() != NULL)
	{
		root = root->rightChild();	
	}
	return root;
}

const char BiSerachTree::findMax() const
{
	TreeNode* maxNode = findMax(getRoot());
	if (maxNode == NULL)
		return ' ';
	return maxNode->data();	
}

bool BiSerachTree::contains(const char& item, TreeNode* root) const
{
	if (root == NULL)
		return false;
	char data = root->data();	
	if (item < data)
		contains(item, root->leftChild());
	else if (data < item)
		contains(item, root->rightChild());
	else
		return true;
}

bool BiSerachTree::contains(const char& x) const
{
	return contains(x, getRoot());
}


bool BiSerachTree::isEmpty() const
{

}

void BiSerachTree::printTree() const
{
	TreeBase::midleOrderTrave(mRoot);
}

void BiSerachTree::insert(const char& item, TreeNode* &root) 
{
	if (root == NULL) {
		root = createNode(item);
		return;
	}
	char data = root->data();
	
	if (item < data) {
		insert(item, root->mLeftChild);
	} else if (data < item) {
		insert(item, root->mRightChild);
	} else {
		return;
	}
}

void BiSerachTree::insert(const char& data)
{
	insert(data, mRoot);
}

void BiSerachTree::remove(const char& item, TreeNode* &root)
{
	if (root == NULL)
		return;
	char data = root->data();
	if (item < data) {
		remove(item, root->mLeftChild);
	} else if (data < item) {
		remove(item, root->mRightChild);
	} else {
		if (root->mLeftChild != NULL && root->mRightChild != NULL) {
			root->mData = findMin(root->mRightChild)->data();	
			remove(root->mData, root->mRightChild);
		} else {
			TreeNode* oldNode = root;
			root = (root->mLeftChild != NULL) ? root->mLeftChild : root->mRightChild;
			delete oldNode;
		}
	}
}

void BiSerachTree::remove(const char& data)
{
	remove(data, mRoot);
}
























