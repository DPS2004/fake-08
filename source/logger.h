#pragma once

#include <stdio.h>

#if __PLAYDATE__

extern "C"
{
#include "pd_api.h"
}
void Logger_Initialize_Playdate(PlaydateAPI* playdate);

#endif

void Logger_Initialize(const char* pathPrefix);
void Logger_Exit();
void Logger_LogOutput(const char * func, size_t line, const char * format, ...);
void Logger_Write(const char * format, ...);
void Logger_WriteUnformatted(const char * message);


#define LOG(format, ...) Logger_LogOutput(__PRETTY_FUNCTION__, __LINE__, format, ## __VA_ARGS__)