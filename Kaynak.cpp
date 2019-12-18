#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cstring>
#include <chrono>
using namespace std;
using namespace chrono;

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int wordBegin;
	int wordFinal;
	int wordSize;
	int leap = 0;
	


	
	for (int i = 0; i <= N - M; i++) {// for block to proceed in truman_show_script
		int j;
	


		for (j = 0; j < M; j++) {// for block to proceed in statements' pattern
			
			if (pat[j] == '_') { //if block to handle underscore situations
				if (j + 3 != M) { //if block to handle if underscore is in the end of the statement or not

					wordBegin = i + j;//we keep the index of missing word's initial.
				

					int temp = i + j;
					while (!isalpha(pat[j])) { //leaps j to next word with checking pat[j] is alphabetic or not(j would increment till we rid underscores, spaces, special chars etc.)
						
						j++;
					}
					


					while (isalpha(txt[temp])) { //leaps temp to the index of missing word's end +1
						temp++;

					}
					if (txt[temp] > 33 && txt[temp] < 47) { //handles if missing word contains special characters (e.g "light.")
						temp++;
					}
					wordFinal = temp;//word's end +1

					wordSize = wordFinal - wordBegin; //missing word's size

					leap = wordSize - 3; // difference between sentence in text and sentence in pattern would be wordSize - 3. Because there are 3 underscores in pattern.



				}
				else { //if underscore is in the end of the statement this else block will execute
					
					wordBegin = i + j;//we keep the index of missing word's initial.
					int temp = i + j;

					while (isalpha(txt[temp])) { 
						temp++;

					}
					wordFinal = temp;
					j += 3; //we increment j by 3 to end for loop and print completed statement afterwards...
					
				}
			}


			if (txt[i + j + leap] != pat[j]) { //checking inequality of text and pattern if there exists inequality it would break inner for loop and continue to outer loop
				break;
			}
			


		}


		if (j == M) { //If there is successful match this if block will execute
			cout << "Completed Statement:";
			
			for (j = 0; j < M; j++) {
				
				if (pat[j] == '_') {
					
					for (int t = wordBegin; t < wordFinal; t++) {

						cout << txt[t];
					}
					j += 2;
				}
				else {
					cout << pat[j];
				}
			}
			cout << "\n";
			cout << "/==========================================================================/" << endl;
			break;
		}

		else if (i == (N - M)) { //If there is unsuccessful match this if block will execute
			cout << "Statement NOT found" << endl;
			cout << "/==========================================================================/" << endl;
		}
	}
}



int main() {
	auto start = high_resolution_clock::now();//start timer
	ifstream text("the_truman_show_script.txt");
	ifstream statements("statements.txt");
	string sentence;
	string strtext((istreambuf_iterator<char>(text)), istreambuf_iterator<char>());//converting txt file to string
	int n = strtext.length();
	char* textChar;
	textChar = new char[n];//creating an dynamic char array

	strcpy(textChar, strtext.c_str());//converting string to charArray
	while (getline(statements, sentence)) {

		int n = sentence.length();
		char* words;

		words = new char[n];//creating an dynamic char array


		strcpy(words, sentence.c_str());//converting string to charArray

		cout << "Original Statement: " << sentence << endl;
		search(words, textChar);


	}
	auto stop = high_resolution_clock::now();//stop timer
	auto duration = duration_cast<milliseconds>(stop - start);
	auto durati = duration_cast<seconds>(stop - start);

	cout << "Running Time = " << duration.count() << " ms and " << durati.count() << " sec" << endl;
	cout << (double)duration.count() / 1000 << " sec" << endl;

}


