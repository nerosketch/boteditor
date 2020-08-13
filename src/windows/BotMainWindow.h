/********************************************************************************
** Form generated from reading UI file 'designerTT9149.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BOTEDITOR_BOTMAINWINDOW_H
#define BOTEDITOR_BOTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
//    QWidget *widget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow);

    void retranslateUi(QMainWindow *MainWindow);

};

namespace Ui {
    class MainWindow: public Ui_MainWindow, public QMainWindow {
    public:
        MainWindow();
        ~MainWindow() override;

    };
} // namespace Ui

QT_END_NAMESPACE

#endif // BOTEDITOR_BOTMAINWINDOW_H
