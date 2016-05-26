


void set_previous(node * head)
{
if (head == NULL)
    return;
if (previous != NULL)
    previous == NULL;
return set_previous(head->next);
}


void set_dll(node * head)
{
if (head == NULL)
    return;
if (head->next != NULL)
    return;
head->next->previous = head;
return set_dll(head->next);
}
