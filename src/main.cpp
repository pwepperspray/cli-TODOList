#include <iostream>     
#include <vector>
#include <fstream>

//function definition
void list();
void add();
void remove();
void sate();
void errormsg();

//function explanation
void list(const std::string &filepath){
	std::string task;
	std::cout << "list \n";

	//file operation list
	std::ifstream file(filepath, std::ios::in);
	getline(file, task);
	std::cout << task;
	file.close();
}

void add(const std::string &filepath, std::string task){

	//file operation add
	std::ofstream file(filepath, std::ios::app);
	file << task;
	file.close();
	std::cout << task << "\n";
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

void errormsg(){
	std::cout << "teri maa bc \n";
}

//main 
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

	//initialization of array containing argument variables
	//inserting the arguments into an array
	std::string argument[4] = {}; 
	if (argc < 2){
		errormsg();
	}
	else{
		for(int i = 0; i < argc; i++){
			argument[i] = argv[i];
		}
	}
	
	//checking the commmand line arguments and working accordingly
	//list the todo list
	if(argument[1] == "list"){
		std::cout << "true \n";
		list(path);
	}
	//add a new task
	else if (argument[1] == "add"){
		add(path, argument[2]);
	}


	return 0;
}
