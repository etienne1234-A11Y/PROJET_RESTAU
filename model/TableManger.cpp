#include "TableManger.h"

TableManger::TableManger()
    : tablePositions({
        {265, 20}, {500, 20}, {670, 120}, {855,10},
        {335, 140}, {855, 530}, {575, 340}, {550, 500},
        {360, 420}, {855, 350}, {640, 40}
    }),
    tableStatuses(11, "available"),
    tableCapacities({4, 6, 8, 10, 4, 6, 8, 10, 6, 4, 2}) {}

int TableManger::getTableCapacity(int tableIndex) const {
    return tableCapacities.at(tableIndex);
}

std::string TableManger::getTableStatus(int tableIndex) const {
    return tableStatuses.at(tableIndex);
}

int TableManger::findAvailableTable(int numberOfClients) const {
    for (size_t i = 0; i < tableStatuses.size(); ++i) {
        if (tableStatuses[i] == "available" && tableCapacities[i] >= numberOfClients) {
            return i;
        }
    }
    return -1;
}

void TableManger::setTableStatus(int tableIndex, const std::string& status) {
    tableStatuses[tableIndex] = status;
}

std::pair<int, int> TableManger::getTablePosition(int tableIndex) const {
    return tablePositions.at(tableIndex);
}

std::vector<std::pair<int, int>> TableManger::getTablePositions() const {
    return tablePositions;
}
