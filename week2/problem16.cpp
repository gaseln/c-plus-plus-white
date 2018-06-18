std::set<std::string> BuildMapValuesSet(const map<int, string>& m) {
	std::set<std::string> to_return;
	for (auto el : m) {
		to_return.insert(el.second);
	}
	return to_return;
}