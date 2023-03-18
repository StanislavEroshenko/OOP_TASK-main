#include "hashtag.h"

std::string hashtag(std::string inputLine)
{
    if(!inputLine.length())throw std::invalid_argument("Short input line");
    std::string hashtag  = "#";
    bool upper = true;
    for (int i = 0; i < inputLine.length(); i++)
    {
        if (inputLine[i] != ' ')
        {
           if(upper)
           {
                if(islower(inputLine[i]))hashtag += toupper(inputLine[i]);
                else hashtag += inputLine[i];
                upper = false;
            }
           else hashtag += inputLine[i];
        }
        else upper = true;
    }
    if(hashtag.length() > 100)throw std::length_error("Too long outut line");
    else return hashtag;
}