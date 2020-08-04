//
// Created by ns on 8/4/20.
//

#include "DialogLogicInput.h"

DialogLogicInput::DialogLogicInput() = default;
DialogLogicInput::~DialogLogicInput() = default;

unsigned int DialogLogicInput::nPorts(PortType portType) const
{
    switch (portType) {
        case PortType::In:
            return 1;
            break;

        case PortType::Out:
            return 3;
            break;

        default:
            break;
    }

    return 0;
}

QString DialogLogicInput::portCaption(PortType port_type, PortIndex port_index) const
{
    switch (port_type) {
        case PortType::In:
            return tr("Вход");
            break;
        case PortType::Out:
            return tr("Опция");
            break;
        default:
            break;
    }

    return QStringLiteral("Не понятно");
}

NodeDataType DialogLogicInput::dataType(PortType, PortIndex) const
{
    return NodeDataType {"integer", "Integer"};
}

std::shared_ptr<NodeData> DialogLogicInput::outData(PortIndex port)
{
    return std::shared_ptr<NodeData>();
}
