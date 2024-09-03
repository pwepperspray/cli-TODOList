#include <iostream>     
#include <vector>
#include <fstream>

void show();
void add();
void remove();

void show(const std::string &filepath){
	std::ifstream file;
	file.open(filepath);
	file.close();
}

void add(const std::string &filepath){
	std::string input;
	std::cout << "ADD CHANNNN!!!!!! >.< -" << "task" << "\n";
	std::cin >> input;
	std::cout << input;
}

void remove(){
	int index;
	std::cout << "Enter index : ";
	std::cin >> index;
	std::cout << index;
}

void sate(){
	std::cout << "bored \n";
}

int main (int argc, char* argv[]) {

	//finding the user profile path and saving it
	char * userpath = std::getenv("USERPROFILE");
	std::string path;
	if (userpath != nullptr){
		path =  std::string(userpath) + "\\data.csv"; 
	}

	//chekcing if the file exists and creating one if it doesnt
	std::ifstream file(path);
	if(!file){
		std::ofstream createfile(path);
		createfile.close();
	}
	
	//initialization of input variables for file
	std::vector<std::string> task;
	std::vector<bool> state;

	//initialization of argument variables 
	std::string arg1;
	std::string arg2;
	std::string arg3;
	
	//checking the commmand line arguments and working according
	return 0;
}
