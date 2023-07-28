#include <stdio.h>
#include <stdlib.h>

// create structure to node
struct Node
{
    char data;
    struct Node *next;
};

struct Node *CREATE_NODE(char k)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = k;
    newnode->next = NULL;
    return newnode;
}

struct Node *LIST_INSERT_FRONT(struct Node **LL, char k)
{
    struct Node *node = CREATE_NODE(k);
    if (*LL == NULL)
    {
        // if linked list is empty
        *LL = node;
        return *LL;
    }
    else
    {
        // if LL is not empty
        node->next = *LL;
        *LL = node;
        return *LL;
    }
}

struct Node *LIST_INSERT_TAIL(struct Node **LL, char k)
{
    // create new node by calling CREATE_NODE()
    struct Node *node = CREATE_NODE(k);

    if (*LL == NULL)
    {
        // if LL is empty
        *LL = node;
        return *LL;
    }
    else
    {
        // if LL is not empty
        struct Node *temp = *LL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        temp = node;

        return *LL;
    }
}

struct Node *LIST_DELETE_FIRST(struct Node **LL)
{
    if (*LL == NULL)
    {
        printf("NULL\n");
        return *LL;
    }
    else
    {

        struct Node *temp = *LL;
        // printing deleted nodes data
        printf("%c\n", temp->data);
        *LL = (*LL)->next;
        temp->next = NULL;
        free(temp);
        return *LL;
    }
    // return LL->next;
}

struct Node *LIST_DELETE_LAST(struct Node **LL)
{
    if (*LL == NULL)
    {
        // if LL is empty
        printf("NULL\n");
        return *LL;
    }
    else
    {
        struct Node *curr = *LL;
        struct Node *prev = curr;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        // prev->next = NULL;
        // if(prev->next->next == NULL){
        if (curr == prev && curr->next == NULL && prev->next == NULL)
        {
            printf("%c\n",curr->data);
            free(curr);
            return NULL;
        }
        else
        {

            prev->next = NULL;
            printf("%c\n", curr->data);
            free(curr);
            return *LL;
        }
        // }
    }
}

void PRINT_LIST(struct Node **LL)
{
    struct Node *temp = *LL;
    if (*LL == NULL)
    {
        printf("NULL\n");
        return;
    }
    else
    {

        while (temp != NULL)
        {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{

    struct Node *head = NULL;
    char input;
    char key;
    while (1)
    {
        scanf("%c", &input);
        if (input == 'f')
        {
            scanf(" %c", &key);
            head = LIST_INSERT_FRONT(&head, key);
            // printf("%c\n", head->data);
        }
        else if (input == 't')
        {
            scanf(" %c", &key);
            head = LIST_INSERT_TAIL(&head, key);
            // printf("%c\n", head->data);
        }
        else if (input == 'i')
        {

            head = LIST_DELETE_FIRST(&head);
            // if (head != NULL)
            //     printf("%c\n", head->data);
        }
        else if (input == 'l')
        {
            head = LIST_DELETE_LAST(&head);
            // if (head != NULL)
            //     printf("%c\n", head->data);
        }
        else if (input == 'p')
        {
            PRINT_LIST(&head);
        }
        else if (input == 'e')
        {
            break;
        }
    }
    return 0;
}