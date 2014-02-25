/**************************************
文件名：Log.h
描述：  写日志功能
版本： 0.1
作者： jj
完成日期：2013/12/26
***************************************/

#define LOGFILEDIR "c:\\lion\\log\\"
#define LOGFILEPATH "crt310_"
//根据日志级别写日志
#define LOG_ERR		0	//0=记录错误日志
#define LOG_NORMAL	1	//1=记录日常日志和错误日志
#define LOG_DEBUG	2	//2=记录错误日志日常日志调试日志
#define LOG_LEVEL	LOG_DEBUG

#ifndef _MSC_VER  
#define _MSC_VER 1600 
#endif      



void log(int loglev,const char * format, ... );
void loghex(int loglev,unsigned char *logmsg,int len);
