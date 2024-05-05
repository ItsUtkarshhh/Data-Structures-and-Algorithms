// ---------------------------------------------------------- LECTURE 44 - Linked Lists and Its Types --------------------------------------------------------------------------------------------------------->
// Linked List is a data structure which is a collection of nodes, and a node is a combination of a data + address of next node!
// Now why we need it? so problem is can we change the size of an array at the runtime? No we can't, similarly can we change the size of vector during the runtime? Here in case of vectors we can do this but the problem is yahaa pr jaise vector crrate kiya humne and now ab jab runtime me agar hum size maanlo 5 se 10 krna chahenge toh pehle toh ek alag se vector banega of size 10 and then pehle vaale vector ki values copy hojayengi! and this is not feasible for large vectors!
// Even arrays ko bhi dynamically initiallize krke with the new keyword we can change its size during the runtime... but again the problem arises in processing and memory management!
// Also vectors ke case me ye bhi dikkat hai ki maanlo humne size 5 se 10 hogya pr hume bss itni jagah chahiye thi ki 6 elements store kr paye toh baaki ke 4 blocks waste hogye!

// So to solve this issue we have Linked Lists!
// Properties of LL : Dynamically created! and No memory wastage! and Insertion and deletion operation is easily!
// Also isme continous manner me memory blocks allocate nhi hote, kyunki ab jab nodes me address stored hai next block ka toh ab vo next block kahin pr bhi hum uss next block tak phoch jayenge!

// So it looks like something like this...
// [Value1,Address of next node] -> [Value2,Address of next node] -> [Value3,Address of next node] -> [Value4,Address of next node] -> NULL
// This is the Singly Linkedlist! here the first node is called Head Node and Last Node is called Tail Node!

// Now there are three of its types...Singly, Doubly and Circular!
// Now lets implement it... we will use classes to implement it... as array jaise hote hai na vaise hi hum yahaa LinkedList ko bhi ek keyword ki tarah banaa denge classes ka use krke... kyunki in the end class toh ek template hi toh bnati hai kisi ek data type ka! toh bss hum vhi krenge Linked List ki implementation ke liye
// Now lets see...
#include<iostream>
using namespace std;

// Template created for creation of node!
class Node {
    public :
    int data;
    Node* next;

    Node(int data) { // we have made a constructor so that jab bhi koi node ka object create hota hai toh vaise hi uske andar nodes ki properties aajaye! jo iss implementation me likhi hui hai!
        this-> data = data;
        this->next = NULL;
    }
};

int main() {
    Node* n1 = new Node(10); // Here one node is created dynamically and it is of "Node" type...
    cout<<n1->data<<endl;
    cout<<n1->next<<endl;
    // Above we have created one node and uss node me humne ek value store ki 10 and usko abhi ke liye kahin point nhi karaya hua... toh linkedlist ke percpective se ye node head node bhi hai aur tail node bhi hai...becoz it is pointing towards NULL!
}

// Now ab baat aati hai Linkedlist create krne ki and head ko add krne ki and ek nayi value ko head pr insert krne ki!
// So pehli cheez, that we have made a node already, which will be pointing towards NULL and has nothing stored in it! at the very initial stage! then humne ek node create ki upar vaale implementation se, but ab humko linkedlist bnani hai toh vo uske liye humko aur nodes add krne honge so we will do it from the head!
// So lets write for inserting at the head!

#include<iostream>
using namespace std;
// Toh upar jo humne node create kiya tha vaise hi yahaa bhi krenge... so basically hum kr kya rhe hai ki nodes create kr rhe hai and then unn nodes ko head bnaa de rhe hai vo kaise? jaise maanlo node1 create hua, ab usme toh ek value stored hogi and ek address stored hoga next pointer ka...ab jo node hum create krrenge sabse pehle usme value toh stored hai pr usme address stored hai NULL pointer ka! and then ab jo bhi hum next nodes create krenge unko hum iss previous node ke aage lagayenge..
// kyunki ab jo new node bhi create hoga usme bhi ek value hogi and NULL pointer ka address stored hoga, toh hum bss itna krenge ki jo iss new node me jo NULL pointer ka address stored hai usko NULL se hataa kr previous vaale node ka address store krdenge! and aise we form a linkedlists! and then iss hi same fashion me baaki linkedlist bhi create hogi!
// Now lets implement it....
// And understand it one by one...
class Node2 {
    public :
    int data;
    Node2* next;

    Node2(int data) {
        this->data = data;
        this->next = NULL;
    }
}; // Here we have created a default node, using the constructor! and is constructor ki help se jaise hi koi object banega Node2 ko use krke tab hi hum uss object ko ek node bnaa denge and uska jo "address of the next node" vaala part hai usko default ke liye abhi hum NULL set krdenge!
// Kyunki yahaa pr last node se first node ki taraf jaate hue linkedlist create krne ki koshish kr rhe hai! toh isliye ek tarah se humne jo sabse pehla node banaya hai vo ek tail node hai kyunki iska "next node ka address store" krne vaala jo part hai usme NULL stored hai!
// And yahaa pr this keytword ka use toh samajh aa hi gya hoga ki jo current object jisko node banana chah rhe onge uske hi data and next value ko hum initiate krne vaale hai iski help se!  

void insertatHead(Node2* &head, int data) {
    // Now lets create a new node...
    Node2* temp = new Node2(data); // New node created and a pointer named temp and of type node is used to point on it!
    temp->next = head; // using this temp, the next is pointed on the head, which is currently the previosu node...
    head = temp; // head changed to the new node's head!
} // Now here, what we did is... ab ek first node toh humara create ho chuka hai! so now ab hum ek aur node create krenge jo default hi hoga mtlb usme value toh stored hogi pr vo initially vo bhi NULL ko hi point kr rha hoga...
// Jo humne ye likha hua hai na... "Node2* temp = new Node2(data);" isme humne Node2(data) krke ek aur node banaya jisme humne inputed data daal diya and usko temp naam se point kraa diya! toh as for this moment memory me abhi do nodes honge... ek jo pehle create kiya tha and ek jo ab just is line me create kiya and dono hi NULL ko point kr rhe honge!
// But as soon as we move to next line...temp vaale name se jo node bnaa hai uska jo "next" vaala pointer hai usme humne current head ka address store krdiya! and as of this moment current head is the previous node!
// And now as soon as we move to next line...hum ne temp ke next pointer ko previous head ki taraf point kraa ke head me current temp ka address daal diya! toh mtlb ab head change hogya... and aise linkedlist create hogyi which is having two nodes as of this moment...
// But ab jitni baar hum insertatHead function ko call krte rahenge utni baar new nodes bante rahenge and our linkedlist will keep increasing

void print(Node2* &head) {
    Node2* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    // Iss loop me kya ho rha hai ki temp me humne pehle head ka address daala! then humne loop chalaya and bola ki jab temp ki value NULL hojaye tab looop se bahar aajana! means jab temp me jo address stored hai vo NULL hojaye toh loop se bahar aajaana! so hum baar baar temp me jo data hai usko print kr rhe hai and then temp ko update krde rhe hai with temp->next! isse poori linkedlist print hojaa rhi hai!
    cout<<endl;
} // It starts from the head node and iterates through each node using the next pointer until reaching the end of the list (where next is NULL).

int main() {
    // Now we have used the functions and created the linkedlists!
    Node2* n1 = new Node2(10);
    Node2* head = n1;
    print(head);

    insertatHead(head,12);
    print(head);

    insertatHead(head,15);
    print(head);
}
// So in short and detail the story and the logic is...
// Humne pehle ek default implementation likhi ek node ki that is ek node me ek Data hoga and ek next pointer hoga...and jaise hi hum koi object banaye iss class ka toh vaise hi ek node create hojaye uske liye humne ek constructor banaa diya! and jab humne int main me likha "Node2* n1 = new Node2(10);" toh heap me 4+4 = 8 bytes ki memory is n1 node ko allocate hogyi! 4 byte data ke liye and 4 bytes (mere compiler ke architectire ke kaaran) next node ka address store krne ke liye jo humne next pointer banaya hua hai usme NULL value stored hai! mtlb as of now abhi ye n1 node kahi bhi point nhi kr rha!
// ab ye jo n1 hai ye bhi ek pointer hi hai jo abhi current memory block ka address store kr rha hai! humne iss hi address ko copy krdiya head naam se ek aur pointer bnaa ke (ye humne dekha tha ki kaise pointers copy krte hai!) toh humne head me n1 ka address copy krdiya! now head and n1 dono hi first node ko point kr rhe hai! also memory me bhi n1 and head name se variable ban gye honge! jinme uss first node ka address stored hoga!
// Now, hum print se pehle insertAtHead samajhte hai... so now kya hua ki, humne head ko as reference pass kiya iss function me as an argument! isme hum ye try krne ka koshish kr rhe hai ki ek nayaa node banaye toh uska data toh pass krde and jo next pointer hai vo initially toh becoz of implementation in class NULL ko point kr rha hoga but then hum usko head ki taraf point kraa denge! and ye jo nayaa node banaa hai isko hum ek aur pointer se point karwaa rhe hai which is temp... means temp is a pointer which will store the address of this new node! and humne 3rd line me head ko update krdiya temp se! mtlb now temp is the new head...
// And isliye humne function call me jab bhi nayaa node banaa rhe hai toh head pass kr rhe hai along with data kyunki we know that the current head is changed and head ko refernce leke pass kiya gya hai taaki koi copy na ban jaye!
// Then humne print function banaya hai jo temp me head daalke usko harr loop ke end me next se update krke, ek ek krke poori linkedlist print krdega
// So this is how linkedlists are created!

// Now lets write the code for Insert at Tail!
#include<iostream>
using namespace std;

class Node3 {
    public :
    int data;
    Node3* next;

    Node3(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Node3* &head, int data) {
    Node3* temp = new Node3(data);
    temp->next = head;
    head = temp;
} 

void insertAtTail(Node3* &tail, int data) {
    Node3* temp = new Node3(data);
    tail->next = temp;
    tail = tail->next;
} // This you can understand ki kya changes hue hai isme...ki humne n1 pointer ko tail me copy kraa ke iss node ke next ko next node ke head me point krdiya and then tail update krdiya new node ke tail se!

void print(Node3* &head) {
    Node3* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node3* n1 = new Node3(10);
    Node3* head = n1;
    Node3* tail = n1;
    print(head);
    
    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);
}

// Now lets insert at some position other than Head and Tail!
// So isme hum kya krenge ki maanlo koi linkedlist hai bani hui... like [10,Address of node2] -> [12,Address of node3] -> [14,Address of node4] -> [16,Address of node5] -> [18,NULL]
// Now maanli hume koi ek value insert krni hai in between the node 2 and 3, so for that what we will do is ki hum node 2 me jo node 3 ka reference hai usko node 3 se shift krke iss new node pr daal denge and jo new node hai usme next node ka refeence daal denge! and isse nodes ka count (count jo humaare dimaag me chal rha hai) ek aage badh jayega!
// So that is how we insert in the middle, hence the final node will be.... [10,Address of node2] -> [12,Address of node3] -> [13,Address of node5] -> [14,Address of node4] -> [16,Address of node5] -> [18,NULL]
// So our approach will be, So see agar hum nth position pr insert kr rhe hai toh hum (n-1)th node tak jaa rhe hai! and chalo ek node jo hum insert krne vaale hai usko NodetoInsert bolte hai, toh ab hum (n-1)th node tak jaa rhe hai and then jo nodetoInsert hai uska next ko (n-1)th next se replace kr de rhe hai! and then jo (n-1)th node ka next hai usko nodetoInsert pr daal de rhe hai!
// Lets code it now...
#include<iostream>
using namespace std;

class Node4 {
    public :
    int data;
    Node4* next;

    Node4(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Node4* &head, int data) {
    Node4* temp = new Node4(data);
    temp->next = head;
    head = temp;
}

void insertAtPosition(Node4* &head, int position, int data) {
    // Toh pehle humne temp ko head pr set krdiya and ab hum yhi se iterate krke linkedlist traverse krenge and then hume jis positin pr insert krna hai uss tak jayenge!
    Node4* temp = head;
    int cnt = 1; // temp abhi head pr hai toh isliye usko count = 1 rakh diya!

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // Now create a new node for the data jo add krna hai!
    Node4* NodetoInsert = new Node4(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;

}

void insertAtTail(Node4* &tail, int data) {
    Node4* temp = new Node4(data);
    tail->next = temp;
    tail = tail->next;
}

void printNode(Node4* &head) {
    Node4* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node4* newNode = new Node4(11);

    // Yahaa pr humne head se insert krna shuru kiya hai! and jab print karaya toh head to tail saare print hojayenge which will be, 15,14,13,12,11
    Node4* head = newNode;
    insertatHead(head, 12);
    insertatHead(head, 13);
    insertatHead(head, 14);
    insertatHead(head, 15);
    printNode(head);

    // Yahaa pr humne tail se insert krna shuru kiya hai! and jab print karaya toh head to tail saare elements print hogye! which will be 15,14,13,12,11,10,9,8,7
    Node4* tail = newNode;
    insertAtTail(tail,10);
    insertAtTail(tail,9);
    insertAtTail(tail,8);
    insertAtTail(tail,7);
    printNode(head);

    // Now lets insert in the middle! using the function!
    Node4* NodetoInsert = newNode;
    insertAtPosition(head,3,50);
    printNode(head);

    // But ye jo insertatpositon vaala function hai vo head ya tail pr insert nhi kr sakta! toh for that let create a general function jo linkedlist me kahin bhi insert kr sakta ho!
}

// So lets do this again...
#include<iostream>
using namespace std;

class Node5 {
    public :
    int data;
    Node5* next;

    Node5(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Node5* &head, int data) {
    Node5* temp = new Node5(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node5* &tail, int data) {
    Node5* temp = new Node5(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node5* &head, Node5* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node5* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // Ab see isme tail pr update toh hojayega bina kisi changes ki yahaa tak, but problem will be jo tail ka pointer vo insert krne ke baad bhi previous tail pr hi rahega.. so we need to fix it...
    // So we just need to update tail after inserting some value at tail...
    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    // Here we did the same what we thought in the approach...
    Node5* NodetoInsert = new Node5(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node5* &head) {
    Node5* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node5* newNode = new Node5(10); // Ye iss time jo node create hua that will be like [10,NULL]
    Node5* head = newNode; // Now here humne head and tail define krdiye! and at this moment head and tail dono hi starting node pr point kr rhe hai!
    Node5* tail = newNode;
    // But then when you have used insertAtAnyposition, then agar hum position me 1 daalenge maanlo 9 toh 1 toh head ko represent krta hai toh isliye head pr insert hojayega! mtlb it will be like [9,address of next node] -> [10,NULL]
    // Ab dekho ab agar iss hi me insertatAnyposition me position ke paramter me 2 daal denge toh ab 9 and 10 ke beech me ek aur node insert hojayega! and isse kya hoga ki jo pehle starting node tha vo krte krte end me hi rahega and tail bhi vhi rahega!

    // insertatHead(head,9);
    // insertatHead(head,8);

    // insertAtTail(tail,11);
    // insertAtTail(tail,12);

    // insertAtAnyPosition(head,tail,1,7);
    // insertAtAnyPosition(head,tail,4,20);
    // insertAtAnyPosition(head,tail,7,30);

    // So if you want to insert data without using insertAtHead() or insertAtTail(), then in that case you need to start with position 2, kyunki initial node toh 10 vaala hi hai uspr hi head hai and uss pr hi tail hai! toh hume agar sirf insertAtAnyposition ko use krna hai toh 2 position se insert krna shuru kro!
    insertAtAnyPosition(head,tail,2,30);
    insertAtAnyPosition(head,tail,3,40);
    insertAtAnyPosition(head,tail,4,50);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

    printNode(head);
}

// Lets now learn how to delete a node! so for that there can be two ways, one is with position and another is with data value!
// So appraoch will be, just opposite to the insert any any position! suppose you have [Data1,address of node2] -> [Data2,address of node3] -> [Data3,address of node4] -> [Data4,NULL]
// Lets delete one node... suppose you want to delete node3... so for that we will change the address stored in next pointer of node2 to the address of node4 and node3 ke jo next pointer me address stored hai usko vaisa hi rehne do and then isko memory free krdo!
// so maanlo yahaa what we will do is, jaise node3 ko delete krna tha, toh what we will do is we will write something like, node2->next = node3->next, isse kya hua jo node2 hai vo ab node4 ko point krne lgaa and node3 se uska connection toot gya and then humne node3 ke liye jo memory alotted hai vo humne free krdi!
// Last node bhi aise hi delete hojayega! but ab agar first node ko delete krne ke liye we need to follow some other approach..
// First node ke liye hume head ko shift krna hoga and then jahaa pehle head tha uske liye jo memory allocated thi usko free krdenge!
// And ye memory free krne ke liye hume ek destructor banana hoga! taaki memory jab free krne ki baat aaye tab destructor call hojaye!
// Lets code... linkedlists are about changing and adjusting connection between the nodes and iss hi basis pr insertion deletion and dusri cheeze hoti hai!
#include<iostream>
using namespace std;

class Node6 {
    public :
    int data;
    Node6* next;

    Node6(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node6() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node6* &head, int data) {
    Node6* temp = new Node6(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node6* &tail, int data) {
    Node6* temp = new Node6(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node6* &head, Node6* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node6* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node6* NodetoInsert = new Node6(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void deleteNode(Node6* &head, int position) {
    // Deleting the first node...
    if(position == 1) {
        Node6* temp = head;
        head = head->next; // Head ko shift krdiya ek node aage
        // Ab memory free krdo...
        temp->next = NULL;
        delete temp;
    }

    // Deleting middle nodes and last node...
    else {
        Node6* current = head;
        Node6* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = current;
            current = current->next;
            cnt++;
        }

        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void printNode(Node6* &head) {
    Node6* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node6* node1 = new Node6(10);
    Node6* head = node1;
    Node6* tail = node1;

    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    insertAtAnyPosition(head,tail,6,60);

    printNode(head);

    // Calling the delete function for the node with data value 30, its position is 3
    deleteNode(head,3);

    // Printing the updated linkedlist...
    cout<<"The updated linked list is : ";
    printNode(head);
} // Lets understand the final working of all of this... this theory will clear everything about single linkedlist... it will be a detailed summary of everything what we have studied about singly linked lists here!
// Lets gooo....
// So basically how we create linkedlist is pehle hum ek default node ke liye ek class create krte hai node naam se jo jaise hi hum koi object create krenge iss class ka vo ek node ban jayega! and then humne uss node ko initiate krne ke liye humne usme ek contructor create krdiya, and we know that constructor tab hi call hojaate hai jaise hi koi object create hota hai
// Toh isse ye fayeda hua ki jaise hum koi node class se object create krenge toh vo ek node ban jayega jaise hi vo object create hota hai...and humne constructor aise create kiya hai ki... we wrote int data; and Node6* next; means iss node me ek data hoga jo 4 bytes lega int ki and ek node type ka pointer hoga jo nodes ka address store krega! jisko humne next naam diya hai! toh overall this node will take memory of 8 bytes 
// jo constructor ki implementation hai vo aise hai ki like, ki jab bhi koi object create hota hai node ka toh vo toh ek node ban jayega and humne ye paramterized constructor banaya hai toh vo easily data value initialize krdega and uski jo next pointer hai usme NULL address store krdega!
// And similarly isme humne ek destructor bhi banaa diya hai kyunki isme hum jo bhi memory space use krenge vo heap vaali hogi toh usko hume free bhi krna hota hai! toh uske liye hume ek destructor banaya hai jisme humne node vaale object ko delete krne ke liye delete keyword ka use kiya hua hai! and vo humne aise implement kiya hua hai ki jaise hi kisi object ka scope over hota hai toh uss object ke liye destructor call hoga and uska next pointer ki value ko NULL krdiya jayega! isse uss node ka next ke nodes se link toot jayega and iske pichle node ka next pointer se iske next node ko point kraa denge!
// Now lets clear one thing, that is head and tail... so head and tail are two pointers of node class type jo sabse pehli node ko point kr rhe hote hai! starting me dono ek hi jagah point kr rhe hote hai! but then jaise jaise hum linkedlist create krte hai hum head and tail ko update krte rehte hai!
// Now lets see... insertatHead function me kya hua hai... isme hum pehle toh jo head hai linkedlist ka uska head pass kr rhe hai! and data bhi! and yahaa kya ho rha hai ki jab bhi insertatHead func call hoga tab ek new node create hoga jisko humne temp naam diya hai and jisme pass kiya hua data jayega and then iss new node ke next pointer se hum abhi jo current head hai usko point karwaa de rhe hai! then humne third line me uss head ko update krde rhe hai kyunki as now the new head is the new node temp!
// Then humne jo insertatTail jo create kiya hai vo insertatHead ki tarah hi banaya hai! bss the only difference is ki isme humne tail pass ki hai and then humne tail update krdi hai!
// Then we come at InsertatAnyPosition func(), isme kya hua hai ki pehle humne without head and tail ke logic se banaya tha and then humne isko generalize krdiya head tail and an position ke liye! now the thing is... isme what we did is... ki agar paramter me 1 pass hota hai toh mtlb ki hum head me insert krna chah rhe hai toh uss time toh as it is insertatHead ko hi call krdega!....
// then humne isme ek node type ka pointer create kiya temp jisme humne head copy krdiya! and then humne count krna shuru kiya and ye jo count hai iski help se hume kis position pr insert krenge vo calculate krenge, ab maanlo jaise agar koi node hai [data1,address of node2] -> [data2,address of node3] -> [data3,address of node4] -> [data4,address of node5] -> [data5,NULL] toh ab agar hume 2nd position pr insert krna hai toh mtlb hume 1st position ke aage insert krna hai, toh humne jo condition lgaa rakha hai vo cnt < position-1 kiya hua hai toh ye jo loop hai vo 1 pr iterate hua toh uss while loop ki help se toh bss hum linkedlists ko traverse kr rhe hai!...
// and once hum uss count pr pohoch jaaye traverse krke, then hum ye check kr rhe hai ki kya jo position humne input me di thi usko traverse krte krte kahin hum last node tak pohoch gye kya and ye humne check kiya temp->next == NULL likh ke, kyunki agar ye condition true hogyi toh mtlb hum linkedlist ke end tak pohoch gye and then humne iss if statement me insertatTail func ko call krdiya!
// and agar after all this koi bhi condition true nhi hui toh, finally humne ek new node create kiya node vaali class ka constructor ko use krke and iska name humne nodetoInsert diya and then humne usme data daala, then humne temp ke next ko iss nodetoInsert ke next me daal diya basically yahaa what we did is ki jo iss temp se pehle vaala node tha uske aage toh hume ye new node insert krna tha toh pehle hume isse pehle vaale node ke next me jo address stored hai usko change krke iss new node pr point karana tha and also uss node me jo next pointer jiss node ko point kr rha tha usko hume iss new node ke next me daalna tha! taaki vo link create ho sake!
// And that is how this new node is inserted!
// Now ab deleteNode, isme hum ye kr rhe the ki pehle toh jis node ko delete krna hai uska pehle toh link todna padega linkedlist se, so for that we first changed the next pointer of this node to NULL and jo isse pehle vaal node thh usko bhi iske next vaale node ko point kraa diya taaki poora linke khatam hojaye!
// Ab ye cheez middle and tail node ke liye toh kaam kr rhi thi pr head ke liye different approach follow krni padegui becoz it does not have any previous node, so for that what we did is, toh sabse pehle toh humne iss head node ko copy kiya temp name se! and then humne head ko update krdiya and temp->next ko NULL set krdiya and isse iska link toot gya linkedlist se, but sirf link thori torna hai memory bhi free krni hai toh for that we used the delete keyword!
// and agar head ke alawa koi aur node delete krni hai toh uske liye we wrote the else condition, where again humne apne head node ko copy kiya current naam se ek node ke liye pointer banaa kr and ek prev naam se pointer bnaa ke usme NULL store krdiya, then humne vhi count vaala loop use krke loop me iterate kiya, jahaa humne jahaa humne prev pointer jo NULL ko point kr rha tha usko humne current node copy krdiya, then current node ko update krdiya and then cnt++ krdiya so basically we traversed the linkedlist...
// then fir humne vhi prev node ke next pointer ko current node ke next pointer se replace krdiya and the jo abhi current node that uske next pointer ko NULL daal diya! and isse iska bhi link toot gya linkedlist se and then humne memory free krdiya! using delete keyword!
// Lastly printNode, isme humne head pass kiya to tell ki linkedlist start kahaa se ho rhi hai! then temp naam ka pointer create kiya usme head copy kiya (taaki head me koi changes na ho and iterate krne ke liye hum temp ko use kre naa ki head update hojaye, head always points at the start and tail always points towards tail)
// And humne yahaa loop iterate kiya jab tak NULL na temp ka next hojaye! and vaise vaise print krte gye!
// fir toh finally humne int main me node class ka use krke nodes banaye and unme values pass ki! also remember isme humne ek head and tail node ko create kiya jisme humne initial node ko copy krdiya! so that node1, head and tail sab ek hi memory location pr point kr rhe hai! and yahaa hum head and tail ko use krenge func call me pass krne ke liye!


// Doubly LinkedLists : Isme ek prev pointer hote hai and ek data hota hai and ek next pointer hota hai!
// Lets create it with the same logic as of above...
#include<iostream>
using namespace std;

class Node7 {
    public :
    int data;
    Node7* prev;
    Node7* next;

    Node7 (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printNode(Node7* &head) {
    Node7* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// lets find something new, which is length of the linkedlists!
int getLength(Node7* &head) {
    int len = 0;
    Node7* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// So what happened here is, jaise we know double linkeds are like this [NULL,data1,next node address] -><- [previour node address,data2,next node address] -><- [previour node address,data3,next node address] -><- [previour node address,data4,NULL]
// So hume first node mtlb head pr insert krne ke liye we need to do these things ki jo current insert krne se pehle jo head node tha uske prev pointer ko iss new node pr point karana hai iss new node ke pointer ko current head node pr point karana hai and new node ke prev pointer ko NULL pr point krana hai pr vo toh ho hi rakhaa hota hai! and then last me humne head ko update krdiya!
// So bss humne vhi kiya hai isme in code format! basics I already told in the singly linked list function of insert!
void insertAtHead(Node7* &head, int data) {
    Node7* temp = new Node7(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

// So yaa here we did the same, ki tail and data humne input me liya, then isse pehle jo tail ka jo next tha isko iss new node pr point karawaya and then iss new node ke prev ko pichle vaale tail pr point karwaya! and then last me tail ko upfdate krdiya! 
void insertAtTail(Node7* &tail, int data) {
    Node7* temp = new Node7(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtAnyPosition(Node7* &head, Node7* &tail, int position, int data) {
    // Insert at position 1 which is head
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node7* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node7* NodetoInsert = new Node7(data);
    NodetoInsert->next = temp->next;
    NodetoInsert->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

int main() {
    Node7* node1 = new Node7(10);
    Node7* head = node1;
    Node7* tail = node1;

    printNode(head);
    cout<<"Length : "<<getLength(head)<<endl;

    insertAtHead(head,9);
    printNode(head);

    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    printNode(head);

    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    printNode(head);

    insertAtAnyPosition(head, tail, 3, 100); // Insertin at any randome position
    printNode(head);
    
    insertAtAnyPosition(head, tail, 1, 101); // Inserting at Head using this function
    printNode(head);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    insertAtAnyPosition(head, tail, getLength(head)+1, 102); // Inserting at Tail using this function, writing this becoz tumko last position pr insert krna hai and agar sirf getlength() use kroge toh mtlb ki tum 12 position opr insert krna chah rhe ho and that will move the last element one node aage and it will insert 102 at second last position, so to insert at tail you need position of the last element + 1.
    printNode(head);

} // Here we have created a node and inserted at head and tail and at any position of the linkedlist & then printed it, also length of the linkedlists!


// Now lets do some correction.... and that is manlo jaise abhi toh hum pehle se ek node create krte then and then hum uske aage ya peeche se insert krna shuru krte the... maanlo agar vo initial node hi naa vo and hum linkedlist ekdum scratch se banana shuru kre bina uss initial node ke! then we need to do this...
#include<iostream>
using namespace std;

class Node8 {
    public :
    int data;
    Node8* prev;
    Node8* next;

    Node8 (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int getLength(Node8* &head) {
    int len = 0;
    Node8* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node8* &head, Node8* &tail, int data) {
    if(head == NULL) {
        Node8* temp = new Node8(data);
        head = temp;
        tail = temp;
    }
    else {
        Node8* temp = new Node8(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node8* &head, Node8* &tail, int data) {
    if(tail == NULL) {
        Node8* temp = new Node8(data);
        tail = temp;
        head = temp;
    }
    else {
        Node8* temp = new Node8(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAnyPosition(Node8* &head, Node8* &tail, int position, int data) {
    // Insert at position 1 which is head
    if(position == 1) {
        insertAtHead(head,tail,data);
        return;
    }

    Node8* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(head,tail,data);
        return;
    }

    Node8* NodetoInsert = new Node8(data);
    NodetoInsert->next = temp->next;
    NodetoInsert->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

void printNode(Node8* &head) {
    Node8* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node8* head = NULL; // At the initial stage there is no node at all!
    Node8* tail = NULL;

    // Now we will start adding nodes into it using the insertAtHead and insertAtTail function or insertAtAnyFunction...
    insertAtHead(head,tail,10);
    printNode(head);

    insertAtHead(head,tail,9);
    insertAtHead(head,tail,8);
    insertAtHead(head,tail,7);
    insertAtHead(head,tail,6);
    cout<<"Current Linkedlist is : ";
    printNode(head);

    insertAtTail(head,tail,11);
    insertAtTail(head,tail,12);
    insertAtTail(head,tail,13);
    insertAtTail(head,tail,14);
    cout<<"Current Linkedlist is : ";
    printNode(head);
} // So here the thing is, yahaa kya hua ki jo head and tail hai vo dono starting me dono NULL ko point kr rhe the and then humne kya kiya ki insert at head function call kiya toh pehle ek node create hua and then jo vo head and tail the jo pehle NULL koi point kr rhe the vo ab uss node1 ko point krne lage!
// And then humne uss temp ko head and tail me copy krdiya and then next time se jab bhi insertathead ko use krke jab bhi koi node add hua toh uss time else vaali condition kaam kr rhi thi jo head ko update kr rhi thi and tail vaisa ka vaisa node1 ko point kr rha tha!
// and ye same cheez humne insertattail ke saath bhi krdi! isliye humne tail and head dono hi as a paramter pass krdiye! vrna vaise tail naam se kabhi koi paramter nhi bnaate hai! head se hi saara kaam karaate hai!
// So if you want to create a insertAtTail function using only head! then in that case, pehle hum head se last pointer tak jayenge loop me iterate karaake! and then hum jaake value/data insert krenge! isme thori time compelxity badh jayegi which will be O(n), but space bachega jo humne tail banane me lagaya tha!

// Now lets move to deleting a node!
// Approach : Jaise pehle rhi thi same vaisi hi, pehle head ko delete krna seekhte hai, toh jo head hai uska prev toh NULL ko point kr rha hoga and jo uska next hai vo next node ko point kr rha hoga, and jo next node hai uska prev head ko point kr rha hoga, and then humne head update bhi krna hai and then memory bhi free krni hai!
// So flow will be...
// temp->next->prev = NULL, then head = temp->next, then temp->next = NULL and then last me memory free krdo destructor call krke using the delet keyword kyunki these nodes are dynamically allocated and they are to be deleted manually!
// Ab agar head ke alawa koi aur node delete krna hota toh, the flow would be...
// curr->prev = NULL, then prev->next = curr->next, then curr->next = NULL and then lastly memory free krdena hai!
// Now lets code it....
#include<iostream>
using namespace std;

class Node9 {
    public :
    int data;
    Node9* prev;
    Node9* next;

    Node9 (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node9() { // Bina destructor banaye bhi kaam chal jaata! koi dikkat nhi hoti, bss thora cuctomize krne ke liye deletion ko we are using destructor
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

int getLength(Node9* &head) {
    int len = 0;
    Node9* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node9* &head, Node9* &tail, int data) {
    if(head == NULL) {
        Node9* temp = new Node9(data);
        head = temp;
        tail = temp;
    }
    else {
        Node9* temp = new Node9(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node9* &head, Node9* &tail, int data) {
    if(tail == NULL) {
        Node9* temp = new Node9(data);
        tail = temp;
        head = temp;
    }
    else {
        Node9* temp = new Node9(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAnyPosition(Node9* &head, Node9* &tail, int position, int data) {
    // Insert at position 1 which is head
    if(position == 1) {
        insertAtHead(head,tail,data);
        return;
    }

    Node9* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(head,tail,data);
        return;
    }

    Node9* NodetoInsert = new Node9(data);
    NodetoInsert->next = temp->next;
    NodetoInsert->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

void printNode(Node9* &head) {
    Node9* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(Node9* &head, int position) {
    // Deleting the first node...
    if(position == 1) {
        Node9* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        // Ab memory free krdo...
        delete temp;
    }

    // Deleting middle nodes and last node...
    else {
        Node9* current = head;
        Node9* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = current;
            current = current->next;
            cnt++;
        }

        current->prev = NULL;
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main() {
    Node9* head = NULL;
    Node9* tail = NULL;

    // Now we will start adding nodes into it using the insertAtAnyFunction...
    insertAtAnyPosition(head,tail,1,101);
    insertAtAnyPosition(head,tail,2,102);
    insertAtAnyPosition(head,tail,3,103);
    insertAtAnyPosition(head,tail,4,104);
    insertAtAnyPosition(head,tail,5,105);
    insertAtAnyPosition(head,tail,6,106);
    cout<<"Current Linkedlist is : ";
    printNode(head);

    deleteNode(head,1);
    printNode(head);

    deleteNode(head,4);
    printNode(head);

    deleteNode(head,getLength(head)); // Using the getlength function taaki hum last node ko delete kr sake!
    printNode(head);
}

// Circular Linkedlist : Ye bhi do type ke hote hai, Singly circular linkedlist! and Doubly circular linkedlist! So overall isme kya hota hai ki in case of singly ki jo last node hota hai uska next linkedlist ke head ko point kr rha hota hai! and in case of double jo last node hota hai uska next linkedlist ke head ko point kr rha hota hai and jo head ka prev hai vo last node ko point kr rha hota hai!
// Yahaa humari approach thori alag hogi, yahaa hume head ki zarurat nhi hai yahaa hum tail ka use krenge! kyunki uss tail se hi hum tail->next krke head tak pohoch sakte hai and tail se toh hum tail ko access kr hi sakte hai! in case of singly, in case of doubly we can use the tail->prev and tail->next and all to access any node... also yahaa head ka koi logic nhi banta kyunki jab linkedlist circular hai toh isliye!
// Also yaha ye bhi differene hai ki yahaa hum position kuch define nhi kar payenge as such! toh isliye yaha kisi ek element ke respect me dusra node add ya delete krenge!
// In case of empty list, we will create a node which will have a value and its next will be pointing towards its ownself!
// And agar pehle se koi node hai toh uss element ke respect me daalenge ki kahaa nayaa node insert hoga!
// Now lets see the approach...
// In case of empty list : Pehle hum ek node create krenge and isko hum khudse hi point kraa denge! tail = NULL, temp = tail, temp->next = temp.
// Second case when there is already a node in the linkedlist : Then in that case pehle toh humne ek forward name se ek space banai and isme humne temp->next store kiya, then humne current->next = temp, temp->next = forward.
// Now suppose there are already two nodes are present and now we want to insert a third node : Imagine it like, [3,address of next node] -> [5,pointing towards the supposedly first node], then ab isme we have 2 cases maanlo we want to insert after node with data 3, so this is the flow, pehle ek node create kro and then jahaa 3 vaala node point kr rha hai na usk store krlo, forward = curr->next; yaa isse better hai you can do is, jo nayaa node humne create kiya usko we have named temp, so temp->next = current->next; and then current->next = temp; Another case can be if we want to insert a node after 5, so in that case, so first create a node, temp->next = current->next; current->next = temp;
// Now lets code these logic...
#include<iostream>
using namespace std;

class Node10{
    public :
    int data;
    Node10* prev;
    Node10* next;

    Node10 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node10() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNode(Node10* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node10* newNode = new Node10(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        // Now if the list is not empty...and the element we have input is present!
        Node10* current = tail;
        // Now we are finding that element vaala node thru traversal!
        while(current->data != element) {
            current = current->next;
        }
        // Now element is found and the current is representing that element vaala node!
        Node10* temp = new Node10(data);
        temp->next = current->next;
        current->next = temp;
    }
} // Now isme ye jo element hai in case of empty list agar hum function call me ye element pass kr bhi dete hai fir bhi koi fark nhi padega kyunki vo element list me hai hi nhi!
// Now lets see how to print the list...

void printNode(Node10* tail) {
    Node10* temp = tail;
    // cout<<tail->data<<" ";

    // while(tail->next != temp) {
    //     tail = tail->next;
    //     cout<<tail->data<<" ";
    // }
    // cout<<endl;
    // Iss upar vaale logic se bhi print hojayega linkedlist, but we have another way of doing the same thing, that is do while loop, we rarely use it but here we can!

    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main() {
    Node10* tail = NULL; // This shows that the list is empty!

    insertNode(tail,-1,3); // Yahaa humne -1 daal diya but kyunki ye empty list thi startting me toh ye -1 match nhi hoga kabhi and iss function call se seedha 3 insert hojayega! and linkedlist will have its first node which is 3
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,3,5); // Isme humne vo 2nd case apply kiya, jab pehle iss function call se poore list me check hua ki kahin 3 hai and jahaa 3 mila uske aage 5 add krdiya! vaise ye same cheez hui toh empty list ke case me bhi hai bss vahaa kabhi -1 mila nhi isliye if vaala statement execute hua insertNode function ka first node ke case me!
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,5,7);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,7,9);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,3,4);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,9,10);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,7,8);
    cout<<"Current Linked List : ";
    printNode(tail);

    // insertNode(tail,-1,2); // Iss case me kuch hua hi nhi kyunki -1 exist hi nhi krta! empty ke case me hogya tha kyunku uss time list empty thi/ tail NULL tha but iss time nhi! but basically yahaa humara ye try tha ki hum 3 se pehle 2 daal de so for that being said iska koi sense nhi hai! kyunki... it is circular, so 3 ke pehle 2 daalde ya jo tail vaala element hai uske baad 2 daalde it means the same! so just insert 2 after 10...
    insertNode(tail,10,2);
    cout<<"Current Linked List : ";
    printNode(tail);
}

// Deletion of node in case of Circular Linkedlists!
// So we will here try to delete when we are given with the node's data, and uske basis pr hum delete krenge! also hum position ke basis pr bhi delete kr sakte hai but you can try on your own, here lets try for only data based deletion!
#include<iostream>
using namespace std;

class Node11{
    public :
    int data;
    Node11* prev;
    Node11* next;

    Node11 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node11() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNode(Node11* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node11* newNode = new Node11(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        // Now if the list is not empty...and the element we have input is present!
        Node11* current = tail;
        // Now we are finding that element vaala node thru traversal!
        while(current->data != element) {
            current = current->next;
        }
        // Now element is found and the current is representing that element vaala node!
        Node11* temp = new Node11(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void deleteNode(Node11* &tail, int value) {
    // If the list is empty!
    if(tail == NULL) {
        cout<<"Linkedlist is empty!"<<endl;
        return;
    }
    else {
        // If the list is non-empty
        // and assuming the "value" is present in the list!
        Node11* prev = tail; // Here we have defined ki prev and tail kya kya hai!
        Node11* curr = prev->next;
        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
// So basically what we did is, ek jo circular linkedlist hai usme hume jis node ko delete krna hai vo hum identify yahaa value se kr rhe hau uss node ki, so hum uss value ke base pr uss node tak pohche and then humne uss node ke prev ke next ko current node (mtlb jahaa actual value hai) ke next pr point krwa diya! and jo current node hai uske next ko NULL krdiya! isme tail ko prev node pr point kraane ki zarurat nhi hai kyunki its a circular LL toh vo toh pehle se hi point kr rha hoga!

void printNode(Node11* tail) {
    Node11* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main() {
    Node11* tail = NULL; // This shows that the list is empty!
    deleteNode(tail,3); // Iss time it will print the LL is empty!

    // now lets insert some data...
    insertNode(tail,-1,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,5,6);
    insertNode(tail,6,7);
    insertNode(tail,7,8);
    cout<<"Current Linked List is : ";
    printNode(tail);

    deleteNode(tail,3); // Iss case me ek dikkat ho rhi thi where, kyunki ye LL kuch aise hai, 3 4 5 6 7 8 so iss case me current = 3 and so prev = 8 hojayega! so ab agar hum 3 ko delete krte hai toh prev ab current->next ko point krega! toh yahaa tak theek tha, but jab humne 3 delete kiya toh tail abhi bhi current pr tha toh usko humne fir if statement ki help se update krdiya! ye dikkat sirf tab hi aati hai jab kisi aise node ko delete kr rhe hai jisko tail point kr rakha hai! and yahaa pr 3 vaisa hi node tha, so isliye we need to add this if condition in the deleteNode statement!
    printNode(tail);
}

// Toh upar toh we have handles two cases one of trying deletion on empty LL and deleting a single node from the LL when there are more than 1 nodes... now lets see deletion of the node when there is only one node in LL...
// Iss case me kya hoga ki, like suppose you have a LL with only one node, [3,address of itself], now isme kya hoga ki iska tail bhi yhi pr hoga, iska prev and iska current bhi yhi pr point kr rha hoga, toh jab hum isko delete krenge toh iski memory toh free hogyi! toh jab hum print karayenge LL tab jo cheez humne delete krdi usko kaise vapis print ho sakti hai? isliye error ya segmentation fault ya garbage value print hogi, lets solve this thing, so that we get a more genuine answer!
#include<iostream>
using namespace std;

class Node12{
    public :
    int data;
    Node12* prev;
    Node12* next;

    Node12 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node12() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNode(Node12* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node12* newNode = new Node12(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node12* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node12* temp = new Node12(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void deleteNode(Node12* &tail, int value) {
    // If the list is empty!
    if(tail == NULL) {
        cout<<"Linkedlist is empty!"<<endl;
        return;
    }
    else {
        Node12* prev = tail; // Here we have defined ki prev and tail kya kya hai!
        Node12* curr = prev->next;
        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // When there is only 1 node in linked list...
        if(curr == tail) {
            tail = NULL;
        }
        // for >= 2 nodes linkedlist
        else if(tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void printNode(Node12* tail) {
    Node12* temp = tail;
    // Empty list...
    if(tail == NULL) {
        cout<<"Linkedlist is Empty!";
        return;
    }
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main() {
    Node12* tail = NULL;
    insertNode(tail,-1,3);
    cout<<"Current Linked List is : ";
    printNode(tail);
    deleteNode(tail,3);
    printNode(tail);
}
// Must try the dry run for all of the codes and logic and try for yourself also for better understanding! visit codestudio for more topics related to it!

// ---------------------------------------------------------- LECTURE 45 - Linked Lists Questions --------------------------------------------------------------------------------------------------------->
// Question : Reverse a Linkedlist
// Approach 1 (An iterative approach): We can do this like, suppose you have linkedlist like [3,address of next node] -> [4,address of next node] -> [5,address of next node] -> [6,address of next node] -> [7,address of next node] -> NULL... ab iss linkedlist me jo pehla node hai vo head hai and last vaala tail, toh arrays me kya krte the ki hum poore elements ko yahaa se vahaa utha kr rakhte the, but here we just reverse the links, that ki jo node abhi right vaale node ko point kr rha tha vo ab bss pichle vaale node ko point kr rha tha
// Now lets see how we will achieve this...
// So first we will make a pointer name as "prev" jo kisi NULL ko point kr rha hoga, then we will create a "curr" jo abhi ke liye current head node ko point kr rha hoga, then ab hume reverse krna hai toh hume saare links ulte krne honge, toh hum agar starting me hi head ke next ko next node se hataa ke prev jo ki humne NULL banaya hua hai uss pr point kraa denge toh head ka link baaki linkedlist ke elements se toot jayega! and our linkedlist will be lost! so for that we will also create a forward pointer jo curr->next ko point kr rha hoga!
// Now, hum jaise jaise curr vaale nodes ke pointers ko "unke" prev pr point krte jayenge, vaise vaise hum forward ko bhi aage shift krte jaana hai! for this we will use the while loop! and jab curr == NULL hojayega tab hum loop se exit hojayenge! as kyunki iss time pr prev new head ko point kr rha hoga (jo head reverse krne se pehle tail tha)! and then lastly we will return prev, becoz that is the new head, and hum head se hi reversed linkedlist print krenge!
// Lets code this approach...
#include<iostream>
using namespace std;

class Node13 {
    public :
    int data;
    Node13* next;

    Node13(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node13() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node13* &head, int data) {
    Node13* temp = new Node13(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node13* &tail, int data) {
    Node13* temp = new Node13(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node13* &head, Node13* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node13* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node13* NodetoInsert = new Node13(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node13* ReversedLinkedList(Node13* head) {
    // In case of empty list or list have only one node...
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // Now if list is not empty and has more than 1 node...
    Node13* prev = NULL; // Prev create krke usko initially null pr point kraa diya
    Node13* curr = head; // current create krke usko initially current head pr point kraa diya
    Node13* forward = NULL; // forward ko current ke next pr point kraa diya taaki iterate kr sake linkedlist ko bina list ko lost kiye

    while(curr != NULL) {
        // then iterated the list.... by moving the forward further and changing the links using curr and prev pointers!
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void printNode(Node13* &head) {
    Node13* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
   Node13* node1 = new Node13(10);
   Node13* head = node1;
   Node13* tail = node1;
   printNode(head);

    // Inserting more elements to the linkedlist...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 30);
    insertAtAnyPosition(head, tail, 4, 40);
    insertAtAnyPosition(head, tail, 5, 50);
    insertAtAnyPosition(head, tail, 6, 60);
    insertAtAnyPosition(head, tail, 7, 70);
    insertAtAnyPosition(head, tail, 8, 80);
    cout<<"Current Linkedlist : ";
    printNode(head);

    cout<<"Reversed Linkedlist : ";
    Node13* reversedHead = ReversedLinkedList(head);
    printNode(reversedHead);
} // This approach time complexity and space complexity are, T(n) = O(n) & Space Complexity : O(1).
// This was an iterative approach, lets see another one...

// Approach 2 (A recursive one) : Toh jaisa abhi tak hum krte aaye hai recursive approach me, ki ek case sambhal lo base condition btaa do ki kahaa rukna hai baaki recursion sambhal lega!
// So what we will do is, hum first node ke next ko prev pr point kraa denge and baaki then recursion sambhal lega! 
// Base case will be ki hum jab last me pohochenge tab humara curr null hogya hoga and prev last node ko point kr rha hoga (jo reversed list ka head hai), so hum head ko prev me copy krke return krdenge! and then jo conditions upar lagai thi forwards curr and prev ki, vhi same operations yahaa pr bhi perform honge! and then baaki me recursive call krdenge!
// Lets code this....
#include<iostream>
using namespace std;

class Node14 {
    public :
    int data;
    Node14* next;

    Node14(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node14() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node14* &head, int data) {
    Node14* temp = new Node14(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node14* &tail, int data) {
    Node14* temp = new Node14(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node14* &head, Node14* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node14* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node14* NodetoInsert = new Node14(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void reverse(Node14* &head, Node14* curr, Node14* prev) {
    // Base case
    if(curr == NULL) {
        head = prev;
        return;
    }
    Node14* forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;
}

Node14* ReversedLinkedList(Node14* head) {
    // In case of empty list or list have only one node...
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // Now if list is not empty and has more than 1 node...
    Node14* curr = head;
    Node14* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

void printNode(Node14* &head) {
    Node14* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
   Node14* node1 = new Node14(10);
   Node14* head = node1;
   Node14* tail = node1;
   printNode(head);

    // Inserting more elements to the linkedlist...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 30);
    insertAtAnyPosition(head, tail, 4, 40);
    insertAtAnyPosition(head, tail, 5, 50);
    insertAtAnyPosition(head, tail, 6, 60);
    insertAtAnyPosition(head, tail, 7, 70);
    insertAtAnyPosition(head, tail, 8, 80);
    cout<<"Current Linkedlist : ";
    printNode(head);

    cout<<"Reversed Linkedlist : ";
    Node14* reversedHead = ReversedLinkedList(head);
    printNode(reversedHead);
} // So here the time complexity is again the same O(n) and space complexity is O(n)!

// Question 2 : Find middle of the linkedlist!
// Approach 1 : So what we will do is we will find the length of the list! and then we will calculate the middle node! in case of odd length, the middle node vo hoga jo ekdum beech me hai! and in case of even length, middle node 2 honge toh unme se hum iss question ke liye right vaala consider krenge! now lets understand the rest of it through code...
#include<iostream>
using namespace std;

class Node15 {
    public :
    int data;
    Node15* next;

    Node15(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node15() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node15* &head, int data) {
    Node15* temp = new Node15(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node15* &tail, int data) {
    Node15* temp = new Node15(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node15* &head, Node15* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node15* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node15* NodetoInsert = new Node15(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node15* &head) {
    Node15* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Function to find the length of the list...
int getlength(Node15* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find the middle node...
Node15* findMiddleNode(Node15* head) {
    int len = getlength(head);
    int ans = (len/2);
    Node15* temp = head;
    int cnt = 0;
    while(cnt < ans) {
        temp = temp->next;
        cnt++;
    }
    return temp;
} // So here what we did is, pehle getlength se length nikala! and then ans me len/2 store kiya, then list ke head ko temp me store kiya! and jo ans me jo len/2 store hai vahaa tak loop ko iterate kraa ke jab loop exit hua toh temp me vo node tha jo middle node hai! toh in the last humne temp return krdiya!
// in case of even number of elements, let say 6, then ans = 3 (mtlb humara loop 3 baar chalega), and humara jo middle node hoga vo 4th position pr hoga! so loop start hua, cnt = 0 se, and now the thing is, starting me temp jo hai vo head pr tha, toh cnt = 0 me vo node2 pr aaya, then cnt = 1 pr vo node3 pr aaya, then cnt = 2 hua toh vo node4 pr aagya! and then jab cnt = 3 hua toh loop exit hogya and jo temp me node4 store hua vo return krdiya humne!
// Toh yahaa thora dekhna padega ki kya ans chahiye uske according hum apna loop utni baar chalaa sakte hai, also ans me (len/2) store krna hai ya (len/2) + 1, ye sab pehle hi dekhna hoga! love babbar ka answer yhi galat aa rha tha!

int main() {
    Node15* node1 = new Node15(10);
    Node15* head = node1;
    Node15* tail = node1;
    printNode(head);

    // Inserting odd number of element...
    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    // Inserting another element to make it an list weith even number of elements...
    insertAtAnyPosition(head,tail,6,60); // in this case 30 and 40 both will be middle element but for this question we are considering the right one is the middle element, so 40 will be the ans!
    
    cout<<"Current Linked List : ";
    printNode(head);

    Node15* middleNode = findMiddleNode(head);
    cout<<"Middle element of the Linked List is : "<<middleNode->data<<endl;
}
// Time Complexity : T(n) + T(n/2); -> T(n) for getlength function ke liye and T(n/2) findmiddlenode vaale function me loop ke liye!
// So overall humari TC : O(n)...
// But here we can see that ek baar hum full traversal kr rhe hai and ek baar hum sirf half hi kr rhe hai! so lets see the optimized solution based on this approach...


// Optimized Approach : Now suppose you have two person one is fast and another is slow, fast one runs 2 metre in 1 sec and slow one runs 1 metre in 1 sec! Now, jitni agar 5 sec ki race hai usme fast person will cover 10 metres and slpw one will cover 5 metres! so we can see ki slow half distance cover krega, toh yahaa hum iss logic ka use krke slow ki help se middle node nikal sakte hai!
// Now lets see the coding logic...
// in case of empty list : NULL (no middle node)
// in case of one node : Head
// in case of 2 nodes : Head->next
// In all other cases, we will keep fast at head->next and slow at head, now in case of suppose odd 5 nodes, and starting with slow at head and fast at head->next means node2, so first iteration me slow node2 pr pohchega and uss hi iteration me fast node4 pr pohchega, now dusri iteration me slow ek aage badh ke node3 pr pohochega and fast node4 se do aage NULL pr pohoch jayega and yahaa hum loop se exit hojayenge! and we will return slow, kyunki vo apni sahi jagah pohoch gya!
// In case of even number of nodes, slow will ba again at head and fast will be at head->next which is node2, now in the first iteration slow will be at node2 and fast will be at node4 and then in the next iteration slow will be at node3 and fast will be at node6 and then in the next iteration, slow will be at node4 and fast can't move 2 nodes further becoz there is only one left and that is NULL, so fast will move only one step ahead and here fast is now pointing at NULL, and here we will exit the loop and we will see that slow again covered our half distance, as we have finalised the middle node in case of even is the right one... hence we got it! and now we will return the slow...
// Lets code this logic...
#include<iostream>
using namespace std;

class Node16 {
    public :
    int data;
    Node16* next;

    Node16(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node16() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node16* &head, int data) {
    Node16* temp = new Node16(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node16* &tail, int data) {
    Node16* temp = new Node16(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node16* &head, Node16* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node16* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node16* NodetoInsert = new Node16(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node16* &head) {
    Node16* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node16* getMiddleNode(Node16* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node16* slow = head;
    Node16* fast = head->next;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node16* findMiddleNode(Node16* head) {
    getMiddleNode(head);
}

int main() {
    Node16* node1 = new Node16(10);
    Node16* head = node1;
    Node16* tail = node1;
    printNode(head);

    // Inserting odd number of element...
    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    // Inserting another element to make it an list weith even number of elements...
    insertAtAnyPosition(head,tail,6,60); // in this case 30 and 40 both will be middle element but for this question we are considering the right one is the middle element, so 40 will be the ans!
    
    cout<<"Current Linked List : ";
    printNode(head);

    Node16* middleNode = findMiddleNode(head);
    cout<<"Middle element of the Linked List is : "<<middleNode->data<<endl;
}
// So this is the more optimized solution! here the TC : O(n) and SC : O(1)

// ---------------------------------------------------------- LECTURE 46 - Linked Lists Questions --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse the Linkedlist in the groups of K
// Like suppose you have a linkedlist, node1 -> node2 -> node3 -> node4 -> node5 -> node6 -> NULL.
// Now, if we are asked to reverse the linkedlist in the group of K, then if K = 2, then it means to reverse the linkedlist in the group of 2, means the final output will be, node2 -> node1 -> node4 -> node3 -> node6 -> node5 -> NULL here the head will be node2, and then similarly for K equal to any other value...
// lets see the approach : Now if you get the input 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL here the head is 2, and now in this case, the reverse with the K group will be like, 3 -> 2 -> 5 -> 4 -> 7 -> 6 -> NULL.
// Toh do this pehle hum iteratively pehle do nodes ko reverse krenge and then baaki ke jo elements hai unko recursively solve krke iske aage lgaa denge!
// Pehle lets code then you we will do a dry run! to understand it clearly!
#include<iostream>
using namespace std;

class Node17 {
    public :
    int data;
    Node17* next;

    Node17(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node17() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node17* &head, int data) {
    Node17* temp = new Node17(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node17* &tail, int data) {
    Node17* temp = new Node17(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node17* &head, Node17* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node17* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node17* NodetoInsert = new Node17(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node17* &head) {
    Node17* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node17* ReverseK(Node17* head, int K) {
    // Base case...
    if(head == NULL) {
        return NULL;
    }
    // In other cases...
    // Step 1 : Reverse first K Nodes...
    Node17* next = NULL;
    Node17* curr = head;
    Node17* prev = NULL;
    int count = 0;
    while( curr != NULL && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Step 2 : Recursion will handle rest of it...
    if(next != NULL) {
        head->next = ReverseK(next,K);
    }
    // Step 3 : Return the head of the reversed list...
    return prev;
}
// So what we did here is, Now suppose jo LL input me aaya hai that is 1 -> 2 -> 3 -> 4 -> NULL. now, hume isko reverse krna hai in K groups! and here for demo we let K = 2, now first we will take first 2 node, 1 -> 2 -> remaining LL, and here head is at 1, Now as hum log LL ko reverse krne ke time sirf links ko reverse krdete hai toh kaam ban jaata hai! toh bss yahaa bhi jo 1 -> 2 -> remainging list, isme se humne 2 vaali link ko hataa ke 1 pr point kraa diya and 1 jo pehle 2 ko point kr rha tha ab vo peeche ki taraf kisi NULL ko point kra denge! so what we got is, NULL <- 1 <- 2
// Now, ye sab cheeze hui kaise toh ye sab hua humare inn operations se, humne pehle Node17* next and prev ko null pr point karaya and curr ko head pr, mtlb ki at this moment head is at 1, mtlb in 1 -> 2 -> NULL, isme head is at 1, and prev and next are at NULL now we iterated a loop, where we put the condition ki jab tak current null na hojaye and jo count hai vo K se kam na hojaye, ye tab hoga jab humaare LL me jo k value hai usse kam nodes bache hai in that case hum exit hojayenge loop se, and now iss loop ke andar we didi operations! lets understand how these operations are helping in reversing the first 2 nodes (as K = 2)
// So first we wrote, next = curr->next; means next ko NULL se hataa ke curr ke next node pr point karaa do means now the next is at 2 node, and then humne curr->next = prev; krdiya, isse kya hua ki prev me toh NULL tha and isse humne current ke next me NULL daal diya! means now at this moment curr uss par abhi head toh hai pr vo abhi NULL ko point kr rha hai! as in our approach humne discus kiya tha ki hume links reverse krni hai toh bss hum vhi kr rhe hai current (which is currently head) usko NULL point kraa ke (mtlb ek tarah se kehdo ki peeche point kraa ke) now, we did prev = curr; it means, ab iss moment me curr and prev dono hi 1 ko point kr rhe hai! and next 2 ko point kr rha hai! now we did is curr = next; mtlb ab jahaa next point kr rha hai vaaha current point kr rha hai! and then humne count aage badhaa diya!
// Now lets summarize what we did, pehle jahaa head point kr rha tha vahaa current point kr rha tha! and prev and next NULL ko point kr rhe the! then in the first line of while loop, humne next ko NULL se shift krke vahaa point kraa diya jahaa curr ka next point kr rha tha, then humne next line me curr (head) ke next ko vahaa point kraa diya jahaa prev point kr rha tha mtlb ki NULL, then in next line prev ko humne vahaa point kraa diya jahaa curr (head) abhi point kr rha hai! and then in next line humne current ko vahaa point kraa diya jahaa next point kr rha hai! mtlb ki at this moment, jab loop end hone vaala hai tab humara jo pehla K group tha vo aisa hogya hai! NULL <- 1 <- 2, and isme prev pehle NULL pe tha inn sab operations se humne usko 2 pr point kra diya and curr and next ko 2 pr point kra diya and then count++ krdiya to tell ki ek iteration khatam hogyi! and then firse humne ye same opeartions kiye jab next ko humne first curr->next pr point kraya! and all vo sab steps repeat kiye jo just abhi kiye the!
// And jab ye loop se exit hoke aaye toh pehla K group reverse hogya tha! and then baaki ke liye we used recursion! and the rest of the LL is handled by recursion!

int main() {
    int K;
    cout<<"Enter the value of K : ";
    cin>>K;
    Node17* node1 = new Node17(10);
    Node17* head = node1;
    Node17* tail = node1;
    printNode(head);

    // Inserting odd number of element...
    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    insertAtAnyPosition(head,tail,6,60);
    cout<<"Current LL : ";
    printNode(head);

    cout<<"Reversed LL in groups of K : ";
    Node17* reversedK = ReverseK(head, K);
    printNode(reversedK);
} // TC : Hum harr node ko sirf ek baar visit kr rhe hai and total numbers of node agar n hai toh TC = O(n)!
// SC : Humari harr recursive calls pr K nodes ko reverse kr rhe hai and usme hum constant space le rhe hai! and aise hum n/k times space lenge baaki recursive calls me toh humari Sc = n/k * k = n, so SC = O(n)!

// Question 2 : Check whether a LinkedList is Circular or Not.
// Approach will be, like suppose if your LL is empty then return true and if your LL has only 1 node then check if the head->next is NULL or is it point towards itself, if NULL then return false and if it is equal to head->next then return true, then another case of nodes > 1... in that case, make a pointer of Node type and point it at head->next! agar head pr point krayenge then vo head ko do baar count krlega so isliye point it at heads next...
// Then, ek loop chalo iss hi temp ka use krke jo abhi head->next ko point kr rha hai, and tak tak chalao jab tak temp yaa toh head ke equal na hojaye ya toh NULL na hojaye, then agar loop ke end me temp head ko point kr rha ho toh mtlb ki it is a circular LL and if NULL ko point kr rha ho toh mtlb ki it is a non-circular LL kyunki circular me kahin bhi NULL toh hoga nhi!
// Now lets code...
#include<iostream>
using namespace std;

// Creating a Circular LinkedList
class Node18{
    public :
    int data;
    Node18* prev;
    Node18* next;

    Node18 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node18() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node18* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node18* newNode = new Node18(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node18* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node18* temp = new Node18(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node18* tail) {
    Node18* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Checking for Circular or not!
bool isCircularList(Node18* head) {
    // Empty list..
    if(head == NULL) {
        return NULL;
    }

    // We can write single node and more than 1 node case under one condition, as they are overlapping...
    Node18* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // Creating Circular LL...
    Node18* tailC = NULL;
    insertNodeCircularLL(tailC, -1, 10);
    insertNodeCircularLL(tailC, 10, 20);
    insertNodeCircularLL(tailC, 20, 30);
    insertNodeCircularLL(tailC, 30, 40);
    insertNodeCircularLL(tailC, 40, 50);
    insertNodeCircularLL(tailC, 50, 60);
    cout<<"Circular LL : ";
    printNodeCircularLL(tailC);

    // Now lets write code for checking that the LL is circular or not...
    if(isCircularList(tailC)) {
        cout<<"It is a Circular LL!";
    }
    else {
        cout<<"It is not a Circular LL";
    }
} // TC : O(n) kyunki hum poori list ko travers kr rhe hai so n is number of nodes! and then SC : O(1) kyunki humne koi space nhi li isme!

// There is another approach also to solve this question... that is useing Maps! as maps me values key value pair ke form me store hoti hai toh,
// jaise jaise jo node traverse hote jaa rhi hai usko true mark krte jayenge and jab poori linkedlist traverse krne ke baad agar vapis true value pr ajaye iterate krne pr means that is a cicular LL otherwise Not!
// try this on your own while doing revision!


// ---------------------------------------------------------- LECTURE 47 - Detect & Remove Loop Question in LL --------------------------------------------------------------------------------------------------------->
// Question : Detect and Remove loop in the LL! but this question is divided into 3 parts, 1) Detect the loop, 2) Output the starting node of the loop!, 3) Remove loop
// 1) Detect the loop/cycle in LL : We just need to check whether the LL has loop or not!
// Yahaa pr hum kis tarah ke loops ki baat kr rhe hai ye janna zaruri hai! so like maanlo kuch nodes hai node1 -> node2 -> node3 -> node4 and now this node4 is again pointing towards node2 or node3 then iss case me ek loop ban jayega! and due to which jab bhi hum node4 visit krenge then hum node2 pr chalenge jayenge agar node4 lets say node2 pr point kr rha hoga and then hum ek loop me fass jayenge!
// Abb iska hi ek extreme case hota hai circular linkedlist jisme node4 seedha node1 ko hi point kr rha hoga toh usme bhi ek loop hota hai! toh dono hi cases me humne loop find krna hai ki kya loop exist krta hai ya nhi!
#include<iostream>
#include<map>
using namespace std;

// Creating a Circular LinkedList
class Node19{
    public :
    int data;
    Node19* prev;
    Node19* next;

    Node19 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node19() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node19* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node19* newNode = new Node19(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node19* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node19* temp = new Node19(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node19* tail) {
    Node19* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Checking for Circular or not!
bool isCircularList(Node19* head) {
    // Empty list..
    if(head == NULL) {
        return NULL;
    }

    Node19* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    else {
        return false;
    }
}

// Function to detect a loop in the list!
// Approach : So for this question we will create a map and isme content key values ke pair ke form me store rehta hai, so what we will do is we will use this maps! and isme vaise hi data store krenge! jo jo nodes visit hote jayenge unko true mark krte rehna and jab poori list traverse krne ke baad jab bhi agar vapis true vaala node pr pointer aayega tab true return krdenge ki haa iss list me loop hai!
bool detectLoop(Node19* head) {
    if(head == NULL) {
        return false;
    }
    map<Node19*, bool> visited;
    Node19* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
} // jo dono tarah ke loops the vo dono tarah ke loops ye function detect kr sakta hai!

int main() {
    // Creating Circular LL...
    Node19* tail = NULL;
    insertNodeCircularLL(tail, -1, 10);
    insertNodeCircularLL(tail, 10, 20);
    insertNodeCircularLL(tail, 20, 30);
    insertNodeCircularLL(tail, 30, 40);
    insertNodeCircularLL(tail, 40, 50);
    insertNodeCircularLL(tail, 50, 60);
    cout<<"Circular LL : ";
    printNodeCircularLL(tail);

    if(detectLoop(tail)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    }
} // You can try to execute the detectLoop function in case of singly linkedlist, there it will print Loop does not exist! kyunki usme loop hi nhi hoga!
// TC : O(n) and SC : O(n), but there is an algorithm, which is called Floyd Cycle Detection algorithm, and this algorithm can reduce the Space complexity to O(1). upar vaale algo se bhi harr tarah ke loops/cycle detect hojayenge but floyd cycle detection ek more optimized way hai cycles in a LL detect krne ka!

// Approach 2 to solve this question! : So here we will be using the floyd cycle detection algorithm! and in this we will use jo humne fast and slow vaale pointer padhe the pehle vo sab! but pehle humne slow ko head pr rakha tha and fast ko head->next pr, but iss algo me dono head pr honge! and then vhi same cheez hoga ki fast 2 nodes ek baar me traverse krega but slow ek ek krke aage badhega!
// Now agar traverse krte krte fast and slow equal hogye kabhi bhi then means cycle exist! and agar kabhi nhi mile ya fast ya slow me se koi bhi NULL hogya toh means cycle does not exist!
#include<iostream>
#include<map>
using namespace std;

// Now here what we will do is we will create a singly linkedlist and a singly linkedlist with a inner loop (jo pehla vaala case tha jisme node4 node2 ko point kr rha tha) and then a circular linkedlist! and then we will use both the methods to check are we able to identify loop/cycle in the three LLs using the two methods...
// First using the detectLoop() function on all three LLs...
// Constructing a Singly Linkedlist (Will use this class to make 2 LLs one without any loop and other with a inner loop)
class Node20 {
    public :
    int data;
    Node20* next;

    Node20(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node20() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node20* &head, int data) {
    Node20* temp = new Node20(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node20* &tail, int data) {
    Node20* temp = new Node20(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node20* &head, Node20* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node20* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node20* NodetoInsert = new Node20(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node20* &head) {
    Node20* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Constructing a Circular LinkedList...
class Node21{
    public :
    int data;
    Node21* prev;
    Node21* next;

    Node21 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node21() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node21* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node21* newNode = new Node21(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node21* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node21* temp = new Node21(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node21* tail) {
    Node21* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Creating two different functions for Singly LLs and Circular LL, becoz currently I want to keep it simple and just want to understand the things clearly! isliye dono type ke LLs ke liye alag alag detectLoop function create kiye hai!
// For Singly LLs...
bool detectLoop1(Node20* head) {
    if(head == NULL) {
        return false;
    }
    map<Node20*, bool> visited;
    Node20* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// For Circular LLs...
bool detectLoop2(Node21* head) {
    if(head == NULL) {
        return false;
    }
    map<Node21*, bool> visited;
    Node21* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main() {
    // Creating Singly LL 1 without any loop...
    Node20* nodeLL1 = new Node20(10);
    Node20* headLL1 = nodeLL1;
    Node20* tailLL1 = nodeLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    // inserting more nodes...
    insertAtAnyPosition(headLL1, tailLL1, 2, 20);
    insertAtAnyPosition(headLL1, tailLL1, 3, 30);
    insertAtAnyPosition(headLL1, tailLL1, 4, 40);
    insertAtAnyPosition(headLL1, tailLL1, 5, 50);
    insertAtAnyPosition(headLL1, tailLL1, 6, 60);
    cout<<"Singly Linked List 1 : ";
    printNode(headLL1);

    // Detecting Loop using detectLoop1 function of Singly LLs...
    if(detectLoop1(headLL1)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is printing Loop does not exist!

    cout<<endl;
    cout<<endl;

    // Now Lets create another singly LL but this time with an inner loop!
    Node20* nodeLL2 = new Node20(100);
    Node20* headLL2 = nodeLL2;
    Node20* tailLL2 = nodeLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);


    // inserting more nodes...
    insertAtAnyPosition(headLL2, tailLL2, 2, 200);
    insertAtAnyPosition(headLL2, tailLL2, 3, 300);
    insertAtAnyPosition(headLL2, tailLL2, 4, 400);
    insertAtAnyPosition(headLL2, tailLL2, 5, 500);
    insertAtAnyPosition(headLL2, tailLL2, 6, 600);
    cout<<"Singly Linked List 2 : ";
    printNode(headLL2);

    // Detecting Loop using detectLoop1 function of Singly LLs...
    // But for that lets create an inner loop, by pointing the tail of this LL2 at position 3...
    tailLL2->next = headLL2->next->next; // Ab agar tum isko normally bhi seedha head se point kraa doge toh ye bhi ek circular LL ban jayega, toh your did'ne need to implement circular LL alag se, but ofc alag se krne ke apne fayede hai ki tumko harr baar ye line nhi likhni padegi kyunki vo uski class me hi implemented hai and nayaa element add krne ke time dikkat aa sakti hai also jo different operations hum perform krte hai circular LL pr vo hum aise krke na kr paye!
    // even tho koi as such dikkat nhi hogi pr we need to be then more careful while performing delet insert and other operations, but yahaa hum bss ye check kr rhe hai ki LLs me loop exist krta hai ki nhi toh ye hum aise bhi check kr sakte hai!

    // Now lets check that, does the loop exist...
    if(detectLoop1(headLL2)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is showing that the loop exists!

    cout<<endl;
    cout<<endl;

    // Now lets create a circular linkedlist using its implementation in class node21...
    Node21* tailC = NULL;
    insertNodeCircularLL(tailC,-1,1000);
    insertNodeCircularLL(tailC,1000,2000);
    insertNodeCircularLL(tailC,2000,3000);
    insertNodeCircularLL(tailC,3000,4000);
    insertNodeCircularLL(tailC,4000,5000);
    insertNodeCircularLL(tailC,5000,6000);
    cout<<"Circular Linked List : ";
    printNodeCircularLL(tailC);

    // Now lets check whether detectLoop2 function of circular LL can detect the loop in it...
    if(detectLoop2(tailC)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // As expected it is printing Loop exist!
}

// Now using Floyd Detection Algorithm on all the three LLs to detect the loop...
#include<iostream>
#include<map>
using namespace std;

// Constructing a Singly Linkedlist (Will use this class to make 2 LLs one without any loop and other with a inner loop)
class Node22 {
    public :
    int data;
    Node22* next;

    Node22(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node22() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node22* &head, int data) {
    Node22* temp = new Node22(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node22* &tail, int data) {
    Node22* temp = new Node22(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node22* &head, Node22* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node22* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node22* NodetoInsert = new Node22(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node22* &head) {
    Node22* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Constructing a Circular LinkedList...
class Node23{
    public :
    int data;
    Node23* prev;
    Node23* next;

    Node23 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node23() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node23* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node23* newNode = new Node23(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node23* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node23* temp = new Node23(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node23* tail) {
    Node23* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Creating two different functions for Singly LLs and Circular LL, becoz currently I want to keep it simple and just want to understand the things clearly! isliye dono type ke LLs ke liye alag alag detectLoop function create kiye hai!
// For Singly LLs...
Node22* floydDetectLoop1(Node22* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node22* fast = head;
    Node22* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

// For Circular LLs...
Node23* floydDetectLoop2(Node23* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node23* fast = head;
    Node23* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

int main() {
    // Creating Singly LL 1 without any loop...
    Node22* nodeLL1 = new Node22(10);
    Node22* headLL1 = nodeLL1;
    Node22* tailLL1 = nodeLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    // inserting more nodes...
    insertAtAnyPosition(headLL1, tailLL1, 2, 20);
    insertAtAnyPosition(headLL1, tailLL1, 3, 30);
    insertAtAnyPosition(headLL1, tailLL1, 4, 40);
    insertAtAnyPosition(headLL1, tailLL1, 5, 50);
    insertAtAnyPosition(headLL1, tailLL1, 6, 60);
    cout<<"Singly Linked List 1 : ";
    printNode(headLL1);

    // Detecting Loop using floydDetectLoop1() function of Singly LLs...
    if(floydDetectLoop1(headLL1) != NULL) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is printing Loop does not exist!

    cout<<endl;
    cout<<endl;

    // Now Lets create another singly LL but this time with an inner loop!
    Node22* nodeLL2 = new Node22(100);
    Node22* headLL2 = nodeLL2;
    Node22* tailLL2 = nodeLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);


    // inserting more nodes...
    insertAtAnyPosition(headLL2, tailLL2, 2, 200);
    insertAtAnyPosition(headLL2, tailLL2, 3, 300);
    insertAtAnyPosition(headLL2, tailLL2, 4, 400);
    insertAtAnyPosition(headLL2, tailLL2, 5, 500);
    insertAtAnyPosition(headLL2, tailLL2, 6, 600);
    cout<<"Singly Linked List 2 : ";
    printNode(headLL2);

    // Detecting Loop using floydDetectLoop1() function of Singly LLs...
    tailLL2->next = headLL2->next->next;

    // Now lets check that, does the loop exist...
    if(floydDetectLoop1(headLL2) != NULL) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is showing that the loop exists!

    cout<<endl;
    cout<<endl;

    // Now lets create a circular linkedlist using its implementation in class node21...
    Node23* tailC = NULL;
    insertNodeCircularLL(tailC,-1,1000);
    insertNodeCircularLL(tailC,1000,2000);
    insertNodeCircularLL(tailC,2000,3000);
    insertNodeCircularLL(tailC,3000,4000);
    insertNodeCircularLL(tailC,4000,5000);
    insertNodeCircularLL(tailC,5000,6000);
    cout<<"Circular Linked List : ";
    printNodeCircularLL(tailC);

    // Now lets check whether floydDetectLoop2() function of circular LL can detect the loop in it...
    if(floydDetectLoop2(tailC) != NULL) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    }
}
// Now lets see why it works...
// Kyunki harr iteration me dono nodes ke beech ka distance ek ek unit kam hote jaata hai! and in the end kahin toh milna hi hai! so that is why this algorithm actually works!

// Identify the starting point of the Loop!
// Approach : What we will do is, ki hum pehle step me toh Floyd Cycle Detection algo ke through vo point of intersection toh nikal hi lenge jahaa Fast and Slow meet kr rhe hai! and then jab hum vo nikal le then in the next step what we will do is, slow ko vapis se head pr point kraa denge and fast toh abhi bhi uss point of intersection pr hi point kr rha hai! but ab iss step me hum slow and fast ko same rate se move krenge and jahaa pr iss baar ye meet kr jaye that will be the starting node of the loop!
// But lets see why this logic works? isme ek A + B = K*C ka expression banta hai LL me, and vo kaise that you can visit again Love Babbar vdo! its very simple and easy! so iss logic se hi this algo works! refer the vdo for details and accurate explaination!
// Lets code this logic now....
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node24 {
    public :
    int data;
    Node24* next;

    Node24(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node24() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node24* &head, int data) {
    Node24* temp = new Node24(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node24* &tail, int data) {
    Node24* temp = new Node24(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node24* &head, Node24* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node24* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node24* NodetoInsert = new Node24(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node24* &head) {
    Node24* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// We need it as we have discussed in the approach!
Node24* floydDetectLoop1(Node24* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node24* fast = head;
    Node24* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

// Code to implement the solution to find the starting node of the Loop!
Node24* getStartingNode(Node24* head) {
    if(head == NULL) {
        return NULL;
    }
    Node24* intersection = floydDetectLoop1(head);
    Node24* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow; // Here in the end the slow will be pointing at the starting node of the loop!
}

int main() {
    Node24* node = new Node24(100);
    Node24* tail = node;
    Node24* head = node;
    cout<<"First node of LL : ";
    printNode(head);


    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 200);
    insertAtAnyPosition(head, tail, 3, 300);
    insertAtAnyPosition(head, tail, 4, 400);
    insertAtAnyPosition(head, tail, 5, 500);
    insertAtAnyPosition(head, tail, 6, 600);
    cout<<"Singly Linked List : ";
    printNode(head);

    // Creating an inner loop!
    tail->next = head->next->next;

    // Now as we have already created a loop! lets find the starting node of the Linkedlist
    Node24* startingNode = getStartingNode(head);
    cout<<"The starting node of the loop is : "<<startingNode->data<<endl;
} // So that is how we have find the starting node of the loop!

// Removing the Loop! isme what we will do is, we will jo starting point hai Loop ka usse pehle jo node hai (inside the loop) usko NULL ko point kraa denge! ek tarah se jaise loop create hua tha vaise hi remove bhi hoga, jaise tail ko kisi ek particular node pr point kraya tha na bss uss hi pointer ko hataa do we will get the loop removed!
// Toh for this we will need floyd detect loop vaala function jo interection point detect krega jiski help se hum starting node nikalenge and then uss starting se pehle vaale node ko (Loop ke andar) NULL pr point kraa denge! and we will get the answer!
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node25 {
    public :
    int data;
    Node25* next;

    Node25(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node25() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node25* &head, int data) {
    Node25* temp = new Node25(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node25* &tail, int data) {
    Node25* temp = new Node25(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node25* &head, Node25* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node25* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node25* NodetoInsert = new Node25(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node25* &head) {
    Node25* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// We need it as we have discussed in the approach!
Node25* floydDetectLoop1(Node25* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node25* fast = head;
    Node25* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

// We also needed this...
Node25* getStartingNode(Node25* head) {
    if(head == NULL) {
        return NULL;
    }
    Node25* intersection = floydDetectLoop1(head);
    if(intersection == NULL) { // Here we puting checks ki agar intersection NULL na hojaye agar hogya toh intersection -> next krne pr error aa sakta hai, kyunki iska mtlb hoga ki hum NULL->next try kr rhe hai find krne ka! which is not logical! so it can give our segementation fault or system may crash! or things like that! overall it will show error!
        return NULL;
    }
    Node25* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow;
}

Node25* removeLoop(Node25* head) {
    if(head == NULL) {
        return NULL;
    }
    Node25* startofLoop = getStartingNode(head);
    // Ye humne extra NULL checks lagaye vrna segementation fault y faaltu ka kuch errors aa sakte hai, kyunki agar hume ye check nhi lgaye toh getStartingNode se NULL value aane pr intersection me NULL store hoga! and then temp me bhi NULL jayega and then temp->next ke time pr NULL->next calculate krne ki koshish hogi which will return an error! or a segementation fault!
    if(startofLoop == NULL) {
        return NULL;
    }
    Node25* temp = startofLoop;

    while(temp->next != startofLoop) {
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main() {
    Node25* node = new Node25(100);
    Node25* tail = node;
    Node25* head = node;
    cout<<"First node of LL : ";
    printNode(head);


    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 200);
    insertAtAnyPosition(head, tail, 3, 300);
    insertAtAnyPosition(head, tail, 4, 400);
    insertAtAnyPosition(head, tail, 5, 500);
    insertAtAnyPosition(head, tail, 6, 600);
    cout<<"Singly Linked List : ";
    printNode(head);

    // Creating an inner loop!
    tail->next = head->next->next;

    // Found the starting point of the Loop!
    Node25* startingNode = getStartingNode(head);
    cout<<"The starting node of the loop is : "<<startingNode->data<<endl;

    // Removing the loop!
    removeLoop(head);

    // To check whether loop is removed or not,
    cout<<tail->next<<endl;
} // So that is how you remove loops from LL

// ---------------------------------------------------------- LECTURE 48 - Remove Duplicates from sorted/unsorted Linkedlists! --------------------------------------------------------------------------------------------------------->
// Question 1 : Suppose a linkedlist 10->20->20->30->30->30->30->40->NULL, so this LL is sorted and now we will, remove all the duplicates so we will get the final output as 10->20->30->40->NULL
// Approach : With the example of the above case, we will use tow pointers, head and current, initially dono head pr point kr rhe honge! now hum current ko use krke current ka data and current ke next ka data compare krenge, agar dono same honge toh hum current ka next ka data delete krdenge and current ke next ko current->next->next pr point kraa denge! and agar same nhi hote toh hum current ko just ek aage badhaa dete!
// Lets code now....
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node26 {
    public :
    int data;
    Node26* next;

    Node26(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node26() {
        int value = this->data; // isme isko bhi likhne ki zrurat nhi hai, kyunki jiss jagah pr delete keyword call hua hoga hoga vo uske hisaab se data utha lega! toh alag se specify krne ki zarurat nhi hai!
        cout<<"Memory is free for the node with data "<<value<<endl;
    } // Here we have changed the destructor a little bit becoz destructor already delete krta hai, toh usme alag se delete operation perform krne ki zarurat nhi hai!
};

void insertatHead(Node26* &head, int data) {
    Node26* temp = new Node26(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node26* &tail, int data) {
    Node26* temp = new Node26(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node26* &head, Node26* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node26* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node26* NodetoInsert = new Node26(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node26* &head) {
    Node26* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node26* uniqueSortedList(Node26* head) { // This function is to remove all the duplicate elements!
    // Empty list...
    if(head == NULL) {
        return NULL;
    }
    Node26* curr = head;
    while(curr != NULL) {
        if((curr->next != NULL) && (curr->data == curr->next->data)) {
            Node26* next_to_next = curr->next->next;
            Node26* nodeToDelete = curr->next;
            curr->next = next_to_next;
            delete(nodeToDelete);
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node26* node = new Node26(10);
    Node26* head = node;
    Node26* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 20);
    insertAtAnyPosition(head, tail, 4, 30);
    insertAtAnyPosition(head, tail, 5, 30);
    insertAtAnyPosition(head, tail, 6, 40);
    cout<<"Singly Linked List : ";
    printNode(head); // Currently this LL contains duplicate elements!

    // Removing duplicate elements...
    head = uniqueSortedList(head);
    printNode(head);
} // Time Complexity : O(n) and Space Complexity : O(1).
// So this is how we will remove duplicates in a sorted Linkedlist!, now lets remove duplicates from UnSorted!

// Removing duplicates in unsorted Linkedlist!
// Jaise pehle hum kr rhe the ki current ko harr iteration me aage badhaa rhe the and current->data and current->next hai usko compare kr rhe the agar dono same ho rhe the toh current->next ko pehle delete krke and then usko current->next->next pr point kraa de rhe the! and aise current ko aage badhaye jaa rhe the jab tak current->next NULL na hojaye!
// Approach 1 : So in this case what we will do is, hum iss baar curr ko head pr rakhenge and then poori LL traverse krenge then jaha jahaa same values dikhengi current->data se, unn unn nodes ke data ko vahaa se delete krte jayenge! and that is how we will move further! but isme TC will become O(n^2) which is not a good thing, so...
// Approach 2 : Yaa toh pehle hi LL ko sort krlo and then jo pehle vaala tha method tha usse hi solve krlo! in this case the TC : O(nlogn)
// Approach 3 : Yaa toh map use krlo, where map create krlo <node, bool> type ka jisme jo jo nodes hum visit krte jayenge unko hum true mark krte jayenge! and jab bhi traverse krte time koi aisa node aata hai jo map me already true marked hai usko delete krke uske prev node ko uske aage vaale node pr point kraa denge! and similarly for other nodes!
// Code for Approach 1, rest you can try while doing practice!
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node27 {
    public :
    int data;
    Node27* next;

    Node27(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node27() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node27* &head, int data) {
    Node27* temp = new Node27(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node27* &tail, int data) {
    Node27* temp = new Node27(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node27* &head, Node27* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node27* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node27* NodetoInsert = new Node27(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node27* &head) {
    Node27* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node27* uniqueUnsortedList(Node27* head) { // This function is to remove all the duplicate elements!
    // Empty list...
    if(head == NULL) {
        return NULL;
    }
    Node27* curr = head;
    while(curr != NULL) {
        Node27* temp = curr;
        while(temp->next != NULL) {
            if(temp->next->data == curr->data) {
                Node27* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            }
            else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    Node27* node = new Node27(10);
    Node27* head = node;
    Node27* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 20);
    insertAtAnyPosition(head, tail, 4, 30);
    insertAtAnyPosition(head, tail, 5, 30);
    insertAtAnyPosition(head, tail, 6, 40);
    cout<<"Singly Linked List : ";
    printNode(head); // Currently this LL contains duplicate elements!

    // Removing duplicate elements...
    head = uniqueUnsortedList(head);
    printNode(head);
} // It will have TC : O(n^2) becoz we have used two loops!, and SC will be constant O(1) kyunki koi extra space nhi li gyi hai!
// Rest, write and practice other approaches as well! as they are important to know, kyunki interviews me different approaches puche jaa sakte hai!
// Along with this learn to split cicular LL into two halves! and write the code!

// ---------------------------------------------------------- LECTURE 49 - Merge 2 Sorted LLs, Sort 0s, 1s, 2s --------------------------------------------------------------------------------------------------------->
// Question 1 : We are given with a LL with 0s 1s and 2s in the LL as nodes but they are are not in a sequence! so we have to sort them in a order!, like if you have a LL, 0->1->0->2->1->2, so we need to sort them as 0->0->1->1->2->2, so how will you do this...
// Approach 1 : So what we will do is that we will traverse the whole LL and count all the 0s 1s and 2s in the LL and then jo given LL hai usme hi start se end tak jaate jaate jitni jitni baar 0s 1s and 2s hai unko LL me data replace krte jayenge!
// Lets code this approach :
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node28 {
    public :
    int data;
    Node28* next;

    Node28(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node28() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node28* &head, int data) {
    Node28* temp = new Node28(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node28* &tail, int data) {
    Node28* temp = new Node28(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node28* &head, Node28* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node28* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node28* NodetoInsert = new Node28(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node28* sortList(Node28* head) { // Here we have codes the same approach! to print all the nodes 0 1 2 one by one according to there count! by replace the previous nodes data with the sorted ones!
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node28* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            oneCount++;
        }
        else if(temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

void printNode(Node28* &head) {
    Node28* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node28* node = new Node28(0);
    Node28* head = node;
    Node28* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 1);
    insertAtAnyPosition(head, tail, 4, 0);
    insertAtAnyPosition(head, tail, 5, 1);
    insertAtAnyPosition(head, tail, 6, 2);
    cout<<"Singly Linked List : ";
    printNode(head);

    head = sortList(head); // Updated the head
    printNode(head); // Printing the LL with the new head!
} // TC will be O(n) kyunki do loops alag alag traverse hue hai! and koi extra space nhi use ki bss variables hi create kiye hai! so SC will be O(1)

// Approach 2 : Now what if we are not allowed to replace the data! then in that case what else can we replace or change? that is Links! so we will try to change the Links of nodes though this approach!
// So what we will do is we will create 3 LLs one for 0s and one 1s and one for 2s, and then we will merge all of them! Here we will be using dummy nodes like ye ek tarah se head nodes honge saare individual LLs ke taaki hum identify kr sake ki ye jo 3 LLs honge vo teeno kiske kiske hai! and then final jab hum merge kr rhe honge toh inn Dummy nodes ki help se hi krenge!
// Bina dummy nodes ke bhi hojayega question solve, pr usme if condition lga lga ke pagal hojayenge! isliye we will use dummy nodes!
// Lets code and see further...
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node28 {
    public :
    int data;
    Node28* next;

    Node28(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node28() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node28* &head, int data) {
    Node28* temp = new Node28(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node28* &tail, int data) {
    Node28* temp = new Node28(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node28* &head, Node28* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node28* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node28* NodetoInsert = new Node28(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void insertAtTail2(Node28* &tail, Node28* curr) { // This is just created to insert the data into the created sub-LLs in the sortList function!
    tail->next = curr;
    tail = curr;
}

Node28* sortList(Node28* head) { // As we discussed in the approach using dummy nodes! and merge all the three LLs!
    // Three individual LLs created for 0s 1s and 2s
    // Here we have created head and tail both! kyunki humaari jo LL ki implementations hai usme hum head and tail dono leke chal rhe hai and isliye humne insert at tail ko bhi implement kiya hua hai apne insertAtAnyPosition me! so isliye humne tail bhi banai! otherwise jab actually implement log krte hai toh generally tail bnaate hi nhi hai sirf head ke through hi inserting operations implement kr dete hai! but okay hum head nad tail dono leke chal rhe hai!
    // So here we have created three dummy nodes with head and tails which are be pointing at sub-LLs of 0s 1s and 2s! and later on we will merge them!
    Node28* zeroHead = new Node28(-1);
    Node28* zeroTail = zeroHead;

    Node28* oneHead = new Node28(-1);
    Node28* oneTail = oneHead;

    Node28* twoHead = new Node28(-1);
    Node28* twoTail = twoHead;

    Node28* curr = head;
    while(curr != NULL) {
        int value = curr->data;
        if(value == 0) {
            insertAtTail2(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail2(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail2(twoTail, curr);
        }
        curr = curr->next;
    }
    // Now we will merge the created three sub-LLs...
    // Approach is ki hum zerotail ke next ko oneHead ke next se link kr denge (one head is just a dummy node main data toh oneHead ke next node se store hona shuru ho rha hai isliye zeroTail next ko oneHead ke next se link kraa rhe hai!)
    // and similarly for other sub-LLs... but isme ek dikkat ho sakti hai, that is ki what if zeroHead vaali LL me toh 0s hai, pr 1s vaali poori khali ho! and jo 2s vaali hai usme 2s hai, so in this case hum 0s vaali LL ko 2s vaali LL se link naa krke 2s vaali se link krdenge seedha, and for this we will use a if else conditions!

    // 1s list is not empty...
    if(oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    // Ab yahaa tak ka toh kaam hogya! but ab humari list ready hai, but now we need to remove the dummy nodes as becoz they are using extra space also zeroHead vaal dummy node toh abhi current head bnaa hua hai is merged LL ka, so hum chahenge ki usko 0s ki first vaali node pr point kraye! toh hum head bhi change krna hoga!
    head = zeroHead->next;

    // Deleting dummy nodes!
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void printNode(Node28* &head) {
    Node28* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node28* node = new Node28(0);
    Node28* head = node;
    Node28* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 1);
    insertAtAnyPosition(head, tail, 4, 0);
    insertAtAnyPosition(head, tail, 5, 1);
    insertAtAnyPosition(head, tail, 6, 2);
    cout<<"Singly Linked List : ";
    printNode(head);

    head = sortList(head); // Updated the head
    printNode(head); // Printing the LL with the new head!
} // TC : O(n) and SC : O(1), iski aur upar vaale approach ki TC and SC dono same hai, so ab interviewer pr depend krta hai ki what they will ask! if they tell to sort 0s 1s and 2s without replacement, then you will use this approach!


// Question 2 : Merge two sorted LLs!
// You will be given with two sorted LLs and dono ko merge krke jo resultant LL hogi vo bhi sorted honi chahiye!
// Lets see the approach : Pehli baar toh agar dono me se koi bhi LL empty hoti hai toh hum dusri vaali LL ko print krdenge as simple as that! but now lets see otherwise...
// So, here what we will do is, suppose have two LLs one is LL1 and another is LL2, now, LL1 me do pointer honge prev and curr, and hum prev and curr node ke beech me kisi aisi value ko dhundenge dusri LL me jo inn dono ke beech me aa sakti hai, agar aa sakti hai toh simply uss node ko daal denge LL1 me and prev ko update krke uss node pr le ayenge jisko abhi abhi merge kiya LL1 me from LL2, now again we will check ki kya ab kr sakte hai ki prev and curr ke beech me koi node insert from LL2, if yes then will repeat the same and if noe then will just update prev and curr! and will keep on doing this jab tak LL2 k NULL nhi aa jaata!
// So yahaa hum merge krne ke liye kisi ek LL ko LL1 maanenge and ek ko LL2! and LL2 ke nodes ko LL1 me add krte jayenge! and once LL2 ka NULL aajaata hai toh hum vhi ruk jayenge! and will print LL1!
// Also hum kisko LL1 maanna hai and kisko LL2 ye bhi toh ptaa krna padega! kyunki LL1 me LL2 ka data tab hi daalenge na jab LL2 ka first node badaa ho LL1 ke first node se!, so for that pehle hume yhi ptaa krna pdega ki konsa LL1 and and konsa LL2!
// Now lets code...
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node29 {
    public :
    int data;
    Node29* next;

    Node29(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node29() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node29* &head, int data) {
    Node29* temp = new Node29(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node29* &tail, int data) {
    Node29* temp = new Node29(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node29* &head, Node29* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node29* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node29* NodetoInsert = new Node29(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node29* solve(Node29* ActualLL1, Node29* ActualLL2) {
    // Here we have created prev and curr jisko use krke hum Actual LL1 pr windows create krenge jisme hum LL2 ke elements ko compare krke merge krenge!
    Node29* prev = ActualLL1;
    Node29* curr = prev->next;

    // This is a pointer is created jisse hum Actual LL2 me traverse krenge!
    Node29* temp = ActualLL2;
    Node29* tempNext = temp->next; // Isko hum bss use krenge ActualLL2 ko track me rakhne ke liye ki kahin jab ActualLL2 ke nodes ActualLL1 me merge ho rhe ho toh uss instant pr kahin baaki nodes ka access na kho jaye humse! isliye ye create kiya gya hai! It is just like a helping pointer! which will just track the nodes of ALL2.

    while(curr != NULL && temp != NULL) {
        if((temp->data >= prev->data) && (temp->data <= curr->data)) {
            prev->next = temp; // Prev of ALL1 ke next ko ALL2 ke temp se link krdiya! 
            tempNext = temp->next; // ALL2 ke remaining nodes ka track na kho jaye isliye unko tempNext ek helping pointer create krke usko uss remaining part of ALL2 pr point kraa diya!
            temp->next = curr; // Ab hum safely temp of ALL2 ke next ko ALL1 ke curr ke saath link kr sakte hai

            // Now just update the pointers...
            prev = temp;
            temp = tempNext;
        }
        else {
            // If me tha ki agar temp prev and curr ke beech me lie krta hai toh temp daaldo ALL1 me, but what if agar nhi krta hai lie between prev and curr...then...
            // So in this case hume bss prev and curr ko aage badhaana padega!
            prev = curr;
            curr = curr->next;
        }
    }
    return ActualLL1;
}

Node29* mergeLLs(Node29* LL1, Node29* LL2) {
    if(LL1 == NULL) {
        return LL2;
    }
    if(LL2 == NULL) {
        return LL1;
    }

    // Here we have managed that konsi Linkedlist actual LL1 banegi and konsi actual LL2!
    if(LL1->data <= LL2->data) {
        return solve(LL1, LL2);
    }
    else {
        return solve(LL2, LL1);
    }
}

void printNode(Node29* &head) {
    Node29* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating Linkedlist 1...
    Node29* LL1 = new Node29(1);
    Node29* headLL1 = LL1;
    Node29* tailLL1 = headLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    // Inserting more nodes in LL1...
    insertAtAnyPosition(headLL1, tailLL1, 2, 5);
    insertAtAnyPosition(headLL1, tailLL1, 3, 6);
    insertAtAnyPosition(headLL1, tailLL1, 4, 8);
    insertAtAnyPosition(headLL1, tailLL1, 5, 10);
    insertAtAnyPosition(headLL1, tailLL1, 6, 15);
    cout<<"Singly Linkedlist LL1 : ";
    printNode(headLL1);

    cout<<endl;

    // Creating Linkedlist 2...
    Node29* LL2 = new Node29(1);
    Node29* headLL2 = LL2;
    Node29* tailLL2 = headLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);

    // Inserting more nodes in LL2...
    insertAtAnyPosition(headLL2, tailLL2, 2, 2);
    insertAtAnyPosition(headLL2, tailLL2, 3, 3);
    insertAtAnyPosition(headLL2, tailLL2, 4, 7);
    insertAtAnyPosition(headLL2, tailLL2, 5, 9);
    insertAtAnyPosition(headLL2, tailLL2, 6, 12);
    cout<<"Singly Linkedlist LL2 : ";
    printNode(headLL2);

    cout<<endl;

    // merging the two Linkedlists LL1 and LL2...
    Node29* head = mergeLLs(LL1, LL2);
    cout<<"Final merged Linkedlist : ";
    printNode(head);
} // So that is how we do it! and its TC : O(n) and SC : O(1), kyunki do loops chale hai jo poori linkedlist traverse kr rhe hai and space bhi koi as such li nhi hai bss variables alot kiye hai!

// But there is still one problem and that is ki suppose LL1 has only 1 node then in that case prev will be at that node and curr will be at NULL, now due to which solve vaale function me kabhi bhi Loop chalega hi nhi!, so bss yhi ek case handle krna bacha hai upar vaale case me!, so for that we will do this...
#include<iostream>
using namespace std;

class Node29 {
    public :
    int data;
    Node29* next;

    Node29(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node29() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node29* &head, int data) {
    Node29* temp = new Node29(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node29* &tail, int data) {
    Node29* temp = new Node29(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node29* &head, Node29* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node29* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node29* NodetoInsert = new Node29(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node29* solve(Node29* ActualLL1, Node29* ActualLL2) {
    // If only one node is present in the ActualLL1, iss case me simply uss first node ke next ko ActualLL2 ke first se link krdo, and thats it!
    if(ActualLL1->next == NULL) {
        ActualLL1->next = ActualLL2;
        return ActualLL1;
    } // this is the change we have done here!

    Node29* prev = ActualLL1;
    Node29* curr = prev->next;

    Node29* temp = ActualLL2;
    Node29* tempNext = temp->next;

    while(curr != NULL && temp != NULL) {
        if((temp->data >= prev->data) && (temp->data <= curr->data)) {
            prev->next = temp;
            tempNext = temp->next;
            temp->next = curr;

            // Now just update the pointers...
            prev = temp;
            temp = tempNext;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return ActualLL1;
}

Node29* mergeLLs(Node29* LL1, Node29* LL2) {
    if(LL1 == NULL) {
        return LL2;
    }
    if(LL2 == NULL) {
        return LL1;
    }

    // Here we have managed that konsi Linkedlist actual LL1 banegi and konsi actual LL2!
    if(LL1->data <= LL2->data) {
        return solve(LL1, LL2);
    }
    else {
        return solve(LL2, LL1);
    }
}

void printNode(Node29* &head) {
    Node29* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating Linkedlist 1 with only one element!...
    Node29* LL1 = new Node29(1);
    Node29* headLL1 = LL1;
    Node29* tailLL1 = headLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    cout<<"Singly Linkedlist LL1 : ";
    printNode(headLL1);

    cout<<endl;

    // Creating Linkedlist 2...
    Node29* LL2 = new Node29(1);
    Node29* headLL2 = LL2;
    Node29* tailLL2 = headLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);

    // Inserting more nodes in LL2...
    insertAtAnyPosition(headLL2, tailLL2, 2, 2);
    insertAtAnyPosition(headLL2, tailLL2, 3, 3);
    insertAtAnyPosition(headLL2, tailLL2, 4, 7);
    insertAtAnyPosition(headLL2, tailLL2, 5, 9);
    insertAtAnyPosition(headLL2, tailLL2, 6, 12);
    cout<<"Singly Linkedlist LL2 : ";
    printNode(headLL2);

    cout<<endl;

    // merging the two Linkedlists LL1 and LL2...
    Node29* head = mergeLLs(LL1, LL2);
    cout<<"Final merged Linkedlist : ";
    printNode(head);
} // So overall that is how we merge two linkedlists!

// ---------------------------------------------------------- LECTURE 50 - Palindrome Problem! --------------------------------------------------------------------------------------------------------->
// Question : Check whether the List is a palidrome or not!, we already know what is a palindrome!
// Approach 1 : So here we will proceed with creating an array! and then will copy all the nodes value into the array! and then will apply the array vaala logic to check a palindrome! so is case me SC : o(n) kyunki jitne nodes honge utni space lagegi! and TC : O(n) kyunki ek toh LL traverse krne me O(n) ki TC thi and then reverse krne me O(n) so we will get the final TC : O(n)!
// Lets code this....
#include<iostream>
#include<vector>
using namespace std;

class Node30 {
    public :
    int data;
    Node30* next;

    Node30(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node30() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node30* &head, int data) {
    Node30* temp = new Node30(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node30* &tail, int data) {
    Node30* temp = new Node30(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node30* &head, Node30* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node30* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node30* NodetoInsert = new Node30(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

bool checkPalindrome(vector<int> arr) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(arr[s] != arr[e]) {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(Node30* head) {
    vector<int> arr;
    Node30* temp = head;
    while(temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}

void printNode(Node30* &head) {
    Node30* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist...
    Node30* node = new Node30(1);
    Node30* head = node;
    Node30* tail = head;
    cout<<"First node of LL : ";
    printNode(head);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 3);
    insertAtAnyPosition(head, tail, 4, 2);
    insertAtAnyPosition(head, tail, 5, 1);
    printNode(head);

    if(isPalindrome(head)) {
        cout<<"This Linked List is a Palindrome!";
    }
    else {
        cout<<"Its not a Palindrome!";
    }
} // So yes this is how we do it with approach 1...

// But in the above approach we are taking extra space! so lets try something there different where we could minimize the SC!
// Approach 2 : Isme what we do is hum pehle LL ka mid find krenge and then mid ke next se remaining LL ko reverse krenge and then uske baad ek ek krke first node ko mid ke next node se compare krenge and second node ko mid ke next ke next se compare krenge and so on...
// agar sab same hote hai toh it will be a Palindrome! otherwise not! and then last me vapis LL ko reverse krdenge taki we get our original LL back jo humne compare krne ke liye reverse krdi thi
// lets code this...
#include<iostream>
using namespace std;

class Node31 {
    public :
    int data;
    Node31* next;

    Node31(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node31() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node31* &head, int data) {
    Node31* temp = new Node31(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node31* &tail, int data) {
    Node31* temp = new Node31(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node31* &head, Node31* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node31* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node31* NodetoInsert = new Node31(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node31* getMid(Node31* head) {
    Node31* slow = head;
    Node31* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node31* reverse(Node31* head) {
    Node31* curr = head;
    Node31* prev = NULL;
    Node31* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node31* head) {
    // If the list is empty...
    if(head == NULL || head->next == NULL) {
        return 1;
    }

    // Finding the middle node...
    Node31* mid = getMid(head);

    // Reverse the list after the middle node...
    Node31* temp = mid->next;
    mid->next = reverse(temp);

    // Now lets compare the two halves! for that we will create two pointers! head1 and head2! where head1 will be pointing at the first half of the LL and head2 will pointing at the other half of the LL!
    Node31* head1 = head;
    Node31* head2 = mid->next;
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // Now bss ab vapis LL ko reverse krdo! taki we get our original LL back! hum chaahe toh bina iske bhi humara answer sahi ayega! we just have used this piece of code with a wider perspective! that ki kabhi agar hume future me LL original vaali chahiye! toh thats why we did this! taaki original LL intact rahe!
    temp = temp->next;
    reverse(temp);

    // Now return true agar ye sab hoke uss loop se successfully bahar aa chuke hai toh...
    return true;
}

void printNode(Node31* &head) {
    Node31* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist...
    Node31* node = new Node31(1);
    Node31* head = node;
    Node31* tail = head;
    cout<<"First node of LL : ";
    printNode(head);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 3);
    insertAtAnyPosition(head, tail, 4, 2);
    insertAtAnyPosition(head, tail, 5, 1);
    printNode(head);

    if(isPalindrome(head)) {
        cout<<"This Linked List is a Palindrome!";
    }
    else {
        cout<<"Its not a Palindrome!";
    }
} // Here the TC : O(n) and SC : O(1), so here we have reduced the space complexity! as becoz no extra space is used! but the TC : O(n) kyunki time toh utna hi lag rha hai! kyunki abhi we are traversing the whole LL, pehle mid nikalne me TC : O(n/2) then reverse me TC : O(n), then humne jo comparison kiya hai usme TC : O(n), then lastly firse reverse krne me TC : O(n), so overall our TC : 3*O(n) + O(n/2) = O(n)! 

// ---------------------------------------------------------- LECTURE 51 - Add two numbers represented by a LinkedList! --------------------------------------------------------------------------------------------------------->
// Approach : So here what we will do is, we know LL is like...
// 4->5->NULL
// 3->4->5->NULL, Dono ko add krenge toh we will get, 3->9->0->NULL, but ye ayega kaise, kyunki we know that addition hum right side se krte hai! but LL toh left se like shuru hoti hai toh addition krne ke liye, ya toh hum aisa kuch kre ki 5 ko 5 se add kr paye 4 ko 4 se and then 3 ko 0 se so that we get 390, but vo krenge kaise, so for that we will reverse both the LLs and then add the corresponding elements!
// 5->4->NULL
// 5->4->3->NULL, now on adding them, we will get 0->9->3->NULL, now we will reverse this also! and we will get 390!
// Lets code this....
#include<iostream>
using namespace std;

class Node32 {
    public :
    int data;
    Node32* next;

    Node32(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node32() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node32* &head, int data) {
    Node32* temp = new Node32(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node32* &tail, int data) {
    Node32* temp = new Node32(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node32* &head, Node32* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node32* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node32* NodetoInsert = new Node32(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node32* reverse(Node32* head) {
    Node32* curr = head;
    Node32* prev = NULL;
    Node32* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// This func is created to insert the digit in the answer linkedlist!
void insertAtTail3(Node32* &head, Node32* &tail, int digit) {
    Node32* temp = new Node32(digit);

    // empty list...
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

Node32* addingLLs1(Node32* LL1, Node32* LL2) {
    int carry = 0;
    Node32* ansHead = NULL;
    Node32* ansTail = NULL;
    while(LL1 != NULL && LL2 != NULL) {
        int sum = carry + LL1->data + LL2->data;
        int digit = sum%10;

        // Create node and add it in answer Likedlist!
        insertAtTail3(ansHead, ansTail, digit);

        // Calculating carry...
        carry = sum/10;
        LL1 = LL1->next;
        LL2 = LL2->next;
    }

    // Now ek kaisa aisa bhi hoga jab jo do nodes add ho rhe honge unme se ek NULL hoga, ye kab hoga? jab koi ek list choti ho ya badi ho! tab ek node and NULL ko kaise manage krenge add krna? lets see...
    // When first List is short...
    while(LL1 != NULL) {
        int sum = carry + LL1->data;
        int digit = sum%10;

        // Create node and add it in answer Likedlist!
        insertAtTail3(ansHead, ansTail, digit);

        // Calculating carry...
        carry = sum/10;
        LL1 = LL1->next;
    }

    // When second List is short...
    while(LL2 != NULL) {
        int sum = carry + LL2->data;
        int digit = sum%10;

        // Create node and add it in answer Likedlist!
        insertAtTail3(ansHead, ansTail, digit);

        // Calculating carry...
        int carry = sum/10;
        LL2 = LL2->next;
    }

    // When carry is still remaining after adding all the nodes...
    while(carry != 0) {
        int sum = carry;
        int digit = sum%10;

        // Create node and add it in answer Likedlist!
        insertAtTail3(ansHead, ansTail, digit);
        carry = sum/10;
    }
    return ansHead;
} // But this function have became too lengthy! so we will write another function addingLLs2. where we will combine all these while loops together!

Node32* addingLLs2(Node32* LL1, Node32* LL2) {
    int carry = 0;
    Node32* ansHead = NULL;
    Node32* ansTail = NULL;
    while(LL1 != NULL || LL2 != NULL || carry != 0) {
        int val1 = 0;
        if(LL1 != NULL) {
            val1 = LL1->data;
        }

        int val2 = 0;
        if(LL2 != NULL) {
            val2 = LL2->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum%10;

        // Create node and add it in answer Likedlist!
        insertAtTail3(ansHead, ansTail, digit);

        // Calculating carry...
        carry = sum/10;

        if(LL1 != NULL) {
            LL1 = LL1->next;
        }
        if(LL2 != NULL) {
            LL2 = LL2->next;
        }
    }
    return ansHead;
}

Node32* addTwoLLs(Node32* LL1, Node32* LL2) {
    // Reverse the input Linkedlists!
    LL1 = reverse(LL1);
    LL2 = reverse(LL2);

    // Add the two LLs...
    // Node32* ans = addingLLs1(LL1, LL2); // This has a lengthy code! and has 4 loops!
    Node32* ans = addingLLs2(LL1, LL2); // This has the same logic just with less lines of code and 1 loop

    // Now reverse the answer...
    ans = reverse(ans);
    return ans;
}

void printNode(Node32* &head) {
    Node32* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist LL1...
    Node32* nodeLL1 = new Node32(1);
    Node32* headLL1 = nodeLL1;
    Node32* tailLL1 = headLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(headLL1, tailLL1, 2, 3);
    insertAtAnyPosition(headLL1, tailLL1, 3, 4);
    insertAtAnyPosition(headLL1, tailLL1, 4, 1);
    printNode(headLL1);


    cout<<endl;

    // Creating another Linkedlist LL2...
    Node32* nodeLL2 = new Node32(1);
    Node32* headLL2 = nodeLL2;
    Node32* tailLL2 = headLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(headLL2, tailLL2, 2, 2);
    insertAtAnyPosition(headLL2, tailLL2, 3, 3);
    insertAtAnyPosition(headLL2, tailLL2, 4, 2);
    insertAtAnyPosition(headLL2, tailLL2, 5, 1);
    printNode(headLL2);

    Node32* ans = addTwoLLs(headLL1, headLL2);
    printNode(ans);
} // So that is how we add two numbers represented with LLs!
// TC : O(max(M+N)) & SC : O(max(M,N))... kyunki jiss list me zyada nodes honge uske hisaab se TC ya SC calculate hogi! TC ke case me dono me mila ke time lag rha hai reverse and all operations krne me! and in case of SC ke case me jis LL me zyada elements honge vo zyada spage lega!

// ---------------------------------------------------------- LECTURE 52 - Clone a Linkedlist with Random pointers! --------------------------------------------------------------------------------------------------------->
// Question : Till now we have studied about the linkedlist implementation as, ki ek node me ek data hota hai ek next pointer hota hai jo next node ko point kr rha hota hai! So what this question says is ki bss implementation me change hoga! and that is ki data and next ke alawa ek random pointer bhi hoga jo kisi bhi random nodes ko point kr rha hoga! so then finally jo hume krna hai ki ek aise hi linkedlist ka clone banana hai! mtlb ki as it is ek aur LL banani hai!
// Toh hume aise hi ek LL input me di hui hogi! hume bss uss same Linkedlist ko clone krke output dedena hai!
// Approach : So pehle cheez toh humare input me jo LL hogi usko bina randome pointer ke copy krlenge! and then hum Random pointers copy krna shuru krenge! and vo kaise? so vo aise ki hum harr node pr traverse krenge and dekhenge ki usko randome pointer jahaa point kr rha hai vo node kitni dur hai! toh hum humari LL me bhi uss node ko uss randome vaale pointer ke hisaab se point kraa denge! and will do this for all nodes!
// So isme we will use two loops! ek toh jisse hum saare LLs copy krenge bina random node ke! and then uske andar me ek aur loop chalayenge jiske through hum harr node ke random pointers check krte krte vo randome pointers add krte jayenge!, so in this case the TC : O(n^2), and this is not a very good thing! so we will try to minimize this!...
// So for that lets see another approaches!

// Approach 2 : In this we will again copy the whole LL without the random pointers! and now ab random pointers copy krne ke liye we will use maps! so ye aise ki, suppose you have input LL which has head named as original node and the copied one is called the clone LL which has a head named as clone node! now suppose jo input LL hai usme jo original node hai vo normally next node ko toh point kr hi rha hai but uske saath saath vo node 3 pr bhi point kr rha hai! (using random pointier), so hum inn hi random pointers ko store krlenge inside a map! ki like input LL me kahaa kahaa random pointers kin kin node ko point kr rhe hai, ye cheez humne store krliya map me! so what we will do is...
// jaise humne jo overall LL hai with data and next pointers vo toh copy krliya! ab in case of copying the random node, what we will do is, we will write cloneNode->random = map[originalNode->random]! and similarly we will do it for the whole LL!
// Here humare iss approach se TC : O(n) and SC will also be O(n), kyunki dono me hi hum poori poori linkedlist traverse kr rhe the!
// Lets code this approach!
#include <iostream>
#include <unordered_map>
using namespace std;

class Node33 {
public:
    int data;
    Node33* next;
    Node33* random;

    Node33(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node33() {
        cout << "Memory is free for the node with data " << data << endl;
    }
};

void insertAtHead(Node33* &head, int data) {
    Node33* temp = new Node33(data);
    temp->next = head;
    head = temp;
}

void insertAtTail4(Node33* &head, Node33* &tail, int data) {
    Node33* newNode = new Node33(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtAnyPosition(Node33* &head, Node33* &tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        if (tail == NULL) {
            tail = head; // if the list was empty, now head is also the tail.
        }
        return;
    }

    Node33* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position is out of bounds." << endl;
        return;
    }

    if (temp->next == NULL) {
        insertAtTail4(head, tail, data);
        return;
    }

    Node33* nodeToInsert = new Node33(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

Node33* cloneList(Node33* head) {
    if (!head) return NULL;

    Node33* cloneHead = NULL;
    Node33* cloneTail = NULL;
    Node33* temp = head;

    unordered_map<Node33*, Node33*> oldToNewNode;
    while (temp != NULL) {
        insertAtTail4(cloneHead, cloneTail, temp->data);
        oldToNewNode[temp] = cloneTail;
        temp = temp->next;
    }

    Node33* originalNode = head;
    Node33* cloneNode = cloneHead;
    while (originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

void printNode(const Node33* head) {
    const Node33* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->random) {
            cout << " [Random points to " << temp->random->data << "]";
        }
        cout << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node33* headO = new Node33(1);
    Node33* tailO = headO;

    // Construct the linked list
    insertAtAnyPosition(headO, tailO, 2, 2);
    insertAtAnyPosition(headO, tailO, 3, 3);
    insertAtAnyPosition(headO, tailO, 4, 4);
    insertAtAnyPosition(headO, tailO, 5, 5);

    // Set up random pointers
    headO->random = headO->next->next; // Head's random points to third node
    headO->next->random = headO->next->next->next; // Second node's random points to fourth node
    headO->next->next->random = headO; // Third node's random points back to head

    // Print the original list
    cout << "Original list:" << endl;
    printNode(headO);

    // Clone the list
    Node33* clonedList = cloneList(headO);

    // Print the cloned list
    cout << "Cloned list:" << endl;
    printNode(clonedList);

    return 0;
} // This code is entirely of ChatGPT and is giving the correct answer! its the same approach, bss love babbar ke code se thora alag hai, baaki approach is all same! go through the code to understand it!

// Approach 3 : Upar vaale me SC : O(n) aa rhi thi, iss approach me we will try to minimize this also! so we will not use maps!
// So means here we will change the links!
// Further approach you can see while revision of this topic! till you understood how to actually clone the list! throught the above two approaches! and for now that is enuf!

// ---------------------------------------------------------- LECTURE 53 - Merge Sort in LinkedList --------------------------------------------------------------------------------------------------------->
// We already know what is Merge sort! so bss vhi krna hai yahaa!
// Also we wont change the data! hum sirf links ko change krenge!
// So lets see how...
// Lets code and see...
#include<iostream>
using namespace std;

class Node34 {
    public :
    int data;
    Node34* next;

    Node34(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node34() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node34* &head, int data) {
    Node34* temp = new Node34(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node34* &tail, int data) {
    Node34* temp = new Node34(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node34* &head, Node34* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node34* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node34* NodetoInsert = new Node34(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node34* findMid(Node34* head) {
    Node34* slow = head;
    Node34* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node34* merge(Node34* left, Node34* right) {
    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }
    Node34* ans = new Node34(-1); // dummy node! and iske aage hi poori list ko sort krke lgaa denge and then iss ans ko hi update krke head pr le ayenge! and then finally ans ko hi return krdege!
    Node34* temp = ans;

    // Merge two sorted LL
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node34* mergeSort(Node34* head) { // We will use recursion here!
    // Base case...
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // now in otherwise cases we will break the LL and will apply merge sort recursively!
    // Ab hume LL ko do halves me todna hai, toh ye cheez arrays ke case me toh simple si thi ki mid find kiya and tod diya vahaa se! but in case of LL its a little difficult! ki mid alag se nikalo! so we better use slow and fast vaala method!
    Node34* mid = findMid(head);

    Node34* leftHalf = head;
    Node34* rightHalf = mid->next;
    mid->next = NULL; // Ye isliye kiya taaki left half ka tail NULL ko pint kr rha hai tab hi toh actually do halves me tootegi LL! jab dono LL ke tails NULL ko point kr rhe honge!

    // recursive calls to sort both halves!
    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    Node34* result = merge(leftHalf, rightHalf);
    return result;
}

void printNode(Node34* &head) {
    Node34* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist LL1...
    Node34* node = new Node34(1);
    Node34* head = node;
    Node34* tail = head;
    cout<<"First node of LL1 : ";
    printNode(head);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(head, tail, 2, 3);
    insertAtAnyPosition(head, tail, 3, 4);
    insertAtAnyPosition(head, tail, 4, 1);
    insertAtAnyPosition(head, tail, 5, 0);
    printNode(head);

    Node34* result = mergeSort(head);
    cout<<"Sorted Linkedlist : ";
    printNode(result);
} // So that is we have done sorting using Merge Sort! TC : O(nlogn) and SC : O(logn)

// Question for Homework : Flatten Linkedlis! isme kya hota hai ki kuch aisi LL hoti hai!
// Node1 -> Node2 -> Node3 -> Node4 -> NULL
// and har node ke downward directions me bhi aur nodes linked hai! toh hume kya krna hai ki hume unn sab nodes ko ek seedh me lgaa dena hai! and that is called Flattened Linkedlist!
// For reference visit question name : Flatten A Linkedlist! on codestudio! link is given under Lovebabbar vdo!
// Approach is :
// flatten(head) {
//     node* down = head;
//     down->next = NULL;
//     node* right flatten(head->right);
//     node* ans = merge(down, right);
//     return ans;
// }
// Visit the LB vdo for proper explaination! and try this question while revision!
