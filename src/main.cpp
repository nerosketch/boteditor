//#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMenuBar>

#include <nodes/DataModelRegistry>
#include <QtCore/QTranslator>
#include<QDebug>

#include "TextSourceDataModel.h"
//#include "TextDisplayDataModel.hpp"
#include "Dialog/DialogDataModel.h"

#include "windows/BotMainWindow.h"

using QtNodes::DataModelRegistry;
using QtNodes::FlowView;
using QtNodes::FlowScene;

static std::shared_ptr<DataModelRegistry>
registerDataModels()
{
    auto ret = std::make_shared<DataModelRegistry>();

    ret->registerModel<TextSourceDataModel>();

//    ret->registerModel<TextDisplayDataModel>();

    ret->registerModel<DialogDataModel>();

    return ret;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator myTranslator;
    qInfo() << "boteditor_" << QLocale::system().name();
//    myTranslator.load("boteditor_" + QLocale::system().name(), "translates");
    myTranslator.load("boteditor_ru.qm", "translates");
    QApplication::installTranslator(&myTranslator);

    Ui::MainWindow mw;
    auto *l = mw.horizontalLayout;

    /*auto menuBar    = new QMenuBar();
    auto saveAction = menuBar->addAction("Save..");
    auto loadAction = menuBar->addAction("Load..");
    auto *l = new QVBoxLayout(mainWidget);
    l->addWidget(menuBar);*/

    auto* scene = new FlowScene(registerDataModels(), &mw);

    auto *fv = new FlowView(scene);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(fv->sizePolicy().hasHeightForWidth());
    fv->setSizePolicy(sizePolicy1);
    l->addWidget(fv);
    l->setContentsMargins(0, 0, 0, 0);
    l->setSpacing(0);

    mw.show();
    return app.exec();
}
