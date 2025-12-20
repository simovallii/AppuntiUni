#include<iostream>
#include<iterator>

//Definire la funzione generica count_if che prende in input una sequenza (due iteratori: inizio e fine) 
//e un predicato unario, e restituisce il numero di elementi della sequenza che soddisfano il predicato.

template <typename Iter, typename UnaryFun>
int count_if(Iter begin, Iter end, UnaryFun fun){

    int count = 0;
    for(; begin != end; ++begin){

        if(fun(*begin))
            count++;
    }
    return count;
};

//Definire la funzione generica all_of che prende in input una sequenza (due iteratori: inizio e fine) e
// un predicato unario, e restituisce true se tutti gli elementi della sequenza soddisfano il predicato, false altrimenti.

template <typename Iter, typename UnaryFun>
bool all_of(Iter first, Iter last, UnaryFun fun){
  
        for (; first != last; ++first){
            if(!fun(*first))
                return false;
        }
        return true;
};

//Definire la funzione generica transform che prende in input una sequenza (due iteratori: inizio e fine), un iteratore di destinazione 
//e una funzione unaria, e applica la funzione a tutti gli elementi della sequenza, scrivendo i risultati nella sequenza di destinazione.
template <typename Iter, typename UnaryFun, typename IterOut>
IterOut trasform(Iter first, Iter last,IterOut out, UnaryFun fun){
  
        for (; first != last; ++first, ++out)
            *out = fun(*first);
        return out;
};

//Definire la funzione generica copy_if che prende in input 
//una sequenza (due iteratori: inizio e fine), un iteratore di destinazione 
//e un predicato unario, e copia nella sequenza di destinazione solo gli elementi che soddisfano il predicato.
//La funzione deve restituire l’iteratore alla fine della sequenza di destinazione.

template<typename Iter, typename IterOut, typename UnaryFun>

IterOut copy_if(Iter first, Iter last, IterOut out, UnaryFun fun){
        for(; first != last; ++first){
            if(fun(*first)){
                *out = *first;
                ++out;
            }
        }
    return out;
}

//Definire la funzione generica replace_if che prende in input una sequenza (due iteratori: inizio e fine),
// un predicato unario e un valore, e sostituisce con il valore dato tutti gli elementi della sequenza che soddisfano il predicato.
template <typename Iter, typename UnaryFun, typename Value>

void replace_if (Iter first, Iter last, UnaryFun fun, Value value){
    for(; first != last; ++first ){
        if(fun(*first)){
            *first = value;
        }
    }
};

//Definire la funzione generica for_each che prende in input una sequenza (due iteratori: inizio e fine) 
//e una funzione unaria, e applica la funzione a tutti gli elementi della sequenza.
//La funzione deve restituire la funzione stessa.

template <typename UnaryFun, typename Iter>
UnaryFun for_each(Iter first, Iter last, UnaryFun fun){
    for(; first != last; ++first)
         fun(*first);
    return fun;
}