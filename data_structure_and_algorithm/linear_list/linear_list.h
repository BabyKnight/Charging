/*
 * data_structure_and algorithm/linear_list/linear_list.h
 *
 * (C) Copyright 2021 - 2025 Vincent Hu
 *
 * Linear list related header file. 
 * Define the struct of Linked list and sequenatial list, and all related functions.
 *
 */

#ifndef __V_LINEAR_LIST_H__
#define __V_LINEAR_LIST_H__

#define LINEAR_LIST_CHAPTER_NAME "Linear List"
#define LINEAR_LIST_SEQUENATIAL_LIST "Sequenatial List"
#define LINEAR_LIST_LINKED_LIST "Linked List"
#define LINEAR_LIOST_DOUBLE_LINKED_LIST "Double Linked List"

enum linear_list_option{
		sequenatial_list,
		linked_list,
		double_linked_list
};

/*
 * Since this is only for practise and testing purpose
 * define the maxium number of element in list as 100
 */
#define MAX 100

struct sq_list_int{
		int data[MAX];
		int length;
};

struct l_node{
		int data;
		struct l_node *next;
};

struct dl_node{
		int data;
		struct dl_node *pri;
		struct dl_node *next;
};

#endif
