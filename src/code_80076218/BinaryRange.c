#include "common.h"

extern int BinarySearch(unsigned long Keys[], int nItems, unsigned long SearchKey);
extern int BinaryRange(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast);
int BinarySearch(unsigned long Keys[], int nItems, unsigned long SearchKey);
int BinaryRange(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast);
int BinaryRange(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast){
 int pos, first, last;
 pos = BinarySearch(Keys, nItems, SearchKey);
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
