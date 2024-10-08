#include <stdio.h>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* parent;
    TreeNode* right;
    TreeNode* left;
};

TreeNode *root = NULL;

void insertInBST(int v) {
    TreeNode *z = new TreeNode();
    z->parent = NULL;
    z->right = NULL;
    z->left = NULL;
    z->key = v;

    TreeNode *y = NULL;
    TreeNode *x = root;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void InOrder(TreeNode *node) {
    if (node != NULL) {
        InOrder(node->left);
        printf("%d ", node->key);
        InOrder(node->right);
    }
}

bool SearchInorder(TreeNode* node, int key) {
    if (node == NULL)
        return false;

    if (SearchInorder(node->left, key))
        return true;

    if (node->key == key) {
        printf("Found\n");
        return true;
    }

    return SearchInorder(node->right, key);
}

bool SearchPreorder(TreeNode* node, int key) {
    if (node == NULL)
        return false;

    if (node->key == key) {
        printf("Found\n");
        return true;
    }

    return (SearchPreorder(node->left, key) || SearchPreorder(node->right, key));
}

bool SearchPostorder(TreeNode* node, int key) {
    if (node == NULL)
        return false;

    if (SearchPostorder(node->left, key) || SearchPostorder(node->right, key))
        return true;

    if (node->key == key) {
        printf("Found\n");
        return true;
    }

    return false;
}

int Height(TreeNode* root) {
    if (root == NULL)
        return 0;

    int lHeight = Height(root->left);
    int rHeight = Height(root->right);

    return max(lHeight, rHeight)+1;
}

TreeNode* LCAinaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != NULL) {
        if (root->key > p->key && root->key > q->key)
            root = root->left;
        else if (root->key < p->key && root->key < q->key)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

void InorderSuccessor(TreeNode* root, TreeNode* key) {
    TreeNode* successor = NULL;

    while (root != NULL) {
        if (key->key >= root->key) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    if (successor != NULL) {
        printf("Inorder successor is: %d\n", successor->key);
    } else {
        printf("Inorder successor not found\n");
    }
}




int Minimum( TreeNode*node){

while (node->left != NULL)
   {
        node = node->left;

        }
   return node ->key;

}

int Maximum( TreeNode*node){

while (node->right != NULL)
   {
        node = node->right;

        }
   return node ->key;

}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Replace root's key with inorder successor's key
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}
// void InorderSuccessor(TreeNode*node,int key){
//   int array[100];
//   for(int i=0;i<100;i++){
//     array[i]=InOrder(root);
//   }

//   int n = 0;
//   while (array[n] != 0) {
//     n++;
//   }
  
//   for (int i = 0; i < n; i++) {
//     if (array[i] == key) {
//       if (i < n - 1) {
//         printf("Inorder successor of %d is %d\n", key, array[i + 1]);
//       } else {
//         printf("No inorder successor for %d (last element)\n", key);
//       }
//       return;
//     }
//   }
  
//   printf("Key %d not found in the tree\n", key);

// }




int main() {
    insertInBST(40);
    insertInBST(30);
    insertInBST(25);
    insertInBST(35);
    insertInBST(50);
    insertInBST(45);
    insertInBST(60);

    printf("InOrder Traversal: ");
    InOrder(root);
    printf("\n");

    printf("Searching 35 (Inorder): ");
    SearchInorder(root, 35);
    printf("\n");

    printf("Tree Height: %d\n", Height(root));

    TreeNode* p = new TreeNode();
    p->key = 25;
    TreeNode* q = new TreeNode();
    q->key = 60;
    TreeNode* lca = LCAinaBST(root, p, q);
    if (lca)
        printf("LCA of %d and %d is %d\n", p->key, q->key, lca->key);

    printf("Finding Inorder Successor of 45: ");
    TreeNode* key = new TreeNode();
    key->key = 45;
    InorderSuccessor(root, key);


    printf("Minimum value in the BST: %d\n", Minimum(root));
    printf("Maximum value in the BST: %d\n", Maximum(root));

    printf("Deleting node 30\n");
    root = deleteNode(root, 30);

    // Inorder Traversal after deletion
    printf("InOrder Traversal after deletion: ");
    InOrder(root);
    printf("\n");

    return 0;
}
