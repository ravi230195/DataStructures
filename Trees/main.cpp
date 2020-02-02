#include <iostream>
#include "Tree.h"
#include <vector>

using namespace TreeUtil;

namespace {
    template <typename T>
    void printVector(vector<T> v)
    {
        for (int i = 0 ; i<v.size(); i++)
        {
            cout<<v[i]->data<<" ";
        }
        cout<<endl;
    }
    template <typename T>
    void printMap(map<int, vector<Node*>> mp)
    {
        map<int, vector<Node*>>::iterator it = mp.begin();
        for (; it != mp.end(); ++it)
        {
            cout<<it->first<<": ";
            vector<T> v = it->second;
            for (int i = 0; i<v.size(); ++i)
            {
                cout<<v[i]->data<<" ";
            }
            cout<<endl;
        }
    }

    void printStack(stack<Node*>& s)
    {
        while(!s.empty())
        {
            cout<<s.top()->data<<" ";
            s.pop();
        }
        cout<<endl;
    }
    void print2DArray(vector<vector<int>> vect)
    {
        for (int i = 0; i < vect.size(); i++) {
            for (int j = 0; j < vect[i].size(); j++)
                cout << vect[i][j] << " ";
            cout << endl;
        }
    }

}
int main()
{

    Node* root = NULL;
    vector<int> treeNode{10,2,1,9,6,4,3,5,8,7,12,11,13};
    for (int i = 0; i<treeNode.size(); i++)
    {
        root = TreeUtil::insert(root, treeNode[i]);
    }

    cout << "\nPreorder traversal of binary tree is \n";
    TreeUtil::printPreorder(root);
    cout << "\nInorder traversal of binary tree is \n";
    TreeUtil::printInorder(root);
    cout << "\nInorder traversal of binary tree is \n";
    TreeUtil::printInOrderUsingStack(root);
    cout << "\nPostorder traversal of binary tree is \n";
    TreeUtil::printPostorder(root);

    findElement(root, 1);

    int min = TreeUtil::findMin(root);
    cout<<"Min Value \n"<<min<<endl;

    root = TreeUtil::deleteNode(root, 1);
    cout << "\nInorder traversal of binary tree is \n";
    TreeUtil::printInOrderUsingStack(root);

    Node* rootCpy = copyTree(root);
    cout << "\nInorder traversal of binary copy tree is \n";
    TreeUtil::printInOrderUsingStack(rootCpy);
    cout<<endl;
    TreeUtil::insert(rootCpy, 1);
    if(TreeUtil::identical(root, rootCpy))
        cout<<"Identical tree\n"<<endl;
    else
        cout<<"Identical Not tree\n"<<endl;
    if(TreeUtil::identicalStack(root, rootCpy))
        cout<<"Identical tree\n"<<endl;
    else
        cout<<"Identical Not tree\n"<<endl;

    int k = 6;
    int small = -1;
    KthSmallest(root, k, small);
    cout<<"Kth Smallest element is "<<small<<endl;

    vector<Node*> levelOrder = levelOrderTraversal(rootCpy);
    cout<<"level order traversal of the tree :"<<endl;
    printVector<Node*>(levelOrder);

    map<int, vector<Node*>> vertical;
    verticalLines(rootCpy, 0, vertical);
    cout<<"vertical View of the tree : "<<endl;
    printMap<Node*>(vertical);

    map<int, vector<Node*>> level;
    levelMap(rootCpy, 0, level);
    cout<<"Level order of the tree : "<<endl;
    printMap<Node*>(level);

    vector<Node*> leftV = leftView(rootCpy);
    cout<<"Left View of the tree : "<<endl;
    printVector(leftV);

    vector<Node*> rightV = rightView(rootCpy);
    cout<<"Right View of the tree : "<<endl;
    printVector(rightV);

    if (isValid(root, NULL, NULL))
        cout<<"Valid Binary Tree"<<endl;

    vector<vector<int>> matrix = AncestorMatrix(rootCpy);
    print2DArray(matrix);

    stack<Node*> ps;
    Node* p = new Node(7);
    findElementBinaryTree(rootCpy, p, ps);
    printStack(ps);
    Node* q = new Node(4);
    stack<Node*> qs;
    findElementBinaryTree(rootCpy, q, qs);
    printStack(qs);

    Node* ancestor = LowestCommonAncestor(rootCpy, p, q);
    if (ancestor != NULL)
        cout<<"Lowest Common ancestor "<<ancestor->data<<endl;
    else
        cout<<"No common ancestor"<<endl;

    cout<<"height of the tree "<<height(rootCpy)<<endl;
    cout<<"diameter of the tree "<<diameter(rootCpy)<<endl;

    vector<Node*> leafNode;
    leafNodes(rootCpy, leafNode);
    printVector<Node*>(leafNode);
    deleteTree(rootCpy);
    return 0;
}
