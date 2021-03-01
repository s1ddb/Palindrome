#include <iostream> // required for cout, and cin
#include <cstring> 


/* 
By Siddhartha Bobba
Date: 02/22/2021

A program to ask the user for their input so it can check if the user input is a palindrome or not, while disregarding spaces, punctuation and any other characters that are not alphabets. The program scans through the input of the user and sees if it's the same when it's reversed as it is when entered so it can return palindrome or not a palindrome.

*/



using namespace std;

int main()
{
    // Get input from the user.
  char userinput[80]; // variable to track the user's input, limited to 80 characters
  int textlength; //variable to calculate the length of the user's input
  int lastchar; //variable to track the last character of the input entered.
  char reinput[80]; // variable to store the recount of the OG input so it can remove punctuation and spaces later in the code
  int recount; 


  for (int i = 0; i <= 80; i++) //to clear the memory
    {
      userinput[i] = '\0';
      reinput[i] = '\0';
    }

  cout << "Enter any text to check for Palindrome or not:" << endl; // asks the user to enter any text
  cin.get(userinput,80); // stores the user's input, alternative to 'cin' as it categorizes spaces or white spaces and a return, so the code disregards anything after the space.
  cin.get(); //to clear the infinite loop of returns after the end of the previous cin.
  
  textlength = strlen(userinput) - 1;
  

  for (int i = 0; i <= textlength; i++) //for loop to scan through the user's original input

    {

      // if statement to convert lower case characters to capitals characters

      // ACSII VALUES FOR CONVERTING UPPER CASE TO LOWER CASE, DIFFERENCE IS 32 FOR UPPER TO LOWER
      if (userinput[i] >= 65 && userinput[i] <= 90) // this also ignores coping over anything outside the upper case values, which includes punctuation, etc.

	
	{
	  //if (userinput[i] = 32)
	  //{
	  // recount++;
	      //}
	  reinput[recount] = userinput[i] + 32; // adds 32 to the ASCII value of the upper case letter to convert them to lower case
	  recount++; //increments the recount if the ASCII values are within the range of 65 to 90 which are UPPER case letters
	}
      


      // if statement for lowercase to keep lower case characters lower cased. 
      if (userinput[i] >= 97 && userinput[i] <= 122) // if the userinput is within the lower case ASCII values, keep it lower cased.
	
	{
	  reinput[recount] = userinput[i];
	  recount++; 
	}



      
    }

  cout << reinput << endl;

  textlength = strlen(reinput); //sets the variable textlength to take the length of the re arranged user's input without any punctuation or spaces
  


  
  lastchar = textlength - 1; // subtracts 1 from the last character of the textlength variable and subtracts 1 as the count starts at 0


  
    // Boolean to store if we found a palindrome or not
    bool isPalindrome = true;

    // Loops back through the user's input checking if the last character is equal to the first, second, etc and decrements down as it scans
    for (int i = lastchar; i >= textlength/2; i--)
    {

      
        // Check the palindrome condition and returns false if not a palindrome
        if (reinput[i] != reinput[lastchar - i])
        {
            isPalindrome = false;
            break;
        }
    }

    // Outputs the result to user
    if (isPalindrome)
    {
      cout << "Palindrome" << endl;
    }
    else
    {
      cout << "Not palindrome" << endl;
    }

    return 0;
}
