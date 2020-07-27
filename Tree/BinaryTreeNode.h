/**
 * @author AJAY G.
 * @copyright AJAY G. - Code Stack 2020
 */
/*  title: BinaryTreeNode.h
    + _Author_      : *AJAY G.*
    + _Copyright_   : *AJAY G. - Code Stack 2020*
	.
		
*/
/*  Struct: BinaryTreeNode
    *Binary Tree Node* with _data_, _left_, _right_ and _height_ field. 

    --- Code ---
    typedef struct BinaryTreeNode
	{
		void *dataPtr;
		struct BinaryTreeNode *left;
		struct BinaryTreeNode *right;
		int height;

	} BinaryTreeNode;
*/
typedef struct BinaryTreeNode
{
	// Var: void *dataPtr
	// Used to store data pointer.
	void *dataPtr;
	// Var: struct BinaryTreeNode *left
	// Pointer to left subtree.
	struct BinaryTreeNode *left;
	// Var: struct BinaryTreeNode *right
	// Pointer to right subtree.
	struct BinaryTreeNode *right;
	// Var: height
	// Holds the height of node in the tree.
	int height;
} BinaryTreeNode;