// ---------------------------------------------------------- LECTURE 25 - Pointers in C++ Part-1 --------------------------------------------------------------------------------------------------------->
// Basic logic of pointers you already know very well, if confused maybe see the vdos again or refer the C notes!
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr = &a; // yahaa humne a variable ka address store kiya jisme 5 rakhaa hua hai
    cout<<*ptr<<endl; // Yahaa humne * ko use kiya dereference krne ke liye, and upar kiya tha reference krne ke liye (pointer declare krne ke liye)
    // Never write like this int *ptr; kyunki isme humne iss pointer ko kahin point nhi kiya, ab ye memory ke kisi bhi jagah point kr rha ho sakta hai, agar kahin reference nhi krna hai toh usko 0 se initialize krdo and make it a NULL pointer! but dont leave it like this! Its a very bad practice!
}

// Jiss type ka memory space refer krana hai uss type ka hi pointer bhi banega! agar aise kisi variable ko point kraa rhe ho jo ek char type ka hai toh pointer bhi char type ka banega!
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr = &a;
    cout<<"Size of integer : "<<sizeof(a)<<endl; // Here it will be 4 bytes, as usual!
    cout<<"Size of pointer : "<<sizeof(ptr)<<endl; // Here it will give 8 becoz chaahe kisi bhi data type ka pointer ho store toh vo address hi krega and address will be a hexadecimal number due to which it will always be of 8 bytes! but the problem is ki yahaa pr jo compiler I'm using is of 32 bits and that is why it will still show 4 bytes! and that is why the output will be 4 bytes!

    int *ptr2 = 0;
    // int *ptr2 = NULL;
    cout<<*ptr2<<endl; // It will give output as "Segmentation Fault" kyunki yahaa pr hum ek NULL pointer ki value nikalne ka try kr rhe hai! or maybe not always sometimes it shows a very undefined behaviour or the program may crash! also maybe it can show no visible effect or any other unexpected behaviour! but it is not neccessary that it will always lead to segmentation fault!
}
// This is it for this lecture, most of the topics and logic are already covered in C lectures notes or you may again visit the lecture here!


// ---------------------------------------------------------- LECTURE 26 - Pointers in C++ Part-2 --------------------------------------------------------------------------------------------------------->
// Suppose we have created an array int arr[10]; and now in memory there will be 10 int size memory blocks will form and the array name here it is arr will be pointing towards the first memory block of the array!
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Address of first memory block is : "<<arr<<endl;
}

// using & operator : agar hum chahte hai & operator ka use krke first location ka address nikalna hai then we can do this... &arr[0] it will mean address of first location of the array arr.
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    cout<<"Address of first memory block is : "<<arr<<endl;
    cout<<"Address of first memory block is : "<<&arr[0]<<endl;

    int *ptr = &arr[0];
    cout<<"Address of first memory block is : "<<ptr<<endl;
    cout<<"Value at first index of the array : "<<*arr<<endl; // It will print the value at the first index of the array arr!
    cout<<*arr + 1<<endl; // It will add 1 to the value in *arr, hence it will print 11 here!
    cout<<*(arr+1)<<endl; // it will print the value at second index of the array!
} // So this is another way of finding the address of firs location of array arr... thru three methods!

// How actually compiler evaluate arr[i] : So, arr[i] = *(arr + i), and that is how it is actually evaluated!
// even we can write the above arr[i] = *(arr + i) or i[arr] = *(i + arr)!
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {10,20,30};
    cout<<arr[2]<<endl;
    cout<<*(arr + 2)<<endl;
    cout<<2[arr]<<endl;
    cout<<*(arr + 2)<<endl;
    // All the above will give the same answer!
}

#include<iostream>
using namespace std;

int main() {
    int temp[10] = {1,2,3,4};
    cout<<sizeof(temp)<<endl; // Isme bhale hi temp first location ka address batat ho but here hum size nikal rhe hai naa ki address toh it will print 40 as 40 is the entire size of the array!
    cout<<(*temp)<<endl; // It will print the value which is present at the first location of the array temp!
    cout<<(&temp)<<endl;
    cout<<sizeof(*temp)<<endl;
    cout<<sizeof(&temp)<<endl;
    cout<<&temp[0]<<endl; // it will print the address of the first location of the array!
}

#include<iostream>
using namespace std;

int main() {
    int a[10] = {1,2,3,4,5};
    cout<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;
    // All the above will print the exact same output!

    int *p = &a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl; // It will print the address of the block which is storing the address of the first location of the array!
}
// Note : Content of symbol table cannot be changed!
// Symbol table : Jaise jo humne array banai thi uske first location ka address uske naam se represent hota hai and vo naam kisi ek memory address se map hoga and hum uss address ko change nhi kr sakte hai! this is what we mean by saying symbol table content cannot be changed!
// Means we cannot do arr = arr+1;
#include<iostream>
using namespace std;

int main() {
    int arr[10];
    // arr = arr + 1; // This will show error as it cannot be done!
    cout<<arr<<endl;
}


// Character Arrays!
#include<iostream>
using namespace std;

int main() {
    int arr[5] =  {1,2,3,4,5};
    char ch[6] = "abcde"; // Here hume iska size 6 krna hoga, kyunki character arrays me ek last me null character hota hai and uske liye bhi space chahiye hoti hai! so that is why we have made it 5!
    cout<<arr<<endl; // Isme toh as we know ki address of the first location of the array print hojayega!
    cout<<ch<<endl; // Isme hum expect krenge ki first location of the char array ka address print ho pr vo nhi hoga, balki vo char array as it is print hojayega!

    // Even if agar hum ye tareeka soche address of the first location of the char array print krne ka tab bhi kuch nhi hoga! kyunki C++ me cout ki implementation hi different hai!
    char *c = &ch[0];
    cout<<c<<endl; // Iss case me bhi ye poora string hi print krdega, kyunki c++ me cout ka implementation hi different way se hai! yahaa pr jab bhi cout ko null character dikh jayega tab hi ye print krna band krdega!
    // Lets see kya hota hai agar isko null character nhi milta toh!
    char temp = 'a';
    char *p = &temp;
    cout<<p<<endl; // Iss case me ye iss time abcde print kr rha hai jisme se "bcde" are some randome garbage values! aur aisa isliye hua kyunki isko a ke baad null character seedha bcde ke baad mila!
}

// Now lets see the difference between, char ch[6] = "abcde"; and char *c = "abcde";
// In the first case kya hoga ki pehle ek temporary memory banegi usme abcde jaake store hoga with null character in the end! and then ek ch naam se memory create hogi and vahaa pr ye temp vaali memory copy hojayegi!
// And in the second case ye ho rha hai ki ek temporary memory ban rhi hai and then uc naam se jo pointer hai vo uss temporary memory ke first element ko point kr de rha hai (mtlb uska address store krde rha hai)! but this process is very risky!

// Functions using Pointers!
#include<iostream>
using namespace std;

void print(int *p) {
    cout<<p<<endl;
}

void update(int *p) {
    p = p+1;
}

int main() {
    int value = 5;
    int *p = &value;
    print(p);

    cout<<"Before : "<<p<<endl;
    update(p);
    cout<<"After : "<<p<<endl; // Here we can see even after using the update function we are not able to update the value of the p!
}
// So what happened is ki isme pass by value hoti hai! mtlb jo function me pass krte hai value hum int main ke andar uss value ki ek copy jaati hai function defintion ke andar and then vo value sirf uss scope ke andar me update hoti hai! toh agar hum uss scope ke andar me print karayenge value tab value update hojayegi!
// Pr agar hum iss hi function me *p ko update krne ki koshish kre tab easily hojayegi!
#include<iostream>
using namespace std;

void update(int *p) {
    *p = *p+1;
}

int main() {
    int value = 5;
    int *p = &value;
    // print(p);

    cout<<"Before : "<<*p<<endl;
    update(p);
    cout<<"After : "<<*p<<endl;
}
// Is case me value update hogyi! aisa isliye kyunki jab pehle humne *p print kiya toh jo uss time value thi *p vo print hogyi! but iss baar jab humne update function call maara tab seedha jaake pe jo address stored hai uspe jo value hai vhi change hogyi! and in this case vo value hi from the root update hogyi and that is why After me updated value print hui!

// Pointers with arrays and functions!
#include<iostream>
using namespace std;

int getSum(int arr[], int n) { // Isme hum int arr[] ko  "int *arr" bhi likh sakte hai!  baat ek hi hai!
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    cout<<"Sum is : "<<getSum(arr,5)<<endl; // Isme hum poori array nhi paas kr rhe hai balki array ka sirf first location ka address pass kr rhe hai!
} // Lets understand the code in more depth! jab hum int *p naam se ek pointer create krte hai tab ek pointer create hota hai jo array ke first element pr point kr rha hota hai! and then uske baad se poora array continue ho rha hota hai!
// Jab humne arr pass kiya function call me tab vo array ki first location ko represent kr rha tha but like agar hum chahte hai ki array ki kuch ek particular location se hi element pass kre toh hum aise likh sakte hai...getSum(arr+3, 5) isse kya hoga ki array ki 3rd location se saare elements pass hojayenge array function me! and them hum apne hisaab se specific set of index ki values ka sum nikal sakte hai!
// lets try this....

#include<iostream>
using namespace std;

int getSum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    cout<<"Sum is : "<<getSum(arr+2,3)<<endl; // Is case me humne jo array ki index badhane ke baad jo nayi size aayi hai vo bhi likhna hota hai!
} // So we are done here riight now!


// ---------------------------------------------------------- LECTURE 27 - Double Pointers in C++ --------------------------------------------------------------------------------------------------------->
// lets see why we did'nt use the pointer keywords in C++ and why use * along with the type of pointer we want to create!
// Reason is ki agar hum data types ko use krke define krenge pointer toh isse 2 cheez pehle se hi confirm hojayegi ki jo pointer hai vo kis type ka data type store krne vaala hai! and another is ki kitne bytes ke memory location ko vo pointer point krne vaala hai!

// And double pointers are nothing but just that they points towards another pointers! and similarly triple pointers are just another pointers which are pointing towards the double pointer and this things goes on....
#include<iostream>
using namespace std;

int main() {
    int i = 5;
    int* p1 = &i;
    int** p2 = &p1;

    cout<<"Value in i : "<<i<<endl;
    cout<<"Address of i : "<<&i<<endl; // this will print the address of i
    cout<<"Value in p1 : "<<p1<<endl; // this will print the address of i
    cout<<"Address of p1 : "<<&p1<<endl; // this will print the address of p1
    cout<<"Value at address store in p1 : "<<*p1<<endl; // this will print the value at that memory block whose address is stored in the pointer p1, in this case it is i's address stored in p1 so it will print the value which is stored in i which is 5!
    cout<<"Value in p2 : "<<p2<<endl; // this will print the address of p1 as it is the double pointer which is pointing towards another pointer p1
    cout<<"Address of p2 : "<<&p2<<endl; // this will print the address of p2
    cout<<"Value at address stored in p2 : "<<*p2<<endl; // this will print the value of that memory address whose address is stored in the pointer p2, in this case it is p1's address stored in p2 so it will print the value which is stored in p1 which is the address of i!

    cout<<"Value in i : "<<**p2<<endl; // Printing the value of i directly from p2!
}

#include<iostream>
using namespace std;

void update(int **p) {
    // p = p+1;
    // Will it change anything? Nothing changed! reason we already discussed above! kyunki overall isme pass by value hota hai toh values copy krke aati hai function me!

    // *p = *p + 1;
    // Will it change anything? yes!

    **p = **p + 1;
    // Will it change anything? yess!
}

int main() {
    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    cout<<"Before : "<<i<<endl;
    cout<<"Before : "<<p1<<endl;
    cout<<"Before : "<<p2<<endl;
    update(p2);
    cout<<"After : "<<i<<endl;
    cout<<"After : "<<p1<<endl;
    cout<<"After : "<<p2<<endl;
}
// Lets understand what we just did above! so pehle humne 3 memory blocks banai jisme se ek normal variable hai aur do pointers hai ek single pointer and double pointer!
// Now we created a function jisme hum double pointers ki value function call ke thru pass kr sakte hai! and humne uss function ke andar 3 alag alag increament operations likhe hue hai jinko hum ek ek krke check krenge ki kis operation se koi fark padta hai ya nhi!
// Now first lets create 3 blocks... i = 5 and address is 510, p1 = 510 and address is 610, p2 = 610 and address is 710!
// Now in the first case... hum is function me sirf double pointer hi pass kr sakte hai kyunki humne iski defintion hi aise likhi hai! so humne int main ke function call me p2 ko pass krdiya and now update function me ek alag se p2 memory block ban jayega jisme store toh 610 hi hoga but iss p2 block ka address kuch aur hoga kyunki ye toh int main vaale p2 ki ek copy hai! and now humne try kiya p = p+1 mtlb ki p2 me jo value hai usko increment krne ki, so p2 ki value increment hoke 610 se 614 hojayegi (kyunki integer ke size ke hisaab se addition hota hai), but ye increment sirf update function ke andar me hi hua hai iska int main se koi link nhi isliye update krne ke baad bhi after vaale couts ki value me koi change nhi ayega!
// Now in the 2nd case... this time we will check whether *p = *p + 1 works or not, so int main ke p2 ki ek copy pehle toh ban gyi update function me jiska address kuch aur hoga, so update function has p2 = 610 and address some other lets suppose 810, so now this time operation is *p = *p+1, so it means p2 block me jo value padi hai uss address pr jo value hai usko increment krdo by 1, so p2 me toh address p1 ka padaa hua hai, and vahaa pr jo value hai vo toh i ka address hai toh iss function ke according p1 me jo value hai uska increment hona hai! toh vo jayega means 510+1 which will be 514, and iss time kya alag hua ki iss update function ne iss baar int main ke p1 ki values me changes krdiye so this time the changes will reflect int not only in update function but also in int main! and hence in this case i ki value same rahegi, p1 ki change hojayegi and p2 ki same rahegi!
// Now in the 3rd case... this time we will check whether **p = **p + 1 works or not, so int main ke p2 ki again ek copy banegi and all, let this copy be as p2 = 610 and its address is 810, now the operation suggests **p = **p + 1, so now p2 me jo address stored hai uss address pr jo address stored hai uski values me changes krne hai, mtlb simply i ki value me changes krne hai! so yahaa again update function apne scope ke bahar ke ek variable me changes kr rha hai toh ye changes iske scope ke bahar bhi reflect honge! and i ki value +1 hojayegi! and this time p1 and p1 same rahenge bss i change hojayega!

// Practice Question on Pointers!
#include<iostream>
using namespace std;

int main() {
    // int first = 6;
    // int *p = &first;
    // int *q = p; // aise pointers copy krte hai! p and q are pointing at the same memory location!
    // (*q)++;
    // cout<<first<<endl;

    // int *p = 0;
    // int first = 110;
    // *p = first; // this is wrong, it will generate segmentation fault hence the correct syntax to do this will be p = &first, agar null pointer ko baad me update krke kisi aur jagah point karana hai toh vo aise krte hai! p = &first.. yahaa p ek NULL pointer tha!
    // cout<<*p<<endl;

    // int arr[5] = {11,12,13,14,15};
    // cout<<*(arr)<<" "<<*(arr+1)<<endl; // Will print 11 and then 12

    // int arr[5] = {11,12,13,14,15};
    // cout<<arr<<" "<<&(arr)<<endl; // Same address do baar print hojayega!

    // int arr[5] = {11,12,13,14,15};
    // int *ptr = arr++; // Here it will throw error kyunki here we are trying to update the symbol table!
    // cout<<*ptr<<endl;

    // char arr[] = "abcde"; // C/C++ me string ke case me compiler khud hi char array ka size samajh leta hai null character ki help se! aur yahaa humne double quotes use kiya hai jo strings ki notation hoti hai toh automatocally ek null character last me lag jaata hai jahaa se size calculate hojaata hai!
    // char* p = &arr[0];
    // cout<<p<<endl; // Here we know char arrays ke case me cout behaves differently so yahaa poori string print hojayegi!

    // char arr[] = "abcde";
    // char* p = &arr[0];
    // p++;
    // cout<<p<<endl; // Isme bcde print hojayega kyunki first index se humne increment krdiya hai!
}
