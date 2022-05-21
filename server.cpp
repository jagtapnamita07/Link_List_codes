#include "List.h"
#include<stdio.h>
#include <stdlib.h>

node::node(int val):data(val),next(0)
{
	
}

list::list()
{
	head_node = new node(0);
	head_node ->next = NULL;
}

int list::show() const
{
	int t = check_is_list_empty();
	if(t == 1)
	{
		printf("\n List is empty");
        return 0;
	}
	node* prun = this->head_node->next;
	node* ilist = 0;
	printf("\n[START] ->");
	for(ilist = prun; ilist!=NULL; ilist= ilist->next)
	{
		printf(" %d ->", ilist->data);
	}
	printf("[END]");
	return 1;
}

int list::insert_start(int val)
{   
   	this->generic_insert_node(this->head_node, new node(val),this->head_node->next); 
	return 1;
}
int list::insert_End(int val)
{   
	node* prun = 0;
	prun = this->head_node->next;
	while(prun->next!= NULL)
	{
		prun= prun->next;
	}
	
   	this->generic_insert_node(prun, new node(val),prun->next);
   	return 1;
}

int list::insert_before(int val, int new_val)
{   
	int t = this->is_node_Available(val);
	if(t == 1)
	{
		printf("\n Given node is not avilable in link list");
		return 0;
	}
	
	node* tempList = 0;
	node* prun = this->head_node->next;
	tempList = this->search_Node(val);
	
	while(prun->next!= tempList)
	{
		prun= prun->next;
	}
	
   	this->generic_insert_node(prun, new node(new_val),prun->next);
   
	return 1;
}

int list::insert_after(int val, int new_val)
{   
	int t = this->is_node_Available(val);
	if(t == 1)
	{
		printf("\n insert After Given node is not avilable in link list");
		return 0;
	}
	
	node* tempList = 0;
	node* prun = head_node->next;
	tempList = this->search_Node(val);
	
	while(prun!= tempList)
	{
		prun= prun->next;
	}
	
   	this->generic_insert_node(prun, new node(new_val),prun->next);
   
	return 1;
}
void list::generic_insert_node(node* pbeg, node* pmid , node* pend)
{   
	pmid->next = pend;
	pbeg->next = pmid;
}

int list::check_is_list_empty() const
{
	if(head_node->next!=NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int list::is_node_Available(int val) const
{
	node* temp_list = this->head_node->next;
	while(temp_list->next!=NULL)
	{
		temp_list = temp_list->next;
		
		if(temp_list->data == val)
		{   

			return 0;
		}
	}
	return 1;
	
}

node* list::search_Node(int val) const
{
	node* temp_list = this->head_node->next;

	while(temp_list->next!=NULL)
	{
		temp_list = temp_list->next;
		if(temp_list->data==val)
			break;
	}
        
		return temp_list;
}


int list::remove_start()
{
  generic_Delete_node(head_node,head_node->next);
  
  return 1;
}
int list::remove_end()
{
  node* prun  = this->head_node->next;
  //printf("\n remove end start generic delete :: %d %d", prun->data,head_node->next->data);
  while(prun->next->next!=NULL)
  {//printf("\n generic delete :: %d ", prun->next->data);
  	  	prun = prun->next;
  }

  generic_Delete_node(prun,prun->next);
  
  return 1;
}
int list::remove_Before(int val)
{
  int t = this->is_node_Available(val);
  if(t == 1)
  {
  	printf("\n node is not available");
  	return 0;
  }

  node* temp =0;
  temp = this->search_Node(val);
  node* prun  = this->head_node->next;
  while(prun->next->next!=temp)
  {	
  	prun= prun ->next;
  }
  
generic_Delete_node(prun,prun->next);

return 1;
 
}
int list::remove_after(int val)
{
	int t = this->is_node_Available(val);
  if(t == 1)
  {
  	printf("\n node is not available");
  	return 0;
  }

  node* temp =0;
  temp = this->search_Node(val);
  node* prun  = temp;
  generic_Delete_node(prun,prun->next);
  return 1;
}
int list::remove_data(int val)
{   
  int t = this->is_node_Available(val);
  if(t == 1)
  {
  	printf("\n node is not available");
  	return 0;
  }

  node* temp =0;
  temp = this->search_Node(val);
  
  node* prun  = this->head_node->next;
  while(prun->next!=temp)
  {
  	prun = prun->next;
  }

  generic_Delete_node(prun,prun->next);
	return 1;
}

void list::generic_Delete_node(node* pbeg, node* mid)
{
	pbeg->next = mid->next;
	delete mid;
	mid = 0;

}	

int list::get_start(int *n)
{ 
 node* prun = head_node->next;
 int t = this->check_is_list_empty();
 if(t==1)
 {
 	printf("\nList is empty");
 	return 0;
 }
 *n = prun->data;
 
 return 1;
}
int list::get_end(int* n) 
{
 node* prun = head_node->next;
 int t = this->check_is_list_empty();
 if(t==1)
 {
 	printf("\nList is empty");
 	return 0;
 }

 while(prun->next!=NULL)
 {
 	prun = prun->next;
 }
 *n = prun->data;
 return 1;
}

int list::get_length() const
{
 node* prun = head_node->next;
 int len = 0;
 while(prun!=NULL)
 {
 	len++;
  	prun =	prun->next;
 }

 printf("\n length = %d",len);

 return 1;
}
    

list::~list()
{
	node* prun;
	node* ptemp;
	for(prun = this->head_node->next; prun!=NULL; prun = ptemp)
	{
		ptemp = prun->next;
		delete(prun);
	}

	delete this->head_node;
	head_node = 0;

}