#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) {
		data = val;
        left = right = NULL;
	}
};

void Inorder(Node* root) {
	if(root) {
		cout<<root->data<<" ";
		Inorder(root->left);
		Inorder(root->right);
	}
}

int height(Node* root) {
	if(root == NULL) {
		return -1;
	}
	return max(height(root->left), height(root->right)) + 1;
}

void PrintKthNode(Node* root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 0) {
		cout<<root->data<<" ";
	}
	else {
	    PrintKthNode(root->left, k-1);
	    PrintKthNode(root->right,k-1);
    }
}

void levelordertraversal(Node* root) {
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		int count = q.size();
		for(int i = 0; i < count; i++) {
			Node* temp = q.front();
		    q.pop();
		    cout<<temp->data<<" ";
	     	if(temp->left) {
			    q.push(temp->left);
	    	}
	    	if(temp->right) {
		     	q.push(temp->right);
	    	}	
		}
		cout<<endl;
		
	}
	
}

int countNodes(Node* root) {
	if(root == NULL) {
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}

int maxElement(Node* root) {
	if(root == NULL) {
		return INT_MIN;
	}
	return max(root->data,max(maxElement(root->left),maxElement(root->right)));
}

int preindex = 0;
Node* cTree(int in[], int pre[], int st, int end) {
	if(st > end) {
		return NULL;
	}
	Node* root = new Node(pre[preindex++]);
	int index;
	for(int i = st; i <= end; i++) {
		if(in[i] == root->data) {
			index = i;
			break;
		}
	}
	root->left = cTree(in, pre, st, index-1);
	root->right = cTree(in, pre, index+1,end);
	return root;	
}

void sprialPrint(Node* root) {
	queue<Node*>q;
	q.push(root);
	bool reverse = false;
	stack<int>st;
	while(!q.empty()) {
		int count = q.size();
		for(int i = 0; i < count; i++) {
			Node* temp = q.front();
			q.pop();
			if(reverse) {
				st.push(temp->data);
			}
			else {
				cout<<temp->data<<" ";
			}
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}	
		}
		if(reverse) {
			while(!st.empty()) {
			cout<<st.top()<<" ";
			st.pop();	
		}
	}
		reverse = !reverse;
		cout<<endl;
}
}

void sprialPrint1(Node* root) {
	stack<Node*>st1;
	stack<Node*>st2;
	st1.push(root);
	while(!st1.empty() || !st2.empty()) {
		while(!st1.empty()) {
			Node* temp = st1.top();
			cout<<temp->data<<" ";
			st1.pop();
			if(temp->left) {
				st2.push(temp->left);
			}
			if(temp->right) {
				st2.push(temp->right);
			}
		}
		cout<<endl;
		while(!st2.empty()) {
			Node* temp = st2.top();
			cout<<temp->data<<" ";
			st2.pop();
			if(temp->right) {
				st1.push(temp->right);
			}
			if(temp->left) {
				st1.push(temp->left);
			}
		}
		cout<<endl;	
	}
}


bool childrensum(Node* root) {
	if(root == NULL) {
		return true;
	}
	if(root->left == NULL && root->right == NULL) {
		return true;
	}
	int sum = 0;
	if(root->left) {
		sum += root->left->data;
	}
	if(root->right) {
		sum += root->right->data;
	}
	
	bool l = childrensum(root->left);
	bool r = childrensum(root->right);
	return root->data == sum && l && r;
}

int main() {
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(60);
	root->left->right = new Node(70);
	root->right->left = new Node(50);
	root->right->right = new Node(40);
	//Inorder(root);
	//cout<<height(root);
	//PrintKthNode(root,2);
    //levelordertraversal(root);
    //cout<<countNodes(root);
    //cout<<maxElement(root);
    //int in[] = {20,10,40,30,50};
    //int pre[] = {10,20,30,40,50};
   //Node* root1 = cTree(in,pre,0,4);
   //levelordertraversal(root1);
   //sprialPrint1(root);
   //cout<<childrensum(root);
     

    
    
	return 0;
}
