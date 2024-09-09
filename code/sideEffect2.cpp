#include <iostream>
using namespace std;
int count; 
void DoTwo ( ) { 
  	count  = 12; 
  	while (count > 3) {
        	cout<<count<<endl;
        	count  -=  2;
}
}
void DoOne ( ) {
	count  = 1; 
  	while (count < 4) {
	      DoTwo(); 
     	      count++; 
  	}   
}
//lap vo han
void One() { 
	for(count = 1 ; count <=10; count++) { 
            cout<<count<<endl;
     	} 
} 
void  Two() {
	for (count = 10; count >0; count--) { 
	        cout<<count<<endl;
        	One(); 
    	}
}

int main()
{
    // DoOne();
    Two();
}
