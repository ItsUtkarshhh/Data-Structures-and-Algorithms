// ---------------------------------------------------------- LECTURE 42 - OOPS Part 1 --------------------------------------------------------------------------------------------------------->
// What is it? It is that type of programming technique where things revolve around objects
// What are objects, objects has some properties, or state and has a behaviour! through OOPS we try to include real world objects into our program! taaki humare code ka real world application badh jaye!
// Now suppose in aa game we have an entity as Hero, now that hero is an objects, kyunki a Hero hs properties like it has a Name, Health, Level and etc... also it shows certain behaviours like Attack(), Defence() and similar etc... so this is the implication of OOPS!

// Classes and Objects
// Class : It is a user-defined data type!
// Objects : Instance of a class!
// So aise samajhlo ki jab hum koi int a; ko use krke ek variable and uska ek data type bnaate hai, similarly in OOPS we write Hero Ramesh, jisme Hero ek class hai jisse hum Ramesh naam ke object ka data type define kr rhe hai, mtlb ki Ramesh jo hai vo ek Hero type ka entity hai!
// So you can say that Class is the Data Type and Object is like the Variable!
// Lets code...
#include<iostream>
using namespace std;

class Hero {
    // iss class ki help se jo bhi objects hum banayenge ye unki properties hongi! for now its only health!
    int health;
};

int main() {
    Hero Utkarsh; // So what we did here is we made an Object (instance of class Hero) Utkarsh jo Hero type ka hai!
    cout<<"Size of Utkarsh : "<<sizeof(Utkarsh)<<endl; // It will output as 4 bytes kyunki Utkarsh jo object hai uski abhi sirf ek hi property hai and that is Health and health is of int type and int occupies 4 bytes!
    // Agar koi property nhi likhi hogi toh output 1 byte ayega kyunki compiler class ki identfication ke kuch nhi toh 1 byte toh memory me store kr hi deta hai!
}
// Now doing this has two ways, yaa toh hum alag se Hero.cpp vaali file create krle and then usko preprocessor directive me daal ke uss Hero.cpp file ko include krle yaa toh explicitly yhi pr class bnaa de! We can do either way, choice is ours!
// Now if you want to access the properties which are technically called Data Members using Objects, you need to use "." operator!

// Let see...
#include<iostream>
using namespace std;

class Hero {
    int Health;
    int Age;
};

int main() {
    Hero Utkarsh;
    // cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl; // They will give errors becoz right now they are private data members! we need to make them public to access them.. but lets first study the Access Modifiers in OOPS
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl;
}

// Access Modifiers!
// They are used to define the scope of Data Members, ki kisi data member ko hum kahaa pr access kr payenge, kya sirf class ke andar hi access kr payenge ya class ke bahar bhi yaa kisi aur class ke andar bhi and all...
// Their are three types of Access Modifiers : Public, Private and Protected!
#include<iostream>
using namespace std;

class Hero {
    private : // by default vaise bhi private hi rehte hai!
    int Health;
    public :
    int Age;
};

int main() {
    Hero Utkarsh;
    // cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl;
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl; // Age se pehle public likhne se age class ke bahar bhi accessible hogya but health abhi bhi private hi hai kyunki public neeche likha hua hai uske! by default saare private hote hai!
}
// Even agar hum koi function bhi bnaa dete hai class ke andar toh usko bhi hum private ya public ya protected bnaa sakte hai, jo private hoga vo sirf class ke andar hi access kiya jaa sakta hoga, public class ke bahar bhi access kiya jaa sakta hoga!

// Now suppose hum chahte hai ki kuch data members ko private rakhte hai but still hum unko access krna chahte hai int main me, toh for that we use Getter and Setter functions!
// These functions are created withing the public scope and can be accessed using "." operator!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health; // Now as health is private toh ab health ko directly access nhi kr sakte! so we need to create getter and setter functions for it in the public scope of the class, so lets do it!
    public :
    int Age;
    int Level;
    char Name;
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    Hero Utkarsh;
    Utkarsh.sethealth(100); // Even tho health is a private member we are able to set the value of Health using the setter function!
    cout<<"Utkarsh's health is : "<<Utkarsh.getHealth()<<endl; // Printed the value of Health using the getter function we have created inside the class
    
    Utkarsh.Age = 21;
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl;

    // Lets calculate size of the data members...
    cout<<"Size of Utkarsh : "<<sizeof(Utkarsh)<<endl; // this is showing the size : 16 jabki dekha jaye toh 13 aani chahiye, kyunki Health + Level + Age = 12, and then Name is of one byte so it should be 13, but answer is 16 aisa kyu? so aisa isliye beoz of Padding and Greedy alignment!
    // Padding : Padding involves inserting empty bytes between the members of a structure or class to ensure that each member is properly aligned in memory. The goal of padding is to ensure that each data member starts at an address that's a multiple of its size, which can improve memory access performance, especially on architectures that require aligned memory accesses.
    // Alignment : Alignment refers to the requirement that data types should start at particular memory addresses. For example, many architectures require that int variables start at memory addresses that are multiples of 4 (for 32-bit integers) or 8 (for 64-bit integers). Similarly, char variables can usually start at any address. Alignment can be influenced by the size of the data type. For example, if an int requires 4-byte alignment, and a char requires 1-byte alignment, the compiler may insert padding bytes between the members of a structure to ensure proper alignment.
    // Greedy Alignment : Greedy alignment is a strategy used by some compilers to minimize padding. In greedy alignment, the compiler tries to align each member of a structure or class to the largest alignment requirement of any member in the structure. This strategy helps reduce padding by minimizing the number of empty bytes inserted between members.
}

// Static and Dynamic Allocation!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health;
    public :
    int Age;
    int Level;
    char Name;
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    // Statically Created Object!
    Hero Utkarsh1;
    // Here we can use the normal syntax to print its properties!
    Utkarsh1.Level = 69;
    Utkarsh1.sethealth(100);
    cout<<"Level : "<<Utkarsh1.Level<<endl;
    cout<<"Health : "<<Utkarsh1.getHealth()<<endl;


    // Dynamically Created Object!
    Hero *Utkarsh2 = new Hero; // Jaise normally krte the vaise hi yahaa bhi kr rhe hai! isse heap me ek mere compiler ke according 4 byte ki memory allocate hogyi hogi jisme Utkarsh naam ke ek pointer ka address store hoga! and agar mera compiler 64 bits ka hota toh 8 bytes ki memory heap me allocate hoti! abhi 32 bits ka hai isliye bss 4 bytes ke memory hi allocate hoti hai heap me!
    (*Utkarsh2).Level = 69;
    (*Utkarsh2).sethealth(100);
    cout<<"Level : "<<(*Utkarsh2).Level<<endl;
    cout<<"Health : "<<(*Utkarsh2).getHealth()<<endl;

    // Another way dynamic vaali values print krne ka is...using "->" arrow operator, ye sirf dynamic ke time hi krna hai!
    cout<<"Level : "<<Utkarsh2->Level<<endl;
    cout<<"Health : "<<Utkarsh2->getHealth()<<endl;
}

// Now the thing is jab bhi koi object create hota hai tab ek constructore call hota hai sabse pehle and that is ObjectName.Class() kuch iss type ka constructor call hojaata hai automatically isko we call Default Constructor!
// These constructors work behind the scene zaruri nhi ki hum inko class me banaye but if banana chahte hai toh bnaa bhi sakte hai!
// Now ye jo constructors hote hai inka koi return type nhi hota! and koi input parameter nhi hota!
// Default Constructor! 
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health;
    public :
    int Age;
    int Level;
    char Name;
    Hero() {
        cout<<"Constructor Called!"<<endl;
    }
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    // Statically Created Object
    Hero Utkarsh; // Jaise hi hum iss object ko create krenge vaise hi default constructor call hojayega, agar humne explicitly class me nhi bnaaya hua koi default constructor then compiler ne jo default constructor background me banaya hua hai vo call hojayega pr usko koi effect nhi dikhega,
    // but agar hum koi apna khud ka default constructor bnaate hai toh jo pehle vaala constructor hai ye naya vaala usko replace krdega! and iss naye vaale ka effect dekhne ke liye we can use the cout statement! ki jaise hi object creation hua vaise hi constructor call hogya!

    // Dynamically Created Object
    Hero *Utkarsh1 = new Hero; // Dono hi case me same constructor call hoga! kyunki class toh same hi hai dono objects ka!
    // Hero *Utkarsh2 = new Hero(); // Aise bhi likh sakte hai
}
// Also agar ek baar default constructor bnaa diya toh usko hataoge toh ab error show krega kyunki jo compiler vaala tha vo khatam ho chuka hai once you have created your own constructor, so you have to keep it now!

// Parameterized Constructor! and "This" keyword!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health;

    public :
    int Age;
    int Level;
    char Name;
    
    // Hero(int Health) {
    //     Health = Health; // In such cases it causes confusion ki kis health ko kidhar daalna hai, so for that we use a "this" keyword, where "this" is a pointer that stores the address of the current object! so this is how we use it...
    // }

    Hero(int Health) {
        this -> Health = Health; // So agar kabhi parameterized constructor me jo paramter hum pass kr rhe hai and jiss data member ka use kr rhe hai dono ka name same hai toh in that case we use "this" keyword taaki ye btaa sake ki konsa variable object ka hai and konsa ek paramter hai!
        // so writing this we can see "this" keyword is used on the "Health" on left side of assignment operator which tells that left vaala object ka data member hai and right vaala paramter hai!

        // "this" ka bss yhi kaam hai ki confusion khatam krna ki konsa name kiska hai... hum chahe toh different names bhi use kr sakte hai but just telling ki agar same names use krna chahte hai toh ye "this" operator use kr sakte hai...
        // Overall "this" is a pointer which stores the address of the current object!
        // Current Object : When you create instances of a class, each instance is an object with its own set of data members and member functions. When you call a member function on an object, that object becomes the "current object" within the context of that function call.
    } // yahaa iss this -> Health ki help se hum bss ye kehna chah rhe hai ki jaise maanlo current object hai Utkarsh and usne iss constructor ko call kiya toh curent object Utkarsh ban gya hai toh ab jab iss constructor ke paas jab request ayegi tab ye aise hoga ki This Utkarsh ki Health ke andar jo paramter me di gyi value hai vo daal do!
    
    Hero() {
        cout<<"Constructor Called!"<<endl;
    }
    
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
}; // Here it was the explaination of this and parameterized constructor! lets code it properly!

#include<iostream>
using namespace std;

class Hero1 {
    private :
    int Health;

    public :
    int Age;
    int Level;
    char Name;

    Hero1(int Health) {
        cout<<"Address of this : "<<this<<endl;
        this -> Health = Health;
    }

    Hero1() {
        cout<<"Constructor Called!"<<endl;
    }
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    Hero1 Utkarsh(100); // This object will call the paramterized constructor!
    cout<<"Address of Utkarsh : "<<&Utkarsh<<endl; // <- this and "cout<<"Address of this : "<<this<<endl;" both are giving the same output!
    Hero1 Utkarsh2; // This Object will call the default constructor! Thing is agar tumne koi default object bnaya hua hai and tumne agar pehle se compiler vaale constructor ko hataa ke apna koi constructor nhi banaya toh koi error nhi aayega! but agar tumne ek baar apna default constructor banaa diya! toh vo pehle vaala default constructor toh hatt gya! and ab jab bhi tum koi default object banaoge and then tum agar Default constructor hataate ho tab error show krega!
    // Pehle toh chalo theek tha default object banao ya naa banao, compiler ka default ka constructor sambhal le rha tha! but jaise hi tumne koi default constructor bnaa diya and tumhara koi default object bnaa hua hai... and ab agar tum vo default constructor hataoge tab error show krega!
    // means default constructor ko default object ke hone ya naa hone se fark nhi padta but default object ke liye ek default constructor hona zaruri hai!
} // Passing multiple paramters in parameterized constructor is also possible, we can use "this" for both the paramters also jo pass hue hai uss constructor me! 

// Copy Constructor!
// This constructor is used to copy objects!.. ek compiler ka khud ka copy constructor hota hai! agar hum apna explicitly create nhi krte hai toh vo default me jo ek compiler ka copy constructor rakhaa hua hai bg me vhi call hojaata hai jab bhi hujm objects copy krne ka try krte hai!
// A copy constructor is a member function that initializes an object using another object of the same class. In simple terms, a constructor which creates an object by initializing it with an object of the same class, which has been created previously is known as a copy constructor.
// Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.
// The copy constructor can be defined explicitly by the programmer. If the programmer does not define the copy constructor, the compiler does it for us.
// Toh chalo abhi we are defining our own copy constructor and using it to copy one object to another!
#include<iostream>
using namespace std;

class Hero2 {
    private :
    int health;

    public :
    int level;
    int age;

    Hero2(Hero2& old_obj) { // Here we use & to avoid ambiguity! Using & ensures that you're working with the original object rather than a copy. If you don't use &, the copy constructor would be called to create a copy, and any modifications made within the copy constructor would only affect the copy, not the original object.
        health = old_obj.health;
        level = old_obj.level;
        age = old_obj.age;
    }

    Hero2(int health, int age, int level) {
        this -> health = health;
        this -> age = age;
        this -> level = level;
    }

    void display() {
        cout<<"Health of the object : "<<health<<endl;
        cout<<"Age of the object : "<<age<<endl;
        cout<<"Level of the object : "<<level<<endl;
    }
};

int main() {
    Hero2 old_obj1(100,21,69); // Created and intiallized an object using a paramterized constructor! agar default hota toh hume sab values alag alag initiallize krni padti!
    Hero2 new_obj1(old_obj1); // Copies the old object into the new one! agar khud se apna copy constructor nhi create krenge toh compiler khud ka copy constructor call krdega agar hum object aise copy krne ka try krenghe toh! khud ka create krne ka yhi fayeda hota hai ki hum thora customize kr sakte hai ki hum kaise copy krna chahte hai object ko!

    old_obj1.display();
    new_obj1.display();
}

// Now lets understandd deep and shallow copy constructors!
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Hero3 {
    private :
    int health;

    public :
    int level;
    int age;
    char *name; // Here we are trying to allocate the memory for name dynamically, vo kaise? vo aise ki hum name ko intizallize default constructor me karayenge! taaki jab object create ho tab hi name ke liye memory allocate aur vo bhi dynamically!

    Hero3() {
        cout<<"Default constructor called!";
        name = new char[100];
    }

    void setterFunc(char name[], int health, int level, int age) { // Created the setter function, kuch nhi bss jo cheeze pehle hum alag alag likh rhe the unn sabko ek me hi likh diya setter function bnaa ke!
        strcpy(this->name,name);
        this->health = health;
        this->level = level;
        this->age = age;
    }

    void getterFunc() { // Did the same with the getter function!
        cout<<endl;
        cout<<"[ Name : "<<name<<", ";
        cout<<"Health : "<<health<<", ";
        cout<<"Level : "<<level<<", ";
        cout<<"Age : "<<age<<" ]"<<endl;
    }
};

int main() {
    Hero3 hero1;
    char name[] = "Utkarsh";
    hero1.setterFunc(name, 100, 69, 21); // So here we have set the details for our object 1 which is hero1!
    hero1.getterFunc();

    // Now lets create a copy of this object! using default copy constructor!
    Hero3 hero2(hero1); // Poora ka poora hero1, hero2 me copy hogya as it is...
    hero2.getterFunc(); // Humne usko print bhi karaa liya!

    // Now lets change the name in the hero1...
    hero1.name[1] = 'S'; // humne ye chhota sa change kiya hero1 ke name me... and now lets print it...
    hero1.getterFunc(); // And its name is printing Stkarsh... jo ekdum sahi hai kyunki humne yhi changes kiye hai... but now comes the interesting part...
    hero2.getterFunc(); // hero2 me bhi name change hogya hai!! jabki humne name me changes sirf hero1 me kiye the!
    // So this is called shallow copy!...toh jo humara default copy constructor hota hai vo ek shallow copy constructor hota hai!
    // Lets understand aisa kyu hua!
    // Jab humne name me Utkarsh store kiya toh, "Utkarsh/0" store hua memory me, and then humne class me jo name banaya vo ek pointer ki help se banaya and and vo name hi as a data member humne dono objects me daale hai, toh jo dono objects bane hai unme 4 data members ke liye space bani hui hai jaise name, health, age, level... ab jo name vaali space hai usme toh name variable ka address stored hai na! and jab copy bhi hua object toh name ka address bhi copy hui!
    // isliye jab humne name ki value me koi bhi change kiya toh vo change dono objects me reflect hua!
}

// Ab agar ye cheez hone se rokni hai toh usko hum deep copy kehte hai! and hume apne copy constructor ko deep copy banana tha!
// so we need to do the changes in the copy constructor's defintion!
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Hero3 {
    private :
    int health;

    public :
    int level;
    int age;
    char *name;

    Hero3() {
        cout<<"Default constructor called!";
        name = new char[100];
    }

    // Creating a copy constructor which will perform the deep copy! this will over write the default copy constructor which was doing the shallow copy!
    Hero3(Hero3& temp) { // Uss shallow copy se bachne ke liye what this will do is ki ye jo name vaali array thi uska bhi ek copy bana dega object copy krte time, isse jo bhi changes hum krenge ek object ke name vo dusre object ke name me carry forward nhi honge, kyunki dono ke liye apne apne name vaale array separate hogye hai! pehle dono ke liye changes same hi array me ho rhe the!
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->age = temp.age;
        this->level = temp.level;
    }

    void setterFunc(char name[], int health, int level, int age) {
        strcpy(this->name,name);
        this->health = health;
        this->level = level;
        this->age = age;
    }

    void getterFunc() {
        cout<<endl;
        cout<<"[ Name : "<<name<<", ";
        cout<<"Health : "<<health<<", ";
        cout<<"Level : "<<level<<", ";
        cout<<"Age : "<<age<<" ]"<<endl;
    }
};

int main() {
    Hero3 hero1;
    char name[] = "Utkarsh";
    hero1.setterFunc(name, 100, 69, 21);
    hero1.getterFunc();

    Hero3 hero2(hero1);
    hero2.getterFunc();

    // Dono me se kisi bhi object ke name ya kisi aur data member (property) me koi bhi changes kroge toh vo dono object me show krenge! shallow copy constructor ke case me!
    // But agar tum yhi Deep copy kroge toh jisme jo change kroge vo change sirf usme hi reflect hoga!
    hero1.name[1] = 'S';
    hero1.getterFunc();
    hero2.getterFunc();

    hero2.name[2] = 'K';
    hero1.getterFunc();
    hero2.getterFunc();
    // So from this example both deep and shallow copy constructors are clear!
}

// Use of Copy Assignment operator! : Agar do object create ho chuki hai and dono me se kisi ek ko dusre me copy krna hai tab we use this operator, copy constructor me kya tha ki ek object create ho chuki hai dusra object bss create hua hai but initiallize nhi and hume pehle vaali ko dusre me copy krna hai then we use that, but here dono initialize ho rakhe hai and humne bss ek ko dusre me copy krna hai!
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Hero3 {
    private :
    int health;

    public :
    int level;
    int age;
    char *name;

    Hero3() {
        cout<<"Default constructor called!";
        name = new char[100];
    }

    void setterFunc(char name[], int health, int level, int age) {
        strcpy(this->name,name);
        this->health = health;
        this->level = level;
        this->age = age;
    }

    void getterFunc() {
        cout<<endl;
        cout<<"[ Name : "<<name<<", ";
        cout<<"Health : "<<health<<", ";
        cout<<"Level : "<<level<<", ";
        cout<<"Age : "<<age<<" ]"<<endl;
    }
};

int main() {
    Hero3 hero1;
    char name[] = "Utkarsh";
    hero1.setterFunc(name, 100, 69, 21);
    hero1.getterFunc();

    char name2[] = "Palak";
    Hero3 hero2;
    hero2.setterFunc(name2, 100, 70, 22);
    hero2.getterFunc();

    // So after creating and initiallizing both the objects we are just going to assign one to another...
    hero1 = hero2; // Ab hero1 me hero2 ki saari values copy hogyi hai!
    hero1.getterFunc(); // Output of hero1 will be the output of hero2 kyunki hero2 ki values humne saari hero1 me copy krdi hai!
}

// Destructors : To de-allocate memory! it frees the memory jab object ka life span khatam hone vaala hota hai!
// Class create hote hi ye bhi create hojaata hai...
// Like suppose jaise upar vaale examples ke case me jo jo objects create hue hai vo sab jaise hi int main ka scope khatam hone vaala hoga usse pehle destructors call hojaate hai and vo memory ko free kr dete hai!
// Same as class name, no return type and no input parameter!
// Ye already class create krte hi ban jaate hai but agar chahte hai toh khud ke destructor bhi bnaa sakte hai!
// lets see an example...
#include<iostream>
using namespace std;

class Hero4 {
    private :
    int age;

    public :
    int health;

    // Constructor :
    Hero4() {
        cout<<"Constructor Called!"<<endl;
    }

    ~Hero4() {
        cout<<"Destructor Called!"<<endl;
    }
};

int main() {
    // Object created statically!
    Hero4 Utkarsh;

    // Object created dynamically!
    Hero4 *Utkarsh1 = new Hero4;
    // Here we will notice one thing that static objects ke liye constructor automatically call hojaata hai but dynamic ke liye hume alag se manually krna padta hai for that we need to do it manually!
    delete Utkarsh1; // This is to call the destructor for the dynamically created object
    // Kyunki agar ye nhi likhte toh static vaale ke liye ek baar constructor call hua and ek baar destructor, but dynamically ke case me sirf ek baar constructor call hua, destructor ko call krne ke liye we need to write delete object_name; taaki destructor bhi call hojaye!
}

// Static Keyword :
#include<iostream>
using namespace std;

class Hero5 {
    private :
    int age;

    public :
    int health;
    static int timeToComplete; // This keyword is used for those data members jo poore class ke liye same rehne vaale hai, jaise maanlo ek game hai usme time to complete kisi bhi object enemy ya hero ke liye same hi hone vaala hai! toh aise datam members ke liye hum static keyword use krte hai! to initiallize them we write this outisde the class, [datatype of static data member] [Class Name] :: [Static Data member name] = [Value]

    // Constructor :
    Hero5() {
        cout<<"Constructor Called!"<<endl;
    }

    ~Hero5() {
        cout<<"Destructor Called!"<<endl;
    }
};

int Hero5 :: timeToComplete = 5; // So here we have initialized it!
// Now ab isko access krne ke liye hume kisi object ki zarurat nhi hoti hai!

int main() {
    cout<<Hero5::timeToComplete<<endl; // It will print 5

    Hero5 h1;
    cout<<h1.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!

    Hero5 h2;
    h2.timeToComplete = 10; // Humne time to complete change krdiya ab, aur ab ye change jab hua hai toh ye poori class ke liye change hua hai!
    cout<<h1.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!
    cout<<h2.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!
}

// Static Functions : Same as static data members, this is also for the class not for the objects... objects bhi access kr sakte hai but hoti hai ye mainly class ke liye hai!
// Isme koi this keyword nhi hota kyunki this keyword ka kaam hi hai current object ko point krna pr yahaa toh object hi nhi hai isliye ye kisi kaam ka nhi static functions me!
// And static functions sirf static data members ko hi access kr sakte hai!
#include<iostream>
using namespace std;

class Hero5 {
    private :
    int age;

    public :
    int health;
    static int timeToComplete; // This keyword is used for those data members jo poore class ke liye same rehne vaale hai, jaise maanlo ek game hai usme time to complete kisi bhi object enemy ya hero ke liye same hi hone vaala hai! toh aise datam members ke liye hum static keyword use krte hai! to initiallize them we write this outisde the class, [datatype of static data member] [Class Name] :: [Static Data member name] = [Value]

    static int func() {
        // cout<<this->age<<endl; // this will throw error, kyunki naa toh yahaa this ka koi kaam aur naa hi age ka kyunki vo koi static data member nhi hai!
        // cout<<health<<endl; // Same here also...
        return timeToComplete; // This will work kyunki ye ek static data member hai!
    }

    // Constructor :
    Hero5() {
        cout<<"Constructor Called!"<<endl;
    }

    ~Hero5() {
        cout<<"Destructor Called!"<<endl;
    }
};

int Hero5 :: timeToComplete = 5;

int main() {
    cout<<Hero5::timeToComplete<<endl;
    cout<<Hero5::func()<<endl;
    // Both will print 5
}

// ---------------------------------------------------------- LECTURE 43 - OOPS Part 2 --------------------------------------------------------------------------------------------------------->
// OOPS has 4 pillars : Encapsulation, Inheritence, Polymorphism and Data Abstraction!
// Encapsulation : Encapsulation is combining all the data members and functions in one single entity which we called class!
// Ek Dawai ki capsule me kaafi saari dawai ki gloiyan hoti hai toh bss vaisa hi maanlo, ki vo dawai ki goliyan Data Members and Functions hai...and uss dawai ki capsule ko hi hum class bolte hai!

// Fully Encapsulated Class : Where all of its Data Members are set Private! and can be accessed within the class only! Class ke Functions/Methods public ho sakte hai, but Data Members agar saare Private ho toh tab usko fulle encapsulated kehte hai!
// In short Encapsulation is called Data Hiding, dont confuse it with Data Abstraction as Data Abstraction is Implementation Hiding!

// Advantages : Data Hiding ke kaaran Security badh jaati hai!
//            : If we want we can make our class Read-only vo aise ki hum koi setter naa banaye toh koi bhi usko change nhi kr payega! isliye the class which will be having only getter will be a Read-only class!
//            : Increases Code Reusability
//            : Encasulation helps in unit testing!
// Lets see an example and how we implement encapsulation, its nothing like big task...jo abhi tak hum krte aa rhe the vo encapsulation tha!
#include<iostream>
#include<cstring> // for strcpy
using namespace std;

class Student{
    private :
    char *Name;
    int age;
    int marks;

    // Student() { // Don create constructor in private kyunki object createion ke time ye call hota hai toh private hone ke kaaran ye call hi nhi ho payega, isliye isko ya kisi bhi function humaesha public rakhna chahiye!
    //     cout<<"Constructor called!";
    //     Name = new char[100];
    // }

    public :
    Student() {
        cout<<"Constructor called!"<<endl;
        Name = new char[100];
    }

    void setterfunc1(char Name[], int age, int marks) {
        cout<<"setter function called"<<endl;
        strcpy(this->Name, Name);
        this->age = age;
        this->marks = marks;
    }

    void getterfunc1() {
        cout<<"getter function called"<<endl;
        cout<<"Name : "<<Name<<" ";
        cout<<"Age : "<<age<<" ";
        cout<<"marks : "<<marks<<" ";
    }
};

int main() {
    Student Utkarsh;
    char name[] = "Utkarsh";
    Utkarsh.setterfunc1(name,21,95);
    Utkarsh.getterfunc1();
}
// Overall this is all encapsulation only, jo bhi abhi tak lecture 42 me kr rhe the vo sab encapsulation hi hai!

// Inheritance! : Jab kisi ek class ki koi property koi aur class inherit krleti hai toh usko hum inheritance kehte hai!
// Lets understand it with code...
#include<iostream>
using namespace std;

class Human {
    public :
    int height;
    int weight;
    int age;

    void setterFunc1(int height, int weight, int age) {
        this->height = height;
        this->weight = weight;
        this->age = age;
    }

    void getterFunc1() {
        cout<<"Height : "<<height<<endl;
        cout<<"Weight : "<<weight<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

class Male : public Human { // here this is the syntax to inherit one class from other, [class child_class_name : access_modifiers parent_class_name] jo class inherit krti hai that is child and jahaa se inherit krti hai that is parent!
    public :
    int salary;

    void setterFunc2(int salary) {
        this->salary = salary;
    }
    void getterFunc2() {
        cout<<"Salary : "<<salary<<endl;
    }

};

int main() {
    // Human H1; // Is object ke liye toh parent class ke saare data members use honge but ye class child class ke data members access nhi kr payega
    Male Utkarsh;
    // Utkarsh.age = 21;
    // Utkarsh.height = 170;
    // Utkarsh.weight = 70;

    // Utkarsh.salary = 5000000;
    // Ye cheeze upar vaali hum setter function se bhi set kr sakte hai...
    Utkarsh.setterFunc1(170,70,21);
    Utkarsh.setterFunc2(5000000);

    Utkarsh.getterFunc1();
    Utkarsh.getterFunc2();
}
// Now what happened is, ki humare pass classes thi do ek Human jo ek parent class thi and Male jo ek child class thi... ab dono classes ke apne apne data members and member function the... jab hum male me Human ko inherit karwaya toh Human ki jitni bhi properties thi vo sab inherit hogyi child class ke liye! and now child class ka koi bhi object parent class ke kisi bhi data members ya member function ko use kr sakta hai!

// In the above case our mode of inheritance was public and jin data members ko acess kr rhe the vo bhi public hi the isliye koi dikkat nhi aayi!
// But there will be some complications agar base class ke data members ka access modifier private ya protected hua toh...
// so for that remember this table...
// Access Modifier of base clas     |       Mode of inheritance
//      Public                                      Public          ->       Public
//      Public                                      Private         ->       Private
//      Public                                      Protected       ->       Protected
//      Protected                                   Public          ->       Protected
//      Protected                                   Private         ->       Private
//      Protected                                   Protected       ->       Protected
//      Private                                     Public          ->       Not Possible
//      Private                                     Private         ->       Not Possible
//      Private                                     Protected       ->       Not Possible
// Private data member of any class cannot be inherited!

// What is Protected Access Modifier? So basically it is more of less similar to Private, it can be access withing the class, the only difference is ki jab aap inheritence use kroge tab ye protected data member child class bhi access kr sakta hai! but private ke case me aisa nhi hai! This is the only difference!
// Ab baaki toh we know ki hum private public ya protected teeno ko hi member functions bnaa ke access kr sakte hai and then unn member functions ko use kr krke hum objects ke saath use kr sakte hai! jo abhi tak krte bhi aye hai!

// Tyoes of Inheritance!
// Simple | Multiple | Multi-Level | Hierarchial | Hybrid Inheritances!

// Single Inheritance : Jab koi ek class dusre class ke properties ko inherit krle! Like class B ne class A ki properties ko inherit krliya! then it is Single Inheritance!
// Above example of Human and Male is of Single Inheritance!
// Lets see example :
#include<iostream>
using namespace std;

class Animal { // Base class!
    public :
    int age;
    int weight;

    void speak() {
        cout<<"Speak!"<<endl;
    }
};

class Dog : public Animal { // Child class inheriting base class Animal!
    public :
    void speakDog() {
        cout<<"Bark!"<<endl;
    }
};

int main() {
    Dog d1;
    d1.speak();
    d1.speakDog();
} // So here we have used single inheritance!

// Multi-Level Inheritance : Jab E class D class ko inherit kre and D class C class ko and C class B class ko and B class A class ko!
// Lets see example...
#include<iostream>
using namespace std;

class Animal { // Base class!
    public :
    int age;
    int weight;

    void speak() {
        cout<<"Animals can Speak!"<<endl;
    }
};

class Dog : public Animal { // Child class inheriting base class Animal!
    public :
    void speakDog() {
        cout<<"Dogs Bark!"<<endl;
    }
};

class GermanShephard : public Dog {
    public :
    void Color() {
        cout<<"German Shephard has Yellow color with Black stripes!"<<endl;
    }
};

int main() {
    GermanShephard GS1;
    GS1.speak();
    GS1.speakDog();
    GS1.Color();
    // Here we can see the German Shephard class can access all the higher level classes becoz due to inheritance between its higher level class it got functionalities of all the highesr level classes
}

// Multiple Inheritance : When a class inherits more than 1 classes! Like suppose there is class C and it is inheriting 2 classes A and B, this is multiple inheritance!
// Lets see example...
#include<iostream>
using namespace std;

class Animals { // Base class!
    public :
    int age;
    int weight;

    void cantSpeak() {
        cout<<"Animals can't Speak!"<<endl;
    }
};

class Humans { // Base class!
    public :
    int age;
    int weight;

    void speak() {
        cout<<"Humans can Speak!"<<endl;
    }
};

class Mix : public Animals, public Humans {
    // Isme kuch likha nhi zarurat nhi abhi abhi bsss samjhaane vaala kaam chal rha hai! agar koi iska apna function ya data members bnaa denge toh vo bhi Mix ke kisi objects ka banake use kr sakte hai
};

int main() {
    Mix m1;
    m1.speak();
    m1.cantSpeak();
} // So here this is example of Multiple Inheritance...
// Now thing is yahaa ye sab code likhne me thore error aa rhe hai kabhi kabhi isliye names of variable and function and class change krna pad rha hai kyunki yahaa pr ab bhot saari classes ban gyi hai and sabka scope poore code me hai! toh isliye vo thora understand krna revision ke time!
// Uss errors ko handle krne ke liye hi yahaa functions classes and data members ke names change krna pad rha hai!

// Hierarchial Inheritance : Here ek base class hota hai uski properties more than one classes inherit kr rhe hote hai! Multiple ke case me ek class ek se zyada ki properties inherit kr rha tha yahaa just opposite!
// Lets see...
#include<iostream>
using namespace std;

class A {
    public :
    void func1() {
        cout<<"Inside Function 1"<<endl;
    }
};

class B : public A {
    public :
    void func2() {
        cout<<"Inside Function 2"<<endl;
    }
};

class C : public A {
    public :
    void func3() {
        cout<<"Inside Function 3"<<endl;
    }
};

int main() {
    A obj1;
    obj1.func1(); // Calling its own function

    cout<<endl;

    B obj2;
    obj2.func1(); // Calling base class function
    obj2.func2(); // Calling its own function

    cout<<endl;

    C obj3;
    obj3.func1(); // Calling base class function
    // obj3.func2(); // Ye possible nhi ho payega kyunki B and C me koi relation nhi hai!
    obj3.func3(); // Calling its own function
}

// Hybrid Inheritance : Combination of more than one type of inheritance!
// lets see...
#include<iostream>
using namespace std;

class D { // Base class, which is doing hierarchial inheritance
    public :
    void funcD() {
        cout<<"Inside D class!"<<endl;
    }
};

class E { // Base class
    public :
    void funcE() {
        cout<<"Inside E class!"<<endl;
    }
};

class F : public D { // Class F doing Single Inheritance of class D
    public :
    void funcF() {
        cout<<"Inside F class!"<<endl;
    }
};

class G : public D, public E { // Class G multiple inheritance of class D and F
    public :
    void funcG() {
        cout<<"Inside G class!"<<endl;
    }
};

int main() {
    D d1;
    d1.funcD();

    cout<<endl;

    E e1;
    e1.funcE();

    cout<<endl;

    F f1;
    f1.funcD();
    f1.funcF();

    cout<<endl;

    G g1;
    g1.funcD();
    g1.funcE();
    g1.funcG();
} // So here we can see there are different types of inheritance are perfoming at once, so it is called Hybrid Inheritance!

// Inheritance Ambiguity : Jab do classes ko kisi child ke dwara inherit kiya jaata hai and unn dono base classes me kisi member function ya data member ka name same hai and ab jab child class uss funtion ya data member ko use krne ka try krega toh compiler will get confuse ki konsa function ki baat ho rhi!
// So to solve this ambiguity we use "::" scope resoltion operator!
// Lets see...
#include<iostream>
using namespace std;

class H { // Base class
    public :
    void func() {
        cout<<"Inside H class!"<<endl;
    }
};

class I { // Base class
    public :
    void func() {
        cout<<"Inside I class!"<<endl;
    }
};

class J : public H, public I {
    public :
    void func() {
        cout<<"Inside J class!"<<endl;
    }
};

int main() {
    J j1;
    // j1.func(); // This will throw error kyunki this is ambigous or can say it is confusing ki kiske func() function ki baat ho rhi hai!.. so we need to use cope resoltion operator!
    j1.H::func();
    j1.I::func();
    j1.J::func();
    // j1.func(); // Agar sirf ye likhoge toh J class ka func() vaala function call hojayega, this is method over riding which we are about to study in runtime polymorphism
} // Ambiguity Resolved! using scope resolution operator!

// Now the thing is OOPS are used a lot in industries!! but jo abhi hum padh rhe hai ye bhot hi basic level ki OOPS hai, other wise OOPS jo actual use hoti hai usme aur isme zameen aasman ka antar hai!

// Polymorphism! : When one particular thing can have mutltiple forms! like a father can be a father for you but can also be son for his father, a husbanf ofr your mom, a brother for his sister and in a similar way!
// There are two type of Polymorphism! : Compile Time Polymorphism and Runtime Polymorphism!

// Compile time Polymorphism : Isme konsa function kab call hona hai vo decide kiya jaata hai at the compile time! means, it is achieved through function overloading and operator overloading. In compile-time polymorphism, the decision about which function or operator to call is made during the compile-time, based on the types of arguments or operands involved. The compiler resolves the method or function call at compile-time.
// It is also called Static Polymorphism!
// Lets see...
#include<iostream>
using namespace std;

class K {
    public :
    void sayHello() {
        cout<<"Hello Utkarsh"<<endl;
    }

    void sayHello(string name) {
        cout<<"Hello "<<name<<endl;
    }

    void sayHello(string name, int age) {
        cout<<"Hello "<<name<<" Your age is "<<age<<endl;
    }

    void SayHello(string name, int age, int height = 0, int weight = 0) { // Isme kya hoga ki iss function ko agar hume access krna hai toh object bnaa ke chaahe 2 arguments pass kro ya chahe 3 yaa chahe 4, teeno hi case me work krega kyunki yahaa humne default arguments use kiye hai!
        cout<<"Hello "<<name<<" Your age is "<<age<<" your height is "<<height<<" your weight is "<<weight<<endl;
    }

    // int sayHello(string name, int age) { // This will show error kyunki yahaa bhi function ko overload toh krne ki koshish kr rhe hai but vo sirf return type change krke and this is not valid, agar function overload krna hai toh vo sirf number of input arguments ya type of arguments ko change krke hi ho sakta hai!
    //     cout<<"Hello "<<name<<" Your age is "<<age<<endl;
    //     return 1;
    // }
}; // So saare functions ka name same hai bss arguments ka number ya type different hai and this is how function overloading works!

int main() {
    K k1;
    k1.sayHello();
    k1.sayHello("Palak");
    k1.sayHello("Kinshuk", 22);
    k1.sayHello("Paresh",21); // height and weight nhi daala fir bhi work krega! this is becoz of default arguments!
} // So this is Function overloading in compile time polymorphism, ki yahaa ek hi function ke multiple forms exists! and compile time me hi decide ho rha hai arguments ka type and number dekh ke hi decide ho rha hai ki konsa function call hona hai!

// Operator overloading : Jaise we know + jo operator hai vo addition toh krta hi hai string ke case me concat bhi krta hai but hum chah rhe hai ki hum apne liye Hello bhi bulwaye jab bhi + operator call ho, logically it wont make sense, but just telling ki we want it to do this!
// Lets see...
// Chalo hum chahte hai ki + operator se - karwaye! logically it wont make sense but we are just using the operator overloading!
#include<iostream>
using namespace std;

class L {
    public :
    int a, b;

    void operator+ (L &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"Output : "<<value2 - value1<<endl;
    }

    void operator() () {
        cout<<"Inside the bracket function! "<<this->a<<endl; // Mtlb ki jab bhi bracket call ho, tab ye cout print krdena and jis obj ne call kiya ye uski a ki value print krdena!
    }
};

int main() {
    L obj1, obj2;
    obj1.a = 5;
    obj2.a = 12;

    obj1 + obj2;
    // + is a binary operator hai toh uske liye ye matter krta hai ki right left me konsa operand hai
    // toh humne yahaa obj1 ko left operand bnaa diya and obj2 ko right... now ab jo + ke case me jo operand right me hota hai vo as a inout pass hota hai operator overloading me and jo left me hota hai vo current object hota hai ,tlb ki uss object ke liye humari function hui hoti hai!
    // means jab obj1 + obj2 likha humne, toh ye hua ki obj1 ne function call ki toh is kaaran se value1 me this->a jo likha hai vo usme obj1 ki value store ho rhi hai becoz we have used "this" and this points to the current object and current object is obj1 kyunki vo left me likha hua hai!... and value2 me jo obj.a likha hua vo obj2 ki baat ho rhi hai kyunki vo right me likha tha and isliye vo as pa paramter pass hua tha function call me! isliye value2 me obj2 ki value gyi!
    // Toh ab jab bhi + operator call hoga tab uske right and left operands ko dekh ke function call hoga and uske hisaab se - hojayega! 

    obj1(); // Obj1 ne call kiya bracket ko toh output me Inside the bracket function! print hoga and saath saath obj1 ki a value print hojayegi which is 5!
}

// There are some operators which cannot be overloaded! and they are... "::", "*", ".", "?:"

// Runtime Polymorphism : also known as dynamic polymorphism, is achieved through method overriding using inheritance and virtual functions. In runtime polymorphism, the decision about which function to call is made during the runtime, based on the type of object being referred to.
// Lets see...
// When we have different class suppose A and B and we are inheriting properties of A into B means A is base and B is child and they both have a function with same name func() and func() in A says cout<<"Hello" and func() in B says cout<<"Hi", toh hua kya hai ki ek class ne dusre class ko inherit krne ke baad same name ke function ko dusri tarah se implement krdiya!
// This is called Function Overriding or Method Overriding!
// There are some rules... 1) Method of parent and child class should have same names 2) Also both methods in both the classes should have same number of paramters 3) Method overriding is possible thru inheritance only!
// Means Runtime Polymorphism depends on Inheritance!

#include<iostream>
using namespace std;

class M {
    public :
    void display() {
        cout<<"Inside M class"<<endl;
    }
};

class N : public M {
    public :
    void display() { // Here you have done method overiding... agar tum ye function nhi banate toh M vaala hi display function call hojaata kyunki N ne M ko inherit kr rakha hai, pr kyunki humne iss class ke liye N ki khud hi implementation daal di hai display() ki isliye agar N ka object bnaa ke function call krenge toh "Inside N class" print hoga...
        cout<<"Inside N class"<<endl;
    }
};

int main() {
    N obj1;
    obj1.display(); // Here it will print N class's implementation of display()... but if you want to specify ki which display function you want to call then in that case you use scope resolution operator!
    obj1.M::display(); // It will print according to the implementation of display function of M class
}
// Iska use is that ki agar humare paas ek base function hai uske 10 methods hai and then ek sub class hai usko uss base class ke 8 methods as it is use krne hai bss 2 jo uske mthods hai unke iss sub class ko khud ke implementation use krne hai then we use this method over riding!

// Data Abstraction : It is called Implementation Hiding! jo essential cheeze hai vo dikhao baaki mtt dikhao jo hume dekhne ki zarurat nhi hai!
// Data Abstraction can be achieved using Private Public Protected access specifiers!
// Advantages : Only you can change to your data and no one ele can! it makes application more secure by not allowing anyone else to see the background details! increase the reusability of the table! Avoid duplication of data!
