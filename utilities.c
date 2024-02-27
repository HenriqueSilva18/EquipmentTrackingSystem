#include "utilities.h"
#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int isValidDate(int day, int month, int year) {
    int daysInFeb;
    if (month == 2) {
        daysInFeb = (isLeapYear(year)) ? 29 : 28;
        return (day <= daysInFeb);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return (day <= 30);    
    }
    return (day <= 31);
}

Date getDate(char *dayPrompt, char *monthPrompt, char *yearPrompt) {
    Date date;
    do {
        date.day = getInt(MIN_DAY, MAX_DAY, dayPrompt);
        date.month = getInt(MIN_MONTH, MAX_MONTH, monthPrompt);
        date.year = getInt(MIN_YEAR, MAX_YEAR, yearPrompt);
        if (!isValidDate(date.day, date.month, date.year)) {
            printf("Invalid date. Please try again.\n");
        }
    } while (!isValidDate(date.day, date.month, date.year));
    return date;
}

