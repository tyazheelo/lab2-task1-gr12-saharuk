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

void previous_day_date(int *day, int *month, int *year)
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
    *day = days_in_month(*month, *year);
  }
  else
  {
    (*day)--;
  }    
}

void next_day_date(int *day, int *month, int *year)
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
  if(argc != 4)
  {
    printf("There should be 3 arguments\n");
    return 1;
  }

  int year = atoi(argv[1]);
  int month = atoi(argv[2]);
  int day = atoi(argv[3]);

  if (month < 1 || month > 12) {
    printf("Ошибка: месяц должен быть от 1 до 12\n");
    return 1;
  }

  if (day < 1 || day > days_in_month(month, year)) {
    printf("Ошибка: для месяца %d и года %d число должно быть от 1 до %d\n", 
           month, year, days_in_month(month, year));
    return 1;
  }

  printf("Исходная дата: %04d-%02d-%02d\n", year, month, day);
  printf("Дней в месяце: %d\n", days_in_month(month, year)); 
  printf("Год %s\n", is_leap_year(year) ? "високосный" : "не високосный");

  int prev_year = year, prev_month = month, prev_day = day;
  previous_day_date(&prev_day, &prev_month, &prev_year);
  printf("Предыдущий день: %04d-%02d-%02d\n", prev_year, prev_month, prev_day);

  int next_year = year, next_month = month, next_day = day;
  next_day_date(&next_day, &next_month, &next_year);
  printf("Следующий день: %04d-%02d-%02d\n", next_year, next_month, next_day);

  return 0;
}