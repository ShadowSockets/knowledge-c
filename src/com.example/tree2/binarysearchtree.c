#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct {
    Node *root;
} Tree;


void insert(Tree *tree, int value) {
    Node *node = malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL) {
        tree->root = node;
    } else {
        Node *temp = tree->root;
        while (temp != NULL) {
            if (value < temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = node;
                    return;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}

//先序遍历
void preorder(Node *node) {
    if (node != NULL) {
        printf("%d\n", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}


//中序遍历(它的顺序就是从小到大排序)
void inorder(Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d\n", node->data);
        inorder(node->right);
    }
}


//后续遍历
void postorder(Node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\n", node->data);
    }
}


//求指定节点高度
int get_height(Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        int left_h = get_height(node->left);
        int right_h = get_height(node->right);
        int max = left_h;
        if (right_h > max) {
            max = right_h;
        }
        return max + 1;
    }
}

//求一个树中所有节点中的最大值 （该树中所有节点的值都是正数，此方法才成立）
int get_maximum(Node *node) {
    if (node == NULL) {
        return -1;
    } else {
        int m1 = get_maximum(node->left);
        int m2 = get_maximum(node->right);
        int m3 = node->data;
        int max = m1;
        if(m2 > max) { max = m2; }
        if(m3 > max) { max = m3; }
        return max;
    }
}

int main() {

    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    Tree tree;
    tree.root = NULL;

    int i;
    for (i = 0; i < 7; i++) {
        insert(&tree, arr[i]);
    }


    inorder(tree.root);
    return 0;
}
