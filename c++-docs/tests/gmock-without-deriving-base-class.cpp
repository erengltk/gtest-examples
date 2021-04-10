#include<iostream>
#include<vector>
#include<gtest/gtest.h>
#include<gmock/gmock.h>
using namespace std;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

class DataBaseConnect
{
public:
    virtual bool login(std::string username,std::string password) 
    {
    return true;
    }
    virtual bool logout(std::string username)
    {
    return true;
    }
    virtual int fetchRecord()
    {
    return -1;
    }
};
class MOCKDataBaseConnect : public DataBaseConnect
{
public:
    MOCK_METHOD0(fetchRecord,int());
    MOCK_METHOD1(logout,bool(std::string username));
    MOCK_METHOD2(login,bool(std::string username,std::string password));
};
class myDataBase
{
    DataBaseConnect &dbC;
public:
    myDataBase(DataBaseConnect &_dbC ) :dbC(_dbC)
    {}
    int Init(std::string username,std::string password)
    {
        if(dbC.login(username,password)!= true)
        {
            std::cout<<"DB FAILURE"<<std::endl;
            return -1;
        }
        else
        {
            return 1;
        }
    }

};
TEST(myDataBaseT,LoginTest)
{
   MOCKDataBaseConnect MockDBC;
   myDataBase myDB(MockDBC);
   EXPECT_CALL(MockDBC,login("TrueUs","TruePassw"))
   .Times(1)
   .WillOnce(Return(true));

   int returnValue=myDB.Init("TrueUs","TruePassw");

   EXPECT_EQ(returnValue,1);

}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }