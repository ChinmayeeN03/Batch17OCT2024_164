/*#include<pthread.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#define MAXBUFF 1024
#define PORTNO 3001
*/
#include<header.h>
void menuc(int);
int main()
{
    static int cfd = 0, retValue=0;
    int choice;
    char ans[10]={0,};
    struct sockaddr_in serv_address;

    char buffer[MAXBUFF] = {0,};

    cfd = socket(AF_INET,SOCK_STREAM,0);

    if(cfd < 0)
    {
        perror("socket() ");
        exit(EXIT_FAILURE);
    }
    printf("\nSocket created with sockfd : %d",cfd);

    //reset/set address of client

    memset(&serv_address,'\0',sizeof(serv_address));

    // setting of Server side ipaddress and port no
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(PORTNO);
    serv_address.sin_addr.s_addr = INADDR_ANY;

    retValue = connect(cfd,(struct sockaddr *)&serv_address, sizeof(serv_address));
if(retValue < 0)
    {
        perror("connect()");
        exit(EXIT_FAILURE);
    }

    printf("\nClient: Connected to the server\n");


    // strcpy(msg,"\nHi This is from Client\n");
    while(1)
    {
        printf("\n***********************************************************\n");
        printf("Choose an Option:\n");
        printf("\n\n");
        printf("1. SignUp\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("************************************************************\n");
        printf("\n");
        printf("Enter your choice:\n ");

        // Input validation for choice
        while (1) {
            if (scanf("%d", &choice) != 1)
            {
                printf("Invalid input. Please enter a number: ");
                while (getchar() != '\n'); // Clear the input buffer
            }
            else if (choice < 1 || choice > 3)
                printf("Please enter a valid option (1-4): ");
            else
                break; // Valid input, break out of the loop

        }

        send(cfd, &choice, sizeof(choice), 0);
        switch(choice)
        {
        case 1:
                printf("\n Enter username");
                getchar();
                scanf("%s",buffer);
                send(cfd,buffer,sizeof(buffer),0);

                printf("\n Enter Password");
                memset(buffer, 0, sizeof(buffer));
                send(cfd,buffer,sizeof(buffer),0);
                break;
        case 2:

                printf("\n Enter username");
                getchar();
                scanf("%s",buffer);
                send(cfd,buffer,sizeof(buffer),0);

                printf("\n Enter Password");
                memset(buffer, 0, sizeof(buffer));
                send(cfd,buffer,sizeof(buffer),0);

                memset(buffer, 0, sizeof(buffer));
                recv(cfd,buffer,sizeof(buffer),0);
                printf("\n %s",buffer);
                if(strcmp(buffer,"Login Successful")==0)
                {
                    menuc(cfd);

                }
                break;
        case 3:
                close(cfd);
                exit(EXIT_FAILURE);


        default:
                  printf("\n Invalid choice \n");
                  break;
        }
    }

    // close(sfd);

    return 0;
}
void menuc(int cfd )
{
    char buffer[1024]={0,};
    char operator[50]={0,};
    long int msisdn;

    printf("\n \n");
    printf("\n 1. Process CDR File");
    printf("\n 2. Print/Search Billing Info");
    printf("\n 3. Logout");
   printf("\nEnter Choice:\n");
    int choice;
    scanf("%d",&choice);
    send(cfd,&choice,sizeof(choice),0);
    switch(choice)
    {
        case 1:
            recv(cfd,buffer,sizeof(buffer),0);
            printf("\n %s",buffer);
        case 2:
            printf("\n ");
            printf("1. Customer Billing \n");
            printf("2. Interoperator Billing \n");
            printf("Enter Choice: \n");
            getchar();
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("\n Enter MSISDN:");
                    scanf("%ld",&msisdn);
                    send(cfd,msisdn,sizeof(msisdn),0);
                    memset(buffer,sizeof(buffer),0);
                    recv(cfd,buffer,sizeof(buffer),0);
                    recv(cfd,buffer,sizeof(buffer),0);
                    printf("\n %s",buffer);
                    break;
                case 2:
                    printf("\n Enter Operator Name:");
                    getchar();
                    scanf("%s",operator);
                    send(cfd,operator,strlen(operator),0);
                    memset(buffer,sizeof(buffer),0);
                    recv(csfd,buffer,sizeof(buffer),0);
                    recv(cdfd,buffer,sizeof(buffer),0);
                    break;
            }
    }
}

                           
