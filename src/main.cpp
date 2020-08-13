//#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMenuBar>

#include <nodes/DataModelRegistry>

#include "TextSourceDataModel.h"
//#include "TextDisplayDataModel.hpp"
#include "Dialog/DialogDataModel.h"

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

    QWidget mainWidget;

    auto menuBar    = new QMenuBar();
    auto saveAction = menuBar->addAction("Save..");
    auto loadAction = menuBar->addAction("Load..");
    auto *l = new QVBoxLayout(&mainWidget);
    l->addWidget(menuBar);

    auto* scene = new FlowScene(registerDataModels(), &mainWidget);

    l->addWidget(new FlowView(scene));
    l->setContentsMargins(0, 0, 0, 0);
    l->setSpacing(0);

    QObject::connect(saveAction, &QAction::triggered,
            scene, &FlowScene::save);

    QObject::connect(loadAction, &QAction::triggered,
            scene, &FlowScene::load);
    
    mainWidget.setWindowTitle("Редактор для бота");
    mainWidget.resize(800, 600);
    mainWidget.showNormal();

    return app.exec();
}
