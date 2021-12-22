#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "info.h"
#include "node.h"


class avl_tree {
private:
	node *root;
public:
	avl_tree();
	int max(int, int);
	void updateHeight(node * );
	int get_height(node *);
	int height_dif(node *);
	

	node * rr_rotation(node *&);
	node * ll_rotation(node *);
	node * rl_rotation(node *);
	node * lr_rotation(node *);

	void inorder(node *);

	void rebalance(node *& );
	void insert(info );
	void insert(info,node *& );
	node * search( long long  );
	static node * search(node *,long long);
	bool exist_search( long long);
	bool exist_search(node *, long long);
	node * get_root();
	
	//void in_order(node *);

};
