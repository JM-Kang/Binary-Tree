/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.h                                                                 */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/15 10:55:48 by JianMing                                 */
/*   Updated: 2017/11/23 13:46:32 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int		data;
	Node	*right;
	Node	*left;
};

#endif
