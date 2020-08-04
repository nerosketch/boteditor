//
// Created by ns on 8/4/20.
//

#ifndef BOTEDITOR_DIALOGLOGICOUTPUT_H
#define BOTEDITOR_DIALOGLOGICOUTPUT_H

#include <QtCore/QObject>
#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;


class DialogLogicOutput : public NodeDataModel {
Q_OBJECT
public:
    DialogLogicOutput();
    virtual ~DialogLogicOutput();

    QString caption() const override
    {
        return QString("Выход");
    }

    static QString Name()
    { return QString("Выход из диалога"); }

    QString name() const override
    { return DialogLogicOutput::Name(); }

    bool portCaptionVisible(PortType, PortIndex) const override
    { return true; }

    // port type is Out
    unsigned int nPorts(PortType portType) const override;

    QString portCaption(PortType port_type, PortIndex port_index) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(std::shared_ptr<NodeData>, int) override
    { }

    QWidget *embeddedWidget() override { return nullptr; }
};


#endif //BOTEDITOR_DIALOGLOGICOUTPUT_H
