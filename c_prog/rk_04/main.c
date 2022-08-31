//variant 2
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
 
 
typedef struct node node_t;
 
typedef struct node
{
    void *data;
    node_t *prev;
    node_t *next;
} node;
 
node *node_create(void *data)
{
    node *res = malloc(sizeof(node));
    res->data = data;
    res->prev = NULL;
    res->next = NULL;
    return res;
}
void node_dispose(node *n)
{
    free(n);
}
void list_dispose(node *head)
{
    while (head)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}
node *list_sort(node *head, int (*comparator)(const void *, const void *))
{
    node *cur = head;
 
    size_t n = 0;
    while (cur && cur->next)
    {
        if (comparator(cur->data, cur->next->data) > 0)
        {
            void *t = cur->data;
            cur->data = cur->next->data;
            cur->next->data = t;
        }
 
        cur = cur->next;
        n++;
    }
    if (!n)
        return head;
    while (--n)
    {
        cur = head;
        while (cur && cur->next)
        {
            if (comparator(cur->data, cur->next->data) > 0)
            {
                void *t = cur->data;
                cur->data = cur->next->data;
                cur->next->data = t;
            }
            cur = cur->next;
        }
    }
 
    return head;
}
void list_print(const node *head, void (*printer)())
{
    while (head)
    {
        printer(head->data);
        head = head->next;
    }
}
node *list_add(node *head, void *data)
{
    if (!head)
        return node_create(data);
 
    node *cur = head;
    while (cur->next)
        cur = cur->next;
    
    node *tmp = node_create(data);
    cur->next = tmp;
    tmp->prev = cur;
    return head;
}
 
typedef struct student
{
    char *name;
    int age;
    node *marks;
} student;
student *student_create(const char *name, int age)
{
    student *s = malloc(sizeof(student));
    s->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(s->name, name);
    s->age = age;
    s->marks = NULL;
    return s;
}
void student_dispose(student *s)
{
    free(s->name);
    node *mark = s->marks;
    while (mark)
    {
        free(mark->data);
        mark = mark->next;
    }
    list_dispose(s->marks);
}
void student_print(void *s)
{
    student *stud = (student *)s;
    printf("Name: %s\n", stud->name);
    printf("Age: %d\n", stud->age);
    printf("Marks:");
    node *mark = stud->marks;
    while (mark)
    {
        printf(" %d", *((int *)mark->data));
        mark = mark->next;
    }
    printf("\n");
}
 
int compare_students(const void *l, const void *r)
{
    return strcmp(((student *)l)->name, ((student *)r)->name);
}
 
int main()
{
    printf("Available actions:\n");
    printf("1) Add student\n");
    printf("2) Print students\n");
    printf("3) Sort students\n");
    printf("4) Exit\n");
    node *head = NULL;
 
    int running = 1;
    int error = 0;
    while (running)
    {
        int sel;
        printf("Select action: ");
        if (scanf("%d", &sel) != 1)
        {
            error = 1;
            break;
        }
 
        char buffer[256];
        int age;
        int mark_v, mark_c;
        int *ip;
        student *stud;
        switch (sel)
        {
        case 1:
            printf("Enter student name: ");
            if (scanf("%255s", buffer) != 1)
            {
                running = 0;
                error = 1;
                break;
            }
            printf("Enter student age: ");
            if (scanf("%d", &age) != 1)
            {
                running = 0;
                error = 1;
                break;
            }
            stud = student_create(buffer, age);
 
            printf("Enter marks count: ");
            if (scanf("%d", &mark_c) != 1)
            {
                running = 0;
                error = 1;
                break;
            }
 
            printf("Enter marks: ");
            while (mark_c--)
            {
                if (scanf("%d", &mark_v) != 1)
                {
                    running = 0;
                    error = 1;
                    break;
                }
                ip = malloc(sizeof(int));
                *ip = mark_v;
                stud->marks = list_add(stud->marks, ip);
            }
            head = list_add(head, stud);
            break;
 
        case 2:
            list_print(head, &student_print);
            break;
 
        case 3:
            head = list_sort(head, &compare_students);
            break;
        case 4:
            running = 0;
            break;
        default:
            printf("Error: Unknown action.\n");
            break;
        }
    }
 
    node *cur = head;
    while (cur)
    {
        student_dispose(cur->data);
        cur = cur->next;
    }
    list_dispose(head);
    return error;
}