TARGET = QtAdMob
VERSION = 1.0.0
TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

IOS_PACKAGE_SOURCE_DIR = $$PWD/platform/ios
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/platform/android

SOURCES += main.cpp

RESOURCES += qml.qrc

DEFINES += QTADMOB_QML

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(QtAdMob/QtAdMob.pri)

android:
{
    android:DISTFILES += \
            $$ANDROID_PACKAGE_SOURCE_DIR/AndroidManifest.xml \
            $$ANDROID_PACKAGE_SOURCE_DIR/build.gradle \
            $$ANDROID_PACKAGE_SOURCE_DIR/src/org/dreamdev/QtAdMob/QtAdMobActivity.java
}

ios:
{
    ios:QMAKE_INFO_PLIST = $$IOS_PACKAGE_SOURCE_DIR/Info.plist
    ios:QMAKE_IOS_DEPLOYMENT_TARGET = 7.0
}

