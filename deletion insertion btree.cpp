#include <stdio.h> 
#include <stdlib.h> 
#include <queue>

using namespace std;

// A binary tree node containing data, left pointer and right pointer
struct bNode { 
	int data; // data
	struct bNode* left; // poiter to the left
	struct bNode* right; // pointer to the right
};

// newNode creator for tree nodes
struct bNode* bNewNode(int data) { 
	struct bNode* bNode = (struct bNode*) malloc(sizeof(struct bNode)); // allocating memory
	bNode -> data = data; // data
	bNode -> left = NULL; // poiter to the left
	bNode -> right = NULL; // pointer to the right
	
	return (bNode); 
} 

void insert(bNode ** tree, int val){
    bNode *root = NULL; // temp for creation if no root present
    
    if (!(*tree)) { // checking if tree is empty or not
        root = (bNode *) malloc (sizeof (bNode) ); // allocating memory
        root -> left = root -> right = NULL;
        root -> data = val;
        *tree = root;
        return;
    }

    if (val < (*tree) -> data) {
        insert(&(*tree) -> left, val); // insertion at left
    }
    else if (val > ((*tree) -> data)) {
        insert(&(*tree) -> right, val); // insertion at right
    }
}

// function to delete the entire tree
void deltree(bNode * tree){
    if (tree) { // checking if tree exists
        deltree(tree -> left);
        deltree(tree -> right);
        delete(tree);
    }
}

void deletDeepest(bNode* root, bNode* d_node){ 
    queue<struct bNode*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct bNode* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp -> right) { 
            if (temp -> right == d_node) { 
                temp -> right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp -> right); 
        } 
  
        if (temp -> left) { 
            if (temp -> left == d_node) { 
                temp -> left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp -> left); 
        } 
    } 
} 

//function for node deletion
bNode* deletion(bNode* root, int key) 
{ 
    if (root == NULL) // checking if tree is empty or not
        return NULL; 
  
    if (root -> left == NULL && root->right == NULL) { // if only root exists and root is not equal to key
        if (root -> data == key) 
            return NULL; 
        else
            return root; 
    } 
  
    queue <struct bNode*> q; 
    q.push(root); 
  
    struct bNode* temp; 
    struct bNode* key_node = NULL; 
  
    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp -> data == key) 
            key_node = temp; 
  
        if (temp -> left) 
            q.push(temp -> left); 
  
        if (temp -> right) 
            q.push(temp -> right); 
    } 
  
    if (key_node != NULL) { 
        int x = temp -> data; 
        deletDeepest(root, temp); 
        key_node -> data = x; 
    } 
    return root; 
} 

// function for post order traversal
void printPostorder(bNode* bNode) { 
	if (bNode == NULL) //empty tree
		return; 

	printPostorder(bNode -> left); // first recur on left subtree 

	printPostorder(bNode -> right); // then recur on right subtree 

	printf("%d ", bNode -> data); //printing each node data
} 

// function for inorder traversal
void printInorder(bNode* bNode) { 
	if (bNode == NULL)  // tree empty
		return; 

	printInorder(bNode -> left); // first recur on left child

	printf("%d ", bNode -> data); // then print the data of nod

	printInorder(bNode -> right); // now recur on right child
} 

// preorder traversal function
void printPreorder(bNode* bNode) { 
	if (bNode == NULL) // empty tree case
		return; 

	printf("%d ", bNode -> data); // first print data of node

	printPreorder(bNode -> left); // then recur on left sutree

	printPreorder(bNode -> right); // now recur on right subtree
}	 

void display(bNode* root){
	if (root == NULL) {
		return;
	}
    printf("\nPreorder traversal of binary tree is \n"); 
	printPreorder(root); 

	printf("\nInorder traversal of binary tree is \n"); 
	printInorder(root); 

	printf("\nPostorder traversal of binary tree is \n"); 
	printPostorder(root); 
	return;
}


int main() { 
	struct bNode *root = bNewNode(1); 
	root -> left = bNewNode(2); 
	root -> right	= bNewNode(3); 
	root -> left -> left = bNewNode(4); 
	root -> left -> right = bNewNode(5); 
	
	printf("\n current tree\n");
	display(root);
    
    insert(&root, 7);
    
    printf("\n\n\n tree after insertion\n");
    display(root);
    
    deletion(root, 5);
    
    printf("\n\n\n tree after deletion\n");
    display(root);
    
    //user interaction menu driven
    printf("\n\n Menu driven Program \n");
    int s = 3, val;
    while (s != 4) {
    	printf("\n\n 1. insert \n 2. delete \n 3. display \n 4. Exit \n\n");
    	scanf("%d", &s);
    	switch (s) {
    		case 1:
    			printf("Enter the data to be inserted");
    			scanf ("%d", &val);
    			insert(&root, val);
				break;
			case 2:
				printf("Enter value to be deleted");
				scanf ("%d", &val);
				deletion(root, val);
				break;
			case 3:
				display(root);
				break;
			case 4:
				break;
			default:
				printf("Entered a wrong key");
				break;
		}
	}
    
	return 0; 
} 

