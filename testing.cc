/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/15 12:03:39 by JianMing                                 */
/*   Updated: 2017/11/23 13:39:16 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

//read in data and build in the tree 
Node	*getTree(ifstream &cin, Node *&tree, ofstream &c_out)
{
	int 	num = 0;
	char	type = ' ';

	while(cin.get(type))   //get the type before the set of numbers
	{
		if(type == '#')
			break;
	}
	cin >> num;
	c_out << "Set #" << num << endl;
	cin >> num;

	while(num != -999)   //do not put -999 into the tree
	{
		tree = Insert(tree, num);
		cin >> num;
	}
	return (tree);
}

//insert the new node into the tree
Node	*Insert(Node *&root, int num)
{
	if(root == NULL)   //put the new node into the root
		root = GetNewNode(root, num);
	else if(num < root->data)   //data should put into left subtree
		root->left = Insert(root->left, num);
	else if (num > root->data)   //data should put into to right subtree
		root->right = Insert(root->right, num);
	else  //the number invalid
		cout << "already existed\n";
	return (root);
}

//create the new node and put into the root
Node	*GetNewNode(Node *&node, int num)
{
	Node *newNode = new Node;
	newNode->data = num;
	newNode->left = newNode->right = NULL;
	return (newNode);
}

//calculate the number of node in the tree
int	count(Node *&node)
{
	if(node == NULL)   //empty node and return 0
		return (0);

	if(node->left == NULL && node->right == NULL)   //no sons then add 1 up
		return (1);

	else    //has 1 to 2 sons, add 1 up and goes to both subtrees
		return (1 + count(node->left) + count(node->right));
}

//Delete the nodes in the tree
Node	*Delete(Node *&root, int num)
{
	if(root == NULL)   //if no value, return back
		return (root);
	else if(num < root->data)  //data is in the left subtree
		root->left = Delete(root->left, num);
	else if(num > root->data)  //data is in the right subtree
		root->right = Delete(root->right, num);
	else 
	{
		if(root->left == NULL && root->right == NULL) //case 1: no children
		{
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) //case 2: one child ( right )
		{
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) //case 3: one child ( left )
		{
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else //case 4: two children
		{
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return (root);
}			

//find the minimum number in the substree
Node	*FindMin(Node *root)
{
	if(root == NULL) //no value return back
		return NULL;
	if(root->left) //minimum number is in the left
		return (FindMin(root->left));
	return (root);
}

//delete all the node and free the tree
void	FreeNode(Node *&leaf)
{
	if(leaf != NULL) //if the leaf has value, then delete 
	{
		FreeNode(leaf->left);
		FreeNode(leaf->right);
		delete leaf;
	}
}
