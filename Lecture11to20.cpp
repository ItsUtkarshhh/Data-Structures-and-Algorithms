// ---------------------------------------------------------- LECTURE 11 - Time & Space Complexity --------------------------------------------------------------------------------------------------------->
// Time Complexity : It is the amount of time taken by an algo to run, as a function of length of the input!
// So means overall hum time complexity ke aadhaar pr ye btaa sakte hai ki koi algo/program acha hai ya bekar, and ye time kitna lega!
// Why Time Complexity : Becoz it helps in making better programs and helps in comparison of different algorithms!

// Now jiss tarah se hum length ko metre me naapte hai volume ko m^3 me, vaise hi time complexity ko 3 ways se naapa jaata hai, and they are : BigO Notation, Theta Notation and Omega Notations!
// And here BigO represents Upper Bound : Means koi algorithm max to max kitna time lega, that is represented as BigO
// And then we have Theta which is Average case : Mtlb ki koi algo on an average kitna time lega, that is represented as Theta
// And then lastly, Omega, which is Lower Bound : Ki koi algorithm kam se kam kitna time lega, this is represented as Omega

// Now constant time is represented using O(1) : jab hum loop, normally 0 - 10 (or kisi constant value tak chalaate hai) that is called constant time complexity and is denoted as O(1).
// Now there is linear time complexity using O(n) : Jab hum upar vaale case me hi 0 - n (kisi variable jo user ke input pr dependent hoga), uske basis pr chalaa dete hai then that is called linear time complexity and is denoted as O(n).
// Now there is a logarithmic time complexity O(logn) : It happens in case binary search, we will study it further.
// Now there is a O(n^2) : Jab do loop ek ke andar ek 0 - n chal jaye, then that is O(n^2).
// Now there is a O(n^3) : Jab teen loop ek ke andar ek 0 - n chal jaye, then that is O(n^3).

// Graphs of BigO notations : refer the notes of DSA in the notebook!
// But one thing I will add on into this notes, that is order of Time Complexities : O(n!) > O(2^n) > O(n^3) > O(n^2) > O(nlogn) > O(n) > O(logn) > O(1)

// Jab hum ye bolte hai ki ek loop 0-n tak chal rha hai toh iski time complexity O(n) hogi, ye tab hi hoga jab loop ke andar jo operations perform ho rhe hai unki time complexity is O(1) which is constant, tab hi O(n) bolenge! otherwise loop ke andar jo bhi operations hai unn sabki milaa ke jo time complexity ban rhi hai vo final hogi!
// Now lets see how to Solve TLE : So to solve this, we use 10^8 operation rule, which means, ki aaj kal ki modern machines 10^8 operations perform kr sakti hai ek second me! so hume humara length of input dekh ke uske according aisi algo use krni hai jiski time complexity sabse kam ho!, like agar question me diya hua hai ki time limit : 1 sec, means we are asked to perform 10^8 operations in 1 sec! so in that case we will use a table which is drawn in the notebook, kindly refer that!
// So now if the time limit is given 1 sec, means we are asked to perform 10^8 operations in 1 sec! so according to table we will be using O(n) or O(logn) vaale time complexity vaale algorithms! kyunki agar isse zyada jayenge then time limit exceed hojayega, kyunki if you calculate... O(n) me n is length of input and if n = 10^8 then koi dikkat nhi hai ye araam se ek sec me execute hojayenge! and even with O(logn) me bhi kyunki log ki property ke chalte ye O(8) ban jayega! so yess you got the point, similarly for other cases!
// Agar length of input 10^6 hai toh hum table ke according O(nlogn) use krenge kyunki again mathematically it will perform 10^6 * 6 operations and which is again possible with in 1 second!
// Then if length of input gets even less, like 400, then in that case, hum thori high time complexity bhi use kr sakte hai! like O(n^3) kyunki 400^3 wont be again exceed the 10^8 operations limit, so it can also be executed within 1 second!
// similarly, agar length of input aur kam hogyi, like 10, then in that case toh hum very high time complexity bhi use kr sakte hai! like O(n!) and O(n^6) kyunki isme bhi agar mathematically calculate kre tab bhi 10! will be 36,28,800 operations, which is again less than 10^8 operations limit, means ye bhi 1 sec ke under me execute ho sakta hai, even 10^6 it is still less that 10^8, so yes ye bhi 1 sec ke under me execute ho sakta hai!
// So yess this is how we avoid TLE!

// Sometimes we are given constraints like, 1 < n <= 10^8, is case me hume aisi time complexities use krni hai jo TLE na occur karaye, toh yes according ot table those are O(n) and O(logn)
// Also, if the values constraints are given like, 1 < arr[i] <= 10^9, then here we can use int as the data type, but suppose if the power gets upto 12 or 13 or above, then we have to use long or long long, becoz int ki range sirf -2^31-1 to 2^31-1 hi ho sakti hai! for signed and for unsigned, 0-2^32 tak ho sakti hai!
// So yess constraints ko dekh ke we decide the algorithm we should choose and data type we should use!
// Find the time complexity of the below code, most people will think that it will be O(n) but no! it will be O(1) kyunki bhyi ye loop poora n tak chlaa hi kahaa, ye toh bss 1 pe hi ruk gya becoz of break statement! so yess be mindfull while finding time complexities!
// for(int i = 0; i<n; i++) {
//     if(i==0) {
//         break;
//     }
// }

// Sometimes even on applying the 10^8 rule, it still showing TLE, then you may go for some other techniques to reduce the time, and they are like, you can use printf and scanf functions in C++ as they are more optimized than cin and cout!
// Sometimes what happens is ki hum koi ek aisi value jo baar baar use ho rhi hai usko hum kahin store krlete hai taaki usko baar baar calculate na krne pade and number of operations thore kam hojaye! and isse time bhi thora kam lagega! and this is called space time trade off, ki like thora time bachane ke liye thora space hum zyada use krlete hai! so yess this is another way of avoiding TLE!
// But sometimes even doing all of this still you get the TLE, then in that case you need to change your approach of solving the problem! you need to think some more optimized solution!

// Now...
// Space Complexity : Amount of space/memory required by your program or algorithm as the function of length of the input!
// Variable create krne se space complexity nhi badhti hai, we can create as many variables we want, it wont affect the space complexity! and it will be O(1) means constant space complexity
// Now, agar...maanlo humne vector create krdiya and uske size humne krdiya variable, then space complexity will not be constant and it will be O(n)
// int size;
// cin>>size;
// vector<int> arr1(size); It will have a space complexity of O(n).
// similarly maanlo maine ek for loop me ek vector create krdiya with variable size and then uske baad uss hi for loop ke andar ek aur for loop shuru krdiya, then kya hogi space complexity! it will still be O(n), kyunki for loop space thori khaata hai vo toh time khaata hai!

// ---------------------------------------------------------- LECTURE 12 - Binary Search --------------------------------------------------------------------------------------------------------->
// So till now we have studied Linear Search, where we use to iterate at every index of the array and find our key value, and isme worst case me time complexity O(n) hoti jab hum n comparisons krte hai for that key value. So this we have studied!
// Now lets dive into Binary Search!
// Firstly binary search is applicable over only Monotonic Function, means only those functions which are entirely increasing or entirely decreasing! means binary search sirf sorted finctions pr hi lgti hai! ab vo functions array ho ya vector ya kuch aur!
// Now how to do Binary Search :
// Suppose we have an array of 5 size (sorted in ascending order), now what we will do is, we will find the mid element, and then we will match that mid value with our key element, if it matches the key element then we will return the index! otherwise agar key > mid se, then we will go on the right side of the array,
// otherwise on the left, and then we will again find the mid element and then again will compare with the mid, then again if key matches with the element of the array then we will return the index, otherwise we will again see is key > element, if yes or no, according to it we will proceed! and if the key is not found in the array, then we will return -1.
// Now suppose an array = [1,2,3,4,5] (odd no. of elements) and key we want to find is 5
// On applying binary search, we will see that, mid = (start + end)/2, so it will come mid = (0+4)/2 = 2, so now mid = 2. now we will compare the mid with key and here key(5) > mid(2) so we will go on the right side! so now we will update our start (while going on right, kyunki end toh pehle se hi end pr hai, pr start pehle 0 pr tha pr ab usko mid se aage laana hoga toh we will update start), so we will do start = mid + 1, and now again we will find a new mid of the new half array and again will do the same operations until we find our key element!
// Also, here doing mid = (start+end)/2, is not a very optimized way to do it! kyunki agar maanlo start index ki jo value hai that is 2^31-1 and end ki bhi jo value hai that is also 2^31-1 and on adding them it will exceed the int range! so we will apply some maths here, like we will write mid = (start + ((end-start)/2)) taaki values range ke andar hi rahe! but although pehle vaale formule me bhi values half hojayegi even tho agar start and end dono 2^31-1 rahe toh maybe fark nhi padna chahiye, but okay maybe becoz kuch test cases pass naa ho isliye love babbar told to do this! So okay lets do this optimization!
// Here's the explaination of why we use the start + (end-start)/2 formulae for mid and not the (start + end)/2, it is to deal with the overflow of value of start and end indexes! ki kahin ye int ke range se bahar na chale jaye! aisa kaise hoga? toh aisa tab ho sakta hai jab maanlo humara array bhott larage hai! ki like iska jo end ka index hai vo int ki max value ke aas paas hai! and now chalo humara start initially toh 0 pr rahega! but jaise jaise hum binary search krenge and maanlo agar humara start update ho ho ke uski value badhti hi jaa rhi hai! (kyunki key element bhot right side me hai toh hume start ko right side me aur shift krte jaana hoga and right side me shift krne ka mtlb ki start ki value ko badhate rehna!)
// toh agar koi aisa time aagya jab start ki value bhi bhot badi hogyi hai! uss condition me agar hum (start+end)/2 use krenge toh mid out of int range chalaa jayega! and it will cause overflow! so to prevent this we use the optimized approach! ab aisa toh nhi krenge ki chhoti array size ke liye purana formula use kro and badi arrays ke liye optimized vaala! hume cheeze dynamically sochni chahiye kyunki situations can change anytime! like in case of vectors! usme kisi ne agar size ek baar bhot kam daaldi and ek baar bhot zyada! toh ab baar baar change thori krenge mid ke calculation ko! So that is why! 
// Now lets Implement Binary Search :
#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2; // More optimized way to use here is, mid = (start + ((end-start)/2)), but okay keep this thing in mind during interviews and coding compettions and online coding! to pass all the test cases!
    while(start<=end) {
        if(key==arr[mid]) {
            return mid;
        }

        if(key>arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

int main() {
    int oddArr[5] = {1,2,3,4,5};
    int evenArr[6] = {6,7,8,9,10,11};

    int oddIndex = BinarySearch(oddArr, 5, 5);
    cout<<"Index of 5 is "<<oddIndex<<endl;
    int evenIndex = BinarySearch(evenArr, 6, 15);
    cout<<"Index of 15 is "<<evenIndex<<endl;
} // here we have statically made an array, and then found the element, we can also go for getting the array as input from the user, but okay usme sirf ek array hi input karwaana hai baaki sab toh same hi hoga!

// Now lets talk about its complexity!
// Look we know that Linear Search ke case me agar 1000 elements hai toh worst case me 1000 comparisons krne pad sakte hai! and its time complexity becomes O(n)!
// but in Binary Search, agar 1000 elements ka array ho bhi, now lets calculate kitne padenge, we know that harr iteration me size of the array half ho jaa rha hai so, if size is 1000 then, 1000 -> 500 -> 250 -> 125 -> 62 -> 31 -> 15 -> 7 -> 3 -> 1 -> 0, So means in BS we need to do only 10 comparisons as compared to LS where we need to do 1000 comparisons! So this is the benefit of BS!
// Now Time Complexity is O(logn), now ye kaise aayi, that is, Pehle n size tha array ka, then n/2 hua, then n/4 hua, then n/8 hua, then n/16 hua, then krte krte kam hote gya, so we can say is n/(2^k) rate se size kam ho rha hai! mtlb ki n/(2^k) comparisons hone ke baad iterations khatam hogyi mtlb ki iski length hogi 1, kyunki last me toh ek hi index bachega! so n/(2^k) = 1, and from here we will get k = logn, where is k is no. of comparisons done! So that is how we got TC = logn.

// ---------------------------------------------------------- LECTURE 13 & 14 - Binary Search Interview Questions! --------------------------------------------------------------------------------------------------------->
// Codestudio Question 1 : Find the first and last position of an element in a sorted array!
// Approach : First we will find the first occurence, where what we will do is, hum pehle toh mid nikalenge, then hum uss mid ko apne key value se compare krenge! then hum peeche jayenge end ko update krke mid - 1 se! then hum peeche jaake compare krenge mid ko firse peeche vaale elements se! and then we will repeat the same thing until we find our element!
// Now we will find the last occurence, where what we will do is, hum pehle toh mid nikalenge, then hum uss mid ko apne key value se compare krenge! then hum aage jayenge start ko update krke mid + 1 se! then hum aage jaake compare krenge mid ko firse aage vaale elements se! and then we will repeat the same thing until we find our element!
#include<iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key) {
    int s = 0;
    int e = size-1;
    int mid = (s + ((e-s)/2));
    int ans = -1;
    while (s<=e){
        if(arr[mid]==key) {
            ans = mid;
            e = mid - 1;
        }
        else if(key>arr[mid]) {
            s = mid+1;
        }
        else if(key<arr[mid]) {
            e = mid-1;
        }
        mid = (s + ((e-s)/2));
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key) {
    int s = 0;
    int e = size-1;
    int mid = (s + ((e-s)/2));
    int ans = -1;
    while (s<=e){
        if(arr[mid]==key) {
            ans = mid;
            s = mid + 1;
        }
        else if(key>arr[mid]) {
            s = mid+1;
        }
        else if(key<arr[mid]) {
            e = mid-1;
        }
        mid = (s + ((e-s)/2));
    }
    return ans;
}

int main() {
    int arr1[5] = {1,2,3,3,5};
    cout<<"The first occurence of 3 is at index "<<firstOccurence(arr1, 5, 3)<<endl;
    cout<<"The last occurence of 3 is at index "<<lastOccurence(arr1, 5, 3)<<endl;
}

// Another variation of the above question is find the total number of occurence! We will write the same code just with an add on to it and that is that (last occurence ka index - first occurence ka index) + 1.
#include<iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key) {
    int s = 0;
    int e = size-1;
    int mid = (s + ((e-s)/2));
    int ans = -1;
    while (s<=e){
        if(arr[mid]==key) {
            ans = mid;
            e = mid - 1;
        }
        else if(key>arr[mid]) {
            s = mid+1;
        }
        else if(key<arr[mid]) {
            e = mid-1;
        }
        mid = (s + ((e-s)/2));
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key) {
    int s = 0;
    int e = size-1;
    int mid = (s + ((e-s)/2));
    int ans = -1;
    while (s<=e){
        if(arr[mid]==key) {
            ans = mid;
            s = mid + 1;
        }
        else if(key>arr[mid]) {
            s = mid+1;
        }
        else if(key<arr[mid]) {
            e = mid-1;
        }
        mid = (s + ((e-s)/2));
    }
    return ans;
}

int main() {
    int arr1[5] = {1,2,3,3,5};
    cout<<"The first occurence of 3 is at index "<<firstOccurence(arr1, 5, 3)<<endl;
    cout<<"The last occurence of 3 is at index "<<lastOccurence(arr1, 5, 3)<<endl;

    // Total number of occurences of 3
    cout<<"Total number of occurence of 3 : "<<(lastOccurence(arr1, 5, 3)-firstOccurence(arr1, 5, 3))+1<<endl;
}

// Leetcode Question 1 : Find peak in a mountain array! here mountain array means like the array will be like {1,2,3,4,3,2,1} here the peak is 4. so similarly you have to find it!
// My Solution : Approach is that ki compare krte gye harr step me, as you can see in the code!
#include<iostream>
using namespace std;

int peakElement(int arr[], int size) {
    int s = 0;
    int e = size-1;
    int mid = s + ((e-s)/2);
    while(s<=e) {
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) {
            return mid; // agar peak element ki value chahiye then just write return arr[mid].
        }
        else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]) {
            s = mid + 1;
        }
        else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]) {
            e = mid - 1;
        }
        mid = s + ((e-s)/2);
    }
    return -1;
}

int main() {
    int arr1[7] = {1,2,3,4,3,2,1};
    int arr2[5] = {0,1,2,1,0};
    int arr3[5] = {0,1,2,3,4};
    int arr4[5] = {0,1,3,2,4};
    cout<<"The index of the peak element of the arr1 is : "<<peakElement(arr1, 7)<<endl;
    cout<<"The index of the peak element of the arr2 is : "<<peakElement(arr2, 5)<<endl;
    cout<<"The index of the peak element of the arr3 is : "<<peakElement(arr3, 5)<<endl;
    cout<<"The index of the peak element of the arr4 is : "<<peakElement(arr4, 5)<<endl;
} // This method does not include the conditions or test cases where, edge elements might be the peak element! also this method assumes that mid+1 and mid-1 always exists! also if the size of the array = 1, then also it wont print the peak value! kyunki usme toh na mid-1 and na mid+1 exist krta hai!
// To resolve this issue! we will procees with this... pehle toh, if(size==1) return 0; kyunki agar size = 1 hogya toh simply peak element 0th index pr hi hoga!
// And if iske alawa... lets see in code...
#include<iostream>
using namespace std;

int peak(int arr[], int size) {
    if (size == 1) return 0; // Single element case
    int s = 0;
    int e = size - 1;
    while (s <= e) {
        int mid = s + ((e - s) / 2);

        // Check if mid is a peak element
        if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == size - 1 || arr[mid] > arr[mid + 1])) {
            return mid;
        }
        // If mid is not a peak and its left neighbor is greater, move left
        else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            e = mid - 1;
        }
        // If mid is not a peak and its right neighbor is greater, move right
        else {
            s = mid + 1;
        }
    }
    return -1; // This should never be reached if the array has at least one peak element
}

int main() {
    int arr1[7] = {1,2,3,4,3,2,1};
    int arr2[5] = {0,1,2,1,0};
    int arr3[5] = {0,1,2,3,4};
    int arr4[5] = {0,1,3,2,4};
    int arr5[1] = {4};
    cout<<"The index of the peak element of the arr1 is : "<<peak(arr1, 7)<<endl;
    cout<<"The index of the peak element of the arr2 is : "<<peak(arr2, 5)<<endl;
    cout<<"The index of the peak element of the arr3 is : "<<peak(arr3, 5)<<endl;
    cout<<"The index of the peak element of the arr4 is : "<<peak(arr4, 5)<<endl;
    cout<<"The index of the peak element of the arr5 is : "<<peak(arr5, 1)<<endl;
} // So this is how we optimize this method!
// But this optimized method is same as solution of Love babbar below!

// Love Babbar Solution :
#include<iostream>
using namespace std;

int peakElement(int arr[], int size) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid]<arr[mid+1]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    int arr1[7] = {1,2,3,4,3,2,1};
    int arr2[5] = {0,1,2,1,0};
    int arr3[5] = {0,1,2,3,4};
    int arr4[5] = {0,1,3,2,4};
    int arr5[1] = {4};
    cout<<"The index of the peak element of the arr1 is : "<<peakElement(arr1, 7)<<endl;
    cout<<"The index of the peak element of the arr2 is : "<<peakElement(arr2, 5)<<endl;
    cout<<"The index of the peak element of the arr3 is : "<<peakElement(arr3, 5)<<endl;
    cout<<"The index of the peak element of the arr4 is : "<<peakElement(arr4, 5)<<endl;
    cout<<"The index of the peak element of the arr5 is : "<<peakElement(arr5, 1)<<endl;
}

// Pivot Element : We will understand a pivot element in terms of Sorted and Rotated array! So Suppose we have sorted array (and yahaa pr sorted ka mtlb sirf ascending order me sort hona hota hai, and now we rotate it from one of its index, like example suppose you have a sorted array, [1,2,3,7,9] now we rotate it from index 3 and now the sorted and rotated array will be, [7,9,1,2,3].
// Now the pivot element is that element jahaa se ye array rotate hogya, like here that pivot element can be 1 or 9, kyunki kuch log bolenge ki ye 7 se rotate hua and kuch log bolenge ki ye 1 se rotate hua! but in our understanding, hum maan ke chalenge ki here the smallest element is the pivot element and here that is 1, now isko hum apne hisaab se largest element ke liye bhi nikal sakte hai!
// Now the question is ab ye kaise nikale? So now, what we will do is... and abhi hum pivot element binary search ke thru nikalenge so, binary search sirf monotonic behaviour and functions pr hi lgta hai and in this case [7,9,1,2,3] isme [7,9] is monotonic and [1,2,3] is monotonic in nature, so now, as we know that the sorted and rotated array is divided into two monotonic sub-arrays, so now we will find mid first and then iss mid pr hum kuch aisi condition lgayenge taaki hum pivot element tak pohoch paaye!
// Now see, suppose an array, [5,6,7,8,9,1,2] isme hume pivot element nikalna hai, now, the first condition which can help us finding the pivot element is, arr[mid] >= arr[0] isse kya hoga ki hum kis side of the array me hai, like agar hum arr[mid] >= arr[0] krte hai then we will see that, we will arrive in the first portion of the array which is [5,6,7,8,9] and then we will do s = mid+1 isse hume ye ptaa chal gya ki chalo humara pivot element yahaa toh nhi hai kyunki idhar ke left side vaale saare elements increasing order me hai left to right kyunki arr[mid] >= arr[0], now we did s = mid+1 now our new s is 9 and now we are left with [9,1,2] here s = 9, e = 2 and mid jo update hua hoga mid = s+(e-s)/2 ke formula se that will be 1, so now again we will check the conditions!
// arr[mid] >= arr[0], but here we will see that arr[0] = 5 which is not smaller that arr[mid] which is 1, so ye condition to false hogyi! now the we will check the next condition, which is a else condition which is (arr[mid] < arr[0]) and here, this condition is true, so we will update end = mid, yahaa end ko mid-1 isliye nhi kiya kyunki vrna ek mid element jo bhi pivot element ho sakta tha vo skip ho jaata! isliye we kept end = mid. and now hume kaise pta chalega ki yhi pivot element hai, vo aise ki hum s<e vaali condition lgaa denge taaki s = e na ho paye, and means poori array traverse ho chuki hai and sirf yhi ek element bacha hai which will be our pivot element!

// Now lets ek baar is array ke bhi respect me samajh lete hai, so array, [7,9,1,2,3] now, our first condition is arr[mid] >= arr[0] and here arr[mid] = 1 and arr[0] is 5 so this condtion gets false and now we will move to the next condition and that is arr[mid] < arr[0] this condition humari else statetment hogi, so now, 1 < 5 and it is true! so now we will update end = mid, and now end = 1, now agar loop ek baar aur chalta hai toh arr[mid] >= arr[0] is condition ke according (humara s = 7 and e = 1 and mid jo update hua hai that will be 9) 9 > 7 and it is true so s will get updated and it will be s = mid+1 and that will be s = 1 but e and s cannot be same so here our loop will break and we will get our pivot element!
// Now lets code it!
// My Solution :
#include<iostream>
using namespace std;

int findPivot(int arr[], int n) {
    int s = 0; int e = n-1;
    int mid = s +(e-s)/2;
    while(s<e) {
        if(arr[mid]>=arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s +(e-s)/2;
    }
    cout<<s;
}

int main() {
    int n;
    cin>>n;
    int arr1[500];
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    findPivot(arr1, n);
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int findPivot(int arr[], int n) {
    int s = 0; int e = n-1;
    int mid = s +(e-s)/2;
    while(s<e) {
        if(arr[mid]>=arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s +(e-s)/2;
    }
    return s;
}

int main() {
    int arr1[5] = {7,9,1,2,3};
    cout<<"The Pivot Index is "<<findPivot(arr1, 5);
} // Here we have found out the smallest pivot element! if we want to find the largest in that case we just need to return s-1, but along with this we need to specofy a condition that ki s agar 0 hua toh, in that case we will return the last element of the sorted array! kyunki agar s = 0 is where the smallest element is, then means largest element will be at last index! kyunki iska ye mtlb hua ki array rotated hi nhi hai!

// Leetcode Question 2 : Search in a rotated sorted array!
// Approach : What we will do is that, as we know abhi abhi humne padhaa pivot element ke baare me so hum usko use krenge! like we know pivot element kya uske ek taraf badi values hoti hai and ek taraf choti values hoti hai jo increase ho rhi hoti hai (kind of yhi hota hai na! its not exactly but yes you got my point!)
// Now what we will do is, that suppose we are given a key, now we dont know ki vo key kis side of the array se belong krti hai so for that we will pivot element! now what we will do is, our first condition will be, arr[pivot] < key < arr[end], kya vo key is portion me lie krta hai ya arr[start] < key < arr[pivot-1] vaale portion me lie krta hai! and jis bhi portion me lie krta hai uss portion me we will apply binary search!
// Now lets code!
#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = (start+end)/2;
    while(start<=end) {
        if(key==arr[mid]) {
            return mid;
        }

        if(key>arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

int pivotElement(int arr[], int n) {
    int s = 0; int e = n-1;
    int mid = s +(e-s)/2;
    while(s<e) {
        if(arr[mid]>=arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s +(e-s)/2;
    }
    return s;
}

int findPosition(int arr[], int n, int key) {
    int pivot = pivotElement(arr, n);
    int e = n-1;
    if(key>=arr[pivot] && key<=arr[e]) {
        return binarySearch(arr,pivot,n-1,key);
    }
    else {
        return binarySearch(arr, 0, pivot-1, key);
    }
}

int main() {
    int arr1[9] = {6,7,8,9,1,2,3,4,5};
    cout<<findPosition(arr1, 9, 10);
}

// Leetcode Question 3 : Finding Square root using Binary Search!
// Approach : Maanlo koi bhi number hai x, toh uska square root jo bhi hoga vo 0 to x ke beech me hi lie krega! so means humare paas jo search space hai jisme hume x ka square root search krna hai that from 0 to x and 0 to x me saare increasing order me hi numbers honge, means they will be monotonic hence, we can apply Binary search into this!
// Now ab vo kaise, jaise maanlo 36 koi number ha jiska hume square root nikalna hai and now what we will do is, as from the above line we can say that our search space will be from 0 to 36, means it can be anyy number between 0-36, so now, we will use Binary Search!
// Pehle mid nikalenge, mid = n/2 and in this case it will be 18, now we will calculate 18*18 and will check ki kya ye badaa hai and we know it is bigger than 36 so ab 18 se right me jaane ka toh koi fayeda nhi hai! kyunki unn sab numbers ke square bada hi hoga 36 se, so we wil go on left! and make end = mid-1, now, we got the search space of 0-17,
// now again we will find the mid and this time it will be 8 and now again we will see that 8*8 is > 36, means hume abhi aur left me jaana hoga, so again we will do end = mid-1, now we will be at 0-7, now we will again find mid and this time it will be 3 and now 3*3 is < 36 so now we will store this ans, kyunki chalo ye chhota toh hai usse, mtlb kya ptaa ek chance ban jaaye ki yhi ans ho,
// kyunki kya pta iske aage kuch decimals points ho answer ke liye (this we will get in the next part), but point is agar mid*mid < 36 hojaye then hum mid ho pehle toh save krlete hai and then start ko update krte hai start = mid+1 means, now we are at 4-7 now we will again find mid which will be 5 ((4+7)/2) and now we can see that again 5*5 is < 36 so again we will update our stored answer to 5 and then we will update the start value to mid+1 and this time it will be 6-7 and now mid will be 6 and here we will see 6*6 = 36 toh jahaa pr aake equal hojayega vo mid ki value hum print krdenge!
// So in short, if mid*mid > x -> Then end = mid-1
// then if mid*mid < x -> ans = mid, start = mid+1
// and lastly, if mid*mid == x -> then return mid.
// Lets code it!
#include<iostream>
using namespace std;

int binarySearch (int n) {
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {
        int square = mid*mid;
        if(square == n) {
            return mid;
        }
        if(square < n) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int mySqrt(int x) {
    return binarySearch(x);
}

int main() {
    int n;
    cin>>n;
    cout<<mySqrt(n);
}
// But the above code has one very interesting mistake and that is, whatif agar mid*mid int ki range se bahar chlaa gya toh? tab toh humara code sahi hone ke baad bhi error dedega! so hume int ka size badhaana hoga, and for that we will use long long data type!
#include<iostream>
using namespace std;

int binarySearch (int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;
    while(s<=e) {
        long long int square = mid*mid;
        if(square == n) {
            return mid;
        }
        if(square < n) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int mySqrt(int x) {
    return binarySearch(x);
}

int main() {
    int n;
    cin>>n;
    cout<<mySqrt(n);
} // Now this is the very optimized solution to the square root, kyunki we have did it in O(logn) complexity!

// Leetcode Question 3 : lets find the remaining decimal vaala part of the above question! means the floating part of the square root!
// Approach : Lets take an example number 37, So what we will do is that hume integer value of the square root to nikalni aati hai na, toh bss hum pehle vo nikal lenge and in this case that will be 6, and then usme pehle 0.1 add krdenge and then compare krenge ki kya ye 37 ke equal hai? like 6.1*6.1 = 37? if no and it is less than 37,
// then we will add another 0.1 into 6.1 and now it will be 6.2 and then 6.2*6.2 ab isko compare krenge! and aise krte jayenge jab tak iska square 37 ke upar nhi chlaa jaata, jab chlaa jaaye then hum isme 0.01 add krna shuru krenge (to get more accurate square root) and then will keep doint it until its square exceeds 37,
// and once it exceeds fir agar hume aur accurate value chahiye then hum isme 0.001 add krna shuru krenge! and then finally jab firse three decimal places tak ki value bhi 37 ko exceed krne lage then hum ruk jayenge (agar hume aur zyada accurate value nhi chahiye toh, but generally itna kaafi hota hai!) and then usse just pehle jo value thi jahaa square 37 se kam aa rha tha usko print krdenge!
// Lets code it...
#include<iostream>
using namespace std;

int sqrtInteger(int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;
    while(s<=e) {
        long long int square = mid*mid;
        if(square == n) {
            return mid;
        }
        if(square < n) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

double morePrecise(int n, int precision, int tempsol) {
    double factor = 1;
    double ans = tempsol;
    for(int i = 0; i<precision; i++) {
        factor = factor/10;
        for(double j = ans; j*j<n; j=j+factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int tempsol = sqrtInteger(n);
    cout<<morePrecise(n, 3, tempsol);
}

// ---------------------------------------------------------- LECTURE 15 - Binary Search Advanced Interview Questions! --------------------------------------------------------------------------------------------------------->
// Question 1 : Book Allocation Problem : Given an array 'arr' of integers, where 'arr[i]' represents the number of pages in the 'ith' book. There are m number of students, and the task is to allocate all the books to their students, allocate books in such a way that :
// each student get atleast one book! each book should be allocate to a student, book allocation should be in contigous manner! (mtlb jab tak pehle indexes ki books allocate na hojaye tab tak next index ki book ko allocate nhi kiya jayega!),
// you have to allocate the books to the 'm' students, "such that the maximum number of pages assigned to a student is minimum!"
// Example : Lets take an example, an array where, [10,20,30,40]; now here each index of the array representing number of pages in a book! and you have to distribute these book between 2 students, so now what we will do is, we will for dry run create partition, like...
// Suppose humne pehle vaala book ek student ko dediya and remaining vaala dusre student ko! Then the first student will be having 1 book of 10 pages and the another student will be having the rest of the three books with (20+30+40) 90 pages, so this was our first condition!
// Then another case is, where we can give first 2 books to first student and and the rest of the remaining to the another! then the first person will have 30 pages and the second student will be having 70 pages, now another case could be,
// When the first person can get first 3 books and the another person can get last one book, then the first person will have 60 pages and the second person will have 40 pages, now...
// We are told to allocate the books to the students, in such a manner that the max number of pages assigned to a student is minimum! iska mtlb ye ki...like from above example we got to know that there are many ways of assigning the books! but what we want is out of all the possibilities,
// hume vo way nikalna hai jisme maximum number of pages jo kisi ek student ko diye gye hai vo baaki saare ways me sabse kam hai! (In my opinion isko aise bhi keh sakte hai like jiss way me sabse kam difference ho number of pages me jo dono students ko allocate ki gyi hai, that will our answer!)

// So what we understand from the above para, that...
// In first case, 10 | 20 30 40, isme first student ko 1 book and remaining ko 3 books where, first book has 10 pages and rest of the three books have sum of 90 pages, now, here the max is 90.
// In second case, 10 20 | 30 40, isme first student ko 2 books and remaining ko 2 books where, first and second book has a sum of 30 pages and rest of the two books have sum of 70 pages, now, here the max is 70.
// In third case, 10 20 30 | 40, isme first student ko 3 books and remaining ko 1 books where, first and second and third book has a sum of 60 pages and rest 1 book has sum of 40 pages, now, here the max is 60.
// Now saare maximum ka minimum nikalna hai and that will be our required answer!

// Now ab humari approach kya hogi isme...hume ye ptaa hai ki jaise humne pehle search space use kiya tha sqrt vaale question me, voh hum yahaa kr sakte hai! kaise? aise...
// Humne yahaa dekha ki arrays sorted the ye unsorted bhi ho sakte hai, so hume kya krna hai ki, pehli baat we are given some constraints, uske according we will make conditions!
// If it is not possible to allocate m books to n students then return 0;
// number of students and number of books, 2-1000 tak me lie krenge!
// number of pages 1-10^9 tak rahenge!

// Now lets create a search space, how? as an example le lete hai ki hume maanlo 0-100 pages ko alot krne hai between 2 students! so what we will do is, we will first find mid and it will be at 50, now we will check that kya 50 ek possible solution hai ki nhi, so now, we had 10, 20, 30, 40 pages books, now lets see...
// 10 20 30 40, books dena shuru kiya and agar no. of pages 50 ya usse kam ho rhe hai toh usko kisi ek student ko alot krdiya, then remaining books dena shuru kiya!
// 10 20 | 30 | 40, pehle do books dediye 1st student ko (as 30<=50), now 3rd book dediya 2nd student ko (as 30<=50), now 4th book dediya 3rd student ko, but waittt 3rd student toh hai hi nhi, mtlb ki saare books alot hue bhi nhi pr students nhi bache ab! mtlb ki ye ek possible solution nhi hai, mtlb ki we need to shift our mid, so what we will do is, hume pta hai ki agar 50 se peeche jayenge toh aur answer nhi ayega kyunki fir bhi saare students ko books dedene ke baad bhi books bache rahenge, so we will move our mid forward and will do s=mid+1, ab firse nayaa mid nikalenge and then again usko compare krenge ki iss naye mid se solve ho paa rha hai question ki nhi!...so like in this case...
// our new mid will be, 75 (51-100) and now lets check, 10 20 30 | 40, here we can see that partition ke dono taraf sum of pages chhote hai 75 se, so we will store this answer first, but hume toh minimum nikalna hai toh for that ab iss baar hum backward jayenge and search space ko aur chhota krenge, with end = mid-1, now our new search space is, 51-74, now the new mid is 62, now, 10 20 30 | 40, dono partition ke number of pages compare kiye 62 se, but still its a solution! so now we will again replace our already stored answer 75 with 62 and now we will again change the end = mid-1, now the new start = 51 and end = 61, now mid = 56, this time ab jab hume pta hai 10 20 30 | 40 could be our best possible solution and also partition ke dono taraf jo sum of number of pages hai vo 56 se toh kam hi hai,
// so we will update our start = mid + 1, and now our new search space is, 57-61, and now, our new mid is 59 and now again humne compare kiye values of number of pages on both the sides, but this time again they are bigger than the mid (60>=59) so we have again updated our start=mid+1, now we have reached start = 60 and end = 61 and the mid = 60, so now 10 20 30 | 40 isme both partition have <= 60, so now this is our again a solution, now according to our code start will again update to mid + 1 and this time start = 61 and end = 61, and iss case me toh 10 20 30 | 40 vaala partition possible nhi hai and kyunki vhii number of pages ka sum 60<= nhi hai, so end update hojayega mid-1 se, and now start = end hojayega and here we will exit the loop!
// And we will print our answer stored!

// Now lets code!
#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int st, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > st || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int st) {
    int s = 0;
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e) {
        if(isPossible(arr,n,st,mid)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int arr1[1000];
    int size, students;
    cout<<"Enter size of book shelf : "<<endl;
    cin>>size;
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    cin>>students;
    cout<<"Maximum number of pages assigned to a student are : "<<allocateBooks(arr1,size,students);
}

// Question 2 : Aggressive Cows Problem : Given an array of length "n", where each element denotes the position of a stall! Now you have "n" stalls and an integer "k", which denotes the number of cows that are aggressive. To prevent the cows from hurting each other! You need to assign the cows to the stall. such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance!
// Lets understand with an example, suppose an array, {4,2,1,3,6}, and now suppose you have 2 cows jo aapas me bhot ladti hai toh hume unn cows ko inn 5 me se kin hi 2 positions pr place krna hai! toh vo kaise krenge! so here we will use the same approach as we have did earlier! so overall we need to find the largest minimum distance! mtlb jitne alag ways hai cows ko arrange krne ke liye unn harr way ki largest values me se largest minimum distance kya hai vo nikalna hai!
// First way of arrangement!
// 4  |  2  |  1  |  3  |  6    Minimum Distances of every cows arrangements!
// C1 |  C2 |     |     |       = 2 unit distance
// C1 |     |  C2 |     |       = 3 unit distance
// C1 |     |     |  C2 |       = 1 unit distance
// C1 |     |     |     |  C2   = 2 unit distance

// Second way of arrangement!
// 4  |  2  |  1  |  3  |  6
//    |  C1 |  C2 |     |       = 1 unit distance
//    |  C1 |     |  C2 |       = 1 unit distance
//    |  C1 |     |     |  C2   = 4 unit distance 

// Third way of arrangement!
// 4  |  2  |  1  |  3  |  6
//    |     |  C1 |  C2 |       = 2 unit distance
//    |     |  C1 |     |  C2   = 5 unit distance

// Fourth way of arrangement!
// 4  |  2  |  1  |  3  |  6
//    |     |     |  C1 |  C2   = 3 unit distance

// And we are asked to find the largest minimum distances, toh humne sabke minimum distances nikal liye ki ek cow ko ek particular arrangement me kitna dur rakh sakte hai and then humne unn sab minimum distance me jo maximum hai uski value nikal li and then vhi answer ho jayega!

// Now what we will do is that we find a search space! so we know in the array given to us usme we have positions in an un sorted manner like 4,2,1,3,6 and we are placing the cows one by one! now the thing is how we know ki kis distance pr cows ladengi? ye hume nhi pta but itna toh pta hai na ki jita zyada distance hga dono cows me utna chance hai ki vo nhi ladengi! so bss hume vhi latgest distance nikalna hai! and hum vhi krne vaale hai!
// But for that lets first define a search space! we know the minimum distance between two cows can be 0 and the maximum can be max-min = 6-1 = 5
// Now we know the distance can range from 0 to 5, and that will be our search space!
// Now we will find the mid, and here between 0-5 the mid = 2 (yahaa 2 position nhi hai distance between 2 positions hai), ab hum ek cow ko array ko sort krke unke number line pr positions ke according place krte jayenge!
// like from starting, jaise pehle cow ko 1 position pr then next cow ko 2nd pr place kiya and then distance naapa and in this case it is 1 which is <= 2 so yahaa toh possible nhi hai (Kyunki jo mid aaya hai vo hum minimum distance maan ke chal rhe hai ki uss distance pr toh cows ladengi toh ab jab kin hi do positions ka distance 2 se kam aayega toh vahaa toh aur obviously cows ladengi) so now we will place the second cow on the 3rd position and here the distance is = 2 so as this distance between 1 and 3 is >=2 so ab hume toh maximum distance nikalna hai na jahaa pr cows nhi ladengi, so to find that we will move on the right side so we will do s = mid+1, and now the search space has become, 3-5 (again saying this is not positions, they are minimum distances jitne pr cows ko place kiya jaa sakta hai!), now we will again find the mid! and here the new mid is 4.
// Now, firse cows ko place krenge pehle 1st postion pr sorted array ke and then dusre cow ko pehle 2nd position jo sahi nhi hoga then 3rd pr jo iss baar sahi nhi hoga kyunki 3 pr rakhne me minimum distance between the cows 2 hojayega but hume minimum distance ab 3 chahiye atleast so ab cow ko hum rakhenge 4th position which is also not valid becoz iss case me minimum distance 3 hoga which is still <= mid, so now we will put the second cow at 5th position and now the distance is 4 which is >= mid (which is 4), so now again we will update the s = mid+1 and now the s = 5, means now the start and end is the same! ab jab ptaa hai ki pehli cow ko 1st pr rakhne ke baad secod cow ko 5th pr rakhne ka bhi fayeda nhi hai toh this time hum 5th cow ko 6th position pr rakhenge and now the minimum distance is 5 which is >= mid, now we will again update s = mid+1 and now s>e and this will be our termination condition!
// And now we will print it!
// Now lets write the code!
#include <iostream>
#include <algorithm>
#include <vector>  // Added to use vectors
using namespace std;

bool isPossible(vector<int>& stalls, int cows, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0]; // It tells the first cow kahaa rakhi hai, here last is not LAST, its like abhi jo last cow rakhi thi vo kahaa rakhi thi, toh vo first stall pr rakhi thi and that is represented as stall[0]
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == cows) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls.back();  // Use the maximum element as the end point
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, cows, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    vector<int> stalls(size);
    for (int i = 0; i < size; i++) {
        cin >> stalls[i];
    }

    int cows; // Number of cows!
    cin >> cows;

    int result = aggressiveCows(stalls, cows);
    cout << result << endl;

    return 0;
} // The more appropriate way of forming this question also to avoid the confusion becoz of the word aggressive is, find the maximum minimum distance in such a way that K cows can be arranged at N stalls!
// So thats how you solve aggressive cows question! There are more questions to binary search but lets discuss it in future! till the practice it properly! and keep revising the approaches that you are studying in the whole DSA series!


// ---------------------------------------------------------- LECTURE 16 - Sorting Algorithm : Selection Sort! --------------------------------------------------------------------------------------------------------->
// This is a sorting algorithm which is used to sort an array in ascending order!
// Now what is actually selection sort!
// So what we are actually doing is ek element ko hold kiya! and then remaining array me jitne bhi elements hai unn sabko ek ek krke compare kiya and jab bhi koi smaller element milta hai hum swap krdete hai and then apni iteration continue rakhte hai agar firse koi aur more smaller milta hai usko bhi swap krdete hai and this is how we basically move forward and completely sort the array ek ek krke, isme hum do loops use krte hai, ek first element ko hold krke rakhne ke liye and ek uske remaining array me iterations krke uss first element se compare krne ke liye! and then jab inner loop poora execute hojaata hai then hum jo final index save kiya hai sabse chhote element ka uss remaining array ka usko swap krdete hai first element se!
// So in short, first element ko min index naam se hold kiya! and then remaining array me se sabse chhota element find kiya, jo uss remaining array me bhi chhota ho and jo uss first element se bhi chhota ho! and then usko swap krdiya with the first element!
// For example, suppose an array 1 7 9 2 3 0, now its size is 6 now agar hum first 1 ko hold krle and then remaining me se sabse chhote element ko usse compare kraa kra ke swap krte jaye toh how many steps it will take...
// 1 | 7 9 2 3 0 -> 0 is the smallest element in the remaining array so we will save its index and when the j vaala loop khatam hoga tab 0 aur 1 ko swap krdenge!
// 0 7 | 9 2 3 1 -> now in this case, 0 is already sorted and i = 1 and j = 2 now remaining array ke saare element ko i = 2 se compare krenge and jo chhota element hoga uska index save krenge jaise 7 se chhota 2 hai toh pehle isak index save kiya then ab check kiya ki kya 2 se chota koi hai? so yes 1 hai ab firse iska index save kiya, now 1 se chhota remaining array me koi nhi hai toh bss isko swap krdiya!
// 0 1 9 | 2 3 7 -> Did the same thing as above!
// 0 1 2 9 | 3 7 -> Did the same thing as above!
// 0 1 2 3 9 | 7 -> Did the same thing as above!
// 0 1 2 3 7 9 | -> Did the same thing as above!
// And hence after 5 steps our array is sorted totally! means hume agar 6 size ka array hai toh 5 baar comparisons krne honge! jo i vaala loop hai vo end tak nhi jayega vo sirf n-2 tak jayega kyunki n-1 tak toh j jayega compare krne ke liye!
// Let see how we will code this!
#include<iostream>
using namespace std;

int printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int selectionSort(int arr[], int n) {
    for(int i = 0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    printArray(arr, n);
}

int main() {
    int size;
    cin>>size;

    int arr1[500];
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    selectionSort(arr1, size);
}
// Space Complexity! : It is constant here! kya humne koi extra space liya hai sort krne ke liye? NO, humne sirf kuch variables banaye hai sort krne ke liye! but koi extra space nhi liya sort krne ke liye! Hence space complexity is here is O(1) which is constant space complexity!
// Time Complexity! : Here we can see that andar vaala loop n-1 time chal rha hai and outer loop n-2 times, and they are nested loop so the time complexity will be (n-1)*(n-2) and hence the answer will be (n^2)! hence the time complexity will be, O(n^2)!

// Best Case Time Complexity : Best case is that the array is already sorted! but fir bhi hum comparisons toh krenge hi! hence in the best case bhi the time complexity will be O(n^2)!
// Worst Case Time Complexity : Worst Case me jab array ekdum hi ulta ho! uss case me bhi hum saare comparisons krenge hi, toh uss time bhi time complexity will be O(n^2)!
// So in selection sort the Best case TC and Worst case TC are same!

// Use Case of Selection Sort! : We can use this algorithm when the array/vector/list size is small!
// Stable Algorithms : Imagine you have a list of things, and some of those things have the same value or "key". A stable algorithm will sort the list in a way that if two things have the same value, the one that appeared first in the original list will still be first in the sorted list.
// UnStable Algorithms : On the other hand, an unstable algorithm doesn't guarantee that order. If two things have the same value, their order might get swapped in the sorted list.

// Let's say you have a list of students with their scores. Some students might have the same score. If you use a stable sorting algorithm and two students have the same score, the one who took the test first stays ahead in the sorted list. If you use an unstable sorting algorithm, the order of students with the same score might get mixed up in the sorted list.
// Now for selection sort, it is an unstable sorting algorithm!

// ---------------------------------------------------------- LECTURE 17 - Sorting Algorithm : Bubble Sort! --------------------------------------------------------------------------------------------------------->
// Bubble Sort : So kya hota hai ki hum array ke harr adjacent element ko aapas me compare krke agar right vaala element chota hai left vaale se toh swap krdete hai, ya agar right vaala element badaa hai left vaale se toh usks step ko ignore krke aage badh jaate hai!
// So bss hum vahi krenge!
// Suppose an array : 10 1 7 6 14 9
// Round 1 :
// 10<->1 7 6 14 9 : right element is < left element, so we will swap the two elements.
// 1 10<->7 6 14 9 : right element is < left element, so we will swap the two elements.
// 1 7 10<->6 14 9 : right element is < left element, so we will swap the two elements.
// 1 7 6 10<->14 9 : right element is > left element, so we will ignore it. and will move forward.
// 1 7 6 10 14<->9 : right element is < left element, so we will swap the two elements.
// ---> 1 7 6 10 9 | 14 : After the first round we can see that the 1st largest element is at the end of the array, jahaa usko hona chahiye tha.

// Round 2 :
// 1<->7 6 10 9 | 14 : right element is > left element, so we will ignore it and will move forward.
// 1 7<->6 10 9 | 14 : right element is < left element, so we will swap the two elements.
// 1 6 7<->10 9 | 14 : right element is > left element, so we will ignore it. and move forward.
// 1 7 6 10<->9 | 14 : right element is < left element, so we will swap the two elements.
// ---> 1 7 6 9 | 10 14 : After the second round we can see the 2nd largest element is at the right position! jahaa usko hona chahiye!

// Round 3 :
// 1<->7 6 9 | 10 14 : right element is > left element, so we will ignore it and will move forward.
// 1 7<->6 9 | 10 14 : right element is < left element, so we will swap the two elements.
// 1 6 7<->9 | 10 14 : right element is > left element, so we will ignore it and will move forward.
// ---> 1 6 7 | 9 10 14 : After the 3rd round the 3rd largest element is also sorted and is now at the right position!

// Round 4 :
// 1<->6 7 | 9 10 14 : right element is > left element, so we will ignore it and will move forward.
// 1 6<->7 | 9 10 14 : right element is > left element, so we will ignore it and will move forward.
// 1 6 | 7 9 10 14 : After the 4th round the 4th largest element of the array is also sorted and is at the right position!

// Round 5 :
// 1<->6 | 7 9 10 14 : right element is > left element, so we will ignore it and will move forward.
// 1 | 6 7 9 10 14 : Now after the 5th iteration 5th largest element is also sorted, so now we can say from obvious logic and common sense ki agar saare elements apne right place pr hai toh 1st element bhi apne right place pr hoga!
// And hence the whole array is sorted!

// So we can see it took us 5 rounds for an array of size 6, means hume n-1 round lgte hai n size ke array ke liye to sort using bubble sorting!
// Also we can say ki hum bubble sort me ith largest element ko ith round me uske sahi jagah pohocha dete hai!
// Now lets code it!
#include<iostream>
using namespace std;

int printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[], int n) {
    for(int i = 1; i<n; i++) { // Yahaa hum index ke hisaab se nhi rounds ke hisaab se loop ko iterate kr rhe hai! so yahaa humne 1 se lekar n-1 rounds tak ke liye loop ko iterate kraya hai!
        for(int j = 0; j<n-i; j++) { // Here the reason of n-i condition is kyunki harr ek round ke end me largest element apne sahi place pr pohoch jaa rha hai means ab hume us last ek element ko sort krne ki zarurat nhi hai isliye hum n-i krde rhe hai taaki vo ek element hatt jaye humari range se and faltu me hum uss element ko bhi traverse na krde! vaise sort toh fir bhi ho jayega but ye krne se extra elements bhi travserse ho rhe honge and isse thora zyada time lega
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    printArray(arr, n);
}

int main() {
    int size;
    cin>>size;

    int arr1[500];
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    bubbleSort(arr1, size);
}
// Time Complexity : Here we can see that do loops chal rhe hai ek jo n-1 tak chal rha hai and ek jo n-i-1 tak chal rha hai! and the two loops are nested, so we multiple the the two, and hence the TC will be, O(n^2)!
// Space Complexity : Again yahaa humne koi extra space nhi liya hai comparison ya sorting ke liye and jo bhi space liya hai vo sirf variable declare krne ke liye, so means here the space complexity is, O(1). means it has a constant space complexity!

// Best case Time Complexity : For this we know if the array is already sorted, then means koi element swap hi nhi hua! means agar kabhi array ko sort krte time koi bhi element swap nhi hua! means ki vo array already sorted hai! so hum yahaa thora code optimize krenge, like in the best case we know koi element swap nhi hua, toh chalo iss cheez ko bhi add krte hai code me! taaki hum apni best case TC ko thora kam kr sake, vrna agar bina swaps ko check kiye krenge then our time complexity will be O(n^2)! but agar hum iss swaps ko check krlete hai then our TC can be reduced!
#include<iostream>
using namespace std;

int printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int BubbleSort(int arr[], int n) {
    for(int i = 1; i<n; i++) {
        int swapped = false;
        for(int j = 0; j<n-i; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped = false) {
            // Agar yahaa ye condition sahi hojaati hai means koi element swap nhi hua hai means ye array already sorted hai means hum yahaa pr loop exit kr sakte hai!
            break;
        }
    }
    printArray(arr, n);
}

int main() {
    int size;
    cin>>size;

    int arr1[500];
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    bubbleSort(arr1, size);
}
// Hence in this case our best case time complexity will be O(n), kyunki sirf ek baar loop iterate kiya and usme ek bhi swap nhi hua means array already sorted hai! So aise humne apna code optimize krliya hai and TC bhi kam krli hai from O(n^2) -> O(n)!
// Worst Case Time Complexity : The worst case will ve when the array is reversed! then uss case me toh TC O(n^2) hi rahegi!

// Bubble Sort is a stable Sorting ALgorithm!
// Now there is a term "in-place" sorting algorithms, what happens in this is that ki ye vo tarah ke sorting algorithms hote hai jinme koi extra space required nhi hoti, ye vahi ka vahi sort krdete hai swap and all krke, but koi extra space nhi lete!
// A formal definition of In-Place Sorting Algorithms is : In computer science, "in-place sorting" refers to a sorting algorithm or method that uses a constant amount of extra memory space to rearrange elements within the data structure being sorted. In other words, the sorting process does not require additional memory proportional to the size of the input data.
// In-place sorting is desirable for situations where memory usage is a critical factor, and there is a need to minimize the use of additional memory. Algorithms that operate in-place modify the input data structure directly, without requiring additional arrays or data structures to store temporary values during the sorting process.
// Common in-place sorting algorithms include :
// 1) Bubble Sort : It compares and swaps adjacent elements in the array, moving the largest element to its correct position in each pass.
// 2) Selection Sort : It repeatedly selects the minimum (or maximum) element from the unsorted portion of the array and swaps it with the first unsorted element.
// 3) Insertion Sort : It builds the sorted array one element at a time by repeatedly taking elements from the unsorted part and inserting them into their correct position in the sorted part.
// 4) Heap Sort : It uses a binary heap data structure to repeatedly extract the minimum (or maximum) element and rebuild the heap until the entire array is sorted.
// While in-place sorting algorithms are memory-efficient, they may not be the most time-efficient for large datasets. Other sorting algorithms that use additional memory, such as Merge Sort and QuickSort, can be more time-efficient in certain scenarios but are not considered in-place algorithms. The choice of sorting algorithm depends on the specific requirements of the application and the constraints on memory usage.


// ---------------------------------------------------------- LECTURE 18 - Sorting Algorithm : Insertion Sort! --------------------------------------------------------------------------------------------------------->
// So lets understand this sorting algo with the help of cards example!
// Suppose you have 5 cards with the numbers on it, suppose the cards are arranged in an array, 5 2 6 9 4
// Now, you will pick the first card and place it on your hand, now you will pick another card and in this case it is 2 and 2<5 so ye 5 se pehle ayega! now you have 2 5, now will pick another card, and now you have 6, and 6>5 so you will put it after 5, so now the new array forming is 2 5 6, now will pick another one and now it is 9, now we will put it after 6, now the new array is 2 5 6 9, and now lastly the last card we will pick and it is 4 so we will put it between 2 and 5! And now our array is totally sorted!
// Now lets understand the actual technical way ki hum kaise krenge ye uparvaali cheez!

// Suppose an array, 10 1 7 4 8 2 11.
// Lets start with the first element of the array which is 10 here.
// First we took 10 the first element as our smallest element!
// 10 | 1 7 4 8 2 11

// Round 1 : Now we will take 2nd element, which is 1 and 1<10 so we will shift the 10 one index forward and will put 1 at the place of 10!
// 1 10 | 7 4 8 2 11

// Round 2 : Now we will pick the 3rd element, which is 7 and now we compare again, 7<10 and >1, so we will place it between 1 and 10, so we will shift 10 one index forward and will put the 7 at 2nd index
// 1 7 10 | 4 8 2 11

// Round 3 : Now 4th element, which is 4 and 4<10, 4<7 and 4>1, so we will shift 7 and 10 both one index forward and then will put 4 there!
// 1 4 7 10 | 8 2 11

// Round 4 : Now 5th element, which is 8 and 8>1, 8>4, 8>7 and 8<10, so we will shift 10 one index forward and now will put 8 there!
// 1 4 7 8 10 | 2 11

// Round 5 : Now 6th element, which is 2 and 2>1, 2<4, 2<7, 2<8 and 2<10, so we will shift all 4 7 8 10 one index forward and will put 2 in at index 1
// 1 2 4 7 8 10 | 11

// Round 6 : Now 7th element, which is 11, and 11>1, 11>2, 11>4, 11>7, 11>8, 11>10 means we will keep it at last! Hence the final sorted array will be...
// 1 2 4 7 8 10 11
// Array is sorted!

// We can see ki 7 size ka array tha toh 6 rounds chale hai! means here agar size n hua toh n-1 rounds chalenge!
// Lets code this logic now...
#include<iostream>
using namespace std;

int printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int insertionSort(int arr[], int n) {
    int j;
    for(int i = 1; i<n; i++) { // Ye loop hum i = 1 se chalaa he hai reason being, hum rounds ke according iterate kr rhe hai! and also kyunki hum first element ko toh sorted hi man rhe hai na!
        int temp = arr[i];
        for(j=i-1; j>=0; j--) {
            if(arr[j]>temp) {
                // Shift
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
    printArray(arr, n);
}

int main() {
    int size;
    cin>>size;

    int arr1[500];
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    insertionSort(arr1, size);
}
// Some characteristics of this algorithms are : It is very Adaptable, It is a stable Algorithm and yes it works well when size of the array is small! or the array is partially sorted tab zyada achi performance aati hai!
// Space Complexity : It is constant, kyunki hum koi extra space use nhi kr rhe! jitna space hai utne me hi hum sort kr rhe hai!
// Time Complexity : Here it will be O(n^2), kyunki again becoz of the same reason as of above!

// Now, Best Case and Worst Case :
// Best Case TC : O(n), ye tab hoga when the array will be already sorted! Tab kya hoga ki like, 1 2 3 4 5, isme kya hoga ki hum harr round me sirf ek comparison kr rhe honge, like 1 ko humara smallest element maana, then 2 ko compare kiya and 2>1 so usko aage lgaa diya, then 3 ko 2 se compare kiya and 3>2 toh isko bhi uske aage lgaa diya, aise sabko aise ek ke aage ek lgaa diya toh baar baar harr element se compare krne ki zarurat nhi padi! so its TC is O(n) in the best case!
// Worst Case TC : O(n^2), ye tab hoga when the array is reversed, tab saare elements se comparison hoga and then TC will become, O(n^2)!


// ---------------------------------------------------------- LECTURE 19 - C++ STL (Standard Template Library) --------------------------------------------------------------------------------------------------------->
// STL is like a short way of using some of the functionlaties jinko hum entirely code krte hai! like, jaise koi binary search hogyi uske liye abhi tak hum poora code likh rhe the pr using STL hum simple ek line add krke hi binary serch ki saari functionlaties include kr sakte hai!
// C++ STL do tarah ke hote hai, ek toh hota hai Containers (which are used to store data) and ek hota hai algorithms (which are used to apply algorithms).
// So lets first start with containers :
// 1) Arrays :
#include<iostream>
#include<array> // To implement arrays using STL we include this library!
using namespace std;

int main() {
    int arr1[5] = {1,2,3,4,5}; // This is a static array.
    array<int,5> arr2 = {6,7,8,9,10}; // This is also a static array, just implemeted using STL!
    int size = arr2.size(); // This .size() is used to find the size of the STL array.
    for(int i = 0; i<size; i++) { // Printing all the elements of the STL array!
        cout<<arr2[i]<<" ";
    }
    cout<<"Element at Index 2 : "<<arr2.at(2)<<endl; // It will tell the value at index 2 in the STL array!
    cout<<"Empty or not : "<<arr2.empty()<<endl; // It returns a boolean value that whether the array is empty or not.
    cout<<"First element of the array : "<<arr2.front()<<endl; // It tells the first element of the array.
    cout<<"Last element of the array : "<<arr2.back()<<endl; // It returns the last element of the array.
}

// 2) Vector : Vectors are the dynamic arrays, they increase their length according to the number of elements! Now maanlo humne ek vector banaya and uska size 4 tha and jaise hi hum 5th element daalenge vaise hi uska size double hojayega!
// And ye vectors kaam aise krte hai ki like jab 4 se zyada elements humne daale toh ye vector apne se double size ka ek dynamic array bnaa dega kisi aur memory location pr and usme saare elements copy krdega and jo humne add kiya hai usko bhi add krdega and saath saath jo pooraana vaala tha array usko bhi remove and delete krdega!
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v1;
    cout<<"Capacity of the vector : "<<v1.capacity()<<" and "; // Capacity is the amount of space available in the vector!
    cout<<"Size of the vector : "<<v1.size()<<endl; // And size is the number of elements present in the vector!

    v1.push_back(20);
    cout<<"Capacity of the vector : "<<v1.capacity()<<" and ";
    cout<<"Size of the vector : "<<v1.size()<<endl;

    v1.push_back(21);
    cout<<"Capacity of the vector : "<<v1.capacity()<<" and ";
    cout<<"Size of the vector : "<<v1.size()<<endl;

    v1.push_back(22);
    cout<<"Capacity of the vector : "<<v1.capacity()<<" and ";
    cout<<"Size of the vector : "<<v1.size()<<endl;

    cout<<"Elements at Index 2 is : "<<v1.at(2)<<endl;

    // int size = v1.size(); // Aise size declare krdoge toh size pop ke baat toh change hoga na, pr kyunki tumne isko aise initiallize kiya hua hai, and after the popping ke baad bhi tum iss hi size variable ko use kr rhe ho iss chakkar me size change hi nhi hua after popping ke iteration me!
    for(int i = 0; i<v1.size(); i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    cout<<"Before popping the last element, ";
    cout<<"Capacity of the vector : "<<v1.capacity()<<" and ";
    cout<<"Size of the vector : "<<v1.size();
    cout<<" And the current array is : ";
    for(int i = 0; i<v1.size(); i++) {
        cout<<v1[i]<<" ";
    }

    v1.pop_back();

    cout<<endl;

    cout<<"After popping the last element, ";
    cout<<"Capacity of the vector : "<<v1.capacity()<<" and ";
    cout<<"Size of the vector : "<<v1.size();
    cout<<" And the new array is : ";
    for(int i = 0; i<v1.size(); i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    // Another way of iterating this for loop is the below one, jahaa hum range-based for loop ko use kr rhe hai! jisme i bss harr element ke paas jaata hai and uss value ko print krdeta hai! yahaa index se kuch lena dena nhi hai!
    // cout<<"Before Pop : "<<endl;
    // for(int i:v1) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // v1.pop_back();
    // cout<<"After Pop : "<<endl;
    // for(int i:v1) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // Now lets clear the vector and then again inspect...
    cout<<"Vector before clear command : ";
    for(int i:v1) {
        cout<<i<<" ";
    }
    cout<<", And the size of vector is : "<<v1.size();
    cout<<endl;
    v1.clear();
    cout<<"Vector after clear command : ";
    for(int i:v1) {
        cout<<i<<" ";
    }
    cout<<", And the size of vector is : "<<v1.size();
    cout<<endl;

    // Another way of intiallizing the vector is...
    vector<int> v2(5,1); // It means that ek vector bnao 5 size ka and uske saare places pr 1 daaldo!
    cout<<"Vector v2 is : ";
    for(int i:v2) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Another way is when you already has a vector and bss hume usko copy paste krna hai, then...
    vector<int> v2copy(v2);
    cout<<"Vector v2copy is : ";
    for(int i:v2copy) {
        cout<<i<<" ";
    }
}

// 3) Deque : It has an open end and start, isme hum deletion and insertion dono end pr kr sakte hai! Deque is a dynamic array! Deque means a doubly ended queue!
#include<iostream>
#include<deque>
using namespace std;

int main() {
    // Initiallizing deque
    deque<int> d1;
    // Pushing elements into deque
    d1.push_front(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    // Printing the deque :
    cout<<"Elemets of the Deque are : ";
    for(int i : d1) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of the deque are : "<<d1.size()<<endl;

    // Popping elements from the deque.
    cout<<"Before popping from back : ";
    for(int i : d1) {
        cout<<i<<" ";
    }
    cout<<",And size of deque before popping : "<<d1.size()<<endl;
    d1.pop_back();
    cout<<"After popping from back : ";
    for(int i : d1) {
        cout<<i<<" ";
    }
    cout<<",And size of deque after popping : "<<d1.size()<<endl;
    // Just like pop_back we have pop_front! jo aage se elements pop krta hai in the similar way!

    // Printing a particular element at a particular index.
    cout<<"Element at index 2 : "<<d1.at(2)<<endl;

    // Printing front and back elements
    cout<<"Element from front : "<<d1.front()<<endl;
    cout<<"Element from back : "<<d1.back()<<endl;

    // Empty command in deque
    cout<<"Is the deque empty? : "<<d1.empty()<<endl; // It will return 0 means no the deque is not empty!

    // Erase command in deque
    cout<<"Size of deque before erase function : "<<d1.size()<<endl;
    d1.erase(d1.begin()); // Parameter ke according decide hota hai ki konsa element erase krna hai, agar .end() likha hota toh end se 3 delete hojaata! agar .begin() + 1 likha hota toh 2 erase hojaata
    cout<<"Size of deque after erase function : "<<d1.size()<<endl;
    cout<<"The final deque : ";
    for(int i : d1) {
        cout<<i<<" ";
    }
}

// 4) Lists : Lists are implemented using doubly linked lists, ye hum baad me padhenge! abhi ke liye bss STL ke through samajhte hai! and isme koi indexes nhi hote toh yahaa at jaise functions kaam nhi krenge!
#include<iostream>
#include<list>
using namespace std;

int main() {
    // Initiallizing lists
    list<int> l1;

    // Pushing elements into lists
    l1.push_front(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    // Printing all the elements of the list
    cout<<"All the elements of the lists are : ";
    for(int i:l1) {
        cout<<i<<" ";
    }
    cout<<endl;

    // There are more functions like .begin(), .empty(), .back(), jaise push_back hai toh push_front bhi hai vaise hi pop_front and back bhi hai and all jo humne upar padh liye hai!
    cout<<"Elements of the list before erase : ";
    for(int i:l1) {
        cout<<i<<" ";
    }
    cout<<",and size of the list before erase : "<<l1.size()<<endl;
    l1.erase(l1.begin());
    cout<<"Elements of the list after erase : ";
    for(int i:l1) {
        cout<<i<<" ";
    }
    cout<<",and size of the list after erase : "<<l1.size()<<endl;
}

// 5) Stack : Jaise ek ke upar ek rakhne vaale system ko stack kehte hai, so isme LIFO principle follow hota hai, mtlb jo sabse last me jayega vo sabse pehle niklega and vice versa!
#include<iostream>
#include<stack>
using namespace std;

int main() {
    // Initiallizing stack
    stack<string> s1;

    // pushing into the stack
    s1.push("Utkarsh");
    s1.push("The");
    s1.push("King");
    s1.push("Verma");

    // top command in stack
    cout<<"Top most element of the stack is : "<<s1.top()<<endl; // Jo sabse end me gya hai vo sabse top pr hoga! so yahaa pr verma print hoga!

    // popping from stack, jo sabse upar hoga vo sabse pehle pop hoga!
    cout<<"top most element before popping from stack : "<<s1.top()<<endl;
    s1.pop();
    cout<<"top most element after popping from stack : "<<s1.top()<<endl;

    // Size of the stack
    cout<<"Size of the stack : "<<s1.size()<<endl;

    // Empty stack or not
    cout<<"Stack is empty or not : "<<s1.empty()<<endl;

    // Stack has no clear or erase methods!
}

// 6) Queue : It is based on the first in and first out! FIFO!
#include<iostream>
#include<queue>
using namespace std;

int main() {
    // Initiallizing queue
    queue<string> q1;

    // Pushing elements into the queue
    q1.push("Utkarsh");
    q1.push("Palak");
    q1.push("Kinshuk");
    q1.push("Paresh");
    q1.push("Vansi");
    cout<<"Original size of the Queue : "<<q1.size()<<endl;
    // So here Utkarsh entered first in the queue so he will exit first also!

    cout<<"First person in the queue : "<<q1.front()<<endl;
    q1.pop(); // Utkarsh nikal gya queue se...
    cout<<"First person in the queue : "<<q1.front()<<endl; // Now sabse aage palak hogi toh iss case me Palak print hoga! Now also jaise front hota hai vaise hi back bhi hota hai!
    cout<<"Size after popping first person from the queue : "<<q1.size()<<endl;
}

// 7) Priority Queue : Priority queue ek aisa data structure hai like ek baar humne agar isme data daal diya randomly jo bhi humaare paas hai, and now jab hum uss data ko nikalenge, toh humaare paas sirf do hi tareeke hai! yaa toh max_heap ya toh min_heap...means agar humne priority queue ko humne max_heap ke form me banaya hai toh sabse largest value sabse pehle niklegi and so on...
// Otherwise agar humne min_heap banaya hai tab sabse smallest value sabse pehle niklegi! Now lets see ki priority queue me max and min heap kaise banaate hai! By default agar hum koi priority_queue bnaate hai toh vo max_heap hota hai!
#include<iostream>
#include<queue>
using namespace std;

int main() {
    // max heap : yahaa humne jo priority queue banaya hai ye ek max heap hai, kyunki agar isme hum agar kuch data push kre and then unko bahar nikaale toh vo humesha pehle greatest bahar ayega!
    priority_queue<int> maxi;

    maxi.push(11);
    maxi.push(13);
    maxi.push(16);
    maxi.push(12);
    maxi.push(15);
    maxi.push(14);

    int n1 = maxi.size();
    for(int i = 0; i<n1; i++) {
        cout<<maxi.top()<<" "; // Sabse pehle sabse largest element print hua, then usko jab pop kiya gya, then uske baad usse second largest element nikla and then so on!
        maxi.pop();
    }
    cout<<endl;

    // min heap : It is just ulta of that max heap!
    priority_queue<int, vector<int>, greater<int>> mini;

    mini.push(1);
    mini.push(4);
    mini.push(3);
    mini.push(2);
    mini.push(6);
    mini.push(5);

    int n2 = mini.size();
    for(int i = 0; i<n2; i++) {
        cout<<mini.top()<<" "; // Isme kya ho rha hai ki as becoz ye ek queue hai and vo bhi priority queue and vo bhi mini heap vaala, toh pehle toh sabse chhota element jo bhi hoga vo print hojayega and then vo nikal jayega! and then remaining p_queue me jo sabse chhota element hoga vo print hoga and then vo bhi nikal jayega and so on, and thats how it works!
        mini.pop();
    }
    cout<<endl;

    // Ab as becoz humne upar vaale dono queues me pop kr kr ke khaali krdiya hai toh ab empty check krne pr dono hi queues me true dikhayega!
    cout<<"maxi is empty? : "<<maxi.empty()<<endl;
    cout<<"mini is empty? : "<<mini.empty()<<endl;
    // they both are printing 1 means they both are empty!
}

// 8) Sets : Sets me sirf unique elements hi hote hai, like agara aapne 5 baar 5 daal diya toh sirf ek hi baar 5 store hoga!
// Iski implementation BST ka use krke hoti hai and isme agar koi aap element daal dete hai toh uske baad usko aap modify nhi kr sakte hai, toh yaa toh aap daale ya naa daale (means delete krde)! chaahe kaise bhi daaldo elements but jab nikaloge tab isme se sorted order me elements retrieve ho rhe hote hai!
#include<iostream>
#include<set>
using namespace std;

int main() {
    // Initiallization of sets
    set<int> s1;

    // Pushing element into the set
    s1.insert(11);
    s1.insert(12);
    s1.insert(13);
    s1.insert(13);
    s1.insert(13);
    s1.insert(14);
    s1.insert(15);

    // Printing all the elements of the set
    cout<<"Elements of the set s1 are : ";
    for(int i:s1) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Using erase method
    s1.erase(s1.begin()); // It will remove the first element of the array!
    cout<<"Elements of the set after removing the first element : ";
    for(int i:s1) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Inserting a new element again... Jab bhi element insert kroge vo insert ho toh jayega pr jab usko print kraoge set ko toh vo sorted form me print hoga, kyunki memory me vaise hi array stored hota hai, and then set me iteration different type se hoti hai isme ek normal iterator use nhi hota hai!
    s1.insert(10); // 10 add kiya toh ye sabse aage gya set ke
    s1.insert(19); // 19 add kiya toh ye sabse last me gya set ke, reason being ofc kyunki isko sorted form me print hona tha!
    cout<<"Elements of the set after adding a new element : ";
    for(int i:s1) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Elements of the set after removing the 2nd element of the set : ";
    // erase ko use krne ke liye hum ek alag type se bhi likh sakte hai, like suppose hume set ka 2nd element delete krna hai toh we will write...
    set<int>::iterator it = s1.begin(); // This is a special type of iterator, which is used for sets! so what is special about this iterator, std::set<T>::iterator is a bidirectional iterator, meaning you can move it forward and backward. This allows you to easily navigate through the elements of the set, std::set<T>::iterator provides a convenient way to iterate over the unique, sorted elements of a std::set. It adheres to the characteristics of the set container, ensuring ordered traversal and uniqueness of elements. Ye iterator khud hi dhyaan rakhta hai sets i properties ka, like agar set me kisi element ka copy hai toh ye uspr iterate nhi krta!
    it++;
    s1.erase(it);
    for(int i:s1) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Understanding the set's iterator in a little more detail...like hum iterate ek normal for loop se bhi kr sakte hai! but aise hi nhi, lets understand...isme hum kya krte hai ki hum s1.begin() se shuru krte hai and condition daal dete hai ki jab tak !=s1.end() naa hojaye tab tak elements ko print krte raho and isme catch ye hai ki jo iterator hoga vo starting of the for loop me s.begin() mtlb starting of the set ko point, toh hum fir usme derefernce krke cout ke through print kareyenge!
    cout<<"All Elements of the set s1 : ";
    for(auto i = s1.begin(); i!=s1.end(); i++) { // Auto ka means ki the iterator is open to iterate over any data type of the set!
        cout<<*i<<" ";
    } // So this is the traditional way of using the for loop using iterator to dereference
    cout<<endl;

    // Count Method of sets, isme what happens is that ki hume ye toh ptaa hi hai ki set me duplicate values hote hi nhi hai toh isko use kyu kr rhe hai? so that we can see that if an element exist or not in the set! like agar count 0 aaya means nhi krta exist and 1 aaya means krta hai exist!
    cout<<"Does 5 exist in the set : "<<s1.count(5)<<endl;
    cout<<"Does 13 exist in the set : "<<s1.count(13)<<endl;

    // Find method
    set<int>::iterator it2 = s1.find(13); // Ab ye kya krega ki pehle element find krega and then it2 me uss element ka iterator return krdega! and then hum it2 ko derefence krke uss iterator ki value nikal lenge ki jisse hume ptaa chal jayega ki vo element kis position pr hai!
    cout<<"Value at iterator it2 : "<<(*it2)<<endl;
    // Now lets just print the set once again...
    for(auto it=it2; it!=s1.end(); it++) { // Humne it2 ko intiallize krne ke time pr usme jo element daala tha vo first element tha isliye usme first element ka iterator stored tha and iss hi kaaran jab print kiye saari values set s1 ki iss baar toh 13 se print hona chaalu hua, agar yhi uss time agar hum  set<int>::iterator it2 = s1.find(14); likh diye hote toh 14 se value print hona shuru hoti!
        cout<<*it<<" ";
    }
    cout<<endl;
    // So what happens in find method is jab hum use krte hai find function ko toh response me hume uss value ka refernce mil jaata hai!

    // Baaki rest is clear & empty method!
    s1.clear(); // It will clear all the elements in the set!
    for(auto i:s1) {
        cout<<i<<" ";
    } // Isme kuch print nhi hoga kyunki set iss baar poora khaali hai!
    cout<<endl;
    bool empty = s1.empty();
    cout<<"is the set s1 empty? : "<<empty;
}
// TC of insert find erase and count : O(logn)
// TC of size begin end empty : O(1)

// 9) Maps : In this DS the value are stored in form of Key Value pairs! and same key multiple values ko point nhi kr sakti but ek value ko point krne ke liye multiple keys ho sakti hai, Like Name1, Rolls Royce and another key value pair can be Name2, Rolls Royce. Now Name1 and Name2 are the keys but they are pointing at the same car value that is Rolls Royce, and Rolls Royce is being pointed by 2 different keys that is Name1 and Name2!
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
    map<int,string> m1;

    m1[1]="Utkarsh";
    m1[2]="The";
    m1[3]="King";
    m1[4]="Verma";

    // Another way of inserting values into the ordered map m1
    // m1.insert({1,"Utkarsh"});
    // m1.insert({2,"The"});
    // m1.insert({3,"King"});
    // m1.insert({4,"Verma"});

    cout<<"Key Value pairs of ordered map m1 : "; // It will print the key value pair of the ordered map m1
    for(auto i:m1) {
        cout<<i.first<<" "<<i.second<<endl; // First will print the integer key and second will print the string value!
    } // Ab dekho yahaa toh hum ordered map ke key value pairs ko print kraa rhe hai! toh yahaan toh sorted hi milega output! bhale hi humne initiallize upar neeche kiya hua ho! But yhi agar unordered map hota toh vahaa order ka kuch ptaa nhi, vo random hota hai, like uski koi guarantee nhi hai kismat achi ho toh sorted bhi ajayega output! but vaise koi pakka nhi hai!
    cout<<endl;

    unordered_map<int,string> m2;
    m2.insert({1,"Palak"});
    m2.insert({2,"is"});
    m2.insert({4,"Bestfriend"});
    m2.insert({3,"my"});

    cout<<"Key Value pairs of ordered map m1 : "; // It will print the key value pair of the unordered map m1
    for(auto i:m2) {
        cout<<i.first<<" "<<i.second<<endl;
    } // Isme order reverse me print ho rha hai iss time but ye bhi koi fix nhi hai but haa random order hota hai, mtlb koi order nhi hota!

    // Count method in maps
    cout<<"Does 12 exist in the ordered map? : "<<m1.count(12)<<endl; // Iska mtlb ek tarah se ye hua ki koi aisa key value pair hai? jiska key 12 ho!
    cout<<"Does 2 exist in unordered map? : "<<m2.count(2)<<endl;

    // Now lets carry forward with ordered map, unordered ke liye same hi cheez hogi...
    // Erase method in Maps
    cout<<"Key value pairs of ordered map m1 before erase : "<<endl;
    for(auto i:m1) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    m1.erase(4);
    cout<<"Key value pairs of ordered map m1 after erase : "<<endl;
    for(auto i:m1) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    // Find method, returns the iterator of that element (key value pair) ka!
    auto it = m1.find(1);
    for(auto i = it; i!=m1.end(); i++) {
        cout<<(*i).first<<" "<<(*i).second<<endl;
    } // Yahaa bhi same logic ki agar yahaa pe auto it = m1.find(1); me find ke andar me 1 ki jagah 2 hota toh iteration for loop me 2 se start hoti! and tab print hota sirf "The King"!
}
// TC of erase, insert, find and count methods for ordered maps is : O(logn), becoz iski implementation hoti hai red-black tree se ya balanced tree ka use krke
// TC of erase, insert, find and count methods for unordered maps is : O(1), but iski implementation hoti hai hash table se isliye yahaa pr complexity is O(1)


// Sorting Algorithms : Jo abhi tak hum kr rhe the ki binary search, and sorting ke jo algos the hume agar unka code yaad nhi hai pr hume usko use krna hai and even poora code likhna takes time, so hum seedha unke methods ko use kr sakte hai!
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> v1;
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    v1.push_back(15);

    // Binary search using STL
    cout<<"Does 5 exist in the vector v1? : "<<binary_search(v1.begin(), v1.end(), 5)<<endl;
    cout<<"Does 11 exist in the vector v1? : "<<binary_search(v1.begin(), v1.end(), 11)<<endl;

    // Lower and Upper Bound Methods : finding the iterator using two methods that are lower bound and upper bound
    // Lower Bound is the smallest index such that the number at that index is more than or equal to the given number!
    // Upper Bound is the smallest index such that the number at that index is more than to the given number!
    cout<<"Lower Bound of the vector v1 is : "<<lower_bound(v1.begin(), v1.end(), 13)-v1.begin()<<endl; 
    cout<<"Upper Bound of the vector v1 is : "<<upper_bound(v1.begin(), v1.end(), 14)-v1.begin()<<endl;
    // Then we have did "-v1.begin()" taaki hum 0 indexing ke form me laa sake! also removing "-v1.begin()" is showing error kyunki what happens is, this "lower_bound(v1.begin(), v1.end(), 13);" returns an iterator of type, "std::vector<int>::iterator", Using the iterator directly, such as by dereferencing (*it), allows you to access the value it points to. If you do not use the iterator, the compiler does not know what you intend to do with it, leading to an error.
    // so, doing this "lower_bound(v1.begin(), v1.end(), 13) - v1.begin();" "v1.begin()" returns an iterator to the first element. Subtracting "v1.begin()" from the iterator returned by lower_bound gives the distance (index) from the beginning of the vector. This is a valid operation because subtracting two iterators of the same container gives their distance as an integer.

    // Swap, Min and Max methods
    int a = 2, b = 3;
    cout<<"Before swap : a = "<<a<<" and b = "<<b<<endl;
    swap(a,b);
    cout<<"Before swap : a = "<<a<<" and b = "<<b<<endl;
    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;

    // Reverse method
    string abcd = "ABCD";
    reverse(abcd.begin(), abcd.end());
    cout<<"Reversed string : "<<abcd<<endl;

    // Rotate the vector
    cout<<"Before rotate : ";
    for(auto i : v1) {
        cout<<i<<" ";
    }
    cout<<endl;
    rotate(v1.begin(), v1.begin()+2, v1.end()); // Isme ek tarah se humne start, mid and end input diya hai as paramters!
    cout<<"After rotate : ";
    for(auto i : v1) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Sort method : It sorts the elements in ascending order and isme jo sorting use ho rhi hai usko kehte hai intro sort and this intro sort is based on the combination of Quick sort, Insertion sort and Heap sort!
    sort(v1.begin(), v1.end());
    cout<<"Vector v1 after sorting the elements : ";
    for(auto i : v1) {
        cout<<i<<" ";
    }
}

// ---------------------------------------------------------- LECTURE 20 - LeetCode/CodeStudio Questions --------------------------------------------------------------------------------------------------------->
// CodeStudio Question : Reverse a array after a particular index! pehle lets do it normally, ki normally kaise reverse krte hai!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> reverse(vector<int> v) {
    int s = 0;
    int e = v.size()-1;
    while(s<=e) {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v) {
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(5);

    vector<int> ans = reverse(v1);
    print(ans);
}

// For reversing the array/vector after a particular index is...
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> reverse(vector<int> v, int m) {
    int s = m+1;
    int e = v.size()-1;
    while(s<=e) {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v) {
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // You can also use the range based for loop here, it will work the same! just remember that here i is not an index it is the actual value!
    // for(auto i : v) {
    //     cout<<i<<" ";
    // }
}

int main() {
    int index;
    cin>>index;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(10);

    vector<int> ans = reverse(v1, index);
    print(ans);
}

// CodeStudio Question : Merge 2 sorted arrays!
// Approach ye hogi ki like dono arrays me alag alag apni apni iterations hongi and unn dono iterations ko apas me compare krenge jo iteration ki value chhoti hogi uski arr3 me push krdenge, and then jiss array ki vo value thi uske iterator ko ++ krdenge! and maanlo aise krte krte kisi ek array ki iteration khtam hogyi (mtlb usme jitne elements the sab iterate hoke add ho chuke hai arr3 me, toh ab jo dusri array hai uske jo remaining elements hai unko ab as it is daal sakte hai kyunki pehle baat toh vo sorted hai and dusri baat ki vo agar abhi tak bache hue hai toh ofc bade hi honge arr3 me jo elements gye hai unse!)
// So now lets code this logic!
#include<iostream>
using namespace std;

void mergeArrays(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0; int j = 0;
    int k = 0;
    while(i<n && j<m) { // Pehle sab elements ko compare kiya and push krdiya arr3 me and iterator ko increment krte gye!
        if(arr1[i]<arr2[j]) {
            arr3[k++] = arr1[i++]; // It is nothing but, k++ and i++ ko square brackets ke andar hi likh diya hai!
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    // After dono me se koi ek array ki iteration khatam hojaye, toh baaki ke elements bharna yahaa continue hoga!
    while(i<n) { // Ye vaala tab execute hoga jab arr1 ke elements bache hue hai abhi!
        arr3[k++] = arr1[i++];
    }

    while(j<m) { // Ye vaala tab execute hoga jab arr2 ke elements bache hue hai abhi!
        arr3[k++] = arr2[j++];
    }
    // And ofc dono me se koi ek hi execute hoga kyunki agar dono ki iteration bachi toh first while loop chalna chahiye the pr vo khatm hogya mtlb ki ab koi ek array hi bacha hua hai toh ab 2nd 3rd while loop me se koi ek execute hojayega!
    // also as becoz agar maanlo jaise iss case me arr2 ke saare iterations over hojayenge arr1 se toh last iteration ke time pr j=4 hojayega toh ab pehli baat toh 1st while loop end hojayega aur ye hua kyu kyunki arr2 ke elements ki iteration khatam hogyi and means arr1 ki bachi hui hai means abhi bhi i<=n and isliye 2nd while loop abhi bhi chalega and ramaining jitne bhi elements the arr1 ke vo saare arr3 me bhar dega! and 3rd while loop nhi chalega! isliye kahaa tha ki dono me se koi ek hi while loop chalega!
}

void print(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr1[5] = {1,3,5,7,9};
    int arr2[4] = {2,4,6,8};

    int arr3[9] = {0};
    mergeArrays(arr1, 5, arr2, 4, arr3);
    print(arr3, 9);
}


// CodeStudio Question : Move Zeroes, move all the zeroes to the right! in an array!, we can solve this question like move all the non zeroes to the left
// Approach : We will use two pointers and ek ko rakhenge 0 (i) (jo nun zero value denote kr rha hoga) pr and ek ko uske aage 1 pr and then jo 1 pr hai (j) usko aage badhaate jayenge and compare krte jayenge agar j pr jo value hai vo non zero hai toh usko i se swap krdenge jisse non zero elements left side chale jayenge and aise hi poore array me traverse krke hum poore array ke saare zeroes ko right side me shift krdenge!
#include<iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int i = 0;
    for(int j = 0; j<n; j++) {
        if(arr[j]!=0) {
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

void print(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr1[10] = {0,1,0,2,0,0,0,13,4,0};
    moveZeroes(arr1, 10);
    print(arr1, 10);
}
// We can convert this code for vectors also, but the logic is more important!
