#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int day1, hour1, minute1, second1;
    int day2, hour2, minute2, second2;

    // Read and parse the start day
    string daystring;
    getline(cin, daystring);
    istringstream iss1(daystring.substr(4)); // Skip "Dia " part
    iss1 >> day1;

    // Read and parse the start time
    string timestring;
    getline(cin, timestring);
    timestring.erase(remove(timestring.begin(), timestring.end(), ' '), timestring.end()); // Remove spaces
    istringstream time1(timestring);
    string token;

    getline(time1, token, ':');
    hour1 = stoi(token);
    getline(time1, token, ':');
    minute1 = stoi(token);
    getline(time1, token);
    second1 = stoi(token);

    // Read and parse the end day
    getline(cin, daystring);
    istringstream iss2(daystring.substr(4)); // Skip "Dia " part
    iss2 >> day2;

    // Read and parse the end time
    getline(cin, timestring);
    timestring.erase(remove(timestring.begin(), timestring.end(), ' '), timestring.end()); // Remove spaces
    istringstream time2(timestring);

    getline(time2, token, ':');
    hour2 = stoi(token);
    getline(time2, token, ':');
    minute2 = stoi(token);
    getline(time2, token);
    second2 = stoi(token);

    // Calculate the difference
    int r_day = day2 - day1;
    int r_hour = hour2 - hour1;
    int r_minute = minute2 - minute1;
    int r_second = second2 - second1;

    if (r_second < 0) {
        r_second += 60;
        r_minute -= 1;
    }
    if (r_minute < 0) {
        r_minute += 60;
        r_hour -= 1;
    }
    if (r_hour < 0) {
        r_hour += 24;
        r_day -= 1;
    }

    printf("%i dia(s)\n%i hora(s)\n%i minuto(s)\n%i segundo(s)\n", r_day, r_hour, r_minute, r_second);

    return 0;
}
