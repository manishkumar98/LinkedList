#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int ch;
	struct node *next;
}node;
int main()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	head->ch = 1e9 + 7;
	head->next = NULL;
	node *temp = head;
	int len = 0;
	do
	{
		int x;
		scanf("%d", &x);
		node *value;
		value = (node *)malloc(sizeof(node));
		value->ch = x;
		value->next = NULL;
		if(temp->ch != x) temp->next = value, temp = temp->next, len++;
	} while(getchar() != 10);
	printf("%d\n", len);
	temp = head->next;
	while(temp != NULL) printf("%d ", temp->ch), temp = temp->next;
}
