#include "BaseSocket.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Return;
using ::testing::_;

class BaseSocketMock
{
public:
    static BaseSocketMock *getInstance()
    {
        if (instance == NULL)
            instance = new BaseSocketMock();
        return instance;
    }
    static void destroyInstance()
    {
        if (instance)
        {
            delete instance;
            //must having, or will fail bc of sencond test getInstance is deleted instance
            instance = NULL;

        }
    }


    MOCK_METHOD3(socket, int(int, int, int));
    MOCK_METHOD5(setsockopt, int(int, int, int, const void *, socklen_t));
    //issue:const sockaddr *'s const should be there, or it will not overwrite system call bind(...const sockaddr *...)
    MOCK_METHOD3(bind, int(int, const sockaddr *, int));

protected:
    static BaseSocketMock *instance;
};

#define mock_instance (*BaseSocketMock::getInstance())

BaseSocketMock* BaseSocketMock::instance = NULL;

int socket(int domain, int type, int protocol)
{
    return mock_instance.socket(domain, type, protocol);
}

int setsockopt(int sockfd, int level, int optname, 
              const void *optval, socklen_t optlen)
{
    return mock_instance.setsockopt(sockfd, level, optname,
                                    optval, optlen);
}

int bind(int soc, const sockaddr *add, socklen_t len)
{
    return mock_instance.bind(soc, add, len);
}


class BaseSocket_test : public testing::Test
{
public:
    virtual void SetUp() {
    }

    virtual void TearDown()
    {
       BaseSocketMock::destroyInstance();
    }
};

TEST_F(BaseSocket_test, create_success)
{
    BaseSocket bs;
    EXPECT_CALL(mock_instance, socket(_,_,_)).WillOnce(Return(1));
    EXPECT_CALL(mock_instance, setsockopt(_,_,_,_,_)).WillOnce(Return(1));
    bool created = bs.create();
    EXPECT_EQ(true, created); 
};

TEST_F(BaseSocket_test, create_sock_fail)
{
    BaseSocket bs;
    EXPECT_CALL(mock_instance, socket(_,_,_)).WillOnce(Return(-1));
    bool created = bs.create();
    EXPECT_EQ(false, created); 
    
}

TEST_F(BaseSocket_test, create_setsock_fail)
{
    BaseSocket bs;
    EXPECT_CALL(mock_instance, socket(_,_,_)).WillOnce(Return(1));
    EXPECT_CALL(mock_instance, setsockopt(_,_,_,_,_)).WillOnce(Return(-1));
    bool created = bs.create();
    EXPECT_EQ(false, created); 
    
}

TEST_F(BaseSocket_test, bind_fail)
{
    BaseSocket bs;
    EXPECT_CALL(mock_instance, bind(_,_,_)).WillOnce(Return(-1));
    bool ret = bs.bind1(1);
    EXPECT_EQ(false, ret); 
    
}
