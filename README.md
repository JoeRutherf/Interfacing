# Interfacing
Interfacing c++ to R coursework

### TASK 1

The function stable_marriage is included in the R package called stable. The stable_marriage function takes as inputs a list of vector of strings that represent everyone's preferences, and outputs a dictionary that maps each man to each woman so they are all stable marriages depending on the preference tables. 

### TASK 2

The R package called stable has been updated onto Github so it can be extracted, installed and used by others.

Inside the folder called stable is a file called DESCRIPTION that gives a basic description of the stable package and other information such as the package maintainer details. There is also a file called NAMESPACE that lists the dependencies of the package.

Inside the folder called R in the stable folder is an R-file called load_Rcpp_module.R that loads Rcpp modules into the R session. There is also the R-file called random_table.R which is a function that I made to randomly change the order of vectors in a list; this is later used in TASK 4.

Inside the folder called src in the stable folder is are many files. The file module.cpp contains the code that very importantly contains the functions stable_marriage and stable_marriage_other to find the set of stable matchings of preference tables, using the Fundamental Algorithm from the header and source files Fundamental.h and Fundamental.cpp respectfully, which are also included in this folder. The folder also contains the header and source files IS_STABLE.h and IS_STABLE.cpp which are used in the module.cpp file to determine whether the matchings are truly stable. The final file in this folder is Makevars, which configures the way that the R package gets constructed, in this case by using c++17.

To extract the stable function into R from my Github repository, you ned to put the following code into R to use it:

```
install.packages("Rcpp")
library(Rcpp)
install.packages("devtools")
devtools::install_github("JoeRutherf/Interfacing/stable",force=TRUE)
library(stable)
```

#### TASK 3

The table and explanations required for task 3 can be found in the Interfacing folder in the document called Interfacing_part_3.pynb .

#### TASK 4

The R file stable-github.ipynb explains how I was able to incorporate capability, error checking and random pertubations to the stable_marriage function in the package, and also shows examples of the package in work. 
