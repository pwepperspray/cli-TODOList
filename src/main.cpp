#include <iostream>     
#include <iomanip>      
#include <vector>

void show();
void add();
void remove();

void show(){
	std::cout << "SHOW KAWAIII >.< \n";
}

void add(){
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

	std::vector<std::string> task;
	std::vector<bool> state;

	std::string arg1;
	std::string arg2;
	std::string arg3;
	
	arg1 = argv[1];

	if(argc == 2){
		if(arg1 == "list"){
			show();
		}
		else if(arg1 == "add"){
			add();
		}
		else if(arg1 == "remove"){
			remove();
		}
		else if(arg1 == "state"){
			sate();
		}
	}
	return 0;
}
