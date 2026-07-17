QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamepage.cpp \
    homepage.cpp \
    infopage.cpp \
    loginpage.cpp \
    main.cpp \
    playernamespage.cpp \
    profilepage.cpp \
    replay.cpp \
    signuppage.cpp

HEADERS += \
    Global.h \
    gamepage.h \
    homepage.h \
    infopage.h \
    loginpage.h \
    playernamespage.h \
    profilepage.h \
    replay.h \
    signuppage.h

FORMS += \
    gamepage.ui \
    homepage.ui \
    infopage.ui \
    loginpage.ui \
    playernamespage.ui \
    profilepage.ui \
    replay.ui \
    signuppage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    tst_test1.qml
