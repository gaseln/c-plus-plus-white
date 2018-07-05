#include <string>
#include <exception>

class TimeServer {
public:
	std::string GetCurrentTime() {
		try {
			LastFetchedTime = AskTimeServer();
		}
		catch (std::system_error& ex) {
		}
		return LastFetchedTime;
	}
private:
	std::string LastFetchedTime = "00:00:00";
};