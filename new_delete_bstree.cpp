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

/*void in_order(BTnode *root){
	stack<BTnode *> node_stack;
	BTnode *lnode = root->left;
	BTnode *rnode = root->right;
	if (root != NULL){
		while(lnode != NULL){
			node_stack.push(lnode);
			lnode = lnode->left;
		}
		cout << " key:" << (*root).key << endl;
		while(lnode->right != NULL)
			node_stack.push(lnode->right);
		node_stack.pop();
	}
}*/
void in_order(BTnode *root){
	stack<BTnode *> node_stack;
	BTnode *p = root;
	while(p || !node_stack.empty()){
		while(p){
			node_stack.push(p);
			p = p->left;
		}
		if(!node_stack.empty()){
			p = node_stack.top();
			node_stack.pop();
			cout << "key: " << p->key << endl;
			p = p->right;
		}
	}
}

void Transplant(BTnode *root, BTnode *u, BTnode *v){
	if(u->parent == NULL){
		root = v;
	}
	else if(u == u->parent->left){
		u->parent->left = v;
	}
	else u->parent->right = v;
	if(v != NULL){
		v->parent = u->parent;
	}
}

BTnode *tree_minimum(BTnode *min_node, BTnode *s){
	while(s->left != NULL){
		s = s->left;
	}
	return s;
}
void Delete(BTnode *root, BTnode *node){
	if(node->left == NULL){
		Transplant(root, node, node->left);
	}
	else if(node->right == NULL){
		Transplant(root, node, node->right);
	}
	else {
		BTnode *y = new BTnode();
		y = tree_minimum(y, node->right);
		if(y->parent != node){
			Transplant(root, y, y->right);
			y->right = node->right;
			y->right->parent = y;
		}
		Transplant(root, node, y);
		y->left = node->left;
		y->left->parent = y;
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
	twoleft->parent = oneleft;
	tworight->parent = oneleft;
	in_order(root);
	Delete(root, oneleft);
	in_order(root);
	return 0;
}
