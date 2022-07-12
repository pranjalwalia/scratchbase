TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dbmanagement-tests.cpp

include(../scratchbase/Defines.pri)

#macx:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../scratchbase/ -lscratchbase
#else:macx:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../scratchbase/ -lscratchbase

HEADERS += \
    catch.hpp \
    tests.h
