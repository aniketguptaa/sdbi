#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *p = NULL;

void append(struct node**);
void add_beg(struct node**);
void display(struct node*);
void add_mid(struct node**);

int main()
{
	int ch;
	while(1)
	{
		printf("\nSingle linked list operation\n\n");
		printf("1.Append\n");
		printf("2.Add at begin\n");
		printf("3.Add at after\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: append(&p);
					break;
					
			case 2: add_beg(&p);
					break;
			
			case 3: add_mid(&p);
					break;
			
			case 4: display(p);
					break;		
			
			case 5: exit(1);
					break;
			
			default: printf("Invalid input");
		}
	}
	
	return 0;
}

void append(struct node **q)
{
	struct node *temp, *r;
	temp =  *q;
	r = (struct node *)malloc(sizeof(struct node));
	printf("Enter a node data: ");
	scanf("%d",&r->data);
	r -> link = NULL;
	if(*q == NULL)
	{
		*q = r;
		return;
	}
	else{
		while(temp -> link!=NULL)
		temp = temp -> link;
		temp -> link=r;
	}
	return;
}

void add_beg(struct node **q)
{
	struct node *r;
	r = (struct node *)malloc(sizeof(struct node));
	printf("Enter a node data: ");
	scanf("%d",&r -> data);
	r -> link = *q;
	*q=r;
	return;
}

void display(struct node *q)
{
	struct node *temp;
	temp = q;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d -> ",temp -> data);
		temp = temp -> link;
	}
	printf("NULL");
	return;
}

void add_mid(struct node **q)
{
	struct node *temp, *r;
	int loc, i;
	printf("Enter location: ");
	scanf("%d",&loc);
	temp = *q;
	
	for(i = 1; i<loc; i++){
		temp = temp -> link;
		if(temp == NULL)
		{
			printf("The list contains less than %d no. of elements", loc);
			return;
		}
	}
	
	r = (struct node *)malloc(sizeof(struct node));
	printf("Enter a node data:");
	scanf("%d",&r -> data );
	r -> link = temp -> link;
	temp -> link = r;
	return;
}
