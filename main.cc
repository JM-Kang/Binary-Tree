/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/14 17:10:18 by JianMing                                 */
/*   Updated: 2017/11/23 13:08:10 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_print.h"
#include "testing.h"

int	main(void)
{
	ifstream	f_cin;
	ofstream	f_out;
	Node		*tree;
	int			info;
	string		str;
	f_cin.open("data.txt");
	f_out.open("statement.txt");

	while(f_cin)
	{
		tree = NULL;
		//build the tree
		tree = getTree(f_cin, tree, f_out);

		//Check if the tree is empty
		if(!treeEmpty(tree, f_out))
			printInfo(tree, f_out);
		f_cin >> str;

		//using while loop to read in instructions
		while(str != "Set")
		{
			f_cin >> info;
			if(str == "Delete")
				tree = Delete(tree, info);
			else
				tree = Insert(tree, info);
			f_cin >> str;
		}

		//check if the tree is empty after instructions
		if(!treeEmpty(tree, f_out))
			printInfo(tree, f_out);
		FreeNode(tree);
	}
	f_cin.close();
	f_out.close();
	return (0);
}	
