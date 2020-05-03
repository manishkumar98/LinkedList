#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
#define N 1000006
char a[N], b[N];
int main()
{
	scanf("%s", a);
	scanf("%s", b);
	int len1 = strlen(a), len2 = strlen(b), c = 0;
	node *head1, *head2, *head3;
	head1 = (node *)malloc(sizeof(node));
	head2 = (node *)malloc(sizeof(node));
	head3 = (node *)malloc(sizeof(node));
	head1->data = 1e6 + 7, head2->data = 1e6 + 7, head3->data = 1e6 + 7;
	head1->next = NULL, head2->next = NULL, head3->next = NULL;
	node *temp1 = head1, *temp2 = head2, *temp3 = head3, *temp;
	for(int i = len1 - 1; i >= 0; i--)
	{
		node *value;
		value = (node *)malloc(sizeof(node));
		value->data = a[i] - '0';
		value->next = NULL;
		temp1->next = value;
		temp1 = temp1->next;
	}
	for(int i = len2 - 1; i >= 0; i--)
	{
		node *value;
		value = (node *)malloc(sizeof(node));
		value->data = b[i] - '0';
		value->next = NULL;
		temp2->next = value;
		temp2 = temp2->next;
	}
	if (len1 > len2) temp = temp2;
	else temp = temp1;
	for(int i = 0; i < abs(len1 - len2); i++)
	{
		node *value;
		value = (node *)malloc(sizeof(node));
		value->data = 0;
		value->next = NULL;
		temp->next = value;
		temp = temp->next;
	}
	temp1 = head1->next, temp2 = head2->next;
	while(temp1 != NULL)
	{
		int sum = temp1->data ^ temp2->data ^ c;
		c = (temp1->data & temp2->data) | (temp2->data & c) | (c & temp1->data);
		node *value;
		value = (node *)malloc(sizeof(node));
		value->data = sum;
		value->next = NULL;
		temp3->next = value;
		temp1 = temp1->next, temp2 = temp2->next, temp3 = temp3->next;
	}
	temp3 = head3->next, head3 = NULL;
	while(temp3 != NULL)
	{
		temp = temp3->next;
		temp3->next = head3;
		head3 = temp3;
		temp3 = temp;
	}
	temp3 = head3;
	if (c) printf("%d", c);
	while(temp3 != NULL)
	{
		printf("%d", temp3->data);
		temp3 = temp3->next;
	}
}