#include "common.h"

extern int func_80083BF4(unsigned long Keys[], int nItems, unsigned long SearchKey);
int func_80083BF4(unsigned long Keys[], int nItems, unsigned long SearchKey);
int func_80083BF4(unsigned long Keys[], int nItems, unsigned long SearchKey){
 unsigned int left, right, mid;
 if (nItems)
 {
  left = 0;
  right = ((unsigned int) nItems) - 1;
  while (left < right)
  {
   mid = (left + right) >> 1;
   if (Keys[mid] < SearchKey)
    left = mid + 1;
   else
    right = mid;
  }
  if (Keys[left] == SearchKey)
   return (int) left;
  else
   return -1;
 }
 else
 {
  return -1;
 }
}
