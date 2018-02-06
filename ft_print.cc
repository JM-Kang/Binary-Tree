/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.cc                                                              */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/18 20:18:41 by JianMing                                 */
/*   Updated: 2017/11/23 13:51:27 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "testing.h"

//print out the inorder of binary tree
void	inorder(Node *&node, ofstream &c_out)
{
	if(node == NULL)
		return;
	inorder(node->left, c_out);
	c_out << node->data << " ";
	inorder(node->right, c_out);
	return;
}

//print out the preorder of binary tree
void	preorder(Node *&node, ofstream &c_out)
{
	if(node == NULL)
		return;
	c_out << node->data << " ";
	preorder(node->left, c_out);
	preorder(node->right, c_out);
}

//print out the postorder of binary tree
void	postorder(Node *&node, ofstream &c_out)
{
	if(node == NULL)
		return;
	postorder(node->left, c_out);
	postorder(node->right, c_out);
	c_out << node->data << " ";
}

//print out the number of node at each children
void	NumNodeChildren(Node *&node, ofstream &c_out)
{
	if(node == NULL)  //no value, return back
		return;	
	NumNodeChildren(node->left, c_out);
	if(node->left == NULL && node->right == NULL)    //no sons
		c_out << "Node " << node->data << " has no children" << endl;
	else if(node->left == NULL && node->right != NULL)   //one child ( right )
		c_out << "Node " << node->data << " has 1 child" << endl;
	else if(node->left != NULL && node->right == NULL)   //one child ( left )
		c_out << "Node " << node->data << " has 1 child" << endl;
	else     //two children
		c_out << "Node " << node->data << " has 2 childdren" << endl;
	NumNodeChildren(node->right, c_out);
}

//print out all kind of information
void	printInfo(Node *&tree, ofstream &c_out)
{
	int	num = 0;
	c_out << "InOrder: ";
	inorder(tree, c_out);

	c_out << endl << "PreOrder: ";
	preorder(tree, c_out);

	c_out << endl << "PostOrder: ";
	postorder(tree, c_out);

	num = count(tree);
	c_out << endl << "The number of leaf in the tree is: " << num << endl;
	
	NumNodeChildren(tree, c_out);
	c_out << endl;
}

//check if the tree is empty
bool	treeEmpty(Node *&tree, ofstream &c_out)
{
	if(tree == NULL || tree->data == -999)   //the tree is empty
	{
		c_out << "This is empty tree" << endl << endl;
		return (true);
	}
	else
		return (false);
}
	
