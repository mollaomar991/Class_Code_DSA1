#include <iostream>
using namespace std;

class TreeNode
{
public:
    int key;
    TreeNode *parent;
    TreeNode *Right;
    TreeNode *left;
};

TreeNode *root = NULL;

void insertInBST(int v)
{
    TreeNode *z = new TreeNode();
    z->parent = NULL;
    z->Right = NULL;
    z->left = NULL;
    z->key = v;

    TreeNode *y = NULL;
    TreeNode *x = root;

    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->Right;
        }
    }

    z->parent = y;

    if (y == NULL)
    {
        root = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->Right = z;
    }
}

void preOrder(TreeNode *x)
{
    if (x != NULL)
    {

        printf("%d ", x->key);
        preOrder(x->left);
        preOrder(x->Right);
    }
}

void InOrder(TreeNode *x)
{
    if (x != NULL)
    {

        InOrder(x->left);
        printf("%d ", x->key);
        InOrder(x->Right);
    }
}

void PostOrder(TreeNode *x)
{
    if (x != NULL)
    {

        PostOrder(x->left);

        PostOrder(x->Right);
        printf("%d ", x->key);
    }
}

//TreeNode* findMin(TreeNode* node)
//{
//    while (node->left != NULL)
//    {
//        node = node->left;
//    }
//    return node;
//}
//
//TreeNode *findMax(TreeNode *node)
//{
//    while(node-> Right!= NULL)
//    {
//        node =node->Right;
//    }
//    return node;
//
//}
//

int Minimum( TreeNode*node)
{

    while (node->left != NULL)
    {
        node = node->left;

    }
    return node ->key;

}

int Maximum( TreeNode*node)
{

    while (node->Right != NULL)
    {
        node = node->Right;

    }
    return node ->key;

}
TreeNode* search(TreeNode* root, int key) {


    if (root == NULL || root->key == key)
        return root;


    if (root->key < key)
        return search(root->Right, key);


    return search(root->left, key);
}




int main()
{
    insertInBST(10);
    insertInBST(20);
    insertInBST(9);
    insertInBST(7);
    insertInBST(100);
    insertInBST(16);
    insertInBST(17);
    insertInBST(18);
    insertInBST(19);
    insertInBST(2);

    printf("PreOrder of the BST: ");
    preOrder(root);
    printf("\n");
    printf("\n");

    printf("InOrder of the BST: ");
    InOrder(root);
    printf("\n");
    printf("\n");

    printf("PostOrder of the BST: ");
    PostOrder(root);
    printf("\n");
    printf("\n");



    printf("Minimum value in the BST: %d\n", Minimum(root));
    printf("Maximum value in the BST: %d\n", Maximum(root));


//    TreeNode* minimum = findMin(root);
//    TreeNode* maximum = findMax(root);
//
//    printf("Minimum : %d\n", minimum->key);
//    printf("Maximum : %d\n", maximum->key);


    int key = 40;
    TreeNode* result = search(root, key);
    if (result != NULL) {
        printf"Node with key " << key << " found." << endl;
    } else {
        cout << "Node with key " << key << " not found." << endl;
    }


    return 0;
}
