#include <stdio.h>
#include <stdlib.h>

// create structure to node
struct Node
{
    char data;
    struct Node *next;
};

struct Node *LIST_SEARCH(struct Node **, char);
struct Node *LIST_INSERT_AFTER(struct Node **, char, char);
struct Node *LIST_INSERT_BEFORE(struct Node **, char, char);
struct Node *LIST_INSERT_FRONT(struct Node **, char);
struct Node *LIST_INSERT_TAIL(struct Node **, char);

struct Node *CREATE_NODE(char k)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = k;
    newnode->next = NULL;
    return newnode;
}

struct Node *LIST_SEARCH(struct Node **LL, char k)
{
    if (*LL == NULL)
    {
        // if list is empty
        return NULL;
    }
    else
    {
        struct Node *temp = *LL;
        while (temp != NULL)
        {
            if (temp->data == k)
            {
                // if key found
                return temp;
            }
            temp = temp->next;
        }

        // key not found
        return NULL;
    }
}

struct Node *LIST_INSERT_AFTER(struct Node **LL, char k, char n)
{
    if (*LL == NULL)
    {
        // if list is empty
        printf("NULL\n");
        return *LL;
    }
    else
    {
        struct Node *temp = LIST_SEARCH(LL, n);
        struct Node *newnode = CREATE_NODE(k);
        if (temp == NULL)
        {
            // key not found
            printf("ABSENT\n");
            return *LL;
        }
        else if (temp->next == NULL)
        {
            // key found at tail
            temp->next = newnode;
            return *LL;
        }
        else
        {
            // key found anywhere
            newnode->next = temp->next;
            temp->next = newnode;
            return *LL;
        }
    }
}

struct Node *LIST_INSERT_BEFORE(struct Node **LL, char k, char n)
{
    if (*LL == NULL)
    {
        // if list is empty
        printf("NULL\n");
        return *LL;
    }
    else
    {
        struct Node *temp = LIST_SEARCH(LL, n);
        if (temp == NULL)
        {
            // key not found
            printf("ABSENT\n");
            return *LL;
        }
        else
        {
            // key found
            if (temp == *LL)
            {
                // insertion before head
                *LL = LIST_INSERT_FRONT(LL, k);
                return *LL;
            }
            else
            {
                // insertion before any node
                struct Node *prev = *LL;
                while (prev->next != temp)
                {
                    prev = prev->next;
                }
                struct Node *newnode = CREATE_NODE(k);
                prev->next = newnode;
                newnode->next = temp;
                return *LL;
            }
        }
    }
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
            printf("%c\n", curr->data);
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

struct Node* LIST_DELETE(struct Node** LL , char k)
{
    if(*LL == NULL)
    {
        // list is empty
        printf("NULL\n");
        return *LL;
    }
    else
    {
        struct Node* temp = LIST_SEARCH(LL , k);
        if(temp == NULL)
        {
            // key not found
            printf("ABSENT\n");
            return *LL;
        }
        else
        {
            // key found
            /*
                CASE 1 : deletion of head node
                CASE 2 : deletion in middle of list
                CASE 3 : deletion of last node
            */
           if(temp == *LL)
           {
                // key found at head
                (*LL) = (*LL)->next;
                if(temp->next != NULL)
                    printf("%c\n",temp->next->data);
                else
                    printf("LAST\n");
                free(temp);
                return *LL;
           }
           else if(temp == *LL && temp->next == NULL)
           {
                // key is last node of the linked list
                printf("LAST\n");
                free(temp);
                return NULL;
           }
           else
           {
                struct Node* prev = *LL;
                while (prev->next != temp)
                {
                    prev = prev->next;
                }
                prev->next = NULL;
                printf("%c\n",temp->next->data);
                free(temp);
                return *LL;
                
           }
        }
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
        else if (input == 'a')
        {
            char search;
            scanf(" %c %c", &key, &search);
            head = LIST_INSERT_AFTER(&head, key, search);
        }
        else if (input == 'b')
        {
            char search;
            scanf(" %c %c", &key, &search);
            head = LIST_INSERT_BEFORE(&head, key, search);
        }
        else if(input == 'd')
        {
            char search;
            scanf(" %c",&search);
            head = LIST_DELETE(&head , search);
        }
        else if (input == 'e')
        {
            break;
        }
    }
    return 0;
}