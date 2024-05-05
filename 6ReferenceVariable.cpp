// ---------------------------------------------------------- LECTURE 28 - Reference Variable and Static vs Dynamic Memory --------------------------------------------------------------------------------------------------------->
// Similar to that we have difference names for a same person!
// Reference variable are those jab hum ek hi memory location ko do ya usse zyada alag alag names se bulate hai, like agar ek memory location ya block ko i se bulaya jaa rha hai and uss same ko hi hum j se bhi bula rhe hai then j is the reference variable!
// Reference variable is created like this...
#include<iostream>
using namespace std;

int main() {
    int i = 5;
    int &j = i; // This is how we create a reference variable! so yahaa pr do different names hai same memory block ke, i and j!
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<j<<endl;
}

// Why we need it...remember we have studied about the pass by value and all...vahaa copy ban rhi thi jo variable pass ho rha tha function call me so we will create reference variable so that vo copy na bane and jo jisme change krna chahte hai changes uss hi me changes hojaye! which is called pass by reference!
#include<iostream>
using namespace std;

void update(int n) { // Here it is pass by value so yahaa ek copy ban jayegi!
    n++;
}

void update2(int &n) { // Here it is pass by reference so yahaa copy nhi banegi and changes original variable me hi honge!
    n++;
}

int main() {
    int n = 5;
    cout<<"After : "<<n<<endl;
    update(n);
    cout<<"Before : "<<n<<endl; // Iss case me koi changes nhi ayega! kyunki this is pass by value!

    cout<<"After : "<<n<<endl;
    update2(n);
    cout<<"Before : "<<n<<endl;
} // So isme kya hua ki jo variable humne function call me pass kiya vo ek reference ki tarah pass hua function defintion ke kaaran! isse what actually happened is &n uss hi variable ko refer kr rha hai jo function call me pass hua hai isse jo changes honge vo uss original vaale me hi hojayenge!

// What if we want to return a reference variable from a function? is it right thing to do? lets see...
#include<iostream>
using namespace std;

int& func1(int n) {
    int num = n;
    int& ref = num;
    ref++;
    return ref;
} // Doing this does not make sense! kyunki dekha haye toh humne ek function ke scope me hi ek variable create kiya num and then uska hi ek reference variable create kiya so uss ref variable ka bhi scope function ke scope tak hi hai! so isko return kraane ka koi sense nhi hai kyunki ye dono hi variables are local variables so inn dono ka existence iss scope tak hi hai uske baad they will be dead, so what are we returning? thats why this is not right to do!

int* func2(int n) {
    int* ptr = &n;
    return ptr;
} // Doing this is also wrong coz of the same reason! ki iska scope is function ke scope tak hi valid hai to return kya kr rhe hai!

int main() {
    int n = 5;
    cout<<func1(n)<<endl;
} // So overall doing this is not good!

// Now lets talk about arrays!
// Remember? writing this throws errors, int n; cin>>n; int arr[n]; isme hum chah rhe hai ki program ke runtime me array ko uska size allocate ho! and ye nhi hota hai! aisa kyu? becoz see..
// There are two types of memory while compiler time, one is stack and another is heap! stack is that memory jo compiler allocate krta hai ek program ko and heap is large memory which is allocated to that program but stack is small! so maanlo agar humne ye code likh ke execute krdiya and size of array pehle specify nhi kiya toh pehle toh compiler ek stack and ek heap memory program ko allocate krdega apne hisaab se but agar runtime me humne jo size of array daala vo size of stack allocate to the array during the compile time se zyada hogya toh? in that case program will crash and that is why doing this is BAD practice!
// Isliye agar size ptaa na ho toh pehle se hi array ka size badaa leke chalo... but ye vaala kaam mtt kro!

// So can't we create variable size array? yes we can...
// So agar hume ye krna hai toh pehle toh stack ki memory toh stactic rahegi, toh dynamic memory allocate krne ke liye ki like runtime pr hum btaa sake ki hume kitni memory chahiye for that we will use that Heap memory! and for that we have to use the "new" keyword!
// so we will write "new char;" isse heap me ek char type ki memory allocate hojayegi bss uska koi naam nhi hoga, name and all ye sab stack memory me hota hai heap me nhi! and ye "new char;" keyword ek address return krega! jisko hum use krenge uss heap memory ko access krne ke liye!
// so we will write "char* ch = new char;" isse ye hua ki jo memory heap me create hui thi uska address humne ek pointer ki help se store krliya in the stack memory! and now we can access it! toh stack me ek pointer hai ch naam se jo heap ki ek memory ko point kr rha hai!

// Creating a dynamic array using heap and dynamic memory allocation! so we will write...
#include<iostream>
using namespace std;

int getSum(int *arr, int n) { // int arr[] bhi likh sakte hai int *arr ki jagah... but lets play with pointer which is more dynamic!
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // int *arr = new int[5]; // Isme int *arr se stack me ek pointer create hua jo heap me 5 size ke array ke first index ko point kr rha hai!
    // Now our main aim was to create a dynamiz size ka array, mtlb runtime pr hum array ka size daale and runtime pr define ho ki array ka size ka hoga!
    int n;
    cin>>n;
    int *arr = new int[n]; // this makes total sense as, stack ki memory to limited hai isliye hum variable size stack ke case me daal nhi paa rhe the but ab new keyword se jo heap me memory allocate ho rhi hai vo toh badi hai kaafi toh vahaa toh hum variable daal sakte hai kyunki yahaa pr enough space hai!
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Sum of elements of the array : "<<getSum(arr, n); // Another variation if we want, we can also try (arr+2, n-2) isse hum jo bhi array input krenge jitne bhi size ka uske 2nd index se sum hona shuru hoga naa ki first index se and similarly we can do more things!
} // So this is how we have allocated dynamic memory!
// lets calculate memory kitni jaa rhi hai static and dynamic me! agar hum normally aise likhte int arr[50]; isme 50*4 = 200 bytes of memory use ho rhi thi... agar hum iss hi ko dynamically kre toh int *arr = new int[50]; isme 50*4 + 4 (My compiler is of 32 bits isliye size of pointer is 4 bytes otherwise it can also be 8 bytes!) = 204 bytes are being used! here it is more than the static memory!

// Lets see some interesting stuff!
#include<iostream>
using namespace std;

int main() {
    while(true) {
        int i = 5;
    } // Isme kya ho rha hai ki stack me baar baar i naam se ek memory create hote jaa rhi hai but jaise hi scope khatam ho rha hai vaise hi vo khud hi delete bhi ho jaa rhi hai! toh means harr ek instant of time me ek hi i variable hai stack me!

    while(true) {
        int *p = new int;
    } // In this case ek pointer create ho rha hai p naam se stack me and heap me int size ki ek memory allocate ho rhi hai, but jab scope end ho rha hai toh stack vaali memory toh khud delet ho jaa rhi hai but heap vaali aise hi khud delete nhi hoti! toh harr baar heap me memory bharte jaa rhi hai int size ki and ek time ke baad heap full hojayega and program crash kr jayega!
    // Static aur Dynamic me yhi antar hai ek toh ki static me khud hi memory use hone ke baad delete ho jaati hai pr Dynamic me aise nhi hoti! to delete that memory we use "delete" keyword!
}

#include<iostream>
using namespace std;

int main() {
    int *i = new int; // dynamically allocated memory for i
    delete i; // we will write this to delete i from heap as well!

    int *p = new int[50];
    delete []p; // we will write this to delete the array from the heap!
}

// Void Pointers : Void pointers, also known as generic pointers, are pointers that point to data of unspecified type! declared as void *ptr;
int main() {
    int num = 10;
    float fnum = 3.14;

    void *ptr;

    // Assigning an int pointer to a void pointer
    ptr = &num;
    // Dereferencing a void pointer after casting it to an int pointer
    printf("Value of num: %d\n", *((int*)ptr));

    // Assigning a float pointer to a void pointer
    ptr = &fnum;
    // Dereferencing a void pointer after casting it to a float pointer
    printf("Value of fnum: %f\n", *((float*)ptr));

    return 0;
}
// You can assign any type of pointer to a void pointer without explicit casting, but you need to cast it back to its original type before dereferencing it.

// ---------------------------------------------------------- LECTURE 29 - Dynamic Memory Allocation in 2D arrays! --------------------------------------------------------------------------------------------------------->
// 1D array me ko dynamically kaise banaate the that you get it! so in case of 2D arrays we need to think like this...
// 1D ke liye we use to write, int *arr = new int[5]; here humne 1D array ke liye multiple int blocks banaye heap me! and sabse pehle int block ka address humne store krdiya arr me jo stack me hai!
// So for this case, we will do this... int **arr = new int*[n]; isme what we did is ki humne jaise pehle 1D array banane ke liye multiple int blocks banaye the heap me vaise hi 2D array banane ke liye humne pehle multiple n arrays ke rows banaa liye heap me and then we will create columns for each row of arrays, like...
// for(int i = 0; i<n; i++) {
//     arr[i] = new int[n];
// }

// int **arr = new int*[n]; Lets understand the main function...
// int **arr : Declares a pointer to a pointer to an integer. This means arr will point to a memory location that stores the address of another memory location, which in turn stores integers.
// new int*[n]; : Dynamically allocates an array of pointers to integers. Here, n specifies the number of pointers in the array. Each element of this array will hold the address of a dynamically allocated array of integers.
// After this statement, arr points to the first element of the array of pointers, which are not yet initialized
// and then vo loop vaala kaam!
// lets try this once...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int **arr = new int*[n];
    for(int i = 0; i<n; i++) {
        arr[i] = new int[n];
    }
    // 2D array creation done!

    // taking input into the 2D array!
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    // priting output
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
} // that is how 2D array is created using dynamic memory allocation and printing it! for same number of rows and columns
// lets do it once also for different row and column size!
#include<iostream>
using namespace std;

int main() {
    int r;
    cin>>r;

    int c;
    cin>>c;
    int **arr = new int*[r];
    for(int i = 0; i<r; i++) {
        arr[i] = new int[c];
    }
    // 2D array creation done!

    // taking input into the 2D array!
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cin>>arr[i][j];
        }
    }

    // priting output
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
} // that is how 2D array is created using dynamic memory allocation and printing it! for different number of rows and columns!
// And jab bhi hum heap me memory create krte hai toh we should keep in mind ki we should also delete it after it is used!

// 2D array dynamic visuallization : isme hua hai kya hai ki heap me pehle toh n pointer bane hai and unn n pointers ke corresponding arrays create ho rakhi hai!
// so agar hum pehle unn pointers ko delete krdenge toh heap me jo create ho rakhi arrays hai vo toh reh jayengi! so pehle we will delete the arrays and then the pointers in the stack!
#include<iostream>
using namespace std;

int main() {
    int r;
    cin>>r;

    int c;
    cin>>c;
    int **arr = new int*[r];
    for(int i = 0; i<r; i++) {
        arr[i] = new int[c];
    }
    // 2D array creation done!

    // taking input into the 2D array!
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cin>>arr[i][j];
        }
    }

    // priting output
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    for(int i = 0; i<r; i++) {
        delete []arr[i];
    }
    // heap memory deleted!

    delete []arr;
    // stack arrays deleted!
}


// ---------------------------------------------------------- LECTURE 30 - Macros, Global Variable, Inline Functions and Default Args --------------------------------------------------------------------------------------------------------->
// We will learn some techniques jisse we can optimize our code!
// Macros : A piece of code in a program that is replaced by the value of macro! Macro is defined by #define directive
// Lets understand macro with this context, suppose you are making a program jisme hum bhot baar PI ki value 3.14 use kr rhe hai, but kabhi maanlo future me jaake PI ki value 3.15 hojaati hai toh ab kya hum harr jagah jaake program me PI ki value change krenge? Nhi! for that we will just write #define PI 3.14... ab future me jab bhi PI ki values change hoti hai toh hum PI ki value sirf macro me jaake change krdenge and humara kaam hojayega!
// You can argue ki ek aur solution ho sakta tha and that is ek global variable declare krdo! double PI = 3.14.. isme ye dikkat hai ki isme hum ek extra space le rhe hai... itni si space lene se zyada fark toh nhi padega but still agar bina space liye macro se kaam ho jaa rha hai toh kyu space le!
// lets see thru code...
#include<iostream>
using namespace std;

#define PI 3.14

int main() {
    int r = 5;
    // double area1 = 3.14 * r * r;
    // cout<<"Area of circle : "<<area1<<endl;
    // Is way se krne pr hume kabhi agar 3.14 jo PI ki value hai usko change krna pad gya toh bhot dikkat hojayegi, yahaa toh chalo bss ek baar use hui hai but agar kabhi 100 baar use hogyi toh harr 100 jagah jaake change krna feasible nhi hai! so another solution could be declaring local/global variable

    // double PI = 3.14;
    // double area2 = PI * r * r;
    // cout<<"Area of circle : "<<area2<<endl;
    // Isme dikkat ye hai ki ye extra space le rha hai PI ki value store krne ke liye! also yahaa koi easily program me PI ki value PI = PI + 1 krke update kr sakta hai! jo ofc hum nhi chahenge! so that is why in these cases we use define macro!

    double area3 = PI * r * r;
    cout<<"Area of circle : "<<area3<<endl;
    // Isme koi space bhi nhi li PI ne and ye PI updatable bhi nhi hai!
    // PI = Pi + 1; // Not possible!
    // Agar kabhi value change hoti hai toh compile hone se pehle hi macros program me sab jagah values update krdega!
}

// Another example of macro #define
#include<iostream>
using namespace std;

#define Area(l,b) (l*b) // yahaa that is how we have used macros!

int main() {
    int l = 3, b = 5;
    cout<<"Area of rectangle : "<<Area(l,b);
}

// Types of Macros : Object Like Macros, Chain Like Macros, Multiline Macros, Function Like Macros!
// Object Like Macros : ye upar jo hum kr rhe the ye vhi Object like macros ka hi example the!
#include <iostream>
using namespace std;

#define DATE 31

// Driver Code
int main() {
	cout<<"Lockdown will bve extended upto "<<DATE<<"-MAY-2020."<<endl;
}

// Chain Like Macros : Macros inside macros are termed chain macros. In chain macros first of all parent macro is expanded then the child macro is expanded.
#include <iostream>
using namespace std;

#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

int main() {
	cout<<"I have "<<INSTAGRAM<<"K followers on Instagram!"<<endl;
}

// Multiline Macros : An object-like macro could have a multi-line. So to create a multi-line macro you have to use backslash-newline.
#include <iostream>
using namespace std;

#define ELE 1, \
            2, \
            3
            // Yahaa mye macro likhne ka tareeka aise hi hoga! iss hi format me!

int main() {
	int arr[] = { ELE };
    cout<<"Printing array : ";
    for(int i = 0; i<3; i++) {
        cout<<arr[i];
    }
}

// Function Like Macros : These macros are the same as a function call. It replaces the entire code instead of a function name. Pair of parentheses immediately after the macro name is necessary. If we put a space between the macro name and the parentheses in the macro definition, then the macro will not work.
// A function-like macro is only lengthened if and only if its name appears with a pair of parentheses after it. If we don’t do this, the function pointer will get the address of the real function and lead to a syntax error.
#include<iostream>
using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main() {
    int a = 20, b = 40;
    cout<<"Out of "<<a<<" and "<<b<<", "<<min(a,b)<<" is smaller value.";
}

// Global Variables!!
// They are used when we want to share some variables between functions! Ye sharing variable vaal kaam hum ref variable se bhi kr sakte hai, kyunki agar int main me koi variable hai usko hum chahte hai ki usko multiple functions access kr sake toh vo toh hum ref variable se bhi kr sakte hai sab func me int main vaale variable ka ref pass krke! but also ek tareeka hai variable share krne ka and that is global variable bnaa ke! usme bhi memory block ek hi hota hai and multiple functions access kr paate hai!
#include<iostream>
using namespace std;

int i = 10; // Global variable i, this can be accessed any where!

void a(int& x1) {
    cout<<"Value of x1 referenced from i of int main outer block : "<<x1<<endl;
    cout<<"Address of x1 referenced from i of int main outer block : "<<&x1<<endl;
    cout<<"Value of Global i : "<<i<<endl;
}

void b(int& x2) {
    cout<<"Value of x2 referenced from i of int main outer block : "<<x2<<endl;
    cout<<"Address of x2 referenced from i of int main outer block : "<<&x2<<endl;
    cout<<"Value of Global i : "<<i<<endl;
}

int main() {
    int i = 5;
    {
        int i = 3;
        cout<<"Value of int main inner block i : "<<i<<endl; // It will print 3
        cout<<"Address of int main inner vblock i : "<<&i<<endl;
    }
    cout<<"Value of int main outer block i : "<<i<<endl; // It will print 5
    cout<<"Address of int main outer block i : "<<&i<<endl;
    // Local variable toh we know what are they!

    a(i);
    b(i);
}
// lets understand certain things, yahaa 3 memory blocks hai i naam se jinme sabka scope alag alag hai hence inn sabko alag alag memory location allot ki gyi hai memory me, isliye inn teeno i's ka address ek dusre se different hoga!
// and int main me just baad jo i hai (i=5 vaala) and jo functions me jo x1 and x2 hai inn teeno ka address same hoga kyunki ye sab same jagah point kr rhe hai! which is i = 5 vaale memory block pe!
// Also the global i is not affecting the values of local i and the functions the local i is referencing to, this is becoz hume dekhne se lag rha hai ki local i and global i same hai kyunki unke naam same hai, pr they are two different memory locations! and hum jo function call me pass kr rhe hai vo local i variable hai isliye functions output bhi uss hi ke hisaab se de rhe hai!
// So abhi tak we get it, ki teeno i's are different and have different memory locations kyunki sabka alag alag scope hai! and i = 5 vaala i and x1, x2 are just different names of the same memory block i = 5! isliye inn teeno ka address same hai and teeno i ka different hai!

// Hum chahe toh global i variable bhi pass kr sakte hai a and b ke function call me, like this...its bit extra to know, but okay...
#include<iostream>
using namespace std;

int i = 10; // Global variable i, accessible anywhere

void a(int& x1, int& global_i) {
    cout<<"Value of x1 referenced from i of int main outer block : "<<x1<<endl;
    cout<<"Address of x1 referenced from i of int main outer block : "<<&x1<<endl;
    cout<<"Value of Global i : "<<global_i<<endl;
}

void b(int& x2, int& global_i) {
    cout<<"Value of x2 referenced from i of int main outer block : "<<x2<<endl;
    cout<<"Address of x2 referenced from i of int main outer block : "<<&x2<<endl;
    cout<<"Value of Global i : "<<global_i<<endl;
}

int main() {
    int i = 5; // Local variable i in main
    {
        int i = 3; // Local variable i in inner block
        cout<<"Value of int main inner block i : "<<i<<endl; // It will print 3
        cout<<"Address of int main inner block i : "<<&i<<endl;
    }
    cout<<"Value of int main outer block i : "<<i<<endl; // It will print 5
    cout<<"Address of int main outer block i : "<<&i<<endl;

    // Passing global variable i into the function calls
    a(i, ::i); // Pass local i and global i to function a
    b(i, ::i); // Pass local i and global i to function b
    // Here we need to use :: (scope resolution operator) to explicitly specify the global scope. In your code, ::i is used to refer to the global variable i.
    // Inside the main function, you have a local variable i, and outside of any function, you have a global variable i. When you want to specifically refer to the global variable i within the main function or any other function, you use the scope resolution operator :: followed by the variable name (::i).
    // To avoid ambiguity : Since there's a local variable i within the main function, if you simply use i within the function calls to a and b, it will refer to the local i variable, not the global one. To differentiate between the local and global variables named i, you use ::i to explicitly refer to the global variable.
}

// But using Global variables is not good, its a bad practice, kyunki agar maanlo humne koi ek program likha jisme hume ek hi variable bhot baar use krna ho rha hai, toh humne usko global bnaa diya, but problem is isko koi bhi update kr sakta hai and agar ek baar update hogya toh kaam khraab hojayega! jabki aisa define ke case me nhi tha!
// Jaise define me pta hai hume ki agar koi change krega bhi toh vo sirf define me macro ki value me hi change krega toh usko toh baad me undo kiya jaa sakta hai! but agar kisine global variable me koi change krdiya within the program me kahin bhi, toh uss change ko dhundna mushkil hojayega! jabki we know define ke thru macro bnaa ke value use krne pr vo program me kahin bhi aur update nhi ho sakta except the define itself, but global variables intiallize krne ke baad bhi program me kahin bhi change ya update kiye jaa sakte hai!


// Inline Functions!
// The thing is jab hum koi program likhte hai, toh uss poore program ki ek stack banti hai as we have talked earlier! and sabse pehle uss stack me int main function aata hai and then int main ke jo variable hote hai vo apni apni memory space lelete hai! then uu int main me koi function call ho rhi hoti hai toh pehle vo function hoti hai then vahaa se return me jo bhi response aata hai (and isme processing lgti hai!) another thing is  ek function call me jo variable hote hai function defintion me unki copy ban jaati hai and iske kaaran aur memory use ho rhi hai!
// ab optimize krna hai hume code ko toh function call krna hataa bhi nhi sakte kyunki usse readility badhti hai code ki, toh kya kre? ki sab cheeze settle hojaye!
// lets see...
#include<iostream>
using namespace std;

int main() {
    int a = 1, b = 3;
    int ans = 0;
    // if(a>b) {
    //     cout<<a<<endl;
    // }
    // else {
    //     cout<<b<<endl;
    // }
    // iss cheez ko hum ek line me bhi likh sakte hai jisse readabilitybadhegi code ki... using ternary operator!
    ans = (a>b) ? a : b; // ye ek line me aagya and isse readibilty badh gyi!
}
// but suppose now ab ye same cheez baar baar likhi ho agar! like...

#include<iostream>
using namespace std;

int main() {
    int a = 1, b = 3;
    int ans = 0;
    a = a + 2;
    b = b + 4;
    ans = (a>b) ? a : b;

    a = a + 10;
    b = b + 20;
    ans = (a>b) ? a : b;

    a = a + 20;
    b = b + 30;
    ans = (a>b) ? a : b;
    // Ab isse harr baar hume calculate krna pad rha hai, toh isse better hai isko ek functon me likhdo and function call maardo, but usme bhi function call me variable pass krne pr vo copy hojaate hai function defintion me jisse extra memory jayegi, toh usse bachne ke liye pass by refernce krdo!
}

#include<iostream>
using namespace std;

int getMax(int& a, int& b) {
    return (a>b) ? a : b;
}

int main() {
    int a = 1, b = 3;
    int ans = 0;
    a = a + 2;
    b = b + 4;
    cout<<getMax(a,b)<<endl;

    a = a + 10;
    b = b + 20;
    cout<<getMax(a,b)<<endl;

    a = a + 20;
    b = b + 30;
    cout<<getMax(a,b)<<endl;
}
// So abhi tak humne almost saari problems solve krdi bss ek bachi hai and that is of function call krna pad rha hai baar baar jisse processing pr zor pad rha hoga (bhale hi zyada nhi, but still we are talking about optimization!)
// So for that we will use Inline keyword, ab ye kya krta hai ki jiss tarah define keyword compile hone se pehle sab jagah se values ko macro ke according replace krdeta hai vhi similar cheez inline keyword krta hai functions ke liye! but remember ye one line functions ke liye easily krdeta hai! 2-3 lines functions ke liye ye cheez work krna depends on compiler and usse zyada lines ke functions ke liye this keyword doesnot work!

#include<iostream>
using namespace std;

inline int getMax(int& a, int& b) {
    return (a>b) ? a : b;
}

int main() {
    int a = 1, b = 3;
    int ans = 0;
    a = a + 2;
    b = b + 4;
    cout<<getMax(a,b)<<endl;

    a = a + 10;
    b = b + 20;
    cout<<getMax(a,b)<<endl;

    a = a + 20;
    b = b + 30;
    cout<<getMax(a,b)<<endl;
}
// Isme sab jagah se getMax ki jagah jo function definition hai vo aajayega just before compiling... isse humari code readability bhi affect nhi hui, baar baar function call krne vaali prblms bhi solve hogyi, and jo extra space ban rha tha vo bhi ref variable ki help se solve hogya!
// Overall this code is optimized!

// Default Argumnents!
#include<iostream>
using namespace std;

void printArr(int arr[], int size, int start = 0) { // Start is the default argument!
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    printArr(arr, size, 2); // Iss case me array 2 index se print hojayega end tak!
    // Ab now what we want is maanlo kabhi humne agar start parameter dene ka mann nhi kiya, toh hum chahte hai by default jo printArr function hai vo array ko starting se print krde by default! so for that hum function ke defintion me int start = 0; likh denge jisse ye start ek default argument bangya! means agar koi parameter pass nhi krenge start ke liye toh automatically the start ko 0 value assign hojayegi!
    printArr(arr, size); // Iss case me array start to end poora print hojayega!
    printArr(arr, size, 3); // Iss case me array 3 index se print hojayega end tak!
}
// but remember default arguments sirf right to left hi bante hai, mtlb pehle sabse right vaala argument banega uske baad hi koi left vaala argument default ban sakta hai, mtlb ki agar aisa hota, printArr(int arr[], int size, int start, int end), toh pehle end ko default banaate then start ko and so on...agar size ko default banana hai toh pehle start and end ko default hona zaruri hai!

// Const Keyword : it is used to initiallize constant variables and they are variables whose values cannot be changed once they are initialized, and they are declared using the const keyword. Keywords, on the other hand, are reserved words in C++ that have special meanings and play a vital role in defining the syntax and structure of the language.
