#include <QApplication>

#include "loginpage.h"
#include "signuppage.h"
#include "homepage.h"
#include "profilepage.h"
#include "infopage.h"
#include "playernamespage.h"
#include "gamepage.h"
#include "replay.h"

#include "Global.h"

int UserID;  // Definition of global variable to store the user's ID.
int GameID;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginPage loginPage;
    SignUpPage signUpPage;
    HomePage homePage;
    ProfilePage profilePage;
    InfoPage infoPage;
    PlayerNamesPage playerNamesPage;
    GamePage gamePage;
    Replay replay;

    QObject::connect(&loginPage, &LoginPage::loggedIn, [&loginPage, &homePage] { loginPage.hide(); homePage.show(); });
    QObject::connect(&loginPage, &LoginPage::signUpRequested, [&] {loginPage.hide(); signUpPage.show();});

    QObject::connect(&signUpPage, &SignUpPage::signedUp, [&] {signUpPage.hide(); homePage.show();});
    QObject::connect(&signUpPage, &SignUpPage::loginRequested, [&] {signUpPage.hide(); loginPage.show();});

    QObject::connect(&homePage, &HomePage::profileRequested, [&] {homePage.hide(); profilePage.show(); profilePage.loadUserHistory();});
    QObject::connect(&homePage, &HomePage::infoRequested, [&] {homePage.hide(); infoPage.show();});
    QObject::connect(&homePage, &HomePage::gameModeChosen, &homePage, &HomePage::hide);
    QObject::connect(&homePage, &HomePage::gameModeChosen, &playerNamesPage, &PlayerNamesPage::show);
    QObject::connect(&homePage, &HomePage::gameModeChosen, &playerNamesPage, &PlayerNamesPage::setGameMode);

    QObject::connect(&playerNamesPage, &PlayerNamesPage::HomeRequested, [&] { playerNamesPage.hide(); homePage.show();});
    QObject::connect(&playerNamesPage, &PlayerNamesPage::startGame, &playerNamesPage, &PlayerNamesPage::hide);
    QObject::connect(&playerNamesPage, &PlayerNamesPage::startGame, &gamePage, &GamePage::show);
    QObject::connect(&playerNamesPage, &PlayerNamesPage::startGame, &gamePage, &GamePage::setGameMode);

    QObject::connect(&gamePage, &GamePage::homeRequested, [&] {gamePage.hide(); homePage.show();});

    QObject::connect(&profilePage, &ProfilePage::homeRequested, [&] {profilePage.hide(); homePage.show();});
    QObject::connect(&infoPage, &InfoPage::homeRequested, [&] {infoPage.hide(); homePage.show();});

    QObject::connect(&profilePage, &ProfilePage::replayRequested, &profilePage , &ProfilePage::hide);
    QObject::connect(&profilePage, &ProfilePage::replayRequested, &replay , &Replay::show);
    QObject::connect(&profilePage, &ProfilePage::replayRequested, &replay , &Replay::start);

    QObject::connect(&replay, &Replay::profileRequested, [&] {replay.hide(); profilePage.show(); profilePage.loadUserHistory();});

    QObject::connect(&profilePage, &ProfilePage::logoutRequested, [&] {profilePage.hide(); loginPage.show();});

    loginPage.show();
    return a.exec();

}
