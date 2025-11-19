#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/

bool Password::has_mixed_case(string str)
{
  bool has_lower = false;
  bool has_upper = false;
  for (char ch : str)
  {
    if (std::islower(ch))
    {
      has_lower = true;
    }
    else if (std::isupper(ch))
    {
      has_upper = true;
    }
  }
  return has_lower && has_upper;
}

// bool Password::has_mixed_case(string str)
// {
//   int count_lower = 0;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       count_lower++;
//     }
//   }
//   return count_lower > 0 && count_lower < str.length();
// }
// bool Password::has_mixed_case(string str)
// {
//   bool lower = false;
//   bool upper = false;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       lower = true;
//     }
//     else if (str[i] >= 'A' && str[i] <= 'Z')
//     {
//       upper = true;
//     }
//   }
//   return upper && lower;
// }
// Implementation D
// bool Password::has_mixed_case(string str)
// {
//   bool is_lower = false;
//   bool is_upper = false;
//   for (char c : str)
//   {
//     if (std::islower(c))
//     {
//       is_lower = true;
//     }
//     else
//     {
//       is_upper = true;
//     }
//   }
//   return is_lower && is_upper;
// }
// // Implementation E
// bool Password::has_mixed_case(string str)
// {
//   bool found = false;
//   for(char c : str){
//     if( !found && c >= 'A' && c <= 'Z' ){
//       found = true;
//     }
//     else if( found && c >= 'a' && c <= 'z'){
//       return true;
//     }
//   }
//   return false;
// }


/* Receives a string and returns a count of how many case-sensitive unique characters 
there are. If there are duplicate instances of the same character it should only count as a 
single character. Even if characters look similar, as long as they have distinct ASCII values, 
they should qualify as unique characters. */

unsigned int Password::unique_characters(string str){
  int count = 0;
  for(int i = 0; i < str.length(); i++){
    bool is_unique = true;
    for(int j = 0; j < i; j++){
      if( str[i] == str[j] ){
        is_unique = false;
        break;
      }
    }
    if( is_unique ){
      count++;
    }
  }
  return count;
}

