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

void createTree(BTree* tree)
{
    char ch;
    cin >> ch;
    if(ch == '#')
        *tree = NULL ;
    else
    {
		*tree=(BTree)malloc(sizeof(BTree));
		if(!*tree)
			exit(0);
        (*tree)->data = ch;
        createTree(&(*tree)->leftTree);
        createTree(&(*tree)->rightTree);
    }
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
    printf("%c",tree->data);
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
	for(int i = 0; i < st.size()/sizeof(BTree); i ++)
    {
        BTree t = st.top();
        printf("%s",t->data);
		st.pop();
    }
}

void postOrderTraversal(BTree tree)
{
    if(isEmpty(tree))
        return;
    postOrderTraversal(tree->leftTree);
    postOrderTraversal(tree->rightTree);
    printf("%c",tree->data) ;
}

int main()
{
    BTree b = new BTNode;
	createTree(&b);
    postOrderTraversal(b);
}
