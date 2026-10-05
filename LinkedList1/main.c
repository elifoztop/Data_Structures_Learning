#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
int num;
struct LinkedList *next;
}NList;

NList *first=NULL,*tail=NULL,*temp=NULL;

int add_num();
int list_print();
int delete_num();

int main()
{
    if(add_num()){
        printf("\nRAM Error");
        return -1;
    }
    int exit=0;
    int choice;
    while(exit==0){
        printf("\n\n1:Add\n2:Print\n3:Delete\n4:Exit\nChoice: ");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            if(add_num()){
            printf("\nRAM Error");
            return -1;
            }
            break;

        case 2:
            if(list_print())
            {
                if(add_num()){
                printf("\nRAM Error");
                return -1;
                }
            }
            break;

        case 3:
            if(delete_num())
            {
                if(add_num()){
                printf("\nRAM Error");
                return -1;
                }
            }
            break;

        case 4:

            printf("Exit...");
            exit=1;
            break;

        default:
            continue;
        }
    }
    return 0;
}
int add_num(){
    int stop=0;
    int num;
    while(stop==0)
    {
        printf("\nNumber: ");
        scanf("%d",&num);
         if (first==NULL){
                first=(NList*)malloc(sizeof(NList));
                if (first==NULL)
                {
                    printf("\nRAM Error");
                    return -1;
                }
                first->next=NULL;
                tail=first;
                first->num=num;
                printf("\nContinue='0' Exit='1': ");
                scanf("%d",&stop);
                if (stop==1){
                    return 0;
                }
                printf("\nNumber: ");
                scanf("%d",&num);
        }
        tail->next=(NList*)malloc(sizeof(NList));
        if (tail->next==NULL)
        {
            printf("\nRAM Error");
            return -1;
        }
        tail=tail->next;
        tail->num=num;
        tail->next=NULL;
        printf("\nContinue='0' Exit='1': ");
        scanf("%d",&stop);
    }
    return 0;
}

int list_print()
{
    if(first==NULL){
        printf("\nList No Found --> ADD NUM");
        return 1;
    }
    temp=first;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->num);
        temp=temp->next;
    }
    return 0;
}

int delete_num()
{
    if(first==NULL){
        printf("\nList No Found --> ADD NUM");
        return 1;
    }

    NList *deleted;
    int deleted_num;
    printf("\nDeleted Num: ");
    scanf("%d",&deleted_num);

    if (first->num==deleted_num){
        if (first->next==NULL){
            deleted=first;
            free(deleted);
            first=NULL;
            tail=NULL;
            temp=NULL;
            printf("\nList Empty --> ADD NUM");
            return 1;
        }
        deleted=first;
        first=first->next;
        free(deleted);
        return 0;
    }

    temp=first;
    while(temp->next!=NULL)
    {
        if (temp->next->num==deleted_num)
        {
            if(tail==temp->next){
                tail=temp;
            }
            deleted=temp->next;
            temp->next=temp->next->next;
            free(deleted);
            return 0;
        }
        temp=temp->next;
    }
    printf("\nDeleted Num Not Found");
    return 0;
}
