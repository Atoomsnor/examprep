/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarytree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:42:41 by roversch          #+#    #+#             */
/*   Updated: 2025/09/04 12:25:56 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
	int				value;
	struct s_tree	*right;
	struct s_tree	*left;	
}	t_tree;

int	biggestbinary(t_tree *root)
{
	int	left;
	int	right;

	if (root == 0)
		return (0);
	left = biggestbinary(root->left);
	right = biggestbinary(root->right);
	return (left + right + 1);
}

int	binary_tree_depth(t_tree *root)
{
	int leftdepth = 0;
	int rightdepth = 0;

	if (root == 0)
		return (0);
	leftdepth = binary_tree_depth(root->left);
	rightdepth = binary_tree_depth(root->right);
	if (leftdepth > rightdepth)
		return leftdepth + 1;
	else
		return rightdepth + 1;
}

int	biggest_value(t_tree *root)
{
	int	leftvalue;
	int	rightvalue;
	int	value;

	if (root == 0)
		return (0);
	leftvalue = biggest_value(root->left);
	rightvalue = biggest_value(root->right);
	
	value = root->value;
	if (leftvalue > value)
		value = leftvalue;
	if (rightvalue > value)
		value = rightvalue;
	return (value);
}

int	find_value(t_tree *root, int value)
{
	if (root == NULL)
		return 0;

	if (root->value == value)
		return 1;

	if (find_value(root->left, value))
		return 1;

	if (find_value(root->right, value))
		return 1;

	return 0;
}

int	main()
{
	t_tree *root = malloc(sizeof(t_tree));
	root->right = malloc(sizeof(t_tree));
	root->left = malloc(sizeof(t_tree));
	root->value = 7;

	root->right->right = 0;
	root->right->left = 0;
	root->right->value = 5;

	root->left->right = malloc(sizeof(t_tree));
	root->left->left = 0;
	root->left->value = 2;

	root->left->right->left = 0;
	root->left->right->right = 0;
	root->left->right->value = 20;
	
	printf("%i\n", find_value(root, 10));
}