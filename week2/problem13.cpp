#include <iostream>
#include <map>
#include <vector>
#include <string>

std::map<std::string, std::vector<std::string>> all_buses;
std::map<std::string, std::vector<std::string>> all_stops;
std::vector<std::string> out;

void NewBus(std::string bus, std::vector<std::string> stops) {
	all_buses[bus] = stops;
	for (const auto& stop : stops) {
		all_stops[stop].push_back(bus);
	}
}

void StopsForBuses(std::string initial_bus) {
	if (all_buses.count(initial_bus) == 0) {
		out.push_back("No bus");
	}
	else {
		for (const auto& stop : all_buses[initial_bus]) {
			int counter = 0;
			std::string new_str = "Stop " + stop + ": ";
			for (const auto& bus : all_stops[stop]) {
				if (bus != initial_bus) {
					new_str += bus + " ";
					++counter;
				}
			}
			if (counter == 0) {
				new_str += "no interchange ";
			}
			out.push_back(new_str);
		}
	}
}

void BusesForStop(std::string curr_stop) {
	if (all_stops.count(curr_stop) == 0) {
		out.push_back("No stop");
	}
	else {
		std::string new_str = "";
		for (int j = 0; j < all_stops[curr_stop].size(); ++j) {
			new_str += all_stops[curr_stop][j] + " ";
		}
		out.push_back(new_str);
	}
}

void AllBuses() {
	if (all_buses.empty()) {
		out.push_back("No buses");
	}
	else {
		for (const auto& bus : all_buses) {
			std::string new_str = "Bus " + bus.first + ": ";
			for (const auto& stop : bus.second) {
				new_str += stop + " ";
			}
			out.push_back(new_str);
		}
	}
}


int main() {
	std::string command, str1, str2;
	int Q, i, j, bus_count;
	std::cin >> Q;
	for (i = 0; i < Q; ++i) {
		std::cin >> command;
		if (command == "NEW_BUS") {
			std::cin >> str1;
			std::cin >> bus_count;
			std::vector<std::string> new_stops(bus_count);
			for (j = 0; j < bus_count; ++j) {
				std::cin >> str2;
				new_stops[j] = str2;
			}
			NewBus(str1, new_stops);
		}
		if (command == "BUSES_FOR_STOP") {
			std::cin >> str1;
			BusesForStop(str1);
		}
		if (command == "STOPS_FOR_BUS") {
			std::cin >> str1;
			StopsForBuses(str1);
		}
		if (command == "ALL_BUSES") {
			AllBuses();
		}
	}
	for (j = 0; j < out.size(); ++j) {
		std::cout << out[j] << std::endl;
	}
	return 0;
}
