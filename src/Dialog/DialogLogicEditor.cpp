//
// Created by ns on 8/4/20.
//
#include <iostream>
#include <memory>
#include <QtWidgets/QVBoxLayout>
#include <nodes/DataModelRegistry>
#include "DialogLogicInput.h"
#include "DialogLogicOutput.h"
#include "DialogLogicEditor.h"

using QtNodes::DataModelRegistry;

static std::shared_ptr<DataModelRegistry>
registerDataModels()
{
    auto ret = std::make_shared<DataModelRegistry>();

    ret->registerModel<DialogLogicInput>();

    ret->registerModel<DialogLogicOutput>();

    return ret;
}


DialogLogicEditor::DialogLogicEditor(QWidget *parent) : QDialog(parent),
                                                        scene(registerDataModels(), parent)
{
    setWindowTitle("Редактор для логики");
    resize(400, 300);

    auto *pvl = new QVBoxLayout;

    p_view = new FlowView(&scene);
    pvl->addWidget(p_view);

    setLayout(pvl);
//    view.show();
}


DialogLogicEditor::~DialogLogicEditor()
{
    delete p_view;
}


void DialogLogicEditor::open()
{
    std::cout << "DialogLogicEditor::open()" << std::endl;
//    p_view->show();
    exec();
//    QDialog::show();
}
