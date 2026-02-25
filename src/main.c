#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int year){
  if((year%4==0 && year%100!=0) || year%400==0){
    return 1;
  }
  return 0;
}

int days_in_month(int month, int year)
{
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(month == 2 && is_leap_year(year)){
    return 29;
  }
  return days[month-1];
}

void previous_day(int *day, int *month, int *year)
{
  if(*day == 1){
    if(*month == 1){
      (*year)--;
      *month = 12;
    }
    else
    {
      (*month)--;
    }
    *n = days_in_month(*month, *year);
  }
  else
  {
    (*day)--;
  }    
}

void next_day(int *day, int *month, int *year)
{
  if(*day < days_in_month(*month, *year))
  {
    (*day)++;
  }
  else
  {
    if(*month == 12)
    {
      (*year)++;
      *month = 1;
    }
    else
    {
      (*month)++;
    }
    *day = 1;
  }
}
int main(int argc, char *argv[])
{

}