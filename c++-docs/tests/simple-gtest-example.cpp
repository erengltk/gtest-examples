#include<gtest/gtest.h>
#include<iostream>
#include <memory>
struct BankAccount
{
int balance=0;
BankAccount()
{
}
explicit BankAccount(const int balance) : balance{balance}
{
}
void deposit(int amount)
{ 
  balance+=amount;
}
bool withdraw(int amount)
{
  if(amount<=balance)
  {
    balance-=amount;
    return true;
  }
  return false;
}

};
struct BankAccountTest :testing::Test
{
  std::shared_ptr<BankAccount> account ;
  BankAccountTest()
  {
  account =std::make_unique<BankAccount>();
  //std::shared_ptr<BankAccount> account(new BankAccount());
 
  }
  virtual ~BankAccountTest()
  {
    
  }
};
struct account_state
{
 int initial_balance;
 int withdraw_amount;
 int final_balance;
 bool success;
};
struct withdrawAccountTest :BankAccountTest, testing::WithParamInterface<account_state>
{
  withdrawAccountTest()
  {
    account->balance=GetParam().initial_balance;
  }

};
TEST_P(withdrawAccountTest,FinalBalance)
{
  auto as = GetParam();
  auto success=account->withdraw(as.withdraw_amount);
  EXPECT_EQ(as.final_balance,account->balance);
  EXPECT_EQ(as.success,success);
}
INSTANTIATE_TEST_CASE_P(Default,withdrawAccountTest,
testing::Values(account_state{100,50,50,true},
                account_state{100,200,100,false}));

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