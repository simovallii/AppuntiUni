#include<iostream>
#include<map>
#include<iterator>
#include<string>

using wordFreq = std::map<std::string, unsigned long>;

int main(){

    wordFreq wf; 
    std::istream_iterator<std::string> i (std::cin);
    std::istream_iterator<std::string> iend;

    for (; i != iend; ++i){
    ++wf[*i];
    }

    for(const auto& iter : wf){
        std::cout<< "la parola " << iter.first << " occorre " << iter.second << " volte" << std::endl;
    }
    }