//
// Created by ravik on 12/19/2019.
//

#include "Tree.h"
#include <stack>
#include<queue>
/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */

namespace
{
    bool findNode(Node *node, int val){
        if (node == NULL)
            return false;
        if (node->data > val)
            return findNode(node->left, val);
        else if (node->data < val)
            return findNode(node->right, val);
        else
        {
            return true;
        }
    }
}


void TreeUtil::printPostorder(struct Node *node) {
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void TreeUtil::printInorder(struct Node *node) {
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void TreeUtil::printPreorder(struct Node *node) {
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

void TreeUtil::printInOrderUsingStack(Node *node) {
    if (node == NULL)
        return;
    else {
        stack<Node *> s;
        Node *temp = node;
        //s.push(node);
        while (!s.empty() || temp != NULL) {
            if (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            else{
                cout << s.top()->data << " ";
                temp = s.top()->right;
                s.pop();
            }
        }
    }
}

Node *TreeUtil::insert(Node *node, int val) {
    if (node == NULL) {
        return new Node(val);
    } else {
        if (node->data > val)
            node->left = TreeUtil::insert(node->left, val);
        else
            node->right = TreeUtil::insert(node->right, val);
    }
    return node;
}

void TreeUtil::findElement(Node *node, int val) {
    if (findNode(node, val))
        cout << "\nFound Element\n" << endl;
    else
        cout << "Element Not Found\n" << endl;
}

int TreeUtil::findMin(Node *node) {
    if (node == NULL)
        return -1; // ERROR Case
    while (node->left != NULL) {
        node = node->left;
    }
    return node->data;
}

Node *TreeUtil::deleteNode(Node *node, int val) {
    if (node == NULL)
        return NULL;
    if (node->data > val)
        node->left = TreeUtil::deleteNode(node->left, val);
    else if (node->data < val)
        node->right = TreeUtil::deleteNode(node->right, val);
    else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        } else if (node->left == NULL && node->right != NULL) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if (node->left != NULL && node->right == NULL) {
            Node *temp = node->left;
            delete node;
            return temp;
        } else {
            int minVal = findMin(node->right);
            node->data = minVal;
            deleteNode(node->right, minVal);
            return node;
        }
    }
}

Node *TreeUtil::copyTree(Node *node) {
    if (node == NULL)
        return NULL;
    else {
        Node *temp = new Node(node->data);
        temp->left = copyTree(node->left);
        temp->right = copyTree(node->right);
        return temp;
    }
}

void TreeUtil::deleteTree(Node *node) {
    if (node == NULL)
        return;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete(node);
    }
}

bool TreeUtil::identical(Node *node1, Node *node2) {
    if (node1 == NULL && node2 == NULL)
        return true;
    else if (node1 != NULL && node2 != NULL)
    {
        if (node1->data != node2->data)
            return false;
        else {
            bool isLeftIdentical = TreeUtil::identical(node1->left, node2->left);
            if (isLeftIdentical && TreeUtil::identical(node1->right, node2->right))
                return true;
            else
                return false;
        }
    }
    else
        return false;
}

bool TreeUtil::identicalStack(Node *node1, Node *node2) {
    if (node1 == NULL && node2 == NULL)
        return true;
    else if (node1 != NULL && node2 != NULL)
    {
        stack<Node*> t1;
        stack<Node*> t2;
        Node* temp1 = node1;
        Node* temp2 = node2;
        while(!t1.empty() && !t2.empty() || (temp1 != NULL && temp2 != NULL))
        {
            if (temp1 != NULL && temp2 != NULL) {
                t1.push(temp1);
                t2.push(temp2);
                if (temp1->data != temp2->data)
                    return false;
                else {
                    temp1 = temp1->left;
                    temp2 = temp2->left;
                }
            }
            else if (temp1 == NULL && temp2 == NULL)
            {
                temp1 = t1.top()->right;
                temp2 =  t2.top()->right;
                t1.pop();
                t2.pop();
            }
            else
                return false;
        }
        return true;
    }
    else
        return false;
}

int TreeUtil::KthSmallestStack(Node *node, int k) {
    stack<Node*> s;
    Node* temp = node;
    while (!s.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else{
            temp = s.top();
            --k;
            if (k == 0)
                return temp->data;
            temp = temp->right;
            s.pop();
        }
    }
    return -1; //Error
}
void TreeUtil::KthSmallest(Node* node, int& k, int& element){
    static bool isFound = false;
    if(node == NULL)
        return;
    else
    {
        KthSmallest(node->left, k, element);
        if (!isFound) {
            --k;
            //cout << "Element " << node->data << " " << k << endl;
            if (k == 0) {
                isFound = true;
                element = node->data;
            } else
                KthSmallest(node->right, k,element);
        }
    }
    return; //error
}

vector<Node*> TreeUtil::levelOrderTraversal(Node* node){
    queue<Node*> q;
    if (node == NULL)
        return vector<Node*>();
    q.push(node);
    vector<Node*> levelOrder;
    Node* temp = NULL;
    while(!q.empty())
    {
        temp = q.front();
        levelOrder.push_back(temp);
        q.pop();
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    return levelOrder;
}

void TreeUtil::verticalLines(Node* node, int h, map<int, vector<Node*>>& vl){
    if (node == NULL)
        return;
    else{
        vl[h].push_back(node);
        TreeUtil::verticalLines(node->left, h+1, vl);
        TreeUtil::verticalLines(node->right, h-1, vl);
    }
}

void TreeUtil::levelMap(Node* node, int h, map<int, vector<Node*>>& vl){
    if (node == NULL)
        return;
    else{
        vl[h].push_back(node);
        TreeUtil::levelMap(node->left, h+1, vl);
        TreeUtil::levelMap(node->right, h+1, vl);
    }
}

vector<Node*> TreeUtil::leftView(Node* node)
{
    int h = 0;
    map<int, vector<Node*>> vl;
    levelMap(node, h, vl);
    vector<Node*> answer;
    map<int, vector<Node*>>::iterator it = vl.begin();
    for(; it != vl.end(); ++it)
    {
        vector<Node*> v = it->second;
        answer.push_back(v[0]);
    }
    return answer;
}

vector<Node*> TreeUtil::rightView(Node* node)
{
    int h = 0;
    map<int, vector<Node*>> vl;
    levelMap(node, h, vl);
    vector<Node*> answer;
    map<int, vector<Node*>>::iterator it = vl.begin();
    for(; it != vl.end(); ++it)
    {
        vector<Node*> v = it->second;
        answer.push_back(v[v.size()-1]);
    }
    return answer;
}

bool TreeUtil::isValid(Node* root, int* leftVal, int* rightVal)
{
    if (root == NULL)
        return true;
    if (leftVal != NULL && root->data >= *leftVal)
        return false;
    if (rightVal != NULL && root->data <= *rightVal)
        return false;

    return TreeUtil::isValid(root->left, &root->data, rightVal) && TreeUtil::isValid(root->right, leftVal, &root->data);
}

vector<vector<int>> TreeUtil::AncestorMatrix(Node* node)
{
    map<int, vector<Node*>> level;
    levelMap(node, 0, level);
    map<int, vector<Node*>>::iterator it = level.begin();
    int numNode = 0;
    for (; it != level.end(); ++it)
    {
        vector<Node*> v = it->second;
        numNode += v.size();
    }
    vector<vector<int>> matrix(numNode, vector<int>(numNode, 0));
    vector<int> visited;
    it = level.begin();
    for (; it != level.end(); ++it)
    {
        vector<Node*> v = it->second;
        for (int i = 0; i<v.size(); ++i)
        {
            if(visited.empty())
            {
                visited.push_back(v[i]->data-1);
                for (int j = 0; j<numNode; ++j)
                    if (j != v[i]->data-1)
                        matrix[v[i]->data -1][j] = 1;
            }
            else{

                for (int k = 0; k < visited.size(); k++)
                        matrix[v[i]->data-1][visited[k]] = 1;

            }
            for (int j = 0; j<v.size(); ++j)
                visited.push_back(v[j]->data-1);
        }
    }
    return matrix;
}

bool TreeUtil::findElementBinaryTree(Node* node, Node* ele, stack<Node*>& s)
{
    if (node == NULL)
        return false;
    else{
        //cout << node->data << endl;
        if (node->data == ele->data)
        {
            return true;
        }
        else {
            s.push(node);
            //cout << node->data <<"Inside"<< endl;
            if (TreeUtil::findElementBinaryTree(node->left, ele, s))
                return true;
            if (TreeUtil::findElementBinaryTree(node->right, ele, s)) {
                return true;
            }
            s.pop();
            return false;
        }
        }
}

Node* TreeUtil::LowestCommonAncestor(Node* node , Node* p, Node* q)
{
    stack<Node*> ps;
    if (!TreeUtil::findElementBinaryTree(node, p, ps))
        return NULL;
    stack<Node*> qs;
    if (!TreeUtil::findElementBinaryTree(node, q, qs))
        return NULL;
    vector<Node*> psv(ps.size());
    vector<Node*> qsv(qs.size());
    int i = 0;
    while(!ps.empty())
    {
        psv[psv.size() - i - 1] = ps.top();
        ps.pop();
        i++;
    }
    i = 0;
    while(!qs.empty())
    {
        qsv[qsv.size() - i - 1] = qs.top();
        qs.pop();
        i++;
    }
    i = 0;
    while(1) {
        if (psv[i] != qsv[i])
            return psv[i-1];
        i++;
    }

}

int TreeUtil::height(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right) + 1;

    }
}

int TreeUtil::diameter(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        int ldia = diameter(node->left);
        int rdia = diameter(node->right);

        return max(lHeight + rHeight + 1, max(ldia,rdia));
    }
}

void
TreeUtil::leafNodes(Node* node, vector<Node*>& leafNode)
{
    if (node == NULL)
        return;
    else if (node->left == NULL && node->right == NULL)
    {
        leafNode.push_back(node);
    } else{
        TreeUtil::leafNodes(node->left, leafNode);
        TreeUtil::leafNodes(node->right, leafNode);
    }
}
