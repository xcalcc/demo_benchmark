#include <stdio.h>
#include <iostream>

class City{
public:
    //成员变量
    char *cityName;
    unsigned int iPM25;

    City(char *name)
    { 
        cityName = name;
    }    

    void reportPM25(){
        if (NULL == cityName)
            std::cout<<"city name is Null pointer"<<std::endl;  
	else
            std::cout<<cityName<<"'s Air Quality PM2.5 = "<<iPM25<<std::endl;
    }
};
