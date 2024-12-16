#include<header.h>

//Process the data of CDR file for Customer billing.
char *Process_CDR_Customer_Biling(void *cargs)
{
        long int n=0;
        struct User *CS=(struct User*)cargs;
        FILE *fp;
        fp=fopen("data/data.cdr","r");
        if(fp == NULL)
        {
                return NULL;
        }
        else
        {
                char line[MAX_LINE_LENGTH]={0,};
                int i=0,j=0,token_count = 0;
                char tokens[9][MAX_LINE_LENGTH]={0,};
                while (fgets(line,MAX_LINE_LENGTH,fp) != NULL)
                {
                        for(i=0;line[i]!='\0';i++)
                        {
                                if(line[i]=='|')
                                {
                                        tokens[token_count][j]='\0';
                                        token_count++;
                                        j=0;
                                        continue;
                                }
                                tokens[token_count][j]=line[i];
                                j++;
                        }

                        n++;
                strcpy(CS[n-1].msisdn, tokens[0]);
            strcpy(CS[n-1].opbrandname, tokens[1]);
                strcpy(CS[n-1].opmmc, tokens[2]);
                strcpy(CS[n-1].caltype, tokens[3]);
                strcpy(CS[n-1].dur, tokens[4]);
                strcpy(CS[n-1].down, tokens[5]);
                strcpy(CS[n-1].upload, tokens[6]);
                strcpy(CS[n-1].thirdparmsisdn, tokens[7]);
                strcpy(CS[n-1].thirdparmmc, tokens[8]);
                        token_count=0;
                        j=0;
        }
    fclose(fp);
   }
    return NULL;
}

//Process the data of CDR file for Ineter operator billing.
char *Process_CDR_Operator_Biling(void *oargs)
{
        IP *op=(IP*)oargs;
        FILE *fp;
        fp=fopen("data/data.cdr","r");
        if(fp == NULL)
        {
                printf("\nfile error\n");
                return NULL;
        }
        else
        {

                char line[MAX_LINE_LENGTH]={0,};
                int i=0,j=0,token_count = 0;
                long int IN=0;
                char tokens[9][MAX_LINE_LENGTH]={0,};
                struct User *us=(struct User *)malloc(1*(sizeof(struct User)));
                while (fgets(line,MAX_LINE_LENGTH,fp) != NULL)
                {

                        us=(struct User *)realloc(us,(IN+1)*sizeof(struct User));
                        for(i=0;line[i]!='\0';i++)
                        {
                                if(line[i]=='|')
                                {
                                        tokens[token_count][j]='\0';
                                        token_count++;
                                        j=0;
                                        continue;
                                }
                                tokens[token_count][j]=line[i];
                                j++;
                        }

                        IN++;
                        strcpy(us[IN-1].msisdn, tokens[0]);
                strcpy(us[IN-1].opbrandname, tokens[1]);
                strcpy(us[IN-1].opmmc, tokens[2]);
                strcpy(us[IN-1].caltype, tokens[3]);
                strcpy(us[IN-1].dur, tokens[4]);
                strcpy(us[IN-1].down, tokens[5]);
                strcpy(us[IN-1].upload, tokens[6]);
                strcpy(us[IN-1].thirdparmsisdn, tokens[7]);
                 strcpy(us[IN-1].thirdparmmc, tokens[8]);

                        token_count=0;
                        j=0;
        }

                strcpy(op[0].opmmc,"42500");
                strcpy(op[1].opmmc,"42501");
                strcpy(op[2].opmmc,"42502");
                strcpy(op[3].opmmc,"42503");
                strcpy(op[4].opmmc,"42504");
                int k=0;
                while(k<5)
                {
                        bzero(op[k].opname,20);
                        op[k].incomingcall=0;
                        op[k].outgoingcall=0;
                        op[k].incomingsms=0;
                        op[k].outgoingsms=0;
                        op[k].downloaded=0;
                        op[k].uploaded=0;
                        k++;
                }
            char *mtc="MTC", *moc="MOC", *smsin="SMS-MT", *smsout="SMS-MO", *gprs="GPRS";
                k=0;
                while(k<IN)
                {
                        if(atol(us[k].opmmc)==atol(op[0].opmmc))
                        {
                                if(strcmp(us[k].caltype,mtc)==0)
                                {
                                        op[0].incomingcall=op[0].incomingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,moc)==0)
                                {
                                        op[0].outgoingcall=op[0].outgoingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,smsin)==0)
                                {
                                        op[0].incomingsms=op[0].incomingsms+1;
                                }
                                else if(strcmp(us[k].caltype,smsout)==0)
                                {
                                        op[0].outgoingsms=op[0].outgoingsms+1;
                                }
                                else if(strcmp(us[k].caltype,gprs)==0)
                                {
                                         op[0].downloaded=op[0].downloaded+atol(us[k].down);
                                        op[0].uploaded=op[0].uploaded+atol(us[k].upload);
                                }
                                strcpy(op[0].opname,us[k].opbrandname);
                                k++;
                        }

                        else if(atol(us[k].opmmc)==atol(op[1].opmmc))
                        {
                                if(strcmp(us[k].caltype,mtc)==1)
                                {
                                        op[1].incomingcall=op[1].incomingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,moc)==0)
                                {
                                        op[1].outgoingcall=op[1].outgoingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,smsin)==0)
                                {
                                        op[1].incomingsms=op[1].incomingsms+1;
                                }
                                else if(strcmp(us[k].caltype,smsout)==0)
                                {
                                        op[1].outgoingsms=op[1].outgoingsms+1;
                                }
                                else if(strcmp(us[k].caltype,gprs)==0)
                                {
                                        op[1].downloaded=op[1].downloaded+atol(us[k].down);
                                        op[1].uploaded=op[1].uploaded+atol(us[k].upload);
                                }
                                strcpy(op[1].opname,us[k].opbrandname);
                                k++;
                        }
                        else if(atol(us[k].opmmc)==atol(op[2].opmmc))
                        {
                                if(strcmp(us[k].caltype,mtc)==0)
                                {
                                        op[2].incomingcall=op[2].incomingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,moc)==0)
                                {
                                        op[2].outgoingcall=op[2].outgoingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,smsin)==0)
                                {
                                        op[2].incomingsms=op[2].incomingsms+1;
                                }
                                else if(strcmp(us[k].caltype,smsout)==0)
                                {
                                          
                                        op[2].outgoingsms=op[2].outgoingsms+1;
                                }
                                else if(strcmp(us[k].caltype,gprs)==0)
                                {
                                        op[2].downloaded=op[2].downloaded+atol(us[k].down);
                                        op[2].uploaded=op[2].uploaded+atol(us[k].upload);
                                }
                                strcpy(op[2].opname,us[k].opbrandname);
                                k++;
                        }
                        else if(atol(us[k].opmmc)==atol(op[3].opmmc))
                        {
                                if(strcmp(us[k].caltype,mtc)==0)
                                {
                                        op[3].incomingcall=op[3].incomingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,moc)==0)
                                {
                                        op[3].outgoingcall=op[3].outgoingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,smsin)==0)
                                {
                                        op[3].incomingsms=op[3].incomingsms+1;
                                }
                                else if(strcmp(us[k].caltype,smsout)==0)
                                {
                                        op[3].outgoingsms=op[3].outgoingsms+1;
                                }
                                else if(strcmp(us[k].caltype,gprs)==0)
                                {
                                        op[3].downloaded=op[3].downloaded+atol(us[k].down);
                                        op[3].uploaded=op[3].uploaded+atol(us[k].upload);
                                }
                                strcpy(op[3].opname,us[k].opbrandname);
                                k++;
                        }
                        else if(atol(us[k].opmmc)==atol(op[4].opmmc))
                        {
                                if(strcmp(us[k].caltype,mtc)==0)
                                {
                                        op[4].incomingcall=op[4].incomingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,moc)==0)
                                {
                                        op[4].outgoingcall=op[4].outgoingcall+atol(us[k].dur);
                                }
                                else if(strcmp(us[k].caltype,smsin)==0)
                                {
                                         
                                        op[4].incomingsms=op[4].incomingsms+1;
                                }
                                else if(strcmp(us[k].caltype,smsout)==0)
                                {
                                        op[4].outgoingsms=op[4].outgoingsms+1;
                                }
                                else if(strcmp(us[k].caltype,gprs)==0)
                                {
                                        op[4].downloaded=op[4].downloaded+atol(us[k].down);
                                        op[4].uploaded=op[4].uploaded+atol(us[k].upload);
                                }
                                strcpy(op[4].opname,us[k].opbrandname);
                                k++;
                        }
                }
                free(us);
        }
    fclose(fp);
        return NULL;

}

//Perform the data processing for both customer and inter operator using multi threading.
char *dataProcess(struct User *CS,IP *IOS)
{

        pthread_t CDthread,IDthread;
        pthread_create(&CDthread,NULL,Process_CDR_Customer_Biling,(void *)CS);
        pthread_join(CDthread,NULL);
        pthread_cancel(CDthread);
        pthread_create(&IDthread,NULL,Process_CDR_Operator_Biling,(void *)IOS);
        pthread_join(IDthread,NULL);
        pthread_cancel(IDthread);

}




                                                                                 
                                                          
