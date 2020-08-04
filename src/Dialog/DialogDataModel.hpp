//
// Created by ns on 7/31/20.
//

#ifndef BOTEDITOR_DIALOGDATAMODEL_HPP
#define BOTEDITOR_DIALOGDATAMODEL_HPP

#include <memory>
#include <QtCore/QObject>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>

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

    bool portCaptionVisible(PortType, PortIndex) const override
    { return true; }

    // port type is Out
    unsigned int nPorts(PortType portType) const override;

    QString portCaption(PortType port_type, PortIndex port_index) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData>, int) override
    { }

    QWidget *embeddedWidget() override;

private Q_SLOTS:

    void onCaptionClicked();
    void onVarsClicked();
    void onDialogOkSignal(QStringList& vars);

private:
    QWidget *_qwidget;
    int _one_dialog_control;
    QStringList _outVars;
    unsigned int vcount;
    QLabel *_label;
};


#endif //BOTEDITOR_DIALOGDATAMODEL_HPP
