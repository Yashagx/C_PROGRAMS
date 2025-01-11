/*******************************************************************************
*
* Program: Print The First Letter Of Each Word In A String 
* 
* Description: Program to print the first letter of each word in a string using
* C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jT-fh-fvJDo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
  // char array which stores a test string where first letter of each word 
  // gives us "HDMI"
  char string[] = "High Definition Multimedia Interface";
  
  // Find the length of the string (not including null terminator character 
  // which signifies the end of the string).
  int length = strlen(string);

  // We'll go through the string one character at a time and keep track of 
  // whether we are currently "reading a word" or not using reading_word, in 
  // order to help output the first letter of each word.  We initialize it to
  // false because we have not yet read any characters yet.
  bool reading_word = false;
  
  // Loop counter variable i will go through each index of the string in order
  // one at a time with each loop iteration.  We use i to examine the string 
  // one character at a time.  We consider words to consist of characters from
  // a-z and A-Z and all other characters to be non-word characters.  The 
  // isalpha() function returns true if a character it is passed is from a-z 
  // or A-Z, and false otherwise.  The algorithm works by keeping reading_word
  // up to date as to whether we are currently reading a word, and when we 
  // transition from not reading a word to reading a word we output the first 
  // character of that word.
  for (int i = 0; i < length; i++)
  {
    // If we are NOT currently reading a word and the character we are currently
    // examining IS a letter, we have encountered the first letter of a new 
    // word.  We set reading_word to true to acknowledge we are now reading a 
    // word, and we output this first letter of the word.
    if (!reading_word && isalpha(string[i]))
    {
      reading_word = true;
      printf("%c", string[i]);
    }
    // If we ARE currently reading a word and the character we are currently 
    // examining is NOT a letter, we have reached the end of a word and set 
    // reading_word to false to acknowledge this.
    else if (reading_word && !isalpha(string[i]))
    {
      reading_word = false;
    }
  }
  printf("\n");
  
  return 0;
}