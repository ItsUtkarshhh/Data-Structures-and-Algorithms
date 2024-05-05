// ---------------------------------------------------------- LECTURE 22 - Character Arrays and Strings --------------------------------------------------------------------------------------------------------->
// If we want to store a name into an array we will use character arrays which are called strings! like ek single character ko store krne ke liye we use char data type and jab inn hi characters ko ek array ke form me store krdenge toh vo character array ban jaate hai! jinko hum strings kehte hai!
// Overall strings are nothing but a 1-D character array!
// Strings me array ki tarah hi values store rehti hai bss difference is that ki yahaa sirf characters store hoti hai!
// Strings are intiallized like char ch[10]; this will be character array (string) of length 10, and isme input lene ke liye we write cin>>ch; that's it, there is one difference and that is ki yahaa pr jab humara input khatam hota hai toh last input ke next vaale block me ek null character (\0) store ho jaata hai which denotes the termination of the string! and its ASCII value is 0
// Vaise hi jab input lene ke liye cout krenge tab bhi jahaa pr null character aayega vahaa pr execution ruk jayega! so suppose there is a character array like, a\0ba\0c\0, isme kya hoga ki jaise hi a ke baad cout ko \0 dikhega vhi pr execution ruk jayega and the final output will be "a" only
// Lets understand further thru code...
#include<iostream>
using namespace std;

int main() {
    char name[20];
    cout<<"Enter you name : "<<endl;
    cin>>name;

    cout<<"Your name is "<<name<<endl;
    // Now here what happened is Utkarsh input dene pr vo toh as it is print hogya but jab "Utkarsh Verma" input diya tab poori string print nhi hui, aisa isliye kyunki space, new line character and tab inn sab se input band ho jaata hai!
}

#include<iostream>
using namespace std;

int main() {
    char name[20];
    cout<<"Enter you name : "<<endl;
    cin>>name;
    name[2] = '\0'; // Humne bss name ke 2nd index pr ek null character daal diya ab as our logic says ki pehle user input krega and then uss input ke 2nd index pr \0 humne daal diya and toh jab cout hoga name, tab pooraa name nhi print hoga sirf index 0,1 print honge kyunki 2nd pr execution ruk gya! toh like agar Utkarsh input doge toh iss naam ke 2nd index pr \0 ajayega and it will look like Ut\0karsh and then print sirf Ut hoga!

    cout<<"Your name is "<<name<<endl;
}

// Question 1 : Find the length of the character array!
#include<iostream>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char input[30];
    cin>>input;
    cout<<"Length of the char array is : "<<lengthString(input)<<endl;
}

// Question 2 : Reverse a string
#include<iostream>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

// First Method of reversing
char* reverse(char input[]) { // Here we have used a * over the char keyword! kyunki bina star ki agar iss function ko create krenge toh ye ek single character return krega sirf but hum chahte hai ki ye ek string return kre and in that case we need to make the data type of the function also a character array! and that's why we have used the *. integer me bhi ye dikkat aa sakti thi pr usme hum pehle se hi size input lete the, pr iss function me humne size input nhi liya hai toh that's why hume kuch toh btaana padega ki isko ek character array return krna hai, toh yaa toh hum star lgaye yaa toh hum isko input me isko size dede!
    int i = 0, j = lengthString(input)-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
    return input;
}

// Second method of reversing
void reverse2(char input[], int n) {
    int i = 0, j = n-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
}

int main() {
    // From first method through reverse function
    char input[50];
    cin>>input;
    cout<<"Reversed character array is : "<<reverse(input);
    cout<<endl;
    // From second method through reverse2 function
    char input2[50];
    cin>>input2;
    reverse2(input2, lengthString(input2)); // Yaa toh length function ki value kisi variable me store kraa ke input me dedo function ke yaa toh directly baat ek hi hai!
    cout<<"Reversed character array is : "<<input2;
}

// Question 3 : Check for a palindrome
// Like kisi ek string ko reverse krne pr bhi vhi same string generate ho rhi hai toh that string will be called a palindrome!
// Here we can solve this question with two different approaches! and they are...
// App 1 : Ek string hai humaare paas, usko reverse kro and then uss reverse string ko kisi aur variable me store kro and then dono strings ko compare kro and if they are same then they will be a palindrome! otherwise not! but isme ek main problem ye hai ki isme hum ek extra space le rhe hai! and due to which the space complexity will increase!
// App 2 : Uss string ke end to end characters ko compare kro end to end and agar saare characters same mil rhe hai toh mtlb ki it will be a palindrome! but yahaa ek cheez aur hoga ki it will be case sensitive! means ye A and a ko alag alag maan ke chalega! so for example agar humne Noon likha toh isko ye palindrome nhi maanega kyunki Noon ka reverse nooN hoga, so we need to keep it in mind! But yahaa hum ek cheez kr sakte hai and that ki upper case ko lower case me convert krke palindrome check kr sakte hai! agar hume case sensitivity se mtlb nhi hai!
// Lets try both the approaches! one by one!
// Approach 1 :
#include<iostream>
#include<cstring>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

char* reverse1(char input[]) {
    int i = 0, j = lengthString(input)-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
    return input;
}

int main() {
    char s1[50] = "Noon";
    char s1_reversed[50];
    strcpy(s1_reversed, reverse1(s1)); // Copy the reversed string into s1_reversed
    
    // Compare the reversed string with the original string
    if (strcmp(s1, s1_reversed) == 0) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
// But yes as we have discussed we have a problem with this approach ki yahaa pr ek extra space le rha hai s1_reversed! so we will move forward with another method!

// Approach 2 :
#include<iostream>
#include<cstring>
using namespace std;

bool checkPalindrome(char input[], int n) {
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(input[s] != input[e]) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

int main() {
    char s1[50];
    cout<<"Enter s1 : ";
    cin>>s1;
    bool result = checkPalindrome(s1, strlen(s1));
    if(result) {
        cout<<"Its a palindrome!";
    }
    else {
        cout<<"Its not a palindrome!";
    }
}
// But still as discusses above there is atill aproblem and that is about the case sensitivity! so for that we will add one more fundtion to it to convert all the UPPERCASE alphabets to lowercase! and the logic will be like, suppose we have a upper case character ch and we want to convert it into lower case so what we will di is, we will write ch - 'A' + 'a', isse kya hoga jaise, suppose koi upper case character hai B toh B - A + a will be be 'b', how? kyunki B - A will give 1 and then a me 1 jab add hoga toh vo b ban jayega! Now we will code it!
// A little modifications in the approach 2 :
#include<iostream>
#include<cstring>
using namespace std;

// So this is how we have managed case sensitivity here! So overall yahaa we have used the ASCII values to convert the Uppercase into lower case!
char tolowercase(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else {
        return ch - 'A' + 'a';
    }
}

bool checkPalindrome(char input[], int n) {
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(input[s] != input[e]) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

// Applied those case sensitivity modifications to it!
bool checkPalindrome2(char input[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(tolowercase(input[s]) != tolowercase(input[e])) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

int main() {
    char s1[50];
    cout<<"Enter s1 : ";
    cin>>s1;
    bool result = checkPalindrome(s1, strlen(s1));
    if(result) {
        cout<<"Its a palindrome!";
    }
    else {
        cout<<"Its not a palindrome!";
    }
}
// In the above code, the checkPalindrome vaala function Noon ko palindrome nhi maanega kyunki isme N and n are considered different! but after those case sensitivity modifications in the checkPalindrome2 function, now the Noon will be considered palindrome kyunki ab N and n are same for that function!

// What are strings! They are character arrays only! but in cpp we have a keyword also for the strings!
#include<iostream>
using namespace std;

int main() {
    string s1 = "Utkarsh";
    cout<<s1<<endl;
    s1.push_back('V');
    cout<<s1<<endl;
    s1.pop_back();
    cout<<s1<<endl;
    cout<<s1.length();
}

// But strings and character arrays are not entirely same! they have some differences and they are...
// 1) Character Array : It is terminated by a null character ('\0'), which marks the end of it. BUT Strings :  The length of a string is determined by its contents and is not limited by a null character.
// 2) Character Array : Its size is fixed at compile time. If you need to store a larger string than the size of the array, you may encounter buffer overflow issues. BUT String : Strings have dynamic size. They can grow or shrink as needed, making them more flexible for handling strings of varying lengths.
// 3) Character Array : While character arrays provide low-level control over memory and can be more efficient in some cases, they require more manual management and error-prone coding practices to handle. BUT String: Strings offer higher-level abstractions and ease of use. They manage memory dynamically, handle null termination automatically, and provide a wide range of utility functions, making string manipulation simpler and less error-prone.
// 4) Character Array : Manipulating character arrays often involves using standard library functions or manual iteration to perform tasks like copying, concatenating, or comparing strings. BUT String : Strings in C++ (std::string) offer a wide range of built-in functions for string manipulation, such as concatenation (+ operator or append() function), comparison (==, <, >, etc.), substring extraction (substr()), searching (find()), and many more.

// Question 4 : Check for a valid palindrome!
// Approach : First we will remove all the faaltu ke characters, then saare characters ko lowercase me convert krenge and then finally we will check that is it a palindrome or not! and jaise jaise hum faaltu characters remove krte jayenge vaise vaise hum unn valid characters ko hum naye strung me push krte jayenge!
#include<iostream>
#include<cstring>
using namespace std;

bool valid(char ch) {
    if((ch >= 'a' && ch <= 'z' ) || (ch >= 'A' && ch <= 'Z' ) || (ch >= '0' && ch <= '9' )) {
        return 1;
    }
    return 0;
}

char tolowercase(char ch) {
    if((ch >= 'a' && ch <= 'z' ) || (ch >= '0' && ch <= '9' )) {
        return ch;
    }
    else {
        return ch - 'A' + 'a';
    }
}

bool checkPalindrome(string a) {
    int s = 0;
    int e = a.length() - 1;
    while(s<=e) {
        if(a[s] != a[e]) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

bool isPalindrome(string s) {
    // Faltu character hataa do
    string temp = "";
    for(int j = 0; j<s.length(); j++) {
        if(valid(s[j])) {
            temp.push_back(s[j]);
        }
    }

    // Now lets convert all of them into a lowercase
    for(int j = 0; j<temp.length(); j++) {
        temp[j] = tolowercase(temp[j]);
    }

    return checkPalindrome(temp);
}

int main() {
    string s1 = "utkr@5$rktu"; // For this it will return 1, means its true that this is palidrome!
    string s2 = "utkr@5$rjhce"; // And for this it will return 0, means its false that it is a palindrome!
    cout<<isPalindrome(s1);
    cout<<isPalindrome(s2);
}

// Question 5 : Find the maximum occuring characters in a string!
// Approach : Here we are going to consider only lowercase characters and both the uppercase and lower case characters both will be considered same and if a string has a and A both, then count of 'a' will be 2, becoz a and A both are considered same!
// Now lets code and then will discuss the approach...
#include<iostream>
using namespace std;

char maxOccCharacter(string s) {
    int arr[26] = {0};

    // Upar humne ek array create kiya jisme jo bhi string hum input krenge uske characters ka count unke alphabetical position ke according store hojayega arr vaale array me!
    for(int i = 0; i<s.length(); i++) {
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <= 'z') {
            number = ch - 'a';
        }
        else {
            number = ch - 'A';
        }
        arr[number]++;
    }

    // Yahaa humne uss arr vaale array ki sabse maximum value nikali!
    int maxi = -1, ans = 0;
    for(int i = 0; i<26; i++) {
        if(maxi<arr[i]) {
            ans = i; // Yahaa pr jiss index pr maximum value hai vo ans me store ki! kyunki in the end yhi toh vo final alphabet batayega jo maximum number of time occur hua hai!
            maxi = arr[i]; // Yahaa pr humne uss index ki maximum value store ki!
        }
    }

    // Then yahaa humne finally a me ans add krke vo konsa character hai jo sabse zyada baar occur hua hai vo nikal liya!
    char finalAnswer = 'a' + ans;
    return finalAnswer;

}

int main() {
    string s;
    cin>>s;
    cout<<maxOccCharacter(s);
}
// Now lets understand upar humne actually kiya kya hai! so maanlo humne ek string enter kiya "moon", now ye moon string function ke pehle for loop me jayegi, and then uske saare characters scan honge and uske saath saath unn sab ka alphabetical order ke according kya kya position hai uske according arr[26] vaale array me uss character ka count increament krdiya jayega!
// So like if moon is there, then 'm' gya pehle for loop me and now ch - 'a' vaale if statement me gya ye 'm' and usme isko number mila 13 according to ch - 'm' and now, arr[26] me 13th position pr ek count add krdiya gya using arr[number]++ and aise hi baaki characters of that string ke saath hua and then finally, next for loop me uss arr[26] ko hi traverse krke jo maximum value tha uska jo index tha vo nikala gya and then uss index ko 'a' ke saath add krdiya gya and then we got the final character jo sabse maximum times occur hua hai!


// cin.getline() function : This is a function which is used to take input a string with spaces, like we know a normal cin will stop input whenever a space, newline or tab is encountered! but using this cin.getline() here we can specify that from where the input will be stored and what will be the maximum size of input and what will be the delimiter, like in normal cin delimiters are newline, tab or space, but here we can specify the delimter if we let that parameter vacant then newline will be considered as delimiter by default!
#include<iostream>
#include<string>
using namespace std;

int main() {
    const int max_size = 50;
    char ch[max_size];
    cin.getline(ch, max_size); // Here we have'nt use the delimiter so bydefault it will be \n which i the newline!
    cout<<ch;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
    const int max_size = 50;
    char ch[max_size];
    cin.getline(ch, max_size, '7'); // Here we have used a delimter so while inputting a string kahin pr bhi input me agar 7 dikh gya toh vhi pr execution stop hojayega! and jab print karaoge toh bss uss delimiter tak hi print hoga! and similarly we can use any delimiter!
    cout<<ch;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
    const int max_size = 50;
    string str;
    getline(cin, str, '7'); // This function does the same as of the cin.getline function as in character arrays! here also we can use delimiter the only thing is that here the parameters are a little different!
    cout<<str;
}

// Now there are some inbuilt functions in strings! and they are like : strcmp(), strlen() and strcpy().

// Question 6 : You have a line of text and you have to replace all the spaces with the @40
#include<iostream>
#include<string>
using namespace std;

string replaceSpaces(string &str) {
    string temp = "";
    for(int i = 0; i<str.length(); i++) {
        if(str[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            temp.push_back(str[i]);
        }
    }
    return temp;
}

int main() {
    string input;

    cout<<"Enter the string : ";
    getline(cin, input);

    cout<<replaceSpaces(input);
}

// Question 7 : Remove all the occurences of a sub string in a parent string!
// So like suppose we have a string which is daabcbaabcbc now we want to remove a substring abc from the main string!
// so what we will do is first we will remove the abc when it appears the first time while traversing the string! so from da"abc"baabcbc "abc" will be removed and the final string will be dabaabcbc,
// now we will remove it again! daba"abc"bc, nnow we will remove it again and the new string generated is dababc now again we will remove abc from the string and now we will remove dab"abc" and now the final string will be dab! so hence this will be our final string!
// Now we will code the logic!
#include<iostream>
#include<string>
using namespace std;

string removeOcc(string str, string substr) {
    while(str.length()!=0 && str.find(substr) < str.length()) {
        str.erase(str.find(substr), substr.length());
    }
    return str;
}

int main() {
    string str;
    string substr;
    getline(cin, str);
    getline(cin, substr);
    cout<<"The final string is : "<<removeOcc(str, substr);
}

// Question 8 : Permutation in string! agar s1 vaali string ka koi bhi permutation (arrangement) agar s2 me exist krta hai toh hum uss case me true return krenge!
// Like suppose, s1 : ab and s2 : eibaooo, now we know s1 permutations can be "ab" and "ba", so ab agar s2 me ab ya ba me se koi bhi exist krta hai toh hum true return krdenge!
#include<iostream>
#include<string>
using namespace std;

bool checkEqual(int a[26], int b[26]) {
    for(int i = 0; i<26; i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

bool checkInclusion(string s1, string s2) {
    // character count array
    int count1[26] = {0};

    for(int i = 0; i<s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // Traverse s2 in window of size of s1 length and compare
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    // Running for first window
    while(i<windowSize && i<s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if (checkEqual(count1, count2)) {
        return 1;
    }

    while(i<s2.length()) {
        char newChar = s2[i];
        int newIndex = newChar - 'a';
        count2[newIndex]++;

        char oldChar = s2[i - windowSize]; // Getting the character going out of the window
        int oldIndex = oldChar - 'a';
        count2[oldIndex]--; // Decrementing its count since it's going out of the window

        i++;
        
        if (checkEqual(count1, count2)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    string s2 = "eibbabo";
    string s1 = "ab";
    cout<<checkInclusion(s1, s2);
}

// Question 8 : Removing all adjacent duplicates! Actual question number 1047 on LeetCode!
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while(i<n) {
        int j = i+1;
        while(j<n && chars[i] == chars[j]) {
            j++;
        }
        // Yahaa kab aoge? ya toh jab vector poora traverse krdiya, ya toh jab new/different character encounter kiya!

        // Old Character store krliya!
        chars[ansIndex++] = chars[i];
        int count = j-i;

        if(count>1) {
            // converting counting into single digits and saving the answer...
            string cnt = to_string(count);
            for(char ch : cnt) {
                chars[ansIndex++] = ch;
            }
        }
        // Moving to new different character
        i = j;
    }
    return ansIndex;
}

int main() {
    vector<char> str = {'a','b','b','c','c','d','d'};
    compress(str);

    for (int i = 0; i < compress(str); i++) {
        cout << str[i];
    }
}
