#include "lists.h"
/**
* insert_node - insert node in sorted list
* @head: head pointer
* @number: new value for the node
* Return: head pointer
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *Node, *new;

	Node = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (head == NULL || *head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (Node)
	{
		if (Node->n >= number)
		{
			new->next = Node;
			*head = new;
			return (*head);
		}
		if (Node->next && (Node->next->n >= number))
		{
			new->next = Node->next;
			Node->next = new;
			return (*head);
		}
		if (Node->next == NULL)
		{
			Node->next = new;
			new->next = NULL;
			return (*head);
		}
		Node = Node->next;
	}
	return (*head);
}
