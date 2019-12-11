#include <iostream>
#include <stack>
#include <queue>

using namespace std;
typedef struct BTNode* BTree;
struct BTNode
{
    char data;
    BTree leftTree;
    BTree rightTree;
};

BTree createTree()
{
	BTree tree = new BTNode;
    char exp;
    cin >> exp;
    if(exp == '#')
        tree = NULL ;
    else
    {
        tree->data = exp;
        tree->leftTree = createTree();
        tree->rightTree = createTree();
    }
	return tree;
}

bool isEmpty(BTree tree)
{
    if(tree == NULL)
        return true;
    return false;
}

void preOrderTraversal(BTree tree)
{
    if(isEmpty(tree))
        return;
    printf("%s",tree->data);
    preOrderTraversal(tree->leftTree);
    preOrderTraversal(tree->rightTree);
}

void preOrderTraversal2(BTree tree)
{
    if(isEmpty(tree))
        return;
    BTree b = tree;
    stack<BTree> st;
    st.push(b);
    BTree top = st.top();
    printf("%s",top->data);
    st.pop();
    while(!isEmpty(b->rightTree))
    {
        b = b->rightTree;
        st.push(b);
    }
    while(!isEmpty(b->leftTree))
    {
        b = b->leftTree;
        st.push(b);
    }
    /*for(stack<BTree>::iterator it = st.begin(); it != st.end(); it++)
    {
        BTree t = *it;
        printf("%s",t->data);
    }*/
}

void postOrderTraversal(BTree tree)
{
    if(isEmpty(tree))
        return;
    preOrderTraversal(tree->leftTree);
    preOrderTraversal(tree->rightTree);
    printf("%s",tree->data);
}

int main()
{
    BTree b =  createTree();
    postOrderTraversal(b);
}
