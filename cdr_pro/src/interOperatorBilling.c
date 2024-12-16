#include<header.h>


//Display the Inter operator billing data.
char * interOperatorBilling(IP *IOS,char mmc[])
{
    int k=0;
    int flag=0;
    char * mkg=(char *)malloc(MAXBUFF);
    bzero(mkg,MAXBUFF);
    while(k<5)
    {
        if(atol(IOS[k].opmmc)==atol(mmc))
        {
            char dum[MAXBUFF]={0,};
            strcat(mkg,"\n\nOperator Brand : ");
            strcat(mkg,IOS[k].opname);
            strcat(mkg," (");
            strcat(mkg,mmc);
            strcat(mkg,")");
            strcat(mkg,"\nIncoming voice call duration: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",IOS[k].incomingcall);
            strcat(mkg,dum);
            strcat(mkg,"\nOutgoing voice call duration: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",IOS[k].outgoingcall);
            strcat(mkg,dum);
            strcat(mkg,"\nIncoming SMS messages: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",IOS[k].incomingsms);
            strcat(mkg,dum);
            strcat(mkg,"\nOutgoing SMS messages: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",IOS[k].outgoingsms);
            strcat(mkg,dum);
            strcat(mkg,"\nMB downloaded: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",IOS[k].downloaded);
            strcat(mkg,dum);
            strcat(mkg," | MB uploaded: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",IOS[k].uploaded);
            strcat(mkg,dum);
            strcat(mkg,"\n\n");

            flag=1;
            break;
        }
        k++;
    }
    if(flag==1)
    {
            return mkg;
    }
    else
    {
        strcpy(mkg,"Operator not found!");

        return mkg;
    }
    return mkg;
}

//Download the processed Inter operator data in IOSB.txt file.
char * interOperatorBillingFile(IP *op)
{
    FILE *fp=NULL;
    fp=fopen("data/IOSB.txt","w+");
    char * mkg=(char *)malloc(2048);
    bzero(mkg,2048);
    int flag=0;
    if(fp==NULL)
    {
        perror("fopen()");
    }
    else
    {
        int z=0;
        strcpy(mkg,"\n\nInter operator billing!\n");
        strcat(mkg,"<----------------------------->\n");
        while(z<5)
        {
            char dum[MAXBUFF]={0,};
            strcat(mkg,"\n\nOperator Brand : ");
            strcat(mkg,op[z].opname);
            strcat(mkg," (");
            strcat(mkg,op[z].opmmc);
            strcat(mkg,")");
            strcat(mkg,"\nIncoming voice call duration: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",op[z].incomingcall);
            strcat(mkg,dum);
            strcat(mkg,"\nOutgoing voice call duration: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",op[z].outgoingcall);
            strcat(mkg,dum);
            strcat(mkg,"\nIncoming SMS messages: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",op[z].incomingsms);
            strcat(mkg,dum);
            strcat(mkg,"\nOutgoing SMS messages: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",op[z].outgoingsms);
            strcat(mkg,dum);
            strcat(mkg,"\nMB downloaded: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",op[z].downloaded);
            strcat(mkg,dum);
            strcat(mkg," | MB uploaded: ");
            bzero(dum,MAXBUFF);
            sprintf(dum,"%ld",op[z].uploaded);
            strcat(mkg,dum);
            strcat(mkg,"\n\n");
            z++;
            flag=1;
        }
    }
  if(flag==1)
    {
        fprintf(fp,"%s",mkg);
        bzero(mkg,MAXBUFF);
        strcpy(mkg,"yes");

        fclose(fp);
        return mkg;
    }
    else
    {
        fclose(fp);

        bzero(mkg,MAXBUFF);
        strcpy(mkg,"no");
        return mkg;
    }

    return mkg;

}

