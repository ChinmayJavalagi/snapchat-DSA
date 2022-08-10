#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
//structure to store the details of friends
struct friends
{
    char name[50];
    char username[50];
    char dob[50];
};
typedef struct friends F;
//structure to store the details of contacts
struct contacts
{
    char cname[50];
    char userid[50];
};
typedef struct contacts C;


//to hold the message
char m[100];


int i=0;
//node for the linked list
struct node
{
    char data[50];
    struct node *next;
};
typedef struct node *NODE;
NODE head=NULL;


F frns[200];
C cncts[200];

F search_result[200];
int global_count = 0;
int global_count1 = 0;

void print()
{
    //to print the friends list
    printf("\nYOUR FRIENDS:\n");
    printf("  NAME\t\t\tUSERNAME\n");
    for(int i=0;i<global_count;i++)
    {
        printf("%d.%s\t\t\t%s\n",i+1,frns[i].name,frns[i].username);
    }
}
void printcontacts()
{
    //to print the contact list
    printf("\nYOUR contacts:\n");
    printf("  NAME\t\t\t\t\tUSERNAME\n");
    for(int i=0;i<global_count1;i++)
    {
        printf("%d.%s\t\t\t%s\n",i+1,cncts[i].cname,cncts[i].userid);
    }
}
int streak(char name[])
{
    int streak=0;
    int a,b;
    while(1)
    {
        printf("\n\nnew day!\n\n");
        printf("If yes enter 1 else 0\nEnter 3 to exit streaks.\n");
        printf("Did you send snap today?\n");
        scanf("%d",&a);
        if(a==3)
        {
            printf("Exited from streaks.\n");
            return 0;
        }
        else
        {
        printf("did %s send snap today?\n",name);
        scanf("%d",&b);
        if(a==1&&b==1)
        {
            streak++;
            //streak is established after 3 consecutive days of sending snaps.
            if(streak>=3)
                //fire emoji is usually displayed here since we cannot do that have written the same.
                printf("****%s %d FIREEEEE****\n",name,streak);
        }
        else if ((a==1&&b==0)||(a==0&&b==1)||a==0&&b==0)
        {
            printf("streaks broke\n");
            break;
        }
        }
    }
}

void load()
{
    // to load the friends list into the structure array
    FILE *fp;
    fp = fopen("SnapFriends.txt", "r+");

    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }


    while(!feof(fp))
    {
        fscanf(fp,"%s%s%s", frns[global_count].name, frns[global_count].username,
        frns[global_count].dob);

        global_count++;
    }

    fclose(fp);
}
void load_contacts()
{
    // to load the contact list into the structure array
    FILE *fp;


    fp = fopen("contacts.txt", "r+");


    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }


    while(!feof(fp))
    {
        fscanf(fp,"%s%s", cncts[global_count1].cname, cncts[global_count1].userid);

        global_count1++;
    }

        fclose(fp);
}

int check(char nm[20])
{
    int flag=0;
    for(int i=0;i<global_count;i++)
    {
        if(strcmp(nm,frns[i].username)==0)
        {
            flag=1;
            break;
        }
    }
    return flag;

}

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

//We have used Warshall's algorithm to display the mutual of two friends.

void warshells(int a[MAX][MAX],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<n;j++)
                a[i][j]=max(a[i][j],a[i][k]&&a[k][j]);
        }
    }
}


int printlogo()
{
    //to print the logo
    printf("                                         ******                                                      \n");
    printf("                                      ************                                                   \n");
    printf("                                    ****************                                                 \n");
    printf("                                   ******************                                                \n");
    printf("                               *   ******************   *                                            \n");
    printf("                              * ** ****************** ** *                                           \n");
    printf("                               **************************                                            \n");
    printf("                                ************************                                             \n");
    printf("                                  ********************                                               \n");
    printf("                                  ********************                                               \n");
    printf("                                 **********************                                              \n");
    printf("                                ************************                                             \n");
    printf("                               ***************************                                           \n");
    printf("                             *******************************                                         \n");
    printf("                           ***********************************                                       \n");
    printf("                            *********************************                                        \n");
    printf("                                 ***********************                                             \n");
    printf("                                 ***********************                                             \n");
    printf("                                         *******                                                     \n");
    printf("********************************||||WELCOME TO SNAPCHAT!||||*********************\n");
        return 0;
}


void quickadd()
{
    //string compare is the major operation here.
    int i;
    for(i=0;i<global_count1;i++)
    {
        int j;
        for(j=0;j<global_count;j++)
        {
            if(strcmp(cncts[i].cname,frns[j].name)==0)
            break;

        }
        if(j==global_count)
            printf("%s\n",cncts[i].cname);
    }
}

//functions to get the linked list working

NODE getnode()
{
    NODE newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory is not allocated \n");
    }

    //scanf("%s",newnode->data);
    strcpy(newnode->data,frns[i].name);
    newnode->next=NULL;
    i++;
    return newnode;
}

void display(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty \n");
        return;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->data);
        temp=temp->next;
    }
}

NODE delete_position(NODE head)
{
    char sname[100],msg[100];
    int d;
    printf("Enter the name to chat with:\n");
    scanf("%s",sname);
    printf("Type the message\n");
    scanf("%s",msg);
    printf("Do u want the message to be saved in chat?\nIf yes enter 1 else 0\n");
    scanf("%d",&d);
    if(d==1)
    {
    int z;
    for(z=0;z<global_count;z++)
    {
        if(strcmp(sname,frns[z].name)==0)
        {

            break;
        }
    }

    if(z==global_count)
        printf("no such friend exists");
    else
        strcpy(m,msg);
        printf("Message saved successfully\n");
        printf("\n");
    }
    if(head==NULL)
    {
        printf("cannot delete \n");
        return head;
    }
        NODE cur=head,prev=NULL;
        if(cur==head&&strcmp(cur->data,sname)==0)
        {
            return head;
        }
    while(strcmp(cur->data,sname)!=0&&cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("person not in friend list\n");
        return head;
    }
    prev->next=cur->next;
        NODE temp2=cur;
        NODE newnode=malloc(sizeof(struct node));
        strcpy(newnode->data,temp2->data);
        newnode->next=head;
        head=newnode;
        return head;
}

NODE insert_front(NODE head)
{
    NODE Newnode=getnode();
    if(head==NULL)
    {
        head=Newnode;
        return head;
    }
    else
    {
        Newnode->next=head;
        head=Newnode;

        return head;
    }

}

NODE delete_specific(NODE head)
{
    char sname[100],msg[100];
    printf("Remove friend:\n");
    scanf("%s",sname);
    if(head==NULL)
    {
        printf("cannot delete \n");
        return head;
    }
        NODE cur=head,prev=NULL;
        if(cur==head&&strcmp(cur->data,sname)==0)
        {
            return head;
        }
    while(strcmp(cur->data,sname)!=0&&cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("person not in friend list\n");
        return head;
    }
    prev->next=cur->next;
    return head;
}


void bubblesort()
{
    //we are sorting based on alphabetical order
    char temp[200];
    for(int i=0;i<=global_count-2;i++)
    {
        for(int j=0;j<=global_count-2-i;j++)
        {
            if(strcmp(frns[j].name,frns[j+1].name)>0)
            {
                strcpy(temp,frns[j].name);
                strcpy(frns[j].name,frns[j+1].name);
                strcpy(frns[j+1].name,temp);
            }
        }
    }
    for(int i=0;i<global_count;i++)
    {
        printf("%s\n",frns[i].name);
    }
}

void print2()
{
    for(int i=0;i<global_count;i++)
    {
        printf("%s\n",frns[i].name);
    }
}

struct nodeqa
{
    char data[50];
    struct nodeqa *next;
};
typedef struct nodeqa *NODEQA;

NODEQA headqa=NULL;

NODEQA getnode_qckadd()
{
    NODEQA newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory is not allocated \n");
    }

    //scanf("%s",newnode->data);
    strcpy(newnode->data,cncts[i].cname);
    newnode->next=NULL;
    i++;
    return newnode;
}

void display_qckadd(NODEQA headqa)
{
    // contacts who arent friends is displayed
    if(headqa==NULL)
    {
        printf("List is empty \n");
        return;
    }
    NODEQA temp=headqa;
    while(temp!=NULL)
    {
        printf("%s\n",temp->data);
        temp=temp->next;
    }
}

NODEQA insert_front_qckadd(NODEQA headqa)
{
    NODEQA Newnode=getnode_qckadd();
    if(headqa==NULL)
    {
        headqa=Newnode;
        return headqa;
    }
    else
    {
        Newnode->next=headqa;
        headqa=Newnode;
        return headqa;
    }
}

NODEQA delete_specific_qckadd(NODEQA headqa)
{
    char contact[50];
    printf("Re-enter the name to add:\n");
    scanf("%s",contact);
    if(headqa==NULL)
    {
        printf("cannot delete \n");
        return headqa;
    }
        NODE cur,prev;
        cur=headqa,prev=NULL;
        if((cur==headqa)&&(strcmp(cur->data,contact)==0))
        {
            return headqa;
        }
    while(strcmp(cur->data,contact)!=0&&cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("person not in list\n");
        return headqa;
    }
    prev->next=cur->next;
    return headqa;
}


int main()
{
    load();
    load_contacts();
    printf("data loaded.\n\n");
    printf("Contacts loaded\n\n");
    printlogo();
    printf("\n");
    for(int i=0;i<10;i++)
    {
        head=insert_front(head);
    }
    for(int i=0;i<global_count1;i++)
    {
        headqa=insert_front_qckadd(headqa);
    }
    for(int i=0;i<85;i++)
    {
        printf("-");
    }
    //Login code
    printf("\n");
    printf("                                     LOGIN\n");
    for(int i=0;i<85;i++)
    {
        printf("-");
    }
    printf("\n");
    printf("To login enter 1 else 0\n");
    int y;
    scanf("%d",&y);
    //if user opted to login then
    if(y==1)
       {
           int t;
           char sir[20];
           int num;
           //user can login in two ways
           //1.via username
           //2.via phone number
          printf( "login using\n 1. username\n 2. phone number\n");
          printf("(Enter 1 to login using username, 2 to login using phone number)\n");
          printf("your choice?\n");
          scanf("%d",&t);

          //via username
          if( t==1)
            {
                //check if username matches
                printf("enter username:\n");
                scanf("%s",sir);
                if(strcmp("prakash_h",sir)!=0)
                 {
                     //if not then stop the process
                     printf("invalid username.");
                     return 0;
                 }

            }

            //via phone number
        if (t==2)
        {
            //check if phone number matches
            int phno;
            printf("enter phone number:\n");
            scanf("%d",&phno);
            if(phno!=9964437282)
               {
                   //if not then stop the process
                   printf("invalid phone number");
                   return 0;
               }
        }
        char pass[40];
        //password check
        printf("enter ur password:\n");
        scanf("%s",pass);
        // if matches continue
        if(strcmp("snapchatprakash",pass)!=0)
            {
                //if not then stop the process
                printf("wrong password");
                return 0;
            }

       }
       else
        return 0;
    printf("\n***********************************||||HAPPY SNAPPING||||************************\n");
    int c;
    while(1)
    {
        printf("                                       **************\n                                           MENU\n                                       **************\n");
        for(int l=0;l<85;l++)
        {
            printf("-");
        }
        printf("\n");
        printf("                                ||  1.Display friends      ||\n");
        printf("                                ||  2.Streaks              ||\n");
        printf("                                ||  3.Mutual               ||\n");
        printf("                                ||  4.Search               ||\n");
        printf("                                ||  5.QuickAdd             ||\n");
        printf("                                ||  6.Display contacts     ||\n");
        printf("                                ||  7.Send message         ||\n");
        printf("                                ||  8.Remove a friend      ||\n");
        printf("                                ||  9.display saved message||\n");
        printf("                                ||  10.Sort by Name        ||\n");
        printf("                                ||  11.Logout              ||\n");
        for(int l=0;l<85;l++)
        {
            printf("-");
        }
        printf("\n");
        printf("enter choice:\n");
        scanf("%d",&c);

        switch(c)
        {
            case 1: //displays the friend list.
                    print();
                    break;
            case 2:
            //Snap streak: The count of how many consecutive days two people
            //have been sending snaps to each other.
                {
                    char nm[20];
                    printf("enter the username \n");
                    scanf("%s",nm);
                    // check if the entered name exists in the friends list
                    int flag=check(nm);
                    //if not print that it does ot exist
                    if(flag==0)
                    {
                        printf("No friends with that username:(\n");
                    }
                    //if it does call the function streak
                    else
                        streak(nm);
                    break;
                    }
            case 3:
            //using warshall we find the mutual friends with other contacts.
                {
                    int a[MAX][MAX],n,e,u,v;
                    n=10;
                    e=5;
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            a[i][j]=0;
                        }
                    }
                    /*
                    for(int i=0;i<e;i++)
                    {
                        printf("Enter the 2 friends numbers\n");
                        scanf("%d%d",&u,&v);
                        a[u][v]=1;
                    }
                    */
                    a[1][2]=1;
                    a[2][4]=1;
                    a[3][9]=1;
                    a[8][7]=1;
                    a[9][5]=1;
                    warshells(a,n);
                    printf("Suggestions\n");
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(i!=j)
                            {
                                if(a[i][j]==1)
                                {
                                    printf("friend of %s and %s\n",frns[i].name,frns[j].name);
                                }
                            }
                        }
                    }
                    break;
                    }
            case 4:{
                    //search the name in the friends list using the
                    //user input substring
                    int r;
                    char s[20];
                    //search can be based on two things
                    //1.username
                    //2.name
                    printf("Search based on\n1.username\n2.name\n");
                    printf("(Enter 1 to search based on username, 2 to search based on name)\n your choice:\n");
                    scanf("%d",&r);
                    switch(r)
                    {
                        case 1: {
                                    //search via username
                                    printf("Enter the username to search \n");
                                    scanf("%s",s);
                                        int flag=0,n,m,i,j,k,l,z=0;
                                            for(i=0;i<global_count;i++)
                                            {
                                                n=strlen(frns[i].username);
                                                m=strlen(s);
                                                for(j=0;j<=n-m;j++)
                                                {
                                                    k=0;
                                                    while((k<m)&&(s[k]==(frns[i].username)[j+k]))
                                                    k++;
                                                    if(k==m)
                                                    {
                                                        strcpy(search_result[z].name,frns[i].name);
                                                        strcpy(search_result[z].username,frns[i].username);
                                                        z++;
                                                        break;
                                                    }
                                                }
                                            }
                                            z--;
                                            printf("\nRESULTS\nFriends whose username matches with %s:\n",s);
                                            for(i=0;i<=z;i++)
                                            {
                                                printf("%s\t%s\n",search_result[i].name,search_result[i].username);
                                            }
                                            if(z==-1)
                                            {
                                               //if it does not exist
                                                printf("\n NOT FOUND\n");
                                            }

                                } break;

                        case 2: {
                                    //search using name as input.
                                    printf("Enter the name to search \n");
                                    scanf("%s",s);
                                        int flag=0,n,m,i,j,k,l,z=0;
                                            for(i=0;i<global_count;i++)
                                            {
                                                n=strlen(frns[i].name);
                                                m=strlen(s);
                                                for(j=0;j<=n-m;j++)
                                                {
                                                    k=0;
                                                    while((k<m)&&(s[k]==(frns[i].name)[j+k]))
                                                    k++;
                                                    if(k==m)
                                                    {
                                                        strcpy(search_result[z].name,frns[i].name);
                                                        strcpy(search_result[z].username,frns[i].username);
                                                        z++;
                                                        break;
                                                    }
                                                }
                                            }
                                            z--;
                                            printf("\nRESULTS\nFriends whose name matches with %s:\n",s);
                                            for(i=0;i<=z;i++)
                                            {
                                                printf("%s\t%s\n",search_result[i].name,search_result[i].username);
                                            }
                                            if(z==-1)
                                            {
                                               //if it does not exist
                                                printf("\n NOT FOUND\n");
                                            }


                                }
                        }break;
                        }break;

            case 5:
                   //Displays the names of the contacts which are not present in the friends list.
                   //This feature allows the users to add friend,which in turn moves the name from
                   //contact list to the friends list.
                           {
                               int flag=0;
                               char contact[50];
                               printf("QUICKADD:\n");
                               quickadd();
                               printf("Enter the name:\n");
                               scanf("%s",contact);
                               for(int i=0;i<global_count1;i++)
                               {
                                   if(strcmp(contact,cncts[i].cname)==0)
                                   {
                                        flag=1;
                                        strcpy(contact,cncts[i].cname);
                                   }
                               }
                               if(flag==1)
                               {
                                    headqa=delete_specific_qckadd(headqa);
                                    printf("Updated QuickAdd\n");

                                    display_qckadd(headqa);
                                    NODE newnode;
                                    newnode=malloc(sizeof(struct node));
                                    if(newnode==NULL)
                                    {
                                        printf("memory is not allocated \n");
                                    }
                                    strcpy(newnode->data,contact);
                                    newnode->next=NULL;
                                    if(head==NULL)
                                    {
                                        head=newnode;
                                    }
                                    else
                                    {
                                        newnode->next=head;
                                        head=newnode;
                                    }
                                    printf("\n");
                                    printf("Updated Friends list\n");
                                    display(head);
                               }
                               else
                               {
                                   printf("Name doesn't exist!\n");
                               }
                           }
                           break;

            case 6:
                    //Displays the contacts which may or may not be friends.
                    {
                        printcontacts();
                    }
                   break;

            case 7:printf("Friends to chat with:\n");
                print();
                head=delete_position(head);
                //we have used linked list here to store the whole data
                //sorting of the whole list takes place based on the last message sent.
                //The name of the person who was texted most recently will be visible
                //on the top of the list.
                {
                    if(head==NULL)
                    {
                        printf("List is empty \n");
                        break;
                    }
                    NODE temp=head;
                    //display of list based on last message.(last receipient on the top)
                    printf("Refreshed!\n");
                    while(temp!=NULL)
                    {
                        printf("%s\n",temp->data);
                        temp=temp->next;
                    }
                 }
                break;

            case 8:
                    // we also have an option where we can remove someone as a friend
                    // we have used delete node of linked list to do the same
                {
                    head=delete_specific(head);
                    printf("\n");
                    printf("Friends:\n");
                    display(head);
                }
                break;

            case 9:
                {
                    print();
                    int w;
                    //last saved chat can be viewed here.
                    char nme[20];
                    printf("\n");
                    printf("Enter the name to view the saved message with that user:\n");
                    scanf("%s",nme);
                    for(w=0;w<global_count;w++)
                    {
                        if(strcmp(nme,frns[w].name)==0)
                        {
                          printf("\n");
                          printf("Saved message with %s : %s\n",nme,m);
                          printf("\n");
                          break;
                        }
                    }
                    if(w==global_count)
                    printf("no such friend exists\n");

                } break;

                //This is an extra feature that we added . i.e sorting the list based on name
                //It makes easy for the user to locate the person whom he/she would like to contact
            case 10:{
                        int p;
                        printf("Press 0 to view friend list in random order\n");
                        printf("Press 1 to view friend list in sorted order\n");
                        scanf("%d",&p);
                        if(p==1)
                        {
                            bubblesort();
                        }
                        else
                        {
                            print2();
                        }
                    }

                     break;
            case 11:{
                int n;
                printf("Are you sure you want to logout?\n1 for YES, 0 for NO\n");
                //logout of snapchat
                scanf("%d",&n);
                if(n==1)
                {
                    printf("LOGGED OUT SUCCESSFULLY.\n");
                    exit(0);
                }
                else
                {
                    printf("Keep snapping :)\n");
                }
                    break;
            }

            default:printf("invalid choice\n");
        }
    }
    return 0;
}
