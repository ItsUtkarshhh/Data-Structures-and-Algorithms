// Data Structures and Algorithms
// Data Structures : They are way to arrange data in main memory for efficient usage and they are ingredients to make good algorithms. Example : Arrays, Stacks, Linked List, Queue, Binary Search Trees.
// Algorithms : Sequence of steps to solve a given problem. Eg : Sorting an Array
// Database : Collection of information in permanent storage for faster retrieval and updation.
// Data warehouse : Management of huge amount of legacy data for better analysis. Legacy data is that data which is stored for analysis purposes and now it has no use. like facebook stores some data like how many times you viewed one profile and how many times you commented a particular comment, these data are of no use but they are being stored to analyse and create algortihms, this is dataware house.
// Big Data : Analysis of too large complex data which cannot be dealt with traditional data processing application, like making a search engine will require you a lotttt of data that a normal or general processing computer can't even store.

// ---------------------------------------------------------- LECTURE 1 - Basics --------------------------------------------------------------------------------------------------------->

// To solve a problem we do the following steps like, understand the problem, look for the given values, analyse the approach to be taken to solve the problem and then start programming!
// But proper program likhne se pehle hum ek rough code/solution likhte hai jisko hum pseudo code kehte hai!
// Pehle hum solution sochte hai rough format me and then uske liye ek flowchart and pseudo code likhte hai and then hum proper program likhte hai code krke and then vo code machine level language me convert hota hai and then vo execute hota hai!

// Flowchart : A diagramatic representation of the program/approach is called a flowchart! isme hum kuch symbols ka use krke apne rough solution ko diagramatic form me represent krte hai!
// Pseudo Code : Generic way of representing a particular solution so that it can be coded in different languages!

// FLowchart Components : Oval block (represents that the program start or ends here), parallelogram block (represents input/output), rectangle (represents a process), and then a decision block (used for if/else statement)!
// Suppose you want to create a flowchart of the sum of two statements, so it will be like : [Already done in handwritten notes! or if not then visit Love Babbar vdo 1 of DSA Series at 9:42 minutes]
// Pseudo code for the above program will be, Start -> Read a, b -> sum = a + b -> print sum -> end!, And pseudo code is a generic code which represents a code in a most general way such that it can be coded in other languages also!

// In these notes, only the exclusively DSA se related cheeze hi hai, basic cheeze bhaut kam hai! So if you want to study basics then go and visit the notes of C/C++/Python!
// Compiler is used to translate code and find errors in the code like compile time error amnd runtime error!
// In code the compilation start with int main() and flowchart me jo start vaala component hota hai vo int main() ke liye hota hai!
// C++ me jo using namespace std; likhte hai, iska mtlb ye hai ki like C++ me kuch namespaces hote hai unme se hum std vaala namespace use krna chahte hai! like example cout function alag alag namespace me alag type se define hoga, pr hume std vaala jo defintion hai cout ka usko use krenge output print krne ke liye!

// Modulus operator does not support float values!
// Also writing printf(0) in C is not right! and will give the runtime error!

// How the cpp file converts to the execultable file!
// Preprocessing -> Compilation -> Assembler -> Linker
// Preprocessor : Isme ye hota hai ki jo bhi pre processor directives hote hai, like file inclusion, macros expansion and all! ye sab hota hai like jo bhi hum likhte hai #include me vo saari directories and files include hoti hai file me! and saare macros expand hote hai like #define and all! and then iss step me humari ".cpp" file ".i" file me convert hoti hai!
// Compilation : Isme jo humari preprocessed file hai vo ".i" se ".s" me convert hoti hai! and jo humara C++ ka code hai vo aseembly code me convert hota hai! also iss process me saare errors and all check hote hai!
// Assembler : Isme jo humari compiled file hoti hai ".s" vaali ye ".o" object file me convert hoti hai! means isme jo assembly code hai vo machine language code me convert hota hai! and the object file contains machine-level code, along with other information necessary for linking. 
// Linker : Isme saari object files include hoti hai and then ek final ".exe" file banti hai, jo aakhri final executable file hoti hai! 

// Type Casting in C++ :
#include<iostream>
using namespace std;

int main() {
    int a = 'b';
    cout<<a<<endl; // Yahaa kya hua ki jab a ko int data type diya and then usme ek character store krne ki koshish ki tab implicit conversion hogya int se char me and jo int value (ASCII value) b se map krti hai vo print hogyi!

    char ch = 99;
    cout<<ch<<endl; // Yahaa bhi vaisa hi hua jo upar hua, yahaa pr jab humne 99 jo ek integer value hai jab humne vo store krne ki koshish ki tab 99 jiss character se map hota hai ASCII table ke according vo charcater print hojayega, here that character is c toh vo print hogya! 

    char ch2 = 123456;
    cout<<ch2<<endl; // Yahaa as we know that int me 0 -> 2^31-1 tak ki values store ho sakti hai, and char me 0 -> 2^8-1 tak ki values print ho sakti hai! so what if agar hum koi 2^16 jaisi value store kraane ki koshish kre toh in character, tab kya hoga? then jo least significant byte mtlb jo rightmost 8 bits hongi (as becoz char 1 byte = 8 bits ki value store krta hai) toh utni values ko lekr utne ko hi character me convert hojayega and vo print hojayegi!
} //Means like here in ch2 we tried to store 123456, so ho sakta hai jo rightmost byte hogi usme 64 ban rha hoga and 64 maps with @ character in the ASCII table, toh bss vo print hogya!

// Now abhi tak toh hum ye samajh gye ki positive numbers kaise store hote hai memory me, but negative numbers kaise hote hai store?? So ans is that if first bit is 1 it is -ve and if 0 then +ve!
// If we want to store a negative values in the memory then first we ignore the -ve sign and then we take its 1's complement and then 2's complement and now the leftmost bit will tell the sign if its 0 then +ve and 1 then -ve!
// Example : int a = -5 ko agar store krna hai, so it will be like : first we will ignore the -ve sign hence, 00000000 00000000 00000000 00000101 -> 11111111 11111111 11111111 11111010 (1's complement) -> 11111111 11111111 11111111 11111011 (2's complement), hence ab ye store hojayega! and jo leftmost bit hai vo iska sign btaa rha hai that's negative!

// Now if we want to print that -ve value -5, so ab as we know ki memory me toh ye 11111111 11111111 11111111 11111011 stored hai, so ab pehle 1's complement hoga, steps will be, 11111111 11111111 11111111 11111011 -> 00000000 00000000 00000000 00000100 (1's complement) -> 00000000 00000000 00000000 00000101 (2's complement), now as we know the final value jo aayi vo toh +5 denote krti hai, toh value yahaa se lelenge and sign jo value pehle stored thi memory me which was this 11111111 11111111 11111111 11111011, toh yahaa se uska sign lelenge (that's the leftmost bit 1 and hence it represents the sign) and aise ye negative value print hojayegi!

// All the data types are : int, float, char, long, double, long double, long long!
// Other than all these data types, there are some ways of declaring data types, signed and unsigned! signed means all +ve and -ve values of that range! then unsigned is only for +ve values range!

// "const" keyword : The const keyword in C and C++ is used to declare constants - variables whose values cannot be changed after initialization!
//                 : Use case 1 : const int MAX_VALUE = 100; This declares a constant MAX_VALUE with the value 100. Once initialized, its value cannot be modified.
//                 : Use case 2 : void printMessage(const char* message) { printf("%s\n", message); } The const keyword can be used in function parameters to indicate that the function will not modify the value passed to it. This can help prevent accidental modifications and improve code clarity.
//                 : Use case 3 : const int* ptr; Pointer to Constant Data : Ye line ka matlab hai ki ptr ek pointer hai jo constant integer data ko point karta hai. Iska matlab hai ki ptr dvara point kiye gaye data ko modify nahi kiya ja sakta, lekin khud pointer ko dusre data ko point karne ke liye change kiya ja sakta hai.
//                 : Use case 4 : int x = 10; int* const ptr = &x; Constant Pointer : This declares a constant pointer ptr that points to an integer. Once initialized, the pointer itself cannot be changed to point to another memory location, but the data it points to can be modified. means it is just opposite of pointer to constant data!
//                 : Use case 5 : Constant Member Functions (C++) : In C++, the const keyword can be used to declare member functions as constant. These functions promise not to modify the state of the object they are called on. This is particularly useful in classes to ensure that certain member functions don't modify the object's state accidentally. example : class MyClass { public: void print() const { printf("Value: %d\n", value); } private: int value; };
//                 : Use case 6 : Return Values : In C++, you can declare a function's return value as const. This indicates that the return value should not be modified by the caller. example : const int getValue() { return 42; }

// ---------------------------------------------------------- LECTURE 2 - Basics --------------------------------------------------------------------------------------------------------->

// And now we have 2 variation while assigning a data type, that is signed and unsigned, signed jab hota hai toh -(2^31-1) -> (2^31-1) itni range ki values store ho sakti hai and jab unsigned hota hai tab 0 -> (2^31-1) values store hoti hai! means only positive values!
#include<iostream>
using namespace std;

int main() {
    unsigned int a = -123;
    cout<<a<<endl; // It will print : 4,294,967,173, Reason : By default int is always signed, if we make it unsigned and then if we will try to store a -ve value tab kya hoga ki jo abhi hum upar kr rhe the print kraane time 1's complement ke baad 2' complement leke, and last me jo humne last me jo value aayi thi usko and previously jo stored value thi jisme leftmost bit 1 tha unn dono ko humne under consideration leke -ve value print kraya tha na, pr ab jab humne pehle hi int ko unsigned declare kiya hua hai toh ab iss baar vo previously stored value ko dhyaan nhi dega and seedha jo final value thi usko print krdega! and hence it will print a very large number!
}

// Some extra info : int/int = int, float/int = float, double/int = double

// A little overview on relational operartor!
#include<iostream>
using namespace std;

int main() {
    int a = 1;
    int b = 0;

    int first = a>b; // And similarly we can do with other relational operators!
    cout<<first<<endl;

    int second = a&&b; // And similarly we can do this with other logical operators!
    cout<<second<<endl;
}

// ---------------------------------------------------------- LECTURE 3 - Basics + Pattern Making --------------------------------------------------------------------------------------------------------->

// Conditional statements me agar hum else if use kr rhe hai, toh bina hum else ke bhi end kr sakte hai, it depends on our use, vrna sirf elseif me end krne pr koi dikkat nhi hai!
// Pattern making :
// Practice Question 1 : Draw a pattern with 4 rows and 4 columns!
#include<iostream>
using namespace std;

int main() {
    int n; 
    cin>>n; // This is the input of ki kitni rows me * print krwaane hai, if its 5 means ki hum 5 rows me * print krwaana chahte hai!
    int i = 1;
    while(i<=n) { // toh humne loop chlaa diya 1st row se nth row tak
        int j = 1;
        while(j<=n) { //Now ab harr row me kitne * print krne hai vo j vaala loop decide krega!
            cout<<"*";
            j++;
        }
        cout<<endl; // Once we will be done printing the * in one row, so now we will change the row and move on to the next row!
        i++;
    }
} //Understand the logic here, we used the outer loop to switch between rows and inner loop to print the * (switch between columns)!

// Practice Question 2 : Print 1 three times in 1st row, 2 three times in 2nd row, 3 three times in 3rd row!
// Using While Loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Using For Loop
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i;
    for(i=1; i<=n; i++) {
        int j;
        for(j=1; j<=n; j++) {
            cout<<i;
        }
        cout<<endl;
    }
}

// Using Do While Loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    do {
        int j = 1;
        do {
            cout<<i;
            j++;
        } while (j<=n);
        cout<<endl;
        i++;
    } while (i<=n);
}

// Basic Questions
// Question 1 : Write a Program to Display Fibonacci Series upto certain number n (n is entered by user) Example: n = 100, Output : Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
// This code is in C language!
#include <stdio.h>

void printFibonacciSeries(int n) {
    int a = 0, b = 1, next;
    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return;
    }
    printf("Fibonacci Series: ");
    if (n >= 0) {
        printf("%d", a);
    }
    if (n >= 1) {
        printf(", %d", b);
    }
    next = a + b;
    while (next <= n) {
        printf(", %d", next);
        a = b;
        b = next;
        next = a + b;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printFibonacciSeries(n);
    return 0;
}

// Question 2 : Find the GCD of 2 numbers input by the user!
// Code is in C language!
#include<stdio.h>

int GCD(int a, int b) {
    while(b!=0) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",GCD(a,b));
}

// Question 3 : Find LCM of 2 numbers entered by the user!
// Code is in C language!
// Approach : We can find LCM with the formula, LCM(a,b) * GCD(a,b) = a*b
#include<stdio.h>

int GCD(int a, int b) {
    while(b!=0) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("LCM of the 2 numbers is : %d",(a*b)/(GCD(a,b)));
}

// Solving the above question without finding GCD!
#include <stdio.h>

int findLCM(int a, int b) {
    int max = (a > b) ? a : b;
    
    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;
        }
        max++;
    }
}

int main() {
    int num1 = 4;
    int num2 = 6;

    int lcm = findLCM(num1, num2);
    printf("LCM of %d and %d is %d\n", num1, num2, lcm);
    return 0;
}
// Method to calculate HCF/GCD is hum dono numbers ke factors nikalte hai! and then unme se jo jo common hote hai unko apas me product krke jo value hoti hai vo final HCF/GCD hota hai!
// Method for calculating LCM is hum dono numbers ko again factorize krte hai! and then unme se jo jo maximum powers hai saare numbers ki unko apas me product krke final LCM nikal lete hai! 

// ---------------------------------------------------------- LECTURE 4 - Pattern Making --------------------------------------------------------------------------------------------------------->
// Here we will be solving only questions related to patterns!
// Practice Queston 3 : Create a pattern like there are 4 rows and 1st column contains only 1, 2nd column contains only 2, 3rd column contains only 3, 4th column contains only 4!
// Using only While loop, we can try it into for and do while loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 4 : Create a pattern where it has three rows and 1 2 3 in first row, 4 5 6 in 2nd row and 7 8 9 in 3rd row!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    int count = 1;
    while (i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 5 : Print the star pattern, where 1st row has 1 star, 2nd row has 2 stars and so on..
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 6 : Print 1 one time in 1st row, 2 two times in 2nd row and so on....
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 7 : Print 1 in 1st row, 2 3 in 2nd, 4 5 6 in 3rd and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    int count = 1;
    while (i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 8 : 1 in 1st row, 2 3 in 2nd row, 3 4 5 in 3rd row, 4 5 6 7 in 4th row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        int count = i;
        while(j<=i) {
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Without count
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = i;
        while(j<2*i) {
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another approach for without count...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row =  1;
    while(row<=n) {
        int col = 1;
        while(col<=row) {
            cout<<row+col-1<<" ";

            col++;
        }
        cout<<endl;
        row++;
    }
}

// Practice Question 9 : Print 1 in 1st row, 2 1 in 2nd row, 3 2 1 in 3rd row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int count = i;
        int j = 1;
        while(j<=i) {
            cout<<count;
            count--;
            j++;
        }
        cout<<endl;
        i++;
    }
}
// Solving the above question without using an extra variable count!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<i-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// My Approach, it is similar to without using extra variable, but in a more understanding way
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row =  1;
    while(row<=n) {
        int col = 1;
        while(col<=row) {
            cout<<row-(col-1)<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}

// Practice Question 10 : Print ABCDE in each row as input by the user.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        char j = 1;
        char val = 'A';
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 11 : Print A three times in 1st row, B three times in 2nd row, C three times in 3rd row and so on...
// My Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<val;
            j++;
        }
        cout<<endl;
        val++;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            char ch = 'A'+i-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 13 : Print A B C in every row as input by the user!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A';
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another Approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row = 1;
    while(row<=n) {
        int col = 1;
        while(col<=n) {
            char ch = 'A'+ col - 1;
            cout<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}

// Practice Question 14 : Print A B C and then D E F in the next line and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<val;
            j++;
            val++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 15 : Print A B C, B C D in next row, C D E in next row and so on...
// My Solution #1 :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        val--;
        val--;
        cout<<endl;
        i++;
    }
}

// My Solution #2 :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    while(i<n) {
        char val = 'A'+i;
        int j = 1;
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            char ch = 'A'+i+j-2;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// My Solution #3 : More easy to understand
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row = 1;
    while(row<=n) {
        char ch = 'A'+(row-1);
        int col = 1;
        while(col<=n) {
            cout<<ch<<" ";
            ch++;
            col++;
        }
        cout<<endl;
        row++;
    }
}

// Practice Question 16 : Print A, B B then C C C and so on...
// My Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<val;
            j++;
        }
        val++;
        cout<<endl;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            char val = 'A'+i-1;
            cout<<val;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 17 : Print A, B C, D E F, G H I J and so on....
// My Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 18 : Print A, B C, C D E, D E F G and so on...
// Love babbar solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A'+i+j-2;
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}
// To observe the pattern you need to make a matrix and then find that formula, like here it is A + i + j - 2, isko nikalne ke liye make a matrix and then find the pattern!

// Practice Question 19 : Print a pattern like D, C D, B C D, A B C D and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A'+n-i+j-1; // char val = 'A'+n-i+j-1; isme j-1 krne ka koi logic nhi hai, isko hataa bhi doge and sirf n-row likhoge toh bhi same answer ayega kyunki inner loop exit hone ke baad col/j toh firse 1 hi ho jaa rha hai iske kaaran baar baar j-1 krne pr 0 hi ho jaa rha hai! and hence just write it as 'A' + n - row; its enuf!
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A'+n-i;
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 20 : Print this ___* in first row, __** in 2nd row, _***, in 3rd row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        // Pehle Spaces print krlo
        int space = n-i;
        while(space) {
            cout<<" ";
            space--;
        }

        // Then stars print krlo
        int j = 1;
        while(j<=i) {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 21 : Print this **** in 1st row, ***_ in 2nd row, **__ in 3rd row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n-i+1) {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 22 : Print this ****, _***, __**, ___* and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i;
    for(i = 1; i <= n; i++)
    {
        int space;
        for(space=0; space<i-1; space++) {
            cout<<' ';
        }
        int stars;
        for(stars=0; stars<=n-i; stars++)
            cout<<'*';
        cout<<endl;
    }
}

// ---------------------------------------------------------- LECTURE 5 - Bitwise Operators --------------------------------------------------------------------------------------------------------->
// Bitwise Operators!
// There are 4 types of bitwise operators! AND (&) OR (|) NOT (~) XOR (^)
// These operators works on the bit level... Example :
// AND (&) : Suppose we are doing 2 & 3, then its output will be decided at the bit level, like... 2 -> 10 and 3 -> 11 now we will do the AND operation of each bit, as 10 & 11 and it will give 10 which is 2 and hence the output will be 2, we must have to do the normal AND operation!
// OR (|) : Similarly as above, 2 | 3, it can be written as 10 | 11 and its output will be... 11 and it is 3, hence the output will be 3!
// NOT (~) : Here it is a little different, like ~2, now we know that int is 4 bytes and we know that it stored as 00000000 00000000 00000000 00000010 in the memory, so iska NOT krna hai, so poore ka NOT krna hai toh one's complement lelo, and it will be... 11111111 11111111 11111111 11111101 and now ab we isko print krna hai, toh ab we know kaise print krte hai, pehle most significant bit denote krta hai sign which is -ve, now baaki remaining bits ka 2's complement lenge, and we know 2's complement kaise lete hai, that is 1's complement and then add 1 and uske baad final answer ayega and hence the answer will be, (left most significant bit toh sign ke liye use hogyi toh uske alawa remaining bits ko convert krliya decimal me) (1)0000000 00000000 00000000 00000011 and hence the answer will be -3
// XOR (^) : Here its like, jo same bits hoti hai unka output 0 and opposite bits hoti hai unka output 1, so 2 ^ 3 ka output hoga 10 ^ 11 will be 1! according to the truth table of XOR!

// Now some more featured are, left-shift and right-shift, which will be done, suppose you are said to do "3<<2" it means 3 ko 2 baar left shift krdo, means 3 ke harr bit ko 2 baar left me shift krdo! hence, 00000000 00000000 00000000 00000011 isko 2 baar right shift krne ka mtlb hua ki 00000000 00000000 00000000 00001100, and it will be 12, and same is the right shift...
// Also a note that mostly aisa lgega ki left shift krne se number 2 se multiply ho jaate hai, and ye baat kaafi hadd tak sahi bhi hai, like upar hi dekhlo, 3<<2 me 3 me 2 times 2 multiply hogya and answer mila 12, which is 3x2x2, so mostly cases me yhi hoga, bss right shift me 2 se divide hota hai... But in case of large numbers ye nhi hoga, kyunki reason being... suppose a number 01000000 00000000 00000000 00000010, this is a very large number, toh yahaa kya hoga ki agar humne isko 1 baar left shift krdiya, toh most significant but 1 banjayega, and isse vo number -ve number ban jayega, so yahaa aisa bhi hota hai, so that's why this shorcut is not valud for very large number, but for small number it is valid!
// Baki ye toh baat hogyi +ve numbers ki, like ek aur cheez hoti hai that is padding, means jab hum left shift kr rhe hai toh right me 0's add kr rhe hai means +ve numbers me 0 ki padding hoti hai, but -ve numbers ka kuch ptaa nhi hota, answer will be depended on compiler!

// Now lets program it! :
#include<iostream>
using namespace std;

int main() {
    // Bitwise Operators!
    cout<<(2&3)<<endl;
    cout<<(2|3)<<endl;
    cout<<(~2)<<endl;
    cout<<(2^3)<<endl;

    // Left-Shift and Right_Shift!
    cout<<(3<<2)<<endl;
    cout<<(2>>2)<<endl;
    cout<<(5<<1)<<endl;
    cout<<(5>>1)<<endl;
}

// Some Questions on post-increments, pre increments and For Loops!
// Now there is one "break" statement, iss instruction se jo immediate loop hota hai usse exit hojaate hai!
// Now there is one "continue" statement, iss instruction se jo immediate next line of execution hota hai, usko skip krdete hai and uske baad ke line execute hote hai!
// Also in for loop where we know that there is one section of iteration, then condition and then increment or decrements, so one add on to that, is teeno section me ek se zyada iterations, conditions and increments add kr sakte hai!
#include<iostream>
using namespace std;

int main() {
    {
        int a, b = 1;
        a = 10;
        if(++a) {
            cout<<b;
        }
        else {
            cout<<++b;
        }
    }
    {
        int a = 1;
        int b = 2;
        if(a-- > 0 && ++b > 2) {
            cout<<"Stage 1 - Inside If";
        }
        else {
            cout<<"Stage 2 - Inside Else";
        }
        cout<<a<<" "<<b;
    }
    {
        int a = 1;
        int b = 2;
        if(a-- > 0 || ++b > 2) {
            cout<<"Stage 1 - Inside If";
        }
        else {
            cout<<"Stage 2 - Inside Else";
        }
        cout<<a<<" "<<b;
    }
    {
        int a = 1;
        int b = 2;
        if(a-- > 0 || ++b > 2) {
            cout<<"Stage 1 - Inside If";
        }
        else {
            cout<<"Stage 2 - Inside Else";
        }
        cout<<a<<" "<<b;
    }
    {
        int number = 3;
        cout<<25*(++number);
    }
    {
        int a = 1;
        int b = a++;
        int c = ++a;
        cout<<a<<b<<c;
    }
    {
        for(int i= 0; i<=5; i++) {
        cout<<i<<" ";
        i++;
        }
    }
    {
        for(int i= 0; i<=5; i--) {
        cout<<i<<" ";
        i++;
        }
    }
    {
        for(int i= 0; i<=15; i+=2) {
        cout<<i<<" ";
        if(i&1) {
            continue;
        }
        i++;
        }
    }
    {
        for(int i=0; i<5; i++) {
            for(int j=i; j<=5; j++) {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    {
        for(int i=0; i<5; i++) {
            for(int j=i; j<=5; j++) {
                if(i+j==10) {
                    break;
                }
                cout<<i<<" "<<j<<endl;
            }
        }
    }

}
// Now as of this course of Love Babbar DSA, now its time for watching out operators precedence, but that is not very important, we can always go and check to get to know that, but kuch yaad rehna chahiye, so they are...
// Priority order : 1) ! 2) *, /, % 3) +, - 4) <, <=, >=, > 5) ==, != 6) && 7) ||

// Leetcode Question 1 : Subtract the product and sum of all the digits of an Integer!
// Approach : Yahaa hum ek number input kraate hai toh vo number ke harr digit ka product and sum ka subtraction nikalna hai and vo print krna hai,
// toh approach will be as we know that kisi number ka 10 se modulo lenge toh o milega vo uss number ka one's place ka digit hoga and then uss number ko hum divide krenge,
// and jo number milega usme se vo one's vaala digit hatt jayega, and then iss new digit ko hum firse iss loop me bhejenge, jisse ye sab firse hoga and tab tak hoga jab tak n 0 na hojaye!
// For example : 234 isme 234%10 will give 4 we will keep it in line of sum and product, now we will divide the 234 with 10 and now we will get 23, and now we will put this again through the whole loop,
// as ab 23%10 hoga and we will get 3 and now ab ye 3 pehle vaale 4 se multiply and add hoga and iss value ko store krlenge, and now firse 23 ko 10 se divide krenge and we will get 2 and now firse isko loop me daalenge,
// and now 2%10 will give 2 and now ab ye sum and product me jaake multiply and add honge and then now 2/10 krenge toh 0 hojayega and ab loop exit hojayega! and we will get the answer!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int rem;
    int product = 1;
    int sum = 0;
    for(; n!=0;) {
        rem = n%10;
        product = product * rem;
        sum = sum + rem;
        n = n/10;
    }
    int answer = product - sum;
    cout<<answer;
}

// Another way of writing the above syntax!
#include<iostream>
using namespace std;

int main() {
    int n;
    // cin>>n;
    int rem;
    int product = 1;
    int sum = 0;
    for(cin>>n; n!=0; n/=10) {
        rem = n%10;
        product = product * rem;
        sum = sum + rem;
    }
    int answer = product - sum;
    cout<<answer;
}

// Leetcode Question 2 : Number of 1 Bits, find the number of 1 bits in the unsigned integer input by the user!
// Approach : Isko solve krne ke 2 ways ho sakte hai, pehle ki harr number ko decimal to binary me convert kro and then iterate krke check kro harr place pr 1 hai ya nhi and then finally vo count print krdo!
// Another approach is ki harr inout ko binary me convert krke right shift krke count krlo number of 1's!
#include<iostream>
using namespace std;

int main() {
    uint32_t n;
    int count = 0;
    for(cin>>n; n!=0; n=n>>1) { // Yahaa isko hum aise bhi likh sakte hai, "n>>=1" as a shortcut! 
        // Yahaa pr hume sirf 1st bit check kr rhe hai, as we know that koi bhi number ho maanlo 5, toh iska binary representation hota hai 0101, toh bss iska 1 ke saath & kr rhe hai and jab jab ye 1 dega tab tab if condition true hojayegi and tab tab count++ ho jayega!
        // and then right-shift krke firse & krenge 1 ke saath, toh jitni baar condition true hogi utni baar count hote jayega! and after all the right-shift it will end!
        if(n&1) {
            count++;
        }
    }
    cout<<count;
}

// ---------------------------------------------------------- LECTURE 6 - Binary to Decimal --------------------------------------------------------------------------------------------------------->
// How to convert Decimal to Binary and vice versa!
// Decimal to Binary Conversion :
// 1st Approach : Let a number we want to convert to binary be n, now first we divide that number n by 2, then we store its remainder in another variable in answer variable, then we repeat the previous two steps until the number n!=0, and finally now we do the reverse of the number which was stored in the remainder.
// For example : Suppose we have a number 10, now we will divide it with 2, we will get 5 and remainder = 0 -> Now we will divide that 5 which was obtained as quotient by 2, and now we will get the quotient = 2 and remainder = 1 -> Now we will again divide that quotient 2 by 2 and now we will get the quotient = 1 and remainder = 0 -> Now we will again divide the quotient by 2 and now we will get the quotient = 0 and remainder = 1. And now as our quotient = 0 (or can say our n=0, so now we will stop this process) So the final value obtained is 0101, but this is not 10, so now we will reverse the final number obtained and we will get 1010 and that is the final answer!

// 2nd Approach : Agar hum thora soche, toh we can see that kisi number ka 1 ke saath bitwise & krne pr, agar output 1 aaye toh vo ek odd number and agar 0 aaye toh vo ek even number hai! Another way of looking at it is like agar kisi number ka 1 ke saath bitwise & krne pr 1 output aata hai toh mtlb ki uske rightmost bit 1 hai, and vahi agar output 0 aaye toh mtlb ki uska rightmost bit (jisse hum calculate kr rhe hai) 0 hai, so from here we can see that ki hum kisi number ka 1 ke saath bitwise and krne se hum uska rightmost bit nikal sakte hai, toh bss hum aise hi krenge and after humne rightmost bit ka nikal liye ek baar, toh fir uss number ko rightshift krdenge taaki baaki ke places me bhi konsi bit hai 1 ya 0 vo nikal sake,
// hence our flow will be, We will find the bitwise & of that number with 1 and then we will do the rightshift and then again we will find the bitwise & with 1, and we will do it until we have checked all the bits! But now the thing is how we will create or generate our final answer! so for that we will create a formula...
// Initiallize a variable ans = 0; now, yahaa hum digit vaale variable me vo saare bits rakhenge jo upar bitwise & vaale operation kr kr ke obtained hue hai!
// Demo : Suppose our given number is 5, so applying the above 2nd approach to find its binary form, from the above bitwise & process humne iske alag alag bits nikal liye hai, but unn sabko saath me rakh ke ek number bnane ke liye we will apply this formula, and it will go like...
// ans = (10^0 * 1) + ans; -> ans = 1
// ans = (10^1 * 0) + ans; -> ans = 01
// ans = (10^2 * 1) + ans; -> ans = 101, hence we got our final answer!

// Also the above formula is used to find the reverse of the number given to us! like agar 1,2,3 diya hota toh ye formula ans = (10^i * digits) + ans; toh iss formula se answer aata 321. but upar 101 me pta nhi chlaa ye cheez kyunki humaare paas 1,0,1 number aaye toh unko ulta ya seedha likhe koi fark nhi pad rha tha, but yes this formula is used to reverse the digits and form a number.
// But if we want ki like, 1,2,3 ka 123 ban jaye, then we use....
// Initiallize the ans = 0; then we use this formula : ans = (ans * 10) + digit;
// Demo : Suppose we have given three numbers 1,2,3 so now, we will proceed like...
// ans = (0 * 10) + 1; -> ans = 1
// ans = (1 * 10) + 2; -> ans = 12
// ans = (12 * 10) + 3; -> ans = 123, That's how we get our final answer!

// Now actually implement the above things :
// First Approach :
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0) {
        int rem = n%2;
        ans = (ceil(pow(10,i)) * rem) + ans; // Here we have to use the ceil function, becoz pow function gives double value! and so isliye hume isko inlcude krna padega! vrna sahi answer nhi ayega!
        i++;
        n = n/2;
    }
    cout<<ans;
}

// Second Approach :
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int i = 0;
    while(n!=0) {
        int digit = n&1;
        ans = (ceil(pow(10,i)) * digit) + ans; // Here again we have to use the ceil function for the previous reasons!
        n = n>>1;
        i++;
    }
    cout<<ans;
}

// Converting a -ve number into binary! We already know the logic, like how a -ve number is stored in binary in memory, and then how it is printed, we already know the logic and theory, but now lets implement it in code!
#include <iostream>
using namespace std;

// Function to convert a decimal number to binary and print it
void printBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    // Print the binary representation using two's complement for negative numbers
    printBinary(n);

    return 0;
}
// Here kya ho rha hai ki jo number humne input kiya jaise -10, vo seedha jaake memory me toh -ve number jaise store hote hai vaise hi store hoga! and then hum bss ye code uss binary representation ko as it is print krde rha hai! and same cheez +ve numbers ke case me bhi hoti hai kyunki usme hum koi convert nhi krte, hum bss jo input aaya vo jaise jaake memmory ke form me store hua hai usko hi as it is print krdete hai!
// So yahaa agar -10 input krenge, toh being a -ve value ye 11111111 11111111 11111111 11110110 aise store ho rakha hoga memory me! toh humne bss isko ((n >> i) & 1) krke print krte gye! and here we get the answer!
// And ye code +ve integers ko bhi print krdega! jaise vo memory me stored hai!
// Toh upar vaali do approaches ka kya kaam hai? so they are more specific to performing operations on that input taaki smallest answer mile! as becoz upar vaale approaches me toh hum 5 ka binary 101 nikal paa rhe hai kuch operations krke! but isme hum vo 32 bit int variable me kaise stored hai vo dekh paa rhe hai!
// Both are correct approaches! but for negative this is the one! kyunki upar vaale approaches -ve decimals ko convert nhi kr rhe hai binary me!

// Binary to Decimal Conversion :
// So our approach here will be like, as we know hum binary numbers ko mathematically kaise dekhte hai, that is 2 ki power me! so hum right se left jaate hue 2 ki ek power badhaa dete hai! So...
// So whenever we will encounter 1 while going right to left of the binary number we increase the power of 2 with 1 and then we will print the answer!
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0) {
        int digit = n%10;
        if(digit == 1) {
            ans = ans + ceil(pow(2,i));
        }
        i++;
        n = n/10;
    }
    cout<<ans;
}
// But here we need to keep somethings in mind and they are, jab input le rhe hai tab hum, like for example, agar kisine 101 input diya toh vo actually hum ek decimal 101 number input de rhe hai naa ki binary number, toh agar binary se decimal convert krna hai toh hume binary number hi input dena hoga!
// Toh vo kaise hoga? Toh what we have done above is we have divided the input number with 10 and then we have used the remainder taaki fir hum bit by bit krke binary se decimal me comvert krne ke liye code likh sake!
// Vaise agar jab hum thore aur concepts padh lenge tab hum strings ko use krke binary se decimal convert kr sakte hai! taaki jo number hum input kr rhe hai vo bit by bit krke string ke harr ek entry me store hojaye! and that's how thing will proceed!

// Before moving on, lets clarify one important concept! and that reversing the number and printing the number in the same order! So it all depends on in which order you are picking the digits! Last se pick krna shuru kiye ho, ya starting se pick krna shuru kiye ho! kyunki uske basis pr hum "digits" nikalte hai!
// Agar starting se hi numbers pick krna shuru kiye ho tab toh koi dikkat nhi hai, digits vhi honge jo given order me hai!
// But agar last se digits pick krna shuru krna hai then digits aise nikaloge, digits = n%10;
// Now, Jiss order me numbers pick kiye hai uss hi same order me print krna chahte ho toh use this formula : ans = (ans * 10) + digits;
// Jiss order me numbers pick kiye hai uske reverse order me print krna chahte ho toh use this formula : ans = (10^i * digits) + ans;

// ---------------------------------------------------------- LECTURE 7 - Leetcode Questions --------------------------------------------------------------------------------------------------------->
// Practice Question 1 : Reverse an Integer! but if it goes out of the range of int them print 0! 
#include<iostream>
#include<math.h>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0) {
        int digit = n%10;
        if( (ans>INT_MAX/10 || ans < INT_MIN/10)) {
            cout<<0;
        }
        ans = (ans * 10) + digit;
        n /= 10;
        i++;
    }
    cout<<ans;
}

// Practice Question 2 : Complement of an Integer!
// Approach : We will get an input but that will be in decimal! so first we will use negation (~) and then we will get a number, but as we know that int number are of 32 bits so, lets understand with an example...
// Suppose we have a number 5, its binary form is 101, but in 32 bits it is 00000000 00000000 00000000 00000101, now its negation will be ~5 = 11111111 11111111 11111111 11111010, now the rigtmost 3 bits are the answer we need! so now kisi tarah we need to remove the rest of the bits on the left of 010, so for that we will proceed like, we know that agar hum unn remaining 1's ka & lele 0 ke saath and 010 ka 1's ke saath & lele toh hum unn sabko 0 bnaa sakte hai and 010 bach jayega! so then we will left with 00000000 00000000 00000000 00000'010' and we will get the answer!
// So overall hume aisa koi number create krna padega, jisse ye strategy which we discussed above kaam kre, toh for that we create that number and let that number be called mask, because it will mask all the bits except our answer bits!
// So we will create it like...jo number input me mila hai usko right shift krte jayenge, and har right shift me check krenge ki vo 0 hua hai ya nhi! ab 0 ho jayega toh stop hojayenge, lets understand this with an example, 00000000 00000000 00000000 000000101, now we will right shift, so after 3 times right-shifting, vo number ab 0 ban jayega! toh now we now that left se 29 bits pr 0 chahiye and baaki right ki remaining 3 pr 1 chahiye!
// So now we will do the start the left-shifting, and ab iss baar jab bhi left shift kr rhe honge toh 1 ke saath 'or' krenge taaki jo bhi nayaa padding vaala zero aaye vo 1 ke saath 'or' me 1 ban jaye, and that is how we will get the mask! continue the above example : abhi tak we got, 00000000 00000000 00000000 00000, on doing three times left shifting and then performing 'or' operation with 1 will attach 1 bits to its rightmost bits, and we will get, 00000000 00000000 00000000 00000111 and this is the mask we needed!
// Overall what actually happened her is this...
// 1) Entered number (5) : 00000000 00000000 00000000 00000101
// 2) Performed (~5) :     11111111 11111111 11111111 11111010
// 3) Mask created :       00000000 00000000 00000000 00000111
// Answer :                00000000 00000000 00000000 00000010
// 2nd and 3rd step me & operation perform krne ke baad we got our final answer!
// Now lets code the above things :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int num = n;
    int mask = 0;
    // Boundary condition! this is that one condition jo humne upar poore approach me discuss nhi ki hai kyunki isko alag se likhna hoga as an exceptional condition!
    if(n==0) {
        cout<<1;
    }
    while(num!=0) {
        mask = (mask << 1) | 1;
        num = num >> 1;
    }
    int ans = (~n) & (mask);
    cout<<ans<<endl;
}

// Practice Question 3 : Power of two, display yes if a number can be represented in form of power of 2, and if no then print no!
// Approach : Simple bss yhi ki harr 2 ki power ko jo int me possible hai usko check krke dekh liya input vaale number se and then uske according print krdiya Yes or No!
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    bool flag = false;
    for(int i = 0; i<31; i++) {
        int ans = pow(2,i);
        if(n == ans) {
            cout<<"Yes";
            flag = true;
        }
    }
    if(flag == false) {
        cout<<"No";
    }
}


// ---------------------------------------------------------- LECTURE 8 - Switch Case and Functions! --------------------------------------------------------------------------------------------------------->
// A demo example for switch case!
#include<iostream>
using namespace std;

int main() {
    int num = 1;
    switch (num)
    {
    case 1:
        cout<<"First case"<<endl;
        break;
    case 2:
        cout<<"Second case"<<endl;
        break;
    default:
        cout<<"Default case"<<endl;
        break;
    }
}
// Here break statement help krta hai jab humari jo condition match hojaati hai, uss case ko execute krne ke baad poore switch statement se bahar aane me!
// Like agar aise likha hota....
// Toh iss case me case 1 ans 2 dono execute hojaate! kyunki pehla case jab jab match kiya condition se and jab execute hua toh uske baad break nhi kiya humne, iss hi kaaran case 2 bhi execute hogya!
#include<iostream>
using namespace std;

int main() {
    int num = 1;
    switch (num)
    {
    case 1:
        cout<<"First case"<<endl;
        // break;
    case 2:
        cout<<"Second case"<<endl;
        break;
    default:
        cout<<"Default case"<<endl;
        break;
    }
}
// Another variation...
#include<iostream>
using namespace std;

int main() {
    int num = 2;
    switch (num)
    {
    case 1:
        cout<<"First case"<<endl;
        break;
    case 2:
        cout<<"Second case"<<endl;
        // break;
    default:
        cout<<"Default case"<<endl;
        break;
    }
}
// So we get to know that break statement is a very integral part of switch statement!
// Also default condition optional hoti hai, lagao ya na lagao koi error toh nhi aayega, pr agar jab koi condition match nhi hogi toh kuch toh execute krne ke liye chahiye, isliye hum default use krte hai!
// Nested loops and Switch cases are inter-convertible
// Suppose you have a infinite loop of while, and you have a switch statement inside it, so how will you exit both switch statement and while loop providing you can only use break statement onlyy inside of SWITCH statement...
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
    int num = 1;
    while(1) {
        switch (num)
        {
        case 1:
            cout<<"First case"<<endl;
            // break;
            exit(0);
        case 2:
            cout<<"Second case"<<endl;
            // break;
            exit(0);
        default:
            cout<<"Default case"<<endl;
            // break;
            exit(0);
        }
    }
}
// Here what happened is that agar hum break use krenge toh yahaa ek infinite loop ban jayega jisme sirf "First Case" print hoga! so, even if in this infinite loop we want to print only particular cases, then we need to use exit() statement!
// As exit not just pull you out of a loop, it pull you out of the entire program!
// That's why using exit() statement, we managed to handle the infinite loop!
// More elaboration of exit() statement : In C++, the exit() function is used to terminate a program. It is defined in the <cstdlib> header. When exit() is called, it performs some cleanup tasks and terminates the program. You can also specify an exit status code as an argument to exit().
// Keep in mind that, similar to the Python exit() function, using exit() in C++ should be done with caution. In more complex programs, you might want to use return statements from the main() function or throw exceptions to handle program termination more gracefully.
// If you're working with a specific function or a block of code within a program, you might prefer to use return to exit from that function or block, rather than calling exit().

// Continue Statement, it is used to skip the next iteration! but continue is not used in Switch case!
// In C++ (and many other programming languages), the continue statement is not used within a switch statement. The continue statement is typically associated with loop control structures, such as for, while, or do-while loops, and it is used to skip the rest of the current iteration and move on to the next one.
// In the context of a switch statement, you already have the ability to control the flow using the break statement. When a break statement is encountered inside a case, it exits the switch statement, preventing the execution of subsequent case statements. This behavior is sufficient for controlling the flow within the switch block.
// Using continue in a switch statement would not make sense, as the purpose of continue is to move to the next iteration of a loop, and switch is not a loop construct. If you need to skip the rest of the current case and move on to the next one, you can achieve that by using break.

// Functions :
// Lets just do one question to understand function!
// Print the nCr values of the number input by the user!
#include<iostream>
using namespace std;

// Function Definition
int fact(int num) {
    // Function Body
    int fact = 1;
    for(int i = 1; i <=num; i++) {
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) {
    return fact(n)/(fact(r)*fact(n-r));
}

int main() {
    int n, r;
    cin>>n>>r;
    cout<<"nCr value is "<<nCr(n,r)<<endl; //Function Call
}
// We used function and function calls!
// Function Call Stack : And the flow of function calls are, In int main() we called the function nCr(n,r) then in nCr(n,r) we called the function fact() then in fact() we returned the value of fact, then we returned another value, then we used that value in int main()!
// Return was a statement we were using to get out of the function!
// Now we also know that how pass by value and pass by reference works! these notes are already there in C language notes!

// Some questions on this lecture!
#include<iostream>
using namespace std;

void update(int x) {
    x = x/2;
}

int update2(int x) {
    x -= 5;
    return x;
}

int update3(int x) {
    int ans = x*x;
    return ans;
}

int main() {
    {
        int a = 2;
        update(a);
        cout<<a<<endl; // Here there will be no updates!
    }
    {
        int a = 15;
        update2(a);
        cout<<a<<endl; // Here again there will be no updates!
    }
    {
        int a = 4;
        a = update3(a);
        cout<<a<<endl; // Here update will happen! as kyunki jo update kiya gya hai function me usko store krke return kiya gya! upar ke do cases me ek me toh kuch return nhi kiya gya and ek me return kiya gya but print local variable vaala hi a karaya gya! isliye dono cases me koi bhi updates nhi aaye! agar isme reference kiya hota tab values change hoti! tab return krne ki bhi zarurat nhi hoti kyunki uss case me original value me hi changes ho jaate hai! these things we will study further!
    }
}

// ---------------------------------------------------------- LECTURE 9 - Arrays --------------------------------------------------------------------------------------------------------->
// Arrays : Can store multiple values/data in a single variable, similar type of data, data stored at contigous memory location, and can be stored using indexes!
// Declaring Arrays : int dost[10]; -> Here we have created an array with the name dost which has 10 contigous memory locations and where the name dost is refering to the first element of the array or can say is pointing at the 0th index of the array!
// Also maan lo agar int dost[10]; ek array banaya, toh ye memory me kaise dikhega, it will like suppose the first element is at memory address 100, now the 2nd element (means 1st index) will be at 104 becoz its data type is int and int has 4 byte, so one memory location (which will contain 32 bits) will be able to store a value of the int range which we know already! so means, dost[10] ka mtlb ki aisi 10 memory locations alot hojayengi dost naam ke variable ko jahaa pr hum 10 different (or same) values of same data type (here it is int) daal sakte hai and harr ek memory location (which is of 4 bytes = 32 bits) will be able to store value of the int range, which is -2^31 -> 2^31-1.

// Initiallization of Arrays : int dost[5] = {1,2,3,4,5}; Isse memory me 5 block bane and unn sab blocks me harr ek index ke according value store hogyi!
// Now another way of initiallizing array is, int dost[5] = {0}; isse kya hua ki jitne memory blocks allocate hue iss array ko unn sab me 0 store hogya!
// Another way is, int dost[10]; isse kya hua ki 10 memory locations ke according memory allocate hui and sab jagah garbage value store hogyi!
// But the thing is ye cheez iss case me nhi hota hai, int dost[5] = {1}; isse sirf first index pr hi store hota hai 1 and baaki remaining 4 memory locations pr garbage value store hojaati hai!
// But agar hum chahte hai ki 0 ki tarah sirf int dost[5] = {1}; likhne se harr index pr 1 store hojaye, toh iske liye what we have to do? so answer is : this will be done by using vectors! and it is demonstrated below...
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size = 5; // Replace 5 with the desired size of the array
    vector<int> array(size, 1);
    cout<<array[0]<<endl;
    cout<<array[1]<<endl;
    cout<<array[2]<<endl;
    cout<<array[3]<<endl;
    cout<<array[4]<<endl;

    // If you want to use a regular array in C++
    // int array[size];
    // std::fill(array, array + size, 1);

    // Another way of doing the above thing...
    int arr[5];
    fill(arr, arr + 5, 1);
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[3]<<endl;
    cout<<arr[4]<<endl;
    
    return 0;
}

// Implementation of Array!
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5};
    // One way to print all the values is to use the cout again n again, but that is not very feasible, so we will use the loop!
    for(int i = 0; i<10; i++) {
        cout<<arr[i]<<endl;
    }
    // Isse humari prblm toh solve hogyi ki hume baar baar cout nhi likhna padega jab index ki values print karwayenge toh, but iske saath saath ek aur cheez hui ki like humari array toh 10 size ki thi, but humne enter toh sirf 5 hi values ki hai toh after doing this baaki saari remaining indexes pr 0 store ho jayega! This is becoz of the C++ Standards!
}

// Arrays with Functions!
// Using the arrays with functions has the same reason as of the using normal functions and that is code ki readability and usability badhti hai!
#include<iostream>
using namespace std;

// Creating function to print every value in the array!
int printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<"Value at "<<i<<" of "<<" is : "<<arr[i]<<endl;
    }
}
// In the above function, jab array humne declare kiya brackets me tab hum chaahe toh arr[], iske andar hum size ki value daal sakte hai like, int arr[10], but that is not advisable becoz vo fir specific case hojayega!
// If you also want ki arrays ki values ke saath unn arrays ke naam bhi print ho toh uske liye ek alag parameter add krna hoga function declaration me arrayName naam se taaki array ka naam bhi print ho taaki pta chale ki vo jo value hai vo kis array se belong krti hai!

int main() {
    int arr1[5] = {0,1,2,3,4};
    int arr2[10] = {10,11,12,13,14};
    int arr3[15] = {20,21,22,23,24};

    // Now one way we have to print all the indexes is by using cout statement for all the entries!
    // But we will use the array with functions to print all the entries/indexes of the three arrays!

    // But lets start with the very lame method, that is using the cout statements for every indexes of array arr1...
    // cout<<arr1[0]<<endl;
    // cout<<arr1[1]<<endl;
    // cout<<arr1[2]<<endl;
    // cout<<arr1[3]<<endl;
    // cout<<arr1[4]<<endl;
    // Here we have printed every value at every index using the cout statement! also above we have seen that we have used the for loop to print all the values, but still like we dont neither want to write cout statements again and again for every array nor we want to write for loop for every arrays again n again!
    // so now we will use the array with function, we will create a function and write the for loop inside it and then we will just do the function calls!
    // Now using function calls for every array!
    printArray(arr1, 5);
    printArray(arr2, 10);
    printArray(arr3, 15);
    // Now these function call will print all the values of the array! isse kya hua ki humare code ki readability and reusability badh gyi!

    // Now suppose we want to find the size of an array, then we will do this...
    int arr1size = sizeof(arr1)/sizeof(int);
    cout<<"Size of arr1 : "<<arr1size; // it will print 5, which is the size of the array arr1.
    // But maanlo like humare array 10 size ka hai and usme 5 hi element pade hue hai then hume uska actual size nikalna possible nhi hai toh uss case me hi hum int size naam se ek parameter daalte hai function declaration me!
}
// Arrays character and baaki data types ke bhi bante hai, we can do the same above thing with them also! but upar me jo printArray function hai vo sirf int data type vaale arrays ke liye kaam krega!

// Finding the maximum/minimum value among all the values in an array!
#include<iostream>
#include<climits>
using namespace std;

// Declaring a array function, ye array or uska size leke poore array me iterate krega and find krega sabse badaa number konsa hai, and that will be done with the INT_MIN value!
int getMax(int arr[], int n) {
    int maximum = INT_MIN;
    for(int i=0; i<n; i++) {
        // We have inbuilt function also to find the maximum value of the array!
        // maximum = max(maximum, arr[i]); // Ye line vahi same kaam krega jo neeche ki 3 lines ne kiya hai!
        if(arr[i]>maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

// Declaring a array function, ye array or uska size leke poore array me iterate krega and find krega sabse chhota number konsa hai, and that will be done with the INT_MAX value!
int getMin(int arr[], int n) {
    int minimum = INT_MAX;
    for(int i=0; i<n; i++) {
        // We have inbuilt function also to find the minimum value of the array!
        // minimum = min(minimum, arr[i]); // Ye line vahi same kaam krega jo neeche ki 3 lines ne kiya hai!
        if(arr[i]<minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int main() {
    int size;
    cin>>size;

    // int arr[size]; // This is not at all a good practice as here we are trying to make the size of the array a variable, but this is not how you do it!, that we will learn later on, but for now lets keep its size static!
    int arr1[100];

    // The below for loop is used to take input for an array, also humne pehle array ka ek fixed size rakh diya, then humne ek size naam ka variable banaya jisse kya hoga ki hum pehle size input krenge and then uss size ke hisaab se hi input jayega!
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }

    // Function call while printing the values!
    cout<<getMax(arr1, size)<<endl;
    cout<<getMin(arr1, size)<<endl;
}


// Addressing and Updation and function call in Arrays!
#include<iostream>
using namespace std;

int update(int arr[], int size) {
    cout<<"Inside the Update Function"<<endl;
    arr[1] = 100;
    for(int i=0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Going back to the Main Function"<<endl;
}

int main() {
    // Declared an array inside the main function!
    int arr1[3] = {1,2,3};

    // Here we have called the update function, now the point is, that jab pehle humne jab aise updates kiye the pehle ke questions me toh main me jo function call me jo paramter pass krte the unki ek copy ban jaati thi and fir uss code pr jo bhi updation hona hota tha vo hota tha, pr yahaa aisa nhi hua, why?...
    // This is becoz it is an array, yahaa hum array ko function call me pass nhi krte, balki array ke base element ke address ko pass krte hai function call me, toh jab update function ke paas arr1 ka address gya, toh usne saari updation seedha arr1 me krdi rather than koi ek alag copy banaye bagair!
    // Tab hi main function me arr1 jo hai usme bhi updation hogyi! kyunki humne array ke 0th index ke element ka address hi pass krdiya tha! as the name of an array maps with the address of the base element of that array!
    update(arr1, 3);
    for(int i=0; i<3; i++) {
        cout<<arr1[i]<<" ";
    }
}

// Practice Question : Take input in an array and then find the sum of all of its elements!
#include<iostream>
using namespace std;

int arraySum(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum = arr[i] + sum;
        // sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cin>>size;
    int arr1[20]; // You can input any number of elements up to 20. and You cannot input more than 20 elements because the array only has 20 slots available.
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"Sum of all the values of the array "<<arraySum(arr1, size)<<endl;
}

// Linear Search! : This is used to seach an element in an array! and that element for which we are searching for is called a key!
#include<iostream>
using namespace std;

// Linearly harr element pr iterate kraa ke check kiya ki kya vo key ke equal hai, agar hai toh return true krdo otherwise false!
int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i]==key) {
            return true;
            // return 1; // Can also write this
        }
    }
    return false;
    // return 0; // Can also write this
}

int main() {
    cout<<"Enter the size of the array : ";
    int size;
    cin>>size;

    // Declaring and Input in Array!
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }

    bool found = linearSearch(arr1, size, 5); // Called the function and key = 5. and kept the data type boolean for the output

    // Final Answer!
    if(found) {
        cout<<"Key is present!";
    }
    else {
        cout<<"Key is absent";
    }
}

// Reverse an Array!
// Approach : We will take a starting point jo 0th index of array ko represent krega and then ek end point jo last index of array ko represent krega, now what we will do is, vaise toh hum ek swap function use krenge pr vo swap function krta kya that is explained here,
// so, kya hota hai ki jaise agar ek array hai 6 elements ka, toh pehle start point 0th index pr hoga and end vaala last index pr (which is 5 here) toh pehle inn dono ko hum swap krdenge, now we will do start++ and end-- and now will again swap, now will continue this,
// jab tak start end se aage na badh jaye or in other words ki start>end, this will be our terminating condition!
#include<iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n-1;

    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void PrintArray(int arr[], /* int n (Ye nhi likh sakte, vrna function overload ke chakkar me printArray ke neeche redline ayegi!) */ int size) { // Yahaa agar multiple functions void type ke hai dono ke parameter list ekdum same hai even with the variable declarations are same! then in that case IDE shows a function overload error! to resolve that just make sure when you have multiple functions with same return type and their parameter list is also same in that case,
    for(int i=0; i<size; i++) {  // change the name of the variable declaration names in the function declaration brackets! Even tho code execute successfully hojayega! bss jo do functions hai jinke function declaration and return type dono same hai, bhale hi vo kaam alag alag kr rhe ho, unn dono me se kisi ek ke neeche red line aayegi! so just to resolve that make sure you keep this thing in mind! Also iss poori file multiple times same hi function and cheeze repeatative bani hui hai! isliye bhi isme error aa rha hai!
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    cout<<"Enter the size of the array : ";
    int size;
    cin>>size;

    // Declaring and Input in Array!
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }

    reverseArray(arr1, size);
    printArray(arr1, size);
}
// Solved the above problem with 2 function calls! ek hi me bhi kr sakte the like printArray() vaala function ka code reverseArray() ke saath rakh sakte the, but okay thori readability and reusability badhaane ke liye theek hai for now!


// ---------------------------------------------------------- LECTURE 10 - Arrays Question (Leetcode/CodeStudio) --------------------------------------------------------------------------------------------------------->
// Problems in Arrays!
// Leetcode Question 1 : Swap all the alternate numbers in the array! like if array is 1,2,3,4,5 then output will be 2,1,4,3,5 in case of odd number, baaki you get it what will be in even number!
#include<iostream>
using namespace std;

int swapAlter(int arr[], int n) {
    for(int i=0; i<n; i+=2) {
        if(i+1<n) {
            swap(arr[i], arr[i+1]);
        }
    }
}

int printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    cout<<"Enter the size of the Array : ";
    int size;
    cin>>size;

    int arr1[30];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    swapAlter(arr1, size);
    printArray(arr1, size);
}
// Lets breakdown the above swap function that we made in the some of the above questions!
// So what actually happens is : swap(arr[i], arr[i+1]), now we make a temp variable jisme hum ek index ki value ko temporary store krenge taaki uss index ki jagah kisi aur index ki value daal sake and then uss temp me jo value store this usko dusre vaale index me daal de!
// swap(arr[i], arr[i+1]);
// int temp = arr[i+1];
// arr[i+1] = arr[i];
// arr[i] = arr[i+1];
// So that is how we swap!

// Another Solution :
#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void printarray(int arrInput[], int size) {
    for(int i = 0; i<size; i++) {
        cout<<arrInput[i];
    }
}

int main() {
    int arr1[30];
    int size;
    cin>>size;
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    swapAlternate(arr1,size);
    printArray(arr1,size);
}

// Leetcode Question 2 : Check whether an array contains any unique element or not! and print that unique element!
// There are multiple ways to do so...
// 1st (Optimized solution) :
#include <iostream>
#include<climits>
using namespace std;

int main() {
    
    int n; cin>>n;
    int *arr = new int[n];
    int max_element = INT_MIN;
    bool flag = false;
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
        max_element = max(max_element, arr[i]);
    }
    int *freq = (int*)calloc(max_element+1,sizeof(int));
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<=max_element;i++)
    {
        if(freq[i]==1)
        {
            n = i;
            flag = true;
            break;
        }
    }
    if(flag==true)
            cout<<"Found a distinct element:"<<n<<endl;
    else{
        cout<<"No distinct element found"<<endl;
    }
    return 0;
}

// 2nd (Using STL library map) : This we will study further going in... so for now you can ignore this solution but once you understand STL then you can check it again!
#include<map>
#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        mp[num] += 1; // key ki value ko 1 se se increment kr rhe hain
    }
    for(auto it:mp)
    {
        cout<<"Element:"<<it.first<<" occurence --> "<<it.second<<endl;
    }
}

// 3rd (Normal Solution) :
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        flag = true;
        for(int j=0; j<n; j++)
        {
            if(i!=j && arr[i]==arr[j])
                flag = false;
        }
        if(flag==true)
        {
            cout<<"Unique Element found: "<<arr[i]<<endl;
            // break;
        }
    }
}

// 4th (Love Babbar Solution) :
// Approach : Ek bhot lame si approach toh ye hogi ki hum harr ek element ka count nikal le and then jiss element ka count 1 hoga vo humara answer hojayega!
// But that is not a very good solution, so another thing that we can do is, previously we have studied XOR operation, what it does is ki vo do same operand ki value ko 0 krdeta hai, toh hum uski iss hi property ka use krenge,
// like agar 1,1,2,2,3 hoga array me toh vo 1 and 1 ka XOR krke 0 krdega and then 2 and 2 ka XOR krke isko bhi 0 krdega and then 0 XOR 3 XOR 0 will give us 3, and thats how we will get our answer! Agar ek XOR operation me saare same operands honge toh vo sabko 0 krdega!
// and last me sab element ke 0 hojane ke baad jo ek akela element bacha hoga uske saath XOR krke output vo akela element ho ajayega! So we will do this...
#include<iostream>
using namespace std;

int findUnique(int arr[], int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = arr[i]^ans;
    }
    return ans;
}

int main() {
    int size;
    cin>>size;

    int arr1[10000]; // Later on we should declare array dynamically but okay for now, but that will be more optimized solution!
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"The Unique Element is : "<<findUnique(arr1, size);

}
// The above solutions will not only check whether an array contain a unique element, but also it will tell what are frequency of all the elements and find the unique element! for checking frequencies of other elements, you can use the Maps! it will be best to use! and for most optimal solution you can use the first solution! and for the unique solution you can use the last solution!

// Leetcode Question 3 : You are given an array, and it contains each element between 1 -> n-1 at least once, there is a single integer value that present in the array twice, Your task is to find the duplicate value integer value present in the array!
// Approach : Pehli approach toh vhi hai ki harr element ko count krlo and jiss element ka count 2 ke equal hoga vo humara answer hojayega! this is a brute force approach!
// Brute Force Approach : My Solution...
// This is a very good brute force solution also it is very optimized, but nevertheless it is a brute force solution, so it can optimized more! But yeah kuddos for that!
#include<iostream>
#include<climits>
using namespace std;

int countTwo(int arr[], int size,int max_element) {
    int *count = (int*)calloc(max_element+1,sizeof(int));
    for(int i = 0; i<=max_element; i++) {
        count[arr[i]]++;
    }
    for(int i = 0; i<size; i++) {
        if(count[i] == 2) {
            return i;
        }
    }   
    return 0;
}

int main() {
    int arr1[50];
    int size;
    cin>>size;
    int max_element = INT_MIN;
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
        max_element = max(max_element,arr1[i]);
    }
    int countTwoIndex = countTwo(arr1,size,max_element);
    cout<<"Elements whose index is count 2 is : "<<countTwoIndex;
}

// But lets try to find some good solution...
// So what we will do, maanlo array jo input me aya that is, of size = 10 and elements are 1,2,3,4,5,6,7,7,8 now we want to find the duplicate, so what we will do is ki hum isme same elements add krke (duplicate vaale me se sirf ek) and then sabka apas me XOR kra lenge taaki in the end sirf ek single element bachega and that will be our final answer!
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = ans^arr[i];
    }
    for(int i=1; i<n; i++) {
        ans = ans^i;
    }
    return ans;
}

int main() {
    int size;
    cin>>size;
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"Duplicate Element is : "<<findDuplicate(arr1, size)<<endl;
}
// So what happened here is, humne arr1 me input liya array ko, and question me hai ki 1 to n-1 tak ke atleast ek element hona hi chahiye along with the sirf ek duplicate element hona chahiye!, toh ab after getting the input!
// function definition me, humne first loop me array ke sab element ko apas me XOR karwaya, so maanlo agar humne input liya tha of size = 10, and elements are, 1,2,3,4,5,6,7,7,8,9, now, sabka apas me XOR hua, so it will be 1^2^3^4^5^6^7^7^8^9, now vaise iska answer hoga 14, so ans me yaa toh 14 store ho ya 1^2^3^4^5^6^7^7^8^9 poori string baat ek hi hai, so after completion of 1st loop, ans variable has that whole string in it (yaa 14 store ho baat ek hi hai), now...
// in the 2nd for loop, humne normal 1 se n-1 tak ke elements ka ek ek krke XOR karwaya previous stored ans variable ki value me, so it final is like, (1^2^3^4^5^6^7^7^8^9) ^ (1) in the first iteration, then (1^2^3^4^5^6^7^7^8^9) ^ (1^2) in second iteration and similarly so on upto n-1, so the final calculation will be, (1^2^3^4^5^6^7^7^8^9) ^ (1^2^3^4^5^6^7^8^9), now we know that XOR holds associative property, so next will be, (1^1)^(2^2)^(3^3)^(4^4)^(5^5)^(6^6)^(7^7^7)^(8^8)^(9^9), and now we know ki same values ka XOR = 0 and XOR of three operation is like a^a^a, isko hum aise likh sakte hai (a^a)^a, so now...
// 0^0^0^0^0^0^(7^7^7)^0^0 which will give output, (7^7^7) and now, (7^7)^7, it will give, 0^7 and then final answer will be, 7, hence our duplicate element is 7!

// Another approach can be, ki array ko input leke sab ka sum nikal do and then 1 se n-1 tak ke saare numbers ka sum nikal do and then dono sum ko subtract krdo!
// Lets try this approach :
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n) {
    int sum1 = 0, sum2 = 0;
    for(int i=0; i<n; i++) {
        sum1 = sum1 + arr[i];
    }
    for(int i=0; i<n; i++) {
        sum2 = sum2 + i;
    }
    int ans = sum1 - sum2;
    return ans;
}

int main() {
    int size;
    cin>>size;
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"Duplicate Element is : "<<findDuplicate(arr1, size)<<endl;
}

// Leetcode Question 4 : Find the intersection of 2 arrays! and if no intersection present then print -1! and arrays are sorted in non-decreasing order, means increasing order! Time Limit : 1 sec, 1 < size1 & size2 <= 10000, 0 < arr1[i] & arr2[i] <= 100000!
// Approach : What we will do is suppose we have an Array arr1 = [1,2,3,3] and arr2 = [3,4], now hum kya krenge ki arr1 ke saare elements ko hum arr2 ke saare elements se compare krenge and jab bhi do elements match hojayenge, then usko print krdenge and then koi aur element firse uss same element se match na hojaye uske liye hum second array me jo element match hua hai iski value ko replace krke kuch abrupt value daal denge (and here that abrupt value will be INT_MIN)
// Means, like arr1 ke saare elements humne compare kiye arr2 se, and now, we can see 1 se koi match nhi ho rha arr2 me, similarly with 2 but when we will go to 3 it matches with the first element of arr2, now we will print it and then arr2 me jo 3 hai (jo element match hua hai arr1 ke element se) usko hum replace krdenge taaki next time agar 3 aaye check krne then firse uss hi same element se match na hojaye! Now lets code it!
// So here we have used vector as becoz we do not know what the length of the array, so we allocate the memory dynamically! the vectors we will learn deeply in STL, but for now understand the logic here!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> findIntersection(vector<int> &arr1, int size1, vector<int> &arr2, int size2) {
    vector<int> ans;
    for(int i=0; i<size1; i++) {
        int element = arr1[i];
        for(int j=0; j<size2; j++) {
            if(element == arr2[j]) {
                ans.push_back(element);
                arr2[j] = INT_MIN; // Yahaa pr koi negative number bhi daal sakte hai kyunki ek constraint question me hi diya hua hai ki dono array me value humesha positive hi hongi, toh for this case -1 se bhi replace krdenge toh koi dikkat nhi hai!
                break;
            }
        }
    }
    return ans;
}

int main() {
    int size1, size2;
    cin>>size1>>size2;
    vector<int> arr1(size1);
    vector<int> arr2(size2);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    for(int i=0; i<size2; i++) {
        cin>>arr2[i];
    }
    vector<int> result = findIntersection(arr1, size1, arr2, size2);
    cout << "Intersection: ";
    for (int i : result) { // Here, this is another way of using for-loop, which is called range-based forloop, which is a convenient syntax introduced in C++11 for iterating over elements in a range, such as the elements of a container (like a vector).
        cout << i << " ";  // In summary, the range-based for loop simplifies the syntax for iterating over elements in a container, making the code more concise and readable. The loop automatically iterates over all elements in the specified range (here, the result vector), and the loop variable (i in this case) takes the value of each element in turn. This is a cleaner and more modern alternative to traditional iterator-based loops.
    } // Normal for-loop bhi use kr sakte hai with and.size() use krke condition me jaise normal arrays ke saath krte hai!
}
// But the above solution is not optimized as it is giving a warning : TLE (Time limit exceeded), so now we will make it optimize, how? so the point is, we did'nt used the point of non-decreasing order, as we know agar element non-decreasing order (increasing order) me stored hai, toh jab hum ek element ko dusre array ke first element se compare krenge and then agar second element se compare kiya and dekha ki ye element arr1 ke element se badaa hai toh hum aage jayenge hi nhi na, vrna humaari processing waste hogi! so to optimize this we will apply this as a constraint in the program!
// like suppose we have an arr1 = [1,4,5] and arr2 = [4,5], now 1 ko ja 4 se compare krenge, then we will see ki 4>1 means aage aane vaale bhi jo bhi elements honge vo bhii 1 se bade honge toh aage jaana hi nhi and we will move to the next element of arr1! so bss yhi cheez hume apne code me add krni hai!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> findIntersection(vector<int> &arr1, int size1, vector<int> &arr2, int size2) {
    vector<int> ans;
    for(int i=0; i<size1; i++) {
        int element = arr1[i];
        for(int j=0; j<size2; j++) {
            if(element < arr2[j]) {
                break;
            }
            if(element == arr2[j]) {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int size1, size2;
    cin>>size1>>size2;
    vector<int> arr1(size1);
    vector<int> arr2(size2);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    for(int i=0; i<size2; i++) {
        cin>>arr2[i];
    }
    vector<int> result = findIntersection(arr1, size1, arr2, size2);
    cout << "Intersection: ";
    for (int i : result) {
        cout << i << " ";
    }
}
// But again this is still giving warning of TLE, so we will go with optimization 2 : now this thing is pehli baat toh time limit isliye bhi exceed ho rhi kyunki hum 2 loops use kr rhe hai! so pehle toh hume try krna hai ki ek loop kam kre, then...
// Lets learn a different approach which is called 2 pointer approach, which says, suppose two arr1 = [1,2,2,2,3,4] and arr2 = [2,2,3,3] now hum pehla pointer (not really pointer vaala pointer), its just a iteration, so first humne i arr1 ke first element pr rakha and next humne arr2 ke 1st element pr rakha! now we will compare...
// So first thing jo hume dhyaan se ek condition banani hai ki, arr1[i] < arr2[j], then i++ krdo
// Now second thing jo hume dhyaan se ek aur condition banani hai ki, arr1[i] == arr2[j], then print krdo/vector me push krdo and i++ and j++ krdo
// Now lastly ek aur condition banani hai ki, agar arr1[i] > arr2[j] hogya, then j++ krdo
// Also tab tak hi loop chalana hai jab tak dono array me se koi bhi ek ke saare elements traverse na hojaye! kisi bhi ek ke saare elements traverse hojaate hai toh exit the loop
// So now lets follow this approach :
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> findIntersection(vector<int> &arr1, int size1, vector<int> &arr2, int size2) {
    vector<int> ans;
    int i = 0, j = 0;
    while(i<size1 & j<size2) {
        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return ans;
} // So this time we have applied all the conditions here now! and now this is the most optimized condition!

int main() {
    int size1, size2;
    cin>>size1>>size2;
    vector<int> arr1(size1);
    vector<int> arr2(size2);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    for(int i=0; i<size2; i++) {
        cin>>arr2[i];
    }
    vector<int> result = findIntersection(arr1, size1, arr2, size2);
    cout << "Intersection: ";
    for (int i : result) {
        cout << i << " ";
    }
}

// Leetcode Question 5 : You are given an int array of size n, your task is return the list of all pairs of elements, such that sum of elements of each pair equals S. Each pair should be sorted and first value should be less than the second value, also...
// Return the list of pairs sorted in non-decreasing order of their first value, in case two pairs have the same first value then the pair with smaller second value should come first!
// A better explaination of question and its constraints : The task is to find all pairs of elements in an array such that the sum of each pair equals a given value S. The pairs should satisfy the following conditions : 1) Each pair should be sorted in ascending order. 2) The list of pairs should be sorted primarily by the first value of the pairs, and if two pairs have the same first value, they should be sorted by the second value.
// Approach : Again 2 pointer approach, given array me i = 0 se n-1 tak ka loop chalayenge and uske andar j = i+1 se lekar n-1 tak ka loop chalayenge, and jahaa bhi sum = s hojayega usko 2D vector me daal denge! (Kyunki yahaa hume pairs toh return krna hi hai pr uske saath list of pair bhi return krna hai iske liye we need a 2D array) so we are using dynamic one!
#include<iostream>
#include<vector>
#include<algorithm> // To use the sort function
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr1, int n) {
    vector<vector<int>> ans;
    for(int i=0; i<arr1.size(); i++) {
        for(int j=i+1; j<arr1.size(); j++) {
            if(arr1[i] + arr1[j] == n) {
                vector<int> temp;
                temp.push_back(min(arr1[i], arr1[j]));
                temp.push_back(max(arr1[i], arr1[j]));
                ans.push_back(temp); // isme agar tum ye socho ki 1D vector ko 2D vector me kaise input kiya, toh iska answer ye hai ki, ans is vector of vectors, toh ye input me 1D vectors ko hi store krega! isko aise samajh lo ki jaise normal 1D vector me atomic int values store hoti hai! vaise hi 2D vector me linear vectors store hote hai! toh agar initially ans = [[]] aise tha, toh jab first time temp input hua hoga, toh iske andar ek vector gya hoga! toh ab ye update hoke ans = [[a,b]] ban jayega! and then jab dusri iteration me firse pair of values temp me store hoke ek vector ke form me and vaale 2D vector me store hone ayengi toh firse ans vector update hojayega with ans = [[a,b],[c,d]] and so on... 
            }
        }
    }
    sort(ans.begin(), ans.end()); // ye dusri vaali condition ki, list of pairs should be sorted primarily by the first value of the pairs, and if two pairs have the same first value, they should be sorted by the second value ye cheez sort function khud hi handle kr le rha hai! we dont need to do something else more!
    return ans;
}

int main() {
    int value;
    cin>>value;
    int size1;
    cin>>size1;
    vector<int> arr1(size1);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    vector<vector<int>> result = pairSum(arr1, value);
    cout << "Intersection: ";
    for (vector<int> pair : result) {
        cout << "(" << pair[0] << ", " << pair[1] << ") ";
    }
} // Don't worry we will study the vector in detail in the upcoming lecture of STL, but for now just undertstand it as dynamic array! and more or less the above code is very clear what is it doing!

// Leetcode Question 7 : Sort 0, 1 in an array!
#include<iostream>
using namespace std;

void sortOne(int arr[], int n) {
    int left = 0, right = n-1;
    while(left<right) {
        while(arr[left] == 0 && left<right) {
            left++;
        }
        while(arr[right] == 1 && left<right) {
            right--;
        }
        if(left<right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void PrintArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int size;
    cin>>size;
    int arr1[10000];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    sortOne(arr1, size);
    PrintArray(arr1, size);
}

// ---------------------------------------------------------- Some Extras --------------------------------------------------------------------------------------------------------->

// College Bootcamp Question : Write a program to display the sum of the series: 1 + 22 + 333 + 4444 + ... where the number of terms in the series is provided by the user.
#include<iostream>
using namespace std;

int sumofArrays(int arr[], int size) {
    int sum = 0;
    for (int i = 1; i <= size; i++) {
        int term = 0;
        for (int j = 0; j < i; j++) {
            term = term * 10 + i;
        }
        sum += term;
    return sum;
    }
}

int main() {
    int arr1[500];
    int size;
    cin>>size;
    int ans = sumofArrays(arr1,size);
    cout<<"Sum of arrays : "<<ans;
}

// Dynamic Memory Allocation! in C/C++.
// It is a way of allocating the memory to the data structure during the runtime! and we do this using some functions like, calloc(), malloc(), realloc() and free()
// malloc() : Malloc() ek function hai jo C programming language mein dynamic memory allocate karne ke kaam aata hai. Iska full form hai "memory allocation". Isko use karke hum runtime par memory allocate kar sakte hain, jo humein flexibility aur efficiency deta hai.
//          : Takes the number of bytes to allocate & return a pointer of the type void!
//          : Syntax : int *ptr; ptr = (int*)malloc(10*sizeof(int)); Here we have allocated 10 int size of uninitiallized memory and returned the address of first index of that memory to the pointer ptr, so that it can be accessed easily! and while returning we have type casted it into int, kyunki vrna bina type caste ke krte toh ek void pointer return hota 1st index ka! so that is why we have type casted it into int!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    
    // 10 integers ke liye memory allocate karte hain
    ptr = (int*)malloc(10 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Memory ko initialize karte hain
    for (int i = 0; i < 10; i++) {
        ptr[i] = i + 1;  // Ya phir ptr[i] = 0; se initialize kar sakte hain
    }
    
    // Values ko print karte hain
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    // Memory free karna zaroori hai
    free(ptr);
    
    return 0;
}

// calloc() : calloc ek function hai jo C programming language mein dynamic memory allocate karne ke kaam aata hai, lekin yeh malloc se thoda different hai. calloc memory allocate karne ke sath-saath us memory ko zero se initialize bhi karta hai.
//          : Takes the number of bytes to allocate and unn sab ko 0 se initiallize krdeta hai, which is an extra feature as compare to malloc()
//          : syntax : int *ptr; ptr = (int*)calloc(num, sizeof(int)); isme ye num me hum jo size daalenge utne block ye sizeof() operator ko use krke utne blocks allocate krdega! and then again vhi 0th index ka index int me type caste krke return krdega! agar type caste nhi krenge toh ye bhi void pointer return krta hai! hum kisi aur data type me bhi type cast kr sakte hai! ya sizeof() me int ke jagah koi aur data type bhi dall sakte hai! agar hume kisi aur size ke hisaab se memory allocate krni hai toh!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;  // 5 integers ka array
    
    // 5 integers ke liye memory allocate karte hain
    arr = (int*) calloc(n, sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Array ko initialize karna zaroori nahi hai, kyunki calloc ne already zero se initialize kiya hua hai
    // Lekin hum fir bhi use karke initialize kar sakte hain, jaise:
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    // Array ko print karte hain
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Memory free karna zaroori hai
    free(arr);
    
    return 0;
}

// realloc() : Agar maanlo humne kisi ek program me 30 students ki info ke liye memory allocate ki thi pr ab 30 se zyada bache aagye toh hume memory badhani padhegi! so in that case we use realloc()
//           : realloc ek function hai jo dynamically allocated memory ki size ko adjust karne ke kaam aata hai. Iska use tab hota hai jab aapko pehle se allocated memory block ko chhota ya bada karna ho. Yeh malloc aur calloc se allocated memory ko resize karta hai.
//           : If we take reference syntax like this, void* realloc(void* ptr, size_t new_size); so, jab realloc function call hota hai, yeh existing memory block (pointed by ptr) ko new_size bytes ka banane ki koshish karta hai. Agar successful hota hai, to wahi memory block resize ho jata hai aur same pointer return hota hai. Agar existing memory block ko resize karna possible nahi hota, to nayi memory allocate karta hai, purani values ko copy karta hai, aur nayi memory block ka address return karta hai. Purani memory block free kar di jaati hai.
//           : syntax : int* ptr; realloc(ptr, new size); isme almost sab cheeze same hai malloc calloc ka jo basic logic hai ki dynamically memory allocate ho rhi hai! bss isme ye hai ki ye new size ke hisaab se already allocated memory ko increase ya decrease krta hai! like, agar pehle 5 size of int ki memory allocated hai! and agar hum 8 size of int ki memory all allocate krte hai realloc ke through! so yaa toh jo already allocated memory hai vo 5 size ki hai toh usme hi 3 bytes aur add hojayenge size of int ke! otherwise ek poora nayaa memory series of memory block banega of size 8, and usme pehle toh saara data copy hoga unn poorani 5 bytes and then uske baad 3 bytes ki memory aur allocate hogi! mtlb ki poorani bytes rehti hai and usme aur add on hoti hai new add on bytes!
//           : Its like, pehle se 5 thi, size badhai humne 8 ki, toh agar vhi ke vhi allocate hogyi toh bss 3 bytes aur add hongi kyunki pehle se 5 thi and new allocated memory 8 ki hai! in other case, ek new 8 bytes ki size allocate hogi! and then usme pehle toh vo 5 bytes copy hongi! and then uske baad 3 bytes bachi rahengi! toh yahaa bhi size badh gyi!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    
    // Initial size ke liye memory allocate karte hain
    arr = (int*) malloc(5 * sizeof(int));
    
    if (arr == NULL) {
        printf("Initial memory allocation failed\n");
        return 1;
    }
    
    // Array ko initialize karte hain
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    // Initial array ko print karte hain
    printf("Initial array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Array ki size ko resize karte hain
    arr = (int*) realloc(arr, 8 * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    
    // Nayi memory ko initialize karte hain
    for (int i = 5; i < 8; i++) {
        arr[i] = i + 1;
    }
    
    // Resized array ko print karte hain
    printf("Resized array:\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Memory free karte hain
    free(arr);
    
    return 0;
}

// free() : free ek function hai jo C programming language mein dynamically allocated memory ko deallocate karne ke kaam aata hai. Jab hum malloc, calloc, ya realloc se memory allocate karte hain, toh us memory ko manually free karna padta hai, taaki memory leak na ho. Yeh memory ko free karke usse wapas heap memory mein available banata hai.
//        : Jab free function call hota hai, toh yeh memory block ko deallocate karta hai jo ptr pointer point kar raha hota hai. Yeh memory ko release karke wapas system ko available kar deta hai. Agar ptr NULL hai, toh free kuch nahi karta.
//        : Syntax : int *ptr; free(ptr); Isne seedha uss dynamically allocated memory ko free/deallocate krdiya jispe ptr pointer point kr rha tha!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    
    // Memory allocate karte hain 5 integers ke liye
    ptr = (int*) malloc(5 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Memory ko use karte hain
    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }
    
    // Values ko print karte hain
    printf("Values in allocated memory:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    // Memory ko free karte hain
    free(ptr);
    
    // ptr ko NULL set karna, taaki accidentally use na ho
    ptr = NULL;
    return 0;
}
// All these 4 functions are found in "stdlib.h" header file! so use krne se pehle include krna padega isko!

// Goto Statements : The goto statement in C and C++ provides an unconditional jump to another point in the program. It allows the control to be transferred to a labeled statement within the same function. This can be useful for breaking out of deeply nested loops or for implementing certain kinds of error handling.
// Syntax : First we define a label, by just writing "label_name : ", after this we write "goto label_name;"
// Example Syntax :
// label_name:
// Code to be executed when the goto statement jumps here
// goto label_name;

// Example of goto statement :
// Example 1 :
#include <stdio.h>

int main() {
    int num = 0;

    // Define a label
    start:
    printf("num: %d\n", num);
    num++;

    // Conditional jump using goto
    if (num < 5) {
        goto start;  // Jump back to the label 'start'
    }

    printf("Loop finished.\n");

    return 0;
} // This will behave as a loop! everytime when num exceeds 5!

// Example 2 :
#include<stdio.h>

int main() {
    int num;
    for(int i = 0; i<8; i++) {
        printf("%d",i);
        for(int j = 0; j<8; j++) {
            printf("Enter number & enter 0 to exit");
            scanf("%d",&num);
            if(num == 0) {
                // break; // Ye sirf ek loop se exit kraa dega! but goto seedha uss end label pr leke chale jayega!
                goto end;
            }
        }
    }
    end :
    printf("Loop end");
}

// Unions :
// Union is very similar to structure! bss jo main difference vo ye hai ki jaise pehle toh ki ye dono hi user defined data types hote hai! but jo difference vo ye hai ki jaise structure me jo data members hote hai unn sabko ek individual alag se memory milti hai apne apne data ko store krne ke liye! but in case of unions jitne bhi data members hote hai unn sabke ke liye ek common memory allocate hoti hai! and utni memory allocate hogi jitni jiss data member ki sabse zyada hogi!
// Now suppose an example of structure, where it has data members like, int roll_number; float cgpa, char name[30]; now isme kyunki ye ek structure se define hui hai toh yahaa pr harr data member ke liye alag alag memory allocate hogi! now like jaise int ke liye 4 bytes allocate hue + float ke liye 4 bytes + then char name[30] means 30 bytes for name! means in total structure needs 38 bytes in total to store values of its data members when objects/instances of structure are created
// But in the same example, if we just replace struct with union, then then jo data member sabse zyada memory lega utni memory bss allocate hogi! but sab data member ke liye alag memory allocate nhi hogi! means in total memory will be 30 bytes only! unions use krne ka ek fayeda hota hai ki memory kaafi efficiently use hoti hai! like isme agar hum instances bnaate hai union ke then jaise humne agar [instance].id = 3 krdi toh uss 30 bytes ki memory me ye 3 jaake store hojayega! but agar iske baad agar hum [instance].cgpa = 8.9, toh jo pehle id store tha ek instance vo corrupt hojayega and uss hi same memory space me ye cgpa store hojayegi! and similalry agar ab vgpa ke baad name store krte hai toh fir cgpa corrupt hojayegi and uss hi same memory space me name store hojayga! means jo hum end me value assign krenge jiss data member ki vo valye store hogi memory me! and usse pehle jitne bhi data members ki value hai vo erase ho jayegi! but agar hum structures me dekhe toh harr data member ki value store rehti hai! and dusre data members ka initiallization kisi aur data member ki value ko change/erase/corrupt nhi krta!
// Lets code this and understand with an example...
#include<stdio.h>
#include<string.h>

struct student { // Here we can use "typedef" to give it an abbreviation!
    int id;
    float cgpa;
    char name[30];
};
// Hum int main ke bajaye yahaa pr bhi objects/instances declare kr sakte hai, by just writing it between the closed curly bracket and semicolon!
// Something like this, } Utkarsh, Aditya, Vishal; so yahaa pr humne 3 objects bnaa diya ab seedha isko int main me id, cgpa and name ko initiallize kr sakte hai! kyunki objects toh pehle hi bnaa diye!
// And this same thing can be done in union also!

int main() {
    student Utkarsh;
    Utkarsh.id = 365;
    Utkarsh.cgpa = 9.5;
    strcpy(Utkarsh.name,"Utkarsh");
    // Here due to struct, id + cgpa + name = 4 + 4 + 30 = 38 bytes of memory is allocate to this user defined data type student! and every data member has its own memory!

    printf("ID: %d\n", Utkarsh.id); // It will print 365 and its initiallization will not affect values/initiallization of other instances!
    printf("CGPA: %.2f\n", Utkarsh.cgpa); // It will print 9.50 and its initiallization will not affect values/initiallization of other instances!
    printf("Name: %s\n", Utkarsh.name); // It will print Utkarsh and its initiallization will not affect values/initiallization of other instances!
}

// Now lets just replace struct with unions!
#include<stdio.h>
#include<string.h>

union student {
    int id;
    float cgpa;
    char name[30];
};

int main() {
    student Utkarsh;
    Utkarsh.id = 365;
    Utkarsh.cgpa = 9.5;
    strcpy(Utkarsh.name,"Utkarsh");

    printf("ID: %d\n", Utkarsh.id); // Here it will print corrupted or garbage value kyunki vaise toh ye 365 print krta agar sirf id initiallize hu hoti! but id ke baad cgpa and uske baad name bhi initiallize ho chuka hai! and union me jo last me initiallize hua hota hai sirf vhi memory me jaake store hota hai! toh isliye yahaa pr garbage value print hogi!
    printf("CGPA: %.2f\n", Utkarsh.cgpa); // Yahaa pr bhi garbage value print hogi! reason is same as above!
    printf("Name: %s\n", Utkarsh.name); // Here it will print name of the instance! kyunki as becoz union hai toh jaise jaise data member initiallize hote rahenge! and in the end jo last me jo initiallize hoga vhi in the end memory me store hoga! kyunki memory saare data members ke liye ek hi hai iss hi wajah se ek baar me sirf ek hi data member ki value store ho sakti hai!
}

// Enums :
// It is again a user defined data type! bss ye thora syntactically and use case wise alag hai struct and union se! like isme hum integer values ko kuch strings ki help se define krre hai! yes you heard it write! kuch "integer" value ko "string" se represent krte hai, naa ki string ko integer value se!
// An enum, short for "enumeration," is a special data type in many programming languages that allows you to define a set of named values, which are typically used to represent a collection of related constants. Enums provide a way to group and name a set of related values, making code more readable, maintainable, and less error-prone.
// Like aisa kabhi kabhi hota hai na jaise hume koi ek particular cheez ko integer ke jagah string se define kr paate taaki thori confusion and readability badhti code ki! toh bss vhi ki unn integers ko hi string ki help se define krte hai!
// Lets understand this with code...
#include<stdio.h>

int main() {
    enum Meal {Breakfast, Lunch, Dinner};
    // So maanlo jaise kabhi hume kuch calculation krni hai jahaa hume output me breakfast, lunch ya dinner chahiye! toh uss case me bina enum ke toh hum kuch integer values ya koi aur tareeke se define krte ki agar output ye aaya toh mtlb hua breakfast agar ye aaya toh lunch agar ye aaya toh dinner! so yahaa chalo theek hai ki humne output le aaye and koi dikkat bhi nhi hai as such!
    // But aise cheezo ko krne ke ek more readable tareeka ye hai ki hum unn outputs ko kisi string se hi link krde! like Breakfast ko 0 se ki agar 0 aaya toh samajh jayenge ki iska mtlb Breakfast hai and similarly for 1 for Lunch and 2 for Dinner!
    // So bss enum vhi krta hai! isme kuch bhi strings daloge toh usko pehla integral 0 assign hojayega! agar iss Breakfast ko lekar koi bhi calculation kroge toh uss calculation me Breakfast kisi string ka nhi ek 0 ka role play krega kyunki ye Breakfast 0 ko represent kr rha hai becoz we have used enum for it! and similarly for others!
    // Also ye Meal ab ek data type ban gya hai jisme ye 3 tarah ki value store ho sakti hai!

    // For C++
    // cout<<Breakfast;
    // cout<<Lunch;
    // cout<<Dinner;

    // For C
    printf("%d\n",Breakfast); // It will print 0
    printf("%d\n",Lunch); // It will print 1
    printf("%d\n",Dinner); // It will print 2
}

// Another example :
#include<stdio.h>

int main() {
    enum Week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    Week Today = Wednesday; // Today is declared as Wednesday, which assigns the integer value 2 to Today (since enums start at 0 and Wednesday is the third element).
    // Hum chaahe toh yahaa pr Today ko scanf ka use krke input bhi le sakte hai but input ek integer value honi chahiye (Means we will use %d format specifier in C for input) as each value in enum is representing an integer value!

    switch (Today) {
    case Monday:
        printf("Today is Monday");
        break;
    case Tuesday:
        printf("Today is Chewsday");
        break;
    case Wednesday:
        printf("Today is Vensday");
        break;
    case Thursday:
        printf("Today is Thirstay");
        break;
    case Friday:
        printf("Today is Fryday");
        break;
    case Saturday:
        printf("Today is Saturday");
        break;
    case Sunday:
        printf("Today is Sun-Day");
        break;
    default:
        printf("Not a valid day of the week");
        break;
    }
} // Baaki iska aur koi use case hoga you will study them going further! as of now it is enough for enum!
