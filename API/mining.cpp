#include "mining.h"

Mining::Mining()
{
}

void Mining::setStrategy(iStrategy *strategy) {
    this->strategy = strategy;
}

QJsonObject Mining::getData() {
    return strategy->getData();
}
