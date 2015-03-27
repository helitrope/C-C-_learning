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
void PostOrder_NoRecur(BTnode *MyTree)  
{  
    stack<BTnode *> stk,stk1;  
    if(MyTree==NULL)  
        return;  
    stk.push(MyTree);  
  
    BTnode *left=MyTree->left;  
    while(left)  
    {  
        stk.push(left);  
        left=left->left;  
    }  
    while(!stk.empty())  
    {  
        BTnode *top=stk.top();  
        if(top->right==NULL)  
        {  
            cout<<top->key << endl;  
            stk.pop();  
        }  
        else  
        {     
            if((!stk1.empty()) && top==stk1.top())  
            {  
                cout<<stk1.top()->key<<endl;  
                stk.pop();  
                stk1.pop();  
                continue;  
            }  
            stk1.push(top);  
            top=top->right;  
            while(top)  
            {  
                stk.push(top);  
                top=top->left;  
            }  
  
        }  
  
  
    }  
}   
int arr[5] = {5,1,7,11,12};
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
