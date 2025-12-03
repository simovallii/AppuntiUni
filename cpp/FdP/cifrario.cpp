#include<iostream>
using namespace std;
int main (){
    char a, b, c;
    
    cin >> a >> b >> c;

// controllo di a

    if (a + 13 > 122)
    {
            a =  97 + (( a + 12 ) - 122) ;
    }
    else if (a >= 97 && a <= 122)
   {
            a = a + 13;
   }
    else if (a > 122 || a < 97)
    {
    
            a = 63;
    }


// controllo di b

    if (b+ 13 > 122)
    {
            b = 97 + ((b + 12) - 122) ;
    }
    else if (b >= 97 && b <= 122)
   {
            b = b + 13;
   }
  
    else  if (b > 122 || b < 97)
    {
            b = 63;
    }


    // controllo di c


   if (c + 13 > 122)
    {
            c=  97 + (( c + 12 ) - 122) ;
    } 
    
   else if (c >= 97 && c <= 122)
   {
            c = c + 13;
   }
 
    else if (c > 122 || c < 97)
    {
            c = 63;
    }

    cout << a << " " << b << " " << c <<endl;
    
   



    
    return 0;
}