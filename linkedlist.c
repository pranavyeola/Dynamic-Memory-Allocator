// linkedlist program which uses myalloc and myfree , own dynamic memory allocator functions

#include<stdio.h>
#include"myalloc.h"
struct node
{
	int data;
	struct node*next;
};
struct node*head=NULL;
struct node*last=NULL;
void insertEnd(int data)
{
	struct node*newnode=(struct node*)myalloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
		head=newnode;
	else
		last->next=newnode;
	last=newnode;
}
void display()
{
	struct node*start=head;
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
void delete(int key)
{
	int flag=0;
	struct node*start=head;
	if(start->data==key)
	{
		head=start->next;
		myfree(start);
		return;
	}
	while(start->next!=NULL)
	{
		if(start->next->data==key)
		{
			if(start->next->next)
			{
				start->next=start->next->next;
				myfree(start->next);
			}
			else
				start->next=NULL;
			flag=1;
			break;
		}
		else
			start=start->next;
	}
	if(flag==0)
		printf("\n\t Key to be daleted not found!!");

}

int main()
{
	int ch,data;
	do
	{
		
		printf("\n*******MENU********\n1.Insert\n2.Display\n3.Delete\n4.Exit");
		printf("\n\tEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n\t Enter data to insert");
			       scanf("%d",&data);
			       insertEnd(data);
			       break;
			case 2:display();
			       break;
			case 3:printf("\n\t Enter key to be deleted");
			       scanf("%d",&data);
			       delete(data);
			       break;
			case 4:return 0;
			default:printf("\n\tb Enter valid choice");
		}
	}while(ch>=1 && ch<=4);
	return 0;
}

