#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void fill_time(char* buffer, int format);
void fill_date(char*);
int input_formate();
void clear_screen();


int main() {
    char time[50];
    char date[100];
    int format = input_formate();

    while (1){
    fill_time(time, format);
    fill_date(date);
    clear_screen();
    printf("\n\n ⁠✧ Current Time (IST): %s\n", time);
    printf("\n ⁠✧ Date: %s\n", date);
    sleep(1);  //sleeps for 1 second
    }
    return 0;
}

void clear_screen(){
   #ifdef _WIN32
    system("cls");
   #else
    system("clear");
    #endif
}

int input_formate() {
    int format;
    printf("⁠✧ Choose Time Format:~ ⁠✧ \n");
    printf("\n1. 24-Hour Format ʕ⁠´⁠•⁠ᴥ⁠•⁠`⁠ʔ✧\n");
    printf("\n2. 12-Hour Format (default) ʕ⁠´⁠•⁠ᴥ⁠•⁠`⁠ʔ✧\n");
    printf("\nMake a choice (1/2): ");
    scanf("%d", &format);
    return format;
}

void fill_date(char *buffer) {
    time_t raw_time;
    struct tm *current_time;

    // Get the current time
    time(&raw_time);
    
    // Adjust time for IST (UTC+5:30)
    raw_time += 5 * 3600 + 30 * 60;

    current_time = gmtime(&raw_time);  // Use gmtime to avoid local time zone adjustments
    strftime(buffer, 100, "%A %B %d %Y", current_time);
}

void fill_time(char* buffer, int format) {
    time_t raw_time;
    struct tm *current_time;

    // Get the current time
    time(&raw_time);
    
    // Adjust time for IST (UTC+5:30)
    raw_time += 5 * 3600 + 30 * 60;

    current_time = gmtime(&raw_time);  // Use gmtime to avoid local time zone adjustments
    if (format == 1) {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    } else {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

