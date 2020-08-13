#ifndef HELPER_H
#define HELPER_H

#include <ctime> //retrieve time to be used for triggers
#include <string>
#include <sstream> //converting various types to strings

//create a namespace to accept generic types and convert them to a string
namespace Helper
{
    template <class T>

    std::string ToString(const T &); //convert items to strings
    //example: ToString(5) -> 5 will be a string instead of an int

    struct DateTime //user defined types, like classes. Everything in structs are public by default.
    {
        DateTime()//local machine time on which the keylogger is running
        {
            time_t ms; //type which represents time (from ctime library); places system time into variable ms
            time (&ms); //reference time in ms as time

            struct tm *info = localtime(&ms);//info variable is a pointer to a struct tm
            //pointers are variables that contain the address (in ram) to another variable; when you access a pointer, you access the var to which it points
            //localtime takes ms as param and creates a value; info points to that value.

            D = info->tm_mday;//access attributes of DateTime
            m = info->tm_mon + 1;
            y = 1900 + info->tm_year;//human format year; 1900 is referent year;localtime will return the number of seconds since that date, so format this
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_seconds;

        }
    };
}


#endif // HELPER_H
