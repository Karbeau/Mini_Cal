#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    // Year must be divisible by 4
    // Years that are divisible by 100 (1900 is NOT a LY) must be divisible by 400 
    if (year % 4 == 0 && year % 100 == 0) {
        if (year % 400 == 0){
            return true;
        }
        return false;

    } else if (year % 4 == 0){
        return true;
    } 
    return false;
}

// Placeholder, Jan, Feb, Mar...
int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 


void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add)
{
    //int days_left_in_month = 0;
    while (days_left_to_add > 0){
        int days_left_in_month = days_in_month[*mm] - *dd;
        if(*mm == 02 && is_leap_year(*yy)){
            days_left_in_month++;
        }
        if(days_left_to_add >= days_left_in_month){
            days_left_to_add -= days_left_in_month +1;
            *dd = 1;

            if(*mm == 12){
                *mm = 1;
                *yy = *yy + 1;
            } else 
                *mm = *mm +1;
        } else
            // days_left_to_add <= days_left_in_month
            *dd = *dd + days_left_to_add;
            days_left_to_add = 0;
    }
}

int main() {
    // int year;
    // printf("Input a year:");
    // scanf("%d", &year);

    // if(is_leap_year(year)){
    //     printf("Leap year!");
    // } else {
    //     printf("Not a leap year");
    // }

    int mm;
    int dd;
    int yy;
    int days_left_to_add;
    printf("Enter a date in the format mm dd yy plus anumber of days to add to this date (ex. 05 15 1997 12):");
    scanf("%d%d%d%d", &mm, &dd, &dd, &days_left_to_add);
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("%d %d %d", mm, dd, yy);
}
