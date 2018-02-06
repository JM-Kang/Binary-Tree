/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.h                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/18 21:04:53 by JianMing                                 */
/*   Updated: 2017/11/23 10:38:19 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
#define FT_PRINT_H

#include "struct.h"

void	inorder(Node*&, ofstream&);
void	preorder(Node*&, ofstream&);
void	postorder(Node*&, ofstream&);
void	NumNodeChildren(Node*&, ofstream&);
void	printInfo(Node *&, ofstream&);

#endif
