/*
 * btree.h
 *
 *  Created on: Feb 20, 2015
 *      Author: MackO
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
using namespace std;

template<class type>
struct node
{
	type key;
	node* left;
	node* right;
	node* parent;
};

template<class type>
class bstree
{
public:
	bstree();
	bstree(const bstree& other);
	~bstree();

	void insert(type key);
	node<type>* search(type key);
	node<type>* getroot() const;
	void destroyTree();
	int nodelvl(type key);
	bool remove(type key);

private:
	node<type>* removeFindNew(node<type>* leaf);
	node<type>* copynode(node<type>* clone);
	void copytree(node<type>* clone,node<type>* thisTree);
	node<type>* nodelvl(type key, node<type>* leaf,int &count);
    void destroyTree(node<type> *leaf);
    void insert(type key, node<type> *leaf);
    node<type> *search(type key, node<type> *leaf);

    node<type>* root;
};

template<class type>
node<type>* bstree<type>::getroot() const{
	return root;
}
template<class type>
void bstree<type>::copytree(node<type>* clone,node<type>* thisTree){
	if(clone != NULL){
		thisTree = copynode(clone);
		if(clone->right !=NULL){
			copytree(clone->right,thisTree->right);
		}
		if(clone->left !=NULL)
			copytree(clone->left,thisTree->left);
	}
}

template<class type>
bstree<type>::bstree(const bstree& other){
	root = copynode(other.getroot());
	node<type>* temp = other.getroot();
	if(temp->right != NULL)
		copytree(temp->right,root->right);
	if(temp->left != NULL)
		copytree(temp->left,root->left);
}

template<class type>
node<type>* bstree<type>::copynode(node<type>* clone){
	node<type>* temp = new node<type>;
	temp -> key = clone ->key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

template<class type>
node<type>* bstree<type>::removeFindNew(node<type>* leaf){
	if(leaf != NULL && leaf->left != NULL){
		return removeFindNew(leaf->left);
	}
	else return leaf;
}

template<class type>
bool bstree<type>::remove(type key){
	node<type>* temp = search(key);

	if(temp != NULL){
		node<type>* replace = removeFindNew(temp->right);
		if(root == temp){
			if(temp->right == NULL){
				root = temp->left;
			}
			else{
				if(replace->right !=NULL)
					replace->parent->left = replace->right;
				else
					replace->parent->left = NULL;

				replace->right = root->right;
				replace->left = root->left;

				if(replace->left != NULL)
					replace->left->parent = replace;

				root = replace;
			}
		}
		else if(temp->right == NULL){
			if(temp->parent->right->key == temp->key)
				temp->parent->right = NULL;
			else
				temp->parent->left = NULL;
		}
		else if(temp->right->left == NULL){
			if(temp->parent->right->key == temp->key)
				temp->parent->right = replace;
			else
				temp->parent->left = replace;
			replace->left = temp->left;
			if(replace->left != NULL)
				replace->left->parent = replace;
		}
		else if(temp->right != NULL){

			if(replace->right !=NULL)
				replace->parent->left = replace->right;
			else
				replace->parent->left = NULL;

			if(temp->parent->right->key == temp->key)
				temp->parent->right = replace;
			else
				temp->parent->left = replace;

			replace->parent = temp->parent;
			replace->left = temp->left;
			replace->right = temp->right;
			replace->right->parent = replace;

			if(replace->left !=NULL)
				replace->left->parent = replace;
		}
		delete temp;
	}
	return (temp != NULL);
}

template<class type>
int bstree<type>::nodelvl(type key){
	int count = 0;
	node<type>* N = nodelvl(key,root,count);
	if(N == NULL)
		count = -1;
	return count;
}

template<class type>
node<type>* bstree<type>::nodelvl(type key, node<type>* leaf,int& count){
	  if(leaf!=NULL)
	  {
	    if(key==leaf->key)
	      return leaf;
	    if(key<leaf->key){
	    	count ++;
	      return nodelvl(key,leaf->left,count);
	    }
	    else{
	    	count ++;
	      return nodelvl(key,leaf->right,count);
	    }
	  }
	  else return NULL;
}
template<class type>
bstree<type>::bstree()
{
	root = NULL;
}

template<class type>
bstree<type>::~bstree()
{
	destroyTree();
}

template<class type>
void bstree<type>::destroyTree(node<type> *leaf)
{
  if(leaf!=NULL)
  {
    destroyTree(leaf->left);
    destroyTree(leaf->right);
    delete leaf;
  }
}

template<class type>
void bstree<type>::destroyTree()
{
  destroyTree(root);
}

template<class type>
void bstree<type>::insert(type key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node<type>;
    root->key=key;
    root->left=NULL;
    root->right=NULL;
    root->parent = NULL;
  }
}

template<class type>
void bstree<type>::insert(type key, node<type> *leaf)
{
  if(key< leaf->key)
  {
    if(leaf->left!=NULL)
      insert(key, leaf->left);
    else
    {
      leaf->left=new node<type>;
      leaf->left->key=key;
      leaf->left->left=NULL;
      leaf->left->right=NULL;
      leaf->left->parent = leaf;
    }
  }
  else if(key>=leaf->key)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node<type>;
      leaf->right->key=key;
      leaf->right->left=NULL;
      leaf->right->right=NULL;
      leaf->right->parent =leaf;
    }
  }
}

template<class type>
node<type> *bstree<type>::search(type key, node<type> *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key)
      return leaf;
    if(key<leaf->key)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

template<class type>
node<type> *bstree<type>::search(type key)
{
  return search(key, root);
}


#endif /* BTREE_H_ */
