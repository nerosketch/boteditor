//
// Created by ns on 8/4/20.
//

#include "DialogLogicOutput.h"

DialogLogicOutput::DialogLogicOutput()
{}

DialogLogicOutput::~DialogLogicOutput() = default;


unsigned int DialogLogicOutput::nPorts(PortType portType) const
{
    switch (portType) {
        case PortType::In:
            return 1;
            break;

        default:
            break;
    }

    return 0;
}

QString DialogLogicOutput::portCaption(PortType port_type, PortIndex port_index) const
{
    switch (port_type) {
        case PortType::In:
            return tr("Выход");
            break;
        default:
            break;
    }

    return QStringLiteral("Не понятно");
}

NodeDataType DialogLogicOutput::dataType(PortType, PortIndex) const
{
    return NodeDataType {"integer", "Integer"};
}

std::shared_ptr<NodeData> DialogLogicOutput::outData(PortIndex port)
{
    return std::shared_ptr<NodeData>();
}
