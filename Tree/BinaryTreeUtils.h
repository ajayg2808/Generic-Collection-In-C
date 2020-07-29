/**
 * @author Ajay G.
 * @copyright Ajay G. - Code Stack 2020
 * @desc This code can not be used for commercial purpose. 
 *       Can be used for educational, academic projects, learning and any personal usage.
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

        *_3. print()_* 

            Used to print data pointed by data pointer in <QueueNode>.

            *Prototype*
            --- Code ---
            void print(const void * dataPtr);
            ---
		
*/
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

#ifndef MATH_H
#define MATH_H <math.h>
#include MATH_H
#endif

/*  Defines: Boolean Values

    TRUE   - Used for true. 
    FALSE  - Used for false.
*/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*  Defines: Message Strings
    
    TREE_EMPTY_MSG                     - Info message for empty tree.
    TREE_NODE_NOT_FOUND_FOR_DELETE     - Info message for tree node search fail.
    TREE_NODE_DELETE_SUCCESS           - Info message for tree node deletion success.
*/
#define TREE_EMPTY_MSG "\n [INFO] : Tree is empty.\n"
#define TREE_NODE_NOT_FOUND_FOR_DELETE "\n [INFO] : Tree Node not found for deletion.\n"
#define TREE_NODE_DELETE_SUCCESS "\n [INFO] : Tree Node deleted successfully.\n"

/*	define: 
	SPACE_COUNT	- Space count increment value.
*/
#define SPACE_COUNT 10

/*  Function: max()
    Check maximum from given integer
    
    Parameters:
        int num2   	- 1st number.
		int num2   	- 2nd number.
	 
    Returns:
        int			- Maximum from inputs.

    See Also:
        <getHeight()>

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
        <getBalanceFactor()>

*/
int getHeight(BinaryTreeNode *ptr)
{
    if (ptr == NULL)
        return 0;
    return ptr->height;
}

/*  Function: updateHeight()
    Update height for every *Tree Node* in any *Binary Tree*.
    
    Parameters:
        BinaryTreeNode *ptr		- Pointer to root of *Tree* for which wanted to update height.
	 
    Returns:
        int						- Height of *Tree*.

    See Also:
        <getHeight()>

*/
int updateHeight(BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL)
        root->left->height = updateHeight(root->left);
    if (root->right != NULL)
        root->right->height = updateHeight(root->right);
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root->height;
}

/*  Function: createNode()
    Allocate memory for new *BinaryTreeNode* and assign data pointer to it.
    
    Parameters:
        void *dataPtr			- Pointer to data which would be stored in *Tree Node*.
	 
    Returns:
        BinaryTreeNode *		- Return pointer to newly created *BinaryTreeNode*.


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

/*  Function: searchNodeBST()
    Search *Tree Node* with given data in *Binary Tree*.
    
    Parameters:
        BinaryTreeNode *root						- Pointer to root node of tree in which we gonna search.
		void *dataPtr								- Pointer to data which need be searched in *Binary Tree*.
		int (*compare)(const void *, const void *)	- Compare function to compare data hold by dataPtr.
		--- Code ---
		int compare(const void *, const void *);
		--- 
	 
    Returns:
        int				- Return TREUE[1] if key is found, 
						  Otherwise return FALSE[0].

    See Also:
        <countTotalNodes()>
*/
int searchNodeBST(BinaryTreeNode *root, void *dataPtr, int (*compare)(const void *, const void *))
{
    if (root == NULL)
    {
        return FALSE;
    }

    if ((*compare)(dataPtr, root->dataPtr) < 0)
    {
        return searchNodeBST(root->left, dataPtr, compare);
    }
    else if ((*compare)(dataPtr, root->dataPtr) > 0)
    {
        return searchNodeBST(root->right, dataPtr, compare);
    }
    else
    {
        return TRUE;
    }
}

/*  Function: deleteTree()
    Delete *Binary Tree*. Deletes all the nodes in *Binary Tree*.
    Also delete all data pointers (Frees memory pointed by data pointer).
    
    Parameters:
        BinaryTreeNode *root			- Pointer to root node of tree, which we wanna delete.
	 
    Returns:
        BinaryTreeNode *				- Return NULL when tree is deleted successfully to avoid dangling pointer

    See Also:
        <countTotalNodes()>
*/
BinaryTreeNode *deleteTree(BinaryTreeNode *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            deleteTree(root->left);
        }
        if (root->right != NULL)
        {
            deleteTree(root->right);
        }
        free(root->dataPtr);
        free(root);
        root == NULL;
    }
    return root;
}

/*  Function: countTotalNodes()
    Count Total Nodes in *Binary Tree*.
    
    Parameters:
        BinaryTreeNode *root			- Pointer to root node of tree, which nodes we going to count.
	 
    Returns:
        int								- Count of nodes.

    See Also:
        <treeToArray()>
*/
int countTotalNodes(BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;

    int count = 1;

    count += (countTotalNodes(root->left) + countTotalNodes(root->right));

    return count;
}

/*  Function: treeToArray()
    Copy data pointer from every *Tree Node* to Array of pointer.
	All Nodes in *BInary Tree* is copied to Array given
    
    Parameters:
        BinaryTreeNode *root		- Pointer to root node of tree, which converted to array.
		int *array[]				- Array in which all data pointers are copied.
		int i						- index to array's last element.
	 
    Returns:
        int							- Total nodes copied in Array / Index to last element of array.

    See Also:
        <printInOrder()>
*/
int treeToArray(BinaryTreeNode *root, int *array[], int i)
{
    if (root == NULL)
        return i;

    if (root->left != NULL)
        i = treeToArray(root->left, array, i);

    array[i] = (int *)root->dataPtr;
    i++;

    if (root->right != NULL)
        i = treeToArray(root->right, array, i);

    return i;
}

/*  Function: printInOrder()
    Print inorder traversal of *Binary Tree*.
    
    Parameters:
        BinaryTreeNode *root			- Pointer to root node of tree, which nodes we going to print.
		void (*print)(const void *)     - Function to print data.
	 
    See Also:
        <print2D()>
*/
void printInOrder(BinaryTreeNode *root, void (*print)(const void *))
{
    if (root != NULL)
    {
        printInOrder(root->left, print);
        (*print)(root->dataPtr);
        printInOrder(root->right, print);
    }
}

/*  Function: print2DUtil()
    Print 2D represenatation of *Binary Tree*.
	Print *Binary Tree* in _horizontal_ manner.
	It is compatible with any size of tree.
    
    Parameters:
        BinaryTreeNode *root			- Pointer to root node of tree.
		int space						- Space count to print empty space.
										  It will automatically get incremented with every level.
		void (*print)(const void *)     - Function to print data.
	 
    See Also:
        <print2D>	: Wrapper over <print2DUtil()>
*/
void print2DUtil(BinaryTreeNode *root, int space, void (*print)(const void *))
{
    int i;
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += SPACE_COUNT;

    // Process right child first
    print2DUtil(root->right, space, print);

    // Print current node after space
    // count
    printf("\n");
    for (i = SPACE_COUNT; i < space; i++)
        printf(" ");
    (*print)(root->dataPtr);
    printf("\n");

    // Process left child
    print2DUtil(root->left, space, print);
}

/*  Function: print2D()
	*Wrapper over <print2DUtil()>*
    Print 2D represenatation of *Binary Tree*.
	Print *Binary Tree* in _horizontal_ manner.
	It is compatible with any size of tree.
    
    Parameters:
        BinaryTreeNode *root			- Pointer to root node of tree.
		void (*print)(const void *)     - Function to print data.
	 
    See Also:
        <print2D()>	: Wrapper over print2DUtil()
*/
void print2D(BinaryTreeNode *root, void (*print)(const void *))
{
    // Pass initial space count as 0
    print2DUtil(root, 0, print);
}

/*  Function: printGivenLevel()
    Prints physical appearance of *Tree* using provided *void print(const void *dataPtr)* function.
    
    Parameters:
        BinaryTreeNode *root            - Pointer to *root* of tree
        int level                       - Level of tree node
        double space                    - Space count to print empty spaces.
        void (*print)(const void *)     - Function to print data.

    See Also:
        <printLevelOrder()>

*/
void printGivenLevel(BinaryTreeNode *root, int level, double space, void (*print)(const void *))
{
    int i;
    if (root == NULL)
    {
        for (i = 0; i < space / 2; i++)
            printf(" ");
        printf(" ");
        for (i = 1; i < space / 2; i++)
            printf(" ");
        return;
    }
    if (level == 1)
    {
        for (i = 0; i < space / 2; i++)
            printf(" ");
        (*print)(root->dataPtr);
        for (i = 2; i < space / 2; i++)
            printf(" ");
    }
    else if (level > 1)
    {
        space /= 2;
        printGivenLevel(root->left, level - 1, space, print);
        printGivenLevel(root->right, level - 1, space, print);
    }
}

/*  Function: printLevelOrder()
    Print 2D represenatation of *Binary Tree*.
	Print *Binary Tree* in _vertical_ manner.
	It is not compatible with bigger size of tree.
    
    Parameters:
        BinaryTreeNode *root            - Pointer to *root* of tree
        void (*print)(const void *)     - Function to print data.

    See Also:
        <printInOrder()>

*/
void printLevelOrder(BinaryTreeNode *root, void (*print)(const void *))
{
	if(root == NULL)
	{
		printf(TREE_EMPTY_MSG);
		return;
	}
    int h = root->height;
    int i;
    double space = (pow(2, h - 2) * 3) / 2 * 8;

    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, space, print);
        printf("\n\n\n");
    }
}

/*  Function: getMinValueNode()
    Return Return *Tree Node* with minimum value from given tree.
    
    Parameters:
        BinaryTreeNode *root	- Pointer of root element of *Binary Tree*
	 
    Returns:
        BinaryTreeNode *		- _BinaryTreeNode_ with minimum value.

    See Also:
        <getMaxValueNode()>

*/
BinaryTreeNode *getMinValueNode(BinaryTreeNode *root)
{
    BinaryTreeNode *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

/*  Function: getMaxValueNode()
    Return Return *Tree Node* with maximum value from given tree.
    
    Parameters:
        BinaryTreeNode *root	- Pointer of root element of *Binary Tree*
	 
    Returns:
        BinaryTreeNode *		- _BinaryTreeNode_ with maximum value.

    See Also:
        <getMinValueNode()>

*/
BinaryTreeNode *getMaxValueNode(BinaryTreeNode *root)
{
    BinaryTreeNode *current = root;

    while (current->right != NULL)
        current = current->right;

    return current;
}
