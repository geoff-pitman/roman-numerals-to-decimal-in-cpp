// Problem: Convert Roman numerals to decimal equivalent
// C++ Solution
// 9/4/2016

#include<iostream>
#include<string>
#include<fstream>
#include<map>

using namespace std;

int main()
{
	
   /************************   VARIABLE DECLARATIONS  *******************/	
	// holds in-file in ifstream variable
	ifstream inf;
	
	// output stream variable we will use to write to a file
	ofstream outf;
	
	// total sum of current roman numeral string
	int decimalSum = 0;
	
	// current value being looked at
	int currentVal = 0;
	
	// keeps track of highest value looked at
	int maxVal = 0;
	
	// holds current string of roman numerals
	string numerals = "";
	
	// create associative array for roman numerals
	map<char, int> roman;
	roman['C'] = 100;
	roman['L'] = 50;
	roman['X'] = 10;
	roman['V'] = 5;
	roman['I'] = 1;
   /*********************************************************************/

     
	// open file to read from
	inf.open("roman_numerals.txt");
	
	// open file to write to
	outf.open("output_numerals.txt");
	
// In the code below,  inf >> numerals , will read characters and put them in the 
// buffer stream until it hits white space. The stream is then inserted into the 
// string variable ' numerals ' .  The body of the loop will then execute.
// When the end of the file is reached the operator>>() function will flag false,
// which kills the loop.
// 
// !!!!! Don't forget that operators are functions in C++ !!!!!!
// inf >> numerals is the same as operator>>(inf, numerals)

	while (inf >> numerals)
	{
		for (int i = numerals.length()-1; i >= 0; i--)
		{
		  // numerals[i] resolves to a char, which is passed to the associative array, roman[ ]
			currentVal = roman[numerals[i]];
			
			if (currentVal == maxVal) 
				decimalSum += currentVal;
			if (currentVal < maxVal)
				decimalSum -= currentVal;
			if (currentVal > maxVal)
			{
				decimalSum += currentVal;
				maxVal = currentVal;
			}
		}
	   
	   // output to console
	   cout << endl << numerals << " translated to decimal equivalent -> " 
	        << decimalSum << endl; 
	
	
	   // write the same output to file
	   outf << endl << numerals << " translated to decimal equivalent -> " 
	        << decimalSum << endl; 
			
	   decimalSum = 0;
	   currentVal = 0;
	   maxVal = 0;
	}
	
	// close output file stream
	outf.close();
	
	return 0;
}
