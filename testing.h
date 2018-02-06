/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/18 19:38:41 by JianMing                                 */
/*   Updated: 2017/11/23 12:27:26 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TESTING_H
#define TESTING_H

#include "struct.h"

using namespace std;

Node	*getTree(ifstream&, Node*&, ofstream&);
Node	*Insert(Node*&, int);
Node	*GetNewNode(Node*&, int);
Node	*Delete(Node*&, int);
int		count(Node*&);
Node	*FindMin(Node *);
void	FreeNode(Node*&);
bool	treeEmpty(Node*&, ofstream&);

#endif
