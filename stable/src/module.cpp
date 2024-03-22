#include "Rcpp.h"
#include "Fundamental.h"
#include "IS_STABLE.h"
using namespace Rcpp;


#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <map> 
#include <functional>
#include <iterator>
#include <algorithm>
#include <random>



std::unordered_map<std::string,std::vector<std::string>> marshall_unordered_dictionaries(
const std::list<std::vector<std::string>>& X)                 // This marshalling function produces an unordered map from taking a list of vectors of strings as an input
{

    
    std::unordered_map<std::string,std::vector<std::string>> Y;
    for(std::vector<std::string> xy_pair : X)
    {
    std::string Z{xy_pair[0]};

        Y[Z]=xy_pair;
        Y[Z].erase(Y[Z].begin());
    }

    return(Y);
}

std::unordered_map<std::string,std::string> stable_marriage(std::list<std::vector<std::string>>& A, std::list<std::vector<std::string>>& B)
{               // This function produces a set of stable marriages when it takes two lists of vectors of strings as inputs
std::unordered_map<std::string,std::vector<std::string>> Y_1{marshall_unordered_dictionaries(A)};
std::unordered_map<std::string,std::vector<std::string>> Y_2{marshall_unordered_dictionaries(B)};

std::unordered_map<std::string,std::string> h;
h = Fundamental(Y_1, Y_2);

std::string j;
j = IS_STABLE(Y_1,Y_2,h);
Rcout << j << std::endl;

return(h);

}




std::unordered_map<std::string,std::vector<std::string>> marshall_vector_list(     //This marshalling takes a vector of strings and a list of vector of strings as inputs and produces a dictionary
const std::vector<std::string>& W, const std::list<std::vector<std::string>>& X)
{
    std::unordered_map<std::string,std::vector<std::string>> Y;

    for(std::vector<std::string> x:X)
    {
        int l;
        l=-1;
        for (std::vector<std::string> y:X)
       {
           l=l+1;
           if(y==x){
                    std::string Z{W[l]};
                     Y[Z]=x;
                   }
       }
    }

    return(Y);
}


std::unordered_map<std::string,std::string> stable_marriage_other(std::list<std::vector<std::string>>& A, std::list<std::vector<std::string>>& B, std::vector<std::string> C, std::vector<std::string> D)                  // This function produces a set of stable marriages when it takes two vectors of strings and two lists of vector of strings as inputs
{
std::unordered_map<std::string,std::vector<std::string>> Y_1{marshall_vector_list(C,A)};
std::unordered_map<std::string,std::vector<std::string>> Y_2{marshall_vector_list(D,B)};

std::unordered_map<std::string,std::string> h;
h = Fundamental(Y_1, Y_2);

std::string j;
j = IS_STABLE(Y_1,Y_2,h);
Rcout << j << std::endl;

return(h);

}




RCPP_MODULE(marshalling) 
{

function("rcpp_marshall_unordered_dictionaries", &marshall_unordered_dictionaries);
function("rcpp_marshall_vector_list", &marshall_vector_list);
function("stable_marriage", &stable_marriage);
function("stable_marriage_other", &stable_marriage_other);
}


