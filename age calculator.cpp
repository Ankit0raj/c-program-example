// Code for Age calculator
#include <stdio.h>
#include <time.h>
//  Enter the day you were born       
//  mmddyyyy                
int main (void){
    int month, day, year, monthT, dayT, yearT;
    printf("Enter your Date in ddmmyyyy format\n");
    scanf("%2d%2d%4d", &month, &day, &year);
    time_t seconds = time(NULL);
    struct tm *now = localtime(&seconds);
    monthT = now->tm_mon + 1;
    dayT = now->tm_mday;
    yearT = now->tm_year + 1900;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(yearT % 4 == 0){
    days[1] = 29;
    }
    
    int day_month = days[now->tm_mon];
    int month_before = days[month - 2];
    if(month == 0){
        month_before = days[12];
    }
     printf("The current date is %02d-%02d-%d\n", monthT, dayT, yearT);
    if(month < monthT)
        if(day > dayT)
        printf("\nYou are %d years, %d months, and %d days old.", yearT - 1 - year, 12 - month + now->tm_mon - 1, dayT + month_before - day);
        else
        printf("\nYou are %d years, %d months, and %d days old.", yearT - 1 - year, 12 - month + now->tm_mon, dayT - day);
    
    else if(month > monthT)
        if(day > dayT)
        printf("\nYou are %d years, %d months, and %d days old.", yearT - 1 - year, 12 - month + now->tm_mon - 1, dayT + month_before - day);
        else
        printf("\nYou are %d years, %d months, and %d days old.", yearT - 1 - year, 12 - month + now->tm_mon, dayT - day);
    
    else
        if(day > dayT)
        printf("\nYou are %d years, %d months, and %d days old.", yearT - 1 - year, 11, day_month - (day - dayT));
        else
        printf("\nYou are %d years, %d months, and %d days old.", yearT - year, 0, dayT - day);
    
}
