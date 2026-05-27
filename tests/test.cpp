#include <gtest/gtest.h>

#include "Account.h"
#include "Transaction.h"

TEST(Account, Constructor)
{
    Account account(1, 100);

    EXPECT_EQ(account.id(), 1);
    EXPECT_EQ(account.GetBalance(), 100);
}

TEST(Account, Lock)
{
    Account account(1, 100);

    EXPECT_NO_THROW(account.Lock());
}

TEST(Account, ChangeBalance)
{
    Account account(1, 100);

    account.Lock();
    account.ChangeBalance(50);

    EXPECT_EQ(account.GetBalance(), 150);
}

TEST(Transaction, SetFee)
{
    Transaction transaction;

    transaction.set_fee(10);

    EXPECT_EQ(transaction.fee(), 10);
}

TEST(Transaction, Make)
{
    Transaction transaction;

    Account from(1, 200);
    Account to(2, 100);

    EXPECT_TRUE(transaction.Make(from, to, 100));
}
