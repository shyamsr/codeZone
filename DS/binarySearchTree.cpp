#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

template <class T>
struct node {
  T data;
  struct node* left;
  struct node* right;
};


template <class T>
class BST{
  struct node<T> *root;
  
  void printInHelper(struct node<T> *root);
  T inorderSuccessorHelper(struct node<T> *root, T, bool&);
  bool checkBSTHelper(struct node<T> *root, T min, T max);

  public:
    void insert(T);
    void printInOrder();
    T findInorderSuccessor(T);
    bool checkBST();

    BST(){
      this->root = NULL;
    }

};

template <class T>
void BST<T>::insert(T val) {
  if(root == NULL) {
    root = new struct node<T>;
    root->left=NULL;
    root->right=NULL;
    root->data=val;
    return;
  }

  struct node<T> *iter=root;
  struct node<T> *temp_iter;

  while(iter!=NULL) {
    if(val > iter->data) {
      temp_iter = iter;
      iter = iter->right;
    } else {
      temp_iter = iter;
      iter = iter->left;
    }
  }

  iter = new struct node<T>;
  iter->left=NULL;
  iter->right=NULL;
  iter->data=val;

  if(val > temp_iter->data) {
    temp_iter->right = iter;
  } else {
    temp_iter->left = iter;
  }

  return;
}

template <class T>
void BST<T>::printInOrder() {
  printInHelper(root);
}

template <class T>
void BST<T>::printInHelper(struct node<T> *root) {
  if(root==NULL) return;
  printInHelper(root->left);
  cout<<root->data<<" ";
  printInHelper(root->right);

}

template <class T>
T BST<T>::findInorderSuccessor(T input) {
  struct node<T> *pred_1=NULL;
  struct node<T> *pred_2=NULL;
  struct node<T> *curr=root;

  while(curr!=NULL) {
    if(input == curr->data) break;

    if(pred_1==NULL&&pred_2==NULL) {
      pred_1 = curr;
    } else {
      pred_2=pred_1;
      pred_1=curr;
    }

    if(input > curr->data) {
      curr = curr->right;
    } else if(input < curr->data) {
      curr = curr->left;
    }

  }
  if(curr==NULL) { // error: input not present in Tree
    return -1;
  }

  struct node<T> *temp;
  if(curr->right!=NULL) {
    temp=curr->right;
    curr=curr->right;
    while(curr!=NULL) {
      temp = curr;
      curr=curr->left;
    }
    return temp->data;
  } else if(pred_1 == NULL) {
    return -1;
  } else if(pred_1->left==curr) {
    return pred_1->data;
  } else if(pred_2 !=NULL && pred_2->data >input) {
    return pred_2->data;
  }
  
  return -1;
}

template <class T>
bool BST<T>::checkBSTHelper(struct node<T> *root, T min, T max) {
  if(root == NULL) return true;

  bool isBST = (root->data < max) && (root->data >= min);

  if(isBST) {
    isBST = checkBSTHelper(root->left, min, root->data);
    if(isBST) {
      checkBSTHelper(root->right, root->data, max);
    }
  }
  return isBST;
}

template <class T>
bool BST<T>::checkBST() {

  T min = numeric_limits<T>::min();
  T max = numeric_limits<T>::max();
  return checkBSTHelper(root, min, max);

}


int main() {
  BST<int> mytree;
  mytree.insert(10);
  mytree.insert(8);
  mytree.insert(9);
  mytree.insert(3);
  mytree.insert(6);
  mytree.insert(15);
  mytree.printInOrder();
  cout<<mytree.findInorderSuccessor(15)<<endl;
  cout<<mytree.findInorderSuccessor(3)<<endl;
  cout<<mytree.findInorderSuccessor(8)<<endl;
  cout<<mytree.findInorderSuccessor(6)<<endl;
  if(mytree.checkBST()) {
    cout<<"true\n";
  } else {
    cout<<"false\n";
  }
  return 0;
}
