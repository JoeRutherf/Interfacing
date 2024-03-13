#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<std::string,std::string>  Fundamental(std::unordered_map<std::string,std::vector<std::string>> men_preferences,
std::unordered_map<std::string,std::vector<std::string>> women_preferences){

std::string Z{"Z"};

int n ;
for(auto& w:women_preferences){
        women_preferences[w.first].push_back(Z);  // Adds undesirable man at the end of each woman's preference list
    
n=size(women_preferences[w.first]);    // gives n=number of men (including undesirable man Z)
}

std::unordered_map<std::string,std::string> matchings;     // making the dictionary "matchings"

for(auto& h:women_preferences){
    matchings[h.first]= women_preferences[h.first][n-1]; //Matches each woman initially with their least favourable man
} 

std::vector<std::string>W{};
for(auto& m:men_preferences){
        W.push_back(m.first);
    }
    std::string X{};
int k;
k=0;
int l;
int t;
int o;
std::string x;

for(k=0;k<n-1;k++){
    X=W[k];     // X is the kth man
 while(X!=Z){            // While X is not man Z
      x=men_preferences[X][0];      // x is man X's first preference
                l=-1;
                for(auto& q : women_preferences[x]){
                        l=l+1;
                            if(q==X){
                                t=l;      // woman x's ranking of man X
                            }
                        else if(q==matchings[x]){
                            o=l;       // woman x's ranking of her current partner
                            } 
                    }
                 if(t-o<0){       // If woman x prefers man X over her current partner...
                std::string Y{matchings[x]};    // Y = woman x's old partner
                matchings[x]=X;    // x is now matched with X
                X=Y;               //man X is her old partner, Y
               }
      if(X!=Z){
   men_preferences[X].erase(men_preferences[X].begin());
   }
 }     
}
return(matchings);
}
