#include <iostream>
#include<cstdio>
#include<tuple>
#include<sstream>
#include<memory>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <gtest/gtest.h>
using namespace boost;
using namespace std;
    class SingletonDatabase
    {
        SingletonDatabase()
        {
            std::cout<<"Initializing database\n";
            ifstream ifs("capitals.txt");
            string s, s2;
            while(getline(ifs,s))
            {
                getline(ifs,s2);
                int pop=lexical_cast<int>(s2);
                capitals[s]=pop;
            }

        }
        map<string,int> capitals;
    public:
        SingletonDatabase(SingletonDatabase const&)= delete;
        void operator=(SingletonDatabase const&)= delete;
        
        static SingletonDatabase& get()
        {
            static SingletonDatabase db;
            return db;
        }
        int get_population(const string &name)
        {
            return capitals[name];
        }

    };
    struct SingletonRecordFinder
    {
        int return_total_population(vector<string> names)
        {
            int result{0};
            for(auto &name:names)
            {
                result+=SingletonDatabase::get().get_population(name);
            }
            return result;
        }
    };

    

     
