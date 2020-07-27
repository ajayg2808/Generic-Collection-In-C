/**
 * @author AJAY G.
 * @copyright AJAY G. - Code Stack 2020
 */
/*  title: AVL_Tree.h
    + _Author_      : *AJAY G.*
    + _Copyright_   : *AJAY G. - Code Stack 2020*
    
    
    About:
        *_1. Poiners_* 
        
            In *AVL Tree* all pointers are used which should have memory allocated by *malloc()/calloc()/realloc()* functions.
        
            It is useful for _dynamic memory management_.
    
        *_2. compare()_* 

            Used to compare data pointed by data pointer in <BinaryTreeNode>.

            *Prototype*
            --- Code ---
            int compare(const void * var1, const void * var2);
        
            if var1.value > var1.value
                return value should be > 0
        
            if var1.value < var1.value 
                return value should be < 0
        
            if var1.value == var1.value 
                return value should be 0
            ---
		
*/
#include "BinaryTreeUtils.h"

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H "BinaryTreeNode.h"
#include BINARY_TREE_NODE_H
#endif

#ifndef STDIO_H
#define STDIO_H <stdio.h>
#include STDIO_H
#endif

#ifndef STDLIB_H
#define STDLIB_H <stdlib.h>
#include STDLIB_H
#endif

/*	About: Thread Safety
	Something

*/

/*  Function: max()
    Check maximum from given integer
    
    Parameters:
        int num2   	- 1st number.
		int num2   	- 2nd number.
	 
    Returns:
        int			- Maximum from inputs.

    See Also:
        <getHeight>

*/
int max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

/*  Function: getHeight()
    Return height of *Tree Node* in tree.
    
    Parameters:
        BinaryTreeNode *ptr		- _BinaryTreeNode_ which hieght should be returned.
	 
    Returns:
        int						- Height of node.

    See Also:
        <getBalanceFactor>

*/
int getHeight(BinaryTreeNode *ptr)
{
	if (ptr == NULL)
		return 0;
	return ptr->height;
}

/*  Function: getBalanceFactor()
    Return _Balance Factor_ of *Tree Node* in tree.
    
    Parameters:
        BinaryTreeNode *ptr		- _BinaryTreeNode_ which height should be returned.
	 
    Returns:
        int						- _Balance Factor_ of node.

    See Also:
        <getHeight>

*/
int getBalanceFactor(BinaryTreeNode *ptr)
{
	if (ptr == NULL)
		return 0;
	return getHeight(ptr->left) - getHeight(ptr->right);
}

/*  Function: rightRotate()
    Right Rotation for balancing tree.
    
    Parameters:
        BinaryTreeNode *ptr			- Pointer to root of unbalanced sub tree.
	 
    Returns:
        BinaryTreeNode *			- Return pointer to new root pointer of balanced sub tree.

    See Also:
        <leftRotate>

*/
BinaryTreeNode *rightRotate(BinaryTreeNode *ptr)
{
	BinaryTreeNode *ptrLeft = ptr->left;
	BinaryTreeNode *pLRight = ptrLeft->right;

	ptrLeft->right = ptr;
	ptr->left = pLRight;

	ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
	ptrLeft->height = max(getHeight(ptrLeft->left), getHeight(ptrLeft->right)) + 1;

	return ptrLeft;
}

/*  Function: leftRotate()
    Left Rotation for balancing tree.
    
    Parameters:
        BinaryTreeNode *ptr			- Pointer to root of unbalanced sub tree..
	 
    Returns:
        BinaryTreeNode *			- Return pointer to new root pointer of balanced sub tree.

    See Also:
        <rightRotate>

*/
BinaryTreeNode *leftRotate(BinaryTreeNode *ptr)
{
	BinaryTreeNode *ptrRight = ptr->right;
	BinaryTreeNode *pRLeft = ptrRight->left;

	ptrRight->left = ptr;
	ptr->right = pRLeft;

	ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
	ptrRight->height = max(getHeight(ptrRight->left), getHeight(ptrRight->right)) + 1;

	return ptrRight;
}

/*  Function: createNode()
    Allocate memory for new *BinaryTreeNode* and assign data pointer to it.
    
    Parameters:
        void *dataPtr			- Pointer to data which would be stored in *Tree Node*.
	 
    Returns:
        BinaryTreeNode *		- Return pointer to newly created *BinaryTreeNode*.

    See Also:
        <insertNode>

*/
BinaryTreeNode *createNode(void *dataPtr)
{
	BinaryTreeNode *node = (BinaryTreeNode *)
		malloc(sizeof(BinaryTreeNode));
	node->dataPtr = (void *)dataPtr;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

/*  Function: insertNode()
    Add new *Tree Node* into *AVL Tree*.
    
    Parameters:
        BinaryTreeNode *root						- Pointer to root node of tree in which we wanna add new *Tree Node*.
		void *dataPtr								- Pointer to data which would be stored in new *Tree Node*.
		int (*compare)(const void *, const void *)	- Compare function to compare data hold by dataPtr.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        BinaryTreeNode *							- Return new root pointer of balanced tree.

    See Also:
        <deleteNode>

*/
BinaryTreeNode *insertNode(BinaryTreeNode *root, void *dataPtr, int (*compare)(const void *, const void *))
{
	// Find the correct position to insertNode the node and insertNode it
	if (root == NULL)
	{
		return (createNode(dataPtr));
	}

	int compResult = (*compare)(dataPtr, root->dataPtr);

	if (compResult < 0)
	{
		root->left = insertNode(root->left, dataPtr, compare);
	}
	else if (compResult > 0)
	{
		root->right = insertNode(root->right, dataPtr, compare);
	}
	else
	{
		return root;
	}
	// Update the balance factor of each node and Balance the tree
	root->height = 1 + max(getHeight(root->left),
						   getHeight(root->right));

	int balance = getBalanceFactor(root);

	if (balance > 1 && (*compare)(dataPtr, root->left->dataPtr) < 0)
	{
		return rightRotate(root);
	}

	if (balance < -1 && (*compare)(dataPtr, root->right->dataPtr) > 0)
	{
		return leftRotate(root);
	}

	if (balance > 1 && (*compare)(dataPtr, root->left->dataPtr) > 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && (*compare)(dataPtr, root->right->dataPtr) < 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

/*  Function: deleteNode()
    Delete *Tree Node* from *AVL Tree* with data witch matches to given data.
    
    Parameters:
        BinaryTreeNode *root						- Pointer to root node of tree in which deletetion *Tree Node* will done.
		void *dataPtr								- Pointer to data which would be deleted from *AVL Tree*.
		int (*compare)(const void *, const void *)	- Compare function to compare data hold by dataPtr.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        BinaryTreeNode *							- Return new root pointer of balanced tree.

    See Also:
        <insertNode>

*/
BinaryTreeNode *deleteNode(BinaryTreeNode *root, void *dataPtr, int (*compare)(const void *, const void *))
{
	// Find the node and delete it
	if (root == NULL)
		return root;

	int compResult = (*compare)(dataPtr, root->dataPtr);

	if (compResult < 0)
	{
		root->left = deleteNode(root->left, dataPtr, compare);
	}
	else if (compResult > 0)
	{
		root->right = deleteNode(root->right, dataPtr, compare);
	}

	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			BinaryTreeNode *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				root = temp;
			}
			free(temp);
		}
		else
		{
			BinaryTreeNode *temp = getMinValueNode(root->right);

			root->dataPtr = temp->dataPtr;

			root->right = deleteNode(root->right, temp->dataPtr, compare);
		}
	}

	if (root == NULL)
		return root;

	// Update the balance factor of each node and Balance the tree
	root->height = 1 + max(getHeight(root->left),
						   getHeight(root->right));

	int balance = getBalanceFactor(root);
	if (balance > 1 && getBalanceFactor(root->left) >= 0)
	{
		return rightRotate(root);
	}

	if (balance > 1 && getBalanceFactor(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalanceFactor(root->right) <= 0)
	{
		return leftRotate(root);
	}

	if (balance < -1 && getBalanceFactor(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


