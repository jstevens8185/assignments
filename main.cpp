#include <iostream>
#include <string>
#include <fstream> 

using namespace std;


struct Node{
  string word;
  Node* Next;
  Node(string w){
    word = w;
    Next = NULL;
  }
};

class Dictionary {
private:
  Node* Start;

  string LowerCase(string input){
    for(int i=0;i<input.length();i++){
      if((int)input[i] < 96){
        input[i] += 32;
      }
    }
    return input;
  }


public:

  Dictionary(){
    Start = NULL;
  }

  void Add(string word){

    word = LowerCase(word);
    // create new memory
    Node* temp = new Node(word);
  
    // if list is empty hook in new Node
    if(Start == NULL){
      Start = temp;
    }else{
      // get ready to walk the list
      Node* traverse = Start;
      while(traverse->Next != NULL){
        // walks the list
        traverse = traverse->Next;
      }
      // now at proper place to link in new memory
      traverse->Next = temp;
    }
  }

  string Remove(string key){
    string temp = "";

    if(!Start){
      return "";
    }else{
      Node* cCurrent = Start;
      Node* prev = Start;
      while(cCurrent && cCurrent->word != key){
        prev = cCurrent;
        cCurrent = cCurrent->Next;
      }
      // if cCurrent then we found the word
      if(cCurrent){
        temp = cCurrent->word;
        prev->Next = cCurrent->Next;
        delete cCurrent;
      }else{
        // no word, return empty
        temp = "";
      }
      return temp;
    }


    return temp;
  }

  void ReOrder(){
    // pointers for new list
    Node* NewList = NULL;
    Node* Tail=NULL;

    int i;
//Start will never be NULL
    while(Start->Next != NULL){

    // helper pointers to manipulate lists
    Node* Current = Start;
    Node* Min = Start;
    Node* Prev = Start;
    Node* MinPrev = Start;
   

      // find one minimum word in old list
      while(Current->Next != NULL){
        if(Current->word < Min->word){
          MinPrev = Prev;
          Min = Current;
        }

        Prev = Current;
        Current = Current->Next;
      }
      //end finding one word in old list

      // add one word to new list

      if(!NewList){
        NewList = Min;
      }else{
        Tail->Next = Min;
      }

      Tail = Min;
      if(MinPrev == Start){
        Start = Start->Next;
      }else{
        MinPrev->Next = Min->Next;
      }
      
      Min->Next = NULL;
  }
      // i++;

      // if(i>=6){
      //   break;
      // }
      // adding one word to new list

      // Node* Temptemptmemp = NewList;

      // while(Temptemptmemp){
      //   cout<<Temptemptmemp->word<<" ";
      //   Temptemptmemp = Temptemptmemp->Next;
      // }
      // cout<<endl;
   

   Start = NewList;


  }

  void Print(){
    Node* temp = Start;
    while(temp){
      cout<<temp->word;
      if(temp->Next){
        cout<<"->";
      }
      temp = temp->Next;
    }
    cout<<endl;
  }



};
/////////////////////////////////////////////////////

int main() {
  Dictionary W;
  ifstream fin("dictionary.txt");
  string word;

  // while(fin>>word){
  //   W.Add(word);
  // }

  W.Add("Ant");
  W.Add("Dog");
  W.Add("Aaron");
  W.Add("Aardvark");
  W.Add("Cow");
  W.Add("Rabbit");


  W.Print();

  W.ReOrder();

  W.Print();

}