//
// Created by ns on 7/31/20.
//

#include <iostream>
#include <QtWidgets/QPushButton>
#include "DialogDataModel.hpp"
#include <QInputDialog>
#include "DialogVariantsWindow.hpp"
#include "DialogLogicEditor.hpp"


DialogDataModel::DialogDataModel() :
NodeDataModel(),
_qwidget(new QWidget),
_one_dialog_control(0),
_outVars(),
vcount(0),
_label(new QLabel(tr("Название")))
{
//    connect(_vboxLay, &QVBoxLayout::textEdited,
//            this, &TextSourceDataModel::onTextEdited);



    auto *lay = new QVBoxLayout;
    auto *_captionBtn = new QPushButton("Название");
    connect(_captionBtn, &QPushButton::clicked, this, &DialogDataModel::onCaptionClicked);

    auto *_logicBtn = new QPushButton("Поведение");
    connect(_logicBtn, &QPushButton::clicked, this, &DialogDataModel::onLogicClicked);

    auto *_varsBtn = new QPushButton("Варианты");
    connect(_varsBtn, &QPushButton::clicked, this, &DialogDataModel::onVarsClicked);

    lay->addWidget(_label);
    lay->addWidget(_captionBtn);
    lay->addWidget(_logicBtn);
    lay->addWidget(_varsBtn);

    _qwidget->setLayout(lay);
}

DialogDataModel::~DialogDataModel() = default;


unsigned int DialogDataModel::nPorts(PortType portType) const
{
    switch (portType) {
        case PortType::In:
            return 1;
            break;

        case PortType::Out:
            return vcount;
            break;

        default:
            break;
    }

    return 0;
}

QString DialogDataModel::portCaption(PortType port_type, PortIndex port_index) const
{
    switch (port_type) {
        case PortType::In:
            return QStringLiteral("Вход");
            break;
        case PortType::Out:
            return _outVars.value(port_index);
            break;
        default:
            break;
    }

    return QStringLiteral("Не понятно");
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


void DialogDataModel::onCaptionClicked()
{
    if (_one_dialog_control > 0) {
        return;
    }
    _one_dialog_control ++;

    bool ok;
    QString newCaption = QInputDialog::getText(_qwidget, tr("Изменить название"), tr("Название диалога"), QLineEdit::Normal, _label->text(), &ok);

    if (ok && !newCaption.isEmpty())
    {
        _label->setText(newCaption);
    }
    _one_dialog_control --;
}

void DialogDataModel::onVarsClicked()
{
    if (_one_dialog_control > 0) {
        return;
    }
    _one_dialog_control ++;
    DialogVariantsWindow dlg(_qwidget);
    connect( &dlg, &DialogVariantsWindow::onOkSignal, this, &DialogDataModel::onDialogOkSignal );
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
    _one_dialog_control --;
}

void DialogDataModel::onDialogOkSignal(QStringList& vars)
{
    _outVars = vars;
    vcount = _outVars.size();
    emit portCountChanged();
}

void DialogDataModel::onLogicClicked()
{
    DialogLogicEditor dle(_qwidget);
    dle.open();
}
