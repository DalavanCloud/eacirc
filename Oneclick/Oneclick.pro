TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../EACirc

CONFIG += c++11

SOURCES += \
    src/ConfigParser.cpp \
    src/FileGenerator.cpp \
    src/main.cpp \
    src/OneclickConstants.cpp \
    src/ResultProcessor.cpp \
    src/XMLproc.cpp \
    src/tinyXML/tinystr.cpp \
    src/tinyXML/tinyxml.cpp \
    src/tinyXML/tinyxmlerror.cpp \
    src/tinyXML/tinyxmlparser.cpp \
    ../EACirc/projects/estream/EstreamCiphers.cpp \
    ../EACirc/projects/sha3/Sha3Functions.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    src/ConfigParser.h \
    src/dirent.h \
    src/FileGenerator.h \
    src/FileLogger.hpp \
    src/FileSystem.h \
    src/OneclickConstants.h \
    src/ResultProcessor.h \
    src/Utils.h \
    src/XMLproc.h \
    src/tinyXML/tinystr.h \
    src/tinyXML/tinyxml.h \
    ../EACirc/projects/estream/EstreamCiphers.h \
    ../EACirc/projects/sha3/Sha3Functions.h

DISTFILES += \
    src/tinyXML/tinyXML_LICENCE.txt

