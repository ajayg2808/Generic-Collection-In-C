/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, academic projects, learning and any personal usage.
 */

/*  title: CompleteBinaryTree.h
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
		
*/

#include "BinaryTreeUtils.h"
#include "../Queue/Queue.h"

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

/*  Function: insertLevelOrder()
    Insert new *Tree Nodes* in level order. Filling levels.
    
    Parameters:
        BinaryTreeNode *root    - _BinaryTreeNode_ - *Tree* root pointer in which new *Tree Node* will be added.
        void *dataPtr           - Pointer to data for which new *Tree Node* will created.
        int level               - Level of *Tree Node* (1st parameter).
        int *inserted           - Flag to check *Tree Node* inserted or not.
	 
    Returns:
        BinaryTreeNode *		- _BinaryTreeNode_ pointer.

    See Also:
        <insertNode()> : Wrapper to <insertLevelOrder()>

*/
BinaryTreeNode *insertLevelOrder(BinaryTreeNode *root, void *dataPtr, int level, int *inserted)
{

    if (root == NULL)
    {
        *inserted = TRUE;
        return createNode(dataPtr);
    }
    if (level == 1)
    {
        return root;
    }
    else if (level > 1)
    {
        if (!*inserted)
            root->left = insertLevelOrder(root->left, dataPtr, level - 1, inserted);
        if (!*inserted)
            root->right = insertLevelOrder(root->right, dataPtr, level - 1, inserted);

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        return root;
    }
}

/*  Function: insertNode()
    Wrapper to <insertLevelOrder()>
    Insert new *Tree Node* in *Complete Binary Tree*.
    
    Parameters:
        BinaryTreeNode *root    - _BinaryTreeNode_ - *Tree* root pointer in which new *Tree Node* will be added.
        void *dataPtr           - Pointer to data for which new *Tree Node* will created.

    Returns:
        BinaryTreeNode *		- _BinaryTreeNode_ pointer.

    See Also:
        <deleteNode()>

*/
BinaryTreeNode *insertNode(BinaryTreeNode *root, void *dataPtr)
{
    int inserted = FALSE;
    if (root == NULL)
    {
        return (createNode(dataPtr));
    }
    else
    {
        root = insertLevelOrder(root, dataPtr, root->height, &inserted);

        if (!inserted)
        {
            BinaryTreeNode *p = root;
            while (p->left != NULL)
            {
                p = p->left;
            }
            p->left = createNode(dataPtr);
            root->height = updateHeight(root);
        }
    }

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
        BinaryTreeNode *ptr = root, *t = NULL, *nodeToDelete = NULL, *parentOfLastNode;
        Queue *queue = createEmptyQueue();
        enQueue(queue, (void *)ptr);
        while (!isEmpty(queue))
        {
            t = (BinaryTreeNode *)deQueue(queue);
            if (t->left != NULL)
            {
                enQueue(queue, (void *)(t->left));
            }

            if (t->right != NULL)
            {
                enQueue(queue, (void *)(t->right));
            }

            // Find 1st node with given key
            if ((*compare)(ptr->dataPtr, dataPtr) == 0 && nodeToDelete == NULL)
            {
                nodeToDelete = t;
            }
        }
        if (nodeToDelete == NULL)
        {
            printf(TREE_NODE_NOT_FOUND_FOR_DELETE);
            deleteQueue(queue);
            return root;
        }
        else
        {
            // Find parent of nodeToDelete
            enQueue(queue, (void *)ptr);
            while (!isEmpty(queue))
            {
                ptr = (BinaryTreeNode *)deQueue(queue);

                if (ptr->left == t || ptr->right == t)
                {
                    parentOfLastNode = ptr;
                    makeQueueEmpty(queue);
                    break;
                }
                if (ptr->left != NULL)
                {
                    enQueue(queue, (void *)(ptr->left));
                }

                if (ptr->right != NULL)
                {
                    enQueue(queue, (void *)(ptr->right));
                }
            }

            deleteQueue(queue);

            if (nodeToDelete == t)
            {
                if (nodeToDelete == root)
                {
                    free(nodeToDelete->dataPtr);
                    free(nodeToDelete);
                    root = NULL;
                }
                else if (parentOfLastNode->right == nodeToDelete)
                {
                    free(nodeToDelete->dataPtr);
                    free(nodeToDelete);
                    parentOfLastNode->right = NULL;
                }
                else
                {
                    free(nodeToDelete->dataPtr);
                    free(nodeToDelete);
                    parentOfLastNode->left = NULL;
                }
            }
            else
            {
                free(nodeToDelete->dataPtr);
                nodeToDelete->dataPtr = t->dataPtr;

                if (parentOfLastNode->right == t)
                {
                    parentOfLastNode->right = NULL;
                }
                else
                {
                    parentOfLastNode->left = NULL;
                }
                free(t);
            }

            printf(TREE_NODE_DELETE_SUCCESS);
        }
        if (root != NULL)
        {
            root->height = updateHeight(root);
        }
    }
    return root;
}
