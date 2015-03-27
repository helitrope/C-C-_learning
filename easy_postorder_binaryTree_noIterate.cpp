#include <iostream>
#include <stack>

using namespace std;

class BTnode{
	public:
	int key;
	BTnode *left;
	BTnode *right;
	BTnode *parent;
};
void PostOrder_NoRecur(BTnode *node){
	stack<BTnode *> s;
	while(node || !s.empty()){
		if(node){
			s.push(node);
			node = node->left;
		}
		else {
			while(!s.empty() && node == s.top()->right){
				node = s.top();
				s.pop();
				cout << "key: " << node->key << endl;
			}
			node = s.empty() ? NULL : s.top()->right;
		}
	}

}
int arr[5] = {5,2,7,1,3};
int main(){
	BTnode *root = new BTnode();
	//int arr[5] = {5,1,7,11,12};
	(*root).key = 5;
	root->parent = NULL;
	BTnode *oneleft = new BTnode();
	BTnode *oneright = new BTnode();
	BTnode *twoleft = new BTnode();
	BTnode *tworight = new BTnode();
	(*oneleft).key = arr[1];
	(*oneright).key = arr[2];
	(*twoleft).key = arr[3];
	(*tworight).key = arr[4];
	root->left = oneleft;
	root->right = oneright;
	oneleft->left = twoleft;
	oneleft->right = tworight;
	oneleft->parent = root;
	oneright->parent = root;
	twoleft->left = NULL;
	twoleft->right = NULL;
	tworight->left = NULL;
	tworight->right = NULL;
	PostOrder_NoRecur(root);
	return 0;
}
