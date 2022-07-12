TEMPLATE = subdirs

SUBDIRS += \
    scratchbase \
    scratchbase-cli \
    scratchbase-tests

scratchbase-tests.depends = scratchbase
scratchbase-cli.depends = scratchbase

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=

HEADERS +=
