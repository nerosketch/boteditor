//
// Created by ns on 8/13/20.
//

#include "BotMainWindow.h"

QT_BEGIN_NAMESPACE

void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(905, 678);
    action = new QAction(MainWindow);
    action->setObjectName(QStringLiteral("action"));
    action_3 = new QAction(MainWindow);
    action_3->setObjectName(QStringLiteral("action_3"));
    action_4 = new QAction(MainWindow);
    action_4->setObjectName(QStringLiteral("action_4"));
    action_5 = new QAction(MainWindow);
    action_5->setObjectName(QStringLiteral("action_5"));
    action_6 = new QAction(MainWindow);
    action_6->setObjectName(QStringLiteral("action_6"));
    action_7 = new QAction(MainWindow);
    action_7->setObjectName(QStringLiteral("action_7"));
    action_8 = new QAction(MainWindow);
    action_8->setObjectName(QStringLiteral("action_8"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QStringLiteral("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    horizontalLayout = new QHBoxLayout();

    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    verticalLayout->addLayout(horizontalLayout);
    treeWidget = new QTreeWidget(verticalLayout->widget());
    QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
    QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
    new QTreeWidgetItem(__qtreewidgetitem1);
    new QTreeWidgetItem(__qtreewidgetitem);
    new QTreeWidgetItem(treeWidget);
    treeWidget->setObjectName(QStringLiteral("treeWidget"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
    treeWidget->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(treeWidget);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 905, 24));
    menu = new QMenu(menubar);
    menu->setObjectName(QStringLiteral("menu"));
    menu_2 = new QMenu(menubar);
    menu_2->setObjectName(QStringLiteral("menu_2"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QStringLiteral("statusbar"));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menu->menuAction());
    menubar->addAction(menu_2->menuAction());
    menu->addAction(action_5);
    menu->addAction(action_6);
    menu->addAction(action_7);
    menu_2->addAction(action_4);
    menu_2->addAction(action_8);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
} // setupUi


void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    action->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
    action_3->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
    action_4->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
    action_5->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
    action_6->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
    action_7->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
    action_8->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
    QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
    ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "1", Q_NULLPTR));

    const bool __sortingEnabled = treeWidget->isSortingEnabled();
    treeWidget->setSortingEnabled(false);
    QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
    ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
    QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
    ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "New Subitem", Q_NULLPTR));
    QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
    ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "New Subitem", Q_NULLPTR));
    QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(1);
    ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
    QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(1);
    ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
    treeWidget->setSortingEnabled(__sortingEnabled);

    menu->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    menu_2->setTitle(QApplication::translate("MainWindow", "Types", Q_NULLPTR));
} // retranslateUi


Ui::MainWindow::MainWindow()
{
    setupUi(this);
}

Ui::MainWindow::~MainWindow() = default;


QT_END_NAMESPACE
