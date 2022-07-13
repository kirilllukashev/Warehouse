#pragma once
#include "debug.h"
#include "Supplier.h"
#include "Consumer.h"
#include "Warehouse.h"
#include <vector>

struct WarehouseReport_ {
	int income = 0;
	int cash = 0;
	std::unordered_map<std::string, int> get;
	std::unordered_map<std::string, int> defects;
	std::unordered_map<std::string, int> rotten;
	std::unordered_map<std::string, int> products;
	std::unordered_map<std::string, int> packages;
	std::unordered_map<std::string, int> demand;
	std::unordered_map<std::string, int> sended;
	std::unordered_map<std::string, int> requested;
};

struct TransferReport_ {
	std::vector<Transmission> trans;
};

struct ConsumerReport_ {
	std::unordered_map<std::string, int> requested;
	std::unordered_map<std::string, int> sended;
};

class DayReport {
public:
	DayReport(Warehouse warehouse, std::vector<Consumer> consumers, int prodCount, int consume);
	friend std::ostream& operator<<(std::ostream& out, const DayReport& rep);

	WarehouseReport_ warehouseReport;
	TransferReport_ transferReport;
	std::vector<ConsumerReport_> consumersReport;
    std::list<Transmission> get_packages();
    std::vector<Consumer> get_consumers();
    Warehouse get_warehouse();
	int foodTypes;
private:
	Warehouse warehouse_;
	std::vector<Consumer> consumers_;
	std::list<Transmission> packages_;
};

class Simulation {
public:
	Simulation(int consumers, int foodTypes = 10, int warehouseCapacity = 100);
	DayReport process();
	const std::vector<DayReport>& genReports(int iters);

	DayReport report();

	friend int main();
private:
	Simulation();
	int foodTypes_ = 10;
	std::vector<DayReport> reports_;
	Warehouse warehouse_ = Warehouse(nullptr, 100, 10);
	Supplier supplier_;
	std::vector<Consumer> consumers_;
};
