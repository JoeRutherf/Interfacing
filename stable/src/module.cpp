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
const std::list<std::vector<std::string>>& X)
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
{
std::unordered_map<std::string,std::vector<std::string>> Y_1{marshall_unordered_dictionaries(A)};
std::unordered_map<std::string,std::vector<std::string>> Y_2{marshall_unordered_dictionaries(B)};

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
function("stable_marriage", &stable_marriage);
}





