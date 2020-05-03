#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node{
	int v;
	struct node *next;
	struct node *prev;
}node;
node *head=NULL;
node*tail=NULL;
int main()
{
	int x,y;
	char c;
	node *temp;
	int size=0;
	do
	{
		scanf("%d",&x);
		node *value=(node *)malloc(sizeof(node));
		value->next=NULL;
		value->prev=NULL;
		value->v=x;
		temp=head;
		if(head==NULL)
		{	
			head=value;
			tail=value;
			size++;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=value;
			value->prev=temp;
			tail=value;
			size++;
		}
	}while(getchar()!=10);
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->v);
		temp=temp->next;
	}
	printf("\n");
	scanf("%d %c",&y,&c);
	y=y%size;
	temp=head;
	if(c=='R')
	{
		for(int i=0;i<(size-y-1);i++)
		{
			temp=temp->next;
		}
		node *temp2=temp->next;
		temp->next=NULL;
		temp=temp2;
		for(int i=0;i<y-1;i++)
		{
			temp=temp->next;
		}
		temp->next=head;
		head=temp2;
	}
	else if(c=='L')
	{
		for(int i=0;i<y-1;i++)
		{
			temp=temp->next;
		}
		node *temp2=temp->next;
		temp->next=NULL;
		temp=temp2;
		for(int i=0;i<(size-y-1);i++)
		{
			temp=temp->next;
		}
		temp->next=head;
		head=temp2;
	}

	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->v);
		temp=temp->next;
	}
	printf("\n");

}
