#include<gtest/gtest.h>

struct BankAccount
{
int balance=0;
BankAccount()
{
}
explicit BankAccount(const int balance) : balance{balance}
{
}

};
TEST(BankAccount,InitalStartsEmpty)
{
  BankAccount account;
  EXPECT_EQ(0,account.balance);
}


  int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }