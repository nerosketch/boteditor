//#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include <QtWidgets/QApplication>

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

    FlowScene scene(registerDataModels());

    FlowView view(&scene);

    view.setWindowTitle("Редактор для бота");
    view.resize(800, 600);
    view.show();

    return app.exec();
}
