#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Node{
	Node *left , *right ;
	int height , data ;
	Node(){
		left = NULL , right = NULL ;
		height = data = 0 ;
	}

	Node(int x){
		left = NULL , right = NULL ;
		data = x ;
		height = 0 ;
	}
} ;

struct BST{
	Node* root ;
	BST(){
		root = NULL ;
	}
	void insert(int x){
		root = insert(x , root) ;
	}

	int height(Node* root){
		if(!root) return -1 ;
		return root->height ;
	}

	int bal(Node* root){
		return height(root->left) - height(root->right) ;
	}

	void setHeight(Node* root){
		root->height = max(height(root->left) , height(root->right)) + 1 ;
	}

	Node* insert(int x , Node* root){
		if(!root) {
			return new Node(x) ;
		}
		if(x > root->data){
			root->right = insert(x , root->right) ;
		} else {
			root->left = insert(x , root->left) ;
		}
		
		int bf = bal(root) ;
		if(bf > 1){
			if(x < root->left->data){ // ll
				return rightRotate(root) ;
			} else { //lr
				root->left = leftRotate(root->left) ;
				return rightRotate(root) ;
			}
		}
		if(bf < -1){
			if(x > root->right->data){
				return leftRotate(root) ;
			} else {
				root->right = rightRotate(root->right) ;
				return leftRotate(root) ;
			}
		}
		setHeight(root) ;
		return root ;
	}

	Node* rightRotate(Node* T){
		Node* W = T->left ;
		Node* a2 = W->right ;
		W->right = T ;
		T->left = a2 ;
		setHeight(T) ;
		setHeight(W) ;
		return W ;
	}
	
	Node* leftRotate(Node* T){
		Node* W = T->right ;
		Node* a2 = W->left ;
		W->left = T ;
		T->right = a2 ;
		setHeight(T) ;
		setHeight(W) ;
		return W ;
	}

	void inorder(Node* root){
		if(!root) return ;
		inorder(root->left) ;
		cout << root->data << " " ;
		inorder(root->right) ;
	}
	
	void display(Node* root , int parent = -1){
		if(!root) return ;
		cout << parent << " -> " << root->data << endl ;
		display(root->left , root->data) ;
		display(root->right , root->data) ;
	}

} ;

int32_t main(){
	BST tree ;
	for(int i = 0 ; i < 10 ; i++) tree.insert(i) ;
	tree.display(tree.root) ;
	return 0 ;
}

