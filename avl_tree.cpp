#include "avl_tree.h"
using namespace std;
avl_tree::avl_tree()
{
	root = NULL;
}


int avl_tree::max(int num_1, int num_2) {
	return  (num_1 > num_2) ? num_1 : num_2;
}

void avl_tree:: updateHeight(node * temp) {
	int lHeight = 0;
	int rHeight = 0;
	if (temp->left) {
		lHeight = temp->left->height;
	}
	if (temp->right) {
		rHeight = temp->right->height;
	}
	int max = (lHeight > rHeight) ? lHeight : rHeight;
	temp->height = max + 1;
}
int avl_tree::get_height(node *temp)
{
	int h = 0;
	if (temp) {
		int left_height = get_height(temp->left);
		//cout << left_height;
		int right_height = get_height(temp->right);
		//cout << right_height;
		int max_height = max(left_height, right_height);
		h = max_height+1 ;
	}
	

	return h;
}

int avl_tree::height_dif(node *leaf)
{
	int lHeight = 0;
	int rHeight = 0;
	if (leaf->left) {
		lHeight = leaf->left->height;
	}
	if (leaf->right) {
		rHeight = leaf->right->height;
	}
	return lHeight - rHeight;
}

node * avl_tree::get_root()
{
	return this->root;
}




node * avl_tree::rr_rotation(node *&p)
{

	node *temp = p->left;
	p->left = temp->right;
	temp->right = p;
	updateHeight(p);
	return temp;
}

node * avl_tree::ll_rotation(node *p)
{
	node * temp = p->right;
	p->right = temp->left;
	temp->left = p;
	updateHeight(p);
	return temp;
}

node * avl_tree::rl_rotation(node *p)
{
	node * temp = p->right;
	p->right = rr_rotation(temp);
	return ll_rotation(p);

}
 
node * avl_tree::lr_rotation(node *p)
{
	node* temp = p->left;
	p->left = ll_rotation(temp);
	return rr_rotation(p);
}

void avl_tree::rebalance(node *&leaf) {
	int hDiff = height_dif(leaf);
//	cout <<leaf->account.name<<"\t"<< hDiff<<endl;
	if (hDiff > 1) {
		if (height_dif(leaf->left) > 0) {
			leaf = rr_rotation(leaf);
		}
		else {
			leaf = lr_rotation(leaf);
		}
	}
	else if (hDiff < -1) {
		
		if (height_dif(leaf->right) < 0) {
			leaf = ll_rotation(leaf);
		}
		else {
			leaf = rl_rotation(leaf);
		}
	}
}

void avl_tree::insert(info newUser) {
	insert(newUser, this->root);
}
void avl_tree::insert(info newUser, node *&leaf)
{
	cout << newUser.phone_number;
	if (leaf == NULL) {

		leaf = new node(newUser);
		updateHeight(leaf);
	}
	else {
		if (newUser.phone_number < leaf->account.phone_number ) {
			insert( newUser, leaf->left);
			updateHeight(leaf);
			rebalance(leaf);
		}
		else {
			insert(newUser, leaf->right);
			updateHeight(leaf);
			rebalance(leaf);
		}
	}
}

node* avl_tree::search(node * root, long long  user)
{
	if (root == NULL)
		//USER not found
		cout << "not exist";
	if (root->account.phone_number == user)
		return root;
	if (root->account.phone_number < user)
		return search(root->right, user);
	else 
		return search(root->left, user);
	
}
node * avl_tree::search(long long number)
{
	return search(root, number);
}
bool avl_tree::exist_search(long long number)
{
	return exist_search(this->root, number);
}
bool avl_tree::exist_search(node * root, long long phone_number)
{
	if (root == NULL)
		return false;
	if (root->account.phone_number == phone_number)
		return true;

	if (root->account.phone_number < phone_number)
		return exist_search(root->right, phone_number);
	else
		return exist_search(root->left, phone_number);
}

void avl_tree::inorder(node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->account.name<<"      "<< tree->account.f_name<<"      " << tree->account.phone_number <<"\n";
	inorder(tree->right);
}