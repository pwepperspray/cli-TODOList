#include <iostream>     
#include <iomanip>      
#include <vector>
#include <windows.h>

void show();
void add();

void show(){
	std::cout << "SHOW KAWAIII >.< \n";
}

void add(){
	std::cout << "ADD CHANNNN!!!!!! >.< \n";
}

int main (int argc, char* argv[]) {

	std::string input;
	std::vector<std::string> task;
	std::vector<bool> state;

	//checking the arguments applied
	while(1){
		std::cout << argv[1] << "\n";
		if (argc >=2){
			if (argv[1] == "list"){
				show();
				break;
			}
			else if (argv[1] == "add"){
				add();
				break;
			}	
		}
		else{
			std::cout << "HELP \n";
			break;
		}
	}

	return 0;
}
