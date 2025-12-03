#include<memory>
#include<iostream>
void maybe_print ( std :: weak_ptr <int > wp ) {
if ( auto sp2 = wp . lock ())
std :: cout << * sp2 ;
else
std :: cout << "non␣pi`u␣ disponibile ";
}
void foo () {
std :: weak_ptr <int > wp ;
{
auto sp = std :: make_shared <int >(42);
wp = sp ; // wp non incrementa il reference count
* sp = 55;
maybe_print ( wp ); // stampa 55
} // sp viene distrutto , insieme alla risorsa
maybe_print ( wp ); // stampa " non pi`u disponibile "
}

int main (){
    std :: weak_ptr <int> pj;
    maybe_print(pj);
}