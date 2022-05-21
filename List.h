#pragma once

class node{
	friend class list;
	private:
		
		int data;
		node* next;
		node(int val);
};


class list{
private:
	node* head_node;

    int is_node_Available(int data) const;
    node* search_Node(int data) const;
    void generic_insert_node(node*, node*, node*);
    void generic_Delete_node(node*, node*);

 public:
 	list();

 	int insert_start(int val);
 	int insert_End(int val);
 	int insert_before(int val, int new_val);
 	int insert_after(int val, int new_val);

 	int remove_start();
 	int remove_end();
 	int remove_Before(int val);
 	int remove_after(int val);
 	int remove_data(int val);

    int get_start(int *) ; //get start + remove
    int get_end(int* ) ; //get end + remove
    int get_length()const;

    int check_is_list_empty() const;
 	int show() const;
 	~list();
};