//
// Created by ns on 8/4/20.
//

#ifndef BOTEDITOR_DIALOGLOGICINPUT_H_UNUSED
#define BOTEDITOR_DIALOGLOGICINPUT_H_UNUSED

#include <QtCore/QObject>
#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;

class DialogLogicInput : public NodeDataModel {
Q_OBJECT
public:
    DialogLogicInput();
    virtual ~DialogLogicInput();

    QString caption() const override
    {
        return QString("Вход");
    }

    static QString Name()
    { return QString("вход в диалог"); }

    QString name() const override
    { return DialogLogicInput::Name(); }

    bool portCaptionVisible(PortType, PortIndex) const override
    { return true; }

    // port type is In
    unsigned int nPorts(PortType portType) const override;

    QString portCaption(PortType port_type, PortIndex port_index) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(std::shared_ptr<NodeData>, int) override
    { }

    QWidget *embeddedWidget() override { return nullptr; }
};


#endif //BOTEDITOR_DIALOGLOGICINPUT_H_UNUSED
