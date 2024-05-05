// ---------------------------------------------------------- LECTURE 23 - 2D Arrays --------------------------------------------------------------------------------------------------------->
// Suppose hume koi matrix bnana hai jisme hume 3 rows and 3 columns chahiye! so what we want is 9 memory spaces! so hum kya sochenge ki lets create 3 arrays one below the other and kaam hojayega!
// But ye cheez ek limit tak sahi thi as uske baad jab number of rows and columns badhenge tab hum inti saari arrays thori baanane baithenge! like agar 1000 rows and columns chahiye mtlb its not feasible to create 1000 arrays, so to solve this problem we will create 2D arrays!
// There syntax will be int arr[row][column];
// But memory me 2D arrays kaise store hota hai? its not like ki matrix ke pattern me store hota hai, hota toh ye store linearly hi hai, bss elements ko access krne ke liye hum ek formula ya rule lgaa dete hai, taaki jab jis element ki baat kre tab vhi element mile!
// Isko hum visuallize matrix ke form me kr sakte hai pr memory me store ye linearly hi hota hai!

// we use this formula : column*(i+j) to map the visuallization with the actual linear store of the 2D array in the memory!
// Iss formula ke according hi ye dono aapas me map hote hai!
// To ye mathematically mapping vaala kaam dono ka aapas me already backend pr yhi logic se map ho rhe hai...so now we need to study how to create it in code!

// Creating 2D array! int arr[row][column];
// Taking input! cin>>arr[i][j];
// Output! cout<<arr[i][j];

// Now lets code!
#include<iostream>
using namespace std;

int main() {
    int twoDarray1[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>twoDarray1[i][j];
        }
    }
    cout<<"Our 2D array :"<<endl;
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cout<<twoDarray1[i][j]<<" ";
        }
        cout<<endl;
    }
    // So this is a way of taking input of the array and then printing it! hum alag alag way se print kr sakte hai bss i and j positions ko shift krke!
    // Ye matrix patern me print ho rha hai kyunki endl lagaya hau humne for loop ke andar, vrna aise normal ye linearl hi store ho rhi hai values!
}

// Intiallizing 2D arrays!
#include<iostream>
using namespace std;

int main() {
    int twoDarray1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; // Isme toh humne saare elements daal diye ab jo bhi jaise jaise i and j ke hisaab se store hote jayenge array me!
    int twoDarray2[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}; // Isme hume kis row me konsa element daalna hai vo hum pehle hi btaa sakte hai!
}

// Linear Search in 2D Array!
#include<iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int m, int n) {
    // In the above function declaration we need to sepcify the column size, because the compiler needs to know the size of each row in order to correctly access elements within the array.
    // Unlike with a 1D array, where you can omit the size parameter in the function parameter list because the size information is retained from the array itself, in the case of a 2D array, the size of the columns is not implicitly known to the function when you pass the array.
    // If you were to omit the column size, the compiler wouldn't know how many elements to skip when moving from one row to the next.
    // In this function, arr[][3] specifies a 2D array where each row has 3 columns. You need to specify the number of columns (in this case, 3) because the compiler needs this information to calculate the memory offset correctly when accessing elements within the array.
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            if(arr[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;

    // Aise bhi likh sakte hai!
    // for(m = 0; m<3; m++) {
    //     for(n = 0; n<4; n++) {
    //         if(arr[m][n] == target) {
    //             return 1;
    //         }
    //     }
    // }
    // return 0;
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    int target;
    cout<<"Enter your target element : ";
    cin>>target;

    if(isPresent(arr, target, 3, 4)) {
        cout<<"Element Present!";
    }
    else {
        cout<<"Not Present!";
    }
}

// Question : Row sum! printing sum of all the rows in the 2D array!
#include<iostream>
using namespace std;

void rowSum(int arr[][4], int m, int n) {
    for(int i = 0; i<3; i++) {
        int sum = 0;
        for(int j = 0; j<4; j++) {
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }

    rowSum(arr, 3, 4);
}
// Above example was for row wise sum, column wise krna ho toh bss function me jaake i and j ko interchange krdo!

// Question : Find the largest rowsum and which row has it!
#include<iostream>
#include<climits>
using namespace std;

int largestRowsum(int arr[][4], int m, int n) {
    int maxi = INT_MIN;
    int rowNum = -1;
    for(int i = 0; i<3; i++) {
        int sum = 0;
        for(int j = 0; j<4; j++) {
            sum += arr[i][j];
        }
       if(sum > maxi) {
        maxi = sum;
        rowNum = i;
       }
    }
    cout<<"Maximum sum is : "<<maxi<<endl;
    return rowNum;
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    cout<<largestRowsum(arr, 3, 4);
}

// Question : Wave print problem! Here we have to print the array elements like a wave, means suppose you have a 2D array as, {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}, so here print aise hoga ki like, 1,5,9,10,6,2,3,7,11,12,8,4
// Toh aise hume print krna hai ki like 1st column me upar se neeche print krenge then 2nd column ko neeche se upar then 3rd column ko upar se neeche and so on...
// So what we will do is, we can see that jahaa pr column ka index odd hai vahaa pr hum bottom se top jaa rhe hai and even index ke liye hum top se bottom jaa rhe hai!
// So according to the above approach, what we will do is hum column ke naam se loop chalaa lenge and then usme jahaa pr column odd hoga vahaa bottom se top jayenge and jahaa even hoga vahaa top se bottom jayenge!
#include<iostream>
using namespace std;

void wavePrint(int arr[][4], int m, int n) {
    for(int col = 0; col<n; col++) {
        if(col&1) {
            // Odd Index -> bottom se top!
            for(int row = m-1; row>=0; row--) {
                cout<<arr[row][col]<<" ";
            }
        }
        else {
            // Even index -> top to bottom!
            for(int row = 0; row<m; row++) {
                cout<<arr[row][col]<<" ";
            }
        }
    }
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    wavePrint(arr, 3, 4);
}
// and hence the above code will print the 2D array in waveform!
// Time Complexity : Isme hum upar se neeche and neeche se upar jaa rhe hai, mtlb hum harr element ko ek baar traverse kr rhe hai! means total number of element jo humne traverse kiya that is n*m means, the time complexity will be O(nm)!


// Question : Spiral Print! Here hume saare elements circular order me print krne hai! like pehle poori row, then poora column, then again poori row in reverse order amd so on... Question 54 at LeetCode!
// Approach : Hum pehle starting row print krenge then ending column print krenge then ending row print krenge then starting column print krenge!... jab bhi koi row ya column print hojaye then hum starting ya ending row ya column ko update krdenge! isme duplicates handle hojayenge!
#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row*col;

    // index intiallization...
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count<total) {
        // printing starting row...
        for(int index = startingCol; count<total && index<=endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // printing ending column...
        for(int index = startingRow; count<total && index<=endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // printing ending row...
        for(int index = endingCol; count<total && index>=startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // printing starting row...
        for(int index = endingRow; count<total && index>=startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> arr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> spiral = spiralOrder(arr1);
    cout << "Spiral order of the matrix: ";
    for(int i = 0; i < spiral.size(); i++) {
        cout << spiral[i] << " ";
    }
    cout << endl;   
}
// Time Complexity will be O(n*m) and it can't be decreased further!


// Binary search in 2D arrays!
// It is more or less similar to linear binary search! the only difference here will be finding the mid element! yahaa hum start, end mid index sab vaise hi nikalenge jaise linear me nikalte the!
// As in the end jo ye matrix hai 2D vaala ye memory me store toh linear form me hi hota hai, and ye sorted hi hota hai mostly... agar sorted nhi hai toh vo alaga baat hai usko then sort krke fir binary search lagayenge! but here we will talk about applying binary search in sorted 2D array!
// So now, pehle hum iss 2D matrix ko linear visuallize krke start, end and mid nikalenge!...
// start = 0
// end = row*col - 1
// mid = start + (end-start)/2
// now mid ka kya kya rules hota hai like... agar mid element == target element ke then return the mid, agar mid>target then we go on the left side of the array, and then agar mid<target then we go on the right side of the array!
// But the thing is mid element kaise nikalenge, mid index toh nikal liya, ab mid element kaose nikale kyunki yahaa toh uske liye hume row and index uss mid index ka specify krna hoga, yahaa linear vaali baat nhi hai na ki sirf mid nikal ke vhi index ki jagah daal diya, here we need to map that mid element ka jo humne index nikala hai start + (end-start)/2 se, isko hum row and column se map krna hoga ki ye ye jo mid aaya isse matrix ka konsa element map ho rha hai!
// And now if we try to map it, so it will be like, row = mid/(length of the row or number of columns).. make sense? kyunki mid jo bhi aaya toh usko agar kisi bhi ek row ke length (which will be equal to number of columns) se divide krdenge toh hume ye pta chal jayega ki vo mid element kis row se belong krta hai! and then for column we will find the remainder of the same division!
// hence, mid element ka (row = mid/number of col) and mid element ka column will be equal to (col = mid%number of col)! 
// Now lets code...
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row*col - 1;
    int mid = start + (end-start)/2;

    while(start<=end) {
        int midElement = matrix[mid/col][mid%col];
        if(midElement == target) {
            return 1;
        }
        if(midElement > target) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return 0;
}

int main() {
    vector<vector<int>> arr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    if(searchMatrix(arr1, 10)) {
        cout<<"Element present!";
    }
    else {
        cout<<"Element absent!";
    }
}
// Time complexity : O(log(nm))


// ---------------------------------------------------------- LECTURE 24 - Maths for DSA --------------------------------------------------------------------------------------------------------->
// Prime Numbers : Normally what we used to do is if we get an input n and then hum 1 to n tak ke saare numbers se n ko divide krke check krte the agar kahin bhi output 0 aajaye then vo prime nhi hai otherwise vo prime hai! lets write a small code for it...
#include<iostream>
using namespace std;

bool isPrime(int n) {
    if(n<=1) {
        return false;
    }

    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    cout<<isPrime(n);
}

// Question : Count the number of primes! Leetcode question : 204
// Isme hum upar vaala approach use nhi kr sakte kyunki uski TC bhot khrab ajayegi, as becoz isme har n ke liye n number of comparisions kr rhe honge! hence iski TC n^2 ajayegi! ehich will be very bad! so isliye we need to use some other approach!
// And for that we will introduce another method which will be called "Sieve of Eratosthenes"!
// So what this method says...
// So what we know is that prime numbers sirf apne table me aa sakte hai and sirf 1 se divisible ho sakte hai! and kisi aur ke nhi!
// So what we will do is... suppose we have n = 40 and now we will write all the counting upto 40 for better understanding!
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 38 39 40...
// Now, first we will do the comparison with all the number which are less than n and we will start our loop with 2 kyunki 1 se toh sab divisible honge hi!, and now we will mark all the numbers from 1-40 prime... pehle sabko prime maanlo! then, humari first iteration hogi 2 se, ab 2 toh prime number hai so humne usko prime marks krdiya! and then jo bhi numbers 2 ki table me aa rhe hai usko humne no-prime marks krdiya! then we moved to 3 now 3 is prime so jo bhi numbers 3 ki table me aa rhe hai unko non-prime mark krdiya! so humne same we moved to 5 as humne 4 ko cut krdiya, and 5 is a prime so 5 ki table me aane vaale saare numbers ko humne non-prie marks krdiya and same with 7 11 13 17 19 23 29 31 37...
// and then lastly we counted all of them... and we got the answer!
// lets code it!
#include<iostream>
#include<vector>
using namespace std;

int countPrime(int n) {
    int count = 0;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i<n; i++) {
        if(prime[i]) {
            count++;
            for(int j = 2*i; j<n; j=j+i) {
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    cout<<countPrime(n);
}
// Time Complexity : isme humne harr iteration pr n/i number of comparisons kiye hai, like pehle n/2 then n/3 then n/5 and so on...
// So on adding all of them by taking n common... n(1/2 + 1/3 + 1/5 + 1/7 + ....) it will give... n*(log(logn))...
// So our time complexity will be "O(n*log(log(n)))"


// GCD/HCF : Do numbers ka GCD/HCF vo hota hai jo unn dono ka koi aisa highest common factor jo dono ko divide krta ho!
// Ye hum aise nikalte the... suppose the 2 numbers are 24 and 72, then iske common factors nikalenge pehle...
// 24 = 2 x 2 x 2 x 3
// 72 = 2 x 2 x 2 x 3 x 3
// Hence here 2 x 2 x 2 x 3 is common, hence it is the GCD/HCF!
// GCD(a,b) = GCD(a-b,b) or GCD(a%b,b)
// Suppose we have to find the GCD of GCD(72,24) => GCD(48,24) => GCD(24,24) => GCD(0,24) hence here 24 is the GCD, means in layman terms, jab GCD me koi ek a ya b 0 hojaye then jo dusra vaala hoga usko hum GCD maan lenge!
// Lets code it...
#include<iostream>
using namespace std;

int GCD(int a, int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    while(a!= b) {
        if(a>b) {
            a = a-b;
        }
        if(b>a) {
            b = b-a;
        }
    }
    return a;
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
}
// Another mathematical relation we can keep in mind is : GCD(a,b) * LCM(a,b) = a*b


// Modulo Arithematic!
// 1) (a+b)%m = a%m + b%m
// 2) a%m - b%m = (a-b)%m
// 3) a%m * b%m = (a*b)%m

// Fast Exponentiation!
// Some lectures back we have calculated a power of a number thru the approach like... we need to find the value of a^b so we let int res = 1; then humne ek for loop ko b times iterate kraa ke res = res*a kiya tha! isme TC humari aa rhi thi O(b) kyunki loop ko b times iterate karaya!
// Now we will try to reduce the TC here using Fast Exponentiation!
// Approach : if we have a^b we can write it as a^(b/2) if b is even and (a^(b/2))*a if b is odd

// Question : Find the value of (x^n)%m isme hume x,n,m diya hua hai...here agar humne pehle vaali appproach follow kri toh TC kaafi badh jayega, so here we will use Fast Exponentiation! as becoz isme humari TC O(logn) ayegi!
// lets code this approach!
#include<iostream>
using namespace std;

int moduloExponentiation(int x, int n, int m) {
    int res = 1;
    while(n>0) {
        if(n&1) {
            res = ((1LL * (res) * (x)%m)%m);
        }
        x = (1LL * (x)%m * (x)%m)%m;
        n = n>>1;
    }
    return res;
}

int main() {
    int x1, m1, n1;
    cin>>x1>>m1>>n1;
    cout<<moduloExponentiation(x1,n1,m1);
}
