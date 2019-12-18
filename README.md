# algorithmproject
Application that fills the blanks in a given statement using the input text.
Abstract
Searching long documents and retrieving information from them can take long time. This can be the result of long-term operation, even on highly configurable computers. Using correct algorithm at these points has major role in saving time and performance improvement. Therefore, it is significant to choose right algorithm.

Keywords
C++, String, Search, Text, Algorithm, Performance, Data, Pattern, Underscore

Objective

We have two text files. One text file (“truman_show_script.txt”) is very long. Other text file (“statements.txt”) has statements. Also, one word has been extracted from these statements and word has been replaced with three underscores. Our goal is to find that missing word in “truman_show_script.txt” file and print out the whole sentence.


















Algorithm

We have used C++ language to make this project. 

We have used below libraries; 
<iostream>
<string>
<fstream>
<ctype.h>
<cstring>
<chrono>

We have used these libraries to ;

•	take inputs from txt files,
 

•	calculate running time,
 

•	use isalpha() method for checking if some char’s value is alphabetic or not,
 





•	use string methods

 

We have tried many pattern searching algorithms. However, we could not make progress with them. We have decided to apply another algorithm and we have used naive pattern searching algorithm. Since, it is simply written and uncomplicated algorithm we could make progress easily. Normally, Naive Algorithm would only slides the pattern over text one by one and check for a match, if a match is found, then slides by 1 again to check for subsequent matches. In our case, we have missing words replaced by underscores. Therefore, we’ve changed the algorithm in our favor.    
We handled underscore cases in search method. We have used ”if else”s to handle some cases. 
We have tried to write our code according to every situation. Average speed of our algorithm is 0.070 seconds. 

Challenges

•	We spent most of the time to choose right algorithm to use
•	Trying to handle all underscore situations.

Conclusion

Text search can become a very complex problem, and if it is not properly programmed, it may take a long time to implement and test. This problem can be solved more quickly by keeping the complexity low and keeping the values of the comparison sites without complicated the solution.

References

Naive algorithm for Pattern Searching
https://www.geeksforgeeks.org/naive-algorithm-for-pattern-
Convert a file stream to a string

https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

General information about pattern searching algorithms
https://www.geeksforgeeks.org/
