#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<pthread.h>
 
#define MAXBUFF 1024
#define PORTNO 65534
#define MAX_LINE_LENGTH 1024
struct User
{
    char msisdn[20];
    char opbrandname[64];
    char opmmc[20];
    char caltype[10];
    char dur[10];
    char down[10];
    char upload[10];
    char thirdparmsisdn[10];
    char thirdparmmc[10];
}a;
struct IP
{
    char opmmc[20];
    char opname[20];
    long int incomingcall;
    long int outgoingcall;
    long int incomingsms;
    long int outgoingsms;
    long int downloaded;
    long int uploaded;
}b;

int signUp(char [],char []);
int logIn(char [],char []);
char *dataProcess(struct User *, struct IP *);
char *customerBilling(struct User *,char* []);
char *customerBillingFile(struct User *,char* []);
char *interOperatorBilling(struct IP *,char* []);
char *interOperatorBillingFile(struct IP *);
 
#endif
