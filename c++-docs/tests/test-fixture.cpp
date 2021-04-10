#include<gtest/gtest.h>
class Foo
{   
    public:
    int f=0;
};
 

class TestFixture : public testing::Test
{
    void SetUp()
    {
        std::cout<<"test started"<<std::endl;
    }

    void TearDown()
    {
        std::cout<<"test finished"<<std::endl;
    }
public:
    Foo f;

};

TEST_F(TestFixture,initalValueTest)
{
ASSERT_EQ(0,f.f);
}

int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }