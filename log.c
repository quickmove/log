
#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "Log.h"

// get current date with format yyyyMMdd
int currentdate(char * currDate)
{
	struct tm *ptm = NULL;
	time_t tme;
	tme = time(NULL);
	ptm = localtime(&tme);
	char szTime[256];
	memset(szTime, 0, 256);
	sprintf(szTime, "%d%02d%02d", (ptm->tm_year + 1900),
		ptm->tm_mon + 1, ptm->tm_mday);
	strcpy(currDate, szTime);
	return 0;
}

// get current date time with format yyyy-MM-dd hh:mm:ss
int currenttime(char * currTime)
{
	struct tm *ptm = NULL;
	time_t tme;
	tme = time(NULL);
	ptm = localtime(&tme);
	char szTime[256];
	memset(szTime, 0, 256);
	sprintf(szTime, "[%d-%02d-%02d %02d:%02d:%02d] ", (ptm->tm_year + 1900),
		ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	strcpy(currTime, szTime);
	return 0;
}

int filepath(char* path)
{
	char currDate[256];
	memset(currDate, 0, 256);
	currentdate(currDate);
	
	strcat(path, LOGFILEDIR);
	strcat(path, LOGFILEPATH);
	strcat(path, currDate);
	strcat(path, ".log");
	return 0;
}

// write log
void log(int loglev,const char * format, ... )
{
	if (loglev>LOG_LEVEL) return;

	CreateDirectory(LOGFILEDIR, NULL);
	
	char temp[1024];
    memset(temp, 0, 1024);
    
    va_list args;
    va_start( args, format );
    vsprintf(temp, format, args );
    va_end( args );
    
    char currTime[256];
	memset(currTime, 0, 256);
    currenttime(currTime);
	
	char logpath[256];
	memset(logpath, 0, 256);
	filepath(logpath);
	
	FILE * pf = fopen(logpath, "aw");

	if (pf)
	{
		fputs(currTime, pf);
		fputs(temp, pf);
		fputs("\n", pf);
		
		fclose(pf);
	}
	
	

}

void loghex(int loglev,unsigned char *logmsg,int len)
{
	if (loglev>LOG_LEVEL) 
		return;
	char msg[1024];
	int ilen,i;
	ilen=len;
	if (ilen>512) ilen=512;
	for (i=0;i<ilen;i++)
	{
		sprintf(msg+i*2,"%02X",logmsg[i]);
	}
	log(loglev,msg);
}
