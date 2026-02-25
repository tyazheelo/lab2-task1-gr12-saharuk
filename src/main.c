#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int year){
  if((year%4==0 && year%100!=0) || year%400==0){
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[])
{

}