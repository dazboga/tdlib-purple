#ifndef _FIXTURE_H_
#define _FIXTURE_H_

#include "test-transceiver.h"
#include "purple-events.h"
#include <gtest/gtest.h>

using namespace td::td_api;

class CommTest: public testing::Test {
public:
    CommTest();

private:
    PurplePlugin      purplePlugin;
protected:
    TestTransceiver      tgl;
    PurpleEventReceiver &prpl = g_purpleEvents;
    PurpleAccount       *account;
    PurpleConnection    *connection;

    const std::string phoneNumber       = "1234567";
    const int         selfId            = 1;
    const std::string selfFirstName     = "Isaac";
    const std::string selfLastName      = "Newton";

    const int32_t     userIds[2]        = {100, 101};
    const int64_t     chatIds[2]        = {1000, 1001};
    const std::string userPhones[2]     = {"00001", "00002"};
    const std::string userFirstNames[2] = {"Gottfried", "Galileo"};
    const std::string userLastNames[2]  = {"Leibniz", "Galilei"};

    void SetUp() override;
    void TearDown() override;
    void login(std::initializer_list<object_ptr<Object>> extraUpdates = {},
               object_ptr<users> getContactsReply = make_object<users>(),
               object_ptr<chats> getChatsReply = make_object<chats>(),
               std::initializer_list<std::unique_ptr<PurpleEvent>> postUpdateEvents = {},
               std::initializer_list<object_ptr<Function>> postUpdateRequests = {},
               std::initializer_list<std::unique_ptr<PurpleEvent>> postLoginEvents = {nullptr});
    void loginWithOneContact();

    object_ptr<updateUser>     standardUpdateUser(unsigned index);
    object_ptr<updateNewChat>  standardPrivateChat(unsigned index);
    PurplePluginProtocolInfo  &pluginInfo();
};

#endif
