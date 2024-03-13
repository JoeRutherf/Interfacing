#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

std::string IS_STABLE(std::unordered_map<std::string,std::vector<std::string>> men_preferences,
std::unordered_map<std::string,std::vector<std::string>> women_preferences,
std::unordered_map<std::string,std::string> pairings){

std::vector<int> V{};
for(auto& r : pairings)
{
    std::string b{r.first}; //b = man in each pairing
    std::string w{r.second}; //w = woman in each pairing

int j;
j=-1;

for (auto& p : men_preferences[b])
{
    j=j+1;
    if (p == pairings[b])
    {
        int k;
        k=j;
        if (k==0){
    V.push_back(0); 
        }
        else{
                    std::vector<std::string> U{};
        for(int f=0;f<k;f++){
            U.push_back(men_preferences[b][f]);  // U - vector of women preferred by man m over wife w
            }
        for(auto& u:U){      
        for(auto& m:women_preferences[u]){
            if(pairings[m]==u){  // finding man m who is matched with woman u
                int l;
                int n;
                int o;
                l=-1;
                for (auto& q : women_preferences[u])
                    {
                        l=l+1;
                            if(q==m){
                                n=l;
                            }
                        else if(q==b){
                            o=l;
                            } 
                    }
               if(n-o<0){
                   V.push_back(0);    // if woman u prefers her partner m to man b, assign 0
               }
                else{
                    V.push_back(1);
                }
        }     
        } 
        }
        }
    }
}
}
int z;
z=0;
for(auto& v:V){
z=z+v;
}

if(z==0){
    return("Stable");}
else{
    return("Not Stable");
}
}
