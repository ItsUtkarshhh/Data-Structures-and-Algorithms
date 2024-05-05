//Data Structures and Algorithms
//Data Structures : They are way to arrange data in main memory for efficient usage and they are ingredients to make good algorithms. Example : Arrays, Stacks, Linked List, Queue, Binary Search Trees.
//Algorithms : Sequence of steps to solve a given problem. Eg : Sorting an Array
//Database : Collection of information in permanent storage for faster retrieval and updation.
//Dataware House : Management of huge amount of legacy data for better analysis. Legacy data is that data which is stored for analysis purposes and now it has no use. like facebook stores some data like how many times you viewed one profile and how many times you commented a particular comment, these data are of no use but they are being stored to analyse and create algortihms, this is dataware house.
//Big Data : Analysis of too large complex data which cannot be dealt with traditional data processing application, like making a search engine will require you a lotttt of data that a normal or general processing computer can't even store.

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

// Type Casting in C++ :
#include<iostream>
using namespace std;

int main() {
    int a = 'b';
    cout<<a<<endl; // Yahaa kya hua ki jab a ko int data type diya and then usme ek character store krne ki koshish ki tab implicit conversion hogya int se char me and jo int value (ASCII value) b se map krti hai vo print hogyi!

    char ch = 99;
    cout<<ch<<endl; // Yahaa bhi vaisa hi hua jo upar hua, yahaa pr jab humne 99 jo ek integer value hai jab humne vo store krne ki koshish ki tab 99 jiss character se map hota hai ASCII table ke according vo charcater print hojayega, here that character is c toh vo print hogya! 

    char ch2 = 123456;
    cout<<ch2<<endl; // Yahaa as we know that int me 0 -> 2^31-1 tak ki values store ho sakti hai, and char me 0 -> 2^8-1 tak ki values print ho sakti hai! so what if agar hum koi 2^16 jaisi value store kraane ki koshish kre toh in character, tab kya hoga? then jo least significant byte mtlb jo rightmost 8 bits hongi (as becoz char 1 byte = b bits ki value store krta hai) toh utni values ko lekr utne ko hi character me convert hojayega and vo print hojayegi!
} //Means like here in ch2 we tried to store 123456, so ho sakta hai jo rightmost byte hogi usme 64 ban rha hoga and 64 maps with @ character in the ASCII table, toh bss vo print hogya!

// Now abhi tak toh hum ye samajh gye ki positive numbers kaise store hote hai memory me, but negative numbers kaise hote hai store?? So ans is that if first bit is 1 it is -ve and if 0 then +ve!
// If we want to store a negative values in the memory then first we ignore the -ve sign and then we take its 1's complement and then 2's complement and now the leftmost bit will tell the sign if its 0 then +ve and 1 then -ve!
    // Example : int a = -5 ko agar store krna hai, so it will be like : first we will ignore the -ve sign hence, 00000000 00000000 00000000 00000101 -> 11111111 11111111 11111111 11111010 (1's complement) -> 11111111 11111111 11111111 11111011 (2's complement), hence ab ye store hojayega! and jo leftmost bit hai vo iska sign btaa rha hai that's negative!

// Now if we want to print that -ve value -5, so ab as we know ki memory me toh ye 11111111 11111111 11111111 11111011 stored hai, so ab pehle 1's complement hoga, steps will be, 11111111 11111111 11111111 11111011 -> 00000000 00000000 00000000 00000100 (1's complement) -> 00000000 00000000 00000000 00000101 (2's complement), now as we knwo the final value jo aayi vo toh +5 denote krti hai, toh value yahaa se lelenge and sign jo value pehle stored thi memory me which was this 11111111 11111111 11111111 11111011, toh yahaa se uska sign lelenge (that's the leftmost bit 1 and hence it represents the sign) and aise ye negative value print hojayegi!

// ---------------------------------------------------------- LECTURE 2 - Basics --------------------------------------------------------------------------------------------------------->

// And now we have 2 variation while assigning a data type, that is signed and unsigned, signed jab hota hai toh -(2^31-1) -> (2^31-1) itni range ki values store ho sakti hai and jab unsigned hota hai tab 0 -> (2^31-1) values store hoti hai! means only positive values!
#include<iostream>
using namespace std;

int main() {
    unsigned int a = -123;
    cout<<a<<endl; // Reason : By default int is always signed, if we make it unsigned and then if we will try to store a -ve value tab kya hoga ki jo abhi hum upar kr rhe the print kraane time 1's complement ke baad 2' complement leke, and last me jo humne last me jo value aayi thi usko and previously jo stored value thi jisme leftmost bit 1 tha unn dono ko humne under consideration leke -ve value print kraya tha na, pr ab jab humne pehle hi int ko unsigned declare kiya hua hai toh ab iss baar vo previously stored value ko dhyaan nhi dega and seedha jo final value thi usko print krdega! and hence it will print a very large number!
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
} //Understand the logic here, we used the outer loop to swithc between rows and inner loop to print the * (switch between columns)!

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

// ---------------------------------------------------------- LECTURE 4 - Pattern Making --------------------------------------------------------------------------------------------------------->
// Here we will be solving only wuestions related to patterns!
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
// My Solution 1 :
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

// My Solution 2 :
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
        // val++;
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
        char val = 'A'+n-i+j-1;
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
// AND (&) : Suppose we are doing 2 & 3, then its output will be decided at the bit level, like... 2 -> 10 and 3 -> 11 now we will do the AND operation of each bit, as 10 & 11 and it will give 10 which is 2 and hence the output will be 2, we ust have to do the normal AND operation!
// OR (|) : Similarly as above, 2 | 3, it can be written as 10 | 11 and its output will be... 11 and it is 3, hence the output will be 3!
// NOT (~) : Here it is a little different, like ~2, now we know that int is 4 bytes and we know that it stored as 00000000 00000000 00000000 00000010 in the memory, so iska NOT krna hai, so poore ka NOT krna hai toh one's complement lelo, and it will be... 11111111 11111111 11111111 11111101 and now ab we isko print krna hai, toh ab we know kaise print krte hai, pehle most significant bit denote krta hai sign which is -ve, now baaki remaining bits ka 2's complement lenge, and we know 2's complement kaise lete hai, that is 1's complement and then add 1 and uske baad final answer ayega and hence the answer will be, (most significant bit toh sign ke liye use hogyi toh uske alawa remaining bits ko convert krliya decimal me) (1)0000000 00000000 00000000 00000011 and hence the answer will be -3
// XOR (^) : Here its like, jo same bits hoti hai unka output 0 and opposiet bits hoti hai unka output 1, so 2 ^ 3 ka output hoga 10 ^ 11 will be 1! according to the truth table of XOR!

// Now some more featured are, left-shift and right-shift, which will be done, suppose you are said to do "3<<2" it means 3 ko 2 baar left shift krdo, means 3 ke harr bit ko 2 baar left me shift krdo! hence, 00000000 00000000 00000000 00000011 isko 2 baar right shift krne ka mtlb hua ki 00000000 00000000 00000000 00001100, and it will be 12, and same is the right shift...
// Also a note that mostly aisa lgega ki left shift krne se number 2 se multiply ho jaate hai, and ye baat kaafi hadd tak sahi bhi hai, like upar hu dekhlo, 3<<2 me 3 me 2 times 2 multiply hogya and answer mila 12, which is 3x2x2, so mostly cases me yhi hoga, bss right shift me 2 se divide hota hai... But in case of large numbers ye nhi hoga, kyunki reason being... suppose a number 01000000 00000000 00000000 00000010, this is a very large number, toh yahaa kya hoga ki agar humne isko 1 baar left shift krdiya, toh most significant but 1 banjayega, and isse vo number -ve number ban jayega, so yaa aisa bhi hota hai, so that's why this shorcut is not valud for very large number, but for small number it is valid!
// Baki ye tob aat hogyi +ve numbers ki like ek aur cheez hoti hai that is padding, means jab hum left shift kr rhe hai toh right me 0's add kr rhe hai means +ve numbers me 0 ki padding hoti hai, but -ve numbers ka kuch ptaa nhi hota, answer will be depended on compiler!

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
// Also in for loop where we know that there is one section of iteration, then condition and then increment or decrements, so one add on to that, is teeno section me ek se zyada interations, conditions and increments add kr sakte hai!
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

// 2nd Approach : Agar hum thora soche, toh we can see that kisi number ka 1 ke saath bitwise & krne pr, agar output 1 aaye toh vo ek odd number and agar even aaye toh vo ek even number hai! Another way of looking at it is like agar kisi number ka 1 ke saath bitwise & krne pr 1 output aata hai toh mtlb ki uske rightmost bit 1 hai, and vahi agar output 0 aaye toh mtlb ki uska rightmost bit (jisse hum calculate kr rhe hai) 0 hai, so from here we can see that ki hum kisi number ka 1 ke saath bitwise and krne se hum uska rightmost bit nikal sakte hai, toh bss hum aise hi krenge and after humne rightmost bit ka nikal liye ek baar, toh fir uss number ko rightshift krdenge taaki baaki ke places me bhi konsi bit hai 1 ya 0 vo nikal sake,
// hence our flow will be, We will find the bitwise & of that number with 1 and then we will do the rightshift and then again we will find the bitwise & with 1, and we will do it until we have checked all the bits! But now the thing is how we will create or generate our final answer! so for that we will create a formula...
// Initiallize a variable ans = 0; now, yahaa hum digit vaale variable me vo saare bits rakhenge jo uoar bitwise & vaale operation kr kr ke obtained hue hai!
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
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n>=0) {
        int ans = 0;
        int i = 0;
        while(n!=0) {
            int digit = n&1;
            ans = (ceil(pow(10,i)) * digit) + ans;
            n = n>>1;
            i++;
        }
        cout<<ans;
    }
    else {
        int i = 0;
        int bin;
        int fbin = 0;
        while(n!=0) {
            bin = n&1;
            fbin = (ceil(pow(10,i)) * bin) + fbin;

        }
    }
}

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
// So now we will do the start the left-shifting, and ab iss baar jab bhi left shift kr rhe honge toh 1 ke saath 'or' krenge taaki jo bhi nayaa padding vaala zero aaye vo 1 ke saath 'or' me 1 ban jaye, and that is how we will get the mask! continue the above example : abhi tak we got, 00000000 00000000 00000000 00000, on doing three times left shifting and then performing 'or' operation with 1 will attach 1 bits to its rightmost bits, and we will get, 00000000 00000000 00000000 00000111 and this is the mas we needed!
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
// As exit not just pull you our of a loop, it pull you out of the entire program!
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
// Print the nCr values of the number inout by the user!
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
        cout<<a<<endl;
    }
    {
        int a = 15;
        update2(a);
        cout<<a<<endl;
    }
    {
        int a = 4;
        a = update3(a);
        cout<<a<<endl;
    }
}
