#include<header.h>
 
 
//Display the requested customer data
char * customerBilling(struct User *us,char *msisdnc[])
{
	int k=0,flag=0;
	char * mkg=(char *)malloc(MAXBUFF);
	bzero(mkg,MAXBUFF);
	long int n=100000;
	while(k<n)
	{
 
		if(atoi(msisdnc)==atoi(us[k].msisdn))
		{
			strcpy(mkg,"\n#Customers Data Base:\nCustomer ID: ");
			strcat(mkg,us[k].msisdn);
			strcat(mkg,"(");
			strcat(mkg,us[k].opbrandname);
			strcat(mkg,")");
			if(strcmp(us[k].opmmc,us[k].thirdparmmc)==0)
			{
				strcat(mkg,"\n\t*Services within the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
 
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
 
				strcat(mkg,"\n\t*Services outside the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
 
			else
			{
 
				strcat(mkg,"\n\t*Services within the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
 
				strcat(mkg,"\n\t*Services outside the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
 
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
 
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			flag=1;
 
 
			return mkg;
		}
		k++;
	}
	if(flag==0)
	{
 
		strcpy(mkg,"User not found!");
 
		return mkg;
	}
	return mkg;
}
 
 
//Download the requested customer data in CB.txt file
char * customerBillingFile(struct User *us,char msisdnc[])
{
	int k=0,flag=0;
	long int n=100000;
	char * mkg=(char *)malloc(MAXBUFF);
	bzero(mkg,MAXBUFF);
	FILE *fp=NULL;
	fp=fopen("data/CB.txt","w+");
	if(fp==NULL)
	{
		perror("fopen() ");
	}
	else{
	while(k<n)
	{
		if(atoi(msisdnc)==atoi(us[k].msisdn))
		{
			strcpy(mkg,"\n#Customers Data Base:\nCustomer ID: ");
			strcat(mkg,us[k].msisdn);
			strcat(mkg,"(");
			strcat(mkg,us[k].opbrandname);
			strcat(mkg,")");
			if(strcmp(us[k].opmmc,us[k].thirdparmmc)==0)
			{
				strcat(mkg,"\n\t*Services within the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
 
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
 
				strcat(mkg,"\n\t*Services outside the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
 
			else
			{
 
				strcat(mkg,"\n\t*Services within the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
 
				strcat(mkg,"\n\t*Services outside the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
 
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
 
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			flag=1;
			fprintf(fp,"%s",mkg);
			break;
		}
		k++;
	}
	}
	if(flag==0)
	{
		bzero(mkg,MAXBUFF);
		fclose(fp);
 
 
		strcpy(mkg,"failed");
		return mkg;
	}
	else
	{
		bzero(mkg,MAXBUFF);
		fclose(fp);
 
 
		strcpy(mkg,"success");
		return mkg;
	}
 
}
