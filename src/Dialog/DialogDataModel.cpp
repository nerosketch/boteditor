//
// Created by ns on 7/31/20.
//

#include <iostream>
#include <QtWidgets/QPushButton>
#include "DialogDataModel.hpp"
#include "DialogOptionsWindow.hpp"

DialogDataModel::DialogDataModel() : _qwidget(new QWidget)
{
//    connect(_vboxLay, &QVBoxLayout::textEdited,
//            this, &TextSourceDataModel::onTextEdited);



    auto *lay = new QVBoxLayout;
//    auto *_layItem = new QLabel("kduhfskdf");
    auto *_optsBtn = new QPushButton("Настройки");
    connect(_optsBtn, &QPushButton::clicked, this, &DialogDataModel::onOptsClicked);

    auto *_logicBtn = new QPushButton("Поведение");
    auto *_varsBtn = new QPushButton("Варианты");

//    lay->addWidget(_layItem);
    lay->addWidget(_optsBtn);
    lay->addWidget(_logicBtn);
    lay->addWidget(_varsBtn);

    _qwidget->setLayout(lay);
}

DialogDataModel::~DialogDataModel() = default;


unsigned int DialogDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType) {
        case PortType::In:
            result = 0;
            break;

//        case PortType::Out:
//            result = 1;

        default:
            break;
    }

    return result;
}


NodeDataType DialogDataModel::dataType(PortType, PortIndex) const
{
    return NodeDataType {"integer", "Integer"};
}


std::shared_ptr<NodeData> DialogDataModel::outData(PortIndex port)
{
    return std::shared_ptr<NodeData>();
}

QWidget* DialogDataModel::embeddedWidget() {
    return _qwidget;
}


void DialogDataModel::onOptsClicked(bool checked)
{
    DialogOptionsWindow dlg(_qwidget);
//    connect( &dlg, SIGNAL( applied() ), SLOT( onApplied() ) );
    switch( dlg.exec() ) {
        case QDialog::Accepted:
            std::cout << "Accepted" << std::endl;
            break;
        case QDialog::Rejected:
            std::cout << "Rejected" << std::endl;
            break;
        default:
            std::cout << "Unexpected" << std::endl;
    }
}
