#include<stdio.h>
#include<stdlib.h>
typedef struct Nod
{
	int info;
	struct Nod *next;
}Node;
Node* start=NULL;
void Display()
{
	Node *temp;
	if(start == NULL)
	printf("list is Empty");
	else
	{
		temp=start;
		while(temp != NULL)
		{
			printf("Data=%d\n",temp->info);
			temp=temp->next;
		}
	}
}
void insertAtbeg()
{
	int data;
	Node *temp;
	temp=malloc(sizeof(Node));
	printf("\nEnter Number To be Inserted:");
	scanf("%d",&data);
	temp->info=data;
	temp->next=start;
	start=temp;
}
void insertAtend()
{
	int data;
	Node *temp, *head;
	temp=malloc(sizeof(Node));
	printf("\nEnter Number to Be Inserted:");
	scanf("%d",&data);
	temp->next=0;
	temp->info=data;
	head=start;
	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next=temp;
}
	void insertAtposition()
	{
		Node *temp,*newnode;
		int pos, data, i=1;
		newnode=malloc(sizeof(Node));
		printf("Enter position and data:");
		scanf("%d %d",&pos,&data);
		temp=start;
		newnode->info=data;
		newnode->next=0;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	void deleteEnd()
	{
		Node *temp, *prevnode;
		if(start==NULL)
		printf("\nList is empty\n");
		else
		{
			temp=start;
			while (temp->next!=0)
			{
				prevnode=temp;
				temp=temp->next;
			}
			
			free(temp);
			prevnode->next=0;
	}
}
void deleteFirst()
{
	Node* temp;
	if(start==NULL)
	printf("\nList is empty\n");
	else
	{
		temp=start;
		start=start->next;
		free(temp);
	}
}
void deletePosition()
{
	Node *temp, *position;
		int i=1,pos;
		if(start==NULL)
		printf("\nList is empty");
		else
		{
			printf("\nEnter index:");
			scanf("%d", &pos);
			position=malloc(sizeof(Node));
			temp=start;
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			position=temp->next;
			temp->next=position->next;
			free(position);
		}
}
	void main()
	{
		int choice;
		while(1)
		{
			printf("\n\t1 To see list");
			printf("\n\t2 To insert at front");
			printf("\n\t3 To insert at end");
			printf("\n\t4 To insert at any position");
			printf("\n\t6 To delete from first");
			printf("\n\t7 To delete from end");
			printf("\n\t8 To delete from any position");
			printf("\n\t5 To exit");
			printf("\nEnter Your Choice:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					Display();
					break;
					case 2:
						insertAtbeg();
						break;
						case 3:
							insertAtend();
							break;
							case 4:
								insertAtposition();
								break;
								case 5:
									exit(1);
									break;
									case 6:
										deleteFirst();
										break;
										case 7:
											deleteEnd();
											break;
											case 8:
												deletePosition();
												break;
									default:
										printf("Invalid Command");
				
			}
	}
	}
