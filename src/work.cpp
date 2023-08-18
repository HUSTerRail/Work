
#include<bits/stdc++.h>
using namespace std;

int main(){

    string a;
    string word;
    vector<string>str;
    cin >> a;
    a +=':';
    for(int i=0; i<a.length(); i++){

        if(a[i] == ':'){
            if(word.length() <=4 && word.length() > 0){
                str.push_back(word);
                if(str.size() > 8){
                     cout << "No";
                    return 0;
                }
                word = "";
            }else{
                 cout << "No";
                return 0;
            }
            
        }else{
            if((a[i] >= '0' && a[i] <= '9')  ||  (a[i] >= 'A' && a[i] <= 'F') ||  (a[i] >= 'a' && a[i] <= 'f')){
                 word += a[i];
            }else{
                cout << "No";
                return 0;
                
            }
           
        }
    }
    
    
    cout << "Yes";
    return 0;
}
