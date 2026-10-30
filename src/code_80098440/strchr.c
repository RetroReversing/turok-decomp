#include "common.h"

unsigned char *strchr(unsigned char *s,int c){unsigned char x=(unsigned char)c;while(*s!=x){if(!*s)return 0;s++;}return s;}
