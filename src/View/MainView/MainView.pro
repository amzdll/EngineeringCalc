QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Controller/engineering_controller.cc \
    ../../Controller/finance_controller.cc \
    ../../Model/EnigineeringCalculator/Calculator/calculator.cc \
    ../../Model/EnigineeringCalculator/Converter/converter.cc \
    ../../Model/EnigineeringCalculator/Validator/validator.cc \
    ../../Model/EnigineeringCalculator/engineering_calculator_facade.cc \
    ../../Model/FinanceCalculator/finance_calculator_model.cc \
    ../EngineeringCalculator/engineering_calculator.cc \
    ../FinanceCalculator/finance_calculator.cc \
    ../QCustomPlot/qcustomplot.cc \
    main.cc \
    mainwindow.cc

HEADERS += \
    ../../Controller/engineering_controller.h \
    ../../Controller/finance_controller.h \
    ../../Model/EnigineeringCalculator/Calculator/calculator.h \
    ../../Model/EnigineeringCalculator/Converter/converter.h \
    ../../Model/EnigineeringCalculator/Validator/validator.h \
    ../../Model/EnigineeringCalculator/common.h \
    ../../Model/EnigineeringCalculator/engineering_calculator_facade.h \
    ../../Model/FinanceCalculator/finance_calculator_model.h \
    ../EngineeringCalculator/engineering_calculator.h \
    ../FinanceCalculator/finance_calculator.h \
    ../QCustomPlot/qcustomplot.h \
    mainwindow.h

FORMS += \
    ../EngineeringCalculator/engineering_calculator.ui \
    ../FinanceCalculator/finance_calculator.ui \
    mainwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-MainView-Desktop-Debug/MainView.app/Contents/Info.plist \
    ../build-MainView-Desktop-Debug/MainView.app/Contents/PkgInfo \
    ../build-MainView-Desktop-Debug/MainView.app/Contents/Resources/empty.lproj
