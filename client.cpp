#include <stdio.h>
#include "List.h"

int main()
{
	int status = 0;
	list *plist = new list;
    plist->show();
    printf("\ncreate Link list of 5 nodes ");
	for(int i = 5; i> 0; i--)
	{
		plist->insert_start(i);
	}
	plist->show();

	printf("\n Inser node 7 at the end of the link list");
    plist->insert_End(7);
    plist->show();

    printf("\n Insert node 6 before node 7");
	plist->insert_before(7,6);
    plist->show();

	printf("\n Insert node 8 before node 7");
	plist->insert_after(7,8);
    plist->show();

    printf("\n remove start node");
	plist-> remove_start();
    plist->show();

	printf("\n remove start node");
    plist-> remove_start();
    plist->show();
   
    printf("\n remove end node");
 	plist-> remove_end();
 	plist->show();

    printf("\nRemove node before 7");
 	plist-> remove_Before(7);
 	plist->show();

 	printf("\nRemove node after 4");
 	plist-> remove_after(4);
	plist->show();

	printf("\nRemove node number 5");
	plist->remove_data(5);
	plist->show();
    
    printf("\nRemove node number 4");
	plist->remove_data(4);
	plist->show();

	plist->get_start(&status);
	printf("\nget_start = %d", status);

	plist->get_end(&status);
	printf("\nget_end = %d", status);

    plist->get_length();
    
    printf("\nfinal list after all operations");
	plist->show();

}