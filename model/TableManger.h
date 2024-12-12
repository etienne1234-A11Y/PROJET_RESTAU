#ifndef TABLEMANGER_H
#define TABLEMANGER_H

#include <vector>
#include <string>
#include <utility> // Pour std::pair

class TableManger {
public:
    TableManger();

    int getTableCapacity(int tableIndex) const;
    std::string getTableStatus(int tableIndex) const;
    int findAvailableTable(int numberOfClients) const;
    void setTableStatus(int tableIndex, const std::string& status);
    std::pair<int, int> getTablePosition(int tableIndex) const;
    std::vector<std::pair<int, int>> getTablePositions() const;

private:
    std::vector<std::pair<int, int>> tablePositions;
    std::vector<std::string> tableStatuses;
    std::vector<int> tableCapacities;
};

#endif // TABLEMANGER_H
