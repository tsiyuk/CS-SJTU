//4-1
#include<iostream>
using namespace std;

int main()
{
    int x, y, z;
    for(x = 1;x <= 4;++x){
        for(y = 1;y <= 4;++y){
            if(100*x+10*y+1+100*y+11==532&&x!=y){
                z = 1;
                cout<<"x="<<x<<endl<<"y="<<y<<endl<<"z="<<z;
                }
            if(100*x+10*y+6+100*y+66==532&&x!=y){
                z = 6;
                cout<<"x="<<x<<endl<<"y="<<y<<endl<<"z="<<z;
            }//z只能等于1或6
        }
    }
    return 0;
}