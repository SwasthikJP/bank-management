#include<string>
#include<regex>
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isMobnum(string s)
{
    // The given argument to pattern()
    // is regular expression. With the help of
    // regular expression we can validate mobile
    // number.
    // 1) Begins with 0 or 91
    // 2) Then contains 6 or 7 or 8 or 9.
    // 3) Then contains 9 digits
  const regex pattern("(0|91)?[6-9][0-9]{9}");
  
  // regex_match() is used to
  // to find match between given number
  // and regular expression
  if(regex_match(s, pattern))
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool isEmail(const string& email)
{
  
    // Regular expression definition
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  
    // Match the string pattern
    // with regular expression
    return regex_match(email, pattern);
}

bool isLeap(int year)
{
// Return true if year
// is a multiple of 4 and
// not multiple of 100.
// OR year is multiple of 400.
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
    // If year, month and day
    // are not in given range
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
 
    // Handle February month
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
 
    // Months of April, June,
    // Sept and Nov must have
    // number of days less than
    // or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
 
    return true;
}