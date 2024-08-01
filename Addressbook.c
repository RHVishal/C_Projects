#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int choice;
struct Addressbook
{
    char Name[30];
    char Mob[12];
    char email[25];
    char address[15];
};
void Add_details(struct Addressbook *, int *);
void Edit_details(struct Addressbook *, int *);
void Print_details(struct Addressbook *, int *);
void Search_details(struct Addressbook *, int *);
int main()
{
    int repeat = 1, User_count = 0;
    struct Addressbook user[30];
    while (repeat)
    {
        printf("1. Add Details\n");
        printf("2. Edit Details\n");
        printf("3. Search Details\n");
        printf("4. Print Details\n");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Add_details(user, &User_count);
            break;
        case 2:
            Edit_details(user, &User_count);
            break;
        case 3:
            Search_details(user, &User_count);
            break;
        case 4:
            Print_details(user, &User_count);
            break;
        default:
            break;
        }
        char ch;
        printf("\nDo you want to continue with Home Page(Y/N) :");
        scanf(" %c", &ch);
        ch == 'y' || ch == 'Y' ? (repeat = 1) : (repeat = 0);
    }
    return 0;
}
void Add_details(struct Addressbook user[], int *User_count)
{
    char Repeat = 1;
    while (Repeat)
    {
        int i = *User_count;
        printf("Enter your name %d: ", *User_count + 1);
        scanf(" %[^\n]", user[i].Name);
        printf("Enter your Mobile number : ");
        scanf(" %[^\n]", user[i].Mob);
        printf("Enter your email : ");
        scanf(" %[^\n]", user[i].email);
        printf("Enter your Address : ");
        scanf(" %[^\n]", user[i].address);
        (*User_count)++;
        char ch;
        printf("\nDo you want to Add Another name(Y/N) : ");
        scanf(" %c", &ch);
        ch == 'y' || ch == 'Y' ? (Repeat = 1) : (Repeat = 0);
    }
}
void Print_details(struct Addressbook user[], int *User_count)
{
    printf("\n----------------Print Details---------------\n\n");
    printf("Name\tMob\temail\tAddress\n");
    for (int i = 0; i < *User_count; i++)
    {
        printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
    }
}
void Search_details(struct Addressbook user[], int *User_count)
{
    int Repeat = 1;
    while (Repeat)
    {
        printf("\n---------------Search Customer---------------\n\n");
        printf("Select Any one of the following option to search\n");
        printf("1. Name\n2. Mob\n3. email\n4. Address\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char str[50];
            printf("Enter the name : ");
            scanf(" %[^\n]", str);
            printf("Name\tMob\temail\tAddress\n");
            for (int i = 0; i < *User_count; i++)
            {
                if (strcmp(user[i].Name, str) == 0)
                {
                    printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            char Mobile[12];
            printf("Enter the mobile number : ");
            scanf(" %s", Mobile);
            printf("Name\tMob\temail\tAddress\n");
            for (int i = 0; i < *User_count; i++)
            {
                if (strcmp(user[i].Mob, Mobile) == 0)
                {
                    printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    break;
                }
            }
        }
        else if (choice == 3)
        {
            char Email[25];
            printf("Enter the email : ");
            scanf(" %s", Email);
            printf("Name\tMob\temail\tAddress\n");
            for (int i = 0; i < *User_count; i++)
            {
                if (strcmp(user[i].email, Email) == 0)
                {
                    printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    break;
                }
            }
        }
        else if (choice == 4)
        {
            char Address[25];
            printf("Enter the Address : ");
            scanf(" %s", Address);
            printf("Name\tMob\temail\tAddress\n");
            for (int i = 0; i < *User_count; i++)
            {
                if (strcmp(user[i].address, Address) == 0)
                {
                    printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    break;
                }
            }
        }
        else
            printf("---404 Error Invalid Choice--- \n");
        char ch;
        printf("\nDo you want to Search Again (Y/N) :");
        scanf(" %c", &ch);
        ch == 'y' || ch == 'Y' ? (Repeat = 1) : (Repeat = 0);
    }
}
void Edit_details(struct Addressbook user[], int *User_count)
{
    int Repeat = 1;
    while (Repeat)
    {
        printf("\n--------------Edit Option---------------\n\n");
        printf("Select the following option to edit\n1. Edit Name\n2. Edit Mobile Number\n3. Edit Email\n4. Edit Address\n5. Edit All Data\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char editname[30];
            printf("Enter the name you want to edit from Data: ");
            scanf(" %[^\n]", editname);
            for (int i = 0; i < *User_count; i++)
            {
                char str[30];
                if (strcmp(user[i].Name, editname) == 0)
                {
                    printf("Enter the new Name : ");
                    scanf(" %s", str);
                    if (strcpy(user[i].Name, str))
                    {
                        printf("Name\tMob\temail\tAddress\n");
                        printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    }
                }
            }
        }
        else if (choice == 2)
        {
            char editMob[30];
            printf("Enter the Mobile number you want to edit from Data: ");
            scanf(" %[^\n]", editMob);
            for (int i = 0; i < *User_count; i++)
            {
                char str[30];
                if (strcmp(user[i].Mob, editMob) == 0)
                {
                    printf("Enter the new Mobile number : ");
                    scanf(" %s", str);
                    if (strcpy(user[i].Mob, str))
                    {
                        printf("Name\tMob\temail\tAddress\n");
                        printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    }
                }
            }
        }
        else if (choice == 3)
        {
            char editemail[25];
            printf("Enter the name you want to edit from Data: ");
            scanf(" %[^\n]", editemail);
            for (int i = 0; i < *User_count; i++)
            {
                char str[25];
                if (strcmp(user[i].Name, editemail) == 0)
                {
                    printf("Enter the new email : ");
                    scanf(" %s", str);
                    if (strcpy(user[i].email, str))
                    {
                        printf("Name\tMob\temail\tAddress\n");
                        printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    }
                }
            }
        }
        else if (choice == 4)
        {
            char editaddress[15];
            printf("Enter the address you want to edit from Data: ");
            scanf(" %[^\n]", editaddress);
            for (int i = 0; i < *User_count; i++)
            {
                char str[15];
                if (strcmp(user[i].address, editaddress) == 0)
                {
                    printf("Enter the new Address : ");
                    scanf(" %s", str);
                    if (strcpy(user[i].address, str))
                    {
                        printf("Name\tMob\temail\tAddress\n");
                        printf("%s\t%s\t%s\t%s\n", user[i].Name, user[i].Mob, user[i].email, user[i].address);
                    }
                }
            }
        }
        else
            printf("---------Invalid Choice--------\n");
        char ch;
        printf("\nDo you want to edit Again (Y/N) : ");
        scanf(" %c", &ch);
        ch == 'y' || ch == 'Y' ? (Repeat = 1) : (Repeat = 0);
    }
}