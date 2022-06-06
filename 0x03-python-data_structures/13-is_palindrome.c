#include "lists.h"
/**
* len_list - length of linked list
* @head: head pointer
* Return: length of list
*/
int len_list(listint_t *head)
{
	listint_t *cur;
	int len = 0;

	if (head == NULL)
		return (0);
	cur = head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
/**
* is_palindrome - check if linked list is palindrome
* @head: head pointer
* Return: 1 if palindrome else 0
*/
int is_palindrome(listint_t **head)
{
	listint_t *tmp, *tmp2, *cur;
	int i = 0, len;

	if (head == NULL || *head == NULL)
		return (1);
	cur = *head;
	tmp = *head;
	len = len_list(*head);
	if (len == 1)
		return (1);
	if (len == 2)
	{
		if ((*head)->n == (((*head)->next)->n))
			return (1);
		else
			return (0);
	}
	tmp2 = cur->next;
	for (i = 0; i < (len / 2); i++)
	{
		if (i == 0)
		{
			tmp->next = NULL;
			cur = tmp2;
		}
		else
		{
			tmp2 = cur->next;
			cur->next = tmp;
			tmp = cur;
			cur = tmp2;
		}
	}
	cur = tmp;
	if (len % 2 == 0)
	{
		while (cur != NULL && tmp2 != NULL)
		{
			if (cur->n != tmp2->n)
				return (0);
			cur = cur->next;
			tmp2 = tmp2->next;
		}
		return (1);
	}
	tmp2 = tmp2->next;
	while (cur != NULL && tmp2 != NULL)
	{
		if (cur->n != tmp2->n)
			return (0);
		cur = cur->next;
		tmp2 = tmp2->next;
	}
	return (1);
}
