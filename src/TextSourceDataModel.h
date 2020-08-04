//
// Created by ns on 7/30/20.
//

#ifndef BOTSERVER_TEXTSOURCEDATAMODEL_HPP
#define BOTSERVER_TEXTSOURCEDATAMODEL_HPP

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>

#include "TextData.h"

#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;


class TextSourceDataModel : public NodeDataModel {
    Q_OBJECT
public:
    TextSourceDataModel();
//    TextSourceDataModel(const TextSourceDataModel&);
    virtual ~TextSourceDataModel();

    QString caption() const override
    {
        return QString("My Source caption");
    }

//    bool captionVisible() const override { return true; }

    static QString
    Name()
    { return QString("My test text data source"); }

    QString
    name() const override
    { return TextSourceDataModel::Name(); }

    // port type is Out
    unsigned int nPorts(PortType portType) const override;

    NodeDataType
    dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData>
    outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData>, int) override
    { }

    QWidget *
    embeddedWidget() override { return _lineEdit; }

private Q_SLOTS:

    void
    onTextEdited(QString const &string);

private:
    QLineEdit * _lineEdit;
};


#endif //BOTSERVER_TEXTSOURCEDATAMODEL_HPP
