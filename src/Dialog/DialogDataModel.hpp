//
// Created by ns on 7/31/20.
//

#ifndef BOTEDITOR_DIALOGDATAMODEL_HPP
#define BOTEDITOR_DIALOGDATAMODEL_HPP

#include <memory>
#include <QtCore/QObject>
#include <QtWidgets/QVBoxLayout>

#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;


class DialogDataModel : public NodeDataModel {
Q_OBJECT
public:
    DialogDataModel();
    virtual ~DialogDataModel();

    QString caption() const override
    {
        return QString("Диалог");
    }

    static QString Name()
    { return QString("Диалог квеста"); }

    QString
    name() const override
    { return DialogDataModel::Name(); }

    // port type is Out
    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData>, int) override
    { }

    QWidget *embeddedWidget() override;

private Q_SLOTS:

    void onOptsClicked(bool checked = false);

private:
    QWidget *_qwidget;

};


#endif //BOTEDITOR_DIALOGDATAMODEL_HPP
