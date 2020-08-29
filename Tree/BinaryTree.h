/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, academic projects, learning and any personal usage.
 */

/*  title: BinaryTree.h
    + _Author_      : *AJAY G.*
    + _Copyright_   : *AJAY G. - Code Stack 2020*
    
    
    About:
        *_1. Poiners_* 
        
            In *Binary Tree* all pointers are used which should have memory allocated by *malloc()/calloc()/realloc()* functions.
        
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

        *_3. print()_* 

            Used to print data pointed by data pointer in <QueueNode>.

            *Prototype*
            --- Code ---
            void print(const void * dataPtr);
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

/*  Function: insertNode()
    Insert new *Tree Node* in *Binary Tree*.
    
    Parameters:
        BinaryTreeNode *root    		- _BinaryTreeNode_ - *Tree* root pointer in which new *Tree Node* will be added.
        void *dataPtr           		- Pointer to data for which new *Tree Node* will created.
		void (*print)(const void *)     - Function to print data.
        --- Code ---
		void print(const void *,);
		--- 

    Returns:
        BinaryTreeNode *				- _BinaryTreeNode_ pointer.

    See Also:
        <deleteNode()>

*/
BinaryTreeNode *insertNode(BinaryTreeNode *root, void *dataPtr, void (*print)(const void *))
{
	int ch;
	if (root == NULL)
	{
		return (createNode(dataPtr));
	}
	else
	{
		BinaryTreeNode *ptr1 = root, *ptr2;
		do
		{

			printf("\n 1. Insert left to : ");
			(*print)(ptr1->dataPtr);
			printf("\n 2. Insert right to : ");
			(*print)(ptr1->dataPtr);
			printf("\n Enter your choice : ");
			scanf("%d", &ch);

			ptr2 = ptr1;
			if (ch == 1)
			{
				ptr1 = ptr1->left;
			}
			else if (ch == 2)
			{
				ptr1 = ptr1->right;
			}
			else
			{
				printf("\n INVALID CHOICE.....!!\n Please choose correct option.");
			}

		} while (ptr1 != NULL);
		if (ch == 1)
		{
			ptr2->left = createNode(dataPtr);
		}
		else if (ch == 2)
		{
			ptr2->right = createNode(dataPtr);
		}
	}
	//updateHeight(root);
	return root;
}

/*  Function: deleteNode()
    Delete *Tree Node* which data matches to data pointer.
    
    Parameters:
        BinaryTreeNode *root                            - _BinaryTreeNode_ - *Tree* root pointer from *Tree Node* will be deleted.
        void *dataPtr                                   - Pointer to data to search for *Tree Node* which should be deleted.
        int (*compare)(const void *, const void *)      - Compare function to compare data hold by dataPtr.
        --- Code ---
		int compare(const void *, const void *);
		---

    Returns:
        BinaryTreeNode *		                        - _BinaryTreeNode_ pointer. NULL if last *Tree Node* deleted.

    See Also:
        <searchNode()>

*/
BinaryTreeNode *deleteNode(BinaryTreeNode *root, void *dataPtr, int (*compare)(const void *, const void *))
{
	if (root != NULL)
	{
		int res = (*compare)(root->dataPtr, dataPtr);
		if (res == 0)
		{
			BinaryTreeNode *temp;
			if (root->left == NULL && root->right == NULL)
			{
				free(root->dataPtr);
				free(root);
				root = NULL;
			}
			else if (root->left == NULL || root->right == NULL)
			{
				temp = root->left ? root->left : root->right;
				free(root->dataPtr);
				free(root);
				root = temp;
			}
			else
			{
				temp = root->left;
				while (temp->right != NULL)
				{
					temp = temp->right;
				}
				temp->right = root->right;
				temp = root;
				root = temp->left;
				free(temp->dataPtr);
				free(temp);
			}
		}
		else
		{
			root->left = deleteNode(root->left, dataPtr, compare);
			root->right = deleteNode(root->right, dataPtr, compare);
		}
	}
	//updateHeight(root);
	return root;
}
