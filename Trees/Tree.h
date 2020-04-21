//
// Created by ravik on 12/19/2019.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;


class Node
{
public:
    int data;
    Node* left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* A binary tree node has data, pointer to left child
and a pointer to right child */
namespace TreeUtil
{
//public:
     void  printPreorder( Node* node);
     void  printInorder( Node* node);
     void  printPostorder( Node* node);
     void  printInOrderUsingStack(Node* node);
     vector<int> preorderTraversalUsingStack(Node* root)
     Node* insert(Node* node, int val);
     Node* deleteNode(Node* node, int val);
     void findElement(Node *node, int val);
     int findMin(Node* node);
     Node* copyTree(Node* node);
     void deleteTree(Node* node);
     bool identical(Node* node1, Node* node2);
     bool identicalStack(Node* node1, Node* node2);
     int KthSmallestStack(Node* node, int k);
     void KthSmallest(Node* node, int& k, int& element);
     vector<Node*> levelOrderTraversal(Node* node);
     void verticalLines(Node* node, int h, map<int, vector<Node*>>& vl);
     void levelMap(Node* node, int h, map<int, vector<Node*>>& vl);
     vector<Node*> leftView(Node* node);
     vector<Node*> rightView(Node* node);
     bool isValid(Node* root, int* leftVal, int* rightVal);
     vector<vector<int>> AncestorMatrix(Node* node);
     bool findElementBinaryTree(Node* node, Node* ele, stack<Node*>& s);
     Node* LowestCommonAncestor(Node* node , Node* p, Node* q);
     int height(Node* node);
     int diameter(Node* node);
     void leafNodes(Node* node, vector<Node*>& leafNode);



};


#endif //TREES_TREE_H
