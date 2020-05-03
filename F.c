#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int v;
	struct node *next;
	struct node *prev;
}node;
node *c(int x)
{
	node *value=(node *)malloc(sizeof(node));
	value->prev=NULL;
	value->v=x;
	value->next=NULL;
	return value;
}
node *head1=NULL,*head2=NULL,*head3=NULL;
int main()
{
	int x;node *temp1,*temp2,*temp,*temp3,*temp4; int count1=0,count2=0;
	do
	{
		scanf("%d",&x);
		if(head1==NULL)
		{
			head1=c(x);
			temp1=head1;
			count1++;
		}
		else
		{
			temp1->next=c(x);
			temp1->next->prev=temp1;
			temp1=temp1->next;
			count1++;
		}
	}while(getchar()!=10);
	do
	{
		scanf("%d",&x);
		if(head2==NULL)
		{
			head2=c(x);
			temp2=head2;
		}
		else
		{
			temp2->next=c(x);
			temp2->next->prev=temp2;
			temp2=temp2->next;

		}
	}while(getchar()!=10);
	/*temp1=head1;
	while(temp1!=NULL)
	{
		printf("%d ",temp1->v);
		temp1=temp1->next;
	}
	printf("\n");
	temp2=head2;
	while(temp2!=NULL)
	{
		printf("%d ",temp2->v);
		temp2=temp2->next;
	}
	printf("\n");*/
	/*int count=count1+count2;
	while((count1+count2)>0)
	{
		if(count1>0)
	{
		while(((temp1->v<temp2->v||count2==0)&&temp1!=NULL))
		{
			temp1=temp1->next;
		}
		temp=temp3;
		while(temp!=temp1&&count1>0)
		{
			count1--;
			printf("%d ",temp->v);
			temp=temp->next;

		}
		temp3=temp;
	}
	if(count2>0)
	{
		while(((temp2->v<temp1->v||count1==0)&&temp2!=NULL))
		{
			temp2=temp2->next;
		}
		temp=temp4;
		while(temp!=temp2&&count2>0)
		{
			count2--;
			printf("%d ",temp->v);
			temp=temp->next;
		}
		temp4=temp;
	}

	}*/
	temp1=head1;temp2=head2;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->v<=temp2->v)
		{
				if(head3==NULL)
			{
				head3=c(temp1->v);
				temp3=head3;
				
			}
			else
			{
				temp3->next=c(temp1->v);
				temp3->next->prev=temp3;
				temp3=temp3->next;
			}	
			temp1=temp1->next;
		}
		else
		{
				if(head3==NULL)
			{
				head3=c(temp2->v);
				temp3=head3;
				
			}
			else
			{
				temp3->next=c(temp2->v);
				temp3->next->prev=temp3;
				temp3=temp3->next;

			}	
			temp2=temp2->next;
		}
	}
	while(temp1!=NULL)
	{
		temp3->next=c(temp1->v);
				temp3->next->prev=temp3;
				temp3=temp3->next;
				temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		temp3->next=c(temp2->v);
				temp3->next->prev=temp3;
				temp3=temp3->next;
				temp2=temp2->next;
	}
	temp3=head3;
	while(temp3!=NULL)
	{
		printf("%d ",temp3->v);
		temp3=temp3->next;
	}
	printf("\n");
}
