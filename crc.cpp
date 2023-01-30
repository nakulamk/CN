
#include<bits//stdc++.h>
using namespace std;

string crc(string data, string poly, bool errChk){
    string rem = data;
    if(!errChk){
      for(int i = 0; i < poly.length()-1; i++){
        rem.append("0");
      }
    }
    cout<< "the rem before is "<< rem<<endl;
    
    for(int i = 0; i < rem.length()-poly.length()+1; i++){
        if(rem[i] == '1'){
            for(int j = 0; j < poly.length(); j++){
                if(rem[i+j] == poly[j]){
                    rem[i+j] = '0';
                }
                else{
                    rem[i+j] = '1';
                }
            }
        }
    }
    // ''''''''''''''''''''''''''''''''
    cout<<rem<<endl;
    cout<< rem.substr(rem.length()-poly.length()+1)<<endl;
    return rem.substr(rem.length()-poly.length()+1);
    // substr is predefined function used for string handling
}   

int main(){
  string data, poly;

  cout << "Enter the data to be sent in binary: ";
  cin >> data;

  cout << "Enter gererating polynomial in binary: ";
  cin >> poly;

  string rem = crc(data, poly, 0);
  string codeword = data+rem;
  cout << "Remainder : " << rem << endl;
  cout << "Codeword : " << codeword << endl;

  //Error checking
  string newCodeword;
  cout << "Enter data that is recieved : ";
  cin >> newCodeword;
  string newRem = crc(newCodeword, poly, 1);

  if(stoi(newRem) == 0){
    // The stoi() is a standard library function that turns a string into an integer.
    cout << "No error in data transmission" << endl;
  }
   else{
    cout << "Error in data transmission" << endl;
  }  
      
}