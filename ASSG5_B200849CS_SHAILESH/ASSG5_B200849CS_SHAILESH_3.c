#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *CREATE_NODE(int k)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = k;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

Node *LIST_SEARCH(Node **List, int x)
{
    if (*List == NULL)
    {
        // list is empty
        return NULL;
    }
    else
    {
        // list is not empty
        Node *temp = *List;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                // if key found
                return temp;
            }
            temp = temp->next;
        }

        // if key not found
        return temp;
    }
}

Node *LIST_INSERT_FRONT(Node **List, int k)
{
    if (*List == NULL)
    {
        // if list is empty
        Node *newnode = CREATE_NODE(k);
        return newnode;
    }
    else
    {
        Node *newnode = CREATE_NODE(k);
        newnode->next = *List;
        (*List)->prev = newnode;
        return newnode;
    }
}

Node *LIST_INSERT_TAIL(Node **List, int k)
{
    if (*List == NULL)
    {
        // if list is empty
        Node *newnode = CREATE_NODE(k);
        return newnode;
    }
    Node *newnode = CREATE_NODE(k);
    Node *temp = *List;
    // traversing till last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // printf("%d\n",temp->data);
    temp->next = newnode;
    newnode->prev = temp;
    return *List;
}

Node *LIST_INSERT_AFTER(Node **List, int k, int n)
{

    if (*List == NULL)
    {
        // if list is empty
        printf("NULL\n");
        return *List;
    }
    Node *temp = LIST_SEARCH(List, n);
    if (temp == NULL)
    {
        // key not found;
        printf("ABSENT\n");
        return *List;
    }
    else
    {
        /*
            Key found:
                case 1 : anywhere except tail
                case 2 : at tail
        */
        if (temp->next == NULL)
        {
            // insertion at tail
            *List = LIST_INSERT_TAIL(List, k);
            return *List;
        }
        else
        {
            // insertion after the node anywhere in the list
            Node *newnode = CREATE_NODE(k);
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            return *List;
        }
    }
}

Node *LIST_INSERT_BEFORE(Node **List, int k, int n)
{
    if (*List == NULL)
    {
        // if list is empty
        printf("NULL\n");
        return *List;
    }
    else
    {
        Node *temp = LIST_SEARCH(List, n);
        if (temp == NULL)
        {
            // key not found
            printf("ABSENT\n");
            return *List;
        }
        else
        {
            Node *newnode = CREATE_NODE(k);
            // key found
            if (temp == *List)
            {
                // key found at head so insertion before head
                newnode->next = *List;
                (*List)->prev = newnode;
                return newnode;
            }
            else
            {
                // insertion before any node
                newnode->prev = temp->prev;
                temp->prev->next = newnode;
                newnode->next = temp;
                temp->prev = newnode;
                return *List;
            }
        }
    }
}

Node *LIST_DELETE_FIRST(Node **List)
{
    if (*List == NULL)
    {
        // list empty
        printf("NULL\n");
        return *List;
    }
    else
    {
        // list is not empty
        Node *temp = *List;
        if (temp->next == NULL)
        {
            // last node
            printf("%d\n", temp->data);
            free(temp);
            return *List;
        }
        else
        {

            printf("%d\n", temp->data);
            *List = (*List)->next;
            temp->next->prev = NULL;
            temp->next = NULL;
            free(temp);
            return *List;
        }
    }
}

Node *LIST_DELETE_LAST(Node **List)
{
    if (*List == NULL)
    {
        // if list is empty
        printf("NULL\n");
        return NULL;
    }
    else
    {
        Node *temp = *List;
        if (temp->next == NULL)
        {
            // last node is remaining
            printf("%d\n", temp->data);
            free(temp);
            return NULL;
        }
        else
        {

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            printf("%d\n", temp->data);
            temp->prev->next = NULL;
            temp->prev = NULL;
            free(temp);
            return *List;
        }
    }
}

Node *LIST_DELETE(Node **List, int k)
{
    if (*List == NULL)
    {
        // list empty
        printf("NULL\n");
        return *List;
    }
    else
    {
        Node *temp = LIST_SEARCH(List, k);
        if (temp == NULL)
        {
            // key not found
            printf("ABSENT\n");
            return *List;
        }
        else
        {
            if (temp == *List)
            {
                // key found at head
                printf("FIRST\n");
                (*List) = (*List)->next;
                temp->next = NULL;
                free(temp);
                return *List;
            }
            else if (temp->next == NULL)
            {
                // key found at tail
                printf("%d\n", temp->prev->data);
                temp->prev->next = NULL;
                temp->prev = NULL;
                free(temp);
                return *List;
            }
            else
            {
                // key found in the middle of the list
                printf("%d\n", temp->prev->data);
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = NULL;
                temp->prev = NULL;
                free(temp);
                return *List;
            }
        }
    }
}

void PRINT_REVERSE(Node **List, int n)
{
    if (*List == NULL)
    {
        // list is empty
        printf("NULL\n");
        return;
    }
    else
    {
        Node *temp = LIST_SEARCH(List, n);
        if (temp == NULL)
        {
            // key not found
            printf("ABSENT\n");
            return;
        }
        else
        {
            // key is found
            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->prev;
            }
            printf("\n");
            return;
        }
    }
}

int main()
{
    Node *head = NULL;
    char opt;
    int key;
    while (1)
    {
        int search_node;
        scanf("%c", &opt);
        if (opt == 'f')
        {
            scanf(" %d", &key);
            head = LIST_INSERT_FRONT(&head, key);
        }
        else if (opt == 't')
        {
            scanf(" %d", &key);
            head = LIST_INSERT_TAIL(&head, key);
        }
        else if (opt == 'a')
        {
            scanf(" %d %d", &key, &search_node);
            head = LIST_INSERT_AFTER(&head, key, search_node);
        }
        else if (opt == 'b')
        {
            // do something something
            scanf(" %d %d", &key, &search_node);
            head = LIST_INSERT_BEFORE(&head, key, search_node);
        }
        else if (opt == 'i')
        {
            // delete first
            head = LIST_DELETE_FIRST(&head);
        }
        else if (opt == 'l')
        {
            // delete last
            head = LIST_DELETE_LAST(&head);
        }
        else if (opt == 'd')
        {
            scanf(" %d", &search_node);
            head = LIST_DELETE(&head, search_node);
        }
        else if (opt == 'r')
        {
            // print list in reverse direction
            scanf(" %d", &search_node);
            PRINT_REVERSE(&head, search_node);
        }
        else if (opt == 'e')
        {
            break;
        }
    }

    return 0;
}
