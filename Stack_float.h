#include<stdlib.h>
#include<stdio.h>

struct stack 
{
	float data;
	struct stack *prev;
};

struct stack *current = NULL;
int size_stack = 0;

int get_size()
{
	return size_stack;
}

void push(float dat)
{
	struct stack *temp_ptr;
	if (( temp_ptr = (malloc(sizeof(struct stack)))) == NULL)
	{
		printf("\n\tError. Stack overflow\n");
	}
	else
	{	
		temp_ptr->prev = current;
		temp_ptr->data = dat;
		current = temp_ptr;
		size_stack++;
	}

}

float pop()
{
	if (size_stack == 0)
	{
		return 0;
	}
	struct stack *temp_ptr;
	int temp_data;
	temp_data = current->data;
	temp_ptr = current->prev;
	free(current);
	current = temp_ptr;
	size_stack--;
	return temp_data;
}

void clean_stack()
{
	while(size_stack)
	{
		pop();
	}
}

