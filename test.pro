#-------------------------------------------------
#
# Project created by QtCreator 2017-11-29T15:20:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parametregrille.cpp \
    pageacceuil.cpp \
    pagenouvellepartie.cpp \
    bdd.cpp \
    bddjoueur.cpp

HEADERS  += mainwindow.h \
    parametregrille.hpp \
    pageacceuil.hpp \
    pagenouvellepartie.h \
    bdd.h \
    bddjoueur.h

FORMS    += mainwindow.ui \
    pageacceuil.ui \
    pagenouvellepartie.ui \
    bdd.ui \
    bddjoueur.ui

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
