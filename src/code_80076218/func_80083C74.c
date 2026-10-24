#include "common.h"

extern int func_80083BF4(unsigned long Keys[], int nItems, unsigned long SearchKey);
extern int func_80083C74(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast);
int func_80083BF4(unsigned long Keys[], int nItems, unsigned long SearchKey);
int func_80083C74(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast);
int func_80083C74(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast){
 int pos, first, last;
 pos = func_80083BF4(Keys, nItems, SearchKey);
 if (pos == -1)
  return 0;
 first = pos;
 while (first--)
  if (Keys[first] != SearchKey)
   break;
 *pFirst = first + 1;
 last = pos;
 while (++last < nItems)
  if (Keys[last] != SearchKey)
   break;
 *pLast = last - 1;
 return 1;
}
