#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>

using namespace std;

void makeHeap(int array[], int n, int i){ //heap array, n = size of heap, i = max index
  int max = i;
  int left = i*2 + 1; //if max index = 0, left and right must add one more
  int right = i*2 + 2;

  if(left < n && array[left] > array[max]) //if left greater than max, make left max
    max = left;
  if(right < n && array[right] > array[max]) //same as previous
    max = right;
  if(max != i){ //if max is not root
    swap(array[i], array[max]); //make max i
    makeHeap(array, n, max); //recursively sorts the current sub tree
  }
}

void sort(int array[], int n){
  for(int i = n/2 - 1; i >= 0; i--) //make heap
    makeHeap(array, n, i);
  for(int i = n - 1; i >= 0; i--){ //remove single int from heap
    swap(array[0], array[i]); //move current root to end
    makeHeap(array, i, 0); //sort remaining
  }
}

void printHeap(int array[], int n){ //print out heap w/ double the int per line
  //cout<<n<<endl;
  for(int i = 0; i < n; i++){
    cout << array[n-(i+1)] << " ";
    /*for(int j = pow(2,i-1); j <= pow(2,i); j++){
      cout << array[j-1] << " ";
      }
      cout << endl;*/
  }
}

int main(){
  char* input = new char[10];

  cout << "File or Manual input?" << endl;
  cin.get(input, 10);
  cin.clear();
  cin.ignore(100, '\n');

  if(strcmp(input, "file") == 0){
    int i = 0;
    char* fileCount = new char[10];
    char* filepath = new char[200];
    cout << "Enter file name: ";
    cin.get(filepath, 200);
    cin.clear();
    cin.ignore(100, '\n');

    cout << "How many integers are in the file?" << endl;
    cin >> fileCount;
    cin.clear();
    cin.ignore(100, '\n');
    int harray[atoi(fileCount)];
    
    ifstream File;
    File.open(filepath);
    
    while(!File.eof()){
      File >> harray[i];
      i++;
    }

    File.close();

    int n = sizeof(harray)/sizeof(harray[0]);
    sort(harray, n);
    cout << "Sorted." << endl;
    printHeap(harray, n);
    
  }
  if(strcmp(input, "manual") == 0){
    int i = 0;
    int lol = 0;
    char* exitCon = new char[10];
    cout << "How many numbers will you enter? " << endl;
    cin >> exitCon;
    cin.clear();
    cin.ignore(100, '\n');
    int harray[atoi(exitCon)];
    while(lol != atoi(exitCon)){
      char* num = new char[10];
      cout << "Enter a number between 1 and 1000: ";
      cin >> num;
      cin.clear();
      cin.ignore(100, '\n');
      harray[i] = atoi(num);
      i++;
      lol++;
    }

    

    int n = sizeof(harray)/sizeof(harray[0]);
    
    sort(harray, n);
    cout << "Sorted." << endl;
    printHeap(harray, n);
  }

}
  
