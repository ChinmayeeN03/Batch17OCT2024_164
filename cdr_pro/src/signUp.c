#include<header.h>
 
//Performs the signup operation.
int signUp(char user_name[],char password [])
{
	char exist_user_name[MAX_LINE_LENGTH];
	char exist_password[MAX_LINE_LENGTH];
	FILE *fp;
	int flag=1;
 
	fp = fopen("./data/user_details.txt","r");
	if(fp == NULL)
	{
		printf("\nSorry,,please Try again\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while(fscanf(fp,"%s %s\n",exist_user_name,exist_password)==2)
		{
			if(strcmp(user_name,exist_user_name)==0)
			{
				flag=0;
				break;
			}
		}
	}
	fclose(fp);
	return flag;
}
