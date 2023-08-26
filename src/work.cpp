#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m, tmp, q;
    cin >> q;
    
    int flag = 0;
    vector<int>a;
    vector<int>b;
    for(int w = 0; w<q; w++){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> tmp;
            a.push_back(tmp);
        }

        for(int i=0; i<n; i++){
            cin >> tmp;
            b.push_back(tmp);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i=0; i<n; i++){
            if(a[i] + b[n-1-i] < 0 || a[i] + b[n-1-i]>m){
                cout<<i<<" "<<a[i]<<":"<< b[n-1-i]<<endl;
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            cout<<"No"<<endl;
            flag = 0;
        }else{
            cout << "Yes";
        }
        a = vector<int>();
        b = vector<int>();
    }
    




   

    return 0;
}
