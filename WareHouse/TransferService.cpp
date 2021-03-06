#include "Simulation.h"
#include "Commands.h"
#include "TransferService.h"

std::list<Transmission> TransferService::packages_;

void TransferService::addTrans(Transmission trans) {
	packages_.push_back(trans);
}

void TransferService::process(DayReport& report) {
	for (auto it = packages_.begin(); it != packages_.end();) {
		if (it->time == 0) {
			Transmission trans = *it;
			if (it->dest != nullptr)
				const_cast<ITransferPoint*>(trans.dest)->processTransmission(trans);
			packages_.erase(it++);
			continue;
		}
		it->time--;
		it++;
	}
	for (auto it : packages_) {
		report.transferReport.trans.push_back(it);
	}
}